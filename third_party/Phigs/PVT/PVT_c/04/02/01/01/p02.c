/* fort/04/02/01/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.01/02                        * */
/*  *    TEST TITLE : Appearance of individual attributes   * */
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
	    plattr_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), initgl_(), plattr_();
#endif /* NO_PROTO */

    initgl_("04.02.01.01/02", 14L);
    plattr_("i", 1L);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

