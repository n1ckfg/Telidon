/* fort/09/01/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b33 = 1.f;
static real c_b34 = .1f;
#else /* NO_PROTO */
static real c_b33 = (float)1.;
static real c_b34 = (float).1;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b72 = 0.f;
static real c_b97 = .4f;
static real c_b98 = .6f;
static real c_b99 = .5f;
static real c_b100 = .7f;
#else /* NO_PROTO */
static real c_b72 = (float)0.;
static real c_b97 = (float).4;
static real c_b98 = (float).6;
static real c_b99 = (float).5;
static real c_b100 = (float).7;
#endif /* NO_PROTO */
static integer c__100 = 100;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02052                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02052_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02052_(useprm)
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
    static integer ix, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqewk (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int ropwk_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqewk ();
    extern logical streq_();
    extern /* Subroutine */ int ropwk_(), setvs_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer nmtype, thisty, mxtype;

/*  E02052 tests the handling of error number 52 */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the workstation type is not recognized by the i"
	    "mplementation", 200L, 60L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the workstation type is not recognized by the i\
mplementation", 200L, 60L);
#endif /* NO_PROTO */
    setvs_("52,55", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nqewk (&c__1, &errind, &nmtype, &mxtype);
    chkinq_("pqewk", &errind, 5L);
    i__1 = nmtype;
    for (ix = 1; ix <= i__1; ++ix) {
	nqewk (&ix, &errind, &idum1, &thisty);
	chkinq_("pqewk", &errind, 5L);
	if (thisty > mxtype) {
	    thisty = mxtype;
	}
/* L50: */
    }
    i__1 = mxtype + 1;
    ropwk_(&globnu_1.wkid, &globnu_1.conid, &i__1);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02052_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02053                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02053_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02053_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char cdum[1];
    static integer idum1, idum2, idum3;
    static logical ignok;
    static integer owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    ropwk_(integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), ropwk_(), setvs_();
#endif /* NO_PROTO */
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, nwkall, opwkid;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer numowk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk ();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

/*  E02053 tests the handling of error number 53 */
    s_copy(errchr_1.curcon, "the specified workstation identifier is in use", 
	    200L, 46L);
    setvs_("53", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
/*  **** Generate errors */
    ignok = TRUE_;
    multws_(&c__0, "a", &nwkall, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    i__1 = nwkall;
    for (ix = 1; ix <= i__1; ++ix) {
	multws_(&ix, "a", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
	nopwk (&owkid, &oconid, &owtype);
	ropwk_(&owkid, &oconid, &owtype);
	nqopwk (&c__1, &errind, &numowk, &opwkid);
	chkinq_("pqopwk", &errind, 6L);
	if (! (streq_("OO**", 4L) && numowk == 1 && opwkid == owkid)) {
	    ignok = FALSE_;
	}
	nclwk (&owkid);
/* L150: */
    }
    tstign_(&ignok);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02053_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02054                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    rstxr_(&globnu_1.wkid, &c__1, &c__1, &c__0, &c_b33, &c_b34, &c__1);
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
    rswkw_(&i__1, &c_b72, &c_b33, &c_b72, &c_b33);
    nqopwk (&c__1, &errind, &numowk, &opwkid);
    chkinq_("pqopwk", &errind, 6L);
    L__1 = streq_("OO**", 4L) && numowk == 1 && opwkid == globnu_1.wkid;
    tstign_(&L__1);
    nopst (&c__101);
    i__1 = globnu_1.wkid + 1;
    rpost_(&i__1, &c__101, &c_b33);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02056                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02056_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02056_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02056 tests the handling of error number 56. */
#ifndef NO_PROTO
    setmsg_("6", "Test for error 56 (writing to workstation not of category "
	    "MO) not yet available.", 1L, 80L);
#else /* NO_PROTO */
    setmsg_("6", "Test for error 56 (writing to workstation not of category \
MO) not yet available.", 1L, 80L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02056_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02057                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02057_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02057_(useprm)
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
    extern /* Subroutine */ int etr_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr_();
#endif /* NO_PROTO */
    static char cdum[1];
    static integer isiz, idum1, idum2, idum3, owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static integer nwkmi;
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), rswkv_(integer *, 
	    real *, real *, real *, real *), rswkw_(integer *, real *, real *,
	     real *, real *), rsvwr_(integer *, integer *, real *, real *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), rswkv_(), rswkw_(), 
	    rsvwr_();
#endif /* NO_PROTO */
    static real mapmt2[9]	/* was [3][3] */, limit2[6], rotmt2[9]	/* 
	    was [3][3] */;
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvtip_(integer *, integer *, integer *, 
	    integer *), multws_(integer *, char *, integer *, integer *, 
	    integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvtip_(), multws_();
#endif /* NO_PROTO */

/*  E02057 tests the handling of error number 57. */
/* workstation category */
/*  relative input priority */
    s_copy(errchr_1.curcon, "the specified workstation is of category MI", 
	    200L, 43L);
    setvs_("57", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    multws_(&c__0, "n", &nwkmi, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    if (nwkmi == 0) {
#ifndef NO_PROTO
	inmsg_("There is no accessible workstation with category of MI, the "
		"test is skipped.", 76L);
#else /* NO_PROTO */
	inmsg_("There is no accessible workstation with category of MI, the \
test is skipped.", 76L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = rndint_(&c__1, &nwkmi);
    multws_(&i__1, "n", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
/*  **** Generate errors */
    nopwk (&owkid, &oconid, &owtype);
    etr_(&c_b97, &c_b98, mapmt2);
    etr_(&c_b99, &c_b100, rotmt2);
    setrvs_("0.1,0.9,0.2,0.9", limit2, &isiz, 15L);
    rsvwr_(&owkid, &c__1, rotmt2, mapmt2, limit2, &c__0);
    L__1 = streq_("OO**", 4L);
    tstign_(&L__1);
    rsvtip_(&owkid, &c__1, &c__1, &c__1);
    rswkw_(&owkid, &c_b72, &c_b33, &c_b72, &c_b33);
    rswkv_(&owkid, &c_b72, &c_b33, &c_b72, &c_b33);
    nclwk (&owkid);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02057_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02058                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02058_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02058_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02058 tests the handling of error number 58. */
#ifndef NO_PROTO
    setmsg_("8", "Test for error 58 (metafile retrieval from workstation not"
	    " of category MI) not yet available.", 1L, 93L);
#else /* NO_PROTO */
    setmsg_("8", "Test for error 58 (metafile retrieval from workstation not\
 of category MI) not yet available.", 1L, 93L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02058_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02059                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02059_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02059_(useprm)
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
    static integer iin2, iex2;
    static char cdum[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int ruwk_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ruwk_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int rscmd_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rscmd_();
#endif /* NO_PROTO */
    static integer owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), rsedr_(integer *, 
	    integer *, integer *, integer *, real *, integer *), nclwk (
	    integer *), nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    rsplr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    rpost_(integer *, integer *, real *), rstxr_(integer *, integer *,
	     integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), rsedr_(), nclwk (), nclst ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), rsplr_(), setvs_(), nopst (), 
	    rpost_(), rstxr_();
#endif /* NO_PROTO */
    static integer inset2[10], exset2[10], oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    rsivft_(integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int esetup_(), tstign_(), rsivft_();
#endif /* NO_PROTO */
    static integer nwknot, owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

/*  E02059 tests the handling of error number 59. */
/* off/on switch for edge flag and error handling mode */
/* text precision */
/* colour model */
/* workstation category */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the workstation type does not have output capab"
	    "ility", 200L, 52L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the workstation type does not have output capab\
ility", 200L, 52L);
#endif /* NO_PROTO */
    setvs_("59", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "9", 40L, 1L);
    esetup_(useprm);
    multws_(&c__0, "in", &nwknot, &idum1, &idum2, &idum3, cdum, 2L, 1L);
    if (nwknot == 0) {
#ifndef NO_PROTO
	inmsg_("All accessible workstations have output capability. This tes"
		"t is skipped.", 73L);
#else /* NO_PROTO */
	inmsg_("All accessible workstations have output capability. This tes\
t is skipped.", 73L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = rndint_(&c__1, &nwknot);
    multws_(&i__1, "in", &idum1, &owkid, &oconid, &owtype, owcat, 2L, 1L);
/*  **** Generate errors: */
    nopwk (&owkid, &oconid, &owtype);
    ruwk_(&owkid, &c__0);
    rsplr_(&owkid, &c__1, &c__1, &c_b33, &c__1);
    rstxr_(&owkid, &c__1, &c__1, &c__0, &c_b33, &c_b33, &c__0);
    rsedr_(&owkid, &c__1, &c__0, &c__1, &c_b33, &c__0);
    setvs_("1,5,2", inset2, &iin2, 5L);
    setvs_("4", exset2, &iex2, 1L);
    rsivft_(&owkid, &iin2, inset2, &iex2, exset2);
    rscmd_(&owkid, &c__1);
    nopst (&c__101);
    rpost_(&owkid, &c__100, &c_b99);
    L__1 = streq_("OOO*", 4L);
    tstign_(&L__1);
    nclst ();
    nclwk (&owkid);
/*  **** Examine saved errors */
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02059_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02060                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02060_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02060_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02060 tests the handling of error number 60. */
#ifndef NO_PROTO
    setmsg_("10", "Test for error 60 (using pick on workstation not of categ"
	    "ory OUTIN) not yet available.", 2L, 86L);
#else /* NO_PROTO */
    setmsg_("10", "Test for error 60 (using pick on workstation not of categ\
ory OUTIN) not yet available.", 2L, 86L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02060_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02061                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02061_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02061_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), setmsg_();
#endif /* NO_PROTO */

/*  E02061 tests the handling of error number 61. */
#ifndef NO_PROTO
    setmsg_("11", "Test for error 61 (graphical input from workstation not o"
	    "f category OUTIN or INPUT) not yet available.", 2L, 102L);
#else /* NO_PROTO */
    setmsg_("11", "Test for error 61 (graphical input from workstation not o\
f category OUTIN or INPUT) not yet available.", 2L, 102L);
#endif /* NO_PROTO */
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02061_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.02/e02063                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e02063_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02063_(useprm)
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
    static integer ix;
    static char cdum[1];
    static integer idum1, idum2, idum3, idum4, idum5, idum6, owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), inmsg_();
#endif /* NO_PROTO */
    static integer maxwk;
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    ropwk_(integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), ropwk_(), setvs_();
#endif /* NO_PROTO */
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, nwkall;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer nmopwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk ();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

/*  E02063 tests the handling of error number 63. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "it would exceed the maximum number of simultane"
	    "ously open workstations", 200L, 70L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "it would exceed the maximum number of simultane\
ously open workstations", 200L, 70L);
#endif /* NO_PROTO */
    setvs_("63", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "12", 40L, 2L);
    esetup_(useprm);
    multws_(&c__0, "a", &nwkall, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    nqphf (&c__0, &errind, &maxwk, &idum1, &idum2, &idum3, &idum4, &idum5, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
    if (nwkall <= maxwk) {
#ifndef NO_PROTO
	inmsg_("The number of all accessible workstations is less than or eq"
		"ual to maximum number of simultaneously open workstations; t"
		"herefore this test is skipped.", 150L);
#else /* NO_PROTO */
	inmsg_("The number of all accessible workstations is less than or eq\
ual to maximum number of simultaneously open workstations; therefore this te\
st is skipped.", 150L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = maxwk + 1;
    for (ix = 1; ix <= i__1; ++ix) {
	multws_(&ix, "a", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
	if (ix <= maxwk) {
	    nopwk (&owkid, &oconid, &owtype);
	} else {
	    ropwk_(&owkid, &oconid, &owtype);
	}
/* L150: */
    }
    nqopwk (&c__0, &errind, &nmopwk, &idum1);
    chkinq_("pqopwk", &errind, 6L);
    L__1 = streq_("OO**", 4L) && nmopwk == maxwk;
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02063_ */

