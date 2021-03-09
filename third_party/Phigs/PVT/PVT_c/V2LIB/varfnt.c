/* varfnt.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int varfnt_(integer *bestfn, real *ncbhtw, real *ncbwdw, 
	real *ncbhti, real *ncbwdi)
#else /* NO_PROTO */
/* Subroutine */ int varfnt_(bestfn, ncbhtw, ncbwdw, ncbhti, ncbwdi)
integer *bestfn;
real *ncbhtw, *ncbwdw, *ncbhti, *ncbwdi;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int subfnt_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int subfnt_();
#endif /* NO_PROTO */

/*  VARFNT looks for a stroke text font other than 1, preferably not */
/*  #2 and not monospaced, and returns nominal size for "W" and "i". */
/*  Output parameters: */
/*    BESTFN        : selected font */
/*    NCBHTW,NCBWDW : nominal height, width of "W" in selected font */
/*    NCBHTI,NCBWDI : nominal height, width of "i" in selected font */
    subfnt_(&dialog_1.specwt, bestfn, ncbhtw, ncbwdw, ncbhti, ncbwdi);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* varfnt_ */

