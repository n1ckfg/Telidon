/* cpyiar.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int cpyiar_(integer *size, real *from, real *to)
#else /* NO_PROTO */
/* Subroutine */ int cpyiar_(size, from, to)
integer *size;
real *from, *to;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i;

/*  CPYIAR copies the contents of an array of a given size to */
/*  another array. */
/*  Input parameters: */
/*    SIZE : number of elements to copy */
/*    TO   : source array */
/*  Output parameter: */
/*    FROM : destination array */
    /* Parameter adjustments */
    --to;
    --from;

    /* Function Body */
    i__1 = *size;
    for (i = 1; i <= i__1; ++i) {
	to[i] = from[i];
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* cpyiar_ */

