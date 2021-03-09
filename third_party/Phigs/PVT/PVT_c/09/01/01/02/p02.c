/* fort/09/01/01/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01.01.02/02                        * */
/*  *    TEST TITLE : Error 2 handled by system             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), initgl_(
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), initgl_();
#endif /* NO_PROTO */

    initgl_("09.01.01.02/02", 14L);
#ifndef NO_PROTO
    inmsg_("No test performed, because the standard does not specify the eff"
	    "ect of signalling an error when PHIGS is closed and the default "
	    "system error handler is in effect.", 162L);
#else /* NO_PROTO */
    inmsg_("No test performed, because the standard does not specify the eff\
ect of signalling an error when PHIGS is closed and the default system error\
 handler is in effect.", 162L);
#endif /* NO_PROTO */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

