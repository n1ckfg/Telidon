/* loctx2.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int loctx2_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int loctx2_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static real xa[1], ya[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), ntx ();
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCTX2 draws a text string at the real y-location corresponding */
/*  to the integer index given in YLOC, and puts a polymarker at */
/*  the text position. */
    xa[0] = *xval;
    ya[0] = ylocel_(yloc);
    npm (&c__1, xa, ya);
    r__1 = ylocel_(yloc);
    ntx (xval, &r__1, "Phigs", 5L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* loctx2_ */

