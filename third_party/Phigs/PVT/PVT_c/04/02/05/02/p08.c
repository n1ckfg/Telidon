/* fort/04/02/05/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/08                        * */
/*  *    TEST TITLE : Interior style index: hatch           * */
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
    static integer hs[1024], isi;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer hsid, nahs;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     pass_(void), nqir (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqif (), pass_(), nqir ();
#endif /* NO_PROTO */
    static integer ints;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsir ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer imdhs;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static integer rstyi;
    static logical errcod, impdep;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, naints, thishs, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    errctl_(logical *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), errctl_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___21 = { 0, msg, 0, "(A, I5,A)", 300, 1 };
    static icilist io___22 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___23 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };


/* type of returned value */
/* interior style */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.02/08", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  naints = number of available interior styles */
/*  nahs   = number of available hatch styles */
    nqif (&specwt, &c__0, &c__0, &errind, &naints, &idum1, &nahs, &idum2, &
	    idum3);
    chkinq_("pqif", &errind, 4L);
/* loop thru list of interior styles to determine if hatch is supported */

    i__1 = naints;
    for (isi = 1; isi <= i__1; ++isi) {
	nqif (&specwt, &isi, &c__0, &errind, &idum1, &ints, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	if (ints == 3) {
	    goto L150;
	}
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("43", "If HATCH interior style is not available, <inquire interi"
	    "or facilities> should report 0 available hatch styles.", 2L, 111L)
	    ;
#else /* NO_PROTO */
    setmsg_("43", "If HATCH interior style is not available, <inquire interi\
or facilities> should report 0 available hatch styles.", 2L, 111L);
#endif /* NO_PROTO */
    L__1 = nahs == 0;
    ifpf_(&L__1);
    goto L666;
L150:
#ifndef NO_PROTO
    setmsg_("42", "The absolute value of the number of available hatch style"
	    "s should be greater than or equal to 3.", 2L, 96L);
#else /* NO_PROTO */
    setmsg_("42", "The absolute value of the number of available hatch style\
s should be greater than or equal to 3.", 2L, 96L);
#endif /* NO_PROTO */
    L__1 = abs(nahs) >= 3;
    ifpf_(&L__1);
/* no inaccessible hatch styles found yet */
    errcod = FALSE_;
/* no implementation-dependent hatch style found yet */
    impdep = FALSE_;
/* go through list of available hatch styles */
    i__1 = abs(nahs);
    for (hsid = 1; hsid <= i__1; ++hsid) {
	nqif (&specwt, &c__0, &hsid, &errind, &idum1, &idum2, &idum3, &thishs,
		 &idum4);
/*  keep track of non-zero error indicators */
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___17);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing hatch style list element #", 43L);

	    do_fio(&c__1, (char *)&hsid, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L200;
	}
	if (hsid <= 1024) {
	    hs[hsid - 1] = thishs;
	}
/*  keep track of implementation-dependent types (non-positives): */
	if (thishs < 1) {
	    impdep = TRUE_;
	}
L200:
	;
    }
#ifndef NO_PROTO
    setmsg_("44", "All entries within the reported size of the list of avail"
	    "able hatch styles should be accessible.", 2L, 96L);
#else /* NO_PROTO */
    setmsg_("44", "All entries within the reported size of the list of avail\
able hatch styles should be accessible.", 2L, 96L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
    if (nahs > 0) {
/*  positive number of available hatch styles - includes imp-dep */
	if (impdep) {
/*  looks OK - do nothing */
	} else {
#ifndef NO_PROTO
	    setmsg_("16 41 45 47", "When system reports that no implementati"
		    "on-dependent hatch styles are available, none should be.",
		     11L, 96L);
#else /* NO_PROTO */
	    setmsg_("16 41 45 47", "When system reports that no implementati\
on-dependent hatch styles are available, none should be.", 11L, 96L);
#endif /* NO_PROTO */
	    for (imdhs = 0; imdhs >= -3; --imdhs) {
		nsir (&globnu_1.wkid, &c__1, &c__3, &imdhs, &c__1);
		nqir (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, &rstyi, &
			idum2);
		chkinq_("pqir", &errind, 4L);
		if (rstyi == imdhs) {
		    fail_();
		    s_wsfi(&io___21);
		    do_fio(&c__1, "Implementation-dependent hatch index #", 
			    38L);
		    do_fio(&c__1, (char *)&imdhs, (ftnlen)sizeof(integer));
		    do_fio(&c__1, " in error, because realized as itself.", 
			    38L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    goto L350;
		}
/* L300: */
	    }
	    pass_();
L350:
	    ;
	}
    } else {
/*  non-positive number of available hatch styles - excludes imp-dep 
*/
#ifndef NO_PROTO
	setmsg_("46 47", "Negative number of available hatch styles should i"
		"ndicate that list contains no implementation-dependent hatch"
		" styles.", 5L, 118L);
#else /* NO_PROTO */
	setmsg_("46 47", "Negative number of available hatch styles should i\
ndicate that list contains no implementation-dependent hatch styles.", 5L, 
		118L);
#endif /* NO_PROTO */
	L__1 = ! impdep;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    setmsg_("16 40", "All entries within the list of available hatch styles "
	    "should be realizable.", 5L, 75L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("16 40", "All entries within the list of available hatch styles \
should be realizable.", 5L, 75L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/* set all hatch styles */
/* Computing MIN */
    i__2 = 1024, i__3 = abs(nahs);
    i__1 = min(i__2,i__3);
    for (hsid = 1; hsid <= i__1; ++hsid) {
	thishs = hs[hsid - 1];
	nsir (&globnu_1.wkid, &c__3, &c__3, &thishs, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___22);
	    do_fio(&c__1, "Hatch style #", 13L);
	    do_fio(&c__1, (char *)&thishs, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalild.", 22L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L500;
	}
/*  inquire attributes as realized */
/*  rstyi = realized hatch style */
	nqir (&globnu_1.wkid, &c__3, &c__1, &errind, &idum1, &rstyi, &idum2);
	chkinq_("pqir", &errind, 4L);
	if (rstyi != thishs) {
	    fail_();
	    s_wsfi(&io___23);
	    do_fio(&c__1, "Hatch style set as #", 20L);
	    do_fio(&c__1, (char *)&thishs, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as #", 18L);
	    do_fio(&c__1, (char *)&rstyi, (ftnlen)sizeof(integer));
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
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

