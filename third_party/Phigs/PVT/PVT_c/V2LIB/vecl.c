/* vecl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal vecl_(real *vx, real *vy, real *vz)
#else /* NO_PROTO */
doublereal vecl_(vx, vy, vz)
real *vx, *vy, *vz;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_();
#endif /* NO_PROTO */

/*  This function returns the length of a 3D vector. */
    ret_val = sqrt(vecl2_(vx, vy, vz));
    return ret_val;
} /* vecl_ */

