/* asfset.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int asfset_(integer *asfix, integer *asftab, integer *start, 
	integer *end)
#else /* NO_PROTO */
/* Subroutine */ int asfset_(asfix, asftab, start, end)
integer *asfix, *asftab, *start, *end;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf ();
#endif /* NO_PROTO */

/*  ASFSET is used to set a sequence of ASFs to values specified in */
/*  an indicated row of the ASF table. */
/*  Input parameters: */
/*    ASFIX     : the row (1-5) of the table from which values are taken 
*/
/*    ASFTAB    : table containing ASF values */
/*    START,END : first,last column in the table (corresponding to aspect 
*/
/*                identifier) from which values are taken. */
/* aspect identifier */
    /* Parameter adjustments */
    --asftab;

    /* Function Body */
    i__1 = *end;
    for (ix = *start; ix <= i__1; ++ix) {
	nsiasf (&ix, &asftab[*asfix + ix * 5]);
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* asfset_ */

