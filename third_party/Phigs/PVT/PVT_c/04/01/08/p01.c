/* fort/04/01/08/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c__2 = 2;
static integer c__20 = 20;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__50 = 50;
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b39 = 0.f;
#else /* NO_PROTO */
static real c_b39 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.08/01                           * */
/*  *    TEST TITLE : Generalized drawing primitive         * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real xarr[5] = { 0.f,-99.99f,1.3e-4f,3.2e-12f,-3.4e23f };
    static real yarr[5] = { 4.2f,0.f,99.99f,0.f,.002f };
    static real zarr[5] = { 34.2f,1.4f,3.2f,9900.f,0.f };
#else /* NO_PROTO */
    static real xarr[5] = { (float)0.,(float)-99.99,(float)1.3e-4,(float)
	    3.2e-12,(float)-3.4e23 };
    static real yarr[5] = { (float)4.2,(float)0.,(float)99.99,(float)0.,(
	    float).002 };
    static real zarr[5] = { (float)34.2,(float)1.4,(float)3.2,(float)9900.,(
	    float)0. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1, i__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, j, id, rl;
    static char msg[300];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer bndl[5], nbnd;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ngdp (integer *, real *, 
	    real *, integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ngdp ();
#endif /* NO_PROTO */
    static integer idum;
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), ngdp3 (integer *, real *, real *,
	     real *, integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), ngdp3 ();
#endif /* NO_PROTO */
    static integer strl2[10], gdpel[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nprec (integer *, integer *, integer *, real *
	    , integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, ftnlen, ftnlen), inmsg_(char *, ftnlen), nurec (integer *,
	     char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, integer *, char *, 
	    ftnlen, ftnlen), nqgdp (integer *, integer *, integer *, integer *
	    , integer *);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), nopst (
	    integer *), nqegd3 (integer *, integer *, integer *, integer *, 
	    integer *), nqgdp3 (integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nprec (), inmsg_(), nurec (), nqgdp ();
    extern integer itrim_();
    extern /* Subroutine */ int nqwkc (), nopwk (), nopst (), nqegd3 (), 
	    nqgdp3 ();
#endif /* NO_PROTO */
    static integer ldract;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco ();
#endif /* NO_PROTO */
    static integer ugdpid;
    static real rlcomb[15];
    static integer maxgdp;
    static char drindr[80*20];
    static integer errind, intlen, drinin[50], drinsl[10], celtyp, drotin[50],
	     strlen, drotsl[10], numgdp, thiset;
    static real drinrl[50], drotrl[50];
    static char drotdr[80*20], drinst[30*10], drotst[30*10];
    static integer specwt, specon, numpts;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), chkinq_(char *, integer *, ftnlen), setmsg_(char *, 
	    char *, ftnlen, ftnlen), nqcets (integer *, integer *, integer *, 
	    integer *, integer *), nqegdp (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), chkinq_(), setmsg_(), 
	    nqcets (), nqegdp ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___26 = { 0, msg, 0, "(A,I4,A)", 300, 1 };
    static icilist io___43 = { 0, msg, 0, "(A,I4,A)", 300, 1 };


/* GDP attributes */
/* GDP attributes for PHIGS-PLUS */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.01.08/01", 11L);
    numpts = 5;
/* set up comparison values */
    i__1 = numpts;
    for (i = 1; i <= i__1; ++i) {
	rlcomb[i - 1] = xarr[i - 1];
	rlcomb[i + 4] = yarr[i - 1];
	rlcomb[i + 9] = zarr[i - 1];
/* L10: */
    }
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* get this workstation type */
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  dr = data record to hold */
/*  integers: 174, 175, 176 */
/*  reals:    17.4,17.5,17.6 */
/*  strings:  "This is a GDP test string.", "This is another." */
    drinin[0] = 174;
    drinin[1] = 175;
    drinin[2] = 176;
#ifndef NO_PROTO
    drinrl[0] = 17.4f;
    drinrl[1] = 17.5f;
    drinrl[2] = 17.6f;
#else /* NO_PROTO */
    drinrl[0] = (float)17.4;
    drinrl[1] = (float)17.5;
    drinrl[2] = (float)17.6;
#endif /* NO_PROTO */
    s_copy(drinst, "This is a GDP test string.", 30L, 26L);
    s_copy(drinst + 30, "This is another.", 30L, 16L);
    drinsl[0] = itrim_(drinst, 30L);
    drinsl[1] = itrim_(drinst + 30, 30L);
/* pack data record */
    nprec (&c__3, drinin, &c__3, drinrl, &c__2, drinsl, drinst, &c__20, &
	    errind, &ldract, drindr, 30L, 80L);
    chkinq_("pprec", &errind, 5L);
/* *** *** *** *** ***   Generalized drawing primitive 3   *** *** *** ***
 ****/
#ifndef NO_PROTO
    setmsg_("4", "<Inquire list of available generalized drawing primitives "
	    "3> should be able to return the list of GDP 3 identifiers.", 1L, 
	    116L);
#else /* NO_PROTO */
    setmsg_("4", "<Inquire list of available generalized drawing primitives \
3> should be able to return the list of GDP 3 identifiers.", 1L, 116L);
#endif /* NO_PROTO */
/* get list size */
    numgdp = 666;
    nqegd3 (&specwt, &c__0, &errind, &numgdp, &idum);
    chkinq_("pqegd3", &errind, 6L);
    maxgdp = -999999;
    i__1 = numgdp;
    for (i = 1; i <= i__1; ++i) {
	id = -666;
	nqegd3 (&specwt, &i, &errind, &idum, &id);
	if (errind != 0) {
	    fail_();
	    goto L110;
	}
/* save GDP id's */
	gdpel[i - 1] = id;
	maxgdp = max(maxgdp,id);
/* L100: */
    }
    pass_();
L110:
#ifndef NO_PROTO
    setmsg_("5", "<Inquire generalized drawing primitive 3> should be able t"
	    "o return the list of sets of attributes used by a given GDP 3 id"
	    "entifier.", 1L, 131L);
#else /* NO_PROTO */
    setmsg_("5", "<Inquire generalized drawing primitive 3> should be able t\
o return the list of sets of attributes used by a given GDP 3 identifier.", 
	    1L, 131L);
#endif /* NO_PROTO */
    i__1 = numgdp;
    for (i = 1; i <= i__1; ++i) {
	nbnd = -6;
	bndl[0] = -6;
	nqgdp3 (&specwt, &gdpel[i - 1], &errind, &nbnd, bndl);
	if (errind != 0 || nbnd < 0 || nbnd > 7) {
	    goto L210;
	}
/* check bndl validity */
	i__2 = nbnd;
	for (j = 1; j <= i__2; ++j) {
	    thiset = bndl[j - 1];
	    if (thiset < 0 || thiset > 5) {
		goto L210;
	    }
/* L2010: */
	}
/* L200: */
    }
    pass_();
    goto L220;
L210:
    fail_();
    s_wsfi(&io___26);
    do_fio(&c__1, "Failure at GDP id = ", 20L);
    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
L220:
/*  select ugdpid = not in gdplist (unsupported) */
    ugdpid = maxgdp + 1;
    nopst (&c__1);
    ngdp3 (&numpts, xarr, yarr, zarr, &ugdpid, &ldract, drindr, 80L);
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return ge"
	    "neralized drawing primitive 3 as the type of the created element"
	    " and the appropriate element size.", 3L, 154L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return ge\
neralized drawing primitive 3 as the type of the created element and the app\
ropriate element size.", 3L, 154L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 16 && intlen == 2 && rllen == numpts * 3 
	    && strlen == ldract;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for a generalized drawing primitive 3.", 3L, 
	    114L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for a generalized drawing primitive 3.", 3L, 114L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, drotdr, 80L);
    if (errind == 0 && intg == 2 && intar[0] == numpts && intar[1] == ugdpid 
	    && rl == numpts * 3 && str == ldract) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PQCECO are incorrect.", 38L);
	goto L625;
    }
    i__1 = numpts * 3;
    if (! rareq_(&i__1, rlar, rlcomb, &c_b39, &c_b39)) {
	fail_();
	inmsg_("Geometric point values are incorrect.", 37L);
	goto L625;
    }
    i__1 = ldract;
    for (j = 1; j <= i__1; ++j) {
	if (strl2[j - 1] != 80) {
	    fail_();
	    inmsg_("Reported length of data record from PQCECO is incorrect.",
		     56L);
	    goto L625;
	}
/* L20: */
    }
/*  unpack DR and compare all 4 arrays */
    nurec (&ldract, drotdr, &c__50, &c__50, &c__10, &errind, &intg, drotin, &
	    rl, drotrl, &str, drotsl, drotst, 80L, 30L);
    if (errind == 0 && intg == 3 && rl == 3 && str == 2) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PUREC are incorrect.", 37L);
	goto L625;
    }
    if (drinin[0] == drotin[0] && drinin[1] == drotin[1] && drinin[2] == 
	    drotin[2]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Integer array from PUREC is incorrect.", 38L);
	goto L625;
    }
    if (drinrl[0] == drotrl[0] && drinrl[1] == drotrl[1] && drinrl[2] == 
	    drotrl[2]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Real array from PUREC is incorrect.", 35L);
	goto L625;
    }
    if (drinsl[0] == drotsl[0] && drinsl[1] == drotsl[1]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String-length array from PUREC is incorrect.", 44L);
	goto L625;
    }
    if (s_cmp(drinst, drotst, 30L, 30L) == 0 && s_cmp(drinst + 30, drotst + 
	    30, 30L, 30L) == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String array from PUREC is incorrect.", 37L);
	goto L625;
    }
    pass_();
L625:
/* *** *** *** *** ***   Generalized drawing primitive   *** *** *** *** 
****/
#ifndef NO_PROTO
    setmsg_("9", "<Inquire list of available generalized drawing primitives>"
	    " should be able to return the list of GDP identifiers.", 1L, 112L)
	    ;
#else /* NO_PROTO */
    setmsg_("9", "<Inquire list of available generalized drawing primitives>\
 should be able to return the list of GDP identifiers.", 1L, 112L);
#endif /* NO_PROTO */
/* get list size */
    numgdp = 666;
    nqegdp (&specwt, &c__0, &errind, &numgdp, &idum);
    chkinq_("pqegdp", &errind, 6L);
    maxgdp = -999999;
    i__1 = numgdp;
    for (i = 1; i <= i__1; ++i) {
	id = -666;
	nqegdp (&specwt, &i, &errind, &idum, &id);
	if (errind != 0) {
	    fail_();
	    goto L2110;
	}
/* save GDP id's */
	gdpel[i - 1] = id;
	maxgdp = max(maxgdp,id);
/* L2100: */
    }
    pass_();
L2110:
#ifndef NO_PROTO
    setmsg_("10", "<Inquire generalized drawing primitive> should be able to"
	    " return the list of sets of attributes used by a given GDP ident"
	    "ifier.", 2L, 127L);
#else /* NO_PROTO */
    setmsg_("10", "<Inquire generalized drawing primitive> should be able to\
 return the list of sets of attributes used by a given GDP identifier.", 2L, 
	    127L);
#endif /* NO_PROTO */
    i__1 = numgdp;
    for (i = 1; i <= i__1; ++i) {
	nbnd = -6;
	bndl[0] = -6;
	nqgdp (&specwt, &gdpel[i - 1], &errind, &nbnd, bndl);
	if (errind != 0 || nbnd < 0 || nbnd > 7) {
	    goto L2210;
	}
/* check bndl validity */
	i__2 = nbnd;
	for (j = 1; j <= i__2; ++j) {
	    thiset = bndl[j - 1];
	    if (thiset < 0 || thiset > 5) {
		goto L2210;
	    }
/* L22010: */
	}
/* L2200: */
    }
    pass_();
    goto L2220;
L2210:
    fail_();
    s_wsfi(&io___43);
    do_fio(&c__1, "Failure at GDP id = ", 20L);
    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
L2220:
/*  select ugdpid = not in gdplist (unsupported) */
    ugdpid = maxgdp + 1;
    ngdp (&numpts, xarr, yarr, &ugdpid, &ldract, drindr, 80L);
#ifndef NO_PROTO
    setmsg_("6 7", "<Inquire current element type and size> should return ge"
	    "neralized drawing primitive as the type of the created element a"
	    "nd the appropriate element size.", 3L, 152L);
#else /* NO_PROTO */
    setmsg_("6 7", "<Inquire current element type and size> should return ge\
neralized drawing primitive as the type of the created element and the appro\
priate element size.", 3L, 152L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 17 && intlen == 2 && rllen == numpts << 1 
	    && strlen == ldract;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6 8", "<Inquire current element content> should return the stan"
	    "dard representation for a generalized drawing primitive.", 3L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("6 8", "<Inquire current element content> should return the stan\
dard representation for a generalized drawing primitive.", 3L, 112L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, drotdr, 80L);
    if (errind == 0 && intg == 2 && intar[0] == numpts && intar[1] == ugdpid 
	    && rl == numpts << 1 && str == ldract) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PQCECO are incorrect.", 38L);
	goto L777;
    }
    i__1 = numpts << 1;
    if (! rareq_(&i__1, rlar, rlcomb, &c_b39, &c_b39)) {
	fail_();
	inmsg_("Geometric point values are incorrect.", 37L);
	goto L777;
    }
    i__1 = ldract;
    for (j = 1; j <= i__1; ++j) {
	if (strl2[j - 1] != 80) {
	    fail_();
	    inmsg_("Reported length of data record from PQCECO is incorrect.",
		     56L);
	    goto L777;
	}
/* L120: */
    }
/*  unpack DR and compare all 4 arrays */
    nurec (&ldract, drotdr, &c__50, &c__50, &c__10, &errind, &intg, drotin, &
	    rl, drotrl, &str, drotsl, drotst, 80L, 30L);
    if (errind == 0 && intg == 3 && rl == 3 && str == 2) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes from PUREC are incorrect.", 37L);
	goto L777;
    }
    if (drinin[0] == drotin[0] && drinin[1] == drotin[1] && drinin[2] == 
	    drotin[2]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Integer array from PUREC is incorrect.", 38L);
	goto L777;
    }
    if (drinrl[0] == drotrl[0] && drinrl[1] == drotrl[1] && drinrl[2] == 
	    drotrl[2]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Real array from PUREC is incorrect.", 35L);
	goto L777;
    }
    if (drinsl[0] == drotsl[0] && drinsl[1] == drotsl[1]) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String-length array from PUREC is incorrect.", 44L);
	goto L777;
    }
    if (s_cmp(drinst, drotst, 30L, 30L) == 0 && s_cmp(drinst + 30, drotst + 
	    30, 30L, 30L) == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("String array from PUREC is incorrect.", 37L);
	goto L777;
    }
    pass_();
L777:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

