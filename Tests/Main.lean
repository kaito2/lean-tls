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

  if allOk then
    IO.println "All tests passed!"
  else
    IO.println "Some tests failed!"
    IO.Process.exit 1
