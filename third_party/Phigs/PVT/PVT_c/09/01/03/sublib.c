/* fort//09/01/03/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b15 = 1.f;
#else /* NO_PROTO */
static real c_b15 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b106 = .9f;
static real c_b109 = .5f;
static real c_b116 = .01f;
#else /* NO_PROTO */
static real c_b106 = (float).9;
static real c_b109 = (float).5;
static real c_b116 = (float).01;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__801 = 801;
#ifndef NO_PROTO
static real c_b342 = .1f;
static real c_b343 = .2f;
static real c_b344 = .3f;
static real c_b345 = .4f;
static real c_b347 = .6f;
#else /* NO_PROTO */
static real c_b342 = (float).1;
static real c_b343 = (float).2;
static real c_b344 = (float).3;
static real c_b345 = (float).4;
static real c_b347 = (float).6;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b360 = .001f;
#else /* NO_PROTO */
static real c_b360 = (float).001;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__100 = 100;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03100                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03100_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03100_(useprm)
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
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_();
#endif /* NO_PROTO */
    static integer idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedi_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedi_();
#endif /* NO_PROTO */
    static integer index;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedr_(integer *, integer *, integer *, 
	    integer *, real *, integer *), nclwk (integer *), nclst (void), 
	    rspli_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    rspmr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    rstxi_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedr_(), nclwk (), nclst (), rspli_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), rspmr_(), setvs_(), nopst (), 
	    rstxi_();
#endif /* NO_PROTO */
    static integer nentr1, nentr2;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqepmi (integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqepmi ();
#endif /* NO_PROTO */

/*  E03100 tests the handling of error number 100 */
/*  type of returned value */
    s_copy(errchr_1.curcon, "the bundle index value is less than one", 200L, 
	    39L);
    setvs_("100", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    esetup_(useprm);
    nopst (&c__101);
    rspli_(&c__0);
    L__1 = streq_("O*O*", 4L);
    tstign_(&L__1);
    rstxi_(&c_n1);
    index = rndint_(&c_n1, &c__0);
    rsedi_(&index);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqepmi (&globnu_1.wkid, &c__0, &errind, &nentr1, &idum1);
    chkinq_("pqepmi", &errind, 6L);
    rspmr_(&globnu_1.wkid, &c__0, &c__1, &c_b15, &c__0);
    nqepmi (&globnu_1.wkid, &c__0, &errind, &nentr2, &idum1);
    chkinq_("pqepmi", &errind, 6L);
    L__1 = streq_("OO**", 4L) && nentr1 == nentr2;
    tstign_(&L__1);
    rsir_(&globnu_1.wkid, &c_n1, &c__1, &c__1, &c__0);
    index = rndint_(&c_n1, &c__0);
    rsedr_(&globnu_1.wkid, &index, &c__1, &c__1, &c_b15, &c__0);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03100_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03101                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03101_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03101_(useprm)
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
    static integer v1, v2, v11, ix, vdx1[300], vdx2[300], isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nsvwr (integer *, 
	    integer *, real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nsvwr ();
#endif /* NO_PROTO */
    static integer vwsiz;
#ifndef NO_PROTO
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical iareql_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static real mapmat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer errind;
    static real rotmat[9]	/* was [3][3] */, cplimt[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), nqevwi (integer *, 
	    integer *, integer *, integer *, integer *), srtiar_(integer *, 
	    integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), nqevwi (), srtiar_(), tstign_();
#endif /* NO_PROTO */
    static integer numvdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int setrvs_(char *, real *, integer *, ftnlen), 
	    rsvtip_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setrvs_(), rsvtip_();
#endif /* NO_PROTO */

/*  E03101 tests the handling of error number 101 */
/*  clipping indicator */
/*  relative input priority */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified representation has not been defin"
	    "ed", 200L, 49L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified representation has not been defin\
ed", 200L, 49L);
#endif /* NO_PROTO */
    setvs_("101", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &numvdx, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    if (numvdx == 0) {
	idmat_(&c__3, rotmat);
	idmat_(&c__3, mapmat);
	setrvs_("0.,1.,0.,1.", cplimt, &isiz, 11L);
	nsvwr (&globnu_1.wkid, &c__1, rotmat, mapmat, cplimt, &c__1);
	v1 = 2;
	v11 = 3;
	v2 = 1;
    } else {
	i__1 = numvdx;
	for (ix = 1; ix <= i__1; ++ix) {
	    nqevwi (&globnu_1.wkid, &ix, &errind, &idum1, &vdx1[ix - 1]);
	    chkinq_("pqevwi", &errind, 6L);
/* L50: */
	}
	srtiar_(&numvdx, vdx1);
	v1 = vdx1[numvdx - 1] + 1;
	v11 = v1 + 10;
	v2 = vdx1[0];
    }
/*  V1 and V11 are undefined; V2 is defined */
    rsvtip_(&globnu_1.wkid, &v1, &v11, &c__1);
    rsvtip_(&globnu_1.wkid, &v1, &v2, &c__0);
    rsvtip_(&globnu_1.wkid, &v2, &v1, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &vwsiz, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    i__1 = vwsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	nqevwi (&globnu_1.wkid, &ix, &errind, &idum1, &vdx2[ix - 1]);
	chkinq_("pqevwi", &errind, 6L);
/* L60: */
    }
    L__1 = streq_("OO**", 4L) && iareql_(&numvdx, vdx1, &vwsiz, vdx2);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03101_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03103                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03103_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03103_(useprm)
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
    static integer ix;
    static real spec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    , rscr_(integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr (), rscr_();
#endif /* NO_PROTO */
    static integer isiz, idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *), rsedr_(integer *, integer *, 
	    integer *, integer *, real *, integer *), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *), opmsg_(char *,
	     ftnlen);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nsplr (integer *, integer *, integer *, real *, integer *), 
	    rsplr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nstxr (integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    rstxr_(integer *, integer *, integer *, integer *, real *, real *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), nsedr (), rsedr_(), nclwk (), 
	    nqwkc (), opmsg_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), nsplr (), rsplr_(), setvs_(), 
	    nstxr (), rstxr_();
#endif /* NO_PROTO */
    static integer mxedg1, mxcol1, mxply1, mxtxt1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, tabsiz, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), nqepli (integer *, 
	    integer *, integer *, integer *, integer *), tstign_(logical *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), nqepli (), tstign_(), nqwksl (), 
	    setrvs_();
#endif /* NO_PROTO */

/*  E03103 tests the handling of error number 103 */
/*   edge flag */
/*   test precision */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "setting this bundle table entry would exceed th"
	    "e maximum number of entries allowed in the workstation bundle ta"
	    "ble", 200L, 114L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "setting this bundle table entry would exceed th\
e maximum number of entries allowed in the workstation bundle table", 200L, 
	    114L);
#endif /* NO_PROTO */
    setvs_("103", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &mxply1, &idum1, &mxtxt1, &idum2, &mxedg1, &
	    idum3, &mxcol1, &idum4);
    chkinq_("pqwksl", &errind, 6L);
    if (mxply1 >= 1000) {
	opmsg_("Initializing large polyline bundle table.", 41L);
    }
    i__1 = mxply1;
    for (ix = 1; ix <= i__1; ++ix) {
	nsplr (&globnu_1.wkid, &ix, &c__1, &c_b15, &c__0);
/* L50: */
    }
    i__1 = mxply1 + 1;
    rsplr_(&globnu_1.wkid, &i__1, &c__1, &c_b15, &c__0);
    nqepli (&globnu_1.wkid, &c__0, &errind, &tabsiz, &idum1);
    chkinq_("pqepli", &errind, 6L);
    L__1 = streq_("OO**", 4L) && tabsiz == mxply1;
    tstign_(&L__1);
    if (mxtxt1 >= 1000) {
	opmsg_("Initializing large text bundle table.", 37L);
    }
    i__1 = mxtxt1;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxr (&globnu_1.wkid, &ix, &c__1, &c__0, &c_b15, &c_b15, &c__0);
/* L100: */
    }
    i__1 = mxtxt1 + 1;
    rstxr_(&globnu_1.wkid, &i__1, &c__1, &c__0, &c_b15, &c_b15, &c__0);
    if (mxedg1 >= 1000) {
	opmsg_("Initializing large edge bundle table.", 37L);
    }
    i__1 = mxedg1;
    for (ix = 1; ix <= i__1; ++ix) {
	nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b15, &c__0);
/* L150: */
    }
    i__1 = mxedg1 + 1;
    rsedr_(&globnu_1.wkid, &i__1, &c__1, &c__1, &c_b15, &c__0);
    if (mxcol1 > 1000) {
	opmsg_("Initializing large colour table.", 32L);
    }
    setrvs_("0.5,0.5,0.5", spec, &isiz, 11L);
    i__1 = mxcol1;
    for (ix = 1; ix <= i__1; ++ix) {
	nscr (&globnu_1.wkid, &ix, &isiz, spec);
/* L200: */
    }
    i__1 = mxcol1 + 1;
    rscr_(&globnu_1.wkid, &i__1, &isiz, spec);
    nqeci (&globnu_1.wkid, &c__0, &errind, &tabsiz, &idum1);
    chkinq_("pqeci", &errind, 5L);
    L__1 = streq_("OO**", 4L) && tabsiz == mxcol1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03103_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03104                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03104_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03104_(useprm)
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
    static integer ix, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqplf (integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nqplr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nsplr (integer *, integer *, integer *, 
	    real *, integer *), rsplr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nclwk (), nqplf (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nqplr (), nopwk (), nsplr (), rsplr_(), 
	    setvs_();
#endif /* NO_PROTO */
    static integer nltyp1, linecl;
    static real linesc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, linety, thislt, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype, mxtype;

/*   E03104 tests the handling of error number 104 */
/*  type of retured value */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified linetype is not available on the "
	    "specified workstation", 200L, 68L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified linetype is not available on the \
specified workstation", 200L, 68L);
#endif /* NO_PROTO */
    setvs_("104", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqplf (&specwt, &c__1, &errind, &nltyp1, &mxtype, &idum2, &rdum1, &rdum2, 
	    &rdum3, &idum3);
    chkinq_("pqplf", &errind, 5L);
    i__1 = abs(nltyp1);
    for (ix = 1; ix <= i__1; ++ix) {
	nqplf (&specwt, &ix, &errind, &idum1, &thislt, &idum2, &rdum1, &rdum2,
		 &rdum3, &idum3);
	chkinq_("pqplf", &errind, 5L);
	if (thislt > mxtype) {
	    mxtype = thislt;
	}
/* L50: */
    }
    untype = mxtype + 1;

    nsplr (&globnu_1.wkid, &c__1, &thislt, &c_b106, &c__0);
    rsplr_(&globnu_1.wkid, &c__1, &untype, &c_b109, &c__1);
    nqplr (&globnu_1.wkid, &c__1, &c__0, &errind, &linety, &linesc, &linecl);
    chkinq_("pqplr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && linety == thislt && appeq_(&linesc, &c_b106, 
	    &c_b116, &c_b116) && linecl == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03104_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03105                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03105_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03105_(useprm)
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
    static integer ix, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqpmf (integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *), rspmr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nclwk (), nqpmf (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr (), rspmr_(), 
	    setvs_();
#endif /* NO_PROTO */
    static integer nmtyp1, markcl;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static real marksc;
    static integer errind, markty, thismt, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype, mxtype;

/*  E03105 tests the handling of error number 105 */
/*  type of returned value */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified marker type is not available on t"
	    "he specified workstation", 200L, 71L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified marker type is not available on t\
he specified workstation", 200L, 71L);
#endif /* NO_PROTO */
    setvs_("105", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqpmf (&specwt, &c__1, &errind, &nmtyp1, &mxtype, &idum2, &rdum1, &rdum2, 
	    &rdum3, &idum3);
    chkinq_("pqpmf", &errind, 5L);
    i__1 = abs(nmtyp1);
    for (ix = 1; ix <= i__1; ++ix) {
	nqpmf (&specwt, &ix, &errind, &idum1, &thismt, &idum2, &rdum1, &rdum2,
		 &rdum3, &idum3);
	chkinq_("pqpmf", &errind, 5L);
	if (thismt > mxtype) {
	    mxtype = thismt;
	}
/* L50: */
    }
    untype = mxtype + 1;

    nspmr (&globnu_1.wkid, &c__1, &thismt, &c_b15, &c__0);
    rspmr_(&globnu_1.wkid, &c__1, &untype, &c_b109, &c__1);
    nqpmr (&globnu_1.wkid, &c__1, &c__0, &errind, &markty, &marksc, &markcl);
    chkinq_("pqpmr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && markty == thismt && appeq_(&marksc, &c_b15, &
	    c_b116, &c_b116) && markcl == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03105_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03106                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03106_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03106_(useprm)
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
    static integer ii, ip, ir, ix, prec1, idum1, idum2, idum3, idum4, idum5, 
	    font1;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static integer npair;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nqtxf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, real *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), nqtxf (), setvs_();
#endif /* NO_PROTO */
    static real space1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *), rstxr_(integer *, integer *, integer *, integer *, 
	    real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxr (), nstxr (), rstxr_();
#endif /* NO_PROTO */
    static real expan1;
    static integer color1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, fontip[100], unprec, specwt, unfont;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), srtiar_(integer *, 
	    integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), srtiar_(), tstign_();
#endif /* NO_PROTO */
    static integer txtprc[100], txtfnt[100];

/*   E03106 tests the handling of error number 106 */
/*  type of returned value */
/*  text precision */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified font is not available for the req"
	    "uested text precision on the specified workstation", 200L, 97L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified font is not available for the req\
uested text precision on the specified workstation", 200L, 97L);
#endif /* NO_PROTO */
    setvs_("106", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqtxf (&specwt, &c__0, &errind, &npair, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    i__1 = npair;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&specwt, &ix, &errind, &idum1, &txtfnt[ix - 1], &txtprc[ix - 1]
		, &idum2, &rdum1, &rdum2, &idum3, &rdum3, &rdum4, &idum4);
	chkinq_("pqtxf", &errind, 5L);
/* L50: */
    }
    nstxr (&globnu_1.wkid, &c__1, txtfnt, txtprc, &c_b15, &c_b15, &c__0);
    for (ip = 2; ip >= 0; --ip) {
	ii = 0;
	i__1 = npair;
	for (ir = 1; ir <= i__1; ++ir) {
	    if (txtprc[ir - 1] == ip) {
		++ii;
		fontip[ii - 1] = txtfnt[ir - 1];
	    }
/* L160: */
	}
	if (ii == 0) {
	    goto L150;
	}
	srtiar_(&ii, fontip);
	unfont = fontip[ii - 1] + 1;
	unprec = ip;
	goto L200;
L150:
	;
    }
L200:
    rstxr_(&globnu_1.wkid, &c__1, &unfont, &unprec, &c_b109, &c_b109, &c__0);
    nqtxr (&globnu_1.wkid, &c__1, &c__0, &errind, &font1, &prec1, &expan1, &
	    space1, &color1);
    chkinq_("pqtxr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && font1 == txtfnt[0] && prec1 == txtprc[0] && 
	    appeq_(&expan1, &c_b15, &c_b116, &c_b116) && appeq_(&space1, &
	    c_b15, &c_b116, &c_b116) && color1 == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03106_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03107                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03107_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03107_(useprm)
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
    static integer ix, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    rsedr_(integer *, integer *, integer *, integer *, real *, 
	    integer *), nclwk (integer *), nqwkc (integer *, integer *, 
	    integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf ();
    extern logical appeq_();
    extern /* Subroutine */ int nqedr (), nsedr (), rsedr_(), nclwk (), 
	    nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer nedtp1, edgefg, edgecl;
    static real edgesc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer thised, edgety, errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype, mxtype;

/*  E03107 tests the handling of error 107 */
/*  type of returned value */
/*   off/on switch for edge flag and error handling */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified edgetype is not available on the "
	    "specified workstation", 200L, 68L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified edgetype is not available on the \
specified workstation", 200L, 68L);
#endif /* NO_PROTO */
    setvs_("107", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqedf (&specwt, &c__1, &errind, &nedtp1, &mxtype, &idum2, &rdum1, &rdum2, 
	    &rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    i__1 = abs(nedtp1);
    for (ix = 1; ix <= i__1; ++ix) {
	nqedf (&specwt, &ix, &errind, &idum1, &thised, &idum2, &rdum1, &rdum2,
		 &rdum3, &idum3);
	chkinq_("pqedf", &errind, 5L);
	if (thised > mxtype) {
	    mxtype = thised;
	}
/* L50: */
    }
    untype = mxtype + 1;
    nsedr (&globnu_1.wkid, &c__1, &c__0, &thised, &c_b15, &c__0);
    rsedr_(&globnu_1.wkid, &c__1, &c__1, &untype, &c_b109, &c__1);
    nqedr (&globnu_1.wkid, &c__1, &c__0, &errind, &edgefg, &edgety, &edgesc, &
	    edgecl);
    chkinq_("pqedr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && edgefg == 0 && edgety == thised && appeq_(&
	    edgesc, &c_b15, &c_b116, &c_b116) && edgecl == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03107_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03108                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03108_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03108_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static logical isavl[5] = { FALSE_,FALSE_,FALSE_,FALSE_,FALSE_ };

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
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqir (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nsir (integer *, integer *, integer *, 
	    integer *, integer *), rsir_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqif (), nqir (), nsir (), rsir_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer nisty1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, istyle, isindx, iscolo, thisis, specwt, untype;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E03108 tests the handling of error 108 */
/*  interior style */
/*  type of returned value */
    setvs_("108", errinf_1.experr, &errinf_1.expsiz, 3L);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified interior style is not available o"
	    "n the specified workstation", 200L, 74L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified interior style is not available o\
n the specified workstation", 200L, 74L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "8", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqif (&specwt, &c__0, &c__0, &errind, &nisty1, &idum1, &idum2, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
    i__1 = nisty1;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&specwt, &ix, &c__0, &errind, &idum2, &thisis, &idum3, &idum4, &
		idum5);
	chkinq_("pqif", &errind, 4L);
	if (thisis >= 0 && thisis <= 4) {
	    isavl[thisis] = TRUE_;
	}
/* L50: */
    }
    for (ix = 0; ix <= 4; ++ix) {
	if (! isavl[ix]) {
	    untype = ix;
	    goto L70;
	}
/* L60: */
    }
    inmsg_("No unavailable interior styles; test is skipped.", 48L);
    return 0;
L70:
    nsir (&globnu_1.wkid, &c__1, &thisis, &c__1, &c__0);
    rsir_(&globnu_1.wkid, &c__1, &untype, &c__2, &c__1);
    nqir (&globnu_1.wkid, &c__1, &c__0, &errind, &istyle, &isindx, &iscolo);
    chkinq_("pqir", &errind, 4L);
    L__1 = streq_("OO**", 4L) && istyle == thisis && isindx == 1 && iscolo == 
	    0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03108_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03110                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03110_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03110_(useprm)
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
    static integer ix, idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmd (integer *, integer *, integer *), 
	    nscmd (integer *, integer *), rscmd_(integer *, integer *), 
	    nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmd (), nscmd (), rscmd_(), nclwk ();
#endif /* NO_PROTO */
    static integer mxmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer cmodel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf ();
#endif /* NO_PROTO */
    static integer ncolmd;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, thismd, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype;

/*  E03110 tests the handling of error 110 */
/*  colour model */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified colour model is not available on "
	    "the workstation", 200L, 62L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified colour model is not available on \
the workstation", 200L, 62L);
#endif /* NO_PROTO */
    setvs_("110", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "9", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqcmdf (&specwt, &c__1, &errind, &ncolmd, &mxmod, &idum2);
    chkinq_("pqcmdf", &errind, 6L);
    i__1 = ncolmd;
    for (ix = 1; ix <= i__1; ++ix) {
	nqcmdf (&specwt, &ix, &errind, &idum1, &thismd, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
	if (thismd > mxmod) {
	    mxmod = thismd;
	}
/* L50: */
    }
    untype = mxmod + 1;
    nscmd (&globnu_1.wkid, &thismd);
    rscmd_(&globnu_1.wkid, &untype);
    nqcmd (&globnu_1.wkid, &errind, &cmodel);
    chkinq_("pqcmd", &errind, 5L);
    L__1 = streq_("OO**", 4L) && cmodel == thismd;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03110_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03111                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03111_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03111_(useprm)
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
    static integer ix, mxh, idum1, idum2, thish;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nqhrm (integer *, integer *, integer *, 
	    integer *, integer *), nshrm (integer *, integer *), rshrm_(
	    integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nqwkc (), nqhrm (), nshrm (), 
	    rshrm_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer chhmod, nhlhmd;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqhrmf (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqhrmf ();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype;

/*  E03111 tests the handling of error 111 */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified hlhsr mode is not available on th"
	    "e specified workstation", 200L, 70L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified hlhsr mode is not available on th\
e specified workstation", 200L, 70L);
#endif /* NO_PROTO */
    setvs_("111", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "10", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqhrmf (&specwt, &c__1, &errind, &nhlhmd, &mxh);
    chkinq_("pqhrmf", &errind, 6L);
    i__1 = nhlhmd;
    for (ix = 1; ix <= i__1; ++ix) {
	nqhrmf (&specwt, &ix, &errind, &idum1, &thish);
	chkinq_("pqhrmf", &errind, 6L);
	if (thish > mxh) {
	    mxh = thish;
	}
/* L50: */
    }
    untype = mxh + 1;
    nshrm (&globnu_1.wkid, &thish);
    rshrm_(&globnu_1.wkid, &untype);
    nqhrm (&globnu_1.wkid, &errind, &idum1, &chhmod, &idum2);
    chkinq_("pqhrm", &errind, 5L);
    L__1 = streq_("OO**", 4L) && chhmod == thish;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03111_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03112                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03112_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03112_(useprm)
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
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *), inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *), rspar_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_(), inmsg_(), nclwk (), nqwkc (), rspar_(
	    );
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer ptrary[1]	/* was [1][1] */;
#ifndef NO_PROTO
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical intsty_();
#endif /* NO_PROTO */

/*  E03112 tests the handling of error 112. */
/*  interior style */
    s_copy(errchr_1.curcon, "the pattern index value is less than one", 200L, 
	    40L);
    setvs_("112", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "11", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (! intsty_(&specwt, &c__2)) {
#ifndef NO_PROTO
	inmsg_("Pattern style not supported by this workstation; test skippe"
		"d.", 62L);
#else /* NO_PROTO */
	inmsg_("Pattern style not supported by this workstation; test skippe\
d.", 62L);
#endif /* NO_PROTO */
	goto L666;
    }
    rsir_(&globnu_1.wkid, &c__1, &c__2, &c_n1, &c__0);
    L__1 = streq_("OO**", 4L);
    tstign_(&L__1);
    ptrary[0] = 0;
    rspar_(&globnu_1.wkid, &c__0, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, 
	    ptrary);
L666:
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03112_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03113                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03113_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03113_(useprm)
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
    static integer col[1]	/* was [1][1] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), rscr_(integer *, integer *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), rscr_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_();
#endif /* NO_PROTO */
    static integer idum1, sizb4;
    static real cspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *);
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nclst (void), nqwkc (
	    integer *, integer *, integer *, integer *), rspar_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *), rspmr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci ();
    extern logical appeq_();
    extern /* Subroutine */ int nclwk (), nclst (), nqwkc (), rspar_();
    extern logical streq_();
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr (), rspmr_(), 
	    setvs_(), nopst ();
#endif /* NO_PROTO */
    static real mkscal;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedci_(integer *), chkinq_(char *, integer *,
	     ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedci_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, sizaft, mktype, mkcolo, specwt;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int esetup_(integer *), rsplci_(integer *), 
	    tstign_(logical *), rstxci_(integer *), setrvs_(char *, real *, 
	    integer *, ftnlen);
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical strcon_();
    extern /* Subroutine */ int esetup_(), rsplci_(), tstign_(), rstxci_(), 
	    setrvs_();
    extern logical intsty_();
#endif /* NO_PROTO */

/*  E03113 tests the handling of error 113. */
/*  interior styles */
/*  type of return value */
    s_copy(errchr_1.curcon, "the colour index value is less than zero", 200L, 
	    40L);
    setvs_("113", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "12", 40L, 2L);
    esetup_(useprm);
    nopst (&c__101);
    nlb (&c__801);
    rsplci_(&c_n1);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__101, "67,801", 6L);
    tstign_(&L__1);
    rstxci_(&c_n1);
    rsedci_(&c_n1);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__101, "67,801", 6L);
    tstign_(&L__1);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nspmr (&globnu_1.wkid, &c__2, &c__1, &c_b109, &c__1);
    rspmr_(&globnu_1.wkid, &c__2, &c__2, &c_b15, &c_n1);
    nqpmr (&globnu_1.wkid, &c__2, &c__0, &errind, &mktype, &mkscal, &mkcolo);
    chkinq_("pqpmr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && mktype == 1 && appeq_(&mkscal, &c_b109, &
	    c_b116, &c_b116) && mkcolo == 1;
    tstign_(&L__1);
    rsir_(&globnu_1.wkid, &c__1, &c__0, &c__1, &c_n1);
    col[0] = -1;
    if (intsty_(&specwt, &c__2)) {
	rspar_(&globnu_1.wkid, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, &
		c__1, col);
    }
    nqeci (&globnu_1.wkid, &c__0, &errind, &sizb4, &idum1);
    chkinq_("pqeci", &errind, 5L);
    setrvs_("0.5,0.5,0.5", cspec, &isiz, 11L);
    rscr_(&globnu_1.wkid, &c_n1, &c__3, cspec);
    nqeci (&globnu_1.wkid, &c__0, &errind, &sizaft, &idum1);
    chkinq_("pqeci", &errind, 5L);
    L__1 = streq_("OO**", 4L) && sizb4 == sizaft;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03113_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03114                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03114_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03114_(useprm)
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
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer isiz, idum1, sizb4;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static real limit[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    rsvwi_(integer *), nsvwr (integer *, integer *, real *, real *, 
	    real *, integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nclst ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nopst (), rsvwi_(), 
	    nsvwr (), chkinq_();
#endif /* NO_PROTO */
    static real mapmat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer errind, sizaft;
    static real rotmat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqevwi (integer *, integer *, integer *, integer *, integer *), 
	    setrvs_(char *, real *, integer *, ftnlen), rsvtip_(integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical strcon_();
    extern /* Subroutine */ int esetup_(), tstign_(), nqevwi (), setrvs_(), 
	    rsvtip_();
#endif /* NO_PROTO */

/*   E03114 tests the handling of error 114 */
/*   relative input priority */
/*  clipping indicator */
    s_copy(errchr_1.curcon, "the view index value is less than zero", 200L, 
	    38L);
    setvs_("114", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "13", 40L, 2L);
    esetup_(useprm);
    nopst (&c__101);
    nlb (&c__801);
    rsvwi_(&c_n1);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__101, "67,801", 6L);
    tstign_(&L__1);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    idmat_(&c__3, rotmat);
    idmat_(&c__3, mapmat);
    setrvs_("0.,0.5,0.,0.5", limit, &isiz, 13L);
    nsvwr (&globnu_1.wkid, &c__2, rotmat, mapmat, limit, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &sizb4, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    rsvtip_(&globnu_1.wkid, &c_n1, &c__2, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &sizaft, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    L__1 = streq_("OO**", 4L) && sizb4 == sizaft;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03114_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03115                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03115_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03115_(useprm)
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
    static integer cl1, cl2, cl3;
    static real xf1[16]	/* was [4][4] */, xcl[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int etr3_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr3_();
#endif /* NO_PROTO */
    static integer isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqvwr (integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *, integer *, integer *), rsvwr_(integer *, integer *, 
	    real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
    extern logical rareq_();
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real mapmt3[9]	/* was [3][3] */, mapmt4[16]	/* was [4][4] 
	    */, cplmt3[4], cplmt4[6], rotmt3[9]	/* was [3][3] */, rotmt4[16]	
	    /* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvwr3_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), chkinq_(char *, integer 
	    *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer cpindt, errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*  E03115 tests the handling of error 115. */
/*additional in the FORTRAN binding, to be used with PHIGS inquiry functio
ns*/
/* that return both Current and Requested values. */
/*   clipping indicator */
    s_copy(errchr_1.curcon, "the view index value is less than one", 200L, 
	    37L);
    setvs_("115", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "14", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    idmat_(&c__3, rotmt3);
    idmat_(&c__3, mapmt3);
    setrvs_("0.,1.,0.,1.", cplmt3, &isiz, 11L);
    cpindt = 1;
    rsvwr_(&globnu_1.wkid, &c_n1, rotmt3, mapmt3, cplmt3, &cpindt);
    etr3_(&c_b342, &c_b343, &c_b344, rotmt4);
    etr3_(&c_b345, &c_b109, &c_b347, mapmt4);
    setrvs_("0.1, 0.9, 0.1, 0.9, 0.1, 0.9", cplmt4, &isiz, 28L);
    rsvwr3_(&globnu_1.wkid, &c__0, rotmt4, mapmt4, cplmt4, &c__0, &c__0, &
	    c__0);
    nqvwr (&globnu_1.wkid, &c__0, &c__1, &errind, &idum1, rotmt4, mapmt4, 
	    cplmt4, &cl1, &cl2, &cl3);
    chkinq_("pqvwr", &errind, 5L);
    idmat_(&c__4, xf1);
    setrvs_("0,1,0,1,0,1", xcl, &idum1, 11L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, rotmt4, xf1, &c_b360, &c_b360)
	     && rareq_(&c__16, mapmt4, xf1, &c_b360, &c_b360) && rareq_(&c__6,
	     cplmt4, xcl, &c_b360, &c_b360) && cl1 == 1 && cl2 == 1 && cl3 == 
	    1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03115_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03116                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03116_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03116_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer col[6]	/* was [2][3] */ = { 0,1,1,1,0,1 };
    static integer colia[6]	/* was [2][3] */ = { 1,0,0,0,1,0 };

    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer dx, dy, dx1, dy1, psiz, idum1, idum2, idum3, idum4, idum5, 
	    idum7, idum8;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqpar (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqwkc (integer *, 
	    integer *, integer *, integer *), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rspar_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int inmsg_(), nclwk (), nqpar (), nqwkc (), 
	    nspar (), rspar_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer colia1[6]	/* was [2][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqwksl ();
#endif /* NO_PROTO */

/*   E03116 tests the handling of error 116. */
/*  type of returned value */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one of the dimensions of pattern colour index a"
	    "rray is less than one", 200L, 68L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one of the dimensions of pattern colour index a\
rray is less than one", 200L, 68L);
#endif /* NO_PROTO */
    setvs_("116", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "15", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &psiz, &
	    idum7, &idum8);
    chkinq_("pqwksl", &errind, 6L);
    if (psiz < 1) {
#ifndef NO_PROTO
	inmsg_("Skipping test for invalid pattern because workstation patter"
		"n table size is zero.", 81L);
#else /* NO_PROTO */
	inmsg_("Skipping test for invalid pattern because workstation patter\
n table size is zero.", 81L);
#endif /* NO_PROTO */
	return 0;
    }
    dx = 0;
    dy = 2;
    nspar (&globnu_1.wkid, &c__1, &c__2, &c__3, &c__1, &c__1, &c__2, &c__3, 
	    col);
    rspar_(&globnu_1.wkid, &c__1, &dx, &dy, &c__1, &c__1, &c__2, &c__3, colia)
	    ;
    nqpar (&globnu_1.wkid, &c__1, &c__0, &c__2, &c__3, &errind, &dx1, &dy1, 
	    colia1);
    chkinq_("pqpar", &errind, 5L);
    L__1 = streq_("OO**", 4L) && dx1 == 2 && dy1 == 3 && iareq_(&c__6, colia1,
	     col);
    tstign_(&L__1);
    rspar_(&globnu_1.wkid, &c__1, &c__2, &c__3, &c__1, &c__1, &c__2, &c__0, 
	    colia);
    dx = 2;
    dy = 0;
    rspar_(&globnu_1.wkid, &c__1, &dx, &dy, &c__1, &c__1, &c__2, &c__3, colia)
	    ;
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03116_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03117                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03117_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03117_(useprm)
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
    static integer dx, dy;
    static real px, py, qx, qy;
#ifndef NO_PROTO
    extern /* Subroutine */ int rca_(real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    ), nlb (integer *), rca3_(real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int rca_(), nlb (), rca3_();
#endif /* NO_PROTO */
    static real cpxa[3], cpya[3], cpza[3];
    static integer isiz, colia[6]	/* was [2][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), enderr_(void), esetup_(integer *);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int tstign_(logical *), setrvs_(char *, real *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst (), enderr_(), esetup_();
    extern logical strcon_();
    extern /* Subroutine */ int tstign_(), setrvs_();
#endif /* NO_PROTO */

/*  E03117 tests the handling of Error 117. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one of the dimensions of the colour index array"
	    " is less than one", 200L, 64L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one of the dimensions of the colour index array\
 is less than one", 200L, 64L);
#endif /* NO_PROTO */
    setvs_("117", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "16", 40L, 2L);
    esetup_(useprm);
    nopst (&c__100);
    nlb (&c__801);
    setvs_("1,1,1,0,0,1", colia, &isiz, 11L);
    setrvs_("0.,3.,4.", cpxa, &isiz, 8L);
    setrvs_("0.,1.,0.", cpya, &isiz, 8L);
    setrvs_("0.,0.,0.", cpza, &isiz, 8L);
    dx = -1;
    dy = 3;
    rca3_(cpxa, cpya, cpza, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__100, "67,801", 6L);
    tstign_(&L__1);
    dx = 3;
    dy = 0;
    rca3_(cpxa, cpya, cpza, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
#ifndef NO_PROTO
    px = 1.f;
    py = 0.f;
    qx = 3.f;
    qy = 2.f;
#else /* NO_PROTO */
    px = (float)1.;
    py = (float)0.;
    qx = (float)3.;
    qy = (float)2.;
#endif /* NO_PROTO */
    dx = 0;
    dy = 3;
    rca_(&px, &py, &qx, &qy, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
    dx = 2;
    dy = -2;
    rca_(&px, &py, &qx, &qy, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
    rca_(&px, &py, &qx, &qy, &c__2, &c__3, &c__1, &c__1, &c__0, &c__3, colia);

    rca3_(cpxa, cpya, cpza, &c__2, &c__3, &c__1, &c__1, &c__2, &c__0, colia);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__100, "67,801", 6L);
    tstign_(&L__1);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03117_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.03/e03118                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e03118_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03118_(useprm)
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
    static integer ix;
    static real spec[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *), rscr_(integer *, integer *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr (), rscr_();
#endif /* NO_PROTO */
    static integer isiz;
    static real spec1[10], spec2[10];
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
    extern logical rareq_();
    extern /* Subroutine */ int nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer numcp2, lclmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf ();
#endif /* NO_PROTO */
    static integer nclmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*  E03118 tests the handling of error 118. */
/*  type of returned values */
/* colour model */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one of the components of the colour specificati"
	    "on is out of range", 200L, 65L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one of the components of the colour specificati\
on is out of range", 200L, 65L);
#endif /* NO_PROTO */
    setvs_("118", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "17", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqcmdf (&specwt, &c__0, &errind, &nclmod, &idum1, &idum2);
    chkinq_("pqcmdf", &errind, 6L);
    i__1 = nclmod;
    for (ix = 1; ix <= i__1; ++ix) {
	nqcmdf (&specwt, &ix, &errind, &idum1, &lclmod, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
	if (lclmod < 1 || lclmod > 4) {
	    goto L150;
	}
	nscmd (&globnu_1.wkid, &lclmod);
	setrvs_("0.5,0.5,0.5", spec1, &isiz, 11L);
	nscr (&globnu_1.wkid, &c__2, &c__3, spec1);
	setrvs_("-0.5, 0., 1.", spec, &isiz, 12L);
	rscr_(&globnu_1.wkid, &c__2, &c__3, spec);
	setrvs_("0., 1.01, 0.5", spec, &isiz, 13L);
	rscr_(&globnu_1.wkid, &c__2, &c__3, spec);
	setrvs_("0., 0.5, -0.01", spec, &isiz, 14L);
	rscr_(&globnu_1.wkid, &c__2, &c__3, spec);
	nqcr (&globnu_1.wkid, &c__2, &c__10, &c__0, &errind, &numcp2, spec2);
	chkinq_("pqcr", &errind, 4L);
	L__1 = streq_("OO**", 4L) && numcp2 == 3 && rareq_(&c__3, spec2, 
		spec1, &c_b116, &c_b116);
	tstign_(&L__1);
L150:
	;
    }
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03118_ */

