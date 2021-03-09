/* fort/06/01/02/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b15 = 0.f;
static real c_b18 = .5f;
static real c_b21 = 1.5707963250000001f;
#else /* NO_PROTO */
static real c_b15 = (float)0.;
static real c_b18 = (float).5;
static real c_b21 = (float)1.5707963250000001;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b26 = -5.f;
static real c_b27 = 5.f;
#else /* NO_PROTO */
static real c_b26 = (float)-5.;
static real c_b27 = (float)5.;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b57 = .03f;
static real c_b58 = .3f;
static real c_b59 = .9f;
static real c_b60 = .95f;
static real c_b65 = .85f;
static real c_b69 = .53f;
static real c_b70 = .8f;
static real c_b83 = .08f;
static real c_b84 = .13f;
#else /* NO_PROTO */
static real c_b57 = (float).03;
static real c_b58 = (float).3;
static real c_b59 = (float).9;
static real c_b60 = (float).95;
static real c_b65 = (float).85;
static real c_b69 = (float).53;
static real c_b70 = (float).8;
static real c_b83 = (float).08;
static real c_b84 = (float).13;
#endif /* NO_PROTO */
static integer c__101 = 101;
static integer c__6 = 6;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/11                           * */
/*  *    TEST TITLE : Visual effect of modelling clipping   * */
/*  *                 facilities                            * */
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
    address a__1[6];
    integer i__1, i__2, i__3[6];
    char ch__1[191], ch__2[194];

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    double cos(), sin();
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i;
    static real x[15], y[15], hs[3000]	/* was [6][500] */, xf[16]	/* 
	    was [4][4] */;
    static integer ix;
    static real ang, rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer nol;
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static real mc2d[4]	/* was [4][1] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static real mscf, idxf[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static integer nsiz, idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nschh (real *), nsedm (integer *), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nschh (), nsedm (), 
	    inmsg_();
#endif /* NO_PROTO */
    static integer maxpl;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static integer lisop[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmf ();
#endif /* NO_PROTO */
    static integer visct;
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static integer numpl;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmcv (integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmcv ();
#endif /* NO_PROTO */
    static integer numop;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), nosep (integer *), rnset_(
	    integer *, integer *, integer *), nexst (integer *), nopst (
	    integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), nosep (), rnset_(), nexst (), 
	    nopst (), nsvwi ();
#endif /* NO_PROTO */
    static char txstr[23];
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *),
	     nsmcv3 (integer *, integer *, real *), nslmt3 (real *, integer *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm3_(), nsmcv3 (), nslmt3 ();
#endif /* NO_PROTO */
    static real cosang, sinang;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, mclpop, nlrmct, lrmcop[50], nlimct, limcop[
	    50], nmclhs, minmrk, maxmrk;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static char thisop[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), chkinq_(char *, integer *, ftnlen)
	    , nsmksc (real *), nqmclf (integer *, integer *, integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nsmcli (integer *), clpgon_(integer *, integer *, real *), 
	    dchpfv_(char *, integer *, integer *, ftnlen), nsplci (integer *),
	     setrvs_(char *, real *, integer *, ftnlen), vislab_(char *, char 
	    *, real *, real *, real *, real *, ftnlen, ftnlen), nstxal (
	    integer *, integer *), nstxfn (integer *), nstxpr (integer *), 
	    nseplb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), chkinq_(), 
	    nsmksc (), nqmclf (), setmsg_(), nsmcli (), clpgon_(), dchpfv_(), 
	    nsplci (), setrvs_(), vislab_(), nstxal (), nstxfn (), nstxpr (), 
	    nseplb ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___41 = { 0, thisop, 0, "(I3)", 3, 1 };
    static icilist io___42 = { 0, thisop, 0, "(I3)", 3, 1 };


/* aspect source */
/*                bundled     individual */
/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/* edit mode */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
/* maximum number of planes to be tested */
    initgl_("06.01.02/11", 11L);
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

/*  adjust polymarker size */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
#ifndef NO_PROTO
    mscf = .02f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).02 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*    <inquire modelling clipping facilities> to determine */
/*      maxpl  = maximum# of planes */
/*      NOL    = # of operators */
    nqmclf (&c__0, &errind, &maxpl, &nol, &mclpop);
    chkinq_("pqmclf", &errind, 6L);
/*    lrmcop = list of registered modelling clipping combination */
/*             operators > 2 */
/*    limcop = list of implementor modelling clipping combination */
/*             operators < 1 */
    nlimct = 0;
    nlrmct = 0;
    i__1 = nol;
    for (i = 1; i <= i__1; ++i) {
	nqmclf (&i, &errind, &nmclhs, &nol, &mclpop);
	chkinq_("pqmclf", &errind, 6L);
	if (mclpop > 2) {
	    ++nlrmct;
	    lrmcop[nlrmct - 1] = mclpop;
	} else if (mclpop < 1) {
	    ++nlimct;
	    limcop[nlimct - 1] = mclpop;
	}
/* L100: */
    }
/*  *** *** ***  Specified volume with Max Planes  *** *** *** */
/*  numpl = actual number of planes to be tested */
/*  minmrk = minimum number of visible markers = 2 */
/*  maxmrk = maximum number of visible markers = min(12, 0.75*numpl) */
/*  rad = WC radius of prism = 0.4 */
    numpl = min(maxpl,500);
    minmrk = 2;
/* Computing MIN */
    i__1 = 12, i__2 = numpl * 3 / 4;
    maxmrk = min(i__1,i__2);
#ifndef NO_PROTO
    rad = .4f;
    setmsg_("23 35 40 41 42 43 59", "The program should be able to replace t"
	    "he current modelling clipping volume by a specified modelling cl"
	    "ipping volume that uses up to the reported maximum number of dis"
	    "tinct planes.", 20L, 180L);
#else /* NO_PROTO */
    rad = (float).4;
    setmsg_("23 35 40 41 42 43 59", "The program should be able to replace t\
he current modelling clipping volume by a specified modelling clipping volum\
e that uses up to the reported maximum number of distinct planes.", 20L, 180L)
	    ;
#endif /* NO_PROTO */
/*  set local transformation: */
    ebltm3_(&c_b15, &c_b15, &c_b15, &c_b18, &c_b18, &c_b18, &c_b21, &c_b15, &
	    c_b15, &rad, &rad, &rad, xf);
    nslmt3 (xf, &c__2);
    i__1 = numpl;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ang = (ix << 1) * 3.14159265f / numpl;
#else /* NO_PROTO */
	ang = (ix << 1) * (float)3.14159265 / numpl;
#endif /* NO_PROTO */
	cosang = cos(ang);
	sinang = sin(ang);
	hs[ix * 6 - 6] = cosang;
	hs[ix * 6 - 5] = rndrl_(&c_b26, &c_b27);
	hs[ix * 6 - 4] = sinang;
	hs[ix * 6 - 3] = -(doublereal)cosang;
#ifndef NO_PROTO
	hs[ix * 6 - 2] = 0.f;
#else /* NO_PROTO */
	hs[ix * 6 - 2] = (float)0.;
#endif /* NO_PROTO */
	hs[ix * 6 - 1] = -(doublereal)sinang;
/* L110: */
    }
/*  set up current MCV to be replaced by next <Set MCV>: */
#ifndef NO_PROTO
    mc2d[0] = -.5f;
    mc2d[1] = 0.f;
    mc2d[2] = 1.f;
    mc2d[3] = 0.f;
#else /* NO_PROTO */
    mc2d[0] = (float)-.5;
    mc2d[1] = (float)0.;
    mc2d[2] = (float)1.;
    mc2d[3] = (float)0.;
#endif /* NO_PROTO */
    nsmcv (&c__1, &c__1, mc2d);
/*  set 3D MCV */
    nsmcv3 (&c__1, &numpl, hs);
/*  set local transformation back to identity */
    idmat_(&c__4, idxf);
    nslmt3 (idxf, &c__2);
/*  set modelling clipping indicator = CLIP */
    nsmcli (&c__1);
/*  number of unclipped markers */
    visct = rndint_(&minmrk, &maxmrk);
    clpgon_(&visct, &numpl, &rad);
#ifndef NO_PROTO
    dchpfv_("MAXIMUM NUMBER OF SPECIFIED DISTINCT PLANES: How many markers a"
	    "re visible?", &numpl, &visct, 74L);
#else /* NO_PROTO */
    dchpfv_("MAXIMUM NUMBER OF SPECIFIED DISTINCT PLANES: How many markers a\
re visible?", &numpl, &visct, 74L);
#endif /* NO_PROTO */
/*  *** *** ***  Current volume with Max Planes  *** *** *** */
    nemst (&c__102);
#ifndef NO_PROTO
    setmsg_("23 35 40 41 42 43 59", "The intersection operator should be abl"
	    "e to construct a current modelling clipping volume that uses up "
	    "to the reported maximum number of distinct planes.", 20L, 153L);
#else /* NO_PROTO */
    setmsg_("23 35 40 41 42 43 59", "The intersection operator should be abl\
e to construct a current modelling clipping volume that uses up to the repor\
ted maximum number of distinct planes.", 20L, 153L);
#endif /* NO_PROTO */
/*  set local transformation: */
    nslmt3 (xf, &c__2);
/*  construct current MCV */
    i__1 = numpl;
    for (ix = 1; ix <= i__1; ++ix) {
	nsmcv3 (&c__2, &c__1, &hs[ix * 6 - 6]);
/* L130: */
    }
/*  set local transformation back to identity */
    idmat_(&c__4, idxf);
    nslmt3 (idxf, &c__2);
/*  set modelling clipping indicator = CLIP */
    nsmcli (&c__1);
/*  number of unclipped markers */
    visct = rndint_(&minmrk, &maxmrk);
    clpgon_(&visct, &numpl, &rad);
#ifndef NO_PROTO
    dchpfv_("MAXIMUM NUMBER OF CURRENT DISTINCT PLANES: How many markers are"
	    " visible?", &numpl, &visct, 72L);
#else /* NO_PROTO */
    dchpfv_("MAXIMUM NUMBER OF CURRENT DISTINCT PLANES: How many markers are\
 visible?", &numpl, &visct, 72L);
#endif /* NO_PROTO */
/*  *** *** *** implementor defined or registered operators   *** *** *** 
*/
    if (nlrmct == 0 && nlimct == 0) {
#ifndef NO_PROTO
	inmsg_("No registered or implementor defined combination operators a"
		"re supported for setting modelling clipping volume.", 111L);
#else /* NO_PROTO */
	inmsg_("No registered or implementor defined combination operators a\
re supported for setting modelling clipping volume.", 111L);
#endif /* NO_PROTO */
	goto L170;
    }
    nemst (&c__102);
    s_copy(txstr, "WHERE'S THE REST OF ME?", 23L, 23L);
/*  Set up four square areas */
    nsplci (&c__3);
    setrvs_(".01,.01,.99,.99,.01", x, &nsiz, 19L);
    setrvs_(".01,.99,.99,.01,.01", y, &nsiz, 19L);
    npl (&nsiz, x, y);
/*  Cross */
#ifndef NO_PROTO
    x[0] = .5f;
    y[0] = .99f;
    x[1] = .5f;
    y[1] = .01f;
#else /* NO_PROTO */
    x[0] = (float).5;
    y[0] = (float).99;
    x[1] = (float).5;
    y[1] = (float).01;
#endif /* NO_PROTO */
    npl (&c__2, x, y);
#ifndef NO_PROTO
    x[0] = .01f;
    y[0] = .5f;
    x[1] = .99f;
    y[1] = .5f;
#else /* NO_PROTO */
    x[0] = (float).01;
    y[0] = (float).5;
    x[1] = (float).99;
    y[1] = (float).5;
#endif /* NO_PROTO */
    npl (&c__2, x, y);
/*  Label each quadrant */
    vislab_("inside previous MCV", "L", &c_b57, &c_b58, &c_b59, &c_b60, 19L, 
	    1L);
    vislab_("outside new MCV", "L", &c_b57, &c_b58, &c_b65, &c_b59, 15L, 1L);
    vislab_("outside previous MCV", "L", &c_b69, &c_b70, &c_b59, &c_b60, 20L, 
	    1L);
    vislab_("outside new MCV", "L", &c_b69, &c_b70, &c_b65, &c_b59, 15L, 1L);
    vislab_("inside previous MCV", "L", &c_b57, &c_b58, &c_b83, &c_b84, 19L, 
	    1L);
    vislab_("inside new MCV", "L", &c_b57, &c_b58, &c_b57, &c_b83, 14L, 1L);
    vislab_("outside previous MCV", "L", &c_b69, &c_b70, &c_b83, &c_b84, 20L, 
	    1L);
    vislab_("inside new MCV", "L", &c_b69, &c_b70, &c_b57, &c_b83, 14L, 1L);
/*  set previous MCV */
#ifndef NO_PROTO
    mc2d[0] = .5f;
    mc2d[1] = .5f;
    mc2d[2] = -1.f;
    mc2d[3] = 0.f;
#else /* NO_PROTO */
    mc2d[0] = (float).5;
    mc2d[1] = (float).5;
    mc2d[2] = (float)-1.;
    mc2d[3] = (float)0.;
#endif /* NO_PROTO */
    nsmcv (&c__1, &c__1, mc2d);
/*  label element 101 */
    nlb (&c__101);
/*  set dummy MCV */
    nsmcv (&c__1, &c__1, mc2d);
/*  set clipping on */
    nsmcli (&c__1);
/*  text centered at 0.5,0.5 */
    nschh (&c_b57);
    nstxal (&c__2, &c__3);
    nstxfn (&c__1);
    nstxpr (&c__2);
    ntx (&c_b18, &c_b18, txstr, 23L);
/* Position element pointer at  top */
    nsep (&c__1);
/*  edit mode = replace */
    nsedm (&c__1);
/*  position element pointer at label 101 */
    nseplb (&c__101);
/*  increment element pointer by 1 to allow replacement */
/*     of second <set MCV> */
    nosep (&c__1);
/*  clipping plane for operator to be tested */
#ifndef NO_PROTO
    mc2d[0] = .5f;
    mc2d[1] = .5f;
    mc2d[2] = 0.f;
    mc2d[3] = -1.f;
#else /* NO_PROTO */
    mc2d[0] = (float).5;
    mc2d[1] = (float).5;
    mc2d[2] = (float)0.;
    mc2d[3] = (float)-1.;
#endif /* NO_PROTO */
/*  *** *** *** *** Registered Operators  *** *** *** *** */
    if (nlrmct == 0) {
#ifndef NO_PROTO
	inmsg_("No registered combination operators are supported for settin"
		"g modelling clipping volume.", 88L);
#else /* NO_PROTO */
	inmsg_("No registered combination operators are supported for settin\
g modelling clipping volume.", 88L);
#endif /* NO_PROTO */
	goto L160;
    }
#ifndef NO_PROTO
    setmsg_("35 40 44 57", "The effect of combination operators > 2 in <set "
	    "modelling clipping volume> should be as described in the ISO reg"
	    "ister.", 11L, 118L);
#else /* NO_PROTO */
    setmsg_("35 40 44 57", "The effect of combination operators > 2 in <set \
modelling clipping volume> should be as described in the ISO register.", 11L, 
	    118L);
#endif /* NO_PROTO */
    numop = min(nlrmct,8);
    rnset_(&numop, &nlrmct, lisop);
    i__1 = numop;
    for (i = 1; i <= i__1; ++i) {
	nsmcv (&lrmcop[lisop[i - 1] - 1], &c__1, mc2d);
	s_wsfi(&io___41);
	do_fio(&c__1, (char *)&lrmcop[lisop[i - 1] - 1], (ftnlen)sizeof(
		integer));
	e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
	i__3[0] = 70, a__1[0] = "REGISTERED OPERATORS: Is the clipping of th"
		"e centered text primitive \"";
#else /* NO_PROTO */
	i__3[0] = 70, a__1[0] = "REGISTERED OPERATORS: Is the clipping of th\
e centered text primitive \"";
#endif /* NO_PROTO */
	i__3[1] = 23, a__1[1] = txstr;
	i__3[2] = 37, a__1[2] = "\" consistent with the description of ";
	i__3[3] = 22, a__1[3] = "combination operator #";
	i__3[4] = 3, a__1[4] = thisop;
	i__3[5] = 36, a__1[5] = ", as documented in the ISO register?";
	s_cat(ch__1, a__1, i__3, &c__6, 191L);
	if (! dyn_(ch__1, 191L)) {
	    fail_();
	    goto L160;
	}
/* L150: */
    }
    pass_();
L160:
/*  *** *** *** Implementor-defined Operators *** *** *** */
    if (nlimct == 0) {
#ifndef NO_PROTO
	inmsg_("No implementor-defined combination operators are supported f"
		"or setting modelling clipping volume.", 97L);
#else /* NO_PROTO */
	inmsg_("No implementor-defined combination operators are supported f\
or setting modelling clipping volume.", 97L);
#endif /* NO_PROTO */
	goto L170;
    }

#ifndef NO_PROTO
    setmsg_("35 40 45 57", "The effect of combination operators < 1 in <set "
	    "modelling clipping volume> should be as described in the impleme"
	    "ntor's documentation.", 11L, 133L);
#else /* NO_PROTO */
    setmsg_("35 40 45 57", "The effect of combination operators < 1 in <set \
modelling clipping volume> should be as described in the implementor's docum\
entation.", 11L, 133L);
#endif /* NO_PROTO */
    numop = min(nlimct,8);
    rnset_(&numop, &nlimct, lisop);
    i__1 = numop;
    for (i = 1; i <= i__1; ++i) {
	nsmcv (&limcop[lisop[i - 1] - 1], &c__1, mc2d);
	s_wsfi(&io___42);
	do_fio(&c__1, (char *)&limcop[lisop[i - 1] - 1], (ftnlen)sizeof(
		integer));
	e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
	i__3[0] = 74, a__1[0] = "IMPLEMENTATION OPERATORS: Is the clipping o"
		"f the centered text primitive \"";
#else /* NO_PROTO */
	i__3[0] = 74, a__1[0] = "IMPLEMENTATION OPERATORS: Is the clipping o\
f the centered text primitive \"";
#endif /* NO_PROTO */
	i__3[1] = 23, a__1[1] = txstr;
	i__3[2] = 37, a__1[2] = "\" consistent with the description of ";
	i__3[3] = 22, a__1[3] = "combination operator #";
	i__3[4] = 3, a__1[4] = thisop;
	i__3[5] = 35, a__1[5] = ", as documented by the implementor?";
	s_cat(ch__2, a__1, i__3, &c__6, 194L);
	if (! dyn_(ch__2, 194L)) {
	    fail_();
	    goto L170;
	}
/* L180: */
    }
    pass_();
L170:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

