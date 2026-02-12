import LeanTLS

def main : IO Unit := do
  let mut allOk := true

  IO.println "Running AES-128 tests..."
  let aesOk ← LeanTLS.Crypto.AES.runTests
  if !aesOk then allOk := false

  IO.println "Running SHA-256 tests..."
  let sha256Ok ← LeanTLS.Crypto.SHA256.runTests
  if !sha256Ok then allOk := false

  IO.println "Running X25519 tests..."
  let x25519Ok ← LeanTLS.Crypto.X25519.runTests
  if !x25519Ok then allOk := false

  IO.println "Running HMAC-SHA-256 tests..."
  let hmacOk ← LeanTLS.Crypto.HMAC.runTests
  if !hmacOk then allOk := false

  IO.println "Running AES-128-GCM tests..."
  let gcmOk ← LeanTLS.Crypto.GCM.runTests
  if !gcmOk then allOk := false

  IO.println "Running HKDF tests..."
  let hkdfOk ← LeanTLS.Crypto.HKDF.runTests
  if !hkdfOk then allOk := false

  IO.println "Running TLS Record layer tests..."
  let recordOk ← LeanTLS.Record.runTests
  if !recordOk then allOk := false

  IO.println "Running TLS Handshake tests..."
  let hsOk ← LeanTLS.Handshake.runTests
  if !hsOk then allOk := false

  IO.println "Running TLS Key Schedule tests..."
  let ksOk ← LeanTLS.KeySchedule.runTests
  if !ksOk then allOk := false

  IO.println "Running RSA-PSS tests..."
  let rsaOk ← LeanTLS.Crypto.RSA.runTests
  if !rsaOk then allOk := false

  IO.println "Running ASN1 tests..."
  let asn1Ok ← LeanTLS.ASN1.runTests
  if !asn1Ok then allOk := false

  IO.println "Running X509 tests..."
  let x509Ok ← LeanTLS.X509.runTests
  if !x509Ok then allOk := false

  IO.println "Running CertVerify tests..."
  let cvOk ← LeanTLS.CertVerify.runTests
  if !cvOk then allOk := false

  if allOk then
    IO.println "All tests passed!"
  else
    IO.println "Some tests failed!"
    IO.Process.exit 1
