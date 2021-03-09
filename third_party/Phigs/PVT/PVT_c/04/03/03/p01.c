/* fort/04/03/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__10 = 10;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.03/01                           * */
/*  *    TEST TITLE : Set and inquire HLHSR identifier      * */
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
    static integer i, rl;
    static char msg[300];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer hrid;
    static real rlar[50];
    static integer intg, idum1, strl2[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer numid, rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *), nopst (integer *), nqceco (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nopwk (), nopst (), 
	    nqceco (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, intlen, unavid;
    static char drotdr[80*20];
    static integer specon, celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nshrid (integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nshrid (), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, strlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcets (integer *, integer *, integer *, 
	    integer *, integer *), nqhrif (integer *, integer *, integer *, 
	    integer *, integer *), errctl_(logical *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcets (), nqhrif (), errctl_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___21 = { 0, msg, 0, "(A, I5, A, I5)", 300, 1 };


/*  Declare program-specific variables */
/*  parameters for <inquire workstation connection and type> */
    initgl_("04.03.03/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* get this workstation type */
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* open structure */
    nopst (&c__1);
/* hrid = HLHSR identifier */
    hrid = 0;
    nshrid (&hrid);
/*      celtyp = current element type */
/*      celsiz = current element size */
/*      celcon = current element content */
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return HL"
	    "HSR identifier as the type of the created element and the approp"
	    "riate element size.", 3L, 139L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return HL\
HSR identifier as the type of the created element and the appropriate elemen\
t size.", 3L, 139L);
#endif /* NO_PROTO */
/* <inquire current element type and size> to determine celtyp, celsiz */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 56 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for HLHSR identifier.", 3L, 97L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for HLHSR identifier.", 3L, 97L);
#endif /* NO_PROTO */
/*  <inquire current element content> to determine celcon */
    nqceco (&c__50, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, drotdr, 80L);
    L__1 = errind == 0 && intg == 1 && intar[0] == hrid && rl == 0 && str == 
	    0;
    ifpf_(&L__1);
/* find an unavailable HLHSR identifier */
    unavid = 999;
    nqhrif (&specwt, &c__0, &errind, &numid, &idum1);
    chkinq_("pqhrif", &errind, 6L);
L90:
    i__1 = numid;
    for (i = 1; i <= i__1; ++i) {
	nqhrif (&specwt, &i, &errind, &idum1, &hrid);
	chkinq_("pqhrif", &errind, 6L);
	if (hrid == unavid) {
	    unavid *= 3;
	    goto L90;
	}
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("1 3", "Any HLHSR identifier should be accepted as valid, even i"
	    "f not supported by some workstation types.", 3L, 98L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("1 3", "Any HLHSR identifier should be accepted as valid, even i\
f not supported by some workstation types.", 3L, 98L);
    errctl_(&c__1);
#endif /* NO_PROTO */
    nshrid (&unavid);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    if (globnu_1.errsig != 0) {
	fail_();
	s_wsfi(&io___21);
	do_fio(&c__1, "HSHLR identifier set = ", 23L);
	do_fio(&c__1, (char *)&unavid, (ftnlen)sizeof(integer));
	do_fio(&c__1, " signalled error = ", 19L);
	do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
	goto L666;
    }
/*  <inquire current element content> to determine celcon */
    nqceco (&c__50, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, drotdr, 80L);
    L__1 = errind == 0 && intg == 1 && intar[0] == unavid && rl == 0 && str ==
	     0;
    ifpf_(&L__1);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

