/* prpv1.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int prpv1_(real *vx1, real *vy1, real *vz1, real *vx2, real *
	vy2, real *vz2)
#else /* NO_PROTO */
/* Subroutine */ int prpv1_(vx1, vy1, vz1, vx2, vy2, vz2)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2;
#endif /* NO_PROTO */
{
    static real z;

/*  PRPV1 accepts a 3D vector and returns another 3D vector */
/*  perpendicular to it. */
#ifndef NO_PROTO
    z = 0.f;
#else /* NO_PROTO */
    z = (float)0.;
#endif /* NO_PROTO */
    *vx2 = z;
    *vy2 = z;
    *vz2 = z;
    if (*vx1 == z) {
#ifndef NO_PROTO
	*vx2 = 1.f;
#else /* NO_PROTO */
	*vx2 = (float)1.;
#endif /* NO_PROTO */
    } else if (*vy1 == z) {
#ifndef NO_PROTO
	*vy2 = 1.f;
#else /* NO_PROTO */
	*vy2 = (float)1.;
#endif /* NO_PROTO */
    } else if (*vz1 == z) {
#ifndef NO_PROTO
	*vz2 = 1.f;
#else /* NO_PROTO */
	*vz2 = (float)1.;
#endif /* NO_PROTO */
    } else {
	*vx2 = *vy1;
	*vy2 = -(doublereal)(*vx1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prpv1_ */

