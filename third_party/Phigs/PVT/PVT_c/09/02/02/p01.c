/* fort/09/02/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b15 = .1f;
static real c_b17 = .3f;
#else /* NO_PROTO */
static real c_b15 = (float).1;
static real c_b17 = (float).3;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.02/01                           * */
/*  *    TEST TITLE : Error indicator = 52                  * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, ia5[5];
    static real ra2[2], rb2[2], ra6[6], ra9[9], ra44[16]	/* was [4][4] 
	    */, rb44[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqcf_(integer *, integer *, integer *, 
	    integer *, integer *, real *), rqif_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rqdp_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqcf_(), rqif_(), rqdp_();
#endif /* NO_PROTO */
    static integer this__, ival1, ival2, ival3, ival4, ival5, ival6, idum1, 
	    ival7, ival8, ival9;
    static real rval1, rval2, rval3, rval4;
    static integer ival10, ival11, ival12;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqpaf_(integer *, integer *, 
	    integer *), rqplf_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *), nqewk (
	    integer *, integer *, integer *, integer *), rqdsp_(integer *, 
	    integer *, integer *, real *, real *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), rqvwf_(integer *, 
	    integer *, integer *), rqtxf_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *), rqtxx_(integer *, integer *
	    , real *, real *, real *, integer *, integer *, integer *, char *,
	     integer *, real *, real *, real *, real *, ftnlen), rqgdp3_(
	    integer *, integer *, integer *, integer *, integer *), chkinq_(
	    char *, integer *, ftnlen), rqcmdf_(integer *, integer *, integer 
	    *, integer *, integer *, integer *), rqegdp_(integer *, integer *,
	     integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqpaf_(), rqplf_(), nqewk (), 
	    rqdsp_(), setvs_(), rqvwf_(), rqtxf_(), rqtxx_(), rqgdp3_(), 
	    chkinq_(), rqcmdf_(), rqegdp_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqwkca_(integer *, 
	    integer *, integer *), rqhrif_(integer *, integer *, integer *, 
	    integer *, integer *), rqwkcl_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqwkca_(), rqhrif_(), rqwkcl_();
#endif /* NO_PROTO */
    static integer nmtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqdswa_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), xpopph_(
	    integer *, integer *), rqddus_(integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqdswa_(), xpopph_(), rqddus_();
#endif /* NO_PROTO */
    static integer wktype;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqppmr_(integer *, integer *, integer *, 
	    integer *, real *, integer *), rqpedr_(integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), rqegse_(
	    integer *, integer *, integer *, integer *, integer *), rqwksl_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), rqdstr_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     rqpvwr_(integer *, integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqppmr_(), rqpedr_(), rqegse_(), rqwksl_(), 
	    rqdstr_(), rqpvwr_();
#endif /* NO_PROTO */

    initgl_("09.02.02/01", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the workstation type is not recognized by the i"
	    "mplementation", 200L, 60L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the workstation type is not recognized by the i\
mplementation", 200L, 60L);
#endif /* NO_PROTO */
    setvs_("52", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    nqewk (&c__1, &errind, &nmtype, &wktype);
    chkinq_("pqewk", &errind, 5L);
    i__1 = nmtype;
    for (ix = 2; ix <= i__1; ++ix) {
	nqewk (&ix, &errind, &idum1, &this__);
	chkinq_("pqewk", &errind, 5L);
	if (this__ > wktype) {
	    wktype = this__;
	}
/* L50: */
    }
    ++wktype;
    rqwkca_(&wktype, &errind, &ival1);
    rqdsp_(&wktype, &errind, &ival1, &rval1, &rval2, &ival2, &ival3);
    rqhrif_(&wktype, &c__0, &errind, &ival1, &ival2);
    rqvwf_(&wktype, &errind, &ival1);
    rqpvwr_(&wktype, &c__1, &errind, ra44, rb44, ra6, &ival1, &ival2, &ival3);

    rqwkcl_(&wktype, &errind, &ival1);
    rqdswa_(&wktype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5, &ival6, 
	    &ival7, &ival8, &ival9, &ival10, &ival11, &ival12);
    rqddus_(&wktype, &errind, &ival1, &ival2);
    rqplf_(&wktype, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &rval2, &
	    rval3, &ival4);
    rqppmr_(&wktype, &c__1, &errind, &ival1, &rval1, &ival2);
    rqtxf_(&wktype, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &rval1, &
	    rval2, &ival3, &rval3, &rval4, &ival4);
    rqtxx_(&wktype, &c__1, &c_b15, &c_b15, &c_b17, &c__1, &c__1, &c__1, "TEXT"
	    , &errind, ra2, rb2, &rval1, &rval2, 4L);
    rqif_(&wktype, &c__0, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &
	    ival5);
    rqpedr_(&wktype, &c__1, &errind, &ival1, &ival2, &rval1, &ival3);
    rqpaf_(&wktype, &errind, &ival1);
    rqcmdf_(&wktype, &c__1, &errind, &ival1, &ival2, &ival3);
    rqcf_(&wktype, &errind, &ival1, &ival2, &ival3, ra9);
    rqegdp_(&wktype, &c__0, &errind, &ival1, &ival2);
    rqgdp3_(&wktype, &c__1, &errind, &ival1, ia5);
    rqegse_(&wktype, &c__0, &errind, &ival1, &ival2);
    rqdp_(&wktype, &errind, &ival1);
    rqwksl_(&wktype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5, &ival6, 
	    &ival7, &ival8);
    rqdstr_(&wktype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

