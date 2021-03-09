/* coleql.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical coleql_(integer *size, real *act, real *exp__, real *abserr, real *
	relerr)
#else /* NO_PROTO */
logical coleql_(size, act, exp__, abserr, relerr)
integer *size;
real *act, *exp__, *abserr, *relerr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */

/*  Special purpose routine for testing approximate equality of */
/*  all three color components, unless one is -1. */
/*  Input parameters: */
/*    SIZE    : Number of elements to be compared */
/*    ACT     : actual values */
/*    EXP     : expected values */
/*    ABSERR  : absolute tolerance */
/*    RELERR  : relative tolerance */
    /* Parameter adjustments */
    --exp__;
    --act;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	if (act[ix] == -1.f || exp__[ix] == -1.f) {
#else /* NO_PROTO */
	if (act[ix] == (float)-1. || exp__[ix] == (float)-1.) {
#endif /* NO_PROTO */
/* OK so far */
	} else if (appeq_(&act[ix], &exp__[ix], abserr, relerr)) {
/* OK so far */
	} else {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* coleql_ */

