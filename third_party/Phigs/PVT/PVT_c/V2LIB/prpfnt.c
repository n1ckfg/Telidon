/* prpfnt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int prpfnt_(integer *specwt, integer *bestfn)
#else /* NO_PROTO */
/* Subroutine */ int prpfnt_(specwt, bestfn)
integer *specwt, *bestfn;
#endif /* NO_PROTO */
{
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int subfnt_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int subfnt_();
#endif /* NO_PROTO */

/*  PRPFNT looks for a stroke text font other than 1, preferably not */
/*  #2 and not monospaced. */
/*  Input parameters: */
/*    SPECWT : workstation type */
/*  Output parameters: */
/*    BESTFN : selected font */
    subfnt_(specwt, bestfn, &rdum1, &rdum2, &rdum3, &rdum4);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prpfnt_ */

