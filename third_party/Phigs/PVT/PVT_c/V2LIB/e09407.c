/* e09407.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__101 = 101;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e09407_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09407_(useprm)
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
    static char msg[100];
    static integer arid, arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndst ();
#endif /* NO_PROTO */
    static integer isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_();
#endif /* NO_PROTO */
    static integer nstid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *), nrast (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nclarf (integer *), ndasar (integer *), chkinq_(char *, integer *,
	     ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqsid (), nrast ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nclarf (), ndasar (), chkinq_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), narast (integer *), rdstar_(
	    integer *, integer *, integer *), rdsnar_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), narast (), 
	    rdstar_(), rdsnar_();
#endif /* NO_PROTO */
    static integer stlist[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int tstwan_(logical *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int tstwan_();
#endif /* NO_PROTO */

/*   E09407 tests the handling of error 407. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "some of the specified structures do not exist o"
	    "n the archive file", 200L, 65L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "some of the specified structures do not exist o\
n the archive file", 200L, 65L);
#endif /* NO_PROTO */
    s_copy(msg, "it should ignore the structures that do not exist.", 100L, 
	    50L);
    setvs_("407", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "8", 40L, 1L);
    esetup_(useprm);
    arid = 11;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
    ndasar (&arid);
    crest_();
    narast (&arid);
    setvs_("100,102,101", stlist, &isiz, 11L);
    rdstar_(&arid, &isiz, stlist);
    ndst (&c__100);
    ndst (&c__101);
    nrast (&arid);
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    L__1 = streq_("O**O", 4L) && nstid == 0;
    tstwan_(&L__1, msg, 100L);
    crest_();
    narast (&arid);
    setvs_("100,102", stlist, &isiz, 7L);
    rdsnar_(&arid, &isiz, stlist);
    nclarf (&arid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09407_ */

