/* appeq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical appeq_(real *act, real *exp__, real *abserr, real *relerr)
#else /* NO_PROTO */
logical appeq_(act, exp__, abserr, relerr)
real *act, *exp__, *abserr, *relerr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;
    logical ret_val;

    /* Local variables */
    static real abdif;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  General purpose routine for approximate equality of two real-numbers. 
*/
/*  The 1st parameter is the actual value, the 2nd, the expected value. */

/*  Tests as true iff: */
/*     1. absolute error of act wrt exp .le. abserr, OR */
/*     2. relative error of act wrt exp .le. relerr */
#ifndef NO_PROTO
    if (*abserr < 0.f || *relerr < 0.f) {
#else /* NO_PROTO */
    if (*abserr < (float)0. || *relerr < (float)0.) {
#endif /* NO_PROTO */
	unmsg_("Negative tolerance passed to APPEQ.", 35L);
    }
    abdif = (r__1 = *act - *exp__, dabs(r__1));
/* note that this expression is "safe" even if act or exp is zero. */
    ret_val = abdif <= *abserr || abdif <= (r__1 = *relerr * *exp__, dabs(
	    r__1));
    return ret_val;
} /* appeq_ */

