/* ndmw.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int ndmw_(real *reqmw, real *nommw)
#else /* NO_PROTO */
/* Subroutine */ int ndmw_(reqmw, nommw)
real *reqmw, *nommw;
#endif /* NO_PROTO */
{
    static real ndmwsc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmksc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmksc ();
#endif /* NO_PROTO */

/*  NDMW attempts to set marker size to a requested value, but not */
/*  near the default (=1). */

/*  Input parameters: */
/*    REQMW       : requested marker size(WC)- actual will be no greater 
*/
/*    NOMMW       : nominal marker size */
/*  get requested scale factor */
    ndmwsc = *reqmw / (*nommw * dialog_1.wcpdc);
#ifndef NO_PROTO
    if (.95f < ndmwsc && ndmwsc < 1.05f) {
#else /* NO_PROTO */
    if ((float).95 < ndmwsc && ndmwsc < (float)1.05) {
#endif /* NO_PROTO */
/*  default near maximum requested - set down by 25% */
#ifndef NO_PROTO
	ndmwsc *= .75f;
#else /* NO_PROTO */
	ndmwsc *= (float).75;
#endif /* NO_PROTO */
    }
    nsmksc (&ndmwsc);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ndmw_ */

