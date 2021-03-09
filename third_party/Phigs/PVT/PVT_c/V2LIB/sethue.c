/* sethue.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b4 = 0.f;
static real c_b5 = 1.f;
#else /* NO_PROTO */
static real c_b4 = (float)0.;
static real c_b5 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b11 = .01f;
static real c_b14 = .1f;
static real c_b17 = .05f;

/* Subroutine */ int sethue_(integer *wkid, integer *colmod, integer *maxfg, 
	integer *paltte, real *cc, integer *numset, integer *lscoli)
#else /* NO_PROTO */
static real c_b11 = (float).01;
static real c_b14 = (float).1;
static real c_b17 = (float).05;

/* Subroutine */ int sethue_(wkid, colmod, maxfg, paltte, cc, numset, lscoli)
integer *wkid, *colmod, *maxfg, *paltte;
real *cc;
integer *numset, *lscoli;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ix, iy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr (), nscmd ();
#endif /* NO_PROTO */
    static logical colok;
    static integer ccsiz, rncol[20], palix;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int rnset_();
#endif /* NO_PROTO */
    static real realcc[3], thiscc[3];
#ifndef NO_PROTO
    extern logical coleql_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical coleql_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, numdsp;

/*  SETHUE tries to set as many hues as possible in the color table */
/*  and reports back the order in which they were set and how many. */

/*  Input parameters */
/*    WKID   : workstation identifier */
/*    COLMOD : Color model to set up under */
/*    MAXFG  : Maximum number of available foreground entries in */
/*             color table, starting with #2 */
/*    PALTTE : Number of colors to be displayed if possible */
/*    CC     : Color coordinates to be set in color table */

/*  Output parameters */
/*    NUMSET : Number of entries successfully set */
/*    LSCOLI : List of which entries in CC (palette) were set */
/* type of returned value */
/* colour model */
    /* Parameter adjustments */
    --lscoli;
    cc -= 4;

    /* Function Body */
    nscmd (wkid, colmod);
/*  max number to be displayed */
    numdsp = min(*maxfg,*paltte);
    rnset_(&numdsp, paltte, rncol);
/*  how many set so far? */
    *numset = 0;
    i__1 = numdsp;
    for (ix = 1; ix <= i__1; ++ix) {
/*  which color in palette to try */
	palix = rncol[ix - 1];
	for (iy = 1; iy <= 3; ++iy) {
	    thiscc[iy - 1] = cc[iy + palix * 3];
/*  treat -1 as a "don't care" value */
#ifndef NO_PROTO
	    if (thiscc[iy - 1] == -1.f) {
#else /* NO_PROTO */
	    if (thiscc[iy - 1] == (float)-1.) {
#endif /* NO_PROTO */
		thiscc[iy - 1] = rndrl_(&c_b4, &c_b5);
	    }
/* L110: */
	}
	i__2 = *numset + 2;
	nscr (wkid, &i__2, &c__3, thiscc);
	i__2 = *numset + 2;
	nqcr (wkid, &i__2, &c__3, &c__1, &errind, &ccsiz, realcc);
	chkinq_("pqcr", &errind, 4L);
	if (ccsiz != 3) {
	    goto L100;
	}
/*  is realized hue close enough ?? */
	if (*colmod == 2) {
	    colok = coleql_(&c__2, realcc, thiscc, &c_b11, &c_b4) && coleql_(&
		    c__1, &realcc[2], &thiscc[2], &c_b14, &c_b4);
	} else {
	    colok = coleql_(&c__3, realcc, thiscc, &c_b17, &c_b4);
	}
	if (colok) {
/*  add to list */
	    ++(*numset);
	    lscoli[*numset] = palix;
	} else {
/*           not set */
	}
L100:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sethue_ */

