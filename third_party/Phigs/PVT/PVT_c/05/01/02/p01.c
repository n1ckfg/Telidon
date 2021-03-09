/* fort/05/01/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 05.01.02/01                           * */
/*  *    TEST TITLE : Characteristics of workstations       * */
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
    integer i__1, i__2;

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
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_();
#endif /* NO_PROTO */
    static integer laty[200];
    static char cdum1[1];
    static integer idum1, idum2, idum3;
    static logical catok;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer wkcat;
    static logical conok;
    static integer owkid;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static logical inqok;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nqewk (integer *, integer *, integer *, integer *), 
	    nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nqewk (), nopwk ();
#endif /* NO_PROTO */
    static integer numacc, oconid;
    static logical clasok;
    static integer specat, errind, specon, wclass;
    static logical gotone;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqwkca (integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqwkcl (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqwkca (), setmsg_(), nqwkcl ();
#endif /* NO_PROTO */
    static integer specwt;
    static logical gnonly, typeok;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer owtype, numtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___8 = { 0, msg, 0, "(3(A,I6))", 300, 1 };


/* workstation category */
/* vector/raster/other type */
    initgl_("05.01.02/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("5 7", "The number of available workstation types should be repo"
	    "rted as at least 1.", 3L, 75L);
#else /* NO_PROTO */
    setmsg_("5 7", "The number of available workstation types should be repo\
rted as at least 1.", 3L, 75L);
#endif /* NO_PROTO */
/*  <inquire list of available workstation types> to determine */
/*     laty   = list of available types */
    numtyp = -6;
    nqewk (&c__0, &errind, &numtyp, &idum1);
    if (errind != 0 || numtyp <= 0) {
	fail_();
	goto L50;
    }
    i__1 = numtyp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqewk (&ix, &errind, &idum1, &laty[ix - 1]);
	if (errind != 0) {
	    fail_();
	    goto L50;
	}
/* L20: */
    }
    pass_();
#ifndef NO_PROTO
    setmsg_("1 2 3 5", "The result of <inquire workstation category> using a"
	    " generic workstation type should be either a valid category or e"
	    "rror 51.", 7L, 124L);
#else /* NO_PROTO */
    setmsg_("1 2 3 5", "The result of <inquire workstation category> using a\
 generic workstation type should be either a valid category or error 51.", 7L,
	     124L);
#endif /* NO_PROTO */
/*  for each gtype = generic type in laty */
    i__1 = numtyp;
    for (ix = 1; ix <= i__1; ++ix) {
/*        <inquire workstation category> using gtype to determine */
/*           wkcat = workstation category */
	wkcat = -6;
	nqwkca (&laty[ix - 1], &errind, &wkcat);
	if (errind == 51 || errind == 0 && wkcat >= 0 && wkcat <= 4) {
/*           OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___8);
	    do_fio(&c__1, "<Inquire workstation category> for type = ", 42L);
	    do_fio(&c__1, (char *)&laty[ix - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, " returned error = ", 18L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " and category = ", 16L);
	    do_fio(&c__1, (char *)&wkcat, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L50;
	}
/* L40: */
    }
    pass_();
/*  end_gtype: */
L50:
/*  laccwk = list of accessible workstations */
/*     owkid  = workstation identifier for iwk'th workstation in laccwk */

/*     oconid = connection identifier for iwk'th workstation in laccwk */
/*     owtype = workstation type for iwk'th workstation in laccwk */

/*  typeok = true  = list of available workstation types */
/*                   contains all generic types */
/*  gnonly = true  = list of available workstation types */
/*                   contains only generic types */
/*  conok  = true  = connection identifiers ok */
/*  catok  = true  = <inquire workstation category> returns a */
/*                   valid category */
/*  inqok  = true  = <inquire workstation connection and type> */
/*                   works */
/*  clasok = true  = workstation classifications ok */
/*  gotone = false = got one OUTIN workstation */
    typeok = TRUE_;
    gnonly = TRUE_;
    conok = TRUE_;
    catok = TRUE_;
    inqok = TRUE_;
    clasok = TRUE_;
    gotone = FALSE_;
    multws_(&c__0, "a", &numacc, &idum1, &idum2, &idum3, cdum1, 1L, 1L);
/*  for each iwk in laccwk */
    i__1 = numacc;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	multws_(&iwk, "a", &idum1, &owkid, &oconid, &owtype, cdum1, 1L, 1L);
	i__2 = numtyp;
	for (ix = 1; ix <= i__2; ++ix) {
	    if (owtype == laty[ix - 1]) {
		goto L120;
	    }
/* L110: */
	}
	typeok = FALSE_;
L120:
/*     <open workstation> owkid(iwk) */
	nopwk (&owkid, &oconid, &owtype);
/*     <inquire workstation connection and type> to determine */
/*        specon = connection identifier */
/*        specwt = specific workstation type */
	nqwkc (&owkid, &errind, &specon, &specwt);
	if (errind == 0) {
	    if (specon != oconid) {
		conok = FALSE_;
	    }
	    i__2 = numtyp;
	    for (ix = 1; ix <= i__2; ++ix) {
		if (specwt == laty[ix - 1]) {
		    gnonly = FALSE_;
		    goto L140;
		}
/* L130: */
	    }
L140:
	    ;
	} else {
	    inqok = FALSE_;
	}
/*     <inquire workstation category> using specwt to determine */
/*        specat = workstation category */
	specat = -6;
	nqwkca (&specwt, &errind, &specat);
	if (errind != 0 || specat < 0 || specat > 4) {
	    catok = FALSE_;
	}
	if (specat == 0 || specat == 2) {
	    wclass = -6;
	    nqwkcl (&specwt, &errind, &wclass);
	    if (errind != 0 || wclass < 0 || wclass > 2) {
		clasok = FALSE_;
	    }
	}
	if (specat == 2) {
	    gotone = TRUE_;
	}
	nclwk (&owkid);
/*  next iwk */
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("5 6", "The generic workstation type of each accessible workstat"
	    "ion should be in the list of available workstation types.", 3L, 
	    113L);
#else /* NO_PROTO */
    setmsg_("5 6", "The generic workstation type of each accessible workstat\
ion should be in the list of available workstation types.", 3L, 113L);
#endif /* NO_PROTO */
    ifpf_(&typeok);
#ifndef NO_PROTO
    setmsg_("5 6 8", "The list of available workstation types should contain"
	    " only generic types.", 5L, 74L);
#else /* NO_PROTO */
    setmsg_("5 6 8", "The list of available workstation types should contain\
 only generic types.", 5L, 74L);
#endif /* NO_PROTO */
    ifpf_(&gnonly);
#ifndef NO_PROTO
    setmsg_("8", "<Inquire workstation connection and type> should report th"
	    "e same connection identifier as used in <open workstation>.", 1L, 
	    117L);
#else /* NO_PROTO */
    setmsg_("8", "<Inquire workstation connection and type> should report th\
e same connection identifier as used in <open workstation>.", 1L, 117L);
#endif /* NO_PROTO */
    ifpf_(&conok);
#ifndef NO_PROTO
    setmsg_("8", "<Inquire workstation connection and type> should report a "
	    "connection identifier and specific type for any open workstation."
	    , 1L, 123L);
#else /* NO_PROTO */
    setmsg_("8", "<Inquire workstation connection and type> should report a \
connection identifier and specific type for any open workstation.", 1L, 123L);

#endif /* NO_PROTO */
    ifpf_(&inqok);
#ifndef NO_PROTO
    setmsg_("2 3", "The reported category for any workstation type should be"
	    " either OUTPUT, INPUT, OUTIN, MO, or MI.", 3L, 96L);
#else /* NO_PROTO */
    setmsg_("2 3", "The reported category for any workstation type should be\
 either OUTPUT, INPUT, OUTIN, MO, or MI.", 3L, 96L);
#endif /* NO_PROTO */
    ifpf_(&catok);
#ifndef NO_PROTO
    setmsg_("9 10", "The reported workstation classification for workstation"
	    "s of category OUTPUT or OUTIN should be either VECTOR, RASTER, o"
	    "r OTHER.", 4L, 127L);
#else /* NO_PROTO */
    setmsg_("9 10", "The reported workstation classification for workstation\
s of category OUTPUT or OUTIN should be either VECTOR, RASTER, or OTHER.", 4L,
	     127L);
#endif /* NO_PROTO */
    ifpf_(&clasok);
#ifndef NO_PROTO
    setmsg_("2 3 4", "There should be at least one workstation of category O"
	    "UTIN.", 5L, 59L);
#else /* NO_PROTO */
    setmsg_("2 3 4", "There should be at least one workstation of category O\
UTIN.", 5L, 59L);
#endif /* NO_PROTO */
    ifpf_(&gotone);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

