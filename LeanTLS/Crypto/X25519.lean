set_option autoImplicit false

namespace LeanTLS.Crypto.X25519

/-! # X25519 Diffie-Hellman Key Exchange (RFC 7748)

This module implements X25519 scalar multiplication on Curve25519
using the Montgomery ladder algorithm. All field arithmetic is performed
over GF(2^255 - 19) using Lean's arbitrary-precision `Nat`.
-/

-- ============================================================================
-- Field arithmetic over GF(2^255 - 19)
-- ============================================================================

/-- The prime p = 2^255 - 19 defining the field GF(p). -/
def p : Nat := 2 ^ 255 - 19

/-- The constant a24 = (486662 - 2) / 4 = 121665, used in the Montgomery ladder (RFC 7748). -/
def a24 : Nat := 121665

/-- Reduce a natural number modulo p. -/
def fieldReduce (a : Nat) : Nat :=
  a % p

/-- Field addition: (a + b) mod p -/
def fieldAdd (a b : Nat) : Nat :=
  (a + b) % p

/-- Field subtraction: (a - b) mod p.
    We add p before subtracting to ensure the result is non-negative. -/
def fieldSub (a b : Nat) : Nat :=
  (a + p - (b % p)) % p

/-- Field multiplication: (a * b) mod p -/
def fieldMul (a b : Nat) : Nat :=
  (a * b) % p

/-- Field squaring: a^2 mod p -/
def fieldSq (a : Nat) : Nat :=
  (a * a) % p

/-- Modular exponentiation by repeated squaring: base^exp mod p -/
def fieldPow (base : Nat) (exp : Nat) : Nat :=
  let rec go (b : Nat) (e : Nat) (acc : Nat) : Nat :=
    if h : e = 0 then acc
    else
      let acc' := if e % 2 = 1 then (acc * b) % p else acc
      have : e / 2 < e := Nat.div_lt_self (Nat.pos_of_ne_zero h) (by omega)
      go ((b * b) % p) (e / 2) acc'
  termination_by e
  go (base % p) exp 1

/-- Field inversion using Fermat's little theorem: a^(p-2) mod p -/
def fieldInv (a : Nat) : Nat :=
  fieldPow a (p - 2)

-- ============================================================================
-- Byte encoding / decoding utilities
-- ============================================================================

/-- Decode a ByteArray (little-endian) into a Nat. -/
def decodeLE (bs : ByteArray) : Nat :=
  let rec go (i : Nat) (acc : Nat) : Nat :=
    if h : i < bs.size then
      go (i + 1) (acc + (bs[i]'h).toNat * (2 ^ (8 * i)))
    else
      acc
  termination_by bs.size - i
  go 0 0

/-- Encode a Nat into a 32-byte little-endian ByteArray. -/
def encodeLE32 (n : Nat) : ByteArray :=
  let rec go (i : Nat) (val : Nat) (acc : ByteArray) : ByteArray :=
    if i < 32 then
      go (i + 1) (val / 256) (acc.push (val % 256).toUInt8)
    else
      acc
  termination_by 32 - i
  go 0 n ByteArray.empty

/-- Convert a hex character to its numeric value. -/
def hexCharToNat (c : Char) : Nat :=
  if '0' <= c && c <= '9' then c.toNat - '0'.toNat
  else if 'a' <= c && c <= 'f' then c.toNat - 'a'.toNat + 10
  else if 'A' <= c && c <= 'F' then c.toNat - 'A'.toNat + 10
  else 0

/-- Convert a hex string to a ByteArray. -/
def hexToBytes (s : String) : ByteArray :=
  let chars := s.toList
  let rec go (cs : List Char) (acc : ByteArray) : ByteArray :=
    match cs with
    | c1 :: c2 :: rest =>
      let byte := (hexCharToNat c1 * 16 + hexCharToNat c2).toUInt8
      go rest (acc.push byte)
    | _ => acc
  go chars ByteArray.empty

/-- Convert a nibble (0-15) to its hex character. -/
def nibbleToHexChar (n : Nat) : Char :=
  if n < 10 then Char.ofNat ('0'.toNat + n)
  else Char.ofNat ('a'.toNat + n - 10)

/-- Convert a single byte to a two-character hex string. -/
def byteToHex (b : UInt8) : String :=
  let hi := b.toNat / 16
  let lo := b.toNat % 16
  String.mk [nibbleToHexChar hi, nibbleToHexChar lo]

/-- Convert a ByteArray to a hex string. -/
def bytesToHex (bs : ByteArray) : String :=
  let rec go (i : Nat) (acc : String) : String :=
    if h : i < bs.size then
      go (i + 1) (acc ++ byteToHex (bs[i]'h))
    else
      acc
  termination_by bs.size - i
  go 0 ""

-- ============================================================================
-- Scalar clamping
-- ============================================================================

/-- Clamp a 32-byte scalar per RFC 7748:
    - Clear bits 0, 1, 2 of the first byte (AND with 248)
    - Clear bit 7 of the last byte (AND with 127)
    - Set bit 6 of the last byte (OR with 64) -/
def clamp (k : ByteArray) : ByteArray :=
  if k.size < 32 then k
  else
    let k := k.set! 0 (k.get! 0 &&& 248)
    let k := k.set! 31 (k.get! 31 &&& 127)
    let k := k.set! 31 (k.get! 31 ||| 64)
    k

-- ============================================================================
-- u-coordinate decoding
-- ============================================================================

/-- Decode a u-coordinate from 32 bytes (little-endian), masking the high bit
    of the last byte as required by RFC 7748. -/
def decodeUCoordinate (bs : ByteArray) : Nat :=
  if bs.size < 32 then decodeLE bs
  else
    let bs' := bs.set! 31 (bs.get! 31 &&& 127)
    decodeLE bs'

-- ============================================================================
-- Montgomery ladder
-- ============================================================================

/-- State carried through the Montgomery ladder iterations.
    Contains the projective coordinates (x_2, z_2) and (x_3, z_3). -/
structure LadderState where
  x2 : Nat
  z2 : Nat
  x3 : Nat
  z3 : Nat

/-- Perform one step of the Montgomery ladder for a given bit value.
    The `u` parameter is the base point u-coordinate. -/
def ladderStep (st : LadderState) (u : Nat) (bit : Bool) : LadderState :=
  -- Conditional swap
  let (x2, z2, x3, z3) :=
    if bit then (st.x3, st.z3, st.x2, st.z2)
    else (st.x2, st.z2, st.x3, st.z3)
  -- Montgomery ladder body
  let capA  := fieldAdd x2 z2
  let capAA := fieldSq capA
  let capB  := fieldSub x2 z2
  let capBB := fieldSq capB
  let capE  := fieldSub capAA capBB
  let capC  := fieldAdd x3 z3
  let capD  := fieldSub x3 z3
  let capDA := fieldMul capD capA
  let capCB := fieldMul capC capB
  let x3'   := fieldSq (fieldAdd capDA capCB)
  let z3'   := fieldMul u (fieldSq (fieldSub capDA capCB))
  let x2'   := fieldMul capAA capBB
  let z2'   := fieldMul capE (fieldAdd capAA (fieldMul a24 capE))
  -- Conditional swap back
  if bit then
    { x2 := x3', z2 := z3', x3 := x2', z3 := z2' }
  else
    { x2 := x2', z2 := z2', x3 := x3', z3 := z3' }

/-- Get the i-th bit of a natural number (0-indexed from LSB). -/
def getBit (n : Nat) (i : Nat) : Bool :=
  (n / (2 ^ i)) % 2 = 1

/-- Run the Montgomery ladder over all 255 bits (from bit 254 down to bit 0).
    Returns the result as a field element (x2 / z2 mod p). -/
def montgomeryLadder (scalar : Nat) (u : Nat) : Nat :=
  let init : LadderState := { x2 := 1, z2 := 0, x3 := u, z3 := 1 }
  -- Process bits from 254 down to 0
  let rec loop (i : Nat) (st : LadderState) : LadderState :=
    let bit := getBit scalar i
    let st' := ladderStep st u bit
    match i with
    | 0     => st'
    | i + 1 => loop i st'
  let final := loop 254 init
  -- Return x2 * z2^(p-2) mod p = x2 / z2 mod p
  fieldMul final.x2 (fieldInv final.z2)

-- ============================================================================
-- Main X25519 API
-- ============================================================================

/-- Perform X25519 scalar multiplication.
    Both inputs and output are 32-byte `ByteArray`s.
    The scalar `k` is clamped per RFC 7748.
    The u-coordinate has its high bit masked before use. -/
def x25519 (k : ByteArray) (u : ByteArray) : ByteArray :=
  let scalar := decodeLE (clamp k)
  let uCoord := decodeUCoordinate u
  let result := montgomeryLadder scalar uCoord
  encodeLE32 result

/-- The standard base point (u = 9) encoded as 32 little-endian bytes. -/
def basePoint : ByteArray :=
  let bs := ByteArray.mkEmpty 32
  let bs := bs.push 9
  let rec pad (i : Nat) (acc : ByteArray) : ByteArray :=
    if i < 31 then pad (i + 1) (acc.push 0)
    else acc
  termination_by 31 - i
  pad 0 bs

-- ============================================================================
-- Tests (RFC 7748 Section 6.1)
-- ============================================================================

/-- Run the RFC 7748 Section 6.1 test vectors. Returns true if all pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test vector 1
  let scalar1 := hexToBytes "a546e36bf0527c9d3b16154b82465edd62144c0ac1fc5a18506a2244ba449ac4"
  let uCoord1 := hexToBytes "e6db6867583030db3594c1a424b15f7c726624ec26b3353b10a903a6d0ab1c4c"
  let expected1 := "c3da55379de9c6908e94ea4df28d084f32eccf03491c71f754b4075577a28552"

  let result1 := x25519 scalar1 uCoord1
  let result1Hex := bytesToHex result1

  if result1Hex == expected1 then
    IO.println "Test vector 1: PASSED"
  else
    IO.println s!"Test vector 1: FAILED"
    IO.println s!"  Expected: {expected1}"
    IO.println s!"  Got:      {result1Hex}"
    allPassed := false

  -- Test vector 2
  let scalar2 := hexToBytes "4b66e9d4d1b4673c5ad22691957d6af5c11b6421e0ea01d42ca4169e7918ba0d"
  let uCoord2 := hexToBytes "e5210f12786811d3f4b7959d0538ae2c31dbe7106fc03c3efc4cd549c715a493"
  let expected2 := "95cbde9476e8907d7aade45cb4b873f88b595a68799fa152e6f8f7647aac7957"

  let result2 := x25519 scalar2 uCoord2
  let result2Hex := bytesToHex result2

  if result2Hex == expected2 then
    IO.println "Test vector 2: PASSED"
  else
    IO.println s!"Test vector 2: FAILED"
    IO.println s!"  Expected: {expected2}"
    IO.println s!"  Got:      {result2Hex}"
    allPassed := false

  if allPassed then
    IO.println "All X25519 tests passed!"
  else
    IO.println "Some X25519 tests FAILED!"

  return allPassed

end LeanTLS.Crypto.X25519
