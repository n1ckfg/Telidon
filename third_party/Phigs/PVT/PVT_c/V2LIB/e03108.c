/* e03108.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int e03108_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03108_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static logical isavl[5] = { FALSE_,FALSE_,FALSE_,FALSE_,FALSE_ };

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
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqir (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nsir (integer *, integer *, integer *, 
	    integer *, integer *), rsir_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqif (), nqir (), nsir (), rsir_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer nisty1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, istyle, isindx, iscolo, thisis, specwt, untype;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E03108 tests the handling of error 108 */
/*  interior style */
/*  type of returned value */
    setvs_("108", errinf_1.experr, &errinf_1.expsiz, 3L);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified interior style is not available o"
	    "n the specified workstation", 200L, 74L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified interior style is not available o\
n the specified workstation", 200L, 74L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "8", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqif (&specwt, &c__0, &c__0, &errind, &nisty1, &idum1, &idum2, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
    i__1 = nisty1;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&specwt, &ix, &c__0, &errind, &idum2, &thisis, &idum3, &idum4, &
		idum5);
	chkinq_("pqif", &errind, 4L);
	if (thisis >= 0 && thisis <= 4) {
	    isavl[thisis] = TRUE_;
	}
/* L50: */
    }
    for (ix = 0; ix <= 4; ++ix) {
	if (! isavl[ix]) {
	    untype = ix;
	    goto L70;
	}
/* L60: */
    }
    inmsg_("No unavailable interior styles; test is skipped.", 48L);
    return 0;
L70:
    nsir (&globnu_1.wkid, &c__1, &thisis, &c__1, &c__0);
    rsir_(&globnu_1.wkid, &c__1, &untype, &c__2, &c__1);
    nqir (&globnu_1.wkid, &c__1, &c__0, &errind, &istyle, &isindx, &iscolo);
    chkinq_("pqir", &errind, 4L);
    L__1 = streq_("OO**", 4L) && istyle == thisis && isindx == 1 && iscolo == 
	    0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03108_ */

