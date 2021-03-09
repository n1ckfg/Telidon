/* ceilng.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer ceilng_(real *x)
#else /* NO_PROTO */
integer ceilng_(x)
real *x;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer ix;

/*  CEILNG returns the integer ceiling for x, i.e. the lowest */
/*  integer .ge. x */
    ix = (integer) (*x);
#ifndef NO_PROTO
    if ((real) ix == *x || *x <= 0.f) {
#else /* NO_PROTO */
    if ((real) ix == *x || *x <= (float)0.) {
#endif /* NO_PROTO */
	ret_val = ix;
    } else {
	ret_val = ix + 1;
    }
    return ret_val;
} /* ceilng_ */

