/* drwrec.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__5 = 5;

#ifndef NO_PROTO
/* Subroutine */ int drwrec_(real *xl, real *xh, real *yl, real *yh)
#else /* NO_PROTO */
/* Subroutine */ int drwrec_(xl, xh, yl, yh)
real *xl, *xh, *yl, *yh;
#endif /* NO_PROTO */
{
    static real xa[5], ya[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */

/*  DRWREC draws a rectangle as specified by x-low,x-high,y-low,y-high */
    xa[0] = *xl;
    xa[1] = *xl;
    xa[2] = *xh;
    xa[3] = *xh;
    xa[4] = *xl;
    ya[0] = *yl;
    ya[1] = *yh;
    ya[2] = *yh;
    ya[3] = *yl;
    ya[4] = *yl;
    npl (&c__5, xa, ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwrec_ */

