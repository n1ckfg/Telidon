/* drwint.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__14 = 14;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b7 = .15f;
#else /* NO_PROTO */
static real c_b7 = (float).15;
#endif /* NO_PROTO */
static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int drwint_(integer *numbun, integer *bundis, integer *
	bundif)
#else /* NO_PROTO */
/* Subroutine */ int drwint_(numbun, bundis, bundif)
integer *numbun, *bundis, *bundif;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[5], ya[5];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static integer siz, pdci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer pdis;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii ();
#endif /* NO_PROTO */
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsici ();
#endif /* NO_PROTO */
    static integer pdisi;
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsisi (integer *), nqpir (integer *, integer *
	    , integer *, integer *, integer *, integer *), nsedfg (integer *),
	     chkinq_(char *, integer *, ftnlen), numlab_(integer *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsisi (), nqpir (), nsedfg (), chkinq_(), 
	    numlab_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nsiasf (integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nsiasf (), setrvs_();
#endif /* NO_PROTO */

/*  DRWINT draws a set of rectangles where the actual interiors */
/*  are drawn using the specified bundle values, and a set of */
/*  expected interiors are drawn using the attribute values */
/*  returned by <inquire predefined interior representation>. */
/*  It draws the expected interior incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of interior bundle indices to be displayed */
/*    BUNDIF : position of interior to be drawn incorrectly */
/* aspect source */
/*                bundled     individual */
/* interior style */
/*  use bundled attributes, except for edge attributes */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    setasf_(&c__0);
/*  to ensure edges predictable - set ASF individual: */
/*  set edge flag (pedfg=14) = off */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
/*  draw and label actual */
    setrvs_("0.2, 0.2, 0.45, 0.45", xa, &siz, 20L);
#ifndef NO_PROTO
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(numbun, &c_b7, &yloc, &yincr);
    npts[0] = 4;
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .3f;
	ya[1] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).3;
	ya[1] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[2] = ya[1];
	ya[3] = ya[0];
	ya[4] = ya[0];
	nsii (&bundis[ix]);
/* switch between fill area and fill area set */
	if (ix % 2 == 0) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (&c__4, xa, ya);
	}
	yloc -= yincr;
/* L100: */
    }
/*  now draw expected results - with individual attributes from WDT */
/*  use individual attributes */
    setasf_(&c__1);
    setrvs_("0.6, 0.6, 0.85, 0.85", xa, &siz, 20L);
#ifndef NO_PROTO
    yloc = .9f;
#else /* NO_PROTO */
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqpir (&dialog_1.specwt, &bundis[ix], &errind, &pdis, &pdisi, &pdci);
	chkinq_("pqpir", &errind, 5L);
	if (ix == *bundif) {
	    if (pdis == 0) {
		pdis = 4;
	    } else {
		pdis = pdis % 4 + 1;
	    }
	    pdisi = pdisi % 4 + 1;
	    pdci = pdci % 5 + 1;
	}
	nsis (&pdis);
	nsisi (&pdisi);
	nsici (&pdci);
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .3f;
	ya[1] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).3;
	ya[1] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[2] = ya[1];
	ya[3] = ya[0];
/* switch between fill area and fill area set */
	if (ix % 2 == 0) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (&c__4, xa, ya);
	}
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwint_ */

