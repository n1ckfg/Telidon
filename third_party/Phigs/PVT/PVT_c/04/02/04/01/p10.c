/* fort/04/02/04/01/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b3 = 0.f;
#else /* NO_PROTO */
static real c_b3 = (float)0.;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b9 = .7f;
static real c_b10 = .1f;
#else /* NO_PROTO */
static real c_b9 = (float).7;
static real c_b10 = (float).1;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b13 = .03f;
#else /* NO_PROTO */
static real c_b13 = (float).03;
#endif /* NO_PROTO */
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b29 = .2f;
#else /* NO_PROTO */
static real c_b29 = (float).2;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.01/10                        * */
/*  *    TEST TITLE : Annotation style                      * */
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
    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];
    real r__1, r__2;
    logical L__1;
    char ch__1[1741];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[20], ya[20], xb[20], yb[20];
    static integer ix;
    static real xo[20], yo[20];
    static integer adx;
    static char msg[1600];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *), ntx (real *, real *, char *, ftnlen), ifpf_(
	    logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm (), ntx (), ifpf_();
#endif /* NO_PROTO */
    static integer lnid, perm[20];
    static real yloc;
    static integer txci;
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), nsmk (integer *), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), nsmk (), nsln ();
#endif /* NO_PROTO */
    static integer idum1, idum2;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    endit_(void), nschh (real *), nqanf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), endit_(), nschh (), nqanf ();
#endif /* NO_PROTO */
    static integer lncol, regdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int wcnpc_();
#endif /* NO_PROTO */
    static real lwscf;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer numas, stddx, impdx;
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static real nomlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsans (integer *), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsans (), nemst ();
#endif /* NO_PROTO */
    static integer numlt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nspli (integer *), nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplf (), nspli (), nexst (), nopst ();
#endif /* NO_PROTO */
    static integer lntyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsplr (integer *, integer *, integer *, real *
	    , integer *), nsvwi (integer *), dynpf_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsplr (), nsvwi (), dynpf_();
#endif /* NO_PROTO */
    static integer lavias[300];
    static real anoffx;
    static integer errind, numlin, ngstyl, truans, minans, maxans, anstyl, 
	    thisas, lavras[20], lavsas[2], lunsup[10], unsudx;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer picstr;
    static real npcpwc, anoffy;
    static logical ansavl[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), setasf_(
	    integer *), nstxfn (integer *), nstxpr (integer *), nschxp (real *
	    ), nschsp (real *), nsatch (real *), nsatal (integer *, integer *)
	    , nstxal (integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), rnperm_(integer 
	    *, integer *), numlab_(integer *, real *, real *, real *), 
	    dchpfv_(char *, integer *, integer *, ftnlen), nslwsc (real *), 
	    nsplci (integer *), nsiasf (integer *, integer *), dsanst_(
	    integer *, integer *), srtiar_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), setasf_(), 
	    nstxfn (), nstxpr (), nschxp (), nschsp (), nsatch (), nsatal (), 
	    nstxal (), chkinq_(), setmsg_(), rnperm_(), numlab_(), dchpfv_(), 
	    nslwsc (), nsplci (), nsiasf (), dsanst_(), srtiar_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___48 = { 0, msg, 0, "(500I5)", 1600, 1 };


/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* linetype */
/* marker type */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
/* annotation style */
    initgl_("04.02.04.01/10", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    wcnpc_(&c_b3, &c_b3, &npcx, &npcy, &npcpwc);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  defaults */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nschxp (&c_b9);
    nschsp (&c_b10);
/*  geometric attributes for annotation text */
#ifndef NO_PROTO
    r__1 = npcpwc * .03f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).03;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatal (&c__3, &c__3);
/*  geometric attributes for text */
    nschh (&c_b13);
    nstxal (&c__3, &c__3);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*  use <inquire annotation facilities> to determine: */
/*    numas  = number of available annotation styles */
/*    lavsas = list of available standard annotation styles */
/*   lavras = list of available registered (non-mandatory) annotation styl
es*/
/*    lavias = list of available implementor-defined annotation styles */
    nqanf (&dialog_1.specwt, &c__1, &errind, &numas, &minans, &idum2, &rdum1, 
	    &rdum2);
    chkinq_("pqanf", &errind, 5L);
    maxans = minans;
    stddx = 0;
    regdx = 0;
    impdx = 0;
    ansavl[0] = FALSE_;
    ansavl[1] = FALSE_;
    ansavl[2] = FALSE_;
    i__1 = numas;
    for (adx = 1; adx <= i__1; ++adx) {
	nqanf (&dialog_1.specwt, &adx, &errind, &idum1, &thisas, &idum2, &
		rdum1, &rdum2);
	chkinq_("pqanf", &errind, 5L);
	minans = min(minans,thisas);
	maxans = max(maxans,thisas);
	if (thisas > 2) {
	    ++regdx;
	    lavras[regdx - 1] = thisas;
	} else if (thisas > 0) {
	    ++stddx;
	    lavsas[stddx - 1] = thisas;
	    ansavl[thisas] = TRUE_;
	} else {
	    if (thisas == 0) {
		ansavl[0] = TRUE_;
	    }
	    if (impdx < 300) {
		++impdx;
		lavias[impdx - 1] = thisas;
	    }
	}
/* L150: */
    }
#ifndef NO_PROTO
    setmsg_("77", "The list of available annotation styles returned by <inqu"
	    "ire annotation facilities> should include styles number 1 and 2.",
	     2L, 121L);
#else /* NO_PROTO */
    setmsg_("77", "The list of available annotation styles returned by <inqu\
ire annotation facilities> should include styles number 1 and 2.", 2L, 121L);
#endif /* NO_PROTO */
    L__1 = ansavl[1] && ansavl[2];
    ifpf_(&L__1);
#ifndef NO_PROTO
    dline_("Throughout this program, when an annotation text primitive is di"
	    "splayed, its reference point is marked with an asterisk polymark"
	    "er, and its annotation point with a circle polymarker (enter any"
	    "thing to continue).", msg, 211L, 1600L);
#else /* NO_PROTO */
    dline_("Throughout this program, when an annotation text primitive is di\
splayed, its reference point is marked with an asterisk polymarker, and its \
annotation point with a circle polymarker (enter anything to continue).", msg,
	     211L, 1600L);
#endif /* NO_PROTO */
    if (! ansavl[1]) {
	inmsg_("Skipping tests for annotation style #1: not available.", 54L);

	goto L300;
    }
/*  *** *** ***   style #1 (unconnected)   *** *** *** */
/*  set up perm to randomize order */
    numlin = 6;
    rnperm_(&numlin, perm);
/*  ngstyl = random integer from 1 to 3 */
    ngstyl = rndint_(&c__1, &c__3);
/*  display interspersed 3 actual and 3 simulated examples of style #1, */

/*    with actual #ngstyl done incorrectly (use style #2) */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    numlab_(&numlin, &c_b29, &yloc, &yincr);
/*  annotation offsets in WC */
#ifndef NO_PROTO
    anoffx = -.2f;
    anoffy = yincr * .3f;
#else /* NO_PROTO */
    anoffx = (float)-.2;
    anoffy = yincr * (float).3;
#endif /* NO_PROTO */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  mark reference and annotation point */
#ifndef NO_PROTO
	xo[ix - 1] = .5f;
#else /* NO_PROTO */
	xo[ix - 1] = (float).5;
#endif /* NO_PROTO */
	yo[ix - 1] = yloc;
	xa[ix - 1] = xo[ix - 1] - anoffx;
	ya[ix - 1] = yo[ix - 1] - anoffy;
	lnid = perm[ix - 1];
	if (lnid > 3) {
/*  do simulation */
	    ntx (&xo[ix - 1], &yo[ix - 1], "Primitive", 9L);
	} else {
/*  do actual */
	    if (lnid == ngstyl) {
		anstyl = 2;
		truans = ix;
	    } else {
		anstyl = 1;
	    }
	    nsans (&anstyl);
	    r__1 = anoffx * npcpwc;
	    r__2 = anoffy * npcpwc;
	    natr (&xa[ix - 1], &ya[ix - 1], &r__1, &r__2, "Primitive", 9L);
	}
	yloc -= yincr;
/* L200: */
    }
    nsmk (&c__3);
    npm (&numlin, xa, ya);
    nsmk (&c__4);
    npm (&numlin, xo, yo);
#ifndef NO_PROTO
    setmsg_("1 2 5 75 76 78 80", "The mandatory annotation style number 1 sh"
	    "ould leave the reference point and the annotation point of the a"
	    "nnotation text primitive unconnected.", 17L, 143L);
#else /* NO_PROTO */
    setmsg_("1 2 5 75 76 78 80", "The mandatory annotation style number 1 sh\
ould leave the reference point and the annotation point of the annotation te\
xt primitive unconnected.", 17L, 143L);
#endif /* NO_PROTO */
    dchpfv_("ANNOTATION STYLE 1: Which annotation style is different?", &
	    numlin, &truans, 56L);
    nemst (&c__102);
    if (! ansavl[2]) {
	goto L300;
    }
/*  lunsup = list of (mostly) unsupported annotation styles, contains: */
/*    a negative unsupported type (< minimum in lavias) */
/*    a positive unsupported type (> maximum in lavras) */
/*    1, */
/*    2, if supported (the only non-#1 style) */
/*    0, if not in lavias */
    lunsup[0] = minans - 10;
    lunsup[1] = maxans + 1;
    lunsup[2] = 1;
    lunsup[3] = 2;
    if (ansavl[0]) {
	unsudx = 4;
    } else {
	unsudx = 5;
	lunsup[4] = 0;
    }
/*  Display in random order annotation styles from lunsup */
/*  set up perm to randomize order */
    rnperm_(&unsudx, perm);
#ifndef NO_PROTO
    yincr = 1.f / (unsudx + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (unsudx + 1);
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    numlab_(&unsudx, &c_b29, &yloc, &yincr);
    i__1 = unsudx;
    for (ix = 1; ix <= i__1; ++ix) {
	anstyl = lunsup[perm[ix - 1] - 1];
	if (anstyl == 2) {
	    truans = ix;
	}
/*  mark reference and annotation point */
#ifndef NO_PROTO
	xo[ix - 1] = .5f;
#else /* NO_PROTO */
	xo[ix - 1] = (float).5;
#endif /* NO_PROTO */
	yo[ix - 1] = yloc;
	xa[ix - 1] = xo[ix - 1] - anoffx;
	ya[ix - 1] = yo[ix - 1] - anoffy;
	nsans (&anstyl);
	r__1 = anoffx * npcpwc;
	r__2 = anoffy * npcpwc;
	natr (&xa[ix - 1], &ya[ix - 1], &r__1, &r__2, "Primitive", 9L);
	yloc -= yincr;
/* L220: */
    }
    nsmk (&c__3);
    npm (&unsudx, xa, ya);
    nsmk (&c__4);
    npm (&unsudx, xo, yo);
#ifndef NO_PROTO
    setmsg_("5 75 76 78 79 80", "Unavailable annotation styles should be dis"
	    "played as annotation style number 1.", 16L, 79L);
    dchpfv_("UNSUPPORTED ANNOTATION STYLE: Which annotation style is differe"
	    "nt?", &unsudx, &truans, 66L);
#else /* NO_PROTO */
    setmsg_("5 75 76 78 79 80", "Unavailable annotation styles should be dis\
played as annotation style number 1.", 16L, 79L);
    dchpfv_("UNSUPPORTED ANNOTATION STYLE: Which annotation style is differe\
nt?", &unsudx, &truans, 66L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  end_style_1: */
L300:
/*  *** *** ***   style #2 (connected)   *** *** *** */
    if (! ansavl[2]) {
	inmsg_("Skipping tests for annotation style #2: not available.", 54L);

	goto L400;
    }
/*  set up perm to randomize order */
    numlin = 6;
    rnperm_(&numlin, perm);
/*  ngstyl = random integer from 1 to 3 */
    ngstyl = rndint_(&c__1, &c__3);
/*  display interspersed 3 actual and 3 simulated examples of style #2, */

/*    with actual #ngstyl done incorrectly (use style #1) */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    numlab_(&numlin, &c_b29, &yloc, &yincr);
/*  set up exciting polyline attributes */
    nqplf (&dialog_1.specwt, &c__0, &errind, &numlt, &idum1, &idum2, &nomlw, &
	    rdum1, &rdum2, &idum2);
    chkinq_("pqplf", &errind, 5L);
    i__2 = abs(numlt);
    i__1 = rndint_(&c__1, &i__2);
    nqplf (&dialog_1.specwt, &i__1, &errind, &numlt, &lntyp, &idum2, &nomlw, &
	    rdum1, &rdum2, &idum2);
    chkinq_("pqplf", &errind, 5L);
#ifndef NO_PROTO
    lwscf = .02f / (nomlw * dialog_1.wcpdc);
#else /* NO_PROTO */
    lwscf = (float).02 / (nomlw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    lncol = 2;
/*  set linetype/width thru bundle, color individually */
    i__1 = lntyp + 1;
    nsln (&i__1);
    r__1 = lwscf * 2;
    nslwsc (&r__1);
    nsplci (&lncol);
    nspli (&c__2);
    i__1 = lncol - 1;
    nsplr (&globnu_1.wkid, &c__2, &lntyp, &lwscf, &i__1);
    nsiasf (&c__0, &c__0);
    nsiasf (&c__1, &c__0);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  mark reference and annotation point */
#ifndef NO_PROTO
	xo[ix - 1] = .5f;
#else /* NO_PROTO */
	xo[ix - 1] = (float).5;
#endif /* NO_PROTO */
	yo[ix - 1] = yloc;
	xa[ix - 1] = xo[ix - 1] - anoffx;
	ya[ix - 1] = yo[ix - 1] - anoffy;
	lnid = perm[ix - 1];
	if (lnid > 3) {
/*  do simulation */
	    ntx (&xo[ix - 1], &yo[ix - 1], "Primitive", 9L);
	    xb[0] = xa[ix - 1];
	    yb[0] = ya[ix - 1];
	    xb[1] = xo[ix - 1];
	    yb[1] = yo[ix - 1];
	    npl (&c__2, xb, yb);
	} else {
/*  do actual */
	    if (lnid == ngstyl) {
		anstyl = 1;
		truans = ix;
	    } else {
		anstyl = 2;
	    }
	    nsans (&anstyl);
	    r__1 = anoffx * npcpwc;
	    r__2 = anoffy * npcpwc;
	    natr (&xa[ix - 1], &ya[ix - 1], &r__1, &r__2, "Primitive", 9L);
	}
	yloc -= yincr;
/* L310: */
    }
    nsmk (&c__3);
    npm (&numlin, xa, ya);
    nsmk (&c__4);
    npm (&numlin, xo, yo);
#ifndef NO_PROTO
    setmsg_("1 2 5 75 76 78 80", "The mandatory annotation style number 2 sh"
	    "ould connect the reference point and annotation point with a pol"
	    "yline, using the current attributes.", 17L, 142L);
#else /* NO_PROTO */
    setmsg_("1 2 5 75 76 78 80", "The mandatory annotation style number 2 sh\
ould connect the reference point and annotation point with a polyline, using\
 the current attributes.", 17L, 142L);
#endif /* NO_PROTO */
    dchpfv_("ANNOTATION STYLE 2: Which annotation style is different?", &
	    numlin, &truans, 56L);
    nemst (&c__102);
/*  end_style_2: */
L400:
/*  *** *** ***   registered styles   *** *** *** */
/*  regdx = size of lavras */
    if (regdx < 1) {
	inmsg_("No registered annotation styles are supported.", 46L);
	goto L800;
    }
/* display and label at most 8 annotation styles in lavras */
    dsanst_(&regdx, lavras);
#ifndef NO_PROTO
    setmsg_("5 75 76 78 81", "The registered non-mandatory annotation styles"
	    " (> 2) should agree with their registered description.", 13L, 
	    100L);
    dynpf_("NON-MANDATORY REGISTERED ANNOTATION STYLES: Is each annotation s"
	    "tyle depicted according to its numeric identifier's specificatio"
	    "n in the ISO register?", "Y", 150L, 1L);
#else /* NO_PROTO */
    setmsg_("5 75 76 78 81", "The registered non-mandatory annotation styles\
 (> 2) should agree with their registered description.", 13L, 100L);
    dynpf_("NON-MANDATORY REGISTERED ANNOTATION STYLES: Is each annotation s\
tyle depicted according to its numeric identifier's specification in the ISO\
 register?", "Y", 150L, 1L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  neg_type: */
L800:
/*  *** *** ***   implementor-defined styles   *** *** *** */
/*  impdx = size of lavias */
    if (impdx < 1) {
	inmsg_("No implementor defined annotation styles are supported.", 55L)
		;
	goto L666;
    }
/* display and label at most 8 annotation styles in lavias */
    dsanst_(&impdx, lavias);
#ifndef NO_PROTO
    setmsg_("5 75 76 78 82", "Implementor-defined annotation styles (< 1) sh"
	    "ould agree with the descriptions supplied by the implementor.", 
	    13L, 107L);
    dynpf_("IMPLEMENTOR DEFINED ANNOTATION STYLES: Is each annotation style "
	    "depicted according to its numeric identifier's specification in "
	    "the implementor documentation?", "Y", 158L, 1L);
#else /* NO_PROTO */
    setmsg_("5 75 76 78 82", "Implementor-defined annotation styles (< 1) sh\
ould agree with the descriptions supplied by the implementor.", 13L, 107L);
    dynpf_("IMPLEMENTOR DEFINED ANNOTATION STYLES: Is each annotation style \
depicted according to its numeric identifier's specification in the implemen\
tor documentation?", "Y", 158L, 1L);
#endif /* NO_PROTO */
    nemst (&c__102);
    if (impdx <= 8) {
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("82", "All reported implementor-defined annotation styles availa"
	    "ble for a given workstation type should be documented by the imp"
	    "lementor.", 2L, 130L);
#else /* NO_PROTO */
    setmsg_("82", "All reported implementor-defined annotation styles availa\
ble for a given workstation type should be documented by the implementor.", 
	    2L, 130L);
#endif /* NO_PROTO */
    srtiar_(&impdx, lavias);
    s_wsfi(&io___48);
    i__1 = impdx;
    for (ix = 1; ix <= i__1; ++ix) {
	do_fio(&c__1, (char *)&lavias[ix - 1], (ftnlen)sizeof(integer));
    }
    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
    i__3[0] = 141, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR ANNOTAT"
	    "ION STYLES: Are all these reportedly available annotation styles"
	    " documented by the implementor?";
#else /* NO_PROTO */
    i__3[0] = 141, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR ANNOTAT\
ION STYLES: Are all these reportedly available annotation styles documented \
by the implementor?";
#endif /* NO_PROTO */
    i__3[1] = 1600, a__1[1] = msg;
    s_cat(ch__1, a__1, i__3, &c__2, 1741L);
    dynpf_(ch__1, "Y", 1741L, 1L);
/*  end_annotation_style: */
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

