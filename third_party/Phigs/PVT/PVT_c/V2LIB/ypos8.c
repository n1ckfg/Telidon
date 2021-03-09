/* ypos8.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal ypos8_(integer *yth)
#else /* NO_PROTO */
doublereal ypos8_(yth)
integer *yth;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  YPOS8 returns the appropriate y-coordinate in WC for element */
/*  number yth. */
#ifndef NO_PROTO
    ret_val = (9 - *yth) / 9.f;
#else /* NO_PROTO */
    ret_val = (9 - *yth) / (float)9.;
#endif /* NO_PROTO */
    return ret_val;
} /* ypos8_ */

