/* fort/09/02/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

#ifndef NO_PROTO
static real c_b5 = 0.f;
#else /* NO_PROTO */
static real c_b5 = (float)0.;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b9 = .5f;
static real c_b14 = .1f;
static real c_b15 = -.1f;
static real c_b18 = 1.57f;
static real c_b19 = -.3f;
static real c_b20 = 1.f;
static real c_b21 = 2.f;
static real c_b28 = .3f;
#else /* NO_PROTO */
static real c_b9 = (float).5;
static real c_b14 = (float).1;
static real c_b15 = (float)-.1;
static real c_b18 = (float)1.57;
static real c_b19 = (float)-.3;
static real c_b20 = (float)1.;
static real c_b21 = (float)2.;
static real c_b28 = (float).3;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__10 = 10;
static integer c__100 = 100;
static integer c__6 = 6;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.01/01                           * */
/*  *    TEST TITLE : Error indicator = 2                   * */
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
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ia2[2], ib2[2], ia5[5], ia6[6], ib6[6];
    static real ra2[2], rb2[2], ra4[4], rb4[4], ra6[6], ra9[9], ra33[9]	/* 
	    was [3][3] */, rb33[9]	/* was [3][3] */, ra44[16]	/* 
	    was [4][4] */, rb44[16]	/* was [4][4] */, rc44[16]	/* 
	    was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rro_(real *, integer *, real *), rtp_(real *, 
	    real *, real *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rro_(), rtp_();
#endif /* NO_PROTO */
    static integer ia1010[100]	/* was [10][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqcf_(integer *, integer *, integer *, 
	    integer *, integer *, real *), rqif_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rels_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     rqdp_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqcf_(), rqif_(), rels_(), rqdp_();
#endif /* NO_PROTO */
    static integer isiz;
    static char chra6[10*6];
    static integer ival1, ival2, ival3, ival4, ival5, ival6, ival7, ival8;
#ifndef NO_PROTO
    extern /* Subroutine */ int rcom3_(real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rcom3_();
#endif /* NO_PROTO */
    static real rval1, rval2, rval3, rval4;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), rqedf_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), endit_(void), rqedm_(integer *, 
	    integer *), rqeco_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen), rqarf_(integer *, integer *
	    , integer *, integer *, integer *), rqgdp_(integer *, integer *, 
	    integer *, integer *, integer *), rqphf_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rqsid_(integer *, integer *, integer *, integer *), 
	    rcotm_(real *, real *, real *, real *, real *, real *, real *, 
	    real *, integer *, real *), rqpmf_(integer *, integer *, integer *
	    , integer *, integer *, integer *, real *, real *, real *, 
	    integer *), revmm_(real *, real *, integer *, real *), rqpan_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), rqewk_(integer *, integer *, 
	    integer *, integer *), rqets_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), rqvwf_(integer *, integer *, 
	    integer *), rqtxf_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *, real *
	    , real *, integer *), rqtxx_(integer *, integer *, real *, real *,
	     real *, integer *, integer *, integer *, char *, integer *, real 
	    *, real *, real *, real *, ftnlen), rbltm3_(real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, integer *, real *), revom3_(real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, integer *, real *), 
	    rqdsp3_(integer *, integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *), rqcmdf_(integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), rqedf_(), endit_(), rqedm_(), 
	    rqeco_(), rqarf_(), rqgdp_(), rqphf_(), rqsid_(), rcotm_(), 
	    rqpmf_(), revmm_(), rqpan_(), rqewk_(), rqets_(), setvs_(), 
	    rqvwf_(), rqtxf_(), rqtxx_(), rbltm3_(), revom3_(), rqdsp3_(), 
	    rqcmdf_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqmclf_(integer *, 
	    integer *, integer *, integer *, integer *), rqcnrs_(integer *, 
	    integer *, integer *), rqwkca_(integer *, integer *, integer *), 
	    rqwkcl_(integer *, integer *, integer *), rqddus_(integer *, 
	    integer *, integer *, integer *), rqppar_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     rqegse_(integer *, integer *, integer *, integer *, integer *), 
	    rqopwk_(integer *, integer *, integer *, integer *), setrvs_(char 
	    *, real *, integer *, ftnlen), rqwksl_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), rqdstr_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), rqopst_(integer *, 
	    integer *, integer *), rqstst_(integer *, integer *, integer *), 
	    rqpvwr_(integer *, integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqmclf_(), rqcnrs_(), rqwkca_(), 
	    rqwkcl_(), rqddus_(), rqppar_(), rqegse_(), rqopwk_(), setrvs_(), 
	    rqwksl_(), rqdstr_(), rqopst_(), rqstst_(), rqpvwr_();
#endif /* NO_PROTO */

    initgl_("09.02.01/01", 11L);
    s_copy(errchr_1.curcon, "PHIGS is closed", 200L, 15L);
    setvs_("2", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    rro_(&c_b5, &errind, ra33);
    idmat_(&c__4, ra44);
    idmat_(&c__4, rb44);
    rcom3_(ra44, rb44, &errind, rc44);
    idmat_(&c__3, ra33);
    rtp_(&c_b9, &c_b9, ra33, &errind, &rval1, &rval2);
    rbltm3_(&c_b9, &c_b9, &c_b9, &c_b14, &c_b15, &c_b5, &c_b5, &c_b18, &c_b19,
	     &c_b20, &c_b21, &c_b14, &errind, ra44);
    idmat_(&c__4, ra44);
    rcotm_(ra33, &c_b9, &c_b9, &c_b14, &c_b15, &c_b28, &c_b20, &c_b14, &
	    errind, rb33);
    revom3_(&c_b5, &c_b5, &c_b5, &c_b5, &c_b20, &c_b5, &c_b20, &c_b5, &c_b5, &
	    errind, ra44);
    setrvs_("0.,1.,0.,1.", ra4, &isiz, 11L);
    setrvs_("0.,0.5, 0.,0.5", rb4, &isiz, 14L);
    revmm_(ra4, rb4, &errind, ra33);
    rqewk_(&c__0, &errind, &ival1, &ival2);
    rqphf_(&c__0, &errind, &ival1, &ival2, &ival3, &ival4, &ival5, &ival6, &
	    ival7);
    rqmclf_(&c__0, &errind, &ival1, &ival2, &ival3);
    rqedm_(&errind, &ival1);
    rqopwk_(&c__0, &errind, &ival1, &ival2);
    rqsid_(&c__0, &errind, &ival1, &ival2);
    rqarf_(&c__0, &errind, &ival1, &ival2, &ival3);
    rqcnrs_(&errind, &ival1, &ival2);
    rqwkca_(&globnu_1.wtype, &errind, &ival1);
    rqdsp3_(&globnu_1.wtype, &errind, &ival1, &rval1, &rval2, &rval3, &ival2, 
	    &ival3, &ival4);
    rqvwf_(&globnu_1.wtype, &errind, &ival1);
    rqpvwr_(&globnu_1.wtype, &c__0, &errind, ra44, rb44, ra6, &ival1, &ival2, 
	    &ival3);
    rqwkcl_(&globnu_1.wtype, &errind, &ival1);
    rqddus_(&globnu_1.wtype, &errind, &ival1, &ival2);
    rqpmf_(&globnu_1.wtype, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &
	    rval2, &rval3, &ival4);
    rqtxf_(&globnu_1.wtype, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &
	    rval1, &rval2, &ival5, &rval3, &rval4, &ival6);
    rqtxx_(&globnu_1.wtype, &c__1, &c_b9, &c_b14, &c_b9, &c__1, &c__1, &c__1, 
	    "TEXT", &errind, ra2, rb2, &rval1, &rval2, 4L);
    rqif_(&globnu_1.wtype, &c__0, &c__0, &errind, &ival1, &ival2, &ival3, &
	    ival4, &ival5);
    rqedf_(&globnu_1.wtype, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &
	    rval2, &rval3, &ival4);
    rqppar_(&globnu_1.wtype, &c__1, &c__10, &c__10, &errind, &ival1, &ival2, 
	    ia1010);
    rqcmdf_(&globnu_1.wtype, &c__0, &errind, &ival1, &ival2, &ival3);
    rqcf_(&globnu_1.wtype, &errind, &ival1, &ival2, &ival3, ra9);
    rqgdp_(&globnu_1.wtype, &c__1, &errind, &ival1, ia5);
    rqegse_(&globnu_1.wtype, &c__0, &errind, &ival1, &ival2);
    rqdp_(&globnu_1.wtype, &errind, &ival1);
    rqwksl_(&globnu_1.wtype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5, 
	    &ival6, &ival7, &ival8);
    rqdstr_(&globnu_1.wtype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5);

    rqopst_(&errind, &ival1, &ival2);
    rqets_(&c__100, &c__1, &errind, &ival1, &ival2, &ival3, &ival4);
    rqeco_(&c__100, &c__1, &c__6, &c__6, &c__6, &errind, &ival1, ia6, &ival2, 
	    ra6, &ival3, ib6, chra6, 10L);
    rqstst_(&c__100, &errind, &ival1);
    rqpan_(&c__100, &c__1, &c__1, &c__6, &c__1, &errind, &ival1, &ival2, ia6);

    rels_(&c__100, &c__1, &c__1, &c__2, ia2, &c__2, ib2, &errind, &ival1, &
	    ival2);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

