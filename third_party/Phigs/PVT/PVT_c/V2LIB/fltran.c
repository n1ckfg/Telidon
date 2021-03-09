/* fltran.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int fltran_(real *a, real *b, real *c, real *mat)
#else /* NO_PROTO */
/* Subroutine */ int fltran_(a, b, c, mat)
real *a, *b, *c, *mat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Builtin functions */
#ifndef NO_PROTO
    double asin(doublereal);
#else /* NO_PROTO */
    double asin();
#endif /* NO_PROTO */

    /* Local variables */
    static real uu, zz;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
    extern /* Subroutine */ int ebltm3_();
    extern doublereal satan2_();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern doublereal satan2_(real *, real *);

#endif /* not NO_PROTO */
/*  Given a set of attitude numbers for a plane, FLTRAN returns a */
/*  4 X 4 transformation matrix which rotates the plane so as to be */
/*  parallel to the z=0 plane.  This is useful for visualizing a */
/*  planar 3D primitive. */
    /* Parameter adjustments */
    mat -= 5;

    /* Function Body */
#ifndef NO_PROTO
    zz = 0.f;
    uu = 1.f;
#else /* NO_PROTO */
    zz = (float)0.;
    uu = (float)1.;
#endif /* NO_PROTO */
    r__2 = -(doublereal)(*b);
    r__1 = -(doublereal)satan2_(&r__2, c);
    r__3 = -(doublereal)asin(*a / vecl_(a, b, c));
    ebltm3_(&zz, &zz, &zz, &zz, &zz, &zz, &r__1, &r__3, &zz, &uu, &uu, &uu, &
	    mat[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* fltran_ */

