/* fort/03/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 03.03/02                              * */
/*  *    TEST TITLE : Selection of structures for archiving * */
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
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), narsn (integer *, integer *, integer *), narst (
	    integer *, integer *, integer *), setvs_(char *, integer *, 
	    integer *, ftnlen), nclarf (integer *), ndasar (integer *), 
	    initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), narsn (), narst (), setvs_(), 
	    nclarf (), ndasar (), initgl_();
#endif /* NO_PROTO */
    static integer actsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), noparf (integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), noparf ();
#endif /* NO_PROTO */
    static integer actstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    stdcss_(void), narast (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), stdcss_(), narast ();
#endif /* NO_PROTO */
    static integer spcsiz, spcstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer expsiz, expstr[50];

    initgl_("03.03/02", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  set up standard networks in CSS */
    stdcss_();
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    arid = 2;
    noparf (&arid, &arnm);
/*  <delete all structures from archive> to ensure empty file */
    ndasar (&arid);
/*  expstr = expected structures = 114,102,100,140,107 */
    setvs_("114,102,100,140,107", expstr, &expsiz, 19L);
/*  <archive structures> with expstr, arid */
    narst (&arid, &expsiz, expstr);
#ifndef NO_PROTO
    setmsg_("1 4", "Exactly those structures explicitly listed in the input "
	    "parameter of <archive structures> should be reported as existing"
	    " in a previously empty archive file.", 3L, 156L);
#else /* NO_PROTO */
    setmsg_("1 4", "Exactly those structures explicitly listed in the input \
parameter of <archive structures> should be reported as existing in a previo\
usly empty archive file.", 3L, 156L);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine: actstr = actual list of structures */
    nrsid (&arid, &c__50, &actsiz, actstr);
    L__1 = actsiz == expsiz && seteq_(&actsiz, actstr, expstr);
    ifpf_(&L__1);
/*  <delete all structures from archive> to ensure empty file */
    ndasar (&arid);
/*  spcstr = specified structures = 107,114,105 */
    setvs_("107,114,105", spcstr, &spcsiz, 11L);
/*  expstr = expected structures = 105,110,114,108,111,115,107,113 */
    setvs_("105,110,114,108,111,115,107,113", expstr, &expsiz, 31L);
/*  <archive structure networks> with spcstr, arid */
    narsn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("2 4", "The structures explicitly listed in the input parameter "
	    "of <archive structure networks> and all their descendants in the"
	    " CSS should be reported as existing in a previously empty archiv"
	    "e file.", 3L, 191L);
#else /* NO_PROTO */
    setmsg_("2 4", "The structures explicitly listed in the input parameter \
of <archive structure networks> and all their descendants in the CSS should \
be reported as existing in a previously empty archive file.", 3L, 191L);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine: actstr = actual list of structures */
    nrsid (&arid, &c__50, &actsiz, actstr);
    L__1 = actsiz == expsiz && seteq_(&actsiz, actstr, expstr);
    ifpf_(&L__1);
/*  <delete all structures from archive> to ensure empty file */
    ndasar (&arid);
/* expstr = expected structures = 100,101,102,103,104,105,106,107,108,109,
*/
/*                                 110,111,113,114,115,120,130,140,142 */
#ifndef NO_PROTO
    setvs_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,120,"
	    "130,140,142", expstr, &expsiz, 75L);
#else /* NO_PROTO */
    setvs_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,120,\
130,140,142", expstr, &expsiz, 75L);
#endif /* NO_PROTO */
/*  <archive all structures> with arid */
    narast (&arid);
#ifndef NO_PROTO
    setmsg_("3 4", "<Archive all structures> should cause all structures cur"
	    "rently in the CSS to be reported as existing in a previously emp"
	    "ty archive file.", 3L, 136L);
#else /* NO_PROTO */
    setmsg_("3 4", "<Archive all structures> should cause all structures cur\
rently in the CSS to be reported as existing in a previously empty archive f\
ile.", 3L, 136L);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine: actstr = actual list of structures */
    nrsid (&arid, &c__50, &actsiz, actstr);
    L__1 = actsiz == expsiz && seteq_(&actsiz, actstr, expstr);
    ifpf_(&L__1);
/*  <close archive file> with arid */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

