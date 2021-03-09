/* chkelp.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int chkelp_(integer *elpos)
#else /* NO_PROTO */
/* Subroutine */ int chkelp_(elpos)
integer *elpos;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), nqep (integer *, integer *), 
	    pass_(void), nsep (integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), nqep (), pass_(), nsep (), chkinq_();
#endif /* NO_PROTO */

    static integer errind, actpos;

/*  Chkelp checks whether or not the current actual element position */
/*  equals the expected position, as indicated by the parameter, */
/*  and issues pass or fail as appropriate.  In the case of */
/*  failure, it attempts to re-set the pointer to the correct value. */
    nqep (&errind, &actpos);
    chkinq_("pqep", &errind, 4L);
    if (*elpos == actpos) {
	pass_();
    } else {
	fail_();
	nsep (elpos);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkelp_ */

