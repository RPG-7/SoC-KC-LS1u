#include "GlowTypedef.h"

#define EXTRACT_WORDS(ix0,ix1,d)				\
do {								\
  ieee_double_shape_type ew_u;					\
  ew_u.value = (d);						\
  (ix0) = ew_u.parts.msw;					\
  (ix1) = ew_u.parts.lsw;					\
} while (0)

#define INSERT_WORDS(d,ix0,ix1)					\
do {								\
  ieee_double_shape_type iw_u;					\
  iw_u.parts.msw = (ix0);					\
  iw_u.parts.lsw = (ix1);					\
  (d) = iw_u.value;						\
} while (0)

#define GET_HIGH_WORD(i,d)					\
do {								\
  ieee_double_shape_type gh_u;					\
  gh_u.value = (d);						\
  (i) = gh_u.parts.msw;						\
} while (0)

#define GET_LOW_WORD(i,d)					\
do {								\
  ieee_double_shape_type gl_u;					\
  gl_u.value = (d);						\
  (i) = gl_u.parts.lsw;						\
} while (0)

#define SET_LOW_WORD(d,v)					\
do {								\
  ieee_double_shape_type sl_u;					\
  sl_u.value = (d);						\
  sl_u.parts.lsw = (v);						\
  (d) = sl_u.value;						\
} while (0)

#define SET_HIGH_WORD(d,v)					\
do {								\
  ieee_double_shape_type sh_u;					\
  sh_u.value = (d);						\
  sh_u.parts.msw = (v);						\
  (d) = sh_u.value;						\
} while (0)

typedef union
{
    double value;
    struct
    {
        uint32_t lsw;
        uint32_t msw;
    } parts;
} ieee_double_shape_type;

/* ieee style elementary functions */
extern double __ieee754_sqrt(double);
extern double __ieee754_acos(double);
extern double __ieee754_acosh(double);
extern double __ieee754_log(double);
extern double __ieee754_log2(double);
extern double __ieee754_atanh(double);
extern double __ieee754_asin(double);
extern double __ieee754_atan2(double, double);
extern double __ieee754_exp(double);
extern double __ieee754_cosh(double);
extern double __ieee754_fmod(double, double);
extern double __ieee754_pow(double, double);
extern double __ieee754_lgamma_r(double, int*);
/*extern double __ieee754_gamma_r (double,int *) attribute_hidden;*/
extern double __ieee754_lgamma(double);
/*extern double __ieee754_gamma (double) attribute_hidden;*/
extern double __ieee754_log10(double);
extern double __ieee754_sinh(double);
extern double __ieee754_hypot(double, double);
extern double __ieee754_j0(double);
extern double __ieee754_j1(double);
extern double __ieee754_y0(double);
extern double __ieee754_y1(double);
extern double __ieee754_jn(int, double);
extern double __ieee754_yn(int, double);
extern double __ieee754_remainder(double, double);
extern int    __ieee754_rem_pio2(double, double*);
extern double __ieee754_scalb(double, double);

/* fdlibm kernel function */
extern double __kernel_sin(double, double, int);
extern double __kernel_cos(double, double);
extern double __kernel_tan(double, double, int);
extern int    __kernel_rem_pio2(double*, double*, int, int, int, const int*);
