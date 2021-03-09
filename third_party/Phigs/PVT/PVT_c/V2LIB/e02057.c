/* e02057.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b10 = .4f;
static real c_b11 = .6f;
static real c_b12 = .5f;
static real c_b13 = .7f;
static real c_b21 = 0.f;
static real c_b22 = 1.f;
#else /* NO_PROTO */
static real c_b10 = (float).4;
static real c_b11 = (float).6;
static real c_b12 = (float).5;
static real c_b13 = (float).7;
static real c_b21 = (float)0.;
static real c_b22 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e02057_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02057_(useprm)
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
#ifndef NO_PROTO
    extern /* Subroutine */ int etr_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr_();
#endif /* NO_PROTO */
    static char cdum[1];
    static integer isiz, idum1, idum2, idum3, owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static integer nwkmi;
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), rswkv_(integer *, 
	    real *, real *, real *, real *), rswkw_(integer *, real *, real *,
	     real *, real *), rsvwr_(integer *, integer *, real *, real *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), rswkv_(), rswkw_(), 
	    rsvwr_();
#endif /* NO_PROTO */
    static real mapmt2[9]	/* was [3][3] */, limit2[6], rotmt2[9]	/* 
	    was [3][3] */;
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvtip_(integer *, integer *, integer *, 
	    integer *), multws_(integer *, char *, integer *, integer *, 
	    integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvtip_(), multws_();
#endif /* NO_PROTO */

/*  E02057 tests the handling of error number 57. */
/* workstation category */
/*  relative input priority */
    s_copy(errchr_1.curcon, "the specified workstation is of category MI", 
	    200L, 43L);
    setvs_("57", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    multws_(&c__0, "n", &nwkmi, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    if (nwkmi == 0) {
#ifndef NO_PROTO
	inmsg_("There is no accessible workstation with category of MI, the "
		"test is skipped.", 76L);
#else /* NO_PROTO */
	inmsg_("There is no accessible workstation with category of MI, the \
test is skipped.", 76L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = rndint_(&c__1, &nwkmi);
    multws_(&i__1, "n", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
/*  **** Generate errors */
    nopwk (&owkid, &oconid, &owtype);
    etr_(&c_b10, &c_b11, mapmt2);
    etr_(&c_b12, &c_b13, rotmt2);
    setrvs_("0.1,0.9,0.2,0.9", limit2, &isiz, 15L);
    rsvwr_(&owkid, &c__1, rotmt2, mapmt2, limit2, &c__0);
    L__1 = streq_("OO**", 4L);
    tstign_(&L__1);
    rsvtip_(&owkid, &c__1, &c__1, &c__1);
    rswkw_(&owkid, &c_b21, &c_b22, &c_b21, &c_b22);
    rswkv_(&owkid, &c_b21, &c_b22, &c_b21, &c_b22);
    nclwk (&owkid);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02057_ */

