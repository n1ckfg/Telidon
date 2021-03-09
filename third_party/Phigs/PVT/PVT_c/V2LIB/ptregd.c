/* ptregd.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal ptregd_(real *px, real *py, real *pz, integer *nsz, real *xa, real 
	*ya, real *za)
#else /* NO_PROTO */
doublereal ptregd_(px, py, pz, nsz, xa, ya, za)
real *px, *py, *pz;
integer *nsz;
real *xa, *ya, *za;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real ret_val, r__1, r__2, r__3;

    /* Local variables */
    static real d1, d2;
    static integer ia, ib;
    static real xn, yn, zn, abcp, sega, segb, segc;
    static integer side;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static real dtmp, ptmin;
#ifndef NO_PROTO
    extern /* Subroutine */ int invol_(real *, real *, real *, integer *, 
	    real *, real *, real *, integer *, real *), unmsg_(char *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int invol_(), unmsg_();
#endif /* NO_PROTO */
    static real edgmin, pldist;
#ifndef NO_PROTO
    extern /* Subroutine */ int ptlnds_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ptlnds_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  PTREGD computes the minimum distance from a 3D point to a planar */
/*  3D region. */
/* Input parameters: */
/*   PX,PY,PZ : point for which distance is found. */
/*   NSZ      : number of points in region. */
/*   XA,YA,ZA : coordinates of planar region. */
    /* Parameter adjustments */
    --za;
    --ya;
    --xa;

    /* Function Body */
    if (*nsz < 3) {
	unmsg_("Degenerate region passed to PTREGD.", 35L);
    }
    invol_(px, py, pz, nsz, &xa[1], &ya[1], &za[1], &side, &pldist);
    if (side <= 2) {
/*  Distance is simply distance of point from containing plane */
	ret_val = pldist;
	return ret_val;
    }
/*  Distance is minimum of distances from points and from individual edges
 */
/*  Get point minimum: */
#ifndef NO_PROTO
    ptmin = 1e38f;
#else /* NO_PROTO */
    ptmin = (float)1e38;
#endif /* NO_PROTO */
    i__1 = *nsz;
    for (ia = 1; ia <= i__1; ++ia) {
	r__1 = *px - xa[ia];
	r__2 = *py - ya[ia];
	r__3 = *pz - za[ia];
	dtmp = vecl_(&r__1, &r__2, &r__3);
	if (dtmp < ptmin) {
	    ptmin = dtmp;
	}
/* L100: */
    }
/*  Get edge minimum: */
#ifndef NO_PROTO
    edgmin = 1e38f;
#else /* NO_PROTO */
    edgmin = (float)1e38;
#endif /* NO_PROTO */
    i__1 = *nsz;
    for (ia = 1; ia <= i__1; ++ia) {
	ib = ia % *nsz + 1;
/*  Determine if point is between the two planes that contain the */
/*  endpoints of the segment, and are normal to it.  If not, ignore - 
*/
/*  handled by point minimum.  If so, distance is that from point to 
*/
/*  containing line. */
/*  attitude of planes: */
	sega = xa[ia] - xa[ib];
	segb = ya[ia] - ya[ib];
	segc = za[ia] - za[ib];
/*  d-coefficient of each plane: */
	d1 = -(doublereal)(sega * xa[ia] + segb * ya[ia] + segc * za[ia]);
	d2 = -(doublereal)(sega * xa[ib] + segb * ya[ib] + segc * za[ib]);
/*  ABC terms for px,py,pz: */
	abcp = sega * *px + segb * *py + segc * *pz;
#ifndef NO_PROTO
	if ((abcp + d1) * (abcp + d2) < 0.f) {
#else /* NO_PROTO */
	if ((abcp + d1) * (abcp + d2) < (float)0.) {
#endif /* NO_PROTO */
/*  Opposite signs imply point is between planes - get distance fr
om */
/*  point to line. */
	    ptlnds_(px, py, pz, &sega, &segb, &segc, &xa[ia], &ya[ia], &za[ia]
		    , &xn, &yn, &zn, &dtmp);
	    if (dtmp < edgmin) {
		edgmin = dtmp;
	    }
	}
/* L200: */
    }
    ret_val = dmin(ptmin,edgmin);
    return ret_val;
} /* ptregd_ */

