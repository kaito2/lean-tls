set_option autoImplicit false

namespace LeanTLS

/-- TLS alert levels per RFC 8446 Section 6. -/
inductive AlertLevel where
  | warning : AlertLevel    -- 1
  | fatal : AlertLevel      -- 2
  deriving BEq, Repr

/-- TLS alert descriptions per RFC 8446 Section 6. -/
inductive AlertDescription where
  | closeNotify : AlertDescription              -- 0
  | unexpectedMessage : AlertDescription        -- 10
  | badRecordMac : AlertDescription             -- 20
  | recordOverflow : AlertDescription           -- 22
  | handshakeFailure : AlertDescription         -- 40
  | badCertificate : AlertDescription           -- 42
  | certificateExpired : AlertDescription       -- 45
  | certificateUnknown : AlertDescription       -- 46
  | illegalParameter : AlertDescription         -- 47
  | decodeError : AlertDescription              -- 50
  | decryptError : AlertDescription             -- 51
  | protocolVersion : AlertDescription          -- 70
  | internalError : AlertDescription            -- 80
  | missingExtension : AlertDescription         -- 109
  | unsupportedExtension : AlertDescription     -- 110
  deriving BEq, Repr

def AlertLevel.toByte : AlertLevel → UInt8
  | .warning => 1
  | .fatal => 2

def AlertLevel.fromByte : UInt8 → Option AlertLevel
  | 1 => some .warning
  | 2 => some .fatal
  | _ => none

def AlertDescription.toByte : AlertDescription → UInt8
  | .closeNotify => 0
  | .unexpectedMessage => 10
  | .badRecordMac => 20
  | .recordOverflow => 22
  | .handshakeFailure => 40
  | .badCertificate => 42
  | .certificateExpired => 45
  | .certificateUnknown => 46
  | .illegalParameter => 47
  | .decodeError => 50
  | .decryptError => 51
  | .protocolVersion => 70
  | .internalError => 80
  | .missingExtension => 109
  | .unsupportedExtension => 110

def AlertDescription.fromByte : UInt8 → Option AlertDescription
  | 0 => some .closeNotify
  | 10 => some .unexpectedMessage
  | 20 => some .badRecordMac
  | 22 => some .recordOverflow
  | 40 => some .handshakeFailure
  | 42 => some .badCertificate
  | 45 => some .certificateExpired
  | 46 => some .certificateUnknown
  | 47 => some .illegalParameter
  | 50 => some .decodeError
  | 51 => some .decryptError
  | 70 => some .protocolVersion
  | 80 => some .internalError
  | 109 => some .missingExtension
  | 110 => some .unsupportedExtension
  | _ => none

/-- TLS error types for structured error handling. -/
inductive TlsError where
  | alertReceived (level : AlertLevel) (desc : AlertDescription) : TlsError
  | alertSendFailed (desc : AlertDescription) (reason : String) : TlsError
  | handshakeFailure (reason : String) : TlsError
  | decryptionFailed (reason : String) : TlsError
  | unexpectedMessage (expected : String) (got : String) : TlsError
  | badRecordMac : TlsError
  | recordOverflow (size : Nat) : TlsError
  | protocolError (reason : String) : TlsError
  | connectionClosed : TlsError
  | certificateError (reason : String) : TlsError
  | internalError (reason : String) : TlsError
  | ioError (msg : String) : TlsError
  deriving Repr

instance : ToString TlsError where
  toString := fun e => match e with
  | .alertReceived level desc => s!"TLS alert received: {repr level} {repr desc}"
  | .alertSendFailed desc reason => s!"TLS alert send failed ({repr desc}): {reason}"
  | .handshakeFailure reason => s!"TLS handshake failure: {reason}"
  | .decryptionFailed reason => s!"TLS decryption failed: {reason}"
  | .unexpectedMessage expected got => s!"TLS unexpected message: expected {expected}, got {got}"
  | .badRecordMac => "TLS bad record MAC"
  | .recordOverflow size => s!"TLS record overflow: {size} bytes"
  | .protocolError reason => s!"TLS protocol error: {reason}"
  | .connectionClosed => "TLS connection closed"
  | .certificateError reason => s!"TLS certificate error: {reason}"
  | .internalError reason => s!"TLS internal error: {reason}"
  | .ioError msg => s!"TLS IO error: {msg}"

/-- Result type alias for TLS operations. -/
abbrev TlsResult (α : Type) := Except TlsError α

/-- Convert a TlsError to an IO.Error for use with IO.throw. -/
def TlsError.toIOError (e : TlsError) : IO.Error :=
  IO.Error.userError (toString e)

/-- Helper to throw a TlsError in IO context. -/
def throwTlsError {m : Type → Type} {α : Type} [Monad m] [MonadExceptOf IO.Error m] (e : TlsError) : m α :=
  throw e.toIOError

/-- Encode an alert as a 2-byte ByteArray (level, description). -/
def encodeAlert (level : AlertLevel) (desc : AlertDescription) : ByteArray :=
  ByteArray.mk #[level.toByte, desc.toByte]

/-- Decode a 2-byte alert. Returns none if bytes are invalid. -/
def decodeAlert (data : ByteArray) : Option (AlertLevel × AlertDescription) :=
  if data.size < 2 then none
  else
    match AlertLevel.fromByte (data.get! 0), AlertDescription.fromByte (data.get! 1) with
    | some level, some desc => some (level, desc)
    | _, _ => none

end LeanTLS
