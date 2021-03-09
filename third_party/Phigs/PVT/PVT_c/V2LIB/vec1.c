/* vec1.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int vec1_(real *vx, real *vy, real *vz, real *vx1, real *vy1,
	 real *vz1)
#else /* NO_PROTO */
/* Subroutine */ int vec1_(vx, vy, vz, vx1, vy1, vz1)
real *vx, *vy, *vz, *vx1, *vy1, *vz1;
#endif /* NO_PROTO */
{
    static real d;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */

/*  This subroutine accepts an arbitrary 3D vector and returns a */
/*  parallel vector normalized to unit size. */
    d = vecl_(vx, vy, vz);
    *vx1 = *vx / d;
    *vy1 = *vy / d;
    *vz1 = *vz / d;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* vec1_ */

