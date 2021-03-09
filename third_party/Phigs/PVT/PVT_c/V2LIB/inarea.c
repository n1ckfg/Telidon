/* inarea.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer inarea_(real *px, real *py, integer *ilim, real *x, real *y)
#else /* NO_PROTO */
integer inarea_(px, py, ilim, x, y)
real *px, *py;
integer *ilim;
real *x, *y;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static real a, b, c;
    static integer ia, ib;
    static real xa, ya, xb, yb;
    static integer ix, ict, icur;
    static real xcur, ycur, yint;
    static integer iprev;
    static real xprev, yprev;
#ifndef NO_PROTO
    extern /* Subroutine */ int pt2cof_(real *, real *, real *, real *, real *
	    , real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pt2cof_();
#endif /* NO_PROTO */
    static integer cursgn, icross;

/*    Given a 2D point and fill area, determine whether point */
/*    is within the area, on edge, or outside. */
/*  Input parameters: */
/*    PX,PY  : 2D point */
/*    ILIM   : Number of vertices of fill area */
/*    X,Y    : vertices of fill area */
/*   Function returns: */
/*       1 : inside */
/*       2 : on an edge */
/*       3 : outside */
/*  Idea here is to generate a ray straight up from px,py (positive */
/*  y-direction), and see how many times it crosses the border. */
/*  First see if px,py is on any edge: */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    i__1 = *ilim;
    for (ia = 1; ia <= i__1; ++ia) {
	ib = ia % *ilim + 1;
	xa = x[ia];
	ya = y[ia];
	xb = x[ib];
	yb = y[ib];
/* Given two points, calculate line coefficients */
	pt2cof_(&xa, &ya, &xb, &yb, &a, &b, &c);
/* if not co-linear, skip */
#ifndef NO_PROTO
	if (a * *px + b * *py + c != 0.f) {
#else /* NO_PROTO */
	if (a * *px + b * *py + c != (float)0.) {
#endif /* NO_PROTO */
	    goto L100;
	}
/* if px,py between points, it's on edge: */
#ifndef NO_PROTO
	if ((xa - *px) * (xb - *px) <= 0.f && (ya - *py) * (yb - *py) <= 0.f) 
		{
#else /* NO_PROTO */
	if ((xa - *px) * (xb - *px) <= (float)0. && (ya - *py) * (yb - *py) <=
		 (float)0.) {
#endif /* NO_PROTO */
	    ret_val = 2;
	    return ret_val;
	}
L100:
	;
    }
/* OK, assume from here on that point is not on an edge; */
/* get point off y-axis */
    i__1 = *ilim;
    for (ix = 1; ix <= i__1; ++ix) {
	if (x[ix] == *px) {
	    goto L200;
	}
	if (x[ix] < *px) {
	    cursgn = -1;
	} else {
	    cursgn = 1;
	}
	iprev = ix;
	goto L210;
L200:
	;
    }
    ret_val = 3;
    return ret_val;
L210:
    icross = 0;
    xprev = x[iprev];
    yprev = y[iprev];
/* start of loop for checking edge segments */
    i__1 = *ilim - 1;
    for (ict = 0; ict <= i__1; ++ict) {
	icur = (iprev + ict) % *ilim + 1;
	xcur = x[icur];
	ycur = y[icur];
/* if not a definite crossing of y-axis (equal doesn't count), */
/* save last point and keep going ... */
#ifndef NO_PROTO
	if ((xcur - *px) * cursgn >= 0.f) {
#else /* NO_PROTO */
	if ((xcur - *px) * cursgn >= (float)0.) {
#endif /* NO_PROTO */
	    goto L290;
	}
/* crossed y-axis */
	cursgn = -cursgn;
/* last two points (cur and prev) determine whether crossing above */
/* or below px,py: */
	pt2cof_(&xcur, &ycur, &xprev, &yprev, &a, &b, &c);
/* formula for y-intercept of line:a,b,c and line:x=px */
	yint = -(doublereal)(a * *px + c) / b;
	if (yint > *py) {
	    ++icross;
	} else if (yint == *py) {
/* aha - on edge after all .. */
	    ret_val = 2;
	    return ret_val;
	}
L290:
	xprev = xcur;
	yprev = ycur;
/* L300: */
    }
    ret_val = 3 - (icross % 2 << 1);
    return ret_val;
} /* inarea_ */

