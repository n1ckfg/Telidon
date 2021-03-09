/* fort/04/02/03/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.03.02/04                        * */
/*  *    TEST TITLE : Validity of predefined text           * */
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
    static integer npe;
    static char msg[300];
    static integer fpx, txi, txi2;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, pdfn, mpci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static real pcex, rcex;
    static integer pprc, pdpr;
    static real pcsp;
    static integer txci;
    static real rcsp, pdsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static real pdxp;
    static integer idum1, idum2, idum3, idum4, idum5, idum6;
    static real rdum1, rdum2, rdum3, rdum4, rdum5[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real ercex;
    static integer rprec, erbun;
    static logical fperr;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer numfp, pfont;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer rfont, rtxci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nqtxf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, real *, 
	    integer *), nqtxr (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *), nstxr (integer *
	    , integer *, integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nqtxf (), nqtxr (), nstxr ();
#endif /* NO_PROTO */
    static integer erprec, avprec[1000];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, svpdci[6], erfont, ertxci, avfont[1000], svpdfn[6],
	     specon;
    static real mincex, maxcex;
    static integer specwt;
    static logical cexerr, colerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer svpdpr[6];
    static real svpdsp[6];
    static logical rlzerr;
    static real svpdxp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqptxr (
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqptxr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___44 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___45 = { 0, msg, 0, "(A,F11.4,A)", 300, 1 };
    static icilist io___46 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___47 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___48 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___60 = { 0, msg, 0, "(A,I2,A,I2,A)", 300, 1 };


/* text precision */
/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.03.02/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqcf (&specwt, &errind, &idum1, &idum2, &mpci, rdum5);
    chkinq_("pqcf", &errind, 4L);
/*  Since color indices are numbered from 0, the maximum index is */
/*  one less than the number of predefined indices. */
    --mpci;
/*  npe = number of predefined entries */
    nqtxf (&specwt, &c__0, &errind, &numfp, &idum2, &idum3, &idum4, &rdum1, &
	    rdum2, &idum5, &mincex, &maxcex, &npe);
    chkinq_("pqtxf", &errind, 5L);
/* create list of font-precision pairs */
    i__1 = numfp;
    for (fpx = 1; fpx <= i__1; ++fpx) {
	nqtxf (&specwt, &fpx, &errind, &idum1, &avfont[fpx - 1], &avprec[fpx 
		- 1], &idum4, &rdum1, &rdum2, &idum5, &rdum3, &rdum4, &idum6);

	chkinq_("pqtxf", &errind, 5L);
/* L20: */
    }
/*  font/precision error found yet */
    fperr = FALSE_;
/*  character expansion factor error found yet */
    cexerr = FALSE_;
/*  color error found yet */
    colerr = FALSE_;
/*  realized  error found yet */
    rlzerr = FALSE_;
#ifndef NO_PROTO
    setmsg_("19 20 23", "<Inquire predefined text representation> should be "
	    "able to access as many entries as reported by <inquire text faci"
	    "lities>.", 8L, 123L);
#else /* NO_PROTO */
    setmsg_("19 20 23", "<Inquire predefined text representation> should be \
able to access as many entries as reported by <inquire text facilities>.", 8L,
	     123L);
#endif /* NO_PROTO */
    i__1 = npe;
    for (txi = 1; txi <= i__1; ++txi) {
	nqptxr (&specwt, &txi, &errind, &pfont, &pprc, &pcex, &pcsp, &txci);
	if (errind != 0) {
	    fail_();
	    goto L150;
	}
/* check that font & precision are available - note that list of avail
able */
/* fopnt/precision pairs need only contain highest precision. */
	i__2 = numfp;
	for (fpx = 1; fpx <= i__2; ++fpx) {
	    if (pfont == avfont[fpx - 1] && pprc <= avprec[fpx - 1]) {
		goto L120;
	    }
/* L110: */
	}
	fperr = TRUE_;
	erfont = pfont;
	erprec = pprc;
L120:
/* check char-exp-factor */
	if (pprc != 2 && (pcex < mincex || pcex > maxcex)) {
	    cexerr = TRUE_;
	    ercex = pcex;
	}
/* check text color index */
	if (txci < 0 || txci > mpci) {
	    colerr = TRUE_;
	    ertxci = txci;
	}
/* set text representation #3 */
	nstxr (&globnu_1.wkid, &c__3, &pfont, &pprc, &pcex, &pcsp, &txci);
	nqtxr (&globnu_1.wkid, &c__3, &c__1, &errind, &rfont, &rprec, &rcex, &
		rcsp, &rtxci);
	chkinq_("pqtxr", &errind, 5L);
	if (rfont != pfont || rprec != pprc || rcex != pcex || rcsp != pcsp ||
		 rtxci != txci) {
	    rlzerr = TRUE_;
	    erbun = txi;
	}
/* L100: */
    }
    pass_();
#ifndef NO_PROTO
    setmsg_("20 26", "All font-precision pairs in predefined text bundles sh"
	    "ould be supported by an entry in the list of text font-precision"
	    " pairs.", 5L, 125L);
#else /* NO_PROTO */
    setmsg_("20 26", "All font-precision pairs in predefined text bundles sh\
ould be supported by an entry in the list of text font-precision pairs.", 5L, 
	    125L);
#endif /* NO_PROTO */
    if (fperr) {
	fail_();
	s_wsfi(&io___44);
	do_fio(&c__1, "Unsupported font/precision: ", 28L);
	do_fio(&c__1, (char *)&erfont, (ftnlen)sizeof(integer));
	do_fio(&c__1, "/", 1L);
	do_fio(&c__1, (char *)&erprec, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 27", "All character expansion factors in predefined text bun"
	    "dles should be within the reported minimum and maximum character"
	    " expansion factors for non-STROKE precision.", 5L, 162L);
#else /* NO_PROTO */
    setmsg_("20 27", "All character expansion factors in predefined text bun\
dles should be within the reported minimum and maximum character expansion f\
actors for non-STROKE precision.", 5L, 162L);
#endif /* NO_PROTO */
    if (cexerr) {
	fail_();
	s_wsfi(&io___45);
	do_fio(&c__1, "Out-of-range character expansion factor: ", 41L);
	do_fio(&c__1, (char *)&ercex, (ftnlen)sizeof(real));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 29", "All color indices in predefined text bundles should th"
	    "emselves be in the predefined color table.", 5L, 96L);
#else /* NO_PROTO */
    setmsg_("20 29", "All color indices in predefined text bundles should th\
emselves be in the predefined color table.", 5L, 96L);
#endif /* NO_PROTO */
    if (colerr) {
	fail_();
	s_wsfi(&io___46);
	do_fio(&c__1, "Undefined color #", 17L);
	do_fio(&c__1, (char *)&ertxci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined bundle.", 28L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("15 26 27 28 29", "All aspects of all predefined text bundles sh"
	    "ould be reported as realizable by <inquire text representation>.",
	     14L, 109L);
#else /* NO_PROTO */
    setmsg_("15 26 27 28 29", "All aspects of all predefined text bundles sh\
ould be reported as realizable by <inquire text representation>.", 14L, 109L);

#endif /* NO_PROTO */
    if (rlzerr) {
	fail_();
	s_wsfi(&io___47);
	do_fio(&c__1, "Predefined bundle #", 19L);
	do_fio(&c__1, (char *)&erbun, (ftnlen)sizeof(integer));
	do_fio(&c__1, " not realized as set.", 21L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
L150:
    s_wsfi(&io___48);
    do_fio(&c__1, "PHIGS reported ", 15L);
    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
    do_fio(&c__1, " predefined text bundles.", 25L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("19 21", "<Inquire text facilities> should report at least 6 pre"
	    "defined entries.", 5L, 70L);
#else /* NO_PROTO */
    setmsg_("19 21", "<Inquire text facilities> should report at least 6 pre\
defined entries.", 5L, 70L);
#endif /* NO_PROTO */
    if (npe < 6) {
	fail_();
	goto L666;
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("20 22", "The first six predefined text bundle entries should al"
	    "l be mutually distinguishable.", 5L, 84L);
#else /* NO_PROTO */
    setmsg_("20 22", "The first six predefined text bundle entries should al\
l be mutually distinguishable.", 5L, 84L);
#endif /* NO_PROTO */
/*  pdfn = predefined font */
/*  pdpr = predefined precision */
/*  pdxp = predefined character expansion factor */
/*  pdsp = predefined character spacing */
/*  pdci = predefined text color index */
    for (txi = 1; txi <= 6; ++txi) {
/*  get attributes for current bundle */
	nqptxr (&specwt, &txi, &errind, &pdfn, &pdpr, &pdxp, &pdsp, &pdci);
	chkinq_("pqptxr", &errind, 6L);
/*  compare current to all previous bundles */
	i__1 = txi - 1;
	for (txi2 = 1; txi2 <= i__1; ++txi2) {
	    if (svpdfn[txi2 - 1] == pdfn && svpdpr[txi2 - 1] == pdpr && 
		    svpdxp[txi2 - 1] == pdxp && svpdsp[txi2 - 1] == pdsp && 
		    svpdci[txi2 - 1] == pdci) {
		fail_();
		s_wsfi(&io___60);
		do_fio(&c__1, "Text bundle #", 13L);
		do_fio(&c__1, (char *)&txi, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is indistinguishable from #", 28L);
		do_fio(&c__1, (char *)&txi2, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L666;
	    }
/* L250: */
	}
/*  save current attributes */
	svpdfn[txi - 1] = pdfn;
	svpdpr[txi - 1] = pdpr;
	svpdxp[txi - 1] = pdxp;
	svpdsp[txi - 1] = pdsp;
	svpdci[txi - 1] = pdci;
/* L200: */
    }
    pass_();
L666:
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

