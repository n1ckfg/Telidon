/* e09405.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__100 = 100;

#ifndef NO_PROTO
/* Subroutine */ int e09405_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09405_(useprm)
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
    static integer ix, nst, arid, arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndst ();
#endif /* NO_PROTO */
    static integer isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_(), nqsid ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int rarsn_(integer *, integer *, integer *), 
	    rresn_(integer *, integer *, integer *), nqcst (integer *, 
	    integer *, integer *, integer *, integer *), rarst_(integer *, 
	    integer *, integer *), rrast_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nclarf (integer *), 
	    ndasar (integer *), chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rarsn_(), rresn_(), nqcst (), rarst_(), 
	    rrast_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), setvs_(), nclarf (), ndasar (), 
	    chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, nstcft, stcflt[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), nscnrs (integer *, 
	    integer *), avarnm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), nscnrs (), avarnm_();
#endif /* NO_PROTO */
    static integer stlist[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int noparf (integer *, integer *), narast (
	    integer *), srtiar_(integer *, integer *), tstign_(logical *), 
	    rarast_(integer *), nqcstn (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int noparf (), narast (), srtiar_(), tstign_(), 
	    rarast_(), nqcstn ();
#endif /* NO_PROTO */

/*  E09405 tests the handling of error 405. */
/*  conflict resolution */
/*  structure network source */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "name conflict occurs while conflict resolution "
	    "flag has value ABANDON", 200L, 69L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "name conflict occurs while conflict resolution \
flag has value ABANDON", 200L, 69L);
#endif /* NO_PROTO */
    setvs_("405", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    arid = 11;
    crest_();
    nscnrs (&c__1, &c__1);
    avarnm_(&arnm);
    noparf (&arid, &arnm);
    ndasar (&arid);
    narast (&arid);
    setvs_("100", stlist, &isiz, 3L);
    rarst_(&arid, &isiz, stlist);
    nqcst (&arid, &c__0, &errind, &nstcft, &idum1);
    chkinq_("pqcst", &errind, 5L);
    i__1 = nstcft;
    for (ix = 1; ix <= i__1; ++ix) {
	nqcst (&arid, &ix, &errind, &idum1, &stcflt[ix - 1]);
	chkinq_("pqcst", &errind, 5L);
/* L100: */
    }
    srtiar_(&c__2, stcflt);
    L__1 = streq_("O**O", 4L) && nstcft == 2 && stcflt[0] == 100 && stcflt[1] 
	    == 101;
    tstign_(&L__1);
    rarsn_(&arid, &isiz, stlist);
    rarast_(&arid);
    rrest_(&arid, &isiz, stlist);
    rresn_(&arid, &isiz, stlist);
    nqcstn (&arid, &c__100, &c__1, &c__0, &errind, &nstcft, &idum1);
    chkinq_("pqcstn", &errind, 6L);
    i__1 = nstcft;
    for (ix = 1; ix <= i__1; ++ix) {
	nqcstn (&arid, &c__100, &c__1, &ix, &errind, &idum1, &stcflt[ix - 1]);

	chkinq_("pqcstn", &errind, 6L);
/* L150: */
    }
    srtiar_(&c__2, stcflt);
    L__1 = streq_("O**O", 4L) && nstcft == 2 && stcflt[0] == 100 && stcflt[1] 
	    == 101;
    tstign_(&L__1);
    ndst (&c__100);
    rrast_(&arid);
    nqsid (&c__1, &errind, &nst, &strid);
    chkinq_("pqsid", &errind, 5L);
    L__1 = streq_("O**O", 4L) && nst == 1 && strid == 101;
    tstign_(&L__1);
    nclarf (&arid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09405_ */

