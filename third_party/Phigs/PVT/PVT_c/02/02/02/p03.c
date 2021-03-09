/* fort/02/02/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__20 = 20;
static integer c__0 = 0;
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.02/03                           * */
/*  *    TEST TITLE : Generalized structure element         * */
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

    static logical mark[100] = { FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,FALSE_,
	    FALSE_,FALSE_,FALSE_,FALSE_ };

    /* System generated locals */
    integer i__1, i__2, i__3;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, j, k, m, rl, jwk, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer gsel, idum, jdum, intg, plim;
    static real rlar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int ngse (integer *, integer *, char *, ftnlen), 
	    pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ngse (), pass_();
#endif /* NO_PROTO */
    static integer gseid;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer avgse;
    static logical gseok;
#ifndef NO_PROTO
    extern /* Subroutine */ int nprec (integer *, integer *, integer *, real *
	    , integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nprec ();
#endif /* NO_PROTO */
    static integer wkdep, rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nurec (integer *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, integer *, char *, 
	    ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nqewk (integer *, integer *, integer *, 
	    integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nurec ();
    extern integer itrim_();
    extern /* Subroutine */ int nqewk (), nopst ();
#endif /* NO_PROTO */
    static integer ldract;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), chkinq_();
#endif /* NO_PROTO */
    static integer ugseid, lgseim[50];
    static char drindr[80*20];
    static integer errind, intlen, maxgse, wavgse, drinin[50], celtyp, drinsl[
	    50], drotin[50];
    static real drinrl[50];
    static char drotdr[80*20];
    static integer strlen, strarl[50], drotsl[50];
    static real drotrl[50];
    static char drinst[40*50], gsemsg[80];
    static integer worknm;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static char drotst[40*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setmsg_(char *,
	     char *, ftnlen, ftnlen), nqgsef (integer *, integer *, integer *,
	     integer *, integer *), nqcets (integer *, integer *, integer *, 
	    integer *, integer *), nqegse (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setmsg_(), nqgsef (), nqcets (), 
	    nqegse ();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* workstation dependency indicator */
    initgl_("02.02.02/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopst (&c__1);
/* dr = data record to hold */
/* integers:  174,  175,  176 */
/* reals:     17.4, 17.5, 17.6 */
/* strings:   "This is a GSE test string.", "This is another." */
    drinin[0] = 174;
    drinin[1] = 175;
    drinin[2] = 176;
#ifndef NO_PROTO
    drinrl[0] = 17.4f;
    drinrl[1] = 17.5f;
    drinrl[2] = 17.6f;
#else /* NO_PROTO */
    drinrl[0] = (float)17.4;
    drinrl[1] = (float)17.5;
    drinrl[2] = (float)17.6;
#endif /* NO_PROTO */
    s_copy(drinst, "This is a GSE test string.", 40L, 26L);
    s_copy(drinst + 40, "This is another.", 40L, 16L);
    drinsl[0] = itrim_(drinst, 40L);
    drinsl[1] = itrim_(drinst + 40, 40L);
/* set dr */
    nprec (&c__3, drinin, &c__3, drinrl, &c__2, drinsl, drinst, &c__20, &
	    errind, &ldract, drindr, 40L, 80L);
    chkinq_("pprec", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("12", "<Inquire generalized structure element facilities> should"
	    " return a valid list of GSE identifiers and workstation dependen"
	    "cy indicators.", 2L, 135L);
#else /* NO_PROTO */
    setmsg_("12", "<Inquire generalized structure element facilities> should\
 return a valid list of GSE identifiers and workstation dependency indicator\
s.", 2L, 135L);
#endif /* NO_PROTO */
/*  <inquire generalized structure element facilities> to set */
/*    ugseid = an unsupported GSE identifier */
/*    lgseim = list of workstation-dependent GSE's for this */
/*             implementation. */
    avgse = -6;
    nqgsef (&c__0, &errind, &avgse, &idum, &jdum);
    chkinq_("pqgsef", &errind, 6L);
    maxgse = -99999;
    plim = 0;
    gseok = avgse >= 0;
    i__1 = avgse;
    for (i = 1; i <= i__1; ++i) {
	wkdep = -6;
	nqgsef (&i, &errind, &idum, &gseid, &wkdep);
	chkinq_("pqgsef", &errind, 6L);
	maxgse = max(maxgse,gseid);
	if (wkdep == 1) {
	    ++plim;
	    lgseim[plim - 1] = gseid;
	} else if (wkdep == 0) {
/*           OK: do nothing */
	} else {
	    gseok = FALSE_;
	}
/* L5: */
    }
    ugseid = maxgse + 1;
    ifpf_(&gseok);
/* <generalized structure element> with gseid, ldr, dr */
    ngse (&ugseid, &ldract, drindr, 80L);
#ifndef NO_PROTO
    setmsg_("7 8 9", "<Inquire current element type and size> should return "
	    "generalized structure element as the type of the created element"
	    " and the appropriate element size.", 5L, 152L);
#else /* NO_PROTO */
    setmsg_("7 8 9", "<Inquire current element type and size> should return \
generalized structure element as the type of the created element and the app\
ropriate element size.", 5L, 152L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 69 && intlen == 1 && rllen == 0 && strlen 
	    == ldract;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7 8 10", "<Inquire current element content> should return the s"
	    "tandard representation for generalized structure element.", 6L, 
	    110L);
#else /* NO_PROTO */
    setmsg_("7 8 10", "<Inquire current element content> should return the s\
tandard representation for generalized structure element.", 6L, 110L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, drotdr, 80L);
    if (errind == 0 && intg == 1 && intar[0] == ugseid && rl == 0 && str == 
	    ldract) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PQCECO are incorrect.", 38L);
	goto L777;
    }
    i__1 = ldract;
    for (i = 1; i <= i__1; ++i) {
	if (strarl[i - 1] != 80) {
	    fail_();
	    inmsg_("String length STRARL for PQCECO is incorrect.", 45L);
	    goto L777;
	}
/* L10: */
    }
    s_copy(drotst, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 40L, 40L);
    s_copy(drotst + 40, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 40L, 40L);

/* unpack DR and compare all 4 arrays */
    nurec (&ldract, drotdr, &c__50, &c__50, &c__50, &errind, &intg, drotin, &
	    rl, drotrl, &str, drotsl, drotst, 80L, 40L);
    if (errind == 0 && intg == 3 && rl == 3 && str == 2) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PQCECO are incorrect.", 38L);
	goto L777;
    }
    if (drinin[0] == drotin[0] && drinin[1] == drotin[1] && drinin[2] == 
	    drotin[2]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Integer array from PUREC is incorrect.", 38L);
	goto L777;
    }
    if (drinrl[0] == drotrl[0] && drinrl[1] == drotrl[1] && drinrl[2] == 
	    drotrl[2]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Real array from PUREC is incorrect", 34L);
	goto L777;
    }
    if (drinsl[0] == drotsl[0] && drinsl[1] == drotsl[1]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String-length array from PUREC is incorrect.", 44L);
	goto L777;
    }
    if (s_cmp(drinst, drotst, 40L, 40L) == 0 && s_cmp(drinst + 40, drotst + 
	    40, 40L, 40L) == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String array from PUREC is incorrect", 36L);
	goto L777;
    }
    pass_();
L777:
    s_copy(gsemsg, "No error yet", 80L, 12L);
/* get list of workstation types */
    nqewk (&c__0, &errind, &worknm, &idum);
    chkinq_("pqewk", &errind, 5L);
    i__1 = worknm;
    for (j = 1; j <= i__1; ++j) {
	nqewk (&j, &errind, &idum, &jwk);
	chkinq_("pqewk", &errind, 5L);
	wavgse = 666;
	nqegse (&jwk, &c__0, &errind, &wavgse, &idum);
	if (errind == 51) {
	    goto L888;
	}
/* info unavailable for metafile-out type workstation */
	if (errind == 62) {
	    goto L888;
	}
	chkinq_("pqegse", &errind, 6L);
	i__2 = wavgse;
	for (k = 1; k <= i__2; ++k) {
	    gsel = -67;
	    nqegse (&jwk, &k, &errind, &idum, &gsel);
	    if (errind == 51) {
		goto L888;
	    }
	    chkinq_("pqegse", &errind, 6L);
	    i__3 = plim;
	    for (m = 1; m <= i__3; ++m) {
		if (gsel == lgseim[m - 1]) {
		    mark[m - 1] = TRUE_;
		    goto L20;
		}
/* L15: */
	    }
	    s_copy(gsemsg, "Unmatched workstation GSE.", 80L, 26L);
	    goto L880;
L20:
	    ;
	}
/* L25: */
    }
/* all elements should be marked */
    i__1 = plim;
    for (i = 1; i <= i__1; ++i) {
	if (mark[i - 1]) {
/* OK so far */
	} else {
	    s_copy(gsemsg, "Unmatched PHIGS GSE.", 80L, 20L);
	    goto L880;
	}
/* L35: */
    }
/* test can be performed */
L880:
#ifndef NO_PROTO
    setmsg_("11 12 13", "The set of workstation dependent GSEs within the PH"
	    "IGS GSE list as reported by <inquire generalized structure eleme"
	    "nt facilities> should be the union of the workstation GSE lists "
	    "as reported by <inquire list of available generalized structure "
	    "elements>.", 8L, 253L);
#else /* NO_PROTO */
    setmsg_("11 12 13", "The set of workstation dependent GSEs within the PH\
IGS GSE list as reported by <inquire generalized structure element facilitie\
s> should be the union of the workstation GSE lists as reported by <inquire \
list of available generalized structure elements>.", 8L, 253L);
#endif /* NO_PROTO */
    if (s_cmp(gsemsg, "No error yet", 80L, 12L) == 0) {
	pass_();
    } else {
	fail_();
	inmsg_(gsemsg, 80L);
    }
/* skip test */
L888:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

