/* ecotm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ecotm_(real *xfrmti, real *x0, real *y0, real *dx, real *
	dy, real *phi, real *fx, real *fy, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecotm_(xfrmti, x0, y0, dx, dy, phi, fx, fy, xfrmto)
real *xfrmti, *x0, *y0, *dx, *dy, *phi, *fx, *fy, *xfrmto;
#endif /* NO_PROTO */
{
    static real wka[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom_(real *, real *, real *), ebltm_(real *, 
	    real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom_(), ebltm_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 4;
    xfrmti -= 4;

    /* Function Body */
    ebltm_(x0, y0, dx, dy, phi, fx, fy, wka);
    ecom_(&xfrmti[4], wka, &xfrmto[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecotm_ */

