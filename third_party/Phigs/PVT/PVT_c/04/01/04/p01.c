/* fort/04/01/04/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.04/01                           * */
/*  *    TEST TITLE : Annotation text relative element      * */
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
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp();
#endif /* NO_PROTO */

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
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), natr3 (real *, real *, real *, real *, real *, real *, 
	    char *, ftnlen), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), natr3 (), endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
    static char strar[50*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nqceco (integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqceco ();
#endif /* NO_PROTO */
    static integer errind, intlen;
    static char chastr[17];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets ();
#endif /* NO_PROTO */
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
    static real xrefpt, yrefpt, zrefpt, xannpt, yannpt, zannpt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    initgl_("04.01.04/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  *** *** *** *** ***  Annotation text  3 element  *** *** *** *** *** 
*/
#ifndef NO_PROTO
    xrefpt = 2.33f;
    yrefpt = 0.f;
    zrefpt = 4e-4f;
    xannpt = -4.4f;
    yannpt = -99.99f;
    zannpt = 1e-4f;
#else /* NO_PROTO */
    xrefpt = (float)2.33;
    yrefpt = (float)0.;
    zrefpt = (float)4e-4;
    xannpt = (float)-4.4;
    yannpt = (float)-99.99;
    zannpt = (float)1e-4;
#endif /* NO_PROTO */
    s_copy(chastr, "*#Testing#* ..123", 17L, 17L);
    nopst (&c__1);
    natr3 (&xrefpt, &yrefpt, &zrefpt, &xannpt, &yannpt, &zannpt, chastr, 17L);

#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return an"
	    "notation text relative 3 as the type of the created element and "
	    "the appropriate element size.", 3L, 149L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return an\
notation text relative 3 as the type of the created element and the appropri\
ate element size.", 3L, 149L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 8 && intlen == 0 && rllen == 6 && strlen 
	    == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for annotation text relative 3.", 3L, 107L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for annotation text relative 3.", 3L, 107L);
#endif /* NO_PROTO */
/* ensure garbage in strar prior to inquire */
    s_copy(strar, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 50L, 
	    50L);
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 50L);
    L__1 = errind == 0 && intg == 0 && rl == 6 && rlar[0] == xrefpt && rlar[1]
	     == yrefpt && rlar[2] == zrefpt && rlar[3] == xannpt && rlar[4] ==
	     yannpt && rlar[5] == zannpt && str == 1 && strarl[0] == 17 && 
	    s_cmp(strar, chastr, 50L, 17L) == 0;
    ifpf_(&L__1);
/*  *** *** *** *** ***   Annotation text element  *** *** *** *** *** */
    natr (&xrefpt, &yrefpt, &xannpt, &yannpt, chastr, 17L);
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return an"
	    "notation text relative as the type of the created element and th"
	    "e appropriate element size.", 3L, 147L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return an\
notation text relative as the type of the created element and the appropriat\
e element size.", 3L, 147L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 9 && intlen == 0 && rllen == 4 && strlen 
	    == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for annotation text relative.", 3L, 105L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for annotation text relative.", 3L, 105L);
#endif /* NO_PROTO */
/* ensure garbage in strar prior to inquire */
    s_copy(strar, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 50L, 
	    50L);
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 50L);
    L__1 = errind == 0 && intg == 0 && rl == 4 && rlar[0] == xrefpt && rlar[1]
	     == yrefpt && rlar[2] == xannpt && rlar[3] == yannpt && str == 1 
	    && strarl[0] == 17 && s_cmp(strar, chastr, 50L, 17L) == 0;
    ifpf_(&L__1);
/* L777: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

