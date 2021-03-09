/* e04157.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b8 = 0.f;
static real c_b11 = -.1f;
#else /* NO_PROTO */
static real c_b8 = (float)0.;
static real c_b11 = (float)-.1;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b23 = .01f;
#else /* NO_PROTO */
static real c_b23 = (float).01;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e04157_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04157_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real xx, yy, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ds3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ds3_();
#endif /* NO_PROTO */
    static real dx2, dx3, dy3, dz3, dy2, wkvp[6];
    static integer idum1, idum2, idum3, idum4;
    static real wkvp0[6], wkvp1[6], wkvp4[4];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real rduma[6], rdumb[6], rdumc[6], rdumd[4], rdume[4], rdumf[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nqdsp (integer *, integer *, integer *, 
	    real *, real *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqwkt (integer *, 
	    integer *, integer *, real *, real *, real *, real *), nswkv (
	    integer *, real *, real *, real *, real *), rswkv_(integer *, 
	    real *, real *, real *, real *), nqdsp3 (integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    ), nqwkt3 (integer *, integer *, integer *, real *, real *, real *
	    , real *), nswkv3 (integer *, real *), rswkv3_(integer *, real *),
	     chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern logical rareq_();
    extern /* Subroutine */ int nclwk (), nqwkc (), nqdsp ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqwkt (), nswkv (), 
	    rswkv_(), nqdsp3 (), nqwkt3 (), nswkv3 (), rswkv3_(), chkinq_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */

/*   E04157 tests the handling of error 157. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation viewport is not withi"
	    "n display space", 200L, 62L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation viewport is not withi\
n display space", 200L, 62L);
#endif /* NO_PROTO */
    setvs_("157", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqdsp3 (&specwt, &errind, &idum1, &dx3, &dy3, &dz3, &idum2, &idum3, &
	    idum4);
    chkinq_("pqdsp3", &errind, 6L);
    nqdsp (&specwt, &errind, &idum1, &dx2, &dy2, &idum2, &idum3);
    chkinq_("pqdsp", &errind, 5L);
#ifndef NO_PROTO
    xx = dx3 / 2.f;
    yy = dy3 / 2.f;
    zz = dz3 / 2.f;
#else /* NO_PROTO */
    xx = dx3 / (float)2.;
    yy = dy3 / (float)2.;
    zz = dz3 / (float)2.;
#endif /* NO_PROTO */
/* 3D */
    ds3_(&c_b8, &xx, &c_b8, &yy, &c_b8, &zz, wkvp0);
    nswkv3 (&globnu_1.wkid, wkvp0);
    ds3_(&c_b11, &dx3, &c_b8, &dy3, &c_b8, &dz3, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
#ifndef NO_PROTO
    r__1 = dy3 + .1f;
#else /* NO_PROTO */
    r__1 = dy3 + (float).1;
#endif /* NO_PROTO */
    ds3_(&c_b8, &dx3, &c_b8, &r__1, &c_b8, &dz3, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
#ifndef NO_PROTO
    r__1 = dz3 + .1f;
#else /* NO_PROTO */
    r__1 = dz3 + (float).1;
#endif /* NO_PROTO */
    ds3_(&c_b8, &dx3, &c_b8, &dy3, &c_b11, &r__1, wkvp);
    rswkv3_(&globnu_1.wkid, wkvp);
    nqwkt3 (&globnu_1.wkid, &errind, &idum1, rduma, rdumb, wkvp1, rdumc);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__6, wkvp1, wkvp0, &c_b23, &c_b23);
    tstign_(&L__1);
/* 2D */
#ifndef NO_PROTO
    xx = dx2 / 2.f;
    yy = dy2 / 2.f;
#else /* NO_PROTO */
    xx = dx2 / (float)2.;
    yy = dy2 / (float)2.;
#endif /* NO_PROTO */
    nswkv (&globnu_1.wkid, &c_b8, &xx, &c_b8, &yy);
    rswkv_(&globnu_1.wkid, &c_b11, &dx2, &c_b8, &dy2);
#ifndef NO_PROTO
    r__1 = dy2 + .1f;
#else /* NO_PROTO */
    r__1 = dy2 + (float).1;
#endif /* NO_PROTO */
    rswkv_(&globnu_1.wkid, &c_b8, &dx2, &c_b8, &r__1);
#ifndef NO_PROTO
    r__1 = dy2 + .1f;
#else /* NO_PROTO */
    r__1 = dy2 + (float).1;
#endif /* NO_PROTO */
    rswkv_(&globnu_1.wkid, &c_b11, &dx2, &c_b8, &r__1);
    nqwkt (&globnu_1.wkid, &errind, &idum1, rdumd, rdume, wkvp4, rdumf);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = streq_("OO**", 4L) && appeq_(wkvp4, &c_b8, &c_b23, &c_b23) && 
	    appeq_(&wkvp4[1], &xx, &c_b23, &c_b23) && appeq_(&wkvp4[2], &c_b8,
	     &c_b23, &c_b23) && appeq_(&wkvp4[3], &yy, &c_b23, &c_b23);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04157_ */

