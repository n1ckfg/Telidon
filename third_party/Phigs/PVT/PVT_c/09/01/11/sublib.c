/* source.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__200 = 200;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__18 = 18;
#ifndef NO_PROTO
static real c_b26 = .5f;
#else NO_PROTO
static real c_b26 = (float).5;
#endif NO_PROTO
static integer c__100 = 100;
static integer c__11 = 11;
#ifndef NO_PROTO
static real c_b51 = .3f;
#else NO_PROTO
static real c_b51 = (float).3;
#endif NO_PROTO
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.11/e12202                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e12202_(integer *useprm)
#else NO_PROTO
/* Subroutine */ int e12202_(useprm)
integer *useprm;
#endif NO_PROTO
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else NO_PROTO
    /* Subroutine */ int s_copy();
#endif NO_PROTO

    /* Local variables */
    static integer ol;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else NO_PROTO
    extern /* Subroutine */ int ntx ();
#endif NO_PROTO
    static real cplm[4];
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int rdsn_(integer *, integer *);
#else NO_PROTO
    extern /* Subroutine */ int rdsn_();
#endif NO_PROTO
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsis_(integer *), ruwk_(integer *, integer *),
	     rrst_(integer *, integer *), idmat_(integer *, real *), rsedm_(
	    integer *);
    static integer paths[20]	/* was [2][10] */;
    extern /* Subroutine */ int rsedr_(integer *, integer *, integer *, 
	    integer *, real *, integer *), nclwk (integer *), nclst (void), 
	    nopwk (integer *, integer *, integer *), rsdus_(integer *, 
	    integer *, integer *), rslmt_(real *, integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), nopst (integer *), rstxp_(integer *
	    ), nsvwr (integer *, integer *, real *, real *, real *, integer *)
	    , rsvwr_(integer *, integer *, real *, real *, real *, integer *);
#else NO_PROTO
    extern /* Subroutine */ int rsis_(), ruwk_(), rrst_(), idmat_(), rsedm_();
#endif NO_PROTO

#ifdef NO_PROTO
    static integer paths[20]	/* was [2][10] */;
    extern /* Subroutine */ int rsedr_(), nclwk (), nclst (), nopwk (), 
	    rsdus_(), rslmt_(), setvs_(), nopst (), rstxp_(), nsvwr (), 
	    rsvwr_();
#endif NO_PROTO
    static real xfrmt3[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), rsedfg_(integer *), 
	    enderr_(void), rsatal_(integer *, integer *), rsiasf_(integer *, 
	    integer *), esetup_(integer *), avarnm_(integer *);
#else NO_PROTO
    extern /* Subroutine */ int nclarf (), rsedfg_(), enderr_(), rsatal_(), 
	    rsiasf_(), esetup_(), avarnm_();
#endif NO_PROTO
    static integer apthsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int rscnrs_(integer *, integer *), noparf (
	    integer *, integer *), narast (integer *), rrepan_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), rserhm_(integer *), setrvs_(char *, real *,
	     integer *, ftnlen), rsvtip_(integer *, integer *, integer *, 
	    integer *);
#else NO_PROTO
    extern /* Subroutine */ int rscnrs_(), noparf (), narast (), rrepan_(), 
	    rserhm_(), setrvs_(), rsvtip_();
#endif NO_PROTO

/*  E12202 tests the handling of C specific error 2202. */
    s_copy(errchr_1.curcon, "specified enumeration type is out of range", 
	    200L, 42L);
    setvs_("2202", errinf_1.experr, &errinf_1.expsiz, 4L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    rrst_(&globnu_1.wkid, &c__2);
    ruwk_(&globnu_1.wkid, &c__3);
    rsdus_(&globnu_1.wkid, &c__5, &c__0);
    rsdus_(&globnu_1.wkid, &c__1, &c__3);
    nopst (&c__200);
    rstxp_(&c__4);
    rsatal_(&c__4, &c__2);
    rsatal_(&c__1, &c__6);
    rsis_(&c__5);
    rsedfg_(&c__2);
    rsiasf_(&c__18, &c__1);
    rsiasf_(&c__2, &c__2);
    rsedr_(&globnu_1.wkid, &c__1, &c__2, &c__1, &c_b26, &c__1);
    idmat_(&c__3, xfrmt3);
    rslmt_(xfrmt3, &c__3);
    nclst ();
    setrvs_("0.,1.,0.,1.", cplm, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, xfrmt3, xfrmt3, cplm, &c__2);
    nsvwr (&globnu_1.wkid, &c__2, xfrmt3, xfrmt3, cplm, &c__0);
    rsvtip_(&globnu_1.wkid, &c__1, &c__2, &c__2);
    rsedm_(&c__2);
    nopst (&c__100);
    ntx (&c_b26, &c_b26, "TEXT", 4L);
    nclst ();
    rdsn_(&c__100, &c__2);
    rscnrs_(&c__3, &c__0);
    rscnrs_(&c__0, &c__3);
    avarnm_(&arnm);
    noparf (&c__11, &arnm);
    nopst (&c__100);
    ntx (&c_b51, &c_b51, "TEXT3", 5L);
    nclst ();
    narast (&c__11);
    rrepan_(&c__11, &c__100, &c__2, &c__1, &c__10, &c__0, &ol, &apthsz, paths)
	    ;
    rserhm_(&c__2);
    nclarf (&c__11);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif NO_PROTO
} /* e12202_ */

