/* fort/04/02/05/04/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__100 = 100;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.04/02                        * */
/*  *    TEST TITLE : Setting entries of various kinds      * */
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

    static integer defi[300] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    /* System generated locals */
    integer i__1, i__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, j, dx, dy, dx2, dy2, aii, pai, nie, dpi, isc;
    static char msg[300];
    static integer lui, isr, cnde;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer nnde;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer mpai;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, colia[
	    10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical arreq_(integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqpar (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), unmsg_(
	    char *, ftnlen), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical arreq_();
    extern /* Subroutine */ int inmsg_(), nqpar (), nqwkc (), nspar (), 
	    unmsg_(), nopwk ();
#endif /* NO_PROTO */
    static integer colia2[10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), nqepai (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), nqepai ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
#else /* NO_PROTO */
    extern logical patavl_();
#endif /* NO_PROTO */
    static integer listel, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, listot;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___19 = { 0, msg, 0, "(A,A,2I5,A)", 300, 1 };
    static icilist io___31 = { 0, msg, 0, "(A,A,2I5,A)", 300, 1 };
    static icilist io___32 = { 0, msg, 0, "(A,A,2I5,A)", 300, 1 };


/* define a number greater than the number of initialized pattern entries 
*/
/* PHIGS parameter types */
/* interior style */
/* type of returned value */
/* used to control tests */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.04/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (! patavl_(&specwt)) {
#ifndef NO_PROTO
	inmsg_("Skipping all tests because pattern interior style is not sup"
		"ported on this workstation.", 87L);
#else /* NO_PROTO */
	inmsg_("Skipping all tests because pattern interior style is not sup\
ported on this workstation.", 87L);
#endif /* NO_PROTO */
	goto L666;
    }
/* determine mpai = max # pattern entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &mpai, &
	    idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* *** *** *** *** ***    initialized entries   *** *** *** *** *** */
/* There should be at least 1 predefined pattern - */
/* This statement is NOT meant to test the requirement of */
/* 1 predefined pattern; that is done elsewhere. */
#ifndef NO_PROTO
    setmsg_("3", "<Inquire list of pattern indices> should return initialize"
	    "d indices.", 1L, 68L);
#else /* NO_PROTO */
    setmsg_("3", "<Inquire list of pattern indices> should return initialize\
d indices.", 1L, 68L);
#endif /* NO_PROTO */
/*   nie = number of initialized pattern entries */
/*   aii = an initialized index (the first) */
    nqepai (&globnu_1.wkid, &c__1, &errind, &nie, &aii);
    if (errind != 0) {
	fail_();
	goto L200;
    } else {
	pass_();
    }
/* get initialized attributes */
    nqpar (&globnu_1.wkid, &aii, &c__0, &c__100, &c__100, &errind, &dx, &dy, 
	    colia);
/* check errind for overflow */
    if (errind == 2001) {
	s_wsfi(&io___19);
	do_fio(&c__1, "PQPAR returned Fortran error ", 29L);
	do_fio(&c__1, "2001: declared array size of (", 30L);
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_fio(&c__1, ") insufficient.", 15L);
	e_wsfi();
	inmsg_(msg, 300L);
	goto L200;
    }
    chkinq_("pqpar", &errind, 5L);
/* set different values for attributes */
    i__1 = dx;
    for (i = 1; i <= i__1; ++i) {
	i__2 = dy;
	for (j = 1; j <= i__2; ++j) {
	    colia2[i + j * 100 - 101] = colia[i + j * 100 - 101] + 1;
/* L75: */
	}
/* L80: */
    }
    isc = 1;
    isr = 1;
    dx2 = dx;
    dy2 = dy;
    nspar (&globnu_1.wkid, &aii, &c__100, &c__100, &isc, &isr, &dx2, &dy2, 
	    colia2);
/* get current number of defined entries */
    nqepai (&globnu_1.wkid, &c__0, &errind, &cnde, &idum1);
    chkinq_("pqepai", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("1 3", "Redefining a system-initialized entry should not change "
	    "the number of defined entries.", 3L, 86L);
#else /* NO_PROTO */
    setmsg_("1 3", "Redefining a system-initialized entry should not change \
the number of defined entries.", 3L, 86L);
#endif /* NO_PROTO */
    L__1 = cnde == nie;
    ifpf_(&L__1);
/* check that aii is still among defined entries */
#ifndef NO_PROTO
    setmsg_("1 3", "Initialized table entry should be reported as defined af"
	    "ter being set.", 3L, 70L);
#else /* NO_PROTO */
    setmsg_("1 3", "Initialized table entry should be reported as defined af\
ter being set.", 3L, 70L);
#endif /* NO_PROTO */
    i__1 = nie;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepai (&globnu_1.wkid, &listel, &errind, &idum1, &pai);
	chkinq_("pqepai", &errind, 6L);
	if (pai == aii) {
	    pass_();
	    goto L160;
	}
/* L150: */
    }
    fail_();
    goto L200;
L160:
    nqpar (&globnu_1.wkid, &aii, &c__0, &c__100, &c__100, &errind, &dx, &dy, 
	    colia);
    chkinq_("pqpar", &errind, 5L);
    setmsg_("2 5", "New values should be set for initialized table entry.", 
	    3L, 53L);
    L__1 = dx2 == dx && dy2 == dy && arreq_(&c__100, &c__100, &isc, &isr, &
	    dx2, &dy2, colia2, colia);
    ifpf_(&L__1);
/* *** *** *** *** ***    undefined entries   *** *** *** *** *** */
L200:
/* get lowest undefined index */
/* get current number defined entries */
    nqepai (&globnu_1.wkid, &c__0, &errind, &cnde, &idum1);
    chkinq_("pqepai", &errind, 6L);
/* defi is originally an array of zeros */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepai (&globnu_1.wkid, &listel, &errind, &idum1, &pai);
	chkinq_("pqepai", &errind, 6L);
/* mark as defined any index .le. cnde+1 */
/* This will leave at least one UNmarked */
	if (pai <= cnde + 1) {
	    defi[pai - 1] = 1;
	}
/* L250: */
    }
/* first remaining zero indicates undefined entry */
    i__1 = cnde + 1;
    for (pai = 1; pai <= i__1; ++pai) {
	if (defi[pai - 1] == 0) {
/* determine lowest undefined index (not in defined list) = lui */

	    lui = pai;
	    goto L270;
	}
/* L260: */
    }
    unmsg_("Cannot find undefined index - error in test algorithm.", 54L);
/* established lui as lowest undefined index */
L270:
/* inquire undefined table entry as REALIZED */
    nqpar (&globnu_1.wkid, &lui, &c__1, &c__100, &c__100, &errind, &dx, &dy, 
	    colia);
/* check errind for overflow */
    if (errind == 2001) {
	s_wsfi(&io___31);
	do_fio(&c__1, "PQPAR returned Fortran error ", 29L);
	do_fio(&c__1, "2001: declared array size of (", 30L);
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_fio(&c__1, ") insufficient.", 15L);
	e_wsfi();
	inmsg_(msg, 300L);
	goto L350;
    }
    chkinq_("pqpar", &errind, 5L);
/* inquire pattern index #1 as REALIZED */
    nqpar (&globnu_1.wkid, &c__1, &c__1, &c__100, &c__100, &errind, &dx2, &
	    dy2, colia2);
/* check errind for overflow */
    if (errind == 2001) {
	s_wsfi(&io___32);
	do_fio(&c__1, "PQPAR returned Fortran error ", 29L);
	do_fio(&c__1, "2001: declared array size of (", 30L);
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_fio(&c__1, ") insufficient.", 15L);
	e_wsfi();
	inmsg_(msg, 300L);
	goto L350;
    }
    chkinq_("pqpar", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("3 7", "<Inquire pattern representation> should return attribute"
	    "s for pattern index #1 when inquiring an undefined entry as REAL"
	    "IZED.", 3L, 125L);
#else /* NO_PROTO */
    setmsg_("3 7", "<Inquire pattern representation> should return attribute\
s for pattern index #1 when inquiring an undefined entry as REALIZED.", 3L, 
	    125L);
#endif /* NO_PROTO */
/* should have same attributes */
    L__1 = dx2 == dx && dy2 == dy && arreq_(&c__100, &c__100, &c__1, &c__1, &
	    dx, &dy, colia, colia2);
    ifpf_(&L__1);
L350:
/*  If number of initialized entries >= implementation max then skip test 
*/
/*  of setting undefined entry - goto redefined_test. */
    if (nie >= mpai) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because all pattern table entries ar"
		"e initialized.", 74L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because all pattern table entries ar\
e initialized.", 74L);
#endif /* NO_PROTO */
	goto L400;
    }
/* Check that program allows enough room */
    if (nie >= 300) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because number of initialized entrie"
		"s exceed program limits.", 84L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because number of initialized entrie\
s exceed program limits.", 84L);
#endif /* NO_PROTO */
	goto L400;
    }
/* set values for attributes */
    isc = 4;
    isr = 5;
    dx2 = 2;
    dy2 = 2;
    colia2[403] = 33;
    colia2[404] = 53;
    colia2[503] = 32;
    colia2[504] = 48;
    nspar (&globnu_1.wkid, &lui, &c__100, &c__100, &isc, &isr, &dx2, &dy2, 
	    colia2);
    nqepai (&globnu_1.wkid, &c__0, &errind, &listot, &idum1);
    chkinq_("pqepai", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("1 3", "Defining an undefined entry should increment the number "
	    "of defined entries.", 3L, 75L);
#else /* NO_PROTO */
    setmsg_("1 3", "Defining an undefined entry should increment the number \
of defined entries.", 3L, 75L);
#endif /* NO_PROTO */
    L__1 = listot == cnde + 1;
    ifpf_(&L__1);
/* check that lui is now among defined entries */
#ifndef NO_PROTO
    setmsg_("1 3", "Undefined table entry should be reported as defined afte"
	    "r set.", 3L, 62L);
#else /* NO_PROTO */
    setmsg_("1 3", "Undefined table entry should be reported as defined afte\
r set.", 3L, 62L);
#endif /* NO_PROTO */
    i__1 = listot;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepai (&globnu_1.wkid, &listel, &errind, &idum1, &pai);
	chkinq_("pqepai", &errind, 6L);
	if (pai == lui) {
	    pass_();
	    goto L390;
	}
/* L380: */
    }
    fail_();
    goto L400;
L390:
    nqpar (&globnu_1.wkid, &lui, &c__0, &c__100, &c__100, &errind, &dx, &dy, 
	    colia);
    chkinq_("pqpar", &errind, 5L);
    setmsg_("2 5", "New values should be set for undefined table entry.", 3L, 
	    51L);
    L__1 = dx == dx2 && dy == dy2 && arreq_(&c__100, &c__100, &isc, &isr, &
	    dx2, &dy2, colia2, colia);
    ifpf_(&L__1);
/* *** *** *** *** ***    redefined entries   *** *** *** *** *** */
L400:
/* get current number defined entries */
    nqepai (&globnu_1.wkid, &c__0, &errind, &cnde, &idum1);
    chkinq_("pqepai", &errind, 6L);
/* let dpi = a defined pattern index from middle of list */
    i__1 = (cnde + 1) / 2;
    nqepai (&globnu_1.wkid, &i__1, &errind, &idum1, &dpi);
    chkinq_("pqepai", &errind, 6L);
/* set to first set of values */
    isc = 1;
    isr = 1;
    dx = 3;
    dy = 2;
    colia[0] = 8;
    colia[1] = 22;
    colia[2] = 36;
    colia[100] = 19;
    colia[101] = 53;
    colia[102] = 89;
    nspar (&globnu_1.wkid, &dpi, &c__100, &c__100, &isc, &isr, &dx, &dy, 
	    colia);
/* re-set to different values */
    dx2 = 2;
    dy2 = 2;
    colia2[0] = 3;
    colia2[1] = 19;
    colia2[100] = 9;
    colia2[101] = 47;
    nspar (&globnu_1.wkid, &dpi, &c__100, &c__100, &isc, &isr, &dx2, &dy2, 
	    colia2);
/* get list size - nnde = new number of defined entries */
    nqepai (&globnu_1.wkid, &c__0, &errind, &nnde, &idum1);
    chkinq_("pqepai", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("1 3", "Redefining a user-defined entry should not change number"
	    " of defined entries.", 3L, 76L);
#else /* NO_PROTO */
    setmsg_("1 3", "Redefining a user-defined entry should not change number\
 of defined entries.", 3L, 76L);
#endif /* NO_PROTO */
    L__1 = nnde == cnde;
    ifpf_(&L__1);
/* check that dpi is among defined entries */
#ifndef NO_PROTO
    setmsg_("1 3", "Redefined table entry should be reported as defined afte"
	    "r set.", 3L, 62L);
#else /* NO_PROTO */
    setmsg_("1 3", "Redefined table entry should be reported as defined afte\
r set.", 3L, 62L);
#endif /* NO_PROTO */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepai (&globnu_1.wkid, &listel, &errind, &idum1, &pai);
	chkinq_("pqepai", &errind, 6L);
	if (pai == dpi) {
	    pass_();
	    goto L430;
	}
/* L420: */
    }
    fail_();
    goto L499;
L430:
    nqpar (&globnu_1.wkid, &dpi, &c__0, &c__100, &c__100, &errind, &dx, &dy, 
	    colia);
    chkinq_("pqpar", &errind, 5L);
    setmsg_("2 5", "New values should be set for redefined table entry.", 3L, 
	    51L);
    L__1 = dx == dx2 && dy == dy2 && arreq_(&c__100, &c__100, &isc, &isr, &
	    dx2, &dy2, colia2, colia);
    ifpf_(&L__1);
L499:
/* *** *** *** *** ***  access all defined entries  *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("3 4", "<Inquire list of pattern indices> and <inquire pattern r"
	    "epresentation> should detect all defined entries.", 3L, 105L);
#else /* NO_PROTO */
    setmsg_("3 4", "<Inquire list of pattern indices> and <inquire pattern r\
epresentation> should detect all defined entries.", 3L, 105L);
#endif /* NO_PROTO */
/* get listel-th element of defined pattern indices */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepai (&globnu_1.wkid, &listel, &errind, &idum1, &pai);
	if (errind != 0) {
	    fail_();
	    goto L515;
	}
	nqpar (&globnu_1.wkid, &pai, &c__0, &c__100, &c__100, &errind, &dx, &
		dy, colia);
/* check errind for overflow */
	if (errind == 2001 || errind == 0) {
/* OK so far */
	} else {
	    fail_();
	    goto L515;
	}
/* L510: */
    }
    pass_();
L515:
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

