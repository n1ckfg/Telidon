/* opcomt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int opcomt_(void)
#else /* NO_PROTO */
/* Subroutine */ int opcomt_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int opco_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opco_();
#endif /* NO_PROTO */

/*  OPCOMT allows the operator to enter a character string as a */
/*  comment, by using OPCO.  No presumption is made about passing */
/*  or failing. */
    opco_(" ", 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opcomt_ */

