import LeanTLS.Crypto.HKDF
import LeanTLS.Crypto.SHA256
import LeanTLS.Crypto.SHA384
import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.KeySchedule

/-!
# TLS 1.3 Key Schedule (RFC 8446 Section 7.1)

Pure Lean 4 implementation of the TLS 1.3 key schedule using SHA-256 / HKDF-SHA-256.
This module provides the key derivation chain as specified in RFC 8446, including:
- HKDF-Expand-Label
- Derive-Secret
- Early / Handshake / Master secret computation
- Traffic key and IV derivation
-/

-- ============================================================================
-- Section 1: Constants
-- ============================================================================

/-- SHA-256 output length in bytes. -/
private def hashLen : Nat := 32

/-- AES-128-GCM key length in bytes. -/
private def aes128KeyLen : Nat := 16

/-- AES-128-GCM IV length in bytes. -/
private def aes128IVLen : Nat := 12

/-- 32 zero bytes, used as IKM when no PSK or as the zero input. -/
private def zeroKey : ByteArray :=
  ByteArray.mk (Array.replicate hashLen 0)

-- ============================================================================
-- Section 2: HKDF-Expand-Label (RFC 8446 Section 7.1)
-- ============================================================================

/-- HKDF-Expand-Label(Secret, Label, Context, Length) = HKDF-Expand(Secret, HkdfLabel, Length)

    where HkdfLabel is encoded as:
      uint16 length        -- 2 bytes, big-endian
      opaque label<7..255> -- 1-byte length prefix, then "tls13 " + Label
      opaque context<0..255> -- 1-byte length prefix, then Context bytes -/
def hkdfExpandLabel (secret : ByteArray) (label : String) (context : ByteArray) (length : Nat) : ByteArray :=
  let fullLabel := ("tls13 " ++ label).toUTF8
  -- Build HkdfLabel
  let hkdfLabel := ByteArray.emptyWithCapacity (2 + 1 + fullLabel.size + 1 + context.size)
  -- uint16 length (big-endian)
  let hkdfLabel := hkdfLabel.push (length / 256).toUInt8
  let hkdfLabel := hkdfLabel.push (length % 256).toUInt8
  -- opaque label<7..255> with 1-byte length prefix
  let hkdfLabel := hkdfLabel.push fullLabel.size.toUInt8
  let hkdfLabel := hkdfLabel ++ fullLabel
  -- opaque context<0..255> with 1-byte length prefix
  let hkdfLabel := hkdfLabel.push context.size.toUInt8
  let hkdfLabel := hkdfLabel ++ context
  LeanTLS.Crypto.HKDF.expand secret hkdfLabel length

-- ============================================================================
-- Section 4: Derive-Secret (RFC 8446 Section 7.1)
-- ============================================================================

/-- Derive-Secret(Secret, Label, Messages) =
    HKDF-Expand-Label(Secret, Label, Transcript-Hash(Messages), Hash.length)

    The `transcriptHash` parameter is the hash of the transcript messages,
    already computed by the caller. Hash.length = 32 for SHA-256. -/
def deriveSecret (secret : ByteArray) (label : String) (transcriptHash : ByteArray) : ByteArray :=
  hkdfExpandLabel secret label transcriptHash hashLen

-- ============================================================================
-- Section 5: Key Schedule derivation chain (RFC 8446 Section 7.1)
-- ============================================================================

/-- Compute the Early Secret from a PSK (or zero for no PSK).
    early_secret = HKDF-Extract(salt=0, ikm=PSK_or_zero)

    When no PSK is available, IKM defaults to 32 zero bytes.
    Salt of empty ByteArray causes HKDF-Extract to use 32 zero bytes internally. -/
def earlySecret (psk : ByteArray := zeroKey) : ByteArray :=
  LeanTLS.Crypto.HKDF.extract ByteArray.empty psk

/-- Derive the Handshake Secret from the shared secret.
    1. derived_secret = Derive-Secret(early_secret, "derived", empty_hash)
    2. handshake_secret = HKDF-Extract(salt=derived_secret, ikm=shared_secret)

    The empty_hash is SHA-256("") = e3b0c442... -/
def handshakeSecret (earlySecret : ByteArray) (sharedSecret : ByteArray) : ByteArray :=
  let emptyHash := LeanTLS.Crypto.SHA256.hash ByteArray.empty
  let derived := deriveSecret earlySecret "derived" emptyHash
  LeanTLS.Crypto.HKDF.extract derived sharedSecret

/-- Derive client handshake traffic secret.
    client_handshake_traffic_secret =
      Derive-Secret(hs_secret, "c hs traffic", transcript_hash)

    transcript_hash is the hash of ClientHello...ServerHello. -/
def clientHandshakeTrafficSecret (hsSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecret hsSecret "c hs traffic" transcriptHash

/-- Derive server handshake traffic secret.
    server_handshake_traffic_secret =
      Derive-Secret(hs_secret, "s hs traffic", transcript_hash)

    transcript_hash is the hash of ClientHello...ServerHello. -/
def serverHandshakeTrafficSecret (hsSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecret hsSecret "s hs traffic" transcriptHash

/-- Derive the Master Secret from the Handshake Secret.
    1. derived_secret = Derive-Secret(hs_secret, "derived", empty_hash)
    2. master_secret = HKDF-Extract(salt=derived_secret, ikm=0^32) -/
def masterSecret (hsSecret : ByteArray) : ByteArray :=
  let emptyHash := LeanTLS.Crypto.SHA256.hash ByteArray.empty
  let derived := deriveSecret hsSecret "derived" emptyHash
  LeanTLS.Crypto.HKDF.extract derived zeroKey

/-- Derive client application traffic secret.
    client_application_traffic_secret_0 =
      Derive-Secret(master_secret, "c ap traffic", transcript_hash)

    transcript_hash is the hash of ClientHello...server Finished. -/
def clientAppTrafficSecret (masterSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecret masterSecret "c ap traffic" transcriptHash

/-- Derive server application traffic secret.
    server_application_traffic_secret_0 =
      Derive-Secret(master_secret, "s ap traffic", transcript_hash)

    transcript_hash is the hash of ClientHello...server Finished. -/
def serverAppTrafficSecret (masterSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecret masterSecret "s ap traffic" transcriptHash

-- ============================================================================
-- Section 6: Traffic key derivation
-- ============================================================================

/-- Derive the write key from a traffic secret.
    key = HKDF-Expand-Label(Secret, "key", "", key_length)
    For AES-128-GCM: key_length = 16 -/
def trafficKey (secret : ByteArray) : ByteArray :=
  hkdfExpandLabel secret "key" ByteArray.empty aes128KeyLen

/-- Derive the write IV from a traffic secret.
    iv = HKDF-Expand-Label(Secret, "iv", "", iv_length)
    For AES-128-GCM: iv_length = 12 -/
def trafficIV (secret : ByteArray) : ByteArray :=
  hkdfExpandLabel secret "iv" ByteArray.empty aes128IVLen

/-- Derive the finished key from a base key.
    finished_key = HKDF-Expand-Label(BaseKey, "finished", "", Hash.length)
    Hash.length = 32 for SHA-256. -/
def finishedKey (baseKey : ByteArray) : ByteArray :=
  hkdfExpandLabel baseKey "finished" ByteArray.empty hashLen

-- ============================================================================
-- Section 7: Convenience structure
-- ============================================================================

/-- A pair of (key, iv) for use with a symmetric AEAD cipher. -/
structure TrafficKeys where
  key : ByteArray  -- 16 bytes for AES-128-GCM
  iv  : ByteArray  -- 12 bytes for AES-128-GCM

/-- Derive the traffic key and IV from a traffic secret. -/
def deriveTrafficKeys (secret : ByteArray) : TrafficKeys :=
  { key := trafficKey secret, iv := trafficIV secret }

-- ============================================================================
-- Section 8: SHA-384 Key Schedule (for TLS_AES_256_GCM_SHA384)
-- ============================================================================

/-- SHA-384 output length in bytes. -/
private def hashLen384 : Nat := 48

/-- AES-256-GCM key length in bytes. -/
private def aes256KeyLen : Nat := 32

/-- 48 zero bytes, used as IKM when no PSK or as the zero input for SHA-384. -/
private def zeroKey384 : ByteArray :=
  ByteArray.mk (Array.replicate hashLen384 0)

/-- HKDF-Expand-Label using SHA-384. -/
def hkdfExpandLabelSHA384 (secret : ByteArray) (label : String) (context : ByteArray) (length : Nat) : ByteArray :=
  let fullLabel := ("tls13 " ++ label).toUTF8
  let hkdfLabel := ByteArray.emptyWithCapacity (2 + 1 + fullLabel.size + 1 + context.size)
  let hkdfLabel := hkdfLabel.push (length / 256).toUInt8
  let hkdfLabel := hkdfLabel.push (length % 256).toUInt8
  let hkdfLabel := hkdfLabel.push fullLabel.size.toUInt8
  let hkdfLabel := hkdfLabel ++ fullLabel
  let hkdfLabel := hkdfLabel.push context.size.toUInt8
  let hkdfLabel := hkdfLabel ++ context
  LeanTLS.Crypto.HKDF.expandSHA384 secret hkdfLabel length

/-- Derive-Secret using SHA-384. -/
def deriveSecretSHA384 (secret : ByteArray) (label : String) (transcriptHash : ByteArray) : ByteArray :=
  hkdfExpandLabelSHA384 secret label transcriptHash hashLen384

/-- Compute the Early Secret using SHA-384. -/
def earlySecretSHA384 (psk : ByteArray := zeroKey384) : ByteArray :=
  LeanTLS.Crypto.HKDF.extractSHA384 ByteArray.empty psk

/-- Derive the Handshake Secret using SHA-384. -/
def handshakeSecretSHA384 (earlySecret : ByteArray) (sharedSecret : ByteArray) : ByteArray :=
  let emptyHash := LeanTLS.Crypto.SHA384.hash ByteArray.empty
  let derived := deriveSecretSHA384 earlySecret "derived" emptyHash
  LeanTLS.Crypto.HKDF.extractSHA384 derived sharedSecret

/-- Derive client handshake traffic secret using SHA-384. -/
def clientHandshakeTrafficSecretSHA384 (hsSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecretSHA384 hsSecret "c hs traffic" transcriptHash

/-- Derive server handshake traffic secret using SHA-384. -/
def serverHandshakeTrafficSecretSHA384 (hsSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecretSHA384 hsSecret "s hs traffic" transcriptHash

/-- Derive the Master Secret using SHA-384. -/
def masterSecretSHA384 (hsSecret : ByteArray) : ByteArray :=
  let emptyHash := LeanTLS.Crypto.SHA384.hash ByteArray.empty
  let derived := deriveSecretSHA384 hsSecret "derived" emptyHash
  LeanTLS.Crypto.HKDF.extractSHA384 derived zeroKey384

/-- Derive client application traffic secret using SHA-384. -/
def clientAppTrafficSecretSHA384 (masterSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecretSHA384 masterSecret "c ap traffic" transcriptHash

/-- Derive server application traffic secret using SHA-384. -/
def serverAppTrafficSecretSHA384 (masterSecret : ByteArray) (transcriptHash : ByteArray) : ByteArray :=
  deriveSecretSHA384 masterSecret "s ap traffic" transcriptHash

/-- Derive AES-256-GCM traffic key from a traffic secret using SHA-384. -/
def trafficKeySHA384 (secret : ByteArray) : ByteArray :=
  hkdfExpandLabelSHA384 secret "key" ByteArray.empty aes256KeyLen

/-- Derive AES-256-GCM traffic IV from a traffic secret using SHA-384. -/
def trafficIVSHA384 (secret : ByteArray) : ByteArray :=
  hkdfExpandLabelSHA384 secret "iv" ByteArray.empty aes128IVLen

/-- Derive the finished key from a base key using SHA-384. -/
def finishedKeySHA384 (baseKey : ByteArray) : ByteArray :=
  hkdfExpandLabelSHA384 baseKey "finished" ByteArray.empty hashLen384

/-- Derive the AES-256-GCM traffic key and IV from a traffic secret. -/
def deriveTrafficKeysSHA384 (secret : ByteArray) : TrafficKeys :=
  { key := trafficKeySHA384 secret, iv := trafficIVSHA384 secret }

-- ============================================================================
-- Section 9: Test vectors (RFC 8448 - Example Handshake Traces for TLS 1.3)
-- ============================================================================

/-- Run TLS 1.3 Key Schedule test vectors from RFC 8448. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- -----------------------------------------------------------------------
  -- Test 1: Early Secret (no PSK, IKM = 32 zero bytes, salt = empty)
  -- -----------------------------------------------------------------------
  let expectedEarlySecret := "33ad0a1c607ec03b09e6cd9893680ce210adf300aa1f2660e1b22e10f170f92a"
  let es := earlySecret
  let resultES := LeanTLS.Crypto.SHA256.toHex es
  if resultES == expectedEarlySecret then
    IO.println "  KeySchedule test 1 (early secret): PASSED"
  else
    IO.println "  KeySchedule test 1 (early secret): FAILED"
    IO.println s!"    expected: {expectedEarlySecret}"
    IO.println s!"    got:      {resultES}"
    allPassed := false

  -- -----------------------------------------------------------------------
  -- Test 2: Derived Secret for handshake
  -- Derive-Secret(early_secret, "derived", SHA-256(""))
  -- -----------------------------------------------------------------------
  let expectedDerived := "6f2615a108c702c5678f54fc9dbab69716c076189c48250cebeac3576c3611ba"
  let emptyHash := LeanTLS.Crypto.SHA256.hash ByteArray.empty
  let derived := deriveSecret es "derived" emptyHash
  let resultDerived := LeanTLS.Crypto.SHA256.toHex derived
  if resultDerived == expectedDerived then
    IO.println "  KeySchedule test 2 (derived secret): PASSED"
  else
    IO.println "  KeySchedule test 2 (derived secret): FAILED"
    IO.println s!"    expected: {expectedDerived}"
    IO.println s!"    got:      {resultDerived}"
    allPassed := false

  -- -----------------------------------------------------------------------
  -- Test 3: Handshake Secret
  -- shared_secret from X25519 (RFC 8448 Simple 1-RTT Handshake)
  -- -----------------------------------------------------------------------
  let sharedSecret := LeanTLS.Utils.hexToBytes "8bd4054fb55b9d63fdfbacf9f04b9f0d35e6d63f537563efd46272900f89492d"
  let expectedHS := "1dc826e93606aa6fdc0aadc12f741b01046aa6b99f691ed221a9f0ca043fbeac"
  let hs := handshakeSecret es sharedSecret
  let resultHS := LeanTLS.Crypto.SHA256.toHex hs
  if resultHS == expectedHS then
    IO.println "  KeySchedule test 3 (handshake secret): PASSED"
  else
    IO.println "  KeySchedule test 3 (handshake secret): FAILED"
    IO.println s!"    expected: {expectedHS}"
    IO.println s!"    got:      {resultHS}"
    allPassed := false

  -- -----------------------------------------------------------------------
  -- Test 4: Client and Server handshake traffic secrets
  -- transcript_hash = hash of ClientHello...ServerHello from RFC 8448
  -- -----------------------------------------------------------------------
  let transcriptHashHS := LeanTLS.Utils.hexToBytes "860c06edc07858ee8e78f0e7428c58edd6b43f2ca3e6e95f02ed063cf0e1cad8"

  let expectedCHTS := "b3eddb126e067f35a780b3abf45e2d8f3b1a950738f52e9600746a0e27a55a21"
  let chts := clientHandshakeTrafficSecret hs transcriptHashHS
  let resultCHTS := LeanTLS.Crypto.SHA256.toHex chts
  if resultCHTS == expectedCHTS then
    IO.println "  KeySchedule test 4a (client HS traffic secret): PASSED"
  else
    IO.println "  KeySchedule test 4a (client HS traffic secret): FAILED"
    IO.println s!"    expected: {expectedCHTS}"
    IO.println s!"    got:      {resultCHTS}"
    allPassed := false

  let expectedSHTS := "b67b7d690cc16c4e75e54213cb2d37b4e9c912bcded9105d42befd59d391ad38"
  let shts := serverHandshakeTrafficSecret hs transcriptHashHS
  let resultSHTS := LeanTLS.Crypto.SHA256.toHex shts
  if resultSHTS == expectedSHTS then
    IO.println "  KeySchedule test 4b (server HS traffic secret): PASSED"
  else
    IO.println "  KeySchedule test 4b (server HS traffic secret): FAILED"
    IO.println s!"    expected: {expectedSHTS}"
    IO.println s!"    got:      {resultSHTS}"
    allPassed := false

  -- -----------------------------------------------------------------------
  -- Test 5: Server handshake traffic key and IV
  -- -----------------------------------------------------------------------
  let expectedServerKey := "3fce516009c21727d0f2e4e86ee403bc"
  let expectedServerIV := "5d313eb2671276ee13000b30"
  let serverKeys := deriveTrafficKeys shts
  let resultServerKey := LeanTLS.Crypto.SHA256.toHex serverKeys.key
  let resultServerIV := LeanTLS.Crypto.SHA256.toHex serverKeys.iv
  if resultServerKey == expectedServerKey then
    IO.println "  KeySchedule test 5a (server write key): PASSED"
  else
    IO.println "  KeySchedule test 5a (server write key): FAILED"
    IO.println s!"    expected: {expectedServerKey}"
    IO.println s!"    got:      {resultServerKey}"
    allPassed := false
  if resultServerIV == expectedServerIV then
    IO.println "  KeySchedule test 5b (server write IV): PASSED"
  else
    IO.println "  KeySchedule test 5b (server write IV): FAILED"
    IO.println s!"    expected: {expectedServerIV}"
    IO.println s!"    got:      {resultServerIV}"
    allPassed := false

  -- -----------------------------------------------------------------------
  -- Test 6: Client handshake traffic key and IV
  -- -----------------------------------------------------------------------
  let expectedClientKey := "dbfaa693d1762c5b666af5d950258d01"
  let expectedClientIV := "5bd3c71b836e0b76bb73265f"
  let clientKeys := deriveTrafficKeys chts
  let resultClientKey := LeanTLS.Crypto.SHA256.toHex clientKeys.key
  let resultClientIV := LeanTLS.Crypto.SHA256.toHex clientKeys.iv
  if resultClientKey == expectedClientKey then
    IO.println "  KeySchedule test 6a (client write key): PASSED"
  else
    IO.println "  KeySchedule test 6a (client write key): FAILED"
    IO.println s!"    expected: {expectedClientKey}"
    IO.println s!"    got:      {resultClientKey}"
    allPassed := false
  if resultClientIV == expectedClientIV then
    IO.println "  KeySchedule test 6b (client write IV): PASSED"
  else
    IO.println "  KeySchedule test 6b (client write IV): FAILED"
    IO.println s!"    expected: {expectedClientIV}"
    IO.println s!"    got:      {resultClientIV}"
    allPassed := false

  return allPassed

end LeanTLS.KeySchedule
