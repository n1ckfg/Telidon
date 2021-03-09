/* exedv.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int exedv_(char *vxstr, real *xexp, real *yexp, ftnlen 
	vxstr_len)
#else /* NO_PROTO */
/* Subroutine */ int exedv_(vxstr, xexp, yexp, vxstr_len)
char *vxstr;
real *xexp, *yexp;
ftnlen vxstr_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[20], ya[20];
    static integer ix, vx[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), setvs_(char *
	    , integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), setvs_();
#endif /* NO_PROTO */
    static integer vxsiz;

/*  EXEDV draws a polyline using the indicated elements of the */
/*  arrays of expected vertices. */
/*  Input parameters: */
/*    VXSTR     : Positions in array to use as vertices */
/*    XEXP,YEXP : Array of expected vertices from which values are taken 
*/
    /* Parameter adjustments */
    --yexp;
    --xexp;

    /* Function Body */
    setvs_(vxstr, vx, &vxsiz, vxstr_len);
    i__1 = vxsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[ix - 1] = xexp[vx[ix - 1]];
	ya[ix - 1] = yexp[vx[ix - 1]];
/* L100: */
    }
    npl (&vxsiz, xa, ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* exedv_ */

