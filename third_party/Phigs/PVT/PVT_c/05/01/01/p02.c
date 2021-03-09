/* fort/05/01/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.01.01/02                           * */
/*  *    TEST TITLE : Simple open and close of a single     * */
/*  *                 workstation                           * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer n;
    static char msg[900];
    static integer iwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static char cdum1[1];
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer nwkid, owkid;
    static logical valok;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static logical inset;
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
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static logical oneopn, typdif, wkclos, wkopen;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt, wksval;
    static logical noopwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqopwk (
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqopwk ();
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
    static icilist io___10 = { 0, msg, 0, "(A, A, I5)", 900, 1 };


/* workstation category */
/* workstation state */
    initgl_("05.01.01/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  wkopen = true = workstation state is WSOP */
/*  wkclos = true = workstation state is WSCL */
/*  oneopn = true = one workstation identifier in 'set of open */
/*                  workstations' */
/*  inset  = true = correct workstation identifier in 'set of open */
/*                  workstations' */
/*  noopwk = true = no workstations open */
/*  valok  = true = state value either WSOP or WSCL */
/*  typdif = true = workstation type different */
    wkopen = TRUE_;
    wkclos = TRUE_;
    oneopn = TRUE_;
    inset = TRUE_;
    noopwk = TRUE_;
    valok = TRUE_;
    typdif = TRUE_;
    wksval = -6;
/*  <inquire workstation state value> to determine */
/*     wksval = workstation state value */
    nqwkst (&wksval);
    if (wksval != 0 && wksval != 1) {
	valok = FALSE_;
	s_wsfi(&io___10);
	do_fio(&c__1, "Workstation state value ", 24L);
	do_fio(&c__1, "invalid, reported as ", 21L);
	do_fio(&c__1, (char *)&wksval, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 900L);
    }
/*  get each accessible workstation */
    multws_(&c__0, "a", &numacc, &idum1, &idum2, &idum3, cdum1, 1L, 1L);
    i__1 = numacc;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	multws_(&iwk, "a", &idum1, &owkid, &oconid, &owtype, cdum1, 1L, 1L);
	nopwk (&owkid, &oconid, &owtype);
	wksval = -6;
/*     <inquire workstation state value> to determine wksval */
	nqwkst (&wksval);
	if (wksval != 1) {
	    wkopen = FALSE_;
	    if (wksval != 0) {
		valok = FALSE_;
	    }
	}
/*     <inquire set of open workstations> to determine */
/*        numopw = number of open workstations */
	nqopwk (&c__0, &errind, &numopw, &idum1);
	chkinq_("pqopwk", &errind, 6L);
	if (numopw != 1) {
	    oneopn = FALSE_;
	}
/* check that owkid is in set */
	i__2 = numopw;
	for (n = 1; n <= i__2; ++n) {
	    nqopwk (&n, &errind, &idum1, &nwkid);
	    chkinq_("pqopwk", &errind, 6L);
	    if (owkid == nwkid) {
		goto L110;
	    }
/* L100: */
	}
	inset = FALSE_;
L110:
/*     <inquire workstation connection and type> to determine */
/*        specwt = specific workstation type */
	nqwkc (&owkid, &errind, &idum1, &specwt);
	chkinq_("pqwkc", &errind, 5L);
	if (specwt == owtype) {
	    typdif = FALSE_;
	}
/* close workstation */
	nclwk (&owkid);
	nqopwk (&c__0, &errind, &numopw, &idum1);
	chkinq_("pqopwk", &errind, 6L);
	if (numopw != 0) {
	    noopwk = FALSE_;
	}
	wksval = -6;
	nqwkst (&wksval);
	if (wksval != 0) {
	    wkclos = FALSE_;
	    if (wksval != 1) {
		valok = FALSE_;
	    }
	}
/*  next workstation */
/* L200: */
    }
/*  *** *** *** actual tests go here *** *** */
#ifndef NO_PROTO
    setmsg_("3 4 5", "In all circumstances, the reported workstation state v"
	    "alues should be either WSOP or WSCL.", 5L, 90L);
#else /* NO_PROTO */
    setmsg_("3 4 5", "In all circumstances, the reported workstation state v\
alues should be either WSOP or WSCL.", 5L, 90L);
#endif /* NO_PROTO */
    ifpf_(&valok);
#ifndef NO_PROTO
    setmsg_("3 5", "After <open workstation>, the workstation state value sh"
	    "ould be WSOP.", 3L, 69L);
#else /* NO_PROTO */
    setmsg_("3 5", "After <open workstation>, the workstation state value sh\
ould be WSOP.", 3L, 69L);
#endif /* NO_PROTO */
    ifpf_(&wkopen);
#ifndef NO_PROTO
    setmsg_("6 7", "If no workstations are open, then immediately after <ope"
	    "n workstation>, the number of workstation identifiers in the set"
	    " of open workstations should be 1.", 3L, 154L);
#else /* NO_PROTO */
    setmsg_("6 7", "If no workstations are open, then immediately after <ope\
n workstation>, the number of workstation identifiers in the set of open wor\
kstations should be 1.", 3L, 154L);
#endif /* NO_PROTO */
    ifpf_(&oneopn);
#ifndef NO_PROTO
    setmsg_("6 7", "Immediately after <open workstation>, the set of open wo"
	    "rkstations should contain the workstation identifier just opened."
	    , 3L, 121L);
#else /* NO_PROTO */
    setmsg_("6 7", "Immediately after <open workstation>, the set of open wo\
rkstations should contain the workstation identifier just opened.", 3L, 121L);

#endif /* NO_PROTO */
    ifpf_(&inset);
#ifndef NO_PROTO
    setmsg_("8", "The specific workstation type of an open workstation shoul"
	    "d be different from the generic type with which it was opened.", 
	    1L, 120L);
#else /* NO_PROTO */
    setmsg_("8", "The specific workstation type of an open workstation shoul\
d be different from the generic type with which it was opened.", 1L, 120L);
#endif /* NO_PROTO */
    ifpf_(&typdif);
#ifndef NO_PROTO
    setmsg_("7 12", "If only one workstation is open, then <close workstatio"
	    "n> should result in the set of open workstations being empty.", 
	    4L, 116L);
#else /* NO_PROTO */
    setmsg_("7 12", "If only one workstation is open, then <close workstatio\
n> should result in the set of open workstations being empty.", 4L, 116L);
#endif /* NO_PROTO */
    ifpf_(&noopwk);
#ifndef NO_PROTO
    setmsg_("3 4", "If no workstations are open, then the workstation state "
	    "value should be WSCL.", 3L, 77L);
#else /* NO_PROTO */
    setmsg_("3 4", "If no workstations are open, then the workstation state \
value should be WSCL.", 3L, 77L);
#endif /* NO_PROTO */
    ifpf_(&wkclos);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

