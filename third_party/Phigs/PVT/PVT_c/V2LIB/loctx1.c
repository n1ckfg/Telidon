/* loctx1.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int loctx1_(integer *yloc, real *xval, real *scf)
#else /* NO_PROTO */
/* Subroutine */ int loctx1_(yloc, xval, scf)
integer *yloc;
real *xval, *scf;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCTX1 draws a text string at the real y-location corresponding */
/*  to the integer index given in YLOC, scaled down by SCF */
    r__1 = *xval / *scf;
    r__2 = ylocel_(yloc) / *scf;
    ntx (&r__1, &r__2, "Phigs", 5L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* loctx1_ */

