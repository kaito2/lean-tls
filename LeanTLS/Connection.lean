import LeanTLS.Record
import LeanTLS.Handshake
import LeanTLS.KeySchedule
import LeanTLS.Errors
import LeanTLS.Crypto.X25519
import LeanTLS.Crypto.SHA256
import LeanTLS.Crypto.SHA384
import LeanTLS.CertVerify
import LeanTLS.ChainVerify
import LeanTLS.KeyUpdate

/-!
# TLS 1.3 Connection (Integration API)

This module provides the high-level TLS 1.3 client connection API that ties
together the record layer, handshake protocol, key schedule, and cryptographic
primitives into a usable interface.

It exposes:
- `IOStream`: Abstract byte-oriented I/O stream
- `TlsConfig`: Configuration for TLS connections (with `VerifyMode`)
- `TlsConnection`: Stateful TLS connection with `connect`, `send`, `recv`, `shutdown`

Supports:
- AES-128-GCM with SHA-256 (TLS_AES_128_GCM_SHA256, 0x1301)
- AES-256-GCM with SHA-384 (TLS_AES_256_GCM_SHA384, 0x1302)
- Certificate chain verification via ChainVerify
- KeyUpdate post-handshake message handling
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

/-- Certificate verification mode for TLS connections. -/
inductive VerifyMode where
  /-- No certificate verification. -/
  | none : VerifyMode
  /-- Verify the certificate chain against the CA store, but do not check hostname. -/
  | verifyCA : VerifyMode
  /-- Verify the certificate chain and check hostname matches. -/
  | verifyFull : VerifyMode
  deriving BEq, Repr

/-- Configuration options for a TLS connection. -/
structure TlsConfig where
  /-- Server hostname (used for SNI extension and hostname verification). -/
  serverName : String := ""
  /-- Certificate verification mode (default: none for backwards compatibility). -/
  verifyMode : VerifyMode := .none
  /-- Trusted root CA certificates for chain verification. -/
  trustedCerts : Array LeanTLS.X509.X509Certificate := #[]
  /-- Current time for certificate validity checking (optional). -/
  currentTime : Option LeanTLS.ASN1.DateTime := .none

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
  /-- Whether this connection uses AES-256-GCM (true) or AES-128-GCM (false). -/
  isAES256 : Bool
  /-- Current client application traffic secret (for KeyUpdate). -/
  clientAppSecret : ByteArray
  /-- Current server application traffic secret (for KeyUpdate). -/
  serverAppSecret : ByteArray

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
      throwTlsError .connectionClosed
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
    | none => throwTlsError (.protocolError s!"unknown record content type: {ctByte}")
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
    throwTlsError (.recordOverflow fragLen)
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

/-- Send an encrypted handshake message using cipher-suite-aware encryption.
    Returns the updated encryption state. -/
private def sendEncryptedHandshake
    (stream : IOStream)
    (state : LeanTLS.Record.RecordEncryptionState)
    (data : ByteArray) : IO LeanTLS.Record.RecordEncryptionState := do
  match LeanTLS.Record.encryptRecordAuto state .handshake data with
  | some (encRec, newState) =>
    writeRecord stream encRec
    return newState
  | none => throwTlsError (.internalError "sequence number overflow")

-- ============================================================================
-- Section 6: Alert handling helpers
-- ============================================================================

/-- Handle a decrypted alert payload. For close_notify, marks the connection closed
    and returns none. For fatal alerts or unknown alerts, throws a TlsError. -/
private def handleAlert (content : ByteArray) : IO (Option Unit) := do
  match LeanTLS.decodeAlert content with
  | some (.warning, .closeNotify) =>
    return none
  | some (level, desc) =>
    throwTlsError (.alertReceived level desc)
  | none =>
    if content.size >= 2 then
      throwTlsError (.protocolError s!"unknown alert: level={content.get! 0}, desc={content.get! 1}")
    else
      throwTlsError (.protocolError "malformed alert (too short)")

-- ============================================================================
-- Section 7: Handshake message parsing from decrypted content
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
      let rawBytes := msg.encode
      result := result.push rawBytes
      remaining := rest
    | none =>
      throwTlsError (.protocolError "failed to parse handshake message from decrypted content")
  return result

-- ============================================================================
-- Section 8: Helper to extract handshake type and raw bytes from the array
-- ============================================================================

/-- Extract the handshake type from a raw handshake message byte array. -/
private def getHandshakeType (raw : ByteArray) : IO LeanTLS.Handshake.HandshakeType := do
  match LeanTLS.Handshake.HandshakeMessage.decode raw with
  | some (msg, _) => return msg.msgType
  | none => throwTlsError (.protocolError "failed to decode handshake message type")

-- ============================================================================
-- Section 9: TLS 1.3 Handshake (connect)
-- ============================================================================

namespace TlsConnection

/-- Perform a TLS 1.3 handshake over an existing stream and return a connection
    ready for application data exchange.

    Steps:
    1. Generate ephemeral X25519 keypair
    2. Send ClientHello
    3. Receive ServerHello (negotiate cipher suite)
    4. Compute shared secret via X25519
    5. Derive handshake traffic keys (cipher-suite-aware)
    6. Receive encrypted handshake messages (EncryptedExtensions, Certificate,
       CertificateVerify, Finished)
    7. Verify certificate chain (if verifyMode != .none)
    8. Verify server Finished
    9. Send client Finished
    10. Derive application traffic keys
    11. Return connection ready for application data -/
def connect (stream : IOStream) (hostname : String) (config : TlsConfig := {}) : IO TlsConnection := do
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
  let clientHelloMsg := LeanTLS.Handshake.buildClientHello params publicKey hostname

  -- Initialize transcript with the ClientHello message
  let mut transcript : Array ByteArray := #[clientHelloMsg]

  sendHandshakeRecord stream clientHelloMsg

  -- -----------------------------------------------------------------------
  -- Step 4: Read ServerHello record
  -- -----------------------------------------------------------------------
  let serverHelloRec ← readRecord stream
  if serverHelloRec.contentType != .handshake then
    throwTlsError (.unexpectedMessage "handshake" s!"content type {repr serverHelloRec.contentType}")

  -- Parse the handshake message
  let (serverHelloHsMsg, _rest) ← match LeanTLS.Handshake.HandshakeMessage.decode serverHelloRec.fragment with
    | some v => pure v
    | none => throwTlsError (.handshakeFailure "failed to decode ServerHello handshake message")

  if serverHelloHsMsg.msgType != .serverHello then
    throwTlsError (.unexpectedMessage "ServerHello" s!"{repr serverHelloHsMsg.msgType}")

  -- Parse ServerHello data
  let serverHelloData ← match LeanTLS.Handshake.parseServerHello serverHelloHsMsg.payload with
    | some v => pure v
    | none => throwTlsError (.handshakeFailure "failed to parse ServerHello payload")

  -- Determine cipher suite
  let selectedSuite ← match LeanTLS.Handshake.CipherSuite.fromUInt16 serverHelloData.cipherSuite with
    | some cs => pure cs
    | none => throwTlsError (.handshakeFailure s!"server selected unsupported cipher suite: {serverHelloData.cipherSuite}")
  let isAES256 := selectedSuite == .aes256gcmSha384

  -- Extract server's X25519 public key
  let serverPublicKey ← match serverHelloData.serverPublicKey with
    | some k => pure k
    | none => throwTlsError (.handshakeFailure "server did not provide X25519 key share")

  -- Add the raw ServerHello handshake bytes to the transcript
  let serverHelloRaw := serverHelloHsMsg.encode
  transcript := transcript.push serverHelloRaw

  -- -----------------------------------------------------------------------
  -- Step 5: Compute shared secret via X25519
  -- -----------------------------------------------------------------------
  let sharedSecret := LeanTLS.Crypto.X25519.x25519 privateKey serverPublicKey

  -- -----------------------------------------------------------------------
  -- Step 6: Derive handshake secrets and traffic keys (cipher-suite-aware)
  -- -----------------------------------------------------------------------
  let transcriptHashCHSH := LeanTLS.Handshake.transcriptHashForSuite selectedSuite transcript

  -- Derive handshake secrets based on cipher suite
  let (chsTraffic, shsTraffic, hsSecret) :=
    if isAES256 then
      let eSecret := LeanTLS.KeySchedule.earlySecretSHA384
      let hsSecret := LeanTLS.KeySchedule.handshakeSecretSHA384 eSecret sharedSecret
      let chsTraffic := LeanTLS.KeySchedule.clientHandshakeTrafficSecretSHA384 hsSecret transcriptHashCHSH
      let shsTraffic := LeanTLS.KeySchedule.serverHandshakeTrafficSecretSHA384 hsSecret transcriptHashCHSH
      (chsTraffic, shsTraffic, hsSecret)
    else
      let eSecret := LeanTLS.KeySchedule.earlySecret
      let hsSecret := LeanTLS.KeySchedule.handshakeSecret eSecret sharedSecret
      let chsTraffic := LeanTLS.KeySchedule.clientHandshakeTrafficSecret hsSecret transcriptHashCHSH
      let shsTraffic := LeanTLS.KeySchedule.serverHandshakeTrafficSecret hsSecret transcriptHashCHSH
      (chsTraffic, shsTraffic, hsSecret)

  let serverHsKeys := if isAES256 then
    LeanTLS.KeySchedule.deriveTrafficKeysSHA384 shsTraffic
  else
    LeanTLS.KeySchedule.deriveTrafficKeys shsTraffic
  let clientHsKeys := if isAES256 then
    LeanTLS.KeySchedule.deriveTrafficKeysSHA384 chsTraffic
  else
    LeanTLS.KeySchedule.deriveTrafficKeys chsTraffic

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
      throwTlsError (.unexpectedMessage "applicationData" s!"content type {repr encRec.contentType}")

    -- Decrypt the record (cipher-suite-aware)
    let (innerContentType, decryptedContent, newDecState) ←
      match LeanTLS.Record.decryptRecordAuto serverDecState encRec with
      | some v => pure v
      | none => throwTlsError (.decryptionFailed "failed to decrypt server handshake record")
    serverDecState := newDecState

    -- The inner content type should be handshake
    if innerContentType != .handshake then
      if innerContentType == .alert then
        let _ ← handleAlert decryptedContent
        throwTlsError (.handshakeFailure "received alert during handshake")
      throwTlsError (.unexpectedMessage "handshake" s!"inner content type {repr innerContentType}")

    -- Parse potentially multiple handshake messages from the decrypted content
    let msgs ← parseHandshakeMessages decryptedContent
    for rawMsg in msgs do
      handshakeMsgBytes := handshakeMsgBytes.push rawMsg

  -- -----------------------------------------------------------------------
  -- Step 9: Process the handshake messages and verify server Finished
  -- -----------------------------------------------------------------------

  -- Validate we have at least 4 messages
  if handshakeMsgBytes.size < 4 then
    throwTlsError (.handshakeFailure "did not receive all expected handshake messages")

  let eeRaw := handshakeMsgBytes.get! 0
  let certRaw := handshakeMsgBytes.get! 1
  let cvRaw := handshakeMsgBytes.get! 2
  let finRaw := handshakeMsgBytes.get! 3

  -- Validate minimum handshake message size (4-byte header)
  if eeRaw.size < 4 then
    throwTlsError (.protocolError "handshake message too short")
  if certRaw.size < 4 then
    throwTlsError (.protocolError "handshake message too short")
  if cvRaw.size < 4 then
    throwTlsError (.protocolError "handshake message too short")
  if finRaw.size < 4 then
    throwTlsError (.protocolError "handshake message too short")

  -- Validate message types
  let eeType ← getHandshakeType eeRaw
  let certType ← getHandshakeType certRaw
  let cvType ← getHandshakeType cvRaw
  let finType ← getHandshakeType finRaw

  if eeType != .encryptedExtensions then
    throwTlsError (.unexpectedMessage "EncryptedExtensions" s!"{repr eeType}")
  if certType != .certificate then
    throwTlsError (.unexpectedMessage "Certificate" s!"{repr certType}")
  if cvType != .certificateVerify then
    throwTlsError (.unexpectedMessage "CertificateVerify" s!"{repr cvType}")
  if finType != .finished then
    throwTlsError (.unexpectedMessage "Finished" s!"{repr finType}")

  -- Certificate verification (CertVerify signature check via existing CertVerify module)
  if config.verifyMode != .none then
    -- The transcript for CertificateVerify verification includes:
    -- ClientHello, ServerHello, EncryptedExtensions, Certificate
    -- (but NOT CertificateVerify itself)
    let transcriptForCV := transcript.push eeRaw |>.push certRaw
    let transcriptHashForCV := LeanTLS.Handshake.transcriptHashForSuite selectedSuite transcriptForCV

    -- Extract the Certificate and CertificateVerify payloads
    let certPayload ← match LeanTLS.Handshake.HandshakeMessage.decode certRaw with
      | some (msg, _) => pure msg.payload
      | none => throwTlsError (.certificateError "failed to decode Certificate message")
    let cvPayload ← match LeanTLS.Handshake.HandshakeMessage.decode cvRaw with
      | some (msg, _) => pure msg.payload
      | none => throwTlsError (.certificateError "failed to decode CertificateVerify message")

    -- Verify CertificateVerify signature (existing single-cert verification)
    match LeanTLS.CertVerify.verifyCertificate certPayload cvPayload transcriptHashForCV hostname with
    | .ok () => pure ()
    | .error e => throwTlsError e

    -- Certificate chain verification via ChainVerify (if trusted certs are provided)
    if config.trustedCerts.size > 0 then
      match LeanTLS.CertVerify.parseCertificateMessage certPayload with
      | some certMsg =>
        match LeanTLS.ChainVerify.verifyCertificateChain certMsg.certificates config.trustedCerts config.currentTime with
        | .ok () => pure ()
        | .error e => throwTlsError e
      | none =>
        throwTlsError (.certificateError "failed to parse Certificate message for chain verification")

  -- Add EncryptedExtensions, Certificate, CertificateVerify to transcript
  -- (Finished is NOT included when computing the hash to verify it)
  transcript := transcript.push eeRaw
  transcript := transcript.push certRaw
  transcript := transcript.push cvRaw

  -- Verify server Finished (cipher-suite-aware)
  let transcriptHashPreFinished := LeanTLS.Handshake.transcriptHashForSuite selectedSuite transcript
  let serverFinKey := if isAES256 then
    LeanTLS.KeySchedule.finishedKeySHA384 shsTraffic
  else
    LeanTLS.KeySchedule.finishedKey shsTraffic

  -- Extract the verify_data from the Finished message payload
  let serverFinVerifyData ← match LeanTLS.Handshake.HandshakeMessage.decode finRaw with
    | some (finMsg, _) => pure finMsg.payload
    | none => throwTlsError (.handshakeFailure "failed to decode server Finished message")

  if !(LeanTLS.Handshake.verifyFinishedForSuite selectedSuite serverFinKey transcriptHashPreFinished serverFinVerifyData) then
    throwTlsError (.handshakeFailure "server Finished verification failed")

  -- Add server Finished to transcript
  transcript := transcript.push finRaw

  -- -----------------------------------------------------------------------
  -- Step 10: Compute and send client Finished
  -- -----------------------------------------------------------------------
  let transcriptHashWithServerFin := LeanTLS.Handshake.transcriptHashForSuite selectedSuite transcript
  let clientFinKey := if isAES256 then
    LeanTLS.KeySchedule.finishedKeySHA384 chsTraffic
  else
    LeanTLS.KeySchedule.finishedKey chsTraffic
  let clientFinVerifyData := LeanTLS.Handshake.buildFinishedVerifyDataForSuite selectedSuite clientFinKey transcriptHashWithServerFin
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

  let mSecret := if isAES256 then
    LeanTLS.KeySchedule.masterSecretSHA384 hsSecret
  else
    LeanTLS.KeySchedule.masterSecret hsSecret
  let catSecret := if isAES256 then
    LeanTLS.KeySchedule.clientAppTrafficSecretSHA384 mSecret appTranscriptHash
  else
    LeanTLS.KeySchedule.clientAppTrafficSecret mSecret appTranscriptHash
  let satSecret := if isAES256 then
    LeanTLS.KeySchedule.serverAppTrafficSecretSHA384 mSecret appTranscriptHash
  else
    LeanTLS.KeySchedule.serverAppTrafficSecret mSecret appTranscriptHash
  let clientAppKeys := if isAES256 then
    LeanTLS.KeySchedule.deriveTrafficKeysSHA384 catSecret
  else
    LeanTLS.KeySchedule.deriveTrafficKeys catSecret
  let serverAppKeys := if isAES256 then
    LeanTLS.KeySchedule.deriveTrafficKeysSHA384 satSecret
  else
    LeanTLS.KeySchedule.deriveTrafficKeys satSecret

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
    isAES256 := isAES256
    clientAppSecret := catSecret
    serverAppSecret := satSecret
  }

  let ref ← IO.mkRef state
  return { ref := ref }

-- ============================================================================
-- Section 10: Application data send
-- ============================================================================

/-- Send application data over the TLS connection. -/
def send (conn : TlsConnection) (data : ByteArray) : IO Unit := do
  let st ← conn.ref.get
  if st.closed then
    throwTlsError .connectionClosed
  match LeanTLS.Record.encryptRecordAuto st.clientEncState .applicationData data with
  | some (encRec, newEncState) =>
    writeRecord st.stream encRec
    conn.ref.modify fun s => { s with clientEncState := newEncState }
  | none => throwTlsError (.internalError "sequence number overflow")

-- ============================================================================
-- Section 11: Application data receive
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
      throwTlsError (.unexpectedMessage "applicationData" s!"content type {repr encRec.contentType}")

    match LeanTLS.Record.decryptRecordAuto st.serverDecState encRec with
    | some (innerCt, content, newDecState) =>
      conn.ref.modify fun s => { s with serverDecState := newDecState }
      resultCt := innerCt
      resultContent := content
      done := true
    | none =>
      throwTlsError (.decryptionFailed "failed to decrypt application data record")
  return (resultCt, resultContent)

/-- Handle a KeyUpdate post-handshake message. Updates the server's decryption
    keys and optionally sends a KeyUpdate response to update our own keys. -/
private def handleKeyUpdate (conn : TlsConnection) (payload : ByteArray) : IO Unit := do
  let request ← match LeanTLS.KeyUpdate.parseKeyUpdate payload with
    | some r => pure r
    | none => throwTlsError (.protocolError "failed to parse KeyUpdate message")
  let st ← conn.ref.get
  -- Update server application traffic secret and derive new keys
  let newServerSecret := if st.isAES256 then
    LeanTLS.KeyUpdate.updateTrafficSecretSHA384 st.serverAppSecret
  else
    LeanTLS.KeyUpdate.updateTrafficSecret st.serverAppSecret
  let newServerKeys := LeanTLS.KeyUpdate.deriveUpdatedTrafficKeys newServerSecret st.isAES256
  let newServerDecState : LeanTLS.Record.RecordEncryptionState := {
    key := newServerKeys.key
    iv := newServerKeys.iv
    seqNum := 0
  }
  conn.ref.modify fun s => { s with
    serverDecState := newServerDecState
    serverAppSecret := newServerSecret
  }
  -- If update_requested, send a KeyUpdate response and update our client keys
  if request == .updateRequested then
    let st2 ← conn.ref.get
    let responseMsg := LeanTLS.KeyUpdate.buildKeyUpdateMessage .updateNotRequested
    match LeanTLS.Record.encryptRecordAuto st2.clientEncState .handshake responseMsg with
    | some (encRec, _newEncState) =>
      writeRecord st2.stream encRec
      -- Update client application traffic secret and derive new keys
      let newClientSecret := if st2.isAES256 then
        LeanTLS.KeyUpdate.updateTrafficSecretSHA384 st2.clientAppSecret
      else
        LeanTLS.KeyUpdate.updateTrafficSecret st2.clientAppSecret
      let newClientKeys := LeanTLS.KeyUpdate.deriveUpdatedTrafficKeys newClientSecret st2.isAES256
      let newClientEncState : LeanTLS.Record.RecordEncryptionState := {
        key := newClientKeys.key
        iv := newClientKeys.iv
        seqNum := 0
      }
      conn.ref.modify fun s => { s with
        clientEncState := newClientEncState
        clientAppSecret := newClientSecret
      }
    | none => throwTlsError (.internalError "sequence number overflow during KeyUpdate response")

/-- Receive application data from the TLS connection.
    Returns `none` if the connection has been closed (e.g., via close_notify).
    If there is buffered data from a previous record, returns that first.
    Otherwise reads and decrypts the next record from the stream.
    Handles KeyUpdate post-handshake messages transparently. -/
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
    -- If the server closes the TCP connection (EOF), treat it as end-of-stream.
    -- This is normal: the server may close the connection after sending close_notify,
    -- or in some cases close without close_notify.
    let recvResult ← try
      let r ← recvOneRecord conn
      pure (some r)
    catch _ =>
      pure none
    match recvResult with
    | none =>
      conn.ref.modify fun s => { s with closed := true }
      finalResult := none
      gotResult := true
    | some (innerCt, content) =>
    match innerCt with
    | .applicationData =>
      if content.size == 0 then
        continue
      let toReturn := Nat.min maxBytes content.size
      let result := content.extract 0 toReturn
      if toReturn < content.size then
        let remaining := content.extract toReturn content.size
        conn.ref.modify fun s => { s with recvBuffer := remaining }
      finalResult := some result
      gotResult := true
    | .alert =>
      match LeanTLS.decodeAlert content with
      | some (.warning, .closeNotify) =>
        conn.ref.modify fun s => { s with closed := true }
        finalResult := none
        gotResult := true
      | some (level, desc) =>
        throwTlsError (.alertReceived level desc)
      | none =>
        if content.size >= 2 then
          throwTlsError (.protocolError s!"unknown alert: level={content.get! 0}, desc={content.get! 1}")
        else
          throwTlsError (.protocolError "malformed alert (too short)")
    | .handshake =>
      -- Handle post-handshake messages
      match LeanTLS.Handshake.HandshakeMessage.decode content with
      | some (hsMsg, _) =>
        if hsMsg.msgType.toByte == LeanTLS.KeyUpdate.keyUpdateHandshakeType then
          handleKeyUpdate conn hsMsg.payload
        else
          -- Other post-handshake messages (e.g., NewSessionTicket) -- skip them
          pure ()
      | none =>
        -- Could not decode handshake message, skip it
        pure ()
      continue
    | .changeCipherSpec =>
      continue
  return finalResult

-- ============================================================================
-- Section 12: Shutdown
-- ============================================================================

/-- Send a close_notify alert and mark the connection as closed. -/
def shutdown (conn : TlsConnection) : IO Unit := do
  let st ← conn.ref.get
  if st.closed then
    return ()
  let alertData := LeanTLS.encodeAlert .warning .closeNotify
  match LeanTLS.Record.encryptRecordAuto st.clientEncState .alert alertData with
  | some (encRec, newEncState) =>
    writeRecord st.stream encRec
    conn.ref.modify fun s => { s with clientEncState := newEncState, closed := true }
  | none => throwTlsError (.internalError "sequence number overflow")

end TlsConnection

end LeanTLS
