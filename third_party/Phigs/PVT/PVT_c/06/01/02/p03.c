/* fort/06/01/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;
static integer c__3 = 3;
static integer c__20 = 20;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__600 = 600;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/03                           * */
/*  *    TEST TITLE : Setting and inquiring modelling       * */
/*  *                 clipping                              * */
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
    static real lhs3[18]	/* was [6][3] */ = { 2.2f,-3.333e34f,9.9e-11f,
	    -1.2f,3.4f,5.6f,4.4f,5.5f,6.6f,-98.76f,543.21f,1e-12f,0.f,-5.2f,
	    9.9f,2.2f,3.3f,4.4f };
    static real lhs2[12]	/* was [4][3] */ = { -3.333e34f,9.9e-11f,
	    -1.2f,3.4f,5.5f,6.6f,-98.76f,543.21f,-5.2f,9.9f,2.2f,3.3f };
#else /* NO_PROTO */
    static real lhs3[18]	/* was [6][3] */ = { (float)2.2,(float)
	    -3.333e34,(float)9.9e-11,(float)-1.2,(float)3.4,(float)5.6,(float)
	    4.4,(float)5.5,(float)6.6,(float)-98.76,(float)543.21,(float)
	    1e-12,(float)0.,(float)-5.2,(float)9.9,(float)2.2,(float)3.3,(
	    float)4.4 };
    static real lhs2[12]	/* was [4][3] */ = { (float)-3.333e34,(float)
	    9.9e-11,(float)-1.2,(float)3.4,(float)5.5,(float)6.6,(float)
	    -98.76,(float)543.21,(float)-5.2,(float)9.9,(float)2.2,(float)3.3 
	    };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1, i__2;
    logical L__1;

    /* Local variables */
    static integer i, j, rl, ix, col;
    static char msg[300];
    static integer iop, row, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real rlar[20];
    static integer intg;
    static real lhsm[600]	/* was [6][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer nohs, idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[20];
    static real hsval;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer minop, maxop, opval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nrmcv (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nrmcv ();
#endif /* NO_PROTO */
    static logical gotop[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmcv (integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmcv ();
#endif /* NO_PROTO */
    static char strar[1*20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsmcv3 (integer *, integer 
	    *, real *), nqceco (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *, integer *, 
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsmcv3 (), nqceco ();
#endif /* NO_PROTO */
    static integer actmin;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), nqmclf (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), nqmclf ();
#endif /* NO_PROTO */
    static integer errind, intlen, ndpmcv, celtyp, navmco;
    static real replhs[600];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer strlen, opratr, strarl[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcets (integer *, integer *, integer *, integer *, integer *), 
	    errctl_(logical *), sigmsg_(integer *, char *, char *, ftnlen, 
	    ftnlen), xpopph_(integer *, integer *), nsmcli (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcets (), errctl_(), sigmsg_(), 
	    xpopph_(), nsmcli ();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* Element type */
/* Clipping indicator */
/* array sizes */
/* program limit on number of half-spaces */
/*  lhs3 = 3D half space list, in point-vector format: */

/*                point                     vector */
/*                -----                     ------ */
/*  lhs2 = 2D half space list, in point-vector format: */

/*                 point                 vector */
/*                 -----                 ------ */
    initgl_("06.01.02/03", 11L);
/* open PHIGS and structure */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopst (&c__10);
/*  Use <inquire current element type and size> thoughout to determine */
/*      current element type */

/*  Use <inquire current element content> throughout to determine */
/*      current element content */
/*  *** *** ***   Set modelling clipping volume 3   *** *** *** */
    opratr = 1;
/*  <Set modelling clipping volume 3> with operator, lhs3 */
    nsmcv3 (&opratr, &c__3, lhs3);
#ifndef NO_PROTO
    setmsg_("23 24", "<Inquire current element type and size> should return "
	    "set modelling clipping volume 3 as the type of the created eleme"
	    "nt and the appropriate element size.", 5L, 154L);
#else /* NO_PROTO */
    setmsg_("23 24", "<Inquire current element type and size> should return \
set modelling clipping volume 3 as the type of the created element and the a\
ppropriate element size.", 5L, 154L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 61 && intlen == 2 && rllen == 18 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("23 25", "<Inquire current element content> should return the st"
	    "andard representation for set modelling clipping volume 3.", 5L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("23 25", "<Inquire current element content> should return the st\
andard representation for set modelling clipping volume 3.", 5L, 112L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 2 && intar[0] == opratr && intar[1] == 3 && rl 
	    == 18 && str == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes or operator type are incorrect.", 43L);
	goto L190;
    }
    ix = 0;
    for (col = 1; col <= 3; ++col) {
	for (row = 1; row <= 6; ++row) {
	    ++ix;
	    if (lhs3[row + col * 6 - 7] != rlar[ix - 1]) {
		fail_();
		inmsg_("Half-space values are incorrect.", 32L);
		goto L190;
	    }
/* L110: */
	}
/* L100: */
    }
    pass_();
L190:
/*  *** *** ***   Set modelling clipping volume   *** *** *** */
    opratr = 2;
/*  <Set modelling clipping volume> with operator, lhs2 */
    nsmcv (&opratr, &c__3, lhs2);
#ifndef NO_PROTO
    setmsg_("26 27", "<Inquire current element type and size> should return "
	    "set modelling clipping volume as the type of the created element"
	    " and the appropriate element size.", 5L, 152L);
#else /* NO_PROTO */
    setmsg_("26 27", "<Inquire current element type and size> should return \
set modelling clipping volume as the type of the created element and the app\
ropriate element size.", 5L, 152L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 62 && intlen == 2 && rllen == 12 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("26 28", "<Inquire current element content> should return the st"
	    "andard representation for set modelling clipping volume.", 5L, 
	    110L);
#else /* NO_PROTO */
    setmsg_("26 28", "<Inquire current element content> should return the st\
andard representation for set modelling clipping volume.", 5L, 110L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 2 && intar[0] == opratr && intar[1] == 3 && rl 
	    == 12 && str == 0) {
/* OK so far */
    } else {
	fail_();
	inmsg_("Array sizes or operator type are incorrect.", 43L);
	goto L290;
    }
    ix = 0;
    for (col = 1; col <= 3; ++col) {
	for (row = 1; row <= 4; ++row) {
	    ++ix;
	    if (lhs2[row + (col << 2) - 5] != rlar[ix - 1]) {
		fail_();
		inmsg_("Half-space values are incorrect.", 32L);
		goto L290;
	    }
/* L210: */
	}
/* L200: */
    }
    pass_();
L290:
/*  *** *** ***   Modelling clipping volume facilities   *** *** *** */
    nqmclf (&c__0, &errind, &ndpmcv, &navmco, &idum1);
    chkinq_("pqmclf", &errind, 6L);
/* keep track of op 1 and 2 */
    gotop[0] = FALSE_;
    gotop[1] = FALSE_;
/* set up for max,min op */
    maxop = -9999;
    minop = 9999;
    i__1 = navmco;
    for (iop = 1; iop <= i__1; ++iop) {
	nqmclf (&iop, &errind, &idum1, &idum2, &opval);
	chkinq_("pqmclf", &errind, 6L);
	if (opval >= 1 && opval <= 2) {
	    gotop[opval - 1] = TRUE_;
	}
	maxop = max(maxop,opval);
	minop = min(minop,opval);
/* L300: */
    }
#ifndef NO_PROTO
    setmsg_("35 36", "The list of of available modelling clipping operators "
	    "reported by <inquire modelling clipping facilities> should conta"
	    "in 1 and 2.", 5L, 129L);
#else /* NO_PROTO */
    setmsg_("35 36", "The list of of available modelling clipping operators \
reported by <inquire modelling clipping facilities> should contain 1 and 2.", 
	    5L, 129L);
#endif /* NO_PROTO */
    L__1 = gotop[0] && gotop[1];
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("35 37", "The number of distinct planes for a modelling clipping"
	    " volume reported by <inquire modelling clipping facilities> shou"
	    "ld be at least 6.", 5L, 135L);
#else /* NO_PROTO */
    setmsg_("35 37", "The number of distinct planes for a modelling clipping\
 volume reported by <inquire modelling clipping facilities> should be at lea\
st 6.", 5L, 135L);
#endif /* NO_PROTO */
    L__1 = ndpmcv >= 6;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("38", "<Set modelling clipping volume> should be able to specify"
	    " an operator with an integer value greater than those supported.",
	     2L, 121L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("38", "<Set modelling clipping volume> should be able to specify\
 an operator with an integer value greater than those supported.", 2L, 121L);
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = maxop + 1;
    nsmcv (&i__1, &c__3, lhs2);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    if (globnu_1.errsig == 0) {
/*        <inquire current element content> */
	nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	L__1 = errind == 0 && intg == 2 && intar[0] == maxop + 1;
	ifpf_(&L__1);
    } else {
	fail_();
	sigmsg_(&globnu_1.errsig, globch_1.funcid, msg, 80L, 300L);
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("38", "<Set modelling clipping volume 3> should be able to speci"
	    "fy an operator with an integer value less than those supported.", 
	    2L, 120L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("38", "<Set modelling clipping volume 3> should be able to speci\
fy an operator with an integer value less than those supported.", 2L, 120L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/* Computing MIN */
    i__1 = -1, i__2 = minop - 1;
    actmin = min(i__1,i__2);
    nsmcv3 (&actmin, &c__3, lhs3);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    if (globnu_1.errsig == 0) {
/*  <inquire current element content> */
	nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	L__1 = errind == 0 && intg == 2 && intar[0] == actmin;
	ifpf_(&L__1);
    } else {
	fail_();
	sigmsg_(&globnu_1.errsig, globch_1.funcid, msg, 80L, 300L);
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("39", "<Set modelling clipping volume 3> should be able to speci"
	    "fy a modelling clipping volume with zero half-spaces.", 2L, 110L);

    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("39", "<Set modelling clipping volume 3> should be able to speci\
fy a modelling clipping volume with zero half-spaces.", 2L, 110L);
    errctl_(&c__1);
#endif /* NO_PROTO */
    nsmcv3 (&actmin, &c__0, lhs3);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    if (globnu_1.errsig == 0) {
/*  <inquire current element content> */
	nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	L__1 = errind == 0 && intg == 2 && intar[1] == 0;
	ifpf_(&L__1);
    } else {
	fail_();
	sigmsg_(&globnu_1.errsig, globch_1.funcid, msg, 80L, 300L);
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("39", "<Set modelling clipping volume> should be able to specify"
	    " a modelling clipping volume with many half-spaces.", 2L, 108L);
#else /* NO_PROTO */
    setmsg_("39", "<Set modelling clipping volume> should be able to specify\
 a modelling clipping volume with many half-spaces.", 2L, 108L);
#endif /* NO_PROTO */
/* number of half-spaces to try */
/* Computing MIN */
    i__1 = 100, i__2 = ndpmcv + 1;
    nohs = min(i__1,i__2);
/* generate some numbers */
#ifndef NO_PROTO
    hsval = 5.5f;
#else /* NO_PROTO */
    hsval = (float)5.5;
#endif /* NO_PROTO */
    for (i = 1; i <= 6; ++i) {
	i__1 = nohs;
	for (j = 1; j <= i__1; ++j) {
#ifndef NO_PROTO
	    hsval *= 1.1f;
	    if (hsval > 20.f) {
		hsval /= 21.3f;
#else /* NO_PROTO */
	    hsval *= (float)1.1;
	    if (hsval > (float)20.) {
		hsval /= (float)21.3;
#endif /* NO_PROTO */
	    }
	    lhsm[i + j * 6 - 7] = hsval;
/* L340: */
	}
/* L330: */
    }
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nsmcv3 (&c__1, &nohs, lhsm);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    if (globnu_1.errsig == 0) {
/*  <inquire current element content> */
	nqceco (&c__20, &c__600, &c__20, &errind, &intg, intar, &rl, replhs, &
		str, strarl, strar, 1L);
	if (errind == 0 && intg == 2 && intar[1] == nohs) {
/* OK so far */
	    ix = 0;
	    i__1 = nohs;
	    for (col = 1; col <= i__1; ++col) {
		for (row = 1; row <= 6; ++row) {
		    ++ix;
		    if (lhsm[row + col * 6 - 7] != replhs[ix - 1]) {
			fail_();
			inmsg_("Half-space values are incorrect.", 32L);
			goto L360;
		    }
/* L352: */
		}
/* L351: */
	    }
	    pass_();
L360:
	    ;
	} else {
	    fail_();
	    inmsg_("Error code or array size incorrect.", 35L);
	}
    } else {
	fail_();
	sigmsg_(&globnu_1.errsig, globch_1.funcid, msg, 80L, 300L);
	inmsg_(msg, 300L);
    }
/*  *** *** ***   Set modelling clipping indicator   *** *** *** */
/*  <Set modelling clipping indicator> with CLIP */
    nsmcli (&c__1);
#ifndef NO_PROTO
    setmsg_("29 30", "<Inquire current element type and size> should return "
	    "set modelling clipping indicator as the type of the created elem"
	    "ent and the appropriate element size, when CLIP is specified.", 
	    5L, 179L);
#else /* NO_PROTO */
    setmsg_("29 30", "<Inquire current element type and size> should return \
set modelling clipping indicator as the type of the created element and the \
appropriate element size, when CLIP is specified.", 5L, 179L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 63 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("29 31 52", "<Inquire current element content> should return the"
	    " standard representation for set modelling clipping indicator, w"
	    "hen CLIP is specified.", 8L, 137L);
#else /* NO_PROTO */
    setmsg_("29 31 52", "<Inquire current element content> should return the\
 standard representation for set modelling clipping indicator, when CLIP is \
specified.", 8L, 137L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    L__1 = errind == 0 && intg == 1 && intar[0] == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/*  <Set modelling clipping indicator> with NOCLIP */
    nsmcli (&c__0);
#ifndef NO_PROTO
    setmsg_("29 30", "<Inquire current element type and size> should return "
	    "set modelling clipping indicator as the type of the created elem"
	    "ent and the appropriate element size, when NOCLIP is specified.", 
	    5L, 181L);
#else /* NO_PROTO */
    setmsg_("29 30", "<Inquire current element type and size> should return \
set modelling clipping indicator as the type of the created element and the \
appropriate element size, when NOCLIP is specified.", 5L, 181L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 63 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("29 31 52", "<Inquire current element content> should return the"
	    " standard representation for set modelling clipping indicator, w"
	    "hen NOCLIP is specified.", 8L, 139L);
#else /* NO_PROTO */
    setmsg_("29 31 52", "<Inquire current element content> should return the\
 standard representation for set modelling clipping indicator, when NOCLIP i\
s specified.", 8L, 139L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    L__1 = errind == 0 && intg == 1 && intar[0] == 0 && rl == 0 && str == 0;
    ifpf_(&L__1);
/*  *** *** ***   Restore modelling clipping volume   *** *** *** */
/*  <Restore modelling clipping volume> */
    nrmcv ();
#ifndef NO_PROTO
    setmsg_("32 33", "<Inquire current element type and size> should return "
	    "restore modelling clipping volume as the type of the created ele"
	    "ment and the appropriate element size.", 5L, 156L);
#else /* NO_PROTO */
    setmsg_("32 33", "<Inquire current element type and size> should return \
restore modelling clipping volume as the type of the created element and the\
 appropriate element size.", 5L, 156L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 64 && intlen == 0 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("32 34", "<Inquire current element content> should return the st"
	    "andard representation for restore modelling clipping volume.", 5L,
	     114L);
#else /* NO_PROTO */
    setmsg_("32 34", "<Inquire current element content> should return the st\
andard representation for restore modelling clipping volume.", 5L, 114L);
#endif /* NO_PROTO */
/*  <inquire current element content> */
    nqceco (&c__20, &c__20, &c__20, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    L__1 = errind == 0 && intg == 0 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

