/* fort/04/02/05/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.05.03/04                        * */
/*  *    TEST TITLE : Validity of predefined edge           * */
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
    static integer edi, npe;
    static char msg[300];
    static integer edi2, edci, edfl;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdef, pdci, naet, mpci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer pdet;
    static real pdew, erew, ewsf;
    static integer edty;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer edci2, edfl2, idum1, idum2, idum3;
    static real ewsf2;
    static integer edty2;
    static real rdum1, rdum2, rdum3, rdum4[9];
    static integer erflg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_();
#endif /* NO_PROTO */
    static real genew;
    static integer erbun;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedr (), nsedr (), inmsg_();
#endif /* NO_PROTO */
    static real minew, maxew;
    static logical ewerr;
    static real nomew;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer redty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer eredci;
    static logical edgerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static logical flgerr;
    static integer errind, specon, eredty, svpdci[5], svpdef[5];
    static logical colerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqpedr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), nqpedr ();
#endif /* NO_PROTO */
    static integer specwt, svpdet[5];
    static real svpdew[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static logical rlzerr;

    /* Fortran I/O blocks */
    static icilist io___40 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___41 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___42 = { 0, msg, 0, "(A,F11.4,A)", 300, 1 };
    static icilist io___43 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___44 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___45 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___54 = { 0, msg, 0, "(A,I2,A,I2,A)", 300, 1 };


/* off/on switch for edge flag and error handling mode */
/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.03/04", 14L);
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
/*  naet = number of available edgetypes */
/*  nomew = nominal edgewidth */
/*  minew = minimum edgewidth */
/*  maxew = maximum edgewidth */
    nqedf (&specwt, &c__0, &errind, &naet, &idum1, &idum2, &nomew, &minew, &
	    maxew, &npe);
    chkinq_("pqedf", &errind, 5L);
/*  edge flag error found yet */
    flgerr = FALSE_;
/*  edgetype error found yet */
    edgerr = FALSE_;
/*  edgewidth error found yet */
    ewerr = FALSE_;
/*  color error found yet */
    colerr = FALSE_;
/*  rlzerr = realized error found yet */
    rlzerr = FALSE_;
#ifndef NO_PROTO
    setmsg_("19 20 23", "<Inquire predefined edge representation> should be "
	    "able to access as many entries as reported by <inquire edge faci"
	    "lities>.", 8L, 123L);
#else /* NO_PROTO */
    setmsg_("19 20 23", "<Inquire predefined edge representation> should be \
able to access as many entries as reported by <inquire edge facilities>.", 8L,
	     123L);
#endif /* NO_PROTO */
    i__1 = npe;
    for (edi = 1; edi <= i__1; ++edi) {
	nqpedr (&specwt, &edi, &errind, &edfl, &edty, &ewsf, &edci);
	if (errind != 0) {
	    fail_();
	    goto L150;
	}
	if (edfl < 0 || edfl > 1) {
	    flgerr = TRUE_;
	    erflg = edfl;
	}
	i__2 = naet;
	for (edi2 = 1; edi2 <= i__2; ++edi2) {
	    nqedf (&specwt, &edi2, &errind, &idum1, &redty, &idum2, &rdum1, &
		    rdum2, &rdum3, &idum3);
	    chkinq_("pqedf", &errind, 5L);
	    if (edty == redty) {
		goto L60;
	    }
/* L50: */
	}
	edgerr = TRUE_;
	eredty = edty;
L60:
	genew = ewsf * nomew;
	if (genew < minew || genew > maxew) {
	    ewerr = TRUE_;
	    erew = ewsf;
	}
	if (edci < 0 || edci > mpci) {
	    colerr = TRUE_;
	    eredci = edci;
	}
	nsedr (&globnu_1.wkid, &c__3, &edfl, &edty, &ewsf, &edci);
	nqedr (&globnu_1.wkid, &c__3, &c__1, &errind, &edfl2, &edty2, &ewsf2, 
		&edci2);
	chkinq_("pqedr", &errind, 5L);
	if (edfl == edfl2 && edty == edty2 && ewsf == ewsf2 && edci == edci2) 
		{
/*           OK */
	} else {
	    rlzerr = TRUE_;
	    erbun = edi;
	}
/* L100: */
    }
    pass_();
#ifndef NO_PROTO
    setmsg_("20 29", "The edge flag in predefined edge bundles should be eit"
	    "her OFF or ON.", 5L, 68L);
#else /* NO_PROTO */
    setmsg_("20 29", "The edge flag in predefined edge bundles should be eit\
her OFF or ON.", 5L, 68L);
#endif /* NO_PROTO */
    if (flgerr) {
	fail_();
	s_wsfi(&io___40);
	do_fio(&c__1, "Undefined edge flag", 19L);
	do_fio(&c__1, (char *)&erflg, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 26", "All edgetypes in predefined edge bundles should themse"
	    "lves be in the list of available edgetypes.", 5L, 97L);
#else /* NO_PROTO */
    setmsg_("20 26", "All edgetypes in predefined edge bundles should themse\
lves be in the list of available edgetypes.", 5L, 97L);
#endif /* NO_PROTO */
    if (edgerr) {
	fail_();
	s_wsfi(&io___41);
	do_fio(&c__1, "Undefined edgetype #", 20L);
	do_fio(&c__1, (char *)&eredty, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 27", "All edgewidth scale factors in predefined edge bundles"
	    " should generate edgewidths within the minimum and maximum edgew"
	    "idths.", 5L, 124L);
#else /* NO_PROTO */
    setmsg_("20 27", "All edgewidth scale factors in predefined edge bundles\
 should generate edgewidths within the minimum and maximum edgewidths.", 5L, 
	    124L);
#endif /* NO_PROTO */
    if (ewerr) {
	fail_();
	s_wsfi(&io___42);
	do_fio(&c__1, "Unrealizable edgewidth scale factor, ", 37L);
	do_fio(&c__1, (char *)&erew, (ftnlen)sizeof(real));
	do_fio(&c__1, ", found in predefined bundle.", 29L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 28", "All color indices in predefined edge bundles should th"
	    "emselves be in the predefined color table.", 5L, 96L);
#else /* NO_PROTO */
    setmsg_("20 28", "All color indices in predefined edge bundles should th\
emselves be in the predefined color table.", 5L, 96L);
#endif /* NO_PROTO */
    if (colerr) {
	fail_();
	s_wsfi(&io___43);
	do_fio(&c__1, "Undefined color #", 17L);
	do_fio(&c__1, (char *)&eredci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("15 26 27 28 29", "All aspects of all predefined edge bundles sh"
	    "ould be reported as realizable by <inquire edge representation>.",
	     14L, 109L);
#else /* NO_PROTO */
    setmsg_("15 26 27 28 29", "All aspects of all predefined edge bundles sh\
ould be reported as realizable by <inquire edge representation>.", 14L, 109L);

#endif /* NO_PROTO */
    if (rlzerr) {
	fail_();
	s_wsfi(&io___44);
	do_fio(&c__1, "Predefined bundle #", 19L);
	do_fio(&c__1, (char *)&erbun, (ftnlen)sizeof(integer));
	do_fio(&c__1, " not realized as set.", 21L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
L150:
    s_wsfi(&io___45);
    do_fio(&c__1, "PHIGS reported ", 15L);
    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
    do_fio(&c__1, " predefined edge bundles.", 25L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("19 21", "<Inquire edge facilities> should report at least 5 pre"
	    "defined entries.", 5L, 70L);
#else /* NO_PROTO */
    setmsg_("19 21", "<Inquire edge facilities> should report at least 5 pre\
defined entries.", 5L, 70L);
#endif /* NO_PROTO */
    if (npe < 5) {
	fail_();
	goto L666;
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 22", "The first five predefined edge bundle entries should a"
	    "ll be mutually distinguishable.", 5L, 85L);
#else /* NO_PROTO */
    setmsg_("20 22", "The first five predefined edge bundle entries should a\
ll be mutually distinguishable.", 5L, 85L);
#endif /* NO_PROTO */
/*  pdef = predefined edge flag */
/*  pdet = predefined edgetype */
/*  pdew = predefined edgewidth scale factor */
/*  pdci = predefined edge color index */
    for (edi = 1; edi <= 5; ++edi) {
/*  get attributes for current bundle */
	nqpedr (&specwt, &edi, &errind, &pdef, &pdet, &pdew, &pdci);
	chkinq_("pqpedr", &errind, 6L);
/*  compare current to all previous bundles */
	i__1 = edi - 1;
	for (edi2 = 1; edi2 <= i__1; ++edi2) {
	    if (svpdef[edi2 - 1] == pdef && svpdet[edi2 - 1] == pdet && 
		    svpdew[edi2 - 1] == pdew && svpdci[edi2 - 1] == pdci) {
		fail_();
		s_wsfi(&io___54);
		do_fio(&c__1, "Edge bundle #", 13L);
		do_fio(&c__1, (char *)&edi, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is indistinguishable from #", 28L);
		do_fio(&c__1, (char *)&edi2, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L666;
	    }
/* L250: */
	}
/*  save current attributes */
	svpdef[edi - 1] = pdef;
	svpdet[edi - 1] = pdet;
	svpdew[edi - 1] = pdew;
	svpdci[edi - 1] = pdci;
/* L200: */
    }
    pass_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

