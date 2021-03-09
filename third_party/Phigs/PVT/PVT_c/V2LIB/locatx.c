/* locatx.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int locatx_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locatx_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCATX draws an annotation text primitive at the real y-location */
/*  corresponding to the integer index given in YLOC. */
    r__1 = ylocel_(yloc);
    natr (xval, &r__1, &c_b2, &c_b2, "Hi ho!", 6L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locatx_ */

