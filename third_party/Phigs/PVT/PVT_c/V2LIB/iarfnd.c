/* iarfnd.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer iarfnd_(integer *key, integer *arsiz, integer *iarr)
#else /* NO_PROTO */
integer iarfnd_(key, arsiz, iarr)
integer *key, *arsiz, *iarr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer ix;

/*  IARFND searches the first ARSIZ entries within IARR, and returns */
/*  the first location equal to KEY. If not found, 0 is returned. */
    /* Parameter adjustments */
    --iarr;

    /* Function Body */
    i__1 = *arsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	if (iarr[ix] == *key) {
	    ret_val = ix;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = 0;
    return ret_val;
} /* iarfnd_ */

