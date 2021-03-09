/* idmat.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int idmat_(integer *sz, real *mat)
#else /* NO_PROTO */
/* Subroutine */ int idmat_(sz, mat)
integer *sz;
real *mat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer mat_dim1, mat_offset, i__1, i__2;

    /* Local variables */
    static integer i, j;

/* General purpose routine to initialize a square matrix to */
/* the identity matrix. */
    /* Parameter adjustments */
    mat_dim1 = *sz;
    mat_offset = mat_dim1 + 1;
    mat -= mat_offset;

    /* Function Body */
    i__1 = *sz;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *sz;
	for (j = 1; j <= i__2; ++j) {
	    if (i == j) {
#ifndef NO_PROTO
		mat[i + j * mat_dim1] = 1.f;
#else /* NO_PROTO */
		mat[i + j * mat_dim1] = (float)1.;
#endif /* NO_PROTO */
	    } else {
#ifndef NO_PROTO
		mat[i + j * mat_dim1] = 0.f;
#else /* NO_PROTO */
		mat[i + j * mat_dim1] = (float)0.;
#endif /* NO_PROTO */
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* idmat_ */

