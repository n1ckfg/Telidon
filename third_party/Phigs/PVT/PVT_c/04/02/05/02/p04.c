/* fort/04/02/05/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.05.02/04                        * */
/*  *    TEST TITLE : Validity of predefined interior       * */
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
    static integer hi, ii, ii2, ici, npe;
    static char msg[300];
    static integer ici2;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, mpci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer pdin, mphi, pdsi;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer mppi;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nqir (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nqir ();
#endif /* NO_PROTO */
    static integer ints;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsir ();
#endif /* NO_PROTO */
    static integer styi, idum1, idum2, idum3, idum4;
    static real rdum1[9];
    static integer ints2, styi2, erici, erhat;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqpaf (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqpaf ();
#endif /* NO_PROTO */
    static integer erbun, erpat;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nqpir (integer *, integer *, 
	    integer *, integer *, integer *, integer *), nopwk (integer *, 
	    integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nqpir (), nopwk ();
    extern integer iarfnd_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, laints[90], naints, thishi, thisis, erints, svpdin[
	    5], svpdci[5], hstyle[90], svpdsi[5], specwt, specon;
    static logical colerr, paterr, haterr, rlzerr, laserr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setmsg_();
#endif /* NO_PROTO */
    static logical styerr;

    /* Fortran I/O blocks */
    static icilist io___38 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___39 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___40 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___41 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___42 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___43 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___51 = { 0, msg, 0, "(A,I2,A,I2,A)", 300, 1 };


/* interior style */
/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.02/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* get maximum predefined color index and */
/* adjust for color index starting at 0 (not 1) */
    nqcf (&specwt, &errind, &idum1, &idum2, &mpci, rdum1);
    chkinq_("pqcf", &errind, 4L);
    --mpci;
/* get maximum predefined pattern index */
    nqpaf (&specwt, &errind, &mppi);
    chkinq_("pqpaf", &errind, 5L);
/* get number of predefined indices (style, hatch, bundle) */
/* naints  = number of available style indices */
/* laints  = list of available style indices */
/* mphi    = number of available hatch indices */
/* npe     = number of predefined entries */
    nqif (&specwt, &c__0, &c__0, &errind, &naints, &idum1, &mphi, &idum2, &
	    npe);
    chkinq_("pqif", &errind, 4L);
    i__1 = naints;
    for (ii = 1; ii <= i__1; ++ii) {
	nqif (&specwt, &ii, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	laints[ii - 1] = thisis;
/* L100: */
    }
    i__1 = abs(mphi);
    for (hi = 1; hi <= i__1; ++hi) {
	nqif (&specwt, &c__0, &hi, &errind, &idum1, &idum2, &idum3, &thishi, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	hstyle[hi - 1] = thishi;
/* L200: */
    }
/*  error found yet (color, style, pattern, hatch, list of available */
/*                   styles) */
    colerr = FALSE_;
    rlzerr = FALSE_;
    styerr = FALSE_;
    paterr = FALSE_;
    haterr = FALSE_;
    laserr = FALSE_;
#ifndef NO_PROTO
    setmsg_("20 21 24", "<Inquire predefined interior representation> should"
	    " be able to access as many entries as reported by <inquire inter"
	    "ior facilities>.", 8L, 131L);
#else /* NO_PROTO */
    setmsg_("20 21 24", "<Inquire predefined interior representation> should\
 be able to access as many entries as reported by <inquire interior faciliti\
es>.", 8L, 131L);
#endif /* NO_PROTO */
    i__1 = npe;
    for (ii = 1; ii <= i__1; ++ii) {
	nqpir (&specwt, &ii, &errind, &ints, &styi, &ici);
	if (errind != 0) {
	    fail_();
	    goto L400;
	}
/* check interior color index */
	if (ici < 0 || ici > mpci) {
	    colerr = TRUE_;
	    erici = ici;
	}
	nsir (&globnu_1.wkid, &c__3, &ints, &styi, &ici);
	nqir (&globnu_1.wkid, &c__3, &c__1, &errind, &ints2, &styi2, &ici2);
	chkinq_("pqir", &errind, 4L);
	if (ints == ints2 && styi == styi2 && ici == ici2) {
/*           OK */
	} else {
	    rlzerr = TRUE_;
	    erbun = ii;
	}
/* check list of available interior styles */
	if (iarfnd_(&ints, &naints, laints) <= 0) {
	    laserr = TRUE_;
	    erints = ints;
	}
/* check PATTERN interior style */
	if (ints == 2) {
	    if (styi < 1 || styi > mppi) {
		paterr = TRUE_;
		erpat = styi;
	    }
	}
/* check HATCH interior style */
	if (ints == 3) {
/* check list of available interior styles */
	    i__2 = abs(mphi);
	    if (iarfnd_(&styi, &i__2, hstyle) <= 0) {
		haterr = TRUE_;
		erhat = styi;
	    }
	}
/* L300: */
    }
    pass_();
#ifndef NO_PROTO
    setmsg_("21 30", "All color indices in predefined interior bundles shoul"
	    "d themselves be in the predefined color table.", 5L, 100L);
#else /* NO_PROTO */
    setmsg_("21 30", "All color indices in predefined interior bundles shoul\
d themselves be in the predefined color table.", 5L, 100L);
#endif /* NO_PROTO */
    if (colerr) {
	fail_();
	s_wsfi(&io___38);
	do_fio(&c__1, "Undefined color #", 17L);
	do_fio(&c__1, (char *)&erici, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("16 27 28 29 30", "All aspects of all predefined interior bundle"
	    "s should be reported as realizable by <inquire interior represen"
	    "tation>.", 14L, 117L);
#else /* NO_PROTO */
    setmsg_("16 27 28 29 30", "All aspects of all predefined interior bundle\
s should be reported as realizable by <inquire interior representation>.", 
	    14L, 117L);
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
#ifndef NO_PROTO
    setmsg_("21 27", "All interior styles in predefined bundles should thems"
	    "elves be in the list of available interior styles.", 5L, 104L);
#else /* NO_PROTO */
    setmsg_("21 27", "All interior styles in predefined bundles should thems\
elves be in the list of available interior styles.", 5L, 104L);
#endif /* NO_PROTO */
    if (laserr) {
	fail_();
	s_wsfi(&io___40);
	do_fio(&c__1, "Undefined interior style", 24L);
	do_fio(&c__1, (char *)&erints, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("21 28", "For PATTERN interior style, all pattern indices in pre"
	    "defined interior bundles should themselves be in the predefined "
	    "pattern table.", 5L, 132L);
#else /* NO_PROTO */
    setmsg_("21 28", "For PATTERN interior style, all pattern indices in pre\
defined interior bundles should themselves be in the predefined pattern tabl\
e.", 5L, 132L);
#endif /* NO_PROTO */
    if (paterr) {
	fail_();
	s_wsfi(&io___41);
	do_fio(&c__1, "Undefined pattern index", 23L);
	do_fio(&c__1, (char *)&erpat, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("21 29", "For HATCH interior style, all hatch indices in predefi"
	    "ned interior bundles should themselves be in the list of availab"
	    "le hatch styles.", 5L, 134L);
#else /* NO_PROTO */
    setmsg_("21 29", "For HATCH interior style, all hatch indices in predefi\
ned interior bundles should themselves be in the list of available hatch sty\
les.", 5L, 134L);
#endif /* NO_PROTO */
    if (haterr) {
	fail_();
	s_wsfi(&io___42);
	do_fio(&c__1, "Undefined interior style", 24L);
	do_fio(&c__1, (char *)&erhat, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in list of available hatch styles.", 41L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
L400:
    s_wsfi(&io___43);
    do_fio(&c__1, "PHIGS reported ", 15L);
    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
    do_fio(&c__1, " predefined interior bundles.", 29L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("20 22", "<Inquire interior facilities> should report at least 5"
	    " predefined entries.", 5L, 74L);
#else /* NO_PROTO */
    setmsg_("20 22", "<Inquire interior facilities> should report at least 5\
 predefined entries.", 5L, 74L);
#endif /* NO_PROTO */
    if (npe < 5) {
	fail_();
	goto L666;
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("21 23", "The first five predefined interior bundle entries shou"
	    "ld all be mutually distinguishable.", 5L, 89L);
#else /* NO_PROTO */
    setmsg_("21 23", "The first five predefined interior bundle entries shou\
ld all be mutually distinguishable.", 5L, 89L);
#endif /* NO_PROTO */
/*  pdin = predefined interior style */
/*  pdsi = predefined interior style index */
/*  pdci = predefined interior color index */
    for (ii = 1; ii <= 5; ++ii) {
/*  get attributes for current bundle */
	nqpir (&specwt, &ii, &errind, &pdin, &pdsi, &pdci);
	chkinq_("pqpir", &errind, 5L);
/*  compare current to all previous bundles */
	i__1 = ii - 1;
	for (ii2 = 1; ii2 <= i__1; ++ii2) {
	    if (svpdin[ii2 - 1] == pdin && svpdsi[ii2 - 1] == pdsi && svpdci[
		    ii2 - 1] == pdci) {
		fail_();
		s_wsfi(&io___51);
		do_fio(&c__1, "Interior bundle #", 17L);
		do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is indistinguishable from #", 28L);
		do_fio(&c__1, (char *)&ii2, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L666;
	    }
/* L500: */
	}
/*  save current attributes */
	svpdin[ii - 1] = pdin;
	svpdsi[ii - 1] = pdsi;
	svpdci[ii - 1] = pdci;
/* L550: */
    }
    pass_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

