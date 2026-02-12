import LeanTLS.Record
import LeanTLS.Handshake
import LeanTLS.KeySchedule
import LeanTLS.Crypto.X25519
import LeanTLS.Crypto.SHA256

/-!
# TLS 1.3 Connection (Integration API)

This module provides the high-level TLS 1.3 client connection API that ties
together the record layer, handshake protocol, key schedule, and cryptographic
primitives into a usable interface.

It exposes:
- `IOStream`: Abstract byte-oriented I/O stream
- `TlsConfig`: Configuration for TLS connections
- `TlsConnection`: Stateful TLS connection with `connect`, `send`, `recv`, `shutdown`
-/

set_option autoImplicit false

namespace LeanTLS

-- ============================================================================
-- Section 1: IO Stream abstraction
-- ============================================================================

/-- Abstract IO stream for reading/writing bytes.
    Users wrap their TCP socket (or any transport) into this. -/
structure IOStream where
  /-- Read exactly `n` bytes from the stream. Blocks until all bytes are available. -/
  read : Nat → IO ByteArray
  /-- Write all bytes to the stream. -/
  write : ByteArray → IO Unit

-- ============================================================================
-- Section 2: TLS Configuration
-- ============================================================================

/-- Configuration options for a TLS connection. -/
structure TlsConfig where
  /-- Server hostname (used in future SNI extension). -/
  serverName : String := ""
  /-- Skip certificate verification (always true for now). -/
  skipCertVerify : Bool := true

-- ============================================================================
-- Section 3: TLS Connection State
-- ============================================================================

/-- Mutable state of an active TLS connection. -/
structure TlsState where
  /-- The underlying transport stream. -/
  stream : IOStream
  /-- Encryption state for outgoing records. -/
  clientEncState : LeanTLS.Record.RecordEncryptionState
  /-- Decryption state for incoming records. -/
  serverDecState : LeanTLS.Record.RecordEncryptionState
  /-- Buffered decrypted application data not yet consumed by the caller. -/
  recvBuffer : ByteArray
  /-- Whether the connection has been closed. -/
  closed : Bool

/-- A TLS 1.3 connection handle. All mutable state is behind an IO.Ref. -/
structure TlsConnection where
  ref : IO.Ref TlsState

-- ============================================================================
-- Section 4: Random byte generation
-- ============================================================================

/-- Generate `n` cryptographically random bytes from /dev/urandom. -/
private def generateRandomBytes (n : Nat) : IO ByteArray := do
  let handle ← IO.FS.Handle.mk "/dev/urandom" .read
  handle.read n.toUSize

-- ============================================================================
-- Section 5: Stream helpers for reading/writing TLS records
-- ============================================================================

/-- Read exactly `n` bytes from the stream, looping until all bytes have been
    received. This handles partial reads from the underlying transport. -/
private def readExact (stream : IOStream) (n : Nat) : IO ByteArray := do
  let mut buf := ByteArray.empty
  let mut remaining := n
  while remaining > 0 do
    let chunk ← stream.read remaining
    if chunk.size == 0 then
      throw (IO.userError "TLS: connection closed unexpectedly while reading")
    buf := buf ++ chunk
    remaining := remaining - chunk.size
  return buf

/-- Read a complete TLS record from the stream.
    Reads the 5-byte header first, then reads the fragment based on the
    declared length. -/
private def readRecord (stream : IOStream) : IO LeanTLS.Record.TLSRecord := do
  -- Read the 5-byte TLS record header
  let header ← readExact stream 5
  -- Parse content type
  let ctByte := header.get! 0
  let ct ← match LeanTLS.Record.ContentType.fromByte ctByte with
    | some ct => pure ct
    | none => throw (IO.userError s!"TLS: unknown record content type: {ctByte}")
  -- Parse legacy version (2 bytes, big-endian)
  let verHi := header.get! 1
  let verLo := header.get! 2
  let version : UInt16 := (verHi.toUInt16 <<< 8) ||| verLo.toUInt16
  -- Parse fragment length (2 bytes, big-endian)
  let lenHi := header.get! 3
  let lenLo := header.get! 4
  let fragLen : Nat := lenHi.toNat * 256 + lenLo.toNat
  -- Validate fragment length
  if fragLen > 16384 + 256 then
    throw (IO.userError s!"TLS: record fragment too large: {fragLen}")
  -- Read the fragment
  let fragment ← readExact stream fragLen
  return {
    contentType := ct
    legacyVersion := version
    fragment := fragment
  }

/-- Write a TLS record to the stream by encoding it to wire format. -/
private def writeRecord (stream : IOStream) (tlsRec : LeanTLS.Record.TLSRecord) : IO Unit := do
  let encoded := tlsRec.encode
  stream.write encoded

/-- Send a handshake message as an unencrypted TLS record. -/
private def sendHandshakeRecord (stream : IOStream) (data : ByteArray) : IO Unit := do
  let tlsRec : LeanTLS.Record.TLSRecord := {
    contentType := .handshake
    legacyVersion := 0x0303
    fragment := data
  }
  writeRecord stream tlsRec

/-- Send an encrypted handshake message. Returns the updated encryption state. -/
private def sendEncryptedHandshake
    (stream : IOStream)
    (state : LeanTLS.Record.RecordEncryptionState)
    (data : ByteArray) : IO LeanTLS.Record.RecordEncryptionState := do
  let (encRec, newState) := LeanTLS.Record.encryptRecord state .handshake data
  writeRecord stream encRec
  return newState

-- ============================================================================
-- Section 6: Handshake message parsing from decrypted content
-- ============================================================================

/-- Parse all handshake messages from a decrypted buffer. Multiple handshake
    messages can be coalesced into a single TLS record, so we loop until all
    bytes are consumed. Returns an array of raw handshake message bytes
    (each including the 4-byte handshake header). -/
private def parseHandshakeMessages (data : ByteArray) : IO (Array ByteArray) := do
  let mut result : Array ByteArray := #[]
  let mut remaining := data
  while remaining.size > 0 do
    match LeanTLS.Handshake.HandshakeMessage.decode remaining with
    | some (msg, rest) =>
      -- Re-encode the message to get the raw bytes for transcript tracking
      let rawBytes := msg.encode
      result := result.push rawBytes
      remaining := rest
    | none =>
      throw (IO.userError "TLS: failed to parse handshake message from decrypted content")
  return result

-- ============================================================================
-- Section 7: Helper to extract handshake type and raw bytes from the array
-- ============================================================================

/-- Extract the handshake type from a raw handshake message byte array. -/
private def getHandshakeType (raw : ByteArray) : IO LeanTLS.Handshake.HandshakeType := do
  match LeanTLS.Handshake.HandshakeMessage.decode raw with
  | some (msg, _) => return msg.msgType
  | none => throw (IO.userError "TLS: failed to decode handshake message type")

-- ============================================================================
-- Section 8: TLS 1.3 Handshake (connect)
-- ============================================================================

namespace TlsConnection

/-- Perform a TLS 1.3 handshake over an existing stream and return a connection
    ready for application data exchange.

    Steps:
    1. Generate ephemeral X25519 keypair
    2. Send ClientHello
    3. Receive ServerHello
    4. Compute shared secret via X25519
    5. Derive handshake traffic keys
    6. Receive encrypted handshake messages (EncryptedExtensions, Certificate,
       CertificateVerify, Finished)
    7. Verify server Finished
    8. Send client Finished
    9. Derive application traffic keys
    10. Return connection ready for application data -/
def connect (stream : IOStream) (_hostname : String) (_config : TlsConfig := {}) : IO TlsConnection := do
  -- -----------------------------------------------------------------------
  -- Step 1: Generate random bytes for client_random, session_id, and X25519 private key
  -- -----------------------------------------------------------------------
  let clientRandom ← generateRandomBytes 32
  let sessionId ← generateRandomBytes 32
  let privateKey ← generateRandomBytes 32

  -- -----------------------------------------------------------------------
  -- Step 2: Compute X25519 public key
  -- -----------------------------------------------------------------------
  let publicKey := LeanTLS.Crypto.X25519.x25519 privateKey LeanTLS.Crypto.X25519.basePoint

  -- -----------------------------------------------------------------------
  -- Step 3: Build and send ClientHello
  -- -----------------------------------------------------------------------
  let params : LeanTLS.Handshake.ClientHelloParams := {
    random := clientRandom
    sessionId := sessionId
  }
  let clientHelloMsg := LeanTLS.Handshake.buildClientHello params publicKey

  -- Initialize transcript with the ClientHello message
  let mut transcript : Array ByteArray := #[clientHelloMsg]

  sendHandshakeRecord stream clientHelloMsg

  -- -----------------------------------------------------------------------
  -- Step 4: Read ServerHello record
  -- -----------------------------------------------------------------------
  let serverHelloRec ← readRecord stream
  if serverHelloRec.contentType != .handshake then
    throw (IO.userError "TLS: expected handshake record for ServerHello, got different content type")

  -- Parse the handshake message
  let (serverHelloHsMsg, _rest) ← match LeanTLS.Handshake.HandshakeMessage.decode serverHelloRec.fragment with
    | some v => pure v
    | none => throw (IO.userError "TLS: failed to decode ServerHello handshake message")

  if serverHelloHsMsg.msgType != .serverHello then
    throw (IO.userError "TLS: expected ServerHello handshake type")

  -- Parse ServerHello data
  let serverHelloData ← match LeanTLS.Handshake.parseServerHello serverHelloHsMsg.payload with
    | some v => pure v
    | none => throw (IO.userError "TLS: failed to parse ServerHello payload")

  -- Extract server's X25519 public key
  let serverPublicKey ← match serverHelloData.serverPublicKey with
    | some k => pure k
    | none => throw (IO.userError "TLS: ServerHello missing key_share extension (x25519 public key)")

  -- Add the raw ServerHello handshake bytes to the transcript
  let serverHelloRaw := serverHelloHsMsg.encode
  transcript := transcript.push serverHelloRaw

  -- -----------------------------------------------------------------------
  -- Step 5: Compute shared secret via X25519
  -- -----------------------------------------------------------------------
  let sharedSecret := LeanTLS.Crypto.X25519.x25519 privateKey serverPublicKey

  -- -----------------------------------------------------------------------
  -- Step 6: Derive handshake secrets and traffic keys
  -- -----------------------------------------------------------------------
  let transcriptHashCHSH := LeanTLS.Handshake.transcriptHash transcript

  let eSecret := LeanTLS.KeySchedule.earlySecret
  let hsSecret := LeanTLS.KeySchedule.handshakeSecret eSecret sharedSecret
  let chsTraffic := LeanTLS.KeySchedule.clientHandshakeTrafficSecret hsSecret transcriptHashCHSH
  let shsTraffic := LeanTLS.KeySchedule.serverHandshakeTrafficSecret hsSecret transcriptHashCHSH
  let serverHsKeys := LeanTLS.KeySchedule.deriveTrafficKeys shsTraffic
  let clientHsKeys := LeanTLS.KeySchedule.deriveTrafficKeys chsTraffic

  -- -----------------------------------------------------------------------
  -- Step 7: Set up encryption states for handshake
  -- -----------------------------------------------------------------------
  let mut serverDecState : LeanTLS.Record.RecordEncryptionState := {
    key := serverHsKeys.key
    iv := serverHsKeys.iv
    seqNum := 0
  }

  let mut clientEncState : LeanTLS.Record.RecordEncryptionState := {
    key := clientHsKeys.key
    iv := clientHsKeys.iv
    seqNum := 0
  }

  -- -----------------------------------------------------------------------
  -- Step 8: Read encrypted handshake messages from the server
  --
  -- We expect: EncryptedExtensions, Certificate, CertificateVerify, Finished
  -- (all encrypted with the server handshake traffic key).
  --
  -- Between ServerHello and EncryptedExtensions, some servers may send a
  -- ChangeCipherSpec record for middlebox compatibility. We silently ignore it.
  --
  -- Multiple handshake messages can be coalesced into a single TLS record.
  -- -----------------------------------------------------------------------

  -- Collect all decrypted handshake messages (as raw bytes) from encrypted records
  let mut handshakeMsgBytes : Array ByteArray := #[]

  -- We need to read until we have all 4 expected messages
  while handshakeMsgBytes.size < 4 do
    let encRec ← readRecord stream

    -- Silently ignore ChangeCipherSpec records
    if encRec.contentType == .changeCipherSpec then
      continue

    -- All other records during handshake should be encrypted (applicationData outer type)
    if encRec.contentType != .applicationData then
      throw (IO.userError "TLS: unexpected record content type during encrypted handshake")

    -- Decrypt the record
    let (innerContentType, decryptedContent, newDecState) ←
      match LeanTLS.Record.decryptRecord serverDecState encRec with
      | some v => pure v
      | none => throw (IO.userError "TLS: failed to decrypt server handshake record")
    serverDecState := newDecState

    -- The inner content type should be handshake
    if innerContentType != .handshake then
      -- Could be an alert
      if innerContentType == .alert then
        throw (IO.userError "TLS: received alert during handshake")
      throw (IO.userError "TLS: unexpected inner content type during encrypted handshake")

    -- Parse potentially multiple handshake messages from the decrypted content
    let msgs ← parseHandshakeMessages decryptedContent
    for rawMsg in msgs do
      handshakeMsgBytes := handshakeMsgBytes.push rawMsg

  -- -----------------------------------------------------------------------
  -- Step 9: Process the handshake messages and verify server Finished
  -- -----------------------------------------------------------------------

  -- Validate we have at least 4 messages
  if handshakeMsgBytes.size < 4 then
    throw (IO.userError "TLS: did not receive all expected handshake messages")

  let eeRaw := handshakeMsgBytes.get! 0
  let certRaw := handshakeMsgBytes.get! 1
  let cvRaw := handshakeMsgBytes.get! 2
  let finRaw := handshakeMsgBytes.get! 3

  -- Validate message types
  let eeType ← getHandshakeType eeRaw
  let certType ← getHandshakeType certRaw
  let cvType ← getHandshakeType cvRaw
  let finType ← getHandshakeType finRaw

  if eeType != .encryptedExtensions then
    throw (IO.userError "TLS: expected EncryptedExtensions message")
  if certType != .certificate then
    throw (IO.userError "TLS: expected Certificate message")
  if cvType != .certificateVerify then
    throw (IO.userError "TLS: expected CertificateVerify message")
  if finType != .finished then
    throw (IO.userError "TLS: expected Finished message")

  -- Add EncryptedExtensions, Certificate, CertificateVerify to transcript
  -- (Finished is NOT included when computing the hash to verify it)
  transcript := transcript.push eeRaw
  transcript := transcript.push certRaw
  transcript := transcript.push cvRaw

  -- Verify server Finished
  -- The verify_data is computed over the transcript hash of everything
  -- up to (but not including) the Finished message itself
  let transcriptHashPreFinished := LeanTLS.Handshake.transcriptHash transcript
  let serverFinKey := LeanTLS.KeySchedule.finishedKey shsTraffic

  -- Extract the verify_data from the Finished message payload
  let serverFinVerifyData ← match LeanTLS.Handshake.HandshakeMessage.decode finRaw with
    | some (finMsg, _) => pure finMsg.payload
    | none => throw (IO.userError "TLS: failed to decode server Finished message")

  if !(LeanTLS.Handshake.verifyFinished serverFinKey transcriptHashPreFinished serverFinVerifyData) then
    throw (IO.userError "TLS: server Finished verification failed")

  -- Add server Finished to transcript
  transcript := transcript.push finRaw

  -- -----------------------------------------------------------------------
  -- Step 10: Compute and send client Finished
  -- -----------------------------------------------------------------------
  let transcriptHashWithServerFin := LeanTLS.Handshake.transcriptHash transcript
  let clientFinKey := LeanTLS.KeySchedule.finishedKey chsTraffic
  let clientFinVerifyData := LeanTLS.Handshake.buildFinishedVerifyData clientFinKey transcriptHashWithServerFin
  let clientFinMsg := LeanTLS.Handshake.HandshakeMessage.encode {
    msgType := .finished
    payload := clientFinVerifyData
  }

  -- Send client Finished as encrypted handshake record
  clientEncState ← sendEncryptedHandshake stream clientEncState clientFinMsg

  -- -----------------------------------------------------------------------
  -- Step 11: Derive application traffic keys
  -- -----------------------------------------------------------------------
  -- The transcript hash for app traffic secrets includes up through server Finished
  -- (same as transcriptHashWithServerFin, since client Finished is NOT included
  -- in the hash for deriving app traffic secrets per RFC 8446 Section 7.1)
  let appTranscriptHash := transcriptHashWithServerFin

  let mSecret := LeanTLS.KeySchedule.masterSecret hsSecret
  let catSecret := LeanTLS.KeySchedule.clientAppTrafficSecret mSecret appTranscriptHash
  let satSecret := LeanTLS.KeySchedule.serverAppTrafficSecret mSecret appTranscriptHash
  let clientAppKeys := LeanTLS.KeySchedule.deriveTrafficKeys catSecret
  let serverAppKeys := LeanTLS.KeySchedule.deriveTrafficKeys satSecret

  -- -----------------------------------------------------------------------
  -- Step 12: Set up application encryption states and return TlsConnection
  -- -----------------------------------------------------------------------
  let appClientEncState : LeanTLS.Record.RecordEncryptionState := {
    key := clientAppKeys.key
    iv := clientAppKeys.iv
    seqNum := 0
  }

  let appServerDecState : LeanTLS.Record.RecordEncryptionState := {
    key := serverAppKeys.key
    iv := serverAppKeys.iv
    seqNum := 0
  }

  let state : TlsState := {
    stream := stream
    clientEncState := appClientEncState
    serverDecState := appServerDecState
    recvBuffer := ByteArray.empty
    closed := false
  }

  let ref ← IO.mkRef state
  return { ref := ref }

-- ============================================================================
-- Section 9: Application data send
-- ============================================================================

/-- Send application data over the TLS connection. -/
def send (conn : TlsConnection) (data : ByteArray) : IO Unit := do
  let st ← conn.ref.get
  if st.closed then
    throw (IO.userError "TLS: connection is closed")
  let (encRec, newEncState) := LeanTLS.Record.encryptRecord st.clientEncState .applicationData data
  writeRecord st.stream encRec
  conn.ref.modify fun s => { s with clientEncState := newEncState }

-- ============================================================================
-- Section 10: Application data receive
-- ============================================================================

/-- Read and decrypt one record, returning the inner content type and plaintext.
    Skips ChangeCipherSpec records. -/
private def recvOneRecord (conn : TlsConnection) : IO (LeanTLS.Record.ContentType × ByteArray) := do
  let mut done := false
  let mut resultCt : LeanTLS.Record.ContentType := .applicationData
  let mut resultContent := ByteArray.empty
  while !done do
    let st ← conn.ref.get
    let encRec ← readRecord st.stream

    -- Silently ignore ChangeCipherSpec records
    if encRec.contentType == .changeCipherSpec then
      continue

    if encRec.contentType != .applicationData then
      throw (IO.userError "TLS: unexpected record content type during application data")

    match LeanTLS.Record.decryptRecord st.serverDecState encRec with
    | some (innerCt, content, newDecState) =>
      conn.ref.modify fun s => { s with serverDecState := newDecState }
      resultCt := innerCt
      resultContent := content
      done := true
    | none =>
      throw (IO.userError "TLS: failed to decrypt application data record")
  return (resultCt, resultContent)

/-- Receive application data from the TLS connection.
    Returns `none` if the connection has been closed (e.g., via close_notify).
    If there is buffered data from a previous record, returns that first.
    Otherwise reads and decrypts the next record from the stream. -/
def recv (conn : TlsConnection) (maxBytes : Nat := 16384) : IO (Option ByteArray) := do
  let st ← conn.ref.get
  if st.closed then
    return none

  -- If there is buffered data, return from that first
  if st.recvBuffer.size > 0 then
    let toReturn := Nat.min maxBytes st.recvBuffer.size
    let result := st.recvBuffer.extract 0 toReturn
    let remaining := st.recvBuffer.extract toReturn st.recvBuffer.size
    conn.ref.modify fun s => { s with recvBuffer := remaining }
    return some result

  -- Read and decrypt records until we get application data or a close
  let mut gotResult := false
  let mut finalResult : Option ByteArray := none
  while !gotResult do
    let (innerCt, content) ← recvOneRecord conn
    match innerCt with
    | .applicationData =>
      if content.size == 0 then
        -- Empty application data, read another record
        continue
      -- Buffer data and return up to maxBytes
      let toReturn := Nat.min maxBytes content.size
      let result := content.extract 0 toReturn
      if toReturn < content.size then
        let remaining := content.extract toReturn content.size
        conn.ref.modify fun s => { s with recvBuffer := remaining }
      finalResult := some result
      gotResult := true
    | .alert =>
      -- Check for close_notify (alert level 1, description 0)
      if content.size >= 2 && content.get! 1 == 0 then
        conn.ref.modify fun s => { s with closed := true }
        finalResult := none
        gotResult := true
      else
        throw (IO.userError "TLS: received alert from server")
    | .handshake =>
      -- Post-handshake messages (e.g., NewSessionTicket) -- skip them
      continue
    | .changeCipherSpec =>
      -- Ignore
      continue
  return finalResult

-- ============================================================================
-- Section 11: Shutdown
-- ============================================================================

/-- Send a close_notify alert and mark the connection as closed. -/
def shutdown (conn : TlsConnection) : IO Unit := do
  let st ← conn.ref.get
  if st.closed then
    return ()
  -- close_notify alert: level=warning(1), description=close_notify(0)
  let alertData := ByteArray.mk #[1, 0]
  let (encRec, newEncState) := LeanTLS.Record.encryptRecord st.clientEncState .alert alertData
  writeRecord st.stream encRec
  conn.ref.modify fun s => { s with clientEncState := newEncState, closed := true }

end TlsConnection

end LeanTLS
