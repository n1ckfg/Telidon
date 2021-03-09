/* fort/02/02/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.01/01                           * */
/*  *    TEST TITLE : Opening and closing an empty existing * */
/*  *                 structure                             * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqep (integer *, integer *),
	     endit_(void), nclph (void), nclst (void), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqep (), endit_(), nclph (), nclst ()
	    , nopst ();
#endif /* NO_PROTO */
    static integer errind, elepos;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer rstrid;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer strsta, ststin;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */
    static integer opstst;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstrs (integer *), nqstst (integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstrs (), nqstst ();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* open-structure status */
/* structure status indicator */
/* structure state value */
    initgl_("02.02.01/01", 11L);
#ifndef NO_PROTO
    setmsg_("9", "Before opening PHIGS, <inquire structure state value> shou"
	    "ld return the structure state value as CLOSED.", 1L, 104L);
#else /* NO_PROTO */
    setmsg_("9", "Before opening PHIGS, <inquire structure state value> shou\
ld return the structure state value as CLOSED.", 1L, 104L);
#endif /* NO_PROTO */
/* <inquire structure state value> to set strsta */
    strsta = -6;
    nqstrs (&strsta);
    L__1 = strsta == 0;
    ifpf_(&L__1);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("9", "<Inquire structure state value> should return the structur"
	    "e state value as CLOSED when the CSS is empty after opening PHIG"
	    "S.", 1L, 124L);
#else /* NO_PROTO */
    setmsg_("9", "<Inquire structure state value> should return the structur\
e state value as CLOSED when the CSS is empty after opening PHIGS.", 1L, 124L)
	    ;
#endif /* NO_PROTO */
/* <inquire structure state value> to set strsta */
    strsta = -6;
    nqstrs (&strsta);
    L__1 = strsta == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "If no structures exist, <inquire open structure> should re"
	    "turn a NONE structure status and the structure identifier is und"
	    "efined.", 1L, 129L);
#else /* NO_PROTO */
    setmsg_("6", "If no structures exist, <inquire open structure> should re\
turn a NONE structure status and the structure identifier is undefined.", 1L, 
	    129L);
#endif /* NO_PROTO */
    nqopst (&errind, &opstst, &rstrid);
    L__1 = errind == 0 && opstst == 0;
    ifpf_(&L__1);
/* <inquire structure status> to set ststin */
#ifndef NO_PROTO
    setmsg_("7", "<Inquire structure status> should return the appropriate s"
	    "tructure status as NONEXISTENT for a non-existent structure.", 1L,
	     118L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire structure status> should return the appropriate s\
tructure status as NONEXISTENT for a non-existent structure.", 1L, 118L);
#endif /* NO_PROTO */
    nqstst (&c__50, &errind, &ststin);
    L__1 = errind == 0 && ststin == 0;
    ifpf_(&L__1);
/* <Open structure> with strid */
    nopst (&c__50);
#ifndef NO_PROTO
    setmsg_("9", "<Inquire structure state value> should return the structur"
	    "e state value as OPEN when an open structure exists in the CSS.", 
	    1L, 121L);
#else /* NO_PROTO */
    setmsg_("9", "<Inquire structure state value> should return the structur\
e state value as OPEN when an open structure exists in the CSS.", 1L, 121L);
#endif /* NO_PROTO */
/* <inquire structure state value> to set strsta */
    strsta = -6;
    nqstrs (&strsta);
    L__1 = strsta == 1;
    ifpf_(&L__1);
/* <inquire open structure> to set opstst, strid */
#ifndef NO_PROTO
    setmsg_("1 5", "If an empty structure is open <inquire open structure> s"
	    "hould return an OPEN structure status and the structure identifi"
	    "er of the open structure.", 3L, 145L);
#else /* NO_PROTO */
    setmsg_("1 5", "If an empty structure is open <inquire open structure> s\
hould return an OPEN structure status and the structure identifier of the op\
en structure.", 3L, 145L);
#endif /* NO_PROTO */
    nqopst (&errind, &opstst, &rstrid);
    L__1 = errind == 0 && opstst == 1 && rstrid == 50;
    ifpf_(&L__1);
/*  <inquire structure status> to set ststin */
#ifndef NO_PROTO
    setmsg_("7", "<Inquire structure status> should return the appropriate s"
	    "tructure status as EMPTY for an empty structure when the structu"
	    "re is open.", 1L, 133L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire structure status> should return the appropriate s\
tructure status as EMPTY for an empty structure when the structure is open.", 
	    1L, 133L);
#endif /* NO_PROTO */
    nqstst (&c__50, &errind, &ststin);
    L__1 = errind == 0 && ststin == 1;
    ifpf_(&L__1);
/*  <inquire element pointer> to set elepos */
#ifndef NO_PROTO
    setmsg_("3 8", "<Inquire element pointer> should return zero as the elem"
	    "ent pointer position of an empty structure.", 3L, 99L);
#else /* NO_PROTO */
    setmsg_("3 8", "<Inquire element pointer> should return zero as the elem\
ent pointer position of an empty structure.", 3L, 99L);
#endif /* NO_PROTO */
    nqep (&errind, &elepos);
    L__1 = errind == 0 && elepos == 0;
    ifpf_(&L__1);
/*  <Close structure> */
    nclst ();
#ifndef NO_PROTO
    setmsg_("9", "<Inquire structure state value> should return the structur"
	    "e state value as CLOSED when a closed structure exists in the CS"
	    "S.", 1L, 124L);
#else /* NO_PROTO */
    setmsg_("9", "<Inquire structure state value> should return the structur\
e state value as CLOSED when a closed structure exists in the CSS.", 1L, 124L)
	    ;
#endif /* NO_PROTO */
/* <inquire structure state value> to set strsta */
    strsta = -6;
    nqstrs (&strsta);
    L__1 = strsta == 0;
    ifpf_(&L__1);
/*  <inquire open structure> to set opstst, strid */
#ifndef NO_PROTO
    setmsg_("4 6", "If a structure exists, but none is open, <inquire open s"
	    "tructure> should return a NONE structure status and the structur"
	    "e identifier is undefined.", 3L, 146L);
#else /* NO_PROTO */
    setmsg_("4 6", "If a structure exists, but none is open, <inquire open s\
tructure> should return a NONE structure status and the structure identifier\
 is undefined.", 3L, 146L);
#endif /* NO_PROTO */
    nqopst (&errind, &opstst, &rstrid);
    L__1 = errind == 0 && opstst == 0;
    ifpf_(&L__1);
/*  <inquire structure status> to set ststin */
#ifndef NO_PROTO
    setmsg_("7", "<Inquire structure status> should return the appropriate s"
	    "tructure status as EMPTY for an empty structure when the structu"
	    "re is closed.", 1L, 135L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire structure status> should return the appropriate s\
tructure status as EMPTY for an empty structure when the structure is closed."
	    , 1L, 135L);
#endif /* NO_PROTO */
    nqstst (&c__50, &errind, &ststin);
    L__1 = errind == 0 && ststin == 1;
    ifpf_(&L__1);
/* L777: */
/* close PHIGS */
    nclph ();
#ifndef NO_PROTO
    setmsg_("9", "After closing PHIGS, <inquire structure state value> shoul"
	    "d return the structure state value as CLOSED.", 1L, 103L);
#else /* NO_PROTO */
    setmsg_("9", "After closing PHIGS, <inquire structure state value> shoul\
d return the structure state value as CLOSED.", 1L, 103L);
#endif /* NO_PROTO */
/* <inquire structure state value> to set strsta */
    strsta = -6;
    nqstrs (&strsta);
    L__1 = strsta == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

