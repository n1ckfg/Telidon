/* fort/04/01/05/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__10 = 10;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b25 = .02f;
#else /* NO_PROTO */
static real c_b25 = (float).02;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b36 = 0.f;
#else /* NO_PROTO */
static real c_b36 = (float)0.;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b69 = .5f;
#else /* NO_PROTO */
static real c_b69 = (float).5;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.05/03                           * */
/*  *    TEST TITLE : Appearance of fill area interiors     * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Initialized data */

    static logical instav[3] = { FALSE_,FALSE_,FALSE_ };
#ifndef NO_PROTO
    static char instnm[7*3] = "solid  " "pattern" "hatch  ";
#else /* NO_PROTO */
    static char instnm[7*3+1] = "solid  patternhatch  ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1, r__2;
    char ch__1[42];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    double cos(), sin();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);

#endif /* not NO_PROTO */
    /* Local variables */
    static integer i1, i2, i3, i4;
    static real xa[101], ya[101], za[101], xb[101], yb[101], zb[101], xf[9]	
	    /* was [3][3] */;
    static integer ix, iy;
    static real xt[10], yt[10], zt[10], ang;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static integer ans, isi, xhi[20], yhi[20], xlo[20], ylo[20], siz;
    static real rad1, rad2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa3 ();
#endif /* NO_PROTO */
    static integer ran6[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int win6_(integer *, integer *, real *, real *, 
	    real *, real *), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int win6_(), ifpf_();
#endif /* NO_PROTO */
    static integer ihat, ipat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nspa (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqif (), nspa ();
#endif /* NO_PROTO */
    static integer txci, ngsq, this__;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static integer npts;
    static real xsiz, ysiz;
    static integer idum1, idum2, idum3, idum4;
    static real cfrac;
    static integer colia[4]	/* was [2][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), endit_(void), inmsg_(char *, ftnlen), 
	    nclst (void), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nsisi (
	    integer *), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), endit_(), inmsg_(), nclst (), 
	    nspar (), nsisi (), nemst ();
#endif /* NO_PROTO */
    static integer numhs;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    nsvwi (integer *), dchoic_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), setvs_(), nopst (), 
	    nsvwi (), dchoic_();
#endif /* NO_PROTO */
    static real radbas, radinc;
#ifndef NO_PROTO
    extern /* Subroutine */ int denhat_(integer *, integer *, integer *, 
	    integer *), filrec_(integer *, integer *, integer *, integer *, 
	    real *, real *), nsedfg (integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int denhat_(), filrec_(), nsedfg (), chkinq_();
#endif /* NO_PROTO */
    static logical fillok;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thisis;
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer ppturn, nturns, intsty;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setasf_(
	    integer *), setval_(char *, integer *, ftnlen), setrvs_(char *, 
	    real *, integer *, ftnlen), rnperm_(integer *, integer *), 
	    opcofl_(void), setmsg_(char *, char *, ftnlen, ftnlen), arcpts_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setasf_(), setval_(), setrvs_(), 
	    rnperm_(), opcofl_(), setmsg_(), arcpts_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("04.01.05/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  default attributes */
    nsedfg (&c__0);
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
/*  determine if solid, hatch, pattern interior style is supported: */
    fillok = FALSE_;
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &siz, &idum1, &numhs, &
	    idum2, &idum3);
    chkinq_("pqif", &errind, 4L);
/* get interior styles */
    i__1 = siz;
    for (isi = 1; isi <= i__1; ++isi) {
	nqif (&dialog_1.specwt, &isi, &c__0, &errind, &idum1, &thisis, &idum2,
		 &idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis >= 1 && thisis <= 3) {
/* mark which interior styles are available */
	    instav[thisis - 1] = TRUE_;
	    fillok = TRUE_;
	}
/* L50: */
    }
    if (! fillok) {
#ifndef NO_PROTO
	inmsg_("Skipping all tests because no interior-filling style is avai"
		"lable.", 66L);
#else /* NO_PROTO */
	inmsg_("Skipping all tests because no interior-filling style is avai\
lable.", 66L);
#endif /* NO_PROTO */
	goto L666;
    }
    if (instav[2]) {
	denhat_(&c__102, &c__10, &dialog_1.specwt, &ihat);
    }
    if (instav[1]) {
/*  define pattern #ipat as simple checkerboard pattern */
	ipat = 1;
	setval_("0,1,1,0", colia, 7L);
	nspar (&globnu_1.wkid, &ipat, &c__2, &c__2, &c__1, &c__1, &c__2, &
		c__2, colia);
	nspa (&c_b25, &c_b25);
    }
/*  set up structure 106 to label 6 windows */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  *** *** ***   interior of self-overlapping polygon   *** *** *** */
    fillok = TRUE_;
/*  coordinates for overlapping fill area */
#ifndef NO_PROTO
    setrvs_(".05,.05,.60,.60,.30,.30,.75,.75,.30,.30,.45,.45,.05,.05,.85,.85"
	    ",.15,.15,.95,.95", xa, &npts, 79L);
    setrvs_(".05,.55,.55,.45,.45,.65,.65,.35,.35,.25,.25,.95,.95,.75,.75,.15"
	    ",.15,.85,.85,.05", ya, &npts, 79L);
#else /* NO_PROTO */
    setrvs_(".05,.05,.60,.60,.30,.30,.75,.75,.30,.30,.45,.45,.05,.05,.85,.85\
,.15,.15,.95,.95", xa, &npts, 79L);
    setrvs_(".05,.55,.55,.45,.45,.65,.65,.35,.35,.25,.25,.95,.95,.75,.75,.15\
,.15,.85,.85,.05", ya, &npts, 79L);
#endif /* NO_PROTO */
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	za[ix - 1] = xa[ix - 1] * .5f + ya[ix - 1] * .5f;
#else /* NO_PROTO */
	za[ix - 1] = xa[ix - 1] * (float).5 + ya[ix - 1] * (float).5;
#endif /* NO_PROTO */
	xb[npts + 1 - ix - 1] = xa[ix - 1];
	yb[npts + 1 - ix - 1] = ya[ix - 1];
	zb[npts + 1 - ix - 1] = za[ix - 1];
/* L70: */
    }
    for (intsty = 1; intsty <= 3; ++intsty) {
/*  for each available intsty = SOLID, HATCH, PATTERN */
	if (! instav[intsty - 1]) {
	    goto L100;
	}
/*  ran6 = random order for 1-6 */
	rnperm_(&c__6, ran6);
	nsis (&intsty);
	if (intsty == 3) {
	    nsisi (&ihat);
	} else if (intsty == 2) {
	    nsisi (&ipat);
	}
	for (ix = 1; ix <= 6; ++ix) {
	    this__ = ran6[ix - 1];
/*  scale 0:1,0:1 into window #ix */
	    ebltm_(&c_b36, &c_b36, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b36, &
		    xsiz, &xsiz, xf);
	    nslmt (xf, &c__2);
	    if (this__ == 1) {
/*   1 - simulate the figure, filling in the wrong interiors 
*/
		ngsq = ix;
		setvs_("13, 1,18,17,17, 6, 5,10,12,11,15", xlo, &siz, 32L);
		setvs_("18,17,12, 6,16,12,12,11,15, 7,19", xhi, &siz, 32L);
		setvs_("13, 1,18, 2, 1, 6, 5,10,15, 8,20", ylo, &siz, 32L);
		setvs_("14, 2,12,14,17,14, 2, 9,19, 7,19", yhi, &siz, 32L);
		i__1 = siz;
		for (iy = 1; iy <= i__1; ++iy) {
		    filrec_(&xlo[iy - 1], &xhi[iy - 1], &ylo[iy - 1], &yhi[iy 
			    - 1], xa, ya);
/* L120: */
		}
	    } else if (this__ == 2) {
/*   2 - simulate the figure, filled correctly */
		setvs_("13, 1,18,17,17, 6, 5,10,12,11,11, 3,15", xlo, &siz, 
			38L);
		setvs_("18,17,12, 6,16,12,12,11,15, 3, 3, 7,19", xhi, &siz, 
			38L);
		setvs_("13, 1,18, 2, 1, 6, 5,10,15, 3, 8, 8,20", ylo, &siz, 
			38L);
		setvs_("14, 2,12,14,17,14, 2, 9,19, 7, 4, 7,19", yhi, &siz, 
			38L);
		i__1 = siz;
		for (iy = 1; iy <= i__1; ++iy) {
		    filrec_(&xlo[iy - 1], &xhi[iy - 1], &ylo[iy - 1], &yhi[iy 
			    - 1], xa, ya);
/* L130: */
		}
	    } else if (this__ == 3) {
/*   3 - generate the overlapping 3D fill area */
		nfa3 (&npts, xa, ya, za);
	    } else if (this__ == 4) {
/*   4 - generate the overlapping 3D fill area, */
/*       reverse order of point list */
		nfa3 (&npts, xb, yb, zb);
	    } else if (this__ == 5) {
/*   5 - generate the overlapping 2D fill area */
		nfa (&npts, xa, ya);
	    } else if (this__ == 6) {
/*   6 - generate the overlapping 2D fill area, */
/*       reverse order of point list */
		nfa (&npts, xb, yb);
	    }
/*  next ix */
/* L110: */
	}
#ifndef NO_PROTO
	dchoic_("INTERIOR OF SELF-OVERLAPPING FILL AREAS: Which figure is di"
		"fferent?", &c__0, &c__6, &ans, 67L);
#else /* NO_PROTO */
	dchoic_("INTERIOR OF SELF-OVERLAPPING FILL AREAS: Which figure is di\
fferent?", &c__0, &c__6, &ans, 67L);
#endif /* NO_PROTO */
	nemst (&c__102);
	if (ans == ngsq) {
/*           OK so far */
	} else {
	    if (ans == 0) {
		opcofl_();
	    }
	    fillok = FALSE_;
/* Writing concatenation */
	    i__2[0] = 35, a__1[0] = "Overlap failed on interior style = ";
	    i__2[1] = 7, a__1[1] = instnm + (intsty - 1) * 7;
	    s_cat(ch__1, a__1, i__2, &c__2, 42L);
	    inmsg_(ch__1, 42L);
	}
/*  next intsty */
L100:
	;
    }
#ifndef NO_PROTO
    setmsg_("1 4 7 8", "The interior of a self-overlapping fill area should "
	    "be filled correctly.", 7L, 72L);
#else /* NO_PROTO */
    setmsg_("1 4 7 8", "The interior of a self-overlapping fill area should \
be filled correctly.", 7L, 72L);
#endif /* NO_PROTO */
    ifpf_(&fillok);
/*  *** *** ***   interior of concave spiral polygon   *** *** *** */
    fillok = TRUE_;
/*  number of turns and points per turn */
    nturns = 3;
    ppturn = 10;
    npts = (nturns << 1) * ppturn;
#ifndef NO_PROTO
    radbas = .08f;
    radinc = (.47999999999999998f - radbas) / (nturns + .5f);
#else /* NO_PROTO */
    radbas = (float).08;
    radinc = ((float).47999999999999998 - radbas) / (nturns + (float).5);
#endif /* NO_PROTO */
/*  coordinates for spiral fill area */
    i__1 = npts / 2;
    for (ix = 1; ix <= i__1; ++ix) {
	cfrac = (real) ix / ppturn;
#ifndef NO_PROTO
	ang = (cfrac * 2 + .25f) * 3.14159265f;
#else /* NO_PROTO */
	ang = (cfrac * 2 + (float).25) * (float)3.14159265;
#endif /* NO_PROTO */
	rad1 = radbas + cfrac * radinc;
	rad2 = rad1 + radinc / 2;
	iy = npts + 1 - ix;
#ifndef NO_PROTO
	xa[ix - 1] = rad1 * cos(ang) + .5f;
	ya[ix - 1] = rad1 * sin(ang) + .5f;
	za[ix - 1] = xa[ix - 1] * .5f + ya[ix - 1] * .5f;
	xa[iy - 1] = rad2 * cos(ang) + .5f;
	ya[iy - 1] = rad2 * sin(ang) + .5f;
	za[iy - 1] = xa[iy - 1] * .5f + ya[iy - 1] * .5f;
#else /* NO_PROTO */
	xa[ix - 1] = rad1 * cos(ang) + (float).5;
	ya[ix - 1] = rad1 * sin(ang) + (float).5;
	za[ix - 1] = xa[ix - 1] * (float).5 + ya[ix - 1] * (float).5;
	xa[iy - 1] = rad2 * cos(ang) + (float).5;
	ya[iy - 1] = rad2 * sin(ang) + (float).5;
	za[iy - 1] = xa[iy - 1] * (float).5 + ya[iy - 1] * (float).5;
#endif /* NO_PROTO */
/* L150: */
    }
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
	iy = npts + 1 - ix;
	xb[iy - 1] = xa[ix - 1];
	yb[iy - 1] = ya[ix - 1];
	zb[iy - 1] = za[ix - 1];
/* L160: */
    }
    for (intsty = 1; intsty <= 3; ++intsty) {
/*  for each available intsty = SOLID, HATCH, PATTERN */
	if (! instav[intsty - 1]) {
	    goto L200;
	}
/*  ran6 = random order for 1-6 */
	rnperm_(&c__6, ran6);
	nsis (&intsty);
	if (intsty == 3) {
	    nsisi (&ihat);
	} else if (intsty == 2) {
	    nsisi (&ipat);
	}
	for (ix = 1; ix <= 6; ++ix) {
	    this__ = ran6[ix - 1];
/*  scale 0:1,0:1 into window #ix */
	    ebltm_(&c_b36, &c_b36, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b36, &
		    xsiz, &xsiz, xf);
	    nslmt (xf, &c__2);
	    if (this__ == 1 || this__ == 2) {
/*  simulate the figure, filled correctly */
		i__1 = npts / 2 - 1;
		for (iy = 1; iy <= i__1; ++iy) {
		    i1 = iy;
		    i2 = iy + 1;
		    i3 = npts - iy;
		    i4 = i3 + 1;
		    xt[0] = xa[i1 - 1];
		    xt[1] = xa[i2 - 1];
		    xt[2] = xa[i3 - 1];
		    xt[3] = xa[i4 - 1];
		    yt[0] = ya[i1 - 1];
		    yt[1] = ya[i2 - 1];
		    yt[2] = ya[i3 - 1];
		    yt[3] = ya[i4 - 1];
		    nfa (&c__4, xt, yt);
/* L220: */
		}
		if (this__ == 1) {
/*  mark as incorrect, and muck up */
		    ngsq = ix;
		    r__1 = radbas * 2;
#ifndef NO_PROTO
		    r__2 = 6.2831853000000004f / ppturn;
#else /* NO_PROTO */
		    r__2 = (float)6.2831853000000004 / ppturn;
#endif /* NO_PROTO */
		    arcpts_(&ppturn, &c_b69, &c_b69, &r__1, &c_b36, &r__2, xt,
			     yt, zt);
		    nfa (&ppturn, xt, yt);
		}
	    } else if (this__ == 3) {
/*  3 - generate the spiral 3D fill area */
		nfa3 (&npts, xa, ya, za);
	    } else if (this__ == 4) {
/*  4 - generate the spiral 3D fill area, */
/*      reverse order of point list */
		nfa3 (&npts, xb, yb, zb);
	    } else if (this__ == 5) {
/*  5 - generate the spiral 2D fill area */
		nfa (&npts, xa, ya);
	    } else if (this__ == 6) {
/*  6 - generate the spiral 2D fill area, */
/*      reverse order of point list */
		nfa (&npts, xb, yb);
	    }
/*     next ix */
/* L210: */
	}
	dchoic_("INTERIOR OF CONCAVE FILL AREAS: Which figure is different?", 
		&c__0, &c__6, &ans, 58L);
	nemst (&c__102);
	if (ans == ngsq) {
/*           OK so far */
	} else {
	    if (ans == 0) {
		opcofl_();
	    }
	    fillok = FALSE_;
/* Writing concatenation */
	    i__2[0] = 35, a__1[0] = "Concave failed on interior style = ";
	    i__2[1] = 7, a__1[1] = instnm + (intsty - 1) * 7;
	    s_cat(ch__1, a__1, i__2, &c__2, 42L);
	    inmsg_(ch__1, 42L);
	}
/*  next intsty */
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("1 4 7 8", "The interior of a concave spiral fill area should be"
	    " filled correctly.", 7L, 70L);
#else /* NO_PROTO */
    setmsg_("1 4 7 8", "The interior of a concave spiral fill area should be\
 filled correctly.", 7L, 70L);
#endif /* NO_PROTO */
    ifpf_(&fillok);
/*  end_it_all: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

