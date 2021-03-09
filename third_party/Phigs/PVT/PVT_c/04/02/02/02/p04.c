/* fort/04/02/02/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/04                        * */
/*  *    TEST TITLE : Validity of predefined polymarker     * */
/*  *                 bundles                               * */
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
    static integer mi, npe, pmi;
    static char msg[300];
    static integer pmi2;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, mpci, pmci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer namt;
    static real pdms;
    static integer pdmt;
    static real erms;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer pmci2, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3, rdum4[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real genms;
    static integer erbun;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real minms, maxms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nqpmf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nqpmf ();
#endif /* NO_PROTO */
    static real pmssf, nomms;
    static logical mserr;
    static integer mtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr ();
#endif /* NO_PROTO */
    static real pmssf2;
    static integer mtype2, erpmci;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, svpdci[5], specon;
    static logical marerr, colerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer erpmmt, specwt;
    static real svpdms[5];
    static integer svpdmt[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqppmr (
	    integer *, integer *, integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqppmr ();
#endif /* NO_PROTO */
    static integer rmtype;
    static logical rlzerr;

    /* Fortran I/O blocks */
    static icilist io___36 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___37 = { 0, msg, 0, "(A,F11.4,A)", 300, 1 };
    static icilist io___38 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___39 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___40 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___48 = { 0, msg, 0, "(A,I2,A,I2,A)", 300, 1 };


/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.02.02/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  mpci = maximum predefined color index */
    nqcf (&specwt, &errind, &idum1, &idum2, &mpci, rdum4);
    chkinq_("pqcf", &errind, 4L);
/*  Since color indices are numbered from 0, the maximum index is */
/*  one less than the number of predefined indices. */
    --mpci;
/*  npe = number of predefined entries */
/*  namt = number of available marker types */
/*  nomms = nominal marker size */
/*  minms = minimum marker size */
/*  maxms = maximum marker size */
    nqpmf (&specwt, &c__0, &errind, &namt, &idum2, &idum3, &nomms, &minms, &
	    maxms, &npe);
    chkinq_("pqpmf", &errind, 5L);
/*  marerr = marker type error found yet */
    marerr = FALSE_;
/*  mserr  = marker size error found yet */
    mserr = FALSE_;
/*  colerr = color error found yet */
    colerr = FALSE_;
/*  rlzerr = realized error found yet */
    rlzerr = FALSE_;
#ifndef NO_PROTO
    setmsg_("19 20 23", "<Inquire predefined polymarker representation> shou"
	    "ld be able to access as many entries as reported by <inquire pol"
	    "ymarker facilities>.", 8L, 135L);
#else /* NO_PROTO */
    setmsg_("19 20 23", "<Inquire predefined polymarker representation> shou\
ld be able to access as many entries as reported by <inquire polymarker faci\
lities>.", 8L, 135L);
#endif /* NO_PROTO */
    i__1 = npe;
    for (pmi = 1; pmi <= i__1; ++pmi) {
	nqppmr (&specwt, &pmi, &errind, &mtype, &pmssf, &pmci);
	if (errind != 0) {
	    fail_();
	    goto L150;
	}
	i__2 = abs(namt);
	for (mi = 1; mi <= i__2; ++mi) {
	    nqpmf (&specwt, &mi, &errind, &idum1, &rmtype, &idum3, &rdum1, &
		    rdum2, &rdum3, &npe);
	    chkinq_("pqpmf", &errind, 5L);
	    if (mtype == rmtype) {
		goto L60;
	    }
/* L50: */
	}
	marerr = TRUE_;
	erpmmt = mtype;
L60:
	genms = pmssf * nomms;
	if (genms < minms || genms > maxms) {
	    mserr = TRUE_;
	    erms = pmssf;
	}
	if (pmci < 0 || pmci > mpci) {
	    colerr = TRUE_;
	    erpmci = pmci;
	}
	nspmr (&globnu_1.wkid, &c__3, &mtype, &pmssf, &pmci);
	nqpmr (&globnu_1.wkid, &c__3, &c__1, &errind, &mtype2, &pmssf2, &
		pmci2);
	chkinq_("pqpmr", &errind, 5L);
	if (mtype == mtype2 && pmssf == pmssf2 && pmci == pmci2) {
/*           OK */
	} else {
	    rlzerr = TRUE_;
	    erbun = pmi;
	}
/* L100: */
    }
    pass_();
#ifndef NO_PROTO
    setmsg_("20 26", "All marker types in predefined polymarker bundles shou"
	    "ld themselves be in the list of available marker types.", 5L, 
	    109L);
#else /* NO_PROTO */
    setmsg_("20 26", "All marker types in predefined polymarker bundles shou\
ld themselves be in the list of available marker types.", 5L, 109L);
#endif /* NO_PROTO */
    if (marerr) {
	fail_();
	s_wsfi(&io___36);
	do_fio(&c__1, "Undefined marker type #", 23L);
	do_fio(&c__1, (char *)&erpmmt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 27", "All marker size scale factors in predefined polymarker"
	    " bundles should generate marker sizes within the minimum and max"
	    "imum marker sizes.", 5L, 136L);
#else /* NO_PROTO */
    setmsg_("20 27", "All marker size scale factors in predefined polymarker\
 bundles should generate marker sizes within the minimum and maximum marker \
sizes.", 5L, 136L);
#endif /* NO_PROTO */
    if (mserr) {
	fail_();
	s_wsfi(&io___37);
	do_fio(&c__1, "Unrealizable marker size scale factor, ", 39L);
	do_fio(&c__1, (char *)&erms, (ftnlen)sizeof(real));
	do_fio(&c__1, ", found in predefined bundle.", 29L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 28", "All color indices in predefined polymarker bundles sho"
	    "uld themselves be in the predefined color table.", 5L, 102L);
#else /* NO_PROTO */
    setmsg_("20 28", "All color indices in predefined polymarker bundles sho\
uld themselves be in the predefined color table.", 5L, 102L);
#endif /* NO_PROTO */
    if (colerr) {
	fail_();
	s_wsfi(&io___38);
	do_fio(&c__1, "Undefined color #", 17L);
	do_fio(&c__1, (char *)&erpmci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("15 26 27 28", "All aspects of all predefined polymarker bundles"
	    " should be reported as realizable by <inquire polymarker represe"
	    "ntation>.", 11L, 121L);
#else /* NO_PROTO */
    setmsg_("15 26 27 28", "All aspects of all predefined polymarker bundles\
 should be reported as realizable by <inquire polymarker representation>.", 
	    11L, 121L);
#endif /* NO_PROTO */
    if (rlzerr) {
	fail_();
	s_wsfi(&io___39);
	do_fio(&c__1, "Predefined bundle #", 19L);
	do_fio(&c__1, (char *)&erbun, (ftnlen)sizeof(integer));
	do_fio(&c__1, " not realized as set.", 21L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
L150:
    s_wsfi(&io___40);
    do_fio(&c__1, "PHIGS reported ", 15L);
    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
    do_fio(&c__1, " predefined polymarker bundles.", 31L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("19 21", "<Inquire polymarker facilities> should report at least"
	    " 5 predefined entries.", 5L, 76L);
#else /* NO_PROTO */
    setmsg_("19 21", "<Inquire polymarker facilities> should report at least\
 5 predefined entries.", 5L, 76L);
#endif /* NO_PROTO */
    if (npe < 5) {
	fail_();
	goto L666;
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 22", "The first five predefined polymarker bundle entries sh"
	    "ould all be mutually distinguishable.", 5L, 91L);
#else /* NO_PROTO */
    setmsg_("20 22", "The first five predefined polymarker bundle entries sh\
ould all be mutually distinguishable.", 5L, 91L);
#endif /* NO_PROTO */
/*  pdmt = predefined marker type */
/*  pdms = predefined marker size scale factor */
/*  pdci = predefined polymarker color index */
    for (pmi = 1; pmi <= 5; ++pmi) {
/*  get attributes for current bundle */
	nqppmr (&specwt, &pmi, &errind, &pdmt, &pdms, &pdci);
	chkinq_("pqppmr", &errind, 6L);
/*  compare current to all previous bundles */
	i__1 = pmi - 1;
	for (pmi2 = 1; pmi2 <= i__1; ++pmi2) {
	    if (svpdmt[pmi2 - 1] == pdmt && svpdms[pmi2 - 1] == pdms && 
		    svpdci[pmi2 - 1] == pdci) {
		fail_();
		s_wsfi(&io___48);
		do_fio(&c__1, "Polymarker bundle #", 19L);
		do_fio(&c__1, (char *)&pmi, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is indistinguishable from #", 28L);
		do_fio(&c__1, (char *)&pmi2, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L666;
	    }
/* L250: */
	}
/*  save current attributes */
	svpdmt[pmi - 1] = pdmt;
	svpdms[pmi - 1] = pdms;
	svpdci[pmi - 1] = pdci;
/* L200: */
    }
    pass_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

