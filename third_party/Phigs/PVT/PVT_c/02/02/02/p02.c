/* fort/02/02/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.02/02                           * */
/*  *    TEST TITLE : Application data                      * */
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
    static integer i, rl;
#ifndef NO_PROTO
    extern /* Subroutine */ int nap (integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nap ();
#endif /* NO_PROTO */
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), endit_(void), nprec (integer *, 
	    integer *, integer *, real *, integer *, integer *, char *, 
	    integer *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_(), nprec ();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nurec (integer *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, integer *, char *, 
	    ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nurec ();
    extern integer itrim_();
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer ldract;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), chkinq_();
#endif /* NO_PROTO */
    static char drindr[80*20];
    static integer errind, intlen, drinin[50], drinsl[50], drotin[50], celtyp;

    static real drinrl[50];
    static char drotdr[80*20], drinst[80*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50], drotsl[50];
    static real drotrl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcets (integer *, integer *, integer *, integer *, integer *), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcets (), xpopph_();
#endif /* NO_PROTO */
    static char drotst[80*50];

/*  Declare program-specific variables */
    initgl_("02.02.02/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  *** *** *** *** ***   Application data   *** *** *** *** *** */
    nopst (&c__1);
/* dr = data record to hold */
/* integers:  174,  175,   176 */
/* reals:     17.4, 17.5, 17.6 */
/*strings:   "This is a application data test string.", "This is another."
*/
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
    s_copy(drinst, "This is a application data test string.", 80L, 39L);
    s_copy(drinst + 80, "This is another.", 80L, 16L);
    drinsl[0] = itrim_(drinst, 80L);
    drinsl[1] = itrim_(drinst + 80, 80L);
/* set dr */
    nprec (&c__3, drinin, &c__3, drinrl, &c__2, drinsl, drinst, &c__20, &
	    errind, &ldract, drindr, 80L, 80L);
    chkinq_("pprec", &errind, 5L);
/* <application data> with dr */
    nap (&ldract, drindr, 80L);
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return ap"
	    "plication data as the type of the created element and the approp"
	    "riate element size.", 3L, 139L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return ap\
plication data as the type of the created element and the appropriate elemen\
t size.", 3L, 139L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 68 && intlen == 0 && rllen == 0 && strlen 
	    == ldract;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for application data.", 3L, 97L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for application data.", 3L, 97L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, drotdr, 80L);
    if (errind == 0 && intg == 0 && rl == 0 && str == ldract) {
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
/* unpack DR and compare all 4 arrays */
    nurec (&ldract, drotdr, &c__50, &c__50, &c__50, &errind, &intg, drotin, &
	    rl, drotrl, &str, drotsl, drotst, 80L, 80L);
    if (errind == 0 && intg == 3 && rl == 3 && str == 2) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PUREC are incorrect.", 37L);
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
	inmsg_("Real array from PUREC is incorrect.", 35L);
	goto L777;
    }
    if (drinsl[0] == drotsl[0] && drinsl[1] == drotsl[1]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String-length array from PUREC is incorrect.", 44L);
	goto L777;
    }
    if (s_cmp(drinst, drotst, 80L, 80L) == 0 && s_cmp(drinst + 80, drotst + 
	    80, 80L, 80L) == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String array from PUREC is incorrect.", 37L);
	goto L777;
    }
    pass_();
L777:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

