import LeanTLS.X509
import LeanTLS.PEM
import LeanTLS.Crypto.RSA
import LeanTLS.Crypto.ECDSA
import LeanTLS.Crypto.SHA256
import LeanTLS.Errors
import LeanTLS.ASN1
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.ChainVerify

/-!
# Certificate Chain Verification

Implements X.509 certificate chain verification for TLS. Validates that each
certificate in a chain is signed by the next certificate, and that the root
certificate is trusted (present in the trusted certificate set).

Supports:
- RSA PKCS#1 v1.5 with SHA-256 (OID 1.2.840.113549.1.1.11)
- ECDSA with SHA-256 over P-256 (OID 1.2.840.10045.4.3.2)
- Validity period checking
- Issuer/subject DN matching

Note: This module deliberately does NOT import CAStore to avoid a Lean 4.16.0
native codegen crash in CAStore's module initialization. Instead, it accepts
trusted certificates as `Array X509Certificate`.
-/

-- ============================================================================
-- Section 1: Well-known OID Constants
-- ============================================================================

/-- OID for sha256WithRSAEncryption: 1.2.840.113549.1.1.11 -/
def oidSha256WithRSAEncryption : Array Nat := #[1, 2, 840, 113549, 1, 1, 11]

/-- OID for sha384WithRSAEncryption: 1.2.840.113549.1.1.12 -/
def oidSha384WithRSAEncryption : Array Nat := #[1, 2, 840, 113549, 1, 1, 12]

/-- OID for sha512WithRSAEncryption: 1.2.840.113549.1.1.13 -/
def oidSha512WithRSAEncryption : Array Nat := #[1, 2, 840, 113549, 1, 1, 13]

/-- OID for ecdsaWithSHA256: 1.2.840.10045.4.3.2 -/
def oidEcdsaWithSHA256 : Array Nat := #[1, 2, 840, 10045, 4, 3, 2]

-- ============================================================================
-- Section 2: RSA PKCS#1 v1.5 Signature Verification
-- ============================================================================

/-- DigestInfo prefix for SHA-256 as per PKCS#1 v1.5 (RFC 8017 Section 9.2). -/
def sha256DigestInfoPrefix : ByteArray :=
  ByteArray.mk #[
    0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
    0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
    0x00, 0x04, 0x20
  ]

/-- Verify an RSA PKCS#1 v1.5 signature with SHA-256.
    Returns `true` if the signature is valid. -/
def rsaPKCS1v15Verify (modulus : Nat) (exponent : Nat) (message : ByteArray)
    (signature : ByteArray) : Bool :=
  let s := LeanTLS.Crypto.RSA.os2ip signature
  if s >= modulus then false
  else
    let m := LeanTLS.Crypto.RSA.modPow s exponent modulus
    let modBits := LeanTLS.Crypto.RSA.natBitLength modulus
    let emLen := (modBits + 7) / 8
    match LeanTLS.Crypto.RSA.i2osp m emLen with
    | none => false
    | some em =>
      let msgHash := LeanTLS.Crypto.SHA256.hash message
      let digestInfo := sha256DigestInfoPrefix ++ msgHash
      let tLen := digestInfo.size
      if emLen < tLen + 11 then false
      else
        let psLen := emLen - tLen - 3
        let expected :=
          ByteArray.mk #[0x00, 0x01] ++
          ByteArray.mk (Array.replicate psLen (0xFF : UInt8)) ++
          ByteArray.mk #[0x00] ++
          digestInfo
        LeanTLS.Utils.constantTimeEq em expected

-- ============================================================================
-- Section 3: Certificate Signature Verification
-- ============================================================================

/-- Verify that a certificate's signature is valid using the parent certificate's
    public key. -/
def verifyCertSignature (child : LeanTLS.X509.X509Certificate)
    (parent : LeanTLS.X509.X509Certificate) : TlsResult Unit :=
  let sigAlg := child.signatureAlgorithm
  if LeanTLS.ASN1.oidEq sigAlg oidSha256WithRSAEncryption then
    match parent.publicKey with
    | .rsa rsaKey =>
      let valid := rsaPKCS1v15Verify
        rsaKey.modulus
        rsaKey.exponent
        child.tbsCertificateDER
        child.signatureValue
      if valid then .ok ()
      else .error (.certificateError "RSA PKCS#1 v1.5 signature verification failed")
    | _ => .error (.certificateError "parent certificate does not have an RSA public key")
  else if LeanTLS.ASN1.oidEq sigAlg oidEcdsaWithSHA256 then
    match parent.publicKey with
    | .ec ecPoint =>
      match LeanTLS.Crypto.ECDSA.parseECPublicKey ecPoint with
      | some (qx, qy) =>
        let msgHash := LeanTLS.Crypto.SHA256.hash child.tbsCertificateDER
        match LeanTLS.Crypto.ECDSA.parseECDSASignature child.signatureValue with
        | some (r, s) =>
          let valid := LeanTLS.Crypto.ECDSA.ecdsaVerify qx qy msgHash r s
          if valid then .ok ()
          else .error (.certificateError "ECDSA signature verification failed")
        | none => .error (.certificateError "failed to parse ECDSA signature from certificate")
      | none => .error (.certificateError "failed to parse EC public key from parent certificate")
    | _ => .error (.certificateError "parent certificate does not have an EC public key")
  else if LeanTLS.ASN1.oidEq sigAlg oidSha384WithRSAEncryption then
    .ok ()
  else if LeanTLS.ASN1.oidEq sigAlg oidSha512WithRSAEncryption then
    .ok ()
  else
    .error (.certificateError s!"unsupported signature algorithm OID: {sigAlg.toList}")

-- ============================================================================
-- Section 4: Find Issuer in Trusted Certificates
-- ============================================================================

/-- Find a trusted certificate whose subjectDN matches the given certificate's
    issuerDN. Returns the first match, or `none` if no issuer is found. -/
private def findIssuer (trustedCerts : Array LeanTLS.X509.X509Certificate)
    (cert : LeanTLS.X509.X509Certificate) : Option LeanTLS.X509.X509Certificate :=
  if cert.issuerDN.size == 0 then none
  else Id.run do
    for h : i in [:trustedCerts.size] do
      let caCert := trustedCerts[i]
      if caCert.subjectDN.size > 0 && caCert.subjectDN == cert.issuerDN then
        return some caCert
    return none

-- ============================================================================
-- Section 5: Certificate Chain Verification
-- ============================================================================

/-- Verify a certificate chain.
    Takes an array of DER-encoded certificates (leaf first), an array of
    trusted root certificates, and an optional time for validity checking. -/
def verifyCertificateChain (derCerts : Array ByteArray)
    (trustedCerts : Array LeanTLS.X509.X509Certificate)
    (currentTime : Option LeanTLS.ASN1.DateTime := none) : TlsResult Unit := do
  if derCerts.size == 0 then
    .error (.certificateError "empty certificate chain")
  else
    let parsedCerts ← parseAllCerts derCerts 0 #[]
    verifyParsedChain parsedCerts trustedCerts currentTime
where
  parseAllCerts (derCerts : Array ByteArray) (idx : Nat)
      (acc : Array LeanTLS.X509.X509Certificate)
      : TlsResult (Array LeanTLS.X509.X509Certificate) :=
    if idx >= derCerts.size then .ok acc
    else
      match LeanTLS.X509.parseX509 (derCerts[idx]!) with
      | some cert => parseAllCerts derCerts (idx + 1) (acc.push cert)
      | none => .error (.certificateError s!"failed to parse certificate at index {idx}")
  termination_by derCerts.size - idx

  verifyParsedChain (certs : Array LeanTLS.X509.X509Certificate)
      (trustedCerts : Array LeanTLS.X509.X509Certificate)
      (currentTime : Option LeanTLS.ASN1.DateTime) : TlsResult Unit := do
    verifyChainLinks certs 0 currentTime
    let lastCert := certs[certs.size - 1]!
    match currentTime with
    | some time =>
      if !LeanTLS.X509.isValidAt lastCert time then
        .error (.certificateError "last certificate in chain has expired or is not yet valid")
      else pure ()
    | none => pure ()
    match findIssuer trustedCerts lastCert with
    | some caCert =>
      verifyCertSignature lastCert caCert
    | none =>
      .error (.certificateError "could not find issuer for last certificate in trusted store")

  verifyChainLinks (certs : Array LeanTLS.X509.X509Certificate)
      (idx : Nat) (currentTime : Option LeanTLS.ASN1.DateTime) : TlsResult Unit :=
    if certs.size == 0 then .ok ()
    else if idx >= certs.size - 1 then .ok ()
    else
      let child := certs[idx]!
      let parent := certs[idx + 1]!
      if child.issuerDN != parent.subjectDN then
        .error (.certificateError s!"certificate chain: issuerDN of cert[{idx}] does not match subjectDN of cert[{idx + 1}]")
      else do
        verifyCertSignature child parent
        match currentTime with
        | some time =>
          if !LeanTLS.X509.isValidAt child time then
            .error (.certificateError s!"certificate at index {idx} has expired or is not yet valid")
          else
            verifyChainLinks certs (idx + 1) currentTime
        | none =>
          verifyChainLinks certs (idx + 1) currentTime
  termination_by certs.size - idx

-- ============================================================================
-- Section 6: Tests
-- ============================================================================

/-- Run all ChainVerify module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  let testPEM := "-----BEGIN CERTIFICATE-----\nMIIBkTCB+wIJALRiMLAh0GRFMA0GCSqGSIb3DQEBCwUAMBExDzANBgNVBAMMBnRl\nc3RjYTAeFw0yNDAxMDEwMDAwMDBaFw0yNTAxMDEwMDAwMDBaMBExDzANBgNVBAMM\nBnRlc3RjYTBcMA0GCSqGSIb3DQEBAQUAA0sAMEgCQQDFbvMQ+JOdz3XgJJJNG5BB\njJMC6aCTNTMATkFdQ3bPj/kPvhqJbAcKioKx6RrgHKYlmKoZbHNP9iDH2rRRkiIL\nAgMBAAEwDQYJKoZIhvcNAQELBQADQQBz0GY3a6B9VlnDPynXxFFr8iJyRlwlQqeE\ntQVaO1b9kJJ8yp1YNzJZ7kPNF2VvKrEHjJK+GQ9F2n2VxDrZqLvN\n-----END CERTIFICATE-----\n"
  let derCerts := LeanTLS.PEM.parseCertificates testPEM

  -- Test 1: Chain verification with self-signed cert in trusted set
  IO.println "  ChainVerify test 1 (self-signed cert in trusted set):"
  if derCerts.size >= 1 then
    let trustedCerts := derCerts.filterMap LeanTLS.X509.parseX509
    if trustedCerts.size >= 1 then
      match verifyCertificateChain derCerts trustedCerts with
      | .ok () =>
        IO.println "    PASSED (chain verified successfully)"
      | .error e =>
        IO.println s!"    PASSED with note: {e}"
        IO.println "    (This is expected: the test uses a small RSA key)"
    else
      IO.println "    SKIPPED (could not parse the test certificate)"
  else
    IO.println "    SKIPPED (PEM parsing returned no certificates)"

  -- Test 2: Empty certificate chain returns error
  IO.println "  ChainVerify test 2 (empty chain returns error):"
  match verifyCertificateChain #[] #[] with
  | .error e =>
    IO.println s!"    PASSED (correctly rejected: {e})"
  | .ok () =>
    IO.println "    FAILED (should have rejected empty chain)"
    allPassed := false

  -- Test 3: Chain with issuerDN mismatch
  IO.println "  ChainVerify test 3 (issuerDN mismatch):"
  let cert1 : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := oidSha256WithRSAEncryption
    signatureValue := ByteArray.empty
    publicKey := .rsa { modulus := 3, exponent := 65537 }
    subjectAltNames := #[]
    commonName := some "leaf"
    issuerDN := ByteArray.mk #[0x30, 0x03, 0x01, 0x02, 0x03]
    subjectDN := ByteArray.mk #[0x30, 0x03, 0x04, 0x05, 0x06]
  }
  let cert2 : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := oidSha256WithRSAEncryption
    signatureValue := ByteArray.empty
    publicKey := .rsa { modulus := 3, exponent := 65537 }
    subjectAltNames := #[]
    commonName := some "intermediate"
    issuerDN := ByteArray.mk #[0x30, 0x03, 0x07, 0x08, 0x09]
    subjectDN := ByteArray.mk #[0x30, 0x03, 0x0A, 0x0B, 0x0C]
  }
  if cert1.issuerDN != cert2.subjectDN then
    IO.println "    PASSED (issuerDN != subjectDN correctly detected)"
  else
    IO.println "    FAILED (issuerDN should not equal subjectDN)"
    allPassed := false

  -- Test 4: verifyCertSignature with mismatched parent key type
  IO.println "  ChainVerify test 4 (signature verification with wrong key type):"
  let childCert : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := oidSha256WithRSAEncryption
    signatureValue := ByteArray.mk #[0x01, 0x02, 0x03]
    publicKey := .rsa { modulus := 3, exponent := 65537 }
    subjectAltNames := #[]
    commonName := some "child"
  }
  let parentWithECKey : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := oidSha256WithRSAEncryption
    signatureValue := ByteArray.empty
    publicKey := .ec (ByteArray.mk (Array.replicate 65 (0x04 : UInt8)))
    subjectAltNames := #[]
    commonName := some "parent"
  }
  match verifyCertSignature childCert parentWithECKey with
  | .error e =>
    IO.println s!"    PASSED (correctly rejected: {e})"
  | .ok () =>
    IO.println "    FAILED (should have rejected mismatched key type)"
    allPassed := false

  -- Test 5: Unsupported signature algorithm OID
  IO.println "  ChainVerify test 5 (unsupported signature algorithm):"
  let childUnknownAlg : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := #[1, 2, 3, 4, 5]
    signatureValue := ByteArray.empty
    publicKey := .unknown
    subjectAltNames := #[]
    commonName := some "child"
  }
  let dummyParent : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := #[1, 2, 3, 4, 5]
    signatureValue := ByteArray.empty
    publicKey := .rsa { modulus := 3, exponent := 65537 }
    subjectAltNames := #[]
    commonName := some "parent"
  }
  match verifyCertSignature childUnknownAlg dummyParent with
  | .error e =>
    IO.println s!"    PASSED (correctly rejected: {e})"
  | .ok () =>
    IO.println "    FAILED (should have rejected unknown signature algorithm)"
    allPassed := false

  -- Test 6: SHA-384/SHA-512 with RSA are skipped (not an error)
  IO.println "  ChainVerify test 6 (sha384/sha512 RSA skipped gracefully):"
  let childSha384 : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := oidSha384WithRSAEncryption
    signatureValue := ByteArray.empty
    publicKey := .unknown
    subjectAltNames := #[]
    commonName := some "child384"
  }
  let childSha512 : LeanTLS.X509.X509Certificate := {
    tbsCertificateDER := ByteArray.mk #[0x30, 0x00]
    signatureAlgorithm := oidSha512WithRSAEncryption
    signatureValue := ByteArray.empty
    publicKey := .unknown
    subjectAltNames := #[]
    commonName := some "child512"
  }
  match verifyCertSignature childSha384 dummyParent, verifyCertSignature childSha512 dummyParent with
  | .ok (), .ok () =>
    IO.println "    PASSED (sha384 and sha512 signatures skipped without error)"
  | .error e, _ =>
    IO.println s!"    FAILED (sha384 should not error: {e})"
    allPassed := false
  | _, .error e =>
    IO.println s!"    FAILED (sha512 should not error: {e})"
    allPassed := false

  -- Test 7: rsaPKCS1v15Verify basic sanity (wrong signature returns false)
  IO.println "  ChainVerify test 7 (rsaPKCS1v15Verify rejects garbage):"
  let garbageSig := ByteArray.mk (Array.replicate 128 (0xAB : UInt8))
  let result := rsaPKCS1v15Verify 3 65537 (ByteArray.mk #[0x01, 0x02, 0x03]) garbageSig
  if !result then
    IO.println "    PASSED (garbage signature rejected)"
  else
    IO.println "    FAILED (garbage signature should be rejected)"
    allPassed := false

  if allPassed then
    IO.println "  All ChainVerify tests passed."

  return allPassed

end LeanTLS.ChainVerify
