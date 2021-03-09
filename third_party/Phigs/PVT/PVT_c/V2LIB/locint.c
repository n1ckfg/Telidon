/* locint.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int locint_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locint_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), nfas (
	    integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), nfas ();
#endif /* NO_PROTO */
    static real ymid, yval[4];
    static integer npts[1];
    static real yhalf;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCINT draws a fill area or fill area set at the real y-location */
/*  corresponding to the integer index given in YLOC.  It may be used */
/*  to check interiors. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    npts[0] = 4;
    ymid = ylocel_(yloc);
#ifndef NO_PROTO
    yhalf = .02f;
#else /* NO_PROTO */
    yhalf = (float).02;
#endif /* NO_PROTO */
    yval[0] = ymid + yhalf;
    yval[1] = ymid - yhalf;
    yval[2] = ymid - yhalf;
    yval[3] = ymid + yhalf;
    if (*yloc % 2 == 0) {
	nfa (&c__4, &xval[1], yval);
    } else {
	nfas (&c__1, npts, &xval[1], yval);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locint_ */

