/* ecotm3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ecotm3_(real *xfrmti, real *x0, real *y0, real *z0, real 
	*dx, real *dy, real *dz, real *phix, real *phiy, real *phiz, real *fx,
	 real *fy, real *fz, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecotm3_(xfrmti, x0, y0, z0, dx, dy, dz, phix, phiy, phiz,
	 fx, fy, fz, xfrmto)
real *xfrmti, *x0, *y0, *z0, *dx, *dy, *dz, *phix, *phiy, *phiz, *fx, *fy, *
	fz, *xfrmto;
#endif /* NO_PROTO */
{
    static real wka[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *), ebltm3_(real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_(), ebltm3_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 5;
    xfrmti -= 5;

    /* Function Body */
    ebltm3_(x0, y0, z0, dx, dy, dz, phix, phiy, phiz, fx, fy, fz, wka);
    ecom3_(&xfrmti[5], wka, &xfrmto[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecotm3_ */

