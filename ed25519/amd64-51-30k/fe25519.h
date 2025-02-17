#ifndef FE25519_H
#define FE25519_H

#include <stddef.h>

#define fe25519              CRYPTO_NAMESPACE(batch_fe25519)
#define fe25519_freeze       CRYPTO_NAMESPACE(batch_fe25519_freeze)
#define fe25519_unpack       CRYPTO_NAMESPACE(batch_fe25519_unpack)
#define fe25519_pack         CRYPTO_NAMESPACE(batch_fe25519_pack)
#define fe25519_iszero_vartime       CRYPTO_NAMESPACE(batch_fe25519_iszero_vartime)
#define fe25519_iseq_vartime CRYPTO_NAMESPACE(batch_fe25519_iseq_vartime)
#define fe25519_cmov         CRYPTO_NAMESPACE(batch_fe25519_cmov)
#define fe25519_setint       CRYPTO_NAMESPACE(batch_fe25519_setint)
#define fe25519_neg          CRYPTO_NAMESPACE(batch_fe25519_neg)
#define fe25519_getparity    CRYPTO_NAMESPACE(batch_fe25519_getparity)
#define fe25519_add          CRYPTO_NAMESPACE(batch_fe25519_add)
#define fe25519_sub          CRYPTO_NAMESPACE(batch_fe25519_sub)
#define fe25519_mul          CRYPTO_NAMESPACE(batch_fe25519_mul)
#define fe25519_mul121666    CRYPTO_NAMESPACE(batch_fe25519_mul121666)
#define fe25519_square       CRYPTO_NAMESPACE(batch_fe25519_square)
#define fe25519_nsquare       CRYPTO_NAMESPACE(batch_fe25519_nsquare)
#define fe25519_invert       CRYPTO_NAMESPACE(batch_fe25519_invert)
#define fe25519_batchinvert  CRYPTO_NAMESPACE(batch_fe25519_batchinvert)
#define fe25519_pow2523      CRYPTO_NAMESPACE(batch_fe25519_pow2523)

typedef struct
{
  unsigned long long v[5];
}
fe25519;

void fe25519_freeze(fe25519 *r);

void fe25519_unpack(fe25519 *r, const unsigned char x[32]);

void fe25519_pack(unsigned char r[32], const fe25519 *x);

void fe25519_cmov(fe25519 *r, const fe25519 *x, unsigned char b);

void fe25519_cswap(fe25519 *r, fe25519 *x, unsigned char b);

void fe25519_setint(fe25519 *r, unsigned int v);

void fe25519_neg(fe25519 *r, const fe25519 *x);

unsigned char fe25519_getparity(const fe25519 *x);

int fe25519_iszero_vartime(const fe25519 *x);

int fe25519_iseq_vartime(const fe25519 *x, const fe25519 *y);

void fe25519_add(fe25519 *r, const fe25519 *x, const fe25519 *y);

void fe25519_sub(fe25519 *r, const fe25519 *x, const fe25519 *y);

void fe25519_mul(fe25519 *r, const fe25519 *x, const fe25519 *y);

void fe25519_mul121666(fe25519 *r, const fe25519 *x);

void fe25519_square(fe25519 *r, const fe25519 *x);

void fe25519_nsquare(fe25519 *r, unsigned long long n);

void fe25519_invert(fe25519 *r, const fe25519 *x);

void fe25519_batchinvert(fe25519 *out, const fe25519 *in, fe25519 *tmp, size_t num, size_t offset);

void fe25519_pow2523(fe25519 *r, const fe25519 *x);

#endif
