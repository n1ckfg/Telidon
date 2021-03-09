/* clpgon.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b3 = 0.f;
static real c_b4 = 1.f;
#else /* NO_PROTO */
static real c_b3 = (float)0.;
static real c_b4 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int clpgon_(integer *visct, integer *numpl, real *rad)
#else /* NO_PROTO */
/* Subroutine */ int clpgon_(visct, numpl, rad)
integer *visct, *numpl;
real *rad;
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
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */
    static real xloc[500], yloc[500], zloc[500];
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int rnset_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static real thsrad;
    static integer vislis[50];

/*  CLPGON draws a set of markers some of which are just inside the */
/*  clipping region shaped like a regular polygon, and the rest just */
/*  outside it. */
/*  Input parameters: */
/*    VISCT : number of markers to be drawn inside clipping region */
/*    NUMPL : total number of markers to be drawn = #sides of polygon */
/*    RAD   : radius of polygon (distance from center to face, not vertex)
 */
/* maximum number of planes to be tested */
/*  Choose visct markers to be inside */
    rnset_(visct, numpl, vislis);
/*  calculate coordinates of polymarker: */
    i__1 = *numpl;
    for (ix = 1; ix <= i__1; ++ix) {
	if (iarfnd_(&ix, visct, vislis) > 0) {
/*  Inside: */
#ifndef NO_PROTO
	    thsrad = *rad * .99f;
#else /* NO_PROTO */
	    thsrad = *rad * (float).99;
#endif /* NO_PROTO */
	} else {
/*  Outside: */
#ifndef NO_PROTO
	    thsrad = *rad * 1.01f;
#else /* NO_PROTO */
	    thsrad = *rad * (float)1.01;
#endif /* NO_PROTO */
	}
#ifndef NO_PROTO
	ang = (ix << 1) * 3.14159265f / *numpl;
	xloc[ix - 1] = thsrad * cos(ang) + .5f;
	yloc[ix - 1] = thsrad * sin(ang) + .5f;
#else /* NO_PROTO */
	ang = (ix << 1) * (float)3.14159265 / *numpl;
	xloc[ix - 1] = thsrad * cos(ang) + (float).5;
	yloc[ix - 1] = thsrad * sin(ang) + (float).5;
#endif /* NO_PROTO */
	zloc[ix - 1] = rndrl_(&c_b3, &c_b4);
/* L100: */
    }
    npm3 (numpl, xloc, yloc, zloc);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* clpgon_ */

