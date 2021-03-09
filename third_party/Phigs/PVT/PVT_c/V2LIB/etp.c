/* etp.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int etp_(real *xi, real *yi, real *xfrmt, real *xo, real *yo)

#else /* NO_PROTO */
/* Subroutine */ int etp_(xi, yi, xfrmt, xo, yo)
real *xi, *yi, *xfrmt, *xo, *yo;
#endif /* NO_PROTO */
{
    static real w, pti[3]	/* was [3][1] */, pto[3]	/* was [3][1] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    pti[0] = *xi;
    pti[1] = *yi;
#ifndef NO_PROTO
    pti[2] = 1.f;
#else /* NO_PROTO */
    pti[2] = (float)1.;
#endif /* NO_PROTO */
    matmul_(&c__3, &c__3, &c__1, &xfrmt[4], pti, pto);
    w = pto[2];
    *xo = pto[0] / w;
    *yo = pto[1] / w;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etp_ */

