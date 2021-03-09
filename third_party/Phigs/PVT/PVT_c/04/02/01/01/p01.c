/* fort/04/02/01/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__6 = 6;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.01/01                        * */
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

    /* Local variables */
    static integer rl, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln (), endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
    static real lwscf;
    static integer ltval, strid;
    static char strar[1*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nqceco (integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqceco ();
#endif /* NO_PROTO */
    static integer errind, intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nsplci (integer *), 
	    nqcets (integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nsplci (), nqcets ();
#endif /* NO_PROTO */
    static integer eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nslwsc (real *), xpopph_(integer *, integer *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nslwsc (), xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("04.02.01.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Linetype    *** *** *** *** *** */
/* set value for attribute */
    ltval = 33;
    nsln (&ltval);
#ifndef NO_PROTO
    setmsg_("1 4", "<Inquire current element type and size> should return li"
	    "netype as the type of the created element and the appropriate el"
	    "ement size.", 3L, 131L);
#else /* NO_PROTO */
    setmsg_("1 4", "<Inquire current element type and size> should return li\
netype as the type of the created element and the appropriate element size.", 
	    3L, 131L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 23 is the PHIGS enumeration type for peln */
    L__1 = errind == 0 && eltype == 23 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 4", "<Inquire current element content> should return the stan"
	    "dard representation for the linetype value.", 3L, 99L);
#else /* NO_PROTO */
    setmsg_("2 4", "<Inquire current element content> should return the stan\
dard representation for the linetype value.", 3L, 99L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peln */
    L__1 = errind == 0 && intar[0] == ltval && intg == 1 && rl == 0 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***   Linewidth scale factor   *** *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    lwscf = .45f;
#else /* NO_PROTO */
    lwscf = (float).45;
#endif /* NO_PROTO */
    nslwsc (&lwscf);
#ifndef NO_PROTO
    setmsg_("1 13", "<Inquire current element type and size> should return l"
	    "inewidth scale factor as the type of the created element and the"
	    " appropriate element size.", 4L, 145L);
#else /* NO_PROTO */
    setmsg_("1 13", "<Inquire current element type and size> should return l\
inewidth scale factor as the type of the created element and the appropriate\
 element size.", 4L, 145L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 24 is the PHIGS enumeration type for pelwsc */
    L__1 = errind == 0 && eltype == 24 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 13", "<Inquire current element content> should return the sta"
	    "ndard representation for the linewidth scale factor value.", 4L, 
	    113L);
#else /* NO_PROTO */
    setmsg_("2 13", "<Inquire current element content> should return the sta\
ndard representation for the linewidth scale factor value.", 4L, 113L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pelwsc */
    L__1 = errind == 0 && rlar[0] == lwscf && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Polyline colour index    *** *** *** *** *** */
/* set value for attribute */
    nsplci (&c__6);
#ifndef NO_PROTO
    setmsg_("1 19", "<Inquire current element type and size> should return p"
	    "olyline colour index as the type of the created element and the "
	    "appropriate element size.", 4L, 144L);
#else /* NO_PROTO */
    setmsg_("1 19", "<Inquire current element type and size> should return p\
olyline colour index as the type of the created element and the appropriate \
element size.", 4L, 144L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 25 is the PHIGS enumeration type for peplci */
    L__1 = errind == 0 && eltype == 25 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 19", "<Inquire current element content> should return the sta"
	    "ndard representation for the polyline colour index value.", 4L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("2 19", "<Inquire current element content> should return the sta\
ndard representation for the polyline colour index value.", 4L, 112L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peplci */
    L__1 = errind == 0 && intar[0] == 6 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* close it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

