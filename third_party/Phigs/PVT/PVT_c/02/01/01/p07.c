/* fort/02/01/01/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.01/07                           * */
/*  *    TEST TITLE : Structure creation by changing        * */
/*  *                 structure references                  * */
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

    /* Local variables */
    static integer i;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_();
#endif /* NO_PROTO */
    static integer nstr, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqsid ();
#endif /* NO_PROTO */
    static integer nstid, strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst ();
#endif /* NO_PROTO */
    static integer strid1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncstrf (integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncstrf (), setmsg_();
#endif /* NO_PROTO */
    static integer nwstid;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.01/07", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("6", "Changing structure references should create one new struct"
	    "ure with the new identifier in the CSS when the new identifier r"
	    "efers to a non-existent structure and references to the original"
	    " structure exist.", 1L, 203L);
#else /* NO_PROTO */
    setmsg_("6", "Changing structure references should create one new struct\
ure with the new identifier in the CSS when the new identifier refers to a n\
on-existent structure and references to the original structure exist.", 1L, 
	    203L);
#endif /* NO_PROTO */
    strid = 5;
    strid1 = 10;
    nwstid = 20;
    nopst (&strid);
    nexst (&strid1);
    ncstrf (&strid1, &nwstid);
/* nstid = number of structure identifiers */
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    if (nstid != 3) {
	fail_();
	goto L300;
    }
/* nstr  = Nth structure identifier */
    i__1 = nstid;
    for (i = 1; i <= i__1; ++i) {
	nqsid (&i, &errind, &idum1, &nstr);
	chkinq_("pqsid", &errind, 5L);
	if (nstr == nwstid) {
	    pass_();
	    goto L300;
	}
/* L100: */
    }
    fail_();
L300:
#ifndef NO_PROTO
    setmsg_("6", "Changing structure references should create an empty struc"
	    "ture with the new identifier in the CSS when the new identifier "
	    "refers to a non-existent structure and references to the origina"
	    "l structure exist.", 1L, 204L);
#else /* NO_PROTO */
    setmsg_("6", "Changing structure references should create an empty struc\
ture with the new identifier in the CSS when the new identifier refers to a \
non-existent structure and references to the original structure exist.", 1L, 
	    204L);
#endif /* NO_PROTO */
    nqstst (&nwstid, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

