/* fort/04/03/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.01/01                           * */
/*  *    TEST TITLE : Set individual ASF element            * */
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
    /* Format strings */
#ifndef NO_PROTO
    static char fmt_100[] = "(\002Failure occurred with attribute-id = \002,"
	    "i3,\002, and asfval = \002,i3)";
#else /* NO_PROTO */
    static char fmt_100[] = "(\002Failure occurred with attribute-id = \002,\
i3,\002, and asfval = \002,i3)";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer rl;
    static char msg[80];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer atrid;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static char strar[1*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static logical badcon;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco ();
#endif /* NO_PROTO */
    static integer asfval, errind, intlen;
    static logical badtyp;
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nsiasf (integer *, 
	    integer *), nqcets (integer *, integer *, integer *, integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nsiasf (), nqcets (), setmsg_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___11 = { 0, msg, 0, fmt_100, 80, 1 };
    static icilist io___19 = { 0, msg, 0, fmt_100, 80, 1 };


/* aspect identifier */
/* aspect source */
/*                bundled     individual */
    initgl_("04.03.01/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* L100: */
/*  *** *** ***   Set individual ASF for each ASF value   *** *** *** */
    badtyp = FALSE_;
    badcon = FALSE_;
/* <set individual ASF> with atrid, asfval and */
/* <inquire current element type and size> */
    nopst (&c__1);
    for (atrid = 0; atrid <= 17; ++atrid) {
	for (asfval = 0; asfval <= 1; ++asfval) {
	    nsiasf (&atrid, &asfval);
	    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
	    if (errind == 0 && celtyp == 55 && intlen == 2 && rllen == 0 && 
		    strlen == 0) {
/* OK so far, do nothing */
	    } else {
		badtyp = TRUE_;
		goto L15;
	    }
/* L5: */
	}
/* L10: */
    }
L15:
#ifndef NO_PROTO
    setmsg_("1 2 4 5", "<Inquire current element type and size> should retur"
	    "n set individual ASF as the type of the created element and the "
	    "appropriate element size.", 7L, 141L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5", "<Inquire current element type and size> should retur\
n set individual ASF as the type of the created element and the appropriate \
element size.", 7L, 141L);
#endif /* NO_PROTO */
    if (badtyp) {
	fail_();
	s_wsfi(&io___11);
	do_fio(&c__1, (char *)&atrid, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&asfval, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 80L);
    } else {
	pass_();
    }
/* <set individual ASF> with atrid, asfval> */
/* <inquire current element content> */
    for (atrid = 0; atrid <= 17; ++atrid) {
	for (asfval = 0; asfval <= 1; ++asfval) {
	    nsiasf (&atrid, &asfval);
	    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, 
		    &str, strarl, strar, 1L);
	    if (errind == 0 && intg == 2 && intar[0] == atrid && intar[1] == 
		    asfval && rl == 0 && str == 0) {
/* OK so far, do nothing */
	    } else {
		badcon = TRUE_;
		goto L30;
	    }
/* L20: */
	}
/* L25: */
    }
L30:
#ifndef NO_PROTO
    setmsg_("1 3 4 5", "<Inquire current element content> should return the "
	    "standard representation for set individual ASF.", 7L, 99L);
#else /* NO_PROTO */
    setmsg_("1 3 4 5", "<Inquire current element content> should return the \
standard representation for set individual ASF.", 7L, 99L);
#endif /* NO_PROTO */
    if (badcon) {
	fail_();
	s_wsfi(&io___19);
	do_fio(&c__1, (char *)&atrid, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&asfval, (ftnlen)sizeof(integer));
	e_wsfi();
    } else {
	pass_();
    }
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

