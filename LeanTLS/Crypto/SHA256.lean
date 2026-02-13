import LeanTLS.Utils

namespace LeanTLS.Crypto.SHA256

/-!
# SHA-256 (FIPS 180-4 / RFC 6234)

Pure Lean 4 implementation of the SHA-256 cryptographic hash function.
Produces a 32-byte (256-bit) digest from an arbitrary-length `ByteArray`.
-/

-- ============================================================================
-- Section 1: Constants
-- ============================================================================

/-- Initial hash values H(0) per FIPS 180-4 Section 5.3.3.
    These are the first 32 bits of the fractional parts of the square roots
    of the first 8 primes (2, 3, 5, 7, 11, 13, 17, 19). -/
def H0 : Array UInt32 := #[
  0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
  0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
]

/-- Round constants K per FIPS 180-4 Section 4.2.2.
    These are the first 32 bits of the fractional parts of the cube roots
    of the first 64 primes (2 .. 311). -/
def K : Array UInt32 := #[
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
  0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
  0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
  0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
  0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
  0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
  0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
  0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
  0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
]

-- ============================================================================
-- Section 2: Bitwise helper operations (FIPS 180-4 Section 4.1.2)
-- ============================================================================

/-- Right-rotate a 32-bit word by `n` positions. -/
@[inline] def rotr (x : UInt32) (n : UInt32) : UInt32 :=
  (x >>> n) ||| (x <<< (32 - n))

/-- Right-shift a 32-bit word by `n` positions. -/
@[inline] def shr (x : UInt32) (n : UInt32) : UInt32 :=
  x >>> n

/-- Ch(x, y, z) = (x AND y) XOR (NOT x AND z) -/
@[inline] def ch (x y z : UInt32) : UInt32 :=
  (x &&& y) ^^^ (x.complement &&& z)

/-- Maj(x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z) -/
@[inline] def maj (x y z : UInt32) : UInt32 :=
  (x &&& y) ^^^ (x &&& z) ^^^ (y &&& z)

/-- Big sigma 0: Sigma_0^{256}(x) = ROTR^2(x) XOR ROTR^13(x) XOR ROTR^22(x) -/
@[inline] def bigSigma0 (x : UInt32) : UInt32 :=
  rotr x 2 ^^^ rotr x 13 ^^^ rotr x 22

/-- Big sigma 1: Sigma_1^{256}(x) = ROTR^6(x) XOR ROTR^11(x) XOR ROTR^25(x) -/
@[inline] def bigSigma1 (x : UInt32) : UInt32 :=
  rotr x 6 ^^^ rotr x 11 ^^^ rotr x 25

/-- Small sigma 0: sigma_0^{256}(x) = ROTR^7(x) XOR ROTR^18(x) XOR SHR^3(x) -/
@[inline] def smallSigma0 (x : UInt32) : UInt32 :=
  rotr x 7 ^^^ rotr x 18 ^^^ shr x 3

/-- Small sigma 1: sigma_1^{256}(x) = ROTR^17(x) XOR ROTR^19(x) XOR SHR^10(x) -/
@[inline] def smallSigma1 (x : UInt32) : UInt32 :=
  rotr x 17 ^^^ rotr x 19 ^^^ shr x 10

-- ============================================================================
-- Section 3: Byte / word conversion helpers
-- ============================================================================

/-- Read a big-endian UInt32 from 4 bytes starting at index `i`. -/
-- Callers ensure i + 3 < data.size (block is 64 bytes, i = blockOffset + k*4, k in [0,15])
def getUInt32BE (data : ByteArray) (i : Nat) : UInt32 :=
  let b0 := (data.get! i).toUInt32
  let b1 := (data.get! (i + 1)).toUInt32
  let b2 := (data.get! (i + 2)).toUInt32
  let b3 := (data.get! (i + 3)).toUInt32
  (b0 <<< 24) ||| (b1 <<< 16) ||| (b2 <<< 8) ||| b3

/-- Write a UInt32 in big-endian byte order into a ByteArray. -/
def putUInt32BE (w : UInt32) : ByteArray :=
  let b0 := (w >>> 24).toUInt8
  let b1 := (w >>> 16).toUInt8
  let b2 := (w >>> 8).toUInt8
  let b3 := w.toUInt8
  ByteArray.mk #[b0, b1, b2, b3]

-- ============================================================================
-- Section 4: Message padding (FIPS 180-4 Section 5.1.1)
-- ============================================================================

/-- Append `n` zero bytes to a ByteArray. -/
private def appendZeros (ba : ByteArray) (n : Nat) : ByteArray :=
  Nat.fold (n := n) (init := ba) fun _ _ acc => acc.push 0x00

/-- Pad a message according to SHA-256 rules:
    1. Append bit '1' (byte 0x80)
    2. Append zeros until length is 56 mod 64
    3. Append 64-bit big-endian representation of the original message length in bits -/
def pad (msg : ByteArray) : ByteArray :=
  let len := msg.size
  let bitLen : UInt64 := (len.toUInt64) * 8
  -- After appending 0x80, we need (56 - (len + 1) % 64) % 64 zero bytes
  let tmp := (len + 1) % 64
  let zeroPadCount := if tmp <= 56 then 56 - tmp else 64 - tmp + 56
  -- Build padded message
  let padded := msg.push 0x80
  -- Append zero bytes
  let padded := appendZeros padded zeroPadCount
  -- Append 64-bit big-endian length
  let padded := padded.push (bitLen >>> 56).toUInt8
  let padded := padded.push (bitLen >>> 48).toUInt8
  let padded := padded.push (bitLen >>> 40).toUInt8
  let padded := padded.push (bitLen >>> 32).toUInt8
  let padded := padded.push (bitLen >>> 24).toUInt8
  let padded := padded.push (bitLen >>> 16).toUInt8
  let padded := padded.push (bitLen >>> 8).toUInt8
  let padded := padded.push bitLen.toUInt8
  padded

-- ============================================================================
-- Section 5: Message schedule (FIPS 180-4 Section 6.2.2, step 1)
-- ============================================================================

/-- Compute the 64-entry message schedule W from a 64-byte block.
    W[t] = M[t]                                          for 0 <= t <= 15
    W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16]  for 16 <= t <= 63 -/
def messageSchedule (block : ByteArray) (blockOffset : Nat) : Array UInt32 :=
  -- Safe: block is padded to 64-byte multiples; blockOffset + i*4 + 3 < paddedMsg.size
  let w : Array UInt32 := Nat.fold (n := 16) (init := #[]) fun i _ acc =>
    acc.push (getUInt32BE block (blockOffset + i * 4))
  -- Extend to 64 words
  -- Safe: acc grows from 16 to 64 entries; t-2, t-7, t-15, t-16 are all >= 0
  let w := Nat.fold (n := 48) (init := w) fun i _ acc =>
    let t := i + 16
    let s1 := smallSigma1 (acc[t - 2]!)
    let s0 := smallSigma0 (acc[t - 15]!)
    let wt := s1 + acc[t - 7]! + s0 + acc[t - 16]!
    acc.push wt
  w

-- ============================================================================
-- Section 6: Compression function (FIPS 180-4 Section 6.2.2, steps 2-4)
-- ============================================================================

/-- State of the 8 working variables (a, b, c, d, e, f, g, h). -/
structure WorkState where
  a : UInt32
  b : UInt32
  c : UInt32
  d : UInt32
  e : UInt32
  f : UInt32
  g : UInt32
  h : UInt32

/-- Perform one round of the compression function. -/
@[inline] def compressionRound (s : WorkState) (ki wi : UInt32) : WorkState :=
  let t1 := s.h + bigSigma1 s.e + ch s.e s.f s.g + ki + wi
  let t2 := bigSigma0 s.a + maj s.a s.b s.c
  { a := t1 + t2
    b := s.a
    c := s.b
    d := s.c
    e := s.d + t1
    f := s.e
    g := s.f
    h := s.g }

/-- Process one 512-bit (64-byte) block.
    Takes the current hash state (8 words) and returns the updated hash state. -/
def processBlock (hashState : Array UInt32) (paddedMsg : ByteArray) (blockOffset : Nat) : Array UInt32 :=
  let w := messageSchedule paddedMsg blockOffset
  -- Safe: hashState always has exactly 8 elements (initialized from H0)
  let initState : WorkState :=
    { a := hashState[0]!
      b := hashState[1]!
      c := hashState[2]!
      d := hashState[3]!
      e := hashState[4]!
      f := hashState[5]!
      g := hashState[6]!
      h := hashState[7]! }
  -- Safe: K has 64 entries, w has 64 entries, t ranges over [0, 64)
  let finalState := Nat.fold (n := 64) (init := initState) fun t _ acc =>
    compressionRound acc (K[t]!) (w[t]!)
  -- Safe: hashState always has 8 elements
  #[ hashState[0]! + finalState.a,
     hashState[1]! + finalState.b,
     hashState[2]! + finalState.c,
     hashState[3]! + finalState.d,
     hashState[4]! + finalState.e,
     hashState[5]! + finalState.f,
     hashState[6]! + finalState.g,
     hashState[7]! + finalState.h ]

-- ============================================================================
-- Section 7: Main hash function
-- ============================================================================

/-- Compute the SHA-256 hash of `msg`, returning a 32-byte `ByteArray`. -/
def hash (msg : ByteArray) : ByteArray :=
  let padded := pad msg
  let numBlocks := padded.size / 64
  -- Process each 64-byte block
  let finalHash := Nat.fold (n := numBlocks) (init := H0) fun i _ acc =>
    processBlock acc padded (i * 64)
  -- Safe: finalHash always has 8 entries (invariant of processBlock)
  let result := Nat.fold (n := 8) (init := ByteArray.empty) fun i _ acc =>
    acc ++ putUInt32BE (finalHash[i]!)
  result

-- ============================================================================
-- Section 8: Utility helpers for testing
-- ============================================================================

/-- Convert a `ByteArray` to a lowercase hexadecimal string. -/
def toHex := LeanTLS.Utils.bytesToHex

/-- Convert a UTF-8 string to a `ByteArray`. -/
def stringToBytes (s : String) : ByteArray :=
  s.toUTF8

-- ============================================================================
-- Section 9: Test vectors (NIST / RFC 6234)
-- ============================================================================

/-- Run SHA-256 test vectors. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test vector 1: "abc"
  let input1 := stringToBytes "abc"
  let expected1 := "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"
  let result1 := toHex (hash input1)
  if result1 == expected1 then
    IO.println s!"  SHA-256 test 1 (\"abc\"): PASSED"
  else
    IO.println s!"  SHA-256 test 1 (\"abc\"): FAILED"
    IO.println s!"    expected: {expected1}"
    IO.println s!"    got:      {result1}"
    allPassed := false

  -- Test vector 2: "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
  let input2 := stringToBytes "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
  let expected2 := "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"
  let result2 := toHex (hash input2)
  if result2 == expected2 then
    IO.println s!"  SHA-256 test 2 (448-bit): PASSED"
  else
    IO.println s!"  SHA-256 test 2 (448-bit): FAILED"
    IO.println s!"    expected: {expected2}"
    IO.println s!"    got:      {result2}"
    allPassed := false

  -- Test vector 3: "" (empty string)
  let input3 := stringToBytes ""
  let expected3 := "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
  let result3 := toHex (hash input3)
  if result3 == expected3 then
    IO.println s!"  SHA-256 test 3 (empty): PASSED"
  else
    IO.println s!"  SHA-256 test 3 (empty): FAILED"
    IO.println s!"    expected: {expected3}"
    IO.println s!"    got:      {result3}"
    allPassed := false

  return allPassed

end LeanTLS.Crypto.SHA256
