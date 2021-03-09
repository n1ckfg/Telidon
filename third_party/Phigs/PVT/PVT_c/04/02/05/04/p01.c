/* fort/04/02/05/04/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__100 = 100;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.04/01                        * */
/*  *    TEST TITLE : Simple setting and inquiring          * */
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
    logical L__1;

    /* Local variables */
    static integer dx, dy, dx2, dy2, pai, isc, isr;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer colia[10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical arreq_(integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqpar (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nopwk (
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical arreq_();
    extern /* Subroutine */ int inmsg_(), nqpar (), nqwkc (), nspar (), 
	    nopwk ();
#endif /* NO_PROTO */
    static integer colia2[10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
#else /* NO_PROTO */
    extern logical patavl_();
#endif /* NO_PROTO */
    static integer specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.04/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (! patavl_(&specwt)) {
#ifndef NO_PROTO
	inmsg_("Skipping all tests because pattern interior style is not sup"
		"ported on this workstation.", 87L);
#else /* NO_PROTO */
	inmsg_("Skipping all tests because pattern interior style is not sup\
ported on this workstation.", 87L);
#endif /* NO_PROTO */
	goto L666;
    }
/* setup index #1, colia(3 x 2) starting at col 5, row 5 */
    pai = 1;
    isc = 5;
    isr = 5;
    dx = 3;
    dy = 2;
    colia[404] = 11;
    colia[405] = 21;
    colia[406] = 31;
    colia[504] = 41;
    colia[505] = 41;
    colia[506] = 51;
/*  <set pattern representation> for index #1 */
    nspar (&globnu_1.wkid, &pai, &c__100, &c__100, &isc, &isr, &dx, &dy, 
	    colia);
/*  <inquire pattern representation> for index #1, as set */
    nqpar (&globnu_1.wkid, &pai, &c__0, &c__100, &c__100, &errind, &dx2, &dy2,
	     colia2);
    chkinq_("pqpar", &errind, 5L);
    setmsg_("2 5", "Pattern attributes should be returned as set.", 3L, 45L);
    L__1 = errind == 0 && dx2 == dx && dy2 == dy && arreq_(&c__100, &c__100, &
	    isc, &isr, &dx, &dy, colia, colia2);
    ifpf_(&L__1);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

