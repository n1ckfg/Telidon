/* fort/04/02/05/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/06                        * */
/*  *    TEST TITLE : Interior style facilities             * */
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
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer isi;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), nqif (integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *), pass_(void), nqir (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nsir (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), nqif (), pass_(), nqir (), 
	    nsir ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqpaf (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqpaf ();
#endif /* NO_PROTO */
    static integer npdpi;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc ();
#endif /* NO_PROTO */
    static integer rints;
    static logical style[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, naints, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer thisis;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int errctl_(logical *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int errctl_(), xpopph_();
#endif /* NO_PROTO */
    static logical styval;

    /* Fortran I/O blocks */
    static icilist io___14 = { 0, msg, 0, "(A, I5, A, I5, A, I5, A)", 300, 1 }
	    ;
    static icilist io___16 = { 0, msg, 0, "(A, I5, A, I5, A)", 300, 1 };
    static icilist io___17 = { 0, msg, 0, "(A, A, I5, A, I5, A)", 300, 1 };


/* type of returned value */
/* interior style */
/*  parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.02/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);

/*  naints = number of available interior styles */
    nqif (&specwt, &c__0, &c__0, &errind, &naints, &idum1, &idum2, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
#ifndef NO_PROTO
    setmsg_("16 33", "All interior styles within the list of available inter"
	    "ior styles should be accepted as valid and realizable.", 5L, 108L)
	    ;
#else /* NO_PROTO */
    setmsg_("16 33", "All interior styles within the list of available inter\
ior styles should be accepted as valid and realizable.", 5L, 108L);
#endif /* NO_PROTO */
/*  keep track of style and validity */
    for (isi = 0; isi <= 4; ++isi) {
	style[isi] = FALSE_;
/* L50: */
    }
    styval = TRUE_;
/*  get each element in list of available interior styles */
    i__1 = naints;
    for (isi = 1; isi <= i__1; ++isi) {
	nqif (&specwt, &isi, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, 
		&idum4);
	chkinq_("pqif", &errind, 4L);
/*  set interior style */
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
	nsir (&globnu_1.wkid, &c__2, &thisis, &c__1, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___14);
	    do_fio(&c__1, "Interior style ", 15L);
	    do_fio(&c__1, (char *)&thisis, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " in bundle #", 12L);
	    do_fio(&c__1, (char *)&isi, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalid: signalled error #", 39L);
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L150;
	}
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
/*  inquire interior style as realized */
/*  rints = realized interior style */
	nqir (&globnu_1.wkid, &c__2, &c__1, &errind, &rints, &idum1, &idum2);
	chkinq_("pqir", &errind, 4L);
	if (rints != thisis) {
	    fail_();
	    s_wsfi(&io___16);
	    do_fio(&c__1, "Interior style set as ", 22L);
	    do_fio(&c__1, (char *)&thisis, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as ", 17L);
	    do_fio(&c__1, (char *)&rints, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L150;
	}
/* L100: */
    }
    pass_();
L150:
/* keep track of available interior styles and */
/* check that interior style is valid */
    i__1 = naints;
    for (isi = 1; isi <= i__1; ++isi) {
	nqif (&specwt, &isi, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, 
		&idum4);
	chkinq_("pqif", &errind, 4L);
	if (0 <= thisis && thisis <= 4) {
/* style is valid */
	    style[thisis] = TRUE_;
	} else {
	    styval = FALSE_;
	    s_wsfi(&io___17);
	    do_fio(&c__1, "Invalid ", 8L);
	    do_fio(&c__1, "interior style ", 15L);
	    do_fio(&c__1, (char *)&thisis, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " in bundle #", 12L);
	    do_fio(&c__1, (char *)&isi, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " in the list of available interior styles.", 42L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	}
/* L200: */
    }
#ifndef NO_PROTO
    setmsg_("31", "All interior styles in the list of available interior sty"
	    "les should be of type HOLLOW, SOLID, PATTERN, HATCH, or EMPTY.", 
	    2L, 119L);
#else /* NO_PROTO */
    setmsg_("31", "All interior styles in the list of available interior sty\
les should be of type HOLLOW, SOLID, PATTERN, HATCH, or EMPTY.", 2L, 119L);
#endif /* NO_PROTO */
    ifpf_(&styval);
#ifndef NO_PROTO
    setmsg_("32", "The list of available interior styles should contain HOLL"
	    "OW and EMPTY.", 2L, 70L);
#else /* NO_PROTO */
    setmsg_("32", "The list of available interior styles should contain HOLL\
OW and EMPTY.", 2L, 70L);
#endif /* NO_PROTO */
    L__1 = style[0] && style[4];
    ifpf_(&L__1);
    if (style[2]) {
#ifndef NO_PROTO
	setmsg_("34", "For PATTERN interior style, at least 1 predefined pat"
		"tern index should be available.", 2L, 84L);
#else /* NO_PROTO */
	setmsg_("34", "For PATTERN interior style, at least 1 predefined pat\
tern index should be available.", 2L, 84L);
#endif /* NO_PROTO */
/* npdpi = number of predefined pattern index */
	nqpaf (&specwt, &errind, &npdpi);
	chkinq_("pqpaf", &errind, 5L);
	L__1 = npdpi >= 1;
	ifpf_(&L__1);
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

