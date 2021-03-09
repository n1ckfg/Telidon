/* ero.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int ero_(real *rotang, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int ero_(rotang, xfrmt)
real *rotang, *xfrmt;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real cs, sn;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    idmat_(&c__3, &xfrmt[4]);
    sn = sin(*rotang);
    cs = cos(*rotang);
    xfrmt[4] = cs;
    xfrmt[8] = cs;
    xfrmt[7] = -(doublereal)sn;
    xfrmt[5] = sn;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ero_ */

