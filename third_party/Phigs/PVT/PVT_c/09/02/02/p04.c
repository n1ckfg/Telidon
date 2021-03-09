/* fort/09/02/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.02/04                           * */
/*  *    TEST TITLE : Error indicator = 59                  * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
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
    static integer ia5[5];
    static real ra9[9];
    static integer ia10[10], ib10[10];
    static real ra10[10];
    static char cdum[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int rqcf_(integer *, integer *, integer *, 
	    integer *, integer *, real *), rqif_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rqdp_(integer *, integer *, integer *), rqcr_(integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *),
	     rqir_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqcf_(), rqif_(), rqdp_(), rqcr_(), rqir_();
#endif /* NO_PROTO */
    static integer ival1, ival2, ival3, idum1, idum2, idum3, ival4, ival5, 
	    ival6, ival7, ival8;
    static real rval1, rval2, rval3, rval4, rval5;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqcmd_(integer *, integer *, 
	    integer *), rqanf_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqcmd_(), rqanf_();
#endif /* NO_PROTO */
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), rqgdp_(integer *, 
	    integer *, integer *, integer *, integer *), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), rqgdp_(), nclwk ();
#endif /* NO_PROTO */
    static integer twkid;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqplf_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nqwkc (integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqplf_(), nqwkc ();
#endif /* NO_PROTO */
    static integer nwkno;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqdus_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *), rqpmr_(integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), setvs_(char *, integer *, integer *
	    , ftnlen), rqtxf_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *, real *
	    , real *, integer *), rqtxr_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    rqegd3_(integer *, integer *, integer *, integer *, integer *), 
	    rqeedi_(integer *, integer *, integer *, integer *, integer *), 
	    chkinq_(char *, integer *, ftnlen), rqcmdf_(integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqdus_(), nopwk (), rqpmr_(), setvs_(), 
	    rqtxf_(), rqtxr_(), rqegd3_(), rqeedi_(), chkinq_(), rqcmdf_();
#endif /* NO_PROTO */
    static integer tconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqepai_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqepai_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqepli_(integer *, 
	    integer *, integer *, integer *, integer *), rqwkcl_(integer *, 
	    integer *, integer *), rqddus_(integer *, integer *, integer *, 
	    integer *), rqetxi_(integer *, integer *, integer *, integer *, 
	    integer *), rqivft_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), xpopph_(integer *, 
	    integer *), rqpedr_(integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), rqppmr_(integer *, integer *, 
	    integer *, integer *, real *, integer *), rqegse_(integer *, 
	    integer *, integer *, integer *, integer *), rqwksl_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), rqpost_(integer *, integer *, 
	    integer *, integer *, integer *, real *), rqdstr_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     multws_(integer *, char *, integer *, integer *, integer *, 
	    integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqepli_(), rqwkcl_(), rqddus_(), 
	    rqetxi_(), rqivft_(), xpopph_(), rqpedr_(), rqppmr_(), rqegse_(), 
	    rqwksl_(), rqpost_(), rqdstr_(), multws_();
#endif /* NO_PROTO */
    static integer twtype;

    initgl_("09.02.02/04", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified workstation does not have output "
	    "capabilities", 200L, 59L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified workstation does not have output \
capabilities", 200L, 59L);
#endif /* NO_PROTO */
    setvs_("59", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    multws_(&c__0, "in", &nwkno, &idum1, &idum2, &idum3, cdum, 2L, 1L);
    if (nwkno == 0) {
#ifndef NO_PROTO
	inmsg_("There is no workstation without output capabilities, this te"
		"st is skipped.", 74L);
#else /* NO_PROTO */
	inmsg_("There is no workstation without output capabilities, this te\
st is skipped.", 74L);
#endif /* NO_PROTO */
	goto L666;
    }
    i__1 = (nwkno + 1) / 2;
    multws_(&i__1, "in", &idum1, &twkid, &tconid, &twtype, owcat, 2L, 1L);
    nopwk (&twkid, &tconid, &twtype);
    nqwkc (&twkid, &errind, &tconid, &twtype);
    chkinq_("pqwkc", &errind, 5L);
    rqpost_(&twkid, &c__0, &errind, &ival1, &ival2, &rval1);
    rqdus_(&twkid, &errind, &ival1, &ival2, &ival3, &ival4);
    rqepli_(&twkid, &c__1, &errind, &ival1, &ival2);
    rqpmr_(&twkid, &c__1, &c__1, &errind, &ival1, &rval1, &ival2);
    rqetxi_(&twkid, &c__0, &errind, &ival1, &ival2);
    rqtxr_(&twkid, &c__1, &c__0, &errind, &ival1, &ival2, &rval1, &rval2, &
	    ival3);
    rqir_(&twkid, &c__1, &c__1, &errind, &ival1, &ival2, &ival3);
    rqeedi_(&twkid, &c__0, &errind, &ival1, &ival2);
    rqepai_(&twkid, &c__0, &errind, &ival1, &ival2);
    rqcmd_(&twkid, &errind, &ival1);
    rqcr_(&twkid, &c__1, &c__10, &c__1, &errind, &ival1, ra10);
    rqivft_(&twkid, &c__10, &c__10, &errind, &ival1, ia10, &ival2, ib10);
    rqwkcl_(&twtype, &errind, &ival1);
    rqddus_(&twtype, &errind, &ival1, &ival2);
    rqplf_(&twtype, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &rval2, &
	    rval3, &ival4);
    rqppmr_(&twtype, &c__1, &errind, &ival1, &rval1, &ival2);
    rqtxf_(&twtype, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &rval1, &
	    rval2, &ival5, &rval4, &rval5, &ival6);
    rqanf_(&twkid, &c__0, &errind, &ival1, &ival2, &ival3, &rval1, &rval2);
    rqif_(&twkid, &c__0, &c__0, &errind, &ival1, &ival2, &ival3, &ival4, &
	    ival5);
    rqpedr_(&twtype, &c__1, &errind, &ival1, &ival2, &rval1, &ival3);
    rqcmdf_(&twtype, &c__1, &errind, &ival1, &ival2, &ival3);
    rqcf_(&twtype, &errind, &ival1, &ival2, &ival3, ra9);
    rqegd3_(&twtype, &c__0, &errind, &ival1, &ival2);
    rqgdp_(&twtype, &c__1, &errind, &ival1, ia5);
    rqegse_(&twtype, &c__0, &errind, &ival1, &ival2);
    rqdp_(&twtype, &errind, &ival1);
    rqwksl_(&twtype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5, &ival6, 
	    &ival7, &ival8);
    rqdstr_(&twtype, &errind, &ival1, &ival2, &ival3, &ival4, &ival5);
    nclwk (&twkid);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

