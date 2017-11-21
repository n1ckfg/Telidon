/* sol8.h
contains missing pieces for c99 compatibility (sort of) for Solaris 8/Sparc.  This allows
for successful build, but doesn't do anything about the problem that functions in libm
are not truly c99 compatible.  For instance, log(-1) returns -inf, not NAN.  Consequently
there will be incompatibilities in run time for invalid results for these functions.  The only
way around this would be to use a libm derived from Gnu libc, or to use a better Solaris library,
if there is such a thing.
*/

#if !defined(SOL8_GUARD)
#define SOL8_GUARD 1
#include <ieeefp.h>       /* get Solaris FP_SNAN etc.*/
#include <sys/types.h> /* for uint32_t */
#include <sys/int_limits.h> /* for UINT32_MAX and so forth */

/* these are the gcc C99 flags */
# define FP_NAN       0
# define FP_INFINITE  1
# define FP_ZERO      2
# define FP_SUBNORMAL 3
# define FP_NORMAL    4

# define NAN ( ((double) 0.0)/ ((double) 0.0) )

# define isnormal(x) (fpclass (x) >= FP_NZERO                            ? FP_NORMAL   : 0)
# define isinf(x)    (fpclass (x) == FP_NINF  || fpclass (x) == FP_PINF  ? FP_INFINITE : 0)
# define isnan(x)    (fpclass (x) == FP_SNAN  || fpclass (x) == FP_QNAN  ? FP_NAN      : 0)
# define iszero(x)   (fpclass (x) == FP_NZERO || fpclass (x) == FP_PZERO ? FP_ZERO     : 0)
# define log(x)      ( x < 0 ? NAN : log(x) )

int fpclassify(double x){
int status=0; /* Assign to quiet a compiler warning */
  switch(fpclass(x)){
    case FP_SNAN:
    case FP_QNAN:     status=FP_NAN;       break;
    case FP_NINF:
    case FP_PINF:     status=FP_INFINITE;  break;
    case FP_NDENORM:
    case FP_PDENORM:  status=FP_SUBNORMAL; break;
    case FP_NZERO:
    case FP_PZERO:    status=FP_ZERO;      break;
    case FP_NNORM:
    case FP_PNORM:    status=FP_NORMAL;    break;
  }
  return(status);
}

#define fmax(A,B) ( A>=B ? A : B) 
#define fmin(A,B) ( A<=B ? A : B)
#define round(A)  ( A >= 0 ? floor(A+0.5) : -floor(-A+0.5) )

#endif /* SOL8_GUARD */

