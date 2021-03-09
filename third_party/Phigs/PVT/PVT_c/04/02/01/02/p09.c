/* fort/04/02/01/02/p09.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__6 = 6;
static integer c__5 = 5;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b36 = .02f;
static real c_b37 = .15f;
static real c_b40 = .5f;
static real c_b41 = .65f;
static real c_b45 = .8f;
static real c_b49 = .95f;
#else /* NO_PROTO */
static real c_b36 = (float).02;
static real c_b37 = (float).15;
static real c_b40 = (float).5;
static real c_b41 = (float).65;
static real c_b45 = (float).8;
static real c_b49 = (float).95;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.02/09                        * */
/*  *    TEST TITLE : Appearance of predefined polyline     * */
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
    static char ltname[10*4] = "Solid     " "Dashed    " "Dotted    " "Dash-"
	    "dot  ";
#else /* NO_PROTO */
    static char ltname[10*4+1] = "Solid     Dashed    Dotted    Dash-dot  ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];

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
    static real xa[2], ya[2];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
    extern logical dyn_();
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer pdci, pdlt, txci;
    static real pdlw, yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real ybot, ytop;
    static integer idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nscmd ();
#endif /* NO_PROTO */
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
    extern /* Subroutine */ int nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nspli (integer *), nopst (integer *), nsvwi (integer *), 
	    ndellb (integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplf (), nspli (), nopst (), nsvwi (), 
	    ndellb ();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numbun, bundis[8];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), rnperm_(integer *, integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), drwplb_(integer *, 
	    integer *, integer *), displb_(integer *, integer *, integer *, 
	    integer *), srtiar_(integer *, integer *), vislab_(char *, char *,
	     real *, real *, real *, real *, ftnlen, ftnlen), nqpplr (integer 
	    *, integer *, integer *, integer *, real *, integer *), opfail_(
	    void);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), rnperm_(), 
	    setmsg_(), drwplb_(), displb_(), srtiar_(), vislab_(), nqpplr (), 
	    opfail_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___26 = { 0, lntid, 0, "(I5,A)", 40, 1 };
    static icilist io___27 = { 0, lntid, 0, "(I5)", 40, 1 };
    static icilist io___28 = { 0, lntid, 0, "(F8.3)", 40, 1 };
    static icilist io___29 = { 0, lntid, 0, "(I5)", 40, 1 };


/* aspect source */
/*                bundled     individual */
/* linetype */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.01.02/09", 14L);
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
/*  nprei = number of predefined polyline bundles */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &rdum3, &nprei);
    chkinq_("pqplf", &errind, 5L);
/* *** *** *** *** predefined polyline bundles 1-5 */
/*  mark start of polyline bundles 1-5 */
    nlb (&c__1);
/*  use first 5 indices + 1 duplicate */
    numbun = 6;
    rnperm_(&c__6, bundis);
/*  location of #6 */
    bundif = iarfnd_(&c__6, &c__6, bundis);
    bundis[bundif - 1] = rndint_(&c__1, &c__5);
#ifndef NO_PROTO
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the first fi"
	    "ve defined polyline bundles of the WSL should appear as specifie"
	    "d in the corresponding predefined polyline bundles of the WDT.", 
	    9L, 176L);
#else /* NO_PROTO */
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the first fi\
ve defined polyline bundles of the WSL should appear as specified in the cor\
responding predefined polyline bundles of the WDT.", 9L, 176L);
#endif /* NO_PROTO */
    drwplb_(&numbun, bundis, &bundif);
/*  mark end of bundles 1-5 */
    nlb (&c__2);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-5: Whi"
	    "ch pair of lines does NOT match?", &numbun, &bundif, 95L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-5: Whi\
ch pair of lines does NOT match?", &numbun, &bundif, 95L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* *** *** *** *** predefined polyline bundles > 5 */
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
    displb_(&numbun, &c__6, &nprei, bundis);
#ifndef NO_PROTO
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the defined "
	    "polyline bundles > 5 of the WSL should appear as specified in th"
	    "e corresponding predefined polyline bundles of the WDT.", 9L, 
	    169L);
#else /* NO_PROTO */
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the defined \
polyline bundles > 5 of the WSL should appear as specified in the correspond\
ing predefined polyline bundles of the WDT.", 9L, 169L);
#endif /* NO_PROTO */
/*  bundif = randomly selected bundle to be shown incorrectly */
    bundif = rndint_(&c__1, &numbun);
    drwplb_(&numbun, bundis, &bundif);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 5: Whi"
	    "ch pair of lines does NOT match?", &numbun, &bundif, 95L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 5: Whi\
ch pair of lines does NOT match?", &numbun, &bundif, 95L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_comp_tables */
L500:
/* *** *** *** ***  predefined bundle descriptions */
#ifndef NO_PROTO
    setmsg_("3 6 20", "The appearance of predefined polyline bundles should "
	    "agree with the descriptions supplied by the implementor.", 6L, 
	    109L);
#else /* NO_PROTO */
    setmsg_("3 6 20", "The appearance of predefined polyline bundles should \
agree with the descriptions supplied by the implementor.", 6L, 109L);
#endif /* NO_PROTO */
    numbun = min(8,nprei);
/*  bundis = distinct bundles to be displayed, chosen from [1,nprei] */
    displb_(&numbun, &c__1, &nprei, bundis);
    srtiar_(&numbun, bundis);
/*  set position and label */
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .5f;
    yincr = .1f;
    yloc = .9f;
    ybot = yloc - yincr * .3f;
    ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).5;
    yincr = (float).1;
    yloc = (float).9;
    ybot = yloc - yincr * (float).3;
    ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
    vislab_("Bundle#", "R", &c_b36, &c_b37, &ybot, &ytop, 7L, 1L);
    vislab_("  Linetype", "R", &c_b40, &c_b41, &ybot, &ytop, 10L, 1L);
    vislab_("  Width-scale", "R", &c_b41, &c_b45, &ybot, &ytop, 13L, 1L);
    vislab_("  Color-index", "R", &c_b45, &c_b49, &ybot, &ytop, 13L, 1L);
/*  draw polyline and its pdlt, pdlw, pdci */
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	yloc -= yincr;
	nqpplr (&dialog_1.specwt, &bundis[ix - 1], &errind, &pdlt, &pdlw, &
		pdci);
	chkinq_("pqpplr", &errind, 6L);
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ybot = yloc - yincr * .3f;
	ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
	ybot = yloc - yincr * (float).3;
	ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	s_wsfi(&io___26);
	do_fio(&c__1, (char *)&bundis[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ": ", 2L);
	e_wsfi();
	vislab_(lntid, "R", &c_b36, &c_b37, &ybot, &ytop, 7L, 1L);
	nspli (&bundis[ix - 1]);
	npl (&c__2, xa, ya);
	if (pdlt < 1 || pdlt > 4) {
	    s_wsfi(&io___27);
	    do_fio(&c__1, (char *)&pdlt, (ftnlen)sizeof(integer));
	    e_wsfi();
	} else {
/* Writing concatenation */
	    i__3[0] = 1, a__1[0] = " ";
	    i__3[1] = 10, a__1[1] = ltname + (pdlt - 1) * 10;
	    s_cat(lntid, a__1, i__3, &c__2, 40L);
	}
	vislab_(lntid, "L", &c_b40, &c_b41, &ybot, &ytop, itrim_(lntid, 40L), 
		1L);
	s_wsfi(&io___28);
	do_fio(&c__1, (char *)&pdlw, (ftnlen)sizeof(real));
	e_wsfi();
	vislab_(lntid, "R", &c_b41, &c_b45, &ybot, &ytop, 8L, 1L);
	s_wsfi(&io___29);
	do_fio(&c__1, (char *)&pdci, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b45, &c_b49, &ybot, &ytop, 5L, 1L);
/* L600: */
    }
#ifndef NO_PROTO
    if (dyn_("PREDEFINED POLYLINE BUNDLES: Does the appearance of each polyl"
	    "ine agree with the displayed aspect values for that bundle?", 
	    121L)) {
	dynpf_("PREDEFINED POLYLINE BUNDLES: If the implementor provides ext"
		"ernal documentation, is it consistent with the polyline appe"
		"arance and displayed aspect values for every bundle identifi"
		"er?", "Y", 183L, 1L);
#else /* NO_PROTO */
    if (dyn_("PREDEFINED POLYLINE BUNDLES: Does the appearance of each polyl\
ine agree with the displayed aspect values for that bundle?", 121L)) {
	dynpf_("PREDEFINED POLYLINE BUNDLES: If the implementor provides ext\
ernal documentation, is it consistent with the polyline appearance and displ\
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

