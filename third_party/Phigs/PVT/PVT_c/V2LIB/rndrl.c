/* rndrl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal rndrl_(real *lo, real *hi)
#else /* NO_PROTO */
doublereal rndrl_(lo, hi)
real *lo, *hi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern doublereal rnd01_(void);
#else /* NO_PROTO */
    extern doublereal rnd01_();
#endif /* NO_PROTO */

/*  RNDRL returns a random real number, X, uniformly distributed, */
/*  such that LO .LE. X .LT. HI. */
    ret_val = rnd01_() * (*hi - *lo) + *lo;
    return ret_val;
} /* rndrl_ */

