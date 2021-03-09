/* fort//09/01/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__11 = 11;
static integer c__24 = 24;
#ifndef NO_PROTO
static real c_b38 = 1.f;
#else /* NO_PROTO */
static real c_b38 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b53 = 0.f;
#else /* NO_PROTO */
static real c_b53 = (float)0.;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b102 = .5f;
static real c_b152 = .1f;
#else /* NO_PROTO */
static real c_b102 = (float).5;
static real c_b152 = (float).1;
#endif /* NO_PROTO */
static integer c__33 = 33;
static integer c__100 = 100;
static integer c__200 = 200;
#ifndef NO_PROTO
static real c_b192 = .3f;
static real c_b193 = .7f;
#else /* NO_PROTO */
static real c_b192 = (float).3;
static real c_b193 = (float).7;
#endif /* NO_PROTO */
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/e01001                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e01001_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01001_(useprm)
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
#ifndef NO_PROTO
    extern /* Subroutine */ int ropph_(integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    enderr_(void), esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ropph_();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), enderr_(), esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E01001 tests the handling of error number 1: function requires */
/*  state (PHCL,WSCL,STCL,ARCL). */
    s_copy(errchr_1.curcon, "PHIGS is open", 200L, 13L);
    setvs_("1", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    esetup_(useprm);
    ropph_(&globnu_1.errfil, &globnu_1.memun);
    L__1 = streq_("O***", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01001_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/c01002                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int c01002_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01002_(useprm)
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
    static integer mode;
#ifndef NO_PROTO
    extern /* Subroutine */ int rdsn_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rdsn_();
#endif /* NO_PROTO */
    static integer dsnt, arccr;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedm_();
#endif /* NO_PROTO */
    static integer retcr;
#ifndef NO_PROTO
    extern /* Subroutine */ int remst_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int ropwk_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), ifphcl_(integer *), 
	    enderr_(void);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int tstign_(logical *), rcstir_(integer *, 
	    integer *), roparf_(integer *, integer *), rscnrs_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int remst_();
    extern logical streq_();
    extern /* Subroutine */ int ropwk_(), setvs_(), ifphcl_(), enderr_();
    extern integer rndint_();
    extern /* Subroutine */ int tstign_(), rcstir_(), roparf_(), rscnrs_();
#endif /* NO_PROTO */

/*  C01002 tests the handling of error number 2: function requires */
/*  state (PHOP,*,*,*). */
/*  edit mode */
/*  reference handling flag */
/*  conflict resolution maintain,  abandon,    update */
    ifphcl_(useprm);
    setvs_("2", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    ropwk_(&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    mode = rndint_(&c__0, &c__1);
    rsedm_(&mode);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    remst_(&c__101);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    dsnt = rndint_(&c__0, &c__1);
    rdsn_(&c__101, &dsnt);
    rcstir_(&c__101, &c__102);
    arccr = rndint_(&c__0, &c__2);
    retcr = rndint_(&c__0, &c__2);
    roparf_(&c__11, &c__24);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rscnrs_(&arccr, &retcr);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01002_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/e01003                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    rspmr_(&globnu_1.wkid, &c__1, &c__1, &c_b38, &c__1);
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
    rswkw_(&globnu_1.wkid, &c_b53, &c_b38, &c_b53, &c_b38);
    L__1 = streq_("OC**", 4L);
    tstign_(&L__1);
    rswkv_(&globnu_1.wkid, &c_b53, &c_b38, &c_b53, &c_b38);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/c01003                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    rsplr_(&globnu_1.wkid, &c__1, &c__1, &c_b38, &c__0);
    rsedr_(&globnu_1.wkid, &c__1, &c__1, &c__1, &c_b38, &c__0);
    setvs_("2,3,5", inc, &isiz, 5L);
    setvs_("6", exc, &isiz, 1L);
    rshlft_(&globnu_1.wkid, &c__3, inc, &c__1, exc);
    rscmd_(&globnu_1.wkid, &c__1);
    idmat_(&c__3, xfrmt);
    setrvs_("0.,1.,0.,1.", limt, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, xfrmt, xfrmt, limt, &c__1);
    rswkw_(&globnu_1.wkid, &c_b53, &c_b38, &c_b53, &c_b38);
    rswkv_(&globnu_1.wkid, &c_b53, &c_b38, &c_b53, &c_b38);
    rpost_(&globnu_1.wkid, &c__101, &c_b102);
    rupast_(&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01003_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/e01004                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e01004_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01004_(useprm)
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
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int rclph_(void), nclwk (integer *), nclst (void);

    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    nclarf (integer *), enderr_(void), avarnm_(integer *), esetup_(
	    integer *), tstign_(logical *), noparf (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rclph_(), nclwk (), nclst ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nopst (), nclarf (), 
	    enderr_(), avarnm_(), esetup_(), tstign_(), noparf ();
#endif /* NO_PROTO */

/*  E01004 tests the handling of error number 4: function requires */
/*  state (PHOP,WSCL,STCL,ARCL) when PHIGS is open. */
    setvs_("4", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    s_copy(errchr_1.curcon, "PHIGS is open and a workstation is open", 200L, 
	    39L);
    rclph_();
    L__1 = streq_("OO**", 4L);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    nopst (&c__101);
    s_copy(errchr_1.curcon, "PHIGS is open and a structure is open", 200L, 
	    37L);
    rclph_();
    L__1 = streq_("OCO*", 4L);
    tstign_(&L__1);
    nclst ();
    avarnm_(&arnm);
    noparf (&c__11, &arnm);
    s_copy(errchr_1.curcon, "PHIGS is open and an archive file is open", 200L,
	     41L);
    rclph_();
    L__1 = streq_("OCCO", 4L);
    tstign_(&L__1);
    nclarf (&c__11);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01004_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/c01004                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int c01004_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01004_(useprm)
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
#ifndef NO_PROTO
    extern /* Subroutine */ int rclph_(void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    ifphcl_(integer *), enderr_(void), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rclph_();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), ifphcl_(), enderr_(), tstign_();
#endif /* NO_PROTO */

/*  C01004 tests the handling of error number 4: function requires */
/*  state (PHOP,WSCL,STCL,ARCL) when PHIGS is closed. */
    ifphcl_(useprm);
    setvs_("4", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    rclph_();
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01004_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/e01005                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    rtx_(&c_b53, &c_b102, "TEXT", 4L);
    setrvs_("0.,0.5,0.5,0.", pxa, &isiz, 13L);
    setrvs_("0.,0.,0.5,0.5", pya, &isiz, 13L);
    rfa_(&n, pxa, pya);
    rspli_(&c__1);
    rsln_(&c__1);
    rspmci_(&c__1);
    rschxp_(&c_b38);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/c01005                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    ratr_(&c_b53, &c_b53, &c_b152, &c_b152, "annotation-text", 15L);
    npl = 1;
    ixa[0] = 4;
    setrvs_("0.,0.4,0.4,0.", pxa, &isiz, 13L);
    setrvs_("0.,0.,0.4,0.4", pya, &isiz, 13L);
    rfas_(&npl, ixa, pxa, pya);
    rsii_(&c__1);
    rsmksc_(&c_b38);
    rstxfn_(&c__1);
    rsans_(&c__1);
    rsparf_(&c_b53, &c_b53);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/e01006                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e01006_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01006_(useprm)
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
    static integer opid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), ropst_(integer *), chkinq_(char *, integer *, 
	    ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst (), ropst_(), chkinq_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */

/*  E01006 tests the handling of error number 6: function requires */
/*  state (PHOP,*,STCL,*) when PHIGS is open. */
/* structure status indicator */
/* open-structure status */
    s_copy(errchr_1.curcon, "PHIGS is open and a structure is open", 200L, 
	    37L);
    setvs_("6", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopst (&c__101);
    ropst_(&c__102);
    nqopst (&errind, &opstat, &opid);
    chkinq_("pqopst", &errind, 6L);
    L__1 = streq_("O*O*", 4L) && opstat == 1 && opid == 101;
    tstign_(&L__1);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01006_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/c01006                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int c01006_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01006_(useprm)
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
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    ropst_(integer *), ifphcl_(integer *), enderr_(void), tstign_(
	    logical *);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), ropst_(), ifphcl_(), enderr_(), 
	    tstign_();
#endif /* NO_PROTO */

/*  C01006 tests the handling of error number 6: function requires */
/*  state (PHOP,*,STCL,*) when PHIGS is closed. */
    ifphcl_(useprm);
    setvs_("6", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    ropst_(&c__101);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01006_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/e01007                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e01007_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01007_(useprm)
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
    static integer n, ol;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static integer arid, stid, paths[20]	/* was [2][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrsid_(integer *, integer *, integer *, 
	    integer *), nclst (void), rarst_(integer *, integer *, integer *),
	     rrast_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    nexst (integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), rclarf_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrsid_(), nclst (), rarst_(), rrast_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), nexst (), setvs_(), nopst (), 
	    rclarf_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void), rrepan_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rdstar_(integer *, integer *, integer *), esetup_(
	    integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_(), rrepan_(), rdstar_(), esetup_(), 
	    tstign_();
#endif /* NO_PROTO */
    static integer apthsz, stlist[2];

/*  E01007 tests the handling of error number 7: function requires */
/*  state (PHOP,*,*,AROP), when PHIGS is open. */
/*  path order */
    s_copy(errchr_1.curcon, "PHIGS is open but no archive file is open", 200L,
	     41L);
    setvs_("7,404", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    nopst (&c__100);
    ntx (&c_b102, &c_b102, "TEXT", 4L);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    ntx (&c_b192, &c_b193, "TEXT", 4L);
    nclst ();
    arid = 11;
    stid = 101;
    stlist[0] = 100;
    stlist[1] = 101;
    pathod = 0;
    pathdp = 0;
    rclarf_(&arid);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rarst_(&arid, &c__2, stlist);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rrsid_(&arid, &c__2, &n, stlist);
    rrest_(&arid, &c__2, stlist);
    rrast_(&arid);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rrepan_(&arid, &stid, &pathod, &pathdp, &c__10, &c__0, &ol, &apthsz, 
	    paths);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rdstar_(&arid, &c__2, stlist);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01007_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/c01007                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int c01007_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01007_(useprm)
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
    static integer n, ol, arid, stid, paths[20]	/* was [2][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrsid_(integer *, integer *, integer *, 
	    integer *), rarst_(integer *, integer *, integer *), rrast_(
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), ifphcl_(integer *), 
	    rclarf_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrsid_(), rarst_(), rrast_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), setvs_(), ifphcl_(), rclarf_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void), rrepan_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rdstar_(integer *, integer *, integer *), tstign_(
	    logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_(), rrepan_(), rdstar_(), tstign_();
#endif /* NO_PROTO */
    static integer apthsz, stlist[2];

/*  C01007 tests the handling of error number 7: function requires */
/*  state (PHOP,*,*,AROP), when PHIGS is closed. */
/*  path order */
    ifphcl_(useprm);
    setvs_("7,404", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    arid = 11;
    stid = 100;
    stlist[0] = 100;
    stlist[1] = 101;
    pathod = 0;
    pathdp = 0;
    rclarf_(&arid);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rarst_(&arid, &c__2, stlist);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rrsid_(&arid, &c__2, &n, stlist);
    rrest_(&arid, &c__2, stlist);
    rrast_(&arid);
    rrepan_(&arid, &stid, &pathod, &pathdp, &c__10, &c__0, &ol, &apthsz, 
	    paths);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rdstar_(&arid, &c__2, stlist);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01007_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.01/ifphcl                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ifphcl_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int ifphcl_(useprm)
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
#ifndef NO_PROTO
    extern /* Subroutine */ int nclph (void), esetup_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclph (), esetup_();
#endif /* NO_PROTO */

/*  IFPHCL initializes things for the special case where error */
/*  handling is to be tested in the state where PHIGS is closed. */
/*  This requires special handling, since ordinarily the error */
/*  file will not be available for writing. */
/*  Input parameters: */
/*    USEPRM : Handling mode: 1 for user, 2 for system */
    s_copy(errchr_1.curcon, "PHIGS is closed", 200L, 15L);
/*  add 2 to "normal" USRERR value to signify PHCL */
    i__1 = *useprm + 2;
    esetup_(&i__1);
    nclph ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ifphcl_ */

