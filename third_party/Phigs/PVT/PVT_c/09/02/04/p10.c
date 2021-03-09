/* fort/09/02/04/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 09.02.04/10                           * */
/*  *    TEST TITLE : Error indicator = 164                 * */
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
    initgl_("09.02.04/10", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the back plane is in front of the front plane", 
	    200L, 45L);
    s_copy(errchr_1.errsrs, "10", 40L, 2L);
    setvs_("164", errinf_1.experr, &errinf_1.expsiz, 3L);
    setrvs_("-462.27, -80.95, -4891.85, -94.78", vwwnlm, &asiz, 33L);
    setrvs_("0.2640, 0.4082, 0.01339, 0.7457, 0.1395, 0.30036", pjvplm, &asiz,
	     48L);
    pjtype = 0;
    setrvs_("-15.044, 1.318, 34.873", prp, &asiz, 22L);
#ifndef NO_PROTO
    vpd = -1.213f;
    bpd = -3.311f;
    fpd = -15.332f;
#else /* NO_PROTO */
    vpd = (float)-1.213;
    bpd = (float)-3.311;
    fpd = (float)-15.332;
#endif /* NO_PROTO */
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
    setrvs_("-62.2236, -11.39577, -60.530, 24.255", vwwnlm, &asiz, 36L);
    setrvs_("0.1039, 0.2243, 0.1012, 0.1592, 0.2495, 0.8862", pjvplm, &asiz, 
	    46L);
    pjtype = 1;
    setrvs_("-3.6054E-2, 2.1181E-3, 3.0569", prp, &asiz, 29L);
#ifndef NO_PROTO
    vpd = .16487f;
    bpd = .0052858f;
    fpd = .0030531f;
#else /* NO_PROTO */
    vpd = (float).16487;
    bpd = (float).0052858;
    fpd = (float).0030531;
#endif /* NO_PROTO */
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

