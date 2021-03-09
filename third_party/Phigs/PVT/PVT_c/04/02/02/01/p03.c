/* fort/04/02/02/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.01/03                        * */
/*  *    TEST TITLE : Combinations of individual attributes * */
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
    extern /* Subroutine */ int endit_(void), initgl_(char *, ftnlen), 
	    pmattr_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), initgl_(), pmattr_();
#endif /* NO_PROTO */

    initgl_("04.02.02.01/03", 14L);
    pmattr_("c", 1L);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

