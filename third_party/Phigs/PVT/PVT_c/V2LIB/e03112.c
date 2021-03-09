/* e03112.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e03112_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03112_(useprm)
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
#ifndef NO_PROTO
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *), inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *), rspar_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_(), inmsg_(), nclwk (), nqwkc (), rspar_(
	    );
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer ptrary[1]	/* was [1][1] */;
#ifndef NO_PROTO
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical intsty_();
#endif /* NO_PROTO */

/*  E03112 tests the handling of error 112. */
/*  interior style */
    s_copy(errchr_1.curcon, "the pattern index value is less than one", 200L, 
	    40L);
    setvs_("112", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "11", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (! intsty_(&specwt, &c__2)) {
#ifndef NO_PROTO
	inmsg_("Pattern style not supported by this workstation; test skippe"
		"d.", 62L);
#else /* NO_PROTO */
	inmsg_("Pattern style not supported by this workstation; test skippe\
d.", 62L);
#endif /* NO_PROTO */
	goto L666;
    }
    rsir_(&globnu_1.wkid, &c__1, &c__2, &c_n1, &c__0);
    L__1 = streq_("OO**", 4L);
    tstign_(&L__1);
    ptrary[0] = 0;
    rspar_(&globnu_1.wkid, &c__0, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, 
	    ptrary);
L666:
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03112_ */

