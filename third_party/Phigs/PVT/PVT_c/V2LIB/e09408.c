/* e09408.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int e09408_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09408_(useprm)
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
    static integer ix;
    static char msg[100];
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer arnm, isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_();
#endif /* NO_PROTO */
    static integer nstid;
#ifndef NO_PROTO
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern logical seteq_();
    extern /* Subroutine */ int nqsid ();
#endif /* NO_PROTO */
    static integer stids[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int rresn_(integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nclarf (integer *), 
	    chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rresn_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), setvs_(), nclarf (), chkinq_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), narast (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), narast ();
#endif /* NO_PROTO */
    static integer stlist[10], status;
#ifndef NO_PROTO
    extern /* Subroutine */ int tstwan_(logical *, char *, ftnlen), nqstst (
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int tstwan_(), nqstst ();
#endif /* NO_PROTO */

/*   E09408 tests the handling of error 408. */
/*  structure status indicator */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "some of the specified structures do not exist o"
	    "n the archive file", 200L, 65L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "some of the specified structures do not exist o\
n the archive file", 200L, 65L);
#endif /* NO_PROTO */
    s_copy(msg, "it should create empty structures in their place.", 100L, 
	    49L);
    setvs_("408", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "9", 40L, 1L);
    esetup_(useprm);
    arid = 11;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
    crest_();
    narast (&arid);
    ndas ();
    setvs_("100,102,101", stlist, &isiz, 11L);
    rrest_(&arid, &isiz, stlist);
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    i__1 = nstid;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum1, &stids[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L100: */
    }
    nqstst (&c__102, &errind, &status);
    chkinq_("pqstst", &errind, 6L);
    L__1 = streq_("O**O", 4L) && nstid == 3 && seteq_(&c__3, stids, stlist) &&
	     status == 1;
    tstwan_(&L__1, msg, 100L);
    ndas ();
    rresn_(&arid, &isiz, stlist);
    nclarf (&arid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09408_ */

