set_option autoImplicit false

namespace LeanTLS.Utils

/-- Convert a hex character to its numeric nibble value (0-15). Returns 0 for invalid chars. -/
def hexCharToNibble (c : Char) : UInt8 :=
  if '0' ≤ c ∧ c ≤ '9' then (c.toNat - '0'.toNat).toUInt8
  else if 'a' ≤ c ∧ c ≤ 'f' then (c.toNat - 'a'.toNat + 10).toUInt8
  else if 'A' ≤ c ∧ c ≤ 'F' then (c.toNat - 'A'.toNat + 10).toUInt8
  else 0

/-- Convert a hex string to ByteArray. Must be even length. -/
def hexToBytes (s : String) : ByteArray :=
  let chars := s.toList
  let pairs := go chars #[]
  ByteArray.mk pairs
where
  go : List Char → Array UInt8 → Array UInt8
    | c1 :: c2 :: rest, acc =>
      let hi := hexCharToNibble c1
      let lo := hexCharToNibble c2
      go rest (acc.push ((hi <<< 4) ||| lo))
    | _, acc => acc

/-- Convert a single byte to a two-character lowercase hex string. -/
def byteToHex (b : UInt8) : String :=
  let hexChars := "0123456789abcdef".toList.toArray
  let hi := (b >>> 4).toNat
  let lo := (b &&& 0x0f).toNat
  let hiC := hexChars[hi]!
  let loC := hexChars[lo]!
  String.ofList [hiC, loC]

/-- Convert a ByteArray to a lowercase hex string. -/
def bytesToHex (bs : ByteArray) : String :=
  -- Safe: i ranges over [0, bs.size); .get! i is always in bounds
  Nat.fold (n := bs.size) (init := "") fun i _ acc =>
    acc ++ byteToHex (bs.get! i)

/-- Compare two ByteArrays for equality. -/
def byteArrayBEq (a b : ByteArray) : Bool :=
  a.data == b.data

/-- Constant-time comparison of two ByteArrays. Returns true iff they are equal.
    Always examines all bytes to prevent timing side-channels. -/
def constantTimeEq (a b : ByteArray) : Bool :=
  if a.size != b.size then false
  else
    -- Safe: i ranges over [0, a.size); a.size == b.size is checked above
    let xorSum := Nat.fold (n := a.size) (init := (0 : UInt8)) fun i _ acc =>
      acc ||| ((a.get! i) ^^^ (b.get! i))
    xorSum == 0

instance : BEq ByteArray where
  beq := byteArrayBEq

end LeanTLS.Utils
