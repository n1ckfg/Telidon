/* c01003.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

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
static integer c__4 = 4;
static integer c__2 = 2;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b13 = 1.f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b29 = 0.f;
#else /* NO_PROTO */
static real c_b29 = (float)0.;
#endif /* NO_PROTO */
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b38 = .5f;
#else /* NO_PROTO */
static real c_b38 = (float).5;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int c01003_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01003_(useprm)
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
    static integer inc[3], exc[3];
    static real limt[4];
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ruwk_(integer *, integer *), rrst_(integer *, 
	    integer *), idmat_(integer *, real *), rscmd_(integer *, integer *
	    ), rsedr_(integer *, integer *, integer *, integer *, real *, 
	    integer *), rclwk_(integer *);
    extern logical streq_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ruwk_(), rrst_(), idmat_(), rscmd_(), rsedr_()
	    , rclwk_();
    extern logical streq_();
#endif /* NO_PROTO */
    static real xfrmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsdus_(integer *, integer *, integer *), 
	    rsplr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), rpost_(integer *, 
	    integer *, real *), rswkw_(integer *, real *, real *, real *, 
	    real *), rswkv_(integer *, real *, real *, real *, real *), 
	    rsvwr_(integer *, integer *, real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsdus_(), rsplr_(), setvs_(), rpost_(), 
	    rswkw_(), rswkv_(), rsvwr_();
#endif /* NO_PROTO */
    static integer defmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifphcl_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifphcl_();
#endif /* NO_PROTO */
    static integer modmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int tstign_(logical *), rshlft_(integer *, 
	    integer *, integer *, integer *, integer *), setrvs_(char *, real 
	    *, integer *, ftnlen), rupast_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int tstign_(), rshlft_(), setrvs_(), rupast_();
#endif /* NO_PROTO */

/*  C01003 tests the handling of error number 3: function requires */
/*  state (PHOP,WSOP,*,*), when PHIGS is closed. */
/*  clipping indicator */
/*  colour model */
/*  control flag conditionally */
/*  deferral mode */
/* modification mode */
/*  edge flag */
/*  regenerate flag */
    ifphcl_(useprm);
    setvs_("3,54", errinf_1.experr, &errinf_1.expsiz, 4L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    rclwk_(&globnu_1.wkid);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rrst_(&globnu_1.wkid, &c__0);
    ruwk_(&globnu_1.wkid, &c__0);
    defmod = rndint_(&c__0, &c__4);
    modmod = rndint_(&c__0, &c__2);
    rsdus_(&globnu_1.wkid, &defmod, &modmod);
    rsplr_(&globnu_1.wkid, &c__1, &c__1, &c_b13, &c__0);
    rsedr_(&globnu_1.wkid, &c__1, &c__1, &c__1, &c_b13, &c__0);
    setvs_("2,3,5", inc, &isiz, 5L);
    setvs_("6", exc, &isiz, 1L);
    rshlft_(&globnu_1.wkid, &c__3, inc, &c__1, exc);
    rscmd_(&globnu_1.wkid, &c__1);
    idmat_(&c__3, xfrmt);
    setrvs_("0.,1.,0.,1.", limt, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, xfrmt, xfrmt, limt, &c__1);
    rswkw_(&globnu_1.wkid, &c_b29, &c_b13, &c_b29, &c_b13);
    rswkv_(&globnu_1.wkid, &c_b29, &c_b13, &c_b29, &c_b13);
    rpost_(&globnu_1.wkid, &c__101, &c_b38);
    rupast_(&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01003_ */

