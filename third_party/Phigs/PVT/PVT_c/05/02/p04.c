/* fort/05/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/04                              * */
/*  *    TEST TITLE : Deferral mode ASAP                    * */
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
    extern /* Subroutine */ int ifpf_(logical *), endit_(void), inmsg_(char *,
	     ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), endit_(), inmsg_();
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

/* deferral mode */
/* modification mode */
/* dynamic modification */
    initgl_("05.02/04", 8L);
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
/* invoke PICENV to set up standard picture environment */
    picenv_(&globnu_1.wkid);
/*  *** *** *** *** ***  visual changes   *** *** *** *** *** */
    nsdus (&globnu_1.wkid, &c__0, &c__0);
/*  request-change (8,9,12) of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "8,9,12", &actsev, &actpcc, 5L, 6L);
    if (actpcc < 1) {
	inmsg_(badpic, 100L);
	goto L190;
    }
#ifndef NO_PROTO
    setmsg_("3 4 13 22", "After altering a current/request type entity in th"
	    "e WSL, the state of visual representation should be CORRECT when"
	    " the deferral mode is ASAP.", 9L, 141L);
#else /* NO_PROTO */
    setmsg_("3 4 13 22", "After altering a current/request type entity in th\
e WSL, the state of visual representation should be CORRECT when the deferra\
l mode is ASAP.", 9L, 141L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
L190:
/*  non-request-change (1-7,10,11) of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "1,2,3,4,5,6,7,10,11", &actsev, &actpcc, 
	    5L, 19L);
    if (actpcc < 1) {
	inmsg_(badpic, 100L);
	goto L290;
    }
#ifndef NO_PROTO
    setmsg_("3 4 13 22", "After altering a single-valued type entity in the "
	    "WSL, the state of visual representation should be CORRECT when t"
	    "he deferral mode is ASAP.", 9L, 139L);
#else /* NO_PROTO */
    setmsg_("3 4 13 22", "After altering a single-valued type entity in the \
WSL, the state of visual representation should be CORRECT when the deferral \
mode is ASAP.", 9L, 139L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
L290:
/*  structure change (13-17) of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "13,14,15,16,17", &actsev, &actpcc, 5L, 
	    14L);
    if (actpcc < 1) {
	inmsg_(badpic, 100L);
	goto L390;
    }
#ifndef NO_PROTO
    setmsg_("3 4 13 22", "After performing some CSS-type change, the state o"
	    "f visual representation should be CORRECT when the deferral mode"
	    " is ASAP.", 9L, 123L);
#else /* NO_PROTO */
    setmsg_("3 4 13 22", "After performing some CSS-type change, the state o\
f visual representation should be CORRECT when the deferral mode is ASAP.", 
	    9L, 123L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
L390:
/*  *** *** *** *** ***  deferral-mode changes   *** *** *** *** *** */
    nsdus (&globnu_1.wkid, &c__4, &c__0);
    anyok = FALSE_;
/*  structure change   (17-13)     of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "17,16,15,14,13", &actsev, &actpcc, 5L, 
	    14L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  non-request-change (11,10,7-1) of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "11,10,7,6,5,4,3,2,1", &actsev, &actpcc, 
	    5L, 19L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
/*  request-change     (12,9,8)    of greatest available severity */
    picchg_(&globnu_1.wkid, "0,2,1", "12,9,8", &actsev, &actpcc, 5L, 6L);
    if (actpcc > 0) {
	anyok = TRUE_;
    }
    if (! anyok) {
	inmsg_(badpic, 100L);
	goto L490;
    }
    nsdus (&globnu_1.wkid, &c__0, &c__0);
#ifndef NO_PROTO
    setmsg_("3 4 13 22", "After performing visual changes in WAIT,NIVE mode,"
	    " the state of visual representation should be CORRECT when the d"
	    "eferral mode is re-set to ASAP.", 9L, 145L);
#else /* NO_PROTO */
    setmsg_("3 4 13 22", "After performing visual changes in WAIT,NIVE mode,\
 the state of visual representation should be CORRECT when the deferral mode\
 is re-set to ASAP.", 9L, 145L);
#endif /* NO_PROTO */
    L__1 = svrok_(&globnu_1.wkid, "c", 1L);
    ifpf_(&L__1);
L490:
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

