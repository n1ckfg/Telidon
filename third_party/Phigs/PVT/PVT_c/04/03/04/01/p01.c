/* fort/04/03/04/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__5 = 5;
static integer c__50 = 50;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.01/01                        * */
/*  *    TEST TITLE : Simple setting and inquiring          * */
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
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer rl, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nads (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nads ();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nres (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nres ();
#endif /* NO_PROTO */
    static integer strl2[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[5];
#ifndef NO_PROTO
    extern logical setis_(integer *, char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern logical setis_();
    extern /* Subroutine */ int setvs_(), nopst ();
#endif /* NO_PROTO */
    static char datrec[80*20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco ();
#endif /* NO_PROTO */
    static char namval[50];
    static integer errind, namset[10], intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets ();
#endif /* NO_PROTO */
    static integer namsiz, celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer strlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  parameters for <inquire workstation connection and type> */
    initgl_("04.03.04.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open structure */
    nopst (&c__1);
/* initialize array */
    s_copy(namval, "30,62,63,0,1", 50L, 12L);
    setvs_(namval, namset, &namsiz, 50L);
/* <add name to set> */
    nads (&namsiz, namset);
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return ad"
	    "d names to set as the type of the created element and the approp"
	    "riate element size.", 3L, 139L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return ad\
d names to set as the type of the created element and the appropriate elemen\
t size.", 3L, 139L);
#endif /* NO_PROTO */
/* <inquire current element type and size> to determine celtyp, celsiz */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 53 && intlen == namsiz && rllen == 0 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3 9", "<Inquire current element content> should return the st"
	    "andard representation for add names to set for any set of names "
	    "drawn from the accessible range.", 5L, 150L);
#else /* NO_PROTO */
    setmsg_("1 3 9", "<Inquire current element content> should return the st\
andard representation for add names to set for any set of names drawn from t\
he accessible range.", 5L, 150L);
#endif /* NO_PROTO */
/*  <inquire current element content> to determine celcon */
    nqceco (&c__5, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, datrec, 80L);
    L__1 = errind == 0 && intg == namsiz && setis_(intar, namval, 50L) && rl 
	    == 0 && str == 0;
    ifpf_(&L__1);
/*  <remove name from set> */
    nres (&namsiz, namset);
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return re"
	    "move names from set as the type of the created element and the a"
	    "ppropriate element size.", 3L, 144L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return re\
move names from set as the type of the created element and the appropriate e\
lement size.", 3L, 144L);
#endif /* NO_PROTO */
/* <inquire current element type and size> to determine celtyp, celsiz */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 54 && intlen == namsiz && rllen == 0 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6 9", "<Inquire current element content> should return the st"
	    "andard representation for remove names from set for any set of n"
	    "ames drawn from the accessible range.", 5L, 155L);
#else /* NO_PROTO */
    setmsg_("4 6 9", "<Inquire current element content> should return the st\
andard representation for remove names from set for any set of names drawn f\
rom the accessible range.", 5L, 155L);
#endif /* NO_PROTO */
/*  <inquire current element content> to determine celcon */
    nqceco (&c__5, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, datrec, 80L);
    L__1 = errind == 0 && intg == namsiz && setis_(intar, namval, 50L) && rl 
	    == 0 && str == 0;
    ifpf_(&L__1);
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

