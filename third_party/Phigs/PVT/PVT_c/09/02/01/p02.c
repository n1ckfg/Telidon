/* fort/09/02/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.01/02                           * */
/*  *    TEST TITLE : Error indicator = 3                   * */
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
    static real ra4[4], rb4[4], rc4[4], rd4[4], ra6[6], rb6[6], rc6[6], rd6[6]
	    ;
    static integer ia10[10], ib10[10];
    static real ra10[10], ra44[16]	/* was [4][4] */, rb44[16]	/* 
	    was [4][4] */;
    static integer ia1010[100]	/* was [10][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqcr_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), rqir_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int rqcr_(), rqir_();
#endif /* NO_PROTO */
    static integer ival1, ival2, ival3, ival4;
    static real rval1, rval2;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqeci_(integer *, integer *, integer *, 
	    integer *, integer *), endit_(void), rqcmd_(integer *, integer *, 
	    integer *), rqeii_(integer *, integer *, integer *, integer *, 
	    integer *), rqedr_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), rqpar_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), rqwkc_(integer *, integer *, integer *, 
	    integer *), rqhrm_(integer *, integer *, integer *, integer *, 
	    integer *), rqdus_(integer *, integer *, integer *, integer *, 
	    integer *, integer *), rqplr_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), rqpmr_(integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), rqwkt_(integer *, 
	    integer *, integer *, real *, real *, real *, real *), rqtxr_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), rqvwr_(integer *, integer *, integer *
	    , integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *), rqwkt3_(integer *, integer *, integer *, 
	    real *, real *, real *, real *), rqeedi_(integer *, integer *, 
	    integer *, integer *, integer *), rqepai_(integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqeci_(), endit_(), rqcmd_(), rqeii_(), 
	    rqedr_(), rqpar_(), rqwkc_(), rqhrm_(), rqdus_(), rqplr_(), 
	    rqpmr_(), setvs_(), rqwkt_(), rqtxr_(), rqvwr_(), rqwkt3_(), 
	    rqeedi_(), rqepai_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqepmi_(integer *, 
	    integer *, integer *, integer *, integer *), rqhlft_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rqepli_(integer *, integer *, integer *, integer *, 
	    integer *), rqetxi_(integer *, integer *, integer *, integer *, 
	    integer *), rqevwi_(integer *, integer *, integer *, integer *, 
	    integer *), xpopph_(integer *, integer *), rqivft_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rqpost_(integer *, integer *, integer *, integer *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqepmi_(), rqhlft_(), rqepli_(), 
	    rqetxi_(), rqevwi_(), xpopph_(), rqivft_(), rqpost_();
#endif /* NO_PROTO */

    initgl_("09.02.01/02", 11L);
    s_copy(errchr_1.curcon, "PHIGS is closed", 200L, 15L);
    setvs_("3", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    rqevwi_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqhrm_(&globnu_1.wkid, &errind, &ival1, &ival2, &ival3);
    rqdus_(&globnu_1.wkid, &errind, &ival1, &ival2, &ival3, &ival4);
    rqplr_(&globnu_1.wkid, &c__1, &c__0, &errind, &ival1, &rval1, &ival2);
    rqepmi_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqtxr_(&globnu_1.wkid, &c__1, &c__0, &errind, &ival1, &ival2, &rval1, &
	    rval2, &ival3);
    rqeii_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqedr_(&globnu_1.wkid, &c__1, &c__0, &errind, &ival1, &ival2, &rval1, &
	    ival3);
    rqepai_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqcmd_(&globnu_1.wkid, &errind, &ival1);
    rqcr_(&globnu_1.wkid, &c__1, &c__10, &c__0, &errind, &ival1, ra10);
    rqhlft_(&globnu_1.wkid, &c__10, &c__10, &errind, &ival1, ia10, &ival2, 
	    ib10);
    rqwkt_(&globnu_1.wkid, &errind, &ival1, ra4, rb4, rc4, rd4);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "PHIGS is open but no workstation is open", 200L, 
	    40L);
    rqwkc_(&globnu_1.wkid, &errind, &ival1, &ival2);
    rqvwr_(&globnu_1.wkid, &c__1, &c__0, &errind, &ival1, ra44, rb44, ra6, &
	    ival2, &ival3, &ival4);
    rqpost_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2, &rval1);
    rqepli_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqpmr_(&globnu_1.wkid, &c__1, &c__1, &errind, &ival1, &rval1, &ival2);
    rqetxi_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqir_(&globnu_1.wkid, &c__1, &c__0, &errind, &ival1, &ival2, &ival3);
    rqeedi_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqpar_(&globnu_1.wkid, &c__1, &c__1, &c__10, &c__10, &errind, &ival1, &
	    ival2, ia1010);
    rqeci_(&globnu_1.wkid, &c__0, &errind, &ival1, &ival2);
    rqivft_(&globnu_1.wkid, &c__10, &c__10, &errind, &ival1, ia10, &ival2, 
	    ib10);
    rqwkt3_(&globnu_1.wkid, &errind, &ival1, ra6, rb6, rc6, rd6);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

