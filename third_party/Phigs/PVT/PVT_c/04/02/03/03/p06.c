/* fort/04/02/03/03/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b26 = -2.f;
static real c_b27 = 2.f;
#else /* NO_PROTO */
static real c_b26 = (float)-2.;
static real c_b27 = (float)2.;
#endif /* NO_PROTO */
static doublereal c_b28 = 10.;
#ifndef NO_PROTO
static real c_b29 = -1.f;
static real c_b30 = 1.f;
static real c_b32 = -3.f;
static real c_b34 = -.2f;
static real c_b35 = 3.f;
static real c_b40 = .8f;
#else /* NO_PROTO */
static real c_b29 = (float)-1.;
static real c_b30 = (float)1.;
static real c_b32 = (float)-3.;
static real c_b34 = (float)-.2;
static real c_b35 = (float)3.;
static real c_b40 = (float).8;
#endif /* NO_PROTO */
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b113 = 1.5f;
#else /* NO_PROTO */
static real c_b113 = (float)1.5;
#endif /* NO_PROTO */
static integer c__9 = 9;
#ifndef NO_PROTO
static real c_b116 = -.3f;
static real c_b117 = -.1f;
#else /* NO_PROTO */
static real c_b116 = (float)-.3;
static real c_b117 = (float)-.1;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b120 = -.8f;
#else /* NO_PROTO */
static real c_b120 = (float)-.8;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.03/06                        * */
/*  *    TEST TITLE : Appearance of text extent rectangle   * */
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

    static integer lnalgn[3] = { 3,4,2 };

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3], i__3;
    real r__1, r__2, r__3, r__4;
    doublereal d__1;
    char ch__1[111], ch__2[120], ch__3[94];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    double pow_dd();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[5], ya[5], xc, yc, xf[9]	/* was [3][3] */, xh;
    static integer ix;
    static real yh, xl, yl, tx[2], ty[2];
    static char lbl[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntr (real *, 
	    real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntr ();
#endif /* NO_PROTO */
    static integer txp;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real chht, chsp, ccpx, ccpy;
    static integer slen;
    static real chxp, hdst;
    static integer font, txci;
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), nsln ();
#endif /* NO_PROTO */
    static real vdst, ytop, rdum1, rdum2;
    static integer shalf, ngrec;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_();
#endif /* NO_PROTO */
    static real valoc[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), wcnpc_(real *, real *, real *,
	     real *, real *), nbltm (real *, real *, real *, real *, real *, 
	    real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), wcnpc_(), nbltm ();
#endif /* NO_PROTO */
    static integer txalh;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static real xleft;
    static char testc[12];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst ();
#endif /* NO_PROTO */
    static logical horiz;
    static integer txalv;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static char testr[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst ();
#endif /* NO_PROTO */
    static char testv[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), nstxp (
	    integer *), nqtxx (integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *, char *, integer *, real *, real *
	    , real *, real *, ftnlen), setdlg_(integer *, integer *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), nstxp (), nqtxx (), 
	    setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, txplen, numrec;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer dtxalh, dtxalv;
    static real npcpwc, xyincr;
    static char namtxp[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), opmsgw_(char *, ftnlen), nstxfn (
	    integer *), nstxpr (integer *), nstxal (integer *, integer *), 
	    nsplci (integer *), nstxci (integer *), nslwsc (real *), nsatal (
	    integer *, integer *), nsatch (real *), drwrec_(real *, real *, 
	    real *, real *), nschxp (real *), nschsp (real *), chkinq_(char *,
	     integer *, ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), 
	    dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), opmsgw_(), 
	    nstxfn (), nstxpr (), nstxal (), nsplci (), nstxci (), nslwsc (), 
	    nsatal (), nsatch (), drwrec_(), nschxp (), nschsp (), chkinq_(), 
	    setmsg_(), dchpfv_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___34 = { 0, lbl, 0, "(I1,A)", 2, 1 };
    static icilist io___41 = { 0, lbl, 0, "(I1,A)", 2, 1 };
    static icilist io___50 = { 0, lbl, 0, "(I1,A)", 2, 1 };


/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* linetype */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/*  linetypes for various vertical alignments */
    initgl_("04.02.03.03/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
/*  Establish specwt = specific primary workstation type */
    setdlg_(&picstr, &c__801, &txci);
    wcnpc_(&c_b3, &c_b3, &npcx, &npcy, &npcpwc);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Message to operator */
#ifndef NO_PROTO
    opmsgw_("The tests in this program require careful visual inspection.  I"
	    "f you are not familiar with the requirements for text extent and"
	    " alignment, please see the OPERATOR SCRIPT in the documentation "
	    "for this program.", 208L);
#else /* NO_PROTO */
    opmsgw_("The tests in this program require careful visual inspection.  I\
f you are not familiar with the requirements for text extent and alignment, \
please see the OPERATOR SCRIPT in the documentation for this program.", 208L);

#endif /* NO_PROTO */
    s_copy(testr, "Phigs...rules!", 14L, 14L);
    s_copy(testv, "UPPER CASE", 10L, 10L);
    s_copy(testc, "HXHXHXHXHXHX", 12L, 12L);
/*  global attributes */
/*  font (ASCII, possibly non-monospaced) */
    font = 2;
    nstxfn (&font);
    nstxpr (&c__2);
/*  default alignment */
    dtxalh = 2;
    dtxalv = 1;
    nstxal (&dtxalh, &dtxalv);
    nsplci (&c__2);
    nstxci (&c__1);
    nslwsc (&c_b3);
    nsatal (&c__2, &c__3);
#ifndef NO_PROTO
    r__1 = npcpwc * .035f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).035;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*  numrec = number of text extent rectangles per screen */
    numrec = 6;
#ifndef NO_PROTO
    xyincr = 1.f / (numrec + 1);
#else /* NO_PROTO */
    xyincr = (float)1. / (numrec + 1);
#endif /* NO_PROTO */
    ytop = 1 - xyincr;
    xleft = xyincr;
/*  for all text paths, txp = RIGHT,LEFT,UP,DOWN */
    for (txp = 0; txp <= 3; ++txp) {
	if (txp == 0) {
	    horiz = TRUE_;
	    s_copy(namtxp, "RIGHT", 5L, 5L);
	    txplen = 5;
	} else if (txp == 1) {
	    horiz = TRUE_;
	    s_copy(namtxp, "LEFT", 5L, 4L);
	    txplen = 4;
	} else if (txp == 2) {
	    horiz = FALSE_;
	    s_copy(namtxp, "UP", 5L, 2L);
	    txplen = 2;
	} else {
	    horiz = FALSE_;
	    s_copy(namtxp, "DOWN", 5L, 4L);
	    txplen = 4;
	}
#ifndef NO_PROTO
	xl = .2f;
	xh = .9f;
	yl = .1f;
	yh = .8f;
	xc = .1f;
	yc = .9f;
#else /* NO_PROTO */
	xl = (float).2;
	xh = (float).9;
	yl = (float).1;
	yh = (float).8;
	xc = (float).1;
	yc = (float).9;
#endif /* NO_PROTO */
/*  *** *** *** *** ***   text extent rectangle   *** *** *** *** *** 
*/
/*  incorrect entry */
	ngrec = rndint_(&c__1, &numrec);
/*  set text path */
	nstxp (&txp);
	if (horiz) {
	    slen = 14;
	} else {
	    slen = 5;
	}
/*  draw and label text extent rectangles, with text */
	i__1 = numrec;
	for (ix = 1; ix <= i__1; ++ix) {
/*  chht,chxp,chsp = some random values for character height, */
/*    expansion factor, and spacing */
	    d__1 = (doublereal) rndrl_(&c_b26, &c_b27);
	    chht = pow_dd(&c_b28, &d__1);
	    d__1 = (doublereal) rndrl_(&c_b29, &c_b30);
	    chxp = pow_dd(&c_b28, &d__1);
	    if (ix <= 2) {
		chsp = rndrl_(&c_b32, &c_b26);
	    } else {
		chsp = rndrl_(&c_b34, &c_b35);
	    }
	    if (horiz) {
		yc = ytop - (ix - 1) * xyincr;
#ifndef NO_PROTO
		yl = yc - xyincr * .25f;
		yh = yc + xyincr * .25f;
#else /* NO_PROTO */
		yl = yc - xyincr * (float).25;
		yh = yc + xyincr * (float).25;
#endif /* NO_PROTO */
		chsp *= chxp;
	    } else {
		xc = xleft + (ix - 1) * xyincr;
#ifndef NO_PROTO
		xl = xc - xyincr * .25f;
		xh = xc + xyincr * .25f;
#else /* NO_PROTO */
		xl = xc - xyincr * (float).25;
		xh = xc + xyincr * (float).25;
#endif /* NO_PROTO */
	    }
	    drwrec_(&xl, &xh, &yl, &yh);
	    s_wsfi(&io___34);
	    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ":", 1L);
	    e_wsfi();
	    nschxp (&c_b40);
	    nschsp (&c_b3);
	    natr (&xc, &yc, &c_b3, &c_b3, lbl, 2L);
	    nschh (&chht);
	    nschxp (&chxp);
	    nschsp (&chsp);
/*  determine actual rectangle: */
	    nqtxx (&dialog_1.specwt, &font, &chxp, &chsp, &chht, &txp, &
		    dtxalh, &dtxalv, testr, &errind, tx, ty, &ccpx, &ccpy, 
		    slen);
	    chkinq_("pqtxx", &errind, 5L);
/*  apply scale and shift transformation to put testr in next */
/*     text extent rectangle */
	    r__1 = xl - tx[0];
	    r__2 = yl - ty[0];
	    r__3 = (xh - xl) / (tx[1] - tx[0]);
	    r__4 = (yh - yl) / (ty[1] - ty[0]);
	    nbltm (tx, ty, &r__1, &r__2, &c_b3, &r__3, &r__4, &errind, xf);
	    chkinq_("pbltm", &errind, 5L);
	    nslmt (xf, &c__2);
	    if (ix == ngrec) {
/*  apply additional distorting transformation */
#ifndef NO_PROTO
		r__1 = xyincr * .15f;
		r__2 = xyincr * -.15f;
#else /* NO_PROTO */
		r__1 = xyincr * (float).15;
		r__2 = xyincr * (float)-.15;
#endif /* NO_PROTO */
		ntr (&r__1, &r__2, &errind, xf);
		chkinq_("ptr", &errind, 3L);
		nslmt (xf, &c__1);
	    }
	    ntx (&c_b3, &c_b3, testr, slen);
/*  restore identity local transformation */
	    idmat_(&c__3, xf);
	    nslmt (xf, &c__2);
/* L200: */
	}
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 105, a__1[0] = "<Inquire text extent> should accurately re"
		"port the size and position of text primitives when text path"
		" = ";
#else /* NO_PROTO */
	i__2[0] = 105, a__1[0] = "<Inquire text extent> should accurately re\
port the size and position of text primitives when text path = ";
#endif /* NO_PROTO */
	i__2[1] = txplen, a__1[1] = namtxp;
	i__2[2] = 1, a__1[2] = ".";
	s_cat(ch__1, a__1, i__2, &c__3, 111L);
	setmsg_("2 6 7 8 10 15 16", ch__1, 16L, txplen + 106);
#ifndef NO_PROTO
	dchpfv_("ACCURACY OF TEXT EXTENT: Which rectangle does NOT properly "
		"enclose a text primitive?", &numrec, &ngrec, 84L);
#else /* NO_PROTO */
	dchpfv_("ACCURACY OF TEXT EXTENT: Which rectangle does NOT properly \
enclose a text primitive?", &numrec, &ngrec, 84L);
#endif /* NO_PROTO */
	nemst (&c__102);
/*  *** *** *** *** ***   vertical alignment   *** *** *** *** *** */
/*  incorrect entry */
	ngrec = rndint_(&c__1, &numrec);
/*  set text path */
	nstxp (&txp);
	if (horiz) {
	    slen = 10;
	} else {
	    slen = 5;
	}
/*  draw and label vertical alignments with text */
	i__1 = numrec;
	for (ix = 1; ix <= i__1; ++ix) {
/*  chht,chxp,chsp = some random values for character height, */
/*    expansion factor, and spacing */
	    d__1 = (doublereal) rndrl_(&c_b26, &c_b27);
	    chht = pow_dd(&c_b28, &d__1);
	    d__1 = (doublereal) rndrl_(&c_b29, &c_b30);
	    chxp = pow_dd(&c_b28, &d__1);
	    chsp = rndrl_(&c_b34, &c_b27);
	    if (horiz) {
		yc = ytop - (ix - 1) * xyincr;
#ifndef NO_PROTO
		yl = yc - xyincr * .35f;
		yh = yc + xyincr * .35f;
#else /* NO_PROTO */
		yl = yc - xyincr * (float).35;
		yh = yc + xyincr * (float).35;
#endif /* NO_PROTO */
		chsp *= chxp;
	    } else {
		xc = xleft + (ix - 1) * xyincr;
#ifndef NO_PROTO
		xl = xc - xyincr * .25f;
		xh = xc + xyincr * .25f;
#else /* NO_PROTO */
		xl = xc - xyincr * (float).25;
		xh = xc + xyincr * (float).25;
#endif /* NO_PROTO */
	    }
	    s_wsfi(&io___41);
	    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ":", 1L);
	    e_wsfi();
	    nschxp (&c_b40);
	    nschsp (&c_b3);
	    natr (&xc, &yc, &c_b3, &c_b3, lbl, 2L);
	    nschh (&chht);
	    nschxp (&chxp);
	    nschsp (&chsp);
/*  for txalv = TOP,CAP,HALF,BASE */
	    for (txalv = 1; txalv <= 4; ++txalv) {
		nqtxx (&dialog_1.specwt, &font, &chxp, &chsp, &chht, &txp, &
			dtxalh, &txalv, testv, &errind, tx, ty, &ccpx, &ccpy, 
			slen);
		chkinq_("pqtxx", &errind, 5L);
		if (txalv == 1) {
/*  apply scale and shift transformation to put testv in n
ext */
/*     text extent rectangle */
		    r__1 = xl - tx[0];
		    r__2 = yl - ty[0];
		    r__3 = (xh - xl) / (tx[1] - tx[0]);
		    r__4 = (yh - yl) / (ty[1] - ty[0]);
		    nbltm (tx, ty, &r__1, &r__2, &c_b3, &r__3, &r__4, &errind,
			     xf);
		    chkinq_("pbltm", &errind, 5L);
		    nslmt (xf, &c__2);
		    xa[0] = tx[0];
		    xa[1] = tx[1];
		} else {
/*  determine location of capline,halfline,baseline */
		    valoc[txalv - 2] = ty[1];
		}
/*  next txalv */
/* L350: */
	    }
/*  draw expected capline,halfline,baseline */
	    for (txalv = 2; txalv <= 4; ++txalv) {
		ya[0] = -(doublereal)valoc[txalv - 2];
		ya[1] = ya[0];
		nsln (&lnalgn[txalv - 2]);
		npl (&c__2, xa, ya);
/* L380: */
	    }
	    if (ix == ngrec) {
/*  apply additional distorting transformation */
#ifndef NO_PROTO
		r__1 = ((rndint_(&c__0, &c__1) << 1) - 1) * .15f * xyincr;
#else /* NO_PROTO */
		r__1 = ((rndint_(&c__0, &c__1) << 1) - 1) * (float).15 * 
			xyincr;
#endif /* NO_PROTO */
		ntr (&c_b3, &r__1, &errind, xf);
		chkinq_("ptr", &errind, 3L);
		nslmt (xf, &c__1);
	    }
	    ntx (&c_b3, &c_b3, testv, slen);
/*  restore identity local transformation */
	    idmat_(&c__3, xf);
	    nslmt (xf, &c__2);
/* L300: */
	}
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 114, a__1[0] = "<Inquire text extent> should accurately re"
		"port the vertical alignment values for text primitives when "
		"text path = ";
#else /* NO_PROTO */
	i__2[0] = 114, a__1[0] = "<Inquire text extent> should accurately re\
port the vertical alignment values for text primitives when text path = ";
#endif /* NO_PROTO */
	i__2[1] = txplen, a__1[1] = namtxp;
	i__2[2] = 1, a__1[2] = ".";
	s_cat(ch__2, a__1, i__2, &c__3, 120L);
	setmsg_("2 6 7 8 10 11", ch__2, 13L, txplen + 115);
#ifndef NO_PROTO
	dchpfv_("ACCURACY OF VERTICAL ALIGNMENTS: Which text primitive does "
		"NOT have a properly aligned capline (dotted), halfline (dash"
		"ed-dotted), or baseline (dashed)?", &numrec, &ngrec, 152L);
#else /* NO_PROTO */
	dchpfv_("ACCURACY OF VERTICAL ALIGNMENTS: Which text primitive does \
NOT have a properly aligned capline (dotted), halfline (dashed-dotted), or b\
aseline (dashed)?", &numrec, &ngrec, 152L);
#endif /* NO_PROTO */
	nemst (&c__102);
/*  *** *** *** *** ***   concatenation point   *** *** *** *** *** */

/*  incorrect entry */
	ngrec = rndint_(&c__1, &numrec);
/*  set text path */
	nstxp (&txp);
	txalh = 0;
	txalv = 0;
#ifndef NO_PROTO
	hdst = 0.f;
	vdst = 0.f;
#else /* NO_PROTO */
	hdst = (float)0.;
	vdst = (float)0.;
#endif /* NO_PROTO */
	if (horiz) {
	    slen = 12;
	    txalv = 3;
#ifndef NO_PROTO
	    hdst = (rndint_(&c__0, &c__1) - .5f) * 3;
#else /* NO_PROTO */
	    hdst = (rndint_(&c__0, &c__1) - (float).5) * 3;
#endif /* NO_PROTO */
	} else {
	    slen = 6;
	    txalh = 3;
#ifndef NO_PROTO
	    vdst = (rndint_(&c__0, &c__1) - .5f) * 4;
#else /* NO_PROTO */
	    vdst = (rndint_(&c__0, &c__1) - (float).5) * 4;
#endif /* NO_PROTO */
	}
	nstxal (&txalh, &txalv);
/*  draw and label concatenated text */
	i__1 = numrec;
	for (ix = 1; ix <= i__1; ++ix) {
/*  chht,chxp,chsp = some random values for character height, */
/*    expansion factor, and spacing */
	    d__1 = (doublereal) rndrl_(&c_b26, &c_b27);
	    chht = pow_dd(&c_b28, &d__1);
	    d__1 = (doublereal) rndrl_(&c_b29, &c_b30);
	    chxp = pow_dd(&c_b28, &d__1);
	    chsp = rndrl_(&c_b40, &c_b113);
	    if (horiz) {
		yc = ytop - (ix - 1) * xyincr;
#ifndef NO_PROTO
		yl = yc - xyincr * .35f;
		yh = yc + xyincr * .35f;
#else /* NO_PROTO */
		yl = yc - xyincr * (float).35;
		yh = yc + xyincr * (float).35;
#endif /* NO_PROTO */
		shalf = rndint_(&c__3, &c__9);
		if (ix > 3) {
		    chsp = rndrl_(&c_b116, &c_b117);
		}
		chsp *= chxp;
	    } else {
		xc = xleft + (ix - 1) * xyincr;
#ifndef NO_PROTO
		xl = xc - xyincr * .25f;
		xh = xc + xyincr * .25f;
#else /* NO_PROTO */
		xl = xc - xyincr * (float).25;
		xh = xc + xyincr * (float).25;
#endif /* NO_PROTO */
		shalf = rndint_(&c__2, &c__4);
		if (ix > 3) {
		    chsp = rndrl_(&c_b120, &c_b116);
		}
	    }
	    s_wsfi(&io___50);
	    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ":", 1L);
	    e_wsfi();
	    nschxp (&c_b40);
	    nschsp (&c_b3);
	    natr (&xc, &yc, &c_b3, &c_b3, lbl, 2L);
	    nschh (&chht);
	    nschxp (&chxp);
	    nschsp (&chsp);
/*  determine text extent rectangle */
	    nqtxx (&dialog_1.specwt, &font, &chxp, &chsp, &chht, &txp, &txalh,
		     &txalv, testc, &errind, tx, ty, &rdum1, &rdum2, slen);
	    chkinq_("pqtxx", &errind, 5L);
/*  apply scale and shift transformation to put testr1 in next */
/*    labelled location */
	    r__1 = xl - tx[0];
	    r__2 = yl - ty[0];
	    r__3 = (xh - xl) / (tx[1] - tx[0]);
	    r__4 = (yh - yl) / (ty[1] - ty[0]);
	    nbltm (tx, ty, &r__1, &r__2, &c_b3, &r__3, &r__4, &errind, xf);
	    chkinq_("pbltm", &errind, 5L);
	    nslmt (xf, &c__2);
	    ntx (&c_b3, &c_b3, testc, shalf);
	    if (ix == ngrec) {
/*  apply additional distorting transformation */
#ifndef NO_PROTO
		r__1 = hdst * .15f * xyincr;
		r__2 = vdst * .15f * xyincr;
#else /* NO_PROTO */
		r__1 = hdst * (float).15 * xyincr;
		r__2 = vdst * (float).15 * xyincr;
#endif /* NO_PROTO */
		ntr (&r__1, &r__2, &errind, xf);
		chkinq_("ptr", &errind, 3L);
		nslmt (xf, &c__1);
	    }
/*  determine concatenation point = ccpx,ccpy */
	    nqtxx (&dialog_1.specwt, &font, &chxp, &chsp, &chht, &txp, &txalh,
		     &txalv, testc, &errind, tx, ty, &ccpx, &ccpy, shalf);
	    chkinq_("pqtxx", &errind, 5L);
/*  display text primitive = testr2 at ccpx,ccpy */
	    i__3 = shalf;
	    ntx (&ccpx, &ccpy, testc + i__3, slen - i__3);
/*  restore identity local transformation */
	    idmat_(&c__3, xf);
	    nslmt (xf, &c__2);
/* L400: */
	}
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 88, a__1[0] = "<Inquire text extent> should accurately rep"
		"ort the concatenation point when text path = ";
#else /* NO_PROTO */
	i__2[0] = 88, a__1[0] = "<Inquire text extent> should accurately rep\
ort the concatenation point when text path = ";
#endif /* NO_PROTO */
	i__2[1] = txplen, a__1[1] = namtxp;
	i__2[2] = 1, a__1[2] = ".";
	s_cat(ch__3, a__1, i__2, &c__3, 94L);
	setmsg_("2 6 7 8 10 11 12 17 18", ch__3, 22L, txplen + 89);
#ifndef NO_PROTO
	dchpfv_("ACCURACY OF CONCATENATION POINT: In which text primitive ar"
		"e the characters NOT aligned and evenly separated?", &numrec, 
		&ngrec, 109L);
#else /* NO_PROTO */
	dchpfv_("ACCURACY OF CONCATENATION POINT: In which text primitive ar\
e the characters NOT aligned and evenly separated?", &numrec, &ngrec, 109L);
#endif /* NO_PROTO */
	nemst (&c__102);
/*  next text path */
/* L100: */
    }
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

