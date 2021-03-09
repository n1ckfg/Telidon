/* fort/04/02/02/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.02.02/06                        * */
/*  *    TEST TITLE : Marker type facilities                * */
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
    static integer mt[1024];
    static char msg[300];
    static integer rmt;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer mtid, namt;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqpmf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, integer *), nqwkc (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqpmf (), nqwkc ();
#endif /* NO_PROTO */
    static integer impmt;
    static logical stdmt[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr ();
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
    static integer specwt, thismt;
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


/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.02.02/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  namt = number of available marker types */
    nqpmf (&specwt, &c__1, &errind, &namt, &idum2, &idum3, &rdum1, &rdum2, &
	    rdum3, &idum1);
    chkinq_("pqpmf", &errind, 5L);
/* no inaccessible marker types found yet */
    errcod = FALSE_;
/* no standard marker types found yet */
    for (mtid = 1; mtid <= 5; ++mtid) {
	stdmt[mtid - 1] = FALSE_;
/* L100: */
    }
/* no implementation-dependent marker types found yet */
    impdep = FALSE_;
/* go through list of available marker types */
    i__1 = abs(namt);
    for (mtid = 1; mtid <= i__1; ++mtid) {
	nqpmf (&specwt, &mtid, &errind, &idum1, &thismt, &idum3, &rdum1, &
		rdum2, &rdum3, &idum2);
/*  keep track of non-zero error indicators */
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___17);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing marker-type list element #", 43L);

	    do_fio(&c__1, (char *)&mtid, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L200;
	}
	if (mtid <= 1024) {
	    mt[mtid - 1] = thismt;
	}
/*  keep track of marker types 1-5: */
	if (thismt >= 1 && thismt <= 5) {
	    stdmt[thismt - 1] = TRUE_;
	}
/*  keep track of implementation-dependent types (non-positives): */
	if (thismt < 1) {
	    impdep = TRUE_;
	}
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("29", "All entries within the reported size of the list of avail"
	    "able marker types should be accessible.", 2L, 96L);
#else /* NO_PROTO */
    setmsg_("29", "All entries within the reported size of the list of avail\
able marker types should be accessible.", 2L, 96L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("30", "The list of available marker types should contain 1 thru "
	    "5.", 2L, 59L);
#else /* NO_PROTO */
    setmsg_("30", "The list of available marker types should contain 1 thru \
5.", 2L, 59L);
#endif /* NO_PROTO */
    L__1 = stdmt[0] && stdmt[1] && stdmt[2] && stdmt[3] && stdmt[4];
    ifpf_(&L__1);
    if (namt > 0) {
/*  positive number of available marker types - includes imp-dep */
	if (impdep) {
/*  looks OK - do nothing */
	} else {
#ifndef NO_PROTO
	    setmsg_("31 34", "When system reports that no implementation-dep"
		    "endent marker types are available, none should be.", 5L, 
		    96L);
	    errctl_((logical*)&c__1);
#else /* NO_PROTO */
	    setmsg_("31 34", "When system reports that no implementation-dep\
endent marker types are available, none should be.", 5L, 96L);
	    errctl_(&c__1);
#endif /* NO_PROTO */
	    for (impmt = 0; impmt >= -3; --impmt) {
		nspmr (&globnu_1.wkid, &c__1, &impmt, &c_b25, &c__1);
		if (globnu_1.errsig != 105) {
		    fail_();
		    s_wsfi(&io___20);
		    do_fio(&c__1, "Implementation-dependent marker type #", 
			    38L);
		    do_fio(&c__1, (char *)&impmt, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
		    do_fio(&c__1, " not rejected by set polymarker represent"
			    "ation.", 47L);
#else /* NO_PROTO */
		    do_fio(&c__1, " not rejected by set polymarker represent\
ation.", 47L);
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
/*  non-positive number of available marker types - excludes imp-dep 
*/
#ifndef NO_PROTO
	setmsg_("32 34", "Negative number of available marker types should i"
		"ndicate that list contains no implementation-dependent marke"
		"r types.", 5L, 118L);
#else /* NO_PROTO */
	setmsg_("32 34", "Negative number of available marker types should i\
ndicate that list contains no implementation-dependent marker types.", 5L, 
		118L);
#endif /* NO_PROTO */
	L__1 = ! impdep;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    setmsg_("15 33", "All entries within the reported list of available mark"
	    "er types should be realizable and valid.", 5L, 94L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("15 33", "All entries within the reported list of available mark\
er types should be realizable and valid.", 5L, 94L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/* set all marker types */
/* Computing MIN */
    i__2 = 1024, i__3 = abs(namt);
    i__1 = min(i__2,i__3);
    for (mtid = 1; mtid <= i__1; ++mtid) {
	thismt = mt[mtid - 1];
	nspmr (&globnu_1.wkid, &c__3, &thismt, &c_b25, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Marker type #", 13L);
	    do_fio(&c__1, (char *)&thismt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalild.", 22L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L500;
	}
/*  inquire attributes as realized */
/*  rmt = realized marker type */
	nqpmr (&globnu_1.wkid, &c__3, &c__1, &errind, &rmt, &rdum1, &idum1);
	chkinq_("pqpmr", &errind, 5L);
	if (rmt != thismt) {
	    fail_();
	    s_wsfi(&io___23);
	    do_fio(&c__1, "Marker type set as #", 20L);
	    do_fio(&c__1, (char *)&thismt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as #", 18L);
	    do_fio(&c__1, (char *)&rmt, (ftnlen)sizeof(integer));
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

