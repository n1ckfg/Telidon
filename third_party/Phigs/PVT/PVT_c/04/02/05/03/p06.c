/* fort/04/02/05/03/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b9 = 1.f;
#else /* NO_PROTO */
static real c_b9 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/06                        * */
/*  *    TEST TITLE : Edge flag facilities                  * */
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
    static integer efi, ref;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqedr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nsedr (integer *, integer *, integer *, integer *, real *, 
	    integer *), inmsg_(char *, ftnlen), nqwkc (integer *, integer *, 
	    integer *, integer *), nopwk (integer *, integer *, integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqedr (), nsedr (), inmsg_(), 
	    nqwkc (), nopwk (), chkinq_();
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
    static icilist io___6 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___11 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };


/*    Declare program-specific variables */
/* off/on switch for edge flag and error handling mode */
/* type of returned value */
/*   parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.03/06", 14L);
/*  open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*   open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    setmsg_("15 29", "A valid edge flag should be realized as itself.", 5L, 
	    47L);
    for (efi = 0; efi <= 1; ++efi) {
/* <set edge representation> index #1, edge flag = efi */
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
	nsedr (&globnu_1.wkid, &c__1, &efi, &c__1, &c_b9, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___6);
	    do_fio(&c__1, "Edge flag", 9L);
	    do_fio(&c__1, (char *)&efi, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalid.", 21L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
/* <inquire edge representation> index #1 to determine */
/* ref = realized edge flag */
	nqedr (&globnu_1.wkid, &c__1, &c__1, &errind, &ref, &idum1, &rdum1, &
		idum2);
	chkinq_("pqedr", &errind, 5L);
	if (ref != efi) {
	    fail_();
	    s_wsfi(&io___11);
	    do_fio(&c__1, "Edge flag set as ", 17L);
	    do_fio(&c__1, (char *)&efi, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as ", 17L);
	    do_fio(&c__1, (char *)&ref, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
/* L100: */
    }
    pass_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

