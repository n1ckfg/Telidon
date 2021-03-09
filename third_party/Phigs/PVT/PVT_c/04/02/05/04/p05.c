/* fort/04/02/05/04/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__100 = 100;
static integer c__5 = 5;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.04/05                        * */
/*  *    TEST TITLE : WSL pattern table initialized         * */
/*  *                 properly                              * */
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
    address a__1[2];
    integer i__1[2], i__2;
    char ch__1[114], ch__2[149];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ii, ddx, ddy, npe;
    static char msg[300];
    static integer spt, dcia[10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer mpai, pddx, pddy;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, pdcia[
	    10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqpaf (integer *, integer *, 
	    integer *);
    extern logical arreq_(integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqpar (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqwkc (integer *, 
	    integer *, integer *, integer *), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), chkinq_(char 
	    *, integer *, ftnlen), nqepai (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqpaf ();
    extern logical arreq_();
    extern /* Subroutine */ int inmsg_(), nclwk (), nqpar (), nqwkc (), 
	    nspar (), nopwk (), chkinq_(), nqepai ();
#endif /* NO_PROTO */
    static integer errind, specon, newent;
    static logical patmat;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
#else /* NO_PROTO */
    extern logical patavl_();
#endif /* NO_PROTO */
    static char msgsuf[30];
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqppar (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), xpopph_(
	    integer *, integer *), nqwksl (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), nqppar (), xpopph_(), 
	    nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___9 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___15 = { 0, msg, 0, "(A,A,2I5,A)", 300, 1 };
    static icilist io___19 = { 0, msg, 0, "(A,A,2I5,A)", 300, 1 };
    static icilist io___20 = { 0, msg, 0, "(A,I5,A,A)", 300, 1 };


/* set up pattern color array index values */
/* type of returned value */
/* interior style */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.04/05", 14L);
    s_copy(msgsuf, "opening workstation.", 30L, 20L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  perform loop twice - once for open, once for re-open */
L50:
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (! patavl_(&specwt)) {
#ifndef NO_PROTO
	inmsg_("Skipping all tests because pattern interior style is not sup"
		"ported on this workstation.", 87L);
#else /* NO_PROTO */
	inmsg_("Skipping all tests because pattern interior style is not sup\
ported on this workstation.", 87L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  npe = number of predefined entries in WDT */
    nqpaf (&specwt, &errind, &npe);
    chkinq_("pqpaf", &errind, 5L);
/*   spt = size of WSL interior bundle table */
    nqepai (&globnu_1.wkid, &c__0, &errind, &spt, &idum1);
    chkinq_("pqepai", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 84, a__1[0] = "WSL pattern table should be the same size as th"
	    "e WDT predefined pattern table after ";
#else /* NO_PROTO */
    i__1[0] = 84, a__1[0] = "WSL pattern table should be the same size as th\
e WDT predefined pattern table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 114L);
    setmsg_("16 17", ch__1, 5L, 114L);
    if (spt == npe) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___9);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined pattern indices, but ", 37L);
	do_fio(&c__1, (char *)&spt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL pattern indices.", 21L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
/* patterns match so far */
    patmat = TRUE_;
    i__2 = min(npe,spt);
    for (ii = 1; ii <= i__2; ++ii) {
/*  pdcia = predefined pattern color index array */
/*  pddx  = predefined dx -pattern array dimension */
/*  pddy  = predefined dy -pattern array dimension */
	nqppar (&specwt, &ii, &c__100, &c__100, &errind, &pddx, &pddy, pdcia);

	if (errind == 2001) {
	    s_wsfi(&io___15);
	    do_fio(&c__1, "PQPPAR returned Fortran error ", 30L);
	    do_fio(&c__1, "2001: declared array size of (", 30L);
	    do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ") insufficient.", 15L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
	chkinq_("pqppar", &errind, 6L);
/*  inquire defined attributes, as set */
/*  dcia = defined pattern color index array */
/*  ddx  = defined dx -pattern array dimension */
/*  ddy  = defined dy -pattern array dimension */
/*    inquire as SET */
	nqpar (&globnu_1.wkid, &ii, &c__0, &c__100, &c__100, &errind, &ddx, &
		ddy, dcia);
	if (errind == 2001) {
	    s_wsfi(&io___19);
	    do_fio(&c__1, "PQPAR returned Fortran error ", 29L);
	    do_fio(&c__1, "2001: declared array size of (", 30L);
	    do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ") insufficient.", 15L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
	chkinq_("pqpar", &errind, 5L);
	if (ddx == pddx && ddy == pddy && arreq_(&c__100, &c__100, &c__1, &
		c__1, &ddx, &ddy, dcia, pdcia)) {
/*  OK so far - do nothing */
	} else {
	    s_wsfi(&io___20);
	    do_fio(&c__1, "WSL pattern index #", 19L);
	    do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " is not initialized from corresponding WDT ", 43L);

	    do_fio(&c__1, "predefined index.", 17L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    patmat = FALSE_;
	    goto L110;
	}
/* L100: */
    }
L110:
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 119, a__1[0] = "Each WSL pattern table entry should have the s"
	    "ame attributes as the corresponding predefined pattern table ent"
	    "ry after ";
#else /* NO_PROTO */
    i__1[0] = 119, a__1[0] = "Each WSL pattern table entry should have the s\
ame attributes as the corresponding predefined pattern table entry after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 149L);
    setmsg_("11 15 16", ch__2, 8L, 149L);
    ifpf_(&patmat);
/* now alter table - either add entry or change it */
/* maximum number of pattern table entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &mpai, &
	    idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (mpai > spt) {
/* room for additional entries */
	newent = spt + 1;
    } else {
	newent = spt;
    }
/* set up new pattern */
    dcia[404] = 11;
    dcia[405] = 21;
    dcia[406] = 31;
    dcia[504] = 41;
    dcia[505] = 41;
    dcia[506] = 51;
    nspar (&globnu_1.wkid, &newent, &c__100, &c__100, &c__5, &c__5, &c__3, &
	    c__2, dcia);
/* check if this is 2nd time thru */
    if (s_cmp(msgsuf, "opening workstation.", 30L, 20L) == 0) {
/* this is first time thru */
/* close workstation and change msg */
	nclwk (&globnu_1.wkid);
	s_copy(msgsuf, "re-opening workstation.", 30L, 23L);
	goto L50;
    }
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

