/* e01003.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b12 = 1.f;
#else /* NO_PROTO */
static real c_b12 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b27 = 0.f;
#else /* NO_PROTO */
static real c_b27 = (float)0.;
#endif /* NO_PROTO */
static integer c__101 = 101;

#ifndef NO_PROTO
/* Subroutine */ int e01003_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01003_(useprm)
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
    static integer inc[3], exc[3], isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *), ruwk_(integer *, integer *), rrst_(integer 
	    *, integer *), rclwk_(integer *), rshrm_(integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rspmr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    rswkv_(integer *, real *, real *, real *, real *), rswkw_(integer 
	    *, real *, real *, real *, real *), enderr_(void), esetup_(
	    integer *), tstign_(logical *), rsivft_(integer *, integer *, 
	    integer *, integer *, integer *), rupost_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_(), ruwk_(), rrst_(), rclwk_(), rshrm_();
#endif /* NO_PROTO */

#ifdef NO_PROTO
    extern logical streq_();
    extern /* Subroutine */ int rspmr_(), setvs_(), rswkv_(), rswkw_(), 
	    enderr_(), esetup_(), tstign_(), rsivft_(), rupost_();

#endif /* NO_PROTO */
/*  E01003 tests the handling of error number 3: function requires */
/*  state (PHOP,WSOP,*,*), when PHIGS is open. */
/*  clipping indicator */
/*  colour model */
/*  control flag conditionally */
/*  deferral mode */
/*  edge flag */
/*  regenerate flag */
/* interior style */
    s_copy(errchr_1.curcon, "PHIGS is open but all workstations are closed", 
	    200L, 45L);
    setvs_("3,54", errinf_1.experr, &errinf_1.expsiz, 4L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    rclwk_(&globnu_1.wkid);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rrst_(&globnu_1.wkid, &c__0);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    ruwk_(&globnu_1.wkid, &c__0);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rspmr_(&globnu_1.wkid, &c__1, &c__1, &c_b12, &c__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rsir_(&globnu_1.wkid, &c__1, &c__0, &c__1, &c__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    setvs_("2,3,5", inc, &isiz, 5L);
    setvs_("6", exc, &isiz, 1L);
    rsivft_(&globnu_1.wkid, &c__3, inc, &c__1, exc);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rshrm_(&globnu_1.wkid, &c__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rswkw_(&globnu_1.wkid, &c_b27, &c_b12, &c_b27, &c_b12);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rswkv_(&globnu_1.wkid, &c_b27, &c_b12, &c_b27, &c_b12);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rupost_(&globnu_1.wkid, &c__101);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01003_ */

