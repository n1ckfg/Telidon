/* fort/06/01/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__20 = 20;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/02                           * */
/*  *    TEST TITLE : Setting and inquiring global          * */
/*  *                 transformations                       * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real m3[9]	/* was [3][3] */ = { 2.2f,4.4f,0.f,-3.333e34f,5.5f,
	    -5.2f,9.9e-11f,6.6f,9.9f };
    static real m4[16]	/* was [4][4] */ = { 2.2f,4.4f,0.f,3.1f,-3.333e34f,
	    5.5f,-5.2f,4.1f,9.9e-11f,6.6f,9.9f,5.9265f,1.34f,12.4f,123.f,
	    66.66f };
#else /* NO_PROTO */
    static real m3[9]	/* was [3][3] */ = { (float)2.2,(float)4.4,(float)0.,(
	    float)-3.333e34,(float)5.5,(float)-5.2,(float)9.9e-11,(float)6.6,(
	    float)9.9 };
    static real m4[16]	/* was [4][4] */ = { (float)2.2,(float)4.4,(float)0.,(
	    float)3.1,(float)-3.333e34,(float)5.5,(float)-5.2,(float)4.1,(
	    float)9.9e-11,(float)6.6,(float)9.9,(float)5.9265,(float)1.34,(
	    float)12.4,(float)123.,(float)66.66 };
#endif /* NO_PROTO */

    /* System generated locals */
    logical L__1;

    /* Local variables */
    static integer rl, ix, col, row, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real rlar[20];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsgmt (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsgmt ();
#endif /* NO_PROTO */
    static char strar[1*20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsgmt3 (real *), nqceco (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsgmt3 (), nqceco ();
#endif /* NO_PROTO */
    static integer errind, intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets ();
#endif /* NO_PROTO */
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer strlen, strarl[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* Element type */
/* array sizes */
/*              | 2.2 -33.33e33 9.9e-11 | */
/*  matrix m3 = | 4.4   5.5     6.6     | */
/*              | 0.0  -5.2     9.9     | */
/*              | 2.2 -33.33e33 9.9e-11   1.34 | */
/*  matrix m4 = | 4.4   5.5     6.6      12.4  | */
/*              | 0.0  -5.2     9.9     123.0  | */
/*              | 3.1   4.1     5.9265   66.66 | */
    initgl_("06.01.02/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    strid = 101;
    nopst (&strid);
/*  Use <inquire current element type and size> thoughout to determine */
/*      current element type */

/*  Use <inquire current element content> throughout to determine */
/*      current element content */
/*  <Set global transformation 3> with m4 */
    nsgmt3 (m4);
#ifndef NO_PROTO
    setmsg_("9 10", "<Inquire current element type and size> should return s"
	    "et global transformation 3 as the type of the created element an"
	    "d the appropriate element size.", 4L, 150L);
#else /* NO_PROTO */
    setmsg_("9 10", "<Inquire current element type and size> should return s\
et global transformation 3 as the type of the created element and the approp\
riate element size.", 4L, 150L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 59 && intlen == 0 && rllen == 16 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("9 11", "<Inquire current element content> should return the sta"
	    "ndard representation for set global transformation 3.", 4L, 108L);

#else /* NO_PROTO */
    setmsg_("9 11", "<Inquire current element content> should return the sta\
ndard representation for set global transformation 3.", 4L, 108L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 0 && rl == 16 && str == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes are incorrect.", 26L);
	goto L190;
    }
    ix = 0;
    for (col = 1; col <= 4; ++col) {
	for (row = 1; row <= 4; ++row) {
	    ++ix;
	    if (m4[row + (col << 2) - 5] != rlar[ix - 1]) {
		fail_();
		inmsg_("Matrix values are incorrect.", 28L);
		goto L190;
	    }
/* L110: */
	}
/* L100: */
    }
    pass_();
L190:
/*  <Set global transformation> with m3 */
    nsgmt (m3);
#ifndef NO_PROTO
    setmsg_("12 13", "<Inquire current element type and size> should return "
	    "set global transformation as the type of the created element and"
	    " the appropriate element size.", 5L, 148L);
#else /* NO_PROTO */
    setmsg_("12 13", "<Inquire current element type and size> should return \
set global transformation as the type of the created element and the appropr\
iate element size.", 5L, 148L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 60 && intlen == 0 && rllen == 9 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("12 14", "<Inquire current element content> should return the st"
	    "andard representation for set global transformation.", 5L, 106L);
#else /* NO_PROTO */
    setmsg_("12 14", "<Inquire current element content> should return the st\
andard representation for set global transformation.", 5L, 106L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 0 && rl == 9 && str == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes are incorrect.", 26L);
	goto L390;
    }
    ix = 0;
    for (col = 1; col <= 3; ++col) {
	for (row = 1; row <= 3; ++row) {
	    ++ix;
	    if (m3[row + col * 3 - 4] != rlar[ix - 1]) {
		fail_();
		inmsg_("Matrix values are incorrect.", 28L);
		goto L390;
	    }
/* L310: */
	}
/* L300: */
    }
    pass_();
L390:
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

