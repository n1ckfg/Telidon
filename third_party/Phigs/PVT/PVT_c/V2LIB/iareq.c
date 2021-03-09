/* iareq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical iareq_(integer *size, integer *act, integer *exp__)
#else /* NO_PROTO */
logical iareq_(size, act, exp__)
integer *size, *act, *exp__;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix;

/*  General purpose routine for equality of two integer arrays. */
/*  ------- Input parameters: */
/*  size    : Number of elements to be compared */
/*  act     : actual values */
/*  exp     : expected values */
/*  This will handle multi-dimensional arrays according to the usual */
/*  Fortran rules for overlaying arrays. */
    /* Parameter adjustments */
    --exp__;
    --act;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
	if (act[ix] != exp__[ix]) {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* iareq_ */

