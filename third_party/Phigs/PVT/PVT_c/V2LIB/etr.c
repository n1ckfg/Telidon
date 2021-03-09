/* etr.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int etr_(real *dx, real *dy, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int etr_(dx, dy, xfrmt)
real *dx, *dy, *xfrmt;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    idmat_(&c__3, &xfrmt[4]);
    xfrmt[10] = *dx;
    xfrmt[11] = *dy;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etr_ */

