/* satan2.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal satan2_(real *y, real *x)
#else /* NO_PROTO */
doublereal satan2_(y, x)
real *y, *x;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    double atan2(doublereal, doublereal);
#else /* NO_PROTO */
    double atan2();
#endif /* NO_PROTO */

/*  Safe version of arctan-2 function; returns zero when both x and y */
/*  are zero. */
#ifndef NO_PROTO
    if (*x == 0.f && *y == 0.f) {
	ret_val = 0.f;
#else /* NO_PROTO */
    if (*x == (float)0. && *y == (float)0.) {
	ret_val = (float)0.;
#endif /* NO_PROTO */
    } else {
	ret_val = atan2(*y, *x);
    }
    return ret_val;
} /* satan2_ */

