/* pt2cof.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int pt2cof_(real *x1, real *y1, real *x2, real *y2, real *a, 
	real *b, real *c)
#else /* NO_PROTO */
/* Subroutine */ int pt2cof_(x1, y1, x2, y2, a, b, c)
real *x1, *y1, *x2, *y2, *a, *b, *c;
#endif /* NO_PROTO */
{
/* Given two points, calculate line coefficients. */
    *a = *y1 - *y2;
    *b = *x2 - *x1;
    *c = *x1 * *y2 - *y1 * *x2;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pt2cof_ */

