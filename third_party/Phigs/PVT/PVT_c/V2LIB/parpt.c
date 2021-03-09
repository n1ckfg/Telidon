/* parpt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int parpt_(real *rcx, real *rcy, integer *parity, real *
	prvc1x, real *prvc1y, real *prvc2x, real *prvc2y, real *xa, real *ya, 
	real *x, real *y, integer *step1, integer *step2)
#else /* NO_PROTO */
/* Subroutine */ int parpt_(rcx, rcy, parity, prvc1x, prvc1y, prvc2x, prvc2y, 
	xa, ya, x, y, step1, step2)
real *rcx, *rcy;
integer *parity;
real *prvc1x, *prvc1y, *prvc2x, *prvc2y, *xa, *ya, *x, *y;
integer *step1, *step2;
#endif /* NO_PROTO */
{
    static real a1, b1, c1, a2, b2, c2;
#ifndef NO_PROTO
    extern /* Subroutine */ int parlin_(real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *), lintpt_(real *, real *, real *, real *, real *, real *
	    , real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int parlin_(), lintpt_();
#endif /* NO_PROTO */

/*  PARPT accepts a reference point and 2 vectors and computes a */
/*  corner of the smallest parallelogram containing a specified */
/*  rectangle. The corner is found in the direction specified by */
/*  parity. */
/*  Input parameters */
/*    RCX,RCY       : reference point within rectangle */
/*    PARITY        : +1 to search in direction of vectors, -1 to */
/*                    search in opposite direction */
/*    PRVC1X,PRVC1Y : first vector to increment reference point */
/*    PRVC2X,PRVC2Y : second vector to increment reference point */
/*    XA,YA         : 4 corners of rectangle to be contained */
/*  Output parameters */
/*    X,Y           : corner of parallelogram */
/*    STEP1,STEP2   : number of steps taken from reference point in */
/*                    direction of 1st,2nd vector */
/*  find first, second boundary lines */
    /* Parameter adjustments */
    --ya;
    --xa;

    /* Function Body */
    parlin_(rcx, rcy, parity, prvc1x, prvc1y, prvc2x, prvc2y, &xa[1], &ya[1], 
	    &a1, &b1, &c1, step1);
    parlin_(rcx, rcy, parity, prvc2x, prvc2y, prvc1x, prvc1y, &xa[1], &ya[1], 
	    &a2, &b2, &c2, step2);
/*  intersection of lines is corner */
    lintpt_(&a1, &b1, &c1, &a2, &b2, &c2, x, y);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* parpt_ */

