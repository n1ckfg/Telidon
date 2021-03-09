/* pt3pl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int pt3pl_(real *x, real *y, real *z, real *a, real *b, real 
	*c, real *d)
#else /* NO_PROTO */
/* Subroutine */ int pt3pl_(x, y, z, a, b, c, d)
real *x, *y, *z, *a, *b, *c, *d;
#endif /* NO_PROTO */
{
/* Given 3 points, find containing plane */
    /* Parameter adjustments */
    --z;
    --y;
    --x;

    /* Function Body */
    *a = y[2] * z[3] + y[3] * z[1] + y[1] * z[2] - y[1] * z[3] - y[2] * z[1] 
	    - y[3] * z[2];
    *b = z[2] * x[3] + z[3] * x[1] + z[1] * x[2] - z[1] * x[3] - z[2] * x[1] 
	    - z[3] * x[2];
    *c = x[2] * y[3] + x[3] * y[1] + x[1] * y[2] - x[1] * y[3] - x[2] * y[1] 
	    - x[3] * y[2];
    *d = -(doublereal)(*a * x[1] + *b * y[1] + *c * z[1] + *a * x[2] + *b * y[
	    2] + *c * z[2] + *a * x[3] + *b * y[3] + *c * z[3]) / 3;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pt3pl_ */

