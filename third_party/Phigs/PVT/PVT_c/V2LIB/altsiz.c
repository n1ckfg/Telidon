/* altsiz.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int altsiz_(real *expdc, real *minsiz, real *maxsiz, integer 
	*maxalt, integer *numalt, real *alt)
#else /* NO_PROTO */
/* Subroutine */ int altsiz_(expdc, minsiz, maxsiz, maxalt, numalt, alt)
real *expdc, *minsiz, *maxsiz;
integer *maxalt, *numalt;
real *alt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
    static real nxl1, nxl2, nxs1, nxs2;

/*  ALTSIZ finds nearby alternate sizes, to the expected size, and */
/*  returns them to the caller.  The alternates fulfill all these */
/*  conditions: 1) each differs from all the others by at least 25% */
/*  (relative) and by MINSIZ (absolute), and 2) each is no less than */
/*  MINSIZ, and no greater than MAXSIZ. */
/*  Input parameters: */
/*    EXPDC  : Expected size; always the first entry in ALT */
/*   MINSIZ : Minimum size for an entry and for difference between entries
*/
/*    MAXSIZ : Maximum size for an entry */
/*   MAXALT : Maximum number of alternatives to be returned (including EXP
DC)*/
/*  Output parameters: */
/*    NUMALT : Actual number of alternatives returned */
/*    ALT    : List of alternative sizes */
    /* Parameter adjustments */
    --alt;

    /* Function Body */
    *numalt = 1;
    alt[*numalt] = *expdc;
    nxl1 = *expdc;
    nxs1 = *expdc;
/*  generate alternative sizes - must differ by at least 25% *and* MINSIZ 
*/
    i__1 = *maxalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  generate larger choices */
#ifndef NO_PROTO
	nxl2 = nxl1 * 1.25f;
#else /* NO_PROTO */
	nxl2 = nxl1 * (float)1.25;
#endif /* NO_PROTO */
	if (nxl2 - nxl1 < *minsiz) {
	    nxl2 = nxl1 + *minsiz;
	}
	if (nxl2 <= *maxsiz) {
	    ++(*numalt);
	    alt[*numalt] = nxl2;
	    if (*numalt >= *maxalt) {
		return 0;
	    }
	    nxl1 = nxl2;
	}
/*  generate smaller choices */
#ifndef NO_PROTO
	nxs2 = nxs1 / 1.25f;
#else /* NO_PROTO */
	nxs2 = nxs1 / (float)1.25;
#endif /* NO_PROTO */
	if (nxs1 - nxs2 < *minsiz) {
	    nxs2 = nxs1 - *minsiz;
	}
	if (nxs2 >= *minsiz) {
	    ++(*numalt);
	    alt[*numalt] = nxs2;
	    if (*numalt >= *maxalt) {
		return 0;
	    }
	    nxs1 = nxs2;
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* altsiz_ */

