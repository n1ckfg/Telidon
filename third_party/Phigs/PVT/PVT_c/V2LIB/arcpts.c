/* arcpts.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int arcpts_(integer *numpts, real *xmid, real *ymid, real *
	rad, real *ang1, real *anginc, real *xa, real *ya, real *za)
#else /* NO_PROTO */
/* Subroutine */ int arcpts_(numpts, xmid, ymid, rad, ang1, anginc, xa, ya, 
	za)
integer *numpts;
real *xmid, *ymid, *rad, *ang1, *anginc, *xa, *ya, *za;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static real ang;

/*  ARCPTS fills in an array with points on an arc in x and y, on */
/*  an oblique plane (z = (x+y)/2) */
/*  Input parameters: */
/*    NUMPTS    : number of points to fill in */
/*    XMID,YMID : center of circle */
/*    RAD       : radius of circle */
/*    ANG1      : first angle */
/*    ANGINC    : angle increment */
/*  Output parameters: */
/*    XA,YA,ZA  : arc points returned */
    /* Parameter adjustments */
    --za;
    --ya;
    --xa;

    /* Function Body */
    ang = *ang1;
    i__1 = *numpts;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[ix] = *xmid + *rad * cos(ang);
	ya[ix] = *ymid + *rad * sin(ang);
#ifndef NO_PROTO
	za[ix] = xa[ix] * .5f + ya[ix] * .5f;
#else /* NO_PROTO */
	za[ix] = xa[ix] * (float).5 + ya[ix] * (float).5;
#endif /* NO_PROTO */
	ang += *anginc;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* arcpts_ */

