/* fort/04/01/06/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b17 = .15f;
#else /* NO_PROTO */
static real c_b17 = (float).15;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b33 = .02f;
#else /* NO_PROTO */
static real c_b33 = (float).02;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b44 = 0.f;
static real c_b81 = .5f;
#else /* NO_PROTO */
static real c_b44 = (float)0.;
static real c_b81 = (float).5;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.06/03                           * */
/*  *    TEST TITLE : Appearance of fill area set interiors * */
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
    integer i__1, i__2, i__3[2];
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
    static real xa[101], ya[101];
    static integer hs[20];
    static real za[101], xb[101], yb[101], zb[101], xf[9]	/* was [3][3] 
	    */;
    static integer ix, iy;
    static real xt[10], yt[10], zt[10], ang;
    static integer ans, isi, xhi[20], yhi[20], xlo[20], ylo[20], siz;
    static real rad1, rad2;
    static integer ran6[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int win6_(integer *, integer *, real *, real *, 
	    real *, real *), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int win6_(), ifpf_();
#endif /* NO_PROTO */
    static integer ihat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer ipat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa ();
#endif /* NO_PROTO */
    static real yloc;
    static integer txci, ngsq, this__;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static integer npts;
    static real ytop, xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
    static real cfrac;
    static integer colia[4]	/* was [2][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), endit_(void), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), endit_(), inmsg_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nsisi (integer *), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nspar (), nsisi (), nemst ();
#endif /* NO_PROTO */
    static integer numhs;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    nslmt (real *, integer *), nexst (integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), nopst (integer *), nsvwi (integer *
	    ), dchoic_(char *, integer *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), nslmt (), nexst (), setvs_(), 
	    nopst (), nsvwi (), dchoic_();
#endif /* NO_PROTO */
    static real radbas, radinc;
#ifndef NO_PROTO
    extern /* Subroutine */ int filrec_(integer *, integer *, integer *, 
	    integer *, real *, real *), nsedfg (integer *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int filrec_(), nsedfg (), chkinq_();
#endif /* NO_PROTO */
    static logical fillok;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numlin, endpts[10], thisis;
    static real xwinlo[6], ywinlo[6];
    static integer ppturn, nturns, intsty;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setval_(char *, integer *, ftnlen)
	    , setrvs_(char *, real *, integer *, ftnlen), rnperm_(integer *, 
	    integer *), opcofl_(void), setmsg_(char *, char *, ftnlen, ftnlen)
	    , arcpts_(integer *, real *, real *, real *, real *, real *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setval_(), 
	    setrvs_(), rnperm_(), opcofl_(), setmsg_(), arcpts_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("04.01.06/03", 11L);
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
/*  get a dense hatch style from 10 random ones */
	nopst (&c__102);
/* Computing MIN */
	i__1 = 10, i__2 = abs(numhs);
	numlin = min(i__1,i__2);
	i__1 = abs(numhs);
	rnset_(&numlin, &i__1, perm);
#ifndef NO_PROTO
	yincr = 1 / (numlin + 1.f);
#else /* NO_PROTO */
	yincr = 1 / (numlin + (float)1.);
#endif /* NO_PROTO */
	ytop = 1 - yincr;
	yloc = ytop;
	numlab_(&numlin, &c_b17, &ytop, &yincr);
	nsis (&c__3);
#ifndef NO_PROTO
	xa[0] = .2f;
	xa[1] = .9f;
	xa[2] = .9f;
	xa[3] = .2f;
#else /* NO_PROTO */
	xa[0] = (float).2;
	xa[1] = (float).9;
	xa[2] = (float).9;
	xa[3] = (float).2;
#endif /* NO_PROTO */
	endpts[0] = 4;
	i__1 = numlin;
	for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	    ya[0] = yloc + yincr * .4f;
	    ya[1] = yloc + yincr * .4f;
	    ya[2] = yloc - yincr * .4f;
	    ya[3] = yloc - yincr * .4f;
#else /* NO_PROTO */
	    ya[0] = yloc + yincr * (float).4;
	    ya[1] = yloc + yincr * (float).4;
	    ya[2] = yloc - yincr * (float).4;
	    ya[3] = yloc - yincr * (float).4;
#endif /* NO_PROTO */
	    nqif (&dialog_1.specwt, &c__0, &perm[ix - 1], &errind, &idum1, &
		    idum2, &idum3, &hs[ix - 1], &idum4);
	    chkinq_("pqif", &errind, 4L);
	    nsisi (&hs[ix - 1]);
	    nfas (&c__1, endpts, xa, ya);
	    yloc -= yincr;
/* L60: */
	}
	dchoic_("Pick a dense hatch style, preferably diagonal.", &c__1, &
		numlin, &ans, 46L);
	nemst (&c__102);
	nclst ();
	ihat = hs[ans - 1];
    }
    if (instav[1]) {
/*  define pattern #ipat as simple checkerboard pattern */
	ipat = 1;
	setval_("0,1,1,0", colia, 7L);
	nspar (&globnu_1.wkid, &ipat, &c__2, &c__2, &c__1, &c__1, &c__2, &
		c__2, colia);
	nspa (&c_b33, &c_b33);
    }
/*  set up structure 106 to label 6 windows */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  *** *** ***   interior of self-overlapping fill area set *** *** *** 
*/
    fillok = TRUE_;
/*  coordinates for overlapping fill area set */
    setrvs_(".05,.05,.75,.75,.15,.15,.60,.60,.25,.25,.85,.85,.40,.40,.95,.95",
	     xa, &npts, 63L);
    setrvs_(".25,.95,.95,.40,.40,.85,.85,.25,.05,.60,.60,.15,.15,.75,.75,.05",
	     ya, &npts, 63L);
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	za[ix - 1] = xa[ix - 1] * .5f + ya[ix - 1] * .5f;
#else /* NO_PROTO */
	za[ix - 1] = xa[ix - 1] * (float).5 + ya[ix - 1] * (float).5;
#endif /* NO_PROTO */
	iy = npts + 1 - ix;
	xb[iy - 1] = xa[ix - 1];
	yb[iy - 1] = ya[ix - 1];
	zb[iy - 1] = za[ix - 1];
/* L70: */
    }
    endpts[0] = 8;
    endpts[1] = 16;
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
	    ebltm_(&c_b44, &c_b44, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b44, &
		    xsiz, &xsiz, xf);
	    nslmt (xf, &c__2);
	    if (this__ == 1) {
/*   1 - simulate the figure, filling in the wrong interiors 
*/
		ngsq = ix;
		setvs_("1,6, 7,5,  9, 9,12, 4, 14,10,10, 7", xlo, &siz, 34L);
		setvs_("6,3, 3,9, 13,16,15,11,  3,13, 8, 4", xhi, &siz, 34L);
		setvs_("1,6, 7,5,  1, 9,12,14, 14,10, 5,10", ylo, &siz, 34L);
		setvs_("2,3,15,1, 13,13,15,11, 10, 5, 8, 4", yhi, &siz, 34L);
		i__1 = siz;
		for (iy = 1; iy <= i__1; ++iy) {
		    filrec_(&xlo[iy - 1], &xhi[iy - 1], &ylo[iy - 1], &yhi[iy 
			    - 1], xa, ya);
/* L120: */
		}
	    } else if (this__ == 2) {
/*   2 - simulate the figure, filled correctly */
		setvs_("1,6, 7,5,  9, 9,12, 4, 14,10,13, 7", xlo, &siz, 34L);
		setvs_("6,3, 3,9, 13,16,15,11,  7,13, 8, 4", xhi, &siz, 34L);
		setvs_("1,6, 7,5,  1, 9,12,14, 14,10, 5,10", ylo, &siz, 34L);
		setvs_("2,3,15,1, 13,13,15,11, 10, 5, 8, 4", yhi, &siz, 34L);
		i__1 = siz;
		for (iy = 1; iy <= i__1; ++iy) {
		    filrec_(&xlo[iy - 1], &xhi[iy - 1], &ylo[iy - 1], &yhi[iy 
			    - 1], xa, ya);
/* L130: */
		}
	    } else if (this__ == 3) {
/*   3 - generate the overlapping 3D fill area set */
		nfas3 (&c__2, endpts, xa, ya, za);
	    } else if (this__ == 4) {
/*   4 - generate the overlapping 3D fill area set, */
/*       reverse order of point list */
		nfas3 (&c__2, endpts, xb, yb, zb);
	    } else if (this__ == 5) {
/*   5 - generate the overlapping 2D fill area set */
		nfas (&c__2, endpts, xa, ya);
	    } else if (this__ == 6) {
/*   6 - generate the overlapping 2D fill area set, */
/*       reverse order of point list */
		nfas (&c__2, endpts, xb, yb);
	    }
/*  next ix */
/* L110: */
	}
#ifndef NO_PROTO
	dchoic_("INTERIOR OF SELF-OVERLAPPING FILL AREA SETS: Which figure i"
		"s different?", &c__0, &c__6, &ans, 71L);
#else /* NO_PROTO */
	dchoic_("INTERIOR OF SELF-OVERLAPPING FILL AREA SETS: Which figure i\
s different?", &c__0, &c__6, &ans, 71L);
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
	    i__3[0] = 35, a__1[0] = "Overlap failed on interior style = ";
	    i__3[1] = 7, a__1[1] = instnm + (intsty - 1) * 7;
	    s_cat(ch__1, a__1, i__3, &c__2, 42L);
	    inmsg_(ch__1, 42L);
	}
/*  next intsty */
L100:
	;
    }
#ifndef NO_PROTO
    setmsg_("1 4 7 8", "The interiors of a self-overlapping fill area set sh"
	    "ould be filled correctly.", 7L, 77L);
#else /* NO_PROTO */
    setmsg_("1 4 7 8", "The interiors of a self-overlapping fill area set sh\
ould be filled correctly.", 7L, 77L);
#endif /* NO_PROTO */
    ifpf_(&fillok);
/*  *** *** ***   interior of concave fill area set  *** *** *** */
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
	    ebltm_(&c_b44, &c_b44, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b44, &
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
		    endpts[0] = 4;
		    nfas (&c__1, endpts, xt, yt);
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
		    arcpts_(&ppturn, &c_b81, &c_b81, &r__1, &c_b44, &r__2, xt,
			     yt, zt);
		    endpts[0] = ppturn;
		    nfas (&c__1, endpts, xt, yt);
		}
	    } else if (this__ == 3) {
/*  3 - generate the spiral 3D fill area set */
		endpts[0] = npts;
		nfas3 (&c__1, endpts, xa, ya, za);
	    } else if (this__ == 4) {
/*  4 - generate the spiral 3D fill area set, */
/*      reverse order of point list */
		endpts[0] = npts;
		nfas3 (&c__1, endpts, xb, yb, zb);
	    } else if (this__ == 5) {
/*  5 - generate the spiral 2D fill area set */
		endpts[0] = npts;
		nfas (&c__1, endpts, xa, ya);
	    } else if (this__ == 6) {
/*  6 - generate the spiral 2D fill area set, */
/*      reverse order of point list */
		endpts[0] = npts;
		nfas (&c__1, endpts, xb, yb);
	    }
/*     next ix */
/* L210: */
	}
#ifndef NO_PROTO
	dchoic_("INTERIOR OF CONCAVE FILL AREA SETS: Which figure is differe"
		"nt?", &c__0, &c__6, &ans, 62L);
#else /* NO_PROTO */
	dchoic_("INTERIOR OF CONCAVE FILL AREA SETS: Which figure is differe\
nt?", &c__0, &c__6, &ans, 62L);
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
	    i__3[0] = 35, a__1[0] = "Concave failed on interior style = ";
	    i__3[1] = 7, a__1[1] = instnm + (intsty - 1) * 7;
	    s_cat(ch__1, a__1, i__3, &c__2, 42L);
	    inmsg_(ch__1, 42L);
	}
/*  next intsty */
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("1 4 7 8", "The interiors of a concave spiral fill area set shou"
	    "ld be filled correctly.", 7L, 75L);
#else /* NO_PROTO */
    setmsg_("1 4 7 8", "The interiors of a concave spiral fill area set shou\
ld be filled correctly.", 7L, 75L);
#endif /* NO_PROTO */
    ifpf_(&fillok);
/*  end_it_all: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

