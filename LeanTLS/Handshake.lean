import LeanTLS.Crypto.SHA256
import LeanTLS.Crypto.HMAC

set_option autoImplicit false

namespace LeanTLS.Handshake

/-!
# TLS 1.3 Handshake Messages (RFC 8446 Section 4)

Pure Lean 4 implementation of TLS 1.3 handshake message types, construction,
and parsing. Covers ClientHello, ServerHello, Finished messages, and transcript
hash computation.
-/

-- ============================================================================
-- Section 0: ByteArray equality
-- ============================================================================

/-- Compare two ByteArrays for equality by comparing their underlying data. -/
def byteArrayEq (a b : ByteArray) : Bool :=
  a.data == b.data

instance : BEq ByteArray where
  beq := byteArrayEq

-- ============================================================================
-- Section 1: Big-endian encoding/decoding helpers
-- ============================================================================

/-- Encode a UInt16 as 2 bytes in big-endian order. -/
def encodeUInt16BE (v : UInt16) : ByteArray :=
  ByteArray.mk #[(v >>> 8).toUInt8, v.toUInt8]

/-- Decode a big-endian UInt16 from `data` starting at index `i`.
    Returns `none` if there are fewer than 2 bytes available. -/
def decodeUInt16BE (data : ByteArray) (i : Nat) : Option UInt16 :=
  if i + 2 > data.size then none
  else
    let b0 := (data.get! i).toUInt16
    let b1 := (data.get! (i + 1)).toUInt16
    some ((b0 <<< 8) ||| b1)

/-- Encode a 24-bit value as 3 bytes in big-endian order.
    Only the lower 24 bits of the UInt32 are used. -/
def encodeUInt24BE (v : UInt32) : ByteArray :=
  ByteArray.mk #[(v >>> 16).toUInt8, (v >>> 8).toUInt8, v.toUInt8]

/-- Decode a big-endian 24-bit value from `data` starting at index `i`.
    Returns `none` if there are fewer than 3 bytes available. -/
def decodeUInt24BE (data : ByteArray) (i : Nat) : Option UInt32 :=
  if i + 3 > data.size then none
  else
    let b0 := (data.get! i).toUInt32
    let b1 := (data.get! (i + 1)).toUInt32
    let b2 := (data.get! (i + 2)).toUInt32
    some ((b0 <<< 16) ||| (b1 <<< 8) ||| b2)

/-- Extract a sub-array from `data` starting at `start` with `len` bytes.
    Returns `none` if there are not enough bytes. -/
def extractBytes (data : ByteArray) (start : Nat) (len : Nat) : Option ByteArray :=
  if start + len > data.size then none
  else some (data.extract start (start + len))

-- ============================================================================
-- Section 2: Handshake Types
-- ============================================================================

/-- TLS 1.3 handshake message types (RFC 8446 Section 4). -/
inductive HandshakeType where
  | clientHello : HandshakeType         -- 1
  | serverHello : HandshakeType         -- 2
  | encryptedExtensions : HandshakeType -- 8
  | certificate : HandshakeType         -- 11
  | certificateVerify : HandshakeType   -- 15
  | finished : HandshakeType            -- 20
  deriving BEq, Repr

/-- Convert a HandshakeType to its wire byte value. -/
def HandshakeType.toByte (ht : HandshakeType) : UInt8 :=
  match ht with
  | .clientHello         => 1
  | .serverHello         => 2
  | .encryptedExtensions => 8
  | .certificate         => 11
  | .certificateVerify   => 15
  | .finished            => 20

/-- Parse a byte into a HandshakeType, or `none` if unrecognized. -/
def HandshakeType.fromByte (b : UInt8) : Option HandshakeType :=
  match b.toNat with
  | 1  => some .clientHello
  | 2  => some .serverHello
  | 8  => some .encryptedExtensions
  | 11 => some .certificate
  | 15 => some .certificateVerify
  | 20 => some .finished
  | _  => none

-- ============================================================================
-- Section 3: Handshake Message wrapper
-- ============================================================================

/-- A handshake message consisting of a type and a payload (body without
    the 4-byte header). -/
structure HandshakeMessage where
  msgType : HandshakeType
  payload : ByteArray

/-- Encode a handshake message to wire format:
    1 byte type + 3 bytes length (big-endian) + payload. -/
def HandshakeMessage.encode (msg : HandshakeMessage) : ByteArray :=
  let typeByte := ByteArray.mk #[msg.msgType.toByte]
  let lenBytes := encodeUInt24BE msg.payload.size.toUInt32
  typeByte ++ lenBytes ++ msg.payload

/-- Decode a handshake message from wire data.
    Returns the parsed message and the remaining bytes, or `none` on failure. -/
def HandshakeMessage.decode (data : ByteArray) : Option (HandshakeMessage × ByteArray) :=
  if data.size < 4 then none
  else do
    let msgType ← HandshakeType.fromByte (data.get! 0)
    let len ← decodeUInt24BE data 1
    let payloadLen := len.toNat
    if 4 + payloadLen > data.size then none
    else
      let payload := data.extract 4 (4 + payloadLen)
      let rest := data.extract (4 + payloadLen) data.size
      some ({ msgType := msgType, payload := payload }, rest)

-- ============================================================================
-- Section 4: TLS Extension helpers
-- ============================================================================

/-- Build a single TLS extension: type(2 bytes) + length(2 bytes) + data. -/
private def buildExtension (extType : UInt16) (extData : ByteArray) : ByteArray :=
  encodeUInt16BE extType ++ encodeUInt16BE extData.size.toUInt16 ++ extData

/-- Build the supported_versions extension for ClientHello (type 0x002b).
    Content: list_length(1 byte) + 0x0304 (TLS 1.3). -/
private def buildSupportedVersionsExt : ByteArray :=
  -- list_length = 2 (one 2-byte version entry)
  let data := ByteArray.mk #[0x02] ++ encodeUInt16BE 0x0304
  buildExtension 0x002b data

/-- Build the supported_groups extension (type 0x000a).
    Content: list_length(2 bytes) + 0x001d (x25519). -/
private def buildSupportedGroupsExt : ByteArray :=
  -- list of named groups: length 2 bytes + one group (2 bytes)
  let data := encodeUInt16BE 0x0002 ++ encodeUInt16BE 0x001d
  buildExtension 0x000a data

/-- Build the key_share extension for ClientHello (type 0x0033).
    Content: client_shares_length(2 bytes) + key_share_entry.
    key_share_entry: group(2 bytes) + key_exchange_length(2 bytes) + public_key. -/
private def buildKeyShareExt (publicKey : ByteArray) : ByteArray :=
  -- key_share_entry: group (0x001d) + key_exchange_length + public_key
  let entry := encodeUInt16BE 0x001d ++ encodeUInt16BE publicKey.size.toUInt16 ++ publicKey
  -- client_shares_length + entries
  let data := encodeUInt16BE entry.size.toUInt16 ++ entry
  buildExtension 0x0033 data

/-- Build the signature_algorithms extension (type 0x000d).
    Content: list_length(2 bytes) + rsa_pss_rsae_sha256(0x0804) + ecdsa_secp256r1_sha256(0x0403). -/
private def buildSignatureAlgorithmsExt : ByteArray :=
  -- Two 2-byte algorithms = 4 bytes total
  let algos := encodeUInt16BE 0x0804 ++ encodeUInt16BE 0x0403
  let data := encodeUInt16BE algos.size.toUInt16 ++ algos
  buildExtension 0x000d data

-- ============================================================================
-- Section 5: ClientHello construction (RFC 8446 Section 4.1.2)
-- ============================================================================

/-- Parameters for building a ClientHello message. -/
structure ClientHelloParams where
  random : ByteArray          -- 32 bytes of random
  sessionId : ByteArray       -- legacy session ID (32 bytes for compatibility)

/-- Build a ClientHello message for TLS 1.3 with:
    - cipher_suites: [TLS_AES_128_GCM_SHA256] (0x1301)
    - supported_versions extension: [TLS 1.3 (0x0304)]
    - key_share extension: x25519 public key
    - supported_groups extension: [x25519 (0x001d)]
    - signature_algorithms extension: [rsa_pss_rsae_sha256 (0x0804),
      ecdsa_secp256r1_sha256 (0x0403)]
    Returns the full ClientHello handshake message bytes (including handshake header). -/
def buildClientHello (params : ClientHelloParams) (publicKey : ByteArray) : ByteArray :=
  -- legacy_version: TLS 1.2 (0x0303)
  let body := encodeUInt16BE 0x0303
  -- random: 32 bytes
  let body := body ++ params.random
  -- legacy_session_id: length (1 byte) + session_id
  let body := body ++ ByteArray.mk #[params.sessionId.size.toUInt8] ++ params.sessionId
  -- cipher_suites: length (2 bytes) + TLS_AES_128_GCM_SHA256 (0x1301)
  let body := body ++ encodeUInt16BE 0x0002 ++ encodeUInt16BE 0x1301
  -- legacy_compression_methods: length (1 byte) + null (0x00)
  let body := body ++ ByteArray.mk #[0x01, 0x00]
  -- extensions
  let extensions :=
    buildSupportedVersionsExt ++
    buildSupportedGroupsExt ++
    buildKeyShareExt publicKey ++
    buildSignatureAlgorithmsExt
  -- extensions: total_length (2 bytes) + extension data
  let body := body ++ encodeUInt16BE extensions.size.toUInt16 ++ extensions
  -- Wrap in a handshake message
  let msg : HandshakeMessage := { msgType := .clientHello, payload := body }
  msg.encode

-- ============================================================================
-- Section 6: ServerHello parsing (RFC 8446 Section 4.1.3)
-- ============================================================================

/-- Parsed ServerHello data. -/
structure ServerHelloData where
  serverRandom : ByteArray       -- 32 bytes
  sessionId : ByteArray
  cipherSuite : UInt16
  serverPublicKey : Option ByteArray  -- from key_share extension (x25519)

/-- Parse extensions from a ServerHello payload.
    Each extension: type(2) + length(2) + data.
    Returns the x25519 server public key from the key_share extension, if found. -/
private def parseServerExtensions (data : ByteArray) (offset : Nat) (endPos : Nat) : Option ByteArray :=
  go offset none
where
  go (pos : Nat) (pubKey : Option ByteArray) : Option ByteArray :=
    if pos >= endPos then pubKey
    else if pos + 4 > endPos then pubKey  -- malformed, stop
    else
      match decodeUInt16BE data pos, decodeUInt16BE data (pos + 2) with
      | some extType, some extLen =>
        let extDataStart := pos + 4
        let extDataEnd := extDataStart + extLen.toNat
        if extDataEnd > endPos then pubKey  -- malformed, stop
        else
          -- Check if this is the key_share extension (0x0033)
          if extType == 0x0033 then
            -- ServerHello key_share: group(2) + key_exchange_length(2) + key_exchange
            if extLen.toNat >= 4 then
              match decodeUInt16BE data extDataStart, decodeUInt16BE data (extDataStart + 2) with
              | some group, some keyLen =>
                if group == 0x001d then  -- x25519
                  match extractBytes data (extDataStart + 4) keyLen.toNat with
                  | some keyData => go extDataEnd (some keyData)
                  | none => go extDataEnd pubKey
                else go extDataEnd pubKey
              | _, _ => go extDataEnd pubKey
            else go extDataEnd pubKey
          else go extDataEnd pubKey
      | _, _ => pubKey
  termination_by endPos - pos

/-- Parse a ServerHello payload (without the handshake header).

    Wire format:
    - legacy_version: 2 bytes (0x0303)
    - random: 32 bytes
    - legacy_session_id_echo: length(1 byte) + session_id
    - cipher_suite: 2 bytes
    - legacy_compression_method: 1 byte
    - extensions: length(2 bytes) + extension data -/
def parseServerHello (payload : ByteArray) : Option ServerHelloData := do
  -- Minimum: 2 (version) + 32 (random) + 1 (sid len) + 2 (cipher) + 1 (comp) = 38
  if payload.size < 38 then none
  else
    let mut pos : Nat := 0
    -- legacy_version (skip)
    pos := pos + 2
    -- random: 32 bytes
    let serverRandom ← extractBytes payload pos 32
    pos := pos + 32
    -- session_id: length (1 byte) + data
    let sidLen := (payload.get! pos).toNat
    pos := pos + 1
    if pos + sidLen > payload.size then none
    else
      let sessionId ← extractBytes payload pos sidLen
      pos := pos + sidLen
      -- cipher_suite: 2 bytes
      if pos + 2 > payload.size then none
      else
        let cipherSuite ← decodeUInt16BE payload pos
        pos := pos + 2
        -- compression_method: 1 byte (skip)
        if pos + 1 > payload.size then none
        else
          pos := pos + 1
          -- extensions: length(2) + data
          let serverPublicKey ←
            if pos + 2 <= payload.size then do
              let extLen ← decodeUInt16BE payload pos
              pos := pos + 2
              let extEnd := pos + extLen.toNat
              if extEnd > payload.size then
                pure none
              else
                pure (parseServerExtensions payload pos extEnd)
            else
              pure none
          some {
            serverRandom := serverRandom
            sessionId := sessionId
            cipherSuite := cipherSuite
            serverPublicKey := serverPublicKey
          }

-- ============================================================================
-- Section 7: Finished message (RFC 8446 Section 4.4.4)
-- ============================================================================

/-- Build a Finished message verify_data.
    verify_data = HMAC-SHA-256(finished_key, transcript_hash) -/
def buildFinishedVerifyData (finishedKey : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  LeanTLS.Crypto.HMAC.hmacSHA256 finishedKey transcriptHash

/-- Verify a Finished message by comparing the received verify_data
    against the expected value computed from the finished_key and transcript_hash. -/
def verifyFinished (finishedKey : ByteArray) (transcriptHash : ByteArray) (verifyData : ByteArray) : Bool :=
  let expected := buildFinishedVerifyData finishedKey transcriptHash
  -- Constant-time comparison to prevent timing attacks
  if expected.size != verifyData.size then false
  else
    let xorSum := Nat.fold (n := expected.size) (init := (0 : UInt8)) fun i _ acc =>
      acc ||| ((expected.get! i) ^^^ (verifyData.get! i))
    xorSum == 0

-- ============================================================================
-- Section 8: Transcript hash helper
-- ============================================================================

/-- Compute the transcript hash (SHA-256) of all handshake messages so far.
    Concatenates all handshake message bytes and hashes them with SHA-256. -/
def transcriptHash (messages : Array ByteArray) : ByteArray :=
  let concatenated := messages.foldl (init := ByteArray.empty) (· ++ ·)
  LeanTLS.Crypto.SHA256.hash concatenated

-- ============================================================================
-- Section 9: Hex utilities for testing
-- ============================================================================

/-- Convert a single hex character to its numeric value (0-15). -/
private def hexCharToNibble (c : Char) : UInt8 :=
  if '0' ≤ c ∧ c ≤ '9' then (c.toNat - '0'.toNat).toUInt8
  else if 'a' ≤ c ∧ c ≤ 'f' then (c.toNat - 'a'.toNat + 10).toUInt8
  else if 'A' ≤ c ∧ c ≤ 'F' then (c.toNat - 'A'.toNat + 10).toUInt8
  else 0

/-- Convert a hexadecimal string to a ByteArray. -/
private def hexToBytes (s : String) : ByteArray :=
  let chars := s.toList
  go chars #[]
where
  go : List Char → Array UInt8 → ByteArray
    | c1 :: c2 :: rest, acc =>
      let hi := hexCharToNibble c1
      let lo := hexCharToNibble c2
      go rest (acc.push ((hi <<< 4) ||| lo))
    | _, acc => ByteArray.mk acc

-- ============================================================================
-- Section 10: Tests
-- ============================================================================

/-- Run all Handshake module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- --------------------------------------------------------------------------
  -- Test 1: HandshakeMessage encode/decode roundtrip
  -- --------------------------------------------------------------------------
  IO.println "  Handshake test 1 (encode/decode roundtrip):"
  let testPayload := hexToBytes "deadbeef01020304"
  let origMsg : HandshakeMessage := { msgType := .finished, payload := testPayload }
  let encoded := origMsg.encode
  match HandshakeMessage.decode encoded with
  | some (decoded, rest) =>
    let typeOk := decoded.msgType == origMsg.msgType
    let payloadOk := decoded.payload == origMsg.payload
    let restOk := rest.size == 0
    if typeOk && payloadOk && restOk then
      IO.println "    PASSED"
    else
      IO.println "    FAILED (mismatch)"
      IO.println s!"    type match: {typeOk}, payload match: {payloadOk}, rest empty: {restOk}"
      allPassed := false
  | none =>
    IO.println "    FAILED (decode returned none)"
    allPassed := false

  -- Test 1b: encode/decode roundtrip with extra trailing bytes
  IO.println "  Handshake test 1b (encode/decode with trailing data):"
  let trailing := hexToBytes "aabbccdd"
  let encodedWithTrail := encoded ++ trailing
  match HandshakeMessage.decode encodedWithTrail with
  | some (decoded, rest) =>
    let typeOk := decoded.msgType == origMsg.msgType
    let payloadOk := decoded.payload == origMsg.payload
    let restOk := rest == trailing
    if typeOk && payloadOk && restOk then
      IO.println "    PASSED"
    else
      IO.println "    FAILED (mismatch)"
      allPassed := false
  | none =>
    IO.println "    FAILED (decode returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: ClientHello construction
  -- --------------------------------------------------------------------------
  IO.println "  Handshake test 2 (ClientHello construction):"
  -- Use deterministic random and public key for testing
  let testRandom := ByteArray.mk (Array.mkArray 32 0xAA)
  let testSessionId := ByteArray.mk (Array.mkArray 32 0xBB)
  let testPubKey := ByteArray.mk (Array.mkArray 32 0xCC)
  let chParams : ClientHelloParams := { random := testRandom, sessionId := testSessionId }
  let chBytes := buildClientHello chParams testPubKey

  let mut test2Passed := true

  -- Check handshake type byte is 1 (clientHello)
  if chBytes.size > 0 && chBytes.get! 0 == 1 then
    IO.println "    handshake type = 1: OK"
  else
    IO.println "    handshake type = 1: FAILED"
    test2Passed := false

  -- The payload starts at byte 4 (after handshake header).
  -- legacy_version should be at bytes 4-5 = 0x0303
  if chBytes.size > 5 then
    match decodeUInt16BE chBytes 4 with
    | some ver =>
      if ver == 0x0303 then
        IO.println "    legacy_version = 0x0303: OK"
      else
        IO.println s!"    legacy_version = 0x0303: FAILED (got 0x{LeanTLS.Crypto.SHA256.toHex (encodeUInt16BE ver)})"
        test2Passed := false
    | none =>
      IO.println "    legacy_version = 0x0303: FAILED (could not decode)"
      test2Passed := false
  else
    IO.println "    legacy_version = 0x0303: FAILED (too short)"
    test2Passed := false

  -- Check that cipher_suites contains 0x1301
  -- Position: 4 (ver) + 2 (ver) + 32 (random) + 1 (sid len) + 32 (sid) = 71 for cipher_suites length
  let cipherSuitesOffset := 4 + 2 + 32 + 1 + 32  -- = 71
  if chBytes.size > cipherSuitesOffset + 3 then
    match decodeUInt16BE chBytes (cipherSuitesOffset + 2) with
    | some cs =>
      if cs == 0x1301 then
        IO.println "    cipher_suite contains 0x1301: OK"
      else
        IO.println s!"    cipher_suite contains 0x1301: FAILED (got {cs})"
        test2Passed := false
    | none =>
      IO.println "    cipher_suite contains 0x1301: FAILED (could not decode)"
      test2Passed := false
  else
    IO.println "    cipher_suite contains 0x1301: FAILED (too short)"
    test2Passed := false

  -- Check that extensions include supported_versions with 0x0304
  -- Search for extension type 0x002b in the extensions area
  -- After cipher_suites: 2 (len) + 2 (suite) = 4 bytes
  -- compression_methods: 1 (len) + 1 (null) = 2 bytes
  -- extensions_length: 2 bytes
  -- extensions start at: cipherSuitesOffset + 4 + 2 + 2
  let extTotalOffset := cipherSuitesOffset + 4 + 2 + 2  -- = 79
  -- Find 0x002b in the extensions
  let foundSV := go chBytes extTotalOffset chBytes.size false
  if foundSV then
    IO.println "    supported_versions with 0x0304: OK"
  else
    IO.println "    supported_versions with 0x0304: FAILED (not found)"
    test2Passed := false

  if test2Passed then
    IO.println "    PASSED"
  else
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: Transcript hash
  -- --------------------------------------------------------------------------
  IO.println "  Handshake test 3 (transcript hash):"
  let msg1 := hexToBytes "010203"
  let msg2 := hexToBytes "040506"
  let th := transcriptHash #[msg1, msg2]
  -- Expected = SHA-256("010203" ++ "040506") = SHA-256(0x010203040506)
  let expected := LeanTLS.Crypto.SHA256.hash (hexToBytes "010203040506")
  if th == expected then
    IO.println "    PASSED"
  else
    IO.println "    FAILED"
    IO.println s!"    expected: {LeanTLS.Crypto.SHA256.toHex expected}"
    IO.println s!"    got:      {LeanTLS.Crypto.SHA256.toHex th}"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 4: Finished verify_data
  -- --------------------------------------------------------------------------
  IO.println "  Handshake test 4 (Finished verify_data):"
  let finKey := hexToBytes "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f"
  let trHash := hexToBytes "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
  let vd := buildFinishedVerifyData finKey trHash
  -- verify_data = HMAC-SHA-256(finKey, trHash)
  let expectedVd := LeanTLS.Crypto.HMAC.hmacSHA256 finKey trHash
  if vd == expectedVd then
    IO.println "    buildFinishedVerifyData: OK"
  else
    IO.println "    buildFinishedVerifyData: FAILED"
    allPassed := false

  -- Verify with correct data should return true
  let verifyOk := verifyFinished finKey trHash vd
  if verifyOk then
    IO.println "    verifyFinished (correct): OK"
  else
    IO.println "    verifyFinished (correct): FAILED"
    allPassed := false

  -- Verify with wrong data should return false
  let wrongVd := ByteArray.mk (Array.mkArray 32 0xFF)
  let verifyBad := verifyFinished finKey trHash wrongVd
  if !verifyBad then
    IO.println "    verifyFinished (wrong data): OK"
  else
    IO.println "    verifyFinished (wrong data): FAILED"
    allPassed := false

  if allPassed then
    IO.println "  All Handshake tests passed."

  return allPassed
where
  /-- Search for supported_versions extension (0x002b) containing TLS 1.3 (0x0304)
      in the given byte range. -/
  go (data : ByteArray) (pos : Nat) (endPos : Nat) (found : Bool) : Bool :=
    if found then true
    else if pos + 4 > endPos then false
    else
      match decodeUInt16BE data pos, decodeUInt16BE data (pos + 2) with
      | some extType, some extLen =>
        let extDataStart := pos + 4
        let extDataEnd := extDataStart + extLen.toNat
        if extDataEnd > endPos then false
        else if extType == 0x002b then
          -- Check if the extension data contains 0x0304
          containsVersion data extDataStart extDataEnd
        else
          go data extDataEnd endPos false
      | _, _ => false
  termination_by endPos - pos
  /-- Check if the supported_versions extension data contains version 0x0304. -/
  containsVersion (data : ByteArray) (pos : Nat) (endPos : Nat) : Bool :=
    if pos + 2 > endPos then false
    else
      match decodeUInt16BE data pos with
      | some v => if v == 0x0304 then true else containsVersion data (pos + 1) endPos
      | none => false
  termination_by endPos - pos

end LeanTLS.Handshake
