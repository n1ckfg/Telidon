/* e02059.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b13 = 1.f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
#endif /* NO_PROTO */
static integer c__101 = 101;
static integer c__100 = 100;
#ifndef NO_PROTO
static real c_b31 = .5f;
#else /* NO_PROTO */
static real c_b31 = (float).5;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e02059_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02059_(useprm)
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
    static integer iin2, iex2;
    static char cdum[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int ruwk_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ruwk_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int rscmd_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rscmd_();
#endif /* NO_PROTO */
    static integer owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), rsedr_(integer *, 
	    integer *, integer *, integer *, real *, integer *), nclwk (
	    integer *), nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    rsplr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    rpost_(integer *, integer *, real *), rstxr_(integer *, integer *,
	     integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), rsedr_(), nclwk (), nclst ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), rsplr_(), setvs_(), nopst (), 
	    rpost_(), rstxr_();
#endif /* NO_PROTO */
    static integer inset2[10], exset2[10], oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    rsivft_(integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int esetup_(), tstign_(), rsivft_();
#endif /* NO_PROTO */
    static integer nwknot, owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

/*  E02059 tests the handling of error number 59. */
/* off/on switch for edge flag and error handling mode */
/* text precision */
/* colour model */
/* workstation category */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the workstation type does not have output capab"
	    "ility", 200L, 52L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the workstation type does not have output capab\
ility", 200L, 52L);
#endif /* NO_PROTO */
    setvs_("59", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "9", 40L, 1L);
    esetup_(useprm);
    multws_(&c__0, "in", &nwknot, &idum1, &idum2, &idum3, cdum, 2L, 1L);
    if (nwknot == 0) {
#ifndef NO_PROTO
	inmsg_("All accessible workstations have output capability. This tes"
		"t is skipped.", 73L);
#else /* NO_PROTO */
	inmsg_("All accessible workstations have output capability. This tes\
t is skipped.", 73L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = rndint_(&c__1, &nwknot);
    multws_(&i__1, "in", &idum1, &owkid, &oconid, &owtype, owcat, 2L, 1L);
/*  **** Generate errors: */
    nopwk (&owkid, &oconid, &owtype);
    ruwk_(&owkid, &c__0);
    rsplr_(&owkid, &c__1, &c__1, &c_b13, &c__1);
    rstxr_(&owkid, &c__1, &c__1, &c__0, &c_b13, &c_b13, &c__0);
    rsedr_(&owkid, &c__1, &c__0, &c__1, &c_b13, &c__0);
    setvs_("1,5,2", inset2, &iin2, 5L);
    setvs_("4", exset2, &iex2, 1L);
    rsivft_(&owkid, &iin2, inset2, &iex2, exset2);
    rscmd_(&owkid, &c__1);
    nopst (&c__101);
    rpost_(&owkid, &c__100, &c_b31);
    L__1 = streq_("OOO*", 4L);
    tstign_(&L__1);
    nclst ();
    nclwk (&owkid);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02059_ */

