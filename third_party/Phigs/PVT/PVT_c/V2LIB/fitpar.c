/* fitpar.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int fitpar_(char *msgtxt, real *chwrat, real *phwrat, 
	integer *linsiz, ftnlen msgtxt_len)
#else /* NO_PROTO */
/* Subroutine */ int fitpar_(msgtxt, chwrat, phwrat, linsiz, msgtxt_len)
char *msgtxt;
real *chwrat, *phwrat;
integer *linsiz;
ftnlen msgtxt_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static integer err;
    static real chht1, chht2, loghw;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int scapar_(integer *, real *, real *, integer *, 
	    integer *, real *, real *), linbrk_(char *, integer *, integer *, 
	    integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int scapar_(), linbrk_();
#endif /* NO_PROTO */
    static integer lenmsg, minlin, numlin, linpos[300], sizsav;

/*  FITPAR calculates a reasonably good line size (number of characters) 
*/
/*  for fitting MSGTXT into a rectangular area. */
/*  Input parameters: */
/*    MSGTXT : Text to be fit */
/*    CHWRAT : Desired height/width ratio of each character */
/*    PHWRAT : Height/width ratio of area to hold paragraph */
/*  Output parameters: */
/*    LINSIZ : Number of characters per line */
/*  let: */
/*    #chars = #lines * chars-per-line */
/*    char-height = phwrat/#lines */
/*    char-width  = 1/chars-per-line */
/*    char-height/char-width = CHWRAT */
/*  then */
/*    chars-per-line = sqrt(CHWRAT*#chars / phwrat) */
    lenmsg = itrim_(msgtxt, msgtxt_len);
/*  3 is fudge factor, because there won't be perfect packing. */
    *linsiz = sqrt(*chwrat * lenmsg / *phwrat) + 3;
/*  15 is minimum tolerable line-length */
    minlin = 15;
    *linsiz = max(minlin,*linsiz);
/*  Generate line-breaks for LINSIZ: */
    linbrk_(msgtxt, linsiz, &err, &numlin, linpos, msgtxt_len);
/*  get resulting character height */
    scapar_(linsiz, chwrat, phwrat, &numlin, linpos, &chht1, &loghw);
/*  alter LINSIZ for attempted better fit */
    sizsav = *linsiz;
    if (loghw > *phwrat && numlin == 2) {
/*  2-line message is too tall ... force to 1 line */
	*linsiz = lenmsg;
    } else {
/*  try to converge on proper height/width ratio for paragraph */
	*linsiz = *linsiz * loghw / *phwrat;
    }
    *linsiz = max(minlin,*linsiz);
/*  Generate line-breaks for 2nd LINSIZ: */
    linbrk_(msgtxt, linsiz, &err, &numlin, linpos, msgtxt_len);
/*  get 2nd resulting character height */
    scapar_(linsiz, chwrat, phwrat, &numlin, linpos, &chht2, &loghw);
/*  If 2nd attempt generated smaller characters, re-set to 1st, */
/*  otherwise leave LINSIZ as is. */
    if (chht1 > chht2) {
	*linsiz = sizsav;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* fitpar_ */

