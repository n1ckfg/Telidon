/* cldiag.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int cldiag_(real *x1, real *y1, real *x2, real *y2, real *a, 
	real *b, real *c, real *d, real *xl, real *yl, real *xf)
#else /* NO_PROTO */
/* Subroutine */ int cldiag_(x1, y1, x2, y2, a, b, c, d, xl, yl, xf)
real *x1, *y1, *x2, *y2, *a, *b, *c, *d, *xl, *yl, *xf;
#endif /* NO_PROTO */
{
    static real xa[2], ya[2], za[2], zt, xw1, yw1, xw2, yw2, xhi, yhi, xlo, 
	    ylo;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), npl3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), npl3 ();
#endif /* NO_PROTO */
    static real shrink;

/*  CLDIAG accepts the x-y coordinates of 2 MC points, the */
/*  coefficients of a fill area plane, and a transformation from MC */
/*  to WC, and draws the resulting (slightly shrunken) 3D line segment. */


/*  Input parameters: */
/*    X1,Y1, X2,Y2 : MC coordinates of 1st,2nd point */
/*    A,B,C,D      : fill area plane is: a*x + b*y + c*z + d = 0 */
/*    XL,YL        : border of fill area in MC - an aligned rectanlge */
/*    XF           : transformation from MC to WC */
    /* Parameter adjustments */
    xf -= 5;
    --yl;
    --xl;

    /* Function Body */
    xlo = xl[1];
    xhi = xl[3];
    ylo = yl[3];
    yhi = yl[1];
#ifndef NO_PROTO
    shrink = .8f;
#else /* NO_PROTO */
    shrink = (float).8;
#endif /* NO_PROTO */
    xw1 = shrink * *x1 + (1 - shrink) * *x2;
    xw2 = shrink * *x2 + (1 - shrink) * *x1;
    yw1 = shrink * *y1 + (1 - shrink) * *y2;
    yw2 = shrink * *y2 + (1 - shrink) * *y1;
    if (xw1 < xlo || xw1 > xhi || yw1 < ylo || yw1 > yhi || (xw2 < xlo || xw2 
	    > xhi || yw2 < ylo || yw2 > yhi)) {
	return 0;
    }
    zt = -(doublereal)(*a * xw1 + *b * yw1 + *d) / *c;
    etp3_(&xw1, &yw1, &zt, &xf[5], xa, ya, za);
    zt = -(doublereal)(*a * xw2 + *b * yw2 + *d) / *c;
    etp3_(&xw2, &yw2, &zt, &xf[5], &xa[1], &ya[1], &za[1]);
/*  since simulated projection is flat, put in z=0.999 plane */
#ifndef NO_PROTO
    za[0] = .999f;
    za[1] = .999f;
#else /* NO_PROTO */
    za[0] = (float).999;
    za[1] = (float).999;
#endif /* NO_PROTO */
    npl3 (&c__2, xa, ya, za);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* cldiag_ */

