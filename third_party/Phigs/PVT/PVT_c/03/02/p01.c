/* fort/03/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 03.02/01                              * */
/*  *    TEST TITLE : Setting and inquiring conflict        * */
/*  *                 resolution flags                      * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void), 
	    endit_(void), nclph (void), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_(), endit_(), nclph (),
	     inmsg_();
#endif /* NO_PROTO */
    static integer arcriq, errind, recriq, arcrst;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer recrst;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcnrs (integer *, integer *, integer *), nscnrs (integer *, 
	    integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcnrs (), nscnrs (), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___7 = { 0, msg, 0, "(5(A,I4),A)", 300, 1 };


/* conflict resolution */
/*                maintain    abandon     update */
/*  Throughout, use variable names: */
/*  arcrst : archival conflict resolution flag, as set */
/*  recrst : retrieval conflict resolution flag, as set */
/*  arcriq : archival conflict resolution flag, as inquired */
/*  recriq : retrieval conflict resolution flag, as inquired */
    initgl_("03.02/01", 8L);
/*  <open phigs> */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 3", "Immediately after <open phigs>, the archival conflict re"
	    "solution flag should be reported as UPDATE and the retrieval con"
	    "flict resolution flag should be reported as ABANDON.", 3L, 172L);
#else /* NO_PROTO */
    setmsg_("1 3", "Immediately after <open phigs>, the archival conflict re\
solution flag should be reported as UPDATE and the retrieval conflict resolu\
tion flag should be reported as ABANDON.", 3L, 172L);
#endif /* NO_PROTO */
    nqcnrs (&errind, &arcriq, &recriq);
    L__1 = errind == 0 && arcriq == 2 && recriq == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 3", "It should be possible to set and inquire the conflict re"
	    "solution flags to all combinations of valid values: MAINTAIN, AB"
	    "ANDON, and UPDATE.", 3L, 138L);
#else /* NO_PROTO */
    setmsg_("2 3", "It should be possible to set and inquire the conflict re\
solution flags to all combinations of valid values: MAINTAIN, ABANDON, and U\
PDATE.", 3L, 138L);
#endif /* NO_PROTO */
    for (arcrst = 0; arcrst <= 2; ++arcrst) {
	for (recrst = 0; recrst <= 2; ++recrst) {
/*  <set conflict resolution> with arcrst, recrst */
	    nscnrs (&arcrst, &recrst);
/*  <inquire conflict resolution> */
	    nqcnrs (&errind, &arcriq, &recriq);
	    if (errind == 0 && arcriq == arcrst && recriq == recrst) {
/*           OK so far */
	    } else {
		s_wsfi(&io___7);
		do_fio(&c__1, "Set conflict flags as [", 23L);
		do_fio(&c__1, (char *)&arcrst, (ftnlen)sizeof(integer));
		do_fio(&c__1, ",", 1L);
		do_fio(&c__1, (char *)&recrst, (ftnlen)sizeof(integer));
		do_fio(&c__1, "], but reported as [", 20L);
		do_fio(&c__1, (char *)&arcriq, (ftnlen)sizeof(integer));
		do_fio(&c__1, ",", 1L);
		do_fio(&c__1, (char *)&recriq, (ftnlen)sizeof(integer));
		do_fio(&c__1, "], with error code = ", 21L);
		do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		fail_();
		goto L500;
	    }
/* L200: */
	}
/* L100: */
    }
    pass_();
/*  end_set_loop: */
L500:
/*  <set conflict resolution> with MAINTAIN, MAINTAIN */
    nscnrs (&c__0, &c__0);
/*  <close phigs> */
    nclph ();
/*  <open phigs> again */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 3", "Immediately after re-opening phigs, the archival conflic"
	    "t resolution flag should be reported as UPDATE and the retrieval"
	    " conflict resolution flag should be reported as ABANDON.", 3L, 
	    176L);
#else /* NO_PROTO */
    setmsg_("1 3", "Immediately after re-opening phigs, the archival conflic\
t resolution flag should be reported as UPDATE and the retrieval conflict re\
solution flag should be reported as ABANDON.", 3L, 176L);
#endif /* NO_PROTO */
    nqcnrs (&errind, &arcriq, &recriq);
    L__1 = errind == 0 && arcriq == 2 && recriq == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

