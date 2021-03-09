/* fort/05/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.03/02                              * */
/*  *    TEST TITLE : Setting and inquiring display         * */
/*  *                 priorities                            * */
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
    static real strpri[3] = { 0.f,.67f,1.f };
#else /* NO_PROTO */
    static real strpri[3] = { (float)0.,(float).67,(float)1. };
#endif /* NO_PROTO */

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
    static char msg[300];
    static real pri1, pri2;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), nqdp (integer *
	    , integer *, integer *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), nqdp (), pass_();
#endif /* NO_PROTO */
    static integer istr, repid;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_();
#endif /* NO_PROTO */
    static integer strid[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), npost (
	    integer *, integer *, real *), chkinq_(char *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk (), npost (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static real reppri;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt, ndpsup;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqpost (
	    integer *, integer *, integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqpost ();
#endif /* NO_PROTO */
    static integer numstr;

    /* Fortran I/O blocks */
    static icilist io___7 = { 0, msg, 0, "(A,I5)", 300, 1 };


/*  strpri = array of display priorities */
    initgl_("05.03/02", 8L);
/* open PHIGS & workstation */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  Use <inquire number of display priorities supported> to determine: */
/*     ndpsup = number of display priorities supported */
    nqdp (&specwt, &errind, &ndpsup);
    s_wsfi(&io___7);
#ifndef NO_PROTO
    do_fio(&c__1, "Reported number of display priorities for primary worksta"
	    "tion type = ", 69L);
#else /* NO_PROTO */
    do_fio(&c__1, "Reported number of display priorities for primary worksta\
tion type = ", 69L);
#endif /* NO_PROTO */
    do_fio(&c__1, (char *)&ndpsup, (ftnlen)sizeof(integer));
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("16 17", "<Inquire number of display priorities supported> shoul"
	    "d report the number of display priorities for any specific works"
	    "tation type as 0 or >= 2.", 5L, 143L);
#else /* NO_PROTO */
    setmsg_("16 17", "<Inquire number of display priorities supported> shoul\
d report the number of display priorities for any specific workstation type \
as 0 or >= 2.", 5L, 143L);
#endif /* NO_PROTO */
    if (errind == 0 && (ndpsup == 0 || ndpsup >= 2)) {
	pass_();
    } else {
	fail_();
	inmsg_("Skipping all further tests for display priority.", 48L);
	goto L600;
    }
/* post 3 structures */
    for (istr = 1; istr <= 3; ++istr) {
	strid[istr - 1] = istr + 100;
	npost (&globnu_1.wkid, &strid[istr - 1], &strpri[istr - 1]);
/* L100: */
    }
    if (ndpsup == 0) {
#ifndef NO_PROTO
	setmsg_("3 15 16 18", "A workstation with the number of display prio"
		"rities equal to 0 should report any valid display priority e"
		"xactly as it was set.", 10L, 126L);
#else /* NO_PROTO */
	setmsg_("3 15 16 18", "A workstation with the number of display prio\
rities equal to 0 should report any valid display priority exactly as it was\
 set.", 10L, 126L);
#endif /* NO_PROTO */
	nqpost (&globnu_1.wkid, &c__0, &errind, &numstr, &repid, &reppri);
	chkinq_("pqpost", &errind, 6L);
	if (numstr != 3) {
	    goto L160;
	}
	for (istr = 1; istr <= 3; ++istr) {
	    nqpost (&globnu_1.wkid, &istr, &errind, &numstr, &repid, &reppri);

	    chkinq_("pqpost", &errind, 6L);
	    if (repid < 101 || repid > 103) {
		goto L160;
	    }
	    if (reppri != strpri[repid - 101]) {
		goto L160;
	    }
/* prevent re-use of same priority */
#ifndef NO_PROTO
	    strpri[repid - 101] = -66.6f;
#else /* NO_PROTO */
	    strpri[repid - 101] = (float)-66.6;
#endif /* NO_PROTO */
/* L110: */
	}
	pass_();
	goto L600;
L160:
	fail_();
    } else {
#ifndef NO_PROTO
	setmsg_("3 15 16 19", "A workstation with the number of display prio"
		"rities equal to at least 2 should be able to distinguish the"
		" highest and lowest valid priority.", 10L, 140L);
	pri1 = 1e33f;
	pri2 = -1e33f;
#else /* NO_PROTO */
	setmsg_("3 15 16 19", "A workstation with the number of display prio\
rities equal to at least 2 should be able to distinguish the highest and low\
est valid priority.", 10L, 140L);
	pri1 = (float)1e33;
	pri2 = (float)-1e33;
#endif /* NO_PROTO */
	for (istr = 1; istr <= 3; ++istr) {
	    nqpost (&globnu_1.wkid, &istr, &errind, &numstr, &repid, &reppri);

	    chkinq_("pqpost", &errind, 6L);
	    if (repid == 101) {
		pri1 = reppri;
	    }
	    if (repid == 103) {
		pri2 = reppri;
	    }
/* L120: */
	}
	L__1 = pri1 < pri2;
	ifpf_(&L__1);
    }
/*  done: */
L600:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

