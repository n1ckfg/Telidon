/* fort/04/02/04/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b7 = .15f;
static real c_b9 = .25f;
static real c_b16 = .6f;
#else /* NO_PROTO */
static real c_b7 = (float).15;
static real c_b9 = (float).25;
static real c_b16 = (float).6;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.04.02/drwatx                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int drwatx_(integer *numbun, integer *bundis, integer *
	bundif)
#else /* NO_PROTO */
/* Subroutine */ int drwatx_(numbun, bundis, bundif)
integer *numbun, *bundis, *bundif;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static integer ix, pdci, pdfn;
    static real pdex;
    static integer pdpr;
    static real yloc, pdsp, npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), wcnpc_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), wcnpc_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxi (integer *), numlab_(integer *, real *, 
	    real *, real *), chkinq_(char *, integer *, ftnlen), nsatch (real 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxi (), numlab_(), chkinq_(), nsatch ();
#endif /* NO_PROTO */
    static integer errind;
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nsatal (integer *, 
	    integer *), nschsp (real *), nschxp (real *), nstxci (integer *), 
	    nstxfn (integer *), nqptxr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *), nstxpr (integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nsatal (), nschsp (), nschxp (), 
	    nstxci (), nstxfn (), nqptxr (), nstxpr ();
#endif /* NO_PROTO */

/*  DRWATX draws a set of annotation text relative primitives where */
/*  the actual annotation text relative primitives are drawn using */
/*  the specified bundle values, and a set of expected annotation text */
/*  relative primitives are drawn using the attribute values returned */
/*  by <inquire predefined text representation>.  It draws the expected */

/*  annotation text primitive incorrectly at the specified position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of text bundle indices to be displayed */
/*    BUNDIF : position of annotation text to be drawn incorrectly */
/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* colour model */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
/*  get ratio of NPC to WC */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    wcnpc_(&c_b2, &c_b2, &npcx, &npcy, &npcpwc);
/*  use bundled attributes */
    setasf_(&c__0);
/*  draw and label actual */
#ifndef NO_PROTO
    yincr = .8f / *numbun;
    yloc = .9f;
    r__1 = npcpwc * .03f;
#else /* NO_PROTO */
    yincr = (float).8 / *numbun;
    yloc = (float).9;
    r__1 = npcpwc * (float).03;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatal (&c__1, &c__3);
    numlab_(numbun, &c_b7, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxi (&bundis[ix]);
	natr (&c_b9, &yloc, &c_b2, &c_b2, "Phigs", 5L);
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
	natr (&c_b16, &yloc, &c_b2, &c_b2, "Phigs", 5L);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwatx_ */

