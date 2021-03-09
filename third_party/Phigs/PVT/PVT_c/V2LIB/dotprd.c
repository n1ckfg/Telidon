/* dotprd.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal dotprd_(real *vx1, real *vy1, real *vz1, real *vx2, real *vy2, 
	real *vz2)
#else /* NO_PROTO */
doublereal dotprd_(vx1, vy1, vz1, vx2, vy2, vz2)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  This function accepts two 3D vectors and returns their dot product. */

    ret_val = *vx1 * *vx2 + *vy1 * *vy2 + *vz1 * *vz2;
    return ret_val;
} /* dotprd_ */

