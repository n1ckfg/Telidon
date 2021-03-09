/* prsint.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int prsint_(char *str, integer *ival, integer *ierr, ftnlen 
	str_len)
#else /* NO_PROTO */
/* Subroutine */ int prsint_(str, ival, ierr, str_len)
char *str;
integer *ival, *ierr;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
#else /* NO_PROTO */
    integer i_indx(), i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static integer lst, isign;
#ifndef NO_PROTO
    extern /* Subroutine */ int prsuin_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int prsuin_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  Prsint parses a possibly signed integer.  Assumes no leading spaces. 
*/
/*  The value is returned in IVAL, and IERR gets a non-zero code if */
/*  something goes wrong. */
    isign = i_indx("+-", str, 2L, 1L);
    lst = i_len(str, str_len);
    if (isign == 0) {
/* unsigned */
	prsuin_(str, ival, ierr, str_len);
    } else {
/* signed */
	if (lst <= 1) {
/* no digits */
	    *ierr = 50;
	} else {
	    prsuin_(str + 1, ival, ierr, str_len - 1);
	    if (isign == 2) {
		*ival = -(*ival);
	    }
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prsint_ */

