/* ranary.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b4 = .5f;
static real c_b5 = 1.5f;
#else /* NO_PROTO */
static real c_b4 = (float).5;
static real c_b5 = (float)1.5;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int ranary_(integer *size, real *array)
#else /* NO_PROTO */
/* Subroutine */ int ranary_(size, array)
integer *size;
real *array;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer array_dim1, array_offset, i__1, i__2;

    /* Local variables */
    static integer i, j;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */

/*  RANARY initializes a 2D array of size x size to random values */
/*  between 0.5 and 1.5 */
    /* Parameter adjustments */
    array_dim1 = *size;
    array_offset = array_dim1 + 1;
    array -= array_offset;

    /* Function Body */
    i__1 = *size;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *size;
	for (j = 1; j <= i__2; ++j) {
	    array[i + j * array_dim1] = rndrl_(&c_b4, &c_b5);
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ranary_ */

