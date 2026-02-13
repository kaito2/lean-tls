import LeanTLS.KeySchedule
import LeanTLS.Crypto.HKDF
import LeanTLS.Crypto.SHA256
import LeanTLS.Crypto.SHA384
import LeanTLS.Handshake
import LeanTLS.Record
import LeanTLS.Errors
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.KeyUpdate

/-!
# TLS 1.3 KeyUpdate (RFC 8446 Section 4.6.3)

Pure Lean 4 implementation of the TLS 1.3 KeyUpdate post-handshake message.

KeyUpdate allows either side of a connection to update its sending
cryptographic keys. The key update mechanism derives a new
application_traffic_secret from the current one using HKDF-Expand-Label
with the label "traffic upd".

## Wire Format

The KeyUpdate message has handshake type 24 (0x18) and a 1-byte body:

    enum { update_not_requested(0), update_requested(1), (255) } KeyUpdateRequest;

    struct { KeyUpdateRequest request_update; } KeyUpdate;
-/

-- ============================================================================
-- Section 1: KeyUpdateRequest type
-- ============================================================================

/-- KeyUpdate request values per RFC 8446 Section 4.6.3. -/
inductive KeyUpdateRequest where
  | updateNotRequested : KeyUpdateRequest  -- 0
  | updateRequested : KeyUpdateRequest     -- 1
  deriving BEq, Repr

/-- Convert a KeyUpdateRequest to its wire byte value. -/
def KeyUpdateRequest.toByte (r : KeyUpdateRequest) : UInt8 :=
  match r with
  | .updateNotRequested => 0
  | .updateRequested    => 1

/-- Parse a byte into a KeyUpdateRequest, or `none` if unrecognized. -/
def KeyUpdateRequest.fromByte (b : UInt8) : Option KeyUpdateRequest :=
  match b.toNat with
  | 0 => some .updateNotRequested
  | 1 => some .updateRequested
  | _ => none

-- ============================================================================
-- Section 2: Message parsing and serialization
-- ============================================================================

/-- The handshake type byte for KeyUpdate (24 = 0x18). -/
def keyUpdateHandshakeType : UInt8 := 24

/-- Parse a KeyUpdate message from a handshake payload.
    The payload must be exactly 1 byte containing the KeyUpdateRequest value. -/
def parseKeyUpdate (payload : ByteArray) : Option KeyUpdateRequest :=
  if payload.size != 1 then none
  else KeyUpdateRequest.fromByte (payload.get! 0)

/-- Serialize a KeyUpdate message as a complete handshake message.
    Total output: 5 bytes (4-byte header + 1-byte payload). -/
def buildKeyUpdateMessage (request : KeyUpdateRequest) : ByteArray := Id.run do
  let mut msg := ByteArray.emptyWithCapacity 5
  msg := msg.push keyUpdateHandshakeType
  msg := msg.push 0x00
  msg := msg.push 0x00
  msg := msg.push 0x01
  msg := msg.push request.toByte
  return msg

-- ============================================================================
-- Section 3: Traffic secret update (RFC 8446 Section 7.2)
-- ============================================================================

/-- Update an application traffic secret using SHA-256 (for TLS_AES_128_GCM_SHA256).
    application_traffic_secret_N+1 =
      HKDF-Expand-Label(application_traffic_secret_N, "traffic upd", "", 32) -/
def updateTrafficSecret (currentSecret : ByteArray) : ByteArray :=
  LeanTLS.KeySchedule.hkdfExpandLabel currentSecret "traffic upd" ByteArray.empty 32

/-- Update an application traffic secret using SHA-384 (for TLS_AES_256_GCM_SHA384).
    application_traffic_secret_N+1 =
      HKDF-Expand-Label(application_traffic_secret_N, "traffic upd", "", 48) -/
def updateTrafficSecretSHA384 (currentSecret : ByteArray) : ByteArray :=
  let fullLabel := ("tls13 " ++ "traffic upd").toUTF8
  let hkdfLabel := ByteArray.emptyWithCapacity (2 + 1 + fullLabel.size + 1)
  let hkdfLabel := hkdfLabel.push (48 / 256).toUInt8
  let hkdfLabel := hkdfLabel.push (48 % 256).toUInt8
  let hkdfLabel := hkdfLabel.push fullLabel.size.toUInt8
  let hkdfLabel := hkdfLabel ++ fullLabel
  let hkdfLabel := hkdfLabel.push 0
  LeanTLS.Crypto.HKDF.expandSHA384 currentSecret hkdfLabel 48

-- ============================================================================
-- Section 4: Derive updated traffic keys
-- ============================================================================

/-- Helper: HKDF-Expand-Label for SHA-384. -/
private def hkdfExpandLabelSHA384 (secret : ByteArray) (label : String) (context : ByteArray) (length : Nat) : ByteArray :=
  let fullLabel := ("tls13 " ++ label).toUTF8
  let hkdfLabel := ByteArray.emptyWithCapacity (2 + 1 + fullLabel.size + 1 + context.size)
  let hkdfLabel := hkdfLabel.push (length / 256).toUInt8
  let hkdfLabel := hkdfLabel.push (length % 256).toUInt8
  let hkdfLabel := hkdfLabel.push fullLabel.size.toUInt8
  let hkdfLabel := hkdfLabel ++ fullLabel
  let hkdfLabel := hkdfLabel.push context.size.toUInt8
  let hkdfLabel := hkdfLabel ++ context
  LeanTLS.Crypto.HKDF.expandSHA384 secret hkdfLabel length

/-- Derive new traffic keys from an updated application traffic secret. -/
def deriveUpdatedTrafficKeys (newSecret : ByteArray) (isAES256 : Bool) : LeanTLS.KeySchedule.TrafficKeys :=
  if isAES256 then
    { key := hkdfExpandLabelSHA384 newSecret "key" ByteArray.empty 32
    , iv := hkdfExpandLabelSHA384 newSecret "iv" ByteArray.empty 12 }
  else
    LeanTLS.KeySchedule.deriveTrafficKeys newSecret

-- ============================================================================
-- Section 5: Tests
-- ============================================================================

/-- Run all KeyUpdate module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  IO.println "--- KeyUpdate Tests ---"

  -- Test 1: Roundtrip
  IO.println "  KeyUpdate test 1 (serialize/deserialize roundtrip):"
  let msg0 := buildKeyUpdateMessage .updateNotRequested
  let msg1 := buildKeyUpdateMessage .updateRequested
  let mut test1Ok := true
  if msg0.size != 5 || msg0.get! 0 != 24 then test1Ok := false
  if msg1.size != 5 || msg1.get! 0 != 24 then test1Ok := false
  match parseKeyUpdate (msg0.extract 4 5) with
  | some req => if req != .updateNotRequested then test1Ok := false
  | none => test1Ok := false
  match parseKeyUpdate (msg1.extract 4 5) with
  | some req => if req != .updateRequested then test1Ok := false
  | none => test1Ok := false
  if test1Ok then IO.println "    PASSED"
  else IO.println "    FAILED"; allPassed := false

  -- Test 2: Wire format
  IO.println "  KeyUpdate test 2 (wire format):"
  if msg0 == ByteArray.mk #[0x18, 0x00, 0x00, 0x01, 0x00] &&
     msg1 == ByteArray.mk #[0x18, 0x00, 0x00, 0x01, 0x01] then
    IO.println "    PASSED"
  else
    IO.println "    FAILED"
    allPassed := false

  -- Test 3: Traffic secret update SHA-256
  IO.println "  KeyUpdate test 3 (updateTrafficSecret SHA-256):"
  let testSecret := LeanTLS.Utils.hexToBytes "b67b7d690cc16c4e75e54213cb2d37b4e9c912bcded9105d42befd59d391ad38"
  let newSecret := updateTrafficSecret testSecret
  if newSecret.size == 32 && newSecret != testSecret && newSecret == updateTrafficSecret testSecret then
    IO.println "    PASSED"
  else
    IO.println "    FAILED"
    allPassed := false

  -- Test 4: Traffic secret update SHA-384
  IO.println "  KeyUpdate test 4 (updateTrafficSecretSHA384):"
  let testSecret384 := LeanTLS.Utils.hexToBytes "b67b7d690cc16c4e75e54213cb2d37b4e9c912bcded9105d42befd59d391ad38aabbccdd00112233eeff445566778899"
  let newSecret384 := updateTrafficSecretSHA384 testSecret384
  if newSecret384.size == 48 && newSecret384 != testSecret384 then
    IO.println "    PASSED"
  else
    IO.println "    FAILED"
    allPassed := false

  -- Test 5: Invalid payloads
  IO.println "  KeyUpdate test 5 (invalid payloads):"
  let mut test5Ok := true
  if (parseKeyUpdate ByteArray.empty).isSome then test5Ok := false
  if (parseKeyUpdate (ByteArray.mk #[0x00, 0x01])).isSome then test5Ok := false
  if (parseKeyUpdate (ByteArray.mk #[0x02])).isSome then test5Ok := false
  if test5Ok then IO.println "    PASSED"
  else IO.println "    FAILED"; allPassed := false

  -- Test 6: Derived traffic keys sizes
  IO.println "  KeyUpdate test 6 (deriveUpdatedTrafficKeys sizes):"
  let keys128 := deriveUpdatedTrafficKeys newSecret false
  let keys256 := deriveUpdatedTrafficKeys newSecret384 true
  if keys128.key.size == 16 && keys128.iv.size == 12 &&
     keys256.key.size == 32 && keys256.iv.size == 12 then
    IO.println "    PASSED"
  else
    IO.println "    FAILED"
    allPassed := false

  -- Test 7: Chained updates produce distinct secrets
  IO.println "  KeyUpdate test 7 (chained key updates):"
  let s1 := updateTrafficSecret testSecret
  let s2 := updateTrafficSecret s1
  let s3 := updateTrafficSecret s2
  if testSecret != s1 && s1 != s2 && s2 != s3 && testSecret != s2 then
    IO.println "    PASSED"
  else
    IO.println "    FAILED"
    allPassed := false

  if allPassed then
    IO.println "All KeyUpdate tests passed!"
  else
    IO.println "Some KeyUpdate tests FAILED!"

  return allPassed

end LeanTLS.KeyUpdate
