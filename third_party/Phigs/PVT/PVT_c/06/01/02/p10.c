/* fort/06/01/02/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__14 = 14;
static integer c__3 = 3;
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b11 = .4f;
#else /* NO_PROTO */
static real c_b11 = (float).4;
#endif /* NO_PROTO */
static integer c__104 = 104;
static integer c__105 = 105;
#ifndef NO_PROTO
static real c_b19 = .1f;
#else /* NO_PROTO */
static real c_b19 = (float).1;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__103 = 103;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b40 = .066666666666666666f;
static real c_b67 = .2f;
static real c_b71 = .3f;
static real c_b93 = 1.5f;
static real c_b95 = 4.f;
static real c_b109 = 8.f;
static real c_b113 = -.05f;
static real c_b117 = 1.4f;
static real c_b121 = .8f;
#else /* NO_PROTO */
static real c_b40 = (float).066666666666666666;
static real c_b67 = (float).2;
static real c_b71 = (float).3;
static real c_b93 = (float)1.5;
static real c_b95 = (float)4.;
static real c_b109 = (float)8.;
static real c_b113 = (float)-.05;
static real c_b117 = (float)1.4;
static real c_b121 = (float).8;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/10                           * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of modelling           * */
/*  *                 transformation                        * */
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
    integer i__1, i__2[2];
    real r__1;
    char ch__1[118], ch__2[119], ch__3[104];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, z;
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc_(real *, real *, real *), etr_(real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc_(), etr_();
#endif /* NO_PROTO */
    static integer siz, perm[14];
    static real xloc[1];
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static char ques[63];
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nqpmf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *), nclst (void), 
	    nemst (integer *), nsgmt (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nqpmf (), nclst (), 
	    nemst (), nsgmt ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */, nommw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *), nsvwi (integer *), rn1shf_(integer *, integer *
	    ), dchpfv_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), numlab_(integer *, real *, real *, real *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst (), nsvwi (), 
	    rn1shf_(), dchpfv_(), chkinq_(), numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real exploc[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsmksc (real *), locppm_(integer *
	    , real *), nspmci (integer *), setrvs_(char *, real *, integer *, 
	    ftnlen), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsmksc (), 
	    locppm_(), nspmci (), setrvs_(), setmsg_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* marker type */
#ifndef NO_PROTO
    s_copy(ques, " Which line does NOT have a single accurately circled aste"
	    "risk?", 63L, 63L);
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    s_copy(ques, " Which line does NOT have a single accurately circled aste\
risk?", 63L, 63L);
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    initgl_("06.01.02/10", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  use <inquire polymarker facilities> to determine : */
/*     nommw = nominal marker-size (DC) */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nommw, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  *** *** *** *** ***    local transformation    *** *** *** *** *** */
/*   xloc = x-MC for polymarkers, (before transformation) = 0.2 */
#ifndef NO_PROTO
    xloc[0] = .2f;
#else /* NO_PROTO */
    xloc[0] = (float).2;
#endif /* NO_PROTO */
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    rn1shf_(&c__14, perm);
/*  polymarker style = asterisk */
    nsmk (&c__3);
/*  set marker size scale factor equivalent to WC = 0.04 */
#ifndef NO_PROTO
    r__1 = .04f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).04 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
/*  polymarker #1 */
    locppm_(perm, xloc);
    nexst (&c__102);
/*  polymarker #9 */
    locppm_(&perm[8], xloc);
/*  postconcatenate x-shift of +0.4 to local transformation */
    etr_(&c_b11, &z, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__1);
/*  polymarker #10 */
    locppm_(&perm[9], xloc);
/*  set global transformation to make markers #11,12 distinguishable */
/*    from #5,6 */
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    etr_(&z, &shifty, xform);
    chkinq_("etr", &errind, 3L);
    nsgmt (xform);
/*  execute 104 */
    nexst (&c__104);
/*  re-set global transformation to identity */
    idmat_(&c__3, xform);
    nsgmt (xform);
/*  polymarker #13 */
    locppm_(&perm[12], xloc);
/*  polymarker #14 */
    locppm_(&perm[13], xloc);
/*  execute 105 */
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
/*  polymarker #2 */
    locppm_(&perm[1], xloc);
/*  replace x-shift of +0.1 for local transformation */
    etr_(&c_b19, &z, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__2);
/*  execute 103 */
    nexst (&c__103);
/*  polymarker #8 */
    locppm_(&perm[7], xloc);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
/*  polymarker #3 */
    locppm_(&perm[2], xloc);
/*  preconcatenate x-shift of +0.1 to local transformation */
    etr_(&c_b19, &z, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__0);
/*  polymarker #4 */
    locppm_(&perm[3], xloc);
/*  execute 104 */
    nexst (&c__104);
/*  polymarker #7 */
    locppm_(&perm[6], xloc);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker #5 / #11 */
    locppm_(&perm[4], xloc);
/*  postconcatenate x-shift of +0.1 to local transformation */
    etr_(&c_b19, &z, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__1);
/*  polymarker #6 / #12 */
    locppm_(&perm[5], xloc);
    nclst ();
/*  structure #105 */
    nopst (&c__105);
/*  set marker style = circle */
    nsmk (&c__4);
/*  set marker size scale factor equivalent to WC = 0.05 */
#ifndef NO_PROTO
    r__1 = .05f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).05 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
    nspmci (&c__2);
/*  re-set local, global transformation to identity */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    nsgmt (xform);
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b19, &r__1, &c_b40);
    setrvs_("0.2,0.2,0.3,0.4,0.4,0.5,0.4,0.3,0.2,0.6,0.6,0.7,0.6,0.5", exploc,
	     &siz, 55L);
    i__1 = siz;
    for (ix = 1; ix <= i__1; ++ix) {
	locppm_(&perm[ix - 1], &exploc[ix - 1]);
/* L150: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 7 8 16 17 18 19 20 21 22", "The current local transformation "
	    "should be saved and restored by <execute structure> during trave"
	    "rsal.", 26L, 102L);
#else /* NO_PROTO */
    setmsg_("4 7 8 16 17 18 19 20 21 22", "The current local transformation \
should be saved and restored by <execute structure> during traversal.", 26L, 
	    102L);
#endif /* NO_PROTO */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 55, a__1[0] = "STRUCTURE NETWORK INHERITANCE FOR LOCAL TRANSFO"
	    "RMATION:";
#else /* NO_PROTO */
    i__2[0] = 55, a__1[0] = "STRUCTURE NETWORK INHERITANCE FOR LOCAL TRANSFO\
RMATION:";
#endif /* NO_PROTO */
    i__2[1] = 63, a__1[1] = ques;
    s_cat(ch__1, a__1, i__2, &c__2, 118L);
    dchpfv_(ch__1, &c__14, &perm[13], 118L);
/*  *** *** *** *** ***    global transformation    *** *** *** *** *** */

/*  clear the decks */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L200: */
    }
#ifndef NO_PROTO
    xloc[0] = .2f;
#else /* NO_PROTO */
    xloc[0] = (float).2;
#endif /* NO_PROTO */
    rn1shf_(&c__14, perm);
/*  structure #101 */
    nopst (&picstr);
    nsvwi (&c__1);
    setasf_(&c__1);
/*  polymarker style = asterisk */
    nsmk (&c__3);
/*  set marker size scale factor equivalent to WC = 0.04 */
#ifndef NO_PROTO
    r__1 = .04f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).04 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
/*  polymarker #1 */
    locppm_(perm, xloc);
/*  execute 102 */
    nexst (&c__102);
/*  polymarker #9 */
    locppm_(&perm[8], xloc);
/*  replace global transformation with x-shift of +0.4 */
    etr_(&c_b11, &z, xform);
    chkinq_("etr", &errind, 3L);
    nsgmt (xform);
/*  polymarker #10 */
    locppm_(&perm[9], xloc);
/*  set local transformation to make markers #11,12 distinguishable */
/*  from #5,6 */
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    etr_(&z, &shifty, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__2);
/*  execute 104 */
    nexst (&c__104);
/*  re-set local transformation to identity */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
/*  polymarker #13 */
    locppm_(&perm[12], xloc);
/*  polymarker #14 */
    locppm_(&perm[13], xloc);
/*  execute 105 */
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
/*  polymarker #2 */
    locppm_(&perm[1], xloc);
/*  replace global transformation with x-shift of +0.1 */
    etr_(&c_b19, &z, xform);
    chkinq_("etr", &errind, 3L);
    nsgmt (xform);
/*  execute 103 */
    nexst (&c__103);
/*  polymarker #8 */
    locppm_(&perm[7], xloc);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
/*  polymarker #3 */
    locppm_(&perm[2], xloc);
/*  replace global transformation with x-shift of +0.2 */
    etr_(&c_b67, &z, xform);
    chkinq_("etr", &errind, 3L);
    nsgmt (xform);
/*  polymarker #4 */
    locppm_(&perm[3], xloc);
/*  execute 104 */
    nexst (&c__104);
/*  polymarker #7 */
    locppm_(&perm[6], xloc);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker #5 / #11 */
    locppm_(&perm[4], xloc);
/*  replace global transformation with x-shift of +0.3 */
    etr_(&c_b71, &z, xform);
    chkinq_("etr", &errind, 3L);
    nsgmt (xform);
/*  polymarker #6 / #12 */
/*  Usually for inheritance tests, this would explicitly draw */
/*  something only at location PERM(6), and rely on a transformation */
/*  passed down from #101 to move it to location PERM(12) on the */
/*  second invocation.  However, since that inheritance gets done by */
/*  setting the global transformation to the old composite */
/*  transformation, and since we need to set the global */
/*  transformation explicitly, this is the one case where that trick */
/*  won't work; so we have to render explicitly at location 6 and 12 */
/*  both times; otherwise, we'd just get location 6. */
    locppm_(&perm[5], xloc);
    locppm_(&perm[11], xloc);
    nclst ();
/*  structure #105 */
    nopst (&c__105);
/*  set marker style = circle */
    nsmk (&c__4);
/*  set marker size scale factor equivalent to WC = 0.05 */
#ifndef NO_PROTO
    r__1 = .05f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).05 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
    nspmci (&c__2);
/*  re-set global transformation to identity */
    idmat_(&c__3, xform);
    nsgmt (xform);
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b19, &r__1, &c_b40);
    setrvs_("0.2,0.2,0.3,0.4,0.4,0.5,0.4,0.3,0.2,0.6,0.6,0.5,0.6,0.5", exploc,
	     &siz, 55L);
    i__1 = siz;
    for (ix = 1; ix <= i__1; ++ix) {
	locppm_(&perm[ix - 1], &exploc[ix - 1]);
/* L250: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("12 15 16 17 18 19 20 21 22", "The current global transformation"
	    " should be saved and restored by <execute structure> during trav"
	    "ersal.", 26L, 103L);
#else /* NO_PROTO */
    setmsg_("12 15 16 17 18 19 20 21 22", "The current global transformation\
 should be saved and restored by <execute structure> during traversal.", 26L, 
	    103L);
#endif /* NO_PROTO */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 56, a__1[0] = "STRUCTURE NETWORK INHERITANCE FOR GLOBAL TRANSF"
	    "ORMATION:";
#else /* NO_PROTO */
    i__2[0] = 56, a__1[0] = "STRUCTURE NETWORK INHERITANCE FOR GLOBAL TRANSF\
ORMATION:";
#endif /* NO_PROTO */
    i__2[1] = 63, a__1[1] = ques;
    s_cat(ch__2, a__1, i__2, &c__2, 119L);
    dchpfv_(ch__2, &c__14, &perm[13], 119L);
/*  *** *** *** *** ***    composite transformation    *** *** *** *** ***
 */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L300: */
    }
#ifndef NO_PROTO
    xloc[0] = .1f;
#else /* NO_PROTO */
    xloc[0] = (float).1;
#endif /* NO_PROTO */
    rn1shf_(&c__14, perm);
/*  structure #101 */
    nopst (&picstr);
    nsvwi (&c__1);
    setasf_(&c__1);
/*  polymarker style = asterisk */
    nsmk (&c__3);
/*  set marker size scale factor equivalent to WC = 0.04 */
#ifndef NO_PROTO
    r__1 = .04f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).04 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
/*  set global transformation = scale X by 1.5 */
    esc_(&c_b93, &u, xform);
    chkinq_("esc", &errind, 3L);
    nsgmt (xform);
/*  set local transformation  = scale X by 4 */
    esc_(&c_b95, &u, xform);
    chkinq_("esc", &errind, 3L);
    nslmt (xform, &c__2);
/*  polymarker #1 */
    locppm_(perm, xloc);
/*  execute 102 */
    nexst (&c__102);
/*  polymarker #9 */
    locppm_(&perm[8], xloc);
/*  replace local transformation with x-shift of +0.1 */
    etr_(&c_b19, &z, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__2);
/*  polymarker #10 */
    locppm_(&perm[9], xloc);
/*  set local transformation to make markers #11,12 distinguishable */
/*    from #5,6: preconcatenate appropriate y-shift */
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    etr_(&z, &shifty, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__0);
/*  execute 104 */
    nexst (&c__104);
/*  re-set local transformation: preconcatenate negative y-shift */
    r__1 = -(doublereal)shifty;
    etr_(&z, &r__1, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__0);
/*  polymarker #13 */
    locppm_(&perm[12], xloc);
/*  polymarker #14 */
    locppm_(&perm[13], xloc);
/*  execute 105 */
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
/*  polymarker #2 */
    locppm_(&perm[1], xloc);
/*  set global transformation = scale X by 8 */
    esc_(&c_b109, &u, xform);
    chkinq_("esc", &errind, 3L);
    nsgmt (xform);
/*  execute 103 */
    nexst (&c__103);
/*  polymarker #8 */
    locppm_(&perm[7], xloc);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
/*  polymarker #3 */
    locppm_(&perm[2], xloc);
/*  set local transformation = shift X by -0.05 */
    etr_(&c_b113, &z, xform);
    chkinq_("etr", &errind, 3L);
    nslmt (xform, &c__2);
/*  polymarker #4 */
    locppm_(&perm[3], xloc);
/*  execute 104 */
    nexst (&c__104);
/*  postconcatenate to local transformation: scale X by 1.4 */
    esc_(&c_b117, &u, xform);
    chkinq_("esc", &errind, 3L);
    nslmt (xform, &c__1);
/*  polymarker #7 */
    locppm_(&perm[6], xloc);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker #5 / #11 */
    locppm_(&perm[4], xloc);
/*  set local transformation = scale X by 0.8 */
    esc_(&c_b121, &u, xform);
    chkinq_("esc", &errind, 3L);
    nslmt (xform, &c__2);
/*  polymarker #6 / #12 */
    locppm_(&perm[5], xloc);
    nclst ();
/*  structure #105 */
    nopst (&c__105);
/*  set marker style = circle */
    nsmk (&c__4);
/*  set marker size scale factor equivalent to WC = 0.05 */
#ifndef NO_PROTO
    r__1 = .05f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).05 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
    nspmci (&c__2);
/*  re-set global transformation to identity */
    idmat_(&c__3, xform);
    nsgmt (xform);
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b19, &r__1, &c_b40);
    setrvs_("0.6,0.6,0.8,0.4,0.4,0.24,0.56,0.8,0.6,0.3,0.3,0.27,0.3,0.27", 
	    exploc, &siz, 59L);
    i__1 = siz;
    for (ix = 1; ix <= i__1; ++ix) {
	locppm_(&perm[ix - 1], &exploc[ix - 1]);
/* L350: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 8 12 15 16 17 18 19 20 21 22", "For an executed structure, it"
	    "s global transformation should be initialized to the composite t"
	    "ransformation of the invoking structure and its local transforma"
	    "tion should be initialized to the identity transformation.", 30L, 
	    215L);
#else /* NO_PROTO */
    setmsg_("4 8 12 15 16 17 18 19 20 21 22", "For an executed structure, it\
s global transformation should be initialized to the composite transformatio\
n of the invoking structure and its local transformation should be initializ\
ed to the identity transformation.", 30L, 215L);
#endif /* NO_PROTO */
/* Writing concatenation */
    i__2[0] = 41, a__1[0] = "INHERITANCE OF MODELLING TRANSFORMATIONS:";
    i__2[1] = 63, a__1[1] = ques;
    s_cat(ch__3, a__1, i__2, &c__2, 104L);
    dchpfv_(ch__3, &c__14, &perm[13], 104L);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

