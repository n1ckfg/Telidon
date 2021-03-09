/* fort/09/01/04/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b31 = .6f;
static real c_b32 = .3f;
static real c_b33 = 0.f;
static real c_b34 = 1.f;
#else /* NO_PROTO */
static real c_b31 = (float).6;
static real c_b32 = (float).3;
static real c_b33 = (float)0.;
static real c_b34 = (float)1.;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b42 = .01f;
static real c_b44 = .1f;
static real c_b45 = .8f;
static real c_b50 = .9f;
static real c_b51 = .5f;
static real c_b56 = .001f;
static real c_b115 = .7f;
static real c_b124 = .2f;
static real c_b126 = .4f;
#else /* NO_PROTO */
static real c_b42 = (float).01;
static real c_b44 = (float).1;
static real c_b45 = (float).8;
static real c_b50 = (float).9;
static real c_b51 = (float).5;
static real c_b56 = (float).001;
static real c_b115 = (float).7;
static real c_b124 = (float).2;
static real c_b126 = (float).4;
#endif /* NO_PROTO */
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b319 = -.1f;
static real c_b326 = 1.1f;
#else /* NO_PROTO */
static real c_b319 = (float)-.1;
static real c_b326 = (float)1.1;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04150                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04150_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04150_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, isiz, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer maxvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer nvwix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr (integer *, integer *, real *, real *, 
	    real *, integer *), rsvwr_(integer *, integer *, real *, real *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real clplm3[4], clplm4[6], mapmt3[9]	/* was [3][3] */, mapmt4[16]	
	    /* was [4][4] */, rotmt3[9]	/* was [3][3] */, rotmt4[16]	/* 
	    was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvwr3_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), chkinq_(char *, integer 
	    *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqevwi (integer *, integer *, integer *, integer *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqevwi (), nqwksl (), 
	    setrvs_();
#endif /* NO_PROTO */

/*   E04150 tests the handling of error 150 */
/*   clipping indicator */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "setting this view table entry would exceed the "
	    "maximum number of entries allowed in the workstation view table", 
	    200L, 110L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "setting this view table entry would exceed the \
maximum number of entries allowed in the workstation view table", 200L, 110L);

#endif /* NO_PROTO */
    setvs_("150", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &idum7, &maxvw);
    chkinq_("pqwksl", &errind, 6L);
    idmat_(&c__3, rotmt3);
    idmat_(&c__3, mapmt3);
    idmat_(&c__4, rotmt4);
    idmat_(&c__4, mapmt4);
    setrvs_("0.,1.,0.,1.", clplm3, &isiz, 11L);
    setrvs_("0.,1.,0.,1.,0.,1.", clplm4, &isiz, 17L);
/*  valid entries are 0 (unsettable) thru MAXVW-1 */
    i__1 = maxvw - 1;
    for (ix = 1; ix <= i__1; ++ix) {
	nsvwr (&globnu_1.wkid, &ix, rotmt3, mapmt3, clplm3, &c__1);
/* L100: */
    }
    rsvwr_(&globnu_1.wkid, &maxvw, rotmt3, mapmt3, clplm3, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &nvwix, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    L__1 = streq_("OO**", 4L) && nvwix == maxvw;
    tstign_(&L__1);
    rsvwr3_(&globnu_1.wkid, &maxvw, rotmt4, mapmt4, clplm4, &c__1, &c__1, &
	    c__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04150_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04151                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04151_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04151_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer isiz;
    static real wkwn[6];
    static integer idum1;
    static real wkwn0[6], wkwn1[6], wkwn4[4];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real rduma[6], rdumb[6], rdumc[6], rdumd[4], rdume[4], rdumf[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqwkt (integer *, 
	    integer *, integer *, real *, real *, real *, real *), nswkw (
	    integer *, real *, real *, real *, real *), rswkw_(integer *, 
	    real *, real *, real *, real *), nqwkt3 (integer *, integer *, 
	    integer *, real *, real *, real *, real *), nswkw3 (integer *, 
	    real *), rswkw3_(integer *, real *), chkinq_(char *, integer *, 
	    ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern logical rareq_();
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqwkt (), nswkw (), 
	    rswkw_(), nqwkt3 (), nswkw3 (), rswkw3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*   E0451 tests the handling of error 151. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation window limits are inv"
	    "alid: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, UMIN>=UMAX, or VMIN>=VM"
	    "AX", 200L, 113L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation window limits are inv\
alid: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, UMIN>=UMAX, or VMIN>=VMAX", 200L, 
	    113L);
#endif /* NO_PROTO */
    setvs_("151", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    setrvs_(".1,.9,.1,.9,.1,.9", wkwn0, &isiz, 17L);
    nswkw3 (&globnu_1.wkid, wkwn0);
    setrvs_(".6,.3,0.,1.,0.,1.", wkwn, &isiz, 17L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,.6,.6,0.,1.", wkwn, &isiz, 17L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,0.,1.,.6,.3", wkwn, &isiz, 17L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,.6,.3,0.,0.", wkwn, &isiz, 17L);
    rswkw3_(&globnu_1.wkid, wkwn);
    rswkw_(&globnu_1.wkid, &c_b31, &c_b32, &c_b33, &c_b34);
    rswkw_(&globnu_1.wkid, &c_b33, &c_b34, &c_b31, &c_b32);
    nqwkt3 (&globnu_1.wkid, &errind, &idum1, wkwn1, rduma, rdumb, rdumc);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__6, wkwn0, wkwn1, &c_b42, &c_b42);
    tstign_(&L__1);
    nswkw (&globnu_1.wkid, &c_b44, &c_b45, &c_b44, &c_b45);
    rswkw_(&globnu_1.wkid, &c_b31, &c_b32, &c_b50, &c_b51);
    nqwkt (&globnu_1.wkid, &errind, &idum1, wkwn4, rdumd, rdume, rdumf);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = streq_("OO**", 4L) && appeq_(wkwn4, &c_b44, &c_b42, &c_b56) && 
	    appeq_(&wkwn4[1], &c_b45, &c_b42, &c_b56) && appeq_(&wkwn4[2], &
	    c_b44, &c_b42, &c_b56) && appeq_(&wkwn4[3], &c_b45, &c_b42, &
	    c_b56);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04151_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04152                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04152_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04152_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real dx, dy, dz, xx, yy, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ds3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ds3_();
#endif /* NO_PROTO */
    static real wkvp[6];
    static integer idum1, idum2, idum3, idum4;
    static real wkvp0[6], wkvp1[6], wkvp4[4];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real rduma[6], rdumb[6], rdumc[6], rdumd[4], rdume[4], rdumf[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nqdsp (integer *, integer *, integer *, 
	    real *, real *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqwkt (integer *, 
	    integer *, integer *, real *, real *, real *, real *), nswkv (
	    integer *, real *, real *, real *, real *), rswkv_(integer *, 
	    real *, real *, real *, real *), nqdsp3 (integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    ), nqwkt3 (integer *, integer *, integer *, real *, real *, real *
	    , real *), nswkv3 (integer *, real *), rswkv3_(integer *, real *),
	     chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern logical rareq_();
    extern /* Subroutine */ int nclwk (), nqwkc (), nqdsp ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqwkt (), nswkv (), 
	    rswkv_(), nqdsp3 (), nqwkt3 (), nswkv3 (), rswkv3_(), chkinq_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */

/*    E04152 tests the handling of error 152 */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation viewport limits are i"
	    "nvalid: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 200L, 91L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation viewport limits are i\
nvalid: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 200L, 91L);
#endif /* NO_PROTO */
    setvs_("152", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqdsp3 (&specwt, &errind, &idum1, &dx, &dy, &dz, &idum2, &idum3, &idum4);
    chkinq_("pqdsp3", &errind, 6L);
#ifndef NO_PROTO
    xx = dx / 2.f;
    yy = dy / 2.f;
    zz = dz / 2.f;
#else /* NO_PROTO */
    xx = dx / (float)2.;
    yy = dy / (float)2.;
    zz = dz / (float)2.;
#endif /* NO_PROTO */
    ds3_(&c_b33, &xx, &c_b33, &yy, &c_b33, &zz, wkvp0);
    nswkv3 (&globnu_1.wkid, wkvp0);
    ds3_(&xx, &c_b33, &c_b33, &dy, &c_b33, &dz, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
    ds3_(&dx, &dx, &c_b33, &yy, &c_b33, &dz, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
    ds3_(&c_b33, &dx, &c_b33, &dy, &zz, &c_b33, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
    ds3_(&c_b33, &dx, &yy, &yy, &zz, &zz, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
    nqwkt3 (&globnu_1.wkid, &errind, &idum1, rduma, rdumb, wkvp1, rdumc);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__6, wkvp1, wkvp0, &c_b42, &c_b42);
    tstign_(&L__1);
    nqdsp (&specwt, &errind, &idum1, &dx, &dy, &idum2, &idum3);
    chkinq_("pqdsp", &errind, 5L);
#ifndef NO_PROTO
    xx = dx / 2.f;
    yy = dy / 2.f;
#else /* NO_PROTO */
    xx = dx / (float)2.;
    yy = dy / (float)2.;
#endif /* NO_PROTO */
    nswkv (&globnu_1.wkid, &c_b33, &xx, &c_b33, &yy);
    rswkv_(&globnu_1.wkid, &xx, &c_b33, &c_b33, &dy);
    rswkv_(&globnu_1.wkid, &c_b33, &dx, &yy, &c_b33);
    rswkv_(&globnu_1.wkid, &c_b33, &xx, &yy, &yy);
    nqwkt (&globnu_1.wkid, &errind, &idum1, rdumd, rdume, wkvp4, rdumf);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = streq_("OO**", 4L) && appeq_(wkvp4, &c_b33, &c_b42, &c_b56) && 
	    appeq_(&wkvp4[1], &xx, &c_b42, &c_b56) && appeq_(&wkvp4[2], &
	    c_b33, &c_b42, &c_b56) && appeq_(&wkvp4[3], &yy, &c_b42, &c_b56);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04152_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04153                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04153_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04153_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int etr_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr_();
#endif /* NO_PROTO */
    static integer pcl1, pcl2, pcl3;
#ifndef NO_PROTO
    extern /* Subroutine */ int etr3_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr3_();
#endif /* NO_PROTO */
    static integer isiz;
    static real vwcp[6];
    static integer idum1;
    static real vwcp0[6], vwcp1[6], vwcp4[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical rareq_();
#endif /* NO_PROTO */
    static real mapmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
#endif /* NO_PROTO */
    static real vwcp40[6];
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static real rotmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *), nsvwr (integer *, integer *, real *, real *, real *,
	     integer *), rsvwr_(integer *, integer *, real *, real *, real *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwr (), nsvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real mapmt3[16]	/* was [4][4] */, rotmt3[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr3 (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), rsvwr3_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    ), chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr3 (), rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
    static real qmapmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static real qrotmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setrvs_();
#endif /* NO_PROTO */

/*    E04153 tests the handling of error 153. */
/*  clipping indicator */

#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified view clipping limits are invalid:"
	    " XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 200L, 84L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified view clipping limits are invalid:\
 XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 200L, 84L);
#endif /* NO_PROTO */
    setvs_("153", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  try 3D cases first */
    etr3_(&c_b51, &c_b31, &c_b115, rotmt3);
    etr3_(&c_b45, &c_b50, &c_b44, mapmt3);
    setrvs_(".1,.9,.1,.9,.1,.9", vwcp0, &isiz, 17L);
    nsvwr3 (&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp0, &c__1, &c__1, &c__1)
	    ;
    etr3_(&c_b124, &c_b32, &c_b126, rotmt3);
    etr3_(&c_b32, &c_b126, &c_b51, mapmt3);
    setrvs_(".6,.3,0.,1.,0.,1.", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    setrvs_("0.,1.,.6,.6,0.,1.", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    setrvs_("0.,1.,0.,1.,.6,.3", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    setrvs_("0.,1.,.6,.3,0.,0.", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    etr3_(&c_b51, &c_b31, &c_b115, rotmt3);
    etr3_(&c_b45, &c_b50, &c_b44, mapmt3);
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, qrotmt, qmapmt, 
	    vwcp1, &pcl1, &pcl2, &pcl3);
    chkinq_("pqvwr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, qrotmt, rotmt3, &c_b42, &
	    c_b42) && rareq_(&c__16, qmapmt, mapmt3, &c_b42, &c_b42) && 
	    rareq_(&c__6, vwcp1, vwcp0, &c_b42, &c_b42) && pcl1 == 1 && pcl2 
	    == 1 && pcl3 == 1;
    tstign_(&L__1);
/*  now test 2D cases */
    etr_(&c_b44, &c_b124, rotmt);
    etr_(&c_b32, &c_b126, mapmt);
    setrvs_(".1,.9,.1,.9,.0,1.0", vwcp40, &isiz, 18L);
    nsvwr (&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp40, &c__1);
    etr_(&c_b51, &c_b31, rotmt);
    etr_(&c_b115, &c_b45, mapmt);
    setrvs_(".6,.3,0.,1.", vwcp4, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    setrvs_("0.,1.,.6,.3", vwcp4, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    setrvs_(".44,.44, .5,.6", vwcp4, &isiz, 14L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    etr3_(&c_b44, &c_b124, &c_b33, rotmt3);
    etr3_(&c_b32, &c_b126, &c_b33, mapmt3);
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, qrotmt, qmapmt, 
	    vwcp1, &pcl1, &pcl2, &pcl3);
    chkinq_("pqvwr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, qrotmt, rotmt3, &c_b42, &
	    c_b42) && rareq_(&c__16, qmapmt, mapmt3, &c_b42, &c_b42) && 
	    rareq_(&c__6, vwcp1, vwcp40, &c_b42, &c_b42) && pcl1 == 1 && pcl2 
	    == 1 && pcl3 == 1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04153_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04154                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04154_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04154_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int etr_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr_();
#endif /* NO_PROTO */
    static integer pcl1, pcl2, pcl3;
#ifndef NO_PROTO
    extern /* Subroutine */ int etr3_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr3_();
#endif /* NO_PROTO */
    static integer isiz;
    static real vwcp[6];
    static integer idum1;
    static real vwcp0[6], vwcp1[6], vwcp4[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical rareq_();
#endif /* NO_PROTO */
    static real mapmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
#endif /* NO_PROTO */
    static real vwcp40[6];
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static real rotmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *), nsvwr (integer *, integer *, real *, real *, real *,
	     integer *), rsvwr_(integer *, integer *, real *, real *, real *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwr (), nsvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real mapmt3[16]	/* was [4][4] */, rotmt3[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr3 (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), rsvwr3_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    ), chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr3 (), rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
    static real qmapmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static real qrotmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setrvs_();
#endif /* NO_PROTO */

/*   E04154 tests the handling of error 154. */
/*  clipping indicator */
/*  current/requested values */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified view clipping limits are not with"
	    "in NPC range", 200L, 59L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified view clipping limits are not with\
in NPC range", 200L, 59L);
#endif /* NO_PROTO */
    setvs_("154", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  try 3D cases first */
    etr3_(&c_b51, &c_b31, &c_b115, rotmt3);
    etr3_(&c_b45, &c_b50, &c_b44, mapmt3);
    setrvs_(".1,.9,.1,.9,.1,.9", vwcp0, &isiz, 17L);
    nsvwr3 (&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp0, &c__0, &c__0, &c__0)
	    ;
    etr3_(&c_b124, &c_b32, &c_b126, rotmt3);
    etr3_(&c_b32, &c_b126, &c_b51, mapmt3);
    setrvs_("-.1,1.,0.,1.,0.,1.", vwcp, &isiz, 18L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__1, &c__1, &c__1);

    setrvs_("0.,1.,0.,1.1,0.,1.", vwcp, &isiz, 18L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__1, &c__1, &c__1);

    setrvs_("0.,1.,0.,1.,-0.1,1.1", vwcp, &isiz, 20L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__1, &c__1, &c__1);

    etr3_(&c_b51, &c_b31, &c_b115, rotmt3);
    etr3_(&c_b45, &c_b50, &c_b44, mapmt3);
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, qrotmt, qmapmt, 
	    vwcp1, &pcl1, &pcl2, &pcl3);
    chkinq_("pqvwr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, qrotmt, rotmt3, &c_b42, &
	    c_b42) && rareq_(&c__16, qmapmt, mapmt3, &c_b42, &c_b42) && 
	    rareq_(&c__6, vwcp1, vwcp0, &c_b42, &c_b42) && pcl1 == 0 && pcl2 
	    == 0 && pcl3 == 0;
    tstign_(&L__1);
/*  now test 2D cases */
    etr_(&c_b44, &c_b124, rotmt);
    etr_(&c_b32, &c_b126, mapmt);
    setrvs_(".1,.9,.1,.9,.0,1.0", vwcp40, &isiz, 18L);
    nsvwr (&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp40, &c__1);
    etr_(&c_b51, &c_b31, rotmt);
    etr_(&c_b115, &c_b45, mapmt);
    setrvs_("-0.1,1.,0.,1.", vwcp4, &isiz, 13L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    setrvs_("0.1,1.,0.,1.1", vwcp4, &isiz, 13L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    setrvs_("-.1,1.,0.,1.1", vwcp4, &isiz, 13L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    etr3_(&c_b44, &c_b124, &c_b33, rotmt3);
    etr3_(&c_b32, &c_b126, &c_b33, mapmt3);
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, qrotmt, qmapmt, 
	    vwcp1, &pcl1, &pcl2, &pcl3);
    chkinq_("pqvwr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, qrotmt, rotmt3, &c_b42, &
	    c_b42) && rareq_(&c__16, qmapmt, mapmt3, &c_b42, &c_b42) && 
	    rareq_(&c__6, vwcp1, vwcp40, &c_b42, &c_b42) && pcl1 == 1 && pcl2 
	    == 1 && pcl3 == 1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04154_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04156                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04156_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04156_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer isiz;
    static real wkwn[6];
    static integer idum1;
    static real wkwn0[6], wkwn1[6], wkwn4[4];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real rduma[6], rdumb[6], rdumc[6], rdumd[4], rdume[4], rdumf[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqwkt (integer *, 
	    integer *, integer *, real *, real *, real *, real *), nswkw (
	    integer *, real *, real *, real *, real *), rswkw_(integer *, 
	    real *, real *, real *, real *), nqwkt3 (integer *, integer *, 
	    integer *, real *, real *, real *, real *), nswkw3 (integer *, 
	    real *), rswkw3_(integer *, real *), chkinq_(char *, integer *, 
	    ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern logical rareq_();
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqwkt (), nswkw (), 
	    rswkw_(), nqwkt3 (), nswkw3 (), rswkw3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*   E04156 tests the handling of error 156. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation window limits are not"
	    " within NPC range", 200L, 64L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation window limits are not\
 within NPC range", 200L, 64L);
#endif /* NO_PROTO */
    setvs_("156", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  3D */
    setrvs_(".1,.9,.1,.9,.1,.9", wkwn0, &isiz, 17L);
    nswkw3 (&globnu_1.wkid, wkwn0);
    setrvs_("-.1,1.,0.,1.,0.,1.", wkwn, &isiz, 18L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,0.,1.1,0.,1.", wkwn, &isiz, 18L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,0.,1.,-0.1,1.1", wkwn, &isiz, 20L);
    rswkw3_(&globnu_1.wkid, wkwn);
    nqwkt3 (&globnu_1.wkid, &errind, &idum1, wkwn1, rduma, rdumb, rdumc);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__6, wkwn0, wkwn1, &c_b42, &c_b42);
    tstign_(&L__1);
/*  2D */
    nswkw (&globnu_1.wkid, &c_b44, &c_b50, &c_b44, &c_b50);
    rswkw_(&globnu_1.wkid, &c_b319, &c_b34, &c_b33, &c_b34);
    rswkw_(&globnu_1.wkid, &c_b44, &c_b34, &c_b33, &c_b326);
    rswkw_(&globnu_1.wkid, &c_b319, &c_b34, &c_b33, &c_b326);
    nqwkt (&globnu_1.wkid, &errind, &idum1, wkwn4, rdumd, rdume, rdumf);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = streq_("OO**", 4L) && appeq_(wkwn4, &c_b44, &c_b42, &c_b42) && 
	    appeq_(&wkwn4[1], &c_b50, &c_b42, &c_b42) && appeq_(&wkwn4[2], &
	    c_b44, &c_b42, &c_b42) && appeq_(&wkwn4[3], &c_b50, &c_b42, &
	    c_b42);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04156_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/e04157                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e04157_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04157_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real xx, yy, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ds3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ds3_();
#endif /* NO_PROTO */
    static real dx2, dx3, dy3, dz3, dy2, wkvp[6];
    static integer idum1, idum2, idum3, idum4;
    static real wkvp0[6], wkvp1[6], wkvp4[4];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real rduma[6], rdumb[6], rdumc[6], rdumd[4], rdume[4], rdumf[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nqdsp (integer *, integer *, integer *, 
	    real *, real *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqwkt (integer *, 
	    integer *, integer *, real *, real *, real *, real *), nswkv (
	    integer *, real *, real *, real *, real *), rswkv_(integer *, 
	    real *, real *, real *, real *), nqdsp3 (integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    ), nqwkt3 (integer *, integer *, integer *, real *, real *, real *
	    , real *), nswkv3 (integer *, real *), rswkv3_(integer *, real *),
	     chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern logical rareq_();
    extern /* Subroutine */ int nclwk (), nqwkc (), nqdsp ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqwkt (), nswkv (), 
	    rswkv_(), nqdsp3 (), nqwkt3 (), nswkv3 (), rswkv3_(), chkinq_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */

/*   E04157 tests the handling of error 157. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation viewport is not withi"
	    "n display space", 200L, 62L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation viewport is not withi\
n display space", 200L, 62L);
#endif /* NO_PROTO */
    setvs_("157", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqdsp3 (&specwt, &errind, &idum1, &dx3, &dy3, &dz3, &idum2, &idum3, &
	    idum4);
    chkinq_("pqdsp3", &errind, 6L);
    nqdsp (&specwt, &errind, &idum1, &dx2, &dy2, &idum2, &idum3);
    chkinq_("pqdsp", &errind, 5L);
#ifndef NO_PROTO
    xx = dx3 / 2.f;
    yy = dy3 / 2.f;
    zz = dz3 / 2.f;
#else /* NO_PROTO */
    xx = dx3 / (float)2.;
    yy = dy3 / (float)2.;
    zz = dz3 / (float)2.;
#endif /* NO_PROTO */
/* 3D */
    ds3_(&c_b33, &xx, &c_b33, &yy, &c_b33, &zz, wkvp0);
    nswkv3 (&globnu_1.wkid, wkvp0);
    ds3_(&c_b319, &dx3, &c_b33, &dy3, &c_b33, &dz3, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
#ifndef NO_PROTO
    r__1 = dy3 + .1f;
#else /* NO_PROTO */
    r__1 = dy3 + (float).1;
#endif /* NO_PROTO */
    ds3_(&c_b33, &dx3, &c_b33, &r__1, &c_b33, &dz3, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
#ifndef NO_PROTO
    r__1 = dz3 + .1f;
#else /* NO_PROTO */
    r__1 = dz3 + (float).1;
#endif /* NO_PROTO */
    ds3_(&c_b33, &dx3, &c_b33, &dy3, &c_b319, &r__1, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
    nqwkt3 (&globnu_1.wkid, &errind, &idum1, rduma, rdumb, wkvp1, rdumc);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__6, wkvp1, wkvp0, &c_b42, &c_b42);
    tstign_(&L__1);
/* 2D */
#ifndef NO_PROTO
    xx = dx2 / 2.f;
    yy = dy2 / 2.f;
#else /* NO_PROTO */
    xx = dx2 / (float)2.;
    yy = dy2 / (float)2.;
#endif /* NO_PROTO */
    nswkv (&globnu_1.wkid, &c_b33, &xx, &c_b33, &yy);
    rswkv_(&globnu_1.wkid, &c_b319, &dx2, &c_b33, &dy2);
#ifndef NO_PROTO
    r__1 = dy2 + .1f;
#else /* NO_PROTO */
    r__1 = dy2 + (float).1;
#endif /* NO_PROTO */
    rswkv_(&globnu_1.wkid, &c_b33, &dx2, &c_b33, &r__1);
#ifndef NO_PROTO
    r__1 = dy2 + .1f;
#else /* NO_PROTO */
    r__1 = dy2 + (float).1;
#endif /* NO_PROTO */
    rswkv_(&globnu_1.wkid, &c_b319, &dx2, &c_b33, &r__1);
    nqwkt (&globnu_1.wkid, &errind, &idum1, rdumd, rdume, wkvp4, rdumf);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = streq_("OO**", 4L) && appeq_(wkvp4, &c_b33, &c_b42, &c_b42) && 
	    appeq_(&wkvp4[1], &xx, &c_b42, &c_b42) && appeq_(&wkvp4[2], &
	    c_b33, &c_b42, &c_b42) && appeq_(&wkvp4[3], &yy, &c_b42, &c_b42);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04157_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.04/ds3                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ds3_(real *r1, real *r2, real *r3, real *r4, real *r5, 
	real *r6, real *array)
#else /* NO_PROTO */
/* Subroutine */ int ds3_(r1, r2, r3, r4, r5, r6, array)
real *r1, *r2, *r3, *r4, *r5, *r6, *array;
#endif /* NO_PROTO */
{
/*  Set an array with six real numbers */
    /* Parameter adjustments */
    --array;

    /* Function Body */
    array[1] = *r1;
    array[2] = *r2;
    array[3] = *r3;
    array[4] = *r4;
    array[5] = *r5;
    array[6] = *r6;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ds3_ */

