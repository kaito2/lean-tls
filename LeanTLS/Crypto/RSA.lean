import LeanTLS.Crypto.SHA256
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.Crypto.RSA

/-!
# RSA-PSS Signature Verification (RFC 8017)

Pure Lean 4 implementation of RSASSA-PSS-VERIFY using SHA-256 as the hash
function and MGF1-SHA-256 as the mask generation function.

All big-integer arithmetic uses Lean's arbitrary-precision `Nat`. This is
NOT constant-time and should only be used where timing attacks are not a
concern.
-/

-- ============================================================================
-- Section 1: Big-integer helpers
-- ============================================================================

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

/-- Number of bits needed to represent n (floor(log2(n)) + 1, or 0 for n = 0). -/
def natBitLength (n : Nat) : Nat :=
  let rec go (val : Nat) (bits : Nat) : Nat :=
    if val = 0 then bits
    else go (val / 2) (bits + 1)
  termination_by val
  go n 0

-- ============================================================================
-- Section 2: Octet string / integer conversions (RFC 8017 Section 4)
-- ============================================================================

/-- Octet String to Integer Primitive (RFC 8017 Section 4.2).
    Converts a big-endian byte array to a Nat. -/
def os2ip (bytes : ByteArray) : Nat :=
  let rec go (i : Nat) (acc : Nat) : Nat :=
    if h : i < bytes.size then
      go (i + 1) (acc * 256 + (bytes[i]'h).toNat)
    else
      acc
  termination_by bytes.size - i
  go 0 0

/-- Integer to Octet String Primitive (RFC 8017 Section 4.1).
    Converts a Nat to a big-endian byte array of exactly `len` bytes.
    Returns `none` if n >= 256^len. -/
def i2osp (n : Nat) (len : Nat) : Option ByteArray :=
  if len = 0 then
    if n = 0 then some ByteArray.empty else none
  else
    -- Check that n fits in `len` bytes
    if n >= 256 ^ len then none
    else
      -- Build the byte array from least significant to most significant,
      -- then reverse
      let rec go (remaining : Nat) (count : Nat) (acc : Array UInt8) : Array UInt8 :=
        if count = 0 then acc
        else go (remaining / 256) (count - 1) (acc.push (remaining % 256).toUInt8)
      termination_by count
      let bytes := go n len #[]
      -- Reverse to get big-endian order
      some (ByteArray.mk bytes.reverse)

-- ============================================================================
-- Section 3: Mask Generation Function (RFC 8017 Section B.2.1)
-- ============================================================================

/-- Encode a Nat as a 4-byte big-endian ByteArray. -/
private def encodeUInt32BE (n : Nat) : ByteArray :=
  ByteArray.mk #[
    (n >>> 24 % 256).toUInt8,
    (n >>> 16 % 256).toUInt8,
    (n >>> 8 % 256).toUInt8,
    (n % 256).toUInt8
  ]

/-- MGF1 with SHA-256 (RFC 8017 Section B.2.1).
    Generates a mask of `maskLen` bytes from the given seed. -/
def mgf1SHA256 (seed : ByteArray) (maskLen : Nat) : ByteArray :=
  -- Number of hash iterations needed: ceil(maskLen / 32)
  let hashLen : Nat := 32
  let iterations := (maskLen + hashLen - 1) / hashLen
  let rec go (counter : Nat) (acc : ByteArray) : ByteArray :=
    if counter >= iterations then acc
    else
      let counterBytes := encodeUInt32BE counter
      let hashInput := seed ++ counterBytes
      let hashOutput := LeanTLS.Crypto.SHA256.hash hashInput
      go (counter + 1) (acc ++ hashOutput)
  termination_by iterations - counter
  let fullOutput := go 0 ByteArray.empty
  -- Truncate to maskLen bytes
  fullOutput.extract 0 maskLen

-- ============================================================================
-- Section 4: XOR helper
-- ============================================================================

/-- XOR two ByteArrays of equal length. If lengths differ, XOR up to the
    shorter length. -/
def xorByteArrays (a b : ByteArray) : ByteArray :=
  let len := Nat.min a.size b.size
  Nat.fold (n := len) (init := ByteArray.emptyWithCapacity len) fun i _ acc =>
    acc.push ((a.get! i) ^^^ (b.get! i))

-- ============================================================================
-- Section 5: ByteArray helper to set a byte
-- ============================================================================

/-- Set byte at index `i` in a ByteArray. Returns the array unchanged if
    `i` is out of bounds. -/
private def setByteAt (ba : ByteArray) (i : Nat) (val : UInt8) : ByteArray :=
  if i < ba.size then ba.set! i val else ba

-- ============================================================================
-- Section 6: EMSA-PSS-VERIFY (RFC 8017 Section 9.1.2)
-- ============================================================================

/-- EMSA-PSS-VERIFY operation (RFC 8017 Section 9.1.2).
    Verifies a PSS-encoded message against the message hash.
    Uses SHA-256 (hLen = 32) and salt length sLen (default 32). -/
def emsaPSSVerify (mHash : ByteArray) (em : ByteArray) (emBits : Nat)
    (sLen : Nat := 32) : Bool :=
  let hLen : Nat := 32  -- SHA-256 output length

  -- Step 1: Check mHash length
  if mHash.size != hLen then false

  -- Step 2: Check emLen >= hLen + sLen + 2
  else
  let emLen := em.size
  if emLen < hLen + sLen + 2 then false

  -- Step 3: Check last byte is 0xBC
  else if em.get! (emLen - 1) != 0xBC then false

  else
  -- Step 4: Extract maskedDB (leftmost emLen - hLen - 1 octets)
  let dbLen := emLen - hLen - 1
  let maskedDB := em.extract 0 dbLen

  -- Step 5: Extract H (next hLen octets)
  let capH := em.extract dbLen (dbLen + hLen)

  -- Step 6: Check top bits of maskedDB[0]
  -- The top (8 * emLen - emBits) bits of the leftmost octet must be zero
  let topBits := 8 * emLen - emBits
  if topBits > 8 then false
  else
  let topMask : UInt8 := if topBits = 0 then 0xFF else (0xFF : UInt8) >>> topBits.toUInt8
  -- The bits above topMask should be zero
  if (maskedDB.get! 0) &&& topMask.complement != 0 then false

  else
  -- Step 7: Compute dbMask = MGF1(H, dbLen)
  let dbMask := mgf1SHA256 capH dbLen

  -- Step 8: Compute DB = maskedDB XOR dbMask
  let db := xorByteArrays maskedDB dbMask

  -- Step 9: Set top bits of DB[0] to zero
  let db := setByteAt db 0 (db.get! 0 &&& topMask)

  -- Step 10: Check DB format: (emLen - hLen - sLen - 2) zero bytes, then 0x01
  let psLen := emLen - hLen - sLen - 2
  let rec checkZeros (i : Nat) : Bool :=
    if i >= psLen then true
    else if db.get! i != 0x00 then false
    else checkZeros (i + 1)
  termination_by psLen - i
  if !checkZeros 0 then false
  else if db.get! psLen != 0x01 then false

  else
  -- Step 11: Extract salt (last sLen bytes of DB)
  let salt := db.extract (db.size - sLen) db.size

  -- Step 12: Construct M' = (0x)00 00 00 00 00 00 00 00 || mHash || salt
  let mPrime := ByteArray.mk (Array.replicate 8 (0x00 : UInt8)) ++ mHash ++ salt

  -- Step 13: Compute H' = SHA-256(M')
  let hPrime := LeanTLS.Crypto.SHA256.hash mPrime

  -- Step 14: Check H == H'
  LeanTLS.Utils.constantTimeEq capH hPrime

-- ============================================================================
-- Section 7: RSASSA-PSS-VERIFY (RFC 8017 Section 8.1.2)
-- ============================================================================

/-- RSASSA-PSS-VERIFY: Top-level RSA-PSS signature verification.
    Parameters:
    - `n`: RSA modulus
    - `e`: RSA public exponent
    - `message`: the message that was signed
    - `signature`: the signature bytes
    Returns `true` if the signature is valid. -/
def rsassaPSSVerify (n : Nat) (e : Nat) (message : ByteArray) (signature : ByteArray) : Bool :=
  -- Step 1: Convert signature to integer
  let s := os2ip signature

  -- Step 2: Check s < n
  if s >= n then false

  else
  -- Step 3: RSA verification primitive: m = s^e mod n
  let m := modPow s e n

  -- Step 4: Compute bit length of modulus
  let modBits := natBitLength n

  -- Step 5: Compute emLen = ceil((modBits - 1) / 8)
  let emLen := (modBits + 6) / 8

  -- Step 6: Convert m to encoded message
  match i2osp m emLen with
  | none => false
  | some em =>
    -- Step 7: emBits = modBits - 1
    let emBits := modBits - 1

    -- Step 8: Hash the message
    let mHash := LeanTLS.Crypto.SHA256.hash message

    -- Step 9: EMSA-PSS-VERIFY
    emsaPSSVerify mHash em emBits 32

-- ============================================================================
-- Section 8: Tests
-- ============================================================================

/-- Run RSA-PSS test vectors. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- ---- Test 1: modPow basic ----
  IO.println "  RSA test 1a (modPow 2 10 1000)..."
  let r1a := modPow 2 10 1000
  if r1a == 24 then
    IO.println "  RSA test 1a (modPow 2^10 mod 1000): PASSED"
  else
    IO.println s!"  RSA test 1a (modPow 2^10 mod 1000): FAILED — got {r1a}, expected 24"
    allPassed := false

  let r1b := modPow 3 13 1000000007
  if r1b == 1594323 then
    IO.println "  RSA test 1b (modPow 3^13 mod 10^9+7): PASSED"
  else
    IO.println s!"  RSA test 1b (modPow 3^13 mod 10^9+7): FAILED — got {r1b}, expected 1594323"
    allPassed := false

  -- ---- Test 2: os2ip / i2osp roundtrip ----
  let t2input := LeanTLS.Utils.hexToBytes "0102FF"
  let t2val := os2ip t2input
  if t2val == 66303 then
    IO.println "  RSA test 2a (os2ip 0x0102FF = 66303): PASSED"
  else
    IO.println s!"  RSA test 2a (os2ip 0x0102FF): FAILED — got {t2val}, expected 66303"
    allPassed := false

  match i2osp 66303 3 with
  | some bs =>
    if bs == LeanTLS.Utils.hexToBytes "0102FF" then
      IO.println "  RSA test 2b (i2osp 66303 3 roundtrip): PASSED"
    else
      IO.println s!"  RSA test 2b (i2osp 66303 3 roundtrip): FAILED — got {LeanTLS.Utils.bytesToHex bs}"
      allPassed := false
  | none =>
    IO.println "  RSA test 2b (i2osp 66303 3): FAILED — returned none"
    allPassed := false

  match i2osp 256 1 with
  | none =>
    IO.println "  RSA test 2c (i2osp 256 1 = none): PASSED"
  | some _ =>
    IO.println "  RSA test 2c (i2osp 256 1 = none): FAILED — returned some"
    allPassed := false

  -- ---- Test 3: mgf1SHA256 ----
  -- mgf1SHA256 (hexToBytes "0102030405") 64 should equal
  -- SHA-256("0102030405" ++ 00000000) ++ SHA-256("0102030405" ++ 00000001)
  let mgfSeed := LeanTLS.Utils.hexToBytes "0102030405"
  let mgfResult := mgf1SHA256 mgfSeed 64
  let expected_h0 := LeanTLS.Crypto.SHA256.hash (mgfSeed ++ ByteArray.mk #[0x00, 0x00, 0x00, 0x00])
  let expected_h1 := LeanTLS.Crypto.SHA256.hash (mgfSeed ++ ByteArray.mk #[0x00, 0x00, 0x00, 0x01])
  let expectedMgf := expected_h0 ++ expected_h1
  if mgfResult == expectedMgf then
    IO.println "  RSA test 3 (mgf1SHA256): PASSED"
  else
    IO.println s!"  RSA test 3 (mgf1SHA256): FAILED"
    IO.println s!"    expected: {LeanTLS.Utils.bytesToHex expectedMgf}"
    IO.println s!"    got:      {LeanTLS.Utils.bytesToHex mgfResult}"
    allPassed := false

  -- ---- Test 4: Full RSA-PSS verification with known test vector ----
  IO.println "  RSA test 4 (RSA-PSS verify with test vector)..."
  let nHex := "FC249051AB4F1A8F13B41FB382897E7FECAA5824ADF0E0054B3DBDB45E8EFF04655D8F3474998E1F7A692CEDA02D1879A0766B95681617C26DAEFA452EF2A8B2FD165DC094BFAE27DDAD349630AF1AB84BCF1C6082C092639256FE5FBF8299127A3CF08D0FC5497A96BAAEDC3A37BBE2EF69EF488C4C9920847B9286EF9741D35A1D7405ABC22A6C4CED935B24757547F1C6ECF2304760197C4349A58AF12241F82042D8F47546865E6A85E824E18D6F01824785C8979AD8983540E39AEFBD3360EAA17BB4D7130230ABAB286304A46DD846AD396A243A5E3B6E576C4792471A581BC232C855CBD45217A3716199DA261F9652730091B63EE399C9BBE13CBA25"
  let n := os2ip (LeanTLS.Utils.hexToBytes nHex)
  let e : Nat := 65537
  let message := "test message for RSA-PSS verification".toUTF8
  let sigHex := "04fb5979c088ed9a0f42affa5a3418e1245abba6a03dc180e5f9294d3cddb33bbd051e12cf7441aae2a7018bfaacf6a07180490609604defeb37f234318d6e4bb578483797cce6667b21723434169b865652ce1b39517368a50d8d838368eaa1ad5c92dc173a0c92bba70e4d268d5453015e676313f6d5ff9e5bf5ec3c3380d5885ac4596e2a9f992028a86900d59cb072c9f2f33e89232d464d591af62fd60a36f36de3099f09cbe99a297b2a95650912e80e07d8bd096bdfd2f49ac10ae59650f123e873618ceef38a649739dd1c2a36fce6f73a26e229cca161026c666c5d4889466d58340774b112af16305a8cbf1f74761318b7deece9bb6842b0a58e89"
  let sig := LeanTLS.Utils.hexToBytes sigHex
  let verifyResult := rsassaPSSVerify n e message sig
  if verifyResult then
    IO.println "  RSA test 4 (RSA-PSS verify valid signature): PASSED"
  else
    IO.println "  RSA test 4 (RSA-PSS verify valid signature): FAILED — signature did not verify"
    allPassed := false

  -- ---- Test 5: Corrupted signature should fail ----
  IO.println "  RSA test 5 (RSA-PSS corrupted signature)..."
  -- Flip one byte in the signature
  let corruptedSig := sig.set! 10 (sig.get! 10 ^^^ 0xFF)
  let corruptResult := rsassaPSSVerify n e message corruptedSig
  if !corruptResult then
    IO.println "  RSA test 5 (RSA-PSS corrupted signature rejected): PASSED"
  else
    IO.println "  RSA test 5 (RSA-PSS corrupted signature rejected): FAILED — corrupted sig was accepted"
    allPassed := false

  if allPassed then
    IO.println "All RSA-PSS tests passed!"
  else
    IO.println "Some RSA-PSS tests FAILED!"

  return allPassed

end LeanTLS.Crypto.RSA
