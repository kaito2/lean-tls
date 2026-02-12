import LeanTLS.X509
import LeanTLS.Crypto.RSA
import LeanTLS.Crypto.SHA256
import LeanTLS.Handshake
import LeanTLS.Errors
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.CertVerify

/-!
# TLS 1.3 Certificate Verification (RFC 8446 Section 4.4)

Implements parsing of Certificate and CertificateVerify handshake messages,
RSA-PSS signature verification of the server's CertificateVerify, and
hostname matching against the server certificate's SAN/CN.
-/

-- ============================================================================
-- Section 1: Certificate message parsing (RFC 8446 Section 4.4.2)
-- ============================================================================

/-- Parsed TLS Certificate message. -/
structure CertificateMessage where
  requestContext : ByteArray
  certificates : Array ByteArray  -- Array of DER-encoded certificates (leaf first)

/-- Parse a TLS 1.3 Certificate message payload.
    Wire format:
      certificate_request_context: 1-byte length + data
      certificate_list: 3-byte length + CertificateEntry[]
    Each CertificateEntry:
      cert_data: 3-byte length + DER bytes
      extensions: 2-byte length + extension data -/
def parseCertificateMessage (payload : ByteArray) : Option CertificateMessage :=
  if payload.size < 4 then none
  else
    -- certificate_request_context: 1-byte length + data
    let ctxLen := (payload.get! 0).toNat
    let pos := 1
    if pos + ctxLen > payload.size then none
    else
      let requestContext := payload.extract pos (pos + ctxLen)
      let pos := pos + ctxLen
      -- certificate_list: 3-byte length
      match LeanTLS.Handshake.decodeUInt24BE payload pos with
      | none => none
      | some listLen =>
        let pos := pos + 3
        let listEnd := pos + listLen.toNat
        if listEnd > payload.size then none
        else
          -- Parse CertificateEntry items using a recursive helper
          parseCertEntries payload pos listEnd requestContext #[]
where
  parseCertEntries (payload : ByteArray) (pos : Nat) (listEnd : Nat)
      (requestContext : ByteArray) (certs : Array ByteArray) : Option CertificateMessage :=
    if pos >= listEnd then
      some { requestContext := requestContext, certificates := certs }
    else
      -- cert_data: 3-byte length + DER bytes
      match LeanTLS.Handshake.decodeUInt24BE payload pos with
      | none => none
      | some certLen =>
        let pos := pos + 3
        let certEnd := pos + certLen.toNat
        if certEnd > listEnd then none
        else
          let certData := payload.extract pos certEnd
          let pos := certEnd
          -- extensions: 2-byte length + data
          if pos + 2 > listEnd then none
          else
            match LeanTLS.Handshake.decodeUInt16BE payload pos with
            | none => none
            | some extLen =>
              let pos := pos + 2 + extLen.toNat
              parseCertEntries payload pos listEnd requestContext (certs.push certData)
  termination_by listEnd - pos

-- ============================================================================
-- Section 2: CertificateVerify message parsing (RFC 8446 Section 4.4.3)
-- ============================================================================

/-- Parsed TLS CertificateVerify message. -/
structure CertificateVerifyMessage where
  algorithm : UInt16
  signature : ByteArray

/-- Parse a TLS 1.3 CertificateVerify message payload.
    Wire format: algorithm(2 bytes) + signature(2-byte length + data) -/
def parseCertificateVerifyMessage (payload : ByteArray) : Option CertificateVerifyMessage :=
  if payload.size < 4 then none
  else
    match LeanTLS.Handshake.decodeUInt16BE payload 0, LeanTLS.Handshake.decodeUInt16BE payload 2 with
    | some algorithm, some sigLen =>
      let sigStart : Nat := 4
      let sigEnd := sigStart + sigLen.toNat
      if sigEnd > payload.size then none
      else
        let signature := payload.extract sigStart sigEnd
        some { algorithm := algorithm, signature := signature }
    | _, _ => none

-- ============================================================================
-- Section 3: CertificateVerify signed content construction
-- ============================================================================

/-- Build the content that is signed in a TLS 1.3 server CertificateVerify.
    RFC 8446 Section 4.4.3:
      64 × 0x20 (space) + "TLS 1.3, server CertificateVerify" + 0x00 + transcript_hash
    Total: 64 + 33 + 1 + 32 = 130 bytes -/
def buildCertificateVerifyContent (transcriptHash : ByteArray) : ByteArray :=
  let spaces := ByteArray.mk (Array.mkArray 64 (0x20 : UInt8))
  let context := "TLS 1.3, server CertificateVerify".toUTF8
  let separator := ByteArray.mk #[0x00]
  spaces ++ context ++ separator ++ transcriptHash

-- ============================================================================
-- Section 4: Signature verification
-- ============================================================================

/-- Verify the CertificateVerify signature using the server's certificate.
    Currently supports rsa_pss_rsae_sha256 (0x0804) only.
    ECDSA (0x0403) returns an error. -/
def verifyCertificateVerifySignature
    (leafCert : LeanTLS.X509.X509Certificate)
    (transcriptHash : ByteArray)
    (cvMsg : CertificateVerifyMessage) : TlsResult Bool :=
  if cvMsg.algorithm == 0x0804 then
    -- rsa_pss_rsae_sha256
    let signedContent := buildCertificateVerifyContent transcriptHash
    let result := LeanTLS.Crypto.RSA.rsassaPSSVerify
      leafCert.publicKey.modulus
      leafCert.publicKey.exponent
      signedContent
      cvMsg.signature
    .ok result
  else if cvMsg.algorithm == 0x0403 then
    .error (.certificateError "ECDSA signature verification not yet implemented (algorithm 0x0403)")
  else
    .error (.certificateError s!"unsupported signature algorithm: 0x{sigAlgHex cvMsg.algorithm}")
where
  sigAlgHex (alg : UInt16) : String :=
    LeanTLS.Utils.bytesToHex (ByteArray.mk #[(alg >>> 8).toUInt8, alg.toUInt8])

-- ============================================================================
-- Section 5: Hostname verification
-- ============================================================================

/-- Convert a string to lowercase for case-insensitive comparison. -/
private def toLower (s : String) : String :=
  String.mk (s.toList.map fun c =>
    if 'A' ≤ c ∧ c ≤ 'Z' then Char.ofNat (c.toNat - 'A'.toNat + 'a'.toNat)
    else c)

/-- Match a hostname against a certificate name pattern.
    Supports wildcard matching per RFC 6125:
    - "*.example.com" matches "www.example.com" but not "example.com"
      and not "sub.www.example.com"
    - Exact case-insensitive match otherwise. -/
def matchHostname (hostname : String) (pattern : String) : Bool :=
  let h := toLower hostname
  let p := toLower pattern
  if p.startsWith "*." then
    let suffix := p.drop 2  -- drop "*."
    -- hostname must have exactly one more label (no additional dots in prefix)
    match h.splitOn "." with
    | _ :: rest =>
      let parentDomain := ".".intercalate rest
      parentDomain == suffix
    | _ => false
  else
    h == p

/-- Verify that the hostname matches the certificate's SAN or CN.
    Checks SAN first (per RFC 6125), falls back to CN if SAN is empty. -/
def verifyHostname (cert : LeanTLS.X509.X509Certificate) (hostname : String) : TlsResult Unit :=
  if cert.subjectAltNames.size > 0 then
    if cert.subjectAltNames.any (matchHostname hostname ·) then
      .ok ()
    else
      .error (.certificateError s!"hostname '{hostname}' does not match certificate SAN entries")
  else
    match cert.commonName with
    | some cn =>
      if matchHostname hostname cn then .ok ()
      else .error (.certificateError s!"hostname '{hostname}' does not match certificate CN '{cn}'")
    | none =>
      .error (.certificateError s!"certificate has no SAN or CN to verify hostname '{hostname}'")

-- ============================================================================
-- Section 6: Top-level verification orchestrator
-- ============================================================================

/-- Verify a server certificate and its CertificateVerify signature.
    This is the main entry point called from Connection.lean during the handshake.

    Parameters:
    - certPayload: raw Certificate message payload (without handshake header)
    - cvPayload: raw CertificateVerify message payload (without handshake header)
    - transcriptHash: SHA-256 transcript hash of messages up to (not including) CertificateVerify
    - hostname: server hostname for SAN/CN verification -/
def verifyCertificate
    (certPayload : ByteArray) (cvPayload : ByteArray)
    (transcriptHash : ByteArray) (hostname : String) : TlsResult Unit := do
  -- Parse the Certificate message
  let certMsg ← match parseCertificateMessage certPayload with
    | some msg => .ok msg
    | none => .error (.certificateError "failed to parse Certificate message")
  -- Must have at least one certificate
  if certMsg.certificates.size == 0 then
    .error (.certificateError "server sent empty certificate chain")
  else
    -- Parse the leaf certificate (first in chain)
    let leafDer := certMsg.certificates.get! 0
    let leafCert ← match LeanTLS.X509.parseX509 leafDer with
      | some cert => .ok cert
      | none => .error (.certificateError "failed to parse leaf X.509 certificate")
    -- Parse CertificateVerify message
    let cvMsg ← match parseCertificateVerifyMessage cvPayload with
      | some msg => .ok msg
      | none => .error (.certificateError "failed to parse CertificateVerify message")
    -- Verify the CertificateVerify signature
    let sigOk ← verifyCertificateVerifySignature leafCert transcriptHash cvMsg
    if !sigOk then
      .error (.certificateError "CertificateVerify signature verification failed")
    else
      -- Verify hostname
      verifyHostname leafCert hostname

-- ============================================================================
-- Section 7: Tests
-- ============================================================================

/-- Run all CertVerify module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- --------------------------------------------------------------------------
  -- Test 1: buildCertificateVerifyContent
  -- --------------------------------------------------------------------------
  IO.println "  CertVerify test 1 (buildCertificateVerifyContent):"
  let dummyHash := ByteArray.mk (Array.mkArray 32 (0xAA : UInt8))
  let content := buildCertificateVerifyContent dummyHash
  -- Should be 64 + 33 + 1 + 32 = 130 bytes
  if content.size != 130 then
    IO.println s!"    FAILED (expected 130 bytes, got {content.size})"
    allPassed := false
  else
    -- First 64 bytes should be 0x20
    let spacesOk := Nat.fold (n := 64) (init := true) fun i _ acc =>
      acc && (content.get! i == 0x20)
    -- Byte 97 (64 + 33) should be 0x00 separator
    let sepOk := content.get! 97 == 0x00
    -- Last 32 bytes should be the hash
    let hashOk := Nat.fold (n := 32) (init := true) fun i _ acc =>
      acc && (content.get! (98 + i) == 0xAA)
    if spacesOk && sepOk && hashOk then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (spacesOk={spacesOk}, sepOk={sepOk}, hashOk={hashOk})"
      allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: parseCertificateVerifyMessage
  -- --------------------------------------------------------------------------
  IO.println "  CertVerify test 2 (parseCertificateVerifyMessage):"
  -- algorithm = 0x0804, signature = 4 bytes "AABBCCDD"
  let cvBytes := LeanTLS.Utils.hexToBytes "08040004AABBCCDD"
  match parseCertificateVerifyMessage cvBytes with
  | some msg =>
    if msg.algorithm == 0x0804 && msg.signature.size == 4 then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (algorithm={msg.algorithm}, sigLen={msg.signature.size})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: matchHostname
  -- --------------------------------------------------------------------------
  IO.println "  CertVerify test 3 (matchHostname):"
  let mut test3Ok := true

  -- Exact match
  if !matchHostname "example.com" "example.com" then
    IO.println "    FAILED: exact match 'example.com'"
    test3Ok := false

  -- Case insensitive
  if !matchHostname "Example.COM" "example.com" then
    IO.println "    FAILED: case insensitive"
    test3Ok := false

  -- Wildcard match
  if !matchHostname "www.example.com" "*.example.com" then
    IO.println "    FAILED: wildcard 'www.example.com' vs '*.example.com'"
    test3Ok := false

  -- Wildcard should NOT match bare domain
  if matchHostname "example.com" "*.example.com" then
    IO.println "    FAILED: wildcard should not match bare domain"
    test3Ok := false

  -- Wildcard should NOT match multi-level subdomain
  if matchHostname "sub.www.example.com" "*.example.com" then
    IO.println "    FAILED: wildcard should not match multi-level subdomain"
    test3Ok := false

  -- No match
  if matchHostname "other.com" "example.com" then
    IO.println "    FAILED: should not match 'other.com'"
    test3Ok := false

  if test3Ok then
    IO.println "    PASSED"
  else
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 4: verifyHostname with SAN
  -- --------------------------------------------------------------------------
  IO.println "  CertVerify test 4 (verifyHostname):"
  let testCert : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.empty
    signatureAlgorithm := #[]
    signatureValue := ByteArray.empty
    publicKey := { modulus := 0, exponent := 0 }
    subjectAltNames := #["example.com", "*.example.com"]
    commonName := some "Example Inc"
  }

  match verifyHostname testCert "example.com" with
  | .ok () =>
    match verifyHostname testCert "www.example.com" with
    | .ok () =>
      match verifyHostname testCert "other.com" with
      | .error _ => IO.println "    PASSED"
      | .ok () =>
        IO.println "    FAILED: should reject 'other.com'"
        allPassed := false
    | .error e =>
      IO.println s!"    FAILED: www.example.com should match: {e}"
      allPassed := false
  | .error e =>
    IO.println s!"    FAILED: example.com should match: {e}"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 5: parseCertificateMessage
  -- --------------------------------------------------------------------------
  IO.println "  CertVerify test 5 (parseCertificateMessage):"
  -- Build a minimal Certificate message:
  -- context: 00 (empty, 1-byte length)
  -- certificate_list: 3-byte length + one CertificateEntry
  -- CertificateEntry: cert_data (3-byte length + 3 bytes "AABBCC") + extensions (2-byte length + 0 bytes)
  let certEntryData := LeanTLS.Utils.hexToBytes "AABBCC"
  -- cert_data: 000003 AABBCC
  -- extensions: 0000
  let certEntry := LeanTLS.Utils.hexToBytes "000003AABBCC0000"
  -- certificate_list length = 8 bytes
  let certListLen := LeanTLS.Utils.hexToBytes "000008"
  -- context = 00
  let certMsgPayload := ByteArray.mk #[0x00] ++ certListLen ++ certEntry
  match parseCertificateMessage certMsgPayload with
  | some msg =>
    if msg.certificates.size == 1 && msg.certificates.get! 0 == certEntryData then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (numCerts={msg.certificates.size})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  if allPassed then
    IO.println "  All CertVerify tests passed."

  return allPassed

end LeanTLS.CertVerify
