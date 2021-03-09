/* eevmm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int eevmm_(real *vwwnlm, real *pjvplm, real *vwmpmt)
#else /* NO_PROTO */
/* Subroutine */ int eevmm_(vwwnlm, pjvplm, vwmpmt)
real *vwwnlm, *pjvplm, *vwmpmt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_();
#endif /* NO_PROTO */

/* note: no 3D version (eevmm3) because standard does not specify */
/* a unique transformation. */
    /* Parameter adjustments */
    vwmpmt -= 4;
    --pjvplm;
    --vwwnlm;

    /* Function Body */
    r__1 = pjvplm[1] - vwwnlm[1];
    r__2 = pjvplm[3] - vwwnlm[3];
    r__3 = (pjvplm[2] - pjvplm[1]) / (vwwnlm[2] - vwwnlm[1]);
    r__4 = (pjvplm[4] - pjvplm[3]) / (vwwnlm[4] - vwwnlm[3]);
    ebltm_(&vwwnlm[1], &vwwnlm[3], &r__1, &r__2, &c_b2, &r__3, &r__4, &vwmpmt[
	    4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eevmm_ */

