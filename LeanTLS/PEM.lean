import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.PEM

/-!
# PEM Format Parser (RFC 7468)

Pure Lean 4 implementation of PEM (Privacy-Enhanced Mail) format parsing.
Supports:
- Base64 decoding with the standard alphabet (A-Z, a-z, 0-9, +, /)
- PEM block parsing with BEGIN/END markers
- Multiple blocks per file (for CA bundle files)
- Certificate-specific helpers for extracting DER-encoded certificates
-/

-- ============================================================================
-- Section 1: Base64 Decoding
-- ============================================================================

/-- Convert a base64 character to its 6-bit numeric value (0-63).
    Returns `none` for characters not in the base64 alphabet. -/
private def base64CharToVal (c : Char) : Option UInt8 :=
  if 'A' ≤ c ∧ c ≤ 'Z' then some (c.toNat - 'A'.toNat).toUInt8
  else if 'a' ≤ c ∧ c ≤ 'z' then some (c.toNat - 'a'.toNat + 26).toUInt8
  else if '0' ≤ c ∧ c ≤ '9' then some (c.toNat - '0'.toNat + 52).toUInt8
  else if c == '+' then some 62
  else if c == '/' then some 63
  else none

/-- Decode a base64-encoded string to a ByteArray.
    Ignores whitespace (spaces, newlines, carriage returns, tabs).
    Handles `=` padding. Returns `none` if the input contains invalid
    base64 characters. -/
def base64Decode (input : String) : Option ByteArray :=
  -- Strip whitespace and collect only base64 chars and padding
  let chars := input.toList.filter fun c =>
    c != ' ' && c != '\n' && c != '\r' && c != '\t'
  -- Separate padding from data characters
  let dataChars := chars.filter (· != '=')
  -- Convert all data characters to their 6-bit values
  let vals := dataChars.filterMap base64CharToVal
  -- Check that all non-padding, non-whitespace characters were valid base64
  if vals.length != dataChars.length then none
  else
    let valsArr := vals.toArray
    let numVals := valsArr.size
    -- Process groups of 4 values, producing 3 bytes each
    let fullGroups := numVals / 4
    let remainder := numVals % 4
    -- A remainder of 1 is invalid in base64
    if remainder == 1 then none
    else
      let result := Id.run do
        let mut buf := ByteArray.emptyWithCapacity (fullGroups * 3 + if remainder > 0 then remainder - 1 else 0)
        -- Process full 4-value groups
        for i in [:fullGroups] do
          let a := valsArr[i * 4]!
          let b := valsArr[i * 4 + 1]!
          let c := valsArr[i * 4 + 2]!
          let d := valsArr[i * 4 + 3]!
          -- Combine 4 x 6-bit values into 3 bytes
          buf := buf.push ((a <<< 2) ||| (b >>> 4))
          buf := buf.push ((b <<< 4) ||| (c >>> 2))
          buf := buf.push ((c <<< 6) ||| d)
        -- Handle remaining values
        if remainder == 2 then
          -- 2 values = 1 output byte
          let a := valsArr[fullGroups * 4]!
          let b := valsArr[fullGroups * 4 + 1]!
          buf := buf.push ((a <<< 2) ||| (b >>> 4))
        else if remainder == 3 then
          -- 3 values = 2 output bytes
          let a := valsArr[fullGroups * 4]!
          let b := valsArr[fullGroups * 4 + 1]!
          let c := valsArr[fullGroups * 4 + 2]!
          buf := buf.push ((a <<< 2) ||| (b >>> 4))
          buf := buf.push ((b <<< 4) ||| (c >>> 2))
        return buf
      some result

-- ============================================================================
-- Section 2: PEM Block Parsing
-- ============================================================================

/-- A parsed PEM block with its label and decoded binary data. -/
structure PEMBlock where
  label : String        -- e.g., "CERTIFICATE", "PRIVATE KEY"
  data : ByteArray      -- decoded binary data

instance : Inhabited PEMBlock where
  default := { label := "", data := ByteArray.empty }

/-- Check if a string starts with the given target prefix. -/
private def hasPrefix (s : String) (pfx : String) : Bool :=
  s.startsWith pfx

/-- Extract a PEM label from a BEGIN line.
    Expects format: "-----BEGIN <label>-----"
    Returns the label string (e.g., "CERTIFICATE"). -/
private def extractBeginLabel (line : String) : Option String :=
  let trimmed := line.trimAscii.toString
  let beginPfx := "-----BEGIN "
  let endSuffix := "-----"
  if hasPrefix trimmed beginPfx then
    let afterPfx := trimmed.drop beginPfx.length
    -- Check that it ends with "-----"
    if afterPfx.endsWith endSuffix then
      let label := (afterPfx.dropEnd endSuffix.length).toString
      some label
    else none
  else none

/-- Check if a line is an END marker for the given label.
    Expects format: "-----END <label>-----" -/
private def isEndMarker (line : String) (label : String) : Bool :=
  let trimmed := line.trimAscii.toString
  trimmed == s!"-----END {label}-----"

/-- Parse a PEM-formatted string that may contain multiple blocks.
    Finds `-----BEGIN <label>-----` markers, collects base64 lines until
    the matching `-----END <label>-----`, decodes the base64 content,
    and returns an array of PEMBlock values.

    Any text outside BEGIN/END markers is silently ignored.
    Handles both `\n` and `\r\n` line endings. -/
def parsePEM (input : String) : Array PEMBlock :=
  -- Normalize line endings and split into lines
  let normalized := input.replace "\r\n" "\n"
  let lines := normalized.splitOn "\n"
  go lines #[] none ""
where
  go (lines : List String) (blocks : Array PEMBlock)
     (currentLabel : Option String) (currentB64 : String) : Array PEMBlock :=
    match lines with
    | [] =>
      -- If we were in a block, discard it (no END marker found)
      blocks
    | line :: rest =>
      match currentLabel with
      | none =>
        -- Not currently inside a PEM block; look for a BEGIN marker
        match extractBeginLabel line with
        | some label => go rest blocks (some label) ""
        | none => go rest blocks none ""
      | some label =>
        -- Inside a PEM block; check for END marker
        if isEndMarker line label then
          -- Decode the accumulated base64 data
          match base64Decode currentB64 with
          | some decoded =>
            go rest (blocks.push { label := label, data := decoded }) none ""
          | none =>
            -- If decoding fails, skip this block
            go rest blocks none ""
        else
          -- Accumulate this line as base64 data
          go rest blocks (some label) (currentB64 ++ line)

-- ============================================================================
-- Section 3: Certificate-specific Helper
-- ============================================================================

/-- Parse all CERTIFICATE blocks from a PEM string, returning an array of
    DER-encoded certificate ByteArrays. -/
def parseCertificates (input : String) : Array ByteArray :=
  let blocks := parsePEM input
  blocks.filterMap fun block =>
    if block.label == "CERTIFICATE" then some block.data
    else none

-- ============================================================================
-- Section 4: File Reading Helper
-- ============================================================================

/-- Read a PEM file from disk and parse all PEM blocks.
    Returns an array of PEMBlock values. -/
def readPEMFile (path : String) : IO (Array PEMBlock) := do
  let contents ← IO.FS.readFile ⟨path⟩
  return parsePEM contents

-- ============================================================================
-- Section 5: Tests
-- ============================================================================

/-- Run all PEM module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- --------------------------------------------------------------------------
  -- Test 1: Base64 decoding basic cases
  -- --------------------------------------------------------------------------
  IO.println "  PEM test 1a (base64 decode \"Hello World\"):"
  match base64Decode "SGVsbG8gV29ybGQ=" with
  | some result =>
    let expected := "Hello World".toUTF8
    if result == expected then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result}, expected {LeanTLS.Utils.bytesToHex expected})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  IO.println "  PEM test 1b (base64 decode AAEC -> 0x00 0x01 0x02):"
  match base64Decode "AAEC" with
  | some result =>
    let expected := ByteArray.mk #[0x00, 0x01, 0x02]
    if result == expected then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result}, expected {LeanTLS.Utils.bytesToHex expected})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  IO.println "  PEM test 1c (base64 decode empty string):"
  match base64Decode "" with
  | some result =>
    if result.size == 0 then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (expected empty, got {result.size} bytes)"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: Base64 with line breaks
  -- --------------------------------------------------------------------------
  IO.println "  PEM test 2 (base64 with line breaks):"
  let multiLineB64 := "SGVs\nbG8g\r\nV29y\nbGQ="
  match base64Decode multiLineB64 with
  | some result =>
    let expected := "Hello World".toUTF8
    if result == expected then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: PEM parsing single certificate
  -- --------------------------------------------------------------------------
  IO.println "  PEM test 3 (parse single PEM certificate):"
  let singleCertPEM := "-----BEGIN CERTIFICATE-----\nMIIBkTCB+wIJALRiMLAh0GRFMA0GCSqGSIb3DQEBCwUAMBExDzANBgNVBAMMBnRl\nc3RjYTAeFw0yNDAxMDEwMDAwMDBaFw0yNTAxMDEwMDAwMDBaMBExDzANBgNVBAMM\nBnRlc3RjYTBcMA0GCSqGSIb3DQEBAQUAA0sAMEgCQQDFbvMQ+JOdz3XgJJJNG5BB\njJMC6aCTNTMATkFdQ3bPj/kPvhqJbAcKioKx6RrgHKYlmKoZbHNP9iDH2rRRkiIL\nAgMBAAEwDQYJKoZIhvcNAQELBQADQQBz0GY3a6B9VlnDPynXxFFr8iJyRlwlQqeE\ntQVaO1b9kJJ8yp1YNzJZ7kPNF2VvKrEHjJK+GQ9F2n2VxDrZqLvN\n-----END CERTIFICATE-----\n"
  let blocks := parsePEM singleCertPEM
  if blocks.size != 1 then
    IO.println s!"    FAILED (expected 1 block, got {blocks.size})"
    allPassed := false
  else
    let block := blocks[0]!
    if block.label != "CERTIFICATE" then
      IO.println s!"    FAILED (expected label CERTIFICATE, got {block.label})"
      allPassed := false
    else if block.data.size == 0 then
      IO.println "    FAILED (data is empty)"
      allPassed := false
    else if block.data[0]! != 0x30 then
      IO.println s!"    FAILED (expected first byte 0x30)"
      allPassed := false
    else
      IO.println "    PASSED"

  -- --------------------------------------------------------------------------
  -- Test 4: Multiple certificates in one PEM
  -- --------------------------------------------------------------------------
  IO.println "  PEM test 4 (parse multiple certificates):"
  let multiCertPEM := "Some text before\n-----BEGIN CERTIFICATE-----\nMIIBkTCB+wIJALRiMLAh0GRFMA0GCSqGSIb3DQEBCwUAMBExDzANBgNVBAMMBnRl\nc3RjYTAeFw0yNDAxMDEwMDAwMDBaFw0yNTAxMDEwMDAwMDBaMBExDzANBgNVBAMM\nBnRlc3RjYTBcMA0GCSqGSIb3DQEBAQUAA0sAMEgCQQDFbvMQ+JOdz3XgJJJNG5BB\njJMC6aCTNTMATkFdQ3bPj/kPvhqJbAcKioKx6RrgHKYlmKoZbHNP9iDH2rRRkiIL\nAgMBAAEwDQYJKoZIhvcNAQELBQADQQBz0GY3a6B9VlnDPynXxFFr8iJyRlwlQqeE\ntQVaO1b9kJJ8yp1YNzJZ7kPNF2VvKrEHjJK+GQ9F2n2VxDrZqLvN\n-----END CERTIFICATE-----\nSome text in between\n-----BEGIN CERTIFICATE-----\nMIIBkTCB+wIJALRiMLAh0GRFMA0GCSqGSIb3DQEBCwUAMBExDzANBgNVBAMMBnRl\nc3RjYTAeFw0yNDAxMDEwMDAwMDBaFw0yNTAxMDEwMDAwMDBaMBExDzANBgNVBAMM\nBnRlc3RjYTBcMA0GCSqGSIb3DQEBAQUAA0sAMEgCQQDFbvMQ+JOdz3XgJJJNG5BB\njJMC6aCTNTMATkFdQ3bPj/kPvhqJbAcKioKx6RrgHKYlmKoZbHNP9iDH2rRRkiIL\nAgMBAAEwDQYJKoZIhvcNAQELBQADQQBz0GY3a6B9VlnDPynXxFFr8iJyRlwlQqeE\ntQVaO1b9kJJ8yp1YNzJZ7kPNF2VvKrEHjJK+GQ9F2n2VxDrZqLvN\n-----END CERTIFICATE-----\n"
  let certs := parseCertificates multiCertPEM
  if certs.size != 2 then
    IO.println s!"    FAILED (expected 2 certificates, got {certs.size})"
    allPassed := false
  else
    -- Both should start with 0x30 (ASN.1 SEQUENCE tag)
    let cert0 := certs[0]!
    let cert1 := certs[1]!
    let cert0Ok := cert0[0]! == 0x30
    let cert1Ok := cert1[0]! == 0x30
    if cert0Ok && cert1Ok then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (cert0 starts with 0x30: {cert0Ok}, cert1 starts with 0x30: {cert1Ok})"
      allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 5: Base64 padding edge cases
  -- --------------------------------------------------------------------------
  IO.println "  PEM test 5a (base64 \"YQ==\" -> 'a'):"
  match base64Decode "YQ==" with
  | some result =>
    if result == ByteArray.mk #[0x61] then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  IO.println "  PEM test 5b (base64 \"YWI=\" -> 'ab'):"
  match base64Decode "YWI=" with
  | some result =>
    if result == ByteArray.mk #[0x61, 0x62] then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  IO.println "  PEM test 5c (base64 \"YWJj\" -> 'abc'):"
  match base64Decode "YWJj" with
  | some result =>
    if result == ByteArray.mk #[0x61, 0x62, 0x63] then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  IO.println "  PEM test 5d (base64 \"YQ\" without padding -> 'a'):"
  match base64Decode "YQ" with
  | some result =>
    if result == ByteArray.mk #[0x61] then
      IO.println "    PASSED"
    else
      IO.println s!"    FAILED (got {LeanTLS.Utils.bytesToHex result})"
      allPassed := false
  | none =>
    IO.println "    FAILED (returned none)"
    allPassed := false

  if allPassed then
    IO.println "  All PEM tests passed."

  return allPassed

end LeanTLS.PEM
