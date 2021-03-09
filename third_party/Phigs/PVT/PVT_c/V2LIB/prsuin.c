/* prsuin.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int prsuin_(char *str, integer *ival, integer *ierr, ftnlen 
	str_len)
#else /* NO_PROTO */
/* Subroutine */ int prsuin_(str, ival, ierr, str_len)
char *str;
integer *ival, *ierr;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, lst, idig, itot;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

/*  Prsuin parses an unsigned integer.  Assumes no leading spaces. */
/*  The value is returned in IVAL, and IERR gets a non-zero code if */
/*  something goes wrong. */
    lst = itrim_(str, str_len);
    if (lst <= 0) {
	*ierr = 2;
	return 0;
    }
    itot = 0;
    i__1 = lst;
    for (i = 1; i <= i__1; ++i) {
	idig = i_indx("0123456789", str + (i - 1), 10L, 1L) - 1;
	if (idig >= 0 && idig <= 9) {
	    itot = itot * 10 + idig;
	} else {
	    *ierr = 1;
	    return 0;
	}
/* L100: */
    }
    *ierr = 0;
    *ival = itot;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prsuin_ */

