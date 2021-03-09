/* wcnpc.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    real picl, picr, picb, pict, prtl, prtr, prtb, prtt, echl, echr, echb, 
	    echt;
} scrfmt_;

#define scrfmt_1 scrfmt_

#ifndef NO_PROTO
/* Subroutine */ int wcnpc_(real *wcx, real *wcy, real *npcx, real *npcy, 
	real *npcpwc)
#else /* NO_PROTO */
/* Subroutine */ int wcnpc_(wcx, wcy, npcx, npcy, npcpwc)
real *wcx, *wcy, *npcx, *npcy, *npcpwc;
#endif /* NO_PROTO */
{
/*  WCNPC converts a 2D point in WC to the equivalent point in NPC */
/*  within view#1 for the picture area, which maps 0:1,0:1 (WC) to */
/*  PICL:PICR, PICB:PICT (NPC).  It also returns the NPC/WC ratio. */
    *npcx = *wcx * (scrfmt_1.picr - scrfmt_1.picl) + scrfmt_1.picl;
    *npcy = *wcy * (scrfmt_1.pict - scrfmt_1.picb) + scrfmt_1.picb;
    *npcpwc = scrfmt_1.pict - scrfmt_1.picb;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* wcnpc_ */

