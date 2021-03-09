/* fort/06/02/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b27 = 0.f;
#else /* NO_PROTO */
static real c_b27 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/07                           * */
/*  *    TEST TITLE : Update status of view table for INPUT * */
/*  *                 workstations                          * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, col;
    static char msg[300];
    static integer iwk, row;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer ndvi;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer onwk, idum1;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
#endif /* NO_PROTO */
    static integer owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static real cuvmm[16]	/* was [4][4] */, cuvom[16]	/* was [4][4] 
	    */;
    static integer nwval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsdus (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsdus ();
#endif /* NO_PROTO */
    static real orvmm[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static real orvom[16]	/* was [4][4] */, nwvmm[16]	/* was [4][4] 
	    */, nwvom[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *), nsvwr3 (integer *, integer *, real *, real *, real *
	    , integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwr (), nsvwr3 ();
#endif /* NO_PROTO */
    static integer oconid, cuvcid[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real cuvclm[6];
    static integer orvcid[3];
    static real orvclm[6];
    static integer nwvcid[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static real nwvclm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqevwi (integer *, integer *, integer *, 
	    integer *, integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqevwi (), xpopph_();
#endif /* NO_PROTO */
    static integer owtype, vwtupd;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */
    static integer testvw;

    /* Fortran I/O blocks */
    static icilist io___29 = { 0, msg, 0, "(A,I5)", 300, 1 };


/* Current and Requested values. */
/* clipping indicator */
/*                noclip      clip */
/* deferral mode */
/* modification mode */
/* update state */
    initgl_("06.02.02/07", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Get list of accessible workstations of category INPUT, */
/*  one element at a time.  ONWK is number of elements in */
/*  list. */
    multws_(&c__0, "i", &onwk, &owkid, &oconid, &owtype, owcat, 1L, 1L);
    if (onwk <= 0) {
	inmsg_("No INPUT workstations to be tested.", 35L);
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("26 29", "For all workstations of category INPUT, the view trans"
	    "formation update state of all entries in the view table should a"
	    "lways be NOTPENDING and reported as such.", 5L, 159L);
#else /* NO_PROTO */
    setmsg_("26 29", "For all workstations of category INPUT, the view trans\
formation update state of all entries in the view table should always be NOT\
PENDING and reported as such.", 5L, 159L);
#endif /* NO_PROTO */
/*  for each iwk in list of INPUT workstations: */
    i__1 = onwk;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	multws_(&iwk, "i", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
	nopwk (&owkid, &oconid, &owtype);
/*     <Inquire list of view indices> to determine */
/*        ndvi = number of defined indices in the view table */
	nqevwi (&owkid, &c__0, &errind, &ndvi, &idum1);
	chkinq_("pqevwi", &errind, 6L);
/*  <Set display update state> to WAIT, NIVE to try to defer updates 
*/
	nsdus (&owkid, &c__4, &c__0);
	testvw = ndvi / 2;
/*     <inquire view representation> on testvw to determine original 
*/
/*        requested state: */
	nqvwr (&owkid, &testvw, &c__1, &errind, &vwtupd, orvom, orvmm, orvclm,
		 orvcid, &orvcid[1], &orvcid[2]);
	chkinq_("pqvwr", &errind, 5L);
/*  generate different values: */
/*  nwvom  = orvom elements + 1.0 */
/*  nwvmm  = orvmm elements + 1.0 */
	for (row = 1; row <= 4; ++row) {
	    for (col = 1; col <= 4; ++col) {
#ifndef NO_PROTO
		nwvom[row + (col << 2) - 5] = orvom[row + (col << 2) - 5] + 
			1.f;
		nwvmm[row + (col << 2) - 5] = orvmm[row + (col << 2) - 5] + 
			1.f;
#else /* NO_PROTO */
		nwvom[row + (col << 2) - 5] = orvom[row + (col << 2) - 5] + (
			float)1.;
		nwvmm[row + (col << 2) - 5] = orvmm[row + (col << 2) - 5] + (
			float)1.;
#endif /* NO_PROTO */
/* L110: */
	    }
/* L120: */
	}
	for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	    nwvclm[ix - 1] = orvclm[ix - 1] / 2 + .1f;
#else /* NO_PROTO */
	    nwvclm[ix - 1] = orvclm[ix - 1] / 2 + (float).1;
#endif /* NO_PROTO */
/* L130: */
	}
	if (orvcid[0] == 1) {
	    nwval = 0;
	} else {
	    nwval = 1;
	}
	for (ix = 1; ix <= 3; ++ix) {
	    nwvcid[ix - 1] = nwval;
/* L140: */
	}
/*     <set view representation 3> on testvw with */
/*        nwvom, nwvmm, nwvclm, nwvcid */
	nsvwr3 (&owkid, &testvw, nwvom, nwvmm, nwvclm, nwvcid, &nwvcid[1], &
		nwvcid[2]);
/*     <inquire view representation> on testvw to determine new */
/*        current state: */
/*        vwtupd     = view transformation update state */
/*        cuvom(4,4) = current orientation matrix */
/*        cuvmm(4,4) = current mapping matrix */
/*        cuvclm(6)  = current view clipping limits */
/*        cuvcid(3)  = current clipping indicators */
	nqvwr (&owkid, &testvw, &c__0, &errind, &vwtupd, cuvom, cuvmm, cuvclm,
		 cuvcid, &cuvcid[1], &cuvcid[2]);
	chkinq_("pqvwr", &errind, 5L);
	nclwk (&owkid);
	if (vwtupd != 0) {
	    fail_();
	    s_wsfi(&io___29);
	    do_fio(&c__1, "Update state not= NOTPENDING:", 29L);
	    do_fio(&c__1, (char *)&vwtupd, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
	if (rareq_(&c__16, cuvom, nwvom, &c_b27, &c_b27) && rareq_(&c__16, 
		cuvmm, nwvmm, &c_b27, &c_b27) && rareq_(&c__6, cuvclm, nwvclm,
		 &c_b27, &c_b27) && iareq_(&c__3, cuvcid, nwvcid)) {
/*           OK so far */
	} else {
	    fail_();
	    inmsg_("Current values not those most recently set.", 43L);
	    goto L666;
	}
/*  next iwk */
/* L100: */
    }
    pass_();
/*  done: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

