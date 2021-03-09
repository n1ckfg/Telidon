/* fort//09/02/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 09.02.03/02                           * */
/*  *    TEST TITLE : Error indicator = 101                 * */
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
    static integer ix;
    static real ra6[6], ra10[10], ra44[16]	/* was [4][4] */, rb44[16]	
	    /* was [4][4] */;
    static integer this__;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqcr_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), rqir_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int rqcr_(), rqir_();
#endif /* NO_PROTO */
    static integer ival1, ival2, ival3;
    static real rval1, rval2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), endit_(void), nqeii (integer *, integer *, 
	    integer *, integer *, integer *), rqedr_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nopwk (integer *, integer *, integer *), rqplr_(integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    rqpmr_(integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    rqtxr_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), rqvwr_(integer *, integer *
	    , integer *, integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), endit_(), nqeii (), rqedr_(), 
	    nopwk (), rqplr_(), rqpmr_(), setvs_(), rqtxr_(), rqvwr_();
#endif /* NO_PROTO */
    static integer index1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeedi (integer *, integer *, integer *, 
	    integer *, integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeedi (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, nindex;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqepli (integer *, 
	    integer *, integer *, integer *, integer *), nqepmi (integer *, 
	    integer *, integer *, integer *, integer *), nqetxi (integer *, 
	    integer *, integer *, integer *, integer *), nqevwi (integer *, 
	    integer *, integer *, integer *, integer *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqepli (), nqepmi (), nqetxi (), 
	    nqevwi (), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.03/02", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified representation has not been defin"
	    "ed", 200L, 49L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified representation has not been defin\
ed", 200L, 49L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    setvs_("101", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqevwi", &errind, 6L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqevwi (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqevwi", &errind, 6L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L50: */
    }
    ++index1;
    rqvwr_(&globnu_1.wkid, &index1, &c__0, &errind, &ival1, ra44, rb44, ra6, &
	    ival1, &ival2, &ival3);
    nqepli (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqepli", &errind, 6L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqepli (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqepli", &errind, 6L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L150: */
    }
    ++index1;
    rqplr_(&globnu_1.wkid, &index1, &c__0, &errind, &ival1, &rval1, &ival2);
    nqepmi (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqepmi", &errind, 6L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqepmi (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqepmi", &errind, 6L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L250: */
    }
    ++index1;
    rqpmr_(&globnu_1.wkid, &index1, &c__0, &errind, &ival1, &rval1, &ival2);
    nqetxi (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqetxi", &errind, 6L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqetxi (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqetxi", &errind, 6L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L350: */
    }
    index1 += 2;
    rqtxr_(&globnu_1.wkid, &index1, &c__0, &errind, &ival1, &ival2, &rval1, &
	    rval2, &ival3);
    nqeii (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqeii", &errind, 5L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqeii (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqeii", &errind, 5L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L450: */
    }
    index1 += 10;
    rqir_(&globnu_1.wkid, &index1, &c__0, &errind, &ival1, &ival2, &ival3);
    nqeedi (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqeedi", &errind, 6L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqeedi (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqeedi", &errind, 6L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L550: */
    }
    ++index1;
    rqedr_(&globnu_1.wkid, &index1, &c__0, &errind, &ival1, &ival2, &rval1, &
	    ival3);
    nqeci (&globnu_1.wkid, &c__0, &errind, &nindex, &ival1);
    chkinq_("pqeci", &errind, 5L);
    index1 = 1;
    i__1 = nindex;
    for (ix = 1; ix <= i__1; ++ix) {
	nqeci (&globnu_1.wkid, &ix, &errind, &ival1, &this__);
	chkinq_("pqeci", &errind, 5L);
	if (this__ > index1) {
	    index1 = this__;
	}
/* L750: */
    }
    ++index1;
    rqcr_(&globnu_1.wkid, &index1, &c__10, &c__0, &errind, &ival1, ra10);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

