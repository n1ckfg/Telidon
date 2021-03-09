/* etr3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int etr3_(real *dx, real *dy, real *dz, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int etr3_(dx, dy, dz, xfrmt)
real *dx, *dy, *dz, *xfrmt;
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
    xfrmt[17] = *dx;
    xfrmt[18] = *dy;
    xfrmt[19] = *dz;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etr3_ */

