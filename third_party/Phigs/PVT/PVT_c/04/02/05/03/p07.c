/* fort/04/02/05/03/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b25 = 1.f;
#else /* NO_PROTO */
static real c_b25 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/07                        * */
/*  *    TEST TITLE : Edgetype facilities                   * */
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
    static integer et[1024];
    static char msg[300];
    static integer ret;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer etid, naet;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nqedr (integer *, integer *, integer *, integer *
	    , integer *, integer *, real *, integer *), inmsg_(char *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nqedr (), inmsg_();
#endif /* NO_PROTO */
    static integer impet;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedr ();
#endif /* NO_PROTO */
    static logical stdet;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static logical errcod, impdep;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_();
#endif /* NO_PROTO */
    static integer thiset;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___20 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___21 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___23 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };


/* off/on switch for edge flag and error handling mode */
/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.03/07", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  naet = number of available edgetypes */
    nqedf (&specwt, &c__0, &errind, &naet, &idum1, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
/* no inaccessible edgetypes found yet */
    errcod = FALSE_;
/* no standard edgetypes found yet */
    stdet = FALSE_;
/* no implementation-dependent edgetypes found yet */
    impdep = FALSE_;
/* go through list of available edgetypes */
    i__1 = abs(naet);
    for (etid = 1; etid <= i__1; ++etid) {
	nqedf (&specwt, &etid, &errind, &idum1, &thiset, &idum2, &rdum1, &
		rdum2, &rdum3, &idum3);
/*  keep track of non-zero error indicators */
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___17);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing edgetype-list element #", 40L);
	    do_fio(&c__1, (char *)&etid, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L200;
	}
	if (etid <= 1024) {
	    et[etid - 1] = thiset;
	}
/*  keep track of edgetype 1 */
	if (thiset == 1) {
	    stdet = TRUE_;
	}
/*  keep track of implementation-dependent types (non-positives): */
	if (thiset < 1) {
	    impdep = TRUE_;
	}
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("32", "All entries within the reported size of the list of avail"
	    "able edgetypes should be accessible.", 2L, 93L);
#else /* NO_PROTO */
    setmsg_("32", "All entries within the reported size of the list of avail\
able edgetypes should be accessible.", 2L, 93L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
    setmsg_("33", "The list of available edgetypes should contain edgetype 1."
	    , 2L, 58L);
    ifpf_(&stdet);
    if (naet > 0) {
/*  positive number of available edgetypes - includes imp-dep */
	if (impdep) {
/*  looks OK - do nothing */
	} else {
#ifndef NO_PROTO
	    setmsg_("34 37", "When system reports that no implementation-dep"
		    "endent edgetypes are available, none should be.", 5L, 93L)
		    ;
	    errctl_((logical*)&c__1);
#else /* NO_PROTO */
	    setmsg_("34 37", "When system reports that no implementation-dep\
endent edgetypes are available, none should be.", 5L, 93L);
	    errctl_(&c__1);
#endif /* NO_PROTO */
	    for (impet = 0; impet >= -3; --impet) {
		nsedr (&globnu_1.wkid, &c__1, &c__1, &impet, &c_b25, &c__1);
		if (globnu_1.errsig != 107) {
		    fail_();
		    s_wsfi(&io___20);
		    do_fio(&c__1, "Implementation-dependent edgetype #", 35L);

		    do_fio(&c__1, (char *)&impet, (ftnlen)sizeof(integer));
		    do_fio(&c__1, " not rejected by set edge representation.",
			     41L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    goto L350;
		}
/* L300: */
	    }
	    pass_();
L350:
#ifndef NO_PROTO
	    errctl_((logical*)&c__0);
#else /* NO_PROTO */
	    errctl_(&c__0);
#endif /* NO_PROTO */
	}
    } else {
/*  non-positive number of available edgetypes - excludes imp-dep */
#ifndef NO_PROTO
	setmsg_("35 37", "Negative number of available edgetypes should indi"
		"cate that list contains no implementation-dependent edgetype"
		"s.", 5L, 112L);
#else /* NO_PROTO */
	setmsg_("35 37", "Negative number of available edgetypes should indi\
cate that list contains no implementation-dependent edgetypes.", 5L, 112L);
#endif /* NO_PROTO */
	L__1 = ! impdep;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    setmsg_("15 36", "All entries within the reported list of available edge"
	    "types should be realizable and valid.", 5L, 91L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("15 36", "All entries within the reported list of available edge\
types should be realizable and valid.", 5L, 91L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/* set all edgetypes */
/* Computing MIN */
    i__2 = 1024, i__3 = abs(naet);
    i__1 = min(i__2,i__3);
    for (etid = 1; etid <= i__1; ++etid) {
	thiset = et[etid - 1];
	nsedr (&globnu_1.wkid, &c__3, &c__1, &thiset, &c_b25, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Edgetype #", 10L);
	    do_fio(&c__1, (char *)&thiset, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalid.", 21L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L500;
	}
/*  inquire attributes as realized */
/*  ret = realized edgetype */
	nqedr (&globnu_1.wkid, &c__3, &c__1, &errind, &idum1, &ret, &rdum1, &
		idum2);
	chkinq_("pqedr", &errind, 5L);
	if (ret != thiset) {
	    fail_();
	    s_wsfi(&io___23);
	    do_fio(&c__1, "Edgetype set as #", 17L);
	    do_fio(&c__1, (char *)&thiset, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as #", 18L);
	    do_fio(&c__1, (char *)&ret, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L500;
	}
/* L400: */
    }
    pass_();
L500:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

