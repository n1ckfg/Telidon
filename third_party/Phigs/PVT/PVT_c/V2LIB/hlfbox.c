/* hlfbox.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;
static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int hlfbox_(real *x1st, real *y1st, real *xinc, real *yinc, 
	char *xy, ftnlen xy_len)
#else /* NO_PROTO */
/* Subroutine */ int hlfbox_(x1st, y1st, xinc, yinc, xy, xy_len)
real *x1st, *y1st, *xinc, *yinc;
char *xy;
ftnlen xy_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    char ch__1[33];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[5], ya[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer ixy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  HLFBOX draws a half-box. */
/*  Input parameters: */
/*    X1ST,Y1ST : starting point */
/*    XINC,YINC : x,y increments */
/*    XY        : switch to determine which increment is to be applied */
/*                first.  X creates a box open at the side, Y creates */
/*                a box open at the top or bottom. */
    if (*xy == 'X') {
	ixy = 2;
    } else if (*xy == 'Y') {
	ixy = 4;
    } else {
/* Writing concatenation */
	i__1[0] = 31, a__1[0] = "HLFBOX called with invalid XY: ";
	i__1[1] = 1, a__1[1] = xy;
	i__1[2] = 1, a__1[2] = ".";
	s_cat(ch__1, a__1, i__1, &c__3, 33L);
	unmsg_(ch__1, 33L);
    }
    xa[0] = *x1st;
    ya[0] = *y1st;
    xa[2] = *x1st + *xinc;
    ya[2] = *y1st + *yinc;
    xa[ixy - 1] = xa[2];
    ya[ixy - 1] = ya[0];
    xa[6 - ixy - 1] = xa[0];
    ya[6 - ixy - 1] = ya[2];
    npl (&c__4, xa, ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* hlfbox_ */

