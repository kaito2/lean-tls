/-
  AES-128 Block Cipher (FIPS 197)
  Encryption only: 128-bit key, 128-bit block, 10 rounds.

  The state is a 4x4 byte matrix in column-major order as per FIPS 197.
  State indexing: state[row + 4 * col] for row in 0..3, col in 0..3.
-/

import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.Crypto.AES

/-! ## S-Box (FIPS 197, Figure 7) -/

/-- The AES S-Box lookup table (256 entries). -/
private def sbox : Array UInt8 := #[
  -- 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, -- 0
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, -- 1
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, -- 2
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, -- 3
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, -- 4
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, -- 5
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, -- 6
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, -- 7
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, -- 8
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, -- 9
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, -- a
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, -- b
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, -- c
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, -- d
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, -- e
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16  -- f
]

/-- Apply S-Box substitution to a single byte. -/
-- Safe: b.toNat is in [0, 255]; sbox has exactly 256 entries
private def subByte (b : UInt8) : UInt8 :=
  sbox[b.toNat]!

/-! ## Round Constants for Key Expansion (FIPS 197, Section 5.2) -/

/-- Round constants (Rcon). Only the first byte of each word is non-zero for AES-128. -/
private def rcon : Array UInt8 := #[
  0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
]

/-! ## GF(2^8) Arithmetic for MixColumns -/

/-- Multiply by 2 in GF(2^8) with irreducible polynomial x^8 + x^4 + x^3 + x + 1 (0x1b). -/
private def xtime (a : UInt8) : UInt8 :=
  let shifted := a <<< 1
  if a &&& 0x80 != 0 then shifted ^^^ 0x1b else shifted

/-- Multiply two bytes in GF(2^8). Only need multiply by 2 and 3 for MixColumns. -/
private def gmul (a : UInt8) (b : UInt8) : UInt8 :=
  -- We only need gmul for constants 1, 2, 3 in MixColumns.
  -- gmul(2, b) = xtime(b)
  -- gmul(3, b) = xtime(b) ^ b
  if a == 1 then b
  else if a == 2 then xtime b
  else if a == 3 then (xtime b) ^^^ b
  else 0  -- not needed for encryption MixColumns

/-! ## State Representation

  The AES state is a 4x4 matrix of bytes, stored in a flat ByteArray of 16 bytes.
  Index: state[row + 4 * col] where row in {0,1,2,3} and col in {0,1,2,3}.
  This is column-major order as per FIPS 197.
-/

/-- Get a byte from the state at (row, col). -/
-- Safe: row in [0,3], col in [0,3], so row + 4*col in [0, 15]; state is always 16 bytes
private def stateGet (state : ByteArray) (row : Nat) (col : Nat) : UInt8 :=
  state.get! (row + 4 * col)

/-- Set a byte in the state at (row, col). -/
-- Safe: same invariant as stateGet — index in [0, 15], state is 16 bytes
private def stateSet (state : ByteArray) (row : Nat) (col : Nat) (val : UInt8) : ByteArray :=
  state.set! (row + 4 * col) val

/-! ## SubBytes (FIPS 197, Section 5.1.1) -/

/-- Apply S-Box substitution to every byte of the state. -/
private def subBytes (state : ByteArray) : ByteArray := Id.run do
  let mut s := state
  for i in [:16] do
    -- Safe: state is always 16 bytes; i ranges over [0, 16)
    s := s.set! i (subByte (s.get! i))
  return s

/-! ## ShiftRows (FIPS 197, Section 5.1.2)

  Row 0: no shift
  Row 1: shift left by 1
  Row 2: shift left by 2
  Row 3: shift left by 3
-/

/-- Cyclically shift rows of the state matrix to the left. -/
private def shiftRows (state : ByteArray) : ByteArray := Id.run do
  let mut s := state
  -- Row 0: no change

  -- Row 1: shift left by 1
  let t1 := stateGet s 1 0
  s := stateSet s 1 0 (stateGet s 1 1)
  s := stateSet s 1 1 (stateGet s 1 2)
  s := stateSet s 1 2 (stateGet s 1 3)
  s := stateSet s 1 3 t1

  -- Row 2: shift left by 2
  let t20 := stateGet s 2 0
  let t21 := stateGet s 2 1
  s := stateSet s 2 0 (stateGet s 2 2)
  s := stateSet s 2 1 (stateGet s 2 3)
  s := stateSet s 2 2 t20
  s := stateSet s 2 3 t21

  -- Row 3: shift left by 3 (= right by 1)
  let t3 := stateGet s 3 3
  s := stateSet s 3 3 (stateGet s 3 2)
  s := stateSet s 3 2 (stateGet s 3 1)
  s := stateSet s 3 1 (stateGet s 3 0)
  s := stateSet s 3 0 t3

  return s

/-! ## MixColumns (FIPS 197, Section 5.1.3)

  Each column is treated as a polynomial over GF(2^8) and multiplied modulo
  x^4 + 1 with the fixed polynomial {03}x^3 + {01}x^2 + {01}x + {02}.
-/

/-- Mix a single column of the state. -/
private def mixColumn (s0 : UInt8) (s1 : UInt8) (s2 : UInt8) (s3 : UInt8)
    : UInt8 × UInt8 × UInt8 × UInt8 :=
  let r0 := gmul 2 s0 ^^^ gmul 3 s1 ^^^ s2 ^^^ s3
  let r1 := s0 ^^^ gmul 2 s1 ^^^ gmul 3 s2 ^^^ s3
  let r2 := s0 ^^^ s1 ^^^ gmul 2 s2 ^^^ gmul 3 s3
  let r3 := gmul 3 s0 ^^^ s1 ^^^ s2 ^^^ gmul 2 s3
  (r0, r1, r2, r3)

/-- Apply MixColumns to the entire state. -/
private def mixColumns (state : ByteArray) : ByteArray := Id.run do
  let mut s := state
  for col in [:4] do
    let s0 := stateGet s 0 col
    let s1 := stateGet s 1 col
    let s2 := stateGet s 2 col
    let s3 := stateGet s 3 col
    let (r0, r1, r2, r3) := mixColumn s0 s1 s2 s3
    s := stateSet s 0 col r0
    s := stateSet s 1 col r1
    s := stateSet s 2 col r2
    s := stateSet s 3 col r3
  return s

/-! ## AddRoundKey (FIPS 197, Section 5.1.4)

  XOR the state with the round key (4 words = 16 bytes).
-/

/-- XOR the state with a round key starting at the given word offset in the expanded key. -/
private def addRoundKey (state : ByteArray) (expandedKey : Array UInt8) (round : Nat) : ByteArray := Id.run do
  let mut s := state
  -- Round key starts at word index (round * 4), each word is 4 bytes.
  -- Word j of round key corresponds to column j.
  -- Word layout: w[i] = [byte0, byte1, byte2, byte3] corresponds to rows 0,1,2,3.
  for col in [:4] do
    let wordIdx := (round * 4 + col) * 4
    for row in [:4] do
      let keyByte := expandedKey[wordIdx + row]!
      let stByte := stateGet s row col
      s := stateSet s row col (stByte ^^^ keyByte)
  return s

/-! ## Key Expansion (FIPS 197, Section 5.2)

  AES-128: Nk = 4 (key length in 32-bit words), Nr = 10, total words = 4 * (10 + 1) = 44.
-/

/-- Apply SubBytes to each byte of a 4-byte word. -/
private def subWord (w : Array UInt8) : Array UInt8 :=
  #[subByte (w[0]!), subByte (w[1]!), subByte (w[2]!), subByte (w[3]!)]

/-- Rotate a 4-byte word left by one byte: [a0, a1, a2, a3] -> [a1, a2, a3, a0]. -/
private def rotWord (w : Array UInt8) : Array UInt8 :=
  #[w[1]!, w[2]!, w[3]!, w[0]!]

/-- XOR two 4-byte words. -/
private def xorWord (a : Array UInt8) (b : Array UInt8) : Array UInt8 :=
  #[a[0]! ^^^ b[0]!, a[1]! ^^^ b[1]!, a[2]! ^^^ b[2]!, a[3]! ^^^ b[3]!]

/-- Extract a 4-byte word from the expanded key array at word index i. -/
private def getWord (expanded : Array UInt8) (i : Nat) : Array UInt8 :=
  let off := i * 4
  #[expanded[off]!, expanded[off + 1]!, expanded[off + 2]!, expanded[off + 3]!]

/-- Set a 4-byte word in the expanded key array at word index i. -/
private def setWord (expanded : Array UInt8) (i : Nat) (w : Array UInt8) : Array UInt8 :=
  let off := i * 4
  let e := expanded.set! off (w[0]!)
  let e := e.set! (off + 1) (w[1]!)
  let e := e.set! (off + 2) (w[2]!)
  e.set! (off + 3) (w[3]!)

/-- Expand a 16-byte AES-128 key into 44 words (176 bytes). -/
-- All .get!/.set! indices are within the 176-byte expanded array and 16-byte key
private def keyExpansion (key : ByteArray) : Array UInt8 := Id.run do
  -- Initialize with 176 zero bytes
  let mut expanded : Array UInt8 := Array.mkArray 176 0
  -- Copy the original key into the first 4 words (16 bytes)
  for i in [:16] do
    -- Safe: key is 16 bytes; i ranges over [0, 16)
    expanded := expanded.set! i (key.get! i)
  -- Generate remaining 40 words
  for i in [4:44] do
    let mut temp := getWord expanded (i - 1)
    if i % 4 == 0 then
      temp := rotWord temp
      temp := subWord temp
      let rconWord : Array UInt8 := #[rcon[(i / 4) - 1]!, 0, 0, 0]
      temp := xorWord temp rconWord
    let prev := getWord expanded (i - 4)
    let newWord := xorWord prev temp
    expanded := setWord expanded i newWord
  return expanded

/-! ## AES-128 Encryption (FIPS 197, Section 5.1) -/

/-- Encrypt a single 16-byte block with a 16-byte key. Returns 16-byte ciphertext. -/
def encryptBlock (key : ByteArray) (plaintext : ByteArray) : ByteArray := Id.run do
  -- Key expansion
  let expandedKey := keyExpansion key
  -- Initial state = plaintext (column-major: input byte i goes to state[i])
  let mut state := plaintext
  -- Initial round: AddRoundKey with round key 0
  state := addRoundKey state expandedKey 0
  -- Rounds 1 through 9: SubBytes, ShiftRows, MixColumns, AddRoundKey
  for round in [1:10] do
    state := subBytes state
    state := shiftRows state
    state := mixColumns state
    state := addRoundKey state expandedKey round
  -- Final round (round 10): SubBytes, ShiftRows, AddRoundKey (no MixColumns)
  state := subBytes state
  state := shiftRows state
  state := addRoundKey state expandedKey 10
  return state

/-! ## Test Vectors -/

/-- Run AES-128 test vectors. Returns true if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test 1: FIPS 197 Appendix B
  let key1 := LeanTLS.Utils.hexToBytes "2b7e151628aed2a6abf7158809cf4f3c"
  let pt1 := LeanTLS.Utils.hexToBytes "3243f6a8885a308d313198a2e0370734"
  let expected1 := "3925841d02dc09fbdc118597196a0b32"
  let ct1 := encryptBlock key1 pt1
  let result1 := LeanTLS.Utils.bytesToHex ct1
  if result1 == expected1 then
    IO.println s!"[PASS] FIPS 197 Appendix B: {result1}"
  else
    IO.println s!"[FAIL] FIPS 197 Appendix B: expected {expected1}, got {result1}"
    allPassed := false

  -- Test 2: NIST AES-128 ECB (all zeros)
  let key2 := LeanTLS.Utils.hexToBytes "00000000000000000000000000000000"
  let pt2 := LeanTLS.Utils.hexToBytes "00000000000000000000000000000000"
  let expected2 := "66e94bd4ef8a2c3b884cfa59ca342b2e"
  let ct2 := encryptBlock key2 pt2
  let result2 := LeanTLS.Utils.bytesToHex ct2
  if result2 == expected2 then
    IO.println s!"[PASS] NIST AES-128 ECB (zeros): {result2}"
  else
    IO.println s!"[FAIL] NIST AES-128 ECB (zeros): expected {expected2}, got {result2}"
    allPassed := false

  if allPassed then
    IO.println "All AES-128 tests passed!"
  else
    IO.println "Some AES-128 tests FAILED!"

  return allPassed

end LeanTLS.Crypto.AES
