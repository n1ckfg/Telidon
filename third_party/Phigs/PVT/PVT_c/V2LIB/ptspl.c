/* ptspl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ptspl_(integer *ilim, real *x, real *y, real *z, real *a,
	 real *b, real *c, real *d)
#else /* NO_PROTO */
/* Subroutine */ int ptspl_(ilim, x, y, z, a, b, c, d)
integer *ilim;
real *x, *y, *z, *a, *b, *c, *d;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ia;
    static real al, bl, cl, xl, yl, zl, xn, yn, zn, xt[3], yt[3], zt[3];
    static integer ihi, ilo;
    static real sep, dist, xsep, ysep, zsep;
#ifndef NO_PROTO
    extern /* Subroutine */ int pt3pl_(real *, real *, real *, real *, real *,
	     real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pt3pl_();
#endif /* NO_PROTO */
    static integer ibest, ixmin, iymin, ixmax, iymax, izmax, izmin;
#ifndef NO_PROTO
    extern /* Subroutine */ int ptlnds_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ptlnds_();
#endif /* NO_PROTO */
    static real distmx;

/*  Given a set of supposedly co-planar points, find containing */
/*  plane.  Idea here is to find 2 points at greatest separation */
/*  along a principal axis (x, y, or z) and then select 3rd point */
/*  as the one with greatest distance from the line connecting */
/*  these 2 points.  This is an attempt to find 3 "good" (widely */
/*  separated, highly non-colinear) points for computing the plane. */
/*  If there are 3 non-colinear points, this will find them. */
    /* Parameter adjustments */
    --z;
    --y;
    --x;

    /* Function Body */
    ixmax = 1;
    ixmin = 1;
    iymax = 1;
    iymin = 1;
    izmax = 1;
    izmin = 1;
/*  find min,max points for x,y,z */
    i__1 = *ilim;
    for (ia = 2; ia <= i__1; ++ia) {
	if (x[ia] > x[ixmax]) {
	    ixmax = ia;
	}
	if (x[ia] < x[ixmin]) {
	    ixmin = ia;
	}
	if (y[ia] > y[iymax]) {
	    iymax = ia;
	}
	if (y[ia] < y[iymin]) {
	    iymin = ia;
	}
	if (z[ia] > z[izmax]) {
	    izmax = ia;
	}
	if (z[ia] < z[izmin]) {
	    izmin = ia;
	}
/* L100: */
    }
    xsep = x[ixmax] - x[ixmin];
    ysep = y[iymax] - y[iymin];
    zsep = z[izmax] - z[izmin];
/*  take largest of the three separations: */
    if (xsep > ysep) {
	ihi = ixmax;
	ilo = ixmin;
	sep = xsep;
    } else {
	ihi = iymax;
	ilo = iymin;
	sep = ysep;
    }
    if (zsep > sep) {
	ihi = izmax;
	ilo = izmin;
    }
/*  use two widely separated points as axis for plane */
    xt[0] = x[ilo];
    yt[0] = y[ilo];
    zt[0] = z[ilo];
    xt[1] = x[ihi];
    yt[1] = y[ihi];
    zt[1] = z[ihi];
/*  Parameters for axis */
    al = xt[1] - xt[0];
    bl = yt[1] - yt[0];
    cl = zt[1] - zt[0];
    xl = xt[0];
    yl = yt[0];
    zl = zt[0];
/*  as 3rd point, use one with greatest distance from line */
#ifndef NO_PROTO
    distmx = -1.1f;
#else /* NO_PROTO */
    distmx = (float)-1.1;
#endif /* NO_PROTO */
    i__1 = *ilim;
    for (ia = 1; ia <= i__1; ++ia) {
	ptlnds_(&x[ia], &y[ia], &z[ia], &al, &bl, &cl, &xl, &yl, &zl, &xn, &
		yn, &zn, &dist);
	if (dist > distmx) {
	    distmx = dist;
	    ibest = ia;
	}
/* L200: */
    }
    xt[2] = x[ibest];
    yt[2] = y[ibest];
    zt[2] = z[ibest];
    pt3pl_(xt, yt, zt, a, b, c, d);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ptspl_ */

