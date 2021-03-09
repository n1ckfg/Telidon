/* patrec.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int patrec_(real *scf, integer *yloc, real *xval, integer *
	fafas)
#else /* NO_PROTO */
/* Subroutine */ int patrec_(scf, yloc, xval, fafas)
real *scf;
integer *yloc;
real *xval;
integer *fafas;
#endif /* NO_PROTO */
{
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static real xwk[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real yval[4];
    static integer npts[1];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  PATREC draws a rectangle at the real y-location corresponding to */
/*  the integer index given in YLOC, but scaled to allow for current */
/*  transformation by SCF. */
/*  Every 3rd rectangle is drawn with the FILL AREA primitive rather */
/*  than FILL AREA SET, as controlled by FAFAS */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    npts[0] = 4;
#ifndef NO_PROTO
    yval[1] = (ylocel_(yloc) - .02f) / *scf;
#else /* NO_PROTO */
    yval[1] = (ylocel_(yloc) - (float).02) / *scf;
#endif /* NO_PROTO */
    yval[2] = yval[1];
#ifndef NO_PROTO
    yval[0] = yval[1] + .045f / *scf;
#else /* NO_PROTO */
    yval[0] = yval[1] + (float).045 / *scf;
#endif /* NO_PROTO */
    yval[3] = yval[0];
    for (ix = 1; ix <= 4; ++ix) {
	xwk[ix - 1] = xval[ix] / *scf;
/* L10: */
    }
    if (*fafas % 3 == 0) {
	nfa (npts, xwk, yval);
    } else {
	nfas (&c__1, npts, xwk, yval);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* patrec_ */

