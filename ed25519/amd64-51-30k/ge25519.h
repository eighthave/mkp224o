#ifndef GE25519_H
#define GE25519_H

/*
 * Arithmetic on the twisted Edwards curve -x^2 + y^2 = 1 + dx^2y^2
 * with d = -(121665/121666) =
 * 37095705934669439343138083508754565189542113879843219016388785533085940283555
 * Base point:
 * (15112221349535400772501151409588531511454012693041857206046113283949847762202,46316835694926478169428394003475163141307993866256225615783033603165251855960);
 */

#include "fe25519.h"
#include "sc25519.h"

#define ge25519                           CRYPTO_NAMESPACE(batch_ge25519)
#define ge25519_base                      CRYPTO_NAMESPACE(batch_ge25519_base)
#define ge25519_unpackneg_vartime         CRYPTO_NAMESPACE(batch_unpackneg_vartime)
#define ge25519_pack                      CRYPTO_NAMESPACE(batch_pack)
#define ge25519_isneutral_vartime         CRYPTO_NAMESPACE(batch_isneutral_vartime)
#define ge25519_add                       CRYPTO_NAMESPACE(batch_ge25519_add)
#define ge25519_double                    CRYPTO_NAMESPACE(batch_ge25519_double)
#define ge25519_double_scalarmult_vartime CRYPTO_NAMESPACE(batch_double_scalarmult_vartime)
#define ge25519_multi_scalarmult_vartime  CRYPTO_NAMESPACE(batch_ge25519_multi_scalarmult_vartime)
#define ge25519_scalarmult_base           CRYPTO_NAMESPACE(batch_scalarmult_base)
#define ge25519_p1p1_to_p2                CRYPTO_NAMESPACE(batch_ge25519_p1p1_to_p2)
#define ge25519_p1p1_to_p3                CRYPTO_NAMESPACE(batch_ge25519_p1p1_to_p3)
#define ge25519_p1p1_to_pniels            CRYPTO_NAMESPACE(batch_ge25519_p1p1_to_pniels)
#define ge25519_add_p1p1                  CRYPTO_NAMESPACE(batch_ge25519_add_p1p1)
#define ge25519_dbl_p1p1                  CRYPTO_NAMESPACE(batch_ge25519_dbl_p1p1)
#define choose_t                          CRYPTO_NAMESPACE(batch_choose_t)
#define choose_t_smultq                   CRYPTO_NAMESPACE(batch_choose_t_smultq)
#define ge25519_nielsadd2                 CRYPTO_NAMESPACE(batch_ge25519_nielsadd2)
#define ge25519_nielsadd_p1p1             CRYPTO_NAMESPACE(batch_ge25519_nielsadd_p1p1)
#define ge25519_pnielsadd_p1p1            CRYPTO_NAMESPACE(batch_ge25519_pnielsadd_p1p1)

#define ge25519_p3 ge25519

typedef struct
{
  fe25519 x;
  fe25519 y;
  fe25519 z;
  fe25519 t;
} ge25519;

typedef struct
{
  fe25519 x;
  fe25519 z;
  fe25519 y;
  fe25519 t;
} ge25519_p1p1;

typedef struct
{
  fe25519 x;
  fe25519 y;
  fe25519 z;
} ge25519_p2;

typedef struct
{
  fe25519 ysubx;
  fe25519 xaddy;
  fe25519 t2d;
} ge25519_niels;

typedef struct
{
  fe25519 ysubx;
  fe25519 xaddy;
  fe25519 z;
  fe25519 t2d;
} ge25519_pniels;

typedef unsigned char bytes32[32];

extern void ge25519_p1p1_to_p2(ge25519_p2 *r, const ge25519_p1p1 *p);
extern void ge25519_p1p1_to_p3(ge25519_p3 *r, const ge25519_p1p1 *p);
extern void ge25519_p1p1_to_pniels(ge25519_pniels *r, const ge25519_p1p1 *p);
extern void ge25519_add_p1p1(ge25519_p1p1 *r, const ge25519_p3 *p, const ge25519_p3 *q);
extern void ge25519_dbl_p1p1(ge25519_p1p1 *r, const ge25519_p2 *p);
extern void choose_t(ge25519_niels *t, unsigned long long pos, signed long long b, const ge25519_niels *base_multiples);
extern void choose_t_smultq(ge25519_pniels *t, signed long long b, const ge25519_pniels *pre);
extern void ge25519_nielsadd2(ge25519_p3 *r, const ge25519_niels *q);
extern void ge25519_nielsadd_p1p1(ge25519_p1p1 *r, const ge25519_p3 *p, const ge25519_niels *q);
extern void ge25519_pnielsadd_p1p1(ge25519_p1p1 *r, const ge25519_p3 *p, const ge25519_pniels *q);

extern const ge25519 ge25519_base;

extern int ge25519_unpackneg_vartime(ge25519 *r, const unsigned char p[32]);

extern void ge25519_pack(unsigned char r[32], const ge25519 *p);

extern void ge25519_batchpack_destructive_1(bytes32 *out, ge25519_p3 *in, fe25519 *tmp, size_t num);
extern void ge25519_batchpack_destructive_finish(bytes32 out, ge25519_p3 *unf);

extern int ge25519_isneutral_vartime(const ge25519 *p);

extern void ge25519_add(ge25519 *r, const ge25519 *p, const ge25519 *q);

extern void ge25519_double(ge25519 *r, const ge25519 *p);

/* computes [s1]p1 + [s2]ge25519_base */
extern void ge25519_double_scalarmult_vartime(ge25519 *r, const ge25519 *p1, const sc25519 *s1, const sc25519 *s2);

extern void ge25519_multi_scalarmult_vartime(ge25519 *r, ge25519 *p, sc25519 *s, const unsigned long long npoints);

extern void ge25519_scalarmult_base(ge25519 *r, const sc25519 *s);

#endif
