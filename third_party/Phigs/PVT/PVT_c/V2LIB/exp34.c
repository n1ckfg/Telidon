/* exp34.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int exp34_(real *mat3, real *mat4)
#else /* NO_PROTO */
/* Subroutine */ int exp34_(mat3, mat4)
real *mat3, *mat4;
#endif /* NO_PROTO */
{
    static integer i, j;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static integer irecv, jrecv;

/*  Expand a 3x3 matrix into a 4x4 matrix. */
    /* Parameter adjustments */
    mat4 -= 5;
    mat3 -= 4;

    /* Function Body */
    idmat_(&c__4, &mat4[5]);
    for (i = 1; i <= 3; ++i) {
	if (i == 3) {
	    irecv = 4;
	} else {
	    irecv = i;
	}
	for (j = 1; j <= 3; ++j) {
	    if (j == 3) {
		jrecv = 4;
	    } else {
		jrecv = j;
	    }
	    mat4[irecv + (jrecv << 2)] = mat3[i + j * 3];
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* exp34_ */

