/* parlin.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int parlin_(real *rcx, real *rcy, integer *parity, real *
	prvc1x, real *prvc1y, real *prvc2x, real *prvc2y, real *xa, real *ya, 
	real *a, real *b, real *c, integer *step)
#else /* NO_PROTO */
/* Subroutine */ int parlin_(rcx, rcy, parity, prvc1x, prvc1y, prvc2x, prvc2y,
	 xa, ya, a, b, c, step)
real *rcx, *rcy;
integer *parity;
real *prvc1x, *prvc1y, *prvc2x, *prvc2y, *xa, *ya, *a, *b, *c;
integer *step;
#endif /* NO_PROTO */
{
    static integer ix;
    static real chk, curx, cury;
#ifndef NO_PROTO
    extern /* Subroutine */ int parcof_(real *, real *, real *, real *, real *
	    , real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int parcof_();
#endif /* NO_PROTO */

/*  PARLIN accepts a reference point and 2 vectors and computes a */
/*  side of the smallest parallelogram containing a specified */
/*  rectangle.  The side is found in the direction specified by */
/*  parity. */
/*  Input parameters */
/*    RCX,RCY       : reference point within rectangle */
/*    PARITY        : +1 to search in direction of 1st vector, -1 to */
/*                    search in opposite direction */
/*   PRVC1X,PRVC1Y : first vector: used to increment/decrement reference p
oint*/
/*    PRVC2X,PRVC2Y : second vector: indicate direction (slope) of side */

/*    XA,YA         : 4 corners of rectangle to be contained */
/*  Output parameters */
/*    A,B,C         : coefficients of side */
/*    STEP          : number of steps taken from reference point */
    /* Parameter adjustments */
    --ya;
    --xa;

    /* Function Body */
    curx = *rcx;
    cury = *rcy;
    *step = 0;
L100:
    ++(*step);
    curx += *parity * *prvc1x;
    cury += *parity * *prvc1y;
/*  candidate line coefficients */
    parcof_(&curx, &cury, prvc2x, prvc2y, a, b, c);
    chk = *a * xa[1] + *b * ya[1] + *c;
/*  check if all on same side */
    for (ix = 2; ix <= 4; ++ix) {
/*  if not on same side, go back and take another step */
#ifndef NO_PROTO
	if (chk * (*a * xa[ix] + *b * ya[ix] + *c) <= 0.f) {
#else /* NO_PROTO */
	if (chk * (*a * xa[ix] + *b * ya[ix] + *c) <= (float)0.) {
#endif /* NO_PROTO */
	    goto L100;
	}
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* parlin_ */

