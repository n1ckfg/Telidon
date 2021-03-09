/* fort/04/02/03/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b9 = 1.f;
#else /* NO_PROTO */
static real c_b9 = (float)1.;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/08                        * */
/*  *    TEST TITLE : Character spacing support             * */
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
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
    static real spi, rsp, rsp2;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static real chsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nopwk (integer *, 
	    integer *, integer *), nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), nopwk (), 
	    nqtxr (), nstxr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___6 = { 0, msg, 0, "(A,F11.2,A,I6,A)", 300, 1 };


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.03.02/08", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    setmsg_("60", "All character spacing values should be accepted as valid.",
	     2L, 57L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
    chsp = -3.032f;
#else /* NO_PROTO */
    errctl_(&c__1);
    chsp = (float)-3.032;
#endif /* NO_PROTO */
    nstxr (&globnu_1.wkid, &c__3, &c__1, &c__0, &c_b9, &chsp, &c__1);
    if (globnu_1.errsig != 0) {
	goto L100;
    }
#ifndef NO_PROTO
    chsp = .35f;
#else /* NO_PROTO */
    chsp = (float).35;
#endif /* NO_PROTO */
    nstxr (&globnu_1.wkid, &c__4, &c__1, &c__0, &c_b9, &chsp, &c__1);
    if (globnu_1.errsig != 0) {
	goto L100;
    }
#ifndef NO_PROTO
    chsp = 11.121f;
#else /* NO_PROTO */
    chsp = (float)11.121;
#endif /* NO_PROTO */
    nstxr (&globnu_1.wkid, &c__5, &c__1, &c__0, &c_b9, &chsp, &c__1);
    if (globnu_1.errsig != 0) {
	goto L100;
    }
    pass_();
    goto L150;
/*  fail and informational message about character spacing */
L100:
    fail_();
    s_wsfi(&io___6);
    do_fio(&c__1, "Character spacing of ", 21L);
    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
    do_fio(&c__1, " rejected with error code = ", 28L);
    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
L150:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("15 49 50 60", "For CHAR and STROKE precisions, a character spac"
	    "ing value should be realized as itself.", 11L, 87L);
    for (spi = -1.f; spi <= 2.0001f; spi += .25f) {
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("15 49 50 60", "For CHAR and STROKE precisions, a character spac\
ing value should be realized as itself.", 11L, 87L);
    for (spi = (float)-1.; spi <= (float)2.0001; spi += (float).25) {
#endif /* NO_PROTO */
	nstxr (&globnu_1.wkid, &c__3, &c__1, &c__1, &c_b9, &spi, &c__1);
	nqtxr (&globnu_1.wkid, &c__3, &c__1, &errind, &idum1, &idum2, &rdum1, 
		&rsp, &idum3);
	chkinq_("pqtxr", &errind, 5L);
/*  rsp = realized character spacing */
	if (rsp != spi) {
	    fail_();
	    goto L666;
	}
	nstxr (&globnu_1.wkid, &c__6, &c__1, &c__2, &c_b9, &spi, &c__1);
	nqtxr (&globnu_1.wkid, &c__6, &c__1, &errind, &idum1, &idum2, &rdum1, 
		&rsp2, &idum3);
	chkinq_("pqtxr", &errind, 5L);
	if (rsp2 != spi) {
	    fail_();
	    goto L666;
	}
/* L200: */
    }
    pass_();
L666:
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

