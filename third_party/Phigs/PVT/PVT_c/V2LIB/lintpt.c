/* lintpt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int lintpt_(real *a, real *b, real *c, real *d, real *e, 
	real *f, real *x, real *y)
#else /* NO_PROTO */
/* Subroutine */ int lintpt_(a, b, c, d, e, f, x, y)
real *a, *b, *c, *d, *e, *f, *x, *y;
#endif /* NO_PROTO */
{
    static real den;

/* Given two sets of line-coefficients, find intersection point */
    den = *d * *b - *a * *e;
    *x = (*c * *e - *f * *b) / den;
    *y = (*f * *a - *c * *d) / den;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* lintpt_ */

