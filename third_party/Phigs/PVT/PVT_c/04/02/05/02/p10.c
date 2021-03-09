/* fort/04/02/05/02/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b9 = .1f;
#else /* NO_PROTO */
static real c_b9 = (float).1;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__5 = 5;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b43 = .02f;
static real c_b44 = .15f;
static real c_b47 = .5f;
static real c_b48 = .65f;
static real c_b52 = .8f;
static real c_b56 = .95f;
#else /* NO_PROTO */
static real c_b43 = (float).02;
static real c_b44 = (float).15;
static real c_b47 = (float).5;
static real c_b48 = (float).65;
static real c_b52 = (float).8;
static real c_b56 = (float).95;
#endif /* NO_PROTO */
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/10                        * */
/*  *    TEST TITLE : Appearance of predefined interior     * */
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
    static char intnam[9*5] = "Hollow   " "Solid    " "Pattern  " "Hatch    " 
	    "Empty    ";
#else /* NO_PROTO */
    static char intnam[9*5+1] = "Hollow   Solid    Pattern  Hatch    Empty  \
  ";
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[5], ya[5];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), nlb (integer 
	    *);
    extern logical dyn_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), nlb ();
    extern logical dyn_();
#endif /* NO_PROTO */
    static integer siz, pdci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer pdis;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nspa (real *, real *), nsii (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqif (), nspa (), nsii ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real ybot;
    static integer npts[3];
    static real ytop;
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nscmd ();
#endif /* NO_PROTO */
    static integer pdisi;
    static char lntid[40];
    static integer nprei;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), dynpf_(char *, char *,
	     ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), dynpf_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpir (integer *, integer *, integer *, 
	    integer *, integer *, integer *), nopst (integer *), nsvwi (
	    integer *), ndellb (integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpir (), nopst (), nsvwi (), ndellb ();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedfg (integer *), dchpfv_(char *, integer *,
	     integer *, ftnlen), chkinq_(char *, integer *, ftnlen), disinb_(
	    integer *, integer *, integer *, integer *), setdlg_(integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedfg (), dchpfv_(), chkinq_(), disinb_(), 
	    setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numbun, bundis[8];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsiasf (integer *, integer *), 
	    rnperm_(integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), drwint_(integer *, integer *, integer *), srtiar_(
	    integer *, integer *), setrvs_(char *, real *, integer *, ftnlen),
	     vislab_(char *, char *, real *, real *, real *, real *, ftnlen, 
	    ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsiasf (), 
	    rnperm_(), setmsg_(), drwint_(), srtiar_(), setrvs_(), vislab_(), 
	    opfail_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___26 = { 0, lntid, 0, "(I5,A)", 40, 1 };
    static icilist io___27 = { 0, lntid, 0, "(A,I5)", 40, 1 };
    static icilist io___28 = { 0, lntid, 0, "(I5)", 40, 1 };
    static icilist io___29 = { 0, lntid, 0, "(I5)", 40, 1 };


/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* off/on switch for edge flag and error handling mode */
/* interior style */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.05.02/10", 14L);
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
/*  set ASF individual: edge flag = off */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
    nspa (&c_b9, &c_b9);
/*  nprei = number of predefined interior bundles */
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &idum1, &idum2, &idum3, &
	    idum4, &nprei);
    chkinq_("pqif", &errind, 4L);
/* *** *** *** *** predefined interior bundles 1-5 */
/*  mark start of interior bundles 1-5 */
    nlb (&c__1);
/*  use first 5 indices + 1 duplicate */
    numbun = 6;
    rnperm_(&c__6, bundis);
/*  location of #6 */
    bundif = iarfnd_(&c__6, &c__6, bundis);
    bundis[bundif - 1] = rndint_(&c__1, &c__5);
#ifndef NO_PROTO
    setmsg_("3 4 7 21 25", "Immediately after <open workstation>, the first "
	    "5 defined interior bundles of the WSL should appear as specified"
	    " in the corresponding predefined interior bundles of the WDT.", 
	    11L, 173L);
#else /* NO_PROTO */
    setmsg_("3 4 7 21 25", "Immediately after <open workstation>, the first \
5 defined interior bundles of the WSL should appear as specified in the corr\
esponding predefined interior bundles of the WDT.", 11L, 173L);
#endif /* NO_PROTO */
    drwint_(&numbun, bundis, &bundif);
/*  mark end of bundles 1-5 */
    nlb (&c__2);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-5: Whi"
	    "ch pair of rectangles does NOT match?", &numbun, &bundif, 100L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-5: Whi\
ch pair of rectangles does NOT match?", &numbun, &bundif, 100L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* *** *** *** *** predefined interior bundles > 5 */
/*  skip if there are only 5 bundles */
    if (nprei <= 5) {
#ifndef NO_PROTO
	inmsg_("Skip test of bundles > 5, only 5 predefined bundles supporte"
		"d.", 62L);
#else /* NO_PROTO */
	inmsg_("Skip test of bundles > 5, only 5 predefined bundles supporte\
d.", 62L);
#endif /* NO_PROTO */
	goto L500;
    }
/*  numbun = number of bundles beyond #5 to be displayed */
/* Computing MIN */
    i__1 = 8, i__2 = nprei - 5;
    numbun = min(i__1,i__2);
/*  select bundles (as distinct as possible) from list of */
/*    predefined bundles [6,nprei] */
    disinb_(&numbun, &c__6, &nprei, bundis);
#ifndef NO_PROTO
    setmsg_("3 4 7 21 25", "Immediately after <open workstation>, the define"
	    "d interior bundles >5 of the WSL should appear as specified in t"
	    "he corresponding predefined interior bundles of the WDT.", 11L, 
	    168L);
#else /* NO_PROTO */
    setmsg_("3 4 7 21 25", "Immediately after <open workstation>, the define\
d interior bundles >5 of the WSL should appear as specified in the correspon\
ding predefined interior bundles of the WDT.", 11L, 168L);
#endif /* NO_PROTO */
/*  bundif = randomly selected bundle to be shown incorrectly */
    bundif = rndint_(&c__1, &numbun);
    drwint_(&numbun, bundis, &bundif);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 5: Whi"
	    "ch pair of rectangles does NOT match?", &numbun, &bundif, 100L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 5: Whi\
ch pair of rectangles does NOT match?", &numbun, &bundif, 100L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_comp_tables */
L500:
/* *** *** *** ***  predefined bundle descriptions */
#ifndef NO_PROTO
    setmsg_("3 4 7 21", "The appearance of predefined interior bundles shoul"
	    "d agree with the descriptions supplied by the implementor.", 8L, 
	    109L);
#else /* NO_PROTO */
    setmsg_("3 4 7 21", "The appearance of predefined interior bundles shoul\
d agree with the descriptions supplied by the implementor.", 8L, 109L);
#endif /* NO_PROTO */
    numbun = min(8,nprei);
/*  bundis = distinct bundles to be displayed, chosen from [1,nprei] */
    disinb_(&numbun, &c__1, &nprei, bundis);
    srtiar_(&numbun, bundis);
/*  set position and label */
    setrvs_("0.2,0.45,0.45,0.2", xa, &siz, 17L);
#ifndef NO_PROTO
    yincr = .1f;
    yloc = .9f;
    ybot = yloc - yincr * .3f;
    ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
    yincr = (float).1;
    yloc = (float).9;
    ybot = yloc - yincr * (float).3;
    ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
    vislab_("Bundle#", "R", &c_b43, &c_b44, &ybot, &ytop, 7L, 1L);
    vislab_("InteriorStyle", "L", &c_b47, &c_b48, &ybot, &ytop, 13L, 1L);
    vislab_("  Style-index", "R", &c_b48, &c_b52, &ybot, &ytop, 13L, 1L);
    vislab_("  Color-index", "R", &c_b52, &c_b56, &ybot, &ytop, 13L, 1L);
/*  draw interior and its pdis, pdisi, pdci */
    npts[0] = 4;
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	yloc -= yincr;
	nqpir (&dialog_1.specwt, &bundis[ix - 1], &errind, &pdis, &pdisi, &
		pdci);
	chkinq_("pqpir", &errind, 5L);
#ifndef NO_PROTO
	ybot = yloc - yincr * .3f;
	ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
	ybot = yloc - yincr * (float).3;
	ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[0] = ybot;
	ya[1] = ybot;
	ya[2] = ytop;
	ya[3] = ytop;
	s_wsfi(&io___26);
	do_fio(&c__1, (char *)&bundis[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ": ", 2L);
	e_wsfi();
	vislab_(lntid, "R", &c_b43, &c_b44, &ybot, &ytop, 7L, 1L);
	nsii (&bundis[ix - 1]);
/* switch between fill area and fill area set */
	if (ix % 2 == 0) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (&c__4, xa, ya);
	}
	if (pdis >= 0 && pdis <= 4) {
	    s_copy(lntid, intnam + pdis * 9, 40L, 9L);
	} else {
	    s_wsfi(&io___27);
	    do_fio(&c__1, "#", 1L);
	    do_fio(&c__1, (char *)&pdis, (ftnlen)sizeof(integer));
	    e_wsfi();
	}
	vislab_(lntid, "L", &c_b47, &c_b48, &ybot, &ytop, itrim_(lntid, 40L), 
		1L);
	s_wsfi(&io___28);
	do_fio(&c__1, (char *)&pdisi, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b48, &c_b52, &ybot, &ytop, 5L, 1L);
	s_wsfi(&io___29);
	do_fio(&c__1, (char *)&pdci, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b52, &c_b56, &ybot, &ytop, 5L, 1L);
/* L600: */
    }
#ifndef NO_PROTO
    if (dyn_("PREDEFINED INTERIOR BUNDLES: Does the appearance of each inter"
	    "ior agree with the displayed aspect values for that bundle?", 
	    121L)) {
	dynpf_("PREDEFINED INTERIOR BUNDLES: If the implementor provides ext"
		"ernal documentation, is it consistent with the interior appe"
		"arance and displayed aspect values for every bundle identifi"
		"er?", "Y", 183L, 1L);
#else /* NO_PROTO */
    if (dyn_("PREDEFINED INTERIOR BUNDLES: Does the appearance of each inter\
ior agree with the displayed aspect values for that bundle?", 121L)) {
	dynpf_("PREDEFINED INTERIOR BUNDLES: If the implementor provides ext\
ernal documentation, is it consistent with the interior appearance and displ\
ayed aspect values for every bundle identifier?", "Y", 183L, 1L);
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

