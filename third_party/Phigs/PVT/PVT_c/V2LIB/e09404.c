/* e09404.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int e09404_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09404_(useprm)
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
    static integer arid, narf, arnm, isiz, osiz, arid1, qarid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf ();
#endif /* NO_PROTO */
    static integer qarnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void), rrsid_(integer *, integer *, 
	    integer *, integer *), rarsn_(integer *, integer *, integer *), 
	    rresn_(integer *, integer *, integer *), rarst_(integer *, 
	    integer *, integer *), rrast_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nclarf (integer *), 
	    rclarf_(integer *), rdasar_(integer *), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_(), rrsid_(), rarsn_(), rresn_(), 
	    rarst_(), rrast_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), setvs_(), nclarf (), rclarf_(), 
	    rdasar_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int rdstar_(integer *, integer *, integer *), 
	    esetup_(integer *), tstign_(logical *), avarnm_(integer *), 
	    noparf (integer *, integer *), rarast_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rdstar_(), esetup_(), tstign_(), avarnm_(), 
	    noparf (), rarast_();
#endif /* NO_PROTO */
    static integer otlist[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int rdsnar_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rdsnar_();
#endif /* NO_PROTO */
    static integer stlist[10];

/*  E09404 tests the handling of error 404. */
    s_copy(errchr_1.curcon, "the specified archive file is not open", 200L, 
	    38L);
    setvs_("404,7", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    arid = 11;
    crest_();
    setvs_("100,101", stlist, &isiz, 7L);
    rclarf_(&arid);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rarst_(&arid, &isiz, stlist);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rrsid_(&arid, &c__10, &osiz, otlist);
    rrest_(&arid, &isiz, stlist);
    rrast_(&arid);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rdstar_(&arid, &isiz, stlist);
    avarnm_(&arnm);
    noparf (&arid, &arnm);
    arid1 = arid + 1;
    rarsn_(&arid1, &isiz, stlist);
    rarast_(&arid1);
    rresn_(&arid1, &isiz, stlist);
    rdsnar_(&arid1, &isiz, stlist);
    rdasar_(&arid1);
    nqarf (&c__1, &errind, &narf, &qarid, &qarnm);
    L__1 = streq_("O**O", 4L) && errind == 0 && narf == 1 && qarid == arid && 
	    qarnm == arnm;
    tstign_(&L__1);
    nclarf (&arid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09404_ */

