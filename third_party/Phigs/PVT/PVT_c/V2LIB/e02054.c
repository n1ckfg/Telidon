/* e02054.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b13 = 1.f;
static real c_b14 = .1f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
static real c_b14 = (float).1;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b52 = 0.f;
#else /* NO_PROTO */
static real c_b52 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e02054_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02054_(useprm)
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
#ifndef NO_PROTO
    extern /* Subroutine */ int rscr_(integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int rscr_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ruwk_(integer *, integer *), rrst_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ruwk_(), rrst_();
#endif /* NO_PROTO */
    static integer colia[1]	/* was [1][1] */;
    static real cspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nclwk (integer *), 
	    rclwk_(integer *), nclst (void), rspar_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rshrm_(integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    rsdus_(integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen), nopst (integer *), rpost_(integer *, integer 
	    *, real *), rswkw_(integer *, real *, real *, real *, real *), 
	    rstxr_(integer *, integer *, integer *, integer *, real *, real *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nclwk (), rclwk_(), nclst (), 
	    rspar_(), rshrm_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), rsdus_(), setvs_(), nopst (), 
	    rpost_(), rswkw_(), rstxr_();
#endif /* NO_PROTO */
    static integer bclipi, fclipi;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvwr3_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), chkinq_(char *, integer 
	    *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, xyclpi, opwkid;
    static real vwcplm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_();
#endif /* NO_PROTO */
    static integer numowk;
#ifndef NO_PROTO
    extern /* Subroutine */ int tstign_(logical *), setrvs_(char *, real *, 
	    integer *, ftnlen), rsvtip_(integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int tstign_(), setrvs_(), rsvtip_();
#endif /* NO_PROTO */
    static real vwmpmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *), rupost_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk (), rupost_();
#endif /* NO_PROTO */
    static real vwormt[16]	/* was [4][4] */;

/*  E02054 tests the handling of error number 54 */
/* control flag */
/*                conditionally  always */
/* regeneration flag */
/* text precision */
/* clipping indicator */
/*                noclip      clip */
/* modification mode */
/* relative input priority */
/* deferring model */
    s_copy(errchr_1.curcon, "the specified workstation is not open", 200L, 
	    37L);
    setvs_("54,3", errinf_1.experr, &errinf_1.expsiz, 4L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
/*   generate errors */
    rclwk_(&globnu_1.wkid);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rrst_(&globnu_1.wkid, &c__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    ruwk_(&globnu_1.wkid, &c__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rstxr_(&globnu_1.wkid, &c__1, &c__1, &c__0, &c_b13, &c_b14, &c__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    setvs_("1", colia, &isiz, 1L);
    rspar_(&globnu_1.wkid, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, 
	    colia);
    setrvs_("1.,0.,0.", cspec, &isiz, 8L);
    rscr_(&globnu_1.wkid, &c__1, &c__3, cspec);
    rshrm_(&globnu_1.wkid, &c__0);
    idmat_(&c__4, vwormt);
    idmat_(&c__4, vwmpmt);
    setrvs_("0.,1.,0.,1.,0.,1.", vwcplm, &isiz, 17L);
    xyclpi = 1;
    bclipi = 1;
    fclipi = 1;
    rsvwr3_(&globnu_1.wkid, &c__1, vwormt, vwmpmt, vwcplm, &xyclpi, &bclipi, &
	    fclipi);
    rsvtip_(&globnu_1.wkid, &c__1, &c__1, &c__0);
    nopst (&c__101);
    rupost_(&globnu_1.wkid, &c__101);
    L__1 = streq_("OCO*", 4L);
    tstign_(&L__1);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    i__1 = globnu_1.wkid + 1;
    rrst_(&i__1, &c__1);
    nqopwk (&c__1, &errind, &numowk, &opwkid);
    chkinq_("pqopwk", &errind, 6L);
    L__1 = streq_("OO**", 4L) && numowk == 1 && opwkid == globnu_1.wkid;
    tstign_(&L__1);
    i__1 = globnu_1.wkid + 1;
    rsdus_(&i__1, &c__0, &c__0);
    i__1 = globnu_1.wkid + 1;
    rspar_(&i__1, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, colia);
    i__1 = globnu_1.wkid + 1;
    rswkw_(&i__1, &c_b52, &c_b13, &c_b52, &c_b13);
    nqopwk (&c__1, &errind, &numowk, &opwkid);
    chkinq_("pqopwk", &errind, 6L);
    L__1 = streq_("OO**", 4L) && numowk == 1 && opwkid == globnu_1.wkid;
    tstign_(&L__1);
    nopst (&c__101);
    i__1 = globnu_1.wkid + 1;
    rpost_(&i__1, &c__101, &c_b13);
    nqopwk (&c__1, &errind, &numowk, &opwkid);
    chkinq_("pqopwk", &errind, 6L);
    L__1 = streq_("OOO*", 4L) && numowk == 1 && opwkid == globnu_1.wkid;
    tstign_(&L__1);
    nclst ();
    nclwk (&globnu_1.wkid);
/*  examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02054_ */

