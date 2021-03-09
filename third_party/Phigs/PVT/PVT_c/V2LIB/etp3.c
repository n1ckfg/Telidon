/* etp3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int etp3_(real *xi, real *yi, real *zi, real *xfrmt, real *
	xo, real *yo, real *zo)
#else /* NO_PROTO */
/* Subroutine */ int etp3_(xi, yi, zi, xfrmt, xo, yo, zo)
real *xi, *yi, *zi, *xfrmt, *xo, *yo, *zo;
#endif /* NO_PROTO */
{
    static real w, pti[4]	/* was [4][1] */, pto[4]	/* was [4][1] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    pti[0] = *xi;
    pti[1] = *yi;
    pti[2] = *zi;
#ifndef NO_PROTO
    pti[3] = 1.f;
#else /* NO_PROTO */
    pti[3] = (float)1.;
#endif /* NO_PROTO */
    matmul_(&c__4, &c__4, &c__1, &xfrmt[5], pti, pto);
    w = pto[3];
    *xo = pto[0] / w;
    *yo = pto[1] / w;
    *zo = pto[2] / w;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etp3_ */

