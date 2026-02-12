# lean-tls

Pure Lean 4 implementation of a TLS 1.3 client library. No C FFI or external dependencies (OpenSSL etc.).

## Scope

- **TLS 1.3 only** (RFC 8446)
- **Client only** (no server implementation)
- **Cipher suite**: `TLS_AES_128_GCM_SHA256`
- **Key exchange**: X25519 (ECDHE)
- **Certificate verification**: skipped (designed as a future extension point)
- **Toolchain**: `leanprover/lean4:v4.16.0`

## Project Structure

```
LeanTLS/
├── Crypto/
│   ├── SHA256.lean      # SHA-256 hash (FIPS 180-4)
│   ├── HMAC.lean        # HMAC-SHA-256 (RFC 2104)
│   ├── HKDF.lean        # HKDF Extract + Expand (RFC 5869)
│   ├── AES.lean         # AES-128 block cipher (FIPS 197)
│   ├── GCM.lean         # AES-128-GCM AEAD (NIST SP 800-38D)
│   └── X25519.lean      # X25519 Diffie-Hellman (RFC 7748)
├── Record.lean          # TLS record layer (encrypt/decrypt)
├── Handshake.lean       # Handshake messages (ClientHello, ServerHello, Finished)
├── KeySchedule.lean     # TLS 1.3 key schedule (RFC 8446 Section 7.1)
└── Connection.lean      # High-level API: connect / send / recv / shutdown
```

## Usage

Add to your `lakefile.lean`:

```lean
require «lean-tls» from git
  "https://github.com/kaito2/lean-tls.git" @ "main"
```

### API

```lean
import LeanTLS

-- Wrap your TCP socket (or any transport) into an IOStream
let stream : LeanTLS.IOStream := {
  read := fun n => do /* read n bytes from socket */
  write := fun data => do /* write data to socket */
}

-- Connect (performs the full TLS 1.3 handshake)
let conn ← LeanTLS.TlsConnection.connect stream "example.com"

-- Send application data
conn.send data

-- Receive application data
match ← conn.recv with
| some data => /* process data */
| none      => /* connection closed */

-- Shutdown
conn.shutdown
```

### Types

```lean
/-- Abstract byte stream wrapping any transport. -/
structure IOStream where
  read  : Nat → IO ByteArray
  write : ByteArray → IO Unit

/-- TLS connection configuration. -/
structure TlsConfig where
  serverName     : String := ""
  skipCertVerify : Bool   := true

/-- High-level TLS connection handle. -/
structure TlsConnection

namespace TlsConnection
  def connect  (stream : IOStream) (hostname : String) (config : TlsConfig := {}) : IO TlsConnection
  def send     (conn : TlsConnection) (data : ByteArray) : IO Unit
  def recv     (conn : TlsConnection) (maxBytes : Nat := 16384) : IO (Option ByteArray)
  def shutdown (conn : TlsConnection) : IO Unit
end TlsConnection
```

## Building

```sh
lake build
```

## Testing

All cryptographic primitives are tested against RFC/NIST official test vectors.

```sh
lake build tests && .lake/build/bin/tests
```

Test coverage:

| Module | Test vectors | Source |
|--------|-------------|--------|
| SHA-256 | 3 | RFC 6234, NIST |
| HMAC-SHA-256 | 3 | RFC 4231 |
| HKDF | 6 (3 Extract + 3 Expand) | RFC 5869 Appendix A |
| AES-128 | 2 | FIPS 197 Appendix B |
| AES-128-GCM | 9 (4 encrypt + 4 decrypt + bad tag) | NIST SP 800-38D |
| X25519 | 2 | RFC 7748 Section 6.1 |
| TLS Record | 16 | Encode/decode, nonce, encrypt/decrypt |
| TLS Handshake | 5 | Roundtrip, ClientHello, transcript, Finished |
| Key Schedule | 9 | RFC 8448 |

## References

- [RFC 8446](https://datatracker.ietf.org/doc/html/rfc8446) - TLS 1.3
- [RFC 7748](https://datatracker.ietf.org/doc/html/rfc7748) - X25519
- [RFC 5869](https://datatracker.ietf.org/doc/html/rfc5869) - HKDF
- [RFC 2104](https://datatracker.ietf.org/doc/html/rfc2104) - HMAC
- [FIPS 197](https://csrc.nist.gov/publications/detail/fips/197/final) - AES
- [NIST SP 800-38D](https://csrc.nist.gov/publications/detail/sp/800-38d/final) - GCM
- [RFC 8448](https://datatracker.ietf.org/doc/html/rfc8448) - TLS 1.3 test vectors

## License

MIT
