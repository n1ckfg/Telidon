/* fort/04/03/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.03/03                           * */
/*  *    TEST TITLE : HLHSR facilities                      * */
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
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer hr;
    static char msg[300];
    static integer naid;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
    static logical defid;
    static integer namod;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nqhrm (integer *, 
	    integer *, integer *, integer *, integer *), nshrm (integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), nqhrm (), 
	    nshrm (), nopwk ();
#endif /* NO_PROTO */
    static logical defmod, errcod;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, thisid, thismd, reqmod, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqhrif (integer *, 
	    integer *, integer *, integer *, integer *), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqhrmf (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqhrif (), setmsg_(), nqhrmf ();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int errctl_(logical *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int errctl_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___12 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___16 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___17 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___20 = { 0, msg, 0, "(A,I5,A, I5,A)", 300, 1 };


/*  Declare program-specific variables */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.03.03/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* get this workstation type */
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire HLHSR facilities> to determine */
/*     naid  = number of available HLHSR identifiers */
    naid = -6;
    nqhrif (&specwt, &c__0, &errind, &naid, &idum3);
    chkinq_("pqhrif", &errind, 6L);
/* *** *** *** *** HLHSR identifier tests *** *** *** *** */
    errcod = FALSE_;
    defid = FALSE_;
    i__1 = naid;
    for (hr = 1; hr <= i__1; ++hr) {
	thisid = -6;
	nqhrif (&specwt, &hr, &errind, &idum1, &thisid);
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___12);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing HLHSR indentifier #", 36L);
	    do_fio(&c__1, (char *)&thisid, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L100;
	}
/* check for HLHSR identifier 0 */
	if (thisid == 0) {
	    defid = TRUE_;
	}
L100:
	;
    }
#ifndef NO_PROTO
    setmsg_("8", "All HLHSR identifiers in the list of available HLHSR ident"
	    "ifiers should be accessible.", 1L, 86L);
#else /* NO_PROTO */
    setmsg_("8", "All HLHSR identifiers in the list of available HLHSR ident\
ifiers should be accessible.", 1L, 86L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("9", "The reported number of HLHSR identifiers should be at leas"
	    "t 1.", 1L, 62L);
#else /* NO_PROTO */
    setmsg_("9", "The reported number of HLHSR identifiers should be at leas\
t 1.", 1L, 62L);
#endif /* NO_PROTO */
    L__1 = naid >= 1;
    ifpf_(&L__1);
    setmsg_("9", "The list of available HLHSR identifiers should contain 0.", 
	    1L, 57L);
    ifpf_(&defid);
/* ** *** *** *** HLHSR mode tests *** *** *** *** */
/*  <inquire HLHSR facilities> to determine */
/*     namod = number of available HLHSR modes */
    namod = -6;
    nqhrmf (&specwt, &c__0, &errind, &namod, &idum3);
    chkinq_("pqhrmf", &errind, 6L);
    errcod = FALSE_;
    defmod = FALSE_;
    i__1 = namod;
    for (hr = 1; hr <= i__1; ++hr) {
	thismd = -6;
	nqhrmf (&specwt, &hr, &errind, &idum3, &thismd);
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___16);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing HLHSR mode #", 29L);
	    do_fio(&c__1, (char *)&thismd, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L400;
	}
/* check for HLHSR mode 0 */
	if (thismd == 0) {
	    defmod = TRUE_;
	}
L400:
	;
    }
#ifndef NO_PROTO
    setmsg_("8", "All HLHSR modes in the list of available HLHSR modes shoul"
	    "d be accessible.", 1L, 74L);
#else /* NO_PROTO */
    setmsg_("8", "All HLHSR modes in the list of available HLHSR modes shoul\
d be accessible.", 1L, 74L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
    setmsg_("10", "The reported number of HLHSR modes should be at least 1.", 
	    2L, 56L);
    L__1 = namod >= 1;
    ifpf_(&L__1);
    setmsg_("10", "The list of available HLHSR modes should contain 0.", 2L, 
	    51L);
    ifpf_(&defmod);
#ifndef NO_PROTO
    setmsg_("11", "All modes within the reported list of available HLHSR mod"
	    "es should be valid.", 2L, 76L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("11", "All modes within the reported list of available HLHSR mod\
es should be valid.", 2L, 76L);
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = namod;
    for (hr = 1; hr <= i__1; ++hr) {
/* get each HLHSR mode and set it */
	thismd = -6;
	nqhrmf (&specwt, &hr, &errind, &idum3, &thismd);
	chkinq_("pqhrmf", &errind, 6L);
	nshrm (&globnu_1.wkid, &thismd);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___17);
	    do_fio(&c__1, "HLHSR mode ", 11L);
	    do_fio(&c__1, (char *)&thismd, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalid.", 21L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
/* <inquire HLHSR mode> to determine */
/*  reqmod = requested HLHSR mode */
	nqhrm (&globnu_1.wkid, &errind, &idum1, &idum2, &reqmod);
	chkinq_("pqhrm", &errind, 5L);
	if (reqmod != thismd) {
	    fail_();
	    s_wsfi(&io___20);
	    do_fio(&c__1, "HLHSR mode set as ", 18L);
	    do_fio(&c__1, (char *)&thismd, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but reported as ", 17L);
	    do_fio(&c__1, (char *)&reqmod, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
/* L500: */
    }
    pass_();
L666:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

