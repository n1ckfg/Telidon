/* invol.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int invol_(real *px, real *py, real *pz, integer *ilim, real 
	*arx, real *ary, real *arz, integer *side, real *pldist)
#else /* NO_PROTO */
/* Subroutine */ int invol_(px, py, pz, ilim, arx, ary, arz, side, pldist)
real *px, *py, *pz;
integer *ilim;
real *arx, *ary, *arz;
integer *side;
real *pldist;
#endif /* NO_PROTO */
{
    static real a, b, c, d, xn, yn, zn;
    static integer idim;
    static real best;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), ptspl_(integer *, 
	    real *, real *, real *, real *, real *, real *, real *);
    extern integer inarea_(real *, real *, integer *, real *, real *);
    extern /* Subroutine */ int ptplds_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), ptspl_();
    extern integer inarea_();
    extern /* Subroutine */ int ptplds_();
#endif /* NO_PROTO */

/*  Given a 3D point and planar fill area, determine whether point */
/*  is within normal projection of the area, and distance of point */
/*  from the plane. */
/*  Input parameters: */
/*    PX,PY,PZ     : 3D point */
/*    ILIM         : Number of vertices of fill area */
/*    ARX,ARY,ARZ  : vertices of fill area */
/*  Output parameters: */
/*    SIDE         : location of point within volume - */
/*                 : 1 if inside, 2 if on an edge, 3 if outside */
/*    PLDIST       : distance of point from the plane. */
    /* Parameter adjustments */
    --arz;
    --ary;
    --arx;

    /* Function Body */
    if (*ilim < 3) {
	unmsg_("Degenerate fill area passed to INVOL.", 37L);
    }
/* get plane from set of points */
    ptspl_(ilim, &arx[1], &ary[1], &arz[1], &a, &b, &c, &d);
/* Given a point and plane-coefficients, find nearest */
/* point on plane and distance from plane to point. */
    ptplds_(px, py, pz, &a, &b, &c, &d, &xn, &yn, &zn, pldist);
/*  Now project the planar points (fill area, plus the normal */
/*  projected point xn,yn,zn) to the "best" plane: x=0, y=0, or z=0, */
/*  depending on largest attitude number. */
    if (dabs(a) > dabs(b)) {
	idim = 1;
	best = dabs(a);
    } else {
	idim = 2;
	best = dabs(b);
    }
    if (dabs(c) > best) {
	idim = 3;
    }
    if (idim == 1) {
/* project to x=0 */
	*side = inarea_(&yn, &zn, ilim, &ary[1], &arz[1]);
    } else if (idim == 2) {
/* project to y=0 */
	*side = inarea_(&xn, &zn, ilim, &arx[1], &arz[1]);
    } else {
/* project to z=0 */
	*side = inarea_(&xn, &yn, ilim, &arx[1], &ary[1]);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* invol_ */

