/* rndint.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer rndint_(integer *lo, integer *hi)
#else /* NO_PROTO */
integer rndint_(lo, hi)
integer *lo, *hi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern doublereal rnd01_(void);
#else /* NO_PROTO */
    extern doublereal rnd01_();
#endif /* NO_PROTO */

/*  RNDINT returns a random integer value between LO and HI, */
/*  inclusive. */
    ret_val = (integer) (rnd01_() * (*hi + 1 - *lo) + *lo);
    return ret_val;
} /* rndint_ */

