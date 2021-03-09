/* eevom3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int eevom3_(real *vwrx, real *vwry, real *vwrz, real *vpnx, 
	real *vpny, real *vpnz, real *vupx, real *vupy, real *vupz, real *
	vwormt)
#else /* NO_PROTO */
/* Subroutine */ int eevom3_(vwrx, vwry, vwrz, vpnx, vpny, vpnz, vupx, vupy, 
	vupz, vwormt)
real *vwrx, *vwry, *vwrz, *vpnx, *vpny, *vpnz, *vupx, *vupy, *vupz, *vwormt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real wk[16]	/* was [4][4] */, tvx, tvy, tvz;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), etr3_(real *, real *, real *, real *), erox_(
	    real *, real *), eroy_(real *, real *), eroz_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), etr3_(), erox_(), eroy_(), eroz_();
#endif /* NO_PROTO */
    static real trmt[16]	/* was [4][4] */, xrot[16]	/* was [4][4] 
	    */, yrot[16]	/* was [4][4] */, zrot[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static real xyrot[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern doublereal satan2_(real *, real *);
#else /* NO_PROTO */
    extern doublereal satan2_();
#endif /* NO_PROTO */

/* calculate Y-rotation (longitude shift), ie swing VPN around */
/* into the VN plane of the UVN system. */
    /* Parameter adjustments */
    vwormt -= 5;

    /* Function Body */
    r__1 = -(doublereal)satan2_(vpnx, vpnz);
    eroy_(&r__1, yrot);
/* transformed VPN: */
    etp3_(vpnx, vpny, vpnz, yrot, &tvx, &tvy, &tvz);
/* calculate X-rotation (latitude shift), ie swing VPN down */
/* to coincide with N axis */
    r__2 = -(doublereal)tvy;
    r__1 = -(doublereal)satan2_(&r__2, &tvz);
    erox_(&r__1, xrot);
/* calculate composite 1st Y, then X rotation: */
    ecom3_(xrot, yrot, xyrot);
/* calculate transformed view-up vector */
    etp3_(vupx, vupy, vupz, xyrot, &tvx, &tvy, &tvz);
/* calculate Z-rotation so as to swing view-up vector into */
/* vn plane, pointing up. */
    r__2 = -(doublereal)tvx;
    r__1 = -(doublereal)satan2_(&r__2, &tvy);
    eroz_(&r__1, zrot);
/* calculate shift for view ref pt */
    r__1 = -(doublereal)(*vwrx);
    r__2 = -(doublereal)(*vwry);
    r__3 = -(doublereal)(*vwrz);
    etr3_(&r__1, &r__2, &r__3, trmt);
/* compose into one matrix */
    ecom3_(xyrot, trmt, wk);
    ecom3_(zrot, wk, &vwormt[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eevom3_ */

