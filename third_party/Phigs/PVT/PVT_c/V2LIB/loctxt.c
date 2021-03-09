/* loctxt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int loctxt_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int loctxt_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCTXT draws a text primitive at the real y-location */
/*  corresponding to the integer index given in YLOC. */
    r__1 = ylocel_(yloc);
    ntx (xval, &r__1, "Hi ho!", 6L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* loctxt_ */

