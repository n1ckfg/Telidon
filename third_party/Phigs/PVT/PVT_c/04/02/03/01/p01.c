/* fort/04/02/03/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__33 = 33;
static integer c__50 = 50;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/01                        * */
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
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), endit_(void), nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_(), nschh ();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer strid;
    static char strar[1*50];
    static integer txhor;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer txver;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxp (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxp ();
#endif /* NO_PROTO */
    static real txatr1, txatr2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco ();
#endif /* NO_PROTO */
    static integer errind, eltype, intlen, strlen, strarl[50], txprec, txpath;

#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), nstxfn (integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), nqcets (integer *, integer *, integer *, integer *, 
	    integer *), nschxp (real *), nschsp (real *), nstxci (integer *), 
	    nschup (real *, real *), nstxal (integer *, integer *), nstxpr (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), nstxfn (), setmsg_(), 
	    nqcets (), nschxp (), nschsp (), nstxci (), nschup (), nstxal (), 
	    nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___16 = { 0, msg, 0, "(A,I2,A)", 200, 1 };
    static icilist io___20 = { 0, msg, 0, "(A,I2,A)", 200, 1 };
    static icilist io___23 = { 0, msg, 0, "(A,I2,A,I2,A)", 200, 1 };


/* element type */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* PHIGS parameter types */
    initgl_("04.02.03.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Text font   *** *** *** *** *** */
/* set value for attribute */
    nstxfn (&c__33);
#ifndef NO_PROTO
    setmsg_("9 12", "<Inquire current element type and size> should return t"
	    "ext font as the type of the created element and the appropriate "
	    "element size.", 4L, 132L);
#else /* NO_PROTO */
    setmsg_("9 12", "<Inquire current element type and size> should return t\
ext font as the type of the created element and the appropriate element size."
	    , 4L, 132L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 29 is the PHIGS enumeration type for petxfn */
    L__1 = errind == 0 && eltype == 29 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
/* checking correct output parameters for data record type petxfn */
#ifndef NO_PROTO
    setmsg_("10 12", "<Inquire current element content> should return the st"
	    "andard representation for the text font value.", 5L, 100L);
#else /* NO_PROTO */
    setmsg_("10 12", "<Inquire current element content> should return the st\
andard representation for the text font value.", 5L, 100L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    L__1 = errind == 0 && intar[0] == 33 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Text precision   *** *** *** *** *** */
/* set value for attribute */
    nstxpr (&c__2);
#ifndef NO_PROTO
    setmsg_("9 25", "<Inquire current element type and size> should return t"
	    "ext precision as the type of the created element and the appropr"
	    "iate element size.", 4L, 137L);
#else /* NO_PROTO */
    setmsg_("9 25", "<Inquire current element type and size> should return t\
ext precision as the type of the created element and the appropriate element\
 size.", 4L, 137L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 30 is the PHIGS enumeration type for petxpr */
    L__1 = errind == 0 && eltype == 30 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
/* checking correct output parameters for data record type petxpr */
#ifndef NO_PROTO
    setmsg_("10 25 26", "<Inquire current element content> should return the"
	    " standard representation for all valid text precision values.", 
	    8L, 112L);
#else /* NO_PROTO */
    setmsg_("10 25 26", "<Inquire current element content> should return the\
 standard representation for all valid text precision values.", 8L, 112L);
#endif /* NO_PROTO */
    for (txprec = 0; txprec <= 2; ++txprec) {
	nstxpr (&txprec);
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intar[0] == txprec && intg == 1 && rl == 0 && str 
		== 0) {
/*            OK so far */
	} else {
	    fail_();
	    s_wsfi(&io___16);
	    do_fio(&c__1, "Failure for text precision = ", 29L);
	    do_fio(&c__1, (char *)&txprec, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 200L);
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
/* *** *** *** *** ***    Character expansion   *** *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    txatr1 = .4f;
#else /* NO_PROTO */
    txatr1 = (float).4;
#endif /* NO_PROTO */
    nschxp (&txatr1);
#ifndef NO_PROTO
    setmsg_("9 34", "<Inquire current element type and size> should return c"
	    "haracter expansion as the type of the created element and the ap"
	    "propriate element size.", 4L, 142L);
#else /* NO_PROTO */
    setmsg_("9 34", "<Inquire current element type and size> should return c\
haracter expansion as the type of the created element and the appropriate el\
ement size.", 4L, 142L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 31 is the PHIGS enumeration type for pechxp */
    L__1 = errind == 0 && eltype == 31 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 34", "<Inquire current element content> should return the st"
	    "andard representation for the character expansion value.", 5L, 
	    110L);
#else /* NO_PROTO */
    setmsg_("10 34", "<Inquire current element content> should return the st\
andard representation for the character expansion value.", 5L, 110L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pechxp */
    L__1 = errind == 0 && rlar[0] == txatr1 && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Character spacing  *** *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    txatr1 = .25f;
#else /* NO_PROTO */
    txatr1 = (float).25;
#endif /* NO_PROTO */
    nschsp (&txatr1);
#ifndef NO_PROTO
    setmsg_("9 40", "<Inquire current element type and size> should return c"
	    "haracter spacing as the type of the created element and the appr"
	    "opriate element size.", 4L, 140L);
#else /* NO_PROTO */
    setmsg_("9 40", "<Inquire current element type and size> should return c\
haracter spacing as the type of the created element and the appropriate elem\
ent size.", 4L, 140L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 32 is the PHIGS enumeration type for pechsp */
    L__1 = errind == 0 && eltype == 32 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 40", "<Inquire current element content> should return the st"
	    "andard representation for the character spacing value.", 5L, 108L)
	    ;
#else /* NO_PROTO */
    setmsg_("10 40", "<Inquire current element content> should return the st\
andard representation for the character spacing value.", 5L, 108L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pechsp */
    L__1 = errind == 0 && rlar[0] == txatr1 && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Text colour index  *** *** *** *** *** */
/* set value for attribute */
    nstxci (&c__2);
#ifndef NO_PROTO
    setmsg_("9 46", "<Inquire current element type and size> should return t"
	    "ext colour index as the type of the created element and the appr"
	    "opriate element size.", 4L, 140L);
#else /* NO_PROTO */
    setmsg_("9 46", "<Inquire current element type and size> should return t\
ext colour index as the type of the created element and the appropriate elem\
ent size.", 4L, 140L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 33 is the PHIGS enumeration type for petxci */
    L__1 = errind == 0 && eltype == 33 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 46", "<Inquire current element content> should return the st"
	    "andard representation for the text colour index value.", 5L, 108L)
	    ;
#else /* NO_PROTO */
    setmsg_("10 46", "<Inquire current element content> should return the st\
andard representation for the text colour index value.", 5L, 108L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type petxci */
    L__1 = errind == 0 && intar[0] == 2 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Character height  *** *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    txatr1 = .35f;
#else /* NO_PROTO */
    txatr1 = (float).35;
#endif /* NO_PROTO */
    nschh (&txatr1);
#ifndef NO_PROTO
    setmsg_("9 52", "<Inquire current element type and size> should return c"
	    "haracter height as the type of the created element and the appro"
	    "priate element size.", 4L, 139L);
#else /* NO_PROTO */
    setmsg_("9 52", "<Inquire current element type and size> should return c\
haracter height as the type of the created element and the appropriate eleme\
nt size.", 4L, 139L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 34 is the PHIGS enumeration type for pechh */
    L__1 = errind == 0 && eltype == 34 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 52", "<Inquire current element content> should return the st"
	    "andard representation for the character height value.", 5L, 107L);

#else /* NO_PROTO */
    setmsg_("10 52", "<Inquire current element content> should return the st\
andard representation for the character height value.", 5L, 107L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pechh */
    L__1 = errind == 0 && rlar[0] == txatr1 && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Character up vector  *** *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    txatr1 = .25f;
    txatr2 = .13f;
#else /* NO_PROTO */
    txatr1 = (float).25;
    txatr2 = (float).13;
#endif /* NO_PROTO */
    nschup (&txatr1, &txatr2);
#ifndef NO_PROTO
    setmsg_("9 79", "<Inquire current element type and size> should return c"
	    "haracter up vector as the type of the created element and the ap"
	    "propriate element size.", 4L, 142L);
#else /* NO_PROTO */
    setmsg_("9 79", "<Inquire current element type and size> should return c\
haracter up vector as the type of the created element and the appropriate el\
ement size.", 4L, 142L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 35 is the PHIGS enumeration type for pechup */
    L__1 = errind == 0 && eltype == 35 && intlen == 0 && rllen == 2 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 79", "<Inquire current element content> should return the st"
	    "andard representation for the character up vector value.", 5L, 
	    110L);
#else /* NO_PROTO */
    setmsg_("10 79", "<Inquire current element content> should return the st\
andard representation for the character up vector value.", 5L, 110L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pechup */
    L__1 = errind == 0 && rlar[0] == txatr1 && rlar[1] == txatr2 && intg == 0 
	    && rl == 2 && str == 0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Text path  *** *** *** *** *** */
/* set value for attribute */
    nstxp (&c__1);
#ifndef NO_PROTO
    setmsg_("9 64", "<Inquire current element type and size> should return t"
	    "ext path as the type of the created element and the appropriate "
	    "element size.", 4L, 132L);
#else /* NO_PROTO */
    setmsg_("9 64", "<Inquire current element type and size> should return t\
ext path as the type of the created element and the appropriate element size."
	    , 4L, 132L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 36 is the PHIGS enumeration type for petxp */
    L__1 = errind == 0 && eltype == 36 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 64 65", "<Inquire current element content> should return the"
	    " standard representation for all valid text path values.", 8L, 
	    107L);
#else /* NO_PROTO */
    setmsg_("10 64 65", "<Inquire current element content> should return the\
 standard representation for all valid text path values.", 8L, 107L);
#endif /* NO_PROTO */
    for (txpath = 0; txpath <= 3; ++txpath) {
	nstxp (&txpath);
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intar[0] == txpath && intg == 1 && rl == 0 && str 
		== 0) {
/*            OK so far */
	} else {
	    fail_();
	    s_wsfi(&io___20);
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
L210:
/* *** *** *** *** ***    Text alignment    *** *** *** *** *** */
/* set value for attribute */
    nstxal (&c__2, &c__4);
#ifndef NO_PROTO
    setmsg_("9 72", "<Inquire current element type and size> should return t"
	    "ext alignment as the type of the created element and the appropr"
	    "iate element size.", 4L, 137L);
#else /* NO_PROTO */
    setmsg_("9 72", "<Inquire current element type and size> should return t\
ext alignment as the type of the created element and the appropriate element\
 size.", 4L, 137L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 37 is the PHIGS enumeration type for petxal */
    L__1 = errind == 0 && eltype == 37 && intlen == 2 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10 72 73", "<Inquire current element content> should return the"
	    " standard representation for all valid text alignment values.", 
	    8L, 112L);
#else /* NO_PROTO */
    setmsg_("10 72 73", "<Inquire current element content> should return the\
 standard representation for all valid text alignment values.", 8L, 112L);
#endif /* NO_PROTO */
    for (txhor = 0; txhor <= 3; ++txhor) {
	for (txver = 0; txver <= 5; ++txver) {
	    nstxal (&txhor, &txver);
	    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, 
		    &str, strarl, strar, 1L);
	    if (errind == 0 && intg == 2 && intar[0] == txhor && intar[1] == 
		    txver && rl == 0 && str == 0) {
/*            OK so far */
	    } else {
		fail_();
		s_wsfi(&io___23);
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
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

