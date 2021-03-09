/* pervec.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int pervec_(real *vx1, real *vy1, real *vz1, real *vx2, real 
	*vy2, real *vz2, real *vx3, real *vy3, real *vz3)
#else /* NO_PROTO */
/* Subroutine */ int pervec_(vx1, vy1, vz1, vx2, vy2, vz2, vx3, vy3, vz3)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2, *vx3, *vy3, *vz3;
#endif /* NO_PROTO */
{
    static real k;
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *), dotprd_(real *, real *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_(), dotprd_();
#endif /* NO_PROTO */

/*  This subroutine accepts two 3D vectors and returns a vector */
/*  orthogonal to the first, in the plane of the first two vectors, */
/*  whose dot product with the second vector is positive, hence */
/*  the angle between them is < 90 degrees.  I.e. the 2nd vector */
/*  minus the 3rd results in a vector with the same direction (but */
/*  not length) as the 1st.  K is the factor by which V1 is */
/*  multiplied and then subtracted from V2 - i.e. */

/*       V3 = V2 - K*V1 */
/*                     _ */
/*                     /|A */
/*                   /   | */
/*                 /     | */
/*            V2 /       | V3 */
/*             /         | */
/*           /           | */
/*         /             | */
/*       /               | */
/*      ----------->.....| */
/*          V1 */
/*      \________________/ */
/*           V2 - V3 */
/*  Or, V1 can be thought of as the attitude numbers for a plane, and */
/*  then V3 is the result of the normal projection of V2 into the plane. 
*/

/*  Closely related to PTPLDS, which is a slightly more general case. */
    k = dotprd_(vx1, vy1, vz1, vx2, vy2, vz2) / vecl2_(vx1, vy1, vz1);
    *vx3 = *vx2 - k * *vx1;
    *vy3 = *vy2 - k * *vy1;
    *vz3 = *vz2 - k * *vz1;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pervec_ */

