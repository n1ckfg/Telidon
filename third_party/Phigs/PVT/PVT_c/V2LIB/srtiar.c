/* srtiar.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int srtiar_(integer *siz, integer *arr)
#else /* NO_PROTO */
/* Subroutine */ int srtiar_(siz, arr)
integer *siz, *arr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i, j, tmp;

/*  SRTIAR sorts an integer array in place, into ascending order. */

/*  Input parameter: */
/*    SIZ : number of elements in array to be sorted. */
/*  Input/output parameter: */
/*    ARR : the array of integers to be sorted. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    i__1 = *siz - 1;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *siz;
	for (j = i + 1; j <= i__2; ++j) {
	    if (arr[i] > arr[j]) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* srtiar_ */

