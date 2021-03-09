/* pl2pl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int pl2pl_(real *ar, real *br, real *cr, real *dr, real *ax, 
	real *bx, real *cx, real *dx, real *ap, real *bp, real *cp, real *dp)
#else /* NO_PROTO */
/* Subroutine */ int pl2pl_(ar, br, cr, dr, ax, bx, cx, dx, ap, bp, cp, dp)
real *ar, *br, *cr, *dr, *ax, *bx, *cx, *dx, *ap, *bp, *cp, *dp;
#endif /* NO_PROTO */
{
    static real al, bl, cl, px, py, pz;
#ifndef NO_PROTO
    extern /* Subroutine */ int pl2ln_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), crossp_(real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pl2ln_(), crossp_();
#endif /* NO_PROTO */

/*  Given a reference plane (R) and an intersecting crossing plane */
/*  (X), find the perpendicular plane (P), which contains the line of */
/*  intersection of R and X, and is perpendicular to R. */
/*  get line of intersection of R and X */
    pl2ln_(ar, br, cr, dr, ax, bx, cx, dx, &al, &bl, &cl, &px, &py, &pz);
/*  cross-prod of line and ref plane is attitude of P-plane */
    crossp_(ar, br, cr, &al, &bl, &cl, ap, bp, cp);
/*  solve for dp, given point on line: */
    *dp = -(doublereal)(*ap * px + *bp * py + *cp * pz);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pl2pl_ */

