/* seteq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical seteq_(integer *n, integer *a, integer *b)
#else /* NO_PROTO */
logical seteq_(n, a, b)
integer *n, *a, *b;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;
    logical ret_val;

    /* Local variables */
    static integer i, j, wk[5000];
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer wkleft;

/*  seteq compares the contents of the first N elements of two */
/*  arrays, A and B.  If they contain the same elements *in any */
/*  order*, seteq returns .true., else .false. */
    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    if (*n > 5000) {
	unmsg_("Size of array passed to SETEQ exceeds size of work area.", 
		56L);
    }
/* save contents of B in WK, so as not to clobber B */
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	wk[i - 1] = b[i];
/* L50: */
    }
    wkleft = *n;
/* check all elements of A */
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
/* against remaining elements of WK */
	i__2 = wkleft;
	for (j = 1; j <= i__2; ++j) {
	    if (a[i] == wk[j - 1]) {
		wk[j - 1] = wk[wkleft - 1];
		--wkleft;
		goto L100;
	    }
/* L200: */
	}
	ret_val = FALSE_;
	return ret_val;
L100:
	;
    }
    ret_val = TRUE_;
    return ret_val;
} /* seteq_ */

