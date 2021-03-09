/* fort/06/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b20 = 0.f;
#else /* NO_PROTO */
static real c_b20 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.03/04                              * */
/*  *    TEST TITLE : Update status of INPUT workstation    * */
/*  *                 transformation                        * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[300];
    static integer iwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_();
#endif /* NO_PROTO */
    static integer onwk, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
#endif /* NO_PROTO */
    static integer owkid;
    static char owcat[1];
    static real ocwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real cuwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
#endif /* NO_PROTO */
    static real ocvwp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsdus (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsdus ();
#endif /* NO_PROTO */
    static real rqwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer wtupd;
    static real nwwin[6], cuvwp[6], rqvwp[6], nwvwp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkt3 (integer *, integer *, integer *, real 
	    *, real *, real *, real *), nswkv3 (integer *, real *), nswkw3 (
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkt3 (), nswkv3 (), nswkw3 ();
#endif /* NO_PROTO */
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___20 = { 0, msg, 0, "(A,I5)", 300, 1 };


/* deferral mode */
/* modification mode */
/* update state */
    initgl_("06.03/04", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Get list of accessible workstations of category INPUT, */
/*  one element at a time.  ONWK is number of elements in */
/*  list. */
    multws_(&c__0, "i", &onwk, &owkid, &oconid, &owtype, owcat, 1L, 1L);
    if (onwk <= 0) {
	inmsg_("No INPUT workstations to be tested.", 35L);
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("15 20", "For all workstations of category INPUT, the workstatio"
	    "n transformation update state should always be NOTPENDING and re"
	    "ported as such.", 5L, 133L);
#else /* NO_PROTO */
    setmsg_("15 20", "For all workstations of category INPUT, the workstatio\
n transformation update state should always be NOTPENDING and reported as su\
ch.", 5L, 133L);
#endif /* NO_PROTO */
/*  for each iwk in list of INPUT workstations: */
    i__1 = onwk;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	multws_(&iwk, "i", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
	nopwk (&owkid, &oconid, &owtype);
/*  <Set display update state> to WAIT, NIVE to try to defer updates 
*/
	nsdus (&owkid, &c__4, &c__0);
/*     <inquire workstation representation 3> to determine original */

/*        current state: ocwin = 3D window */
/*                       ocvwp = 3D viewport */
	nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, ocwin, rqvwp, ocvwp);
	chkinq_("pqwkt3", &errind, 6L);
/*  alter workstation transformation: */
/*  <set workstation window 3>   = nwwin = ocwin / 2 */
/*  <set workstation viewport 3> = nwvwp = ocvwp / 2 */
	for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	    nwwin[ix - 1] = ocwin[ix - 1] / 2.f;
	    nwvwp[ix - 1] = ocvwp[ix - 1] / 2.f;
#else /* NO_PROTO */
	    nwwin[ix - 1] = ocwin[ix - 1] / (float)2.;
	    nwvwp[ix - 1] = ocvwp[ix - 1] / (float)2.;
#endif /* NO_PROTO */
/* L300: */
	}
/*  <set workstation window 3> */
	nswkw3 (&globnu_1.wkid, nwwin);
/*  <set workstation viewport 3> */
	nswkv3 (&globnu_1.wkid, nwvwp);
/*     <inquire workstation representation 3> to determine new */
/*        current state: wtupd = workstation transformation update sta
te */
/*                       cuwin = current 3D window */
/*                       cuvwp = current 3D viewport */
	nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
	chkinq_("pqwkt3", &errind, 6L);
	nclwk (&owkid);
	if (wtupd != 0) {
	    fail_();
	    s_wsfi(&io___20);
	    do_fio(&c__1, "Update state not= NOTPENDING:", 29L);
	    do_fio(&c__1, (char *)&wtupd, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
	if (rareq_(&c__6, cuwin, nwwin, &c_b20, &c_b20) && rareq_(&c__6, 
		cuvwp, nwvwp, &c_b20, &c_b20)) {
/*           OK so far */
	} else {
	    fail_();
	    inmsg_("Current values not those most recently set.", 43L);
	    goto L666;
	}
/*  next iwk */
/* L100: */
    }
    pass_();
/*  done: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

