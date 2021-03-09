/* fort/04/03/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__10 = 10;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b25 = .5f;
#else /* NO_PROTO */
static real c_b25 = (float).5;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.03/02                           * */
/*  *    TEST TITLE : Set and inquire HLHSR mode            * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real xp[2] = { 0.f,1.f };
    static real yp[2] = { 0.f,1.f };
#else /* NO_PROTO */
    static real xp[2] = { (float)0.,(float)1. };
    static real yp[2] = { (float)0.,(float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
    static integer i, val;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ifpf_(
	    logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ifpf_();
#endif /* NO_PROTO */
    static integer hrmd;
#ifndef NO_PROTO
    extern /* Subroutine */ int nuwk (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nuwk ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, idum8, 
	    idum9, idum10, idum11;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nclst (void), nqhrm (
	    integer *, integer *, integer *, integer *, integer *), nshrm (
	    integer *, integer *), nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *), nsdus (integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), nopst (
	    integer *), npost (integer *, integer *, real *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), nclst (), 
	    nqhrm (), nshrm (), nqdus (), nsdus (), nopwk (), nopst (), 
	    npost (), chkinq_();
#endif /* NO_PROTO */
    static integer update, errind, orgmod, curmod, reqmod, nummod, dynmod, 
	    specwt, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqhrmf (integer *, 
	    integer *, integer *, integer *, integer *), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqdswa (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqhrmf (), setmsg_(), nqdswa (), 
	    xpopph_();
#endif /* NO_PROTO */
    static integer surfmt;

/*  Declare program-specific variables */
/* display surface empty */
/* dynamic modification */
/* regeneration flag */
/* update state */
/* deferral mode */
/* modification mode */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.03.03/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* get this workstation type */
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* <inquire HLHSR facilities> to determine */
/*  nummod = number of available HLHSR modes */
/* in Fortran: - get lstmod, list of HLHSR modes, one element at a time */

/*        use:   hrmd = nth element of list */
    nqhrmf (&specwt, &c__0, &errind, &nummod, &idum3);
    chkinq_("pqhrmf", &errind, 6L);
/* <inquire HLHSR mode> to determine */
/*  orgmod = original current HLHSR mode */
    update = -6;
    orgmod = -6;
    reqmod = -6;
    nqhrm (&globnu_1.wkid, &errind, &update, &orgmod, &reqmod);
    chkinq_("pqhrm", &errind, 5L);
/* find different value for HLHSR mode */
    val = 0;
    i__1 = nummod;
    for (i = 1; i <= i__1; ++i) {
	nqhrmf (&specwt, &i, &errind, &idum3, &hrmd);
	chkinq_("pqhrmf", &errind, 6L);
	if (hrmd != orgmod) {
	    val = hrmd;
	    goto L150;
	}
/* L100: */
    }
L150:
/*  <set display update state> to WAIT, UWOR to allow */
/*     testing of hlhsr update status. */
    nsdus (&globnu_1.wkid, &c__4, &c__1);
/*  <set HLHSR mode> to val */
    nshrm (&globnu_1.wkid, &val);
    update = -66;
    curmod = -66;
    reqmod = -66;
/*  <inquire HLHSR mode> to determine */
/*     update = HLHSR update state */
/*     curmod = current HLHSR mode */
/*     reqmod = requested HLHSR mode */
    nqhrm (&globnu_1.wkid, &errind, &update, &curmod, &reqmod);
    chkinq_("pqhrm", &errind, 5L);
    setmsg_("4 5", "The requested HLHSR mode should be returned as set.", 3L, 
	    51L);
    L__1 = reqmod == val;
    ifpf_(&L__1);
/*  <inquire dynamics of workstation attributes> to determine */
/*     dynmod = dynamic modification entry for HLHSR mode */
    nqdswa (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &idum7, &idum8, &idum9, &idum10, &idum11, &dynmod);
    chkinq_("pqdswa", &errind, 6L);
/*  Surface should be empty */
    nqdus (&globnu_1.wkid, &errind, &idum1, &idum2, &surfmt, &idum3);
    chkinq_("pqdus", &errind, 5L);
    if (surfmt != 1) {
	inmsg_("Skipping surface-empty test.", 28L);
	goto L500;
    }
    if (dynmod == 1) {
#ifndef NO_PROTO
	setmsg_("5 6", "If the dynamic modification entry for HLHSR mode is "
		"IMM and the display surface is EMPTY, then new values should"
		" be set for current HLHSR mode and the HLHSR update state sh"
		"ould be NOTPENDING.", 3L, 191L);
#else /* NO_PROTO */
	setmsg_("5 6", "If the dynamic modification entry for HLHSR mode is \
IMM and the display surface is EMPTY, then new values should be set for curr\
ent HLHSR mode and the HLHSR update state should be NOTPENDING.", 3L, 191L);
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	setmsg_("5 6", "If the dynamic modification entry for HLHSR mode is "
		"not IMM and the display surface is EMPTY, then new values sh"
		"ould be set for current HLHSR mode and the HLHSR update stat"
		"e should be NOTPENDING.", 3L, 195L);
#else /* NO_PROTO */
	setmsg_("5 6", "If the dynamic modification entry for HLHSR mode is \
not IMM and the display surface is EMPTY, then new values should be set for \
current HLHSR mode and the HLHSR update state should be NOTPENDING.", 3L, 
		195L);
#endif /* NO_PROTO */
    }
    L__1 = update == 0 && curmod == val;
    ifpf_(&L__1);
/*  Cause surface to be NOT EMPTY: */
    nopst (&c__10);
    npl (&c__2, xp, yp);
    nclst ();
    npost (&globnu_1.wkid, &c__10, &c_b25);
/*  <set HLHSR mode> to orgmod */
    nshrm (&globnu_1.wkid, &orgmod);
/*  <update workstation> to force orgmod to be current */
/*  and screen to be non-empty */
    nuwk (&globnu_1.wkid, &c__1);
/*  Surface should be non-empty */
    nqdus (&globnu_1.wkid, &errind, &idum1, &idum2, &surfmt, &idum3);
    chkinq_("pqdus", &errind, 5L);
    if (surfmt != 0) {
	inmsg_("Skipping surface-not-empty test.", 32L);
	goto L666;
    }
/*  <set HLHSR mode> to val */
    nshrm (&globnu_1.wkid, &val);
    update = -66;
    curmod = -66;
    reqmod = -66;
/*  <inquire HLHSR mode> to determine */
/*     update = HLHSR update state */
/*     curmod = current HLHSR mode */
/*     reqmod = requested HLHSR mode */
    nqhrm (&globnu_1.wkid, &errind, &update, &curmod, &reqmod);
    chkinq_("pqhrm", &errind, 5L);
/*  non_empty_test: */
L500:
    if (dynmod == 1) {
#ifndef NO_PROTO
	setmsg_("5 6", "If the dynamic modification entry for HLHSR mode is "
		"IMM and the display surface is not EMPTY, then new values sh"
		"ould be set for current HLHSR mode and the HLHSR update stat"
		"e should be NOTPENDING.", 3L, 195L);
#else /* NO_PROTO */
	setmsg_("5 6", "If the dynamic modification entry for HLHSR mode is \
IMM and the display surface is not EMPTY, then new values should be set for \
current HLHSR mode and the HLHSR update state should be NOTPENDING.", 3L, 
		195L);
#endif /* NO_PROTO */
	L__1 = update == 0 && curmod == val;
	ifpf_(&L__1);
    } else {
	if (reqmod != curmod) {
#ifndef NO_PROTO
	    setmsg_("5 7", "If the current HLHSR mode differs from that requ"
		    "ested by <set HLHSR mode>, then the current HLHSR mode s"
		    "hould be unchanged and the HLHSR update state should be "
		    "PENDING.", 3L, 168L);
#else /* NO_PROTO */
	    setmsg_("5 7", "If the current HLHSR mode differs from that requ\
ested by <set HLHSR mode>, then the current HLHSR mode should be unchanged a\
nd the HLHSR update state should be PENDING.", 3L, 168L);
#endif /* NO_PROTO */
	    L__1 = update == 1 && curmod == orgmod;
	    ifpf_(&L__1);
	}
    }
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

