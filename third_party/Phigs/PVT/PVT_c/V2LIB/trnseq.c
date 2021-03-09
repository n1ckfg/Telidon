/* trnseq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b4 = 1e-7f;
static real c_b5 = 1e-4f;
#else /* NO_PROTO */
static real c_b4 = (float)1e-7;
static real c_b5 = (float)1e-4;
#endif /* NO_PROTO */

#ifndef NO_PROTO
logical trnseq_(integer *sz, real *actmat, real *expmat)
#else /* NO_PROTO */
logical trnseq_(sz, actmat, expmat)
integer *sz;
real *actmat, *expmat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer actmat_dim1, actmat_offset, expmat_dim1, expmat_offset, i__1, 
	    i__2;
    real r__1, r__2;
    logical ret_val;

    /* Local variables */
    static integer i, j;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real ascale, bscale;

/*  Test two square matrices to see if they represent the same homogeneous
 */
/*  transformation.  Each transformation has an infinite number of */
/*  representations, because the matrix is scaled by element (sz,sz). */
    /* Parameter adjustments */
    expmat_dim1 = *sz;
    expmat_offset = expmat_dim1 + 1;
    expmat -= expmat_offset;
    actmat_dim1 = *sz;
    actmat_offset = actmat_dim1 + 1;
    actmat -= actmat_offset;

    /* Function Body */
    ascale = actmat[*sz + *sz * actmat_dim1];
    bscale = expmat[*sz + *sz * expmat_dim1];
#ifndef NO_PROTO
    if (ascale * bscale == 0.f) {
#else /* NO_PROTO */
    if (ascale * bscale == (float)0.) {
#endif /* NO_PROTO */
/* at least one is zero */
	if (ascale == bscale) {
/* both are zero - set to 1.0 - both matrices represent transforma
tion to */
/* points at infinity */
#ifndef NO_PROTO
	    ascale = 1.f;
	    bscale = 1.f;
#else /* NO_PROTO */
	    ascale = (float)1.;
	    bscale = (float)1.;
#endif /* NO_PROTO */
	} else {
/* one zero and one not - */
	    ret_val = FALSE_;
	    return ret_val;
	}
    }
    i__1 = *sz;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *sz;
	for (j = 1; j <= i__2; ++j) {
	    r__1 = actmat[i + j * actmat_dim1] / ascale;
	    r__2 = expmat[i + j * expmat_dim1] / bscale;
	    if (! appeq_(&r__1, &r__2, &c_b4, &c_b5)) {
		ret_val = FALSE_;
		return ret_val;
	    }
/* L200: */
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* trnseq_ */

