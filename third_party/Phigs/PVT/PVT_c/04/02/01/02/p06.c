/* fort/04/02/01/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b25 = 1.f;
#else /* NO_PROTO */
static real c_b25 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.02/06                        * */
/*  *    TEST TITLE : Linetype facilities                   * */
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
    static integer lt[1024];
    static char msg[300];
    static integer rlt;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer ltid, nalt;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqplf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqplf ();
#endif /* NO_PROTO */
    static integer implt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static logical stdlt[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqplr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nsplr (integer *, integer *, integer *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplr (), nopwk (), nsplr ();
#endif /* NO_PROTO */
    static logical errcod, impdep;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, thislt;
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


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.01.02/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  nalt = number of available linetypes */
    nqplf (&specwt, &c__1, &errind, &nalt, &idum2, &idum3, &rdum1, &rdum2, &
	    rdum3, &idum1);
    chkinq_("pqplf", &errind, 5L);
/* no inaccessible linetypes found yet */
    errcod = FALSE_;
/* no standard linetypes found yet */
    for (ltid = 1; ltid <= 4; ++ltid) {
	stdlt[ltid - 1] = FALSE_;
/* L100: */
    }
/* no implementation-dependent linetypes found yet */
    impdep = FALSE_;
/* go through list of available linetypes */
    i__1 = abs(nalt);
    for (ltid = 1; ltid <= i__1; ++ltid) {
	nqplf (&specwt, &ltid, &errind, &idum1, &thislt, &idum3, &rdum1, &
		rdum2, &rdum3, &idum2);
/*  keep track of non-zero error indicators */
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___17);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing linetype-list element #", 40L);
	    do_fio(&c__1, (char *)&ltid, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L200;
	}
	if (ltid <= 1024) {
	    lt[ltid - 1] = thislt;
	}
/*  keep track of linetypes 1-4: */
	if (thislt >= 1 && thislt <= 4) {
	    stdlt[thislt - 1] = TRUE_;
	}
/*  keep track of implementation-dependent types (non-positives): */
	if (thislt < 1) {
	    impdep = TRUE_;
	}
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("29", "All entries within the reported size of the list of avail"
	    "able linetypes should be accessible.", 2L, 93L);
#else /* NO_PROTO */
    setmsg_("29", "All entries within the reported size of the list of avail\
able linetypes should be accessible.", 2L, 93L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
    setmsg_("30", "The list of available linetypes should contain 1 thru 4.", 
	    2L, 56L);
    L__1 = stdlt[0] && stdlt[1] && stdlt[2] && stdlt[3];
    ifpf_(&L__1);
    if (nalt > 0) {
/*  positive number of available linetypes - includes imp-dep */
	if (impdep) {
/*  looks OK - do nothing */
	} else {
#ifndef NO_PROTO
	    setmsg_("31 34", "When system reports that no implementation-dep"
		    "endent linetypes are available, none should be.", 5L, 93L)
		    ;
	    errctl_((logical*)&c__1);
#else /* NO_PROTO */
	    setmsg_("31 34", "When system reports that no implementation-dep\
endent linetypes are available, none should be.", 5L, 93L);
	    errctl_(&c__1);
#endif /* NO_PROTO */
	    for (implt = 0; implt >= -3; --implt) {
		nsplr (&globnu_1.wkid, &c__1, &implt, &c_b25, &c__1);
		if (globnu_1.errsig != 104) {
		    fail_();
		    s_wsfi(&io___20);
		    do_fio(&c__1, "Implementation-dependent linetype #", 35L);

		    do_fio(&c__1, (char *)&implt, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
		    do_fio(&c__1, " not rejected by set polyline representat"
			    "ion.", 45L);
#else /* NO_PROTO */
		    do_fio(&c__1, " not rejected by set polyline representat\
ion.", 45L);
#endif /* NO_PROTO */
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
/*  non-positive number of available linetypes - excludes imp-dep */
#ifndef NO_PROTO
	setmsg_("32 34", "Negative number of available linetypes should indi"
		"cate that list contains no implementation-dependent linetype"
		"s.", 5L, 112L);
#else /* NO_PROTO */
	setmsg_("32 34", "Negative number of available linetypes should indi\
cate that list contains no implementation-dependent linetypes.", 5L, 112L);
#endif /* NO_PROTO */
	L__1 = ! impdep;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    setmsg_("15 33", "All entries within the reported list of available line"
	    "types should be realizable and valid.", 5L, 91L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("15 33", "All entries within the reported list of available line\
types should be realizable and valid.", 5L, 91L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/* set all linetypes */
/* Computing MIN */
    i__2 = 1024, i__3 = abs(nalt);
    i__1 = min(i__2,i__3);
    for (ltid = 1; ltid <= i__1; ++ltid) {
	thislt = lt[ltid - 1];
	nsplr (&globnu_1.wkid, &c__3, &thislt, &c_b25, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Linetype #", 10L);
	    do_fio(&c__1, (char *)&thislt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalild.", 22L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L500;
	}
/*  inquire attributes as realized */
/*  rlt = realized linetype */
	nqplr (&globnu_1.wkid, &c__3, &c__1, &errind, &rlt, &rdum1, &idum1);
	chkinq_("pqplr", &errind, 5L);
	if (rlt != thislt) {
	    fail_();
	    s_wsfi(&io___23);
	    do_fio(&c__1, "Linetype set as #", 17L);
	    do_fio(&c__1, (char *)&thislt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as #", 18L);
	    do_fio(&c__1, (char *)&rlt, (ftnlen)sizeof(integer));
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

