/* e05201.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__102 = 102;
static integer c__10 = 10;
static integer c__0 = 0;
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int e05201_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05201_(useprm)
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
    static integer ol, ix, arf, nst;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer path[20]	/* was [2][10] */, arnm, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_();
    extern logical seteq_();
    extern /* Subroutine */ int nqsid ();
    extern logical streq_();
#endif /* NO_PROTO */
    static integer expst[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer lstst[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar (), chkinq_();
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
	    integer *, integer *, integer *), setval_(char *, integer *, 
	    ftnlen), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), narast (), 
	    rrepan_(), setval_(), tstign_();
#endif /* NO_PROTO */

/*  E05201 tests the handling of error 201. */
/*   path order */
    s_copy(errchr_1.curcon, "the specified structure does not exist", 200L, 
	    38L);
    setvs_("201", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    arf = 11;
/*  set up empty archive file */
    avarnm_(&arnm);
    noparf (&arf, &arnm);
    ndasar (&arf);
/*  create structure network #100 - 101 */
    crest_();
/*  archive all structures */
    narast (&arf);
    pathod = 0;
    pathdp = 0;
/*  retrieve ancestors of non-existent structure */
    rrepan_(&arf, &c__102, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    setval_("101,100", expst, 7L);
    nqsid (&c__0, &errind, &nst, &idum1);
    chkinq_("pqsid", &errind, 5L);
    i__1 = nst;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum1, &lstst[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L110: */
    }
    L__1 = streq_("O**O", 4L) && nst == 2 && seteq_(&c__2, lstst, expst);
    tstign_(&L__1);
/*  clear archive and CSS */
    ndas ();
    ndasar (&arf);
/*  create structure network #100 - 101 */
    crest_();
/*  archive all structures */
    narast (&arf);
    pathod = 1;
    pathdp = 0;
/*  retrieve descendants of non-existent structure */
    rrepde_(&arf, &c__102, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    setval_("101,100", expst, 7L);
    nqsid (&c__0, &errind, &nst, &idum1);
    chkinq_("pqsid", &errind, 5L);
    i__1 = nst;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum1, &lstst[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L120: */
    }
    L__1 = streq_("O**O", 4L) && nst == 2 && seteq_(&c__2, lstst, expst);
    tstign_(&L__1);
/*  clear archive and CSS */
    ndas ();
    ndasar (&arf);
    nclarf (&arf);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05201_ */

