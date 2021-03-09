/* chkmcv.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
static real c_b5 = 2.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
static real c_b5 = (float)2.;
#endif /* NO_PROTO */
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int chkmcv_(char *stpath, char *expths, ftnlen stpath_len, 
	ftnlen expths_len)
#else /* NO_PROTO */
/* Subroutine */ int chkmcv_(stpath, expths, stpath_len, expths_len)
char *stpath, *expths;
ftnlen stpath_len;
ftnlen expths_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int ispths_(real *, real *, real *, real *, 
	    integer *, integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ispths_();
#endif /* NO_PROTO */

/*  CHKMCV checks that the correct sequence of found paths is returned */
/*  by ISS as a result of the starting path.  It issues pass or fail */
/*  depending on whether the actual found paths match those expected. */
/*  It always uses a search reference point of 0,0,0 and distance of 2. */

/*  Input parameters: */
/*    STPATH : starting path for ISS */
/*    EXPTHS : expected found paths */
/* clipping indicator */
/*                noclip      clip */
    ispths_(&c_b2, &c_b2, &c_b2, &c_b5, &c__1, &c__1, stpath, expths, 
	    stpath_len, expths_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkmcv_ */

