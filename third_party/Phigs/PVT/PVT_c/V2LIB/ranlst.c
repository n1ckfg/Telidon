/* ranlst.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

#ifndef NO_PROTO
integer ranlst_(integer *stddx, integer *lavslt, integer *regdx, integer *
	lavrlt, integer *impdx, integer *lavilt)
#else /* NO_PROTO */
integer ranlst_(stddx, lavslt, regdx, lavrlt, impdx, lavilt)
integer *stddx, *lavslt, *regdx, *lavrlt, *impdx, *lavilt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer whlist;

/*  RANLST chooses a linetype at random from the three lists of */
/*  available linetypes. */
    /* Parameter adjustments */
    --lavilt;
    --lavrlt;
    --lavslt;

    /* Function Body */
L100:
    whlist = rndint_(&c__1, &c__3);
    if (whlist == 1) {
	if (*stddx <= 0) {
	    goto L100;
	}
	ret_val = lavslt[rndint_(&c__1, stddx)];
    } else if (whlist == 2) {
	if (*regdx <= 0) {
	    goto L100;
	}
	ret_val = lavrlt[rndint_(&c__1, regdx)];
    } else {
	if (*impdx <= 0) {
	    goto L100;
	}
	ret_val = lavilt[rndint_(&c__1, impdx)];
    }
    return ret_val;
} /* ranlst_ */

