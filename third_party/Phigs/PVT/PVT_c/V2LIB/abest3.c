/* abest3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer abest3_(real *aa, real *ba, real *ca)
#else /* NO_PROTO */
integer abest3_(aa, ba, ca)
real *aa, *ba, *ca;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static real a, b, c, best;

/*  function to pick greatest magnitude of 3 numbers */
    a = dabs(*aa);
    b = dabs(*ba);
    c = dabs(*ca);
    if (a > b) {
	ret_val = 1;
	best = a;
    } else {
	ret_val = 2;
	best = b;
    }
    if (c > best) {
	ret_val = 3;
    }
    return ret_val;
} /* abest3_ */

