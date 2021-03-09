/* loctri.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int loctri_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int loctri_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real yval[3];
    static integer npts[1];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCTRI draws a triangle using fill area set at the real */
/*  y-location corresponding to the integer index given in YLOC. */
/*  LOCTRI is normally used to display edges (unique to fill area */
/*  set, as opposed to simple fill area) rather than interiors. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    npts[0] = 3;
#ifndef NO_PROTO
    yval[1] = ylocel_(yloc) - .02f;
#else /* NO_PROTO */
    yval[1] = ylocel_(yloc) - (float).02;
#endif /* NO_PROTO */
    yval[2] = yval[1];
#ifndef NO_PROTO
    yval[0] = yval[1] + .035f;
#else /* NO_PROTO */
    yval[0] = yval[1] + (float).035;
#endif /* NO_PROTO */
    nfas (&c__1, npts, &xval[1], yval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* loctri_ */

