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


/-- Parsed X.509 certificate (subset relevant for TLS verification). -/
structure X509Certificate where
  tbsCertificateDER : ByteArray        -- Raw DER bytes for signature verification
  signatureAlgorithm : Array Nat       -- OID components
  signatureValue : ByteArray           -- Raw signature bytes (BIT STRING content without unused-bits byte)
  publicKey : RSAPublicKey             -- Extracted RSA public key
  subjectAltNames : Array String       -- DNS names from SAN extension
  commonName : Option String           -- CN from Subject

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
      let children := seqNode.getChildren
      if children.size < 2 then none
      else
        let modNode := children.get! 0
        let expNode := children.get! 1
        -- Both should be INTEGERs (universal, tag number 2)
        let modTag := modNode.getTag
        let expTag := expNode.getTag
        if modTag.tagNumber != 2 || expTag.tagNumber != 2 then none
        else
          let modulus := ASN1.parseInteger modNode.getValue
          let exponent := ASN1.parseInteger expNode.getValue
          some { modulus := modulus, exponent := exponent }

-- ============================================================================
-- Section 4: SubjectPublicKeyInfo Parsing
-- ============================================================================

/-- Parse SubjectPublicKeyInfo to extract the RSA public key.
    SubjectPublicKeyInfo ::= SEQUENCE {
      algorithm  AlgorithmIdentifier,  -- SEQUENCE { OID, NULL or params }
      subjectPublicKey BIT STRING
    }
-/
def parseSubjectPublicKeyInfo (node : ASN1.ASN1Node) : Option RSAPublicKey := do
  let children := node.getChildren
  if children.size < 2 then none
  else
    -- First child: AlgorithmIdentifier SEQUENCE
    let algId := children.get! 0
    let algChildren := algId.getChildren
    if algChildren.size < 1 then none
    else
      -- Extract the OID
      let oidNode := algChildren.get! 0
      let oidTag := oidNode.getTag
      if oidTag.tagNumber != 6 || oidTag.tagClass != .universal then none
      else
        let oid ← ASN1.parseOID oidNode.getValue
        -- Verify it is rsaEncryption
        if !ASN1.oidEq oid ASN1.oidRsaEncryption then none
        else
          -- Second child: BIT STRING containing the RSA public key
          let pubKeyBitString := children.get! 1
          let bsTag := pubKeyBitString.getTag
          if bsTag.tagNumber != 3 || bsTag.tagClass != .universal then none
          else
            parseRSAPublicKey pubKeyBitString.getValue

-- ============================================================================
-- Section 5: Subject Common Name Extraction
-- ============================================================================

/-- Parse the Subject field to extract the Common Name (CN).
    Subject is a Name ::= SEQUENCE OF RelativeDistinguishedName
    RDN ::= SET OF AttributeTypeAndValue
    ATAV ::= SEQUENCE { type OID, value ANY }
-/
def parseSubjectCN (subjectNode : ASN1.ASN1Node) : Option String :=
  let rdnSeq := subjectNode.getChildren
  -- Walk each RDN (SET)
  let rec goRDN (i : Nat) : Option String :=
    if i >= rdnSeq.size then none
    else
      let rdn := rdnSeq.get! i
      let atvs := rdn.getChildren
      -- Walk each ATV (SEQUENCE) in the SET
      let rec goATV (j : Nat) : Option String :=
        if j >= atvs.size then none
        else
          let atv := atvs.get! j
          let atvChildren := atv.getChildren
          if atvChildren.size < 2 then goATV (j + 1)
          else
            let oidNode := atvChildren.get! 0
            let oidTag := oidNode.getTag
            if oidTag.tagNumber != 6 || oidTag.tagClass != .universal then goATV (j + 1)
            else
              match ASN1.parseOID oidNode.getValue with
              | none => goATV (j + 1)
              | some oid =>
                if ASN1.oidEq oid ASN1.oidCommonName then
                  let valNode := atvChildren.get! 1
                  some (bytesToString valNode.getValue)
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
  let exts := extensionsNode.getChildren
  let rec goExt (i : Nat) (acc : Array String) : Array String :=
    if i >= exts.size then acc
    else
      let ext := exts.get! i
      let extChildren := ext.getChildren
      -- Extension must have at least 2 children (OID + OCTET STRING),
      -- optionally 3 if critical BOOLEAN is present
      if extChildren.size < 2 then goExt (i + 1) acc
      else
        let oidNode := extChildren.get! 0
        let oidTag := oidNode.getTag
        if oidTag.tagNumber != 6 || oidTag.tagClass != .universal then goExt (i + 1) acc
        else
          match ASN1.parseOID oidNode.getValue with
          | none => goExt (i + 1) acc
          | some oid =>
            if !ASN1.oidEq oid ASN1.oidSubjectAltName then goExt (i + 1) acc
            else
              -- The OCTET STRING is the last child (may be index 1 or 2 depending on critical flag)
              let octetIdx := extChildren.size - 1
              let octetNode := extChildren.get! octetIdx
              let octetTag := octetNode.getTag
              -- Should be OCTET STRING (tag 4, universal)
              if octetTag.tagNumber != 4 || octetTag.tagClass != .universal then goExt (i + 1) acc
              else
                -- Parse the OCTET STRING content as GeneralNames SEQUENCE
                let octetValue := octetNode.getValue
                match ASN1.parseAll octetValue with
                | none => goExt (i + 1) acc
                | some generalNamesSeq =>
                  let names := generalNamesSeq.getChildren
                  let rec goDNS (j : Nat) (dnsAcc : Array String) : Array String :=
                    if j >= names.size then dnsAcc
                    else
                      let name := names.get! j
                      let nameTag := name.getTag
                      -- dNSName: context-specific, tag number 2, primitive
                      if nameTag.tagClass == .contextSpecific && nameTag.tagNumber == 2 then
                        let dnsName := bytesToString name.getValue
                        goDNS (j + 1) (dnsAcc.push dnsName)
                      else
                        goDNS (j + 1) dnsAcc
                  termination_by names.size - j
                  goExt (i + 1) (goDNS 0 acc)
  termination_by exts.size - i
  goExt 0 #[]

-- ============================================================================
-- Section 7: Main Certificate Parser
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
  let outerChildren := outerNode.getChildren
  if outerChildren.size < 3 then none
  else
    -- Determine where the outer SEQUENCE value region starts
    let (_, outerValueStart, _) ← parseTagAndLength der 0
    -- Parse the first child (TBSCertificate) from the raw DER to get its exact byte boundaries
    let (_, tbsEnd) ← ASN1.parseTLV der outerValueStart
    let tbsCertificateDER := der.extract outerValueStart tbsEnd

    -- Extract TBSCertificate from the parsed tree
    let tbsNode := outerChildren.get! 0

    -- Extract signature algorithm OID from the second child
    let sigAlgNode := outerChildren.get! 1
    let sigAlgChildren := sigAlgNode.getChildren
    if sigAlgChildren.size < 1 then none
    else
      let sigAlgOidNode := sigAlgChildren.get! 0
      let sigAlgOidTag := sigAlgOidNode.getTag
      if sigAlgOidTag.tagNumber != 6 || sigAlgOidTag.tagClass != .universal then none
      else
        let signatureAlgorithm ← ASN1.parseOID sigAlgOidNode.getValue

        -- Extract signature value from the third child (BIT STRING)
        let sigValNode := outerChildren.get! 2
        let sigValTag := sigValNode.getTag
        if sigValTag.tagNumber != 3 || sigValTag.tagClass != .universal then none
        else
          let sigRaw := sigValNode.getValue
          -- Skip the unused-bits byte (first byte, should be 0x00)
          if sigRaw.size < 1 then none
          else
            let signatureValue := sigRaw.extract 1 sigRaw.size

            -- Parse TBSCertificate fields
            let tbsChildren := tbsNode.getChildren
            if tbsChildren.size < 6 then none
            else
              -- Detect version tag: if first child is context-specific tag 0,
              -- it is the explicit version wrapper (v3 certificates)
              let firstTag := (tbsChildren.get! 0).getTag
              let hasVersion := firstTag.tagClass == .contextSpecific && firstTag.tagNumber == 0
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
                let subjectNode := tbsChildren.get! subjectIdx
                let spkiNode := tbsChildren.get! spkiIdx

                -- Extract CN from subject
                let commonName := parseSubjectCN subjectNode

                -- Extract RSA public key from SubjectPublicKeyInfo
                let publicKey ← parseSubjectPublicKeyInfo spkiNode

                -- Extract SAN from extensions (if present)
                let subjectAltNames :=
                  if extIdx < tbsChildren.size then
                    let extWrapper := tbsChildren.get! extIdx
                    let extWrapperTag := extWrapper.getTag
                    -- Extensions are wrapped in context-specific tag [3] constructed
                    if extWrapperTag.tagClass == .contextSpecific && extWrapperTag.tagNumber == 3 then
                      let extWrapperChildren := extWrapper.getChildren
                      if extWrapperChildren.size >= 1 then
                        parseSAN (extWrapperChildren.get! 0)
                      else #[]
                    else #[]
                  else #[]

                some {
                  tbsCertificateDER := tbsCertificateDER
                  signatureAlgorithm := signatureAlgorithm
                  signatureValue := signatureValue
                  publicKey := publicKey
                  subjectAltNames := subjectAltNames
                  commonName := commonName
                }

-- ============================================================================
-- Section 8: Tests
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

    -- Check exponent
    if cert.publicKey.exponent == 65537 then
      IO.println "    Exponent = 65537: PASSED"
    else
      IO.println s!"    Exponent: FAILED (expected 65537, got {cert.publicKey.exponent})"
      allPassed := false

    -- Check modulus hex starts with "ca18de9a"
    let modBytes := LeanTLS.Utils.bytesToHex (LeanTLS.Utils.hexToBytes "ca18de9a")
    let modHex := modulusToHex cert.publicKey.modulus
    if modHex.take 8 == modBytes then
      IO.println "    Modulus starts with ca18de9a: PASSED"
    else
      IO.println s!"    Modulus: FAILED (expected prefix 'ca18de9a', got '{modHex.take 8}')"
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
