/* fort/04/02/05/03/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;
static doublereal c_b65 = .25;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/08                        * */
/*  *    TEST TITLE : Edgewidth facilities                  * */
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
    real r__1;
    doublereal d__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    double pow_dd(doublereal *, doublereal *);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    double pow_dd();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer naew;
    static real incr;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_();
#endif /* NO_PROTO */
    static real minsc, thisc, maxsc;
    static logical valok;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nsedr (integer *, 
	    integer *, integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nsedr ();
#endif /* NO_PROTO */
    static real minew, maxew, nomew;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
    extern logical rlzew_(real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk ();
    extern logical rlzew_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
    static real ewidth;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___12 = { 0, msg, 0, "(A,I6,3(A,E13.4))", 300, 1 };
    static icilist io___17 = { 0, msg, 0, "(A,F11.2,A,I6,A)", 300, 1 };


/* off/on switch for edge flag and error handling mode */
/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.03/08", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire edge facilities> to determine: */
/*     naew  = number of available edgewidths */
/*     nomew = nominal edgewidth */
/*     minew = minimum edgewidth */
/*     maxew = maximum edgewidth */
    nqedf (&specwt, &c__0, &errind, &idum1, &idum2, &naew, &nomew, &minew, &
	    maxew, &idum3);
    chkinq_("pqedf", &errind, 5L);
    s_wsfi(&io___12);
    do_fio(&c__1, "Implementation reports number of available edgewidths = ", 
	    56L);
    do_fio(&c__1, (char *)&naew, (ftnlen)sizeof(integer));
    do_fio(&c__1, ";  nominal, minimum, maximum edgewidths = ", 42L);
    do_fio(&c__1, (char *)&nomew, (ftnlen)sizeof(real));
    do_fio(&c__1, ",", 1L);
    do_fio(&c__1, (char *)&minew, (ftnlen)sizeof(real));
    do_fio(&c__1, ",", 1L);
    do_fio(&c__1, (char *)&maxew, (ftnlen)sizeof(real));
    e_wsfi();
    inmsg_(msg, 300L);
    setmsg_("42", "Maximum edgewidth should not be less than minimum.", 2L, 
	    50L);
    L__1 = maxew >= minew;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("43", "The nominal edgewidth, minimum edgewidth, and maximum edg"
	    "ewidth should all be positive.", 2L, 87L);
    L__1 = minew > 0.f && maxew > 0.f && nomew > 0.f;
#else /* NO_PROTO */
    setmsg_("43", "The nominal edgewidth, minimum edgewidth, and maximum edg\
ewidth should all be positive.", 2L, 87L);
    L__1 = minew > (float)0. && maxew > (float)0. && nomew > (float)0.;
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("44", "The reported number of available edgewidths should be at "
	    "least 0.", 2L, 65L);
#else /* NO_PROTO */
    setmsg_("44", "The reported number of available edgewidths should be at \
least 0.", 2L, 65L);
#endif /* NO_PROTO */
    L__1 = naew >= 0;
    ifpf_(&L__1);
/*  minsc = minimum effective scale factor */
/*  maxsc = maximum effective scale factor */
    minsc = minew / nomew;
    maxsc = maxew / nomew;
    setmsg_("45", "All edgewidth scale factors should be accepted as valid.", 
	    2L, 56L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    ewidth = minsc / 10;
    nsedr (&globnu_1.wkid, &c__4, &c__1, &c__1, &ewidth, &c__1);
    if (globnu_1.errsig != 0) {
	goto L500;
    }
    ewidth = maxsc * 10;
    nsedr (&globnu_1.wkid, &c__4, &c__1, &c__1, &ewidth, &c__1);
    if (globnu_1.errsig != 0) {
	goto L500;
    }
#ifndef NO_PROTO
    ewidth = -10.f;
#else /* NO_PROTO */
    ewidth = (float)-10.;
#endif /* NO_PROTO */
    nsedr (&globnu_1.wkid, &c__4, &c__1, &c__1, &ewidth, &c__1);
    if (globnu_1.errsig != 0) {
	goto L500;
    }
    pass_();
    valok = TRUE_;
    goto L600;
/*  fail and informational message about scale_factor */
L500:
    fail_();
    valok = FALSE_;
    s_wsfi(&io___17);
    do_fio(&c__1, "Edgewidth scale factor of ", 26L);
    do_fio(&c__1, (char *)&ewidth, (ftnlen)sizeof(real));
    do_fio(&c__1, " rejected with error code = ", 28L);
    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
L600:
    setmsg_("11 15 42", "The reported minimum edgewidth should be realizable."
	    , 8L, 52L);
    L__1 = rlzew_(&minsc, &minsc);
    ifpf_(&L__1);
    setmsg_("11 15 42", "The reported maximum edgewidth should be realizable."
	    , 8L, 52L);
    L__1 = rlzew_(&maxsc, &maxsc);
    ifpf_(&L__1);
    if (! valok) {
#ifndef NO_PROTO
	inmsg_("Skipping tests of edgewidth coercion, since validity test wa"
		"s failed.", 69L);
#else /* NO_PROTO */
	inmsg_("Skipping tests of edgewidth coercion, since validity test wa\
s failed.", 69L);
#endif /* NO_PROTO */
	goto L610;
    }
#ifndef NO_PROTO
    setmsg_("11 15 42", "A edgewidth scale factor set as less than the minim"
	    "um should be realized as the reported minimum.", 8L, 97L);
#else /* NO_PROTO */
    setmsg_("11 15 42", "A edgewidth scale factor set as less than the minim\
um should be realized as the reported minimum.", 8L, 97L);
#endif /* NO_PROTO */
    r__1 = minsc / 3;
    L__1 = rlzew_(&r__1, &minsc);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11 15 42", "A edgewidth scale factor set as greater than the ma"
	    "ximum should be realized as the reported maximum.", 8L, 100L);
#else /* NO_PROTO */
    setmsg_("11 15 42", "A edgewidth scale factor set as greater than the ma\
ximum should be realized as the reported maximum.", 8L, 100L);
#endif /* NO_PROTO */
    r__1 = maxsc * 3;
    L__1 = rlzew_(&r__1, &maxsc);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11 15 42", "A edgewidth scale factor set as less than zero shou"
	    "ld be realized as the reported minimum.", 8L, 90L);
#else /* NO_PROTO */
    setmsg_("11 15 42", "A edgewidth scale factor set as less than zero shou\
ld be realized as the reported minimum.", 8L, 90L);
#endif /* NO_PROTO */
    r__1 = -(doublereal)dabs(maxsc);
    L__1 = rlzew_(&r__1, &minsc);
    ifpf_(&L__1);
/*  skip_coerce: */
L610:
    if (naew != 0) {
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("11 15 42", "If the reported number of available edgewidths is z"
	    "ero, then all edgewidths between the reported minimum and maximu"
	    "m should be realizable.", 8L, 138L);
#else /* NO_PROTO */
    setmsg_("11 15 42", "If the reported number of available edgewidths is z\
ero, then all edgewidths between the reported minimum and maximum should be \
realizable.", 8L, 138L);
#endif /* NO_PROTO */
    d__1 = (doublereal) (maxsc / minsc);
    incr = pow_dd(&d__1, &c_b65);
    thisc = minsc;
    for (ix = 1; ix <= 3; ++ix) {
	thisc *= incr;
	if (rlzew_(&thisc, &thisc)) {
/*           OK so far */
	} else {
	    fail_();
	    goto L666;
	}
/* L620: */
    }
    pass_();
/*  done: */
L666:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

