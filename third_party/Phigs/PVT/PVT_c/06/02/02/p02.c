/* fort/06/02/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b15 = 0.f;
#else /* NO_PROTO */
static real c_b15 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/02                           * */
/*  *    TEST TITLE : Validity of predefined view table     * */
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
    static real exvclm[6] = { 0.f,1.f,0.f,1.f,0.f,1.f };
#else /* NO_PROTO */
    static real exvclm[6] = { (float)0.,(float)1.,(float)0.,(float)1.,(float)
	    0.,(float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
    static real vmm[16]	/* was [4][4] */, vom[16]	/* was [4][4] */;
    static integer ivw;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer vcid[3];
    static real vclm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer npvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static real ident[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), nqvwf (
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int nqwkc (), nopwk (), nqvwf (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqpvwr (
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    , integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqpvwr ();
#endif /* NO_PROTO */

/* clipping indicator */
/*                noclip      clip */
/* expected values for default clipping limits */
    initgl_("06.02.02/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("4 5", "The reported number of predefined views should be at lea"
	    "st 6.", 3L, 61L);
#else /* NO_PROTO */
    setmsg_("4 5", "The reported number of predefined views should be at lea\
st 6.", 3L, 61L);
#endif /* NO_PROTO */
/*  <Inquire view facilities> to determine */
/*    npvw = number of predefined views */
    npvw = -6;
    nqvwf (&specwt, &errind, &npvw);
    L__1 = errind == 0 && npvw > 5;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "All the predefined view entries should be accessible by "
	    "<inquire predefined view representation>.", 3L, 97L);
#else /* NO_PROTO */
    setmsg_("4 6", "All the predefined view entries should be accessible by \
<inquire predefined view representation>.", 3L, 97L);
#endif /* NO_PROTO */
    i__1 = npvw - 1;
    for (ivw = 0; ivw <= i__1; ++ivw) {
	nqpvwr (&specwt, &ivw, &errind, vom, vmm, vclm, vcid, &vcid[1], &vcid[
		2]);
	if (errind != 0) {
	    fail_();
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
/*  <inquire predefined view representation> on entry #0 to determine: */
/*     vom(4,4) = orientation matrix */
/*     vmm(4,4) = mapping matrix */
/*     vclm(6)  = view clipping limits */
/*     vcid(3)  = clipping indicators */
#ifndef NO_PROTO
    vclm[0] = -6.f;
#else /* NO_PROTO */
    vclm[0] = (float)-6.;
#endif /* NO_PROTO */
    vcid[0] = -6;
    nqpvwr (&specwt, &c__0, &errind, vom, vmm, vclm, vcid, &vcid[1], &vcid[2])
	    ;
    chkinq_("pqpvwr", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("6 7", "The orientation and mapping matrices for predefined view"
	    " #0 should both be the identity matrix.", 3L, 95L);
#else /* NO_PROTO */
    setmsg_("6 7", "The orientation and mapping matrices for predefined view\
 #0 should both be the identity matrix.", 3L, 95L);
#endif /* NO_PROTO */
    idmat_(&c__4, ident);
    L__1 = rareq_(&c__16, vom, ident, &c_b15, &c_b15) && rareq_(&c__16, vmm, 
	    ident, &c_b15, &c_b15);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6 7", "The clipping limits for predefined view #0 should be [0,"
	    "1] in all three dimensions.", 3L, 83L);
#else /* NO_PROTO */
    setmsg_("6 7", "The clipping limits for predefined view #0 should be [0,\
1] in all three dimensions.", 3L, 83L);
#endif /* NO_PROTO */
    L__1 = rareq_(&c__6, vclm, exvclm, &c_b15, &c_b15);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6 7", "All three clipping indicators for predefined view #0 sho"
	    "uld be CLIP.", 3L, 68L);
#else /* NO_PROTO */
    setmsg_("6 7", "All three clipping indicators for predefined view #0 sho\
uld be CLIP.", 3L, 68L);
#endif /* NO_PROTO */
    L__1 = vcid[0] == 1 && vcid[1] == 1 && vcid[2] == 1;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

