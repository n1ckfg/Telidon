/* setasf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int setasf_(integer *flag__)
#else /* NO_PROTO */
/* Subroutine */ int setasf_(flag__)
integer *flag__;
#endif /* NO_PROTO */
{
    static integer aspect;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf ();
#endif /* NO_PROTO */

/*  SETASF sets all ASF flags to the same value, either individual or */
/*  bundled. */
/* aspect identifier */
    for (aspect = 0; aspect <= 17; ++aspect) {
	nsiasf (&aspect, flag__);
/* L50: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setasf_ */

