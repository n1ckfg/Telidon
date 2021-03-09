/* p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01.11.02/01                        * */
/*  *    TEST TITLE:  Error 2202 handled by system          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/* Main program */ MAIN__()
{
    extern /* Subroutine */ int e12202_(), endit_(), initgl_();

    initgl_("09.01.11.02/01", 14L);
    e12202_(&c__2);
    endit_();
} /* MAIN__ */

