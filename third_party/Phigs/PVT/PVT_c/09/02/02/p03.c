/* fort/09/02/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.02/03                           * */
/*  *    TEST TITLE : Error indicator = 57                  * */
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
    static real ra4[4], rb4[4], rc4[4], rd4[6], ra6[6], rb6[6], rc6[6], rd6[6]
	    , ra44[16]	/* was [4][4] */, rb44[16]	/* was [4][4] */;
    static char cdum[1];
    static integer ival1, ival2, ival3, idum1, idum2, idum3, ival4, ival5;
    static real rval1, rval2, rval3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static integer twkid, nwkmi;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), rqhrm_(integer *, integer *, integer *, integer *, 
	    integer *), rqdsp_(integer *, integer *, integer *, real *, real *
	    , integer *, integer *), nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), rqvwf_(integer *, 
	    integer *, integer *), rqwkt_(integer *, integer *, integer *, 
	    real *, real *, real *, real *), rqvwr_(integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    , integer *, integer *), rqdsp3_(integer *, integer *, integer *, 
	    real *, real *, real *, integer *, integer *, integer *), rqwkt3_(
	    integer *, integer *, integer *, real *, real *, real *, real *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), rqhrm_(), rqdsp_(), nopwk (), 
	    setvs_(), rqvwf_(), rqwkt_(), rqvwr_(), rqdsp3_(), rqwkt3_(), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer tconid, errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqhrif_(integer *, 
	    integer *, integer *, integer *, integer *), rqevwi_(integer *, 
	    integer *, integer *, integer *, integer *), xpopph_(integer *, 
	    integer *), multws_(integer *, char *, integer *, integer *, 
	    integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqhrif_(), rqevwi_(), xpopph_(), 
	    multws_();
#endif /* NO_PROTO */
    static integer twtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqpvwr_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqpvwr_();
#endif /* NO_PROTO */

    initgl_("09.02.02/03", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the specified workstation is of category MI", 
	    200L, 43L);
    setvs_("57", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    multws_(&c__0, "n", &nwkmi, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    if (nwkmi == 0) {
#ifndef NO_PROTO
	inmsg_("There is no workstation with category MI, this test is skipp"
		"ed.", 63L);
#else /* NO_PROTO */
	inmsg_("There is no workstation with category MI, this test is skipp\
ed.", 63L);
#endif /* NO_PROTO */
	goto L666;
    }
    i__1 = (nwkmi + 1) / 2;
    multws_(&i__1, "n", &idum1, &twkid, &tconid, &twtype, owcat, 1L, 1L);
    nopwk (&twkid, &tconid, &twtype);
    nqwkc (&twkid, &errind, &tconid, &twtype);
    chkinq_("pqwkc", &errind, 5L);
    rqevwi_(&twkid, &c__0, &errind, &ival1, &ival2);
    rqvwr_(&twkid, &c__1, &c__0, &errind, &ival1, ra44, rb44, ra6, &ival3, &
	    ival4, &ival5);
    rqhrm_(&twkid, &errind, &ival1, &ival2, &ival3);
    rqwkt3_(&twkid, &errind, &ival1, ra6, rb6, rc6, rd6);
    rqwkt_(&twkid, &errind, &ival1, ra4, rb4, rc4, rd4);
    rqdsp3_(&twtype, &errind, &ival1, &rval1, &rval2, &rval3, &ival2, &ival3, 
	    &ival4);
    rqdsp_(&twtype, &errind, &ival1, &rval1, &rval2, &ival2, &ival3);
    rqhrif_(&twtype, &c__0, &errind, &ival1, &ival2);
    rqvwf_(&twtype, &errind, &ival1);
    rqpvwr_(&twtype, &c__1, &errind, ra44, rb44, ra6, &ival1, &ival2, &ival3);

    nclwk (&twkid);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

