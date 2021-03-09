/* e02060.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int e02060_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02060_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02060 tests the handling of error number 60. */
#ifndef NO_PROTO
    setmsg_("10", "Test for error 60 (using pick on workstation not of categ"
	    "ory OUTIN) not yet available.", 2L, 86L);
#else /* NO_PROTO */
    setmsg_("10", "Test for error 60 (using pick on workstation not of categ\
ory OUTIN) not yet available.", 2L, 86L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02060_ */

