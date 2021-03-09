/* patavl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

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

