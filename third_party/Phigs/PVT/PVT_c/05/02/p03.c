/* fort/05/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/03                              * */
/*  *    TEST TITLE : Explicit updating                     * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nuwk (integer *, integer *),
	     nrst (integer *, integer *), endit_(void), inmsg_(char *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nuwk (), nrst (), endit_(), inmsg_();

#endif /* NO_PROTO */
    static logical anyok;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsdus (integer *, integer *, integer *), 
	    nopwk (integer *, integer *, integer *);
    extern logical svrok_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsdus (), nopwk ();
    extern logical svrok_();
#endif /* NO_PROTO */
    static char badpic[100];
    static integer actpcc;
#ifndef NO_PROTO
    extern /* Subroutine */ int picchg_(integer *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int picchg_();
#endif /* NO_PROTO */
    static integer actsev;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), picenv_(integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), picenv_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* deferral mode */
/* modification mode */
/* dynamic modification */
/* clear control flag */
/* regeneration flag */
/* update state */
/* fortran binding: current and requested values */
    initgl_("05.02/03", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  picture change categories are numbered from 1 to 17: */
/*    workstation changes :  1 to 12 */
/*    structure changes   : 13 to 17 */
#ifndef NO_PROTO
    s_copy(badpic, "Skipping next test case because PICCHG unable to perform"
	    " requested operation.", 100L, 77L);
#else /* NO_PROTO */
    s_copy(badpic, "Skipping next test case because PICCHG unable to perform\
 requested operation.", 100L, 77L);
#endif /* NO_PROTO */
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  invoke PCCENV to set up standard environment */
    picenv_(&globnu_1.wkid);
    nsdus (&globnu_1.wkid, &c__4, &c__0);
    anyok = FALSE_;
/*  request-change     (8,9,12)    of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "8,9,12", &actsev, &actpcc, 5L, 6L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  non-request-change (1-7,10,11) of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "1,2,3,4,5,6,7,10,11", &actsev, &actpcc, 
	    5L, 19L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  structure change   (13-17)     of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "13,14,15,16,17", &actsev, &actpcc, 5L, 
	    14L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
    if (! anyok) {
	inmsg_(badpic, 100L);
	goto L100;
    }
/*  <redraw all structures> with CONDITIONAL */
    nrst (&globnu_1.wkid, &c__0);
#ifndef NO_PROTO
    setmsg_("4 13 16", "<Redraw all structures> should cause the state of vi"
	    "sual representation to be CORRECT.", 7L, 86L);
#else /* NO_PROTO */
    setmsg_("4 13 16", "<Redraw all structures> should cause the state of vi\
sual representation to be CORRECT.", 7L, 86L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
L100:
    anyok = FALSE_;
/*  request-change     (12,9,8)    of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "12,9,8", &actsev, &actpcc, 5L, 6L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  non-request-change (11,10,7-1) of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "11,10,7,6,5,4,3,2,1", &actsev, &actpcc, 
	    5L, 19L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  structure change   (17-13)     of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "17,16,15,14,13", &actsev, &actpcc, 5L, 
	    14L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
    if (! anyok) {
	inmsg_(badpic, 100L);
	goto L200;
    }
/*  <update workstation> with PERFORM */
    nuwk (&globnu_1.wkid, &c__1);
#ifndef NO_PROTO
    setmsg_("4 13 17", "<Update workstation> with regeneration flag = PERFOR"
	    "M should cause the state of visual representation to be CORRECT.",
	     7L, 116L);
#else /* NO_PROTO */
    setmsg_("4 13 17", "<Update workstation> with regeneration flag = PERFOR\
M should cause the state of visual representation to be CORRECT.", 7L, 116L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
L200:
    anyok = FALSE_;
/*  <redraw all structures> with CONDITIONAL to make svr = CORRECT */
    nrst (&globnu_1.wkid, &c__0);
/*  request-change     (9,8,12)         of severity = IMM */
    picchg_(&globnu_1.wkid, "1", "9,8,12", &actsev, &actpcc, 1L, 6L);
/*  non-request-change (10,7-1,11)      of severity = IMM */
    picchg_(&globnu_1.wkid, "1", "10,7,6,5,4,3,2,1,11", &actsev, &actpcc, 1L, 
	    19L);
/*  structure change   (15,16,14,17,13) of severity = IMM */
    picchg_(&globnu_1.wkid, "1", "15,16,14,17,13", &actsev, &actpcc, 1L, 14L);

/*  <update workstation> with POSTPONE */
    nuwk (&globnu_1.wkid, &c__0);
#ifndef NO_PROTO
    setmsg_("4 18", "If the severity of all deferred actions is IMM, then <u"
	    "pdate workstation> with regeneration flag = POSTPONE should caus"
	    "e the state of visual representation to be CORRECT.", 4L, 170L);
#else /* NO_PROTO */
    setmsg_("4 18", "If the severity of all deferred actions is IMM, then <u\
pdate workstation> with regeneration flag = POSTPONE should cause the state \
of visual representation to be CORRECT.", 4L, 170L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
/*  <redraw all structures> with CONDITIONAL to make svr = CORRECT */
    nrst (&globnu_1.wkid, &c__0);
    anyok = FALSE_;
/*  request-change     (9,8,12)         of severity = IRG */
    picchg_(&globnu_1.wkid, "0", "9,8,12", &actsev, &actpcc, 1L, 6L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  non-request-change (10,7-1,11)      of severity = IRG */
    picchg_(&globnu_1.wkid, "0", "10,7,6,5,4,3,2,1,11", &actsev, &actpcc, 1L, 
	    19L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  structure change   (15,16,14,17,13) of severity = IRG */
    picchg_(&globnu_1.wkid, "0", "15,16,14,17,13", &actsev, &actpcc, 1L, 14L);

    if (actpcc > 0) {
	anyok = TRUE_;
    }
    if (! anyok) {
	inmsg_(badpic, 100L);
	goto L300;
    }
/*  <update workstation> with POSTPONE */
    nuwk (&globnu_1.wkid, &c__0);
#ifndef NO_PROTO
    setmsg_("4 18", "If the severity of some of the deferred actions is IRG,"
	    " then <update workstation> with regeneration flag = POSTPONE sho"
	    "uld leave the state of visual representation as DEFERRED or make"
	    " it CORRECT.", 4L, 195L);
#else /* NO_PROTO */
    setmsg_("4 18", "If the severity of some of the deferred actions is IRG,\
 then <update workstation> with regeneration flag = POSTPONE should leave th\
e state of visual representation as DEFERRED or make it CORRECT.", 4L, 195L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "cd", 2L);
    ifpf_(&L__1);
/*  end_irg: */
L300:
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

