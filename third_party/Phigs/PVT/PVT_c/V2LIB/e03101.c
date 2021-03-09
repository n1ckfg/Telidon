/* e03101.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__3 = 3;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int e03101_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03101_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer v1, v2, v11, ix, vdx1[300], vdx2[300], isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nsvwr (integer *, 
	    integer *, real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), nsvwr ();
#endif /* NO_PROTO */
    static integer vwsiz;
#ifndef NO_PROTO
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical iareql_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static real mapmat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer errind;
    static real rotmat[9]	/* was [3][3] */, cplimt[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), nqevwi (integer *, 
	    integer *, integer *, integer *, integer *), srtiar_(integer *, 
	    integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), nqevwi (), srtiar_(), tstign_();
#endif /* NO_PROTO */
    static integer numvdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int setrvs_(char *, real *, integer *, ftnlen), 
	    rsvtip_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setrvs_(), rsvtip_();
#endif /* NO_PROTO */

/*  E03101 tests the handling of error number 101 */
/*  clipping indicator */
/*  relative input priority */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified representation has not been defin"
	    "ed", 200L, 49L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified representation has not been defin\
ed", 200L, 49L);
#endif /* NO_PROTO */
    setvs_("101", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &numvdx, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    if (numvdx == 0) {
	idmat_(&c__3, rotmat);
	idmat_(&c__3, mapmat);
	setrvs_("0.,1.,0.,1.", cplimt, &isiz, 11L);
	nsvwr (&globnu_1.wkid, &c__1, rotmat, mapmat, cplimt, &c__1);
	v1 = 2;
	v11 = 3;
	v2 = 1;
    } else {
	i__1 = numvdx;
	for (ix = 1; ix <= i__1; ++ix) {
	    nqevwi (&globnu_1.wkid, &ix, &errind, &idum1, &vdx1[ix - 1]);
	    chkinq_("pqevwi", &errind, 6L);
/* L50: */
	}
	srtiar_(&numvdx, vdx1);
	v1 = vdx1[numvdx - 1] + 1;
	v11 = v1 + 10;
	v2 = vdx1[0];
    }
/*  V1 and V11 are undefined; V2 is defined */
    rsvtip_(&globnu_1.wkid, &v1, &v11, &c__1);
    rsvtip_(&globnu_1.wkid, &v1, &v2, &c__0);
    rsvtip_(&globnu_1.wkid, &v2, &v1, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &vwsiz, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    i__1 = vwsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	nqevwi (&globnu_1.wkid, &ix, &errind, &idum1, &vdx2[ix - 1]);
	chkinq_("pqevwi", &errind, 6L);
/* L60: */
    }
    L__1 = streq_("OO**", 4L) && iareql_(&numvdx, vdx1, &vwsiz, vdx2);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03101_ */

