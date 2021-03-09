/* fort/09/02/04/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.04/04                           * */
/*  *    TEST TITLE : Error indicator = 158                 * */
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
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real bpd, fpd, ra44[16]	/* was [4][4] */, vpd, prp[3];
    static integer asiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), setvs_(char *, integer *, 
	    integer *, ftnlen), revmm3_(real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), setvs_(), revmm3_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static real pjvplm[6];
    static integer pjtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setrvs_(char *,
	     real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setrvs_();
#endif /* NO_PROTO */
    static real vwwnlm[4];

/*   viewtype */
    initgl_("09.02.04/04", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "front plane and back plane distances are equal "
	    "when z-extent of the projection viewport is non-zero", 200L, 99L);

#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "front plane and back plane distances are equal \
when z-extent of the projection viewport is non-zero", 200L, 99L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    setvs_("158", errinf_1.experr, &errinf_1.expsiz, 3L);
    setrvs_("-462.27, -80.95, -4891.85, -94.78", vwwnlm, &asiz, 33L);
    setrvs_("0.2640, 0.4082, 0.01339, 0.7457, 0.1395, 0.30036", pjvplm, &asiz,
	     48L);
    pjtype = 0;
    setrvs_("-15.044, 1.318, 34.873", prp, &asiz, 22L);
#ifndef NO_PROTO
    vpd = -1.213f;
    bpd = 15.332f;
    fpd = 15.332f;
#else /* NO_PROTO */
    vpd = (float)-1.213;
    bpd = (float)15.332;
    fpd = (float)15.332;
#endif /* NO_PROTO */
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
    pjtype = 1;
#ifndef NO_PROTO
    vpd = .16487f;
    bpd = -.0052858f;
    fpd = -.0052858f;
#else /* NO_PROTO */
    vpd = (float).16487;
    bpd = (float)-.0052858;
    fpd = (float)-.0052858;
#endif /* NO_PROTO */
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

