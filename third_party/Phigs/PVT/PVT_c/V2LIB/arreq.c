/* arreq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical arreq_(integer *szx, integer *szy, integer *iax, integer *iay, 
	integer *dx, integer *dy, integer *a, integer *b)
#else /* NO_PROTO */
logical arreq_(szx, szy, iax, iay, dx, dy, a, b)
integer *szx, *szy, *iax, *iay, *dx, *dy, *a, *b;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2;
    logical ret_val;

    /* Local variables */
    static integer i, j;

/* Input parameters - */
/*    szx, szy: declared size of 2D INTEGER arrays a and b; */
/*    iax, iay: initial column and row for array a; */
/*    dx,  dy:  number of columns and rows used; */
/*    a,   b:   2D INTEGER arrays. */
/*  Arreq compares the (DX x DY) contents of the two arrays, */
/*  A starting at (iax, iay) and B starting at (1,1). */
/*  If they contain the same elements in exact order, arreq */
/*  returns .true. else .false. */
/*  local variables to control loops */
    /* Parameter adjustments */
    b_dim1 = *szx;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    a_dim1 = *szx;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *dx;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *dy;
	for (j = 1; j <= i__2; ++j) {
	    if (a[*iax + i - 1 + (*iay + j - 1) * a_dim1] != b[i + j * b_dim1]
		    ) {
		ret_val = FALSE_;
		return ret_val;
	    }
/* L199: */
	}
/* L200: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* arreq_ */

