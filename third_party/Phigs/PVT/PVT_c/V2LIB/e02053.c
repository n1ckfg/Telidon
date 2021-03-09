/* e02053.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int e02053_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02053_(useprm)
integer *useprm;
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
    static char cdum[1];
    static integer idum1, idum2, idum3;
    static logical ignok;
    static integer owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    ropwk_(integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), ropwk_(), setvs_();
#endif /* NO_PROTO */
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, nwkall, opwkid;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer numowk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk ();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

/*  E02053 tests the handling of error number 53 */
    s_copy(errchr_1.curcon, "the specified workstation identifier is in use", 
	    200L, 46L);
    setvs_("53", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
/*  **** Generate errors */
    ignok = TRUE_;
    multws_(&c__0, "a", &nwkall, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    i__1 = nwkall;
    for (ix = 1; ix <= i__1; ++ix) {
	multws_(&ix, "a", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
	nopwk (&owkid, &oconid, &owtype);
	ropwk_(&owkid, &oconid, &owtype);
	nqopwk (&c__1, &errind, &numowk, &opwkid);
	chkinq_("pqopwk", &errind, 6L);
	if (! (streq_("OO**", 4L) && numowk == 1 && opwkid == owkid)) {
	    ignok = FALSE_;
	}
	nclwk (&owkid);
/* L150: */
    }
    tstign_(&ignok);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02053_ */

