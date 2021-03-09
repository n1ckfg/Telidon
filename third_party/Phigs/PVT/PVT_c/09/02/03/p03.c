/* fort/09/02/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.03/03                           * */
/*  *    TEST TITLE : Error indicator = 102                 * */
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
    static real ra6[6], ra9[9], ra10[10], ra44[16]	/* was [4][4] */, 
	    rb44[16]	/* was [4][4] */;
    static integer ia1010[100]	/* was [10][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *), nqif (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf (), nqif ();
#endif /* NO_PROTO */
    static integer ival1, ival2, ival3, ival4, ival5;
    static real rval1, rval2, rval3, rval4;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nqpaf (integer *, integer *, integer *), nqplf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, integer *), nqpmf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *), nqwkc (integer *, integer *, integer *, integer *), 
	    rqpcr_(integer *, integer *, integer *, integer *, integer *, 
	    real *), rqpir_(integer *, integer *, integer *, integer *, 
	    integer *, integer *), nopwk (integer *, integer *, integer *), 
	    nqvwf (integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen), nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nqpaf (), nqplf (), 
	    nqpmf (), nqwkc (), rqpcr_(), rqpir_(), nopwk (), nqvwf (), 
	    setvs_(), nqtxf (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, nindex, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqpedr_(integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    rqppar_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), xpopph_(integer *, integer *), 
	    rqpplr_(integer *, integer *, integer *, integer *, real *, 
	    integer *), rqppmr_(integer *, integer *, integer *, integer *, 
	    real *, integer *), rqptxr_(integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *), rqpvwr_(integer 
	    *, integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqpedr_(), rqppar_(), xpopph_(), 
	    rqpplr_(), rqppmr_(), rqptxr_(), rqpvwr_();
#endif /* NO_PROTO */

    initgl_("09.02.03/03", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified representation has not been prede"
	    "fined on this workstation", 200L, 72L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified representation has not been prede\
fined on this workstation", 200L, 72L);
#endif /* NO_PROTO */
    setvs_("102", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqvwf (&specwt, &errind, &nindex);
    chkinq_("pqvwf", &errind, 5L);
    i__1 = nindex + 1;
    rqpvwr_(&specwt, &i__1, &errind, ra44, rb44, ra6, &ival1, &ival2, &ival3);

    nqplf (&specwt, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &rval2, &
	    rval3, &nindex);
    chkinq_("pqplf", &errind, 5L);
    i__1 = nindex + 1;
    rqpplr_(&specwt, &i__1, &errind, &ival1, &rval1, &ival2);
    nqpmf (&specwt, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &rval2, &
	    rval3, &nindex);
    chkinq_("pqpmf", &errind, 5L);
    i__1 = nindex + 1;
    rqppmr_(&specwt, &i__1, &errind, &ival1, &rval1, &ival2);
    nqtxf (&specwt, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &rval1, &
	    rval2, &ival5, &rval3, &rval4, &nindex);
    chkinq_("pqtxf", &errind, 5L);
    i__1 = nindex + 1;
    rqptxr_(&specwt, &i__1, &errind, &ival1, &ival2, &rval1, &rval2, &ival3);
    nqif (&specwt, &c__0, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &
	    nindex);
    chkinq_("pqif", &errind, 4L);
    i__1 = nindex + 1;
    rqpir_(&specwt, &i__1, &errind, &ival1, &ival2, &ival3);
    nqedf (&specwt, &c__0, &errind, &ival1, &ival2, &ival3, &rval2, &rval2, &
	    rval3, &nindex);
    chkinq_("pqedf", &errind, 5L);
    i__1 = nindex + 1;
    rqpedr_(&specwt, &i__1, &errind, &ival1, &ival2, &rval1, &ival3);
    nqpaf (&specwt, &errind, &nindex);
    chkinq_("pqpaf", &errind, 5L);
    i__1 = nindex + 2;
    rqppar_(&specwt, &i__1, &c__10, &c__10, &errind, &ival1, &ival2, ia1010);
    nqcf (&specwt, &errind, &ival1, &ival2, &nindex, ra9);
    chkinq_("pqcf", &errind, 4L);
    i__1 = nindex + 10;
    rqpcr_(&specwt, &i__1, &c__10, &errind, &ival1, ra10);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

