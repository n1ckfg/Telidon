/* fort/09/02/04/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 09.02.04/01                           * */
/*  *    TEST TITLE : Error indicator = 151                 * */
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
    static real bpd, ra33[9]	/* was [3][3] */, fpd, ra44[16]	/* was [4][4] 
	    */, vpd, prp[3];
    static integer asiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), revmm_(real *, real *, integer *
	    , real *), setvs_(char *, integer *, integer *, ftnlen), revmm3_(
	    real *, real *, integer *, real *, real *, real *, real *, real *,
	     real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), revmm_(), setvs_(), revmm3_();
#endif /* NO_PROTO */
    static real pjvpl2[4];
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
    initgl_("09.02.04/01", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified window is invalid: UMIN>=UMAX or "
	    "VMIN>=VMAX", 200L, 57L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified window is invalid: UMIN>=UMAX or \
VMIN>=VMAX", 200L, 57L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    setvs_("151", errinf_1.experr, &errinf_1.expsiz, 3L);
/*  UMIN > UMAX */
    setrvs_("-80.95, -462.27, -4891.85, -94.78", vwwnlm, &asiz, 33L);
    setrvs_("0.2640, 0.4082, 0.01339, 0.7457, 0.1395, 0.30036", pjvplm, &asiz,
	     48L);
    pjtype = 0;
    setrvs_("-15.044, 1.318, 34.873", prp, &asiz, 22L);
#ifndef NO_PROTO
    vpd = -1.213f;
    bpd = -3.311f;
    fpd = 15.332f;
#else /* NO_PROTO */
    vpd = (float)-1.213;
    bpd = (float)-3.311;
    fpd = (float)15.332;
#endif /* NO_PROTO */
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
/*  VMIN = VMAX */
    setrvs_("-462.27, -80.95, -94.78, -94.78", vwwnlm, &asiz, 31L);
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
/*  VMIN > VMAX */
    setrvs_("-62.2236, -11.39577, 24.255, -60.530", vwwnlm, &asiz, 36L);
    setrvs_("0.1063, 0.2224, 0.1001, 0.1539, 0.2469, 0.8826", pjvplm, &asiz, 
	    46L);
    pjtype = 1;
    setrvs_("-3.6054E-2, 2.1181E-3, 3.0569", prp, &asiz, 29L);
#ifndef NO_PROTO
    vpd = .16487f;
    bpd = -.0052858f;
    fpd = 3.0531f;
#else /* NO_PROTO */
    vpd = (float).16487;
    bpd = (float)-.0052858;
    fpd = (float)3.0531;
#endif /* NO_PROTO */
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
/*  UMIN = UMAX */
    setrvs_("-62.2236, -62.2236, -60.530, 24.255", vwwnlm, &asiz, 35L);
    revmm3_(vwwnlm, pjvplm, &pjtype, prp, &prp[1], &prp[2], &vpd, &bpd, &fpd, 
	    &errind, ra44);
/*  VMIN > VMAX */
    setrvs_("-23.32, 3.56E4, 2.295, 2.29", vwwnlm, &asiz, 27L);
    setrvs_("0.298, 0.736, 0.22, 0.89", pjvpl2, &asiz, 24L);
    revmm_(vwwnlm, pjvpl2, &errind, ra33);
/*  UMIN = UMAX */
    setrvs_("3.56E4, 3.56E4, 2.29, 2.295", vwwnlm, &asiz, 27L);
    revmm_(vwwnlm, pjvpl2, &errind, ra33);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

