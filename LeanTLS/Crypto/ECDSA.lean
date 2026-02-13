import LeanTLS.Crypto.SHA256
import LeanTLS.Utils
import LeanTLS.ASN1

set_option autoImplicit false

namespace LeanTLS.Crypto.ECDSA

/-!
# ECDSA Signature Verification over NIST P-256 (secp256r1)

Pure Lean 4 implementation of ECDSA signature verification using the NIST P-256
curve (also known as secp256r1 or prime256v1). Used by the TLS 1.3 handshake to
verify server certificates signed with ECDSA.

All arithmetic uses Lean's arbitrary-precision `Nat`. This is NOT constant-time
and should only be used where timing attacks are not a concern.

References:
- FIPS 186-4 (Digital Signature Standard)
- SEC 1 v2 (Elliptic Curve Cryptography)
- RFC 6979 (Deterministic ECDSA — signing only; not needed for verification)
-/

-- ============================================================================
-- Section 1: P-256 Curve Parameters
-- ============================================================================

/-- The prime field modulus p for P-256. -/
def p : Nat := 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF

/-- The curve parameter a = p - 3 for P-256. -/
def a : Nat := 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFC

/-- The curve parameter b for P-256. -/
def b : Nat := 0x5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B

/-- The order n of the generator point G for P-256. -/
def n : Nat := 0xFFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551

/-- The x-coordinate of the generator point G for P-256. -/
def Gx : Nat := 0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296

/-- The y-coordinate of the generator point G for P-256. -/
def Gy : Nat := 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5

-- ============================================================================
-- Section 2: Modular Arithmetic over Prime p
-- ============================================================================

/-- Reduce a natural number modulo the field prime p. -/
def modP (x : Nat) : Nat :=
  x % p

/-- Field addition: (a + b) mod p -/
def addModP (x y : Nat) : Nat :=
  (x + y) % p

/-- Field subtraction: (a - b) mod p.
    We add p before subtracting to ensure the result is non-negative. -/
def subModP (x y : Nat) : Nat :=
  (x + p - (y % p)) % p

/-- Field multiplication: (a * b) mod p -/
def mulModP (x y : Nat) : Nat :=
  (x * y) % p

/-- Modular exponentiation by repeated squaring: base^exp mod modulus.
    Returns 0 if modulus <= 1. -/
def modPow (base : Nat) (exp : Nat) (modulus : Nat) : Nat :=
  if modulus <= 1 then 0
  else
    let rec go (b : Nat) (e : Nat) (acc : Nat) : Nat :=
      if h : e = 0 then acc
      else
        let acc' := if e % 2 = 1 then (acc * b) % modulus else acc
        have : e / 2 < e := Nat.div_lt_self (Nat.pos_of_ne_zero h) (by omega)
        go ((b * b) % modulus) (e / 2) acc'
    termination_by e
    go (base % modulus) exp 1

/-- Field inversion using Fermat's little theorem: a^(p-2) mod p -/
def invModP (x : Nat) : Nat :=
  modPow x (p - 2) p

-- ============================================================================
-- Section 3: Modular Arithmetic over Order n
-- ============================================================================

/-- Reduce a natural number modulo the group order n. -/
def modN (x : Nat) : Nat :=
  x % n

/-- Addition modulo n. -/
def addModN (x y : Nat) : Nat :=
  (x + y) % n

/-- Multiplication modulo n. -/
def mulModN (x y : Nat) : Nat :=
  (x * y) % n

/-- Modular inverse modulo n using Fermat's little theorem: a^(n-2) mod n -/
def invModN (x : Nat) : Nat :=
  modPow x (n - 2) n

-- ============================================================================
-- Section 4: Point Operations (Affine Coordinates)
-- ============================================================================

/-- A point on the P-256 curve in affine coordinates.
    The point at infinity (identity element) is represented as (0, 0). -/
structure Point where
  x : Nat
  y : Nat
  deriving BEq, Repr

/-- The point at infinity (identity element). -/
def Point.infinity : Point := { x := 0, y := 0 }

/-- Check whether a point is the point at infinity (sentinel: x=0, y=0). -/
def Point.isInfinity (pt : Point) : Bool :=
  pt.x == 0 && pt.y == 0

/-- The generator point G for P-256. -/
def G : Point := { x := Gx, y := Gy }

/-- Point doubling on P-256: compute 2*P.
    Uses the standard affine doubling formula:
      lambda = (3 * x^2 + a) / (2 * y)  mod p
      x_r = lambda^2 - 2*x  mod p
      y_r = lambda * (x - x_r) - y  mod p -/
def pointDouble (pt : Point) : Point :=
  if pt.isInfinity then Point.infinity
  else if pt.y == 0 then Point.infinity
  else
    let x := pt.x
    let y := pt.y
    -- lambda = (3 * x^2 + a) * (2 * y)^(-1) mod p
    let num := addModP (mulModP 3 (mulModP x x)) a
    let den := invModP (mulModP 2 y)
    let lam := mulModP num den
    -- x_r = lam^2 - 2*x mod p
    let xr := subModP (mulModP lam lam) (mulModP 2 x)
    -- y_r = lam * (x - x_r) - y mod p
    let yr := subModP (mulModP lam (subModP x xr)) y
    { x := xr, y := yr }

/-- Point addition on P-256: compute P + Q.
    Handles identity, doubling, and inverse (P = -Q) cases. -/
def pointAdd (pt1 pt2 : Point) : Point :=
  if pt1.isInfinity then pt2
  else if pt2.isInfinity then pt1
  else if pt1.x == pt2.x then
    -- If same x-coordinate, either doubling or inverse
    if pt1.y == pt2.y then
      -- Same point: double
      pointDouble pt1
    else
      -- Inverse points: P + (-P) = infinity
      Point.infinity
  else
    let x1 := pt1.x
    let y1 := pt1.y
    let x2 := pt2.x
    let y2 := pt2.y
    -- lambda = (y2 - y1) * (x2 - x1)^(-1) mod p
    let num := subModP y2 y1
    let den := invModP (subModP x2 x1)
    let lam := mulModP num den
    -- x_r = lam^2 - x1 - x2 mod p
    let xr := subModP (subModP (mulModP lam lam) x1) x2
    -- y_r = lam * (x1 - x_r) - y1 mod p
    let yr := subModP (mulModP lam (subModP x1 xr)) y1
    { x := xr, y := yr }

/-- Scalar multiplication using the double-and-add algorithm.
    Computes k * P on the P-256 curve. -/
def scalarMul (k : Nat) (pt : Point) : Point :=
  if k == 0 then Point.infinity
  else
    let rec go (i : Nat) (acc : Point) (cur : Point) : Point :=
      if h : i = 0 then acc
      else
        let acc' := if i % 2 = 1 then pointAdd acc cur else acc
        let cur' := pointDouble cur
        have : i / 2 < i := Nat.div_lt_self (Nat.pos_of_ne_zero h) (by omega)
        go (i / 2) acc' cur'
    termination_by i
    go k Point.infinity pt

-- ============================================================================
-- Section 5: Octet String to Integer Conversion
-- ============================================================================

/-- Octet String to Integer Primitive: converts a big-endian byte array to a Nat. -/
def os2ip (bytes : ByteArray) : Nat :=
  let rec go (i : Nat) (acc : Nat) : Nat :=
    if h : i < bytes.size then
      go (i + 1) (acc * 256 + (bytes[i]'h).toNat)
    else
      acc
  termination_by bytes.size - i
  go 0 0

-- ============================================================================
-- Section 6: ECDSA Signature Verification
-- ============================================================================

/-- ECDSA signature verification over P-256.
    Parameters:
    - `qx`, `qy`: public key point coordinates
    - `messageHash`: the SHA-256 hash of the message (32 bytes)
    - `r`, `s`: signature components
    Returns `true` if the signature is valid.

    Implements the verification algorithm from FIPS 186-4 Section 4.1.4. -/
def ecdsaVerify (qx qy : Nat) (messageHash : ByteArray) (r s : Nat) : Bool :=
  -- Step 1: Check that r and s are in the valid range [1, n-1]
  if r == 0 || r >= n then false
  else if s == 0 || s >= n then false
  else
    -- Step 2: Compute e from the message hash (truncate to bit length of n if needed)
    -- For P-256, n is 256 bits and SHA-256 produces 256 bits, so no truncation needed
    let e := os2ip messageHash

    -- Step 3: Compute s_inv = s^(n-2) mod n
    let sInv := invModN s

    -- Step 4: Compute u1 = (e * s_inv) mod n
    let u1 := mulModN e sInv

    -- Step 5: Compute u2 = (r * s_inv) mod n
    let u2 := mulModN r sInv

    -- Step 6: Compute R = u1*G + u2*Q
    let capQ : Point := { x := qx, y := qy }
    let u1G := scalarMul u1 G
    let u2Q := scalarMul u2 capQ
    let capR := pointAdd u1G u2Q

    -- Step 7: If R is the point at infinity, the signature is invalid
    if capR.isInfinity then false
    else
      -- Step 8: The signature is valid iff r == R.x mod n
      r == (capR.x % n)

-- ============================================================================
-- Section 7: ASN.1 Signature Parsing
-- ============================================================================

/-- Parse a DER-encoded ECDSA signature: SEQUENCE { INTEGER r, INTEGER s }.
    Returns the (r, s) pair on success, or `none` on parse failure.
    Uses `LeanTLS.ASN1.parseAll` for DER parsing. -/
partial def parseECDSASignature (sig : ByteArray) : Option (Nat × Nat) := do
  let node ← LeanTLS.ASN1.parseAll sig
  let tag := LeanTLS.ASN1.ASN1Node.getTag node
  -- Must be a SEQUENCE (universal constructed, tag number 0x10 = 16)
  if LeanTLS.ASN1.Tag.tagClass tag != LeanTLS.ASN1.TagClass.universal then none
  else if LeanTLS.ASN1.Tag.tagNumber tag != 0x10 then none
  else if LeanTLS.ASN1.Tag.encoding tag != LeanTLS.ASN1.Encoding.constructed then none
  else
    let children := LeanTLS.ASN1.ASN1Node.getChildren node
    if children.size != 2 then none
    else
      let child0 := children[0]!
      let child1 := children[1]!
      let tag0 := LeanTLS.ASN1.ASN1Node.getTag child0
      let tag1 := LeanTLS.ASN1.ASN1Node.getTag child1
      -- Both children must be INTEGER (universal primitive, tag number 2)
      if LeanTLS.ASN1.Tag.tagClass tag0 != LeanTLS.ASN1.TagClass.universal || LeanTLS.ASN1.Tag.tagNumber tag0 != 2 then none
      else if LeanTLS.ASN1.Tag.tagClass tag1 != LeanTLS.ASN1.TagClass.universal || LeanTLS.ASN1.Tag.tagNumber tag1 != 2 then none
      else
        let r := LeanTLS.ASN1.parseInteger (LeanTLS.ASN1.ASN1Node.getValue child0)
        let s := LeanTLS.ASN1.parseInteger (LeanTLS.ASN1.ASN1Node.getValue child1)
        some (r, s)

-- ============================================================================
-- Section 8: Public Key Parsing
-- ============================================================================

/-- Parse an uncompressed EC public key from a byte string.
    Format: 0x04 || x (32 bytes) || y (32 bytes).
    Returns the (x, y) coordinates on success. -/
def parseECPublicKey (bitString : ByteArray) : Option (Nat × Nat) :=
  -- Uncompressed point format: 0x04 followed by 32 bytes x, 32 bytes y
  if bitString.size != 65 then none
  else if bitString.get! 0 != 0x04 then none
  else
    let xBytes := bitString.extract 1 33
    let yBytes := bitString.extract 33 65
    let x := os2ip xBytes
    let y := os2ip yBytes
    some (x, y)

-- ============================================================================
-- Section 9: Tests
-- ============================================================================

/-- Run ECDSA P-256 test vectors. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- --------------------------------------------------------------------------
  -- Test 1: Generator point is on the curve
  -- Verify Gy^2 mod p == (Gx^3 + a*Gx + b) mod p
  -- --------------------------------------------------------------------------
  IO.println "  ECDSA test 1 (generator point on curve)..."
  let lhs := mulModP Gy Gy
  let rhs := addModP (addModP (mulModP Gx (mulModP Gx Gx)) (mulModP a Gx)) b
  if lhs == rhs then
    IO.println "  ECDSA test 1 (generator point on curve): PASSED"
  else
    IO.println s!"  ECDSA test 1 (generator point on curve): FAILED"
    IO.println s!"    LHS (Gy^2 mod p) = {lhs}"
    IO.println s!"    RHS (Gx^3 + a*Gx + b mod p) = {rhs}"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: scalarMul(1, G) == G
  -- --------------------------------------------------------------------------
  IO.println "  ECDSA test 2 (1*G == G)..."
  let oneG := scalarMul 1 G
  if oneG.x == Gx && oneG.y == Gy then
    IO.println "  ECDSA test 2 (1*G == G): PASSED"
  else
    IO.println s!"  ECDSA test 2 (1*G == G): FAILED"
    IO.println s!"    Got x = {oneG.x}"
    IO.println s!"    Got y = {oneG.y}"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: scalarMul(n, G) == point at infinity
  -- --------------------------------------------------------------------------
  IO.println "  ECDSA test 3 (n*G == infinity)..."
  let nG := scalarMul n G
  if nG.isInfinity then
    IO.println "  ECDSA test 3 (n*G == infinity): PASSED"
  else
    IO.println s!"  ECDSA test 3 (n*G == infinity): FAILED"
    IO.println s!"    Got x = {nG.x}, y = {nG.y}"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 4: Known ECDSA verification (RFC 6979 A.2.5 P-256/SHA-256)
  -- Message: "sample"
  -- Hash: SHA-256("sample") = af2bdbe1aa9b6ec1e2ade1d694f41fc71a831d0268e9891562113d8a62add1bf
  -- --------------------------------------------------------------------------
  IO.println "  ECDSA test 4 (RFC 6979 A.2.5 verify)..."
  let testQx : Nat := 0x60FED4BA255A9D31C961EB74C6356D68C049B8923B61FA6CE669622E60F29FB6
  let testQy : Nat := 0x7903FE1008B8BC99A41AE9E95628BC64F2F1B20C2D7E9F5177A3C294D4462299
  let msgHash := LeanTLS.Utils.hexToBytes "af2bdbe1aa9b6ec1e2ade1d694f41fc71a831d0268e9891562113d8a62add1bf"
  let testR : Nat := 0xEFD48B2AACB6A8FD1140DD9CD45E81D69D2C877B56AAF991C34D0EA84EAF3716
  let testS : Nat := 0xF7CB1C942D657C41D436C7A1B6E29F65F3E900DBB9AFF4064DC4AB2F843ACDA8

  let verifyResult := ecdsaVerify testQx testQy msgHash testR testS
  if verifyResult then
    IO.println "  ECDSA test 4 (RFC 6979 A.2.5 verify): PASSED"
  else
    IO.println "  ECDSA test 4 (RFC 6979 A.2.5 verify): FAILED — signature did not verify"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 5: Corrupted signature should be rejected
  -- Flip one bit in r to produce an invalid signature
  -- --------------------------------------------------------------------------
  IO.println "  ECDSA test 5 (corrupted signature rejection)..."
  let corruptR : Nat := testR ^^^ 1  -- flip the least significant bit
  let corruptResult := ecdsaVerify testQx testQy msgHash corruptR testS
  if !corruptResult then
    IO.println "  ECDSA test 5 (corrupted signature rejected): PASSED"
  else
    IO.println "  ECDSA test 5 (corrupted signature rejected): FAILED — corrupted sig was accepted"
    allPassed := false

  if allPassed then
    IO.println "All ECDSA P-256 tests passed!"
  else
    IO.println "Some ECDSA P-256 tests FAILED!"

  return allPassed

end LeanTLS.Crypto.ECDSA
