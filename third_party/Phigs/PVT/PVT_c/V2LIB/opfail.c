/* opfail.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int opfail_(void)
#else /* NO_PROTO */
/* Subroutine */ int opfail_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), opcofl_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), opcofl_();
#endif /* NO_PROTO */

/*  OPFAIL allows the operator to enter a character string as a */
/*  comment, by using OPCO, and then issues a failure. */
    opcofl_();
    fail_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opfail_ */

