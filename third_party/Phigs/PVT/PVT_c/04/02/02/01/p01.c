/* fort/04/02/02/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.01/01                        * */
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
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static real mkscf;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50], mtval, strid;
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
    extern /* Subroutine */ int initgl_(char *, ftnlen), nspmci (integer *), 
	    nqcets (integer *, integer *, integer *, integer *, integer *), 
	    nsmksc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nspmci (), nqcets (), nsmksc ();
#endif /* NO_PROTO */
    static integer eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("04.02.02.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Marker type    *** *** *** *** *** */
/* set value for attribute */
    mtval = 17;
    nsmk (&mtval);
#ifndef NO_PROTO
    setmsg_("1 4", "<Inquire current element type and size> should return ma"
	    "rker type as the type of the created element and the appropriate"
	    " element size.", 3L, 134L);
#else /* NO_PROTO */
    setmsg_("1 4", "<Inquire current element type and size> should return ma\
rker type as the type of the created element and the appropriate element siz\
e.", 3L, 134L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 26 is the PHIGS enumeration type for pemk */
    L__1 = errind == 0 && eltype == 26 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 4", "<Inquire current element content> should return the stan"
	    "dard representation for the marker type value.", 3L, 102L);
#else /* NO_PROTO */
    setmsg_("2 4", "<Inquire current element content> should return the stan\
dard representation for the marker type value.", 3L, 102L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pemk */
    L__1 = errind == 0 && intar[0] == mtval && intg == 1 && rl == 0 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***   Marker size scale factor   *** *** *** *** *** */

/* set value for attribute */
#ifndef NO_PROTO
    mkscf = .25f;
#else /* NO_PROTO */
    mkscf = (float).25;
#endif /* NO_PROTO */
    nsmksc (&mkscf);
#ifndef NO_PROTO
    setmsg_("1 13", "<Inquire current element type and size> should return m"
	    "arker size scale factor as the type of the created element and t"
	    "he appropriate element size.", 4L, 147L);
#else /* NO_PROTO */
    setmsg_("1 13", "<Inquire current element type and size> should return m\
arker size scale factor as the type of the created element and the appropria\
te element size.", 4L, 147L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 27 is the PHIGS enumeration type for pemksc */
    L__1 = errind == 0 && eltype == 27 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 13", "<Inquire current element content> should return the sta"
	    "ndard representation for the marker size scale factor value.", 4L,
	     115L);
#else /* NO_PROTO */
    setmsg_("2 13", "<Inquire current element content> should return the sta\
ndard representation for the marker size scale factor value.", 4L, 115L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pemksc */
    L__1 = errind == 0 && rlar[0] == mkscf && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Polymarker colour index    *** *** *** *** *** 
*/
/* set value for attribute */
    nspmci (&c__2);
#ifndef NO_PROTO
    setmsg_("1 20", "<Inquire current element type and size> should return p"
	    "olymarker colour index as the type of the created element and th"
	    "e appropriate element size.", 4L, 146L);
#else /* NO_PROTO */
    setmsg_("1 20", "<Inquire current element type and size> should return p\
olymarker colour index as the type of the created element and the appropriat\
e element size.", 4L, 146L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 28 is the PHIGS enumeration type for pepmci */
    L__1 = errind == 0 && eltype == 28 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 20", "<Inquire current element content> should return the sta"
	    "ndard representation for the polymarker colour index value.", 4L, 
	    114L);
#else /* NO_PROTO */
    setmsg_("2 20", "<Inquire current element content> should return the sta\
ndard representation for the polymarker colour index value.", 4L, 114L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pepmci */
    L__1 = errind == 0 && intar[0] == 2 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

