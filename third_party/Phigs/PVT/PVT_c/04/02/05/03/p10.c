/* fort/04/02/05/03/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__11 = 11;
static integer c__13 = 13;
static integer c__4 = 4;
static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b38 = .02f;
static real c_b39 = .15f;
static real c_b42 = .5f;
static real c_b43 = .6f;
static real c_b47 = .7f;
static real c_b51 = .85f;
static real c_b55 = .95f;
static real c_b64 = .12f;
#else /* NO_PROTO */
static real c_b38 = (float).02;
static real c_b39 = (float).15;
static real c_b42 = (float).5;
static real c_b43 = (float).6;
static real c_b47 = (float).7;
static real c_b51 = (float).85;
static real c_b55 = (float).95;
static real c_b64 = (float).12;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/10                        * */
/*  *    TEST TITLE : Appearance of predefined edge bundles * */
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
    static real xa[4], ya[4];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
    extern logical dyn_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
    extern logical dyn_();
#endif /* NO_PROTO */
    static integer pdef, pdci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer pdet;
    static real pdew;
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real ybot;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static integer npts[1];
    static real ytop;
    static integer idum1, idum2;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nsedi (integer *), nscmd (integer *, integer *), 
	    nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nsedi (), nscmd (), 
	    nsici ();
#endif /* NO_PROTO */
    static char lntid[40];
    static integer nprei;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer numet;
#ifndef NO_PROTO
    extern /* Subroutine */ int dynpf_(char *, char *, ftnlen, ftnlen), 
	    nopst (integer *), nsvwi (integer *), disedb_(integer *, integer *
	    , integer *, integer *), ndellb (integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dynpf_(), nopst (), nsvwi (), disedb_(), 
	    ndellb ();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int drwedb_(integer *, integer *, integer *, 
	    integer *), dchpfv_(char *, integer *, integer *, ftnlen), 
	    chkinq_(char *, integer *, ftnlen), vislab_(char *, char *, real *
	    , real *, real *, real *, ftnlen, ftnlen), setdlg_(integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int drwedb_(), dchpfv_(), chkinq_(), vislab_(), 
	    setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numbun, bundis[8];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsiasf (integer *, integer *), 
	    rnperm_(integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), srtiar_(integer *, integer *), nqpedr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    opfail_(void);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsiasf (), 
	    rnperm_(), setmsg_(), srtiar_(), nqpedr (), opfail_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___27 = { 0, lntid, 0, "(I5,A)", 40, 1 };
    static icilist io___28 = { 0, lntid, 0, "(I5)", 40, 1 };
    static icilist io___29 = { 0, lntid, 0, "(I5)", 40, 1 };
    static icilist io___30 = { 0, lntid, 0, "(F8.3)", 40, 1 };
    static icilist io___31 = { 0, lntid, 0, "(I5)", 40, 1 };


/* aspect source */
/* colour model */
/* type of returned value */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* aspect identifier */
    initgl_("04.02.05.03/10", 14L);
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
/*  use bundle attributes */
    setasf_(&c__0);
/*  set interior style attribute ASF to INDIVIDUAL */
    nsiasf (&c__11, &c__1);
    nsiasf (&c__13, &c__1);
/*  set interior style = EMPTY, interior color index = 1 */
    nsis (&c__4);
    nsici (&c__1);
/*  nprei  = number of predefined bundles */
/*  numet = number of edge types */
    nqedf (&dialog_1.specwt, &c__0, &errind, &numet, &idum1, &idum2, &rdum1, &
	    rdum2, &rdum3, &nprei);
    chkinq_("pqedf", &errind, 5L);

/*  *** *** ***   predefined edge bundles 1-5   *** *** *** */

/*  mark start of edge bundles 1-5 */
    nlb (&c__1);
/*  bundis = bundles to be displayed (1 to 5 , with one repeated) */
/*  bundif = location of repeated bundle identifier (so that all 5 */
/*           may be verified) */
    numbun = 6;
    rnperm_(&numbun, bundis);
    bundif = iarfnd_(&numbun, &numbun, bundis);
    i__1 = numbun - 1;
    bundis[bundif - 1] = rndint_(&c__1, &i__1);
#ifndef NO_PROTO
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the first fi"
	    "ve defined edge bundles of the WSL should appear as specified in"
	    " the corresponding predefined edge bundles of the WDT.", 9L, 168L)
	    ;
#else /* NO_PROTO */
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the first fi\
ve defined edge bundles of the WSL should appear as specified in the corresp\
onding predefined edge bundles of the WDT.", 9L, 168L);
#endif /* NO_PROTO */
/*  display and label results */
    drwedb_(&numbun, bundis, &bundif, &numet);
/*  mark end of bundles 1-5 */
    nlb (&c__2);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-5; whi"
	    "ch pair of edges does NOT match?", &numbun, &bundif, 95L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES 1-5; whi\
ch pair of edges does NOT match?", &numbun, &bundif, 95L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);

/*  *** *** ***   predefined edge bundles > 5   *** *** *** */

/*  if nprei <= 5 then skip to end_comp_tables */
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
/*  get distinct bundles to be displayed */
/*  numbun = number of distinct bundles to be displayed */
/* Computing MIN */
    i__1 = 8, i__2 = nprei - 5;
    numbun = min(i__1,i__2);
    disedb_(&numbun, &c__6, &nprei, bundis);
#ifndef NO_PROTO
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the defined "
	    "edge bundles > 5 of the WSL should appear as specified in the co"
	    "rresponding predefined edge bundles of the WDT.", 9L, 161L);
#else /* NO_PROTO */
    setmsg_("3 6 20 24", "Immediately after <open workstation>, the defined \
edge bundles > 5 of the WSL should appear as specified in the corresponding \
predefined edge bundles of the WDT.", 9L, 161L);
#endif /* NO_PROTO */
/*  bundif = randomly selected bundle from bundis */
    bundif = rndint_(&c__1, &numbun);
/*  display and label bundis */
    drwedb_(&numbun, bundis, &bundif, &numet);
#ifndef NO_PROTO
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 5; Whi"
	    "ch pair of edges does NOT match?", &numbun, &bundif, 95L);
#else /* NO_PROTO */
    dchpfv_("WORKSTATION DESCRIPTION AND STATE LIST TABLES, INDICES > 5; Whi\
ch pair of edges does NOT match?", &numbun, &bundif, 95L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_comp_tables: */
L500:
/*  *** ***  predefined bundle descriptions   *** *** */

#ifndef NO_PROTO
    setmsg_("3 6 20", "The appearance of predefined edge bundles should agre"
	    "e with the descriptions supplied by the implementor.", 6L, 105L);
#else /* NO_PROTO */
    setmsg_("3 6 20", "The appearance of predefined edge bundles should agre\
e with the descriptions supplied by the implementor.", 6L, 105L);
#endif /* NO_PROTO */
    numbun = min(8,nprei);
/*  get distinct bundles to be displayed, chosed from [1,nprei] */
    disedb_(&numbun, &c__1, &nprei, bundis);
/*  sorted */
    srtiar_(&numbun, bundis);
/*  set position and label */
#ifndef NO_PROTO
    xa[0] = .15f;
    xa[1] = .15f;
    xa[2] = .45f;
    yincr = 1.f / (numbun + 2);
    yloc = .9f;
    ybot = yloc - yincr * .3f;
    ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
    xa[0] = (float).15;
    xa[1] = (float).15;
    xa[2] = (float).45;
    yincr = (float)1. / (numbun + 2);
    yloc = (float).9;
    ybot = yloc - yincr * (float).3;
    ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
    vislab_("Bundle#", "R", &c_b38, &c_b39, &ybot, &ytop, 7L, 1L);
    vislab_("  Edgeflag", "R", &c_b42, &c_b43, &ybot, &ytop, 10L, 1L);
    vislab_("  Edgetype", "R", &c_b43, &c_b47, &ybot, &ytop, 10L, 1L);
    vislab_("  Width-scale", "R", &c_b47, &c_b51, &ybot, &ytop, 13L, 1L);
    vislab_("  Color", "R", &c_b51, &c_b55, &ybot, &ytop, 7L, 1L);
/*  draw edge and its pdef, pdet, pdew, pdci */
    npts[0] = 3;
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	yloc -= yincr;
	nqpedr (&dialog_1.specwt, &bundis[ix - 1], &errind, &pdef, &pdet, &
		pdew, &pdci);
	chkinq_("pqpedr", &errind, 6L);
#ifndef NO_PROTO
	ybot = yloc - yincr * .3f;
	ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
	ybot = yloc - yincr * (float).3;
	ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[0] = ybot;
	ya[1] = ytop;
	ya[2] = ybot;
	s_wsfi(&io___27);
	do_fio(&c__1, (char *)&bundis[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ": ", 2L);
	e_wsfi();
	vislab_(lntid, "R", &c_b38, &c_b64, &ybot, &ytop, 7L, 1L);
	nsedi (&bundis[ix - 1]);
	nfas (&c__1, npts, xa, ya);
	if (pdef == 1) {
	    s_copy(lntid, "On", 40L, 2L);
	} else if (pdef == 0) {
	    s_copy(lntid, "Off", 40L, 3L);
	} else {
	    s_wsfi(&io___28);
	    do_fio(&c__1, (char *)&pdef, (ftnlen)sizeof(integer));
	    e_wsfi();
	}
	vislab_(lntid, "R", &c_b42, &c_b43, &ybot, &ytop, itrim_(lntid, 40L), 
		1L);
	s_wsfi(&io___29);
	do_fio(&c__1, (char *)&pdet, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b43, &c_b47, &ybot, &ytop, 5L, 1L);
	s_wsfi(&io___30);
	do_fio(&c__1, (char *)&pdew, (ftnlen)sizeof(real));
	e_wsfi();
	vislab_(lntid, "R", &c_b47, &c_b51, &ybot, &ytop, 8L, 1L);
	s_wsfi(&io___31);
	do_fio(&c__1, (char *)&pdci, (ftnlen)sizeof(integer));
	e_wsfi();
	vislab_(lntid, "R", &c_b51, &c_b55, &ybot, &ytop, 5L, 1L);
/* L600: */
    }
#ifndef NO_PROTO
    if (dyn_("PREDEFINED EDGE BUNDLES: Does the appearance of each edge agre"
	    "e with the displayed aspect values for that bundle?", 113L)) {
	dynpf_("PREDEFINED EDGE BUNDLES: If the implementor provides externa"
		"l documentation, is it consistent with the edge appearance a"
		"nd displayed aspect values for every bundle identifier?", 
		"Y", 175L, 1L);
#else /* NO_PROTO */
    if (dyn_("PREDEFINED EDGE BUNDLES: Does the appearance of each edge agre\
e with the displayed aspect values for that bundle?", 113L)) {
	dynpf_("PREDEFINED EDGE BUNDLES: If the implementor provides externa\
l documentation, is it consistent with the edge appearance and displayed asp\
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

