/* locrec.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 1.f;
#else /* NO_PROTO */
static real c_b2 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int locrec_(integer *yloc, real *xval, integer *fafas)
#else /* NO_PROTO */
/* Subroutine */ int locrec_(yloc, xval, fafas)
integer *yloc;
real *xval;
integer *fafas;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int patrec_(real *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int patrec_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  LOCREC draws a rectangle at the real y-location corresponding to */
/*  the integer index given in YLOC. */
/*  Every 3rd rectangle is drawn with the FILL AREA primitive rather */
/*  than FILL AREA SET, as controlled by FAFAS */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    patrec_(&c_b2, yloc, &xval[1], fafas);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locrec_ */

