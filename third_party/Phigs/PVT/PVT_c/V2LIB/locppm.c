/* locppm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int locppm_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locppm_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static real yval[1];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCPPM draws a polymarker at the real y-location corresponding to */
/*  the integer index given in YLOC. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    yval[0] = ylocel_(yloc);
    npm (&c__1, &xval[1], yval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locppm_ */

