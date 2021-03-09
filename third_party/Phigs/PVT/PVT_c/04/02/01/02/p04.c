/* fort/04/02/01/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.01.02/04                        * */
/*  *    TEST TITLE : Validity of predefined polyline       * */
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
    static integer li, npe, pli;
    static char msg[300];
    static integer pli2;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, plci, mpci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer nalt, pdlt;
    static real pdlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static real erlw;
    static integer plci2, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3, rdum4[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer erbun;
    static real genlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqplf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), nqwkc (integer *, integer *, integer *
	    , integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqplf (), nqwkc ();
#endif /* NO_PROTO */
    static real minlw, maxlw, nomlw, plwsf;
    static logical lwerr;
    static integer linty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nsplr (integer *, integer *, integer *, real *, integer *), 
	    nqplr (integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nsplr (), nqplr ();
#endif /* NO_PROTO */
    static real plwsf2;
    static integer linty2, erplci;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, svpdci[5], specon;
    static logical linerr, colerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer erpllt;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt, svpdlt[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static real svpdlw[5];
    static integer rlinty;
    static logical rlzerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpplr (integer *, integer *, integer *, 
	    integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpplr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___36 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___37 = { 0, msg, 0, "(A,F11.4,A)", 300, 1 };
    static icilist io___38 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___39 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___40 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___48 = { 0, msg, 0, "(A,I2,A,I2,A)", 300, 1 };


/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.01.02/04", 14L);
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
/*  nalt = number of available linetypes */
/*  nomlw = nominal linewidth */
/*  minlw = minimum linewidth */
/*  maxlw = maximum linewidth */
    nqplf (&specwt, &c__0, &errind, &nalt, &idum2, &idum3, &nomlw, &minlw, &
	    maxlw, &npe);
    chkinq_("pqplf", &errind, 5L);
/*  linerr = linetype error found yet */
    linerr = FALSE_;
/*  lwerr  = linewidth error found yet */
    lwerr = FALSE_;
/*  colerr = color error found yet */
    colerr = FALSE_;
/*  rlzerr = realized error found yet */
    rlzerr = FALSE_;
#ifndef NO_PROTO
    setmsg_("19 20 23", "<Inquire predefined polyline representation> should"
	    " be able to access as many entries as reported by <inquire polyl"
	    "ine facilities>.", 8L, 131L);
#else /* NO_PROTO */
    setmsg_("19 20 23", "<Inquire predefined polyline representation> should\
 be able to access as many entries as reported by <inquire polyline faciliti\
es>.", 8L, 131L);
#endif /* NO_PROTO */
    i__1 = npe;
    for (pli = 1; pli <= i__1; ++pli) {
	nqpplr (&specwt, &pli, &errind, &linty, &plwsf, &plci);
	if (errind != 0) {
	    fail_();
	    goto L150;
	}
	i__2 = abs(nalt);
	for (li = 1; li <= i__2; ++li) {
	    nqplf (&specwt, &li, &errind, &idum1, &rlinty, &idum3, &rdum1, &
		    rdum2, &rdum3, &npe);
	    chkinq_("pqplf", &errind, 5L);
	    if (linty == rlinty) {
		goto L60;
	    }
/* L50: */
	}
	linerr = TRUE_;
	erpllt = linty;
L60:
	genlw = plwsf * nomlw;
	if (genlw < minlw || genlw > maxlw) {
	    lwerr = TRUE_;
	    erlw = plwsf;
	}
	if (plci < 0 || plci > mpci) {
	    colerr = TRUE_;
	    erplci = plci;
	}
	nsplr (&globnu_1.wkid, &c__3, &linty, &plwsf, &plci);
	nqplr (&globnu_1.wkid, &c__3, &c__1, &errind, &linty2, &plwsf2, &
		plci2);
	chkinq_("pqplr", &errind, 5L);
	if (linty == linty2 && plwsf == plwsf2 && plci == plci2) {
/*           OK */
	} else {
	    rlzerr = TRUE_;
	    erbun = pli;
	}
/* L100: */
    }
    pass_();
#ifndef NO_PROTO
    setmsg_("20 26", "All linetypes in predefined polyline bundles should th"
	    "emselves be in the list of available linetypes.", 5L, 101L);
#else /* NO_PROTO */
    setmsg_("20 26", "All linetypes in predefined polyline bundles should th\
emselves be in the list of available linetypes.", 5L, 101L);
#endif /* NO_PROTO */
    if (linerr) {
	fail_();
	s_wsfi(&io___36);
	do_fio(&c__1, "Undefined linetype #", 20L);
	do_fio(&c__1, (char *)&erpllt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 27", "All linewidth scale factors in predefined polyline bun"
	    "dles should generate linewidths within the minimum and maximum l"
	    "inewidths.", 5L, 128L);
#else /* NO_PROTO */
    setmsg_("20 27", "All linewidth scale factors in predefined polyline bun\
dles should generate linewidths within the minimum and maximum linewidths.", 
	    5L, 128L);
#endif /* NO_PROTO */
    if (lwerr) {
	fail_();
	s_wsfi(&io___37);
	do_fio(&c__1, "Unrealizable linewidth scale factor, ", 37L);
	do_fio(&c__1, (char *)&erlw, (ftnlen)sizeof(real));
	do_fio(&c__1, ", found in predefined bundle.", 29L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 28", "All color indices in predefined polyline bundles shoul"
	    "d themselves be in the predefined color table.", 5L, 100L);
#else /* NO_PROTO */
    setmsg_("20 28", "All color indices in predefined polyline bundles shoul\
d themselves be in the predefined color table.", 5L, 100L);
#endif /* NO_PROTO */
    if (colerr) {
	fail_();
	s_wsfi(&io___38);
	do_fio(&c__1, "Undefined color #", 17L);
	do_fio(&c__1, (char *)&erplci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("15 26 27 28", "All aspects of all predefined polyline bundles s"
	    "hould be reported as realizable by <inquire polyline representat"
	    "ion>.", 11L, 117L);
#else /* NO_PROTO */
    setmsg_("15 26 27 28", "All aspects of all predefined polyline bundles s\
hould be reported as realizable by <inquire polyline representation>.", 11L, 
	    117L);
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
    do_fio(&c__1, " predefined polyline bundles.", 29L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("19 21", "<Inquire polyline facilities> should report at least 5"
	    " predefined entries.", 5L, 74L);
#else /* NO_PROTO */
    setmsg_("19 21", "<Inquire polyline facilities> should report at least 5\
 predefined entries.", 5L, 74L);
#endif /* NO_PROTO */
    if (npe < 5) {
	fail_();
	goto L666;
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 22", "The first five predefined polyline bundle entries shou"
	    "ld all be mutually distinguishable.", 5L, 89L);
#else /* NO_PROTO */
    setmsg_("20 22", "The first five predefined polyline bundle entries shou\
ld all be mutually distinguishable.", 5L, 89L);
#endif /* NO_PROTO */
/*  pdlt = predefined linetype */
/*  pdlw = predefined linewidth scale factor */
/*  pdci = predefined polyline color index */
    for (pli = 1; pli <= 5; ++pli) {
/*  get attributes for current bundle */
	nqpplr (&specwt, &pli, &errind, &pdlt, &pdlw, &pdci);
	chkinq_("pqpplr", &errind, 6L);
/*  compare current to all previous bundles */
	i__1 = pli - 1;
	for (pli2 = 1; pli2 <= i__1; ++pli2) {
	    if (svpdlt[pli2 - 1] == pdlt && svpdlw[pli2 - 1] == pdlw && 
		    svpdci[pli2 - 1] == pdci) {
		fail_();
		s_wsfi(&io___48);
		do_fio(&c__1, "Polyline bundle #", 17L);
		do_fio(&c__1, (char *)&pli, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is indistinguishable from #", 28L);
		do_fio(&c__1, (char *)&pli2, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L666;
	    }
/* L250: */
	}
/*  save current attributes */
	svpdlt[pli - 1] = pdlt;
	svpdlw[pli - 1] = pdlw;
	svpdci[pli - 1] = pdci;
/* L200: */
    }
    pass_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

