/* intsty.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
logical intsty_(integer *specwt, integer *rqstyl)
#else /* NO_PROTO */
logical intsty_(specwt, rqstyl)
integer *specwt, *rqstyl;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix, nis;
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
    static integer errind, thisis;

/*  INTSTY indicates whether or not a requested interior style is */
/*  available for a workstation type. */

/*  Input parameters: */
/*    SPECWT : workstation type */
/*    RQSTYL : the interior style in question */
    nqif (specwt, &c__0, &c__0, &errind, &nis, &idum1, &idum2, &idum3, &idum4)
	    ;
    chkinq_("pqif", &errind, 4L);
    i__1 = nis;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (specwt, &ix, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis == *rqstyl) {
	    ret_val = TRUE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = FALSE_;
    return ret_val;
} /* intsty_ */

