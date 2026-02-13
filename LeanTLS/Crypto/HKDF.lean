import LeanTLS.Crypto.HMAC
import LeanTLS.Crypto.SHA256
import LeanTLS.Crypto.SHA384
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.Crypto.HKDF

/-!
# HKDF (RFC 5869)

Pure Lean 4 implementation of HMAC-based Extract-and-Expand Key Derivation Function
using HMAC-SHA-256 as the underlying PRF.

HKDF follows a two-stage approach:
1. **Extract**: HKDF-Extract(salt, IKM) -> PRK
2. **Expand**: HKDF-Expand(PRK, info, L) -> OKM
-/

-- ============================================================================
-- Section 1: Constants
-- ============================================================================

/-- SHA-256 output length in bytes. -/
private def hashLen : Nat := 32

-- ============================================================================
-- Section 2: HKDF-Extract (RFC 5869 Section 2.2)
-- ============================================================================

/-- HKDF-Extract(salt, IKM) = HMAC-SHA-256(salt, IKM)

    If salt is not provided (empty ByteArray), it is set to a string of
    HashLen (32) zero bytes. -/
def extract (salt : ByteArray) (ikm : ByteArray) : ByteArray :=
  let effectiveSalt :=
    if salt.size == 0 then
      -- Use a string of 32 zero bytes when salt is empty
      Nat.fold (n := hashLen) (init := ByteArray.emptyWithCapacity hashLen) fun _ _ acc =>
        acc.push 0x00
    else
      salt
  LeanTLS.Crypto.HMAC.hmacSHA256 effectiveSalt ikm

-- ============================================================================
-- Section 3: HKDF-Expand (RFC 5869 Section 2.3)
-- ============================================================================

/-- HKDF-Expand(PRK, info, L) -> OKM

    Expands the pseudorandom key PRK to the desired length L (in bytes)
    using the optional context/application-specific info.

    T(0) = empty string
    T(i) = HMAC-SHA-256(PRK, T(i-1) || info || i)    where i is a single byte

    OKM = T(1) || T(2) || ... || T(N), truncated to first L bytes
    where N = ceil(L / HashLen) -/
def expand (prk : ByteArray) (info : ByteArray) (length : Nat) : ByteArray :=
  -- N = ceil(L / hashLen)
  let n := (length + hashLen - 1) / hashLen
  -- Iteratively compute T(1), T(2), ..., T(N), concatenating results
  let (okm, _) := Nat.fold (n := n) (init := (ByteArray.emptyWithCapacity (n * hashLen), ByteArray.empty))
    fun i _ (acc, tPrev) =>
      -- Counter byte: i is 0-based from Nat.fold, RFC uses 1-based
      let counter : UInt8 := (i + 1).toUInt8
      -- T(i) = HMAC-SHA-256(PRK, T(i-1) || info || counter)
      let input := tPrev ++ info |>.push counter
      let ti := LeanTLS.Crypto.HMAC.hmacSHA256 prk input
      (acc ++ ti, ti)
  -- Truncate to desired length
  ByteArray.copySlice okm 0 (ByteArray.emptyWithCapacity length) 0 length

-- ============================================================================
-- Section 4: Constants (SHA-384)
-- ============================================================================

/-- SHA-384 output length in bytes. -/
private def hashLen384 : Nat := 48

-- ============================================================================
-- Section 5: HKDF-Extract for SHA-384 (RFC 5869 Section 2.2)
-- ============================================================================

/-- HKDF-Extract using HMAC-SHA-384.
    HKDF-Extract(salt, IKM) = HMAC-SHA-384(salt, IKM)

    If salt is not provided (empty ByteArray), it is set to a string of
    HashLen (48) zero bytes. -/
def extractSHA384 (salt : ByteArray) (ikm : ByteArray) : ByteArray :=
  let effectiveSalt :=
    if salt.size == 0 then
      -- Use a string of 48 zero bytes when salt is empty
      Nat.fold (n := hashLen384) (init := ByteArray.emptyWithCapacity hashLen384) fun _ _ acc =>
        acc.push 0x00
    else
      salt
  LeanTLS.Crypto.HMAC.hmacSHA384 effectiveSalt ikm

-- ============================================================================
-- Section 6: HKDF-Expand for SHA-384 (RFC 5869 Section 2.3)
-- ============================================================================

/-- HKDF-Expand using HMAC-SHA-384.
    Expands the pseudorandom key PRK to the desired length L (in bytes)
    using the optional context/application-specific info.

    T(0) = empty string
    T(i) = HMAC-SHA-384(PRK, T(i-1) || info || i)    where i is a single byte

    OKM = T(1) || T(2) || ... || T(N), truncated to first L bytes
    where N = ceil(L / HashLen) -/
def expandSHA384 (prk : ByteArray) (info : ByteArray) (length : Nat) : ByteArray :=
  -- N = ceil(L / hashLen384)
  let n := (length + hashLen384 - 1) / hashLen384
  -- Iteratively compute T(1), T(2), ..., T(N), concatenating results
  let (okm, _) := Nat.fold (n := n) (init := (ByteArray.emptyWithCapacity (n * hashLen384), ByteArray.empty))
    fun i _ (acc, tPrev) =>
      -- Counter byte: i is 0-based from Nat.fold, RFC uses 1-based
      let counter : UInt8 := (i + 1).toUInt8
      -- T(i) = HMAC-SHA-384(PRK, T(i-1) || info || counter)
      let input := tPrev ++ info |>.push counter
      let ti := LeanTLS.Crypto.HMAC.hmacSHA384 prk input
      (acc ++ ti, ti)
  -- Truncate to desired length
  ByteArray.copySlice okm 0 (ByteArray.emptyWithCapacity length) 0 length

-- ============================================================================
-- Section 7: Test vectors (RFC 5869 Appendix A)
-- ============================================================================

/-- Run HKDF test vectors from RFC 5869 Appendix A. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test Case 1 (Basic test case with SHA-256)
  -- IKM  = 0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b (22 bytes of 0x0b)
  -- salt = 0x000102030405060708090a0b0c (13 bytes)
  -- info = 0xf0f1f2f3f4f5f6f7f8f9 (10 bytes)
  -- L    = 42
  let ikm1 := LeanTLS.Utils.hexToBytes "0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b"
  let salt1 := LeanTLS.Utils.hexToBytes "000102030405060708090a0b0c"
  let info1 := LeanTLS.Utils.hexToBytes "f0f1f2f3f4f5f6f7f8f9"
  let expectedPrk1 := "077709362c2e32df0ddc3f0dc47bba6390b6c73bb50f9c3122ec844ad7c2b3e5"
  let expectedOkm1 := "3cb25f25faacd57a90434f64d0362f2a2d2d0a90cf1a5a4c5db02d56ecc4c5bf34007208d5b887185865"

  let prk1 := extract salt1 ikm1
  let resultPrk1 := LeanTLS.Crypto.SHA256.toHex prk1
  if resultPrk1 == expectedPrk1 then
    IO.println "  HKDF test 1 Extract: PASSED"
  else
    IO.println "  HKDF test 1 Extract: FAILED"
    IO.println s!"    expected: {expectedPrk1}"
    IO.println s!"    got:      {resultPrk1}"
    allPassed := false

  let okm1 := expand prk1 info1 42
  let resultOkm1 := LeanTLS.Crypto.SHA256.toHex okm1
  if resultOkm1 == expectedOkm1 then
    IO.println "  HKDF test 1 Expand:  PASSED"
  else
    IO.println "  HKDF test 1 Expand:  FAILED"
    IO.println s!"    expected: {expectedOkm1}"
    IO.println s!"    got:      {resultOkm1}"
    allPassed := false

  -- Test Case 2 (Longer inputs/outputs with SHA-256)
  -- IKM  = 80 bytes
  -- salt = 80 bytes
  -- info = 80 bytes
  -- L    = 82
  let ikm2 := LeanTLS.Utils.hexToBytes "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f"
  let salt2 := LeanTLS.Utils.hexToBytes "606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeaf"
  let info2 := LeanTLS.Utils.hexToBytes "b0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
  let expectedPrk2 := "06a6b88c5853361a06104c9ceb35b45cef760014904671014a193f40c15fc244"
  let expectedOkm2 := "b11e398dc80327a1c8e7f78c596a49344f012eda2d4efad8a050cc4c19afa97c59045a99cac7827271cb41c65e590e09da3275600c2f09b8367793a9aca3db71cc30c58179ec3e87c14c01d5c1f3434f1d87"

  let prk2 := extract salt2 ikm2
  let resultPrk2 := LeanTLS.Crypto.SHA256.toHex prk2
  if resultPrk2 == expectedPrk2 then
    IO.println "  HKDF test 2 Extract: PASSED"
  else
    IO.println "  HKDF test 2 Extract: FAILED"
    IO.println s!"    expected: {expectedPrk2}"
    IO.println s!"    got:      {resultPrk2}"
    allPassed := false

  let okm2 := expand prk2 info2 82
  let resultOkm2 := LeanTLS.Crypto.SHA256.toHex okm2
  if resultOkm2 == expectedOkm2 then
    IO.println "  HKDF test 2 Expand:  PASSED"
  else
    IO.println "  HKDF test 2 Expand:  FAILED"
    IO.println s!"    expected: {expectedOkm2}"
    IO.println s!"    got:      {resultOkm2}"
    allPassed := false

  -- Test Case 3 (Zero-length salt and info with SHA-256)
  -- IKM  = 0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b (22 bytes of 0x0b)
  -- salt = (empty — uses 32 zero bytes internally)
  -- info = (empty)
  -- L    = 42
  let ikm3 := LeanTLS.Utils.hexToBytes "0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b"
  let salt3 := ByteArray.empty
  let info3 := ByteArray.empty
  let expectedPrk3 := "19ef24a32c717b167f33a91d6f648bdf96596776afdb6377ac434c1c293ccb04"
  let expectedOkm3 := "8da4e775a563c18f715f802a063c5a31b8a11f5c5ee1879ec3454e5f3c738d2d9d201395faa4b61a96c8"

  let prk3 := extract salt3 ikm3
  let resultPrk3 := LeanTLS.Crypto.SHA256.toHex prk3
  if resultPrk3 == expectedPrk3 then
    IO.println "  HKDF test 3 Extract: PASSED"
  else
    IO.println "  HKDF test 3 Extract: FAILED"
    IO.println s!"    expected: {expectedPrk3}"
    IO.println s!"    got:      {resultPrk3}"
    allPassed := false

  let okm3 := expand prk3 info3 42
  let resultOkm3 := LeanTLS.Crypto.SHA256.toHex okm3
  if resultOkm3 == expectedOkm3 then
    IO.println "  HKDF test 3 Expand:  PASSED"
  else
    IO.println "  HKDF test 3 Expand:  FAILED"
    IO.println s!"    expected: {expectedOkm3}"
    IO.println s!"    got:      {resultOkm3}"
    allPassed := false

  -- ---- HKDF-SHA-384 test vectors ----

  -- Test Case 1 (SHA-384 variant of RFC 5869 Test Case 1)
  -- IKM  = 0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b (22 bytes of 0x0b)
  -- salt = 0x000102030405060708090a0b0c (13 bytes)
  -- info = 0xf0f1f2f3f4f5f6f7f8f9 (10 bytes)
  -- L    = 42
  let expectedPrk384_1 := "704b39990779ce1dc548052c7dc39f303570dd13fb39f7acc564680bef80e8dec70ee9a7e1f3e293ef68eceb072a5ade"
  let expectedOkm384_1 := "9b5097a86038b805309076a44b3a9f38063e25b516dcbf369f394cfab43685f748b6457763e4f0204fc5"

  let prk384_1 := extractSHA384 salt1 ikm1
  let resultPrk384_1 := LeanTLS.Crypto.SHA384.toHex prk384_1
  if resultPrk384_1 == expectedPrk384_1 then
    IO.println "  HKDF-SHA-384 test 1 Extract: PASSED"
  else
    IO.println "  HKDF-SHA-384 test 1 Extract: FAILED"
    IO.println s!"    expected: {expectedPrk384_1}"
    IO.println s!"    got:      {resultPrk384_1}"
    allPassed := false

  let okm384_1 := expandSHA384 prk384_1 info1 42
  let resultOkm384_1 := LeanTLS.Crypto.SHA384.toHex okm384_1
  if resultOkm384_1 == expectedOkm384_1 then
    IO.println "  HKDF-SHA-384 test 1 Expand:  PASSED"
  else
    IO.println "  HKDF-SHA-384 test 1 Expand:  FAILED"
    IO.println s!"    expected: {expectedOkm384_1}"
    IO.println s!"    got:      {resultOkm384_1}"
    allPassed := false

  -- Test Case 2 (SHA-384 variant: zero-length salt and info)
  -- IKM  = 0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b (22 bytes of 0x0b)
  -- salt = (empty — uses 48 zero bytes internally)
  -- info = (empty)
  -- L    = 42
  let expectedPrk384_2 := "10e40cf072a4c5626e43dd22c1cf727d4bb140975c9ad0cbc8e45b40068f8f0ba57cdb598af9dfa6963a96899af047e5"
  let expectedOkm384_2 := "c8c96e710f89b0d7990bca68bcdec8cf854062e54c73a7abc743fade9b242daacc1cea5670415b52849c"

  let prk384_2 := extractSHA384 salt3 ikm3
  let resultPrk384_2 := LeanTLS.Crypto.SHA384.toHex prk384_2
  if resultPrk384_2 == expectedPrk384_2 then
    IO.println "  HKDF-SHA-384 test 2 Extract: PASSED"
  else
    IO.println "  HKDF-SHA-384 test 2 Extract: FAILED"
    IO.println s!"    expected: {expectedPrk384_2}"
    IO.println s!"    got:      {resultPrk384_2}"
    allPassed := false

  let okm384_2 := expandSHA384 prk384_2 info3 42
  let resultOkm384_2 := LeanTLS.Crypto.SHA384.toHex okm384_2
  if resultOkm384_2 == expectedOkm384_2 then
    IO.println "  HKDF-SHA-384 test 2 Expand:  PASSED"
  else
    IO.println "  HKDF-SHA-384 test 2 Expand:  FAILED"
    IO.println s!"    expected: {expectedOkm384_2}"
    IO.println s!"    got:      {resultOkm384_2}"
    allPassed := false

  return allPassed

end LeanTLS.Crypto.HKDF
