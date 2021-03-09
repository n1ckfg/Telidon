/* fort/09/02/04/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 09.02.04/07                           * */
/*  *    TEST TITLE : Error indicator = 161                 * */
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
    static real ra44[16]	/* was [4][4] */, vpnx, vpny, vpnz, vrpx, 
	    vrpy, vrpz, vupx, vupy, vupz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), setvs_(char *, integer *, 
	    integer *, ftnlen), revom3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), setvs_(), revom3_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.04/07", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the view up and view plane normal vectors are p"
	    "arallel", 200L, 54L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the view up and view plane normal vectors are p\
arallel", 200L, 54L);
#endif /* NO_PROTO */
    setvs_("161", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
#ifndef NO_PROTO
    vrpx = -3.24f;
    vrpy = 37.737f;
    vrpz = 11.2f;
    vpnx = 62.25f;
    vpny = 45.675f;
    vpnz = -25.5f;
#else /* NO_PROTO */
    vrpx = (float)-3.24;
    vrpy = (float)37.737;
    vrpz = (float)11.2;
    vpnx = (float)62.25;
    vpny = (float)45.675;
    vpnz = (float)-25.5;
#endif /* NO_PROTO */
    vupx = vpnx * 2;
    vupy = vpny * 2;
    vupz = vpnz * 2;
    revom3_(&vrpx, &vrpy, &vrpz, &vpnx, &vpny, &vpnz, &vupx, &vupy, &vupz, &
	    errind, ra44);
    vupx = vpnx * -4;
    vupy = vpny * -4;
    vupz = vpnz * -4;
    revom3_(&vrpx, &vrpy, &vrpz, &vpnx, &vpny, &vpnz, &vupx, &vupy, &vupz, &
	    errind, ra44);
    vupx = vpnx;
    vupy = vpny;
    vupz = vpnz;
    revom3_(&vrpx, &vrpy, &vrpz, &vpnx, &vpny, &vpnz, &vupx, &vupy, &vupz, &
	    errind, ra44);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

