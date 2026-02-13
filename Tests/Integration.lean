import LeanTLS

/-!
# TLS 1.3 Integration Test

Connects to a real TLS 1.3 server (example.com:443) using a raw TCP socket
via netcat (`nc`), performs a full TLS 1.3 handshake, sends an HTTP GET
request, reads the response, and verifies we get a valid HTTP reply.

## Prerequisites
- `nc` (netcat) must be available on the system PATH
- Network access to example.com:443

## Usage
```
lake build integration-test && .lake/build/bin/integration-test
```
-/

set_option autoImplicit false

/-- Create a LeanTLS.IOStream backed by a child process (nc) connected to the
    given host and port via raw TCP. Returns the IOStream and a cleanup action
    that kills the child process. -/
def mkNetcatStream (host : String) (port : String)
    : IO (LeanTLS.IOStream × IO Unit) := do
  let child ← IO.Process.spawn {
    cmd := "nc"
    args := #["-w", "10", host, port]
    stdin := .piped
    stdout := .piped
    stderr := .piped
  }
  let stream : LeanTLS.IOStream := {
    read := fun n => child.stdout.read n.toUSize
    write := fun data => do
      child.stdin.write data
      child.stdin.flush
  }
  let cleanup : IO Unit := do
    let _ ← child.kill
  return (stream, cleanup)

def main : IO Unit := do
  IO.println "=== TLS 1.3 Integration Test ==="
  IO.println ""

  -- Use mozilla.org which has an RSA certificate (supports RSA-PSS verification)
  let host := "mozilla.org"
  let port := "443"

  -- Step 1: Establish raw TCP connection via netcat
  IO.println s!"[1] Connecting to {host}:{port} via nc ..."
  let (stream, cleanup) ← mkNetcatStream host port
  IO.println s!"[1] TCP connection established."

  -- Step 2: Perform TLS 1.3 handshake WITH certificate verification
  IO.println "[2] Starting TLS 1.3 handshake (certificate verification ENABLED) ..."
  let conn ← LeanTLS.TlsConnection.connect stream host { verifyMode := .verifyFull }
  IO.println "[2] TLS 1.3 handshake with certificate verification completed successfully!"

  -- Step 3: Send HTTP GET request
  let httpRequest := s!"GET / HTTP/1.1\r\nHost: {host}\r\nConnection: close\r\n\r\n"
  IO.println s!"[3] Sending HTTP request ({httpRequest.length} bytes) ..."
  LeanTLS.TlsConnection.send conn httpRequest.toUTF8
  IO.println "[3] HTTP request sent."

  -- Step 4: Receive HTTP response
  IO.println "[4] Reading HTTP response ..."
  let mut responseData := ByteArray.empty
  let mut done := false
  while !done do
    match ← LeanTLS.TlsConnection.recv conn with
    | some chunk =>
      responseData := responseData ++ chunk
    | none =>
      done := true

  let responseStr := String.fromUTF8! responseData
  IO.println s!"[4] Received {responseData.size} bytes of response data."

  -- Step 5: Verify we got a valid HTTP response
  let valid := responseStr.startsWith "HTTP/1.1" || responseStr.startsWith "HTTP/1.0"
  if valid then
    -- Print first line of the response
    let firstLine := (responseStr.splitOn "\r\n").head!
    IO.println s!"[5] Response starts with valid HTTP status line: {firstLine}"
  else
    let preview := responseStr.extract ⟨0⟩ ⟨(Nat.min 80 responseStr.length)⟩
    IO.eprintln s!"[FAIL] Response does not start with HTTP/1.x: {preview}"
    cleanup
    IO.Process.exit 1

  -- Step 6: Shutdown TLS connection
  IO.println "[6] Shutting down TLS connection ..."
  -- Ignore errors on shutdown since the server may have already closed with close_notify
  try
    LeanTLS.TlsConnection.shutdown conn
  catch _ =>
    pure ()
  IO.println "[6] TLS connection shut down."

  -- Cleanup the netcat process
  cleanup

  IO.println ""
  IO.println "=== Integration test PASSED ==="
