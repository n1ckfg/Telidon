/* ptplds.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ptplds_(real *px, real *py, real *pz, real *a, real *b, 
	real *c, real *d, real *xn, real *yn, real *zn, real *dist)
#else /* NO_PROTO */
/* Subroutine */ int ptplds_(px, py, pz, a, b, c, d, xn, yn, zn, dist)
real *px, *py, *pz, *a, *b, *c, *d, *xn, *yn, *zn, *dist;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, sq, sol;
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_();
#endif /* NO_PROTO */

/* Given a point and plane-coefficients, find nearest */
/* point on plane and distance from plane to point. */
    sq = vecl2_(a, b, c);
    sol = *a * *px + *b * *py + *c * *pz + *d;
    *dist = dabs(sol) / sqrt(sq);
    u = -(doublereal)sol / sq;
    *xn = *px + *a * u;
    *yn = *py + *b * u;
    *zn = *pz + *c * u;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ptplds_ */

