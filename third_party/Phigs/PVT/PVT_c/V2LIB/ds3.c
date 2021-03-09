/* ds3.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int ds3_(real *r1, real *r2, real *r3, real *r4, real *r5, 
	real *r6, real *array)
#else /* NO_PROTO */
/* Subroutine */ int ds3_(r1, r2, r3, r4, r5, r6, array)
real *r1, *r2, *r3, *r4, *r5, *r6, *array;
#endif /* NO_PROTO */
{
/*  Set an array with six real numbers */
    /* Parameter adjustments */
    --array;

    /* Function Body */
    array[1] = *r1;
    array[2] = *r2;
    array[3] = *r3;
    array[4] = *r4;
    array[5] = *r5;
    array[6] = *r6;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ds3_ */

