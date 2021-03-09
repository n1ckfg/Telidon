/* fort/09/01/09/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__10 = 10;
static integer c__2 = 2;
static integer c__100 = 100;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.09/e09401                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e09401_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09401_(useprm)
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
    static integer ix, arnm, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *), nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nclarf (integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf (), nqphf ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nclarf (), chkinq_();
#endif /* NO_PROTO */
    static integer maxarf;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer errind, numarf;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), avarnm_(integer *), 
	    noparf (integer *, integer *), roparf_(integer *, integer *), 
	    tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), avarnm_(), noparf (), roparf_(), 
	    tstign_();
#endif /* NO_PROTO */

/*  E09401 tests the handling of error 401. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "opening this archive file would exceed the maxi"
	    "mum number of simultaneously open archive files", 200L, 94L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "opening this archive file would exceed the maxi\
mum number of simultaneously open archive files", 200L, 94L);
#endif /* NO_PROTO */
    setvs_("401", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nqphf (&idum1, &errind, &idum2, &maxarf, &idum3, &idum4, &idum5, &idum6, &
	    idum7);
    chkinq_("pqphf", &errind, 5L);
    i__1 = maxarf;
    for (ix = 1; ix <= i__1; ++ix) {
	avarnm_(&arnm);
	noparf (&ix, &arnm);
/* L100: */
    }
    avarnm_(&arnm);
    i__1 = maxarf + 1;
    roparf_(&i__1, &arnm);
    nqarf (&c__0, &errind, &numarf, &idum1, &idum2);
    chkinq_("pqarf", &errind, 5L);
    L__1 = streq_("O**O", 4L) && numarf == maxarf;
    tstign_(&L__1);
    i__1 = maxarf;
    for (ix = 1; ix <= i__1; ++ix) {
	nclarf (&ix);
/* L150: */
    }
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09401_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.09/e09402                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e09402_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09402_(useprm)
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
    static integer arid, narf, arnm1, arnm2, qarid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf ();
#endif /* NO_PROTO */
    static integer qarnm;
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nclarf (integer *), enderr_(void);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nclarf (), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), roparf_(integer *, integer *), 
	    tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), roparf_(), 
	    tstign_();
#endif /* NO_PROTO */

/*   E09402 tests the handling of error 402. */
    s_copy(errchr_1.curcon, "the archive file identifier is already in use", 
	    200L, 45L);
    setvs_("402", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    arid = 11;
    avarnm_(&arnm1);
    noparf (&arid, &arnm1);
    avarnm_(&arnm2);
    roparf_(&arid, &arnm2);
    nqarf (&c__1, &errind, &narf, &qarid, &qarnm);
    L__1 = streq_("O**O", 4L) && errind == 0 && narf == 1 && qarid == arid && 
	    qarnm == arnm1;
    tstign_(&L__1);
    nclarf (&arid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09402_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.09/e09404                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.09/e09405                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.09/e09407                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.09/e09408                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

