/* e02052.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int e02052_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02052_(useprm)
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
    static integer ix, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqewk (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int ropwk_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqewk ();
    extern logical streq_();
    extern /* Subroutine */ int ropwk_(), setvs_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer nmtype, thisty, mxtype;

/*  E02052 tests the handling of error number 52 */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the workstation type is not recognized by the i"
	    "mplementation", 200L, 60L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the workstation type is not recognized by the i\
mplementation", 200L, 60L);
#endif /* NO_PROTO */
    setvs_("52,55", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nqewk (&c__1, &errind, &nmtype, &mxtype);
    chkinq_("pqewk", &errind, 5L);
    i__1 = nmtype;
    for (ix = 1; ix <= i__1; ++ix) {
	nqewk (&ix, &errind, &idum1, &thisty);
	chkinq_("pqewk", &errind, 5L);
	if (thisty > mxtype) {
	    thisty = mxtype;
	}
/* L50: */
    }
    i__1 = mxtype + 1;
    ropwk_(&globnu_1.wkid, &globnu_1.conid, &i__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02052_ */

