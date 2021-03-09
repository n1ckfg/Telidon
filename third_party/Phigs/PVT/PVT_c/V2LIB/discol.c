/* discol.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__27 = 27;

#ifndef NO_PROTO
/* Subroutine */ int discol_(integer *maxreq, integer *wkid, integer *ndisct)
#else /* NO_PROTO */
/* Subroutine */ int discol_(maxreq, wkid, ndisct)
integer *maxreq, *wkid, *ndisct;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2, r__3;

    /* Local variables */
    static integer ix, ncc;
    static real bval;
    static integer icol;
    static real gval, buse;
    static integer perm[30];
    static real guse, rval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr ();
#endif /* NO_PROTO */
    static real ruse;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, bestc;
    static real bestd, cdist;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static real possc[81]	/* was [3][27] */;
    static integer chosen[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, thiscl;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */
    static integer nxtcol;
    static real rlzcol[84]	/* was [3][28] */;
    static integer maxsiz, szcolt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwksl (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwksl ();
#endif /* NO_PROTO */

/*  DISCOL attempts to change the color table so as to put distinct */
/*  foreground colors in entries 1-MAXREQ.  These are to be */
/*  distinct from the background color as well as from each other. */
/*  DISCOL also attempts to put the color "farthest" from the */
/*  background color (and hence, the most conspicuous) as color #1. */
/*  Input parameters: */
/*    MAXREQ : Number of requested distinct colors */
/*    WKID   : Workstation identifier */
/*  Output parameters: */
/*    NDISCT : Actual number of distinct colors in color table 1-NDISCT */

/* colour model */
/* type of returned value */
/*  set color model = RGB */
    nscmd (wkid, &c__1);
/*  set up possible values - all points at 0.0, 0.67, 1.0 - */
/*  bias towards lighter side of RGB cube */
    ix = 0;
#ifndef NO_PROTO
    for (rval = 0.f; rval <= 1.4f; rval += .67f) {
	ruse = dmin(rval,1.f);
	for (gval = 0.f; gval <= 1.4f; gval += .67f) {
	    guse = dmin(gval,1.f);
	    for (bval = 0.f; bval <= 1.4f; bval += .67f) {
		buse = dmin(bval,1.f);
#else /* NO_PROTO */
    for (rval = (float)0.; rval <= (float)1.4; rval += (float).67) {
	ruse = dmin(rval,(float)1.);
	for (gval = (float)0.; gval <= (float)1.4; gval += (float).67) {
	    guse = dmin(gval,(float)1.);
	    for (bval = (float)0.; bval <= (float)1.4; bval += (float).67) {
		buse = dmin(bval,(float)1.);
#endif /* NO_PROTO */
		++ix;
		possc[ix * 3 - 3] = ruse;
		possc[ix * 3 - 2] = guse;
		possc[ix * 3 - 1] = buse;
/* L120: */
	    }
/* L110: */
	}
/* L100: */
    }
/*  get realized background color */
    nqcr (wkid, &c__0, &c__3, &c__1, &errind, &ncc, rlzcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcolt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  maxsiz = maximum size to try to fill */
/* Computing MIN */
    i__1 = *maxreq, i__2 = szcolt - 1;
    maxsiz = min(i__1,i__2);
/*  get permutation of 27 colors */
    rnperm_(&c__27, perm);
/*  how many distinct so far */
    *ndisct = 0;
#ifndef NO_PROTO
    bestd = -666.f;
#else /* NO_PROTO */
    bestd = (float)-666.;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 27; ++ix) {
	nxtcol = *ndisct + 1;
	thiscl = perm[ix - 1];
/*  try next possibility from 27 */
	nscr (wkid, &nxtcol, &c__3, &possc[thiscl * 3 - 3]);
/*  get color as realized */
	nqcr (wkid, &nxtcol, &c__3, &c__1, &errind, &ncc, &rlzcol[nxtcol * 3])
		;
	chkinq_("pqcr", &errind, 4L);
/*  if realized color different from others and from 0 - got a new one
, */
/*  else re-try same slot */
	for (icol = *ndisct; icol >= 0; --icol) {
/*  inter-color distance squared */
/* Computing 2nd power */
	    r__1 = rlzcol[nxtcol * 3] - rlzcol[icol * 3];
/* Computing 2nd power */
	    r__2 = rlzcol[nxtcol * 3 + 1] - rlzcol[icol * 3 + 1];
/* Computing 2nd power */
	    r__3 = rlzcol[nxtcol * 3 + 2] - rlzcol[icol * 3 + 2];
	    cdist = r__1 * r__1 + r__2 * r__2 + r__3 * r__3;
/*  minimum closeness is .3**2 */
#ifndef NO_PROTO
	    if (cdist < .09f) {
#else /* NO_PROTO */
	    if (cdist < (float).09) {
#endif /* NO_PROTO */
/*  too close - skip it */
		goto L200;
	    }
/* L300: */
	}
/*  OK - use it */
	++(*ndisct);
	chosen[*ndisct - 1] = thiscl;
/*  save color farthest from color #0 */
	if (cdist > bestd) {
	    bestd = cdist;
	    bestc = *ndisct;
	}
	if (*ndisct >= maxsiz) {
	    goto L210;
	}
L200:
	;
    }
L210:
/*  switch color farthest from #0 into slot #1 */
    nscr (wkid, &c__1, &c__3, &possc[chosen[bestc - 1] * 3 - 3]);
    nscr (wkid, &bestc, &c__3, &possc[chosen[0] * 3 - 3]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* discol_ */

