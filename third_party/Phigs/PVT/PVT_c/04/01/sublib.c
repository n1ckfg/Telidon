/* fort/04/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.01/filrec                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int filrec_(integer *xlo, integer *xhi, integer *ylo, 
	integer *yhi, real *xa, real *ya)
#else /* NO_PROTO */
/* Subroutine */ int filrec_(xlo, xhi, ylo, yhi, xa, ya)
integer *xlo, *xhi, *ylo, *yhi;
real *xa, *ya;
#endif /* NO_PROTO */
{
    static real xv[10], yv[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */

/*  FILREC fills a rectangle based on selected points from an */
/*  x-array and y-array */
/*  Input parameters: */
/*   XLO,XHI,YLO,YHI : index to points for x-low,high and y-low,high value
*/
/*    XA, YA          : array of 2D points from which rectangle */
/*                      bounds are selected */
    /* Parameter adjustments */
    --ya;
    --xa;

    /* Function Body */
    xv[0] = xa[*xlo];
    xv[1] = xa[*xhi];
    xv[2] = xv[1];
    xv[3] = xv[0];
    yv[0] = ya[*ylo];
    yv[2] = ya[*yhi];
    yv[1] = yv[0];
    yv[3] = yv[2];
    nfa (&c__4, xv, yv);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* filrec_ */

