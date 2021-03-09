/* fort/04/02/04/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.02/05                        * */
/*  *    TEST TITLE : Appearance of character expansion     * */
/*  *                 factor for STRING and CHAR precision  * */
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
    extern /* Subroutine */ int pass_(void), endit_(void), initgl_(char *, 
	    ftnlen), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_(), initgl_(), setmsg_();
#endif /* NO_PROTO */

    initgl_("04.02.04.02/05", 14L);
#ifndef NO_PROTO
    setmsg_("12 20 21 22 24 25 26", "Test cases for the visual effect of the"
	    " approximated annotation text attribute character expansion fact"
	    "or in STRING and CHAR precision are not yet available.", 20L, 
	    157L);
#else /* NO_PROTO */
    setmsg_("12 20 21 22 24 25 26", "Test cases for the visual effect of the\
 approximated annotation text attribute character expansion factor in STRING\
 and CHAR precision are not yet available.", 20L, 157L);
#endif /* NO_PROTO */
    pass_();
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

