/* e02056.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int e02056_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02056_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02056 tests the handling of error number 56. */
#ifndef NO_PROTO
    setmsg_("6", "Test for error 56 (writing to workstation not of category "
	    "MO) not yet available.", 1L, 80L);
#else /* NO_PROTO */
    setmsg_("6", "Test for error 56 (writing to workstation not of category \
MO) not yet available.", 1L, 80L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02056_ */

