import LeanTLS.Crypto.AES
import LeanTLS.Utils

/-
  AES-128-GCM Authenticated Encryption (NIST SP 800-38D)

  Implements:
  - GF(2^128) multiplication for GHASH
  - GHASH universal hash function
  - AES-128-GCM encrypt and decrypt with 96-bit IV and 128-bit tag

  Depends on LeanTLS.Crypto.AES for the AES-128 block cipher.
-/

set_option autoImplicit false

namespace LeanTLS.Crypto.GCM

/-! ## Utility Functions -/

/-- XOR two ByteArrays of equal length. If lengths differ, XOR up to the shorter length. -/
private def xorBytes (a : ByteArray) (b : ByteArray) : ByteArray := Id.run do
  let len := min a.size b.size
  let mut result := ByteArray.emptyWithCapacity len
  for i in [:len] do
    -- Safe: i < len = min a.size b.size, so i < a.size and i < b.size
    result := result.push (a.get! i ^^^ b.get! i)
  return result

/-- Create a ByteArray of n zero bytes. -/
private def zeroBlock (n : Nat) : ByteArray :=
  Nat.fold (n := n) (init := ByteArray.emptyWithCapacity n) fun _ _ acc => acc.push 0

/-- Pad a ByteArray to a multiple of 16 bytes with zeros. -/
private def padTo16 (data : ByteArray) : ByteArray :=
  let rem := data.size % 16
  if rem == 0 then data
  else
    let padLen := 16 - rem
    let padding := zeroBlock padLen
    data ++ padding

/-- Encode a Nat as a 64-bit big-endian ByteArray. -/
private def natToBytes64BE (n : Nat) : ByteArray := Id.run do
  let mut result := ByteArray.emptyWithCapacity 8
  result := result.push ((n >>> 56) % 256).toUInt8
  result := result.push ((n >>> 48) % 256).toUInt8
  result := result.push ((n >>> 40) % 256).toUInt8
  result := result.push ((n >>> 32) % 256).toUInt8
  result := result.push ((n >>> 24) % 256).toUInt8
  result := result.push ((n >>> 16) % 256).toUInt8
  result := result.push ((n >>> 8) % 256).toUInt8
  result := result.push (n % 256).toUInt8
  return result

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

/-! ## GF(2^128) Multiplication

  The irreducible polynomial is x^128 + x^7 + x^2 + x + 1.
  In the GCM bit-reflection convention, R = 0xe1000000...000 (128 bits).

  We represent 128-bit values as 16-byte ByteArrays where byte 0 is the most
  significant byte.

  The "schoolbook" algorithm processes X bit by bit from MSB to LSB:
    Z = 0
    V = Y
    for i = 0 to 127:
      if bit i of X is set:
        Z = Z XOR V
      if LSB of V is 0:
        V = V >> 1
      else:
        V = (V >> 1) XOR R
    return Z
-/

/-- The reduction polynomial R = 0xe1000000...000 as a 16-byte block. -/
private def ghashR : ByteArray :=
  let r := zeroBlock 16
  r.set! 0 0xe1

/-- Get the i-th bit (0-indexed from MSB of byte 0) of a 16-byte block.
    Bit 0 is the MSB of byte 0, bit 7 is the LSB of byte 0,
    bit 8 is the MSB of byte 1, etc. -/
private def getBit (block : ByteArray) (i : Nat) : Bool :=
  let byteIdx := i / 8
  let bitIdx := 7 - (i % 8)
  if byteIdx < block.size then
    -- Safe: byteIdx < block.size is checked by the guard above
    (block.get! byteIdx >>> bitIdx.toUInt8) &&& 1 == 1
  else
    false

/-- Shift a 16-byte block right by 1 bit. -/
private def shiftRight1 (block : ByteArray) : ByteArray := Id.run do
  let mut result := ByteArray.emptyWithCapacity 16
  let mut carry : UInt8 := 0
  for i in [:16] do
    -- Safe: block is always 16 bytes; i ranges over [0, 16)
    let b := block.get! i
    let newByte := (b >>> 1) ||| (carry <<< 7)
    carry := b &&& 1
    result := result.push newByte
  return result

/-- Multiply two 128-bit blocks (16-byte ByteArrays) in GF(2^128). -/
def gfMul (x : ByteArray) (y : ByteArray) : ByteArray := Id.run do
  let mut z := zeroBlock 16
  let mut v := y
  for i in [:128] do
    if getBit x i then
      z := xorBytes z v
    -- Safe: v is always 16 bytes; index 15 is the last byte
    let lsb := v.get! 15 &&& 1
    v := shiftRight1 v
    if lsb == 1 then
      v := xorBytes v ghashR
  return z

/-! ## GHASH Function

  GHASH(H, A, C):
    Y = 0^128
    For each 16-byte block a_i of A (zero-padded at end):
      Y = (Y XOR a_i) * H
    For each 16-byte block c_i of C (zero-padded at end):
      Y = (Y XOR c_i) * H
    len_block = [len(A) in bits as 64-bit BE] || [len(C) in bits as 64-bit BE]
    Y = (Y XOR len_block) * H
    return Y
-/

/-- Process data in 16-byte blocks, applying GHASH updates.
    data should already be padded to a multiple of 16. -/
private def ghashProcessBlocks (h : ByteArray) (y : ByteArray) (data : ByteArray) : ByteArray := Id.run do
  let numBlocks := data.size / 16
  let mut yi := y
  for i in [:numBlocks] do
    let off := i * 16
    let block := data.extract off (off + 16)
    yi := gfMul (xorBytes yi block) h
  return yi

/-- Compute GHASH(H, aad, ciphertext). -/
def ghash (h : ByteArray) (aad : ByteArray) (ciphertext : ByteArray) : ByteArray := Id.run do
  let mut y := zeroBlock 16

  -- Process AAD blocks
  let paddedAad := padTo16 aad
  if paddedAad.size > 0 then
    y := ghashProcessBlocks h y paddedAad

  -- Process ciphertext blocks
  let paddedCt := padTo16 ciphertext
  if paddedCt.size > 0 then
    y := ghashProcessBlocks h y paddedCt

  -- Length block: [len(A) in bits as 64-bit BE] || [len(C) in bits as 64-bit BE]
  let lenBlock := natToBytes64BE (aad.size * 8) ++ natToBytes64BE (ciphertext.size * 8)
  y := gfMul (xorBytes y lenBlock) h

  return y

/-! ## AES-128-GCM Encryption and Decryption -/

/-- AES-128-GCM encrypt.
    - key: 16-byte AES-128 key
    - iv: 12-byte initialization vector (nonce)
    - plaintext: arbitrary-length plaintext
    - aad: additional authenticated data
    Returns (ciphertext, tag) where tag is 16 bytes. -/
def encrypt (key : ByteArray) (iv : ByteArray) (plaintext : ByteArray) (aad : ByteArray) : ByteArray × ByteArray := Id.run do
  -- H = AES_K(0^128)
  let h := LeanTLS.Crypto.AES.encryptBlock key (zeroBlock 16)

  -- J0 = IV || 0x00000001 (for 96-bit IV)
  let mut j0 := ByteArray.emptyWithCapacity 16
  for i in [:12] do
    -- Safe: iv is 12 bytes; i ranges over [0, 12)
    j0 := j0.push (iv.get! i)
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x01

  -- Tag_pre = AES_K(J0)
  let tagPre := LeanTLS.Crypto.AES.encryptBlock key j0

  -- Counter mode encryption
  let mut counter := j0
  let mut ciphertext := ByteArray.emptyWithCapacity plaintext.size
  let fullBlocks := plaintext.size / 16
  let remainder := plaintext.size % 16

  -- Process full 16-byte blocks
  for i in [:fullBlocks] do
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock key counter
    let off := i * 16
    for j in [:16] do
      -- Safe: off + j < fullBlocks*16 <= plaintext.size; keystream is 16 bytes
      ciphertext := ciphertext.push (plaintext.get! (off + j) ^^^ keystream.get! j)

  -- Process remaining bytes (partial block)
  if remainder > 0 then
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock key counter
    let off := fullBlocks * 16
    for j in [:remainder] do
      -- Safe: off + j < plaintext.size; j < remainder <= 15 < keystream.size
      ciphertext := ciphertext.push (plaintext.get! (off + j) ^^^ keystream.get! j)

  -- Compute authentication tag
  let s := ghash h aad ciphertext
  let tag := xorBytes s tagPre

  return (ciphertext, tag)

/-- AES-128-GCM decrypt.
    - key: 16-byte AES-128 key
    - iv: 12-byte initialization vector (nonce)
    - ciphertext: ciphertext to decrypt
    - aad: additional authenticated data
    - tag: 16-byte authentication tag
    Returns `some plaintext` if tag verifies, `none` otherwise. -/
def decrypt (key : ByteArray) (iv : ByteArray) (ciphertext : ByteArray) (aad : ByteArray) (tag : ByteArray) : Option ByteArray := Id.run do
  -- H = AES_K(0^128)
  let h := LeanTLS.Crypto.AES.encryptBlock key (zeroBlock 16)

  -- J0 = IV || 0x00000001 (for 96-bit IV)
  let mut j0 := ByteArray.emptyWithCapacity 16
  for i in [:12] do
    -- Safe: iv is 12 bytes; i ranges over [0, 12)
    j0 := j0.push (iv.get! i)
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x00
  j0 := j0.push 0x01

  -- Tag_pre = AES_K(J0)
  let tagPre := LeanTLS.Crypto.AES.encryptBlock key j0

  -- Verify authentication tag
  let s := ghash h aad ciphertext
  let computedTag := xorBytes s tagPre

  -- Constant-time tag comparison via XOR accumulation (no early exit)
  let tagOk := LeanTLS.Utils.constantTimeEq computedTag tag

  if !tagOk then
    return none

  -- Counter mode decryption (same as encryption since XOR is symmetric)
  let mut counter := j0
  let mut plaintext := ByteArray.emptyWithCapacity ciphertext.size
  let fullBlocks := ciphertext.size / 16
  let remainder := ciphertext.size % 16

  for i in [:fullBlocks] do
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock key counter
    let off := i * 16
    for j in [:16] do
      -- Safe: off + j < fullBlocks*16 <= ciphertext.size; keystream is 16 bytes
      plaintext := plaintext.push (ciphertext.get! (off + j) ^^^ keystream.get! j)

  if remainder > 0 then
    counter := incrCounter counter
    let keystream := LeanTLS.Crypto.AES.encryptBlock key counter
    let off := fullBlocks * 16
    for j in [:remainder] do
      -- Safe: off + j < ciphertext.size; j < remainder <= 15 < keystream.size
      plaintext := plaintext.push (ciphertext.get! (off + j) ^^^ keystream.get! j)

  return some plaintext

/-! ## Test Vectors (NIST SP 800-38D) -/

/-- Run a single GCM encrypt test case. Returns true if passed. -/
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
    IO.println s!"[PASS] GCM Encrypt {name}"
    return true
  else
    if !ctOk then
      IO.println s!"[FAIL] GCM Encrypt {name}: ciphertext expected {expectedCtHex}, got {ctHex}"
    if !tagOk then
      IO.println s!"[FAIL] GCM Encrypt {name}: tag expected {expectedTagHex}, got {tagHex}"
    return false

/-- Run a single GCM decrypt test case. Returns true if passed. -/
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
      IO.println s!"[PASS] GCM Decrypt {name}"
      return true
    else
      IO.println s!"[FAIL] GCM Decrypt {name}: expected {expectedPtHex}, got {ptResultHex}"
      return false
  | none =>
    IO.println s!"[FAIL] GCM Decrypt {name}: tag verification failed (unexpected)"
    return false

/-- Run all GCM test vectors. Returns true if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- Test Case 1: No plaintext, no AAD
  let ok1e ← testEncrypt "Test Case 1"
    "00000000000000000000000000000000"
    "000000000000000000000000"
    ""
    ""
    ""
    "58e2fccefa7e3061367f1d57a4e7455a"
  if !ok1e then allPassed := false

  let ok1d ← testDecrypt "Test Case 1"
    "00000000000000000000000000000000"
    "000000000000000000000000"
    ""
    ""
    "58e2fccefa7e3061367f1d57a4e7455a"
    ""
  if !ok1d then allPassed := false

  -- Test Case 2: 16-byte plaintext, no AAD
  let ok2e ← testEncrypt "Test Case 2"
    "00000000000000000000000000000000"
    "000000000000000000000000"
    "00000000000000000000000000000000"
    ""
    "0388dace60b6a392f328c2b971b2fe78"
    "ab6e47d42cec13bdf53a67b21257bddf"
  if !ok2e then allPassed := false

  let ok2d ← testDecrypt "Test Case 2"
    "00000000000000000000000000000000"
    "000000000000000000000000"
    "0388dace60b6a392f328c2b971b2fe78"
    ""
    "ab6e47d42cec13bdf53a67b21257bddf"
    "00000000000000000000000000000000"
  if !ok2d then allPassed := false

  -- Test Case 3: Multi-block plaintext, no AAD
  let ok3e ← testEncrypt "Test Case 3"
    "feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b391aafd255"
    ""
    "42831ec2217774244b7221b784d0d49ce3aa212f2c02a4e035c17e2329aca12e21d514b25466931c7d8f6a5aac84aa051ba30b396a0aac973d58e091473f5985"
    "4d5c2af327cd64a62cf35abd2ba6fab4"
  if !ok3e then allPassed := false

  let ok3d ← testDecrypt "Test Case 3"
    "feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "42831ec2217774244b7221b784d0d49ce3aa212f2c02a4e035c17e2329aca12e21d514b25466931c7d8f6a5aac84aa051ba30b396a0aac973d58e091473f5985"
    ""
    "4d5c2af327cd64a62cf35abd2ba6fab4"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b391aafd255"
  if !ok3d then allPassed := false

  -- Test Case 4: Multi-block plaintext with AAD
  let ok4e ← testEncrypt "Test Case 4"
    "feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"
    "feedfacedeadbeeffeedfacedeadbeefabaddad2"
    "42831ec2217774244b7221b784d0d49ce3aa212f2c02a4e035c17e2329aca12e21d514b25466931c7d8f6a5aac84aa051ba30b396a0aac973d58e091"
    "5bc94fbc3221a5db94fae95ae7121a47"
  if !ok4e then allPassed := false

  let ok4d ← testDecrypt "Test Case 4"
    "feffe9928665731c6d6a8f9467308308"
    "cafebabefacedbaddecaf888"
    "42831ec2217774244b7221b784d0d49ce3aa212f2c02a4e035c17e2329aca12e21d514b25466931c7d8f6a5aac84aa051ba30b396a0aac973d58e091"
    "feedfacedeadbeeffeedfacedeadbeefabaddad2"
    "5bc94fbc3221a5db94fae95ae7121a47"
    "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"
  if !ok4d then allPassed := false

  -- Test: Decrypt with wrong tag should fail
  let badResult := decrypt
    (LeanTLS.Utils.hexToBytes "00000000000000000000000000000000")
    (LeanTLS.Utils.hexToBytes "000000000000000000000000")
    (LeanTLS.Utils.hexToBytes "0388dace60b6a392f328c2b971b2fe78")
    ByteArray.empty
    (LeanTLS.Utils.hexToBytes "0000000000000000000000000000dead")  -- wrong tag
  match badResult with
  | none =>
    IO.println "[PASS] GCM Decrypt rejects bad tag"
  | some _ =>
    IO.println "[FAIL] GCM Decrypt accepted bad tag"
    allPassed := false

  if allPassed then
    IO.println "All AES-128-GCM tests passed!"
  else
    IO.println "Some AES-128-GCM tests FAILED!"

  return allPassed

end LeanTLS.Crypto.GCM
