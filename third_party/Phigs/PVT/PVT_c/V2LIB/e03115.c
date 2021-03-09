/* e03115.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c_n1 = -1;
#ifndef NO_PROTO
static real c_b9 = .1f;
static real c_b10 = .2f;
static real c_b11 = .3f;
static real c_b12 = .4f;
static real c_b13 = .5f;
static real c_b14 = .6f;
#else /* NO_PROTO */
static real c_b9 = (float).1;
static real c_b10 = (float).2;
static real c_b11 = (float).3;
static real c_b12 = (float).4;
static real c_b13 = (float).5;
static real c_b14 = (float).6;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b27 = .001f;
#else /* NO_PROTO */
static real c_b27 = (float).001;
#endif /* NO_PROTO */
static integer c__6 = 6;

#ifndef NO_PROTO
/* Subroutine */ int e03115_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03115_(useprm)
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
    static integer cl1, cl2, cl3;
    static real xf1[16]	/* was [4][4] */, xcl[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int etr3_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr3_();
#endif /* NO_PROTO */
    static integer isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nqvwr (integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *, integer *, integer *), rsvwr_(integer *, integer *, 
	    real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
    extern logical rareq_();
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nqvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real mapmt3[9]	/* was [3][3] */, mapmt4[16]	/* was [4][4] 
	    */, cplmt3[4], cplmt4[6], rotmt3[9]	/* was [3][3] */, rotmt4[16]	
	    /* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvwr3_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), chkinq_(char *, integer 
	    *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer cpindt, errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*  E03115 tests the handling of error 115. */
/*additional in the FORTRAN binding, to be used with PHIGS inquiry functio
ns*/
/* that return both Current and Requested values. */
/*   clipping indicator */
    s_copy(errchr_1.curcon, "the view index value is less than one", 200L, 
	    37L);
    setvs_("115", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "14", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    idmat_(&c__3, rotmt3);
    idmat_(&c__3, mapmt3);
    setrvs_("0.,1.,0.,1.", cplmt3, &isiz, 11L);
    cpindt = 1;
    rsvwr_(&globnu_1.wkid, &c_n1, rotmt3, mapmt3, cplmt3, &cpindt);
    etr3_(&c_b9, &c_b10, &c_b11, rotmt4);
    etr3_(&c_b12, &c_b13, &c_b14, mapmt4);
    setrvs_("0.1, 0.9, 0.1, 0.9, 0.1, 0.9", cplmt4, &isiz, 28L);
    rsvwr3_(&globnu_1.wkid, &c__0, rotmt4, mapmt4, cplmt4, &c__0, &c__0, &
	    c__0);
    nqvwr (&globnu_1.wkid, &c__0, &c__1, &errind, &idum1, rotmt4, mapmt4, 
	    cplmt4, &cl1, &cl2, &cl3);
    chkinq_("pqvwr", &errind, 5L);
    idmat_(&c__4, xf1);
    setrvs_("0,1,0,1,0,1", xcl, &idum1, 11L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, rotmt4, xf1, &c_b27, &c_b27) 
	    && rareq_(&c__16, mapmt4, xf1, &c_b27, &c_b27) && rareq_(&c__6, 
	    cplmt4, xcl, &c_b27, &c_b27) && cl1 == 1 && cl2 == 1 && cl3 == 1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03115_ */

