/* rnperm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int rnperm_(integer *size, integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int rnperm_(size, perm)
integer *size, *perm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix, swap;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer ranpos;

/*  RNPERM returns a random permutation of integers 1-SIZE in PERM. */
/*  For example, if SIZE is specified as 4, PERM might = [2,3,1,4]. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
	perm[ix] = ix;
/* L100: */
    }
    for (ix = *size; ix >= 2; --ix) {
	ranpos = rndint_(&c__1, &ix);
	swap = perm[ix];
	perm[ix] = perm[ranpos];
	perm[ranpos] = swap;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rnperm_ */

