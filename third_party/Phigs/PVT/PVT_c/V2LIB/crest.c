/* crest.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__100 = 100;
static integer c__2 = 2;
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b6 = .1f;
static real c_b7 = .55f;
#else /* NO_PROTO */
static real c_b6 = (float).1;
static real c_b7 = (float).55;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int crest_(void)
#else /* NO_PROTO */
/* Subroutine */ int crest_()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real xa[2] = { 0.f,0.f };
    static real ya[2] = { .5f,.5f };
#else /* NO_PROTO */
    static real xa[2] = { (float)0.,(float)0. };
    static real ya[2] = { (float).5,(float).5 };
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), nschh (real *), nclst (void), nexst (
	    integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx (), nschh (), nclst (), nexst (), 
	    nopst ();
#endif /* NO_PROTO */

/*   create a structure network */
    nopst (&c__100);
    npl (&c__2, xa, ya);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    nschh (&c_b6);
    ntx (&c_b7, &c_b7, "TEXT", 4L);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* crest_ */

