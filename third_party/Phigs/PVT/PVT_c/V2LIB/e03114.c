/* e03114.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__801 = 801;
static integer c_n1 = -1;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e03114_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03114_(useprm)
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
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer isiz, idum1, sizb4;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static real limit[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    rsvwi_(integer *), nsvwr (integer *, integer *, real *, real *, 
	    real *, integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nclst ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nopst (), rsvwi_(), 
	    nsvwr (), chkinq_();
#endif /* NO_PROTO */
    static real mapmat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer errind, sizaft;
    static real rotmat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqevwi (integer *, integer *, integer *, integer *, integer *), 
	    setrvs_(char *, real *, integer *, ftnlen), rsvtip_(integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical strcon_();
    extern /* Subroutine */ int esetup_(), tstign_(), nqevwi (), setrvs_(), 
	    rsvtip_();
#endif /* NO_PROTO */

/*   E03114 tests the handling of error 114 */
/*   relative input priority */
/*  clipping indicator */
    s_copy(errchr_1.curcon, "the view index value is less than zero", 200L, 
	    38L);
    setvs_("114", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "13", 40L, 2L);
    esetup_(useprm);
    nopst (&c__101);
    nlb (&c__801);
    rsvwi_(&c_n1);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__101, "67,801", 6L);
    tstign_(&L__1);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    idmat_(&c__3, rotmat);
    idmat_(&c__3, mapmat);
    setrvs_("0.,0.5,0.,0.5", limit, &isiz, 13L);
    nsvwr (&globnu_1.wkid, &c__2, rotmat, mapmat, limit, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &sizb4, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    rsvtip_(&globnu_1.wkid, &c_n1, &c__2, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &sizaft, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    L__1 = streq_("OO**", 4L) && sizb4 == sizaft;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03114_ */

