/* zval.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal zval_(real *x, real *y)
#else /* NO_PROTO */
doublereal zval_(x, y)
real *x, *y;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  ZVAL is just a simple linear function of x and y so as to */
/*  generate 3D points on the plane: 3x + 4y - z - 7 = 0, so */
/*    z = f(x,y) = 3x + 4y - 7 */
    ret_val = *x * 3 + *y * 4 - 7;
    return ret_val;
} /* zval_ */

