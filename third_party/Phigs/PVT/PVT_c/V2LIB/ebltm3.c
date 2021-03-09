/* ebltm3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ebltm3_(real *x0, real *y0, real *z0, real *dx, real *dy,
	 real *dz, real *phix, real *phiy, real *phiz, real *fx, real *fy, 
	real *fz, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int ebltm3_(x0, y0, z0, dx, dy, dz, phix, phiy, phiz, fx, fy,
	 fz, xfrmt)
real *x0, *y0, *z0, *dx, *dy, *dz, *phix, *phiy, *phiz, *fx, *fy, *fz, *xfrmt;

#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real wka[16]	/* was [4][4] */, wkb[16]	/* was [4][4] */, wkc[
	    16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc3_(real *, real *, real *, real *), etr3_(
	    real *, real *, real *, real *), erox_(real *, real *), eroy_(
	    real *, real *), eroz_(real *, real *), ecom3_(real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc3_(), etr3_(), erox_(), eroy_(), eroz_(), 
	    ecom3_();
#endif /* NO_PROTO */

/* shift so that fixed point is at origin */
    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    r__1 = -(doublereal)(*x0);
    r__2 = -(doublereal)(*y0);
    r__3 = -(doublereal)(*z0);
    etr3_(&r__1, &r__2, &r__3, wka);
/* scale */
    esc3_(fx, fy, fz, wkb);
    ecom3_(wkb, wka, wkc);
/* rotations */
    erox_(phix, wka);
    ecom3_(wka, wkc, wkb);
    eroy_(phiy, wka);
    ecom3_(wka, wkb, wkc);
    eroz_(phiz, wka);
    ecom3_(wka, wkc, wkb);
/* do specified shift and undo fixed-point shift */
    r__1 = *x0 + *dx;
    r__2 = *y0 + *dy;
    r__3 = *z0 + *dz;
    etr3_(&r__1, &r__2, &r__3, wka);
    ecom3_(wka, wkb, &xfrmt[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ebltm3_ */

