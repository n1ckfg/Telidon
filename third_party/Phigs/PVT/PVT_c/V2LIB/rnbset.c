/* rnbset.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int rnbset_(integer *size, integer *lo, integer *hi, integer 
	*set)
#else /* NO_PROTO */
/* Subroutine */ int rnbset_(size, lo, hi, set)
integer *size, *lo, *hi, *set;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ix, iy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
    extern integer rndint_();
#endif /* NO_PROTO */

/*  RNBSET returns a random set of SIZE distinct integers, chosen from */
/*  the universe of LO-HI (inclusive), returned in SET.  For example, */
/*  if SIZE is specified as 4, LO=3 and HI=10, SET might = [9,5,7,4]. */
    /* Parameter adjustments */
    --set;

    /* Function Body */
    if (*size > *hi - *lo + 1) {
	unmsg_("In RNBSET, size of set exceeds universe.", 40L);
    }
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
L110:
	set[ix] = rndint_(lo, hi);
	i__2 = ix - 1;
	for (iy = 1; iy <= i__2; ++iy) {
	    if (set[ix] == set[iy]) {
		goto L110;
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rnbset_ */

