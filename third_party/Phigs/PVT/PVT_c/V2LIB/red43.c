/* red43.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int red43_(real *m4, real *m3)
#else /* NO_PROTO */
/* Subroutine */ int red43_(m4, m3)
real *m4, *m3;
#endif /* NO_PROTO */
{
    static integer i, j, ir, jr;

/* General purpose routine to reduce a 4x4 matrix to 3x3, by */
/* suppressing 3rd row and column */
    /* Parameter adjustments */
    m3 -= 4;
    m4 -= 5;

    /* Function Body */
    for (i = 1; i <= 4; ++i) {
	ir = min(i,3);
	for (j = 1; j <= 4; ++j) {
	    jr = min(j,3);
	    m3[ir + jr * 3] = m4[i + (j << 2)];
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* red43_ */

