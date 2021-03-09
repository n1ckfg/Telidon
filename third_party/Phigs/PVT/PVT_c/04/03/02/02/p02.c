/* fort/04/03/02/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b27 = .05f;
static real c_b28 = 0.f;
static real c_b55 = .001f;
#else /* NO_PROTO */
static real c_b27 = (float).05;
static real c_b28 = (float)0.;
static real c_b55 = (float).001;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/02                        * */
/*  *    TEST TITLE : Validity of predefined colour         * */
/*  *                 table                                 * */
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
    static integer i, ci, npe;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), nqcf (integer *
	    , integer *, integer *, integer *, integer *, real *), nqcr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *), nscr (integer *, integer *, integer *, real *), pass_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), nqcf (), nqcr (), nscr (), 
	    pass_();
#endif /* NO_PROTO */
    static integer rsiz, idum1, idum2;
    static real rdum1[9], cspec[6];
    static logical gotbf[2], preal;
    static integer errci;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
#endif /* NO_PROTO */
    static real rspec[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nqpcr (integer *, integer *, 
	    integer *, integer *, integer *, real *), nopwk (integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nqpcr (), nopwk ();
#endif /* NO_PROTO */
    static real cspec1[6];
    static integer defmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf ();
#endif /* NO_PROTO */
    static logical chkcsr;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, errval;
    static logical valcsv;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, numret;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___8 = { 0, msg, 0, "(A,I5,A,A)", 300, 1 };
    static icilist io___23 = { 0, msg, 0, "(A,I4,A)", 300, 1 };
    static icilist io___24 = { 0, msg, 0, "(A,I4,A)", 300, 1 };


/* colour model */
/* NOTE:  INTEGER rather than enumeration type.  Explicitly defined and */

/* required portion of conceptually unbounded range defined here. */
/* colour available */
/* type of returned value */
    initgl_("04.03.02.02/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* get default colour model */
    nqcmdf (&specwt, &c__0, &errind, &idum1, &idum2, &defmod);
    chkinq_("pqcmdf", &errind, 6L);
/* check colour specification range */
    if (defmod < 1 || defmod > 4) {
	s_wsfi(&io___8);
	do_fio(&c__1, "Colour model ", 13L);
	do_fio(&c__1, (char *)&defmod, (ftnlen)sizeof(integer));
	do_fio(&c__1, " not predefined.  Cannot check that colour ", 43L);
	do_fio(&c__1, "specification is within range.", 30L);
	e_wsfi();
	inmsg_(msg, 300L);
	chkcsr = FALSE_;
    } else {
	chkcsr = TRUE_;
    }
/* npe = number of predefined entries */
    nqcf (&specwt, &errind, &idum1, &idum2, &npe, rdum1);
    chkinq_("pqcf", &errind, 4L);
#ifndef NO_PROTO
    setmsg_("8 11", "<Inquire colour facilities> should report at least 2 pr"
	    "edefined entries.", 4L, 72L);
#else /* NO_PROTO */
    setmsg_("8 11", "<Inquire colour facilities> should report at least 2 pr\
edefined entries.", 4L, 72L);
#endif /* NO_PROTO */
    L__1 = npe >= 2;
    ifpf_(&L__1);
/*  got background or foreground index? */
    gotbf[0] = FALSE_;
    gotbf[1] = FALSE_;
/*  valid colour specification values? */
    valcsv = TRUE_;
    preal = TRUE_;
#ifndef NO_PROTO
    setmsg_("8 9 10", "<Inquire predefined colour representation> should be "
	    "able to access as many entries as reported by <inquire colour fa"
	    "cilities>.", 6L, 127L);
#else /* NO_PROTO */
    setmsg_("8 9 10", "<Inquire predefined colour representation> should be \
able to access as many entries as reported by <inquire colour facilities>.", 
	    6L, 127L);
#endif /* NO_PROTO */
/* colour indices start at 0 */
    i__1 = npe - 1;
    for (ci = 0; ci <= i__1; ++ci) {
	nqpcr (&specwt, &ci, &c__6, &errind, &numret, cspec);
	if (errind != 0) {
	    fail_();
	    goto L150;
	}
/* check for index 0 and 1 */
	if (ci == 0 || ci == 1) {
	    gotbf[ci] = TRUE_;
	}
/* check cspec is within range */
	if (chkcsr) {
/* all defined models are 3-dimensional */
	    if (numret != 3) {
		valcsv = FALSE_;
		errval = ci;
	    }
	    i__2 = numret;
	    for (i = 1; i <= i__2; ++i) {
#ifndef NO_PROTO
		if (cspec[i - 1] < 0.f || cspec[i - 1] > 1.f) {
#else /* NO_PROTO */
		if (cspec[i - 1] < (float)0. || cspec[i - 1] > (float)1.) {
#endif /* NO_PROTO */
		    valcsv = FALSE_;
		    errval = ci;
		}
/* L50: */
	    }
	}
/* check all predefined are realizable */
	nscr (&globnu_1.wkid, &c__1, &numret, cspec);
	nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &rsiz, rspec);
	chkinq_("pqcr", &errind, 4L);
	if (rsiz != numret) {
	    preal = FALSE_;
	    errci = ci;
	} else if (! rareq_(&numret, cspec, rspec, &c_b27, &c_b28)) {
	    preal = FALSE_;
	    errci = ci;
	}
/* L100: */
    }
    pass_();
L150:
    if (chkcsr) {
#ifndef NO_PROTO
	setmsg_("9 15 26", "The colour specification parameters for all the "
		"predefined colour indices should be valid for the default co"
		"lour model.", 7L, 119L);
#else /* NO_PROTO */
	setmsg_("9 15 26", "The colour specification parameters for all the \
predefined colour indices should be valid for the default colour model.", 7L, 
		119L);
#endif /* NO_PROTO */
	if (valcsv) {
	    pass_();
	} else {
	    fail_();
	    s_wsfi(&io___23);
	    do_fio(&c__1, "Colour specification #", 22L);
	    do_fio(&c__1, (char *)&errval, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " invalid.", 9L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	}
    }
#ifndef NO_PROTO
    setmsg_("9 15 32 33", "The colour specification parameters for all the p"
	    "redefined colour indices should be realizable by the workstation."
	    , 10L, 114L);
#else /* NO_PROTO */
    setmsg_("9 15 32 33", "The colour specification parameters for all the p\
redefined colour indices should be realizable by the workstation.", 10L, 114L)
	    ;
#endif /* NO_PROTO */
    if (preal) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___24);
	do_fio(&c__1, "Colour specification #", 22L);
	do_fio(&c__1, (char *)&errci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " not realizable.", 16L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("11", "The predefined colour indices should include entries 0 an"
	    "d 1.", 2L, 61L);
#else /* NO_PROTO */
    setmsg_("11", "The predefined colour indices should include entries 0 an\
d 1.", 2L, 61L);
#endif /* NO_PROTO */
    L__1 = gotbf[0] && gotbf[1];
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("9 11 12", "The first two predefined colour indices should be mu"
	    "tually distinguishable.", 7L, 75L);
#else /* NO_PROTO */
    setmsg_("9 11 12", "The first two predefined colour indices should be mu\
tually distinguishable.", 7L, 75L);
#endif /* NO_PROTO */
/* cspec = predefined colour specification for index #0 */
    nqpcr (&specwt, &c__0, &c__6, &errind, &numret, cspec);
    chkinq_("pqpcr", &errind, 5L);
/* cspec1 = predefined colour specification for index #1 */
    nqpcr (&specwt, &c__1, &c__6, &errind, &numret, cspec1);
    chkinq_("pqpcr", &errind, 5L);
    L__1 = ! rareq_(&numret, cspec, cspec1, &c_b55, &c_b55);
    ifpf_(&L__1);
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

