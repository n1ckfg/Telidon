/* parcof.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int parcof_(real *x0, real *y0, real *xcoeff, real *ycoeff, 
	real *a, real *b, real *c)
#else /* NO_PROTO */
/* Subroutine */ int parcof_(x0, y0, xcoeff, ycoeff, a, b, c)
real *x0, *y0, *xcoeff, *ycoeff, *a, *b, *c;
#endif /* NO_PROTO */
{
/*  given parametric form, find line coefficients */
    *a = *ycoeff;
    *b = -(doublereal)(*xcoeff);
    *c = *xcoeff * *y0 - *ycoeff * *x0;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* parcof_ */

