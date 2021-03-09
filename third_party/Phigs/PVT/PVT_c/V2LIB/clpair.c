/* clpair.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int clpair_(real *xwinlo, real *ywinlo, real *xsize, real *
	ysize, integer *iwx, real *delta, real *zval)
#else /* NO_PROTO */
/* Subroutine */ int clpair_(xwinlo, ywinlo, xsize, ysize, iwx, delta, zval)
real *xwinlo, *ywinlo, *xsize, *ysize;
integer *iwx;
real *delta, *zval;
#endif /* NO_PROTO */
{
    static real xa[2], ya[2], za[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */

/*  CLPAIR draws a double polymarker in the middle of the requested */
/*  window, one just in front and one just behind a given z-value, so */
/*  that exactly one of the pair will be clipped. */
/*  Input parameters: */
/*    XWINLO,YWINLO : List of locations of lower-left window corners */
/*    XSIZE,YSIZE   : Window size */
/*    IWX           : Index into window list; which window to draw in */
/*   DELTA         : offset in X and Z dimension from nominal window cente
r*/
/*   ZVAL          : nominal Z location = z-value of expected clipping pla
ne*/
    /* Parameter adjustments */
    --ywinlo;
    --xwinlo;

    /* Function Body */
    xa[0] = xwinlo[*iwx] + *xsize / 2 - *delta;
    ya[0] = ywinlo[*iwx] + *ysize / 2;
    za[0] = *zval - *delta;
    xa[1] = xwinlo[*iwx] + *xsize / 2 + *delta;
    ya[1] = ywinlo[*iwx] + *ysize / 2;
    za[1] = *zval + *delta;
    npm3 (&c__2, xa, ya, za);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* clpair_ */

