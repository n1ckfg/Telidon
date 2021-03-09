/* tranhs.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int tranhs_(real *hs, real *xform, real *a, real *b, real *c,
	 real *d)
#else /* NO_PROTO */
/* Subroutine */ int tranhs_(hs, xform, a, b, c, d)
real *hs, *xform, *a, *b, *c, *d;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int vec1_(real *, real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int vec1_();
#endif /* NO_PROTO */
    static real oldx[4], oldy[4], oldz[4], newx[4], newy[4], newz[4], tmpx, 
	    tmpy, tmpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int pt3pl_(real *, real *, real *, real *, real *,
	     real *, real *), prpv1_(real *, real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pt3pl_(), prpv1_();
#endif /* NO_PROTO */
    static real vecax, vecay, vecaz, vecbx, vecby, vecbz;
#ifndef NO_PROTO
    extern /* Subroutine */ int arrtp3_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *), crossp_(real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int arrtp3_(), crossp_();
#endif /* NO_PROTO */

/*  TRANHS accepts a 3D half-space, described as a point (on the */
/*  boundary plane) and normal vector, applies a transform, and */
/*  returns the coefficients of the new boundary plane, such that */
/*  x,y,z is in the new half-space iff A*x + B*y + C*z + D .GE. 0 */
/*  Input parameters: */
/*    HS(1,2,3)  : x,y,z coordinates of point of half-space */
/*    HS(4,5,6)  : x,y,z coordinates of normal vector of half-space */
/*    XFORM      : transformation matrix */
/*  Output parameters: */
/*    A,B,C,D    : coefficients of new boundary plane. */
/*  VECA is a unit vector orthogonal to the normal vector */
    /* Parameter adjustments */
    xform -= 5;
    --hs;

    /* Function Body */
    prpv1_(&hs[4], &hs[5], &hs[6], &tmpx, &tmpy, &tmpz);
    vec1_(&tmpx, &tmpy, &tmpz, &vecax, &vecay, &vecaz);
/*  VECB is a unit vector orthogonal to the normal vector and VECA */
    crossp_(&vecax, &vecay, &vecaz, &hs[4], &hs[5], &hs[6], &tmpx, &tmpy, &
	    tmpz);
    vec1_(&tmpx, &tmpy, &tmpz, &vecbx, &vecby, &vecbz);
/*  OLD-1, OLD-2, and OLD-3 are all in the (old) boundary plane, */
/*  forming an L-shape. */
    oldx[0] = hs[1] + vecax;
    oldy[0] = hs[2] + vecay;
    oldz[0] = hs[3] + vecaz;
    oldx[1] = hs[1] + vecbx;
    oldy[1] = hs[2] + vecby;
    oldz[1] = hs[3] + vecbz;
    oldx[2] = hs[1];
    oldy[2] = hs[2];
    oldz[2] = hs[3];
/*  OLD-4 is a point inside the (old) half-space */
    oldx[3] = hs[1] + hs[4];
    oldy[3] = hs[2] + hs[5];
    oldz[3] = hs[3] + hs[6];
/*  transform 4 old points to 4 new points */
    arrtp3_(&c__4, oldx, oldy, oldz, &xform[5], newx, newy, newz);
/*  first 3 new points define new boundary plane */
    pt3pl_(newx, newy, newz, a, b, c, d);
/*  check that parity is OK - if not, negate co-efficients */
#ifndef NO_PROTO
    if (*a * newx[3] + *b * newy[3] + *c * newz[3] + *d < 0.f) {
#else /* NO_PROTO */
    if (*a * newx[3] + *b * newy[3] + *c * newz[3] + *d < (float)0.) {
#endif /* NO_PROTO */
	*a = -(doublereal)(*a);
	*b = -(doublereal)(*b);
	*c = -(doublereal)(*c);
	*d = -(doublereal)(*d);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tranhs_ */

