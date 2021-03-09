/* e02058.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int e02058_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02058_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02058 tests the handling of error number 58. */
#ifndef NO_PROTO
    setmsg_("8", "Test for error 58 (metafile retrieval from workstation not"
	    " of category MI) not yet available.", 1L, 93L);
#else /* NO_PROTO */
    setmsg_("8", "Test for error 58 (metafile retrieval from workstation not\
 of category MI) not yet available.", 1L, 93L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02058_ */

