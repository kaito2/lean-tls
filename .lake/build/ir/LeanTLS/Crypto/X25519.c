// Lean compiler output
// Module: LeanTLS.Crypto.X25519
// Imports: Init
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
static lean_object* l_LeanTLS_Crypto_X25519_basePoint___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_x25519(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_basePoint___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_basePoint_pad(lean_object*, lean_object*);
uint8_t lean_uint8_lor(uint8_t, uint8_t);
uint8_t lean_byte_array_fget(lean_object*, lean_object*);
lean_object* lean_uint32_to_nat(uint32_t);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSub___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder_loop___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldAdd(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_nibbleToHexChar___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_encodeLE32(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldReduce___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex_go___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__3;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldInv(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder_loop(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_p___closed__2;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__12;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_getBit___boxed(lean_object*, lean_object*);
uint8_t lean_uint8_land(uint8_t, uint8_t);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__10;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_ladderStep(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldInv___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeUCoordinate(lean_object*);
lean_object* lean_byte_array_push(lean_object*, uint8_t);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__2;
static lean_object* l_LeanTLS_Crypto_X25519_basePoint___closed__3;
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__4;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldPow(lean_object*, lean_object*);
lean_object* lean_string_push(lean_object*, uint32_t);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE_go(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__7;
lean_object* lean_byte_array_set(lean_object*, lean_object*, uint8_t);
lean_object* lean_string_data(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_fieldInv___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_nibbleToHexChar(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__17;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3(uint8_t, lean_object*, lean_object*);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
extern lean_object* l_ByteArray_empty;
lean_object* lean_nat_div(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldMul___boxed(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__13;
lean_object* lean_string_mk(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldMul(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_p___closed__1;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_clamp(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__1;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__3;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_byteToHex(uint8_t);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__2;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSq(lean_object*);
LEAN_EXPORT lean_object* l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__15;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_basePoint;
lean_object* l_IO_print___at_IO_println___spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldReduce(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexCharToNat(uint32_t);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSq___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_ladderStep___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__12;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__6;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__1(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_a24;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldAdd___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexCharToNat___boxed(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__7;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldPow___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexToBytes_go(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldPow_go(lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_empty_byte_array(lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__15;
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE_go___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__5;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder(lean_object*, lean_object*);
static uint8_t l_LeanTLS_Crypto_X25519_runTests___closed__9;
static uint8_t l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__9;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___boxed(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__16;
LEAN_EXPORT uint8_t l_LeanTLS_Crypto_X25519_getBit(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__8;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__2(uint8_t, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__11;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__10;
uint8_t lean_uint8_of_nat(lean_object*);
uint8_t lean_byte_array_get(lean_object*, lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_encodeLE32_go(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_byteToHex___boxed(lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__2;
lean_object* lean_string_append(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexToBytes(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_p;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex_go(lean_object*, lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__1;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__13;
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__1___boxed(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE___boxed(lean_object*);
lean_object* lean_byte_array_size(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__2___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_Char_ofNat(lean_object*);
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSub(lean_object*, lean_object*);
static lean_object* l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__4;
static lean_object* l_LeanTLS_Crypto_X25519_runTests___closed__14;
static lean_object* _init_l_LeanTLS_Crypto_X25519_p___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_cstr_to_nat("57896044618658097711785492504343953926634992332820282019728792003956564819968");
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_p___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_p___closed__1;
x_2 = lean_unsigned_to_nat(19u);
x_3 = lean_nat_sub(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_p() {
_start:
{
lean_object* x_1; 
x_1 = l_LeanTLS_Crypto_X25519_p___closed__2;
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_a24() {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(121665u);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldReduce(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = l_LeanTLS_Crypto_X25519_p;
x_3 = lean_nat_mod(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldReduce___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Crypto_X25519_fieldReduce(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldAdd(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_nat_add(x_1, x_2);
x_4 = l_LeanTLS_Crypto_X25519_p;
x_5 = lean_nat_mod(x_3, x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldAdd___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Crypto_X25519_fieldAdd(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSub(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_3 = l_LeanTLS_Crypto_X25519_p;
x_4 = lean_nat_add(x_1, x_3);
x_5 = lean_nat_mod(x_2, x_3);
x_6 = lean_nat_sub(x_4, x_5);
lean_dec(x_5);
lean_dec(x_4);
x_7 = lean_nat_mod(x_6, x_3);
lean_dec(x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSub___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Crypto_X25519_fieldSub(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldMul(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_nat_mul(x_1, x_2);
x_4 = l_LeanTLS_Crypto_X25519_p;
x_5 = lean_nat_mod(x_3, x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldMul___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Crypto_X25519_fieldMul(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSq(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_2 = lean_nat_mul(x_1, x_1);
x_3 = l_LeanTLS_Crypto_X25519_p;
x_4 = lean_nat_mod(x_2, x_3);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldSq___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Crypto_X25519_fieldSq(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldPow_go(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_unsigned_to_nat(0u);
x_5 = lean_nat_dec_eq(x_2, x_4);
if (x_5 == 0)
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_6 = lean_unsigned_to_nat(2u);
x_7 = lean_nat_mod(x_2, x_6);
x_8 = lean_unsigned_to_nat(1u);
x_9 = lean_nat_dec_eq(x_7, x_8);
lean_dec(x_7);
x_10 = lean_nat_mul(x_1, x_1);
x_11 = l_LeanTLS_Crypto_X25519_p;
x_12 = lean_nat_mod(x_10, x_11);
lean_dec(x_10);
x_13 = lean_nat_div(x_2, x_6);
lean_dec(x_2);
if (x_9 == 0)
{
lean_dec(x_1);
x_1 = x_12;
x_2 = x_13;
goto _start;
}
else
{
lean_object* x_15; lean_object* x_16; 
x_15 = lean_nat_mul(x_3, x_1);
lean_dec(x_1);
lean_dec(x_3);
x_16 = lean_nat_mod(x_15, x_11);
lean_dec(x_15);
x_1 = x_12;
x_2 = x_13;
x_3 = x_16;
goto _start;
}
}
else
{
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldPow(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_3 = l_LeanTLS_Crypto_X25519_p;
x_4 = lean_nat_mod(x_1, x_3);
x_5 = lean_unsigned_to_nat(1u);
x_6 = l_LeanTLS_Crypto_X25519_fieldPow_go(x_4, x_2, x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldPow___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Crypto_X25519_fieldPow(x_1, x_2);
lean_dec(x_1);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_fieldInv___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_p;
x_2 = lean_unsigned_to_nat(2u);
x_3 = lean_nat_sub(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldInv(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = l_LeanTLS_Crypto_X25519_fieldInv___closed__1;
x_3 = l_LeanTLS_Crypto_X25519_fieldPow(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_fieldInv___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Crypto_X25519_fieldInv(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE_go(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_byte_array_size(x_1);
x_5 = lean_nat_dec_lt(x_2, x_4);
lean_dec(x_4);
if (x_5 == 0)
{
lean_dec(x_2);
return x_3;
}
else
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_6 = lean_unsigned_to_nat(1u);
x_7 = lean_nat_add(x_2, x_6);
x_8 = lean_byte_array_fget(x_1, x_2);
x_9 = lean_uint8_to_nat(x_8);
x_10 = lean_unsigned_to_nat(8u);
x_11 = lean_nat_mul(x_10, x_2);
lean_dec(x_2);
x_12 = lean_unsigned_to_nat(2u);
x_13 = lean_nat_pow(x_12, x_11);
lean_dec(x_11);
x_14 = lean_nat_mul(x_9, x_13);
lean_dec(x_13);
lean_dec(x_9);
x_15 = lean_nat_add(x_3, x_14);
lean_dec(x_14);
lean_dec(x_3);
x_2 = x_7;
x_3 = x_15;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE_go___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_LeanTLS_Crypto_X25519_decodeLE_go(x_1, x_2, x_3);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = l_LeanTLS_Crypto_X25519_decodeLE_go(x_1, x_2, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeLE___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Crypto_X25519_decodeLE(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_encodeLE32_go(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_unsigned_to_nat(32u);
x_5 = lean_nat_dec_lt(x_1, x_4);
if (x_5 == 0)
{
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; 
x_6 = lean_unsigned_to_nat(1u);
x_7 = lean_nat_add(x_1, x_6);
lean_dec(x_1);
x_8 = lean_unsigned_to_nat(256u);
x_9 = lean_nat_div(x_2, x_8);
x_10 = lean_nat_mod(x_2, x_8);
lean_dec(x_2);
x_11 = lean_uint8_of_nat(x_10);
lean_dec(x_10);
x_12 = lean_byte_array_push(x_3, x_11);
x_1 = x_7;
x_2 = x_9;
x_3 = x_12;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_encodeLE32(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = l_ByteArray_empty;
x_4 = l_LeanTLS_Crypto_X25519_encodeLE32_go(x_2, x_1, x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexCharToNat(uint32_t x_1) {
_start:
{
lean_object* x_2; uint32_t x_35; uint8_t x_36; 
x_35 = 48;
x_36 = lean_uint32_dec_le(x_35, x_1);
if (x_36 == 0)
{
lean_object* x_37; 
x_37 = lean_box(0);
x_2 = x_37;
goto block_34;
}
else
{
uint32_t x_38; uint8_t x_39; 
x_38 = 57;
x_39 = lean_uint32_dec_le(x_1, x_38);
if (x_39 == 0)
{
lean_object* x_40; 
x_40 = lean_box(0);
x_2 = x_40;
goto block_34;
}
else
{
lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_41 = lean_uint32_to_nat(x_1);
x_42 = lean_unsigned_to_nat(48u);
x_43 = lean_nat_sub(x_41, x_42);
lean_dec(x_41);
return x_43;
}
}
block_34:
{
uint32_t x_3; uint8_t x_4; 
lean_dec(x_2);
x_3 = 97;
x_4 = lean_uint32_dec_le(x_3, x_1);
if (x_4 == 0)
{
uint32_t x_5; uint8_t x_6; 
x_5 = 65;
x_6 = lean_uint32_dec_le(x_5, x_1);
if (x_6 == 0)
{
lean_object* x_7; 
x_7 = lean_unsigned_to_nat(0u);
return x_7;
}
else
{
uint32_t x_8; uint8_t x_9; 
x_8 = 70;
x_9 = lean_uint32_dec_le(x_1, x_8);
if (x_9 == 0)
{
lean_object* x_10; 
x_10 = lean_unsigned_to_nat(0u);
return x_10;
}
else
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_11 = lean_uint32_to_nat(x_1);
x_12 = lean_unsigned_to_nat(65u);
x_13 = lean_nat_sub(x_11, x_12);
lean_dec(x_11);
x_14 = lean_unsigned_to_nat(10u);
x_15 = lean_nat_add(x_13, x_14);
lean_dec(x_13);
return x_15;
}
}
}
else
{
uint32_t x_16; uint8_t x_17; 
x_16 = 102;
x_17 = lean_uint32_dec_le(x_1, x_16);
if (x_17 == 0)
{
uint32_t x_18; uint8_t x_19; 
x_18 = 65;
x_19 = lean_uint32_dec_le(x_18, x_1);
if (x_19 == 0)
{
lean_object* x_20; 
x_20 = lean_unsigned_to_nat(0u);
return x_20;
}
else
{
uint32_t x_21; uint8_t x_22; 
x_21 = 70;
x_22 = lean_uint32_dec_le(x_1, x_21);
if (x_22 == 0)
{
lean_object* x_23; 
x_23 = lean_unsigned_to_nat(0u);
return x_23;
}
else
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_24 = lean_uint32_to_nat(x_1);
x_25 = lean_unsigned_to_nat(65u);
x_26 = lean_nat_sub(x_24, x_25);
lean_dec(x_24);
x_27 = lean_unsigned_to_nat(10u);
x_28 = lean_nat_add(x_26, x_27);
lean_dec(x_26);
return x_28;
}
}
}
else
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; 
x_29 = lean_uint32_to_nat(x_1);
x_30 = lean_unsigned_to_nat(97u);
x_31 = lean_nat_sub(x_29, x_30);
lean_dec(x_29);
x_32 = lean_unsigned_to_nat(10u);
x_33 = lean_nat_add(x_31, x_32);
lean_dec(x_31);
return x_33;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexCharToNat___boxed(lean_object* x_1) {
_start:
{
uint32_t x_2; lean_object* x_3; 
x_2 = lean_unbox_uint32(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Crypto_X25519_hexCharToNat(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexToBytes_go(lean_object* x_1, lean_object* x_2) {
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
lean_object* x_4; lean_object* x_5; lean_object* x_6; uint32_t x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint32_t x_11; lean_object* x_12; lean_object* x_13; uint8_t x_14; lean_object* x_15; 
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
x_8 = l_LeanTLS_Crypto_X25519_hexCharToNat(x_7);
x_9 = lean_unsigned_to_nat(16u);
x_10 = lean_nat_mul(x_8, x_9);
lean_dec(x_8);
x_11 = lean_unbox_uint32(x_5);
lean_dec(x_5);
x_12 = l_LeanTLS_Crypto_X25519_hexCharToNat(x_11);
x_13 = lean_nat_add(x_10, x_12);
lean_dec(x_12);
lean_dec(x_10);
x_14 = lean_uint8_of_nat(x_13);
lean_dec(x_13);
x_15 = lean_byte_array_push(x_2, x_14);
x_1 = x_6;
x_2 = x_15;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_hexToBytes(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_2 = lean_string_data(x_1);
x_3 = l_ByteArray_empty;
x_4 = l_LeanTLS_Crypto_X25519_hexToBytes_go(x_2, x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_nibbleToHexChar(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = lean_unsigned_to_nat(10u);
x_3 = lean_nat_dec_lt(x_1, x_2);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_4 = lean_unsigned_to_nat(97u);
x_5 = lean_nat_add(x_4, x_1);
x_6 = lean_nat_sub(x_5, x_2);
lean_dec(x_5);
x_7 = l_Char_ofNat(x_6);
lean_dec(x_6);
return x_7;
}
else
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; 
x_8 = lean_unsigned_to_nat(48u);
x_9 = lean_nat_add(x_8, x_1);
x_10 = l_Char_ofNat(x_9);
lean_dec(x_9);
return x_10;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_nibbleToHexChar___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Crypto_X25519_nibbleToHexChar(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_byteToHex(uint8_t x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint32_t x_7; lean_object* x_8; uint32_t x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_2 = lean_uint8_to_nat(x_1);
x_3 = lean_unsigned_to_nat(16u);
x_4 = lean_nat_div(x_2, x_3);
x_5 = lean_nat_mod(x_2, x_3);
lean_dec(x_2);
x_6 = l_LeanTLS_Crypto_X25519_nibbleToHexChar(x_4);
lean_dec(x_4);
x_7 = lean_unbox_uint32(x_6);
lean_dec(x_6);
x_8 = l_LeanTLS_Crypto_X25519_nibbleToHexChar(x_5);
lean_dec(x_5);
x_9 = lean_unbox_uint32(x_8);
lean_dec(x_8);
x_10 = lean_box(0);
x_11 = lean_box_uint32(x_9);
x_12 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_12, 0, x_11);
lean_ctor_set(x_12, 1, x_10);
x_13 = lean_box_uint32(x_7);
x_14 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_14, 0, x_13);
lean_ctor_set(x_14, 1, x_12);
x_15 = lean_string_mk(x_14);
return x_15;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_byteToHex___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
lean_dec(x_1);
x_3 = l_LeanTLS_Crypto_X25519_byteToHex(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex_go(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_byte_array_size(x_1);
x_5 = lean_nat_dec_lt(x_2, x_4);
lean_dec(x_4);
if (x_5 == 0)
{
lean_dec(x_2);
return x_3;
}
else
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; 
x_6 = lean_unsigned_to_nat(1u);
x_7 = lean_nat_add(x_2, x_6);
x_8 = lean_byte_array_fget(x_1, x_2);
lean_dec(x_2);
x_9 = l_LeanTLS_Crypto_X25519_byteToHex(x_8);
x_10 = lean_string_append(x_3, x_9);
lean_dec(x_9);
x_2 = x_7;
x_3 = x_10;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex_go___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_LeanTLS_Crypto_X25519_bytesToHex_go(x_1, x_2, x_3);
lean_dec(x_1);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_bytesToHex___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("", 0, 0);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_4 = l_LeanTLS_Crypto_X25519_bytesToHex_go(x_1, x_2, x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_bytesToHex___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_LeanTLS_Crypto_X25519_bytesToHex(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_clamp(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; uint8_t x_4; 
x_2 = lean_byte_array_size(x_1);
x_3 = lean_unsigned_to_nat(32u);
x_4 = lean_nat_dec_lt(x_2, x_3);
lean_dec(x_2);
if (x_4 == 0)
{
lean_object* x_5; uint8_t x_6; uint8_t x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; uint8_t x_12; uint8_t x_13; lean_object* x_14; uint8_t x_15; uint8_t x_16; uint8_t x_17; lean_object* x_18; 
x_5 = lean_unsigned_to_nat(0u);
x_6 = lean_byte_array_get(x_1, x_5);
x_7 = 248;
x_8 = lean_uint8_land(x_6, x_7);
x_9 = lean_byte_array_set(x_1, x_5, x_8);
x_10 = lean_unsigned_to_nat(31u);
x_11 = lean_byte_array_get(x_9, x_10);
x_12 = 127;
x_13 = lean_uint8_land(x_11, x_12);
x_14 = lean_byte_array_set(x_9, x_10, x_13);
x_15 = lean_byte_array_get(x_14, x_10);
x_16 = 64;
x_17 = lean_uint8_lor(x_15, x_16);
x_18 = lean_byte_array_set(x_14, x_10, x_17);
return x_18;
}
else
{
return x_1;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_decodeUCoordinate(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; uint8_t x_4; 
x_2 = lean_byte_array_size(x_1);
x_3 = lean_unsigned_to_nat(32u);
x_4 = lean_nat_dec_lt(x_2, x_3);
lean_dec(x_2);
if (x_4 == 0)
{
lean_object* x_5; uint8_t x_6; uint8_t x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_5 = lean_unsigned_to_nat(31u);
x_6 = lean_byte_array_get(x_1, x_5);
x_7 = 127;
x_8 = lean_uint8_land(x_6, x_7);
x_9 = lean_byte_array_set(x_1, x_5, x_8);
x_10 = lean_unsigned_to_nat(0u);
x_11 = l_LeanTLS_Crypto_X25519_decodeLE_go(x_9, x_10, x_10);
lean_dec(x_9);
return x_11;
}
else
{
lean_object* x_12; lean_object* x_13; 
x_12 = lean_unsigned_to_nat(0u);
x_13 = l_LeanTLS_Crypto_X25519_decodeLE_go(x_1, x_12, x_12);
lean_dec(x_1);
return x_13;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_ladderStep(lean_object* x_1, lean_object* x_2, uint8_t x_3) {
_start:
{
uint8_t x_4; 
if (x_3 == 0)
{
uint8_t x_46; 
x_46 = 0;
x_4 = x_46;
goto block_45;
}
else
{
uint8_t x_47; 
x_47 = 1;
x_4 = x_47;
goto block_45;
}
block_45:
{
lean_object* x_5; lean_object* x_6; 
if (x_4 == 0)
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_33 = lean_ctor_get(x_1, 0);
x_34 = lean_ctor_get(x_1, 1);
x_35 = lean_ctor_get(x_1, 2);
x_36 = lean_ctor_get(x_1, 3);
lean_inc(x_36);
lean_inc(x_35);
x_37 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_37, 0, x_35);
lean_ctor_set(x_37, 1, x_36);
lean_inc(x_34);
x_38 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_38, 0, x_34);
lean_ctor_set(x_38, 1, x_37);
x_5 = x_33;
x_6 = x_38;
goto block_32;
}
else
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; 
x_39 = lean_ctor_get(x_1, 0);
x_40 = lean_ctor_get(x_1, 1);
x_41 = lean_ctor_get(x_1, 2);
x_42 = lean_ctor_get(x_1, 3);
lean_inc(x_40);
lean_inc(x_39);
x_43 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_43, 0, x_39);
lean_ctor_set(x_43, 1, x_40);
lean_inc(x_42);
x_44 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_44, 0, x_42);
lean_ctor_set(x_44, 1, x_43);
x_5 = x_41;
x_6 = x_44;
goto block_32;
}
block_32:
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; 
x_7 = lean_ctor_get(x_6, 1);
lean_inc(x_7);
x_8 = lean_ctor_get(x_6, 0);
lean_inc(x_8);
lean_dec(x_6);
x_9 = lean_ctor_get(x_7, 0);
lean_inc(x_9);
x_10 = lean_ctor_get(x_7, 1);
lean_inc(x_10);
lean_dec(x_7);
x_11 = l_LeanTLS_Crypto_X25519_fieldAdd(x_5, x_8);
x_12 = l_LeanTLS_Crypto_X25519_fieldSq(x_11);
x_13 = l_LeanTLS_Crypto_X25519_fieldSub(x_5, x_8);
lean_dec(x_8);
x_14 = l_LeanTLS_Crypto_X25519_fieldSq(x_13);
x_15 = l_LeanTLS_Crypto_X25519_fieldSub(x_12, x_14);
x_16 = l_LeanTLS_Crypto_X25519_fieldAdd(x_9, x_10);
x_17 = l_LeanTLS_Crypto_X25519_fieldSub(x_9, x_10);
lean_dec(x_10);
lean_dec(x_9);
x_18 = l_LeanTLS_Crypto_X25519_fieldMul(x_17, x_11);
lean_dec(x_11);
lean_dec(x_17);
x_19 = l_LeanTLS_Crypto_X25519_fieldMul(x_16, x_13);
lean_dec(x_13);
lean_dec(x_16);
x_20 = l_LeanTLS_Crypto_X25519_fieldAdd(x_18, x_19);
x_21 = l_LeanTLS_Crypto_X25519_fieldSq(x_20);
lean_dec(x_20);
x_22 = l_LeanTLS_Crypto_X25519_fieldSub(x_18, x_19);
lean_dec(x_19);
lean_dec(x_18);
x_23 = l_LeanTLS_Crypto_X25519_fieldSq(x_22);
lean_dec(x_22);
x_24 = l_LeanTLS_Crypto_X25519_fieldMul(x_2, x_23);
lean_dec(x_23);
x_25 = l_LeanTLS_Crypto_X25519_fieldMul(x_12, x_14);
lean_dec(x_14);
x_26 = l_LeanTLS_Crypto_X25519_a24;
x_27 = l_LeanTLS_Crypto_X25519_fieldMul(x_26, x_15);
x_28 = l_LeanTLS_Crypto_X25519_fieldAdd(x_12, x_27);
lean_dec(x_27);
lean_dec(x_12);
x_29 = l_LeanTLS_Crypto_X25519_fieldMul(x_15, x_28);
lean_dec(x_28);
lean_dec(x_15);
if (x_4 == 0)
{
lean_object* x_30; 
x_30 = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(x_30, 0, x_25);
lean_ctor_set(x_30, 1, x_29);
lean_ctor_set(x_30, 2, x_21);
lean_ctor_set(x_30, 3, x_24);
return x_30;
}
else
{
lean_object* x_31; 
x_31 = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(x_31, 0, x_21);
lean_ctor_set(x_31, 1, x_24);
lean_ctor_set(x_31, 2, x_25);
lean_ctor_set(x_31, 3, x_29);
return x_31;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_ladderStep___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_3);
lean_dec(x_3);
x_5 = l_LeanTLS_Crypto_X25519_ladderStep(x_1, x_2, x_4);
lean_dec(x_2);
lean_dec(x_1);
return x_5;
}
}
LEAN_EXPORT uint8_t l_LeanTLS_Crypto_X25519_getBit(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_3 = lean_unsigned_to_nat(2u);
x_4 = lean_nat_pow(x_3, x_2);
x_5 = lean_nat_div(x_1, x_4);
lean_dec(x_4);
x_6 = lean_nat_mod(x_5, x_3);
lean_dec(x_5);
x_7 = lean_unsigned_to_nat(1u);
x_8 = lean_nat_dec_eq(x_6, x_7);
lean_dec(x_6);
return x_8;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_getBit___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = l_LeanTLS_Crypto_X25519_getBit(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder_loop(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_5 = l_LeanTLS_Crypto_X25519_getBit(x_1, x_3);
x_6 = l_LeanTLS_Crypto_X25519_ladderStep(x_4, x_2, x_5);
lean_dec(x_4);
x_7 = lean_unsigned_to_nat(0u);
x_8 = lean_nat_dec_eq(x_3, x_7);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = lean_unsigned_to_nat(1u);
x_10 = lean_nat_sub(x_3, x_9);
lean_dec(x_3);
x_3 = x_10;
x_4 = x_6;
goto _start;
}
else
{
lean_dec(x_3);
return x_6;
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder_loop___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_LeanTLS_Crypto_X25519_montgomeryLadder_loop(x_1, x_2, x_3, x_4);
lean_dec(x_2);
lean_dec(x_1);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_3 = lean_unsigned_to_nat(1u);
x_4 = lean_unsigned_to_nat(0u);
lean_inc(x_2);
x_5 = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
lean_ctor_set(x_5, 2, x_2);
lean_ctor_set(x_5, 3, x_3);
x_6 = lean_unsigned_to_nat(254u);
x_7 = l_LeanTLS_Crypto_X25519_montgomeryLadder_loop(x_1, x_2, x_6, x_5);
lean_dec(x_2);
x_8 = lean_ctor_get(x_7, 0);
lean_inc(x_8);
x_9 = lean_ctor_get(x_7, 1);
lean_inc(x_9);
lean_dec(x_7);
x_10 = l_LeanTLS_Crypto_X25519_fieldInv(x_9);
lean_dec(x_9);
x_11 = l_LeanTLS_Crypto_X25519_fieldMul(x_8, x_10);
lean_dec(x_10);
lean_dec(x_8);
return x_11;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_montgomeryLadder___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_LeanTLS_Crypto_X25519_montgomeryLadder(x_1, x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_x25519(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_3 = l_LeanTLS_Crypto_X25519_clamp(x_1);
x_4 = lean_unsigned_to_nat(0u);
x_5 = l_LeanTLS_Crypto_X25519_decodeLE_go(x_3, x_4, x_4);
lean_dec(x_3);
x_6 = l_LeanTLS_Crypto_X25519_decodeUCoordinate(x_2);
x_7 = l_LeanTLS_Crypto_X25519_montgomeryLadder(x_5, x_6);
lean_dec(x_5);
x_8 = l_ByteArray_empty;
x_9 = l_LeanTLS_Crypto_X25519_encodeLE32_go(x_4, x_7, x_8);
return x_9;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_basePoint_pad(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; uint8_t x_4; 
x_3 = lean_unsigned_to_nat(31u);
x_4 = lean_nat_dec_lt(x_1, x_3);
if (x_4 == 0)
{
lean_dec(x_1);
return x_2;
}
else
{
lean_object* x_5; lean_object* x_6; uint8_t x_7; lean_object* x_8; 
x_5 = lean_unsigned_to_nat(1u);
x_6 = lean_nat_add(x_1, x_5);
lean_dec(x_1);
x_7 = 0;
x_8 = lean_byte_array_push(x_2, x_7);
x_1 = x_6;
x_2 = x_8;
goto _start;
}
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_basePoint___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(32u);
x_2 = lean_mk_empty_byte_array(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_basePoint___closed__2() {
_start:
{
uint8_t x_1; lean_object* x_2; lean_object* x_3; 
x_1 = 9;
x_2 = l_LeanTLS_Crypto_X25519_basePoint___closed__1;
x_3 = lean_byte_array_push(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_basePoint___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_LeanTLS_Crypto_X25519_basePoint___closed__2;
x_3 = l_LeanTLS_Crypto_X25519_basePoint_pad(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_basePoint() {
_start:
{
lean_object* x_1; 
x_1 = l_LeanTLS_Crypto_X25519_basePoint___closed__3;
return x_1;
}
}
LEAN_EXPORT lean_object* l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(lean_object* x_1, lean_object* x_2) {
_start:
{
uint32_t x_3; lean_object* x_4; lean_object* x_5; 
x_3 = 10;
x_4 = lean_string_push(x_1, x_3);
x_5 = l_IO_print___at_IO_println___spec__1(x_4, x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__1(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
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
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("Some X25519 tests FAILED!", 25, 25);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("All X25519 tests passed!", 24, 24);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__2(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (x_1 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__1;
x_5 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_4, x_3);
if (lean_obj_tag(x_5) == 0)
{
uint8_t x_6; 
x_6 = !lean_is_exclusive(x_5);
if (x_6 == 0)
{
lean_object* x_7; lean_object* x_8; 
x_7 = lean_ctor_get(x_5, 0);
lean_dec(x_7);
x_8 = lean_box(x_1);
lean_ctor_set(x_5, 0, x_8);
return x_5;
}
else
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_9 = lean_ctor_get(x_5, 1);
lean_inc(x_9);
lean_dec(x_5);
x_10 = lean_box(x_1);
x_11 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_11, 0, x_10);
lean_ctor_set(x_11, 1, x_9);
return x_11;
}
}
else
{
uint8_t x_12; 
x_12 = !lean_is_exclusive(x_5);
if (x_12 == 0)
{
return x_5;
}
else
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_13 = lean_ctor_get(x_5, 0);
x_14 = lean_ctor_get(x_5, 1);
lean_inc(x_14);
lean_inc(x_13);
lean_dec(x_5);
x_15 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_15, 0, x_13);
lean_ctor_set(x_15, 1, x_14);
return x_15;
}
}
}
else
{
lean_object* x_16; lean_object* x_17; 
x_16 = l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__2;
x_17 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_16, x_3);
if (lean_obj_tag(x_17) == 0)
{
uint8_t x_18; 
x_18 = !lean_is_exclusive(x_17);
if (x_18 == 0)
{
lean_object* x_19; lean_object* x_20; 
x_19 = lean_ctor_get(x_17, 0);
lean_dec(x_19);
x_20 = lean_box(x_1);
lean_ctor_set(x_17, 0, x_20);
return x_17;
}
else
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_21 = lean_ctor_get(x_17, 1);
lean_inc(x_21);
lean_dec(x_17);
x_22 = lean_box(x_1);
x_23 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_23, 0, x_22);
lean_ctor_set(x_23, 1, x_21);
return x_23;
}
}
else
{
uint8_t x_24; 
x_24 = !lean_is_exclusive(x_17);
if (x_24 == 0)
{
return x_17;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_25 = lean_ctor_get(x_17, 0);
x_26 = lean_ctor_get(x_17, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_17);
x_27 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_27, 0, x_25);
lean_ctor_set(x_27, 1, x_26);
return x_27;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("4b66e9d4d1b4673c5ad22691957d6af5c11b6421e0ea01d42ca4169e7918ba0d", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__1;
x_2 = l_LeanTLS_Crypto_X25519_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("e5210f12786811d3f4b7959d0538ae2c31dbe7106fc03c3efc4cd549c715a493", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__3;
x_2 = l_LeanTLS_Crypto_X25519_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__2;
x_2 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__4;
x_3 = l_LeanTLS_Crypto_X25519_x25519(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__5;
x_2 = lean_unsigned_to_nat(0u);
x_3 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_4 = l_LeanTLS_Crypto_X25519_bytesToHex_go(x_1, x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__7() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Crypto_X25519_runTests___lambda__2___boxed), 3, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("95cbde9476e8907d7aade45cb4b873f88b595a68799fa152e6f8f7647aac7957", 64, 64);
return x_1;
}
}
static uint8_t _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; uint8_t x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6;
x_2 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8;
x_3 = lean_string_dec_eq(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__10() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("Test vector 2: FAILED", 21, 21);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Expected: ", 12, 12);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__12() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11;
x_2 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__13() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__12;
x_2 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("  Got:      ", 12, 12);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__15() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14;
x_2 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__16() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__15;
x_2 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__17() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("Test vector 2: PASSED", 21, 21);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; uint8_t x_5; 
x_4 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__7;
x_5 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__9;
if (x_5 == 0)
{
lean_object* x_6; lean_object* x_7; 
x_6 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__10;
x_7 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_6, x_3);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; 
x_8 = lean_ctor_get(x_7, 1);
lean_inc(x_8);
lean_dec(x_7);
x_9 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__13;
x_10 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_9, x_8);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_11 = lean_ctor_get(x_10, 1);
lean_inc(x_11);
lean_dec(x_10);
x_12 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__16;
x_13 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_12, x_11);
if (lean_obj_tag(x_13) == 0)
{
lean_object* x_14; uint8_t x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_14 = lean_ctor_get(x_13, 1);
lean_inc(x_14);
lean_dec(x_13);
x_15 = 0;
x_16 = lean_box(0);
x_17 = lean_box(x_15);
x_18 = lean_apply_3(x_4, x_17, x_16, x_14);
return x_18;
}
else
{
uint8_t x_19; 
x_19 = !lean_is_exclusive(x_13);
if (x_19 == 0)
{
return x_13;
}
else
{
lean_object* x_20; lean_object* x_21; lean_object* x_22; 
x_20 = lean_ctor_get(x_13, 0);
x_21 = lean_ctor_get(x_13, 1);
lean_inc(x_21);
lean_inc(x_20);
lean_dec(x_13);
x_22 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_22, 0, x_20);
lean_ctor_set(x_22, 1, x_21);
return x_22;
}
}
}
else
{
uint8_t x_23; 
x_23 = !lean_is_exclusive(x_10);
if (x_23 == 0)
{
return x_10;
}
else
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_24 = lean_ctor_get(x_10, 0);
x_25 = lean_ctor_get(x_10, 1);
lean_inc(x_25);
lean_inc(x_24);
lean_dec(x_10);
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
x_27 = !lean_is_exclusive(x_7);
if (x_27 == 0)
{
return x_7;
}
else
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_28 = lean_ctor_get(x_7, 0);
x_29 = lean_ctor_get(x_7, 1);
lean_inc(x_29);
lean_inc(x_28);
lean_dec(x_7);
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
x_31 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__17;
x_32 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_31, x_3);
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; 
x_33 = lean_ctor_get(x_32, 0);
lean_inc(x_33);
x_34 = lean_ctor_get(x_32, 1);
lean_inc(x_34);
lean_dec(x_32);
x_35 = lean_box(x_1);
x_36 = lean_apply_3(x_4, x_35, x_33, x_34);
return x_36;
}
else
{
uint8_t x_37; 
x_37 = !lean_is_exclusive(x_32);
if (x_37 == 0)
{
return x_32;
}
else
{
lean_object* x_38; lean_object* x_39; lean_object* x_40; 
x_38 = lean_ctor_get(x_32, 0);
x_39 = lean_ctor_get(x_32, 1);
lean_inc(x_39);
lean_inc(x_38);
lean_dec(x_32);
x_40 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_40, 0, x_38);
lean_ctor_set(x_40, 1, x_39);
return x_40;
}
}
}
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("a546e36bf0527c9d3b16154b82465edd62144c0ac1fc5a18506a2244ba449ac4", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__1;
x_2 = l_LeanTLS_Crypto_X25519_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("e6db6867583030db3594c1a424b15f7c726624ec26b3353b10a903a6d0ab1c4c", 64, 64);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__3;
x_2 = l_LeanTLS_Crypto_X25519_hexToBytes(x_1);
return x_2;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__2;
x_2 = l_LeanTLS_Crypto_X25519_runTests___closed__4;
x_3 = l_LeanTLS_Crypto_X25519_x25519(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__5;
x_2 = lean_unsigned_to_nat(0u);
x_3 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_4 = l_LeanTLS_Crypto_X25519_bytesToHex_go(x_1, x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__7() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_LeanTLS_Crypto_X25519_runTests___lambda__3___boxed), 3, 0);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__8() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("c3da55379de9c6908e94ea4df28d084f32eccf03491c71f754b4075577a28552", 64, 64);
return x_1;
}
}
static uint8_t _init_l_LeanTLS_Crypto_X25519_runTests___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; uint8_t x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__6;
x_2 = l_LeanTLS_Crypto_X25519_runTests___closed__8;
x_3 = lean_string_dec_eq(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__10() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("Test vector 1: FAILED", 21, 21);
return x_1;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11;
x_2 = l_LeanTLS_Crypto_X25519_runTests___closed__8;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__12() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__11;
x_2 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__13() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14;
x_2 = l_LeanTLS_Crypto_X25519_runTests___closed__6;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__14() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_LeanTLS_Crypto_X25519_runTests___closed__13;
x_2 = l_LeanTLS_Crypto_X25519_bytesToHex___closed__1;
x_3 = lean_string_append(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_LeanTLS_Crypto_X25519_runTests___closed__15() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("Test vector 1: PASSED", 21, 21);
return x_1;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = l_LeanTLS_Crypto_X25519_runTests___closed__7;
x_3 = l_LeanTLS_Crypto_X25519_runTests___closed__9;
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = l_LeanTLS_Crypto_X25519_runTests___closed__10;
x_5 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_4, x_1);
if (lean_obj_tag(x_5) == 0)
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; 
x_6 = lean_ctor_get(x_5, 1);
lean_inc(x_6);
lean_dec(x_5);
x_7 = l_LeanTLS_Crypto_X25519_runTests___closed__12;
x_8 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_7, x_6);
if (lean_obj_tag(x_8) == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_9 = lean_ctor_get(x_8, 1);
lean_inc(x_9);
lean_dec(x_8);
x_10 = l_LeanTLS_Crypto_X25519_runTests___closed__14;
x_11 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_10, x_9);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_12 = lean_ctor_get(x_11, 1);
lean_inc(x_12);
lean_dec(x_11);
x_13 = 0;
x_14 = lean_box(0);
x_15 = lean_box(x_13);
x_16 = lean_apply_3(x_2, x_15, x_14, x_12);
return x_16;
}
else
{
uint8_t x_17; 
x_17 = !lean_is_exclusive(x_11);
if (x_17 == 0)
{
return x_11;
}
else
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; 
x_18 = lean_ctor_get(x_11, 0);
x_19 = lean_ctor_get(x_11, 1);
lean_inc(x_19);
lean_inc(x_18);
lean_dec(x_11);
x_20 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_20, 0, x_18);
lean_ctor_set(x_20, 1, x_19);
return x_20;
}
}
}
else
{
uint8_t x_21; 
x_21 = !lean_is_exclusive(x_8);
if (x_21 == 0)
{
return x_8;
}
else
{
lean_object* x_22; lean_object* x_23; lean_object* x_24; 
x_22 = lean_ctor_get(x_8, 0);
x_23 = lean_ctor_get(x_8, 1);
lean_inc(x_23);
lean_inc(x_22);
lean_dec(x_8);
x_24 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_24, 0, x_22);
lean_ctor_set(x_24, 1, x_23);
return x_24;
}
}
}
else
{
uint8_t x_25; 
x_25 = !lean_is_exclusive(x_5);
if (x_25 == 0)
{
return x_5;
}
else
{
lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_26 = lean_ctor_get(x_5, 0);
x_27 = lean_ctor_get(x_5, 1);
lean_inc(x_27);
lean_inc(x_26);
lean_dec(x_5);
x_28 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_28, 0, x_26);
lean_ctor_set(x_28, 1, x_27);
return x_28;
}
}
}
else
{
lean_object* x_29; lean_object* x_30; 
x_29 = l_LeanTLS_Crypto_X25519_runTests___closed__15;
x_30 = l_IO_println___at_LeanTLS_Crypto_X25519_runTests___spec__1(x_29, x_1);
if (lean_obj_tag(x_30) == 0)
{
lean_object* x_31; lean_object* x_32; uint8_t x_33; lean_object* x_34; lean_object* x_35; 
x_31 = lean_ctor_get(x_30, 0);
lean_inc(x_31);
x_32 = lean_ctor_get(x_30, 1);
lean_inc(x_32);
lean_dec(x_30);
x_33 = 1;
x_34 = lean_box(x_33);
x_35 = lean_apply_3(x_2, x_34, x_31, x_32);
return x_35;
}
else
{
uint8_t x_36; 
x_36 = !lean_is_exclusive(x_30);
if (x_36 == 0)
{
return x_30;
}
else
{
lean_object* x_37; lean_object* x_38; lean_object* x_39; 
x_37 = lean_ctor_get(x_30, 0);
x_38 = lean_ctor_get(x_30, 1);
lean_inc(x_38);
lean_inc(x_37);
lean_dec(x_30);
x_39 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_39, 0, x_37);
lean_ctor_set(x_39, 1, x_38);
return x_39;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Crypto_X25519_runTests___lambda__1(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Crypto_X25519_runTests___lambda__2(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_LeanTLS_Crypto_X25519_runTests___lambda__3___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_LeanTLS_Crypto_X25519_runTests___lambda__3(x_4, x_2, x_3);
lean_dec(x_2);
return x_5;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_LeanTLS_Crypto_X25519(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_LeanTLS_Crypto_X25519_p___closed__1 = _init_l_LeanTLS_Crypto_X25519_p___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_p___closed__1);
l_LeanTLS_Crypto_X25519_p___closed__2 = _init_l_LeanTLS_Crypto_X25519_p___closed__2();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_p___closed__2);
l_LeanTLS_Crypto_X25519_p = _init_l_LeanTLS_Crypto_X25519_p();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_p);
l_LeanTLS_Crypto_X25519_a24 = _init_l_LeanTLS_Crypto_X25519_a24();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_a24);
l_LeanTLS_Crypto_X25519_fieldInv___closed__1 = _init_l_LeanTLS_Crypto_X25519_fieldInv___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_fieldInv___closed__1);
l_LeanTLS_Crypto_X25519_bytesToHex___closed__1 = _init_l_LeanTLS_Crypto_X25519_bytesToHex___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_bytesToHex___closed__1);
l_LeanTLS_Crypto_X25519_basePoint___closed__1 = _init_l_LeanTLS_Crypto_X25519_basePoint___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_basePoint___closed__1);
l_LeanTLS_Crypto_X25519_basePoint___closed__2 = _init_l_LeanTLS_Crypto_X25519_basePoint___closed__2();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_basePoint___closed__2);
l_LeanTLS_Crypto_X25519_basePoint___closed__3 = _init_l_LeanTLS_Crypto_X25519_basePoint___closed__3();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_basePoint___closed__3);
l_LeanTLS_Crypto_X25519_basePoint = _init_l_LeanTLS_Crypto_X25519_basePoint();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_basePoint);
l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__1 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__1);
l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__2 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__2();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__2___closed__2);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__1 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__1);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__2 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__2();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__2);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__3 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__3();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__3);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__4 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__4();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__4);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__5 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__5();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__5);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__6);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__7 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__7();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__7);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__8);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__9 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__9();
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__10 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__10();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__10);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__11);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__12 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__12();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__12);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__13 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__13();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__13);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__14);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__15 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__15();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__15);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__16 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__16();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__16);
l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__17 = _init_l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__17();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___lambda__3___closed__17);
l_LeanTLS_Crypto_X25519_runTests___closed__1 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__1();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__1);
l_LeanTLS_Crypto_X25519_runTests___closed__2 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__2();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__2);
l_LeanTLS_Crypto_X25519_runTests___closed__3 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__3();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__3);
l_LeanTLS_Crypto_X25519_runTests___closed__4 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__4();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__4);
l_LeanTLS_Crypto_X25519_runTests___closed__5 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__5();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__5);
l_LeanTLS_Crypto_X25519_runTests___closed__6 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__6();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__6);
l_LeanTLS_Crypto_X25519_runTests___closed__7 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__7();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__7);
l_LeanTLS_Crypto_X25519_runTests___closed__8 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__8();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__8);
l_LeanTLS_Crypto_X25519_runTests___closed__9 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__9();
l_LeanTLS_Crypto_X25519_runTests___closed__10 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__10();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__10);
l_LeanTLS_Crypto_X25519_runTests___closed__11 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__11();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__11);
l_LeanTLS_Crypto_X25519_runTests___closed__12 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__12();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__12);
l_LeanTLS_Crypto_X25519_runTests___closed__13 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__13();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__13);
l_LeanTLS_Crypto_X25519_runTests___closed__14 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__14();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__14);
l_LeanTLS_Crypto_X25519_runTests___closed__15 = _init_l_LeanTLS_Crypto_X25519_runTests___closed__15();
lean_mark_persistent(l_LeanTLS_Crypto_X25519_runTests___closed__15);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
