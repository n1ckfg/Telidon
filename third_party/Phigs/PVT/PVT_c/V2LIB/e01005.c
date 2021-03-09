/* e01005.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

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

static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b7 = 0.f;
static real c_b8 = .5f;
#else /* NO_PROTO */
static real c_b7 = (float)0.;
static real c_b8 = (float).5;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b15 = 1.f;
#else /* NO_PROTO */
static real c_b15 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__101 = 101;

#ifndef NO_PROTO
/* Subroutine */ int e01005_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01005_(useprm)
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
    static integer n, op;
#ifndef NO_PROTO
    extern /* Subroutine */ int rfa_(integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rfa_();
#endif /* NO_PROTO */
    static real pxa[10], pya[10], pza[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int rtx_(real *, real *, char *, ftnlen), rpl3_(
	    integer *, real *, real *, real *), rdel_(void), rads_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rtx_(), rpl3_(), rdel_(), rads_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsln_(integer *), idmat_(integer *, real *), 
	    rspli_(integer *), rsmcv_(integer *, integer *, real *);
    extern logical streq_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsln_(), idmat_(), rspli_(), rsmcv_();
    extern logical streq_();
#endif /* NO_PROTO */
    static real xfrmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rslmt_(real *, integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), rexst_(integer *), rsedfg_(integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rslmt_(), setvs_(), rexst_(), rsedfg_();
#endif /* NO_PROTO */
    static real halfsp[8]	/* was [4][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer namest[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int rspmci_(integer *), rsiasf_(integer *, 
	    integer *), rcelst_(integer *), esetup_(integer *), rschxp_(real *
	    ), tstign_(logical *), setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int rspmci_(), rsiasf_(), rcelst_(), esetup_(), 
	    rschxp_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  E01005 tests the handling of error number 5: function requires */
/*  state (PHOP,*,STOP,*), when PHIGS is open. */
/*   aspect identifier */
/*   aspect source */
/*   composition  type */
/* modelling clipping operator */
/*                replace     intersect */
    s_copy(errchr_1.curcon, "PHIGS is open but no structure is open", 200L, 
	    38L);
    setvs_("5", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    n = 2;
#ifndef NO_PROTO
    pxa[0] = 0.f;
    pxa[1] = .5f;
    pya[0] = 0.f;
    pya[1] = .5f;
    pza[0] = 0.f;
    pza[1] = .5f;
#else /* NO_PROTO */
    pxa[0] = (float)0.;
    pxa[1] = (float).5;
    pya[0] = (float)0.;
    pya[1] = (float).5;
    pza[0] = (float)0.;
    pza[1] = (float).5;
#endif /* NO_PROTO */
    rpl3_(&c__2, pxa, pya, pza);
    L__1 = streq_("O*C*", 4L);
    tstign_(&L__1);
    rtx_(&c_b7, &c_b8, "TEXT", 4L);
    setrvs_("0.,0.5,0.5,0.", pxa, &isiz, 13L);
    setrvs_("0.,0.,0.5,0.5", pya, &isiz, 13L);
    rfa_(&n, pxa, pya);
    rspli_(&c__1);
    rsln_(&c__1);
    rspmci_(&c__1);
    rschxp_(&c_b15);
    rsedfg_(&c__1);
    namest[0] = 1;
    rads_(&c__1, namest);
    rsiasf_(&c__0, &c__1);
    idmat_(&c__3, xfrmt);
    rslmt_(xfrmt, &c__2);
    op = 1;
    n = 2;
    setrvs_("0.52,0.,-1.,0.,0.48,0.,1.,0.", halfsp, &isiz, 28L);
    rsmcv_(&op, &n, halfsp);
    rexst_(&c__101);
    L__1 = streq_("O*C*", 4L);
    tstign_(&L__1);
    rcelst_(&c__101);
    L__1 = streq_("O*C*", 4L);
    tstign_(&L__1);
    rdel_();
    L__1 = streq_("O*C*", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01005_ */

