import LeanTLS.Crypto.GCM
import LeanTLS.Crypto.GCM256
import LeanTLS.Errors
import LeanTLS.Utils

/-
  TLS 1.3 Record Layer (RFC 8446 Section 5)

  Implements:
  - Content types (Section 5.1)
  - TLS record encoding/decoding (plain records)
  - Encrypted record construction and decryption (Section 5.2)
  - Per-record nonce construction (Section 5.3)
  - AES-128-GCM authenticated encryption via LeanTLS.Crypto.GCM
-/

set_option autoImplicit false

namespace LeanTLS.Record

/-! ## Content Types (RFC 8446 Section 5.1) -/

/-- TLS record content types as defined in RFC 8446 Section 5.1. -/
inductive ContentType where
  | changeCipherSpec : ContentType  -- 20
  | alert : ContentType             -- 21
  | handshake : ContentType         -- 22
  | applicationData : ContentType   -- 23
  deriving BEq, Repr

/-- Convert a ContentType to its wire format byte value. -/
def ContentType.toByte (ct : ContentType) : UInt8 :=
  match ct with
  | .changeCipherSpec => 20
  | .alert            => 21
  | .handshake        => 22
  | .applicationData  => 23

/-- Parse a byte into a ContentType, returning none for unknown values. -/
def ContentType.fromByte (b : UInt8) : Option ContentType :=
  match b with
  | 20 => some .changeCipherSpec
  | 21 => some .alert
  | 22 => some .handshake
  | 23 => some .applicationData
  | _  => none

/-! ## TLS Record Structure -/

/-- A TLS record as it appears on the wire (RFC 8446 Section 5.1).
    The legacyVersion field is always 0x0303 (TLS 1.2) for TLS 1.3 records. -/
structure TLSRecord where
  contentType : ContentType
  /-- Legacy version: always 0x0303 (TLS 1.2) for TLS 1.3 -/
  legacyVersion : UInt16 := 0x0303
  fragment : ByteArray

/-- Maximum TLS plaintext record fragment length: 2^14 = 16384 bytes (RFC 8446 Section 5.1). -/
def maxFragmentLength : Nat := 16384

/-- Maximum TLS encrypted record fragment length: 2^14 + 256 bytes
    (accounts for inner content type + AEAD tag + padding, RFC 8446 Section 5.2). -/
def maxEncryptedFragmentLength : Nat := 16384 + 256

/-! ## Plain Record Encoding/Decoding -/

/-- Encode a TLSRecord to wire format (5-byte header + fragment).
    Wire format:
    - 1 byte: content type
    - 2 bytes: legacy version (big-endian)
    - 2 bytes: fragment length (big-endian)
    - N bytes: fragment -/
def TLSRecord.encode (rec : TLSRecord) : ByteArray := Id.run do
  let len := rec.fragment.size
  let mut result := ByteArray.emptyWithCapacity (5 + len)
  -- Content type (1 byte)
  result := result.push rec.contentType.toByte
  -- Legacy version (2 bytes, big-endian)
  result := result.push (rec.legacyVersion >>> 8).toUInt8
  result := result.push (rec.legacyVersion &&& 0xFF).toUInt8
  -- Fragment length (2 bytes, big-endian)
  result := result.push (len / 256).toUInt8
  result := result.push (len % 256).toUInt8
  -- Fragment
  result := result ++ rec.fragment
  return result

/-- Decode a TLSRecord from wire format.
    Returns (record, remainingBytes) or none on error.
    Fails if:
    - Not enough bytes for the 5-byte header
    - Unknown content type byte
    - Not enough bytes for the declared fragment length -/
def TLSRecord.decode (data : ByteArray) : Option (TLSRecord × ByteArray) := do
  -- Need at least 5 bytes for the header
  if data.size < 5 then
    none
  else
    -- Parse content type
    -- Safety: data.size >= 5 is checked above, so indices 0..4 are in bounds
    let ctByte := data.get! 0
    let ct ← ContentType.fromByte ctByte
    -- Parse legacy version (big-endian)
    let verHi := data.get! 1
    let verLo := data.get! 2
    let version : UInt16 := (verHi.toUInt16 <<< 8) ||| verLo.toUInt16
    -- Parse fragment length (big-endian)
    let lenHi := data.get! 3
    let lenLo := data.get! 4
    let fragLen : Nat := lenHi.toNat * 256 + lenLo.toNat
    -- Validate fragment length per RFC 8446:
    -- Encrypted records (applicationData) may be up to 2^14 + 256 bytes.
    -- Plaintext records must be at most 2^14 bytes.
    let maxLen := if ct == .applicationData then maxEncryptedFragmentLength else maxFragmentLength
    if fragLen > maxLen then
      none
    else if data.size < 5 + fragLen then
      -- Check we have enough data for the fragment
      none
    else
      let fragment := data.extract 5 (5 + fragLen)
      let remaining := data.extract (5 + fragLen) data.size
      let record : TLSRecord := {
        contentType := ct
        legacyVersion := version
        fragment := fragment
      }
      some (record, remaining)

/-! ## Encrypted Record Handling (RFC 8446 Section 5.2) -/

/-- State for encrypting/decrypting TLS 1.3 records.
    Tracks the symmetric key, implicit IV, and per-direction sequence number. -/
structure RecordEncryptionState where
  key : ByteArray      -- 16-byte AES key
  iv : ByteArray       -- 12-byte implicit IV
  seqNum : UInt64      -- sequence number (starts at 0, increments per record)

/-! ## Nonce Construction (RFC 8446 Section 5.3)

  The per-record nonce is computed by:
  1. Pad the 64-bit sequence number to 12 bytes (big-endian, left-padded with zeros)
  2. XOR the padded sequence number with the 12-byte IV
-/

/-- Build the per-record nonce from the IV and sequence number.
    nonce = iv XOR (seqNum padded to 12 bytes, big-endian).
    The sequence number is placed in the rightmost 8 bytes; the leftmost 4 bytes
    of the padding are zero. -/
def buildNonce (iv : ByteArray) (seqNum : UInt64) : ByteArray := Id.run do
  -- Guard: IV must be exactly 12 bytes
  if iv.size != 12 then
    -- Return zero nonce as fallback (should never happen with correct key material)
    return ByteArray.mk (Array.replicate 12 0)
  -- Build a 12-byte padded sequence number (4 zero bytes + 8 bytes big-endian)
  let mut paddedSeq := ByteArray.emptyWithCapacity 12
  -- 4 bytes of zero padding
  for _ in [:4] do
    paddedSeq := paddedSeq.push 0
  -- 8 bytes of sequence number in big-endian
  paddedSeq := paddedSeq.push (seqNum >>> 56).toUInt8
  paddedSeq := paddedSeq.push (seqNum >>> 48).toUInt8
  paddedSeq := paddedSeq.push (seqNum >>> 40).toUInt8
  paddedSeq := paddedSeq.push (seqNum >>> 32).toUInt8
  paddedSeq := paddedSeq.push (seqNum >>> 24).toUInt8
  paddedSeq := paddedSeq.push (seqNum >>> 16).toUInt8
  paddedSeq := paddedSeq.push (seqNum >>> 8).toUInt8
  paddedSeq := paddedSeq.push seqNum.toUInt8
  -- XOR with IV
  -- Safety: both iv and paddedSeq are exactly 12 bytes, so indices 0..11 are in bounds
  let mut nonce := ByteArray.emptyWithCapacity 12
  for i in [:12] do
    nonce := nonce.push (iv.get! i ^^^ paddedSeq.get! i)
  return nonce

/-- Build the 5-byte record header for an encrypted TLS 1.3 record.
    The outer content type is always applicationData (23), the version is 0x0303,
    and the length is the ciphertext + tag length. -/
private def buildEncryptedRecordHeader (encryptedLen : Nat) : ByteArray := Id.run do
  let mut header := ByteArray.emptyWithCapacity 5
  -- Content type: applicationData (23)
  header := header.push ContentType.applicationData.toByte
  -- Legacy version: 0x0303
  header := header.push 0x03
  header := header.push 0x03
  -- Length (big-endian)
  header := header.push (encryptedLen / 256).toUInt8
  header := header.push (encryptedLen % 256).toUInt8
  return header

/-- Encrypt a TLS inner plaintext into an encrypted record (RFC 8446 Section 5.2).

    The inner plaintext is constructed as: content ++ [contentType byte].
    (No zero padding is added in this implementation.)

    The encryption uses AES-128-GCM with:
    - nonce = buildNonce(state.iv, state.seqNum)
    - AAD = 5-byte record header (type=23, version=0x0303, length)

    Returns the encrypted TLSRecord (outer type = applicationData) and updated state
    with incremented sequence number. -/
def encryptRecord (state : RecordEncryptionState) (contentType : ContentType) (content : ByteArray)
    : Option (TLSRecord × RecordEncryptionState) := do
  -- Sequence number overflow protection: must not wrap around
  if state.seqNum == (18446744073709551615 : UInt64) then
    none
  -- Build inner plaintext: content ++ content type byte
  let innerPlaintext := content.push contentType.toByte
  -- Compute per-record nonce
  let nonce := buildNonce state.iv state.seqNum
  -- The encrypted payload will be: ciphertext (same length as inner plaintext) + 16-byte tag
  let encryptedLen := innerPlaintext.size + 16
  -- Build the 5-byte AAD (record header with the encrypted length)
  let aad := buildEncryptedRecordHeader encryptedLen
  -- Encrypt with AES-128-GCM
  let (ciphertext, tag) := LeanTLS.Crypto.GCM.encrypt state.key nonce innerPlaintext aad
  -- The fragment is ciphertext ++ tag
  let fragment := ciphertext ++ tag
  -- Build the outer record
  let record : TLSRecord := {
    contentType := .applicationData
    legacyVersion := 0x0303
    fragment := fragment
  }
  -- Increment sequence number
  let newState : RecordEncryptionState := {
    key := state.key
    iv := state.iv
    seqNum := state.seqNum + 1
  }
  some (record, newState)

/-- Remove trailing zero padding from inner plaintext and extract the real content type.
    The inner plaintext format is: content ++ [contentType] ++ zero_padding.
    We scan from the end, skip zeros, and the first non-zero byte is the content type. -/
private def parseInnerPlaintext (innerPlaintext : ByteArray) : Option (ContentType × ByteArray) := do
  if innerPlaintext.size == 0 then
    none
  else
    -- Find the last non-zero byte (this is the content type)
    -- Walk backward past any zero padding
    -- Safety: pos ranges from innerPlaintext.size-1 down to 0, all in bounds since size > 0
    let mut found := false
    let mut ctIdx := 0
    for i in [:innerPlaintext.size] do
      let pos := innerPlaintext.size - 1 - i
      if !found && innerPlaintext.get! pos != 0 then
        found := true
        ctIdx := pos
    if !found then
      none
    else
      -- Safety: ctIdx was set from a valid pos in the loop above
      let ctByte := innerPlaintext.get! ctIdx
      let ct ← ContentType.fromByte ctByte
      let content := innerPlaintext.extract 0 ctIdx
      some (ct, content)

/-- Decrypt an encrypted TLS record (RFC 8446 Section 5.2).

    Expects the record to have outer content type applicationData.
    The fragment contains: ciphertext ++ 16-byte authentication tag.

    Uses AES-128-GCM with:
    - nonce = buildNonce(state.iv, state.seqNum)
    - AAD = 5-byte record header (reconstructed from the record)

    On success, returns (innerContentType, plainContent, updatedState).
    On failure (wrong outer type, too-short fragment, decryption failure, invalid
    inner content type), returns none. -/
def decryptRecord (state : RecordEncryptionState) (rec : TLSRecord)
    : Option (ContentType × ByteArray × RecordEncryptionState) := do
  -- Sequence number overflow protection: must not wrap around
  if state.seqNum == (18446744073709551615 : UInt64) then
    none
  -- Outer content type must be applicationData
  else if rec.contentType != .applicationData then
    none
  else
    -- Fragment must be at least 17 bytes (1 byte inner content type + 16 byte tag)
    if rec.fragment.size < 17 then
      none
    else
      -- Split fragment into ciphertext and tag
      let ciphertextLen := rec.fragment.size - 16
      let ciphertext := rec.fragment.extract 0 ciphertextLen
      let tag := rec.fragment.extract ciphertextLen rec.fragment.size
      -- Compute per-record nonce
      let nonce := buildNonce state.iv state.seqNum
      -- Build the AAD: the 5-byte record header
      let aad := buildEncryptedRecordHeader rec.fragment.size
      -- Decrypt with AES-128-GCM
      let innerPlaintext ← LeanTLS.Crypto.GCM.decrypt state.key nonce ciphertext aad tag
      -- Parse inner plaintext to extract content type and content
      let (ct, content) ← parseInnerPlaintext innerPlaintext
      -- Increment sequence number
      let newState : RecordEncryptionState := {
        key := state.key
        iv := state.iv
        seqNum := state.seqNum + 1
      }
      some (ct, content, newState)

/-! ## AES-256-GCM Encrypted Record Handling -/

/-- Encrypt a TLS inner plaintext into an encrypted record using AES-256-GCM.
    Same as `encryptRecord` but uses AES-256-GCM (32-byte key). -/
def encryptRecord256 (state : RecordEncryptionState) (contentType : ContentType) (content : ByteArray)
    : Option (TLSRecord × RecordEncryptionState) := do
  if state.seqNum == (18446744073709551615 : UInt64) then
    none
  let innerPlaintext := content.push contentType.toByte
  let nonce := buildNonce state.iv state.seqNum
  let encryptedLen := innerPlaintext.size + 16
  let aad := buildEncryptedRecordHeader encryptedLen
  let (ciphertext, tag) := LeanTLS.Crypto.GCM256.encrypt state.key nonce innerPlaintext aad
  let fragment := ciphertext ++ tag
  let record : TLSRecord := {
    contentType := .applicationData
    legacyVersion := 0x0303
    fragment := fragment
  }
  let newState : RecordEncryptionState := {
    key := state.key
    iv := state.iv
    seqNum := state.seqNum + 1
  }
  some (record, newState)

/-- Decrypt an encrypted TLS record using AES-256-GCM.
    Same as `decryptRecord` but uses AES-256-GCM (32-byte key). -/
def decryptRecord256 (state : RecordEncryptionState) (rec : TLSRecord)
    : Option (ContentType × ByteArray × RecordEncryptionState) := do
  if state.seqNum == (18446744073709551615 : UInt64) then
    none
  else if rec.contentType != .applicationData then
    none
  else
    if rec.fragment.size < 17 then
      none
    else
      let ciphertextLen := rec.fragment.size - 16
      let ciphertext := rec.fragment.extract 0 ciphertextLen
      let tag := rec.fragment.extract ciphertextLen rec.fragment.size
      let nonce := buildNonce state.iv state.seqNum
      let aad := buildEncryptedRecordHeader rec.fragment.size
      let innerPlaintext ← LeanTLS.Crypto.GCM256.decrypt state.key nonce ciphertext aad tag
      let (ct, content) ← parseInnerPlaintext innerPlaintext
      let newState : RecordEncryptionState := {
        key := state.key
        iv := state.iv
        seqNum := state.seqNum + 1
      }
      some (ct, content, newState)

/-- Encrypt a TLS record, auto-dispatching between AES-128-GCM and AES-256-GCM
    based on the key size (16 bytes = AES-128, 32 bytes = AES-256). -/
def encryptRecordAuto (state : RecordEncryptionState) (contentType : ContentType) (content : ByteArray)
    : Option (TLSRecord × RecordEncryptionState) :=
  if state.key.size == 32 then
    encryptRecord256 state contentType content
  else
    encryptRecord state contentType content

/-- Decrypt a TLS record, auto-dispatching between AES-128-GCM and AES-256-GCM
    based on the key size (16 bytes = AES-128, 32 bytes = AES-256). -/
def decryptRecordAuto (state : RecordEncryptionState) (rec : TLSRecord)
    : Option (ContentType × ByteArray × RecordEncryptionState) :=
  if state.key.size == 32 then
    decryptRecord256 state rec
  else
    decryptRecord state rec

/-! ## Tests -/


/-- Run all Record Layer tests. Returns true if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- ===== Test 1: Record encode/decode roundtrip =====
  IO.println "--- Record Encode/Decode Tests ---"

  let handshakeData := ByteArray.mk #[0x01, 0x00, 0x00, 0x05, 0x03, 0x03, 0x01, 0x02, 0x03]
  let originalRec : TLSRecord := {
    contentType := .handshake
    legacyVersion := 0x0303
    fragment := handshakeData
  }
  let encoded := originalRec.encode
  -- Check the encoded size: 5 header bytes + 9 fragment bytes = 14
  if encoded.size != 14 then
    IO.println s!"[FAIL] Record encode: expected size 14, got {encoded.size}"
    allPassed := false
  else
    IO.println "[PASS] Record encode: correct size"

  -- Check header bytes
  let headerOk :=
    encoded.get! 0 == 22 &&         -- handshake content type
    encoded.get! 1 == 0x03 &&       -- version high byte
    encoded.get! 2 == 0x03 &&       -- version low byte
    encoded.get! 3 == 0x00 &&       -- length high byte
    encoded.get! 4 == 0x09          -- length low byte (9 bytes)
  if !headerOk then
    IO.println "[FAIL] Record encode: header bytes incorrect"
    allPassed := false
  else
    IO.println "[PASS] Record encode: correct header bytes"

  -- Decode and verify roundtrip
  match TLSRecord.decode encoded with
  | none =>
    IO.println "[FAIL] Record decode: returned none"
    allPassed := false
  | some (decoded, remaining) =>
    if decoded.contentType != .handshake then
      IO.println "[FAIL] Record decode: wrong content type"
      allPassed := false
    else if decoded.legacyVersion != 0x0303 then
      IO.println "[FAIL] Record decode: wrong legacy version"
      allPassed := false
    else if !LeanTLS.Utils.byteArrayBEq decoded.fragment handshakeData then
      IO.println "[FAIL] Record decode: fragment mismatch"
      allPassed := false
    else if remaining.size != 0 then
      IO.println "[FAIL] Record decode: unexpected remaining bytes"
      allPassed := false
    else
      IO.println "[PASS] Record encode/decode roundtrip"

  -- Test decode with extra trailing bytes
  let extraData := encoded ++ ByteArray.mk #[0xFF, 0xFE]
  match TLSRecord.decode extraData with
  | none =>
    IO.println "[FAIL] Record decode with trailing data: returned none"
    allPassed := false
  | some (_, remaining2) =>
    if remaining2.size != 2 then
      IO.println s!"[FAIL] Record decode with trailing data: expected 2 remaining bytes, got {remaining2.size}"
      allPassed := false
    else
      IO.println "[PASS] Record decode preserves trailing data"

  -- Test decode with insufficient data
  let shortData := ByteArray.mk #[22, 0x03, 0x03]
  match TLSRecord.decode shortData with
  | none =>
    IO.println "[PASS] Record decode rejects too-short data"
  | some _ =>
    IO.println "[FAIL] Record decode accepted too-short data"
    allPassed := false

  -- ===== Test 2: Nonce construction =====
  IO.println ""
  IO.println "--- Nonce Construction Tests ---"

  -- Test 2a: IV = 000000000000000000000001, seqNum = 0
  let iv1 := LeanTLS.Utils.hexToBytes "000000000000000000000001"
  let nonce1 := buildNonce iv1 0
  let expected1 := LeanTLS.Utils.hexToBytes "000000000000000000000001"
  if LeanTLS.Utils.byteArrayBEq nonce1 expected1 then
    IO.println "[PASS] Nonce: IV=...0001, seq=0 -> ...0001"
  else
    IO.println s!"[FAIL] Nonce: IV=...0001, seq=0: expected {LeanTLS.Utils.bytesToHex expected1}, got {LeanTLS.Utils.bytesToHex nonce1}"
    allPassed := false

  -- Test 2b: IV = 000000000000000000000001, seqNum = 1
  let nonce2 := buildNonce iv1 1
  let expected2 := LeanTLS.Utils.hexToBytes "000000000000000000000000"
  if LeanTLS.Utils.byteArrayBEq nonce2 expected2 then
    IO.println "[PASS] Nonce: IV=...0001, seq=1 -> ...0000"
  else
    IO.println s!"[FAIL] Nonce: IV=...0001, seq=1: expected {LeanTLS.Utils.bytesToHex expected2}, got {LeanTLS.Utils.bytesToHex nonce2}"
    allPassed := false

  -- Test 2c: IV = e0e1e2e3e4e5e6e7e8e9eaeb, seqNum = 0
  let iv3 := LeanTLS.Utils.hexToBytes "e0e1e2e3e4e5e6e7e8e9eaeb"
  let nonce3 := buildNonce iv3 0
  let expected3 := LeanTLS.Utils.hexToBytes "e0e1e2e3e4e5e6e7e8e9eaeb"
  if LeanTLS.Utils.byteArrayBEq nonce3 expected3 then
    IO.println "[PASS] Nonce: IV=e0e1...eaeb, seq=0 -> e0e1...eaeb"
  else
    IO.println s!"[FAIL] Nonce: IV=e0e1...eaeb, seq=0: expected {LeanTLS.Utils.bytesToHex expected3}, got {LeanTLS.Utils.bytesToHex nonce3}"
    allPassed := false

  -- ===== Test 3: Encrypt/decrypt roundtrip =====
  IO.println ""
  IO.println "--- Encrypt/Decrypt Roundtrip Tests ---"

  -- Use a known key and IV
  let testKey := LeanTLS.Utils.hexToBytes "000102030405060708090a0b0c0d0e0f"
  let testIV := LeanTLS.Utils.hexToBytes "000000000000000000000001"

  let encState : RecordEncryptionState := {
    key := testKey
    iv := testIV
    seqNum := 0
  }

  -- Create a handshake message to encrypt
  let handshakeMsg := ByteArray.mk #[0x01, 0x00, 0x00, 0x05, 0x03, 0x03, 0x01, 0x02, 0x03]
  match encryptRecord encState .handshake handshakeMsg with
  | none =>
    IO.println "[FAIL] Encrypt: returned none"
    allPassed := false
  | some (encryptedRec, encState2) =>

    -- Verify the outer content type is applicationData
    if encryptedRec.contentType != .applicationData then
      IO.println "[FAIL] Encrypt: outer content type is not applicationData"
      allPassed := false
    else
      IO.println "[PASS] Encrypt: outer content type is applicationData"

    -- Verify sequence number incremented
    if encState2.seqNum != 1 then
      IO.println s!"[FAIL] Encrypt: sequence number should be 1, got {encState2.seqNum}"
      allPassed := false
    else
      IO.println "[PASS] Encrypt: sequence number incremented to 1"

    -- Verify fragment size: inner plaintext (9 + 1 content type) encrypted = 10 ciphertext + 16 tag = 26
    if encryptedRec.fragment.size != 26 then
      IO.println s!"[FAIL] Encrypt: expected fragment size 26, got {encryptedRec.fragment.size}"
      allPassed := false
    else
      IO.println "[PASS] Encrypt: correct fragment size"

    -- Now decrypt with matching state (seqNum = 0)
    let decState : RecordEncryptionState := {
      key := testKey
      iv := testIV
      seqNum := 0
    }

    match decryptRecord decState encryptedRec with
    | none =>
      IO.println "[FAIL] Decrypt: returned none"
      allPassed := false
    | some (decCt, decContent, decState2) =>
      if decCt != .handshake then
        IO.println "[FAIL] Decrypt: wrong content type"
        allPassed := false
      else if !LeanTLS.Utils.byteArrayBEq decContent handshakeMsg then
        IO.println s!"[FAIL] Decrypt: content mismatch, expected {LeanTLS.Utils.bytesToHex handshakeMsg}, got {LeanTLS.Utils.bytesToHex decContent}"
        allPassed := false
      else if decState2.seqNum != 1 then
        IO.println s!"[FAIL] Decrypt: sequence number should be 1, got {decState2.seqNum}"
        allPassed := false
      else
        IO.println "[PASS] Encrypt/decrypt roundtrip: content and type match"
        IO.println "[PASS] Decrypt: sequence number incremented to 1"

    -- Test encrypt/decrypt with a second record (seqNum = 1)
    let appMsg := ByteArray.mk #[0x48, 0x65, 0x6C, 0x6C, 0x6F]  -- "Hello"
    match encryptRecord encState2 .applicationData appMsg with
    | none =>
      IO.println "[FAIL] Encrypt #2: returned none"
      allPassed := false
    | some (encryptedRec2, encState3) =>

      if encState3.seqNum != 2 then
        IO.println s!"[FAIL] Encrypt #2: sequence number should be 2, got {encState3.seqNum}"
        allPassed := false
      else
        IO.println "[PASS] Encrypt #2: sequence number incremented to 2"

      -- Decrypt the second record with matching state (seqNum = 1)
      let decState2b : RecordEncryptionState := {
        key := testKey
        iv := testIV
        seqNum := 1
      }

      match decryptRecord decState2b encryptedRec2 with
      | none =>
        IO.println "[FAIL] Decrypt #2: returned none"
        allPassed := false
      | some (decCt2, decContent2, decState3b) =>
        if decCt2 != .applicationData then
          IO.println "[FAIL] Decrypt #2: wrong content type"
          allPassed := false
        else if !LeanTLS.Utils.byteArrayBEq decContent2 appMsg then
          IO.println "[FAIL] Decrypt #2: content mismatch"
          allPassed := false
        else if decState3b.seqNum != 2 then
          IO.println s!"[FAIL] Decrypt #2: sequence number should be 2, got {decState3b.seqNum}"
          allPassed := false
        else
          IO.println "[PASS] Encrypt/decrypt roundtrip #2: content and type match"

    -- Test decryption failure with wrong sequence number
    let wrongState : RecordEncryptionState := {
      key := testKey
      iv := testIV
      seqNum := 99  -- wrong seq num
    }
    match decryptRecord wrongState encryptedRec with
    | none =>
      IO.println "[PASS] Decrypt with wrong seqNum correctly fails"
    | some _ =>
      IO.println "[FAIL] Decrypt with wrong seqNum should have failed"
      allPassed := false

  -- Summary
  IO.println ""
  if allPassed then
    IO.println "All TLS Record Layer tests passed!"
  else
    IO.println "Some TLS Record Layer tests FAILED!"

  return allPassed

end LeanTLS.Record
