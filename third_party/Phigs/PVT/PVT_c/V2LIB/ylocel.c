/* ylocel.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal ylocel_(integer *yth)
#else /* NO_PROTO */
doublereal ylocel_(yth)
integer *yth;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  YLOCEL returns the appropriate y-coordinate in WC for element */
/*  number YTH, when comparing pairs of elements for traversal */
/*  saving and restoring. */
#ifndef NO_PROTO
    ret_val = (15 - *yth) / 15.f;
#else /* NO_PROTO */
    ret_val = (15 - *yth) / (float)15.;
#endif /* NO_PROTO */
    return ret_val;
} /* ylocel_ */

