/* fort/05/01/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 05.01.01/03                           * */
/*  *    TEST TITLE : Opening and closing multiple          * */
/*  *                 workstations                          * */
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
    static integer n, id, id2;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_();
#endif /* NO_PROTO */
    static integer type[200];
    static char cdum1[1];
    static integer idum1, idum2, idum3, idum4, idum5, idum6, ident[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer maxct, owkid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     inmsg_(char *, ftnlen), nclwk (integer *);
    extern logical seteq_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), inmsg_(), nclwk ();
    extern logical seteq_();
#endif /* NO_PROTO */
    static logical setok;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static integer numacc, oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static logical openok;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer maxsim;
#ifndef NO_PROTO
    extern /* Subroutine */ int errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int errctl_();
#endif /* NO_PROTO */
    static logical wsclok;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt, wksval, setopn[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static logical wsopok;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk ();
#endif /* NO_PROTO */
    static integer numopw, owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkst (integer *), multws_(integer *, char *,
	     integer *, integer *, integer *, integer *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkst (), multws_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___19 = { 0, msg, 0, "(A,I5,A,I5)", 300, 1 };
    static icilist io___28 = { 0, msg, 0, "(3(A,I5))", 300, 1 };


/* workstation state */
    initgl_("05.01.01/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  numacc = number of accessible workstations (from configuration file) 
*/
    multws_(&c__0, "a", &numacc, &idum1, &idum2, &idum3, cdum1, 1L, 1L);
#ifndef NO_PROTO
    setmsg_("9 10", "The maximum number of simultaneously open workstations "
	    "returned by <inquire phigs facilities> should be at least 1.", 4L,
	     115L);
#else /* NO_PROTO */
    setmsg_("9 10", "The maximum number of simultaneously open workstations \
returned by <inquire phigs facilities> should be at least 1.", 4L, 115L);
#endif /* NO_PROTO */
/*  <inquire phigs facilities> to determine */
/*     maxsim = maximum number of simultaneously open workstations */
    nqphf (&c__1, &errind, &maxsim, &idum1, &idum2, &idum3, &idum4, &idum5, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
    L__1 = maxsim >= 1;
    ifpf_(&L__1);
    if (maxsim <= numacc) {
	maxct = maxsim;
#ifndef NO_PROTO
	setmsg_("9 11", "If the maximum number of simultaneously open workst"
		"ations is less than or equal to the number of accessible wor"
		"kstations, then it should be possible to have that maximum s"
		"imultaneously open.", 4L, 190L);
#else /* NO_PROTO */
	setmsg_("9 11", "If the maximum number of simultaneously open workst\
ations is less than or equal to the number of accessible workstations, then \
it should be possible to have that maximum simultaneously open.", 4L, 190L);
#endif /* NO_PROTO */
    } else {
	maxct = numacc;
#ifndef NO_PROTO
	setmsg_("9 11", "If the maximum number of simultaneously open workst"
		"ations is greater than the number of accessible workstations"
		", then it should be possible to open all accessible workstat"
		"ions simultaneously.", 4L, 191L);
#else /* NO_PROTO */
	setmsg_("9 11", "If the maximum number of simultaneously open workst\
ations is greater than the number of accessible workstations, then it should\
 be possible to open all accessible workstations simultaneously.", 4L, 191L);
#endif /* NO_PROTO */
    }
/*  *** *** *** *** ***   open workstations  *** *** *** *** *** */

/*  openok = true = workstation state value is open */
/*  setok  = true = set of open workstations is correct */
/*  ident(maxct) = array of workstation identifiers */
/*  type(maxct)  = array of specific workstation types */
    openok = TRUE_;
    setok = TRUE_;
    i__1 = maxct;
    for (id = 1; id <= i__1; ++id) {
	multws_(&id, "a", &idum1, &owkid, &oconid, &owtype, cdum1, 1L, 1L);
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
	nopwk (&owkid, &oconid, &owtype);
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___19);
	    do_fio(&c__1, "<Open workstation> failed with error code = ", 44L)
		    ;
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " for workstation identifier = ", 30L);
	    do_fio(&c__1, (char *)&owkid, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    maxct = id - 1;
	    goto L110;
	}
/*        <inquire workstation state value> to determine */
/*           wksval = workstation state value */
	nqwkst (&wksval);
	if (wksval != 1) {
	    openok = FALSE_;
	}
/* save opened workstations */
	ident[id - 1] = owkid;
/*        <inquire workstation connection and type> to determine */
/*           specwt = specific workstation type */
	nqwkc (&owkid, &errind, &idum1, &specwt);
	chkinq_("pqwkc", &errind, 5L);
	type[id - 1] = specwt;
/*        <inquire set of open workstations> to determine */
/*           setopn = set of open workstations */
	nqopwk (&c__0, &errind, &numopw, &idum1);
	chkinq_("pqopwk", &errind, 6L);
	if (numopw == id) {
	    i__2 = numopw;
	    for (n = 1; n <= i__2; ++n) {
		nqopwk (&n, &errind, &idum1, &setopn[n - 1]);
		chkinq_("pqopwk", &errind, 6L);
/* L120: */
	    }
	    if (seteq_(&numopw, ident, setopn)) {
/*              OK so far */
	    } else {
		setok = FALSE_;
	    }
	} else {
	    setok = FALSE_;
	}
/*  loop for next workstation */
/* L100: */
    }
    pass_();
/*  end_open_test: */
L110:
#ifndef NO_PROTO
    setmsg_("3 5", "If at least 1 workstation is open, the workstation state"
	    " value should be WSOP.", 3L, 78L);
#else /* NO_PROTO */
    setmsg_("3 5", "If at least 1 workstation is open, the workstation state\
 value should be WSOP.", 3L, 78L);
#endif /* NO_PROTO */
    ifpf_(&openok);
#ifndef NO_PROTO
    setmsg_("6 7", "As workstations are opened, the set of open workstations"
	    " should contain the identifiers of the open workstations and not"
	    "hing else.", 3L, 130L);
#else /* NO_PROTO */
    setmsg_("6 7", "As workstations are opened, the set of open workstations\
 should contain the identifiers of the open workstations and nothing else.", 
	    3L, 130L);
#endif /* NO_PROTO */
    ifpf_(&setok);
#ifndef NO_PROTO
    setmsg_("8", "Every open workstation should have a unique specific works"
	    "tation type.", 1L, 70L);
#else /* NO_PROTO */
    setmsg_("8", "Every open workstation should have a unique specific works\
tation type.", 1L, 70L);
#endif /* NO_PROTO */
    i__1 = maxct - 1;
    for (id = 1; id <= i__1; ++id) {
	i__2 = maxct;
	for (id2 = id + 1; id2 <= i__2; ++id2) {
	    if (type[id - 1] == type[id2 - 1]) {
		fail_();
		s_wsfi(&io___28);
		do_fio(&c__1, "Workstations ", 13L);
		do_fio(&c__1, (char *)&ident[id - 1], (ftnlen)sizeof(integer))
			;
		do_fio(&c__1, " and ", 5L);
		do_fio(&c__1, (char *)&ident[id2 - 1], (ftnlen)sizeof(integer)
			);
		do_fio(&c__1, " both have type = ", 18L);
		do_fio(&c__1, (char *)&type[id - 1], (ftnlen)sizeof(integer));

		e_wsfi();
		inmsg_(msg, 300L);
		goto L290;
	    }
/* L210: */
	}
/* L200: */
    }
    pass_();
/*  end_typedif */
L290:
/*  *** *** *** *** close workstations *** *** *** *** */

/*  wsopok = true = workstation state value WSOP is ok */
/*  wsclok = true = workstation state value WSCL is ok */
/*  setok  = true = set of open workstations is correct */
    wsopok = TRUE_;
    wsclok = TRUE_;
    setok = TRUE_;
    i__1 = maxct;
    for (id = 1; id <= i__1; ++id) {
	nclwk (&ident[id - 1]);
	nqwkst (&wksval);
	if (id < maxct) {
	    if (wksval != 1) {
		wsopok = FALSE_;
	    }
	} else {
	    if (wksval != 0) {
		wsclok = FALSE_;
	    }
	}
/*        <inquire set of open workstations> to determine */
/*           setopn = set of open workstations */
	nqopwk (&c__0, &errind, &numopw, &idum1);
	chkinq_("pqopwk", &errind, 6L);
	if (numopw == maxct - id) {
	    i__2 = numopw;
	    for (n = 1; n <= i__2; ++n) {
		nqopwk (&n, &errind, &idum1, &setopn[n - 1]);
		chkinq_("pqopwk", &errind, 6L);
/* L320: */
	    }
	    if (seteq_(&numopw, &ident[id], setopn)) {
/*              OK so far */
	    } else {
		setok = FALSE_;
	    }
	} else {
	    setok = FALSE_;
	}
/*  loop for next workstation */
/* L300: */
    }
#ifndef NO_PROTO
    setmsg_("3 5", "As workstations are closed, if at least one workstation "
	    "is still open, the workstation state value should be WSOP.", 3L, 
	    114L);
#else /* NO_PROTO */
    setmsg_("3 5", "As workstations are closed, if at least one workstation \
is still open, the workstation state value should be WSOP.", 3L, 114L);
#endif /* NO_PROTO */
    ifpf_(&wsopok);
#ifndef NO_PROTO
    setmsg_("3 4", "After the last open workstation is closed, the workstati"
	    "on state value should be WSCL.", 3L, 86L);
#else /* NO_PROTO */
    setmsg_("3 4", "After the last open workstation is closed, the workstati\
on state value should be WSCL.", 3L, 86L);
#endif /* NO_PROTO */
    ifpf_(&wsclok);
#ifndef NO_PROTO
    setmsg_("7 12", "As workstations are closed, the set of open workstation"
	    "s should contain the identifiers of the workstations left open a"
	    "nd nothing else.", 4L, 135L);
#else /* NO_PROTO */
    setmsg_("7 12", "As workstations are closed, the set of open workstation\
s should contain the identifiers of the workstations left open and nothing e\
lse.", 4L, 135L);
#endif /* NO_PROTO */
    ifpf_(&setok);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

