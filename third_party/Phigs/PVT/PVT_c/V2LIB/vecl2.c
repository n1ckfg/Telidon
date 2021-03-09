/* vecl2.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal vecl2_(real *vx, real *vy, real *vz)
#else /* NO_PROTO */
doublereal vecl2_(vx, vy, vz)
real *vx, *vy, *vz;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  This function returns the squared length of a 3D vector. */
    ret_val = *vx * *vx + *vy * *vy + *vz * *vz;
    return ret_val;
} /* vecl2_ */

