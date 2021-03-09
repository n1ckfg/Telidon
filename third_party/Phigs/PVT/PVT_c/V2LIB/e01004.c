/* e01004.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__101 = 101;
static integer c__11 = 11;

#ifndef NO_PROTO
/* Subroutine */ int e01004_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01004_(useprm)
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
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int rclph_(void), nclwk (integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rclph_(), nclwk (), nclst ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nopst (), nclarf (), 
	    enderr_(), avarnm_(), esetup_(), tstign_(), noparf ();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    nclarf (integer *), enderr_(void), avarnm_(integer *), esetup_(
	    integer *), tstign_(logical *), noparf (integer *, integer *);

#endif /* not NO_PROTO */
/*  E01004 tests the handling of error number 4: function requires */
/*  state (PHOP,WSCL,STCL,ARCL) when PHIGS is open. */
    setvs_("4", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    s_copy(errchr_1.curcon, "PHIGS is open and a workstation is open", 200L, 
	    39L);
    rclph_();
    L__1 = streq_("OO**", 4L);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    nopst (&c__101);
    s_copy(errchr_1.curcon, "PHIGS is open and a structure is open", 200L, 
	    37L);
    rclph_();
    L__1 = streq_("OCO*", 4L);
    tstign_(&L__1);
    nclst ();
    avarnm_(&arnm);
    noparf (&c__11, &arnm);
    s_copy(errchr_1.curcon, "PHIGS is open and an archive file is open", 200L,
	     41L);
    rclph_();
    L__1 = streq_("OCCO", 4L);
    tstign_(&L__1);
    nclarf (&c__11);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01004_ */

