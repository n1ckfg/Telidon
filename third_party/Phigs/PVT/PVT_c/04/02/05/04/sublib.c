/* fort/04/02/05/04/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.02.05.04/patavl                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical patavl_(integer *specwt)
#else /* NO_PROTO */
logical patavl_(specwt)
integer *specwt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer isi;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, naints, thisis;

/*  PATAVL tests whether the PATTERN interior style is available for */
/*  a given workstation type. */
/* interior style */
/* <inquire interior facilities> to determine if pattern is supported: */
/*  naints = number of available interior styles */
    nqif (specwt, &c__0, &c__0, &errind, &naints, &idum1, &idum2, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
/* loop thru list of available interior styles till find PPATTR */
    i__1 = naints;
    for (isi = 1; isi <= i__1; ++isi) {
	nqif (specwt, &isi, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis == 2) {
	    ret_val = TRUE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = FALSE_;
    return ret_val;
} /* patavl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.02.05.04/arreq                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

