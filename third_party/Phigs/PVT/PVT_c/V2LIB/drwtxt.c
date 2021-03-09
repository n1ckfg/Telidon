/* drwtxt.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b3 = .03f;
#else /* NO_PROTO */
static real c_b3 = (float).03;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b6 = .15f;
static real c_b8 = .25f;
static real c_b13 = .6f;
#else /* NO_PROTO */
static real c_b6 = (float).15;
static real c_b8 = (float).25;
static real c_b13 = (float).6;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int drwtxt_(integer *numbun, integer *bundis, integer *
	bundif)
#else /* NO_PROTO */
/* Subroutine */ int drwtxt_(numbun, bundis, bundif)
integer *numbun, *bundis, *bundif;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static integer pdci, pdfn;
    static real pdex;
    static integer pdpr;
    static real yloc, pdsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxi (integer *), chkinq_(char *, integer *, 
	    ftnlen), numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxi (), chkinq_(), numlab_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nschsp (real *), nschxp (
	    real *), nstxci (integer *), nstxal (integer *, integer *), 
	    nstxfn (integer *), nqptxr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *), nstxpr (integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nschsp (), nschxp (), nstxci (), 
	    nstxal (), nstxfn (), nqptxr (), nstxpr ();
#endif /* NO_PROTO */

/*  DRWTXT draws a set of text primitives where the actual texts */
/*  are drawn using the specified bundle values, and a set of */
/*  expected text primitives are drawn using the attribute values */
/*  returned by <inquire predefined text representation>. */
/*  It draws the expected text primitive incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of text bundle indices to be displayed */
/*    BUNDIF : position of text to be drawn incorrectly */
/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* text alignment horizontal */
/* text alignment vertical */
/*  use bundled attributes */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    setasf_(&c__0);
/*  draw and label actual */
#ifndef NO_PROTO
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    nschh (&c_b3);
    nstxal (&c__1, &c__3);
    numlab_(numbun, &c_b6, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxi (&bundis[ix]);
	ntx (&c_b8, &yloc, "Phigs", 5L);
	yloc -= yincr;
/* L100: */
    }
/*  now draw expected results - with individual attributes from WDT */
/*  use individual attributes */
    setasf_(&c__1);
#ifndef NO_PROTO
    yloc = .9f;
#else /* NO_PROTO */
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqptxr (&dialog_1.specwt, &bundis[ix], &errind, &pdfn, &pdpr, &pdex, &
		pdsp, &pdci);
	chkinq_("pqptxr", &errind, 6L);
	if (ix == *bundif) {
	    if (pdfn == 1) {
		pdfn = 2;
	    } else {
		pdfn = 1;
	    }
	}
	nstxfn (&pdfn);
	nstxpr (&pdpr);
	nschxp (&pdex);
	nschsp (&pdsp);
	nstxci (&pdci);
	ntx (&c_b13, &yloc, "Phigs", 5L);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwtxt_ */

