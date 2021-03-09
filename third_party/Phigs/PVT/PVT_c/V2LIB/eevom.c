/* eevom.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int eevom_(real *vwrx, real *vwry, real *vupx, real *vupy, 
	real *vwormt)
#else /* NO_PROTO */
/* Subroutine */ int eevom_(vwrx, vwry, vupx, vupy, vwormt)
real *vwrx, *vwry, *vupx, *vupy, *vwormt;
#endif /* NO_PROTO */
{
    static real u, wk[16]	/* was [4][4] */, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int red43_(real *, real *), eevom3_(real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int red43_(), eevom3_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Parameter adjustments */
    vwormt -= 4;

    /* Function Body */
#ifndef NO_PROTO
    zz = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    zz = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    eevom3_(vwrx, vwry, &zz, &zz, &zz, &u, vupx, vupy, &zz, wk);
    red43_(wk, &vwormt[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eevom_ */

