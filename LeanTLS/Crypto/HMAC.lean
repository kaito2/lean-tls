import LeanTLS.Crypto.SHA256
import LeanTLS.Crypto.SHA384
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.Crypto.HMAC

/-!
# HMAC-SHA-256 (RFC 2104)

Pure Lean 4 implementation of HMAC using SHA-256 as the underlying hash function.

HMAC(K, m) = H((K' XOR opad) || H((K' XOR ipad) || m))

where:
- H is SHA-256
- K' is the key, adjusted to the block size (64 bytes)
- ipad is 0x36 repeated 64 times
- opad is 0x5c repeated 64 times
-/

-- ============================================================================
-- Section 1: Constants
-- ============================================================================

/-- SHA-256 block size in bytes. -/
private def blockSize : Nat := 64

/-- Inner padding byte (0x36). -/
private def ipadByte : UInt8 := 0x36

/-- Outer padding byte (0x5c). -/
private def opadByte : UInt8 := 0x5c

-- ============================================================================
-- Section 2: Key preparation
-- ============================================================================

/-- Pad a ByteArray with zero bytes on the right to reach the target length.
    If the array is already at least `targetLen` bytes, it is returned unchanged. -/
private def padRight (ba : ByteArray) (targetLen : Nat) : ByteArray :=
  if ba.size >= targetLen then ba
  else
    let needed := targetLen - ba.size
    Nat.fold (n := needed) (init := ba) fun _ _ acc => acc.push 0x00

/-- Prepare the key K' for HMAC:
    - If key.size > blockSize, hash the key with SHA-256 and then zero-pad to blockSize.
    - If key.size <= blockSize, zero-pad the key to blockSize. -/
private def prepareKey (key : ByteArray) : ByteArray :=
  if key.size > blockSize then
    padRight (LeanTLS.Crypto.SHA256.hash key) blockSize
  else
    padRight key blockSize

-- ============================================================================
-- Section 3: XOR helpers
-- ============================================================================

/-- XOR each byte of a ByteArray with a constant byte. -/
-- Safe: i ranges over [0, ba.size); .get! i is always in bounds
private def xorWithByte (ba : ByteArray) (b : UInt8) : ByteArray :=
  let result := Nat.fold (n := ba.size) (init := ByteArray.emptyWithCapacity ba.size) fun i _ acc =>
    acc.push ((ba.get! i) ^^^ b)
  result

-- ============================================================================
-- Section 4: HMAC-SHA-256
-- ============================================================================

/-- Compute HMAC-SHA-256 of `message` using `key`.
    Returns a 32-byte `ByteArray`.

    HMAC(K, m) = SHA-256((K' XOR opad) || SHA-256((K' XOR ipad) || m))
-/
def hmacSHA256 (key : ByteArray) (message : ByteArray) : ByteArray :=
  -- Step 1: Prepare the key (hash if too long, pad if too short)
  let k' := prepareKey key
  -- Step 2: Compute inner hash: SHA-256((K' XOR ipad) || message)
  let innerKeyPad := xorWithByte k' ipadByte
  let innerData := innerKeyPad ++ message
  let innerHash := LeanTLS.Crypto.SHA256.hash innerData
  -- Step 3: Compute outer hash: SHA-256((K' XOR opad) || innerHash)
  let outerKeyPad := xorWithByte k' opadByte
  let outerData := outerKeyPad ++ innerHash
  LeanTLS.Crypto.SHA256.hash outerData

-- ============================================================================
-- Section 5: HMAC-SHA-384
-- ============================================================================

/-- SHA-384 block size in bytes (SHA-384 uses SHA-512 internals with 128-byte blocks). -/
private def blockSize384 : Nat := 128

/-- Pad a ByteArray with zero bytes on the right to reach the target length.
    If the array is already at least `targetLen` bytes, it is returned unchanged. -/
private def padRight384 (ba : ByteArray) (targetLen : Nat) : ByteArray :=
  if ba.size >= targetLen then ba
  else
    let needed := targetLen - ba.size
    Nat.fold (n := needed) (init := ba) fun _ _ acc => acc.push 0x00

/-- Prepare the key K' for HMAC-SHA-384:
    - If key.size > blockSize384 (128), hash the key with SHA-384 and then zero-pad to blockSize384.
    - If key.size <= blockSize384, zero-pad the key to blockSize384. -/
private def prepareKey384 (key : ByteArray) : ByteArray :=
  if key.size > blockSize384 then
    padRight384 (LeanTLS.Crypto.SHA384.hash key) blockSize384
  else
    padRight384 key blockSize384

/-- XOR each byte of a ByteArray with a constant byte. -/
-- Safe: i ranges over [0, ba.size); .get! i is always in bounds
private def xorWithByte384 (ba : ByteArray) (b : UInt8) : ByteArray :=
  let result := Nat.fold (n := ba.size) (init := ByteArray.emptyWithCapacity ba.size) fun i _ acc =>
    acc.push ((ba.get! i) ^^^ b)
  result

/-- Compute HMAC-SHA-384 of `message` using `key`.
    Returns a 48-byte `ByteArray`.

    HMAC(K, m) = SHA-384((K' XOR opad) || SHA-384((K' XOR ipad) || m))
-/
def hmacSHA384 (key : ByteArray) (message : ByteArray) : ByteArray :=
  -- Step 1: Prepare the key (hash if too long, pad if too short)
  let k' := prepareKey384 key
  -- Step 2: Compute inner hash: SHA-384((K' XOR ipad) || message)
  let innerKeyPad := xorWithByte384 k' ipadByte
  let innerData := innerKeyPad ++ message
  let innerHash := LeanTLS.Crypto.SHA384.hash innerData
  -- Step 3: Compute outer hash: SHA-384((K' XOR opad) || innerHash)
  let outerKeyPad := xorWithByte384 k' opadByte
  let outerData := outerKeyPad ++ innerHash
  LeanTLS.Crypto.SHA384.hash outerData

-- ============================================================================
-- Section 6: Test vectors (RFC 4231)
-- ============================================================================

/-- Run HMAC-SHA-256 test vectors from RFC 4231. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test Case 1
  -- Key = 0x0b repeated 20 times
  -- Data = "Hi There"
  let key1 := LeanTLS.Utils.hexToBytes "0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b"
  let data1 := LeanTLS.Utils.hexToBytes "4869205468657265"
  let expected1 := "b0344c61d8db38535ca8afceaf0bf12b881dc200c9833da726e9376c2e32cff7"
  let result1 := LeanTLS.Crypto.SHA256.toHex (hmacSHA256 key1 data1)
  if result1 == expected1 then
    IO.println "  HMAC-SHA-256 test 1 (RFC 4231 Case 1): PASSED"
  else
    IO.println "  HMAC-SHA-256 test 1 (RFC 4231 Case 1): FAILED"
    IO.println s!"    expected: {expected1}"
    IO.println s!"    got:      {result1}"
    allPassed := false

  -- Test Case 2
  -- Key = "Jefe"
  -- Data = "what do ya want for nothing?"
  let key2 := LeanTLS.Utils.hexToBytes "4a656665"
  let data2 := LeanTLS.Utils.hexToBytes "7768617420646f2079612077616e7420666f72206e6f7468696e673f"
  let expected2 := "5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843"
  let result2 := LeanTLS.Crypto.SHA256.toHex (hmacSHA256 key2 data2)
  if result2 == expected2 then
    IO.println "  HMAC-SHA-256 test 2 (RFC 4231 Case 2): PASSED"
  else
    IO.println "  HMAC-SHA-256 test 2 (RFC 4231 Case 2): FAILED"
    IO.println s!"    expected: {expected2}"
    IO.println s!"    got:      {result2}"
    allPassed := false

  -- Test Case 3
  -- Key = 0xaa repeated 20 times
  -- Data = 0xdd repeated 50 times
  let key3 := LeanTLS.Utils.hexToBytes "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  let data3 := LeanTLS.Utils.hexToBytes "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"
  let expected3 := "773ea91e36800e46854db8ebd09181a72959098b3ef8c122d9635514ced565fe"
  let result3 := LeanTLS.Crypto.SHA256.toHex (hmacSHA256 key3 data3)
  if result3 == expected3 then
    IO.println "  HMAC-SHA-256 test 3 (RFC 4231 Case 3): PASSED"
  else
    IO.println "  HMAC-SHA-256 test 3 (RFC 4231 Case 3): FAILED"
    IO.println s!"    expected: {expected3}"
    IO.println s!"    got:      {result3}"
    allPassed := false

  -- ---- HMAC-SHA-384 test vectors (RFC 4231) ----

  -- Test Case 1
  -- Key = 0x0b repeated 20 times
  -- Data = "Hi There"
  let key384_1 := LeanTLS.Utils.hexToBytes "0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b"
  let data384_1 := LeanTLS.Utils.hexToBytes "4869205468657265"
  let expected384_1 := "afd03944d84895626b0825f4ab46907f15f9dadbe4101ec682aa034c7cebc59cfaea9ea9076ede7f4af152e8b2fa9cb6"
  let result384_1 := LeanTLS.Crypto.SHA384.toHex (hmacSHA384 key384_1 data384_1)
  if result384_1 == expected384_1 then
    IO.println "  HMAC-SHA-384 test 1 (RFC 4231 Case 1): PASSED"
  else
    IO.println "  HMAC-SHA-384 test 1 (RFC 4231 Case 1): FAILED"
    IO.println s!"    expected: {expected384_1}"
    IO.println s!"    got:      {result384_1}"
    allPassed := false

  -- Test Case 2
  -- Key = "Jefe"
  -- Data = "what do ya want for nothing?"
  let key384_2 := LeanTLS.Utils.hexToBytes "4a656665"
  let data384_2 := LeanTLS.Utils.hexToBytes "7768617420646f2079612077616e7420666f72206e6f7468696e673f"
  let expected384_2 := "af45d2e376484031617f78d2b58a6b1b9c7ef464f5a01b47e42ec3736322445e8e2240ca5e69e2c78b3239ecfab21649"
  let result384_2 := LeanTLS.Crypto.SHA384.toHex (hmacSHA384 key384_2 data384_2)
  if result384_2 == expected384_2 then
    IO.println "  HMAC-SHA-384 test 2 (RFC 4231 Case 2): PASSED"
  else
    IO.println "  HMAC-SHA-384 test 2 (RFC 4231 Case 2): FAILED"
    IO.println s!"    expected: {expected384_2}"
    IO.println s!"    got:      {result384_2}"
    allPassed := false

  return allPassed

end LeanTLS.Crypto.HMAC
