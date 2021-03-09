/* e04156.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b12 = .01f;
static real c_b14 = .1f;
static real c_b15 = .9f;
static real c_b18 = -.1f;
static real c_b19 = 1.f;
static real c_b20 = 0.f;
static real c_b25 = 1.1f;
#else /* NO_PROTO */
static real c_b12 = (float).01;
static real c_b14 = (float).1;
static real c_b15 = (float).9;
static real c_b18 = (float)-.1;
static real c_b19 = (float)1.;
static real c_b20 = (float)0.;
static real c_b25 = (float)1.1;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e04156_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04156_(useprm)
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
    static integer isiz;
    static real wkwn[6];
    static integer idum1;
    static real wkwn0[6], wkwn1[6], wkwn4[4];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real rduma[6], rdumb[6], rdumc[6], rdumd[4], rdume[4], rdumf[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqwkt (integer *, 
	    integer *, integer *, real *, real *, real *, real *), nswkw (
	    integer *, real *, real *, real *, real *), rswkw_(integer *, 
	    real *, real *, real *, real *), nqwkt3 (integer *, integer *, 
	    integer *, real *, real *, real *, real *), nswkw3 (integer *, 
	    real *), rswkw3_(integer *, real *), chkinq_(char *, integer *, 
	    ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern logical rareq_();
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqwkt (), nswkw (), 
	    rswkw_(), nqwkt3 (), nswkw3 (), rswkw3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*   E04156 tests the handling of error 156. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation window limits are not"
	    " within NPC range", 200L, 64L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation window limits are not\
 within NPC range", 200L, 64L);
#endif /* NO_PROTO */
    setvs_("156", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  3D */
    setrvs_(".1,.9,.1,.9,.1,.9", wkwn0, &isiz, 17L);
    nswkw3 (&globnu_1.wkid, wkwn0);
    setrvs_("-.1,1.,0.,1.,0.,1.", wkwn, &isiz, 18L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,0.,1.1,0.,1.", wkwn, &isiz, 18L);
    rswkw3_(&globnu_1.wkid, wkwn);
    setrvs_("0.,1.,0.,1.,-0.1,1.1", wkwn, &isiz, 20L);
    rswkw3_(&globnu_1.wkid, wkwn);
    nqwkt3 (&globnu_1.wkid, &errind, &idum1, wkwn1, rduma, rdumb, rdumc);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__6, wkwn0, wkwn1, &c_b12, &c_b12);
    tstign_(&L__1);
/*  2D */
    nswkw (&globnu_1.wkid, &c_b14, &c_b15, &c_b14, &c_b15);
    rswkw_(&globnu_1.wkid, &c_b18, &c_b19, &c_b20, &c_b19);
    rswkw_(&globnu_1.wkid, &c_b14, &c_b19, &c_b20, &c_b25);
    rswkw_(&globnu_1.wkid, &c_b18, &c_b19, &c_b20, &c_b25);
    nqwkt (&globnu_1.wkid, &errind, &idum1, wkwn4, rdumd, rdume, rdumf);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = streq_("OO**", 4L) && appeq_(wkwn4, &c_b14, &c_b12, &c_b12) && 
	    appeq_(&wkwn4[1], &c_b15, &c_b12, &c_b12) && appeq_(&wkwn4[2], &
	    c_b14, &c_b12, &c_b12) && appeq_(&wkwn4[3], &c_b15, &c_b12, &
	    c_b12);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04156_ */

