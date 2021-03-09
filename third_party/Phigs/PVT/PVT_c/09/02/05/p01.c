/* fort/09/02/05/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__100 = 100;
static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b16 = 0.f;
#else /* NO_PROTO */
static real c_b16 = (float)0.;
#endif /* NO_PROTO */
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.05/01                           * */
/*  *    TEST TITLE : Error indicator = 201                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real px[2] = { 0.f,1.f };
    static real py[2] = { 0.f,1.f };
#else /* NO_PROTO */
    static real px[2] = { (float)0.,(float)1. };
    static real py[2] = { (float)0.,(float)1. };
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real ra10[10];
    static integer ees[1], eis[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer ira10[10], irb10[10], arid, arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int rels_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rels_();
#endif /* NO_PROTO */
    static char str10[80*10];
    static integer ira210[20]	/* was [2][10] */, ival1, ival2, ival3, ival4;

#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqeco_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *, integer *, char *, ftnlen), rqpde_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), nclwk (integer *), rqpan_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), nclst (void), rqets_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nopwk (integer *, integer *, integer *), nexst (integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    npost (integer *, integer *, real *), nclarf (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqeco_(), rqpde_(), nclwk (), 
	    rqpan_(), nclst (), rqets_(), nopwk (), nexst (), setvs_(), 
	    nopst (), npost (), nclarf ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), narast (integer *), rqcstn_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), xpopph_(integer *, integer *), rqwkpo_(integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), narast (), 
	    rqcstn_(), xpopph_(), rqwkpo_();
#endif /* NO_PROTO */

/*   search direction */
/*   path order */
/*   structure network source */
    initgl_("09.02.05/01", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the specified structure does not exist", 200L, 
	    38L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    setvs_("201", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
    npl (&c__2, px, py);
    nclst ();
    arid = 11;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
    narast (&arid);
    rqcstn_(&arid, &c__100, &c__0, &c__0, &errind, &ival1, &ival2);
    rqcstn_(&arid, &c__100, &c__1, &c__1, &errind, &ival1, &ival2);
    nclarf (&arid);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    npost (&globnu_1.wkid, &c__102, &c_b16);
    rqwkpo_(&c__100, &c__0, &errind, &ival1, &ival2);
    nclwk (&globnu_1.wkid);
    rqets_(&c__100, &c__1, &errind, &ival1, &ival2, &ival3, &ival4);
    rqeco_(&c__100, &c__1, &c__10, &c__10, &c__10, &errind, &ival1, ira10, &
	    ival2, ra10, &ival3, irb10, str10, 80L);
    rqpan_(&c__100, &c__0, &c__1, &c__10, &c__0, &errind, &ival1, &ival2, 
	    ira210);
    rqpde_(&c__100, &c__1, &c__1, &c__10, &c__0, &errind, &ival1, &ival2, 
	    ira210);
    rels_(&c__100, &c__1, &c__1, &c__1, eis, &c__1, ees, &errind, &ival1, &
	    ival2);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

