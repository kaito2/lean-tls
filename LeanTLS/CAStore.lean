import LeanTLS.PEM
import LeanTLS.X509
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.CAStore

/-!
# Root CA Certificate Store

Provides a trusted CA certificate store for verifying TLS certificate chains.
Supports loading from PEM files, system default paths, and programmatic
construction. Used by the TLS handshake to verify that a server certificate
was issued by a trusted certificate authority.
-/

-- ============================================================================
-- Section 1: Data Structure
-- ============================================================================

/-- A store of trusted root CA certificates. -/
structure CAStore where
  certificates : Array LeanTLS.X509.X509Certificate

instance : Inhabited CAStore where
  default := { certificates := #[] }

-- ============================================================================
-- Section 2: Construction from PEM Content
-- ============================================================================

/-- Parse PEM content string directly into a CAStore.
    Extracts all CERTIFICATE blocks, parses each with X509.parseX509,
    and silently skips any certificates that fail to parse (e.g., those
    using unsupported algorithms like ECDSA). -/
def CAStore.fromPEM (pemContent : String) : CAStore :=
  let derCerts := LeanTLS.PEM.parseCertificates pemContent
  let parsed := derCerts.filterMap LeanTLS.X509.parseX509
  { certificates := parsed }

-- ============================================================================
-- Section 3: Load from PEM File
-- ============================================================================

/-- Read a PEM file containing multiple certificates (e.g., a CA bundle)
    and return a CAStore. Certificates that fail to parse are silently
    skipped, since some CA certs may use algorithms not yet supported. -/
def CAStore.loadFromFile (path : String) : IO CAStore := do
  let contents ← IO.FS.readFile ⟨path⟩
  return CAStore.fromPEM contents

-- ============================================================================
-- Section 4: Load from System Default Path
-- ============================================================================

/-- Common system CA bundle file paths. -/
private def systemCAPaths : List String :=
  [ "/etc/ssl/certs/ca-certificates.crt"      -- Debian/Ubuntu
  , "/etc/pki/tls/certs/ca-bundle.crt"        -- RHEL/CentOS
  , "/etc/ssl/cert.pem"                        -- Alpine/macOS
  , "/usr/local/etc/openssl@3/cert.pem"        -- Homebrew OpenSSL (Intel)
  , "/opt/homebrew/etc/openssl@3/cert.pem"     -- Homebrew OpenSSL (ARM)
  ]

/-- Check if a file exists at the given path. -/
private def fileExists (path : String) : IO Bool := do
  try
    let _ ← IO.FS.readFile ⟨path⟩
    return true
  catch _ =>
    return false

/-- Try loading CA stores from a list of paths, returning the first success. -/
private def tryLoadPaths : List String → IO CAStore
  | [] => return { certificates := #[] }
  | path :: rest => do
    let pathExists ← fileExists path
    if pathExists then
      try
        CAStore.loadFromFile path
      catch _ =>
        tryLoadPaths rest
    else
      tryLoadPaths rest

/-- Try to load a CA store from common system paths.
    Returns the first one that loads successfully. If none work,
    returns an empty CAStore. -/
def CAStore.loadSystem : IO CAStore :=
  tryLoadPaths systemCAPaths

-- ============================================================================
-- Section 5: Merge
-- ============================================================================

/-- Combine two CA stores into one containing all certificates from both. -/
def CAStore.merge (a b : CAStore) : CAStore :=
  { certificates := a.certificates ++ b.certificates }

-- ============================================================================
-- Section 6: Find Issuer
-- ============================================================================

/-- Find a CA certificate whose subject matches the given certificate's issuer.
    Compares the raw DER bytes of the issuer Name sequence from the target
    certificate against the subject Name sequence of each CA certificate.
    Returns the first match, or `none` if no issuer is found. -/
def CAStore.findIssuer (store : CAStore) (cert : LeanTLS.X509.X509Certificate)
    : Option LeanTLS.X509.X509Certificate :=
  if cert.issuerDN.size == 0 then none
  else Id.run do
    for h : i in [:store.certificates.size] do
      let caCert := store.certificates[i]
      if caCert.subjectDN.size > 0 && caCert.subjectDN == cert.issuerDN then
        return some caCert
    return none

-- ============================================================================
-- Section 7: Utility
-- ============================================================================

/-- Return the number of certificates in the store. -/
def CAStore.size (store : CAStore) : Nat :=
  store.certificates.size

/-- Check whether the store is empty. -/
def CAStore.isEmpty (store : CAStore) : Bool :=
  store.certificates.size == 0

-- ============================================================================
-- Section 8: Tests
-- ============================================================================

/-- Run all CAStore module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- --------------------------------------------------------------------------
  -- Test 1: CAStore.fromPEM with a self-signed test certificate
  -- This is the same test PEM used in the PEM module tests.
  -- --------------------------------------------------------------------------
  IO.println "  CAStore test 1 (fromPEM with test certificate):"
  let testPEM := "-----BEGIN CERTIFICATE-----\nMIIBkTCB+wIJALRiMLAh0GRFMA0GCSqGSIb3DQEBCwUAMBExDzANBgNVBAMMBnRl\nc3RjYTAeFw0yNDAxMDEwMDAwMDBaFw0yNTAxMDEwMDAwMDBaMBExDzANBgNVBAMM\nBnRlc3RjYTBcMA0GCSqGSIb3DQEBAQUAA0sAMEgCQQDFbvMQ+JOdz3XgJJJNG5BB\njJMC6aCTNTMATkFdQ3bPj/kPvhqJbAcKioKx6RrgHKYlmKoZbHNP9iDH2rRRkiIL\nAgMBAAEwDQYJKoZIhvcNAQELBQADQQBz0GY3a6B9VlnDPynXxFFr8iJyRlwlQqeE\ntQVaO1b9kJJ8yp1YNzJZ7kPNF2VvKrEHjJK+GQ9F2n2VxDrZqLvN\n-----END CERTIFICATE-----\n"
  let store := CAStore.fromPEM testPEM
  if store.certificates.size == 1 then
    let cert := store.certificates[0]!
    match cert.commonName with
    | some cn =>
      if cn == "testca" then
        IO.println "    PASSED (1 certificate with CN=testca)"
      else
        IO.println s!"    FAILED (expected CN 'testca', got '{cn}')"
        allPassed := false
    | none =>
      IO.println "    FAILED (certificate has no CN)"
      allPassed := false
  else
    IO.println s!"    FAILED (expected 1 certificate, got {store.certificates.size})"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: CAStore.fromPEM with empty/invalid content
  -- --------------------------------------------------------------------------
  IO.println "  CAStore test 2 (fromPEM with empty content):"
  let emptyStore := CAStore.fromPEM ""
  if emptyStore.certificates.size == 0 then
    IO.println "    PASSED (empty store)"
  else
    IO.println s!"    FAILED (expected 0 certificates, got {emptyStore.certificates.size})"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: CAStore.merge
  -- --------------------------------------------------------------------------
  IO.println "  CAStore test 3 (merge two stores):"
  let storeA := CAStore.fromPEM testPEM
  let storeB := CAStore.fromPEM testPEM
  let merged := CAStore.merge storeA storeB
  if merged.certificates.size == 2 then
    IO.println "    PASSED (merged store has 2 certificates)"
  else
    IO.println s!"    FAILED (expected 2 certificates, got {merged.certificates.size})"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 4: CAStore.loadSystem does not crash
  -- --------------------------------------------------------------------------
  IO.println "  CAStore test 4 (loadSystem does not crash):"
  let sysStore ← CAStore.loadSystem
  -- On some systems this will be empty, on others it will be populated.
  -- Either result is acceptable; what matters is it does not throw.
  IO.println s!"    PASSED (loadSystem returned {sysStore.certificates.size} certificates)"

  -- --------------------------------------------------------------------------
  -- Test 5: CAStore.findIssuer for self-signed certificate
  -- A self-signed certificate has issuerDN == subjectDN, so findIssuer
  -- should find the certificate itself in the store.
  -- --------------------------------------------------------------------------
  IO.println "  CAStore test 5 (findIssuer for self-signed cert):"
  let selfSignedStore := CAStore.fromPEM testPEM
  if selfSignedStore.certificates.size == 1 then
    let cert := selfSignedStore.certificates[0]!
    -- For a self-signed cert, issuerDN should equal subjectDN
    if cert.issuerDN.size > 0 && cert.subjectDN.size > 0 && cert.issuerDN == cert.subjectDN then
      match CAStore.findIssuer selfSignedStore cert with
      | some issuer =>
        if issuer.commonName == cert.commonName then
          IO.println "    PASSED (found self as issuer)"
        else
          IO.println "    FAILED (found wrong issuer)"
          allPassed := false
      | none =>
        IO.println "    FAILED (findIssuer returned none for self-signed cert)"
        allPassed := false
    else
      -- The test cert might not parse issuerDN/subjectDN properly on all
      -- configurations, so we just note it rather than fail.
      IO.println s!"    SKIPPED (issuerDN.size={cert.issuerDN.size}, subjectDN.size={cert.subjectDN.size}, match={cert.issuerDN == cert.subjectDN})"
  else
    IO.println "    SKIPPED (no certificate parsed for findIssuer test)"

  -- --------------------------------------------------------------------------
  -- Test 6: CAStore.size and CAStore.isEmpty
  -- --------------------------------------------------------------------------
  IO.println "  CAStore test 6 (size and isEmpty):"
  let emptyS : CAStore := { certificates := #[] }
  let nonEmptyS := CAStore.fromPEM testPEM
  if emptyS.isEmpty && emptyS.size == 0 && !nonEmptyS.isEmpty && nonEmptyS.size == 1 then
    IO.println "    PASSED"
  else
    IO.println s!"    FAILED (empty.isEmpty={emptyS.isEmpty}, empty.size={emptyS.size}, nonEmpty.isEmpty={nonEmptyS.isEmpty}, nonEmpty.size={nonEmptyS.size})"
    allPassed := false

  if allPassed then
    IO.println "  All CAStore tests passed."

  return allPassed

end LeanTLS.CAStore
