// Lean compiler output
// Module: LeanTLS.Handshake
// Imports: Init LeanTLS.Crypto.SHA256 LeanTLS.Crypto.HMAC
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
static lean_object* l_LeanTLS_Handshake_runTests___closed__8;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__5(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt24BE(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__36;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__10;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
LEAN_EXPORT uint8_t l_Nat_foldTR_loop___at_LeanTLS_Handshake_verifyFinished___spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__8;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__12___closed__4;
uint8_t lean_uint32_to_uint8(uint32_t);
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__2;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__1;
lean_object* lean_byte_array_mk(lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildClientHello___boxed(lean_object*, lean_object*);
uint8_t lean_uint8_lor(uint8_t, uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___boxed(lean_object*, lean_object*, lean_object*);
static uint8_t l_LeanTLS_Handshake_runTests___lambda__11___closed__13;
lean_object* lean_uint32_to_nat(uint32_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt16BE(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__2;
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__3;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__35;
static lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__9___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__9___closed__5;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__10___closed__2;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__4;
static lean_object* l_LeanTLS_Handshake_transcriptHash___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__4___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__9;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_decode(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello(lean_object*);
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_LeanTLS_Handshake_transcriptHash___spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241____boxed(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__21;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__4;
static lean_object* l_LeanTLS_Handshake_runTests___closed__3;
uint32_t lean_uint8_to_uint32(uint8_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__22;
lean_object* lean_array_push(lean_object*, lean_object*);
static uint8_t l_LeanTLS_Handshake_runTests___lambda__6___closed__14;
uint32_t lean_uint32_shift_right(uint32_t, uint32_t);
LEAN_EXPORT lean_object* l_Array_isEqvAux___at_LeanTLS_Handshake_byteArrayEq___spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_verifyFinished___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt16BE___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__3___closed__3;
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__6;
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte(uint8_t);
lean_object* lean_array_fget(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_instReprHandshakeType___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__5;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__7;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_transcriptHash(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__15;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__25;
lean_object* l_ByteArray_extract(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_byteArrayEq___boxed(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildFinishedVerifyData(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__9___closed__2;
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_LeanTLS_Handshake_transcriptHash___spec__1(lean_object*, size_t, size_t, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__37;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__2(uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___closed__9;
static lean_object* l_LeanTLS_Handshake_runTests___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt24BE___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_toCtorIdx(uint8_t);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__17;
static lean_object* l_LeanTLS_Handshake_runTests___closed__5;
static lean_object* l_LeanTLS_Handshake_runTests___closed__7;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__9___closed__1;
lean_object* l_ByteArray_append(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__10;
static uint16_t l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__5;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259_(uint8_t, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_decode___boxed(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__15;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__3___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__12___closed__2;
uint8_t lean_uint8_shift_left(uint8_t, uint8_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__4;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__3;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__31;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__12;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__12___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt16BE___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__10(lean_object*, uint8_t, uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__9___closed__4;
size_t lean_usize_of_nat(lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__2;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions_go___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes___closed__1;
lean_object* lean_string_data(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests_go___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello___boxed(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__3;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__29;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__6;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__9;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello___lambda__1(lean_object*, lean_object*, uint16_t, lean_object*, lean_object*);
lean_object* l_LeanTLS_Crypto_SHA256_toHex(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_transcriptHash___boxed(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__8___closed__1;
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__30;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
lean_object* lean_nat_to_int(lean_object*);
uint32_t lean_uint32_of_nat(lean_object*);
extern lean_object* l_ByteArray_empty;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__8;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__9(lean_object*, uint8_t, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_encode(lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__24;
LEAN_EXPORT uint8_t l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble(uint32_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__5;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__15;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_toByte___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_extractBytes(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt24BE(uint32_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__24;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__11;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__4;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__8;
static lean_object* l_LeanTLS_Handshake_instBEqHandshakeType___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__17;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes_go(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__18;
uint16_t lean_uint16_shift_right(uint16_t, uint16_t);
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_runTests_containsVersion(lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__14;
uint16_t lean_uint8_to_uint16(uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Array_isEqvAux___at_LeanTLS_Handshake_byteArrayEq___spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__8___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__7;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__12(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__13;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__7;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__11___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_runTests_go(lean_object*, lean_object*, lean_object*, uint8_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__20;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__16;
lean_object* l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(lean_object*, lean_object*);
uint16_t lean_uint16_of_nat(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__7;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__21;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__6;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions_go(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_uint16_to_uint8(uint16_t);
static uint8_t l_LeanTLS_Handshake_runTests___lambda__11___closed__11;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__10___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg(uint8_t, uint8_t, lean_object*);
uint8_t lean_uint16_dec_eq(uint16_t, uint16_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildClientHello(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__8;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___lambda__1(lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__38;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__11(uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___closed__3;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__3___closed__4;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__9;
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_byteArrayEq(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__27;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__5;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__1;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__23;
static lean_object* l_LeanTLS_Handshake_runTests___closed__6;
lean_object* lean_byte_array_data(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_instBEqByteArray__leanTLS;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__18;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__9;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble___boxed(lean_object*);
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(uint16_t, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2;
uint16_t lean_uint16_lor(uint16_t, uint16_t);
LEAN_EXPORT uint8_t l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241_(uint8_t, uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__3;
static lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___closed__1;
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__26;
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__3___closed__2;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__33;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__5___boxed(lean_object*, lean_object*, lean_object*);
uint8_t lean_uint8_xor(uint8_t, uint8_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__11;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__3___closed__5;
static lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___closed__6;
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__4;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__2;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildKeyShareExt___boxed(lean_object*);
lean_object* lean_uint16_to_nat(uint16_t);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___lambda__1___boxed(lean_object*);
uint32_t lean_uint32_lor(uint32_t, uint32_t);
static lean_object* l_LeanTLS_Handshake_runTests___closed__11;
uint32_t lean_uint32_shift_left(uint32_t, uint32_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__2___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___closed__1;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__13;
lean_object* lean_nat_sub(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__10___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_instBEqHandshakeType;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__19;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__12;
uint8_t lean_uint8_of_nat(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__4(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__7___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__9___closed__3;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__7;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__8(lean_object*, uint8_t, uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__12___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_instReprHandshakeType;
lean_object* lean_array_mk(lean_object*);
uint8_t lean_byte_array_get(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__1(uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__12___closed__6;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt24BE___boxed(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16;
lean_object* lean_uint8_to_nat(uint8_t);
size_t lean_usize_add(size_t, size_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3;
lean_object* lean_array_uget(lean_object*, size_t);
static lean_object* l_LeanTLS_Handshake_buildClientHello___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__25;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__12;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__8;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__3(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__6;
lean_object* lean_string_append(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__10___closed__3;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__6;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__6(uint8_t, lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_HandshakeType_toByte(uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_encode___boxed(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__11___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_toCtorIdx___boxed(lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__5___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt16BE(uint16_t);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__6___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__6;
lean_object* l_LeanTLS_Crypto_HMAC_hmacSHA256(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Nat_foldTR_loop___at_LeanTLS_Handshake_verifyFinished___spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__4___closed__2;
static lean_object* l_LeanTLS_Handshake_runTests___lambda__6___closed__23;
uint16_t lean_uint16_shift_left(uint16_t, uint16_t);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__10___closed__1;
static lean_object* l_LeanTLS_Handshake_instBEqByteArray__leanTLS___closed__1;
static uint8_t l_LeanTLS_Handshake_runTests___lambda__5___closed__7;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__7(uint8_t, uint8_t, lean_object*, lean_object*);
static uint8_t l_LeanTLS_Handshake_runTests___lambda__11___closed__14;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__20;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_extractBytes___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildKeyShareExt(lean_object*);
lean_object* l_LeanTLS_Crypto_SHA256_hash(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__8___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildFinishedVerifyData___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___lambda__12___closed__3;
lean_object* lean_byte_array_size(lean_object*);
uint8_t lean_uint8_dec_eq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests_containsVersion___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l___private_Init_Data_Repr_0__Nat_reprFast(lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__32;
static lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___closed__2;
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(lean_object*);
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_verifyFinished(lean_object*, lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__4;
static lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___boxed(lean_object*);
static lean_object* l_LeanTLS_Handshake_runTests___closed__10;
static lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Array_isEqvAux___at_LeanTLS_Handshake_byteArrayEq___spec__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; uint8_t x_9; 
x_8 = lean_unsigned_to_nat(0u);
x_9 = lean_nat_dec_eq(x_6, x_8);
if (x_9 == 0)
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; uint8_t x_15; uint8_t x_16; 
x_10 = lean_unsigned_to_nat(1u);
x_11 = lean_nat_sub(x_6, x_10);
lean_dec(x_6);
x_12 = lean_array_fget(x_4, x_11);
x_13 = lean_unbox(x_12);
lean_dec(x_12);
x_14 = lean_array_fget(x_5, x_11);
x_15 = lean_unbox(x_14);
lean_dec(x_14);
x_16 = lean_uint8_dec_eq(x_13, x_15);
if (x_16 == 0)
{
uint8_t x_17; 
lean_dec(x_11);
x_17 = 0;
return x_17;
}
else
{
x_3 = lean_box(0);
x_6 = x_11;
x_7 = lean_box(0);
goto _start;
}
}
else
{
uint8_t x_19; 
lean_dec(x_6);
x_19 = 1;
return x_19;
}
}
}
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_byteArrayEq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
lean_inc(x_1);
x_3 = lean_byte_array_data(x_1);
lean_inc(x_2);
x_4 = lean_byte_array_data(x_2);
x_5 = lean_array_get_size(x_3);
x_6 = lean_array_get_size(x_4);
x_7 = lean_nat_dec_eq(x_5, x_6);
lean_dec(x_6);
if (x_7 == 0)
{
uint8_t x_8; 
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_8 = 0;
return x_8;
}
else
{
uint8_t x_9; 
x_9 = l_Array_isEqvAux___at_LeanTLS_Handshake_byteArrayEq___spec__1(x_1, x_2, lean_box(0), x_3, x_4, x_5, lean_box(0));
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_9;
}
}
}
LEAN_EXPORT lean_object* l_Array_isEqvAux___at_LeanTLS_Handshake_byteArrayEq___spec__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
uint8_t x_8; lean_object* x_9; 
x_8 = l_Array_isEqvAux___at_LeanTLS_Handshake_byteArrayEq___spec__1(x_1, x_2, x_3, x_4, x_5, x_6, x_7);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_2);
lean_dec(x_1);
x_9 = lean_box(x_8);
return x_9;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_byteArrayEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = l_LeanTLS_Handshake_byteArrayEq(x_1, x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_instBEqByteArray__leanTLS___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_byteArrayEq___boxed), 2, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_instBEqByteArray__leanTLS() {
_start:
{
lean_object* x_1; 
x_1 = l_LeanTLS_Handshake_instBEqByteArray__leanTLS___closed__1;
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt16BE(uint16_t x_1) {
_start:
{
uint16_t x_2; uint16_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; 
x_2 = 8;
x_3 = lean_uint16_shift_right(x_1, x_2);
x_4 = lean_uint16_to_uint8(x_3);
x_5 = lean_uint16_to_uint8(x_1);
x_6 = lean_box(0);
x_7 = lean_box(x_5);
x_8 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_8, 0, x_7);
lean_ctor_set(x_8, 1, x_6);
x_9 = lean_box(x_4);
x_10 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_10, 0, x_9);
lean_ctor_set(x_10, 1, x_8);
x_11 = lean_array_mk(x_10);
x_12 = lean_byte_array_mk(x_11);
return x_12;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt16BE___boxed(lean_object* x_1) {
_start:
{
uint16_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Handshake_encodeUInt16BE(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt16BE(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; 
x_3 = lean_byte_array_size(x_1);
x_4 = lean_unsigned_to_nat(2u);
x_5 = lean_nat_add(x_2, x_4);
x_6 = lean_nat_dec_lt(x_3, x_5);
lean_dec(x_5);
lean_dec(x_3);
if (x_6 == 0)
{
uint8_t x_7; uint16_t x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; uint16_t x_12; uint16_t x_13; uint16_t x_14; uint16_t x_15; lean_object* x_16; lean_object* x_17; 
x_7 = lean_byte_array_get(x_1, x_2);
x_8 = lean_uint8_to_uint16(x_7);
x_9 = lean_unsigned_to_nat(1u);
x_10 = lean_nat_add(x_2, x_9);
x_11 = lean_byte_array_get(x_1, x_10);
lean_dec(x_10);
x_12 = lean_uint8_to_uint16(x_11);
x_13 = 8;
x_14 = lean_uint16_shift_left(x_8, x_13);
x_15 = lean_uint16_lor(x_14, x_12);
x_16 = lean_box(x_15);
x_17 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_17, 0, x_16);
return x_17;
}
else
{
lean_object* x_18; 
x_18 = lean_box(0);
return x_18;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt16BE___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt24BE(uint32_t x_1) {
_start:
{
uint32_t x_2; uint32_t x_3; uint8_t x_4; uint32_t x_5; uint32_t x_6; uint8_t x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_2 = 16;
x_3 = lean_uint32_shift_right(x_1, x_2);
x_4 = lean_uint32_to_uint8(x_3);
x_5 = 8;
x_6 = lean_uint32_shift_right(x_1, x_5);
x_7 = lean_uint32_to_uint8(x_6);
x_8 = lean_uint32_to_uint8(x_1);
x_9 = lean_box(0);
x_10 = lean_box(x_8);
x_11 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_11, 0, x_10);
lean_ctor_set(x_11, 1, x_9);
x_12 = lean_box(x_7);
x_13 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_13, 0, x_12);
lean_ctor_set(x_13, 1, x_11);
x_14 = lean_box(x_4);
x_15 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_15, 0, x_14);
lean_ctor_set(x_15, 1, x_13);
x_16 = lean_array_mk(x_15);
x_17 = lean_byte_array_mk(x_16);
return x_17;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_encodeUInt24BE___boxed(lean_object* x_1) {
_start:
{
uint32_t x_2; lean_object* x_3; 
x_2 = lean_unbox_uint32(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Handshake_encodeUInt24BE(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt24BE(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; 
x_3 = lean_byte_array_size(x_1);
x_4 = lean_unsigned_to_nat(3u);
x_5 = lean_nat_add(x_2, x_4);
x_6 = lean_nat_dec_lt(x_3, x_5);
lean_dec(x_5);
lean_dec(x_3);
if (x_6 == 0)
{
uint8_t x_7; uint32_t x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; uint32_t x_12; lean_object* x_13; lean_object* x_14; uint8_t x_15; uint32_t x_16; uint32_t x_17; uint32_t x_18; uint32_t x_19; uint32_t x_20; uint32_t x_21; uint32_t x_22; lean_object* x_23; lean_object* x_24; 
x_7 = lean_byte_array_get(x_1, x_2);
x_8 = lean_uint8_to_uint32(x_7);
x_9 = lean_unsigned_to_nat(1u);
x_10 = lean_nat_add(x_2, x_9);
x_11 = lean_byte_array_get(x_1, x_10);
lean_dec(x_10);
x_12 = lean_uint8_to_uint32(x_11);
x_13 = lean_unsigned_to_nat(2u);
x_14 = lean_nat_add(x_2, x_13);
x_15 = lean_byte_array_get(x_1, x_14);
lean_dec(x_14);
x_16 = lean_uint8_to_uint32(x_15);
x_17 = 16;
x_18 = lean_uint32_shift_left(x_8, x_17);
x_19 = 8;
x_20 = lean_uint32_shift_left(x_12, x_19);
x_21 = lean_uint32_lor(x_18, x_20);
x_22 = lean_uint32_lor(x_21, x_16);
x_23 = lean_box_uint32(x_22);
x_24 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_24, 0, x_23);
return x_24;
}
else
{
lean_object* x_25; 
x_25 = lean_box(0);
return x_25;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_decodeUInt24BE___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Handshake_decodeUInt24BE(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_extractBytes(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; 
x_4 = lean_byte_array_size(x_1);
x_5 = lean_nat_add(x_2, x_3);
x_6 = lean_nat_dec_lt(x_4, x_5);
lean_dec(x_4);
if (x_6 == 0)
{
lean_object* x_7; lean_object* x_8; 
x_7 = l_ByteArray_extract(x_1, x_2, x_5);
lean_dec(x_5);
x_8 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_8, 0, x_7);
return x_8;
}
else
{
lean_object* x_9; 
lean_dec(x_5);
lean_dec(x_2);
x_9 = lean_box(0);
return x_9;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_extractBytes___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_LeanTLS_Handshake_extractBytes(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_toCtorIdx(uint8_t x_1) {
_start:
{
switch (x_1) {
case 0:
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
case 1:
{
lean_object* x_3; 
x_3 = lean_unsigned_to_nat(1u);
return x_3;
}
case 2:
{
lean_object* x_4; 
x_4 = lean_unsigned_to_nat(2u);
return x_4;
}
case 3:
{
lean_object* x_5; 
x_5 = lean_unsigned_to_nat(3u);
return x_5;
}
case 4:
{
lean_object* x_6; 
x_6 = lean_unsigned_to_nat(4u);
return x_6;
}
default: 
{
lean_object* x_7; 
x_7 = lean_unsigned_to_nat(5u);
return x_7;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_toCtorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Handshake_HandshakeType_toCtorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___lambda__1(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___lambda__1___boxed), 1, 0);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg(uint8_t x_1, uint8_t x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___closed__1;
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___boxed), 3, 0);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___lambda__1___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___lambda__1(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = lean_unbox(x_2);
lean_dec(x_2);
x_6 = l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg(x_4, x_5, x_3);
return x_6;
}
}
LEAN_EXPORT uint8_t l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241_(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = l_LeanTLS_Handshake_HandshakeType_toCtorIdx(x_1);
x_4 = l_LeanTLS_Handshake_HandshakeType_toCtorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241____boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
lean_dec(x_1);
x_4 = lean_unbox(x_2);
lean_dec(x_2);
x_5 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241_(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static lean_object* _init_l_LeanTLS_Handshake_instBEqHandshakeType___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241____boxed), 2, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_instBEqHandshakeType() {
_start:
{
lean_object* x_1; 
x_1 = l_LeanTLS_Handshake_instBEqHandshakeType___closed__1;
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("LeanTLS.Handshake.HandshakeType.clientHello", 43, 43);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__1;
x_2 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__5() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__4;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__8() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__7;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__9() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("LeanTLS.Handshake.HandshakeType.serverHello", 43, 43);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__9;
x_2 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__12() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__11;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__13() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__14() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__13;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__15() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("LeanTLS.Handshake.HandshakeType.encryptedExtensions", 51, 51);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__15;
x_2 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__17() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__18() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__17;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__19() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__20() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__19;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__21() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("LeanTLS.Handshake.HandshakeType.certificate", 43, 43);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__21;
x_2 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__23() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__24() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__23;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__25() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__26() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__25;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__27() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("LeanTLS.Handshake.HandshakeType.certificateVerify", 49, 49);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__27;
x_2 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__29() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__30() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__29;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__31() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__32() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__31;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__33() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("LeanTLS.Handshake.HandshakeType.finished", 40, 40);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__33;
x_2 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__35() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__36() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__35;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__37() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34;
x_3 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__38() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__37;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259_(uint8_t x_1, lean_object* x_2) {
_start:
{
switch (x_1) {
case 0:
{
lean_object* x_3; uint8_t x_4; 
x_3 = lean_unsigned_to_nat(1024u);
x_4 = lean_nat_dec_le(x_3, x_2);
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; 
x_5 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__5;
x_6 = l_Repr_addAppParen(x_5, x_2);
return x_6;
}
else
{
lean_object* x_7; lean_object* x_8; 
x_7 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__8;
x_8 = l_Repr_addAppParen(x_7, x_2);
return x_8;
}
}
case 1:
{
lean_object* x_9; uint8_t x_10; 
x_9 = lean_unsigned_to_nat(1024u);
x_10 = lean_nat_dec_le(x_9, x_2);
if (x_10 == 0)
{
lean_object* x_11; lean_object* x_12; 
x_11 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__12;
x_12 = l_Repr_addAppParen(x_11, x_2);
return x_12;
}
else
{
lean_object* x_13; lean_object* x_14; 
x_13 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__14;
x_14 = l_Repr_addAppParen(x_13, x_2);
return x_14;
}
}
case 2:
{
lean_object* x_15; uint8_t x_16; 
x_15 = lean_unsigned_to_nat(1024u);
x_16 = lean_nat_dec_le(x_15, x_2);
if (x_16 == 0)
{
lean_object* x_17; lean_object* x_18; 
x_17 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__18;
x_18 = l_Repr_addAppParen(x_17, x_2);
return x_18;
}
else
{
lean_object* x_19; lean_object* x_20; 
x_19 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__20;
x_20 = l_Repr_addAppParen(x_19, x_2);
return x_20;
}
}
case 3:
{
lean_object* x_21; uint8_t x_22; 
x_21 = lean_unsigned_to_nat(1024u);
x_22 = lean_nat_dec_le(x_21, x_2);
if (x_22 == 0)
{
lean_object* x_23; lean_object* x_24; 
x_23 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__24;
x_24 = l_Repr_addAppParen(x_23, x_2);
return x_24;
}
else
{
lean_object* x_25; lean_object* x_26; 
x_25 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__26;
x_26 = l_Repr_addAppParen(x_25, x_2);
return x_26;
}
}
case 4:
{
lean_object* x_27; uint8_t x_28; 
x_27 = lean_unsigned_to_nat(1024u);
x_28 = lean_nat_dec_le(x_27, x_2);
if (x_28 == 0)
{
lean_object* x_29; lean_object* x_30; 
x_29 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__30;
x_30 = l_Repr_addAppParen(x_29, x_2);
return x_30;
}
else
{
lean_object* x_31; lean_object* x_32; 
x_31 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__32;
x_32 = l_Repr_addAppParen(x_31, x_2);
return x_32;
}
}
default: 
{
lean_object* x_33; uint8_t x_34; 
x_33 = lean_unsigned_to_nat(1024u);
x_34 = lean_nat_dec_le(x_33, x_2);
if (x_34 == 0)
{
lean_object* x_35; lean_object* x_36; 
x_35 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__36;
x_36 = l_Repr_addAppParen(x_35, x_2);
return x_36;
}
else
{
lean_object* x_37; lean_object* x_38; 
x_37 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__38;
x_38 = l_Repr_addAppParen(x_37, x_2);
return x_38;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
lean_dec(x_1);
x_4 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259_(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_instReprHandshakeType___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____boxed), 2, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_instReprHandshakeType() {
_start:
{
lean_object* x_1; 
x_1 = l_LeanTLS_Handshake_instReprHandshakeType___closed__1;
return x_1;
}
}
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_HandshakeType_toByte(uint8_t x_1) {
_start:
{
switch (x_1) {
case 0:
{
uint8_t x_2; 
x_2 = 1;
return x_2;
}
case 1:
{
uint8_t x_3; 
x_3 = 2;
return x_3;
}
case 2:
{
uint8_t x_4; 
x_4 = 8;
return x_4;
}
case 3:
{
uint8_t x_5; 
x_5 = 11;
return x_5;
}
case 4:
{
uint8_t x_6; 
x_6 = 15;
return x_6;
}
default: 
{
uint8_t x_7; 
x_7 = 20;
return x_7;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_toByte___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; uint8_t x_3; lean_object* x_4; 
x_2 = lean_unbox(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Handshake_HandshakeType_toByte(x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__1() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 5;
x_2 = lean_box(x_1);
x_3 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_3, 0, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__2() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 4;
x_2 = lean_box(x_1);
x_3 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_3, 0, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__3() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 3;
x_2 = lean_box(x_1);
x_3 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_3, 0, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__4() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 2;
x_2 = lean_box(x_1);
x_3 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_3, 0, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__5() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 1;
x_2 = lean_box(x_1);
x_3 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_3, 0, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__6() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 0;
x_2 = lean_box(x_1);
x_3 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_3, 0, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte(uint8_t x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; uint8_t x_4; 
x_2 = lean_uint8_to_nat(x_1);
x_3 = lean_unsigned_to_nat(1u);
x_4 = lean_nat_dec_eq(x_2, x_3);
if (x_4 == 0)
{
lean_object* x_5; uint8_t x_6; 
x_5 = lean_unsigned_to_nat(2u);
x_6 = lean_nat_dec_eq(x_2, x_5);
if (x_6 == 0)
{
lean_object* x_7; uint8_t x_8; 
x_7 = lean_unsigned_to_nat(8u);
x_8 = lean_nat_dec_eq(x_2, x_7);
if (x_8 == 0)
{
lean_object* x_9; uint8_t x_10; 
x_9 = lean_unsigned_to_nat(11u);
x_10 = lean_nat_dec_eq(x_2, x_9);
if (x_10 == 0)
{
lean_object* x_11; uint8_t x_12; 
x_11 = lean_unsigned_to_nat(15u);
x_12 = lean_nat_dec_eq(x_2, x_11);
if (x_12 == 0)
{
lean_object* x_13; uint8_t x_14; 
x_13 = lean_unsigned_to_nat(20u);
x_14 = lean_nat_dec_eq(x_2, x_13);
lean_dec(x_2);
if (x_14 == 0)
{
lean_object* x_15; 
x_15 = lean_box(0);
return x_15;
}
else
{
lean_object* x_16; 
x_16 = l_LeanTLS_Handshake_HandshakeType_fromByte___closed__1;
return x_16;
}
}
else
{
lean_object* x_17; 
lean_dec(x_2);
x_17 = l_LeanTLS_Handshake_HandshakeType_fromByte___closed__2;
return x_17;
}
}
else
{
lean_object* x_18; 
lean_dec(x_2);
x_18 = l_LeanTLS_Handshake_HandshakeType_fromByte___closed__3;
return x_18;
}
}
else
{
lean_object* x_19; 
lean_dec(x_2);
x_19 = l_LeanTLS_Handshake_HandshakeType_fromByte___closed__4;
return x_19;
}
}
else
{
lean_object* x_20; 
lean_dec(x_2);
x_20 = l_LeanTLS_Handshake_HandshakeType_fromByte___closed__5;
return x_20;
}
}
else
{
lean_object* x_21; 
lean_dec(x_2);
x_21 = l_LeanTLS_Handshake_HandshakeType_fromByte___closed__6;
return x_21;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeType_fromByte___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Handshake_HandshakeType_fromByte(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_encode(lean_object* x_1) {
_start:
{
uint8_t x_2; uint8_t x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint32_t x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_2 = lean_ctor_get_uint8(x_1, sizeof(void*)*1);
x_3 = l_LeanTLS_Handshake_HandshakeType_toByte(x_2);
x_4 = lean_box(0);
x_5 = lean_box(x_3);
x_6 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_6, 0, x_5);
lean_ctor_set(x_6, 1, x_4);
x_7 = lean_array_mk(x_6);
x_8 = lean_byte_array_mk(x_7);
x_9 = lean_ctor_get(x_1, 0);
x_10 = lean_byte_array_size(x_9);
x_11 = lean_uint32_of_nat(x_10);
lean_dec(x_10);
x_12 = l_LeanTLS_Handshake_encodeUInt24BE(x_11);
x_13 = l_ByteArray_append(x_8, x_12);
lean_dec(x_12);
x_14 = l_ByteArray_append(x_13, x_9);
return x_14;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_encode___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Handshake_HandshakeMessage_encode(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_decode(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; uint8_t x_4; 
x_2 = lean_byte_array_size(x_1);
x_3 = lean_unsigned_to_nat(4u);
x_4 = lean_nat_dec_lt(x_2, x_3);
if (x_4 == 0)
{
lean_object* x_5; uint8_t x_6; lean_object* x_7; 
x_5 = lean_unsigned_to_nat(0u);
x_6 = lean_byte_array_get(x_1, x_5);
x_7 = l_LeanTLS_Handshake_HandshakeType_fromByte(x_6);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_8; 
lean_dec(x_2);
x_8 = lean_box(0);
return x_8;
}
else
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_9 = lean_ctor_get(x_7, 0);
lean_inc(x_9);
lean_dec(x_7);
x_10 = lean_unsigned_to_nat(1u);
x_11 = l_LeanTLS_Handshake_decodeUInt24BE(x_1, x_10);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; 
lean_dec(x_9);
lean_dec(x_2);
x_12 = lean_box(0);
return x_12;
}
else
{
uint8_t x_13; 
x_13 = !lean_is_exclusive(x_11);
if (x_13 == 0)
{
lean_object* x_14; uint32_t x_15; lean_object* x_16; lean_object* x_17; uint8_t x_18; 
x_14 = lean_ctor_get(x_11, 0);
x_15 = lean_unbox_uint32(x_14);
lean_dec(x_14);
x_16 = lean_uint32_to_nat(x_15);
x_17 = lean_nat_add(x_3, x_16);
lean_dec(x_16);
x_18 = lean_nat_dec_lt(x_2, x_17);
if (x_18 == 0)
{
lean_object* x_19; lean_object* x_20; lean_object* x_21; uint8_t x_22; lean_object* x_23; 
x_19 = l_ByteArray_extract(x_1, x_3, x_17);
x_20 = l_ByteArray_extract(x_1, x_17, x_2);
lean_dec(x_2);
x_21 = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(x_21, 0, x_19);
x_22 = lean_unbox(x_9);
lean_dec(x_9);
lean_ctor_set_uint8(x_21, sizeof(void*)*1, x_22);
x_23 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_23, 0, x_21);
lean_ctor_set(x_23, 1, x_20);
lean_ctor_set(x_11, 0, x_23);
return x_11;
}
else
{
lean_object* x_24; 
lean_dec(x_17);
lean_free_object(x_11);
lean_dec(x_9);
lean_dec(x_2);
x_24 = lean_box(0);
return x_24;
}
}
else
{
lean_object* x_25; uint32_t x_26; lean_object* x_27; lean_object* x_28; uint8_t x_29; 
x_25 = lean_ctor_get(x_11, 0);
lean_inc(x_25);
lean_dec(x_11);
x_26 = lean_unbox_uint32(x_25);
lean_dec(x_25);
x_27 = lean_uint32_to_nat(x_26);
x_28 = lean_nat_add(x_3, x_27);
lean_dec(x_27);
x_29 = lean_nat_dec_lt(x_2, x_28);
if (x_29 == 0)
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; uint8_t x_33; lean_object* x_34; lean_object* x_35; 
x_30 = l_ByteArray_extract(x_1, x_3, x_28);
x_31 = l_ByteArray_extract(x_1, x_28, x_2);
lean_dec(x_2);
x_32 = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(x_32, 0, x_30);
x_33 = lean_unbox(x_9);
lean_dec(x_9);
lean_ctor_set_uint8(x_32, sizeof(void*)*1, x_33);
x_34 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_34, 0, x_32);
lean_ctor_set(x_34, 1, x_31);
x_35 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_35, 0, x_34);
return x_35;
}
else
{
lean_object* x_36; 
lean_dec(x_28);
lean_dec(x_9);
lean_dec(x_2);
x_36 = lean_box(0);
return x_36;
}
}
}
}
}
else
{
lean_object* x_37; 
lean_dec(x_2);
x_37 = lean_box(0);
return x_37;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_HandshakeMessage_decode___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Handshake_HandshakeMessage_decode(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(uint16_t x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint16_t x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; 
x_3 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
x_4 = lean_byte_array_size(x_2);
x_5 = lean_uint16_of_nat(x_4);
lean_dec(x_4);
x_6 = l_LeanTLS_Handshake_encodeUInt16BE(x_5);
x_7 = l_ByteArray_append(x_3, x_6);
lean_dec(x_6);
x_8 = l_ByteArray_append(x_7, x_2);
return x_8;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint16_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
lean_dec(x_1);
x_4 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__1() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 2;
x_2 = lean_box(0);
x_3 = lean_box(x_1);
x_4 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_4, 0, x_3);
lean_ctor_set(x_4, 1, x_2);
return x_4;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__1;
x_2 = lean_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__2;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__4() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 772;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__3;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__4;
x_3 = l_ByteArray_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__6() {
_start:
{
uint16_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 43;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__5;
x_3 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt() {
_start:
{
lean_object* x_1; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__6;
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 2;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 29;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2;
x_3 = l_ByteArray_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__4() {
_start:
{
uint16_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 10;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__3;
x_3 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt() {
_start:
{
lean_object* x_1; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__4;
return x_1;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildKeyShareExt(lean_object* x_1) {
_start:
{
lean_object* x_2; uint16_t x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; uint16_t x_9; lean_object* x_10; lean_object* x_11; uint16_t x_12; lean_object* x_13; 
x_2 = lean_byte_array_size(x_1);
x_3 = lean_uint16_of_nat(x_2);
lean_dec(x_2);
x_4 = l_LeanTLS_Handshake_encodeUInt16BE(x_3);
x_5 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2;
x_6 = l_ByteArray_append(x_5, x_4);
lean_dec(x_4);
x_7 = l_ByteArray_append(x_6, x_1);
x_8 = lean_byte_array_size(x_7);
x_9 = lean_uint16_of_nat(x_8);
lean_dec(x_8);
x_10 = l_LeanTLS_Handshake_encodeUInt16BE(x_9);
x_11 = l_ByteArray_append(x_10, x_7);
lean_dec(x_7);
x_12 = 51;
x_13 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(x_12, x_11);
lean_dec(x_11);
return x_13;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildKeyShareExt___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildKeyShareExt(x_1);
lean_dec(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__1() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 2052;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__2() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 1027;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__1;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__2;
x_3 = l_ByteArray_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3;
x_2 = lean_byte_array_size(x_1);
return x_2;
}
}
static uint16_t _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__5() {
_start:
{
lean_object* x_1; uint16_t x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__4;
x_2 = lean_uint16_of_nat(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__6() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__5;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__6;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3;
x_3 = l_ByteArray_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__8() {
_start:
{
uint16_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 13;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__7;
x_3 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildExtension(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt() {
_start:
{
lean_object* x_1; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__8;
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__1() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 771;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__2() {
_start:
{
uint16_t x_1; lean_object* x_2; 
x_1 = 4865;
x_2 = l_LeanTLS_Handshake_encodeUInt16BE(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__3() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_box(0);
x_2 = 0;
x_3 = lean_box(x_2);
x_4 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_4, 0, x_3);
lean_ctor_set(x_4, 1, x_1);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__4() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 1;
x_2 = l_LeanTLS_Handshake_buildClientHello___closed__3;
x_3 = lean_box(x_1);
x_4 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_4, 0, x_3);
lean_ctor_set(x_4, 1, x_2);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_buildClientHello___closed__4;
x_2 = lean_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_buildClientHello___closed__5;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_buildClientHello___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt;
x_3 = l_ByteArray_append(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildClientHello(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; uint16_t x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; uint8_t x_32; lean_object* x_33; lean_object* x_34; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = l_LeanTLS_Handshake_buildClientHello___closed__1;
x_5 = l_ByteArray_append(x_4, x_3);
x_6 = lean_ctor_get(x_1, 1);
x_7 = lean_byte_array_size(x_6);
x_8 = lean_uint8_of_nat(x_7);
lean_dec(x_7);
x_9 = lean_box(0);
x_10 = lean_box(x_8);
x_11 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_11, 0, x_10);
lean_ctor_set(x_11, 1, x_9);
x_12 = lean_array_mk(x_11);
x_13 = lean_byte_array_mk(x_12);
x_14 = l_ByteArray_append(x_5, x_13);
lean_dec(x_13);
x_15 = l_ByteArray_append(x_14, x_6);
x_16 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1;
x_17 = l_ByteArray_append(x_15, x_16);
x_18 = l_LeanTLS_Handshake_buildClientHello___closed__2;
x_19 = l_ByteArray_append(x_17, x_18);
x_20 = l_LeanTLS_Handshake_buildClientHello___closed__6;
x_21 = l_ByteArray_append(x_19, x_20);
x_22 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildKeyShareExt(x_2);
x_23 = l_LeanTLS_Handshake_buildClientHello___closed__7;
x_24 = l_ByteArray_append(x_23, x_22);
lean_dec(x_22);
x_25 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt;
x_26 = l_ByteArray_append(x_24, x_25);
x_27 = lean_byte_array_size(x_26);
x_28 = lean_uint16_of_nat(x_27);
lean_dec(x_27);
x_29 = l_LeanTLS_Handshake_encodeUInt16BE(x_28);
x_30 = l_ByteArray_append(x_21, x_29);
lean_dec(x_29);
x_31 = l_ByteArray_append(x_30, x_26);
lean_dec(x_26);
x_32 = 0;
x_33 = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(x_33, 0, x_31);
lean_ctor_set_uint8(x_33, sizeof(void*)*1, x_32);
x_34 = l_LeanTLS_Handshake_HandshakeMessage_encode(x_33);
lean_dec(x_33);
return x_34;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildClientHello___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Handshake_buildClientHello(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions_go(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; 
x_5 = lean_nat_dec_le(x_2, x_3);
if (x_5 == 0)
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = lean_unsigned_to_nat(4u);
x_7 = lean_nat_add(x_3, x_6);
x_8 = lean_nat_dec_lt(x_2, x_7);
if (x_8 == 0)
{
lean_object* x_9; 
x_9 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_3);
if (lean_obj_tag(x_9) == 0)
{
lean_dec(x_7);
lean_dec(x_3);
return x_4;
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_10 = lean_ctor_get(x_9, 0);
lean_inc(x_10);
lean_dec(x_9);
x_11 = lean_unsigned_to_nat(2u);
x_12 = lean_nat_add(x_3, x_11);
lean_dec(x_3);
x_13 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_12);
lean_dec(x_12);
if (lean_obj_tag(x_13) == 0)
{
lean_dec(x_10);
lean_dec(x_7);
return x_4;
}
else
{
lean_object* x_14; uint16_t x_15; lean_object* x_16; lean_object* x_17; uint8_t x_18; 
x_14 = lean_ctor_get(x_13, 0);
lean_inc(x_14);
lean_dec(x_13);
x_15 = lean_unbox(x_14);
lean_dec(x_14);
x_16 = lean_uint16_to_nat(x_15);
x_17 = lean_nat_add(x_7, x_16);
x_18 = lean_nat_dec_lt(x_2, x_17);
if (x_18 == 0)
{
uint16_t x_19; uint16_t x_20; uint8_t x_21; 
x_19 = 51;
x_20 = lean_unbox(x_10);
lean_dec(x_10);
x_21 = lean_uint16_dec_eq(x_20, x_19);
if (x_21 == 0)
{
lean_dec(x_16);
lean_dec(x_7);
x_3 = x_17;
goto _start;
}
else
{
uint8_t x_23; 
x_23 = lean_nat_dec_le(x_6, x_16);
lean_dec(x_16);
if (x_23 == 0)
{
lean_dec(x_7);
x_3 = x_17;
goto _start;
}
else
{
lean_object* x_25; 
x_25 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_7);
if (lean_obj_tag(x_25) == 0)
{
lean_dec(x_7);
x_3 = x_17;
goto _start;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; 
x_27 = lean_ctor_get(x_25, 0);
lean_inc(x_27);
lean_dec(x_25);
x_28 = lean_nat_add(x_7, x_11);
x_29 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_28);
lean_dec(x_28);
if (lean_obj_tag(x_29) == 0)
{
lean_dec(x_27);
lean_dec(x_7);
x_3 = x_17;
goto _start;
}
else
{
lean_object* x_31; uint16_t x_32; uint16_t x_33; uint8_t x_34; 
x_31 = lean_ctor_get(x_29, 0);
lean_inc(x_31);
lean_dec(x_29);
x_32 = 29;
x_33 = lean_unbox(x_27);
lean_dec(x_27);
x_34 = lean_uint16_dec_eq(x_33, x_32);
if (x_34 == 0)
{
lean_dec(x_31);
lean_dec(x_7);
x_3 = x_17;
goto _start;
}
else
{
lean_object* x_36; uint16_t x_37; lean_object* x_38; lean_object* x_39; 
x_36 = lean_nat_add(x_7, x_6);
lean_dec(x_7);
x_37 = lean_unbox(x_31);
lean_dec(x_31);
x_38 = lean_uint16_to_nat(x_37);
x_39 = l_LeanTLS_Handshake_extractBytes(x_1, x_36, x_38);
lean_dec(x_38);
if (lean_obj_tag(x_39) == 0)
{
x_3 = x_17;
goto _start;
}
else
{
uint8_t x_41; 
lean_dec(x_4);
x_41 = !lean_is_exclusive(x_39);
if (x_41 == 0)
{
x_3 = x_17;
x_4 = x_39;
goto _start;
}
else
{
lean_object* x_43; lean_object* x_44; 
x_43 = lean_ctor_get(x_39, 0);
lean_inc(x_43);
lean_dec(x_39);
x_44 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_44, 0, x_43);
x_3 = x_17;
x_4 = x_44;
goto _start;
}
}
}
}
}
}
}
}
else
{
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_10);
lean_dec(x_7);
return x_4;
}
}
}
}
else
{
lean_dec(x_7);
lean_dec(x_3);
return x_4;
}
}
else
{
lean_dec(x_3);
return x_4;
}
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions_go___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions_go(x_1, x_2, x_3, x_4);
lean_dec(x_2);
lean_dec(x_1);
return x_5;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_box(0);
x_5 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions_go(x_1, x_3, x_2, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello___lambda__1(lean_object* x_1, lean_object* x_2, uint16_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; 
x_6 = lean_alloc_ctor(0, 3, 2);
lean_ctor_set(x_6, 0, x_1);
lean_ctor_set(x_6, 1, x_2);
lean_ctor_set(x_6, 2, x_5);
lean_ctor_set_uint16(x_6, sizeof(void*)*3, x_3);
x_7 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_7, 0, x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; uint8_t x_4; 
x_2 = lean_byte_array_size(x_1);
x_3 = lean_unsigned_to_nat(38u);
x_4 = lean_nat_dec_lt(x_2, x_3);
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_unsigned_to_nat(2u);
x_6 = lean_unsigned_to_nat(32u);
x_7 = l_LeanTLS_Handshake_extractBytes(x_1, x_5, x_6);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_8; 
lean_dec(x_2);
x_8 = lean_box(0);
return x_8;
}
else
{
lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; uint8_t x_15; 
x_9 = lean_ctor_get(x_7, 0);
lean_inc(x_9);
lean_dec(x_7);
x_10 = lean_unsigned_to_nat(34u);
x_11 = lean_byte_array_get(x_1, x_10);
x_12 = lean_uint8_to_nat(x_11);
x_13 = lean_unsigned_to_nat(35u);
x_14 = lean_nat_add(x_13, x_12);
x_15 = lean_nat_dec_lt(x_2, x_14);
if (x_15 == 0)
{
lean_object* x_16; 
x_16 = l_LeanTLS_Handshake_extractBytes(x_1, x_13, x_12);
lean_dec(x_12);
if (lean_obj_tag(x_16) == 0)
{
lean_object* x_17; 
lean_dec(x_14);
lean_dec(x_9);
lean_dec(x_2);
x_17 = lean_box(0);
return x_17;
}
else
{
lean_object* x_18; lean_object* x_19; uint8_t x_20; 
x_18 = lean_ctor_get(x_16, 0);
lean_inc(x_18);
lean_dec(x_16);
x_19 = lean_nat_add(x_14, x_5);
x_20 = lean_nat_dec_lt(x_2, x_19);
if (x_20 == 0)
{
lean_object* x_21; 
x_21 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_14);
lean_dec(x_14);
if (lean_obj_tag(x_21) == 0)
{
lean_object* x_22; 
lean_dec(x_19);
lean_dec(x_18);
lean_dec(x_9);
lean_dec(x_2);
x_22 = lean_box(0);
return x_22;
}
else
{
lean_object* x_23; lean_object* x_24; lean_object* x_25; uint8_t x_26; 
x_23 = lean_ctor_get(x_21, 0);
lean_inc(x_23);
lean_dec(x_21);
x_24 = lean_unsigned_to_nat(1u);
x_25 = lean_nat_add(x_19, x_24);
lean_dec(x_19);
x_26 = lean_nat_dec_lt(x_2, x_25);
if (x_26 == 0)
{
lean_object* x_27; uint8_t x_28; 
x_27 = lean_nat_add(x_25, x_5);
x_28 = lean_nat_dec_le(x_27, x_2);
if (x_28 == 0)
{
lean_object* x_29; uint16_t x_30; lean_object* x_31; 
lean_dec(x_27);
lean_dec(x_2);
x_29 = lean_box(0);
x_30 = lean_unbox(x_23);
lean_dec(x_23);
x_31 = l_LeanTLS_Handshake_parseServerHello___lambda__1(x_9, x_18, x_30, x_25, x_29);
lean_dec(x_25);
return x_31;
}
else
{
lean_object* x_32; 
x_32 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_25);
lean_dec(x_25);
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_33; 
lean_dec(x_27);
lean_dec(x_23);
lean_dec(x_18);
lean_dec(x_9);
lean_dec(x_2);
x_33 = lean_box(0);
return x_33;
}
else
{
lean_object* x_34; uint16_t x_35; lean_object* x_36; lean_object* x_37; uint8_t x_38; 
x_34 = lean_ctor_get(x_32, 0);
lean_inc(x_34);
lean_dec(x_32);
x_35 = lean_unbox(x_34);
lean_dec(x_34);
x_36 = lean_uint16_to_nat(x_35);
x_37 = lean_nat_add(x_27, x_36);
lean_dec(x_36);
x_38 = lean_nat_dec_lt(x_2, x_37);
lean_dec(x_2);
if (x_38 == 0)
{
lean_object* x_39; uint16_t x_40; lean_object* x_41; 
lean_inc(x_27);
x_39 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_parseServerExtensions(x_1, x_27, x_37);
lean_dec(x_37);
x_40 = lean_unbox(x_23);
lean_dec(x_23);
x_41 = l_LeanTLS_Handshake_parseServerHello___lambda__1(x_9, x_18, x_40, x_27, x_39);
lean_dec(x_27);
return x_41;
}
else
{
lean_object* x_42; uint16_t x_43; lean_object* x_44; 
lean_dec(x_37);
x_42 = lean_box(0);
x_43 = lean_unbox(x_23);
lean_dec(x_23);
x_44 = l_LeanTLS_Handshake_parseServerHello___lambda__1(x_9, x_18, x_43, x_27, x_42);
lean_dec(x_27);
return x_44;
}
}
}
}
else
{
lean_object* x_45; 
lean_dec(x_25);
lean_dec(x_23);
lean_dec(x_18);
lean_dec(x_9);
lean_dec(x_2);
x_45 = lean_box(0);
return x_45;
}
}
}
else
{
lean_object* x_46; 
lean_dec(x_19);
lean_dec(x_18);
lean_dec(x_14);
lean_dec(x_9);
lean_dec(x_2);
x_46 = lean_box(0);
return x_46;
}
}
}
else
{
lean_object* x_47; 
lean_dec(x_14);
lean_dec(x_12);
lean_dec(x_9);
lean_dec(x_2);
x_47 = lean_box(0);
return x_47;
}
}
}
else
{
lean_object* x_48; 
lean_dec(x_2);
x_48 = lean_box(0);
return x_48;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint16_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
lean_dec(x_3);
x_7 = l_LeanTLS_Handshake_parseServerHello___lambda__1(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_4);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_parseServerHello___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Handshake_parseServerHello(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildFinishedVerifyData(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Crypto_HMAC_hmacSHA256(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_buildFinishedVerifyData___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Handshake_buildFinishedVerifyData(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t l_Nat_foldTR_loop___at_LeanTLS_Handshake_verifyFinished___spec__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, uint8_t x_6) {
_start:
{
lean_object* x_7; uint8_t x_8; 
x_7 = lean_unsigned_to_nat(0u);
x_8 = lean_nat_dec_eq(x_4, x_7);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; uint8_t x_13; uint8_t x_14; uint8_t x_15; uint8_t x_16; 
x_9 = lean_unsigned_to_nat(1u);
x_10 = lean_nat_sub(x_4, x_9);
lean_dec(x_4);
x_11 = lean_nat_add(x_10, x_9);
x_12 = lean_nat_sub(x_3, x_11);
lean_dec(x_11);
x_13 = lean_byte_array_get(x_2, x_12);
x_14 = lean_byte_array_get(x_1, x_12);
lean_dec(x_12);
x_15 = lean_uint8_xor(x_13, x_14);
x_16 = lean_uint8_lor(x_6, x_15);
x_4 = x_10;
x_5 = lean_box(0);
x_6 = x_16;
goto _start;
}
else
{
lean_dec(x_4);
return x_6;
}
}
}
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_verifyFinished(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_4 = l_LeanTLS_Crypto_HMAC_hmacSHA256(x_1, x_2);
x_5 = lean_byte_array_size(x_4);
x_6 = lean_byte_array_size(x_3);
x_7 = lean_nat_dec_eq(x_5, x_6);
lean_dec(x_6);
if (x_7 == 0)
{
uint8_t x_8; 
lean_dec(x_5);
lean_dec(x_4);
x_8 = 0;
return x_8;
}
else
{
uint8_t x_9; uint8_t x_10; uint8_t x_11; 
x_9 = 0;
lean_inc(x_5);
x_10 = l_Nat_foldTR_loop___at_LeanTLS_Handshake_verifyFinished___spec__1(x_3, x_4, x_5, x_5, lean_box(0), x_9);
lean_dec(x_5);
lean_dec(x_4);
x_11 = lean_uint8_dec_eq(x_10, x_9);
return x_11;
}
}
}
LEAN_EXPORT lean_object* l_Nat_foldTR_loop___at_LeanTLS_Handshake_verifyFinished___spec__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
uint8_t x_7; uint8_t x_8; lean_object* x_9; 
x_7 = lean_unbox(x_6);
lean_dec(x_6);
x_8 = l_Nat_foldTR_loop___at_LeanTLS_Handshake_verifyFinished___spec__1(x_1, x_2, x_3, x_4, x_5, x_7);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_9 = lean_box(x_8);
return x_9;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_verifyFinished___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Handshake_verifyFinished(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_2);
x_5 = lean_box(x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_LeanTLS_Handshake_transcriptHash___spec__1(lean_object* x_1, size_t x_2, size_t x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; 
x_5 = lean_usize_dec_eq(x_2, x_3);
if (x_5 == 0)
{
lean_object* x_6; lean_object* x_7; size_t x_8; size_t x_9; 
x_6 = lean_array_uget(x_1, x_2);
x_7 = l_ByteArray_append(x_4, x_6);
lean_dec(x_6);
x_8 = 1;
x_9 = lean_usize_add(x_2, x_8);
x_2 = x_9;
x_4 = x_7;
goto _start;
}
else
{
return x_4;
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_transcriptHash___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_ByteArray_empty;
x_2 = l_LeanTLS_Crypto_SHA256_hash(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_transcriptHash(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; uint8_t x_4; 
x_2 = lean_array_get_size(x_1);
x_3 = lean_unsigned_to_nat(0u);
x_4 = lean_nat_dec_lt(x_3, x_2);
if (x_4 == 0)
{
lean_object* x_5; 
lean_dec(x_2);
x_5 = l_LeanTLS_Handshake_transcriptHash___closed__1;
return x_5;
}
else
{
uint8_t x_6; 
x_6 = lean_nat_dec_le(x_2, x_2);
if (x_6 == 0)
{
lean_object* x_7; 
lean_dec(x_2);
x_7 = l_LeanTLS_Handshake_transcriptHash___closed__1;
return x_7;
}
else
{
size_t x_8; size_t x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; 
x_8 = 0;
x_9 = lean_usize_of_nat(x_2);
lean_dec(x_2);
x_10 = l_ByteArray_empty;
x_11 = l_Array_foldlMUnsafe_fold___at_LeanTLS_Handshake_transcriptHash___spec__1(x_1, x_8, x_9, x_10);
x_12 = l_LeanTLS_Crypto_SHA256_hash(x_11);
return x_12;
}
}
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_LeanTLS_Handshake_transcriptHash___spec__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
size_t x_5; size_t x_6; lean_object* x_7; 
x_5 = lean_unbox_usize(x_2);
lean_dec(x_2);
x_6 = lean_unbox_usize(x_3);
lean_dec(x_3);
x_7 = l_Array_foldlMUnsafe_fold___at_LeanTLS_Handshake_transcriptHash___spec__1(x_1, x_5, x_6, x_4);
lean_dec(x_1);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_transcriptHash___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Handshake_transcriptHash(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT uint8_t l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble(uint32_t x_1) {
_start:
{
lean_object* x_2; lean_object* x_16; uint32_t x_30; uint8_t x_31; 
x_30 = 48;
x_31 = lean_uint32_dec_le(x_30, x_1);
if (x_31 == 0)
{
lean_object* x_32; 
x_32 = lean_box(0);
x_16 = x_32;
goto block_29;
}
else
{
uint32_t x_33; uint8_t x_34; 
x_33 = 57;
x_34 = lean_uint32_dec_le(x_1, x_33);
if (x_34 == 0)
{
lean_object* x_35; 
x_35 = lean_box(0);
x_16 = x_35;
goto block_29;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; uint8_t x_39; 
x_36 = lean_uint32_to_nat(x_1);
x_37 = lean_unsigned_to_nat(48u);
x_38 = lean_nat_sub(x_36, x_37);
lean_dec(x_36);
x_39 = lean_uint8_of_nat(x_38);
lean_dec(x_38);
return x_39;
}
}
block_15:
{
uint32_t x_3; uint8_t x_4; 
lean_dec(x_2);
x_3 = 65;
x_4 = lean_uint32_dec_le(x_3, x_1);
if (x_4 == 0)
{
uint8_t x_5; 
x_5 = 0;
return x_5;
}
else
{
uint32_t x_6; uint8_t x_7; 
x_6 = 70;
x_7 = lean_uint32_dec_le(x_1, x_6);
if (x_7 == 0)
{
uint8_t x_8; 
x_8 = 0;
return x_8;
}
else
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; uint8_t x_14; 
x_9 = lean_uint32_to_nat(x_1);
x_10 = lean_unsigned_to_nat(65u);
x_11 = lean_nat_sub(x_9, x_10);
lean_dec(x_9);
x_12 = lean_unsigned_to_nat(10u);
x_13 = lean_nat_add(x_11, x_12);
lean_dec(x_11);
x_14 = lean_uint8_of_nat(x_13);
lean_dec(x_13);
return x_14;
}
}
}
block_29:
{
uint32_t x_17; uint8_t x_18; 
lean_dec(x_16);
x_17 = 97;
x_18 = lean_uint32_dec_le(x_17, x_1);
if (x_18 == 0)
{
lean_object* x_19; 
x_19 = lean_box(0);
x_2 = x_19;
goto block_15;
}
else
{
uint32_t x_20; uint8_t x_21; 
x_20 = 102;
x_21 = lean_uint32_dec_le(x_1, x_20);
if (x_21 == 0)
{
lean_object* x_22; 
x_22 = lean_box(0);
x_2 = x_22;
goto block_15;
}
else
{
lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; uint8_t x_28; 
x_23 = lean_uint32_to_nat(x_1);
x_24 = lean_unsigned_to_nat(97u);
x_25 = lean_nat_sub(x_23, x_24);
lean_dec(x_23);
x_26 = lean_unsigned_to_nat(10u);
x_27 = lean_nat_add(x_25, x_26);
lean_dec(x_25);
x_28 = lean_uint8_of_nat(x_27);
lean_dec(x_27);
return x_28;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble___boxed(lean_object* x_1) {
_start:
{
uint32_t x_2; uint8_t x_3; lean_object* x_4; 
x_2 = lean_unbox_uint32(x_1);
lean_dec(x_1);
x_3 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble(x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes_go(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_3; 
x_3 = lean_byte_array_mk(x_2);
return x_3;
}
else
{
lean_object* x_4; 
x_4 = lean_ctor_get(x_1, 1);
lean_inc(x_4);
if (lean_obj_tag(x_4) == 0)
{
lean_object* x_5; 
lean_dec(x_1);
x_5 = lean_byte_array_mk(x_2);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; uint32_t x_9; uint8_t x_10; uint32_t x_11; uint8_t x_12; uint8_t x_13; uint8_t x_14; uint8_t x_15; lean_object* x_16; lean_object* x_17; 
x_6 = lean_ctor_get(x_1, 0);
lean_inc(x_6);
lean_dec(x_1);
x_7 = lean_ctor_get(x_4, 0);
lean_inc(x_7);
x_8 = lean_ctor_get(x_4, 1);
lean_inc(x_8);
lean_dec(x_4);
x_9 = lean_unbox_uint32(x_6);
lean_dec(x_6);
x_10 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble(x_9);
x_11 = lean_unbox_uint32(x_7);
lean_dec(x_7);
x_12 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexCharToNibble(x_11);
x_13 = 4;
x_14 = lean_uint8_shift_left(x_10, x_13);
x_15 = lean_uint8_lor(x_14, x_12);
x_16 = lean_box(x_15);
x_17 = lean_array_push(x_2, x_16);
x_1 = x_8;
x_2 = x_17;
goto _start;
}
}
}
}
static lean_object* _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_box(0);
x_2 = lean_array_mk(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_2 = lean_string_data(x_1);
x_3 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes___closed__1;
x_4 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes_go(x_2, x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_runTests_containsVersion(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; 
x_4 = lean_unsigned_to_nat(2u);
x_5 = lean_nat_add(x_2, x_4);
x_6 = lean_nat_dec_lt(x_3, x_5);
lean_dec(x_5);
if (x_6 == 0)
{
lean_object* x_7; 
x_7 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_2);
if (lean_obj_tag(x_7) == 0)
{
uint8_t x_8; 
lean_dec(x_2);
x_8 = 0;
return x_8;
}
else
{
lean_object* x_9; uint16_t x_10; uint16_t x_11; uint8_t x_12; 
x_9 = lean_ctor_get(x_7, 0);
lean_inc(x_9);
lean_dec(x_7);
x_10 = 772;
x_11 = lean_unbox(x_9);
lean_dec(x_9);
x_12 = lean_uint16_dec_eq(x_11, x_10);
if (x_12 == 0)
{
lean_object* x_13; lean_object* x_14; 
x_13 = lean_unsigned_to_nat(1u);
x_14 = lean_nat_add(x_2, x_13);
lean_dec(x_2);
x_2 = x_14;
goto _start;
}
else
{
uint8_t x_16; 
lean_dec(x_2);
x_16 = 1;
return x_16;
}
}
}
else
{
uint8_t x_17; 
lean_dec(x_2);
x_17 = 0;
return x_17;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests_containsVersion___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Handshake_runTests_containsVersion(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_1);
x_5 = lean_box(x_4);
return x_5;
}
}
LEAN_EXPORT uint8_t l_LeanTLS_Handshake_runTests_go(lean_object* x_1, lean_object* x_2, lean_object* x_3, uint8_t x_4) {
_start:
{
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_5 = lean_unsigned_to_nat(4u);
x_6 = lean_nat_add(x_2, x_5);
x_7 = lean_nat_dec_lt(x_3, x_6);
if (x_7 == 0)
{
lean_object* x_8; 
x_8 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_2);
if (lean_obj_tag(x_8) == 0)
{
uint8_t x_9; 
lean_dec(x_6);
lean_dec(x_2);
x_9 = 0;
return x_9;
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_10 = lean_ctor_get(x_8, 0);
lean_inc(x_10);
lean_dec(x_8);
x_11 = lean_unsigned_to_nat(2u);
x_12 = lean_nat_add(x_2, x_11);
lean_dec(x_2);
x_13 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_12);
lean_dec(x_12);
if (lean_obj_tag(x_13) == 0)
{
uint8_t x_14; 
lean_dec(x_10);
lean_dec(x_6);
x_14 = 0;
return x_14;
}
else
{
lean_object* x_15; uint16_t x_16; lean_object* x_17; lean_object* x_18; uint8_t x_19; 
x_15 = lean_ctor_get(x_13, 0);
lean_inc(x_15);
lean_dec(x_13);
x_16 = lean_unbox(x_15);
lean_dec(x_15);
x_17 = lean_uint16_to_nat(x_16);
x_18 = lean_nat_add(x_6, x_17);
lean_dec(x_17);
x_19 = lean_nat_dec_lt(x_3, x_18);
if (x_19 == 0)
{
uint16_t x_20; uint16_t x_21; uint8_t x_22; 
x_20 = 43;
x_21 = lean_unbox(x_10);
lean_dec(x_10);
x_22 = lean_uint16_dec_eq(x_21, x_20);
if (x_22 == 0)
{
uint8_t x_23; 
lean_dec(x_6);
x_23 = 0;
x_2 = x_18;
x_4 = x_23;
goto _start;
}
else
{
uint8_t x_25; 
x_25 = l_LeanTLS_Handshake_runTests_containsVersion(x_1, x_6, x_18);
lean_dec(x_18);
return x_25;
}
}
else
{
uint8_t x_26; 
lean_dec(x_18);
lean_dec(x_10);
lean_dec(x_6);
x_26 = 0;
return x_26;
}
}
}
}
else
{
uint8_t x_27; 
lean_dec(x_6);
lean_dec(x_2);
x_27 = 0;
return x_27;
}
}
else
{
uint8_t x_28; 
lean_dec(x_2);
x_28 = 1;
return x_28;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests_go___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; uint8_t x_6; lean_object* x_7; 
x_5 = lean_unbox(x_4);
lean_dec(x_4);
x_6 = l_LeanTLS_Handshake_runTests_go(x_1, x_2, x_3, x_5);
lean_dec(x_3);
lean_dec(x_1);
x_7 = lean_box(x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__1(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_box(x_1);
x_5 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_5, 0, x_4);
lean_ctor_set(x_5, 1, x_3);
return x_5;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__2___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  All Handshake tests passed.", 29, 29);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__2(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (x_1 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_box(x_1);
x_5 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_5, 0, x_4);
lean_ctor_set(x_5, 1, x_3);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; 
x_6 = l_LeanTLS_Handshake_runTests___lambda__2___closed__1;
x_7 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_6, x_3);
if (lean_obj_tag(x_7) == 0)
{
uint8_t x_8; 
x_8 = !lean_is_exclusive(x_7);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = lean_ctor_get(x_7, 0);
lean_dec(x_9);
x_10 = lean_box(x_1);
lean_ctor_set(x_7, 0, x_10);
return x_7;
}
else
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_11 = lean_ctor_get(x_7, 1);
lean_inc(x_11);
lean_dec(x_7);
x_12 = lean_box(x_1);
x_13 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_13, 0, x_12);
lean_ctor_set(x_13, 1, x_11);
return x_13;
}
}
else
{
uint8_t x_14; 
x_14 = !lean_is_exclusive(x_7);
if (x_14 == 0)
{
return x_7;
}
else
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_7, 0);
x_16 = lean_ctor_get(x_7, 1);
lean_inc(x_16);
lean_inc(x_15);
lean_dec(x_7);
x_17 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
return x_17;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__1() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 255;
x_2 = lean_unsigned_to_nat(32u);
x_3 = lean_box(x_1);
x_4 = lean_mk_array(x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__3___closed__1;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_runTests___lambda__2___boxed), 3, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    verifyFinished (wrong data): OK", 35, 35);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    verifyFinished (wrong data): FAILED", 39, 39);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__3(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; uint8_t x_7; lean_object* x_8; 
x_6 = l_LeanTLS_Handshake_runTests___lambda__3___closed__2;
x_7 = l_LeanTLS_Handshake_verifyFinished(x_1, x_2, x_6);
x_8 = l_LeanTLS_Handshake_runTests___lambda__3___closed__3;
if (x_7 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = l_LeanTLS_Handshake_runTests___lambda__3___closed__4;
x_10 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_9, x_5);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_11 = lean_ctor_get(x_10, 0);
lean_inc(x_11);
x_12 = lean_ctor_get(x_10, 1);
lean_inc(x_12);
lean_dec(x_10);
x_13 = lean_box(x_3);
x_14 = lean_apply_3(x_8, x_13, x_11, x_12);
return x_14;
}
else
{
uint8_t x_15; 
x_15 = !lean_is_exclusive(x_10);
if (x_15 == 0)
{
return x_10;
}
else
{
lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_16 = lean_ctor_get(x_10, 0);
x_17 = lean_ctor_get(x_10, 1);
lean_inc(x_17);
lean_inc(x_16);
lean_dec(x_10);
x_18 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_18, 0, x_16);
lean_ctor_set(x_18, 1, x_17);
return x_18;
}
}
}
else
{
lean_object* x_19; lean_object* x_20; 
x_19 = l_LeanTLS_Handshake_runTests___lambda__3___closed__5;
x_20 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_19, x_5);
if (lean_obj_tag(x_20) == 0)
{
lean_object* x_21; uint8_t x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; 
x_21 = lean_ctor_get(x_20, 1);
lean_inc(x_21);
lean_dec(x_20);
x_22 = 0;
x_23 = lean_box(0);
x_24 = lean_box(x_22);
x_25 = lean_apply_3(x_8, x_24, x_23, x_21);
return x_25;
}
else
{
uint8_t x_26; 
x_26 = !lean_is_exclusive(x_20);
if (x_26 == 0)
{
return x_20;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; 
x_27 = lean_ctor_get(x_20, 0);
x_28 = lean_ctor_get(x_20, 1);
lean_inc(x_28);
lean_inc(x_27);
lean_dec(x_20);
x_29 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_29, 0, x_27);
lean_ctor_set(x_29, 1, x_28);
return x_29;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__4___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    verifyFinished (correct): FAILED", 36, 36);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__4___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    verifyFinished (correct): OK", 32, 32);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__4(lean_object* x_1, lean_object* x_2, lean_object* x_3, uint8_t x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
uint8_t x_7; 
lean_inc(x_1);
x_7 = l_LeanTLS_Handshake_verifyFinished(x_1, x_2, x_3);
if (x_7 == 0)
{
lean_object* x_8; lean_object* x_9; 
x_8 = l_LeanTLS_Handshake_runTests___lambda__4___closed__1;
x_9 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_8, x_6);
if (lean_obj_tag(x_9) == 0)
{
lean_object* x_10; uint8_t x_11; lean_object* x_12; lean_object* x_13; 
x_10 = lean_ctor_get(x_9, 1);
lean_inc(x_10);
lean_dec(x_9);
x_11 = 0;
x_12 = lean_box(0);
x_13 = l_LeanTLS_Handshake_runTests___lambda__3(x_1, x_2, x_11, x_12, x_10);
return x_13;
}
else
{
uint8_t x_14; 
lean_dec(x_1);
x_14 = !lean_is_exclusive(x_9);
if (x_14 == 0)
{
return x_9;
}
else
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_9, 0);
x_16 = lean_ctor_get(x_9, 1);
lean_inc(x_16);
lean_inc(x_15);
lean_dec(x_9);
x_17 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
return x_17;
}
}
}
else
{
lean_object* x_18; lean_object* x_19; 
x_18 = l_LeanTLS_Handshake_runTests___lambda__4___closed__2;
x_19 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_18, x_6);
if (lean_obj_tag(x_19) == 0)
{
lean_object* x_20; lean_object* x_21; lean_object* x_22; 
x_20 = lean_ctor_get(x_19, 0);
lean_inc(x_20);
x_21 = lean_ctor_get(x_19, 1);
lean_inc(x_21);
lean_dec(x_19);
x_22 = l_LeanTLS_Handshake_runTests___lambda__3(x_1, x_2, x_4, x_20, x_21);
lean_dec(x_20);
return x_22;
}
else
{
uint8_t x_23; 
lean_dec(x_1);
x_23 = !lean_is_exclusive(x_19);
if (x_23 == 0)
{
return x_19;
}
else
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_24 = lean_ctor_get(x_19, 0);
x_25 = lean_ctor_get(x_19, 1);
lean_inc(x_25);
lean_inc(x_24);
lean_dec(x_19);
x_26 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
return x_26;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Handshake test 4 (Finished verify_data):", 42, 42);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__5___closed__2;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__5___closed__4;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__5___closed__3;
x_2 = l_LeanTLS_Handshake_runTests___lambda__5___closed__5;
x_3 = l_LeanTLS_Crypto_HMAC_hmacSHA256(x_1, x_2);
return x_3;
}
}
static uint8_t _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__7() {
_start:
{
lean_object* x_1; uint8_t x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__5___closed__6;
x_2 = l_LeanTLS_Handshake_byteArrayEq(x_1, x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__8() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    buildFinishedVerifyData: FAILED", 35, 35);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__9() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    buildFinishedVerifyData: OK", 31, 31);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__5(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Handshake_runTests___lambda__5___closed__1;
x_5 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_4, x_3);
if (lean_obj_tag(x_5) == 0)
{
lean_object* x_6; uint8_t x_7; 
x_6 = lean_ctor_get(x_5, 1);
lean_inc(x_6);
lean_dec(x_5);
x_7 = l_LeanTLS_Handshake_runTests___lambda__5___closed__7;
if (x_7 == 0)
{
lean_object* x_8; lean_object* x_9; 
x_8 = l_LeanTLS_Handshake_runTests___lambda__5___closed__8;
x_9 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_8, x_6);
if (lean_obj_tag(x_9) == 0)
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; uint8_t x_14; lean_object* x_15; lean_object* x_16; 
x_10 = lean_ctor_get(x_9, 1);
lean_inc(x_10);
lean_dec(x_9);
x_11 = l_LeanTLS_Handshake_runTests___lambda__5___closed__3;
x_12 = l_LeanTLS_Handshake_runTests___lambda__5___closed__5;
x_13 = l_LeanTLS_Handshake_runTests___lambda__5___closed__6;
x_14 = 0;
x_15 = lean_box(0);
x_16 = l_LeanTLS_Handshake_runTests___lambda__4(x_11, x_12, x_13, x_14, x_15, x_10);
return x_16;
}
else
{
uint8_t x_17; 
x_17 = !lean_is_exclusive(x_9);
if (x_17 == 0)
{
return x_9;
}
else
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; 
x_18 = lean_ctor_get(x_9, 0);
x_19 = lean_ctor_get(x_9, 1);
lean_inc(x_19);
lean_inc(x_18);
lean_dec(x_9);
x_20 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_20, 0, x_18);
lean_ctor_set(x_20, 1, x_19);
return x_20;
}
}
}
else
{
lean_object* x_21; lean_object* x_22; 
x_21 = l_LeanTLS_Handshake_runTests___lambda__5___closed__9;
x_22 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_21, x_6);
if (lean_obj_tag(x_22) == 0)
{
lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_23 = lean_ctor_get(x_22, 0);
lean_inc(x_23);
x_24 = lean_ctor_get(x_22, 1);
lean_inc(x_24);
lean_dec(x_22);
x_25 = l_LeanTLS_Handshake_runTests___lambda__5___closed__3;
x_26 = l_LeanTLS_Handshake_runTests___lambda__5___closed__5;
x_27 = l_LeanTLS_Handshake_runTests___lambda__5___closed__6;
x_28 = l_LeanTLS_Handshake_runTests___lambda__4(x_25, x_26, x_27, x_1, x_23, x_24);
lean_dec(x_23);
return x_28;
}
else
{
uint8_t x_29; 
x_29 = !lean_is_exclusive(x_22);
if (x_29 == 0)
{
return x_22;
}
else
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_30 = lean_ctor_get(x_22, 0);
x_31 = lean_ctor_get(x_22, 1);
lean_inc(x_31);
lean_inc(x_30);
lean_dec(x_22);
x_32 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_31);
return x_32;
}
}
}
}
else
{
uint8_t x_33; 
x_33 = !lean_is_exclusive(x_5);
if (x_33 == 0)
{
return x_5;
}
else
{
lean_object* x_34; lean_object* x_35; lean_object* x_36; 
x_34 = lean_ctor_get(x_5, 0);
x_35 = lean_ctor_get(x_5, 1);
lean_inc(x_35);
lean_inc(x_34);
lean_dec(x_5);
x_36 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_36, 0, x_34);
lean_ctor_set(x_36, 1, x_35);
return x_36;
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Handshake test 3 (transcript hash):", 37, 37);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("010203", 6, 6);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__2;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("040506", 6, 6);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__4;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__5;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__3;
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__6;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__7;
x_2 = lean_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__8;
x_2 = l_LeanTLS_Handshake_transcriptHash(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__10() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("010203040506", 12, 12);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__10;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__12() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__11;
x_2 = l_LeanTLS_Crypto_SHA256_hash(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__13() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_runTests___lambda__5___boxed), 3, 0);
return x_1;
}
}
static uint8_t _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__14() {
_start:
{
lean_object* x_1; lean_object* x_2; uint8_t x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__9;
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__12;
x_3 = l_LeanTLS_Handshake_byteArrayEq(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__15() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    FAILED", 10, 10);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__16() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__12;
x_2 = l_LeanTLS_Crypto_SHA256_toHex(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__17() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    expected: ", 14, 14);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__18() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__17;
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__16;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__19() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("", 0, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__20() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__18;
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__21() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__9;
x_2 = l_LeanTLS_Crypto_SHA256_toHex(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__22() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    got:      ", 14, 14);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__23() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__22;
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__21;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__24() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__6___closed__23;
x_2 = l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__25() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    PASSED", 10, 10);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__6(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Handshake_runTests___lambda__6___closed__1;
x_5 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_4, x_3);
if (lean_obj_tag(x_5) == 0)
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = lean_ctor_get(x_5, 1);
lean_inc(x_6);
lean_dec(x_5);
x_7 = l_LeanTLS_Handshake_runTests___lambda__6___closed__13;
x_8 = l_LeanTLS_Handshake_runTests___lambda__6___closed__14;
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = l_LeanTLS_Handshake_runTests___lambda__6___closed__15;
x_10 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_9, x_6);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_11 = lean_ctor_get(x_10, 1);
lean_inc(x_11);
lean_dec(x_10);
x_12 = l_LeanTLS_Handshake_runTests___lambda__6___closed__20;
x_13 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_12, x_11);
if (lean_obj_tag(x_13) == 0)
{
lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_14 = lean_ctor_get(x_13, 1);
lean_inc(x_14);
lean_dec(x_13);
x_15 = l_LeanTLS_Handshake_runTests___lambda__6___closed__24;
x_16 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_15, x_14);
if (lean_obj_tag(x_16) == 0)
{
lean_object* x_17; uint8_t x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; 
x_17 = lean_ctor_get(x_16, 1);
lean_inc(x_17);
lean_dec(x_16);
x_18 = 0;
x_19 = lean_box(0);
x_20 = lean_box(x_18);
x_21 = lean_apply_3(x_7, x_20, x_19, x_17);
return x_21;
}
else
{
uint8_t x_22; 
x_22 = !lean_is_exclusive(x_16);
if (x_22 == 0)
{
return x_16;
}
else
{
lean_object* x_23; lean_object* x_24; lean_object* x_25; 
x_23 = lean_ctor_get(x_16, 0);
x_24 = lean_ctor_get(x_16, 1);
lean_inc(x_24);
lean_inc(x_23);
lean_dec(x_16);
x_25 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_25, 0, x_23);
lean_ctor_set(x_25, 1, x_24);
return x_25;
}
}
}
else
{
uint8_t x_26; 
x_26 = !lean_is_exclusive(x_13);
if (x_26 == 0)
{
return x_13;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; 
x_27 = lean_ctor_get(x_13, 0);
x_28 = lean_ctor_get(x_13, 1);
lean_inc(x_28);
lean_inc(x_27);
lean_dec(x_13);
x_29 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_29, 0, x_27);
lean_ctor_set(x_29, 1, x_28);
return x_29;
}
}
}
else
{
uint8_t x_30; 
x_30 = !lean_is_exclusive(x_10);
if (x_30 == 0)
{
return x_10;
}
else
{
lean_object* x_31; lean_object* x_32; lean_object* x_33; 
x_31 = lean_ctor_get(x_10, 0);
x_32 = lean_ctor_get(x_10, 1);
lean_inc(x_32);
lean_inc(x_31);
lean_dec(x_10);
x_33 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_33, 0, x_31);
lean_ctor_set(x_33, 1, x_32);
return x_33;
}
}
}
else
{
lean_object* x_34; lean_object* x_35; 
x_34 = l_LeanTLS_Handshake_runTests___lambda__6___closed__25;
x_35 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_34, x_6);
if (lean_obj_tag(x_35) == 0)
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; 
x_36 = lean_ctor_get(x_35, 0);
lean_inc(x_36);
x_37 = lean_ctor_get(x_35, 1);
lean_inc(x_37);
lean_dec(x_35);
x_38 = lean_box(x_1);
x_39 = lean_apply_3(x_7, x_38, x_36, x_37);
return x_39;
}
else
{
uint8_t x_40; 
x_40 = !lean_is_exclusive(x_35);
if (x_40 == 0)
{
return x_35;
}
else
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_41 = lean_ctor_get(x_35, 0);
x_42 = lean_ctor_get(x_35, 1);
lean_inc(x_42);
lean_inc(x_41);
lean_dec(x_35);
x_43 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_43, 0, x_41);
lean_ctor_set(x_43, 1, x_42);
return x_43;
}
}
}
}
else
{
uint8_t x_44; 
x_44 = !lean_is_exclusive(x_5);
if (x_44 == 0)
{
return x_5;
}
else
{
lean_object* x_45; lean_object* x_46; lean_object* x_47; 
x_45 = lean_ctor_get(x_5, 0);
x_46 = lean_ctor_get(x_5, 1);
lean_inc(x_46);
lean_inc(x_45);
lean_dec(x_5);
x_47 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_47, 0, x_45);
lean_ctor_set(x_47, 1, x_46);
return x_47;
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__7___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_runTests___lambda__6___boxed), 3, 0);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__7(uint8_t x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_LeanTLS_Handshake_runTests___lambda__7___closed__1;
if (x_2 == 0)
{
uint8_t x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_6 = 0;
x_7 = lean_box(0);
x_8 = lean_box(x_6);
x_9 = lean_apply_3(x_5, x_8, x_7, x_4);
return x_9;
}
else
{
lean_object* x_10; lean_object* x_11; 
x_10 = l_LeanTLS_Handshake_runTests___lambda__6___closed__25;
x_11 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_10, x_4);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_12 = lean_ctor_get(x_11, 0);
lean_inc(x_12);
x_13 = lean_ctor_get(x_11, 1);
lean_inc(x_13);
lean_dec(x_11);
x_14 = lean_box(x_1);
x_15 = lean_apply_3(x_5, x_14, x_12, x_13);
return x_15;
}
else
{
uint8_t x_16; 
x_16 = !lean_is_exclusive(x_11);
if (x_16 == 0)
{
return x_11;
}
else
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; 
x_17 = lean_ctor_get(x_11, 0);
x_18 = lean_ctor_get(x_11, 1);
lean_inc(x_18);
lean_inc(x_17);
lean_dec(x_11);
x_19 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
return x_19;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__8___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_runTests___lambda__7___boxed), 4, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__8___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    supported_versions with 0x0304: FAILED (not found)", 54, 54);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__8___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    supported_versions with 0x0304: OK", 38, 38);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__8(lean_object* x_1, uint8_t x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; uint8_t x_9; lean_object* x_10; 
x_6 = lean_byte_array_size(x_1);
x_7 = lean_unsigned_to_nat(79u);
x_8 = 0;
x_9 = l_LeanTLS_Handshake_runTests_go(x_1, x_7, x_6, x_8);
lean_dec(x_6);
x_10 = l_LeanTLS_Handshake_runTests___lambda__8___closed__1;
if (x_9 == 0)
{
lean_object* x_11; lean_object* x_12; 
x_11 = l_LeanTLS_Handshake_runTests___lambda__8___closed__2;
x_12 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_11, x_5);
if (lean_obj_tag(x_12) == 0)
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_13 = lean_ctor_get(x_12, 1);
lean_inc(x_13);
lean_dec(x_12);
x_14 = lean_box(0);
x_15 = lean_box(x_2);
x_16 = lean_box(x_8);
x_17 = lean_apply_4(x_10, x_15, x_16, x_14, x_13);
return x_17;
}
else
{
uint8_t x_18; 
x_18 = !lean_is_exclusive(x_12);
if (x_18 == 0)
{
return x_12;
}
else
{
lean_object* x_19; lean_object* x_20; lean_object* x_21; 
x_19 = lean_ctor_get(x_12, 0);
x_20 = lean_ctor_get(x_12, 1);
lean_inc(x_20);
lean_inc(x_19);
lean_dec(x_12);
x_21 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_21, 0, x_19);
lean_ctor_set(x_21, 1, x_20);
return x_21;
}
}
}
else
{
lean_object* x_22; lean_object* x_23; 
x_22 = l_LeanTLS_Handshake_runTests___lambda__8___closed__3;
x_23 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_22, x_5);
if (lean_obj_tag(x_23) == 0)
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_24 = lean_ctor_get(x_23, 0);
lean_inc(x_24);
x_25 = lean_ctor_get(x_23, 1);
lean_inc(x_25);
lean_dec(x_23);
x_26 = lean_box(x_2);
x_27 = lean_box(x_3);
x_28 = lean_apply_4(x_10, x_26, x_27, x_24, x_25);
return x_28;
}
else
{
uint8_t x_29; 
x_29 = !lean_is_exclusive(x_23);
if (x_29 == 0)
{
return x_23;
}
else
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_30 = lean_ctor_get(x_23, 0);
x_31 = lean_ctor_get(x_23, 1);
lean_inc(x_31);
lean_inc(x_30);
lean_dec(x_23);
x_32 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_31);
return x_32;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    cipher_suite contains 0x1301: FAILED (too short)", 52, 52);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    cipher_suite contains 0x1301: FAILED (could not decode)", 59, 59);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    cipher_suite contains 0x1301: FAILED (got ", 46, 46);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked(")", 1, 1);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    cipher_suite contains 0x1301: OK", 36, 36);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__9(lean_object* x_1, uint8_t x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = lean_byte_array_size(x_1);
x_7 = lean_unsigned_to_nat(74u);
x_8 = lean_nat_dec_lt(x_7, x_6);
lean_dec(x_6);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = l_LeanTLS_Handshake_runTests___lambda__9___closed__1;
x_10 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_9, x_5);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; uint8_t x_12; lean_object* x_13; lean_object* x_14; 
x_11 = lean_ctor_get(x_10, 1);
lean_inc(x_11);
lean_dec(x_10);
x_12 = 0;
x_13 = lean_box(0);
x_14 = l_LeanTLS_Handshake_runTests___lambda__8(x_1, x_2, x_12, x_13, x_11);
return x_14;
}
else
{
uint8_t x_15; 
x_15 = !lean_is_exclusive(x_10);
if (x_15 == 0)
{
return x_10;
}
else
{
lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_16 = lean_ctor_get(x_10, 0);
x_17 = lean_ctor_get(x_10, 1);
lean_inc(x_17);
lean_inc(x_16);
lean_dec(x_10);
x_18 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_18, 0, x_16);
lean_ctor_set(x_18, 1, x_17);
return x_18;
}
}
}
else
{
lean_object* x_19; lean_object* x_20; 
x_19 = lean_unsigned_to_nat(73u);
x_20 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_19);
if (lean_obj_tag(x_20) == 0)
{
lean_object* x_21; lean_object* x_22; 
x_21 = l_LeanTLS_Handshake_runTests___lambda__9___closed__2;
x_22 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_21, x_5);
if (lean_obj_tag(x_22) == 0)
{
lean_object* x_23; uint8_t x_24; lean_object* x_25; lean_object* x_26; 
x_23 = lean_ctor_get(x_22, 1);
lean_inc(x_23);
lean_dec(x_22);
x_24 = 0;
x_25 = lean_box(0);
x_26 = l_LeanTLS_Handshake_runTests___lambda__8(x_1, x_2, x_24, x_25, x_23);
return x_26;
}
else
{
uint8_t x_27; 
x_27 = !lean_is_exclusive(x_22);
if (x_27 == 0)
{
return x_22;
}
else
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_28 = lean_ctor_get(x_22, 0);
x_29 = lean_ctor_get(x_22, 1);
lean_inc(x_29);
lean_inc(x_28);
lean_dec(x_22);
x_30 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_30, 0, x_28);
lean_ctor_set(x_30, 1, x_29);
return x_30;
}
}
}
else
{
lean_object* x_31; uint16_t x_32; uint16_t x_33; uint8_t x_34; 
x_31 = lean_ctor_get(x_20, 0);
lean_inc(x_31);
lean_dec(x_20);
x_32 = 4865;
x_33 = lean_unbox(x_31);
x_34 = lean_uint16_dec_eq(x_33, x_32);
if (x_34 == 0)
{
uint16_t x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; 
x_35 = lean_unbox(x_31);
lean_dec(x_31);
x_36 = lean_uint16_to_nat(x_35);
x_37 = l___private_Init_Data_Repr_0__Nat_reprFast(x_36);
x_38 = l_LeanTLS_Handshake_runTests___lambda__9___closed__3;
x_39 = lean_string_append(x_38, x_37);
lean_dec(x_37);
x_40 = l_LeanTLS_Handshake_runTests___lambda__9___closed__4;
x_41 = lean_string_append(x_39, x_40);
x_42 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_41, x_5);
if (lean_obj_tag(x_42) == 0)
{
lean_object* x_43; uint8_t x_44; lean_object* x_45; lean_object* x_46; 
x_43 = lean_ctor_get(x_42, 1);
lean_inc(x_43);
lean_dec(x_42);
x_44 = 0;
x_45 = lean_box(0);
x_46 = l_LeanTLS_Handshake_runTests___lambda__8(x_1, x_2, x_44, x_45, x_43);
return x_46;
}
else
{
uint8_t x_47; 
x_47 = !lean_is_exclusive(x_42);
if (x_47 == 0)
{
return x_42;
}
else
{
lean_object* x_48; lean_object* x_49; lean_object* x_50; 
x_48 = lean_ctor_get(x_42, 0);
x_49 = lean_ctor_get(x_42, 1);
lean_inc(x_49);
lean_inc(x_48);
lean_dec(x_42);
x_50 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_50, 0, x_48);
lean_ctor_set(x_50, 1, x_49);
return x_50;
}
}
}
else
{
lean_object* x_51; lean_object* x_52; 
lean_dec(x_31);
x_51 = l_LeanTLS_Handshake_runTests___lambda__9___closed__5;
x_52 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_51, x_5);
if (lean_obj_tag(x_52) == 0)
{
lean_object* x_53; lean_object* x_54; lean_object* x_55; 
x_53 = lean_ctor_get(x_52, 0);
lean_inc(x_53);
x_54 = lean_ctor_get(x_52, 1);
lean_inc(x_54);
lean_dec(x_52);
x_55 = l_LeanTLS_Handshake_runTests___lambda__8(x_1, x_2, x_3, x_53, x_54);
lean_dec(x_53);
return x_55;
}
else
{
uint8_t x_56; 
x_56 = !lean_is_exclusive(x_52);
if (x_56 == 0)
{
return x_52;
}
else
{
lean_object* x_57; lean_object* x_58; lean_object* x_59; 
x_57 = lean_ctor_get(x_52, 0);
x_58 = lean_ctor_get(x_52, 1);
lean_inc(x_58);
lean_inc(x_57);
lean_dec(x_52);
x_59 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_59, 0, x_57);
lean_ctor_set(x_59, 1, x_58);
return x_59;
}
}
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    legacy_version = 0x0303: FAILED (too short)", 47, 47);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    legacy_version = 0x0303: FAILED (could not decode)", 54, 54);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    legacy_version = 0x0303: FAILED (got 0x", 43, 43);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    legacy_version = 0x0303: OK", 31, 31);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__10(lean_object* x_1, uint8_t x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = lean_byte_array_size(x_1);
x_7 = lean_unsigned_to_nat(5u);
x_8 = lean_nat_dec_lt(x_7, x_6);
lean_dec(x_6);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = l_LeanTLS_Handshake_runTests___lambda__10___closed__1;
x_10 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_9, x_5);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; uint8_t x_12; lean_object* x_13; lean_object* x_14; 
x_11 = lean_ctor_get(x_10, 1);
lean_inc(x_11);
lean_dec(x_10);
x_12 = 0;
x_13 = lean_box(0);
x_14 = l_LeanTLS_Handshake_runTests___lambda__9(x_1, x_2, x_12, x_13, x_11);
return x_14;
}
else
{
uint8_t x_15; 
x_15 = !lean_is_exclusive(x_10);
if (x_15 == 0)
{
return x_10;
}
else
{
lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_16 = lean_ctor_get(x_10, 0);
x_17 = lean_ctor_get(x_10, 1);
lean_inc(x_17);
lean_inc(x_16);
lean_dec(x_10);
x_18 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_18, 0, x_16);
lean_ctor_set(x_18, 1, x_17);
return x_18;
}
}
}
else
{
lean_object* x_19; lean_object* x_20; 
x_19 = lean_unsigned_to_nat(4u);
x_20 = l_LeanTLS_Handshake_decodeUInt16BE(x_1, x_19);
if (lean_obj_tag(x_20) == 0)
{
lean_object* x_21; lean_object* x_22; 
x_21 = l_LeanTLS_Handshake_runTests___lambda__10___closed__2;
x_22 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_21, x_5);
if (lean_obj_tag(x_22) == 0)
{
lean_object* x_23; uint8_t x_24; lean_object* x_25; lean_object* x_26; 
x_23 = lean_ctor_get(x_22, 1);
lean_inc(x_23);
lean_dec(x_22);
x_24 = 0;
x_25 = lean_box(0);
x_26 = l_LeanTLS_Handshake_runTests___lambda__9(x_1, x_2, x_24, x_25, x_23);
return x_26;
}
else
{
uint8_t x_27; 
x_27 = !lean_is_exclusive(x_22);
if (x_27 == 0)
{
return x_22;
}
else
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_28 = lean_ctor_get(x_22, 0);
x_29 = lean_ctor_get(x_22, 1);
lean_inc(x_29);
lean_inc(x_28);
lean_dec(x_22);
x_30 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_30, 0, x_28);
lean_ctor_set(x_30, 1, x_29);
return x_30;
}
}
}
else
{
lean_object* x_31; uint16_t x_32; uint16_t x_33; uint8_t x_34; 
x_31 = lean_ctor_get(x_20, 0);
lean_inc(x_31);
lean_dec(x_20);
x_32 = 771;
x_33 = lean_unbox(x_31);
x_34 = lean_uint16_dec_eq(x_33, x_32);
if (x_34 == 0)
{
uint16_t x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; 
x_35 = lean_unbox(x_31);
lean_dec(x_31);
x_36 = l_LeanTLS_Handshake_encodeUInt16BE(x_35);
x_37 = l_LeanTLS_Crypto_SHA256_toHex(x_36);
lean_dec(x_36);
x_38 = l_LeanTLS_Handshake_runTests___lambda__10___closed__3;
x_39 = lean_string_append(x_38, x_37);
lean_dec(x_37);
x_40 = l_LeanTLS_Handshake_runTests___lambda__9___closed__4;
x_41 = lean_string_append(x_39, x_40);
x_42 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_41, x_5);
if (lean_obj_tag(x_42) == 0)
{
lean_object* x_43; uint8_t x_44; lean_object* x_45; lean_object* x_46; 
x_43 = lean_ctor_get(x_42, 1);
lean_inc(x_43);
lean_dec(x_42);
x_44 = 0;
x_45 = lean_box(0);
x_46 = l_LeanTLS_Handshake_runTests___lambda__9(x_1, x_2, x_44, x_45, x_43);
return x_46;
}
else
{
uint8_t x_47; 
x_47 = !lean_is_exclusive(x_42);
if (x_47 == 0)
{
return x_42;
}
else
{
lean_object* x_48; lean_object* x_49; lean_object* x_50; 
x_48 = lean_ctor_get(x_42, 0);
x_49 = lean_ctor_get(x_42, 1);
lean_inc(x_49);
lean_inc(x_48);
lean_dec(x_42);
x_50 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_50, 0, x_48);
lean_ctor_set(x_50, 1, x_49);
return x_50;
}
}
}
else
{
lean_object* x_51; lean_object* x_52; 
lean_dec(x_31);
x_51 = l_LeanTLS_Handshake_runTests___lambda__10___closed__4;
x_52 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_51, x_5);
if (lean_obj_tag(x_52) == 0)
{
lean_object* x_53; lean_object* x_54; lean_object* x_55; 
x_53 = lean_ctor_get(x_52, 0);
lean_inc(x_53);
x_54 = lean_ctor_get(x_52, 1);
lean_inc(x_54);
lean_dec(x_52);
x_55 = l_LeanTLS_Handshake_runTests___lambda__9(x_1, x_2, x_3, x_53, x_54);
lean_dec(x_53);
return x_55;
}
else
{
uint8_t x_56; 
x_56 = !lean_is_exclusive(x_52);
if (x_56 == 0)
{
return x_52;
}
else
{
lean_object* x_57; lean_object* x_58; lean_object* x_59; 
x_57 = lean_ctor_get(x_52, 0);
x_58 = lean_ctor_get(x_52, 1);
lean_inc(x_58);
lean_inc(x_57);
lean_dec(x_52);
x_59 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_59, 0, x_57);
lean_ctor_set(x_59, 1, x_58);
return x_59;
}
}
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Handshake test 2 (ClientHello construction):", 46, 46);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__2() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 170;
x_2 = lean_unsigned_to_nat(32u);
x_3 = lean_box(x_1);
x_4 = lean_mk_array(x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__2;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__4() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 187;
x_2 = lean_unsigned_to_nat(32u);
x_3 = lean_box(x_1);
x_4 = lean_mk_array(x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__4;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__6() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 204;
x_2 = lean_unsigned_to_nat(32u);
x_3 = lean_box(x_1);
x_4 = lean_mk_array(x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__6;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__3;
x_2 = l_LeanTLS_Handshake_runTests___lambda__11___closed__5;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__8;
x_2 = l_LeanTLS_Handshake_runTests___lambda__11___closed__7;
x_3 = l_LeanTLS_Handshake_buildClientHello(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__10() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__9;
x_2 = lean_byte_array_size(x_1);
return x_2;
}
}
static uint8_t _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; uint8_t x_3; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_LeanTLS_Handshake_runTests___lambda__11___closed__10;
x_3 = lean_nat_dec_lt(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__12() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    handshake type = 1: FAILED", 30, 30);
return x_1;
}
}
static uint8_t _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__13() {
_start:
{
lean_object* x_1; lean_object* x_2; uint8_t x_3; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__11___closed__9;
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_byte_array_get(x_1, x_2);
return x_3;
}
}
static uint8_t _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__14() {
_start:
{
uint8_t x_1; uint8_t x_2; uint8_t x_3; 
x_1 = 1;
x_2 = l_LeanTLS_Handshake_runTests___lambda__11___closed__13;
x_3 = lean_uint8_dec_eq(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__15() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    handshake type = 1: OK", 26, 26);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__11(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Handshake_runTests___lambda__11___closed__1;
x_5 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_4, x_3);
if (lean_obj_tag(x_5) == 0)
{
lean_object* x_6; uint8_t x_7; 
x_6 = lean_ctor_get(x_5, 1);
lean_inc(x_6);
lean_dec(x_5);
x_7 = l_LeanTLS_Handshake_runTests___lambda__11___closed__11;
if (x_7 == 0)
{
lean_object* x_8; lean_object* x_9; 
x_8 = l_LeanTLS_Handshake_runTests___lambda__11___closed__12;
x_9 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_8, x_6);
if (lean_obj_tag(x_9) == 0)
{
lean_object* x_10; lean_object* x_11; uint8_t x_12; lean_object* x_13; lean_object* x_14; 
x_10 = lean_ctor_get(x_9, 1);
lean_inc(x_10);
lean_dec(x_9);
x_11 = l_LeanTLS_Handshake_runTests___lambda__11___closed__9;
x_12 = 0;
x_13 = lean_box(0);
x_14 = l_LeanTLS_Handshake_runTests___lambda__10(x_11, x_1, x_12, x_13, x_10);
return x_14;
}
else
{
uint8_t x_15; 
x_15 = !lean_is_exclusive(x_9);
if (x_15 == 0)
{
return x_9;
}
else
{
lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_16 = lean_ctor_get(x_9, 0);
x_17 = lean_ctor_get(x_9, 1);
lean_inc(x_17);
lean_inc(x_16);
lean_dec(x_9);
x_18 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_18, 0, x_16);
lean_ctor_set(x_18, 1, x_17);
return x_18;
}
}
}
else
{
uint8_t x_19; 
x_19 = l_LeanTLS_Handshake_runTests___lambda__11___closed__14;
if (x_19 == 0)
{
lean_object* x_20; lean_object* x_21; 
x_20 = l_LeanTLS_Handshake_runTests___lambda__11___closed__12;
x_21 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_20, x_6);
if (lean_obj_tag(x_21) == 0)
{
lean_object* x_22; lean_object* x_23; uint8_t x_24; lean_object* x_25; lean_object* x_26; 
x_22 = lean_ctor_get(x_21, 1);
lean_inc(x_22);
lean_dec(x_21);
x_23 = l_LeanTLS_Handshake_runTests___lambda__11___closed__9;
x_24 = 0;
x_25 = lean_box(0);
x_26 = l_LeanTLS_Handshake_runTests___lambda__10(x_23, x_1, x_24, x_25, x_22);
return x_26;
}
else
{
uint8_t x_27; 
x_27 = !lean_is_exclusive(x_21);
if (x_27 == 0)
{
return x_21;
}
else
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_28 = lean_ctor_get(x_21, 0);
x_29 = lean_ctor_get(x_21, 1);
lean_inc(x_29);
lean_inc(x_28);
lean_dec(x_21);
x_30 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_30, 0, x_28);
lean_ctor_set(x_30, 1, x_29);
return x_30;
}
}
}
else
{
lean_object* x_31; lean_object* x_32; 
x_31 = l_LeanTLS_Handshake_runTests___lambda__11___closed__15;
x_32 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_31, x_6);
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; uint8_t x_36; lean_object* x_37; 
x_33 = lean_ctor_get(x_32, 0);
lean_inc(x_33);
x_34 = lean_ctor_get(x_32, 1);
lean_inc(x_34);
lean_dec(x_32);
x_35 = l_LeanTLS_Handshake_runTests___lambda__11___closed__9;
x_36 = 1;
x_37 = l_LeanTLS_Handshake_runTests___lambda__10(x_35, x_1, x_36, x_33, x_34);
lean_dec(x_33);
return x_37;
}
else
{
uint8_t x_38; 
x_38 = !lean_is_exclusive(x_32);
if (x_38 == 0)
{
return x_32;
}
else
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; 
x_39 = lean_ctor_get(x_32, 0);
x_40 = lean_ctor_get(x_32, 1);
lean_inc(x_40);
lean_inc(x_39);
lean_dec(x_32);
x_41 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_41, 0, x_39);
lean_ctor_set(x_41, 1, x_40);
return x_41;
}
}
}
}
}
else
{
uint8_t x_42; 
x_42 = !lean_is_exclusive(x_5);
if (x_42 == 0)
{
return x_5;
}
else
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; 
x_43 = lean_ctor_get(x_5, 0);
x_44 = lean_ctor_get(x_5, 1);
lean_inc(x_44);
lean_inc(x_43);
lean_dec(x_5);
x_45 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_45, 0, x_43);
lean_ctor_set(x_45, 1, x_44);
return x_45;
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Handshake test 1b (encode/decode with trailing data):", 55, 55);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("aabbccdd", 8, 8);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___lambda__12___closed__2;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Handshake_runTests___lambda__11___boxed), 3, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    FAILED (decode returned none)", 33, 33);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__6() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    FAILED (mismatch)", 21, 21);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__12(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; 
x_6 = l_LeanTLS_Handshake_runTests___lambda__12___closed__1;
x_7 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_6, x_5);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; 
x_8 = lean_ctor_get(x_7, 1);
lean_inc(x_8);
lean_dec(x_7);
x_9 = l_LeanTLS_Handshake_runTests___lambda__12___closed__3;
x_10 = l_ByteArray_append(x_1, x_9);
x_11 = l_LeanTLS_Handshake_runTests___lambda__12___closed__4;
x_12 = l_LeanTLS_Handshake_HandshakeMessage_decode(x_10);
lean_dec(x_10);
if (lean_obj_tag(x_12) == 0)
{
lean_object* x_13; lean_object* x_14; 
lean_dec(x_2);
x_13 = l_LeanTLS_Handshake_runTests___lambda__12___closed__5;
x_14 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_13, x_8);
if (lean_obj_tag(x_14) == 0)
{
lean_object* x_15; uint8_t x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; 
x_15 = lean_ctor_get(x_14, 1);
lean_inc(x_15);
lean_dec(x_14);
x_16 = 0;
x_17 = lean_box(0);
x_18 = lean_box(x_16);
x_19 = lean_apply_3(x_11, x_18, x_17, x_15);
return x_19;
}
else
{
uint8_t x_20; 
x_20 = !lean_is_exclusive(x_14);
if (x_20 == 0)
{
return x_14;
}
else
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_21 = lean_ctor_get(x_14, 0);
x_22 = lean_ctor_get(x_14, 1);
lean_inc(x_22);
lean_inc(x_21);
lean_dec(x_14);
x_23 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_23, 0, x_21);
lean_ctor_set(x_23, 1, x_22);
return x_23;
}
}
}
else
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; uint8_t x_27; uint8_t x_28; uint8_t x_29; 
x_24 = lean_ctor_get(x_12, 0);
lean_inc(x_24);
lean_dec(x_12);
x_25 = lean_ctor_get(x_24, 0);
lean_inc(x_25);
x_26 = lean_ctor_get(x_24, 1);
lean_inc(x_26);
lean_dec(x_24);
x_27 = lean_ctor_get_uint8(x_25, sizeof(void*)*1);
x_28 = 5;
x_29 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241_(x_27, x_28);
if (x_29 == 0)
{
lean_object* x_30; lean_object* x_31; 
lean_dec(x_26);
lean_dec(x_25);
lean_dec(x_2);
x_30 = l_LeanTLS_Handshake_runTests___lambda__12___closed__6;
x_31 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_30, x_8);
if (lean_obj_tag(x_31) == 0)
{
lean_object* x_32; uint8_t x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; 
x_32 = lean_ctor_get(x_31, 1);
lean_inc(x_32);
lean_dec(x_31);
x_33 = 0;
x_34 = lean_box(0);
x_35 = lean_box(x_33);
x_36 = lean_apply_3(x_11, x_35, x_34, x_32);
return x_36;
}
else
{
uint8_t x_37; 
x_37 = !lean_is_exclusive(x_31);
if (x_37 == 0)
{
return x_31;
}
else
{
lean_object* x_38; lean_object* x_39; lean_object* x_40; 
x_38 = lean_ctor_get(x_31, 0);
x_39 = lean_ctor_get(x_31, 1);
lean_inc(x_39);
lean_inc(x_38);
lean_dec(x_31);
x_40 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_40, 0, x_38);
lean_ctor_set(x_40, 1, x_39);
return x_40;
}
}
}
else
{
lean_object* x_41; uint8_t x_42; 
x_41 = lean_ctor_get(x_25, 0);
lean_inc(x_41);
lean_dec(x_25);
x_42 = l_LeanTLS_Handshake_byteArrayEq(x_41, x_2);
if (x_42 == 0)
{
lean_object* x_43; lean_object* x_44; 
lean_dec(x_26);
x_43 = l_LeanTLS_Handshake_runTests___lambda__12___closed__6;
x_44 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_43, x_8);
if (lean_obj_tag(x_44) == 0)
{
lean_object* x_45; uint8_t x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; 
x_45 = lean_ctor_get(x_44, 1);
lean_inc(x_45);
lean_dec(x_44);
x_46 = 0;
x_47 = lean_box(0);
x_48 = lean_box(x_46);
x_49 = lean_apply_3(x_11, x_48, x_47, x_45);
return x_49;
}
else
{
uint8_t x_50; 
x_50 = !lean_is_exclusive(x_44);
if (x_50 == 0)
{
return x_44;
}
else
{
lean_object* x_51; lean_object* x_52; lean_object* x_53; 
x_51 = lean_ctor_get(x_44, 0);
x_52 = lean_ctor_get(x_44, 1);
lean_inc(x_52);
lean_inc(x_51);
lean_dec(x_44);
x_53 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_53, 0, x_51);
lean_ctor_set(x_53, 1, x_52);
return x_53;
}
}
}
else
{
uint8_t x_54; 
x_54 = l_LeanTLS_Handshake_byteArrayEq(x_26, x_9);
if (x_54 == 0)
{
lean_object* x_55; lean_object* x_56; 
x_55 = l_LeanTLS_Handshake_runTests___lambda__12___closed__6;
x_56 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_55, x_8);
if (lean_obj_tag(x_56) == 0)
{
lean_object* x_57; uint8_t x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; 
x_57 = lean_ctor_get(x_56, 1);
lean_inc(x_57);
lean_dec(x_56);
x_58 = 0;
x_59 = lean_box(0);
x_60 = lean_box(x_58);
x_61 = lean_apply_3(x_11, x_60, x_59, x_57);
return x_61;
}
else
{
uint8_t x_62; 
x_62 = !lean_is_exclusive(x_56);
if (x_62 == 0)
{
return x_56;
}
else
{
lean_object* x_63; lean_object* x_64; lean_object* x_65; 
x_63 = lean_ctor_get(x_56, 0);
x_64 = lean_ctor_get(x_56, 1);
lean_inc(x_64);
lean_inc(x_63);
lean_dec(x_56);
x_65 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_65, 0, x_63);
lean_ctor_set(x_65, 1, x_64);
return x_65;
}
}
}
else
{
lean_object* x_66; lean_object* x_67; 
x_66 = l_LeanTLS_Handshake_runTests___lambda__6___closed__25;
x_67 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_66, x_8);
if (lean_obj_tag(x_67) == 0)
{
lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; 
x_68 = lean_ctor_get(x_67, 0);
lean_inc(x_68);
x_69 = lean_ctor_get(x_67, 1);
lean_inc(x_69);
lean_dec(x_67);
x_70 = lean_box(x_3);
x_71 = lean_apply_3(x_11, x_70, x_68, x_69);
return x_71;
}
else
{
uint8_t x_72; 
x_72 = !lean_is_exclusive(x_67);
if (x_72 == 0)
{
return x_67;
}
else
{
lean_object* x_73; lean_object* x_74; lean_object* x_75; 
x_73 = lean_ctor_get(x_67, 0);
x_74 = lean_ctor_get(x_67, 1);
lean_inc(x_74);
lean_inc(x_73);
lean_dec(x_67);
x_75 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_75, 0, x_73);
lean_ctor_set(x_75, 1, x_74);
return x_75;
}
}
}
}
}
}
}
else
{
uint8_t x_76; 
lean_dec(x_2);
lean_dec(x_1);
x_76 = !lean_is_exclusive(x_7);
if (x_76 == 0)
{
return x_7;
}
else
{
lean_object* x_77; lean_object* x_78; lean_object* x_79; 
x_77 = lean_ctor_get(x_7, 0);
x_78 = lean_ctor_get(x_7, 1);
lean_inc(x_78);
lean_inc(x_77);
lean_dec(x_7);
x_79 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_79, 0, x_77);
lean_ctor_set(x_79, 1, x_78);
return x_79;
}
}
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Handshake test 1 (encode/decode roundtrip):", 45, 45);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("deadbeef01020304", 16, 16);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___closed__2;
x_2 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__4() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 5;
x_2 = l_LeanTLS_Handshake_runTests___closed__3;
x_3 = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_1);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___closed__4;
x_2 = l_LeanTLS_Handshake_HandshakeMessage_encode(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Handshake_runTests___closed__5;
x_2 = l_LeanTLS_Handshake_HandshakeMessage_decode(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__7() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    type match: ", 16, 16);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__8() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked(", payload match: ", 17, 17);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__9() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("false", 5, 5);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__10() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked(", rest empty: ", 14, 14);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Handshake_runTests___closed__11() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("true", 4, 4);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = l_LeanTLS_Handshake_runTests___closed__1;
x_3 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_2, x_1);
if (lean_obj_tag(x_3) == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_ctor_get(x_3, 1);
lean_inc(x_4);
lean_dec(x_3);
x_5 = l_LeanTLS_Handshake_runTests___closed__6;
if (lean_obj_tag(x_5) == 0)
{
lean_object* x_6; lean_object* x_7; 
x_6 = l_LeanTLS_Handshake_runTests___lambda__12___closed__5;
x_7 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_6, x_4);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; lean_object* x_13; 
x_8 = lean_ctor_get(x_7, 1);
lean_inc(x_8);
lean_dec(x_7);
x_9 = l_LeanTLS_Handshake_runTests___closed__5;
x_10 = l_LeanTLS_Handshake_runTests___closed__3;
x_11 = 0;
x_12 = lean_box(0);
x_13 = l_LeanTLS_Handshake_runTests___lambda__12(x_9, x_10, x_11, x_12, x_8);
return x_13;
}
else
{
uint8_t x_14; 
x_14 = !lean_is_exclusive(x_7);
if (x_14 == 0)
{
return x_7;
}
else
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_7, 0);
x_16 = lean_ctor_get(x_7, 1);
lean_inc(x_16);
lean_inc(x_15);
lean_dec(x_7);
x_17 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
return x_17;
}
}
}
else
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; uint8_t x_21; uint8_t x_22; uint8_t x_23; lean_object* x_24; lean_object* x_25; uint8_t x_26; lean_object* x_27; lean_object* x_28; uint8_t x_29; lean_object* x_30; 
x_18 = lean_ctor_get(x_5, 0);
lean_inc(x_18);
x_19 = lean_ctor_get(x_18, 0);
lean_inc(x_19);
x_20 = lean_ctor_get(x_18, 1);
lean_inc(x_20);
lean_dec(x_18);
x_21 = lean_ctor_get_uint8(x_19, sizeof(void*)*1);
x_22 = 5;
x_23 = l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_beqHandshakeType____x40_LeanTLS_Handshake___hyg_241_(x_21, x_22);
x_24 = lean_ctor_get(x_19, 0);
lean_inc(x_24);
lean_dec(x_19);
x_25 = l_LeanTLS_Handshake_runTests___closed__3;
x_26 = l_LeanTLS_Handshake_byteArrayEq(x_24, x_25);
x_27 = lean_byte_array_size(x_20);
lean_dec(x_20);
x_28 = lean_unsigned_to_nat(0u);
x_29 = lean_nat_dec_eq(x_27, x_28);
lean_dec(x_27);
if (x_23 == 0)
{
lean_object* x_109; 
x_109 = lean_box(0);
x_30 = x_109;
goto block_108;
}
else
{
if (x_26 == 0)
{
lean_object* x_110; 
x_110 = lean_box(0);
x_30 = x_110;
goto block_108;
}
else
{
if (x_29 == 0)
{
lean_object* x_111; 
x_111 = lean_box(0);
x_30 = x_111;
goto block_108;
}
else
{
lean_object* x_112; lean_object* x_113; 
x_112 = l_LeanTLS_Handshake_runTests___lambda__6___closed__25;
x_113 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_112, x_4);
if (lean_obj_tag(x_113) == 0)
{
lean_object* x_114; lean_object* x_115; lean_object* x_116; uint8_t x_117; lean_object* x_118; 
x_114 = lean_ctor_get(x_113, 0);
lean_inc(x_114);
x_115 = lean_ctor_get(x_113, 1);
lean_inc(x_115);
lean_dec(x_113);
x_116 = l_LeanTLS_Handshake_runTests___closed__5;
x_117 = 1;
x_118 = l_LeanTLS_Handshake_runTests___lambda__12(x_116, x_25, x_117, x_114, x_115);
lean_dec(x_114);
return x_118;
}
else
{
uint8_t x_119; 
x_119 = !lean_is_exclusive(x_113);
if (x_119 == 0)
{
return x_113;
}
else
{
lean_object* x_120; lean_object* x_121; lean_object* x_122; 
x_120 = lean_ctor_get(x_113, 0);
x_121 = lean_ctor_get(x_113, 1);
lean_inc(x_121);
lean_inc(x_120);
lean_dec(x_113);
x_122 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_122, 0, x_120);
lean_ctor_set(x_122, 1, x_121);
return x_122;
}
}
}
}
}
block_108:
{
lean_object* x_31; lean_object* x_32; 
lean_dec(x_30);
x_31 = l_LeanTLS_Handshake_runTests___lambda__12___closed__6;
x_32 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_31, x_4);
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_33; lean_object* x_34; 
x_33 = lean_ctor_get(x_32, 1);
lean_inc(x_33);
lean_dec(x_32);
if (x_23 == 0)
{
lean_object* x_102; 
x_102 = l_LeanTLS_Handshake_runTests___closed__9;
x_34 = x_102;
goto block_101;
}
else
{
lean_object* x_103; 
x_103 = l_LeanTLS_Handshake_runTests___closed__11;
x_34 = x_103;
goto block_101;
}
block_101:
{
lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_35 = l_LeanTLS_Handshake_runTests___closed__7;
x_36 = lean_string_append(x_35, x_34);
lean_dec(x_34);
x_37 = l_LeanTLS_Handshake_runTests___closed__8;
x_38 = lean_string_append(x_36, x_37);
if (x_26 == 0)
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; 
x_39 = l_LeanTLS_Handshake_runTests___closed__9;
x_40 = lean_string_append(x_38, x_39);
x_41 = l_LeanTLS_Handshake_runTests___closed__10;
x_42 = lean_string_append(x_40, x_41);
if (x_29 == 0)
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; 
x_43 = lean_string_append(x_42, x_39);
x_44 = l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
x_45 = lean_string_append(x_43, x_44);
x_46 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_45, x_33);
if (lean_obj_tag(x_46) == 0)
{
lean_object* x_47; lean_object* x_48; uint8_t x_49; lean_object* x_50; lean_object* x_51; 
x_47 = lean_ctor_get(x_46, 1);
lean_inc(x_47);
lean_dec(x_46);
x_48 = l_LeanTLS_Handshake_runTests___closed__5;
x_49 = 0;
x_50 = lean_box(0);
x_51 = l_LeanTLS_Handshake_runTests___lambda__12(x_48, x_25, x_49, x_50, x_47);
return x_51;
}
else
{
uint8_t x_52; 
x_52 = !lean_is_exclusive(x_46);
if (x_52 == 0)
{
return x_46;
}
else
{
lean_object* x_53; lean_object* x_54; lean_object* x_55; 
x_53 = lean_ctor_get(x_46, 0);
x_54 = lean_ctor_get(x_46, 1);
lean_inc(x_54);
lean_inc(x_53);
lean_dec(x_46);
x_55 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_55, 0, x_53);
lean_ctor_set(x_55, 1, x_54);
return x_55;
}
}
}
else
{
lean_object* x_56; lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; 
x_56 = l_LeanTLS_Handshake_runTests___closed__11;
x_57 = lean_string_append(x_42, x_56);
x_58 = l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
x_59 = lean_string_append(x_57, x_58);
x_60 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_59, x_33);
if (lean_obj_tag(x_60) == 0)
{
lean_object* x_61; lean_object* x_62; uint8_t x_63; lean_object* x_64; lean_object* x_65; 
x_61 = lean_ctor_get(x_60, 1);
lean_inc(x_61);
lean_dec(x_60);
x_62 = l_LeanTLS_Handshake_runTests___closed__5;
x_63 = 0;
x_64 = lean_box(0);
x_65 = l_LeanTLS_Handshake_runTests___lambda__12(x_62, x_25, x_63, x_64, x_61);
return x_65;
}
else
{
uint8_t x_66; 
x_66 = !lean_is_exclusive(x_60);
if (x_66 == 0)
{
return x_60;
}
else
{
lean_object* x_67; lean_object* x_68; lean_object* x_69; 
x_67 = lean_ctor_get(x_60, 0);
x_68 = lean_ctor_get(x_60, 1);
lean_inc(x_68);
lean_inc(x_67);
lean_dec(x_60);
x_69 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_69, 0, x_67);
lean_ctor_set(x_69, 1, x_68);
return x_69;
}
}
}
}
else
{
lean_object* x_70; lean_object* x_71; lean_object* x_72; lean_object* x_73; 
x_70 = l_LeanTLS_Handshake_runTests___closed__11;
x_71 = lean_string_append(x_38, x_70);
x_72 = l_LeanTLS_Handshake_runTests___closed__10;
x_73 = lean_string_append(x_71, x_72);
if (x_29 == 0)
{
lean_object* x_74; lean_object* x_75; lean_object* x_76; lean_object* x_77; lean_object* x_78; 
x_74 = l_LeanTLS_Handshake_runTests___closed__9;
x_75 = lean_string_append(x_73, x_74);
x_76 = l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
x_77 = lean_string_append(x_75, x_76);
x_78 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_77, x_33);
if (lean_obj_tag(x_78) == 0)
{
lean_object* x_79; lean_object* x_80; uint8_t x_81; lean_object* x_82; lean_object* x_83; 
x_79 = lean_ctor_get(x_78, 1);
lean_inc(x_79);
lean_dec(x_78);
x_80 = l_LeanTLS_Handshake_runTests___closed__5;
x_81 = 0;
x_82 = lean_box(0);
x_83 = l_LeanTLS_Handshake_runTests___lambda__12(x_80, x_25, x_81, x_82, x_79);
return x_83;
}
else
{
uint8_t x_84; 
x_84 = !lean_is_exclusive(x_78);
if (x_84 == 0)
{
return x_78;
}
else
{
lean_object* x_85; lean_object* x_86; lean_object* x_87; 
x_85 = lean_ctor_get(x_78, 0);
x_86 = lean_ctor_get(x_78, 1);
lean_inc(x_86);
lean_inc(x_85);
lean_dec(x_78);
x_87 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_87, 0, x_85);
lean_ctor_set(x_87, 1, x_86);
return x_87;
}
}
}
else
{
lean_object* x_88; lean_object* x_89; lean_object* x_90; lean_object* x_91; 
x_88 = lean_string_append(x_73, x_70);
x_89 = l_LeanTLS_Handshake_runTests___lambda__6___closed__19;
x_90 = lean_string_append(x_88, x_89);
x_91 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_90, x_33);
if (lean_obj_tag(x_91) == 0)
{
lean_object* x_92; lean_object* x_93; uint8_t x_94; lean_object* x_95; lean_object* x_96; 
x_92 = lean_ctor_get(x_91, 1);
lean_inc(x_92);
lean_dec(x_91);
x_93 = l_LeanTLS_Handshake_runTests___closed__5;
x_94 = 0;
x_95 = lean_box(0);
x_96 = l_LeanTLS_Handshake_runTests___lambda__12(x_93, x_25, x_94, x_95, x_92);
return x_96;
}
else
{
uint8_t x_97; 
x_97 = !lean_is_exclusive(x_91);
if (x_97 == 0)
{
return x_91;
}
else
{
lean_object* x_98; lean_object* x_99; lean_object* x_100; 
x_98 = lean_ctor_get(x_91, 0);
x_99 = lean_ctor_get(x_91, 1);
lean_inc(x_99);
lean_inc(x_98);
lean_dec(x_91);
x_100 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_100, 0, x_98);
lean_ctor_set(x_100, 1, x_99);
return x_100;
}
}
}
}
}
}
else
{
uint8_t x_104; 
x_104 = !lean_is_exclusive(x_32);
if (x_104 == 0)
{
return x_32;
}
else
{
lean_object* x_105; lean_object* x_106; lean_object* x_107; 
x_105 = lean_ctor_get(x_32, 0);
x_106 = lean_ctor_get(x_32, 1);
lean_inc(x_106);
lean_inc(x_105);
lean_dec(x_32);
x_107 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_107, 0, x_105);
lean_ctor_set(x_107, 1, x_106);
return x_107;
}
}
}
}
}
else
{
uint8_t x_123; 
x_123 = !lean_is_exclusive(x_3);
if (x_123 == 0)
{
return x_3;
}
else
{
lean_object* x_124; lean_object* x_125; lean_object* x_126; 
x_124 = lean_ctor_get(x_3, 0);
x_125 = lean_ctor_get(x_3, 1);
lean_inc(x_125);
lean_inc(x_124);
lean_dec(x_3);
x_126 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_126, 0, x_124);
lean_ctor_set(x_126, 1, x_125);
return x_126;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Handshake_runTests___lambda__1(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Handshake_runTests___lambda__2(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__3___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
lean_dec(x_3);
x_7 = l_LeanTLS_Handshake_runTests___lambda__3(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_4);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__4___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
uint8_t x_7; lean_object* x_8; 
x_7 = lean_unbox(x_4);
lean_dec(x_4);
x_8 = l_LeanTLS_Handshake_runTests___lambda__4(x_1, x_2, x_3, x_7, x_5, x_6);
lean_dec(x_5);
lean_dec(x_3);
lean_dec(x_2);
return x_8;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__5___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Handshake_runTests___lambda__5(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__6___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Handshake_runTests___lambda__6(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__7___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; uint8_t x_6; lean_object* x_7; 
x_5 = lean_unbox(x_1);
lean_dec(x_1);
x_6 = lean_unbox(x_2);
lean_dec(x_2);
x_7 = l_LeanTLS_Handshake_runTests___lambda__7(x_5, x_6, x_3, x_4);
lean_dec(x_3);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__8___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; uint8_t x_7; lean_object* x_8; 
x_6 = lean_unbox(x_2);
lean_dec(x_2);
x_7 = lean_unbox(x_3);
lean_dec(x_3);
x_8 = l_LeanTLS_Handshake_runTests___lambda__8(x_1, x_6, x_7, x_4, x_5);
lean_dec(x_4);
lean_dec(x_1);
return x_8;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__9___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; uint8_t x_7; lean_object* x_8; 
x_6 = lean_unbox(x_2);
lean_dec(x_2);
x_7 = lean_unbox(x_3);
lean_dec(x_3);
x_8 = l_LeanTLS_Handshake_runTests___lambda__9(x_1, x_6, x_7, x_4, x_5);
lean_dec(x_4);
lean_dec(x_1);
return x_8;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__10___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; uint8_t x_7; lean_object* x_8; 
x_6 = lean_unbox(x_2);
lean_dec(x_2);
x_7 = lean_unbox(x_3);
lean_dec(x_3);
x_8 = l_LeanTLS_Handshake_runTests___lambda__10(x_1, x_6, x_7, x_4, x_5);
lean_dec(x_4);
lean_dec(x_1);
return x_8;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__11___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Handshake_runTests___lambda__11(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Handshake_runTests___lambda__12___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
lean_dec(x_3);
x_7 = l_LeanTLS_Handshake_runTests___lambda__12(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_4);
return x_7;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_SHA256(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_HMAC(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_LeanTLS_Handshake(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_SHA256(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_HMAC(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_LeanTLS_Handshake_instBEqByteArray__leanTLS___closed__1 = _init_l_LeanTLS_Handshake_instBEqByteArray__leanTLS___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_instBEqByteArray__leanTLS___closed__1);
l_LeanTLS_Handshake_instBEqByteArray__leanTLS = _init_l_LeanTLS_Handshake_instBEqByteArray__leanTLS();
lean_mark_persistent(l_LeanTLS_Handshake_instBEqByteArray__leanTLS);
l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___closed__1 = _init_l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_noConfusion___rarg___closed__1);
l_LeanTLS_Handshake_instBEqHandshakeType___closed__1 = _init_l_LeanTLS_Handshake_instBEqHandshakeType___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_instBEqHandshakeType___closed__1);
l_LeanTLS_Handshake_instBEqHandshakeType = _init_l_LeanTLS_Handshake_instBEqHandshakeType();
lean_mark_persistent(l_LeanTLS_Handshake_instBEqHandshakeType);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__1 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__1();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__1);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__2);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__3);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__4 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__4();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__4);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__5 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__5();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__5);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__6);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__7 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__7();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__7);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__8 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__8();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__8);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__9 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__9();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__9);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__10);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__11 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__11();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__11);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__12 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__12();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__12);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__13 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__13();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__13);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__14 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__14();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__14);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__15 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__15();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__15);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__16);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__17 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__17();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__17);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__18 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__18();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__18);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__19 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__19();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__19);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__20 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__20();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__20);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__21 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__21();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__21);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__22);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__23 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__23();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__23);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__24 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__24();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__24);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__25 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__25();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__25);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__26 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__26();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__26);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__27 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__27();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__27);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__28);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__29 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__29();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__29);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__30 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__30();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__30);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__31 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__31();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__31);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__32 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__32();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__32);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__33 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__33();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__33);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__34);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__35 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__35();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__35);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__36 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__36();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__36);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__37 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__37();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__37);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__38 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__38();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_reprHandshakeType____x40_LeanTLS_Handshake___hyg_259____closed__38);
l_LeanTLS_Handshake_instReprHandshakeType___closed__1 = _init_l_LeanTLS_Handshake_instReprHandshakeType___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_instReprHandshakeType___closed__1);
l_LeanTLS_Handshake_instReprHandshakeType = _init_l_LeanTLS_Handshake_instReprHandshakeType();
lean_mark_persistent(l_LeanTLS_Handshake_instReprHandshakeType);
l_LeanTLS_Handshake_HandshakeType_fromByte___closed__1 = _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_fromByte___closed__1);
l_LeanTLS_Handshake_HandshakeType_fromByte___closed__2 = _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_fromByte___closed__2);
l_LeanTLS_Handshake_HandshakeType_fromByte___closed__3 = _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_fromByte___closed__3);
l_LeanTLS_Handshake_HandshakeType_fromByte___closed__4 = _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_fromByte___closed__4);
l_LeanTLS_Handshake_HandshakeType_fromByte___closed__5 = _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_fromByte___closed__5);
l_LeanTLS_Handshake_HandshakeType_fromByte___closed__6 = _init_l_LeanTLS_Handshake_HandshakeType_fromByte___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_HandshakeType_fromByte___closed__6);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__1 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__1();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__1);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__2 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__2();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__2);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__3 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__3();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__3);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__4 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__4();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__4);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__5 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__5();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__5);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__6 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__6();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt___closed__6);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedVersionsExt);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__1);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__2);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__3 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__3();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__3);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__4 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__4();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt___closed__4);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSupportedGroupsExt);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__1 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__1();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__1);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__2 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__2();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__2);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__3);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__4 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__4();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__4);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__5 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__5();
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__6 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__6();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__6);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__7 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__7();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__7);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__8 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__8();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt___closed__8);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_buildSignatureAlgorithmsExt);
l_LeanTLS_Handshake_buildClientHello___closed__1 = _init_l_LeanTLS_Handshake_buildClientHello___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__1);
l_LeanTLS_Handshake_buildClientHello___closed__2 = _init_l_LeanTLS_Handshake_buildClientHello___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__2);
l_LeanTLS_Handshake_buildClientHello___closed__3 = _init_l_LeanTLS_Handshake_buildClientHello___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__3);
l_LeanTLS_Handshake_buildClientHello___closed__4 = _init_l_LeanTLS_Handshake_buildClientHello___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__4);
l_LeanTLS_Handshake_buildClientHello___closed__5 = _init_l_LeanTLS_Handshake_buildClientHello___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__5);
l_LeanTLS_Handshake_buildClientHello___closed__6 = _init_l_LeanTLS_Handshake_buildClientHello___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__6);
l_LeanTLS_Handshake_buildClientHello___closed__7 = _init_l_LeanTLS_Handshake_buildClientHello___closed__7();
lean_mark_persistent(l_LeanTLS_Handshake_buildClientHello___closed__7);
l_LeanTLS_Handshake_transcriptHash___closed__1 = _init_l_LeanTLS_Handshake_transcriptHash___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_transcriptHash___closed__1);
l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes___closed__1 = _init_l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes___closed__1();
lean_mark_persistent(l___private_LeanTLS_Handshake_0__LeanTLS_Handshake_hexToBytes___closed__1);
l_LeanTLS_Handshake_runTests___lambda__2___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__2___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__2___closed__1);
l_LeanTLS_Handshake_runTests___lambda__3___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__3___closed__1);
l_LeanTLS_Handshake_runTests___lambda__3___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__3___closed__2);
l_LeanTLS_Handshake_runTests___lambda__3___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__3___closed__3);
l_LeanTLS_Handshake_runTests___lambda__3___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__3___closed__4);
l_LeanTLS_Handshake_runTests___lambda__3___closed__5 = _init_l_LeanTLS_Handshake_runTests___lambda__3___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__3___closed__5);
l_LeanTLS_Handshake_runTests___lambda__4___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__4___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__4___closed__1);
l_LeanTLS_Handshake_runTests___lambda__4___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__4___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__4___closed__2);
l_LeanTLS_Handshake_runTests___lambda__5___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__1);
l_LeanTLS_Handshake_runTests___lambda__5___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__2);
l_LeanTLS_Handshake_runTests___lambda__5___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__3);
l_LeanTLS_Handshake_runTests___lambda__5___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__4);
l_LeanTLS_Handshake_runTests___lambda__5___closed__5 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__5);
l_LeanTLS_Handshake_runTests___lambda__5___closed__6 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__6);
l_LeanTLS_Handshake_runTests___lambda__5___closed__7 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__7();
l_LeanTLS_Handshake_runTests___lambda__5___closed__8 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__8();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__8);
l_LeanTLS_Handshake_runTests___lambda__5___closed__9 = _init_l_LeanTLS_Handshake_runTests___lambda__5___closed__9();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__5___closed__9);
l_LeanTLS_Handshake_runTests___lambda__6___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__1);
l_LeanTLS_Handshake_runTests___lambda__6___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__2);
l_LeanTLS_Handshake_runTests___lambda__6___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__3);
l_LeanTLS_Handshake_runTests___lambda__6___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__4);
l_LeanTLS_Handshake_runTests___lambda__6___closed__5 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__5);
l_LeanTLS_Handshake_runTests___lambda__6___closed__6 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__6);
l_LeanTLS_Handshake_runTests___lambda__6___closed__7 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__7();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__7);
l_LeanTLS_Handshake_runTests___lambda__6___closed__8 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__8();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__8);
l_LeanTLS_Handshake_runTests___lambda__6___closed__9 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__9();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__9);
l_LeanTLS_Handshake_runTests___lambda__6___closed__10 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__10();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__10);
l_LeanTLS_Handshake_runTests___lambda__6___closed__11 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__11();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__11);
l_LeanTLS_Handshake_runTests___lambda__6___closed__12 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__12();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__12);
l_LeanTLS_Handshake_runTests___lambda__6___closed__13 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__13();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__13);
l_LeanTLS_Handshake_runTests___lambda__6___closed__14 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__14();
l_LeanTLS_Handshake_runTests___lambda__6___closed__15 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__15();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__15);
l_LeanTLS_Handshake_runTests___lambda__6___closed__16 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__16();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__16);
l_LeanTLS_Handshake_runTests___lambda__6___closed__17 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__17();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__17);
l_LeanTLS_Handshake_runTests___lambda__6___closed__18 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__18();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__18);
l_LeanTLS_Handshake_runTests___lambda__6___closed__19 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__19();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__19);
l_LeanTLS_Handshake_runTests___lambda__6___closed__20 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__20();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__20);
l_LeanTLS_Handshake_runTests___lambda__6___closed__21 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__21();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__21);
l_LeanTLS_Handshake_runTests___lambda__6___closed__22 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__22();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__22);
l_LeanTLS_Handshake_runTests___lambda__6___closed__23 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__23();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__23);
l_LeanTLS_Handshake_runTests___lambda__6___closed__24 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__24();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__24);
l_LeanTLS_Handshake_runTests___lambda__6___closed__25 = _init_l_LeanTLS_Handshake_runTests___lambda__6___closed__25();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__6___closed__25);
l_LeanTLS_Handshake_runTests___lambda__7___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__7___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__7___closed__1);
l_LeanTLS_Handshake_runTests___lambda__8___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__8___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__8___closed__1);
l_LeanTLS_Handshake_runTests___lambda__8___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__8___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__8___closed__2);
l_LeanTLS_Handshake_runTests___lambda__8___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__8___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__8___closed__3);
l_LeanTLS_Handshake_runTests___lambda__9___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__9___closed__1);
l_LeanTLS_Handshake_runTests___lambda__9___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__9___closed__2);
l_LeanTLS_Handshake_runTests___lambda__9___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__9___closed__3);
l_LeanTLS_Handshake_runTests___lambda__9___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__9___closed__4);
l_LeanTLS_Handshake_runTests___lambda__9___closed__5 = _init_l_LeanTLS_Handshake_runTests___lambda__9___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__9___closed__5);
l_LeanTLS_Handshake_runTests___lambda__10___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__10___closed__1);
l_LeanTLS_Handshake_runTests___lambda__10___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__10___closed__2);
l_LeanTLS_Handshake_runTests___lambda__10___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__10___closed__3);
l_LeanTLS_Handshake_runTests___lambda__10___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__10___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__10___closed__4);
l_LeanTLS_Handshake_runTests___lambda__11___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__1);
l_LeanTLS_Handshake_runTests___lambda__11___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__2);
l_LeanTLS_Handshake_runTests___lambda__11___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__3);
l_LeanTLS_Handshake_runTests___lambda__11___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__4);
l_LeanTLS_Handshake_runTests___lambda__11___closed__5 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__5);
l_LeanTLS_Handshake_runTests___lambda__11___closed__6 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__6);
l_LeanTLS_Handshake_runTests___lambda__11___closed__7 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__7();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__7);
l_LeanTLS_Handshake_runTests___lambda__11___closed__8 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__8();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__8);
l_LeanTLS_Handshake_runTests___lambda__11___closed__9 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__9();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__9);
l_LeanTLS_Handshake_runTests___lambda__11___closed__10 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__10();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__10);
l_LeanTLS_Handshake_runTests___lambda__11___closed__11 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__11();
l_LeanTLS_Handshake_runTests___lambda__11___closed__12 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__12();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__12);
l_LeanTLS_Handshake_runTests___lambda__11___closed__13 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__13();
l_LeanTLS_Handshake_runTests___lambda__11___closed__14 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__14();
l_LeanTLS_Handshake_runTests___lambda__11___closed__15 = _init_l_LeanTLS_Handshake_runTests___lambda__11___closed__15();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__11___closed__15);
l_LeanTLS_Handshake_runTests___lambda__12___closed__1 = _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__12___closed__1);
l_LeanTLS_Handshake_runTests___lambda__12___closed__2 = _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__12___closed__2);
l_LeanTLS_Handshake_runTests___lambda__12___closed__3 = _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__12___closed__3);
l_LeanTLS_Handshake_runTests___lambda__12___closed__4 = _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__12___closed__4);
l_LeanTLS_Handshake_runTests___lambda__12___closed__5 = _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__12___closed__5);
l_LeanTLS_Handshake_runTests___lambda__12___closed__6 = _init_l_LeanTLS_Handshake_runTests___lambda__12___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___lambda__12___closed__6);
l_LeanTLS_Handshake_runTests___closed__1 = _init_l_LeanTLS_Handshake_runTests___closed__1();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__1);
l_LeanTLS_Handshake_runTests___closed__2 = _init_l_LeanTLS_Handshake_runTests___closed__2();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__2);
l_LeanTLS_Handshake_runTests___closed__3 = _init_l_LeanTLS_Handshake_runTests___closed__3();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__3);
l_LeanTLS_Handshake_runTests___closed__4 = _init_l_LeanTLS_Handshake_runTests___closed__4();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__4);
l_LeanTLS_Handshake_runTests___closed__5 = _init_l_LeanTLS_Handshake_runTests___closed__5();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__5);
l_LeanTLS_Handshake_runTests___closed__6 = _init_l_LeanTLS_Handshake_runTests___closed__6();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__6);
l_LeanTLS_Handshake_runTests___closed__7 = _init_l_LeanTLS_Handshake_runTests___closed__7();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__7);
l_LeanTLS_Handshake_runTests___closed__8 = _init_l_LeanTLS_Handshake_runTests___closed__8();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__8);
l_LeanTLS_Handshake_runTests___closed__9 = _init_l_LeanTLS_Handshake_runTests___closed__9();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__9);
l_LeanTLS_Handshake_runTests___closed__10 = _init_l_LeanTLS_Handshake_runTests___closed__10();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__10);
l_LeanTLS_Handshake_runTests___closed__11 = _init_l_LeanTLS_Handshake_runTests___closed__11();
lean_mark_persistent(l_LeanTLS_Handshake_runTests___closed__11);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
