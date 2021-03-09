/* matmul.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int matmul_(integer *m, integer *n, integer *p, real *a, 
	real *b, real *c)
#else /* NO_PROTO */
/* Subroutine */ int matmul_(m, n, p, a, b, c)
integer *m, *n, *p;
real *a, *b, *c;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Local variables */
    static integer i, j, k;
    static real tot;

/* general purpose matrix multiply - multiplies an MxN array (A) */
/* by a NxP array (B) to yield an MxP array (C). */
    /* Parameter adjustments */
    c_dim1 = *m;
    c_offset = c_dim1 + 1;
    c -= c_offset;
    b_dim1 = *n;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    a_dim1 = *m;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *m;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *p;
	for (j = 1; j <= i__2; ++j) {
#ifndef NO_PROTO
	    tot = 0.f;
#else /* NO_PROTO */
	    tot = (float)0.;
#endif /* NO_PROTO */
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
		tot += a[i + k * a_dim1] * b[k + j * b_dim1];
/* L300: */
	    }
	    c[i + j * c_dim1] = tot;
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* matmul_ */

