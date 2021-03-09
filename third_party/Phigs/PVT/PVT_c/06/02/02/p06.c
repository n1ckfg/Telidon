/* fort/06/02/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b26 = 0.f;
#else /* NO_PROTO */
static real c_b26 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/06                           * */
/*  *    TEST TITLE : Update control of view table          * */
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
    static integer ix, col, ivw, row, svr;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer ndvi;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nuwk (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nuwk ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real ocvom[16]	/* was [4][4] */, ocvmm[16]	/* was [4][4] 
	    */;
    static integer nwval;
    static real cuvmm[16]	/* was [4][4] */, cuvom[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *), nsdus (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdus (), nsdus ();
#endif /* NO_PROTO */
    static real orvmm[16]	/* was [4][4] */, orvom[16]	/* was [4][4] 
	    */, nwvmm[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static real nwvom[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *), nsvwr3 (integer *, integer *, real *, real *, real *
	    , integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwr (), nsvwr3 ();
#endif /* NO_PROTO */
    static integer ocvcid[3], cuvcid[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real ocvclm[6], orvclm[6], cuvclm[6];
    static integer orvcid[3];
    static real nwvclm[6];
    static integer nwvcid[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqevwi (integer *, integer *, integer *, 
	    integer *, integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), nqevwi (), xpopph_();
#endif /* NO_PROTO */
    static integer vwtupd, testvw;

/* deferral mode */
/* modification mode */
/* Current and Requested values. */
/* clipping indicator */
/*                noclip      clip */
/* update state */
/* state of visual representation */
/*                correct    deferred    simulated */
/* regeneration flag */
    initgl_("06.02.02/06", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  <Inquire list of view indices> to determine */
/*     ndvi = number of defined indices in the view table */
    nqevwi (&globnu_1.wkid, &c__0, &errind, &ndvi, &idum1);
    chkinq_("pqevwi", &errind, 6L);
/*  <Set display update state> to WAIT, NIVE to try to defer updates */
    nsdus (&globnu_1.wkid, &c__4, &c__0);
    testvw = ndvi / 2;
/*  <inquire view representation> on testvw to determine original */
/*     requested and current state: */
/*     orvom(4,4) = orientation matrix */
/*     orvmm(4,4) = mapping matrix */
/*     orvclm(6)  = view clipping limits */
/*     orvcid(3)  = clipping indicators */

/*     ocvom(4,4) = orientation matrix */
/*     ocvmm(4,4) = mapping matrix */
/*     ocvclm(6)  = view clipping limits */
/*     ocvcid(3)  = clipping indicators */
    nqvwr (&globnu_1.wkid, &testvw, &c__1, &errind, &vwtupd, orvom, orvmm, 
	    orvclm, orvcid, &orvcid[1], &orvcid[2]);
    chkinq_("pqvwr", &errind, 5L);
    nqvwr (&globnu_1.wkid, &testvw, &c__0, &errind, &vwtupd, ocvom, ocvmm, 
	    ocvclm, ocvcid, &ocvcid[1], &ocvcid[2]);
    chkinq_("pqvwr", &errind, 5L);
/*  generate different values: */
/*  nwvom  = orvom elements + 1.0 */
/*  nwvmm  = orvmm elements + 1.0 */
    for (row = 1; row <= 4; ++row) {
	for (col = 1; col <= 4; ++col) {
#ifndef NO_PROTO
	    nwvom[row + (col << 2) - 5] = orvom[row + (col << 2) - 5] + 1.f;
	    nwvmm[row + (col << 2) - 5] = orvmm[row + (col << 2) - 5] + 1.f;
#else /* NO_PROTO */
	    nwvom[row + (col << 2) - 5] = orvom[row + (col << 2) - 5] + (
		    float)1.;
	    nwvmm[row + (col << 2) - 5] = orvmm[row + (col << 2) - 5] + (
		    float)1.;
#endif /* NO_PROTO */
/* L110: */
	}
/* L100: */
    }
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	nwvclm[ix - 1] = orvclm[ix - 1] / 2 + .1f;
#else /* NO_PROTO */
	nwvclm[ix - 1] = orvclm[ix - 1] / 2 + (float).1;
#endif /* NO_PROTO */
/* L120: */
    }
    if (orvcid[0] == 1) {
	nwval = 0;
    } else {
	nwval = 1;
    }
    for (ix = 1; ix <= 3; ++ix) {
	nwvcid[ix - 1] = nwval;
/* L130: */
    }
/*  <set view representation 3> on testvw with */
/*     nwvom, nwvmm, nwvclm, nwvcid */
    nsvwr3 (&globnu_1.wkid, &testvw, nwvom, nwvmm, nwvclm, nwvcid, &nwvcid[1],
	     &nwvcid[2]);
/*  <inquire view representation> on testvw to determine new */
/*     current state: */
/*     vwtupd     = view transformation update state */
/*     cuvom(4,4) = current orientation matrix */
/*     cuvmm(4,4) = current mapping matrix */
/*     cuvclm(6)  = current view clipping limits */
/*     cuvcid(3)  = current clipping indicators */
    nqvwr (&globnu_1.wkid, &testvw, &c__0, &errind, &vwtupd, cuvom, cuvmm, 
	    cuvclm, cuvcid, &cuvcid[1], &cuvcid[2]);
    chkinq_("pqvwr", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("24", "The view transformation update state returned by <inquire"
	    " view representation> should be either PENDING or NOTPENDING.", 
	    2L, 118L);
#else /* NO_PROTO */
    setmsg_("24", "The view transformation update state returned by <inquire\
 view representation> should be either PENDING or NOTPENDING.", 2L, 118L);
#endif /* NO_PROTO */
    if (vwtupd == 0) {
	pass_();
	inmsg_("Skipping PENDING test.", 22L);
	goto L300;
    } else if (vwtupd == 1) {
	pass_();
    } else {
	fail_();
	goto L300;
    }
/*  pending_test: */
#ifndef NO_PROTO
    setmsg_("27", "If the view transformation update state of an entry in th"
	    "e view table is PENDING, then the state of visual representation"
	    " for that workstation should be DEFERRED.", 2L, 162L);
#else /* NO_PROTO */
    setmsg_("27", "If the view transformation update state of an entry in th\
e view table is PENDING, then the state of visual representation for that wo\
rkstation should be DEFERRED.", 2L, 162L);
#endif /* NO_PROTO */
    nqdus (&globnu_1.wkid, &errind, &idum1, &idum2, &idum3, &svr);
    chkinq_("pqdus", &errind, 5L);
    L__1 = svr == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("17 25", "If the view transformation update state of an entry in"
	    " the view table is PENDING, then the current values of that entr"
	    "y should be the same as they were before the requested values we"
	    "re last set.", 5L, 194L);
#else /* NO_PROTO */
    setmsg_("17 25", "If the view transformation update state of an entry in\
 the view table is PENDING, then the current values of that entry should be \
the same as they were before the requested values were last set.", 5L, 194L);
#endif /* NO_PROTO */
    L__1 = rareq_(&c__16, cuvom, ocvom, &c_b26, &c_b26) && rareq_(&c__16, 
	    cuvmm, ocvmm, &c_b26, &c_b26) && rareq_(&c__6, cuvclm, ocvclm, &
	    c_b26, &c_b26) && iareq_(&c__3, cuvcid, ocvcid);
    ifpf_(&L__1);
/*  notpending_test: */
L300:
/*  <update workstation> to force update of view table */
    nuwk (&globnu_1.wkid, &c__1);
/*  <inquire display update state> to determine */
/*     svr = state of visual representation */
    nqdus (&globnu_1.wkid, &errind, &idum1, &idum2, &idum3, &svr);
    chkinq_("pqdus", &errind, 5L);
    if (svr == 0) {
#ifndef NO_PROTO
	setmsg_("28", "If the state of visual representation for a workstati"
		"on is CORRECT, then the view transformation update state of "
		"all entries should be NOTPENDING.", 2L, 146L);
#else /* NO_PROTO */
	setmsg_("28", "If the state of visual representation for a workstati\
on is CORRECT, then the view transformation update state of all entries shou\
ld be NOTPENDING.", 2L, 146L);
#endif /* NO_PROTO */
	i__1 = ndvi - 1;
	for (ivw = 0; ivw <= i__1; ++ivw) {
	    nqvwr (&globnu_1.wkid, &ivw, &c__0, &errind, &vwtupd, cuvom, 
		    cuvmm, cuvclm, cuvcid, &cuvcid[1], &cuvcid[2]);
	    chkinq_("pqvwr", &errind, 5L);
	    if (vwtupd == 0) {
/*              OK so far */
	    } else {
		fail_();
		goto L490;
	    }
/* L400: */
	}
	pass_();
    } else {
	inmsg_("Skipping test that CORRECT implies NOTPENDING.", 46L);
    }
/*  end_correct: */
L490:
/*  <inquire view representation> on testvw to determine new */
/*     current state: */
/*     vwtupd     = view transformation update state */
/*     cuvom(4,4) = current orientation matrix */
/*     cuvmm(4,4) = current mapping matrix */
/*     cuvclm(6)  = current view clipping limits */
/*     cuvcid(3)  = current clipping indicators */
    nqvwr (&globnu_1.wkid, &testvw, &c__0, &errind, &vwtupd, cuvom, cuvmm, 
	    cuvclm, cuvcid, &cuvcid[1], &cuvcid[2]);
    chkinq_("pqvwr", &errind, 5L);
    if (vwtupd != 0) {
	inmsg_("Skipping NOTPENDING test.", 25L);
	goto L590;
    }
#ifndef NO_PROTO
    setmsg_("17 26", "If the view transformation update state of an entry in"
	    " the view table is NOTPENDING, then the current values of that e"
	    "ntry should be the same as the most recently set requested value"
	    "s.", 5L, 184L);
#else /* NO_PROTO */
    setmsg_("17 26", "If the view transformation update state of an entry in\
 the view table is NOTPENDING, then the current values of that entry should \
be the same as the most recently set requested values.", 5L, 184L);
#endif /* NO_PROTO */
    L__1 = rareq_(&c__16, cuvom, nwvom, &c_b26, &c_b26) && rareq_(&c__16, 
	    cuvmm, nwvmm, &c_b26, &c_b26) && rareq_(&c__6, cuvclm, nwvclm, &
	    c_b26, &c_b26) && iareq_(&c__3, cuvcid, nwvcid);
    ifpf_(&L__1);
/*  end_notpending_test: */
L590:
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

