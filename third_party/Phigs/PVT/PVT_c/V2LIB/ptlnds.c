/* ptlnds.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ptlnds_(real *px, real *py, real *pz, real *a, real *b, 
	real *c, real *lx, real *ly, real *lz, real *xn, real *yn, real *zn, 
	real *dist)
#else /* NO_PROTO */
/* Subroutine */ int ptlnds_(px, py, pz, a, b, c, lx, ly, lz, xn, yn, zn, 
	dist)
real *px, *py, *pz, *a, *b, *c, *lx, *ly, *lz, *xn, *yn, *zn, *dist;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real u, dp, dx, dy, dz;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static real d2abc;
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *), dotprd_(real *, real *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_(), dotprd_();
#endif /* NO_PROTO */

/*  Given a point and a line, find nearest point on line and */
/*  distance from line to point. */
    dx = *px - *lx;
    dy = *py - *ly;
    dz = *pz - *lz;
    d2abc = vecl2_(a, b, c);
    dp = dotprd_(a, b, c, &dx, &dy, &dz);
    u = dp / d2abc;
    *xn = *lx + *a * u;
    *yn = *ly + *b * u;
    *zn = *lz + *c * u;
    r__1 = *px - *xn;
    r__2 = *py - *yn;
    r__3 = *pz - *zn;
    *dist = vecl_(&r__1, &r__2, &r__3);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ptlnds_ */

