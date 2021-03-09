/* mod1.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer mod1_(integer *x, integer *m)
#else /* NO_PROTO */
integer mod1_(x, m)
integer *x, *m;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer xw;

/*  MOD1 returns X mod M, but coerced between 1 and M, not between */
/*  0 and M-1. */
    if (*x < 0) {
	xw = *x - (*x / *m - 2) * *m;
    } else {
	xw = *x;
    }
    ret_val = xw % *m;
    if (ret_val <= 0) {
	ret_val = *m;
    }
    return ret_val;
} /* mod1_ */

