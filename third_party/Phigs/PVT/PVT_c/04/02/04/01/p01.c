/* fort/04/02/04/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__50 = 50;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c_n7 = -7;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.01/01                        * */
/*  *    TEST TITLE : Element creation and inquiring        * */
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
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer rl;
    static char msg[200];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer intg;
    static real rlar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatp (integer *), nsans (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatp (), nsans ();
#endif /* NO_PROTO */
    static char strar[1*50];
    static integer txhor;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer txver;
    static real txatr1, txatr2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), nsatch (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), nsatch ();
#endif /* NO_PROTO */
    static integer errind, eltype, intlen, strlen, strarl[50], txpath;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqcets (integer *, integer *, integer *, 
	    integer *, integer *), nsatcu (real *, real *), xpopph_(integer *,
	     integer *), nsatal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), nqcets (), nsatcu (), 
	    xpopph_(), nsatal ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___18 = { 0, msg, 0, "(A,I2,A)", 200, 1 };
    static icilist io___21 = { 0, msg, 0, "(A,I2,A,I2,A)", 200, 1 };


/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* PHIGS parameter types */
    initgl_("04.02.04.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* structure identifier = 101 */
    strid = 101;
/* open structure */
    nopst (&strid);
/*  *** ***   Annotation text character height   *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    txatr1 = 2.35f;
#else /* NO_PROTO */
    txatr1 = (float)2.35;
#endif /* NO_PROTO */
    nsatch (&txatr1);
#ifndef NO_PROTO
    setmsg_("3 42", "<Inquire current element type and size> should return a"
	    "nnotation text character height as the type of the created eleme"
	    "nt and the appropriate element size.", 4L, 155L);
#else /* NO_PROTO */
    setmsg_("3 42", "<Inquire current element type and size> should return a\
nnotation text character height as the type of the created element and the a\
ppropriate element size.", 4L, 155L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
    L__1 = errind == 0 && eltype == 38 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 42", "<Inquire current element content> should return the sta"
	    "ndard representation for the annotation text character height va"
	    "lue.", 4L, 123L);
#else /* NO_PROTO */
    setmsg_("4 42", "<Inquire current element content> should return the sta\
ndard representation for the annotation text character height value.", 4L, 
	    123L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pechh */
    L__1 = errind == 0 && rlar[0] == txatr1 && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/*  *** ***   Annotation text character up vector   *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    txatr1 = -4.25f;
    txatr2 = -5.13f;
#else /* NO_PROTO */
    txatr1 = (float)-4.25;
    txatr2 = (float)-5.13;
#endif /* NO_PROTO */
    nsatcu (&txatr1, &txatr2);
#ifndef NO_PROTO
    setmsg_("3 70", "<Inquire current element type and size> should return a"
	    "nnotation text character up vector as the type of the created el"
	    "ement and the appropriate element size.", 4L, 158L);
#else /* NO_PROTO */
    setmsg_("3 70", "<Inquire current element type and size> should return a\
nnotation text character up vector as the type of the created element and th\
e appropriate element size.", 4L, 158L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
    L__1 = errind == 0 && eltype == 39 && intlen == 0 && rllen == 2 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 70", "<Inquire current element content> should return the sta"
	    "ndard representation for the annotation text character up vector"
	    " value.", 4L, 126L);
#else /* NO_PROTO */
    setmsg_("4 70", "<Inquire current element content> should return the sta\
ndard representation for the annotation text character up vector value.", 4L, 
	    126L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pechup */
    L__1 = errind == 0 && rlar[0] == txatr1 && rlar[1] == txatr2 && intg == 0 
	    && rl == 2 && str == 0;
    ifpf_(&L__1);
/*  *** *** ***   Annotation text path   *** *** *** */
/* set value for attribute */
    nsatp (&c__1);
#ifndef NO_PROTO
    setmsg_("3 55", "<Inquire current element type and size> should return a"
	    "nnotation text path as the type of the created element and the a"
	    "ppropriate element size.", 4L, 143L);
#else /* NO_PROTO */
    setmsg_("3 55", "<Inquire current element type and size> should return a\
nnotation text path as the type of the created element and the appropriate e\
lement size.", 4L, 143L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
    L__1 = errind == 0 && eltype == 40 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 55 56", "<Inquire current element content> should return the "
	    "standard representation for all valid annotation text path value"
	    "s.", 7L, 118L);
#else /* NO_PROTO */
    setmsg_("4 55 56", "<Inquire current element content> should return the \
standard representation for all valid annotation text path values.", 7L, 118L)
	    ;
#endif /* NO_PROTO */
    for (txpath = 0; txpath <= 3; ++txpath) {
	nsatp (&txpath);
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intar[0] == txpath && intg == 1 && rl == 0 && str 
		== 0) {
/*            OK so far */
	} else {
	    fail_();
	    s_wsfi(&io___18);
	    do_fio(&c__1, "Failure for text path = ", 24L);
	    do_fio(&c__1, (char *)&txpath, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 200L);
	    goto L210;
	}
/* L200: */
    }
    pass_();
/*  donepath: */
L210:
/*  *** *** ***   Annotation text alignment   *** *** *** */
/* set value for attribute */
    nsatal (&c__2, &c__4);
#ifndef NO_PROTO
    setmsg_("3 63", "<Inquire current element type and size> should return a"
	    "nnotation text alignment as the type of the created element and "
	    "the appropriate element size.", 4L, 148L);
#else /* NO_PROTO */
    setmsg_("3 63", "<Inquire current element type and size> should return a\
nnotation text alignment as the type of the created element and the appropri\
ate element size.", 4L, 148L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
    L__1 = errind == 0 && eltype == 41 && intlen == 2 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 63 64", "<Inquire current element content> should return the "
	    "standard representation for all valid annotation text alignment "
	    "values.", 7L, 123L);
#else /* NO_PROTO */
    setmsg_("4 63 64", "<Inquire current element content> should return the \
standard representation for all valid annotation text alignment values.", 7L, 
	    123L);
#endif /* NO_PROTO */
    for (txhor = 0; txhor <= 3; ++txhor) {
	for (txver = 0; txver <= 5; ++txver) {
	    nsatal (&txhor, &txver);
	    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, 
		    &str, strarl, strar, 1L);
	    if (errind == 0 && intg == 2 && intar[0] == txhor && intar[1] == 
		    txver && rl == 0 && str == 0) {
/*            OK so far */
	    } else {
		fail_();
		s_wsfi(&io___21);
		do_fio(&c__1, "Failure for text horiz = ", 25L);
		do_fio(&c__1, (char *)&txhor, (ftnlen)sizeof(integer));
		do_fio(&c__1, ", text vert = ", 14L);
		do_fio(&c__1, (char *)&txver, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 200L);
		goto L310;
	    }
/* L305: */
	}
/* L300: */
    }
    pass_();
L310:
/*  *** *** ***   Annotation style   *** *** *** */
/* set value for attribute */
    nsans (&c_n7);
#ifndef NO_PROTO
    setmsg_("3 75", "<Inquire current element type and size> should return a"
	    "nnotation style as the type of the created element and the appro"
	    "priate element size.", 4L, 139L);
#else /* NO_PROTO */
    setmsg_("3 75", "<Inquire current element type and size> should return a\
nnotation style as the type of the created element and the appropriate eleme\
nt size.", 4L, 139L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
    L__1 = errind == 0 && eltype == 42 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 75", "<Inquire current element content> should return the sta"
	    "ndard representation for the annotation style value.", 4L, 107L);
#else /* NO_PROTO */
    setmsg_("4 75", "<Inquire current element content> should return the sta\
ndard representation for the annotation style value.", 4L, 107L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    L__1 = errind == 0 && intar[0] == -7 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

