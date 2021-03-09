/* pass.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int pass_(void)
#else /* NO_PROTO */
/* Subroutine */ int pass_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pf_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pf_();
#endif /* NO_PROTO */

/*  pass handles the processing of a pass-condition. */
    pf_("p", 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pass_ */

