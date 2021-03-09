/* fort/04/02/03/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b17 = 1.f;
static real c_b18 = 0.f;
#else /* NO_PROTO */
static real c_b17 = (float)1.;
static real c_b18 = (float)0.;
#endif /* NO_PROTO */
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/06                        * */
/*  *    TEST TITLE : Text font and precision support       * */
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
    static integer eel, rfn;
    static char msg[300];
    static logical fnt[2];
    static integer rpr;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer nfpp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static logical strk[2];
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nopwk (integer *, 
	    integer *, integer *), nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), nopwk (), 
	    nqtxf ();
#endif /* NO_PROTO */
    static integer tstpr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxr (), nstxr ();
#endif /* NO_PROTO */
    static logical charae, canset;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, thisfn;
    static logical strgae, precok, preval, fontok;
    static integer specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int errctl_();
#endif /* NO_PROTO */
    static integer thispr;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___22 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___25 = { 0, msg, 0, "(A, A, I5, A, I5, A)", 300, 1 };
    static icilist io___26 = { 0, msg, 0, "(A, 2I5, A, I5, A, I5, A)", 300, 1 
	    };
    static icilist io___28 = { 0, msg, 0, "(A, I5, A, I5, A)", 300, 1 };
    static icilist io___29 = { 0, msg, 0, "(A, I5, A, I5, A)", 300, 1 };
    static icilist io___34 = { 0, msg, 0, "(A, 2I5, A, I5, A, I5, A)", 300, 1 
	    };
    static icilist io___35 = { 0, msg, 0, "(3(A,I5),A)", 300, 1 };
    static icilist io___36 = { 0, msg, 0, "(3(A,I5),A)", 300, 1 };


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.03.02/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  in fortran, the list of font/precision pairs (lfnpr) is given by: */
/*  nfpp = number of available font/prec pairs */
/*  font (thisfn) = nth element of list of text fonts */
/*  prec (thispr) = nth element of list of text precisions */
    nqtxf (&specwt, &c__1, &errind, &nfpp, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
/*  strgae = STRING precision available directly */
/*  charae = CHAR precision available directly */
    strgae = FALSE_;
    charae = FALSE_;
/*  no standard fonts found yet */
    fnt[0] = FALSE_;
    fnt[1] = FALSE_;
/*  no STROKE precsion found yet */
    strk[0] = FALSE_;
    strk[1] = FALSE_;
/* go through each element in list of available font/precision pairs */
    i__1 = nfpp;
    for (eel = 1; eel <= i__1; ++eel) {
	nqtxf (&specwt, &eel, &errind, &idum1, &thisfn, &thispr, &idum2, &
		rdum1, &rdum2, &idum3, &rdum3, &rdum4, &idum4);
/*  keep track of non-zero error indicators */
	if (errind != 0) {
	    s_wsfi(&io___22);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing font/prec-list element #", 41L);
	    do_fio(&c__1, (char *)&eel, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L200;
	}
/*  check for fonts 1 and 2 */
	if (thisfn == 1 || thisfn == 2) {
	    fnt[thisfn - 1] = TRUE_;
/*  check on precision */
	    if (thispr == 2) {
		strk[thisfn - 1] = TRUE_;
	    }
	}
/*  check for at least 1 STRING precision (directly available) */
	nstxr (&globnu_1.wkid, &c__1, &thisfn, &c__0, &c_b17, &c_b18, &c__1);
	nqtxr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, &rpr, &rdum1, &
		rdum2, &idum2);
	chkinq_("pqtxr", &errind, 5L);
	if (rpr == 0) {
	    strgae = TRUE_;
	}
/*  check for at least 1 CHAR precision (directly available) */
	if (thispr < 1) {
	    goto L200;
	}
	nstxr (&globnu_1.wkid, &c__2, &thisfn, &c__1, &c_b17, &c_b18, &c__1);
	nqtxr (&globnu_1.wkid, &c__2, &c__1, &errind, &idum1, &rpr, &rdum1, &
		rdum2, &idum2);
	chkinq_("pqtxr", &errind, 5L);
	if (rpr == 1) {
	    charae = TRUE_;
	}
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("30", "The list of available font/precision pairs should contain"
	    " font 1 and font 2.", 2L, 76L);
#else /* NO_PROTO */
    setmsg_("30", "The list of available font/precision pairs should contain\
 font 1 and font 2.", 2L, 76L);
#endif /* NO_PROTO */
    L__1 = fnt[0] && fnt[1];
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("31", "Stroke precision should be available for both font 1 and "
	    "font 2.", 2L, 64L);
#else /* NO_PROTO */
    setmsg_("31", "Stroke precision should be available for both font 1 and \
font 2.", 2L, 64L);
#endif /* NO_PROTO */
    L__1 = strk[0] && strk[1];
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("32", "At least 1 STRING precision font should be available dire"
	    "ctly.", 2L, 62L);
#else /* NO_PROTO */
    setmsg_("32", "At least 1 STRING precision font should be available dire\
ctly.", 2L, 62L);
#endif /* NO_PROTO */
    ifpf_(&strgae);
#ifndef NO_PROTO
    setmsg_("33", "At least 1 CHAR precision font should be available direct"
	    "ly.", 2L, 60L);
#else /* NO_PROTO */
    setmsg_("33", "At least 1 CHAR precision font should be available direct\
ly.", 2L, 60L);
#endif /* NO_PROTO */
    ifpf_(&charae);
/*  keep track of precision validity */
#ifndef NO_PROTO
    setmsg_("15 35", "All text font/precision pairs within the list of avail"
	    "able font/precision pairs should be valid and available directly."
	    , 5L, 119L);
#else /* NO_PROTO */
    setmsg_("15 35", "All text font/precision pairs within the list of avail\
able font/precision pairs should be valid and available directly.", 5L, 119L);

#endif /* NO_PROTO */
    preval = TRUE_;
/*  get each element in list of font/precision pairs */
    i__1 = nfpp;
    for (eel = 1; eel <= i__1; ++eel) {
	nqtxf (&specwt, &eel, &errind, &idum1, &thisfn, &thispr, &idum2, &
		rdum1, &rdum2, &idum3, &rdum3, &rdum4, &idum4);
	chkinq_("pqtxf", &errind, 5L);
/*  check that precision is valid */
	if (thispr < 0 || thispr > 2) {
	    preval = FALSE_;
	    s_wsfi(&io___25);
	    do_fio(&c__1, "Invalid ", 8L);
	    do_fio(&c__1, "precision", 9L);
	    do_fio(&c__1, (char *)&thispr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, "in bundle #", 11L);
	    do_fio(&c__1, (char *)&eel, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " in the list of font/precision pairs.", 37L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	}
/*  set font and precision */
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
	nstxr (&globnu_1.wkid, &c__2, &thisfn, &thispr, &c_b17, &c_b18, &c__1)
		;
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___26);
	    do_fio(&c__1, "Font/precision pair ", 20L);
	    do_fio(&c__1, (char *)&thisfn, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&thispr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " in bundle #", 12L);
	    do_fio(&c__1, (char *)&eel, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalid: signalled error #", 39L);
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L350;
	}
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
/*  inquire font and precision as realized */
/*  rfn = realized font, rpr = realized prec */
	nqtxr (&globnu_1.wkid, &c__2, &c__1, &errind, &rfn, &rpr, &rdum1, &
		rdum2, &idum1);
	chkinq_("pqtxr", &errind, 5L);
	if (rfn != thisfn) {
	    fail_();
	    s_wsfi(&io___28);
	    do_fio(&c__1, "Font set as ", 12L);
	    do_fio(&c__1, (char *)&thisfn, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as ", 17L);
	    do_fio(&c__1, (char *)&rfn, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L350;
	}
	if (rpr != thispr) {
	    fail_();
	    s_wsfi(&io___29);
	    do_fio(&c__1, "Precision set as ", 17L);
	    do_fio(&c__1, (char *)&thispr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as ", 17L);
	    do_fio(&c__1, (char *)&rpr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L350;
	}
/* L300: */
    }
    pass_();
L350:
#ifndef NO_PROTO
    setmsg_("34", "All precisions in the list of text font and precision pai"
	    "rs should be of type STRING, CHAR, or STROKE.", 2L, 102L);
#else /* NO_PROTO */
    setmsg_("34", "All precisions in the list of text font and precision pai\
rs should be of type STRING, CHAR, or STROKE.", 2L, 102L);
#endif /* NO_PROTO */
    ifpf_(&preval);
    precok = TRUE_;
    fontok = TRUE_;
    canset = TRUE_;
    i__1 = nfpp;
    for (eel = 1; eel <= i__1; ++eel) {
	nqtxf (&specwt, &eel, &errind, &idum1, &thisfn, &thispr, &idum2, &
		rdum1, &rdum2, &idum3, &rdum3, &rdum4, &idum4);
	chkinq_("pqtxf", &errind, 5L);
	i__2 = thispr;
	for (tstpr = 0; tstpr <= i__2; ++tstpr) {
#ifndef NO_PROTO
	    errctl_((logical*)&c__1);
#else /* NO_PROTO */
	    errctl_(&c__1);
#endif /* NO_PROTO */
	    nstxr (&globnu_1.wkid, &c__1, &thisfn, &tstpr, &c_b17, &c_b18, &
		    c__1);
#ifndef NO_PROTO
	    errctl_((logical*)&c__0);
#else /* NO_PROTO */
	    errctl_(&c__0);
#endif /* NO_PROTO */
	    if (globnu_1.errsig != 0) {
		canset = FALSE_;
		s_wsfi(&io___34);
		do_fio(&c__1, "Font/precision pair ", 20L);
		do_fio(&c__1, (char *)&thisfn, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&tstpr, (ftnlen)sizeof(integer));
		do_fio(&c__1, " in bundle #", 12L);
		do_fio(&c__1, (char *)&eel, (ftnlen)sizeof(integer));
		do_fio(&c__1, " rejected as invalid: signalled error #", 39L);

		do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(
			integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L460;
	    }
	    nqtxr (&globnu_1.wkid, &c__1, &c__1, &errind, &rfn, &rpr, &rdum1, 
		    &rdum2, &idum1);
	    chkinq_("pqtxr", &errind, 5L);
	    if (rfn != thisfn) {
		fontok = FALSE_;
		s_wsfi(&io___35);
		do_fio(&c__1, "Font set as ", 12L);
		do_fio(&c__1, (char *)&thisfn, (ftnlen)sizeof(integer));
		do_fio(&c__1, " but realized as ", 17L);
		do_fio(&c__1, (char *)&rfn, (ftnlen)sizeof(integer));
		do_fio(&c__1, " for fn_pr pair #", 17L);
		do_fio(&c__1, (char *)&eel, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L460;
	    }
	    if (rpr < tstpr) {
		precok = FALSE_;
		s_wsfi(&io___36);
		do_fio(&c__1, "Precison set as ", 16L);
		do_fio(&c__1, (char *)&tstpr, (ftnlen)sizeof(integer));
		do_fio(&c__1, " but realized as ", 17L);
		do_fio(&c__1, (char *)&rpr, (ftnlen)sizeof(integer));
		do_fio(&c__1, " for fn_pr pair #", 17L);
		do_fio(&c__1, (char *)&eel, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L460;
	    }
/* L400: */
	}
/* L450: */
    }
L460:
#ifndef NO_PROTO
    setmsg_("36 37 47", "If a given font/precision pair is reported as suppo"
	    "rted, then that font should be available in all lower or equal p"
	    "recisions.", 8L, 125L);
#else /* NO_PROTO */
    setmsg_("36 37 47", "If a given font/precision pair is reported as suppo\
rted, then that font should be available in all lower or equal precisions.", 
	    8L, 125L);
#endif /* NO_PROTO */
    ifpf_(&canset);
#ifndef NO_PROTO
    setmsg_("15 36 37 47", "A valid font/precision pair should be realized a"
	    "s that font and at an equal or higher precision.", 11L, 96L);
#else /* NO_PROTO */
    setmsg_("15 36 37 47", "A valid font/precision pair should be realized a\
s that font and at an equal or higher precision.", 11L, 96L);
#endif /* NO_PROTO */
    L__1 = fontok && precok;
    ifpf_(&L__1);
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

