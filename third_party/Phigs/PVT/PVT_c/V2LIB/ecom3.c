/* ecom3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int ecom3_(real *xfrmta, real *xfrmtb, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecom3_(xfrmta, xfrmtb, xfrmto)
real *xfrmta, *xfrmtb, *xfrmto;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 5;
    xfrmtb -= 5;
    xfrmta -= 5;

    /* Function Body */
    matmul_(&c__4, &c__4, &c__4, &xfrmta[5], &xfrmtb[5], &xfrmto[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecom3_ */

