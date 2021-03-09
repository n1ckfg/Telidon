/* c01005.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b5 = 0.f;
static real c_b7 = .1f;
#else /* NO_PROTO */
static real c_b5 = (float)0.;
static real c_b7 = (float).1;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b13 = 1.f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
#endif /* NO_PROTO */
static integer c__33 = 33;
static integer c__3 = 3;
static integer c__100 = 100;
static integer c__200 = 200;

#ifndef NO_PROTO
/* Subroutine */ int c01005_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01005_(useprm)
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
    static integer n;
#ifndef NO_PROTO
    extern /* Subroutine */ int rlb_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rlb_();
#endif /* NO_PROTO */
    static integer ixa[2];
    static real pxa[10];
    static integer npl;
    static real pya[10], pza[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int rpm_(integer *, real *, real *), rfas_(
	    integer *, integer *, real *, real *), rsii_(integer *), ratr_(
	    real *, real *, real *, real *, char *, ftnlen), rsep_(integer *),
	     rres_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rpm_(), rfas_(), rsii_(), ratr_(), rsep_(), 
	    rres_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), rsans_(integer *), 
	    rclst_(void), rsgmt_(real *);
    extern logical streq_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), rsans_(), rclst_(), rsgmt_();
    extern logical streq_();
#endif /* NO_PROTO */
    static real xfrmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    ifphcl_(integer *), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_(), ifphcl_(), enderr_();
#endif /* NO_PROTO */
    static integer namest[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int tstign_(logical *), rsmksc_(real *), rsparf_(
	    real *, real *), rshrid_(integer *), rstxfn_(integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int tstign_(), rsmksc_(), rsparf_(), rshrid_(), 
	    rstxfn_(), setrvs_();
#endif /* NO_PROTO */

/*  C01005 tests the handling of error number 5: function requires */
/*  state (PHOP,*,STOP,*), when PHIGS is closed. */
/*   aspect identifier */
/*   aspect source */
/*   composition  type */
    ifphcl_(useprm);
    setvs_("5", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
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
    rpm_(&n, pxa, pya);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    ratr_(&c_b5, &c_b5, &c_b7, &c_b7, "annotation-text", 15L);
    npl = 1;
    ixa[0] = 4;
    setrvs_("0.,0.4,0.4,0.", pxa, &isiz, 13L);
    setrvs_("0.,0.,0.4,0.4", pya, &isiz, 13L);
    rfas_(&npl, ixa, pxa, pya);
    rsii_(&c__1);
    rsmksc_(&c_b13);
    rstxfn_(&c__1);
    rsans_(&c__1);
    rsparf_(&c_b5, &c_b5);
    rres_(&c__1, namest);
    rshrid_(&c__33);
    idmat_(&c__3, xfrmt);
    rsgmt_(xfrmt);
    rclst_();
    rlb_(&c__100);
    rsep_(&c__200);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01005_ */

