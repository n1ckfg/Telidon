/* fort/06/02/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;
static integer c__20 = 20;
static integer c__1 = 1;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/01                           * */
/*  *    TEST TITLE : View index                            * */
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
    static integer iar[20];
    static real rar[20];
    static char msg[300];
    static integer vwi;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer isiz, rsiz, ssiz, idum1, idum2, idum3, idum4, idum5, idum6,
	     idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc ();
#endif /* NO_PROTO */
    static char strar[80*20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nopst (integer *), nsvwi (integer *), nqceco (integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nopst (), nsvwi (), nqceco (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, unavid, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcets (integer *, integer *, integer *, integer *, integer *), 
	    errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcets (), errctl_();
#endif /* NO_PROTO */
    static integer specwt, lstrar[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___22 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };


/* element type */
    initgl_("06.02.02/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopst (&c__10);
    vwi = 0;
    nsvwi (&vwi);
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return vi"
	    "ew index as the type of the created element and the appropriate "
	    "element size.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return vi\
ew index as the type of the created element and the appropriate element size."
	    , 3L, 133L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &isiz, &rsiz, &ssiz);
    L__1 = errind == 0 && celtyp == 65 && isiz == 1 && rsiz == 0 && ssiz == 0;

    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for view index, when the index is 0.", 3L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for view index, when the index is 0.", 3L, 112L);
#endif /* NO_PROTO */
    nqceco (&c__20, &c__20, &c__20, &errind, &isiz, iar, &rsiz, rar, &ssiz, 
	    lstrar, strar, 80L);
    L__1 = errind == 0 && isiz == 1 && iar[0] == vwi && rsiz == 0 && ssiz == 
	    0;
    ifpf_(&L__1);
/*  <inquire workstation state table lengths> to determine */
/*     unavid = view index not available for primary workstation type */
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &idum7, &unavid);
    chkinq_("pqwksl", &errind, 6L);
    unavid += 3;
#ifndef NO_PROTO
    setmsg_("1 3", "Any non-negative view index should be accepted as valid,"
	    " even if not supported by some workstation types.", 3L, 105L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("1 3", "Any non-negative view index should be accepted as valid,\
 even if not supported by some workstation types.", 3L, 105L);
    errctl_(&c__1);
#endif /* NO_PROTO */
    nsvwi (&unavid);
    if (globnu_1.errsig != 0) {
	fail_();
	s_wsfi(&io___22);
	do_fio(&c__1, "<Set view index> with view index = ", 35L);
	do_fio(&c__1, (char *)&unavid, (ftnlen)sizeof(integer));
	do_fio(&c__1, " failed with error code = ", 26L);
	do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 300L);
	goto L666;
    }
    nqceco (&c__20, &c__20, &c__20, &errind, &isiz, iar, &rsiz, rar, &ssiz, 
	    lstrar, strar, 80L);
    L__1 = errind == 0 && isiz == 1 && iar[0] == unavid && rsiz == 0 && ssiz 
	    == 0;
    ifpf_(&L__1);
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

