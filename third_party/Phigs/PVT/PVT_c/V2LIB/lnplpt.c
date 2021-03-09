/* lnplpt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int lnplpt_(real *lx, real *ly, real *lz, real *al, real *bl,
	 real *cl, real *ap, real *bp, real *cp, real *dp, real *xi, real *yi,
	 real *zi)
#else /* NO_PROTO */
/* Subroutine */ int lnplpt_(lx, ly, lz, al, bl, cl, ap, bp, cp, dp, xi, yi, 
	zi)
real *lx, *ly, *lz, *al, *bl, *cl, *ap, *bp, *cp, *dp, *xi, *yi, *zi;
#endif /* NO_PROTO */
{
    static real u;
#ifndef NO_PROTO
    extern doublereal dotprd_(real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal dotprd_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  Given a line and a plane, find point of intersection. */
/*  Input parameters */
/*    LX,LY,LZ    : point on the line */
/*    AL,BL,CL    : direction of line */
/*    AP,BP,CP,DP : co-efficients of plane */
/*  Output parameters */
/*    XI,YI,ZI    : point of intersection */
    u = -(doublereal)(dotprd_(ap, bp, cp, lx, ly, lz) + *dp) / dotprd_(ap, bp,
	     cp, al, bl, cl);
    *xi = *lx + *al * u;
    *yi = *ly + *bl * u;
    *zi = *lz + *cl * u;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* lnplpt_ */

