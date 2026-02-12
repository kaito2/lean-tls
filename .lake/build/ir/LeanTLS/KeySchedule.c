// Lean compiler output
// Module: LeanTLS.KeySchedule
// Imports: Init LeanTLS.Crypto.HKDF LeanTLS.Crypto.SHA256
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
static lean_object* l_LeanTLS_KeySchedule_finishedKey___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___closed__3;
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___closed__4;
lean_object* lean_byte_array_mk(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1;
uint8_t lean_uint8_lor(uint8_t, uint8_t);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_earlySecret(lean_object*);
lean_object* lean_uint32_to_nat(uint32_t);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___closed__2;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_handshakeSecret(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_masterSecret(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1;
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientAppTrafficSecret(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__5;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__5;
static lean_object* l_LeanTLS_KeySchedule_handshakeSecret___closed__2;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_trafficKey(lean_object*);
lean_object* l_LeanTLS_Crypto_HKDF_extract(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9(lean_object*, uint8_t, lean_object*, lean_object*);
lean_object* lean_byte_array_push(lean_object*, uint8_t);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_ByteArray_append(lean_object*, lean_object*);
static lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1;
uint8_t lean_uint8_shift_left(uint8_t, uint8_t);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_deriveTrafficKeys(lean_object*);
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_string_data(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___closed__3;
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes_go(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__9;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___closed__4;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3;
lean_object* l_LeanTLS_Crypto_SHA256_toHex(lean_object*);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
extern lean_object* l_ByteArray_empty;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_deriveSecret___boxed(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___closed__5;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__7;
static lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__2;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_finishedKey(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___closed__4;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_trafficIV(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__7;
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__5;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__9;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__2;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_handshakeSecret___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__3;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__7;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__8;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret(lean_object*, lean_object*);
lean_object* l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
static lean_object* l_LeanTLS_KeySchedule_trafficIV___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_deriveSecret(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__6;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___closed__5;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverAppTrafficSecret___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_clientAppTrafficSecret___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__10;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_earlySecret___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_hkdfExpandLabel(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__1(uint8_t, lean_object*, lean_object*);
static uint8_t l_LeanTLS_KeySchedule_runTests___closed__4;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__7;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3;
lean_object* lean_mk_empty_byte_array(lean_object*);
LEAN_EXPORT uint8_t l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble(uint32_t);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_hkdfExpandLabel___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_trafficKey___closed__1;
static lean_object* l_LeanTLS_KeySchedule_hkdfExpandLabel___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__6;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___closed__3;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___closed__6;
lean_object* lean_nat_mod(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
lean_object* lean_string_to_utf8(lean_object*);
static lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__5;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2;
lean_object* lean_nat_sub(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_LeanTLS_Crypto_HKDF_expand(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
uint8_t lean_uint8_of_nat(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___closed__2;
lean_object* lean_array_mk(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverAppTrafficSecret(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientAppTrafficSecret___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3(lean_object*, uint8_t, lean_object*, lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_handshakeSecret___closed__1;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___closed__5;
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___closed__4;
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble___boxed(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___closed__1;
lean_object* l_LeanTLS_Crypto_SHA256_hash(lean_object*);
lean_object* lean_byte_array_size(lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__4;
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___closed__2;
static lean_object* l_LeanTLS_KeySchedule_serverAppTrafficSecret___closed__1;
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen() {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(32u);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen() {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(16u);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen() {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(12u);
return x_1;
}
}
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__1() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = 0;
x_2 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_3 = lean_box(x_1);
x_4 = lean_mk_array(x_2, x_3);
return x_4;
}
}
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__1;
x_2 = lean_byte_array_mk(x_1);
return x_2;
}
}
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey() {
_start:
{
lean_object* x_1; 
x_1 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__2;
return x_1;
}
}
LEAN_EXPORT uint8_t l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble(uint32_t x_1) {
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
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble___boxed(lean_object* x_1) {
_start:
{
uint32_t x_2; uint8_t x_3; lean_object* x_4; 
x_2 = lean_unbox_uint32(x_1);
lean_dec(x_1);
x_3 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble(x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes_go(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
return x_2;
}
else
{
lean_object* x_3; 
x_3 = lean_ctor_get(x_1, 1);
lean_inc(x_3);
if (lean_obj_tag(x_3) == 0)
{
lean_dec(x_1);
return x_2;
}
else
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; uint32_t x_7; uint8_t x_8; uint32_t x_9; uint8_t x_10; uint8_t x_11; uint8_t x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_4 = lean_ctor_get(x_1, 0);
lean_inc(x_4);
lean_dec(x_1);
x_5 = lean_ctor_get(x_3, 0);
lean_inc(x_5);
x_6 = lean_ctor_get(x_3, 1);
lean_inc(x_6);
lean_dec(x_3);
x_7 = lean_unbox_uint32(x_4);
lean_dec(x_4);
x_8 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble(x_7);
x_9 = lean_unbox_uint32(x_5);
lean_dec(x_5);
x_10 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexCharToNibble(x_9);
x_11 = 4;
x_12 = lean_uint8_shift_left(x_8, x_11);
x_13 = lean_uint8_lor(x_12, x_10);
x_14 = lean_box(x_13);
x_15 = lean_array_push(x_2, x_14);
x_1 = x_6;
x_2 = x_15;
goto _start;
}
}
}
}
static lean_object* _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_box(0);
x_2 = lean_array_mk(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_2 = lean_string_data(x_1);
x_3 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes___closed__1;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes_go(x_2, x_3);
x_5 = lean_byte_array_mk(x_4);
return x_5;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_hkdfExpandLabel___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("tls13 ", 6, 6);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_hkdfExpandLabel(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; uint8_t x_18; lean_object* x_19; lean_object* x_20; uint8_t x_21; lean_object* x_22; uint8_t x_23; lean_object* x_24; lean_object* x_25; uint8_t x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; 
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel___closed__1;
x_6 = lean_string_append(x_5, x_2);
x_7 = lean_string_to_utf8(x_6);
lean_dec(x_6);
x_8 = lean_byte_array_size(x_7);
x_9 = lean_unsigned_to_nat(3u);
x_10 = lean_nat_add(x_9, x_8);
x_11 = lean_unsigned_to_nat(1u);
x_12 = lean_nat_add(x_10, x_11);
lean_dec(x_10);
x_13 = lean_byte_array_size(x_3);
x_14 = lean_nat_add(x_12, x_13);
lean_dec(x_12);
x_15 = lean_mk_empty_byte_array(x_14);
lean_dec(x_14);
x_16 = lean_unsigned_to_nat(256u);
x_17 = lean_nat_div(x_4, x_16);
x_18 = lean_uint8_of_nat(x_17);
lean_dec(x_17);
x_19 = lean_byte_array_push(x_15, x_18);
x_20 = lean_nat_mod(x_4, x_16);
x_21 = lean_uint8_of_nat(x_20);
lean_dec(x_20);
x_22 = lean_byte_array_push(x_19, x_21);
x_23 = lean_uint8_of_nat(x_8);
lean_dec(x_8);
x_24 = lean_byte_array_push(x_22, x_23);
x_25 = l_ByteArray_append(x_24, x_7);
lean_dec(x_7);
x_26 = lean_uint8_of_nat(x_13);
lean_dec(x_13);
x_27 = lean_byte_array_push(x_25, x_26);
x_28 = l_ByteArray_append(x_27, x_3);
x_29 = l_LeanTLS_Crypto_HKDF_expand(x_1, x_28, x_4);
lean_dec(x_28);
return x_29;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_hkdfExpandLabel___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
lean_dec(x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_deriveSecret(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_deriveSecret___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_LeanTLS_KeySchedule_deriveSecret(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_earlySecret(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = l_ByteArray_empty;
x_3 = l_LeanTLS_Crypto_HKDF_extract(x_2, x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_earlySecret___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_KeySchedule_earlySecret(x_1);
lean_dec(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_handshakeSecret___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_ByteArray_empty;
x_2 = l_LeanTLS_Crypto_SHA256_hash(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_handshakeSecret___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("derived", 7, 7);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_handshakeSecret(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_3 = l_LeanTLS_KeySchedule_handshakeSecret___closed__2;
x_4 = l_LeanTLS_KeySchedule_handshakeSecret___closed__1;
x_5 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_6 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_3, x_4, x_5);
x_7 = l_LeanTLS_Crypto_HKDF_extract(x_6, x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_handshakeSecret___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_KeySchedule_handshakeSecret(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("c hs traffic", 12, 12);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_3, x_2, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("s hs traffic", 12, 12);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_3, x_2, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_masterSecret(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_2 = l_LeanTLS_KeySchedule_handshakeSecret___closed__2;
x_3 = l_LeanTLS_KeySchedule_handshakeSecret___closed__1;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
x_6 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey;
x_7 = l_LeanTLS_Crypto_HKDF_extract(x_5, x_6);
return x_7;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_clientAppTrafficSecret___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("c ap traffic", 12, 12);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientAppTrafficSecret(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = l_LeanTLS_KeySchedule_clientAppTrafficSecret___closed__1;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_3, x_2, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_clientAppTrafficSecret___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_KeySchedule_clientAppTrafficSecret(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_serverAppTrafficSecret___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("s ap traffic", 12, 12);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverAppTrafficSecret(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = l_LeanTLS_KeySchedule_serverAppTrafficSecret___closed__1;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_3, x_2, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_serverAppTrafficSecret___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_KeySchedule_serverAppTrafficSecret(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_trafficKey___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("key", 3, 3);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_trafficKey(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_2 = l_LeanTLS_KeySchedule_trafficKey___closed__1;
x_3 = l_ByteArray_empty;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
return x_5;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_trafficIV___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("iv", 2, 2);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_trafficIV(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_2 = l_LeanTLS_KeySchedule_trafficIV___closed__1;
x_3 = l_ByteArray_empty;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
return x_5;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_finishedKey___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("finished", 8, 8);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_finishedKey(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_2 = l_LeanTLS_KeySchedule_finishedKey___closed__1;
x_3 = l_ByteArray_empty;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_deriveTrafficKeys(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_2 = l_LeanTLS_KeySchedule_trafficKey___closed__1;
x_3 = l_ByteArray_empty;
x_4 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen;
lean_inc(x_1);
x_5 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_2, x_3, x_4);
x_6 = l_LeanTLS_KeySchedule_trafficIV___closed__1;
x_7 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen;
x_8 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_6, x_3, x_7);
x_9 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_9, 0, x_5);
lean_ctor_set(x_9, 1, x_8);
return x_9;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__1(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
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
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_KeySchedule_runTests___lambda__1___boxed), 3, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("5bd3c71b836e0b76bb73265f", 24, 24);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 6b (client write IV): FAILED", 47, 47);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    expected: ", 14, 14);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("", 0, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__5;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("    got:      ", 14, 14);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__9() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 6b (client write IV): PASSED", 47, 47);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_5 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__1;
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2;
x_7 = lean_string_dec_eq(x_1, x_6);
if (x_7 == 0)
{
lean_object* x_8; lean_object* x_9; 
x_8 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__3;
x_9 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_8, x_4);
if (lean_obj_tag(x_9) == 0)
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; 
x_10 = lean_ctor_get(x_9, 1);
lean_inc(x_10);
lean_dec(x_9);
x_11 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__7;
x_12 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_11, x_10);
if (lean_obj_tag(x_12) == 0)
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_13 = lean_ctor_get(x_12, 1);
lean_inc(x_13);
lean_dec(x_12);
x_14 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_15 = lean_string_append(x_14, x_1);
x_16 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_17 = lean_string_append(x_15, x_16);
x_18 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_17, x_13);
if (lean_obj_tag(x_18) == 0)
{
lean_object* x_19; uint8_t x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_19 = lean_ctor_get(x_18, 1);
lean_inc(x_19);
lean_dec(x_18);
x_20 = 0;
x_21 = lean_box(0);
x_22 = lean_box(x_20);
x_23 = lean_apply_3(x_5, x_22, x_21, x_19);
return x_23;
}
else
{
uint8_t x_24; 
x_24 = !lean_is_exclusive(x_18);
if (x_24 == 0)
{
return x_18;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_25 = lean_ctor_get(x_18, 0);
x_26 = lean_ctor_get(x_18, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_18);
x_27 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_27, 0, x_25);
lean_ctor_set(x_27, 1, x_26);
return x_27;
}
}
}
else
{
uint8_t x_28; 
x_28 = !lean_is_exclusive(x_12);
if (x_28 == 0)
{
return x_12;
}
else
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_29 = lean_ctor_get(x_12, 0);
x_30 = lean_ctor_get(x_12, 1);
lean_inc(x_30);
lean_inc(x_29);
lean_dec(x_12);
x_31 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_31, 0, x_29);
lean_ctor_set(x_31, 1, x_30);
return x_31;
}
}
}
else
{
uint8_t x_32; 
x_32 = !lean_is_exclusive(x_9);
if (x_32 == 0)
{
return x_9;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_33 = lean_ctor_get(x_9, 0);
x_34 = lean_ctor_get(x_9, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_9);
x_35 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set(x_35, 1, x_34);
return x_35;
}
}
}
else
{
lean_object* x_36; lean_object* x_37; 
x_36 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__9;
x_37 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_36, x_4);
if (lean_obj_tag(x_37) == 0)
{
lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; 
x_38 = lean_ctor_get(x_37, 0);
lean_inc(x_38);
x_39 = lean_ctor_get(x_37, 1);
lean_inc(x_39);
lean_dec(x_37);
x_40 = lean_box(x_2);
x_41 = lean_apply_3(x_5, x_40, x_38, x_39);
return x_41;
}
else
{
uint8_t x_42; 
x_42 = !lean_is_exclusive(x_37);
if (x_42 == 0)
{
return x_37;
}
else
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; 
x_43 = lean_ctor_get(x_37, 0);
x_44 = lean_ctor_get(x_37, 1);
lean_inc(x_44);
lean_inc(x_43);
lean_dec(x_37);
x_45 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_45, 0, x_43);
lean_ctor_set(x_45, 1, x_44);
return x_45;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("dbfaa693d1762c5b666af5d950258d01", 32, 32);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 6a (client write key): FAILED", 48, 48);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__3___closed__3;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 6a (client write key): PASSED", 48, 48);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; uint8_t x_15; 
x_5 = l_LeanTLS_KeySchedule_trafficKey___closed__1;
x_6 = l_ByteArray_empty;
x_7 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen;
lean_inc(x_1);
x_8 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_5, x_6, x_7);
x_9 = l_LeanTLS_Crypto_SHA256_toHex(x_8);
lean_dec(x_8);
x_10 = l_LeanTLS_KeySchedule_trafficIV___closed__1;
x_11 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen;
x_12 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_10, x_6, x_11);
x_13 = l_LeanTLS_Crypto_SHA256_toHex(x_12);
lean_dec(x_12);
x_14 = l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1;
x_15 = lean_string_dec_eq(x_9, x_14);
if (x_15 == 0)
{
lean_object* x_16; lean_object* x_17; 
x_16 = l_LeanTLS_KeySchedule_runTests___lambda__3___closed__2;
x_17 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_16, x_4);
if (lean_obj_tag(x_17) == 0)
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; 
x_18 = lean_ctor_get(x_17, 1);
lean_inc(x_18);
lean_dec(x_17);
x_19 = l_LeanTLS_KeySchedule_runTests___lambda__3___closed__4;
x_20 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_19, x_18);
if (lean_obj_tag(x_20) == 0)
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_21 = lean_ctor_get(x_20, 1);
lean_inc(x_21);
lean_dec(x_20);
x_22 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_23 = lean_string_append(x_22, x_9);
lean_dec(x_9);
x_24 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_25 = lean_string_append(x_23, x_24);
x_26 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_25, x_21);
if (lean_obj_tag(x_26) == 0)
{
lean_object* x_27; uint8_t x_28; lean_object* x_29; lean_object* x_30; 
x_27 = lean_ctor_get(x_26, 1);
lean_inc(x_27);
lean_dec(x_26);
x_28 = 0;
x_29 = lean_box(0);
x_30 = l_LeanTLS_KeySchedule_runTests___lambda__2(x_13, x_28, x_29, x_27);
lean_dec(x_13);
return x_30;
}
else
{
uint8_t x_31; 
lean_dec(x_13);
x_31 = !lean_is_exclusive(x_26);
if (x_31 == 0)
{
return x_26;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_32 = lean_ctor_get(x_26, 0);
x_33 = lean_ctor_get(x_26, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_26);
x_34 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_34, 0, x_32);
lean_ctor_set(x_34, 1, x_33);
return x_34;
}
}
}
else
{
uint8_t x_35; 
lean_dec(x_13);
lean_dec(x_9);
x_35 = !lean_is_exclusive(x_20);
if (x_35 == 0)
{
return x_20;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_36 = lean_ctor_get(x_20, 0);
x_37 = lean_ctor_get(x_20, 1);
lean_inc(x_37);
lean_inc(x_36);
lean_dec(x_20);
x_38 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_38, 0, x_36);
lean_ctor_set(x_38, 1, x_37);
return x_38;
}
}
}
else
{
uint8_t x_39; 
lean_dec(x_13);
lean_dec(x_9);
x_39 = !lean_is_exclusive(x_17);
if (x_39 == 0)
{
return x_17;
}
else
{
lean_object* x_40; lean_object* x_41; lean_object* x_42; 
x_40 = lean_ctor_get(x_17, 0);
x_41 = lean_ctor_get(x_17, 1);
lean_inc(x_41);
lean_inc(x_40);
lean_dec(x_17);
x_42 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_42, 0, x_40);
lean_ctor_set(x_42, 1, x_41);
return x_42;
}
}
}
else
{
lean_object* x_43; lean_object* x_44; 
lean_dec(x_9);
x_43 = l_LeanTLS_KeySchedule_runTests___lambda__3___closed__5;
x_44 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_43, x_4);
if (lean_obj_tag(x_44) == 0)
{
lean_object* x_45; lean_object* x_46; lean_object* x_47; 
x_45 = lean_ctor_get(x_44, 0);
lean_inc(x_45);
x_46 = lean_ctor_get(x_44, 1);
lean_inc(x_46);
lean_dec(x_44);
x_47 = l_LeanTLS_KeySchedule_runTests___lambda__2(x_13, x_2, x_45, x_46);
lean_dec(x_45);
lean_dec(x_13);
return x_47;
}
else
{
uint8_t x_48; 
lean_dec(x_13);
x_48 = !lean_is_exclusive(x_44);
if (x_48 == 0)
{
return x_44;
}
else
{
lean_object* x_49; lean_object* x_50; lean_object* x_51; 
x_49 = lean_ctor_get(x_44, 0);
x_50 = lean_ctor_get(x_44, 1);
lean_inc(x_50);
lean_inc(x_49);
lean_dec(x_44);
x_51 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_51, 0, x_49);
lean_ctor_set(x_51, 1, x_50);
return x_51;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("5d313eb2671276ee13000b30", 24, 24);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 5b (server write IV): FAILED", 47, 47);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__4___closed__3;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 5b (server write IV): PASSED", 47, 47);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; uint8_t x_7; 
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1;
x_7 = lean_string_dec_eq(x_2, x_6);
if (x_7 == 0)
{
lean_object* x_8; lean_object* x_9; 
x_8 = l_LeanTLS_KeySchedule_runTests___lambda__4___closed__2;
x_9 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_8, x_5);
if (lean_obj_tag(x_9) == 0)
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; 
x_10 = lean_ctor_get(x_9, 1);
lean_inc(x_10);
lean_dec(x_9);
x_11 = l_LeanTLS_KeySchedule_runTests___lambda__4___closed__4;
x_12 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_11, x_10);
if (lean_obj_tag(x_12) == 0)
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_13 = lean_ctor_get(x_12, 1);
lean_inc(x_13);
lean_dec(x_12);
x_14 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_15 = lean_string_append(x_14, x_2);
x_16 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_17 = lean_string_append(x_15, x_16);
x_18 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_17, x_13);
if (lean_obj_tag(x_18) == 0)
{
lean_object* x_19; uint8_t x_20; lean_object* x_21; lean_object* x_22; 
x_19 = lean_ctor_get(x_18, 1);
lean_inc(x_19);
lean_dec(x_18);
x_20 = 0;
x_21 = lean_box(0);
x_22 = l_LeanTLS_KeySchedule_runTests___lambda__3(x_1, x_20, x_21, x_19);
return x_22;
}
else
{
uint8_t x_23; 
lean_dec(x_1);
x_23 = !lean_is_exclusive(x_18);
if (x_23 == 0)
{
return x_18;
}
else
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_24 = lean_ctor_get(x_18, 0);
x_25 = lean_ctor_get(x_18, 1);
lean_inc(x_25);
lean_inc(x_24);
lean_dec(x_18);
x_26 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
return x_26;
}
}
}
else
{
uint8_t x_27; 
lean_dec(x_1);
x_27 = !lean_is_exclusive(x_12);
if (x_27 == 0)
{
return x_12;
}
else
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_28 = lean_ctor_get(x_12, 0);
x_29 = lean_ctor_get(x_12, 1);
lean_inc(x_29);
lean_inc(x_28);
lean_dec(x_12);
x_30 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_30, 0, x_28);
lean_ctor_set(x_30, 1, x_29);
return x_30;
}
}
}
else
{
uint8_t x_31; 
lean_dec(x_1);
x_31 = !lean_is_exclusive(x_9);
if (x_31 == 0)
{
return x_9;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_32 = lean_ctor_get(x_9, 0);
x_33 = lean_ctor_get(x_9, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_9);
x_34 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_34, 0, x_32);
lean_ctor_set(x_34, 1, x_33);
return x_34;
}
}
}
else
{
lean_object* x_35; lean_object* x_36; 
x_35 = l_LeanTLS_KeySchedule_runTests___lambda__4___closed__5;
x_36 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_35, x_5);
if (lean_obj_tag(x_36) == 0)
{
lean_object* x_37; lean_object* x_38; lean_object* x_39; 
x_37 = lean_ctor_get(x_36, 0);
lean_inc(x_37);
x_38 = lean_ctor_get(x_36, 1);
lean_inc(x_38);
lean_dec(x_36);
x_39 = l_LeanTLS_KeySchedule_runTests___lambda__3(x_1, x_3, x_37, x_38);
lean_dec(x_37);
return x_39;
}
else
{
uint8_t x_40; 
lean_dec(x_1);
x_40 = !lean_is_exclusive(x_36);
if (x_40 == 0)
{
return x_36;
}
else
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_41 = lean_ctor_get(x_36, 0);
x_42 = lean_ctor_get(x_36, 1);
lean_inc(x_42);
lean_inc(x_41);
lean_dec(x_36);
x_43 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_43, 0, x_41);
lean_ctor_set(x_43, 1, x_42);
return x_43;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("3fce516009c21727d0f2e4e86ee403bc", 32, 32);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 5a (server write key): FAILED", 48, 48);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__5___closed__3;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 5a (server write key): PASSED", 48, 48);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; uint8_t x_16; 
x_6 = l_LeanTLS_KeySchedule_trafficKey___closed__1;
x_7 = l_ByteArray_empty;
x_8 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen;
lean_inc(x_1);
x_9 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_6, x_7, x_8);
x_10 = l_LeanTLS_Crypto_SHA256_toHex(x_9);
lean_dec(x_9);
x_11 = l_LeanTLS_KeySchedule_trafficIV___closed__1;
x_12 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen;
x_13 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_11, x_7, x_12);
x_14 = l_LeanTLS_Crypto_SHA256_toHex(x_13);
lean_dec(x_13);
x_15 = l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1;
x_16 = lean_string_dec_eq(x_10, x_15);
if (x_16 == 0)
{
lean_object* x_17; lean_object* x_18; 
x_17 = l_LeanTLS_KeySchedule_runTests___lambda__5___closed__2;
x_18 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_17, x_5);
if (lean_obj_tag(x_18) == 0)
{
lean_object* x_19; lean_object* x_20; lean_object* x_21; 
x_19 = lean_ctor_get(x_18, 1);
lean_inc(x_19);
lean_dec(x_18);
x_20 = l_LeanTLS_KeySchedule_runTests___lambda__5___closed__4;
x_21 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_20, x_19);
if (lean_obj_tag(x_21) == 0)
{
lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_22 = lean_ctor_get(x_21, 1);
lean_inc(x_22);
lean_dec(x_21);
x_23 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_24 = lean_string_append(x_23, x_10);
lean_dec(x_10);
x_25 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_26 = lean_string_append(x_24, x_25);
x_27 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_26, x_22);
if (lean_obj_tag(x_27) == 0)
{
lean_object* x_28; uint8_t x_29; lean_object* x_30; lean_object* x_31; 
x_28 = lean_ctor_get(x_27, 1);
lean_inc(x_28);
lean_dec(x_27);
x_29 = 0;
x_30 = lean_box(0);
x_31 = l_LeanTLS_KeySchedule_runTests___lambda__4(x_2, x_14, x_29, x_30, x_28);
lean_dec(x_14);
return x_31;
}
else
{
uint8_t x_32; 
lean_dec(x_14);
lean_dec(x_2);
x_32 = !lean_is_exclusive(x_27);
if (x_32 == 0)
{
return x_27;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_33 = lean_ctor_get(x_27, 0);
x_34 = lean_ctor_get(x_27, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_27);
x_35 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set(x_35, 1, x_34);
return x_35;
}
}
}
else
{
uint8_t x_36; 
lean_dec(x_14);
lean_dec(x_10);
lean_dec(x_2);
x_36 = !lean_is_exclusive(x_21);
if (x_36 == 0)
{
return x_21;
}
else
{
lean_object* x_37; lean_object* x_38; lean_object* x_39; 
x_37 = lean_ctor_get(x_21, 0);
x_38 = lean_ctor_get(x_21, 1);
lean_inc(x_38);
lean_inc(x_37);
lean_dec(x_21);
x_39 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_39, 0, x_37);
lean_ctor_set(x_39, 1, x_38);
return x_39;
}
}
}
else
{
uint8_t x_40; 
lean_dec(x_14);
lean_dec(x_10);
lean_dec(x_2);
x_40 = !lean_is_exclusive(x_18);
if (x_40 == 0)
{
return x_18;
}
else
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_41 = lean_ctor_get(x_18, 0);
x_42 = lean_ctor_get(x_18, 1);
lean_inc(x_42);
lean_inc(x_41);
lean_dec(x_18);
x_43 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_43, 0, x_41);
lean_ctor_set(x_43, 1, x_42);
return x_43;
}
}
}
else
{
lean_object* x_44; lean_object* x_45; 
lean_dec(x_10);
x_44 = l_LeanTLS_KeySchedule_runTests___lambda__5___closed__5;
x_45 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_44, x_5);
if (lean_obj_tag(x_45) == 0)
{
lean_object* x_46; lean_object* x_47; lean_object* x_48; 
x_46 = lean_ctor_get(x_45, 0);
lean_inc(x_46);
x_47 = lean_ctor_get(x_45, 1);
lean_inc(x_47);
lean_dec(x_45);
x_48 = l_LeanTLS_KeySchedule_runTests___lambda__4(x_2, x_14, x_3, x_46, x_47);
lean_dec(x_46);
lean_dec(x_14);
return x_48;
}
else
{
uint8_t x_49; 
lean_dec(x_14);
lean_dec(x_2);
x_49 = !lean_is_exclusive(x_45);
if (x_49 == 0)
{
return x_45;
}
else
{
lean_object* x_50; lean_object* x_51; lean_object* x_52; 
x_50 = lean_ctor_get(x_45, 0);
x_51 = lean_ctor_get(x_45, 1);
lean_inc(x_51);
lean_inc(x_50);
lean_dec(x_45);
x_52 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_52, 0, x_50);
lean_ctor_set(x_52, 1, x_51);
return x_52;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("b67b7d690cc16c4e75e54213cb2d37b4e9c912bcded9105d42befd59d391ad38", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 4b (server HS traffic secret): FAILED", 56, 56);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__6___closed__3;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 4b (server HS traffic secret): PASSED", 56, 56);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6(lean_object* x_1, lean_object* x_2, lean_object* x_3, uint8_t x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; uint8_t x_12; 
x_7 = l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1;
x_8 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
x_9 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_7, x_2, x_8);
x_10 = l_LeanTLS_Crypto_SHA256_toHex(x_9);
x_11 = l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1;
x_12 = lean_string_dec_eq(x_10, x_11);
if (x_12 == 0)
{
lean_object* x_13; lean_object* x_14; 
x_13 = l_LeanTLS_KeySchedule_runTests___lambda__6___closed__2;
x_14 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_13, x_6);
if (lean_obj_tag(x_14) == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_14, 1);
lean_inc(x_15);
lean_dec(x_14);
x_16 = l_LeanTLS_KeySchedule_runTests___lambda__6___closed__4;
x_17 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_16, x_15);
if (lean_obj_tag(x_17) == 0)
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_18 = lean_ctor_get(x_17, 1);
lean_inc(x_18);
lean_dec(x_17);
x_19 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_20 = lean_string_append(x_19, x_10);
lean_dec(x_10);
x_21 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_22 = lean_string_append(x_20, x_21);
x_23 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_22, x_18);
if (lean_obj_tag(x_23) == 0)
{
lean_object* x_24; uint8_t x_25; lean_object* x_26; lean_object* x_27; 
x_24 = lean_ctor_get(x_23, 1);
lean_inc(x_24);
lean_dec(x_23);
x_25 = 0;
x_26 = lean_box(0);
x_27 = l_LeanTLS_KeySchedule_runTests___lambda__5(x_9, x_3, x_25, x_26, x_24);
return x_27;
}
else
{
uint8_t x_28; 
lean_dec(x_9);
lean_dec(x_3);
x_28 = !lean_is_exclusive(x_23);
if (x_28 == 0)
{
return x_23;
}
else
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_29 = lean_ctor_get(x_23, 0);
x_30 = lean_ctor_get(x_23, 1);
lean_inc(x_30);
lean_inc(x_29);
lean_dec(x_23);
x_31 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_31, 0, x_29);
lean_ctor_set(x_31, 1, x_30);
return x_31;
}
}
}
else
{
uint8_t x_32; 
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_3);
x_32 = !lean_is_exclusive(x_17);
if (x_32 == 0)
{
return x_17;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_33 = lean_ctor_get(x_17, 0);
x_34 = lean_ctor_get(x_17, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_17);
x_35 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set(x_35, 1, x_34);
return x_35;
}
}
}
else
{
uint8_t x_36; 
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_3);
x_36 = !lean_is_exclusive(x_14);
if (x_36 == 0)
{
return x_14;
}
else
{
lean_object* x_37; lean_object* x_38; lean_object* x_39; 
x_37 = lean_ctor_get(x_14, 0);
x_38 = lean_ctor_get(x_14, 1);
lean_inc(x_38);
lean_inc(x_37);
lean_dec(x_14);
x_39 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_39, 0, x_37);
lean_ctor_set(x_39, 1, x_38);
return x_39;
}
}
}
else
{
lean_object* x_40; lean_object* x_41; 
lean_dec(x_10);
x_40 = l_LeanTLS_KeySchedule_runTests___lambda__6___closed__5;
x_41 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_40, x_6);
if (lean_obj_tag(x_41) == 0)
{
lean_object* x_42; lean_object* x_43; lean_object* x_44; 
x_42 = lean_ctor_get(x_41, 0);
lean_inc(x_42);
x_43 = lean_ctor_get(x_41, 1);
lean_inc(x_43);
lean_dec(x_41);
x_44 = l_LeanTLS_KeySchedule_runTests___lambda__5(x_9, x_3, x_4, x_42, x_43);
lean_dec(x_42);
return x_44;
}
else
{
uint8_t x_45; 
lean_dec(x_9);
lean_dec(x_3);
x_45 = !lean_is_exclusive(x_41);
if (x_45 == 0)
{
return x_41;
}
else
{
lean_object* x_46; lean_object* x_47; lean_object* x_48; 
x_46 = lean_ctor_get(x_41, 0);
x_47 = lean_ctor_get(x_41, 1);
lean_inc(x_47);
lean_inc(x_46);
lean_dec(x_41);
x_48 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_48, 0, x_46);
lean_ctor_set(x_48, 1, x_47);
return x_48;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("860c06edc07858ee8e78f0e7428c58edd6b43f2ca3e6e95f02ed063cf0e1cad8", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__1;
x_2 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("b3eddb126e067f35a780b3abf45e2d8f3b1a950738f52e9600746a0e27a55a21", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 4a (client HS traffic secret): FAILED", 56, 56);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__5;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__7() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 4a (client HS traffic secret): PASSED", 56, 56);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; 
x_5 = l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1;
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__2;
x_7 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
lean_inc(x_1);
x_8 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_5, x_6, x_7);
x_9 = l_LeanTLS_Crypto_SHA256_toHex(x_8);
x_10 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3;
x_11 = lean_string_dec_eq(x_9, x_10);
if (x_11 == 0)
{
lean_object* x_12; lean_object* x_13; 
x_12 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__4;
x_13 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_12, x_4);
if (lean_obj_tag(x_13) == 0)
{
lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_14 = lean_ctor_get(x_13, 1);
lean_inc(x_14);
lean_dec(x_13);
x_15 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__6;
x_16 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_15, x_14);
if (lean_obj_tag(x_16) == 0)
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; 
x_17 = lean_ctor_get(x_16, 1);
lean_inc(x_17);
lean_dec(x_16);
x_18 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_19 = lean_string_append(x_18, x_9);
lean_dec(x_9);
x_20 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_21 = lean_string_append(x_19, x_20);
x_22 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_21, x_17);
if (lean_obj_tag(x_22) == 0)
{
lean_object* x_23; uint8_t x_24; lean_object* x_25; lean_object* x_26; 
x_23 = lean_ctor_get(x_22, 1);
lean_inc(x_23);
lean_dec(x_22);
x_24 = 0;
x_25 = lean_box(0);
x_26 = l_LeanTLS_KeySchedule_runTests___lambda__6(x_1, x_6, x_8, x_24, x_25, x_23);
return x_26;
}
else
{
uint8_t x_27; 
lean_dec(x_8);
lean_dec(x_1);
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
uint8_t x_31; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
x_31 = !lean_is_exclusive(x_16);
if (x_31 == 0)
{
return x_16;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_32 = lean_ctor_get(x_16, 0);
x_33 = lean_ctor_get(x_16, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_16);
x_34 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_34, 0, x_32);
lean_ctor_set(x_34, 1, x_33);
return x_34;
}
}
}
else
{
uint8_t x_35; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
x_35 = !lean_is_exclusive(x_13);
if (x_35 == 0)
{
return x_13;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_36 = lean_ctor_get(x_13, 0);
x_37 = lean_ctor_get(x_13, 1);
lean_inc(x_37);
lean_inc(x_36);
lean_dec(x_13);
x_38 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_38, 0, x_36);
lean_ctor_set(x_38, 1, x_37);
return x_38;
}
}
}
else
{
lean_object* x_39; lean_object* x_40; 
lean_dec(x_9);
x_39 = l_LeanTLS_KeySchedule_runTests___lambda__7___closed__7;
x_40 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_39, x_4);
if (lean_obj_tag(x_40) == 0)
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_41 = lean_ctor_get(x_40, 0);
lean_inc(x_41);
x_42 = lean_ctor_get(x_40, 1);
lean_inc(x_42);
lean_dec(x_40);
x_43 = l_LeanTLS_KeySchedule_runTests___lambda__6(x_1, x_6, x_8, x_2, x_41, x_42);
lean_dec(x_41);
return x_43;
}
else
{
uint8_t x_44; 
lean_dec(x_8);
lean_dec(x_1);
x_44 = !lean_is_exclusive(x_40);
if (x_44 == 0)
{
return x_40;
}
else
{
lean_object* x_45; lean_object* x_46; lean_object* x_47; 
x_45 = lean_ctor_get(x_40, 0);
x_46 = lean_ctor_get(x_40, 1);
lean_inc(x_46);
lean_inc(x_45);
lean_dec(x_40);
x_47 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_47, 0, x_45);
lean_ctor_set(x_47, 1, x_46);
return x_47;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("8bd4054fb55b9d63fdfbacf9f04b9f0d35e6d63f537563efd46272900f89492d", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__1;
x_2 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("1dc826e93606aa6fdc0aadc12f741b01046aa6b99f691ed221a9f0ca043fbeac", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__4() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 3 (handshake secret): FAILED", 47, 47);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__5;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__7() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 3 (handshake secret): PASSED", 47, 47);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; 
x_5 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__2;
x_6 = l_LeanTLS_KeySchedule_handshakeSecret(x_1, x_5);
x_7 = l_LeanTLS_Crypto_SHA256_toHex(x_6);
x_8 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3;
x_9 = lean_string_dec_eq(x_7, x_8);
if (x_9 == 0)
{
lean_object* x_10; lean_object* x_11; 
x_10 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__4;
x_11 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_10, x_4);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_12 = lean_ctor_get(x_11, 1);
lean_inc(x_12);
lean_dec(x_11);
x_13 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__6;
x_14 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_13, x_12);
if (lean_obj_tag(x_14) == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; 
x_15 = lean_ctor_get(x_14, 1);
lean_inc(x_15);
lean_dec(x_14);
x_16 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_17 = lean_string_append(x_16, x_7);
lean_dec(x_7);
x_18 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_19 = lean_string_append(x_17, x_18);
x_20 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_19, x_15);
if (lean_obj_tag(x_20) == 0)
{
lean_object* x_21; uint8_t x_22; lean_object* x_23; lean_object* x_24; 
x_21 = lean_ctor_get(x_20, 1);
lean_inc(x_21);
lean_dec(x_20);
x_22 = 0;
x_23 = lean_box(0);
x_24 = l_LeanTLS_KeySchedule_runTests___lambda__7(x_6, x_22, x_23, x_21);
return x_24;
}
else
{
uint8_t x_25; 
lean_dec(x_6);
x_25 = !lean_is_exclusive(x_20);
if (x_25 == 0)
{
return x_20;
}
else
{
lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_26 = lean_ctor_get(x_20, 0);
x_27 = lean_ctor_get(x_20, 1);
lean_inc(x_27);
lean_inc(x_26);
lean_dec(x_20);
x_28 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_28, 0, x_26);
lean_ctor_set(x_28, 1, x_27);
return x_28;
}
}
}
else
{
uint8_t x_29; 
lean_dec(x_7);
lean_dec(x_6);
x_29 = !lean_is_exclusive(x_14);
if (x_29 == 0)
{
return x_14;
}
else
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_30 = lean_ctor_get(x_14, 0);
x_31 = lean_ctor_get(x_14, 1);
lean_inc(x_31);
lean_inc(x_30);
lean_dec(x_14);
x_32 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_31);
return x_32;
}
}
}
else
{
uint8_t x_33; 
lean_dec(x_7);
lean_dec(x_6);
x_33 = !lean_is_exclusive(x_11);
if (x_33 == 0)
{
return x_11;
}
else
{
lean_object* x_34; lean_object* x_35; lean_object* x_36; 
x_34 = lean_ctor_get(x_11, 0);
x_35 = lean_ctor_get(x_11, 1);
lean_inc(x_35);
lean_inc(x_34);
lean_dec(x_11);
x_36 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_36, 0, x_34);
lean_ctor_set(x_36, 1, x_35);
return x_36;
}
}
}
else
{
lean_object* x_37; lean_object* x_38; 
lean_dec(x_7);
x_37 = l_LeanTLS_KeySchedule_runTests___lambda__8___closed__7;
x_38 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_37, x_4);
if (lean_obj_tag(x_38) == 0)
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; 
x_39 = lean_ctor_get(x_38, 0);
lean_inc(x_39);
x_40 = lean_ctor_get(x_38, 1);
lean_inc(x_40);
lean_dec(x_38);
x_41 = l_LeanTLS_KeySchedule_runTests___lambda__7(x_6, x_2, x_39, x_40);
lean_dec(x_39);
return x_41;
}
else
{
uint8_t x_42; 
lean_dec(x_6);
x_42 = !lean_is_exclusive(x_38);
if (x_42 == 0)
{
return x_38;
}
else
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; 
x_43 = lean_ctor_get(x_38, 0);
x_44 = lean_ctor_get(x_38, 1);
lean_inc(x_44);
lean_inc(x_43);
lean_dec(x_38);
x_45 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_45, 0, x_43);
lean_ctor_set(x_45, 1, x_44);
return x_45;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("6f2615a108c702c5678f54fc9dbab69716c076189c48250cebeac3576c3611ba", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 2 (derived secret): FAILED", 45, 45);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__9___closed__3;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 2 (derived secret): PASSED", 45, 45);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; 
x_5 = l_LeanTLS_KeySchedule_handshakeSecret___closed__2;
x_6 = l_LeanTLS_KeySchedule_handshakeSecret___closed__1;
x_7 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen;
lean_inc(x_1);
x_8 = l_LeanTLS_KeySchedule_hkdfExpandLabel(x_1, x_5, x_6, x_7);
x_9 = l_LeanTLS_Crypto_SHA256_toHex(x_8);
lean_dec(x_8);
x_10 = l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1;
x_11 = lean_string_dec_eq(x_9, x_10);
if (x_11 == 0)
{
lean_object* x_12; lean_object* x_13; 
x_12 = l_LeanTLS_KeySchedule_runTests___lambda__9___closed__2;
x_13 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_12, x_4);
if (lean_obj_tag(x_13) == 0)
{
lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_14 = lean_ctor_get(x_13, 1);
lean_inc(x_14);
lean_dec(x_13);
x_15 = l_LeanTLS_KeySchedule_runTests___lambda__9___closed__4;
x_16 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_15, x_14);
if (lean_obj_tag(x_16) == 0)
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; 
x_17 = lean_ctor_get(x_16, 1);
lean_inc(x_17);
lean_dec(x_16);
x_18 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_19 = lean_string_append(x_18, x_9);
lean_dec(x_9);
x_20 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_21 = lean_string_append(x_19, x_20);
x_22 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_21, x_17);
if (lean_obj_tag(x_22) == 0)
{
lean_object* x_23; uint8_t x_24; lean_object* x_25; lean_object* x_26; 
x_23 = lean_ctor_get(x_22, 1);
lean_inc(x_23);
lean_dec(x_22);
x_24 = 0;
x_25 = lean_box(0);
x_26 = l_LeanTLS_KeySchedule_runTests___lambda__8(x_1, x_24, x_25, x_23);
return x_26;
}
else
{
uint8_t x_27; 
lean_dec(x_1);
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
uint8_t x_31; 
lean_dec(x_9);
lean_dec(x_1);
x_31 = !lean_is_exclusive(x_16);
if (x_31 == 0)
{
return x_16;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_32 = lean_ctor_get(x_16, 0);
x_33 = lean_ctor_get(x_16, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_16);
x_34 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_34, 0, x_32);
lean_ctor_set(x_34, 1, x_33);
return x_34;
}
}
}
else
{
uint8_t x_35; 
lean_dec(x_9);
lean_dec(x_1);
x_35 = !lean_is_exclusive(x_13);
if (x_35 == 0)
{
return x_13;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_36 = lean_ctor_get(x_13, 0);
x_37 = lean_ctor_get(x_13, 1);
lean_inc(x_37);
lean_inc(x_36);
lean_dec(x_13);
x_38 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_38, 0, x_36);
lean_ctor_set(x_38, 1, x_37);
return x_38;
}
}
}
else
{
lean_object* x_39; lean_object* x_40; 
lean_dec(x_9);
x_39 = l_LeanTLS_KeySchedule_runTests___lambda__9___closed__5;
x_40 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_39, x_4);
if (lean_obj_tag(x_40) == 0)
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_41 = lean_ctor_get(x_40, 0);
lean_inc(x_41);
x_42 = lean_ctor_get(x_40, 1);
lean_inc(x_42);
lean_dec(x_40);
x_43 = l_LeanTLS_KeySchedule_runTests___lambda__8(x_1, x_2, x_41, x_42);
lean_dec(x_41);
return x_43;
}
else
{
uint8_t x_44; 
lean_dec(x_1);
x_44 = !lean_is_exclusive(x_40);
if (x_44 == 0)
{
return x_40;
}
else
{
lean_object* x_45; lean_object* x_46; lean_object* x_47; 
x_45 = lean_ctor_get(x_40, 0);
x_46 = lean_ctor_get(x_40, 1);
lean_inc(x_46);
lean_inc(x_45);
lean_dec(x_40);
x_47 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_47, 0, x_45);
lean_ctor_set(x_47, 1, x_46);
return x_47;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_ByteArray_empty;
x_2 = l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey;
x_3 = l_LeanTLS_Crypto_HKDF_extract(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_KeySchedule_runTests___closed__1;
x_2 = l_LeanTLS_Crypto_SHA256_toHex(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("33ad0a1c607ec03b09e6cd9893680ce210adf300aa1f2660e1b22e10f170f92a", 64, 64);
return x_1;
}
}
static uint8_t _init_l_LeanTLS_KeySchedule_runTests___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; uint8_t x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___closed__2;
x_2 = l_LeanTLS_KeySchedule_runTests___closed__3;
x_3 = lean_string_dec_eq(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 1 (early secret): FAILED", 43, 43);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4;
x_2 = l_LeanTLS_KeySchedule_runTests___closed__3;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___closed__6;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8;
x_2 = l_LeanTLS_KeySchedule_runTests___closed__2;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_KeySchedule_runTests___closed__8;
x_2 = l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_KeySchedule_runTests___closed__10() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  KeySchedule test 1 (early secret): PASSED", 43, 43);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = l_LeanTLS_KeySchedule_runTests___closed__4;
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; 
x_3 = l_LeanTLS_KeySchedule_runTests___closed__5;
x_4 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_3, x_1);
if (lean_obj_tag(x_4) == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_4, 1);
lean_inc(x_5);
lean_dec(x_4);
x_6 = l_LeanTLS_KeySchedule_runTests___closed__7;
x_7 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_6, x_5);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; 
x_8 = lean_ctor_get(x_7, 1);
lean_inc(x_8);
lean_dec(x_7);
x_9 = l_LeanTLS_KeySchedule_runTests___closed__9;
x_10 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_9, x_8);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_11 = lean_ctor_get(x_10, 1);
lean_inc(x_11);
lean_dec(x_10);
x_12 = l_LeanTLS_KeySchedule_runTests___closed__1;
x_13 = 0;
x_14 = lean_box(0);
x_15 = l_LeanTLS_KeySchedule_runTests___lambda__9(x_12, x_13, x_14, x_11);
return x_15;
}
else
{
uint8_t x_16; 
x_16 = !lean_is_exclusive(x_10);
if (x_16 == 0)
{
return x_10;
}
else
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; 
x_17 = lean_ctor_get(x_10, 0);
x_18 = lean_ctor_get(x_10, 1);
lean_inc(x_18);
lean_inc(x_17);
lean_dec(x_10);
x_19 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
return x_19;
}
}
}
else
{
uint8_t x_20; 
x_20 = !lean_is_exclusive(x_7);
if (x_20 == 0)
{
return x_7;
}
else
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_21 = lean_ctor_get(x_7, 0);
x_22 = lean_ctor_get(x_7, 1);
lean_inc(x_22);
lean_inc(x_21);
lean_dec(x_7);
x_23 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_23, 0, x_21);
lean_ctor_set(x_23, 1, x_22);
return x_23;
}
}
}
else
{
uint8_t x_24; 
x_24 = !lean_is_exclusive(x_4);
if (x_24 == 0)
{
return x_4;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_25 = lean_ctor_get(x_4, 0);
x_26 = lean_ctor_get(x_4, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_4);
x_27 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_27, 0, x_25);
lean_ctor_set(x_27, 1, x_26);
return x_27;
}
}
}
else
{
lean_object* x_28; lean_object* x_29; 
x_28 = l_LeanTLS_KeySchedule_runTests___closed__10;
x_29 = l_IO_println___at_LeanTLS_Crypto_SHA256_runTests___spec__1(x_28, x_1);
if (lean_obj_tag(x_29) == 0)
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; uint8_t x_33; lean_object* x_34; 
x_30 = lean_ctor_get(x_29, 0);
lean_inc(x_30);
x_31 = lean_ctor_get(x_29, 1);
lean_inc(x_31);
lean_dec(x_29);
x_32 = l_LeanTLS_KeySchedule_runTests___closed__1;
x_33 = 1;
x_34 = l_LeanTLS_KeySchedule_runTests___lambda__9(x_32, x_33, x_30, x_31);
lean_dec(x_30);
return x_34;
}
else
{
uint8_t x_35; 
x_35 = !lean_is_exclusive(x_29);
if (x_35 == 0)
{
return x_29;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_36 = lean_ctor_get(x_29, 0);
x_37 = lean_ctor_get(x_29, 1);
lean_inc(x_37);
lean_inc(x_36);
lean_dec(x_29);
x_38 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_38, 0, x_36);
lean_ctor_set(x_38, 1, x_37);
return x_38;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_KeySchedule_runTests___lambda__1(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
lean_dec(x_2);
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__2(x_1, x_5, x_3, x_4);
lean_dec(x_3);
lean_dec(x_1);
return x_6;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__3___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
lean_dec(x_2);
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__3(x_1, x_5, x_3, x_4);
lean_dec(x_3);
return x_6;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__4___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
lean_dec(x_3);
x_7 = l_LeanTLS_KeySchedule_runTests___lambda__4(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_4);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__5___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
lean_dec(x_3);
x_7 = l_LeanTLS_KeySchedule_runTests___lambda__5(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_4);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__6___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
uint8_t x_7; lean_object* x_8; 
x_7 = lean_unbox(x_4);
lean_dec(x_4);
x_8 = l_LeanTLS_KeySchedule_runTests___lambda__6(x_1, x_2, x_3, x_7, x_5, x_6);
lean_dec(x_5);
lean_dec(x_2);
return x_8;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__7___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
lean_dec(x_2);
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__7(x_1, x_5, x_3, x_4);
lean_dec(x_3);
return x_6;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__8___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
lean_dec(x_2);
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__8(x_1, x_5, x_3, x_4);
lean_dec(x_3);
return x_6;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_KeySchedule_runTests___lambda__9___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
lean_dec(x_2);
x_6 = l_LeanTLS_KeySchedule_runTests___lambda__9(x_1, x_5, x_3, x_4);
lean_dec(x_3);
return x_6;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_HKDF(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_SHA256(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_LeanTLS_KeySchedule(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_HKDF(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_SHA256(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hashLen);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128KeyLen);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_aes128IVLen);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__1 = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__1();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__1);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__2 = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__2();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey___closed__2);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_zeroKey);
l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes___closed__1 = _init_l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes___closed__1();
lean_mark_persistent(l___private_LeanTLS_KeySchedule_0__LeanTLS_KeySchedule_hexToBytes___closed__1);
l_LeanTLS_KeySchedule_hkdfExpandLabel___closed__1 = _init_l_LeanTLS_KeySchedule_hkdfExpandLabel___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_hkdfExpandLabel___closed__1);
l_LeanTLS_KeySchedule_handshakeSecret___closed__1 = _init_l_LeanTLS_KeySchedule_handshakeSecret___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_handshakeSecret___closed__1);
l_LeanTLS_KeySchedule_handshakeSecret___closed__2 = _init_l_LeanTLS_KeySchedule_handshakeSecret___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_handshakeSecret___closed__2);
l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1 = _init_l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_clientHandshakeTrafficSecret___closed__1);
l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1 = _init_l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_serverHandshakeTrafficSecret___closed__1);
l_LeanTLS_KeySchedule_clientAppTrafficSecret___closed__1 = _init_l_LeanTLS_KeySchedule_clientAppTrafficSecret___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_clientAppTrafficSecret___closed__1);
l_LeanTLS_KeySchedule_serverAppTrafficSecret___closed__1 = _init_l_LeanTLS_KeySchedule_serverAppTrafficSecret___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_serverAppTrafficSecret___closed__1);
l_LeanTLS_KeySchedule_trafficKey___closed__1 = _init_l_LeanTLS_KeySchedule_trafficKey___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_trafficKey___closed__1);
l_LeanTLS_KeySchedule_trafficIV___closed__1 = _init_l_LeanTLS_KeySchedule_trafficIV___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_trafficIV___closed__1);
l_LeanTLS_KeySchedule_finishedKey___closed__1 = _init_l_LeanTLS_KeySchedule_finishedKey___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_finishedKey___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__6);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__7 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__7();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__7);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__8);
l_LeanTLS_KeySchedule_runTests___lambda__2___closed__9 = _init_l_LeanTLS_KeySchedule_runTests___lambda__2___closed__9();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__2___closed__9);
l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__3___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__3___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__3___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__3___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__3___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__3___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__3___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__3___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__3___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__3___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__4___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__4___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__4___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__4___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__4___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__4___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__4___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__4___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__4___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__4___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__5___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__5___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__5___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__5___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__5___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__5___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__5___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__5___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__5___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__5___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__6___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__6___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__6___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__6___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__6___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__6___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__6___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__6___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__6___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__6___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__6 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__6();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__6);
l_LeanTLS_KeySchedule_runTests___lambda__7___closed__7 = _init_l_LeanTLS_KeySchedule_runTests___lambda__7___closed__7();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__7___closed__7);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__5);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__6 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__6();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__6);
l_LeanTLS_KeySchedule_runTests___lambda__8___closed__7 = _init_l_LeanTLS_KeySchedule_runTests___lambda__8___closed__7();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__8___closed__7);
l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__9___closed__1);
l_LeanTLS_KeySchedule_runTests___lambda__9___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__9___closed__2);
l_LeanTLS_KeySchedule_runTests___lambda__9___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__9___closed__3);
l_LeanTLS_KeySchedule_runTests___lambda__9___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__4();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__9___closed__4);
l_LeanTLS_KeySchedule_runTests___lambda__9___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___lambda__9___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___lambda__9___closed__5);
l_LeanTLS_KeySchedule_runTests___closed__1 = _init_l_LeanTLS_KeySchedule_runTests___closed__1();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__1);
l_LeanTLS_KeySchedule_runTests___closed__2 = _init_l_LeanTLS_KeySchedule_runTests___closed__2();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__2);
l_LeanTLS_KeySchedule_runTests___closed__3 = _init_l_LeanTLS_KeySchedule_runTests___closed__3();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__3);
l_LeanTLS_KeySchedule_runTests___closed__4 = _init_l_LeanTLS_KeySchedule_runTests___closed__4();
l_LeanTLS_KeySchedule_runTests___closed__5 = _init_l_LeanTLS_KeySchedule_runTests___closed__5();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__5);
l_LeanTLS_KeySchedule_runTests___closed__6 = _init_l_LeanTLS_KeySchedule_runTests___closed__6();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__6);
l_LeanTLS_KeySchedule_runTests___closed__7 = _init_l_LeanTLS_KeySchedule_runTests___closed__7();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__7);
l_LeanTLS_KeySchedule_runTests___closed__8 = _init_l_LeanTLS_KeySchedule_runTests___closed__8();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__8);
l_LeanTLS_KeySchedule_runTests___closed__9 = _init_l_LeanTLS_KeySchedule_runTests___closed__9();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__9);
l_LeanTLS_KeySchedule_runTests___closed__10 = _init_l_LeanTLS_KeySchedule_runTests___closed__10();
lean_mark_persistent(l_LeanTLS_KeySchedule_runTests___closed__10);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
