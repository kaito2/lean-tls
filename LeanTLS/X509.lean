import LeanTLS.ASN1
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.X509

/-!
# X.509 Certificate Parser

Pure Lean 4 implementation of X.509 certificate parsing for TLS certificate
verification. Parses DER-encoded X.509 certificates and extracts the fields
needed for TLS signature verification:
- TBS (To-Be-Signed) certificate raw DER bytes
- Signature algorithm OID
- Signature value
- RSA public key (modulus and exponent)
- Subject Common Name (CN)
- Subject Alternative Names (SAN DNS entries)
-/

-- ============================================================================
-- Section 1: Data Structures
-- ============================================================================

/-- RSA public key components. -/
structure RSAPublicKey where
  modulus : Nat    -- n
  exponent : Nat   -- e (typically 65537)

/-- Sum type for public keys extracted from X.509 certificates. -/
inductive PublicKey where
  | rsa : RSAPublicKey → PublicKey
  | ec : ByteArray → PublicKey  -- raw uncompressed EC point (65 bytes for P-256)
  | unknown : PublicKey

instance : Inhabited PublicKey where
  default := .unknown

/-- Parsed X.509 certificate (subset relevant for TLS verification). -/
structure X509Certificate where
  tbsCertificateDER : ByteArray        -- Raw DER bytes for signature verification
  signatureAlgorithm : Array Nat       -- OID components
  signatureValue : ByteArray           -- Raw signature bytes (BIT STRING content without unused-bits byte)
  publicKey : PublicKey                -- Extracted public key (RSA, EC, or unknown)
  subjectAltNames : Array String       -- DNS names from SAN extension
  commonName : Option String           -- CN from Subject
  notBefore : Option LeanTLS.ASN1.DateTime := none
  notAfter : Option LeanTLS.ASN1.DateTime := none
  issuerDN : ByteArray := ByteArray.empty   -- Raw DER bytes of the Issuer Name sequence
  subjectDN : ByteArray := ByteArray.empty  -- Raw DER bytes of the Subject Name sequence

instance : Inhabited X509Certificate where
  default := {
    tbsCertificateDER := ByteArray.empty
    signatureAlgorithm := #[]
    signatureValue := ByteArray.empty
    publicKey := .unknown
    subjectAltNames := #[]
    commonName := none
  }

-- ============================================================================
-- Section 2: Helpers
-- ============================================================================

/-- Parse tag and length from data at offset, returning (tag, valueStart, valueLength).
    This allows callers to know exactly where the value region begins in the
    original byte array, which is critical for extracting raw DER bytes. -/
def parseTagAndLength (data : ByteArray) (offset : Nat)
    : Option (ASN1.Tag × Nat × Nat) := do
  let (tag, afterTag) ← ASN1.parseTag data offset
  let (len, afterLen) ← ASN1.parseLength data afterTag
  some (tag, afterLen, len)

/-- Interpret a ByteArray as a string by converting each byte to a Char.
    Handles ASCII and basic UTF-8 content found in certificate fields. -/
private def bytesToString (bs : ByteArray) : String :=
  let chars := Nat.fold (n := bs.size) (init := #[]) fun i _ acc =>
    acc.push (Char.ofNat (bs.get! i).toNat)
  String.mk chars.toList

-- ============================================================================
-- Section 3: RSA Public Key Parsing
-- ============================================================================

/-- Parse an RSA public key from the content of a BIT STRING.
    The BIT STRING value starts with a single unused-bits byte (must be 0x00),
    followed by DER-encoded:
      RSAPublicKey ::= SEQUENCE { modulus INTEGER, publicExponent INTEGER }
-/
def parseRSAPublicKey (bitStringContent : ByteArray) : Option RSAPublicKey := do
  -- First byte is unused bits count; must be 0 for RSA keys
  if bitStringContent.size < 2 then none
  else
    if bitStringContent.get! 0 != 0x00 then none
    else
      -- Parse the remaining bytes as a SEQUENCE of two INTEGERs
      let inner := bitStringContent.extract 1 bitStringContent.size
      let seqNode ← ASN1.parseAll inner
      let children := ASN1.ASN1Node.getChildren seqNode
      if children.size < 2 then none
      else
        let modNode := children[0]!
        let expNode := children[1]!
        -- Both should be INTEGERs (universal, tag number 2)
        let modTag := ASN1.ASN1Node.getTag modNode
        let expTag := ASN1.ASN1Node.getTag expNode
        if ASN1.Tag.tagNumber modTag != 2 || ASN1.Tag.tagNumber expTag != 2 then none
        else
          let modulus := ASN1.parseInteger (ASN1.ASN1Node.getValue modNode)
          let exponent := ASN1.parseInteger (ASN1.ASN1Node.getValue expNode)
          some { modulus := modulus, exponent := exponent }

-- ============================================================================
-- Section 4: SubjectPublicKeyInfo Parsing
-- ============================================================================

/-- Parse SubjectPublicKeyInfo to extract the public key (RSA or EC).
    SubjectPublicKeyInfo ::= SEQUENCE {
      algorithm  AlgorithmIdentifier,  -- SEQUENCE { OID, NULL or params }
      subjectPublicKey BIT STRING
    }
    For RSA: OID 1.2.840.113549.1.1.1 (rsaEncryption), BIT STRING contains DER-encoded RSA key
    For EC:  OID 1.2.840.10045.2.1 (id-ecPublicKey), params = namedCurve OID, BIT STRING contains EC point
-/
def parseSubjectPublicKeyInfo (node : ASN1.ASN1Node) : Option PublicKey := do
  let children := ASN1.ASN1Node.getChildren node
  if children.size < 2 then none
  else
    -- First child: AlgorithmIdentifier SEQUENCE
    let algId := children[0]!
    let algChildren := ASN1.ASN1Node.getChildren algId
    if algChildren.size < 1 then none
    else
      -- Extract the OID
      let oidNode := algChildren[0]!
      let oidTag := ASN1.ASN1Node.getTag oidNode
      if ASN1.Tag.tagNumber oidTag != 6 || ASN1.Tag.tagClass oidTag != .universal then none
      else
        let oid ← ASN1.parseOID (ASN1.ASN1Node.getValue oidNode)
        -- Second child: BIT STRING containing the public key
        let pubKeyBitString := children[1]!
        let bsTag := ASN1.ASN1Node.getTag pubKeyBitString
        if ASN1.Tag.tagNumber bsTag != 3 || ASN1.Tag.tagClass bsTag != .universal then none
        else
          if ASN1.oidEq oid ASN1.oidRsaEncryption then
            -- RSA public key
            let rsaKey ← parseRSAPublicKey (ASN1.ASN1Node.getValue pubKeyBitString)
            some (.rsa rsaKey)
          else if ASN1.oidEq oid ASN1.oidEcPublicKey then
            -- EC public key: BIT STRING value = unused-bits byte (0x00) + EC point
            let bsValue := ASN1.ASN1Node.getValue pubKeyBitString
            if bsValue.size < 2 then none
            else
              if bsValue.get! 0 != 0x00 then none
              else
                let ecPoint := bsValue.extract 1 bsValue.size
                some (.ec ecPoint)
          else
            some .unknown

-- ============================================================================
-- Section 5: Subject Common Name Extraction
-- ============================================================================

/-- Parse the Subject field to extract the Common Name (CN).
    Subject is a Name ::= SEQUENCE OF RelativeDistinguishedName
    RDN ::= SET OF AttributeTypeAndValue
    ATAV ::= SEQUENCE { type OID, value ANY }
-/
def parseSubjectCN (subjectNode : ASN1.ASN1Node) : Option String :=
  let rdnSeq := ASN1.ASN1Node.getChildren subjectNode
  -- Walk each RDN (SET)
  let rec goRDN (i : Nat) : Option String :=
    if i >= rdnSeq.size then none
    else
      let rdn := rdnSeq[i]!
      let atvs := ASN1.ASN1Node.getChildren rdn
      -- Walk each ATV (SEQUENCE) in the SET
      let rec goATV (j : Nat) : Option String :=
        if j >= atvs.size then none
        else
          let atv := atvs[j]!
          let atvChildren := ASN1.ASN1Node.getChildren atv
          if atvChildren.size < 2 then goATV (j + 1)
          else
            let oidNode := atvChildren[0]!
            let oidTag := ASN1.ASN1Node.getTag oidNode
            if ASN1.Tag.tagNumber oidTag != 6 || ASN1.Tag.tagClass oidTag != .universal then goATV (j + 1)
            else
              match ASN1.parseOID (ASN1.ASN1Node.getValue oidNode) with
              | none => goATV (j + 1)
              | some oid =>
                if ASN1.oidEq oid ASN1.oidCommonName then
                  let valNode := atvChildren[1]!
                  some (bytesToString (ASN1.ASN1Node.getValue valNode))
                else goATV (j + 1)
      termination_by atvs.size - j
      match goATV 0 with
      | some cn => some cn
      | none => goRDN (i + 1)
  termination_by rdnSeq.size - i
  goRDN 0

-- ============================================================================
-- Section 6: Subject Alternative Names Extraction
-- ============================================================================

/-- Parse the extensions to extract Subject Alternative Names (DNS names).
    Extensions ::= SEQUENCE OF Extension
    Extension  ::= SEQUENCE { extnID OID, critical BOOLEAN OPTIONAL, extnValue OCTET STRING }
    For SAN (OID 2.5.29.17), extnValue contains DER-encoded:
    GeneralNames ::= SEQUENCE OF GeneralName
    GeneralName  ::= CHOICE { dNSName [2] IA5String, ... }
    dNSName is context-specific tag 2, primitive (tag byte 0x82).
-/
def parseSAN (extensionsNode : ASN1.ASN1Node) : Array String :=
  let exts := ASN1.ASN1Node.getChildren extensionsNode
  let rec goExt (i : Nat) (acc : Array String) : Array String :=
    if i >= exts.size then acc
    else
      let ext := exts[i]!
      let extChildren := ASN1.ASN1Node.getChildren ext
      -- Extension must have at least 2 children (OID + OCTET STRING),
      -- optionally 3 if critical BOOLEAN is present
      if extChildren.size < 2 then goExt (i + 1) acc
      else
        let oidNode := extChildren[0]!
        let oidTag := ASN1.ASN1Node.getTag oidNode
        if ASN1.Tag.tagNumber oidTag != 6 || ASN1.Tag.tagClass oidTag != .universal then goExt (i + 1) acc
        else
          match ASN1.parseOID (ASN1.ASN1Node.getValue oidNode) with
          | none => goExt (i + 1) acc
          | some oid =>
            if !ASN1.oidEq oid ASN1.oidSubjectAltName then goExt (i + 1) acc
            else
              -- The OCTET STRING is the last child (may be index 1 or 2 depending on critical flag)
              let octetIdx := extChildren.size - 1
              let octetNode := extChildren[octetIdx]!
              let octetTag := ASN1.ASN1Node.getTag octetNode
              -- Should be OCTET STRING (tag 4, universal)
              if ASN1.Tag.tagNumber octetTag != 4 || ASN1.Tag.tagClass octetTag != .universal then goExt (i + 1) acc
              else
                -- Parse the OCTET STRING content as GeneralNames SEQUENCE
                let octetValue := ASN1.ASN1Node.getValue octetNode
                match ASN1.parseAll octetValue with
                | none => goExt (i + 1) acc
                | some generalNamesSeq =>
                  let names := ASN1.ASN1Node.getChildren generalNamesSeq
                  let rec goDNS (j : Nat) (dnsAcc : Array String) : Array String :=
                    if j >= names.size then dnsAcc
                    else
                      let name := names[j]!
                      let nameTag := ASN1.ASN1Node.getTag name
                      -- dNSName: context-specific, tag number 2, primitive
                      if ASN1.Tag.tagClass nameTag == .contextSpecific && ASN1.Tag.tagNumber nameTag == 2 then
                        let dnsName := bytesToString (ASN1.ASN1Node.getValue name)
                        goDNS (j + 1) (dnsAcc.push dnsName)
                      else
                        goDNS (j + 1) dnsAcc
                  termination_by names.size - j
                  goExt (i + 1) (goDNS 0 acc)
  termination_by exts.size - i
  goExt 0 #[]

-- ============================================================================
-- Section 7: Validity Period Parsing
-- ============================================================================

/-- Parse a single ASN.1 time node (UTCTime tag 0x17 or GeneralizedTime tag 0x18). -/
private def parseTimeNode (node : ASN1.ASN1Node) : Option ASN1.DateTime :=
  let tag := ASN1.ASN1Node.getTag node
  if ASN1.Tag.tagClass tag != .universal then none
  else if ASN1.Tag.tagNumber tag == 0x17 then
    ASN1.parseUTCTime (ASN1.ASN1Node.getValue node)
  else if ASN1.Tag.tagNumber tag == 0x18 then
    ASN1.parseGeneralizedTime (ASN1.ASN1Node.getValue node)
  else none

/-- Parse the Validity SEQUENCE (notBefore, notAfter) from a TBS certificate ASN1 node. -/
def parseValidity (tbsNode : LeanTLS.ASN1.ASN1Node) (hasVersion : Bool) : Option (LeanTLS.ASN1.DateTime × LeanTLS.ASN1.DateTime) := do
  let tbsChildren := ASN1.ASN1Node.getChildren tbsNode
  let offset := if hasVersion then 1 else 0
  let validityIdx := offset + 3
  if tbsChildren.size <= validityIdx then none
  else
    let validityNode := tbsChildren[validityIdx]!
    let validityChildren := ASN1.ASN1Node.getChildren validityNode
    if validityChildren.size < 2 then none
    else
      let notBefore ← parseTimeNode (validityChildren[0]!)
      let notAfter ← parseTimeNode (validityChildren[1]!)
      some (notBefore, notAfter)

/-- Check if a certificate is valid at the given time. -/
def isValidAt (cert : X509Certificate) (now : LeanTLS.ASN1.DateTime) : Bool :=
  match cert.notBefore, cert.notAfter with
  | some nb, some na => ASN1.dateTimeLe nb now && ASN1.dateTimeLe now na
  | _, _ => false

-- ============================================================================
-- Section 8: Raw DER Field Extraction Helper
-- ============================================================================

/-- Walk through children of a constructed SEQUENCE in raw DER bytes,
    skipping `remaining` children and then returning the raw TLV bytes of
    the next child. -/
private def extractChildDERAux (seqDER : ByteArray) (pos : Nat) (endPos : Nat)
    (remaining : Nat) : Option ByteArray :=
  if pos >= endPos then none
  else
    match ASN1.parseTLV seqDER pos with
    | none => none
    | some (_, childEnd) =>
      if childEnd > endPos then none
      else if remaining == 0 then some (seqDER.extract pos childEnd)
      else if childEnd ≤ pos then none  -- guard against non-progress
      else extractChildDERAux seqDER childEnd endPos (remaining - 1)
termination_by (endPos - pos, remaining)

/-- Extract the raw DER bytes of a specific child TLV element within a
    constructed SEQUENCE given its raw DER bytes. Walks through children
    from the beginning to find the `idx`-th child, returning its full
    TLV bytes (tag + length + value). -/
private def extractChildDER (seqDER : ByteArray) (idx : Nat) : Option ByteArray :=
  match parseTagAndLength seqDER 0 with
  | none => none
  | some (_, valueStart, valueLen) =>
    let valueEnd := valueStart + valueLen
    extractChildDERAux seqDER valueStart valueEnd idx

-- ============================================================================
-- Section 9: Main Certificate Parser
-- ============================================================================

/-- Parse a DER-encoded X.509 certificate.
    Certificate ::= SEQUENCE {
      tbsCertificate     TBSCertificate,
      signatureAlgorithm AlgorithmIdentifier,
      signatureValue     BIT STRING
    }

    CRITICAL: tbsCertificateDER is extracted as raw bytes from the original
    input, not re-encoded, for signature verification correctness.
-/
def parseX509 (der : ByteArray) : Option X509Certificate := do
  -- Parse the outer Certificate SEQUENCE to validate structure
  let (outerNode, _) ← ASN1.parseTLV der 0
  let outerChildren := ASN1.ASN1Node.getChildren outerNode
  if outerChildren.size < 3 then none
  else
    -- Determine where the outer SEQUENCE value region starts
    let (_, outerValueStart, _) ← parseTagAndLength der 0
    -- Parse the first child (TBSCertificate) from the raw DER to get its exact byte boundaries
    let (_, tbsEnd) ← ASN1.parseTLV der outerValueStart
    let tbsCertificateDER := der.extract outerValueStart tbsEnd

    -- Extract TBSCertificate from the parsed tree
    let tbsNode := outerChildren[0]!

    -- Extract signature algorithm OID from the second child
    let sigAlgNode := outerChildren[1]!
    let sigAlgChildren := ASN1.ASN1Node.getChildren sigAlgNode
    if sigAlgChildren.size < 1 then none
    else
      let sigAlgOidNode := sigAlgChildren[0]!
      let sigAlgOidTag := ASN1.ASN1Node.getTag sigAlgOidNode
      if ASN1.Tag.tagNumber sigAlgOidTag != 6 || ASN1.Tag.tagClass sigAlgOidTag != .universal then none
      else
        let signatureAlgorithm ← ASN1.parseOID (ASN1.ASN1Node.getValue sigAlgOidNode)

        -- Extract signature value from the third child (BIT STRING)
        let sigValNode := outerChildren[2]!
        let sigValTag := ASN1.ASN1Node.getTag sigValNode
        if ASN1.Tag.tagNumber sigValTag != 3 || ASN1.Tag.tagClass sigValTag != .universal then none
        else
          let sigRaw := ASN1.ASN1Node.getValue sigValNode
          -- Skip the unused-bits byte (first byte, should be 0x00)
          if sigRaw.size < 1 then none
          else
            let signatureValue := sigRaw.extract 1 sigRaw.size

            -- Parse TBSCertificate fields
            let tbsChildren := ASN1.ASN1Node.getChildren tbsNode
            if tbsChildren.size < 6 then none
            else
              -- Detect version tag: if first child is context-specific tag 0,
              -- it is the explicit version wrapper (v3 certificates)
              let firstTag := ASN1.ASN1Node.getTag (tbsChildren[0]!)
              let hasVersion := ASN1.Tag.tagClass firstTag == .contextSpecific && ASN1.Tag.tagNumber firstTag == 0
              let offset := if hasVersion then 1 else 0

              -- Field indices (with offset applied):
              -- serialNumber  = offset + 0
              -- signature     = offset + 1
              -- issuer        = offset + 2
              -- validity      = offset + 3
              -- subject       = offset + 4
              -- subjectPKInfo = offset + 5
              -- extensions    = offset + 6 (optional, context-specific tag 3)
              let subjectIdx := offset + 4
              let spkiIdx := offset + 5
              let extIdx := offset + 6

              if tbsChildren.size <= spkiIdx then none
              else
                let subjectNode := tbsChildren[subjectIdx]!
                let spkiNode := tbsChildren[spkiIdx]!

                -- Extract CN from subject
                let commonName := parseSubjectCN subjectNode

                -- Extract RSA public key from SubjectPublicKeyInfo
                let publicKey ← parseSubjectPublicKeyInfo spkiNode

                -- Extract SAN from extensions (if present)
                let subjectAltNames :=
                  if extIdx < tbsChildren.size then
                    let extWrapper := tbsChildren[extIdx]!
                    let extWrapperTag := ASN1.ASN1Node.getTag extWrapper
                    -- Extensions are wrapped in context-specific tag [3] constructed
                    if ASN1.Tag.tagClass extWrapperTag == .contextSpecific && ASN1.Tag.tagNumber extWrapperTag == 3 then
                      let extWrapperChildren := ASN1.ASN1Node.getChildren extWrapper
                      if extWrapperChildren.size >= 1 then
                        parseSAN (extWrapperChildren[0]!)
                      else #[]
                    else #[]
                  else #[]

                -- Extract validity dates
                let (notBefore, notAfter) :=
                  match parseValidity tbsNode hasVersion with
                  | some (nb, na) => (some nb, some na)
                  | none => (none, none)

                -- Extract raw DER bytes for Issuer and Subject Name sequences
                let issuerIdx := offset + 2
                let issuerDN := match extractChildDER tbsCertificateDER issuerIdx with
                  | some bytes => bytes
                  | none => ByteArray.empty
                let subjectDN := match extractChildDER tbsCertificateDER subjectIdx with
                  | some bytes => bytes
                  | none => ByteArray.empty

                some {
                  tbsCertificateDER := tbsCertificateDER
                  signatureAlgorithm := signatureAlgorithm
                  signatureValue := signatureValue
                  publicKey := publicKey
                  subjectAltNames := subjectAltNames
                  commonName := commonName
                  notBefore := notBefore
                  notAfter := notAfter
                  issuerDN := issuerDN
                  subjectDN := subjectDN
                }

-- ============================================================================
-- Section 10: Tests
-- ============================================================================

/-- Run all X509 module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Mozilla.org DER certificate hex (RSA-2048, CN=mozilla.org, SAN=DNS:mozilla.org)
  let certHex := "308205223082040aa003020102021100f08ed405f1dd1b8609bebc381bdb9501300d06092a864886f70d01010b0500303b310b3009060355040613025553311e301c060355040a1315476f6f676c65205472757374205365727669636573310c300a06035504031303575233301e170d3236303231313131353930345a170d3236303531323132353233375a3016311430120603550403130b6d6f7a696c6c612e6f726730820122300d06092a864886f70d01010105000382010f003082010a0282010100ca18de9ad7b7c1bf1e75c5e2ab7c99897eb5e6e9aad58cf670f7816516590c3594abcac7d151dd7c6c336b8d1e9efaf74ffc5a3b768bb412dbf7efd47c3fa42c3a0322a3354c4178437d4df2f7c2d16424a19ee81f605e967ce54fa9d3a8e2a7ff7e8f89f343166aca840ecd97888c75c268234b64d49218164eae5b253dd1c24c957e704143fb91eb96329ccee7d694010469dcd69b5e1e9576de7bf31f500e8135bcd736f10726ebcc78a51aa41bf877b7f4608ffe75b344b3b915b465acbf8882227ead02e6ccb4fce4062c0bc42d0c2565deef52245ca38d89a67b97a0526147a1ade8dde5a6c5171d9f16034b96c333fbabb5f4ac44b03884ef6ed406e90203010001a382024430820240300e0603551d0f0101ff0404030205a030130603551d25040c300a06082b06010505070301300c0603551d130101ff04023000301d0603551d0e04160414473dd35c06edb8cf7f71e78e1f8f277bfa3bdf03301f0603551d23041830168014c781f5fd8e88d9003c4d63a2503124a0ce23fe23305e06082b0601050507010104523050302706082b06010505073001861b687474703a2f2f6f2e706b692e676f6f672f732f7772332f384934302506082b060105050730028619687474703a2f2f692e706b692e676f6f672f7772332e63727430160603551d11040f300d820b6d6f7a696c6c612e6f726730130603551d20040c300a3008060667810c01020130360603551d1f042f302d302ba029a0278625687474703a2f2f632e706b692e676f6f672f7772332f33417046474736357267552e63726c30820104060a2b06010401d6790204020481f50481f200f0007500969764bf555897adf743876837084277e9f03ad5f6a4f3366e46a43f0fcaa9c60000019c4cc8ab57000004030046304402201b20527dd5d1cddf5525c42f8d75b4925f13a37268c6180ed56e353919a9bb19022016e1c328e0e7c00bdbb90911b06dbaaf62a1c61d70f86558f788b3d3afdd0561007700cb38f715897c84a1445f5bc1ddfbc96ef29a59cd470a690585b0cb14c31458e70000019c4cc8ab5e000004030048304602210081e632c97242dca37e3197593f080ba772b8f8b3774a42a639d81612ba32c14902210087ca479e96d64a3e36c29519f3641c7ac75942d706c893504e8e0cda04cd3be6300d06092a864886f70d01010b0500038201010070fe76a3e6885feea134b8c77f922448cbc7ff1de76c85ca11f1dd73ecde93bafa342c6d21e8b45abb99827baf1eeb378186fa28bb6a73e8a37596e79e88518bd6c83d4081e3e64899c0934014870731d6c35483c9d5e77133347400e60a5874de33e60fadb82e57c3f445833cc2fc2e2ccf1c5e729b0e3c096ab9fd73a3c22ce3be977d83c4a2446450abc6e624bb7363a244ec605abe0a7da1a98c6f680d30e3eba507d8acb922c0520d05be99f0efb1fd952ceab70b4f5576a2eaa186a966360f38894f60c883d8404183d390ee5a998ccb8e732d66ba80ca869ee37bedbad6cf72472dd1f2a75d0a36fbd455602264cc4814bf9ba184b98a44c7a91eb1be"
  let certDer := LeanTLS.Utils.hexToBytes certHex

  -- --------------------------------------------------------------------------
  -- Test 1: Parse mozilla.org certificate and verify fields
  -- --------------------------------------------------------------------------
  IO.println "  X509 test 1 (parse mozilla.org certificate):"
  match parseX509 certDer with
  | none =>
    IO.println "    FAILED (parseX509 returned none)"
    allPassed := false
  | some cert =>
    -- Check CN
    match cert.commonName with
    | some cn =>
      if cn == "mozilla.org" then
        IO.println "    CN = mozilla.org: PASSED"
      else
        IO.println s!"    CN: FAILED (expected 'mozilla.org', got '{cn}')"
        allPassed := false
    | none =>
      IO.println "    CN: FAILED (commonName is none)"
      allPassed := false

    -- Check SAN
    if cert.subjectAltNames.size > 0 then
      let hasMozilla := cert.subjectAltNames.any (· == "mozilla.org")
      if hasMozilla then
        IO.println "    SAN contains mozilla.org: PASSED"
      else
        IO.println s!"    SAN: FAILED (does not contain 'mozilla.org', got {cert.subjectAltNames.toList})"
        allPassed := false
    else
      IO.println "    SAN: FAILED (subjectAltNames is empty)"
      allPassed := false

    -- Check public key (RSA with expected exponent and modulus prefix)
    match cert.publicKey with
    | .rsa rsaKey =>
      if rsaKey.exponent == 65537 then
        IO.println "    Exponent = 65537: PASSED"
      else
        IO.println s!"    Exponent: FAILED (expected 65537, got {rsaKey.exponent})"
        allPassed := false

      -- Check modulus hex starts with "ca18de9a"
      let modBytes := LeanTLS.Utils.bytesToHex (LeanTLS.Utils.hexToBytes "ca18de9a")
      let modHex := modulusToHex rsaKey.modulus
      if modHex.take 8 == modBytes then
        IO.println "    Modulus starts with ca18de9a: PASSED"
      else
        IO.println s!"    Modulus: FAILED (expected prefix 'ca18de9a', got '{modHex.take 8}')"
        allPassed := false
    | _ =>
      IO.println "    PublicKey: FAILED (expected RSA key)"
      allPassed := false

    -- Check signature algorithm OID
    if ASN1.oidEq cert.signatureAlgorithm ASN1.oidSha256WithRSAEncryption then
      IO.println "    SignatureAlgorithm = sha256WithRSAEncryption: PASSED"
    else
      IO.println s!"    SignatureAlgorithm: FAILED (got {cert.signatureAlgorithm.toList})"
      allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: Verify tbsCertificateDER starts with SEQUENCE tag and is non-empty
  -- --------------------------------------------------------------------------
  IO.println "  X509 test 2 (tbsCertificateDER integrity):"
  match parseX509 certDer with
  | none =>
    IO.println "    FAILED (parseX509 returned none)"
    allPassed := false
  | some cert =>
    if cert.tbsCertificateDER.size == 0 then
      IO.println "    FAILED (tbsCertificateDER is empty)"
      allPassed := false
    else
      if cert.tbsCertificateDER.get! 0 == 0x30 then
        IO.println "    tbsCertificateDER starts with 0x30 (SEQUENCE): PASSED"
      else
        IO.println s!"    FAILED (expected first byte 0x30, got 0x{LeanTLS.Utils.bytesToHex (ByteArray.mk #[cert.tbsCertificateDER.get! 0])})"
        allPassed := false
      -- Additional check: tbsCertificateDER should be a valid ASN.1 structure
      match ASN1.parseAll cert.tbsCertificateDER with
      | some _ =>
        IO.println "    tbsCertificateDER is valid ASN.1: PASSED"
      | none =>
        IO.println "    FAILED (tbsCertificateDER is not valid ASN.1)"
        allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: Validity period parsing from mozilla.org certificate
  -- --------------------------------------------------------------------------
  IO.println "  X509 test 3 (validity period parsing):"
  match parseX509 certDer with
  | none =>
    IO.println "    FAILED (parseX509 returned none)"
    allPassed := false
  | some cert =>
    match cert.notBefore, cert.notAfter with
    | some nb, some na =>
      -- The mozilla.org cert has notBefore: 260211115904Z and notAfter: 260512125237Z
      -- Verify they parsed as valid DateTimes with reasonable years
      if nb.year >= 2020 && nb.year <= 2030 && na.year >= 2020 && na.year <= 2030 then
        IO.println s!"    notBefore: {nb.year}-{nb.month}-{nb.day} {nb.hour}:{nb.minute}:{nb.second}: PASSED"
        IO.println s!"    notAfter:  {na.year}-{na.month}-{na.day} {na.hour}:{na.minute}:{na.second}: PASSED"
        -- Test isValidAt: a date between notBefore and notAfter should be valid
        let midDate : ASN1.DateTime := { year := 2026, month := 3, day := 15, hour := 12, minute := 0, second := 0 }
        if isValidAt cert midDate then
          IO.println "    isValidAt (2026-03-15, within range): PASSED"
        else
          IO.println "    isValidAt (2026-03-15, within range): FAILED"
          allPassed := false
        -- A date far in the future should not be valid
        let futureDate : ASN1.DateTime := { year := 2030, month := 1, day := 1, hour := 0, minute := 0, second := 0 }
        if !isValidAt cert futureDate then
          IO.println "    isValidAt (2030-01-01, outside range): PASSED"
        else
          IO.println "    isValidAt (2030-01-01, outside range): FAILED"
          allPassed := false
      else
        IO.println s!"    FAILED (unexpected years: notBefore.year={nb.year}, notAfter.year={na.year})"
        allPassed := false
    | _, _ =>
      IO.println "    FAILED (notBefore or notAfter is none)"
      allPassed := false

  if allPassed then
    IO.println "  All X509 tests passed."

  return allPassed

where
  /-- Convert a Nat (modulus) to a lowercase hex string. -/
  modulusToHex (n : Nat) : String :=
    if n == 0 then "00"
    else
      let rec go (val : Nat) (acc : List Char) : List Char :=
        if h : val = 0 then acc
        else
          let hexChars := "0123456789abcdef"
          let lo := val % 16
          let hi := val / 16
          let c := hexChars.get! ⟨lo⟩
          have : hi < val := Nat.div_lt_self (Nat.pos_of_ne_zero h) (by omega)
          go hi (c :: acc)
      termination_by val
      String.mk (go n [])

end LeanTLS.X509
