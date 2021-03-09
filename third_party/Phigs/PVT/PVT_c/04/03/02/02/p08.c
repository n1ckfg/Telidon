/* fort/04/03/02/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/08                        * */
/*  *    TEST TITLE : Non-explicitly defined color models   * */
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

    /* Local variables */
    static integer i, cmod, nmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer txci, idum1, idum2, idum3, idum4, idum5, idum6, idum7, 
	    hicol;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nclst (
	    void), nexst (integer *), nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nclst (), nexst (), 
	    nopst (), nsvwi ();
#endif /* NO_PROTO */
    static integer limcmd[100], lrgcmd[100];
#ifndef NO_PROTO
    extern logical undcmd_(integer *, integer *, integer *, char *, ftnlen);
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical undcmd_();
    extern /* Subroutine */ int nqcmdf ();
#endif /* NO_PROTO */
    static integer nlimcm;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), opfail_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), opfail_();
#endif /* NO_PROTO */
    static integer nlrgcm, errind, picstr, colsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setdlg_(integer *, 
	    integer *, integer *), xpopph_(integer *, integer *), setasf_(
	    integer *), nstxci (integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setdlg_(), xpopph_(), setasf_(), 
	    nstxci (), nqwksl (), setmsg_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/*     colour available */
    initgl_("04.03.02.02/08", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  make sure colro coordinate labels are visible */
    nstxci (&c__1);
    nexst (&c__102);
    nclst ();
/*  Determine list of color models to test. */
    nqcmdf (&dialog_1.specwt, &c__0, &errind, &nmod, &cmod, &idum1);
    chkinq_("pqcmdf", &errind, 6L);
    nlimcm = 0;
    nlrgcm = 0;
    i__1 = nmod;
    for (i = 1; i <= i__1; ++i) {
	nqcmdf (&dialog_1.specwt, &i, &errind, &idum1, &cmod, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
/*    implementor-defined color models (i.e. all those < 1) */
	if (cmod < 1) {
	    ++nlimcm;
	    limcmd[nlimcm - 1] = cmod;
	}
/*    registered, non-explicitly defined color models (i.e. all those 
> 4) */
	if (cmod > 4) {
	    ++nlrgcm;
	    lrgcmd[nlrgcm - 1] = cmod;
	}
/* L100: */
    }
/*  Determine the size of color table COLSIZ */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &colsiz, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (colsiz > 2) {
/* Computing MIN */
	i__1 = colsiz - 1;
	hicol = min(i__1,9);
    } else {
#ifndef NO_PROTO
	inmsg_("Color table too small to allow testing of non-explicitly def"
		"ined color models.", 78L);
#else /* NO_PROTO */
	inmsg_("Color table too small to allow testing of non-explicitly def\
ined color models.", 78L);
#endif /* NO_PROTO */
	goto L190;
    }
    nopst (&c__102);
/*  **** **** **** ****  Registered Color Models  **** **** **** **** */
    if (nlrgcm == 0) {
	inmsg_("No registered color models are supported; skipping test.", 
		56L);
	goto L110;
    }
#ifndef NO_PROTO
    setmsg_("16 17 21 28 32", "Registered colour models should work as descr"
	    "ibed by the ISO register.", 14L, 70L);
#else /* NO_PROTO */
    setmsg_("16 17 21 28 32", "Registered colour models should work as descr\
ibed by the ISO register.", 14L, 70L);
#endif /* NO_PROTO */
    if (undcmd_(&nlrgcm, lrgcmd, &hicol, "ISO register", 12L)) {
	pass_();
    } else {
	opfail_();
    }
L110:
/*  **** **** ****  Implementor defined Color Models   **** **** **** */
    if (nlimcm == 0) {
#ifndef NO_PROTO
	inmsg_("No implementor defined color models are supported; skipping "
		"test.", 65L);
#else /* NO_PROTO */
	inmsg_("No implementor defined color models are supported; skipping \
test.", 65L);
#endif /* NO_PROTO */
	goto L190;
    }
#ifndef NO_PROTO
    setmsg_("16 17 21 29 32", "Implementor defined colour models should work"
	    " as described by the implementor's documentation.", 14L, 94L);
#else /* NO_PROTO */
    setmsg_("16 17 21 29 32", "Implementor defined colour models should work\
 as described by the implementor's documentation.", 14L, 94L);
#endif /* NO_PROTO */
    if (undcmd_(&nlimcm, limcmd, &hicol, "implementor's documentation", 27L)) 
	    {
	pass_();
    } else {
	opfail_();
    }
L190:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

