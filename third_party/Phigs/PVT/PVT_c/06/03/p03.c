/* fort/06/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__4 = 4;
static integer c__0 = 0;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b17 = 0.f;
#else /* NO_PROTO */
static real c_b17 = (float)0.;
#endif /* NO_PROTO */
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.03/03                              * */
/*  *    TEST TITLE : Update control of the workstation     * */
/*  *                 transformation                        * */
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
    static integer ix, svr;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void), 
	    nuwk (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_(), nuwk ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
    static real rdum1[6], rdum2[6], rdum3[6], rdum4[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real ocwin[6], cuwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdus ();
#endif /* NO_PROTO */
    static real ocvwp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsdus (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsdus ();
#endif /* NO_PROTO */
    static real rqwin[6], nwwin[6], cuvwp[6];
    static integer wtupd;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static real rqvwp[6], nwvwp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkt3 (integer *, integer *, integer *, real 
	    *, real *, real *, real *), nswkv3 (integer *, real *), nswkw3 (
	    integer *, real *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkt3 (), nswkv3 (), nswkw3 (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* deferral mode */
/* modification mode */
/* update state */
/* state of visual representation */
/*                correct    deferred    simulated */
/* regeneration flag */
    initgl_("06.03/03", 8L);
/* open PHIGS and workstation */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  <Set display update state> to WAIT, NIVE to try to defer updates */
    nsdus (&globnu_1.wkid, &c__4, &c__0);
/*  <inquire workstation transformation 3> to determine original */
/*     current state: */
/*     ocwin = 3D window */
/*     ocvwp = 3D viewport */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, ocwin, rqvwp, ocvwp);
    chkinq_("pqwkt3", &errind, 6L);
/*  alter workstation transformation: */
/*  <set workstation window 3>   = nwwin = ocwin / 2 */
/*  <set workstation viewport 3> = nwvwp = ocvwp / 2 */
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	nwwin[ix - 1] = ocwin[ix - 1] / 2.f;
	nwvwp[ix - 1] = ocvwp[ix - 1] / 2.f;
#else /* NO_PROTO */
	nwwin[ix - 1] = ocwin[ix - 1] / (float)2.;
	nwvwp[ix - 1] = ocvwp[ix - 1] / (float)2.;
#endif /* NO_PROTO */
/* L300: */
    }
/*  <set workstation window 3> */
    nswkw3 (&globnu_1.wkid, nwwin);
/*  <set workstation viewport 3> */
    nswkv3 (&globnu_1.wkid, nwvwp);
/*  <inquire workstation transformation 3> to determine new */
/*     current state: */
/*     wtupd = workstation transformation update state */
/*     cuwin = new 3D window */
/*     cuvwp = new 3D viewport */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("15", "The workstation transformation update state returned by <"
	    "inquire workstation transformation 3> should be either PENDING o"
	    "r NOTPENDING.", 2L, 134L);
#else /* NO_PROTO */
    setmsg_("15", "The workstation transformation update state returned by <\
inquire workstation transformation 3> should be either PENDING or NOTPENDING."
	    , 2L, 134L);
#endif /* NO_PROTO */
    if (wtupd == 0) {
	pass_();
	inmsg_("Skipping PENDING test.", 22L);
	goto L100;
    } else if (wtupd == 1) {
	pass_();
    } else {
	fail_();
	goto L100;
    }
/*  pending_test: */
#ifndef NO_PROTO
    setmsg_("18", "If the workstation transformation update state is PENDING"
	    ", then the state of visual representation for that workstation s"
	    "hould be DEFERRED.", 2L, 139L);
#else /* NO_PROTO */
    setmsg_("18", "If the workstation transformation update state is PENDING\
, then the state of visual representation for that workstation should be DEF\
ERRED.", 2L, 139L);
#endif /* NO_PROTO */
    nqdus (&globnu_1.wkid, &errind, &idum1, &idum2, &idum3, &svr);
    chkinq_("pqdus", &errind, 5L);
    L__1 = svr == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("12 16", "If the workstation transformation update state returne"
	    "d by <inquire workstation transformation 3> is PENDING, then the"
	    " current values of the workstation transformation should be the "
	    "same as they were before the requested values were last set.", 5L,
	     242L);
#else /* NO_PROTO */
    setmsg_("12 16", "If the workstation transformation update state returne\
d by <inquire workstation transformation 3> is PENDING, then the current val\
ues of the workstation transformation should be the same as they were before\
 the requested values were last set.", 5L, 242L);
#endif /* NO_PROTO */
    L__1 = rareq_(&c__6, cuwin, ocwin, &c_b17, &c_b17) && rareq_(&c__6, cuvwp,
	     ocvwp, &c_b17, &c_b17);
    ifpf_(&L__1);
/*  notpending_test: */
L100:
/*  <update workstation> to force update of view table */
    nuwk (&globnu_1.wkid, &c__1);
/*  <inquire display update state> to determine */
/*     svr = state of visual representation */
    nqdus (&globnu_1.wkid, &errind, &idum1, &idum2, &idum3, &svr);
    chkinq_("pqdus", &errind, 5L);
    if (svr == 0) {
#ifndef NO_PROTO
	setmsg_("15 19", "If the state of visual representation for a workst"
		"ation is CORRECT, then the workstation transformation update"
		" returned by <inquire workstation transformation> state shou"
		"ld be NOTPENDING.", 5L, 187L);
#else /* NO_PROTO */
	setmsg_("15 19", "If the state of visual representation for a workst\
ation is CORRECT, then the workstation transformation update returned by <in\
quire workstation transformation> state should be NOTPENDING.", 5L, 187L);
#endif /* NO_PROTO */
	nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rdum1, rdum2, rdum3, rdum4);
	chkinq_("pqwkt3", &errind, 6L);
	L__1 = wtupd == 0;
	ifpf_(&L__1);
    } else {
	inmsg_("Skipping test that CORRECT implies NOTPENDING.", 46L);
    }
/*  <inquire workstation transformation 3> to determine new */
/*     current state: */
/*     wtupd = workstation transformation update state */
/*     cuwin = new 3D window */
/*     cuvwp = new 3D viewport */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    if (wtupd != 0) {
	inmsg_("Skipping NOTPENDING test.", 25L);
	goto L400;
    }
#ifndef NO_PROTO
    setmsg_("15 17", "If the workstation transformation update state returne"
	    "d by <inquire workstation transformation 3> is NOTPENDING, then "
	    "the current values of the workstation transformation should be t"
	    "he same as the most recently set requested values.", 5L, 232L);
#else /* NO_PROTO */
    setmsg_("15 17", "If the workstation transformation update state returne\
d by <inquire workstation transformation 3> is NOTPENDING, then the current \
values of the workstation transformation should be the same as the most rece\
ntly set requested values.", 5L, 232L);
#endif /* NO_PROTO */
    L__1 = rareq_(&c__6, cuwin, nwwin, &c_b17, &c_b17) && rareq_(&c__6, cuvwp,
	     nwvwp, &c_b17, &c_b17);
    ifpf_(&L__1);
/*  end_notpending_test: */
L400:
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

