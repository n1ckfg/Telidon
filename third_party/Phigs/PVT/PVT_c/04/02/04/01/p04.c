/* fort/04/02/04/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__101 = 101;
static integer c__801 = 801;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__102 = 102;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.01/04                        * */
/*  *    TEST TITLE : Character height and expansion factor * */
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
    static char msg[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer naht;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqanf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *), 
	    inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqanf (), inmsg_();
#endif /* NO_PROTO */
    static real minht, maxht;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *), nsvwi (integer *), chkinq_(char *, integer *, ftnlen),
	     setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), nopst (), nsvwi (), 
	    chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), setasf_(integer *), ngtxat_(char *, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), setasf_(), ngtxat_(), 
	    xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___8 = { 0, msg, 0, "(A,I5,A, 2(E13.4,A))", 200, 1 };


/* aspect source */
/*                bundled     individual */
    initgl_("04.02.04.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area - initialize SPECWT */
    setdlg_(&c__101, &c__801, &c__1);
/*  <inquire annotation facilities> to determine */
/*  naht = # available character heights */
/*  minht = minimum character height */
/*  maxht = maximum character height */
    nqanf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &naht, &minht, &
	    maxht);
    chkinq_("pqanf", &errind, 5L);
    s_wsfi(&io___8);
    do_fio(&c__1, "Number of reported character heights = ", 39L);
    do_fio(&c__1, (char *)&naht, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".  Minimum,maximum reported character heights = ", 48L);
    do_fio(&c__1, (char *)&minht, (ftnlen)sizeof(real));
    do_fio(&c__1, ", ", 2L);
    do_fio(&c__1, (char *)&maxht, (ftnlen)sizeof(real));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 200L);
#ifndef NO_PROTO
    setmsg_("43", "Maximum character height should not be less than the mini"
	    "mum character height.", 2L, 78L);
#else /* NO_PROTO */
    setmsg_("43", "Maximum character height should not be less than the mini\
mum character height.", 2L, 78L);
#endif /* NO_PROTO */
    L__1 = maxht >= minht;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("43 44", "The minimum and maximum character heights should be po"
	    "sitive.", 5L, 61L);
    L__1 = minht > 0.f && maxht > 0.f;
#else /* NO_PROTO */
    setmsg_("43 44", "The minimum and maximum character heights should be po\
sitive.", 5L, 61L);
    L__1 = minht > (float)0. && maxht > (float)0.;
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("43 45 47", "The reported number of available character heights "
	    "should be at least 0.", 8L, 72L);
#else /* NO_PROTO */
    setmsg_("43 45 47", "The reported number of available character heights \
should be at least 0.", 8L, 72L);
#endif /* NO_PROTO */
    L__1 = naht >= 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("9 20 21 22 27 28 29 46 47 49 50 51 52", "Test cases for the vis"
	    "ual effect of approximated annotation text attributes (character"
	    " height and character expansion factor) in STRING and CHAR preci"
	    "sion are not yet available.", 37L, 177L);
#else /* NO_PROTO */
    setmsg_("9 20 21 22 27 28 29 46 47 49 50 51 52", "Test cases for the vis\
ual effect of approximated annotation text attributes (character height and \
character expansion factor) in STRING and CHAR precision are not yet availab\
le.", 37L, 177L);
#endif /* NO_PROTO */
    pass_();
    nopst (&c__101);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set up 102 as sub-structure */
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
#ifndef NO_PROTO
    setmsg_("5 7 26 27 42 48 49", "Only the magnitude of character expansion"
	    " factor and character height should affect the annotation text p"
	    "rimitive.", 18L, 114L);
#else /* NO_PROTO */
    setmsg_("5 7 26 27 42 48 49", "Only the magnitude of character expansion\
 factor and character height should affect the annotation text primitive.", 
	    18L, 114L);
#endif /* NO_PROTO */
    ngtxat_("A", 1L);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

