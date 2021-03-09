/* ranmkt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

#ifndef NO_PROTO
integer ranmkt_(integer *stddx, integer *lavsmt, integer *regdx, integer *
	lavrmt, integer *impdx, integer *lavimt)
#else /* NO_PROTO */
integer ranmkt_(stddx, lavsmt, regdx, lavrmt, impdx, lavimt)
integer *stddx, *lavsmt, *regdx, *lavrmt, *impdx, *lavimt;
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

/*  RANMKT chooses a marker type at random from the three lists of */
/*  available marker types. */
    /* Parameter adjustments */
    --lavimt;
    --lavrmt;
    --lavsmt;

    /* Function Body */
L100:
    whlist = rndint_(&c__1, &c__3);
    if (whlist == 1) {
	if (*stddx <= 0) {
	    goto L100;
	}
	ret_val = lavsmt[rndint_(&c__1, stddx)];
/* don't allow marker type 1 (dot) */
	if (ret_val == 1) {
	    goto L100;
	}
    } else if (whlist == 2) {
	if (*regdx <= 0) {
	    goto L100;
	}
	ret_val = lavrmt[rndint_(&c__1, regdx)];
    } else {
	if (*impdx <= 0) {
	    goto L100;
	}
	ret_val = lavimt[rndint_(&c__1, impdx)];
    }
    return ret_val;
} /* ranmkt_ */

