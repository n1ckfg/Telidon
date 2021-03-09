/* fort/04/01/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.03/01                           * */
/*  *    TEST TITLE : Text element                          * */
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
    address a__1[2];
    integer i__1, i__2, i__3[2];
    logical L__1;
    char ch__1[223];
    icilist ici__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfi(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static integer rl, acs;
    static real xdv[2], ydv[2], zdv[2];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen), ntx3 (
	    real *, real *, real *, real *, real *, real *, char *, ftnlen), 
	    fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx (), ntx3 (), fail_();
#endif /* NO_PROTO */
    static integer nacs;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer ixacs, rllen, intar[50];
    static char acstr[200];
    static real xcord, ycord, zcord;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), inmsg_();
#endif /* NO_PROTO */
    static char strar[50*10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nqceco (integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqceco (), chkinq_();
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
    static integer strlen, strarl[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("04.01.03/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  *** *** *** *** ***   Text 3   *** *** *** *** *** */
#ifndef NO_PROTO
    xcord = 2.33f;
    ycord = -4.4f;
    zcord = 3.2e22f;
#else /* NO_PROTO */
    xcord = (float)2.33;
    ycord = (float)-4.4;
    zcord = (float)3.2e22;
#endif /* NO_PROTO */
    s_copy(chastr, "*#Testing#* ..123", 17L, 17L);
#ifndef NO_PROTO
    xdv[0] = -99.99f;
    ydv[0] = 0.f;
    zdv[0] = 3.2e-13f;
    xdv[1] = 7.3f;
    ydv[1] = -9876.5f;
    zdv[1] = -9.9e-8f;
#else /* NO_PROTO */
    xdv[0] = (float)-99.99;
    ydv[0] = (float)0.;
    zdv[0] = (float)3.2e-13;
    xdv[1] = (float)7.3;
    ydv[1] = (float)-9876.5;
    zdv[1] = (float)-9.9e-8;
#endif /* NO_PROTO */
/*  <text 3> with xcord, ycord, zcord, xdv, ydv, zdv, chastr */
    nopst (&c__1);
    ntx3 (&xcord, &ycord, &zcord, xdv, ydv, zdv, chastr, 17L);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return te"
	    "xt 3 as the type of the created element and the appropriate elem"
	    "ent size.", 3L, 129L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return te\
xt 3 as the type of the created element and the appropriate element size.", 
	    3L, 129L);
#endif /* NO_PROTO */
/*    (celtyp = text 3 and */
/*     celsiz = values specified by the standard and language binding; */
/*              fortran binding values are intlen, rllen, and strlen) */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 6 && intlen == 0 && rllen == 9 && strlen 
	    == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for text 3.", 3L, 87L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for text 3.", 3L, 87L);
#endif /* NO_PROTO */
/* ensure garbage in strar prior to inquire */
    s_copy(strar, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 50L, 
	    50L);
    nqceco (&c__50, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 50L);
    L__1 = errind == 0 && intg == 0 && rl == 9 && rlar[0] == xcord && rlar[1] 
	    == ycord && rlar[2] == zcord && rlar[3] == xdv[0] && rlar[4] == 
	    ydv[0] && rlar[5] == zdv[0] && rlar[6] == xdv[1] && rlar[7] == 
	    ydv[1] && rlar[8] == zdv[1] && str == 1 && strarl[0] == 17 && 
	    s_cmp(strar, chastr, 50L, 17L) == 0;
    ifpf_(&L__1);
/*  *** *** *** *** ***   Text   *** *** *** *** *** */
/*  <text> with xcord, ycord, chastr */
    ntx (&xcord, &ycord, chastr, 17L);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return te"
	    "xt as the type of the created element and the appropriate elemen"
	    "t size.", 3L, 127L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return te\
xt as the type of the created element and the appropriate element size.", 3L, 
	    127L);
#endif /* NO_PROTO */
/*    (celtyp = text and */
/*     celsiz = values specified by the standard and language binding; */
/*              fortran binding values are intlen, rllen, and strlen) */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 7 && intlen == 0 && rllen == 2 && strlen 
	    == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for text.", 3L, 85L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for text.", 3L, 85L);
#endif /* NO_PROTO */
/* ensure garbage in strar prior to inquire */
    s_copy(strar, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 50L, 
	    50L);
    nqceco (&c__50, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 50L);
    L__1 = errind == 0 && intg == 0 && rl == 2 && rlar[0] == xcord && rlar[1] 
	    == ycord && str == 1 && strarl[0] == 17 && s_cmp(strar, chastr, 
	    50L, 17L) == 0;
    ifpf_(&L__1);
/*  *** *** *** *** ***   Character sets   *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("7", "<Inquire phigs facilities> should be able to report the li"
	    "st of available character sets.", 1L, 89L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire phigs facilities> should be able to report the li\
st of available character sets.", 1L, 89L);
#endif /* NO_PROTO */
    nacs = -6;
    nqphf (&c__0, &errind, &idum1, &idum2, &idum3, &nacs, &idum4, &idum5, &
	    idum6);
    if (errind != 0 || nacs < 0) {
	fail_();
	goto L777;
    }
    s_copy(acstr, " ", 200L, 1L);
    i__1 = nacs;
    for (ixacs = 1; ixacs <= i__1; ++ixacs) {
	nqphf (&ixacs, &errind, &idum1, &idum2, &idum3, &idum4, &acs, &idum5, 
		&idum6);
	if (errind != 0) {
	    fail_();
	    goto L777;
	}
/* collect character sets */
	i__2 = ixacs * 5 - 5;
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = ixacs * 5 - i__2;
	ici__1.iciunit = acstr + i__2;
	ici__1.icifmt = "(I5)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&acs, (ftnlen)sizeof(integer));
	e_wsfi();
/* L710: */
    }
    pass_();
/* Writing concatenation */
    i__3[0] = 23, a__1[0] = "Character sets in list:";
    i__3[1] = 200, a__1[1] = acstr;
    s_cat(ch__1, a__1, i__3, &c__2, 223L);
    inmsg_(ch__1, 223L);
#ifndef NO_PROTO
    setmsg_("7 8", "The first entry in the list of available character sets "
	    "should be zero.", 3L, 71L);
#else /* NO_PROTO */
    setmsg_("7 8", "The first entry in the list of available character sets \
should be zero.", 3L, 71L);
#endif /* NO_PROTO */
    if (nacs >= 1) {
	nqphf (&c__1, &errind, &idum1, &idum2, &idum3, &idum4, &acs, &idum5, &
		idum6);
	chkinq_("pqphf", &errind, 5L);
	L__1 = acs == 0;
	ifpf_(&L__1);
    } else {
	fail_();
    }
L777:
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

