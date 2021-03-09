/* modsep.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal modsep_(real *period, real *a, real *b)
#else /* NO_PROTO */
doublereal modsep_(period, a, b)
real *period, *a, *b;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val, r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    double r_mod(real *, real *);
#else /* NO_PROTO */
    double r_mod();
#endif /* NO_PROTO */

    /* Local variables */
    static real am, bm, abdif;

/*  Given a period and two values, a and b, modsep calculates the */
/*  absolute value of the smallest "distance" between the values, */
/*  treating them as points on a circle with circumference of size = */
/*  period.  For example, if period=360, as for degree-measure, */
/*  modsep of 5 and 15 would of course be 10, but so would modsep of */
/*  5 and 355, or 0 and 710, or 0 and 730. */
#ifndef NO_PROTO
    if (*period == 0.f) {
	ret_val = 0.f;
#else /* NO_PROTO */
    if (*period == (float)0.) {
	ret_val = (float)0.;
#endif /* NO_PROTO */
	return ret_val;
    }
/* get normalized mod-values - correct for loopy way Fortran */
/* mods negative numbers. */
    am = r_mod(a, period);
#ifndef NO_PROTO
    if (*a < 0.f) {
#else /* NO_PROTO */
    if (*a < (float)0.) {
#endif /* NO_PROTO */
	am += *period;
    }
    bm = r_mod(b, period);
#ifndef NO_PROTO
    if (*b < 0.f) {
#else /* NO_PROTO */
    if (*b < (float)0.) {
#endif /* NO_PROTO */
	bm += *period;
    }
/* now:   0 .le. am,bm  .lt. period */
    abdif = (r__1 = am - bm, dabs(r__1));
/* Computing MIN */
    r__1 = abdif, r__2 = *period - abdif;
    ret_val = dmin(r__1,r__2);
    return ret_val;
} /* modsep_ */

