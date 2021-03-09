/* arrtp3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int arrtp3_(integer *nsz, real *xi, real *yi, real *zi, real 
	*xfrmt, real *xo, real *yo, real *zo)
#else /* NO_PROTO */
/* Subroutine */ int arrtp3_(nsz, xi, yi, zi, xfrmt, xo, yo, zo)
integer *nsz;
real *xi, *yi, *zi, *xfrmt, *xo, *yo, *zo;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_();
#endif /* NO_PROTO */

/*  This subroutine transforms a list of 3D points according to the */
/*  given matrix. */
/*  Input parameters: */
/*    NSZ      : number of points */
/*    XI,YI,ZI : points to be transformed */
/*    XFRMT    : matrix containing transformation */
/*  Output parameters: */
/*    XO,YO,ZO : points after being transformed */
    /* Parameter adjustments */
    --zo;
    --yo;
    --xo;
    xfrmt -= 5;
    --zi;
    --yi;
    --xi;

    /* Function Body */
    i__1 = *nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	etp3_(&xi[ix], &yi[ix], &zi[ix], &xfrmt[5], &xo[ix], &yo[ix], &zo[ix])
		;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* arrtp3_ */

