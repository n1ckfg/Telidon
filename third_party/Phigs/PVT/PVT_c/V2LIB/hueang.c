/* hueang.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int hueang_(real *r, real *g, real *b, real *ang, real *dist)

#else /* NO_PROTO */
/* Subroutine */ int hueang_(r, g, b, ang, dist)
real *r, *g, *b, *ang, *dist;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal), atan(doublereal), atan2(doublereal, doublereal);
#else /* NO_PROTO */
    double sqrt(), atan(), atan2();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, a45, pi, xo, yo, zo, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_();
#endif /* NO_PROTO */
    static real tmat[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm3_();
#endif /* NO_PROTO */

/*  This program calculates a characteristic angle for a hue from the */
/*  RGB color cube.  It does so by rotating the cube 45 deg around the */
/*  y-axis and atan(sqrt(2)) around the z-axis (assuming xyz = RGB). */
/*  This lines up the black-white cube diagonal (0,0,0 to 1,1,1) along */
/*  the y-axis.  Now, transformed points along the color-saturated */
/*  vertices are such that their angle in the x-z plane is a measure */
/*  of hue; so atan2 is used to compute the hue of any RGB point. */
/*  BTW, somewhat surprisingly, the points which are transformed into */
/*  the x=0 plane are all those in the old plane described by: */
/*  x -2y + z = 0 (this plane contains the points (0,0,0), (1,1,1), */
/*  and (0,.5,1), all of which can be "seen" to be rotated into x=0 */
/*  plane).  This plane is such that it is satisfied by any points of */
/*  the form: (q, q+c, q+2c), so that sample points like (3,4,5) will */
/*  always transform into the x=0 plane. */
/*  Hueang also returns the distance of the RGB point from the */
/*  neutral (black-white) axis. */
#ifndef NO_PROTO
    zz = 0.f;
    u = 1.f;
    pi = 3.14159265f;
    a45 = pi / 4.f;
    r__1 = atan(sqrt(2.f));
#else /* NO_PROTO */
    zz = (float)0.;
    u = (float)1.;
    pi = (float)3.14159265;
    a45 = pi / (float)4.;
    r__1 = atan(sqrt((float)2.));
#endif /* NO_PROTO */
    ebltm3_(&zz, &zz, &zz, &zz, &zz, &zz, &zz, &a45, &r__1, &u, &u, &u, tmat);

/* L10: */
    etp3_(r, g, b, tmat, &xo, &yo, &zo);
    *dist = sqrt(xo * xo + zo * zo);
    if (*dist == zz) {
#ifndef NO_PROTO
	*ang = -666.f;
#else /* NO_PROTO */
	*ang = (float)-666.;
#endif /* NO_PROTO */
    } else {
/*  Normalize to 0..1 */
	*ang = atan2(xo, zo) / (pi * 2);
#ifndef NO_PROTO
	if (*ang < 0.f) {
#else /* NO_PROTO */
	if (*ang < (float)0.) {
#endif /* NO_PROTO */
	    *ang += 1;
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* hueang_ */

