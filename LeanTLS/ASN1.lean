import LeanTLS.Utils

set_option autoImplicit false

namespace LeanTLS.ASN1

/-!
# ASN.1/DER Parser (ITU-T X.690)

Pure Lean 4 implementation of a DER (Distinguished Encoding Rules) parser for
ASN.1 structures. Used by the TLS certificate handling code to parse X.509
certificates and related structures.

Implements:
- Tag parsing (single-byte and multi-byte)
- Length parsing (short form and long form)
- TLV (Tag-Length-Value) parsing with recursive constructed types
- OID decoding (base-128 encoding)
- DER INTEGER parsing (big-endian unsigned with sign-padding skip)
-/

-- ============================================================================
-- Section 1: Data Types
-- ============================================================================

/-- ASN.1 tag class, encoded in bits 7-6 of the tag byte. -/
inductive TagClass where
  | universal | application | contextSpecific | private_
  deriving BEq, Repr

/-- ASN.1 encoding form, encoded in bit 5 of the tag byte. -/
inductive Encoding where
  | primitive | constructed
  deriving BEq, Repr

/-- A parsed ASN.1 tag consisting of class, encoding form, and tag number. -/
structure Tag where
  tagClass : TagClass
  encoding : Encoding
  tagNumber : Nat
  deriving BEq, Repr

/-- An ASN.1 node in a parsed DER structure. Either a primitive leaf carrying
    raw value bytes, or a constructed node with child nodes. -/
inductive ASN1Node where
  | primitive (tag : Tag) (value : ByteArray) : ASN1Node
  | constructed (tag : Tag) (children : Array ASN1Node) : ASN1Node

instance : Inhabited ASN1Node where
  default := ASN1Node.primitive
    { tagClass := .universal, encoding := .primitive, tagNumber := 0 }
    ByteArray.empty

-- ============================================================================
-- Section 2: Tag Parsing
-- ============================================================================

/-- Decode the tag class from bits 7-6 of the tag byte. -/
private def tagClassFromBits (b : UInt8) : TagClass :=
  match (b >>> 6).toNat with
  | 0 => .universal
  | 1 => .application
  | 2 => .contextSpecific
  | _ => .private_

/-- Decode the encoding form from bit 5 of the tag byte. -/
private def encodingFromBit (b : UInt8) : Encoding :=
  if (b &&& 0x20) != 0 then .constructed else .primitive

private def readLongTag (data : ByteArray) (pos : Nat) (tc : TagClass)
    (enc : Encoding) (acc : Nat) : Option (Tag × Nat) :=
  if pos >= data.size then none
  else
    let b := data.get! pos
    let acc' := acc * 128 + (b &&& 0x7F).toNat
    if (b &&& 0x80) != 0 then
      if pos + 1 >= data.size then none
      else readLongTag data (pos + 1) tc enc acc'
    else
      some ({ tagClass := tc, encoding := enc, tagNumber := acc' }, pos + 1)
termination_by data.size - pos

/-- Parse an ASN.1 tag from `data` starting at `offset`.
    Returns the parsed `Tag` and the offset immediately after the tag bytes.

    For single-byte tags (low 5 bits < 31): extract class (bits 7-6),
    encoding (bit 5), and tag number (bits 4-0).

    For multi-byte tags (low 5 bits == 0x1F): read continuation bytes where
    bit 7 set means more bytes follow, accumulating the tag number from the
    lower 7 bits of each continuation byte. -/
def parseTag (data : ByteArray) (offset : Nat) : Option (Tag × Nat) :=
  if offset >= data.size then none
  else
    let b := data.get! offset
    let tc := tagClassFromBits b
    let enc := encodingFromBit b
    let low5 := (b &&& 0x1F).toNat
    if low5 < 31 then
      some ({ tagClass := tc, encoding := enc, tagNumber := low5 }, offset + 1)
    else
      readLongTag data (offset + 1) tc enc 0

-- ============================================================================
-- Section 3: Length Parsing
-- ============================================================================

private def readLongLength (data : ByteArray) (pos : Nat) (remaining : Nat)
    (acc : Nat) : Option (Nat × Nat) :=
  if remaining == 0 then some (acc, pos)
  else if pos >= data.size then none
  else
    let b := (data.get! pos).toNat
    let acc' := acc * 256 + b
    readLongLength data (pos + 1) (remaining - 1) acc'
termination_by remaining
decreasing_by simp_all; omega

/-- Parse a DER length field from `data` starting at `offset`.
    Returns the decoded length value and the offset after the length bytes.

    - If byte < 0x80: short form, length = byte value.
    - If byte == 0x80: indefinite form (not valid in DER), returns `none`.
    - If byte > 0x80: long form, lower 7 bits = number of subsequent length
      bytes, which encode the length as a big-endian unsigned integer. -/
def parseLength (data : ByteArray) (offset : Nat) : Option (Nat × Nat) :=
  if offset >= data.size then none
  else
    let b := data.get! offset
    let bNat := b.toNat
    if bNat < 0x80 then
      some (bNat, offset + 1)
    else if bNat == 0x80 then
      none
    else
      let numBytes := bNat - 0x80
      if numBytes == 0 then none
      else readLongLength data (offset + 1) numBytes 0

-- ============================================================================
-- Section 4: TLV Parsing (mutual partial recursion)
-- ============================================================================

mutual

/-- Parse a single TLV (Tag-Length-Value) structure from `data` at `offset`.
    Returns the parsed `ASN1Node` and the offset after the complete TLV.

    For constructed nodes (encoding bit set), the value region is recursively
    parsed as a sequence of child TLVs. For primitive nodes, the raw value
    bytes are extracted directly.

    Marked `partial` because of mutual recursion with `parseChildrenAux`. -/
partial def parseTLV (data : ByteArray) (offset : Nat)
    : Option (ASN1Node × Nat) := do
  let (tag, afterTag) ← parseTag data offset
  let (len, afterLen) ← parseLength data afterTag
  let valueStart := afterLen
  let valueEnd := valueStart + len
  if valueEnd > data.size then none
  else
    let isConstructed := tag.encoding == Encoding.constructed
    if isConstructed then
      let children ← parseChildrenAux data valueStart valueEnd #[]
      some (ASN1Node.constructed tag children, valueEnd)
    else
      let value := data.extract valueStart valueEnd
      some (ASN1Node.primitive tag value, valueEnd)

/-- Auxiliary for parsing consecutive TLVs within [pos, endPos).
    Accumulates results in `acc`. -/
partial def parseChildrenAux (data : ByteArray) (pos : Nat) (endPos : Nat)
    (acc : Array ASN1Node) : Option (Array ASN1Node) :=
  if pos == endPos then some acc
  else if pos > endPos then none
  else
    match parseTLV data pos with
    | some (node, nextPos) =>
      if nextPos > endPos then none
      else if nextPos <= pos then none
      else parseChildrenAux data nextPos endPos (acc.push node)
    | none => none

end

/-- Parse consecutive TLV structures within the byte range [offset, endPos).
    Returns the array of parsed child nodes on success. -/
def parseChildren (data : ByteArray) (offset : Nat) (endPos : Nat)
    : Option (Array ASN1Node) :=
  parseChildrenAux data offset endPos #[]

/-- Parse an entire `ByteArray` as a single top-level TLV structure.
    The TLV must consume the full byte array exactly. -/
def parseAll (data : ByteArray) : Option ASN1Node := do
  let (node, endPos) ← parseTLV data 0
  if endPos == data.size then some node
  else none

-- ============================================================================
-- Section 5: ASN1Node Accessors
-- ============================================================================

/-- Get the child nodes of an ASN1Node. Returns an empty array for primitives. -/
def ASN1Node.getChildren (node : ASN1Node) : Array ASN1Node :=
  match node with
  | .constructed _ children => children
  | .primitive _ _ => #[]

/-- Get the tag of an ASN1Node. -/
def ASN1Node.getTag (node : ASN1Node) : Tag :=
  match node with
  | .constructed tag _ => tag
  | .primitive tag _ => tag

/-- Get the raw value bytes of a primitive ASN1Node.
    Returns an empty ByteArray for constructed nodes. -/
def ASN1Node.getValue (node : ASN1Node) : ByteArray :=
  match node with
  | .primitive _ value => value
  | .constructed _ _ => ByteArray.empty

-- ============================================================================
-- Section 6: OID Parsing
-- ============================================================================

private def parseOIDAux (value : ByteArray) (pos : Nat) (acc : Array Nat)
    (current : Nat) : Option (Array Nat) :=
  if pos >= value.size then
    some acc
  else
    let b := value.get! pos
    let current' := current * 128 + (b &&& 0x7F).toNat
    if (b &&& 0x80) != 0 then
      parseOIDAux value (pos + 1) acc current'
    else
      parseOIDAux value (pos + 1) (acc.push current') 0
termination_by value.size - pos

/-- Decode an OID from its primitive value bytes.

    The first byte encodes two components: `first_component * 40 + second_component`.
    Subsequent bytes use base-128 encoding where bit 7 indicates continuation
    (more bytes follow for the current component). -/
def parseOID (value : ByteArray) : Option (Array Nat) :=
  if value.size == 0 then none
  else
    let first := (value.get! 0).toNat
    let comp1 := first / 40
    let comp2 := first % 40
    parseOIDAux value 1 #[comp1, comp2] 0

/-- Compare two OID component arrays for equality. -/
def oidEq (a b : Array Nat) : Bool :=
  a == b

-- ============================================================================
-- Section 7: Integer Parsing
-- ============================================================================

private def parseIntegerAux (value : ByteArray) (pos : Nat) (acc : Nat) : Nat :=
  if pos >= value.size then acc
  else
    let b := (value.get! pos).toNat
    let acc' := acc * 256 + b
    parseIntegerAux value (pos + 1) acc'
termination_by value.size - pos

/-- Parse a DER INTEGER value to a `Nat`.

    DER INTEGERs are big-endian two's complement. For positive numbers whose
    most significant bit is set, a leading 0x00 padding byte is present.
    This function skips that padding byte and converts the remaining bytes
    as a big-endian unsigned integer.

    Note: this only handles non-negative integers correctly. -/
def parseInteger (value : ByteArray) : Nat :=
  let startIdx :=
    if value.size > 1 && (value.get! 0) == 0x00 then 1
    else 0
  parseIntegerAux value startIdx 0

-- ============================================================================
-- Section 8: Well-known OID Constants
-- ============================================================================

/-- OID for rsaEncryption: 1.2.840.113549.1.1.1 -/
def oidRsaEncryption : Array Nat := #[1, 2, 840, 113549, 1, 1, 1]

/-- OID for sha256WithRSAEncryption: 1.2.840.113549.1.1.11 -/
def oidSha256WithRSAEncryption : Array Nat := #[1, 2, 840, 113549, 1, 1, 11]

/-- OID for subjectAltName: 2.5.29.17 -/
def oidSubjectAltName : Array Nat := #[2, 5, 29, 17]

/-- OID for commonName: 2.5.4.3 -/
def oidCommonName : Array Nat := #[2, 5, 4, 3]

-- ============================================================================
-- Section 9: Tests
-- ============================================================================

/-- Run all ASN1 module tests. Returns `true` if all tests pass. -/
def runTests : IO Bool := do
  let mut allPassed := true

  -- --------------------------------------------------------------------------
  -- Test 1: Parse OID for rsaEncryption
  -- DER: 06 09 2a 86 48 86 f7 0d 01 01 01
  -- --------------------------------------------------------------------------
  IO.println "  ASN1 test 1 (parse OID rsaEncryption):"
  let oidDer := LeanTLS.Utils.hexToBytes "06092a864886f70d010101"
  match parseTLV oidDer 0 with
  | some (node, endPos) =>
    if endPos != oidDer.size then
      IO.println "    FAILED (did not consume all bytes)"
      allPassed := false
    else
      let tag := node.getTag
      if tag.tagClass != TagClass.universal || tag.tagNumber != 6 then
        IO.println s!"    FAILED (wrong tag: class={repr tag.tagClass} number={tag.tagNumber})"
        allPassed := false
      else
        let val := node.getValue
        match parseOID val with
        | some components =>
          if oidEq components oidRsaEncryption then
            IO.println "    PASSED"
          else
            IO.println s!"    FAILED (OID mismatch: got {components.toList})"
            allPassed := false
        | none =>
          IO.println "    FAILED (parseOID returned none)"
          allPassed := false
  | none =>
    IO.println "    FAILED (parseTLV returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 2: Parse SEQUENCE containing two INTEGERs
  -- SEQUENCE { INTEGER(1), INTEGER(255) }
  -- INTEGER 1   = 02 01 01           (3 bytes)
  -- INTEGER 255 = 02 02 00 FF        (4 bytes: leading 0x00 since 0xFF > 0x7F)
  -- SEQUENCE    = 30 07 02 01 01 02 02 00 FF  (content = 3 + 4 = 7 bytes)
  -- --------------------------------------------------------------------------
  IO.println "  ASN1 test 2 (SEQUENCE of two INTEGERs):"
  let seqDer := LeanTLS.Utils.hexToBytes "3007020101020200FF"
  match parseAll seqDer with
  | some node =>
    let children := node.getChildren
    if children.size != 2 then
      IO.println s!"    FAILED (expected 2 children, got {children.size})"
      allPassed := false
    else
      let child0 := children.get! 0
      let child1 := children.get! 1
      let tag0 := child0.getTag
      let tag1 := child1.getTag
      let bothInt := tag0.tagNumber == 2 && tag1.tagNumber == 2
          && tag0.tagClass == TagClass.universal && tag1.tagClass == TagClass.universal
      if !bothInt then
        IO.println "    FAILED (children are not both INTEGER)"
        allPassed := false
      else
        let val0 := parseInteger child0.getValue
        let val1 := parseInteger child1.getValue
        if val0 == 1 && val1 == 255 then
          IO.println "    PASSED"
        else
          IO.println s!"    FAILED (expected 1 and 255, got {val0} and {val1})"
          allPassed := false
  | none =>
    IO.println "    FAILED (parseAll returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 3: Nested SEQUENCE
  -- SEQUENCE { SEQUENCE { INTEGER(42) }, NULL }
  -- INTEGER 42       = 02 01 2A
  -- Inner SEQUENCE   = 30 03 02 01 2A
  -- NULL             = 05 00
  -- Outer SEQUENCE   = 30 07 30 03 02 01 2A 05 00
  -- --------------------------------------------------------------------------
  IO.println "  ASN1 test 3 (nested SEQUENCE):"
  let nestedDer := LeanTLS.Utils.hexToBytes "3007300302012A0500"
  match parseAll nestedDer with
  | some node =>
    let outerTag := node.getTag
    -- SEQUENCE = universal constructed, tag number 0x10 = 16
    if outerTag.tagNumber != 0x10 || outerTag.encoding != Encoding.constructed then
      IO.println s!"    FAILED (outer not SEQUENCE: number={outerTag.tagNumber})"
      allPassed := false
    else
      let children := node.getChildren
      if children.size != 2 then
        IO.println s!"    FAILED (expected 2 children, got {children.size})"
        allPassed := false
      else
        let child0 := children.get! 0
        let child0Tag := child0.getTag
        if child0Tag.tagNumber != 0x10 || child0Tag.encoding != Encoding.constructed then
          IO.println "    FAILED (first child not constructed SEQUENCE)"
          allPassed := false
        else
          let grandChildren := child0.getChildren
          if grandChildren.size != 1 then
            IO.println s!"    FAILED (expected 1 grandchild, got {grandChildren.size})"
            allPassed := false
          else
            let gc0 := grandChildren.get! 0
            let intVal := parseInteger gc0.getValue
            let child1 := children.get! 1
            let child1Tag := child1.getTag
            let nullOk := child1Tag.tagNumber == 5
                && child1Tag.tagClass == TagClass.universal
            if intVal == 42 && nullOk then
              IO.println "    PASSED"
            else
              IO.println s!"    FAILED (INTEGER={intVal}, NULL tag ok={nullOk})"
              allPassed := false
  | none =>
    IO.println "    FAILED (parseAll returned none)"
    allPassed := false

  -- --------------------------------------------------------------------------
  -- Test 4: Context-specific tag
  -- Explicit tag [0] constructed containing INTEGER 3
  -- INTEGER 3  = 02 01 03
  -- Tag [0]    = A0 03 02 01 03
  -- A0 = 10 1 00000 = contextSpecific, constructed, tagNumber 0
  -- --------------------------------------------------------------------------
  IO.println "  ASN1 test 4 (context-specific tag [0]):"
  let ctxDer := LeanTLS.Utils.hexToBytes "A003020103"
  match parseAll ctxDer with
  | some node =>
    let tag := node.getTag
    if tag.tagClass != TagClass.contextSpecific then
      IO.println s!"    FAILED (expected contextSpecific, got {repr tag.tagClass})"
      allPassed := false
    else if tag.tagNumber != 0 then
      IO.println s!"    FAILED (expected tagNumber 0, got {tag.tagNumber})"
      allPassed := false
    else if tag.encoding != Encoding.constructed then
      IO.println "    FAILED (expected constructed encoding)"
      allPassed := false
    else
      let children := node.getChildren
      if children.size != 1 then
        IO.println s!"    FAILED (expected 1 child, got {children.size})"
        allPassed := false
      else
        let child0 := children.get! 0
        let childTag := child0.getTag
        let childVal := parseInteger child0.getValue
        if childTag.tagNumber == 2 && childVal == 3 then
          IO.println "    PASSED"
        else
          IO.println s!"    FAILED (child tagNumber={childTag.tagNumber}, value={childVal})"
          allPassed := false
  | none =>
    IO.println "    FAILED (parseAll returned none)"
    allPassed := false

  if allPassed then
    IO.println "  All ASN1 tests passed."

  return allPassed

end LeanTLS.ASN1
