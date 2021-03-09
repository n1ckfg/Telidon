/* opcofl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int opcofl_(void)
#else /* NO_PROTO */
/* Subroutine */ int opcofl_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int opco_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opco_();
#endif /* NO_PROTO */

/*  OPCOFL allows the operator to enter a character string as a */
/*  comment, by using OPCO.  The comment is made in anticipation */
/*  of failure of the current test case. */
    opco_("on failure", 10L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opcofl_ */

