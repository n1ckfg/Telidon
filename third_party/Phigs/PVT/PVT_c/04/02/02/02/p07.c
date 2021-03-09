/* fort/04/02/02/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;
static doublereal c_b62 = .25;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/07                        * */
/*  *    TEST TITLE : Marker size facilities                * */
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
    static real incr;
    static integer nams;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real minsc, thisc, maxsc;
    static logical valok;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real minms, maxms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static real msize;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmf ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nspmr (integer *, integer *, integer *, real *, integer *);
    extern logical rlzms_(real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nspmr ();
    extern logical rlzms_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
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


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.02.02/07", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire polymarker facilities> to determine: */
/*     nams  = number of available marker sizes */
/*     nomms = nominal marker size */
/*     minms = minimum marker size */
/*     maxms = maximum marker size */
    nqpmf (&specwt, &c__1, &errind, &idum1, &idum2, &nams, &nomms, &minms, &
	    maxms, &idum3);
    chkinq_("pqpmf", &errind, 5L);
    s_wsfi(&io___12);
    do_fio(&c__1, "Implementation reports number of available marker sizes = "
	    , 58L);
    do_fio(&c__1, (char *)&nams, (ftnlen)sizeof(integer));
    do_fio(&c__1, ";  nominal, minimum, maximum marker sizes = ", 44L);
    do_fio(&c__1, (char *)&nomms, (ftnlen)sizeof(real));
    do_fio(&c__1, ",", 1L);
    do_fio(&c__1, (char *)&minms, (ftnlen)sizeof(real));
    do_fio(&c__1, ",", 1L);
    do_fio(&c__1, (char *)&maxms, (ftnlen)sizeof(real));
    e_wsfi();
    inmsg_(msg, 300L);
    setmsg_("39", "Maximum marker size should not be less than minimum.", 2L, 
	    52L);
    L__1 = maxms >= minms;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("40", "The nominal marker size, minimum marker size, and maximum"
	    " marker size should all be positive.", 2L, 93L);
    L__1 = minms > 0.f && maxms > 0.f && nomms > 0.f;
#else /* NO_PROTO */
    setmsg_("40", "The nominal marker size, minimum marker size, and maximum\
 marker size should all be positive.", 2L, 93L);
    L__1 = minms > (float)0. && maxms > (float)0. && nomms > (float)0.;
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("41", "The reported number of available marker sizes should be a"
	    "t least 0.", 2L, 67L);
#else /* NO_PROTO */
    setmsg_("41", "The reported number of available marker sizes should be a\
t least 0.", 2L, 67L);
#endif /* NO_PROTO */
    L__1 = nams >= 0;
    ifpf_(&L__1);
/*  minsc = minimum effective scale factor */
/*  maxsc = maximum effective scale factor */
    minsc = minms / nomms;
    maxsc = maxms / nomms;
    setmsg_("42", "All marker size scale factors should be accepted as valid."
	    , 2L, 58L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    msize = minsc / 10;
    nspmr (&globnu_1.wkid, &c__4, &c__1, &msize, &c__1);
    if (globnu_1.errsig != 0) {
	goto L500;
    }
    msize = maxsc * 10;
    nspmr (&globnu_1.wkid, &c__4, &c__1, &msize, &c__1);
    if (globnu_1.errsig != 0) {
	goto L500;
    }
#ifndef NO_PROTO
    msize = -10.f;
#else /* NO_PROTO */
    msize = (float)-10.;
#endif /* NO_PROTO */
    nspmr (&globnu_1.wkid, &c__4, &c__1, &msize, &c__1);
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
    do_fio(&c__1, "Marker size scale factor of ", 28L);
    do_fio(&c__1, (char *)&msize, (ftnlen)sizeof(real));
    do_fio(&c__1, " rejected with error code = ", 28L);
    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
L600:
#ifndef NO_PROTO
    setmsg_("11 15 39", "The reported minimum marker size should be realizab"
	    "le.", 8L, 54L);
#else /* NO_PROTO */
    setmsg_("11 15 39", "The reported minimum marker size should be realizab\
le.", 8L, 54L);
#endif /* NO_PROTO */
    L__1 = rlzms_(&minsc, &minsc);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11 15 39", "The reported maximum marker size should be realizab"
	    "le.", 8L, 54L);
#else /* NO_PROTO */
    setmsg_("11 15 39", "The reported maximum marker size should be realizab\
le.", 8L, 54L);
#endif /* NO_PROTO */
    L__1 = rlzms_(&maxsc, &maxsc);
    ifpf_(&L__1);
    if (! valok) {
#ifndef NO_PROTO
	inmsg_("Skipping tests of marker size coercion, since validity test "
		"was failed.", 71L);
#else /* NO_PROTO */
	inmsg_("Skipping tests of marker size coercion, since validity test \
was failed.", 71L);
#endif /* NO_PROTO */
	goto L610;
    }
#ifndef NO_PROTO
    setmsg_("11 15 39", "A marker size scale factor set as less than the min"
	    "imum should be realized as the reported minimum.", 8L, 99L);
#else /* NO_PROTO */
    setmsg_("11 15 39", "A marker size scale factor set as less than the min\
imum should be realized as the reported minimum.", 8L, 99L);
#endif /* NO_PROTO */
    r__1 = minsc / 3;
    L__1 = rlzms_(&r__1, &minsc);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11 15 39", "A marker size scale factor set as greater than the "
	    "maximum should be realized as the reported maximum.", 8L, 102L);
#else /* NO_PROTO */
    setmsg_("11 15 39", "A marker size scale factor set as greater than the \
maximum should be realized as the reported maximum.", 8L, 102L);
#endif /* NO_PROTO */
    r__1 = maxsc * 3;
    L__1 = rlzms_(&r__1, &maxsc);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11 15 39", "A marker size scale factor set as less than zero sh"
	    "ould be realized as the reported minimum.", 8L, 92L);
#else /* NO_PROTO */
    setmsg_("11 15 39", "A marker size scale factor set as less than zero sh\
ould be realized as the reported minimum.", 8L, 92L);
#endif /* NO_PROTO */
    r__1 = -(doublereal)dabs(maxsc);
    L__1 = rlzms_(&r__1, &minsc);
    ifpf_(&L__1);
/*  skip_coerce: */
L610:
    if (nams != 0) {
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("11 15 39", "If the reported number of available marker sizes is"
	    " zero, then all marker sizes between the reported minimum and ma"
	    "ximum should be realizable.", 8L, 142L);
#else /* NO_PROTO */
    setmsg_("11 15 39", "If the reported number of available marker sizes is\
 zero, then all marker sizes between the reported minimum and maximum should\
 be realizable.", 8L, 142L);
#endif /* NO_PROTO */
    d__1 = (doublereal) (maxsc / minsc);
    incr = pow_dd(&d__1, &c_b62);
    thisc = minsc;
    for (ix = 1; ix <= 3; ++ix) {
	thisc *= incr;
	if (rlzms_(&thisc, &thisc)) {
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

