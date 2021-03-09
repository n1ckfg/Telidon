/* esc3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int esc3_(real *fx, real *fy, real *fz, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int esc3_(fx, fy, fz, xfrmt)
real *fx, *fy, *fz, *xfrmt;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    idmat_(&c__4, &xfrmt[5]);
    xfrmt[5] = *fx;
    xfrmt[10] = *fy;
    xfrmt[15] = *fz;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* esc3_ */

