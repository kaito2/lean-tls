import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.Crypto.SHA384

/-!
# SHA-384 (FIPS 180-4 / RFC 6234)

Pure Lean 4 implementation of the SHA-384 cryptographic hash function.
SHA-384 is a truncation of SHA-512, using 64-bit words, 80 rounds,
and 128-byte blocks. Produces a 48-byte (384-bit) digest.

Uses Nat with explicit modular reduction (mod 2^64) for correctness.
-/

-- ============================================================================
-- Section 1: Constants
-- ============================================================================

private def w64 : Nat := 0x10000000000000000  -- 2^64

/-- Initial hash values H(0) for SHA-384 per FIPS 180-4 Section 5.3.4. -/
def H0 : Array Nat := #[
  0xcbbb9d5dc1059ed8, 0x629a292a367cd507,
  0x9159015a3070dd17, 0x152fecd8f70e5939,
  0x67332667ffc00b31, 0x8eb44a8768581511,
  0xdb0c2e0d64f98fa7, 0x47b5481dbefa4fa4
]

/-- Round constants K for SHA-512/384 per FIPS 180-4 Section 4.2.3. -/
def K : Array Nat := #[
  0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
  0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
  0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
  0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
  0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
  0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
  0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
  0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
  0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
  0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
  0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
  0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
  0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
  0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
  0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
  0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
  0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
  0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
  0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
  0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
]

-- ============================================================================
-- Section 2: 64-bit word operations using Nat
-- ============================================================================

/-- Modular addition mod 2^64. -/
@[inline] private def add64 (a b : Nat) : Nat := (a + b) % w64

/-- Bitwise AND for 64-bit values. -/
@[inline] private def and64 (a b : Nat) : Nat := a &&& b

/-- Bitwise XOR for 64-bit values. -/
@[inline] private def xor64 (a b : Nat) : Nat := (a ^^^ b) % w64

/-- Bitwise NOT for 64-bit values. -/
@[inline] private def not64 (a : Nat) : Nat := (w64 - 1) ^^^ a

/-- Right rotate a 64-bit word by n positions. -/
@[inline] private def rotr64 (x : Nat) (n : Nat) : Nat :=
  let n' := n % 64
  ((x >>> n') ||| (x <<< (64 - n'))) % w64

/-- Right shift a 64-bit word by n positions. -/
@[inline] private def shr64 (x : Nat) (n : Nat) : Nat := x >>> n

/-- Ch(x, y, z) = (x AND y) XOR (NOT x AND z) -/
@[inline] private def ch (x y z : Nat) : Nat :=
  xor64 (and64 x y) (and64 (not64 x) z)

/-- Maj(x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z) -/
@[inline] private def maj (x y z : Nat) : Nat :=
  xor64 (xor64 (and64 x y) (and64 x z)) (and64 y z)

/-- Big sigma 0: Σ₀(x) = ROTR²⁸(x) XOR ROTR³⁴(x) XOR ROTR³⁹(x) -/
@[inline] private def bigSigma0 (x : Nat) : Nat :=
  xor64 (xor64 (rotr64 x 28) (rotr64 x 34)) (rotr64 x 39)

/-- Big sigma 1: Σ₁(x) = ROTR¹⁴(x) XOR ROTR¹⁸(x) XOR ROTR⁴¹(x) -/
@[inline] private def bigSigma1 (x : Nat) : Nat :=
  xor64 (xor64 (rotr64 x 14) (rotr64 x 18)) (rotr64 x 41)

/-- Small sigma 0: σ₀(x) = ROTR¹(x) XOR ROTR⁸(x) XOR SHR⁷(x) -/
@[inline] private def smallSigma0 (x : Nat) : Nat :=
  xor64 (xor64 (rotr64 x 1) (rotr64 x 8)) (shr64 x 7)

/-- Small sigma 1: σ₁(x) = ROTR¹⁹(x) XOR ROTR⁶¹(x) XOR SHR⁶(x) -/
@[inline] private def smallSigma1 (x : Nat) : Nat :=
  xor64 (xor64 (rotr64 x 19) (rotr64 x 61)) (shr64 x 6)

-- ============================================================================
-- Section 3: Byte / word conversion helpers
-- ============================================================================

/-- Read a big-endian 64-bit word from 8 bytes starting at index `i`. -/
private def getWord64BE (data : ByteArray) (i : Nat) : Nat :=
  (data.get! i).toNat <<< 56 ||| (data.get! (i+1)).toNat <<< 48 |||
  (data.get! (i+2)).toNat <<< 40 ||| (data.get! (i+3)).toNat <<< 32 |||
  (data.get! (i+4)).toNat <<< 24 ||| (data.get! (i+5)).toNat <<< 16 |||
  (data.get! (i+6)).toNat <<< 8  ||| (data.get! (i+7)).toNat

/-- Write a 64-bit word in big-endian byte order. -/
private def putWord64BE (w : Nat) : ByteArray :=
  ByteArray.mk #[
    (w >>> 56 &&& 0xFF).toUInt8, (w >>> 48 &&& 0xFF).toUInt8,
    (w >>> 40 &&& 0xFF).toUInt8, (w >>> 32 &&& 0xFF).toUInt8,
    (w >>> 24 &&& 0xFF).toUInt8, (w >>> 16 &&& 0xFF).toUInt8,
    (w >>> 8  &&& 0xFF).toUInt8, (w &&& 0xFF).toUInt8
  ]

-- ============================================================================
-- Section 4: Message padding (FIPS 180-4 Section 5.1.2)
-- ============================================================================

/-- Pad a message according to SHA-512/384 rules. -/
def pad (msg : ByteArray) : ByteArray := Id.run do
  let len := msg.size
  let bitLen := len * 8
  let tmp := (len + 1) % 128
  let zeroPadCount := if tmp <= 112 then 112 - tmp else 128 - tmp + 112
  let mut padded := msg.push 0x80
  for _ in [:zeroPadCount] do
    padded := padded.push 0x00
  -- Upper 64 bits of 128-bit length (always zero)
  for _ in [:8] do
    padded := padded.push 0x00
  -- Lower 64 bits: actual bit length
  padded := padded.push (bitLen >>> 56 &&& 0xFF).toUInt8
  padded := padded.push (bitLen >>> 48 &&& 0xFF).toUInt8
  padded := padded.push (bitLen >>> 40 &&& 0xFF).toUInt8
  padded := padded.push (bitLen >>> 32 &&& 0xFF).toUInt8
  padded := padded.push (bitLen >>> 24 &&& 0xFF).toUInt8
  padded := padded.push (bitLen >>> 16 &&& 0xFF).toUInt8
  padded := padded.push (bitLen >>> 8  &&& 0xFF).toUInt8
  padded := padded.push (bitLen &&& 0xFF).toUInt8
  return padded

-- ============================================================================
-- Section 5: Message schedule (FIPS 180-4 Section 6.4.2, step 1)
-- ============================================================================

/-- Compute the 80-entry message schedule W from a 128-byte block. -/
private def messageSchedule (block : ByteArray) (blockOffset : Nat) : Array Nat := Id.run do
  let mut w : Array Nat := Array.mkArray 80 0
  for i in [:16] do
    w := w.set! i (getWord64BE block (blockOffset + i * 8))
  for t in [16:80] do
    let s1 := smallSigma1 (w.get! (t - 2))
    let s0 := smallSigma0 (w.get! (t - 15))
    w := w.set! t (add64 (add64 s1 (w.get! (t - 7))) (add64 s0 (w.get! (t - 16))))
  return w

-- ============================================================================
-- Section 6: Compression function (FIPS 180-4 Section 6.4.2, steps 2-4)
-- ============================================================================

/-- State of the 8 working variables. -/
structure WorkState where
  a : Nat
  b : Nat
  c : Nat
  d : Nat
  e : Nat
  f : Nat
  g : Nat
  h : Nat

/-- Perform one round of the compression function. -/
@[inline] private def compressionRound (s : WorkState) (kw : Nat) : WorkState :=
  let t1 := add64 (add64 (add64 s.h (bigSigma1 s.e)) (ch s.e s.f s.g)) kw
  let t2 := add64 (bigSigma0 s.a) (maj s.a s.b s.c)
  { a := add64 t1 t2
    b := s.a
    c := s.b
    d := s.c
    e := add64 s.d t1
    f := s.e
    g := s.f
    h := s.g }

/-- Process one 1024-bit (128-byte) block. -/
private def processBlock (hashState : Array Nat) (paddedMsg : ByteArray) (blockOffset : Nat)
    : Array Nat := Id.run do
  let w := messageSchedule paddedMsg blockOffset
  let mut state : WorkState := {
    a := hashState.get! 0, b := hashState.get! 1,
    c := hashState.get! 2, d := hashState.get! 3,
    e := hashState.get! 4, f := hashState.get! 5,
    g := hashState.get! 6, h := hashState.get! 7
  }
  for t in [:80] do
    state := compressionRound state (add64 (K.get! t) (w.get! t))
  return #[
    add64 (hashState.get! 0) state.a, add64 (hashState.get! 1) state.b,
    add64 (hashState.get! 2) state.c, add64 (hashState.get! 3) state.d,
    add64 (hashState.get! 4) state.e, add64 (hashState.get! 5) state.f,
    add64 (hashState.get! 6) state.g, add64 (hashState.get! 7) state.h
  ]

-- ============================================================================
-- Section 7: Main hash function
-- ============================================================================

/-- Compute the SHA-384 hash of `data`, returning a 48-byte `ByteArray`.
    SHA-384 is SHA-512 truncated to the first 384 bits (6 of 8 hash words). -/
def hash (data : ByteArray) : ByteArray := Id.run do
  let padded := pad data
  let numBlocks := padded.size / 128
  let mut state := H0
  for i in [:numBlocks] do
    state := processBlock state padded (i * 128)
  -- Output only the first 6 words (48 bytes = 384 bits)
  let mut result := ByteArray.empty
  for i in [:6] do
    result := result ++ putWord64BE (state.get! i)
  return result

-- ============================================================================
-- Section 8: Utility helpers
-- ============================================================================

/-- Convert a `ByteArray` to a lowercase hexadecimal string. -/
def toHex := LeanTLS.Utils.bytesToHex

-- ============================================================================
-- Section 9: Test vectors (NIST / RFC 6234)
-- ============================================================================

/-- Run SHA-384 test vectors. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test vector 1: "" (empty string)
  let result1 := toHex (hash "".toUTF8)
  let expected1 := "38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b"
  if result1 == expected1 then
    IO.println "  SHA-384 test 1 (empty): PASSED"
  else
    IO.println s!"  SHA-384 test 1 (empty): FAILED"
    IO.println s!"    expected: {expected1}"
    IO.println s!"    got:      {result1}"
    allPassed := false

  -- Test vector 2: "abc"
  let result2 := toHex (hash "abc".toUTF8)
  let expected2 := "cb00753f45a35e8bb5a03d699ac65007272c32ab0eded1631a8b605a43ff5bed8086072ba1e7cc2358baeca134c825a7"
  if result2 == expected2 then
    IO.println "  SHA-384 test 2 (\"abc\"): PASSED"
  else
    IO.println s!"  SHA-384 test 2 (\"abc\"): FAILED"
    IO.println s!"    expected: {expected2}"
    IO.println s!"    got:      {result2}"
    allPassed := false

  -- Test vector 3: 896-bit message
  let result3 := toHex (hash "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu".toUTF8)
  let expected3 := "09330c33f71147e83d192fc782cd1b4753111b173b3b05d22fa08086e3b0f712fcc7c71a557e2db966c3e9fa91746039"
  if result3 == expected3 then
    IO.println "  SHA-384 test 3 (896-bit): PASSED"
  else
    IO.println s!"  SHA-384 test 3 (896-bit): FAILED"
    IO.println s!"    expected: {expected3}"
    IO.println s!"    got:      {result3}"
    allPassed := false

  return allPassed

end LeanTLS.Crypto.SHA384
