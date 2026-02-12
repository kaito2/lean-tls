// Lean compiler output
// Module: LeanTLS
// Imports: Init LeanTLS.Crypto.SHA256 LeanTLS.Crypto.HMAC LeanTLS.Crypto.HKDF LeanTLS.Crypto.AES LeanTLS.Crypto.GCM LeanTLS.Crypto.X25519 LeanTLS.KeySchedule LeanTLS.Record LeanTLS.Handshake LeanTLS.Connection
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
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_SHA256(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_HMAC(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_HKDF(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_AES(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_GCM(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Crypto_X25519(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_KeySchedule(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Record(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Handshake(uint8_t builtin, lean_object*);
lean_object* initialize_LeanTLS_Connection(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_LeanTLS(uint8_t builtin, lean_object* w) {
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
res = initialize_LeanTLS_Crypto_HKDF(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_AES(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_GCM(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Crypto_X25519(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_KeySchedule(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Record(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Handshake(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanTLS_Connection(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
