/* c01002.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__11 = 11;
static integer c__24 = 24;

#ifndef NO_PROTO
/* Subroutine */ int c01002_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01002_(useprm)
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
    static integer mode;
#ifndef NO_PROTO
    extern /* Subroutine */ int rdsn_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rdsn_();
#endif /* NO_PROTO */
    static integer dsnt, arccr;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedm_();
#endif /* NO_PROTO */
    static integer retcr;
#ifndef NO_PROTO
    extern /* Subroutine */ int remst_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int ropwk_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), ifphcl_(integer *), 
	    enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int tstign_(logical *), rcstir_(integer *, 
	    integer *), roparf_(integer *, integer *), rscnrs_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int remst_();
    extern logical streq_();
    extern /* Subroutine */ int ropwk_(), setvs_(), ifphcl_(), enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int tstign_(), rcstir_(), roparf_(), rscnrs_();
#endif /* NO_PROTO */

/*  C01002 tests the handling of error number 2: function requires */
/*  state (PHOP,*,*,*). */
/*  edit mode */
/*  reference handling flag */
/*  conflict resolution maintain,  abandon,    update */
    ifphcl_(useprm);
    setvs_("2", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    ropwk_(&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    mode = rndint_(&c__0, &c__1);
    rsedm_(&mode);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    remst_(&c__101);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    dsnt = rndint_(&c__0, &c__1);
    rdsn_(&c__101, &dsnt);
    rcstir_(&c__101, &c__102);
    arccr = rndint_(&c__0, &c__2);
    retcr = rndint_(&c__0, &c__2);
    roparf_(&c__11, &c__24);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rscnrs_(&arccr, &retcr);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01002_ */

