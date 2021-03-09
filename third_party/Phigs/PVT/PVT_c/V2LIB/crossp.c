/* crossp.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int crossp_(real *vx1, real *vy1, real *vz1, real *vx2, real 
	*vy2, real *vz2, real *vx3, real *vy3, real *vz3)
#else /* NO_PROTO */
/* Subroutine */ int crossp_(vx1, vy1, vz1, vx2, vy2, vz2, vx3, vy3, vz3)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2, *vx3, *vy3, *vz3;
#endif /* NO_PROTO */
{
/*  This subroutine accepts two 3D vectors and returns their */
/*  cross product. */
    *vx3 = *vy1 * *vz2 - *vz1 * *vy2;
    *vy3 = *vz1 * *vx2 - *vx1 * *vz2;
    *vz3 = *vx1 * *vy2 - *vy1 * *vx2;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* crossp_ */

