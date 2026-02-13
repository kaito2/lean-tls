import LeanTLS.Crypto.AES
import LeanTLS.Crypto.GCM
import LeanTLS.Utils

/-
  AES-256-GCM Authenticated Encryption (NIST SP 800-38D)

  Implements AES-256-GCM using the GHASH/GF(2^128) machinery from LeanTLS.Crypto.GCM
  and AES-256 block cipher from LeanTLS.Crypto.AES.

  The only difference from AES-128-GCM is the use of a 256-bit (32-byte) key
  with AES-256 (14 rounds) instead of AES-128 (10 rounds).
-/

set_option autoImplicit false

namespace LeanTLS.Crypto.GCM256

/-! ## Utility Functions -/

/-- XOR two ByteArrays of equal length. If lengths differ, XOR up to the shorter length. -/
private def xorBytes (a : ByteArray) (b : ByteArray) : ByteArray := Id.run do
  let len := min a.size b.size
  let mut result := ByteArray.mkEmpty len
  for i in [:len] do
    -- Safe: i < len = min a.size b.size, so i < a.size and i < b.size
    result := result.push (a.get! i ^^^ b.get! i)
  return result

/-- Create a ByteArray of n zero bytes. -/
private def zeroBlock (n : Nat) : ByteArray :=
  Nat.fold (n := n) (init := ByteArray.mkEmpty n) fun _ _ acc => acc.push 0

/-- Increment the rightmost 32 bits (bytes 12-15) of a 16-byte block in big-endian. -/
private def incrCounter (block : ByteArray) : ByteArray := Id.run do
  -- Safe: block is always a 16-byte counter block; indices 12..15 are in bounds
  let b12 := block.get! 12
  let b13 := block.get! 13
  let b14 := block.get! 14
  let b15 := block.get! 15
  let ctr : UInt32 :=
    (b12.toUInt32 <<< 24) ||| (b13.toUInt32 <<< 16) |||
    (b14.toUInt32 <<< 8) ||| b15.toUInt32
  let ctr' := ctr + 1
  let mut result := block
  result := result.set! 12 ((ctr' >>> 24).toUInt8)
  result := result.set! 13 ((ctr' >>> 16).toUInt8)
  result := result.set! 14 ((ctr' >>> 8).toUInt8)
  result := result.set! 15 (ctr'.toUInt8)
  return result

/-! ## AES-256-GCM Encryption and Decryption -/

/-- AES-256-GCM encrypt.
    - key: 32-byte AES-256 key
    - iv: 12-byte initialization vector (nonce)
    - plaintext: arbitrary-length plaintext
    - aad: additional authenticated data
    Returns (ciphertext, tag) where tag is 16 bytes. -/
def encrypt (key : ByteArray) (iv : ByteArray) (plaintext : ByteArray) (aad : ByteArray) : ByteArray × ByteArray := Id.run do
  -- Pre-expand the AES-256 key (240 bytes)
  let expandedKey := LeanTLS.Crypto.AES.keyExpansion256 key

  -- H = AES_K(0^128)
  let h := LeanTLS.Crypto.AES.encryptBlock256 expandedKey (zeroBlock 16)

  -- J0 = IV || 0x00000001 (for 96-bit IV)
  let mut j0 := ByteArray.mkEmpty 16
  for i in [:12] do
    -- Safe: iv is 12 bytes; i ranges over [0, 12)
    j0 := j0.push (iv.get! i)
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x01

  -- Tag_pre = AES_K(J0)
  let tagPre := LeanTLS.Crypto.AES.encryptBlock256 expandedKey j0

  -- Counter mode encryption
  let mut counter := j0
  let mut ciphertext := ByteArray.mkEmpty plaintext.size
  let fullBlocks := plaintext.size / 16
  let remainder := plaintext.size % 16

  -- Process full 16-byte blocks
  for i in [:fullBlocks] do
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock256 expandedKey counter
    let off := i * 16
    for j in [:16] do
      -- Safe: off + j < fullBlocks*16 <= plaintext.size; keystream is 16 bytes
      ciphertext := ciphertext.push (plaintext.get! (off + j) ^^^ keystream.get! j)

  -- Process remaining bytes (partial block)
  if remainder > 0 then
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock256 expandedKey counter
    let off := fullBlocks * 16
    for j in [:remainder] do
      -- Safe: off + j < plaintext.size; j < remainder <= 15 < keystream.size
      ciphertext := ciphertext.push (plaintext.get! (off + j) ^^^ keystream.get! j)

  -- Compute authentication tag using GHASH from GCM module
  let s := LeanTLS.Crypto.GCM.ghash h aad ciphertext
  let tag := xorBytes s tagPre

  return (ciphertext, tag)

/-- AES-256-GCM decrypt.
    - key: 32-byte AES-256 key
    - iv: 12-byte initialization vector (nonce)
    - ciphertext: ciphertext to decrypt
    - aad: additional authenticated data
    - tag: 16-byte authentication tag
    Returns `some plaintext` if tag verifies, `none` otherwise. -/
def decrypt (key : ByteArray) (iv : ByteArray) (ciphertext : ByteArray) (aad : ByteArray) (tag : ByteArray) : Option ByteArray := Id.run do
  -- Pre-expand the AES-256 key (240 bytes)
  let expandedKey := LeanTLS.Crypto.AES.keyExpansion256 key

  -- H = AES_K(0^128)
  let h := LeanTLS.Crypto.AES.encryptBlock256 expandedKey (zeroBlock 16)

  -- J0 = IV || 0x00000001 (for 96-bit IV)
  let mut j0 := ByteArray.mkEmpty 16
  for i in [:12] do
    -- Safe: iv is 12 bytes; i ranges over [0, 12)
    j0 := j0.push (iv.get! i)
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x01

  -- Tag_pre = AES_K(J0)
  let tagPre := LeanTLS.Crypto.AES.encryptBlock256 expandedKey j0

  -- Verify authentication tag
  let s := LeanTLS.Crypto.GCM.ghash h aad ciphertext
  let computedTag := xorBytes s tagPre

  -- Constant-time tag comparison via XOR accumulation (no early exit)
  let tagOk := LeanTLS.Utils.constantTimeEq computedTag tag

  if !tagOk then
    return none

  -- Counter mode decryption (same as encryption since XOR is symmetric)
  let mut counter := j0
  let mut plaintext := ByteArray.mkEmpty ciphertext.size
  let fullBlocks := ciphertext.size / 16
  let remainder := ciphertext.size % 16

  for i in [:fullBlocks] do
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock256 expandedKey counter
    let off := i * 16
    for j in [:16] do
      -- Safe: off + j < fullBlocks*16 <= ciphertext.size; keystream is 16 bytes
      plaintext := plaintext.push (ciphertext.get! (off + j) ^^^ keystream.get! j)

  if remainder > 0 then
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock256 expandedKey counter
    let off := fullBlocks * 16
    for j in [:remainder] do
      -- Safe: off + j < ciphertext.size; j < remainder <= 15 < keystream.size
      plaintext := plaintext.push (ciphertext.get! (off + j) ^^^ keystream.get! j)

  return some plaintext

/-! ## Test Vectors (NIST SP 800-38D) -/

/-- Run a single GCM-256 encrypt test case. Returns true if passed. -/
private def testEncrypt (name : String) (keyHex : String) (ivHex : String)
    (ptHex : String) (aadHex : String)
    (expectedCtHex : String) (expectedTagHex : String) : IO Bool := do
  let key := LeanTLS.Utils.hexToBytes keyHex
  let iv := LeanTLS.Utils.hexToBytes ivHex
  let pt := LeanTLS.Utils.hexToBytes ptHex
  let aad := LeanTLS.Utils.hexToBytes aadHex
  let (ct, tag) := encrypt key iv pt aad
  let ctHex := LeanTLS.Utils.bytesToHex ct
  let tagHex := LeanTLS.Utils.bytesToHex tag
  let ctOk := ctHex == expectedCtHex
  let tagOk := tagHex == expectedTagHex
  if ctOk && tagOk then
    IO.println s!"[PASS] GCM-256 Encrypt {name}"
    return true
  else
    if !ctOk then
      IO.println s!"[FAIL] GCM-256 Encrypt {name}: ciphertext expected {expectedCtHex}, got {ctHex}"
    if !tagOk then
      IO.println s!"[FAIL] GCM-256 Encrypt {name}: tag expected {expectedTagHex}, got {tagHex}"
    return false

/-- Run a single GCM-256 decrypt test case. Returns true if passed. -/
private def testDecrypt (name : String) (keyHex : String) (ivHex : String)
    (ctHex : String) (aadHex : String) (tagHex : String)
    (expectedPtHex : String) : IO Bool := do
  let key := LeanTLS.Utils.hexToBytes keyHex
  let iv := LeanTLS.Utils.hexToBytes ivHex
  let ct := LeanTLS.Utils.hexToBytes ctHex
  let aad := LeanTLS.Utils.hexToBytes aadHex
  let tag := LeanTLS.Utils.hexToBytes tagHex
  match decrypt key iv ct aad tag with
  | some pt =>
    let ptResultHex := LeanTLS.Utils.bytesToHex pt
    if ptResultHex == expectedPtHex then
      IO.println s!"[PASS] GCM-256 Decrypt {name}"
      return true
    else
      IO.println s!"[FAIL] GCM-256 Decrypt {name}: expected {expectedPtHex}, got {ptResultHex}"
      return false
  | none =>
    IO.println s!"[FAIL] GCM-256 Decrypt {name}: tag verification failed (unexpected)"
    return false

/-- Run all AES-256-GCM test vectors. Returns true if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test Case 13 (NIST SP 800-38D): No plaintext, no AAD, 256-bit key
  -- Key = 0..0 (32 bytes), IV = 0..0 (12 bytes), PT = empty, AAD = empty
  let ok13e ← testEncrypt "Test Case 13"
    "0000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000"
    ""
    ""
    ""
    "530f8afbc74536b9a963b4f1c4cb738b"
  if !ok13e then allPassed := false

  let ok13d ← testDecrypt "Test Case 13"
    "0000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000"
    ""
    ""
    "530f8afbc74536b9a963b4f1c4cb738b"
    ""
  if !ok13d then allPassed := false

  -- Test Case 14 (NIST SP 800-38D): 16-byte plaintext, no AAD, 256-bit key
  -- Key = 0..0 (32 bytes), IV = 0..0 (12 bytes), PT = 0..0 (16 bytes), AAD = empty
  let ok14e ← testEncrypt "Test Case 14"
    "0000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000"
    "00000000000000000000000000000000"
    ""
    "cea7403d4d606b6e074ec5d3baf39d18"
    "d0d1c8a799996bf0265b98b5d48ab919"
  if !ok14e then allPassed := false

  let ok14d ← testDecrypt "Test Case 14"
    "0000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000"
    "cea7403d4d606b6e074ec5d3baf39d18"
    ""
    "d0d1c8a799996bf0265b98b5d48ab919"
    "00000000000000000000000000000000"
  if !ok14d then allPassed := false

  -- Test Case 15 (NIST SP 800-38D): Multi-block plaintext, no AAD, 256-bit key
  let ok15e ← testEncrypt "Test Case 15"
    "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b391aafd255"
    ""
    "522dc1f099567d07f47f37a32a84427d643a8cdcbfe5c0c97598a2bd2555d1aa8cb08e48590dbb3da7b08b1056828838c5f61e6393ba7a0abcc9f662898015ad"
    "b094dac5d93471bdec1a502270e3cc6c"
  if !ok15e then allPassed := false

  let ok15d ← testDecrypt "Test Case 15"
    "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "522dc1f099567d07f47f37a32a84427d643a8cdcbfe5c0c97598a2bd2555d1aa8cb08e48590dbb3da7b08b1056828838c5f61e6393ba7a0abcc9f662898015ad"
    ""
    "b094dac5d93471bdec1a502270e3cc6c"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b391aafd255"
  if !ok15d then allPassed := false

  -- Test Case 16 (NIST SP 800-38D): Multi-block plaintext with AAD, 256-bit key
  let ok16e ← testEncrypt "Test Case 16"
    "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"
    "feedfacedeadbeeffeedfacedeadbeefabaddad2"
    "522dc1f099567d07f47f37a32a84427d643a8cdcbfe5c0c97598a2bd2555d1aa8cb08e48590dbb3da7b08b1056828838c5f61e6393ba7a0abcc9f662"
    "76fc6ece0f4e1768cddf8853bb2d551b"
  if !ok16e then allPassed := false

  let ok16d ← testDecrypt "Test Case 16"
    "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "522dc1f099567d07f47f37a32a84427d643a8cdcbfe5c0c97598a2bd2555d1aa8cb08e48590dbb3da7b08b1056828838c5f61e6393ba7a0abcc9f662"
    "feedfacedeadbeeffeedfacedeadbeefabaddad2"
    "76fc6ece0f4e1768cddf8853bb2d551b"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"
  if !ok16d then allPassed := false

  -- Test: Decrypt with wrong tag should fail
  let badResult := decrypt
    (LeanTLS.Utils.hexToBytes "0000000000000000000000000000000000000000000000000000000000000000")
    (LeanTLS.Utils.hexToBytes "000000000000000000000000")
    (LeanTLS.Utils.hexToBytes "cea7403d4d606b6e074ec5d3baf39d18")
    ByteArray.empty
    (LeanTLS.Utils.hexToBytes "0000000000000000000000000000dead")  -- wrong tag
  match badResult with
  | none =>
    IO.println "[PASS] GCM-256 Decrypt rejects bad tag"
  | some _ =>
    IO.println "[FAIL] GCM-256 Decrypt accepted bad tag"
    allPassed := false

  if allPassed then
    IO.println "All AES-256-GCM tests passed!"
  else
    IO.println "Some AES-256-GCM tests FAILED!"

  return allPassed

end LeanTLS.Crypto.GCM256
