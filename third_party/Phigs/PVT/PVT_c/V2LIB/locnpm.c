/* locnpm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int locnpm_(integer *nppm, integer *ypos, real *xloc)
#else /* NO_PROTO */
/* Subroutine */ int locnpm_(nppm, ypos, xloc)
integer *nppm, *ypos;
real *xloc;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real ya[5];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static real yval;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCNPM draws a polymarker with NPPM markers at the real y-location */
/*  corresponding to the integer index given in YPOS. */
    /* Parameter adjustments */
    --xloc;

    /* Function Body */
    yval = ylocel_(ypos);
    i__1 = *nppm;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[ix - 1] = yval;
/* L10: */
    }
    npm (nppm, &xloc[1], ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locnpm_ */

