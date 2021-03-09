/* fort/02/03/03/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__123 = 123;
static integer c__101 = 101;
static integer c__2 = 2;
static integer c__102 = 102;
static integer c__1 = 1;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b29 = 3.f;
static real c_b42 = 5.5f;
static real c_b45 = 1.53f;
#else /* NO_PROTO */
static real c_b29 = (float)3.;
static real c_b42 = (float)5.5;
static real c_b45 = (float)1.53;
#endif /* NO_PROTO */
static integer c__20 = 20;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/06                           * */
/*  *    TEST TITLE : Modelling transformation and clipping * */
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
    integer i__1;
    real r__1, r__2, r__3;
    logical L__1;

    /* Local variables */
    static real m1[16]	/* was [4][4] */, m2[16]	/* was [4][4] */, tx, 
	    ty, tz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), vec1_(real *,
	     real *, real *, real *, real *, real *), etp3_(real *, real *, 
	    real *, real *, real *, real *, real *), etr3_(real *, real *, 
	    real *, real *), npm3 (integer *, real *, real *, real *), fail_(
	    void), ifpf_(logical *), ndel (void), ndas (void);
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), vec1_(), etp3_(), etr3_(), npm3 (), 
	    fail_(), ifpf_(), ndel (), ndas ();
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static integer idum[2];
    static real rdum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real srpx, srpy, srpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static integer m1len, m2len, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int niss3 (real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int niss3 ();
#endif /* NO_PROTO */
    static integer falen;
#ifndef NO_PROTO
    extern /* Subroutine */ int issab_(real *, real *, real *, real *, char *,
	     integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int issab_();
#endif /* NO_PROTO */
    static integer fpath[40]	/* was [2][20] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real nvecl, dvecx;
    static integer pmlen, exlen;
    static real mcomp[16]	/* was [4][4] */, dvecy, clvcx, clvcy, clvcz, 
	    nvecx, nvecy, sdist, nvecz, dvecz;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real clptx, clpty, clptz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), setvs_(char *
	    , integer *, integer *, ftnlen), nopst (integer *), ptspl_(
	    integer *, real *, real *, real *, real *, real *, real *, real *)
	    , nsmcv3 (integer *, integer *, real *), arrtp3_(integer *, real *
	    , real *, real *, real *, real *, real *, real *), nsgmt3 (real *)
	    , nslmt3 (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), setvs_(), nopst (), 
	    ptspl_(), nsmcv3 (), arrtp3_(), nsgmt3 (), nslmt3 ();
#endif /* NO_PROTO */
    static real falocx[10], falocy[10], falocz[10], halfsp[60]	/* was [6][10]
	     */;
#ifndef NO_PROTO
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, expath[40]	/* was [2][20] */;
    static real pmlocx[5];
    static integer stpath[10]	/* was [2][5] */;
    static real pmlocy[5], pmlocz[5], exlocx, tplocx[10], tplocy[10], tplocz[
	    10], exlocy, exlocz;
    static integer fpthsz;
#ifndef NO_PROTO
    extern doublereal ptregd_(real *, real *, real *, integer *, real *, real 
	    *, real *);
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen), nsmcli (integer *), ptlnds_(real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal ptregd_();
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), setmsg_(), 
	    nsmcli (), ptlnds_();
#endif /* NO_PROTO */

/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("02.03.03/06", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    if (! sphdis_(&c__123)) {
#ifndef NO_PROTO
	inmsg_("Skipping test because implementation apparently uses non-Euc"
		"lidean metric for search distance.", 94L);
#else /* NO_PROTO */
	inmsg_("Skipping test because implementation apparently uses non-Euc\
lidean metric for search distance.", 94L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  m1 = random transformation matrix */
/*     =   1.43  -2.41  3.25 -1.15 */
/*        -3.25  -3.13  2.54 -1.35 */
/*        -2.43  -1.54  2.31  1.42 */
/*         3.51  -2.32  2.41  3.25 */
#ifndef NO_PROTO
    setrvs_(" 1.43,  -3.25, -2.43,  3.51,  -2.41,  -3.13, -1.54, -2.32,   3."
	    "25,   2.54,  2.31,  2.41,  -1.15,  -1.35,  1.42,  3.25", m1, &
	    m1len, 117L);
#else /* NO_PROTO */
    setrvs_(" 1.43,  -3.25, -2.43,  3.51,  -2.41,  -3.13, -1.54, -2.32,   3.\
25,   2.54,  2.31,  2.41,  -1.15,  -1.35,  1.42,  3.25", m1, &m1len, 117L);
#endif /* NO_PROTO */
/*  m2 = random transformation matrix */
/*     =   -1.23   1.23  -1.02   9.30 */
/*          1.28  -9.34   0.93  -4.89 */
/*          2.03   9.85   4.01  -9.23 */
/*          4.18  -0.12  -9.34   8.01 */
#ifndef NO_PROTO
    setrvs_("-1.23,  1.28,  2.03,  4.18,  1.23, -9.34,  9.85, -0.12, -1.02, "
	    " 0.93,  4.01, -9.34,  9.30, -4.89, -9.23,  8.01", m2, &m2len, 
	    110L);
#else /* NO_PROTO */
    setrvs_("-1.23,  1.28,  2.03,  4.18,  1.23, -9.34,  9.85, -0.12, -1.02, \
 0.93,  4.01, -9.34,  9.30, -4.89, -9.23,  8.01", m2, &m2len, 110L);
#endif /* NO_PROTO */
/*  *** *** *** ***   Modelling transformations   *** *** *** *** */

/*  set up structure #101: */
/*  1. set local transformation = m1 */
/*  2. execute structure 102 */
    nopst (&c__101);
    nslmt3 (m1, &c__2);
    nexst (&c__102);
    nclst ();
/*  pmloc = polymarker location = -6.347, 4.637, 1.082 */
#ifndef NO_PROTO
    pmlocx[0] = -6.347f;
    pmlocy[0] = 4.637f;
    pmlocz[0] = 1.082f;
#else /* NO_PROTO */
    pmlocx[0] = (float)-6.347;
    pmlocy[0] = (float)4.637;
    pmlocz[0] = (float)1.082;
#endif /* NO_PROTO */
/*  set up structure #102: */
/*  1. set global transformation = m2 */
/*  2. polymarker at pmloc */
    nopst (&c__102);
    nsgmt3 (m2);
    npm3 (&c__1, pmlocx, pmlocy, pmlocz);
    nclst ();
/*  exloc = expected WC location = m2 X m1 X pmloc */
    ecom3_(m2, m1, mcomp);
    etp3_(pmlocx, pmlocy, pmlocz, mcomp, &exlocx, &exlocy, &exlocz);
#ifndef NO_PROTO
    sdist = .1f;
#else /* NO_PROTO */
    sdist = (float).1;
#endif /* NO_PROTO */
    srpx = exlocx + sdist;
    srpy = exlocy;
    srpz = exlocz;
#ifndef NO_PROTO
    setmsg_("2 3 4 5 6 8 10", "ISS should detect a primitive according to it"
	    "s location in world coordinates, computed with the current compo"
	    "site modelling transformation, including the effect of inherited"
	    " transformations.", 14L, 190L);
#else /* NO_PROTO */
    setmsg_("2 3 4 5 6 8 10", "ISS should detect a primitive according to it\
s location in world coordinates, computed with the current composite modelli\
ng transformation, including the effect of inherited transformations.", 14L, 
	    190L);
#endif /* NO_PROTO */
/*  ISS twice with SRP, varying search distance */
/*    starting path:  101,1, 102,1 */
/*    search ceiling: 2 */
/*    expected path:  101,1, 102,2 */
#ifndef NO_PROTO
    issab_(&srpx, &srpy, &srpz, &sdist, "101,1, 102,1", &c__0, &c__2, "101,1"
	    ", 102,2", 12L, 12L);
#else /* NO_PROTO */
    issab_(&srpx, &srpy, &srpz, &sdist, "101,1, 102,1", &c__0, &c__2, "101,1\
, 102,2", 12L, 12L);
#endif /* NO_PROTO */
/*  exloc = expected WC location = m2 X pmloc */
    etp3_(pmlocx, pmlocy, pmlocz, m2, &exlocx, &exlocy, &exlocz);
#ifndef NO_PROTO
    sdist = .1f;
#else /* NO_PROTO */
    sdist = (float).1;
#endif /* NO_PROTO */
    srpx = exlocx + sdist;
    srpy = exlocy;
    srpz = exlocz;
#ifndef NO_PROTO
    setmsg_("2 3 4 5 6 10", "ISS should detect a primitive according to its "
	    "location in world coordinates, computed with the current composi"
	    "te modelling transformation when there are no inherited transfor"
	    "mations.", 12L, 183L);
#else /* NO_PROTO */
    setmsg_("2 3 4 5 6 10", "ISS should detect a primitive according to its \
location in world coordinates, computed with the current composite modelling\
 transformation when there are no inherited transformations.", 12L, 183L);
#endif /* NO_PROTO */
/*  ISS twice with SRP, varying search distance */
/*    starting path:  102,1 */
/*    search ceiling: 1 */
/*    expected path:  102,2 */
    issab_(&srpx, &srpy, &srpz, &sdist, "102,1", &c__0, &c__1, "102,2", 5L, 
	    5L);
/*  *** *** *** ***   Modelling clipping   *** *** *** *** */

/*  clear CSS */
    ndas ();
/*  set up structure #101: */
/*    1. set modelling clipping CLIP */
/*    2. set modelling clipping volume with: */
/*          point         =  5, 5, 5 */
/*          normal vector = -1,-1,-1 */
/*    3. set local transformation = shift by +3,+3,+3 */
/*    4. polymarker at MC: 4,4,4 (WC will be 7,7,7) */
/*    5. polymarker at MC: 1,1,1 (WC will be 4,4,4) */
    nopst (&c__101);
    nsmcli (&c__1);
    setrvs_("5,5,5, -1,-1,-1", halfsp, &idum1, 15L);
    nsmcv3 (&c__1, &c__1, halfsp);
    etr3_(&c_b29, &c_b29, &c_b29, m2);
    nslmt3 (m2, &c__2);
    setrvs_("4,1", pmlocx, &pmlen, 3L);
    setrvs_("4,1", pmlocy, &pmlen, 3L);
    setrvs_("4,1", pmlocz, &pmlen, 3L);
    npm3 (&c__1, pmlocx, pmlocy, pmlocz);
    npm3 (&c__1, &pmlocx[1], &pmlocy[1], &pmlocz[1]);
#ifndef NO_PROTO
    setmsg_("2 3 4 5 6 10", "If the modelling clip flag is NOCLIP, ISS shoul"
	    "d detect a primitive whether or not its location in world coordi"
	    "nates is outside the current modelling clipping volume, even if "
	    "the current modelling clipping indicator is CLIP.", 12L, 224L);
#else /* NO_PROTO */
    setmsg_("2 3 4 5 6 10", "If the modelling clip flag is NOCLIP, ISS shoul\
d detect a primitive whether or not its location in world coordinates is out\
side the current modelling clipping volume, even if the current modelling cl\
ipping indicator is CLIP.", 12L, 224L);
#endif /* NO_PROTO */
/*  ISS twice with */
/*    modelling clip flag: NOCLIP */
/*    SRP:                 5.5,5.5,5.5 */
/*    search distance:     1.02*1.5 */

/*  pass/fail depending on */
/*    (found at 101,4 with starting path = 101,0  and */
/*     found at 101,5 with starting path = 101,4) */
    setvs_("101,0", stpath, &idum1, 5L);
    setvs_("101,4", expath, &exlen, 5L);
    niss3 (&c_b42, &c_b42, &c_b42, &c_b45, &c__1, stpath, &c__0, &c__1, &c__0,
	     idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__20, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && iareql_(&i__1, fpath, &exlen, expath)) {
/*        OK so far */
    } else {
	fail_();
	goto L300;
    }
    setvs_("101,4", stpath, &idum1, 5L);
    setvs_("101,5", expath, &exlen, 5L);
    niss3 (&c_b42, &c_b42, &c_b42, &c_b45, &c__1, stpath, &c__0, &c__1, &c__0,
	     idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__20, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &exlen, expath);
    ifpf_(&L__1);
L300:
/*  change element #1 of structure 101 to: */
/*    1. set modelling clipping NOCLIP */
    nsep (&c__1);
    ndel ();
    nsmcli (&c__0);
    nclst ();
#ifndef NO_PROTO
    setmsg_("2 3 4 5 6 10", "If the modelling clip flag is CLIP, ISS should "
	    "detect only those primitives whose location in world coordinates"
	    " is inside the current modelling clipping volume, even if the cu"
	    "rrent modelling clipping indicator is NOCLIP.", 12L, 220L);
#else /* NO_PROTO */
    setmsg_("2 3 4 5 6 10", "If the modelling clip flag is CLIP, ISS should \
detect only those primitives whose location in world coordinates is inside t\
he current modelling clipping volume, even if the current modelling clipping\
 indicator is NOCLIP.", 12L, 220L);
#endif /* NO_PROTO */
/*  ISS with */
/*    modelling clip flag: CLIP */
/*    SRP:                 5.5,5.5,5.5 */
/*    search distance:     1.02*1.5 */

/*  pass/fail depending on */
/*    (found at 101,5 with starting path = 101,0) */
    setvs_("101,0", stpath, &idum1, 5L);
    setvs_("101,5", expath, &exlen, 5L);
    niss3 (&c_b42, &c_b42, &c_b42, &c_b45, &c__1, stpath, &c__1, &c__1, &c__0,
	     idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__20, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &exlen, expath);
    ifpf_(&L__1);
/*  *** *** *** ***   Complex primitive   *** *** *** *** */

/*  clear CSS */
    ndas ();
/*  set up vertices for complex fill area: */

/*     1----------2    p1: 0, 1 */
/*     |          |    p2: 3, 1 */
/*     |  5---6   |    p3: 3,-2 */
/*     |  |   |   |    p4: 1,-2 */
/*     |  |   |   |    p5: 1, 0 */
/*     8--+---7   |    p6: 2, 0 */
/*        |       |    p7: 2,-1 */
/*        4-------3    p8: 0,-1 */
    setrvs_(" 0, 3, 3, 1, 1, 2, 2, 0", falocx, &falen, 23L);
    setrvs_(" 1, 1,-2,-2, 0, 0,-1,-1", falocy, &falen, 23L);
    setrvs_(" 0, 0, 0, 0, 0, 0, 0, 0", falocz, &falen, 23L);
/*  tp1-tp8 = WC vertices = m1 X p1-p8 */
    arrtp3_(&falen, falocx, falocy, falocz, m1, tplocx, tplocy, tplocz);
/*  nvec = unit vector normal to WC plane of fill area */
    ptspl_(&falen, tplocx, tplocy, tplocz, &tx, &ty, &tz, &rdum);
    vec1_(&tx, &ty, &tz, &nvecx, &nvecy, &nvecz);
/*  set up structure #101: */
/*  1. set global transformation = m1 */
/*  2. fill area at p1-p8 */
    nopst (&c__101);
    nsgmt3 (m1);
    nfa (&falen, falocx, falocy);
    nclst ();
/* SRP   = point over hole in fill area = average of pt5,pt6,pt7 + 0.02*nv
ec*/
#ifndef NO_PROTO
    srpx = (tplocx[4] + tplocx[5] + tplocx[6]) / 3 + nvecx * .02f;
    srpy = (tplocy[4] + tplocy[5] + tplocy[6]) / 3 + nvecy * .02f;
    srpz = (tplocz[4] + tplocz[5] + tplocz[6]) / 3 + nvecz * .02f;
#else /* NO_PROTO */
    srpx = (tplocx[4] + tplocx[5] + tplocx[6]) / 3 + nvecx * (float).02;
    srpy = (tplocy[4] + tplocy[5] + tplocy[6]) / 3 + nvecy * (float).02;
    srpz = (tplocz[4] + tplocz[5] + tplocz[6]) / 3 + nvecz * (float).02;
#endif /* NO_PROTO */
/*  Note: the particular values chosen for FALOC preserve the "hole" */
/*  at p5-7, but since M1 is a distorting transformation, this will */
/*  not always be the case with other values for FALOC. */
/*  sdist = distance from SRP to fill area, as computed by PTREGD */
    sdist = ptregd_(&srpx, &srpy, &srpz, &falen, tplocx, tplocy, tplocz);
#ifndef NO_PROTO
    setmsg_("2 3 4 5 6 10 13", "ISS should detect a complex primitive accord"
	    "ing to its location in world coordinates.", 15L, 85L);
#else /* NO_PROTO */
    setmsg_("2 3 4 5 6 10 13", "ISS should detect a complex primitive accord\
ing to its location in world coordinates.", 15L, 85L);
#endif /* NO_PROTO */
/*  ISS twice with SRP, NOCLIP, varying search distance */
/*    starting path:  101,0 */
/*    search ceiling: 1 */
/*    expected path:  101,2 */
    issab_(&srpx, &srpy, &srpz, &sdist, "101,0", &c__0, &c__1, "101,2", 5L, 
	    5L);
/*  *** *** *** ***   Complex clipping   *** *** *** *** */

/*  set up vertices for fill area: */

/*        1----------2     p1: 3,2 */
/*       /           /     p2: 6,2 */
/*      /           /      p3: 4,-1 */
/*     4           /       p4: 1,1 */
/*      \         / */
/*       \       / */
/*        \     / */
/*         \   / */
/*          \ / */
/*           3 */
    setrvs_("3,6, 4,1", falocx, &falen, 8L);
    setrvs_("2,2,-1,1", falocy, &falen, 8L);
    setrvs_("0,0, 0,0", falocz, &falen, 8L);
/*  tp1-tp4 = WC vertices = m1 X p1-p4 */
    arrtp3_(&falen, falocx, falocy, falocz, m1, tplocx, tplocy, tplocz);
/*  clpt  = WC clip point  = point on tp2:tp4 line segment closest to tp1 
*/
/*    (tp1 normal projection onto line segment) */
    r__1 = tplocx[1] - tplocx[3];
    r__2 = tplocy[1] - tplocy[3];
    r__3 = tplocz[1] - tplocz[3];
    ptlnds_(tplocx, tplocy, tplocz, &r__1, &r__2, &r__3, &tplocx[3], &tplocy[
	    3], &tplocz[3], &clptx, &clpty, &clptz, &rdum);
/*  clvec = WC clip vector = vector from clpt to tp1 (in WC plane of */
/*     fill area, normal to line between tp2 and tp4, towards tp1). */
    clvcx = tplocx[0] - clptx;
    clvcy = tplocy[0] - clpty;
    clvcz = tplocz[0] - clptz;
/*  nvec  = unit vector normal to WC fill area plane */
    ptspl_(&falen, tplocx, tplocy, tplocz, &tx, &ty, &tz, &rdum);
    vec1_(&tx, &ty, &tz, &nvecx, &nvecy, &nvecz);
/*  set up structure #102: */
/*  1. set modelling clipping volume with: */
/*        point         = clpt */
/*        normal vector = clvec */
/*  2. set global transformation = m1 */
/*  3. fill area at p1-p4 */
    nopst (&c__102);
    halfsp[0] = clptx;
    halfsp[1] = clpty;
    halfsp[2] = clptz;
    halfsp[3] = clvcx;
    halfsp[4] = clvcy;
    halfsp[5] = clvcz;
    nsmcv3 (&c__1, &c__1, halfsp);
    nsgmt3 (m1);
    nfa (&falen, falocx, falocy);
    nclst ();
/*  dvec = vector away from clipping volume and up from fill area plane */

    nvecl = vecl_(&clvcx, &clvcy, &clvcz) / 10;
    dvecx = nvecl * nvecx - clvcx / 2;
    dvecy = nvecl * nvecy - clvcy / 2;
    dvecz = nvecl * nvecz - clvcz / 2;
/*  SRP = clpt + dvec (outside clipping volume) */
    srpx = clptx + dvecx;
    srpy = clpty + dvecy;
    srpz = clptz + dvecz;
/*  sdist = length of dvec */
    sdist = vecl_(&dvecx, &dvecy, &dvecz);
/*  Note: this is not a general-purpose formula - only works when */
/*  clip point is inside transformed quadrilateral.  Since M1 is a */
/*  distorting transformation, this will not always be the case, */
/*  although it is for the particular values chosen for FALOC. */
#ifndef NO_PROTO
    setmsg_("2 3 4 5 6 10 13", "If the modelling clip flag is CLIP, ISS shou"
	    "ld detect only those portions of a complex primitive whose locat"
	    "ion in world coordinates is inside the current modelling clippin"
	    "g volume.", 15L, 181L);
#else /* NO_PROTO */
    setmsg_("2 3 4 5 6 10 13", "If the modelling clip flag is CLIP, ISS shou\
ld detect only those portions of a complex primitive whose location in world\
 coordinates is inside the current modelling clipping volume.", 15L, 181L);
#endif /* NO_PROTO */
/*  ISS twice with SRP, CLIP, varying search distance */
/*    starting path:  102,0 */
/*    search ceiling: 1 */
/*    expected path:  102,3 */
    issab_(&srpx, &srpy, &srpz, &sdist, "102,0", &c__1, &c__1, "102,3", 5L, 
	    5L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

