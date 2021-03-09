/* newstr.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int newstr_(integer *start, integer *newid)
#else /* NO_PROTO */
/* Subroutine */ int newstr_(start, newid)
integer *start, *newid;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/*  NEWSTR searches for a non-existent structure identifier, starting */
/*  with START, and returns it, if found, in NEWID. */
/* structure status indicator */
    i__1 = *start + 100;
    for (ix = *start; ix <= i__1; ++ix) {
	nqstst (&ix, &errind, &strsti);
	chkinq_("pqstst", &errind, 6L);
	if (strsti == 0) {
	    *newid = ix;
	    return 0;
	}
/* L100: */
    }
    unmsg_("NEWSTR cannot find a new structure identifier.", 46L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* newstr_ */

