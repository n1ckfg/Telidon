/* pl2ln.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int pl2ln_(real *a1, real *b1, real *c1, real *d1, real *a2, 
	real *b2, real *c2, real *d2, real *a, real *b, real *c, real *px, 
	real *py, real *pz)
#else /* NO_PROTO */
/* Subroutine */ int pl2ln_(a1, b1, c1, d1, a2, b2, c2, d2, a, b, c, px, py, 
	pz)
real *a1, *b1, *c1, *d1, *a2, *b2, *c2, *d2, *a, *b, *c, *px, *py, *pz;
#endif /* NO_PROTO */
{
    static integer ixyz;
#ifndef NO_PROTO
    extern integer abest3_(real *, real *, real *);
    extern /* Subroutine */ int crossp_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *), lintpt_(real *, real *, real *,
	     real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern integer abest3_();
    extern /* Subroutine */ int crossp_(), lintpt_();
#endif /* NO_PROTO */

/*  Given two planes, return line-intersection */
/*  Direction of line is cross-product of normal vectors */
    crossp_(a1, b1, c1, a2, b2, c2, a, b, c);
/*  use most stable variable as basis - effectively, use x=0, y=0, */
/*  or z=0 as 3rd plane. */
    ixyz = abest3_(a, b, c);
    if (ixyz == 1) {
#ifndef NO_PROTO
	*px = 0.f;
#else /* NO_PROTO */
	*px = (float)0.;
#endif /* NO_PROTO */
	lintpt_(b1, c1, d1, b2, c2, d2, py, pz);
    } else if (ixyz == 2) {
#ifndef NO_PROTO
	*py = 0.f;
#else /* NO_PROTO */
	*py = (float)0.;
#endif /* NO_PROTO */
	lintpt_(a1, c1, d1, a2, c2, d2, px, pz);
    } else {
#ifndef NO_PROTO
	*pz = 0.f;
#else /* NO_PROTO */
	*pz = (float)0.;
#endif /* NO_PROTO */
	lintpt_(a1, b1, d1, a2, b2, d2, px, py);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pl2ln_ */

