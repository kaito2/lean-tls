import LeanTLS.Crypto.SHA256

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
private def xorWithByte (ba : ByteArray) (b : UInt8) : ByteArray :=
  let result := Nat.fold (n := ba.size) (init := ByteArray.mkEmpty ba.size) fun i _ acc =>
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
-- Section 5: Hex utility helpers for testing
-- ============================================================================

/-- Convert a single hex character to its numeric value (0-15).
    Returns 0 for invalid characters. -/
private def hexCharToNibble (c : Char) : UInt8 :=
  if '0' ≤ c ∧ c ≤ '9' then (c.toNat - '0'.toNat).toUInt8
  else if 'a' ≤ c ∧ c ≤ 'f' then (c.toNat - 'a'.toNat + 10).toUInt8
  else if 'A' ≤ c ∧ c ≤ 'F' then (c.toNat - 'A'.toNat + 10).toUInt8
  else 0

/-- Convert a hexadecimal string to a ByteArray.
    The string must have an even number of characters. -/
private def hexToBytes (s : String) : ByteArray :=
  let chars := s.toList
  let pairs := go chars #[]
  ByteArray.mk pairs
where
  go : List Char → Array UInt8 → Array UInt8
    | c1 :: c2 :: rest, acc =>
      let hi := hexCharToNibble c1
      let lo := hexCharToNibble c2
      go rest (acc.push ((hi <<< 4) ||| lo))
    | _, acc => acc

-- ============================================================================
-- Section 6: Test vectors (RFC 4231)
-- ============================================================================

/-- Run HMAC-SHA-256 test vectors from RFC 4231. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test Case 1
  -- Key = 0x0b repeated 20 times
  -- Data = "Hi There"
  let key1 := hexToBytes "0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b"
  let data1 := hexToBytes "4869205468657265"
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
  let key2 := hexToBytes "4a656665"
  let data2 := hexToBytes "7768617420646f2079612077616e7420666f72206e6f7468696e673f"
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
  let key3 := hexToBytes "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  let data3 := hexToBytes "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"
  let expected3 := "773ea91e36800e46854db8ebd09181a72959098b3ef8c122d9635514ced565fe"
  let result3 := LeanTLS.Crypto.SHA256.toHex (hmacSHA256 key3 data3)
  if result3 == expected3 then
    IO.println "  HMAC-SHA-256 test 3 (RFC 4231 Case 3): PASSED"
  else
    IO.println "  HMAC-SHA-256 test 3 (RFC 4231 Case 3): FAILED"
    IO.println s!"    expected: {expected3}"
    IO.println s!"    got:      {result3}"
    allPassed := false

  return allPassed

end LeanTLS.Crypto.HMAC
