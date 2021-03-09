/* locat2.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int locat2_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locat2_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    static real xa[1], ya[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int locatx_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
    extern doublereal ylocel_();
    extern /* Subroutine */ int locatx_();
#endif /* NO_PROTO */

/*  LOCAT2 draws an annotation text string at the real y-location */
/*  corresponding to the integer index given in YLOC, and puts a */
/*  polymarker at the text position. */
    xa[0] = *xval;
    ya[0] = ylocel_(yloc);
    npm (&c__1, xa, ya);
    locatx_(yloc, xval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locat2_ */

