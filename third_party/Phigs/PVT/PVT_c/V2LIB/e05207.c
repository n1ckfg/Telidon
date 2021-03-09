/* e05207.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__103 = 103;
static integer c__100 = 100;
static integer c__10 = 10;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__101 = 101;

#ifndef NO_PROTO
/* Subroutine */ int e05207_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05207_(useprm)
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
    static integer ol, arf, nst;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer path[20]	/* was [2][10] */, arnm, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_(), nqsid ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), nclarf (integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst (), nclarf (), chkinq_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrepde_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrepde_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), narast (integer *), rrepan_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), narast (), 
	    rrepan_(), tstign_();
#endif /* NO_PROTO */

/*   E05207 tests the handling of error 207. */
/*   path order */
    s_copy(errchr_1.curcon, "the specified path depth is less than zero", 
	    200L, 42L);
    setvs_("207", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    arf = 11;
    avarnm_(&arnm);
    noparf (&arf, &arnm);
    crest_();
    narast (&arf);
    ndas ();
    nopst (&c__103);
    pathod = 1;
    pathdp = -1;
    rrepan_(&arf, &c__100, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    nqsid (&c__1, &errind, &nst, &strid);
    chkinq_("pqsid", &errind, 5L);
    L__1 = streq_("O**O", 4L) && nst == 1 && strid == 103;
    tstign_(&L__1);
    pathod = 0;
    pathdp = -100;
    rrepde_(&arf, &c__101, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    nqsid (&c__1, &errind, &nst, &strid);
    chkinq_("pqsid", &errind, 5L);
    L__1 = streq_("O**O", 4L) && nst == 1 && strid == 103;
    tstign_(&L__1);
    nclarf (&arf);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05207_ */

