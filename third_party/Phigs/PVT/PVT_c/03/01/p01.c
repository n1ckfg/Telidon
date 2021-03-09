/* fort/03/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.01/01                              * */
/*  *    TEST TITLE : Effect of <open archive file> and     * */
/*  *                 <close archive file>                  * */
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
    integer i__1, i__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer cnt;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndas ();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6;
    static logical accok;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nclph (void), nqarf (integer *, 
	    integer *, integer *, integer *, integer *), inmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nclph (), nqarf (), inmsg_();
#endif /* NO_PROTO */
    static logical arset;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqsid (integer *, integer *, integer *, integer *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nclst (void), nqars (integer *), nrast (
	    integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), nqsid ();
    extern logical seteq_();
    extern /* Subroutine */ int nclst (), nqars (), nrast (), nopst ();
#endif /* NO_PROTO */
    static integer acidls[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar ();
#endif /* NO_PROTO */
    static integer acnmls[200], errind, alisiz, custid, arstat, exidls[200], 
	    arcnum, loopct;
    static logical openok;
    static integer mxarno;
    static logical closok;
    static integer exnmls[200];
    static logical statok;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer struid;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    avarnm_(integer *), errctl_(logical *), xpopph_(integer *, 
	    integer *), noparf (integer *, integer *), narast (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), avarnm_(), errctl_(), xpopph_(), 
	    noparf (), narast ();
#endif /* NO_PROTO */
    static integer numstr;

    /* Fortran I/O blocks */
    static icilist io___12 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___21 = { 0, msg, 0, "(A,I5,A,I4,A)", 300, 1 };
    static icilist io___31 = { 0, msg, 0, "(A,I5,A,I4,A)", 300, 1 };


/* archive state */
/*                closed   open */
/*  Throughout, use variable names: */
/*  arid   : archive file identifier */
/*  arnm   : archive file name */
/*  mxarno : maximum number of simultaneously open archive files */
/*  arstat : archive file state */
/*  openok : <open archive file> ok flag */
/*  closok : <close archive file> ok flag */
/*  statok : archive state ok flag */
/*  arset  : open archive file set ok flag */
/*  accok  : access archive file ok flag */
/*  alisiz : actual size of open archive list */
/*  acidls : actual open archive file id. list */
/*  acnmls : actual open archive file name list */
/*  exidls : expected open archive file id. list */
/*  exnmls : expected open archive file name list */
/*  arcnum : opened archive file counter */
/*  struid : structure identifier */
/*  custid : structure identifier list in CSS */
    initgl_("03.01/01", 8L);
#ifndef NO_PROTO
    setmsg_("10", "Before opening PHIGS, <inquire archive state value> shoul"
	    "d return the archive state as ARCL.", 2L, 92L);
#else /* NO_PROTO */
    setmsg_("10", "Before opening PHIGS, <inquire archive state value> shoul\
d return the archive state as ARCL.", 2L, 92L);
#endif /* NO_PROTO */
/*  <Inquire archive state value> to determine */
/*     arstat = archive file state */
    arstat = -66;
    nqars (&arstat);
    L__1 = arstat == 0;
    ifpf_(&L__1);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("3 10", "Immediately after <open phigs>, the archive state shoul"
	    "d be reported as ARCL.", 4L, 77L);
#else /* NO_PROTO */
    setmsg_("3 10", "Immediately after <open phigs>, the archive state shoul\
d be reported as ARCL.", 4L, 77L);
#endif /* NO_PROTO */
    arstat = -66;
    nqars (&arstat);
    L__1 = arstat == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 11", "Immediately after <open phigs>, the set of open archive"
	    " files should be reported as empty.", 4L, 90L);
#else /* NO_PROTO */
    setmsg_("4 11", "Immediately after <open phigs>, the set of open archive\
 files should be reported as empty.", 4L, 90L);
#endif /* NO_PROTO */
/*  <Inquire archive files> to determine acidls */
    alisiz = -66;
    nqarf (&c__0, &errind, &alisiz, &idum1, &idum2);
    L__1 = errind == 0 && alisiz == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire phigs facilities> should report the maximum num"
	    "ber of simultaneously open archive files to be greater than 0.", 
	    3L, 118L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire phigs facilities> should report the maximum num\
ber of simultaneously open archive files to be greater than 0.", 3L, 118L);
#endif /* NO_PROTO */
/*  <Inquire phigs facilities> to determine */
/*     mxarno = maximum number of simultaneously open archive files */
    nqphf (&c__0, &errind, &idum1, &mxarno, &idum2, &idum3, &idum4, &idum5, &
	    idum6);
    if (errind == 0 && mxarno > 0) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___12);
	do_fio(&c__1, "<Inquire phigs facilities> reported error indicator = "
		, 54L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	do_fio(&c__1, " and maximum open archive files = ", 34L);
	do_fio(&c__1, (char *)&mxarno, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".  Skipping opening/closing tests.", 34L);
	e_wsfi();
	inmsg_(msg, 300L);
	goto L500;
    }
    openok = TRUE_;
    statok = TRUE_;
    arset = TRUE_;
    accok = TRUE_;
/* loop to open simultaneously the maximum number of archive files, */
/* up to the program maximum */
    loopct = min(200,mxarno);
    i__1 = loopct;
    for (arcnum = 1; arcnum <= i__1; ++arcnum) {
	arid = arcnum + 10;
	avarnm_(&arnm);
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
/* open next archive file */
	noparf (&arid, &arnm);
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
	if (globnu_1.errsig != 0) {
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Got error ", 10L);
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " when attempting to open archive file named ", 44L)
		    ;
	    do_fio(&c__1, (char *)&arnm, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    openok = FALSE_;
	    goto L100;
	}
/*  <Inquire archive state value> to determine */
/*  arstat = archive file state */
	arstat = -66;
	nqars (&arstat);
	if (arstat != 1) {
	    statok = FALSE_;
	}
/*  expected list of open archive files */
	exidls[arcnum - 1] = arid;
	exnmls[arcnum - 1] = arnm;
/*  get actual list of open archive files */
	nqarf (&c__0, &errind, &alisiz, &idum1, &idum2);
	if (errind != 0) {
	    arset = FALSE_;
	    goto L210;
	}
	i__2 = alisiz;
	for (cnt = 1; cnt <= i__2; ++cnt) {
	    nqarf (&cnt, &errind, &idum1, &acidls[cnt - 1], &acnmls[cnt - 1]);

	    if (errind != 0) {
		arset = FALSE_;
		goto L210;
	    }
/* L200: */
	}
/*  compare expected and actual list of open archive files */
	if (alisiz == arcnum && seteq_(&alisiz, exidls, acidls) && seteq_(&
		alisiz, exnmls, acnmls)) {
/*           OK so far */
	} else {
	    arset = FALSE_;
	}
L210:
/* create structure and test access */
	ndas ();
	ndasar (&arid);
	struid = arcnum + 20;
	nopst (&struid);
	i__2 = arcnum + 30;
	nlb (&i__2);
	nclst ();
/*  <archive all structures> with arid */
	narast (&arid);
	ndas ();
/*  <retrieve all structures> with arid */
	nrast (&arid);
/*  <inquire structure identifiers> to determine: */
/*  custid = current structure identifier list in CSS */
	nqsid (&c__1, &errind, &numstr, &custid);
	if (errind == 0 && numstr == 1 && custid == struid) {
/*           OK so far */
	} else {
	    accok = FALSE_;
	}
/*  end_open_loop */
L100:
	;
    }

#ifndef NO_PROTO
    setmsg_("1 2", "Opening the maximum number of simultaneously open archiv"
	    "e files should be allowed.", 3L, 82L);
#else /* NO_PROTO */
    setmsg_("1 2", "Opening the maximum number of simultaneously open archiv\
e files should be allowed.", 3L, 82L);
#endif /* NO_PROTO */
    ifpf_(&openok);
#ifndef NO_PROTO
    setmsg_("5 10", "A successful <open archive file> should set the archive"
	    " state to AROP.", 4L, 70L);
#else /* NO_PROTO */
    setmsg_("5 10", "A successful <open archive file> should set the archive\
 state to AROP.", 4L, 70L);
#endif /* NO_PROTO */
    ifpf_(&statok);
#ifndef NO_PROTO
    setmsg_("6 11", "A successful <open archive file> should add the specifi"
	    "ed file to the set of open archive files.", 4L, 96L);
#else /* NO_PROTO */
    setmsg_("6 11", "A successful <open archive file> should add the specifi\
ed file to the set of open archive files.", 4L, 96L);
#endif /* NO_PROTO */
    ifpf_(&arset);
#ifndef NO_PROTO
    setmsg_("7", "A successful <open archive file> should provide access to "
	    "the archive file of the specified name through the specified ide"
	    "ntifier.", 1L, 130L);
#else /* NO_PROTO */
    setmsg_("7", "A successful <open archive file> should provide access to \
the archive file of the specified name through the specified identifier.", 1L,
	     130L);
#endif /* NO_PROTO */
    ifpf_(&accok);
    closok = TRUE_;
    statok = TRUE_;
    arset = TRUE_;
/* loop to close the archive files */
    for (arcnum = loopct; arcnum >= 1; --arcnum) {
	arid = arcnum + 10;
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
	nclarf (&arid);
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
	if (globnu_1.errsig != 0) {
	    s_wsfi(&io___31);
	    do_fio(&c__1, "Got error ", 10L);
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
	    do_fio(&c__1, " when attempting to close archive file with ident"
		    "ifier #", 56L);
#else /* NO_PROTO */
	    do_fio(&c__1, " when attempting to close archive file with ident\
ifier #", 56L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&arid, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    closok = FALSE_;
	}
/* check archive state value */
	arstat = -66;
	nqars (&arstat);
	if (arcnum == 1) {
	    if (arstat != 0) {
		statok = FALSE_;
	    }
	} else {
	    if (arstat != 1) {
		statok = FALSE_;
	    }
	}
/* get actual list of open archive files */
	nqarf (&c__0, &errind, &alisiz, &idum1, &idum2);
	if (errind != 0) {
	    arset = FALSE_;
	    goto L410;
	}
	i__1 = alisiz;
	for (cnt = 1; cnt <= i__1; ++cnt) {
	    nqarf (&cnt, &errind, &idum1, &acidls[cnt - 1], &acnmls[cnt - 1]);

	    if (errind != 0) {
		arset = FALSE_;
		goto L410;
	    }
/* L400: */
	}
/*  compare expected and actual list of open archive files */
	if (alisiz == arcnum - 1 && seteq_(&alisiz, exidls, acidls) && seteq_(
		&alisiz, exnmls, acnmls)) {
/*           OK so far */
	} else {
	    arset = FALSE_;
	}
L410:
/* L300: */
	;
    }

#ifndef NO_PROTO
    setmsg_("8 10", "A successful <close archive file> on the last open arch"
	    "ive file should set the archive state to ARCL, but otherwise lea"
	    "ve the state as AROP.", 4L, 140L);
#else /* NO_PROTO */
    setmsg_("8 10", "A successful <close archive file> on the last open arch\
ive file should set the archive state to ARCL, but otherwise leave the state\
 as AROP.", 4L, 140L);
#endif /* NO_PROTO */
    ifpf_(&statok);
#ifndef NO_PROTO
    setmsg_("9", "Closing an archive file in the set of open archive files s"
	    "hould succeed.", 1L, 72L);
#else /* NO_PROTO */
    setmsg_("9", "Closing an archive file in the set of open archive files s\
hould succeed.", 1L, 72L);
#endif /* NO_PROTO */
    ifpf_(&closok);
#ifndef NO_PROTO
    setmsg_("9 11", "A successful <close archive file> should remove the spe"
	    "cified file from the set of open archive files.", 4L, 102L);
#else /* NO_PROTO */
    setmsg_("9 11", "A successful <close archive file> should remove the spe\
cified file from the set of open archive files.", 4L, 102L);
#endif /* NO_PROTO */
    ifpf_(&arset);
/* check_close: */
L500:
    nclph ();
#ifndef NO_PROTO
    setmsg_("10", "After closing PHIGS, <inquire archive state value> should"
	    " return the archive state as ARCL.", 2L, 91L);
#else /* NO_PROTO */
    setmsg_("10", "After closing PHIGS, <inquire archive state value> should\
 return the archive state as ARCL.", 2L, 91L);
#endif /* NO_PROTO */
    arstat = -66;
    nqars (&arstat);
    L__1 = arstat == 0;
    ifpf_(&L__1);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("3 10", "After closing and re-opening PHIGS, the archive state s"
	    "hould be reported as ARCL.", 4L, 81L);
#else /* NO_PROTO */
    setmsg_("3 10", "After closing and re-opening PHIGS, the archive state s\
hould be reported as ARCL.", 4L, 81L);
#endif /* NO_PROTO */
    arstat = -66;
    nqars (&arstat);
    L__1 = arstat == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 11", "After closing and re-opening PHIGS, the set of open arc"
	    "hive files should be reported as empty.", 4L, 94L);
#else /* NO_PROTO */
    setmsg_("4 11", "After closing and re-opening PHIGS, the set of open arc\
hive files should be reported as empty.", 4L, 94L);
#endif /* NO_PROTO */
    nqarf (&c__0, &errind, &alisiz, &idum1, &idum2);
    L__1 = errind == 0 && alisiz == 0;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

