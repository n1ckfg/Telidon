/* fort/04/02/05/02/p12.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__14 = 14;
#ifndef NO_PROTO
static real c_b8 = .1f;
static real c_b25 = .2f;
#else /* NO_PROTO */
static real c_b8 = (float).1;
static real c_b25 = (float).2;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b56 = .05f;
static real c_b57 = .45f;
#else /* NO_PROTO */
static real c_b56 = (float).05;
static real c_b57 = (float).45;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__50 = 50;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b128 = .15f;
#else /* NO_PROTO */
static real c_b128 = (float).15;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b202 = 1.f;
#else /* NO_PROTO */
static real c_b202 = (float)1.;
#endif /* NO_PROTO */
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/12                        * */
/*  *    TEST TITLE : Appearance of bundled attributes      * */
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

#ifndef NO_PROTO
    static char ldesis[14*5] = "hollow        " "solid         " "pattern   "
	    "    " "hatch         " "empty         ";
#else /* NO_PROTO */
    static char ldesis[14*5+1] = "hollow        solid         pattern       \
hatch         empty         ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2], i__4;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    double sin(), cos();
    /* Subroutine */ int s_copy(), s_cat();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[40], ya[40];
    static integer ix;
    static real ang, rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static integer mdi, pai;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer hdx, isi, npi;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer siz, cdim, pcia[2500]	/* was [50][50] */, isci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer undf[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *), nsep (integer *), nsir (
	    integer *, integer *, integer *, integer *, integer *), nqcr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *), nscr (integer *, integer *, integer *, real *), nsln (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii (), nsep (), nsir (), nqcr (), nscr (), 
	    nsln ();
#endif /* NO_PROTO */
    static integer szbt, idum1, idum2, idum3, idum4, idum5, idum6, idum7, 
	    diffi, facol[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_();
#endif /* NO_PROTO */
    static char hatid[12];
    static integer colel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), endit_();
#endif /* NO_PROTO */
    static integer nalis;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static integer regdx, noseg, numci, lavis[5], undpi, impdx;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
    static integer rtans[10];
    static real centx;
    static integer numhs;
    static real centy;
    static integer visdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), rnset_(integer *, 
	    integer *, integer *), dynpf_(char *, char *, ftnlen, ftnlen), 
	    nspar (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nopst (integer *), 
	    nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), rnset_(), dynpf_(), nspar (), 
	    nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real bckcol[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), nsedfg (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), nsedfg ();
#endif /* NO_PROTO */
    static logical noaval[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), setdlg_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thisis, intcst[3], cstsiz, maxrhs, minihs, 
	    endpts[3], thishs, lavrhs[100], lavihs[600], unsudx, lunsup[10], 
	    szcolt, numdis;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer viscol, maxcol, explct;
    static real forcol[6], newcol[6];
    static char prompt[200];
    static logical nozero;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsiasf (integer *, integer *), 
	    srtiar_(integer *, integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), rnperm_(integer *, integer *), numlab_(
	    integer *, real *, real *, real *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), dlstpf_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen), setrvs_(char *, real *, integer *, ftnlen), 
	    vislab_(char *, char *, real *, real *, real *, real *, ftnlen, 
	    ftnlen), dchpfv_(char *, integer *, integer *, ftnlen), nqepai (
	    integer *, integer *, integer *, integer *, integer *), rnbset_(
	    integer *, integer *, integer *, integer *), nstxci (integer *), 
	    nslwsc (real *), nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsiasf (), 
	    srtiar_(), nqwksl (), rnperm_(), numlab_(), setmsg_(), dlstpf_(), 
	    setrvs_(), vislab_(), dchpfv_(), nqepai (), rnbset_(), nstxci (), 
	    nslwsc (), nsplci ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___42 = { 0, hatid, 0, "(A,I5,A)", 12, 1 };
    static icilist io___43 = { 0, hatid, 0, "(A,I5,A)", 12, 1 };


/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* off/on switch for edge flag and error handling mode */
/* interior style */
/* linetype  (edgetype) */
/* type of returned value */
/* colour model */
/* colour available */
/* set up pattern array index values */
/*  interior styles affected by interior color */
    initgl_("04.02.05.02/12", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use bundle attributes */
    setasf_(&c__0);
/*  set edge flag off, (pedfg=14) */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
/* set up pattern size */
    nspa (&c_b8, &c_b8);
/*  use <inquire interior style facilities> to determine: */
/*    nalis  = number of available & legal interior styles (hollow:empty) 
*/
/*    lavis  = list of available interior styles */
/*    numhs  = number of available hatch styles */
/*    lavrhs = list of available registered (non-mandatory) hatch styles 
*/
/*    lavihs = list of available implementor-defined hatch styles */
/*             (may be derived directly from hatch style value, if */
/*              reported number of hatch styles< 0) */
/*    noaval = boolean table of interior styles not available */
    nalis = 0;
    cstsiz = 0;
    for (isi = 0; isi <= 4; ++isi) {
	noaval[isi] = TRUE_;
/* L10: */
    }
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &siz, &idum1, &numhs, &
	    idum2, &idum3);
    chkinq_("pqif", &errind, 4L);
/* get interior styles */
    i__1 = siz;
    for (isi = 1; isi <= i__1; ++isi) {
	nqif (&dialog_1.specwt, &isi, &c__0, &errind, &idum1, &thisis, &idum2,
		 &idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis >= 0 && thisis <= 4) {
	    ++nalis;
	    lavis[nalis - 1] = thisis;
/* mark which interior styles are available */
	    noaval[thisis] = FALSE_;
	}
/*  build list of styles sensitive to interior color */
	if (thisis == 0 || thisis == 1 || thisis == 3) {
	    intcst[cstsiz] = thisis;
	    ++cstsiz;
	}
/* L50: */
    }
/* get hatch styles */
    regdx = 0;
    impdx = 0;
    i__1 = abs(numhs);
    for (hdx = 1; hdx <= i__1; ++hdx) {
	nqif (&dialog_1.specwt, &c__0, &hdx, &errind, &idum1, &idum2, &idum3, 
		&thishs, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (thishs > 0) {
	    ++regdx;
	    lavrhs[regdx - 1] = thishs;
	} else {
	    if (impdx < 600) {
		++impdx;
		if (numhs <= 0) {
/*  build list from first HDX negative integers */
		    lavihs[impdx - 1] = -hdx;
		} else {
		    lavihs[impdx - 1] = thishs;
		}
	    }
	}
/* L100: */
    }
/*  sort them */
    if (regdx > 1) {
	srtiar_(&regdx, lavrhs);
    }
    if (impdx > 1) {
	srtiar_(&impdx, lavihs);
    }
/*  szbt = maximum size of interior bundle table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &szbt, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* *** *** ***  interior style   *** *** *** */
/*  mark start of interior styles */
    nlb (&c__1);
/*  set interior bundle representation */
    i__1 = nalis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsir (&globnu_1.wkid, &ix, &lavis[ix - 1], &c__1, &c__1);
/* L150: */
    }
/*  Display in random order with FILL AREA bundles 1 thru nalis */
    rnperm_(&nalis, perm);
#ifndef NO_PROTO
    yincr = .8f / nalis;
    yloc = .85f;
#else /* NO_PROTO */
    yincr = (float).8 / nalis;
    yloc = (float).85;
#endif /* NO_PROTO */
    numlab_(&nalis, &c_b25, &yloc, &yincr);
    noseg = 7;
#ifndef NO_PROTO
    rad = yincr * .33f;
    centx = .5f;
#else /* NO_PROTO */
    rad = yincr * (float).33;
    centx = (float).5;
#endif /* NO_PROTO */
    i__1 = nalis;
    for (isi = 1; isi <= i__1; ++isi) {
	i__2 = noseg;
	for (siz = 1; siz <= i__2; ++siz) {
#ifndef NO_PROTO
	    ang = (siz << 1) * 3.14159265f / noseg;
#else /* NO_PROTO */
	    ang = (siz << 1) * (float)3.14159265 / noseg;
#endif /* NO_PROTO */
	    xa[siz - 1] = centx + rad * 2 * sin(ang);
	    ya[siz - 1] = yloc + rad * cos(ang);
/* L202: */
	}
	nsii (&perm[isi - 1]);
	nfa (&noseg, xa, ya);
	yloc -= yincr;
/* L200: */
    }
/*  mark end of interior styles */
    nlb (&c__2);
#ifndef NO_PROTO
    setmsg_("3 5 6 7 35 36", "The available interior styles should be recogn"
	    "izable from their standard description.", 13L, 85L);
#else /* NO_PROTO */
    setmsg_("3 5 6 7 35 36", "The available interior styles should be recogn\
izable from their standard description.", 13L, 85L);
#endif /* NO_PROTO */
/*  Operator must identify each interior style according to official */
/*  English description: 0-hollow,1-solid, 2-pattern,3-hatch, 4-empty. */
#ifndef NO_PROTO
    s_copy(prompt, "INTERIOR STYLES: List, in order, the numeric labels for "
	    "interior styles: ", 200L, 73L);
#else /* NO_PROTO */
    s_copy(prompt, "INTERIOR STYLES: List, in order, the numeric labels for \
interior styles: ", 200L, 73L);
#endif /* NO_PROTO */
    i__1 = nalis;
    for (isi = 1; isi <= i__1; ++isi) {
	i__2 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__3[0] = 2, a__1[0] = ", ";
	i__3[1] = 14, a__1[1] = ldesis + lavis[isi - 1] * 14;
	s_cat(prompt + i__2, a__1, i__3, &c__2, 200 - i__2);
	rtans[perm[isi - 1] - 1] = isi;
/* L300: */
    }
    i__1 = itrim_(prompt, 200L);
    s_copy(prompt + i__1, ".", 200 - i__1, 1L);
    dlstpf_(prompt, &nalis, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* *** *** *** interior style index - hatch   *** *** *** */
/* use noaval to check if hatch available */
    if (noaval[3]) {
	inmsg_("Hatch interior style not supported, skip hatch index tests.", 
		59L);
	goto L990;
    }
/*  REGDX = size of lavrhs */
    if (regdx < 1) {
	inmsg_("No registered hatch styles are supported.", 41L);
	goto L890;
    }
/*  select at most 8 hatch styles in lavrhs */
/* Computing MIN */
    i__1 = min(8,regdx);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &regdx, perm);
/*  and sort them */
    srtiar_(&numdis, perm);
/*  set interior bundle representation */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsir (&globnu_1.wkid, &ix, &c__3, &lavrhs[perm[ix - 1] - 1], &c__1);
/* L400: */
    }
/*  Display and label bundles with (some) hatch styles in LAVRHS */
    setrvs_("0.5,0.9,0.9,0.5", xa, &siz, 15L);
#ifndef NO_PROTO
    yincr = .8f / numdis;
    yloc = .85f;
#else /* NO_PROTO */
    yincr = (float).8 / numdis;
    yloc = (float).85;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 2;
	ya[3] = yloc + yincr / 2;
	thishs = lavrhs[perm[ix - 1] - 1];
	s_wsfi(&io___42);
	do_fio(&c__1, "Style#", 6L);
	do_fio(&c__1, (char *)&thishs, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc + yincr * .6f;
#else /* NO_PROTO */
	r__1 = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	vislab_(hatid, "R", &c_b56, &c_b57, &yloc, &r__1, 12L, 1L);
	nsii (&ix);
	nfa (&c__4, xa, ya);
	yloc -= yincr;
/* L500: */
    }
#ifndef NO_PROTO
    setmsg_("3 5 6 7 35 39 40 47 48", "The registered hatch styles (> 0) sho"
	    "uld agree with their registered description.", 22L, 81L);
    dynpf_("REGISTERED HATCH STYLES: Is each hatch style depicted according "
	    "to its numeric identifier's specification in the ISO register?", 
	    "Y", 126L, 1L);
#else /* NO_PROTO */
    setmsg_("3 5 6 7 35 39 40 47 48", "The registered hatch styles (> 0) sho\
uld agree with their registered description.", 22L, 81L);
    dynpf_("REGISTERED HATCH STYLES: Is each hatch style depicted according \
to its numeric identifier's specification in the ISO register?", "Y", 126L, 
	    1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  neg_type: */
L890:
/*  IMPDX = size of lavihs */
    if (impdx < 1) {
	inmsg_("No implementor-defined hatch styles are supported.", 50L);
	goto L903;
    }
/* select at most 8 bundles with hatch styles in lavihs */
/* Computing MIN */
    i__1 = min(8,impdx);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &impdx, perm);
/*  and sort them */
    srtiar_(&numdis, perm);
/*  set interior bundle representation */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsir (&globnu_1.wkid, &ix, &c__3, &lavihs[perm[ix - 1] - 1], &c__1);
/* L600: */
    }
/*  Display AND LABEL BUNDLES WITH (some) hatch styles in LAVIHS */
    setrvs_("0.5,0.9,0.9,0.5", xa, &siz, 15L);
#ifndef NO_PROTO
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 2;
	ya[3] = yloc + yincr / 2;
	thishs = lavihs[perm[ix - 1] - 1];
	s_wsfi(&io___43);
	do_fio(&c__1, "Style#", 6L);
	do_fio(&c__1, (char *)&thishs, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc + yincr * .6f;
#else /* NO_PROTO */
	r__1 = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	vislab_(hatid, "R", &c_b56, &c_b57, &yloc, &r__1, 12L, 1L);
	nsii (&ix);
	nfa (&c__4, xa, ya);
	yloc -= yincr;
/* L700: */
    }
#ifndef NO_PROTO
    setmsg_("3 5 6 7 35 39 40 47 49", "Implementor-defined hatch styles (< 1"
	    ") should agree with the descriptions supplied by the implementor."
	    , 22L, 102L);
    dynpf_("IMPLEMENTOR DEFINED HATCH STYLES: Is each hatch style depicted a"
	    "ccording to its numeric identifier's specification in the implem"
	    "entor documentation?", "Y", 148L, 1L);
#else /* NO_PROTO */
    setmsg_("3 5 6 7 35 39 40 47 49", "Implementor-defined hatch styles (< 1\
) should agree with the descriptions supplied by the implementor.", 22L, 102L)
	    ;
    dynpf_("IMPLEMENTOR DEFINED HATCH STYLES: Is each hatch style depicted a\
ccording to its numeric identifier's specification in the implementor docume\
ntation?", "Y", 148L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* end_hatch_style: */
L903:
/*  check for hatch style 1 - OK to check only 1st position, */
/*  because list is sorted */
    if (lavrhs[0] != 1) {
	inmsg_("No hatch style #1, skip test of unsupported hatch style.", 
		56L);
	goto L990;
    }
/* look for unsupported negative hatch style */
    if (numhs > 0) {
/*  find negative hatch style *not* in LAVIHS and whether zero */
/*  is supported. */
	nozero = TRUE_;
	minihs = 0;
	i__1 = impdx;
	for (hdx = 1; hdx <= i__1; ++hdx) {
	    if (lavihs[hdx - 1] == 0) {
		nozero = FALSE_;
	    }
/* Computing MIN */
	    i__2 = minihs, i__4 = lavihs[hdx - 1];
	    minihs = min(i__2,i__4);
/* L910: */
	}
/*  LUNSUP is list of unsupported hatch styles, indexed by UNSUDX */
	if (nozero) {
	    unsudx = 1;
	    lunsup[unsudx - 1] = 0;
	} else {
	    unsudx = 0;
	}
/*  since this value is less than minimum of LAVIHS, it's unsupported 
*/
	++unsudx;
	lunsup[unsudx - 1] = minihs - 1;
    } else {
/*  all non-positive hatch styles supported - derived directly from */

/*  interior style index value */
	unsudx = 0;
    }
/* now look for unsupported positive hatch style */
    maxrhs = 2;
    i__1 = regdx;
    for (hdx = 1; hdx <= i__1; ++hdx) {
/* Computing MAX */
	i__2 = maxrhs, i__4 = lavrhs[hdx - 1];
	maxrhs = max(i__2,i__4);
/* L920: */
    }
    ++unsudx;
    lunsup[unsudx - 1] = maxrhs + 1;
/*  now add to end of LUNSUP entry #1 and a non-horizontal hatch style */
    ++unsudx;
    lunsup[unsudx - 1] = 1;
/*  other = another available non-horizontal hatch style */
/*  get positive hatch style, if not, get negative style */
/*  this is the only one that should appear as non-horizontal style #1 */
    ++unsudx;
    if (regdx > 1) {
	lunsup[unsudx - 1] = lavrhs[1];
    } else {
	lunsup[unsudx - 1] = lavihs[0];
    }
/*  set interior bundles with mostly unsupported hatch styles */
    i__1 = unsudx;
    for (ix = 1; ix <= i__1; ++ix) {
	nsir (&globnu_1.wkid, &ix, &c__3, &lunsup[ix - 1], &c__1);
/* L750: */
    }
/*  Display in random order bundles 1 thru unsudx */
    rnperm_(&unsudx, perm);
#ifndef NO_PROTO
    xa[0] = .3f;
    xa[1] = .9f;
    xa[2] = .6f;
    yincr = .8f / unsudx;
    yloc = .85f;
    r__1 = yloc + .05f;
#else /* NO_PROTO */
    xa[0] = (float).3;
    xa[1] = (float).9;
    xa[2] = (float).6;
    yincr = (float).8 / unsudx;
    yloc = (float).85;
    r__1 = yloc + (float).05;
#endif /* NO_PROTO */
    numlab_(&unsudx, &c_b25, &r__1, &yincr);
    i__1 = unsudx;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 2;
	nsii (&perm[ix - 1]);
	nfa (&c__3, xa, ya);
	yloc -= yincr;
/* L970: */
    }
#ifndef NO_PROTO
    setmsg_("3 5 6 7 35 39 41", "Unavailable hatch styles should be displaye"
	    "d as hatch style 1.", 16L, 62L);
    dchpf_("UNSUPPORTED HATCH STYLES: Which hatch style is not the horizonta"
	    "l hatch style of index #1?", &unsudx, &unsudx, perm, 90L);
#else /* NO_PROTO */
    setmsg_("3 5 6 7 35 39 41", "Unavailable hatch styles should be displaye\
d as hatch style 1.", 16L, 62L);
    dchpf_("UNSUPPORTED HATCH STYLES: Which hatch style is not the horizonta\
l hatch style of index #1?", &unsudx, &unsudx, perm, 90L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_hatch: */
L990:
/* *** *** ***   interior style index - pattern   *** *** *** */
/* use noavail to check if pattern available */
    if (noaval[2]) {
#ifndef NO_PROTO
	inmsg_("Pattern interior style not supported, skip pattern index tes"
		"ts.", 63L);
#else /* NO_PROTO */
	inmsg_("Pattern interior style not supported, skip pattern index tes\
ts.", 63L);
#endif /* NO_PROTO */
	goto L1900;
    }
#ifndef NO_PROTO
    setmsg_("3 4 5 6 7 35 39 40", "A defined pattern index should cause the "
	    "addressed entry in the pattern table to be used when rendering a"
	    "n interior filled with pattern interior style.", 18L, 151L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 7 35 39 40", "A defined pattern index should cause the \
addressed entry in the pattern table to be used when rendering an interior f\
illed with pattern interior style.", 18L, 151L);
#endif /* NO_PROTO */
/* set 5 patterns (index 1-5): 4 identical and one different */
    pcia[204] = 1;
    pcia[205] = 0;
    pcia[206] = 2;
    pcia[254] = 0;
    pcia[255] = 1;
    pcia[256] = 2;
    for (ix = 1; ix <= 5; ++ix) {
	nspar (&globnu_1.wkid, &ix, &c__50, &c__50, &c__5, &c__5, &c__3, &
		c__2, pcia);
/*  and set up interior bundles */
	nsir (&globnu_1.wkid, &ix, &c__2, &ix, &c__1);
/* L1100: */
    }
/* now randomly set the different pattern */
    diffi = rndint_(&c__1, &c__5);
    pcia[0] = 0;
    pcia[1] = 1;
    pcia[50] = 1;
    pcia[51] = 0;
    nspar (&globnu_1.wkid, &diffi, &c__50, &c__50, &c__1, &c__1, &c__2, &c__2,
	     pcia);
    setrvs_("0.3,0.7,0.7,0.3", xa, &noseg, 15L);
    endpts[0] = noseg;
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .16f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).16;
#endif /* NO_PROTO */
    numlab_(&c__5, &c_b128, &yloc, &yincr);
    for (ix = 1; ix <= 5; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .25f;
	ya[1] = yloc - yincr * .25f;
	ya[2] = yloc + yincr * .25f;
	ya[3] = yloc + yincr * .25f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).25;
	ya[1] = yloc - yincr * (float).25;
	ya[2] = yloc + yincr * (float).25;
	ya[3] = yloc + yincr * (float).25;
#endif /* NO_PROTO */
	nsii (&ix);
/* alternate between PFA and PFAS */
	if (ix % 2 == 1) {
	    nfa (&noseg, xa, ya);
	} else {
	    nfas (&c__1, endpts, xa, ya);
	}
	yloc -= yincr;
/* L1350: */
    }
    dchpfv_("DEFINED PATTERNS: Which pattern is different?", &c__5, &diffi, 
	    45L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* look for 3 undefined pattern indices */
/* loop thru pattern table to determine mdi = the maximum defined index */

/* npi = number of pattern indices */
    nqepai (&globnu_1.wkid, &c__0, &errind, &npi, &idum1);
    chkinq_("pqepai", &errind, 6L);
    mdi = -9999;
    i__1 = npi;
    for (ix = 1; ix <= i__1; ++ix) {
	nqepai (&globnu_1.wkid, &ix, &errind, &idum1, &pai);
	chkinq_("pqepai", &errind, 6L);
	if (mdi < pai) {
	    mdi = pai;
	}
/* L1400: */
    }
/* set up 5 patterns: 3 undefined, index #1, and another */
    unsudx = 5;
/* undpi = undefined pattern index */
    undpi = mdi + 1;
/* lunsup = list of (mostly) unsupported pattern indices */
    lunsup[0] = undpi;
    lunsup[1] = undpi + 1;
    lunsup[2] = undpi + 2;
/* reset pattern for index #1 to checkerboard */
    pcia[0] = 1;
    pcia[1] = 0;
    pcia[50] = 0;
    pcia[51] = 1;
    nspar (&globnu_1.wkid, &c__1, &c__50, &c__50, &c__1, &c__1, &c__2, &c__2, 
	    pcia);
    lunsup[3] = 1;
/* set pattern for index #5 (because we know 1-5 defined above, so this */

/* won't define an undefined index) */
    pcia[0] = 1;
    pcia[1] = 1;
    pcia[50] = 1;
    pcia[51] = 0;
    nspar (&globnu_1.wkid, &c__5, &c__50, &c__50, &c__1, &c__1, &c__2, &c__2, 
	    pcia);
    lunsup[4] = 5;
/*  set interior bundles with mostly unsupported patterns */
    i__1 = unsudx;
    for (ix = 1; ix <= i__1; ++ix) {
	nsir (&globnu_1.wkid, &ix, &c__2, &lunsup[ix - 1], &c__1);
/* L1750: */
    }
/*  Display in random order bundles 1 thru 5 */
    rnperm_(&unsudx, perm);
    setrvs_("0.3,0.9,0.9,0.3", xa, &noseg, 15L);
#ifndef NO_PROTO
    yincr = .8f / unsudx;
    yloc = .85f;
    r__1 = yloc + .05f;
#else /* NO_PROTO */
    yincr = (float).8 / unsudx;
    yloc = (float).85;
    r__1 = yloc + (float).05;
#endif /* NO_PROTO */
    numlab_(&unsudx, &c_b25, &r__1, &yincr);
    i__1 = unsudx;
    for (pai = 1; pai <= i__1; ++pai) {
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 2;
	ya[3] = yloc + yincr / 2;
	nsii (&perm[pai - 1]);
	nfa (&c__4, xa, ya);
	yloc -= yincr;
/* L1500: */
    }
#ifndef NO_PROTO
    setmsg_("3 5 6 7 35 39 41", "Unavailable patterns should be displayed as"
	    " pattern 1.", 16L, 54L);
#else /* NO_PROTO */
    setmsg_("3 5 6 7 35 39 41", "Unavailable patterns should be displayed as\
 pattern 1.", 16L, 54L);
#endif /* NO_PROTO */
    dchpf_("UNDEFINED PATTERNS: Which pattern is different?", &unsudx, &
	    unsudx, perm, 47L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* end_pattern: */
L1900:
/*  *** *** ***   interior color index   *** *** *** */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 7 50 51 52", "A defined interior color index should cau"
	    "se the addressed entry in the color table to be used when render"
	    "ing an interior.", 18L, 121L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 7 50 51 52", "A defined interior color index should cau\
se the addressed entry in the color table to be used when rendering an inter\
ior.", 18L, 121L);
#endif /* NO_PROTO */
    nscmd (&globnu_1.wkid, &c__1);
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcolt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  how many interiors to draw */
    numdis = min(8,szcolt);
/*  from values 2 to SZCOLT-1, pick NUMDIS-2 entries */
    i__1 = numdis - 2;
    i__2 = szcolt - 1;
    rnbset_(&i__1, &c__2, &i__2, facol);
/*  add in 0 and 1 */
    facol[numdis - 2] = 1;
    facol[numdis - 1] = 0;
    rnperm_(&numdis, perm);
/*  from facol, randomly select entry #visdx, but not the one that */
/*    contains 0, since this may not be re-settable. */
    i__1 = numdis - 1;
    visdx = rndint_(&c__1, &i__1);
    viscol = facol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / numdis;
    rad = yincr * .3f;
    centx = rad + .25f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / numdis;
    rad = yincr * (float).3;
    centx = rad + (float).25;
#endif /* NO_PROTO */
    centy = yloc;
    numlab_(&numdis, &c_b128, &yloc, &yincr);
    noseg = 11;
    endpts[0] = noseg;
/*  for each color entry - set to background color */
/*                       - set bundle representation and draw interior */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	isci = facol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &isci, &cdim, bckcol);
/*  set bundle represention */
/*  rotate among available styles: [HOLLOW, SOLID, HATCH] */
	nsir (&globnu_1.wkid, &ix, &intcst[ix % cstsiz], &c__1, &isci);
	i__2 = noseg;
	for (siz = 1; siz <= i__2; ++siz) {
#ifndef NO_PROTO
	    ang = (siz << 1) * 3.14159265f / noseg;
#else /* NO_PROTO */
	    ang = (siz << 1) * (float)3.14159265 / noseg;
#endif /* NO_PROTO */
	    xa[siz - 1] = centx + rad * cos(ang);
	    ya[siz - 1] = centy + rad * sin(ang);
/* L2050: */
	}
	nsii (&ix);
/* alternate between PFA and PFAS */
	if (ix % 2 == 0) {
	    nfa (endpts, xa, ya);
	} else {
	    nfas (&c__1, endpts, xa, ya);
	}
	yloc -= yincr;
	centy = yloc;
/* L2100: */
    }
/*  set entry facol(visdx) to forcol */
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED INTERIOR COLOR INDICES: Which circle is visible?", &
	    numdis, &visdx, perm, 56L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 7 50 51 53", "An undefined interior color index should "
	    "cause entry number 1 in the color table to be used when renderin"
	    "g an interior.", 18L, 119L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 7 50 51 53", "An undefined interior color index should \
cause entry number 1 in the color table to be used when rendering an interio\
r.", 18L, 119L);
#endif /* NO_PROTO */
/*  Try to set entry #1 opposite from BCKCOL */
    for (ix = 1; ix <= 3; ++ix) {
#ifndef NO_PROTO
	if (bckcol[ix - 1] > .5f) {
	    newcol[ix - 1] = 0.f;
#else /* NO_PROTO */
	if (bckcol[ix - 1] > (float).5) {
	    newcol[ix - 1] = (float)0.;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    newcol[ix - 1] = 1.f;
#else /* NO_PROTO */
	    newcol[ix - 1] = (float)1.;
#endif /* NO_PROTO */
	}
/* L2150: */
    }
/*  set entry #1 different from FORCOL - make sure other default */
/*  is to current color-rep of #1, not just a predefined color. */
#ifndef NO_PROTO
    if (forcol[2] > .5f) {
	newcol[2] = 0.f;
#else /* NO_PROTO */
    if (forcol[2] > (float).5) {
	newcol[2] = (float)0.;
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	newcol[2] = 1.f;
#else /* NO_PROTO */
	newcol[2] = (float)1.;
#endif /* NO_PROTO */
    }
    nscr (&globnu_1.wkid, &c__1, &cdim, newcol);
    nqeci (&globnu_1.wkid, &c__0, &errind, &numci, &idum1);
    chkinq_("pqeci", &errind, 5L);
    maxcol = 0;
    i__1 = numci;
    for (ix = 1; ix <= i__1; ++ix) {
	nqeci (&globnu_1.wkid, &ix, &errind, &idum1, &colel);
	chkinq_("pqeci", &errind, 5L);
	maxcol = max(maxcol,colel);
/* L2200: */
    }
/*  undf1,undf2,undf3 = 3 undefined, positive color indices */
    undf[0] = maxcol + 1;
    undf[1] = maxcol + 10;
    undf[2] = maxcol + 90;
/*  explct = number of explicit interiors of color #1 = */
/*  random integer from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    numdis = explct + 3;
    rnperm_(&numdis, perm);
/*  draw star with individual attributes: linetype=1,width=1,color=#1 */
/*  set individual attributes */
    setasf_(&c__1);
    nsln (&c__1);
    nslwsc (&c_b202);
    nsplci (&c__1);
#ifndef NO_PROTO
    rad = .15f;
    centx = .5f;
    centy = .75f;
#else /* NO_PROTO */
    rad = (float).15;
    centx = (float).5;
    centy = (float).75;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	ya[ix - 1] = centy + rad * cos(ix * 12.566370600000001f / 5);
	xa[ix - 1] = centx + rad * sin(ix * 12.566370600000001f / 5);
#else /* NO_PROTO */
	ya[ix - 1] = centy + rad * cos(ix * (float)12.566370600000001 / 5);
	xa[ix - 1] = centx + rad * sin(ix * (float)12.566370600000001 / 5);
#endif /* NO_PROTO */
/* L2400: */
    }
    npl (&c__6, xa, ya);
/*  re-set to bundle attributes */
    setasf_(&c__0);
/*  set edge flag = OFF */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
/*  display interleaved: */
/*    three interiors of color u1,u2,u3, */
/*    explct interiors of color #1 */
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
    xa[0] = .3f;
    xa[1] = .7f;
    xa[2] = .5f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
    xa[0] = (float).3;
    xa[1] = (float).7;
    xa[2] = (float).5;
#endif /* NO_PROTO */
    endpts[0] = 3;
/*  for each color entry - set to background color and draw interior */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nsir (&globnu_1.wkid, &ix, &c__1, &c__1, &undf[colel - 1]);
	} else {
	    nsir (&globnu_1.wkid, &ix, &c__1, &c__1, &c__1);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 2;
	nsii (&ix);
/* alternate between PFA and PFAS */
	if (ix % 2 == 0) {
	    nfa (&c__3, xa, ya);
	} else {
	    nfas (&c__1, endpts, xa, ya);
	}
	yloc -= yincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED INTERIOR COLOR INDICES: How many triangles are the sa"
	    "me color as the star?", &c__12, &numdis, 84L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED INTERIOR COLOR INDICES: How many triangles are the sa\
me color as the star?", &c__12, &numdis, 84L);
#endif /* NO_PROTO */
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

