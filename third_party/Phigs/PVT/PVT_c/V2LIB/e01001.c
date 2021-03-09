/* e01001.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
/* Subroutine */ int e01001_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01001_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ropph_(integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    enderr_(void), esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ropph_();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), enderr_(), esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E01001 tests the handling of error number 1: function requires */
/*  state (PHCL,WSCL,STCL,ARCL). */
    s_copy(errchr_1.curcon, "PHIGS is open", 200L, 13L);
    setvs_("1", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    esetup_(useprm);
    ropph_(&globnu_1.errfil, &globnu_1.memun);
    L__1 = streq_("O***", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01001_ */

