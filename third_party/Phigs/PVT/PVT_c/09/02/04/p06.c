/* fort/09/02/04/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 09.02.04/06                           * */
/*  *    TEST TITLE : Error indicator = 160                 * */
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
    static real ra33[9]	/* was [3][3] */, ra44[16]	/* was [4][4] */, 
	    vpnx, vpny, vpnz, vrpx, vrpy, vrpz, vupx, vupy, vupz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), revom_(real *, real *, real *, 
	    real *, integer *, real *), setvs_(char *, integer *, integer *, 
	    ftnlen), revom3_(real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), revom_(), setvs_(), revom3_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.04/06", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the view up vector has length zero", 200L, 34L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    setvs_("160", errinf_1.experr, &errinf_1.expsiz, 3L);
#ifndef NO_PROTO
    vrpx = -3.24f;
    vrpy = 37.737f;
    vrpz = 11.2f;
    vpnx = 62.21f;
    vpny = 45.67f;
    vpnz = -25.98f;
    vupx = 0.f;
    vupy = 0.f;
    vupz = 0.f;
#else /* NO_PROTO */
    vrpx = (float)-3.24;
    vrpy = (float)37.737;
    vrpz = (float)11.2;
    vpnx = (float)62.21;
    vpny = (float)45.67;
    vpnz = (float)-25.98;
    vupx = (float)0.;
    vupy = (float)0.;
    vupz = (float)0.;
#endif /* NO_PROTO */
    revom3_(&vrpx, &vrpy, &vrpz, &vpnx, &vpny, &vpnz, &vupx, &vupy, &vupz, &
	    errind, ra44);
#ifndef NO_PROTO
    vrpx = -3.24f;
    vrpy = 37.737f;
#else /* NO_PROTO */
    vrpx = (float)-3.24;
    vrpy = (float)37.737;
#endif /* NO_PROTO */
    revom_(&vrpx, &vrpy, &vupx, &vupy, &errind, ra33);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

