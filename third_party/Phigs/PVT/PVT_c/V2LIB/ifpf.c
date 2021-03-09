/* ifpf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ifpf_(logical *cond)
#else /* NO_PROTO */
/* Subroutine */ int ifpf_(cond)
logical *cond;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_();
#endif /* NO_PROTO */

/*  Ifpf simply provides a short form for the typical coding: if */
/*  (condition) then pass else fail. */
    if (*cond) {
	pass_();
    } else {
	fail_();
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ifpf_ */

