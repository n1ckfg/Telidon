/* basbot.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 1.f;
static real c_b3 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)1.;
static real c_b3 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__4 = 4;

#ifndef NO_PROTO
doublereal basbot_(integer *wktype, integer *font)
#else /* NO_PROTO */
doublereal basbot_(wktype, font)
integer *wktype, *font;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char str[7] = "ISO Wg2";
#else /* NO_PROTO */
    static char str[7+1] = "ISO Wg2";
#endif /* NO_PROTO */

    /* System generated locals */
    real ret_val;

    /* Local variables */
    static real xb[2], yb[2], ccx, ccy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  BASBOT returns the nominal distance (i.e. for character height = */
/*  1.0) between the baseline and bottom of characters for a given */
/*  workstation type and font. */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    nqtxx (wktype, font, &c_b2, &c_b3, &c_b2, &c__0, &c__1, &c__4, str, &
	    errind, xb, yb, &ccx, &ccy, 7L);
    chkinq_("pqtxx", &errind, 5L);
    ret_val = -(doublereal)yb[0];
    return ret_val;
} /* basbot_ */

