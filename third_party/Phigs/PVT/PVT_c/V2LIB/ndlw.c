/* ndlw.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

#ifndef NO_PROTO
/* Subroutine */ int ndlw_(real *reqlw, real *nomlw, real *minlw)
#else /* NO_PROTO */
/* Subroutine */ int ndlw_(reqlw, nomlw, minlw)
real *reqlw, *nomlw, *minlw;
#endif /* NO_PROTO */
{
    static real ndlwsc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslwsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslwsc ();
#endif /* NO_PROTO */

/*  NDLW attempts to set linewidth to a requested value, but not */
/*  near the default (=1). */

/*  Input parameters: */
/*    REQLW  : requested linewidth - actual will be no greater */
/*    NOMLW  : nominal linewidth */
/*    MINLW  : minimum linewidth */
#ifndef NO_PROTO
    if (.98f < ndlwsc && ndlwsc < 1.02f) {
#else /* NO_PROTO */
    if ((float).98 < ndlwsc && ndlwsc < (float)1.02) {
#endif /* NO_PROTO */
/*  default near maximum requested - set to min */
	ndlwsc = *minlw / *nomlw;
    } else {
/*  get requested scale factor */
	ndlwsc = *reqlw / (*nomlw * dialog_1.wcpdc);
    }
    nslwsc (&ndlwsc);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ndlw_ */

