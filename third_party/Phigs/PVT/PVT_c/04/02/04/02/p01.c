/* fort/04/02/04/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b6 = 0.f;
#else /* NO_PROTO */
static real c_b6 = (float)0.;
#endif /* NO_PROTO */
static integer c__7 = 7;
static integer c__6 = 6;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b40 = .2f;
static real c_b47 = .02f;
static real c_b48 = .15f;
static real c_b51 = .4f;
static real c_b52 = .5f;
static real c_b55 = .53f;
static real c_b56 = .63f;
static real c_b59 = .66f;
static real c_b60 = .76f;
static real c_b64 = .86f;
static real c_b68 = .96f;
#else /* NO_PROTO */
static real c_b40 = (float).2;
static real c_b47 = (float).02;
static real c_b48 = (float).15;
static real c_b51 = (float).4;
static real c_b52 = (float).5;
static real c_b55 = (float).53;
static real c_b56 = (float).63;
static real c_b59 = (float).66;
static real c_b60 = (float).76;
static real c_b64 = (float).86;
static real c_b68 = (float).96;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.02/01                        * */
/*  *    TEST TITLE : Appearance of predefined text         * */
/*  *                 bundles                               * */
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
    static char precnm[6*3] = "STRING" "CHAR  " "STROKE";
#else /* NO_PROTO */
    static char precnm[6*3+1] = "STRINGCHAR  STROKE";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];
    real r__1;

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
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
    extern logical dyn_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
    extern logical dyn_();
#endif /* NO_PROTO */
    static integer pdci, clen, pdfn;
    static real pdex;
    static integer pdpr, txci;
    static real yloc, pdsp, npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real ybot;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static real ytop;
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nscmd ();
#endif /* NO_PROTO */
    static char lntid[40];
#ifndef NO_PROTO
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int wcnpc_();
#endif /* NO_PROTO */
    static integer nprei;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), dynpf_(char *, char *,
	     ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), dynpf_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *), nopst (integer *), nstxi (
	    integer *), nsvwi (integer *), ndellb (integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxf (), nopst (), nstxi (), nsvwi (), 
	    ndellb ();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), dchpfv_(
	    char *, integer *, integer *, ftnlen), setdlg_(integer *, integer 
	    *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), dchpfv_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numbun, bundis[8];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), rnperm_(integer *, integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), drwatx_(integer *, 
	    integer *, integer *), distxb_(integer *, integer *, integer *, 
	    integer *), srtiar_(integer *, integer *), nsatch (real *), 
	    nsatal (integer *, integer *), vislab_(char *, char *, real *, 
	    real *, real *, real *, ftnlen, ftnlen), nqptxr (integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), rnperm_(), 
	    setmsg_(), drwatx_(), distxb_(), srtiar_(), nsatch (), nsatal (), 
	    vislab_(), nqptxr (), opfail_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___32 = { 0, lntid, 0, "(I5,A)", 40, 1 };
    static icilist io___33 = { 0, lntid, 0, "(I5)", 40, 1 };
    static icilist io___35 = { 0, lntid, 0, "(I5)", 40, 1 };
    static icilist io___36 = { 0, lntid, 0, "(F7.3)", 40, 1 };
    static icilist io___37 = { 0, lntid, 0, "(F7.3)", 40, 1 };
    static icilist io___38 = { 0, lntid, 0, "(I5)", 40, 1 };


/* aspect source */
/*                bundled     individual */
/* text precision */
/* colour model */
/* text alignment horizontal */
/* text alignment vertical */
    initgl_("04.02.04.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nscmd (&globnu_1.wkid, &c__1);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use bundled attributes */
    setasf_(&c__0);
/*  get ratio of NPC and WC */
    wcnpc_(&c_b6, &c_b6, &npcx, &npcy, &npcpwc);
/*  nprei = number of predefined text bundles */
    nqtxf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &idum4, &
	    rdum1, &rdum2, &idum5, &rdum3, &rdum4, &nprei);
    chkinq_("pqtxf", &errind, 5L);
/* *** *** *** *** predefined text bundles 1-6 */
/*  mark start of text bundles 1-6 */
    nlb (&c__1);
/*  use first 6 indices + 1 duplicate */
    numbun = 7;
    rnperm_(&c__7, bundis);
/*  location of #7 */
    bundif = iarfnd_(&c__7, &c__7, bundis);
    bundis[bundif - 1] = rndint_(&c__1, &c__6);
#ifndef NO_PROTO
    setmsg_("1 4 8 9", "Immediately after <open workstation>, the first 6 de"
	    "fined text bundles of the WSL should appear as specified in the "
	    "corresponding predefined text bundles of the WDT.", 7L, 165L);
#else /* NO_PROTO */
    setmsg_("1 4 8 9", "Immediately after <open workstation>, the first 6 de\
fined text bundles of the WSL should appear as specified in the correspondin\
g predefined text bundles of the WDT.", 7L, 165L);
#endif /* NO_PROTO */
    drwatx_(&numbun, bundis, &bundif);
/*  mark end of bundles 1-6 */
    nlb (&c__2);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-6: Whi"
	    "ch pair of annotation text relative primitives does NOT match?", &
	    numbun, &bundif, 125L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-6: Whi\
ch pair of annotation text relative primitives does NOT match?", &numbun, &
	    bundif, 125L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* *** *** *** *** predefined text bundles > 6 */
/*  skip if there are only 6 bundles */
    if (nprei <= 6) {
#ifndef NO_PROTO
	inmsg_("Skip test of bundles > 6, only 6 predefined bundles supporte"
		"d.", 62L);
#else /* NO_PROTO */
	inmsg_("Skip test of bundles > 6, only 6 predefined bundles supporte\
d.", 62L);
#endif /* NO_PROTO */
	goto L500;
    }
/*  numbun = number of bundles beyond #6 to be displayed */
/* Computing MIN */
    i__1 = 8, i__2 = nprei - 6;
    numbun = min(i__1,i__2);
/*  select bundles (as distinct as possible) from list of */
/*    predefined bundles [7, nprei] */
    distxb_(&numbun, &c__7, &nprei, bundis);
#ifndef NO_PROTO
    setmsg_("1 4 8 9", "Immediately after <open workstation>, the defined te"
	    "xt bundles > 6 of the WSL should appear as specified in the corr"
	    "esponding predefined text bundles of the WDT.", 7L, 161L);
#else /* NO_PROTO */
    setmsg_("1 4 8 9", "Immediately after <open workstation>, the defined te\
xt bundles > 6 of the WSL should appear as specified in the corresponding pr\
edefined text bundles of the WDT.", 7L, 161L);
#endif /* NO_PROTO */
/*  bundif = randomly selected bundle to be shown incorrectly */
    bundif = rndint_(&c__1, &numbun);
    drwatx_(&numbun, bundis, &bundif);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 6: Whi"
	    "ch pair of annotation text relative primitives does NOT match?", &
	    numbun, &bundif, 125L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 6: Whi\
ch pair of annotation text relative primitives does NOT match?", &numbun, &
	    bundif, 125L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_comp_tables */
L500:
/* *** *** *** ***  predefined bundle descriptions */
#ifndef NO_PROTO
    setmsg_("1 4 8", "The appearance of predefined text bundles should agree"
	    " with the descriptions supplied by the implementor.", 5L, 105L);
#else /* NO_PROTO */
    setmsg_("1 4 8", "The appearance of predefined text bundles should agree\
 with the descriptions supplied by the implementor.", 5L, 105L);
#endif /* NO_PROTO */
    numbun = min(8,nprei);
/*  bundis = distinct bundles to be displayed, chosen from [1,nprei] */
    distxb_(&numbun, &c__1, &nprei, bundis);
    srtiar_(&numbun, bundis);
/*  set all ASFs to BUNDLED */
    setasf_(&c__0);
#ifndef NO_PROTO
    yloc = .8f;
    yincr = .1f;
    r__1 = npcpwc * .03f;
#else /* NO_PROTO */
    yloc = (float).8;
    yincr = (float).1;
    r__1 = npcpwc * (float).03;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatal (&c__1, &c__3);
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxi (&bundis[ix - 1]);
	natr (&c_b40, &yloc, &c_b6, &c_b6, "Phigs", 5L);
	yloc -= yincr;
/* L550: */
    }
/*  set all ASFs to INDIVIDUAL */
    setasf_(&c__1);
/*  set label */
#ifndef NO_PROTO
    yloc = .9f;
    ybot = yloc - yincr * .3f;
    ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
    yloc = (float).9;
    ybot = yloc - yincr * (float).3;
    ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
    vislab_("Bundle#", "R", &c_b47, &c_b48, &ybot, &ytop, 7L, 1L);
    vislab_("     Font", "R", &c_b51, &c_b52, &ybot, &ytop, 9L, 1L);
    vislab_("Precision", "R", &c_b55, &c_b56, &ybot, &ytop, 9L, 1L);
    vislab_("Expansion", "R", &c_b59, &c_b60, &ybot, &ytop, 9L, 1L);
    vislab_("  Spacing", "R", &c_b60, &c_b64, &ybot, &ytop, 9L, 1L);
    vislab_("    Color", "R", &c_b64, &c_b68, &ybot, &ytop, 9L, 1L);
/*  display and label values for pdfn, pdpr, pdex, pdsp, pdci */
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	yloc -= yincr;
	nqptxr (&dialog_1.specwt, &bundis[ix - 1], &errind, &pdfn, &pdpr, &
		pdex, &pdsp, &pdci);
	chkinq_("pqptxr", &errind, 6L);
#ifndef NO_PROTO
	ybot = yloc - yincr * .3f;
	ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
	ybot = yloc - yincr * (float).3;
	ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	s_wsfi(&io___32);
	do_fio(&c__1, (char *)&bundis[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ": ", 2L);
	e_wsfi();
	vislab_(lntid, "R", &c_b47, &c_b48, &ybot, &ytop, 7L, 1L);
	s_wsfi(&io___33);
	do_fio(&c__1, (char *)&pdfn, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b51, &c_b52, &ybot, &ytop, 5L, 1L);
	if (pdpr >= 0 && pdpr <= 2) {
/* Writing concatenation */
	    i__3[0] = 1, a__1[0] = " ";
	    i__3[1] = 6, a__1[1] = precnm + pdpr * 6;
	    s_cat(lntid, a__1, i__3, &c__2, 40L);
	    clen = 7;
	} else {
	    s_wsfi(&io___35);
	    do_fio(&c__1, (char *)&pdpr, (ftnlen)sizeof(integer));
	    e_wsfi();
	    clen = 5;
	}
	vislab_(lntid, "R", &c_b55, &c_b56, &ybot, &ytop, clen, 1L);
	s_wsfi(&io___36);
	do_fio(&c__1, (char *)&pdex, (ftnlen)sizeof(real));
	e_wsfi();
	vislab_(lntid, "R", &c_b59, &c_b60, &ybot, &ytop, 7L, 1L);
	s_wsfi(&io___37);
	do_fio(&c__1, (char *)&pdsp, (ftnlen)sizeof(real));
	e_wsfi();
	vislab_(lntid, "R", &c_b60, &c_b64, &ybot, &ytop, 7L, 1L);
	s_wsfi(&io___38);
	do_fio(&c__1, (char *)&pdci, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b64, &c_b68, &ybot, &ytop, 5L, 1L);
/* L600: */
    }
#ifndef NO_PROTO
    if (dyn_("PREDEFINED TEXT BUNDLES: Does the appearance of each annotatio"
	    "n text relative primitive agree with the displayed aspect values"
	    " for that bundle?", 143L)) {
	dynpf_("PREDEFINED TEXT BUNDLES: If the implementor provides externa"
		"l documentation, is it consistent with the text appearance a"
		"nd displayed aspect values for every bundle identifier?", 
		"Y", 175L, 1L);
#else /* NO_PROTO */
    if (dyn_("PREDEFINED TEXT BUNDLES: Does the appearance of each annotatio\
n text relative primitive agree with the displayed aspect values for that bu\
ndle?", 143L)) {
	dynpf_("PREDEFINED TEXT BUNDLES: If the implementor provides externa\
l documentation, is it consistent with the text appearance and displayed asp\
ect values for every bundle identifier?", "Y", 175L, 1L);
#endif /* NO_PROTO */
    } else {
	opfail_();
    }
/* L666: */
/*  wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

