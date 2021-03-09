/* fort/04/02/05/04/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.04/04                        * */
/*  *    TEST TITLE : Validity of predefined pattern        * */
/*  *                 table                                 * */
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
    integer i__1, i__2, i__3;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, j, ii, dx, dy, npe;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer mpci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf (), pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2;
    static real rdum1[9];
    static integer colia[10000]	/* was [100][100] */, erpci;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqpaf (integer *, integer *, 
	    integer *), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqpaf (), inmsg_();
#endif /* NO_PROTO */
    static logical nopat, noerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), chkinq_(char 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
    static logical colerr;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern logical patavl_();
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqppar (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqppar (), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, msg, 0, "(A,A,2I5,A)", 300, 1 };
    static icilist io___21 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___22 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/* set up pattern color index array */
/* type of returned value */
/* interior style */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.04/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* nopat = no pattern interior style */
    nopat = ! patavl_(&specwt);
    if (nopat) {
	inmsg_("Pattern interior style is not supported on this workstation.",
		 60L);
    }
/* L25: */
/* get maximum predefined color index and */
/* adjust for color index starting at 0 (not 1) */
    nqcf (&specwt, &errind, &idum1, &idum2, &mpci, rdum1);
    chkinq_("pqcf", &errind, 4L);
    --mpci;
/* npe     = number of predefined entries */
    nqpaf (&specwt, &errind, &npe);
    chkinq_("pqpaf", &errind, 5L);
    if (nopat) {
#ifndef NO_PROTO
	setmsg_("11 14", "If PATTERN interior style is not supported, <inqui"
		"re pattern facilities> should report 0 predefined indices.", 
		5L, 108L);
#else /* NO_PROTO */
	setmsg_("11 14", "If PATTERN interior style is not supported, <inqui\
re pattern facilities> should report 0 predefined indices.", 5L, 108L);
#endif /* NO_PROTO */
	L__1 = npe == 0;
	ifpf_(&L__1);
	goto L666;
    }
/*  color error found yet */
    colerr = FALSE_;
/*  no access error found yet */
    noerr = TRUE_;
/* should be able to access as many predefined pattern entries as */
/*    reported by pattern facilities */
    i__1 = npe;
    for (ii = 1; ii <= i__1; ++ii) {
	nqppar (&specwt, &ii, &c__100, &c__100, &errind, &dx, &dy, colia);
/* check errind for overflow */
	if (errind == 2001) {
	    s_wsfi(&io___17);
	    do_fio(&c__1, "PQPPAR returned Fortran error ", 30L);
	    do_fio(&c__1, "2001: declared array size of (", 30L);
	    do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ") insufficient.", 15L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L400;
	} else if (errind != 0) {
	    noerr = FALSE_;
	    goto L300;
	}
/* check color index as specified in pattern color index array */
/* loop thru each element of pattern color index array */
	i__2 = dx;
	for (i = 1; i <= i__2; ++i) {
	    i__3 = dy;
	    for (j = 1; j <= i__3; ++j) {
		if (colia[i + j * 100 - 101] < 0 || colia[i + j * 100 - 101] 
			> mpci) {
		    colerr = TRUE_;
		    erpci = colia[i + j * 100 - 101];
		}
/* L50: */
	    }
	}
L300:
	;
    }
#ifndef NO_PROTO
    setmsg_("11 12 15", "<Inquire predefined pattern representation> should "
	    "be able to access as many entries as reported by <inquire patter"
	    "n facilities>.", 8L, 129L);
#else /* NO_PROTO */
    setmsg_("11 12 15", "<Inquire predefined pattern representation> should \
be able to access as many entries as reported by <inquire pattern facilities\
>.", 8L, 129L);
#endif /* NO_PROTO */
    ifpf_(&noerr);
#ifndef NO_PROTO
    setmsg_("12 18", "All color indices in predefined pattern color index ar"
	    "ray should themselves be in the predefined color table.", 5L, 
	    109L);
#else /* NO_PROTO */
    setmsg_("12 18", "All color indices in predefined pattern color index ar\
ray should themselves be in the predefined color table.", 5L, 109L);
#endif /* NO_PROTO */
    if (colerr) {
	fail_();
	s_wsfi(&io___21);
	do_fio(&c__1, "Undefined color #", 17L);
	do_fio(&c__1, (char *)&erpci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " found in predefined color index array.", 39L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
L400:
    s_wsfi(&io___22);
    do_fio(&c__1, "PHIGS reported ", 15L);
    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
    do_fio(&c__1, " predefined pattern indices.", 28L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("11 13", "If PATTERN interior style is supported, <inquire patte"
	    "rn facilities> should report at least 1 predefined entry.", 5L, 
	    111L);
#else /* NO_PROTO */
    setmsg_("11 13", "If PATTERN interior style is supported, <inquire patte\
rn facilities> should report at least 1 predefined entry.", 5L, 111L);
#endif /* NO_PROTO */
    L__1 = npe >= 1;
    ifpf_(&L__1);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

