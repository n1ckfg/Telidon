/* fort//V2LIB/e03117.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__801 = 801;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e03117_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03117_(useprm)
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
    static integer dx, dy;
    static real px, py, qx, qy;
#ifndef NO_PROTO
    extern /* Subroutine */ int rca_(real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    ), nlb (integer *), rca3_(real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int rca_(), nlb (), rca3_();
#endif /* NO_PROTO */
    static real cpxa[3], cpya[3], cpza[3];
    static integer isiz, colia[6]	/* was [2][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), enderr_(void), esetup_(integer *);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int tstign_(logical *), setrvs_(char *, real *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst (), enderr_(), esetup_();
    extern logical strcon_();
    extern /* Subroutine */ int tstign_(), setrvs_();
#endif /* NO_PROTO */

/*  E03117 tests the handling of Error 117. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one of the dimensions of the colour index array"
	    " is less than one", 200L, 64L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one of the dimensions of the colour index array\
 is less than one", 200L, 64L);
#endif /* NO_PROTO */
    setvs_("117", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "16", 40L, 2L);
    esetup_(useprm);
    nopst (&c__100);
    nlb (&c__801);
    setvs_("1,1,1,0,0,1", colia, &isiz, 11L);
    setrvs_("0.,3.,4.", cpxa, &isiz, 8L);
    setrvs_("0.,1.,0.", cpya, &isiz, 8L);
    setrvs_("0.,0.,0.", cpza, &isiz, 8L);
    dx = -1;
    dy = 3;
    rca3_(cpxa, cpya, cpza, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__100, "67,801", 6L);
    tstign_(&L__1);
    dx = 3;
    dy = 0;
    rca3_(cpxa, cpya, cpza, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
#ifndef NO_PROTO
    px = 1.f;
    py = 0.f;
    qx = 3.f;
    qy = 2.f;
#else /* NO_PROTO */
    px = (float)1.;
    py = (float)0.;
    qx = (float)3.;
    qy = (float)2.;
#endif /* NO_PROTO */
    dx = 0;
    dy = 3;
    rca_(&px, &py, &qx, &qy, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
    dx = 2;
    dy = -2;
    rca_(&px, &py, &qx, &qy, &c__2, &c__3, &c__1, &c__1, &dx, &dy, colia);
    rca_(&px, &py, &qx, &qy, &c__2, &c__3, &c__1, &c__1, &c__0, &c__3, colia);

    rca3_(cpxa, cpya, cpza, &c__2, &c__3, &c__1, &c__1, &c__2, &c__0, colia);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__100, "67,801", 6L);
    tstign_(&L__1);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03117_ */

