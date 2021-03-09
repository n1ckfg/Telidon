/* ebltm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ebltm_(real *x0, real *y0, real *dx, real *dy, real *phi,
	 real *fx, real *fy, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int ebltm_(x0, y0, dx, dy, phi, fx, fy, xfrmt)
real *x0, *y0, *dx, *dy, *phi, *fx, *fy, *xfrmt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int esc_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc_();
#endif /* NO_PROTO */
    static real wka[9]	/* was [3][3] */, wkb[9]	/* was [3][3] */, wkc[
	    9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ero_(real *, real *), etr_(real *, real *, 
	    real *), ecom_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ero_(), etr_(), ecom_();
#endif /* NO_PROTO */

/* shift so that fixed point is at origin */
    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    r__1 = -(doublereal)(*x0);
    r__2 = -(doublereal)(*y0);
    etr_(&r__1, &r__2, wka);
/* scale */
    esc_(fx, fy, wkb);
    ecom_(wkb, wka, wkc);
/* rotation */
    ero_(phi, wka);
    ecom_(wka, wkc, wkb);
/* do specified shift and undo fixed-point shift */
    r__1 = *x0 + *dx;
    r__2 = *y0 + *dy;
    etr_(&r__1, &r__2, wka);
    ecom_(wka, wkb, &xfrmt[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ebltm_ */

