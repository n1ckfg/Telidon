/* locppl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int locppl_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locppl_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static real yval[2];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCPPL draws a polyline at the real y-location corresponding to */
/*  the integer index given in YLOC. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    yval[0] = ylocel_(yloc);
    yval[1] = yval[0];
    npl (&c__2, &xval[1], yval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locppl_ */

