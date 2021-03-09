/* faclip.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
static real c_b3 = .4f;
static real c_b7 = -1.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
static real c_b3 = (float).4;
static real c_b7 = (float)-1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int faclip_(real *acl, real *bcl, real *ccl, real *dcl, real 
	*xco, real *yco, real *zco, real *mcv3)
#else /* NO_PROTO */
/* Subroutine */ int faclip_(acl, bcl, ccl, dcl, xco, yco, zco, mcv3)
real *acl, *bcl, *ccl, *dcl, *xco, *yco, *zco, *mcv3;
#endif /* NO_PROTO */
{
    static real af, bf, cf, df;
    static integer jx;
#ifndef NO_PROTO
    extern /* Subroutine */ int pl2pl_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *);
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pl2pl_();
    extern doublereal rndrl_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  FACLIP accepts the co-efficients for two given clipping planes, */
/*  generates a plane for a fill area primitive and computes */
/*  another clipping plane, perpendicular to the primitive's */
/*  plane, but intersecting it the same way as does the given */
/*  clipping plane. */
/*  Input parameters: */
/*    ACL,BCL,CCL,DCL : co-efficients of given planes (CCL usually zero) 
*/
/*  Output parameters: */
/*    XCO,YCO         : x,y co-efficients of primitive plane */
/*    MCV3            : computed planes, perpendicular to primitive plane 
*/
/*  randomize plane of fill area (in MC): xco*x + yco*y - z + zco = 0 */
    /* Parameter adjustments */
    mcv3 -= 7;
    --dcl;
    --ccl;
    --bcl;
    --acl;

    /* Function Body */
    *xco = rndrl_(&c_b2, &c_b3);
    *yco = rndrl_(&c_b2, &c_b3);
#ifndef NO_PROTO
    *zco = .1f;
#else /* NO_PROTO */
    *zco = (float).1;
#endif /* NO_PROTO */
/*  calculate 3D MCVs perpendicular to MC fill area plane, with negative 
*/
/*  x-component. */
    for (jx = 1; jx <= 2; ++jx) {
	pl2pl_(xco, yco, &c_b7, zco, &acl[jx], &bcl[jx], &ccl[jx], &dcl[jx], &
		af, &bf, &cf, &df);
#ifndef NO_PROTO
	if (af == 0.f) {
#else /* NO_PROTO */
	if (af == (float)0.) {
#endif /* NO_PROTO */
	    unmsg_("Generated invalid clipping plane.", 33L);
#ifndef NO_PROTO
	} else if (af > 0.f) {
#else /* NO_PROTO */
	} else if (af > (float)0.) {
#endif /* NO_PROTO */
	    af = -(doublereal)af;
	    bf = -(doublereal)bf;
	    cf = -(doublereal)cf;
	    df = -(doublereal)df;
	}
	mcv3[jx * 6 + 1] = -(doublereal)df / af;
#ifndef NO_PROTO
	mcv3[jx * 6 + 2] = 0.f;
	mcv3[jx * 6 + 3] = 0.f;
#else /* NO_PROTO */
	mcv3[jx * 6 + 2] = (float)0.;
	mcv3[jx * 6 + 3] = (float)0.;
#endif /* NO_PROTO */
	mcv3[jx * 6 + 4] = af;
	mcv3[jx * 6 + 5] = bf;
	mcv3[jx * 6 + 6] = cf;
/* L330: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* faclip_ */

