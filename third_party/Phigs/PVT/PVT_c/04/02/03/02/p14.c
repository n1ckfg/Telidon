/* fort/04/02/03/02/p14.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/14                        * */
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

    initgl_("04.02.03.02/14", 14L);
#ifndef NO_PROTO
    setmsg_("39 47 48 49 57 58 59", "Test cases for the visual effect of the"
	    " approximated text attribute character expansion factor in STRIN"
	    "G and CHAR precision are not yet available.", 20L, 146L);
#else /* NO_PROTO */
    setmsg_("39 47 48 49 57 58 59", "Test cases for the visual effect of the\
 approximated text attribute character expansion factor in STRING and CHAR p\
recision are not yet available.", 20L, 146L);
#endif /* NO_PROTO */
    pass_();
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

