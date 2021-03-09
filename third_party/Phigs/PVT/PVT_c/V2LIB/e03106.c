/* e03106.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b11 = 1.f;
static real c_b18 = .5f;
static real c_b26 = .01f;
#else /* NO_PROTO */
static real c_b11 = (float)1.;
static real c_b18 = (float).5;
static real c_b26 = (float).01;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e03106_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03106_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ii, ip, ir, ix, prec1, idum1, idum2, idum3, idum4, idum5, 
	    font1;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static integer npair;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nqtxf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, real *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), nqtxf (), setvs_();
#endif /* NO_PROTO */
    static real space1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *), rstxr_(integer *, integer *, integer *, integer *, 
	    real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxr (), nstxr (), rstxr_();
#endif /* NO_PROTO */
    static real expan1;
    static integer color1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, fontip[100], unprec, specwt, unfont;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), srtiar_(integer *, 
	    integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), srtiar_(), tstign_();
#endif /* NO_PROTO */
    static integer txtprc[100], txtfnt[100];

/*   E03106 tests the handling of error number 106 */
/*  type of returned value */
/*  text precision */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified font is not available for the req"
	    "uested text precision on the specified workstation", 200L, 97L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified font is not available for the req\
uested text precision on the specified workstation", 200L, 97L);
#endif /* NO_PROTO */
    setvs_("106", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqtxf (&specwt, &c__0, &errind, &npair, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    i__1 = npair;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&specwt, &ix, &errind, &idum1, &txtfnt[ix - 1], &txtprc[ix - 1]
		, &idum2, &rdum1, &rdum2, &idum3, &rdum3, &rdum4, &idum4);
	chkinq_("pqtxf", &errind, 5L);
/* L50: */
    }
    nstxr (&globnu_1.wkid, &c__1, txtfnt, txtprc, &c_b11, &c_b11, &c__0);
    for (ip = 2; ip >= 0; --ip) {
	ii = 0;
	i__1 = npair;
	for (ir = 1; ir <= i__1; ++ir) {
	    if (txtprc[ir - 1] == ip) {
		++ii;
		fontip[ii - 1] = txtfnt[ir - 1];
	    }
/* L160: */
	}
	if (ii == 0) {
	    goto L150;
	}
	srtiar_(&ii, fontip);
	unfont = fontip[ii - 1] + 1;
	unprec = ip;
	goto L200;
L150:
	;
    }
L200:
    rstxr_(&globnu_1.wkid, &c__1, &unfont, &unprec, &c_b18, &c_b18, &c__0);
    nqtxr (&globnu_1.wkid, &c__1, &c__0, &errind, &font1, &prec1, &expan1, &
	    space1, &color1);
    chkinq_("pqtxr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && font1 == txtfnt[0] && prec1 == txtprc[0] && 
	    appeq_(&expan1, &c_b11, &c_b26, &c_b26) && appeq_(&space1, &c_b11,
	     &c_b26, &c_b26) && color1 == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03106_ */

