/* issgeo.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__30 = 30;

#ifndef NO_PROTO
/* Subroutine */ int issgeo_(char *stpth, integer *exix, real *exxlo, real *
	exylo, real *exxhi, real *exyhi, char *expth, ftnlen stpth_len, 
	ftnlen expth_len)
#else /* NO_PROTO */
/* Subroutine */ int issgeo_(stpth, exix, exxlo, exylo, exxhi, exyhi, expth, 
	stpth_len, expth_len)
char *stpth;
integer *exix;
real *exxlo, *exylo, *exxhi, *exyhi;
char *expth;
ftnlen stpth_len;
ftnlen expth_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), niss (real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), niss ();
#endif /* NO_PROTO */
    static real srpx, srpy;
    static integer fpath[60]	/* was [2][30] */, exlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer spath[60]	/* was [2][30] */;
    static real sdist;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer spsiz;
#ifndef NO_PROTO
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, expath[30];
    static real sratio, incrvx, incrvy;
    static integer fpthsz;

/*  This subroutine tests whether ISS successfully detects the */
/*  corners of a text extent rectangle. */
/*  Input parameters: */
/*    STPTH    : starting path for ISS */
/*    EXIX, EXXLO,EXYLO,EXXHI,EXYHI */
/*             : expected corner values for rectangle */
/*    EXPTH    : expected found path for ISS */
/* clipping indicator */
/*                noclip      clip */
/*  sratio = search ratio = 0.1 */
#ifndef NO_PROTO
    sratio = .1f;
#else /* NO_PROTO */
    sratio = (float).1;
#endif /* NO_PROTO */
/*  diagv = diagonal vector = vector from lower-left expected corner */
/*    to upper-right */
/*  incrv = incremental vector = sratio*diagv */
    incrvx = (exxhi[*exix] - exxlo[*exix]) * sratio;
    incrvy = (exyhi[*exix] - exylo[*exix]) * sratio;
/*  sdist = search distance  = length of incrv */
    sdist = vecl_(&incrvx, &incrvy, &c_b2);
/*  srp = upper-right corner + incrv */
    srpx = exxhi[*exix] + incrvx;
    srpy = exyhi[*exix] + incrvy;
/*  starting path */
    setvs_(stpth, spath, &spsiz, stpth_len);
    spsiz /= 2;
/*  expected path */
    setvs_(expth, expath, &exlen, expth_len);
/*  ISS: with stpath, srp, try search distance first just below and */
/*     then just above sdist. */
/*  pass/fail depending on (text first not found with expected path, */
/*     then found with expected path) */
#ifndef NO_PROTO
    r__1 = sdist * .98f;
#else /* NO_PROTO */
    r__1 = sdist * (float).98;
#endif /* NO_PROTO */
    niss (&srpx, &srpy, &r__1, &spsiz, spath, &c__0, &c__1, &c__0, idum, idum,
	     idum, idum, &c__0, idum, idum, idum, idum, &c__30, &errind, &
	    fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && ! iareql_(&i__1, fpath, &exlen, expath)) {
/* OK so far */
    } else {
	fail_();
#ifndef NO_PROTO
	inmsg_("ISS erroneously found expected path, even though search dist"
		"ance was insufficient.", 82L);
#else /* NO_PROTO */
	inmsg_("ISS erroneously found expected path, even though search dist\
ance was insufficient.", 82L);
#endif /* NO_PROTO */
	return 0;
    }
#ifndef NO_PROTO
    r__1 = sdist * 1.02f;
#else /* NO_PROTO */
    r__1 = sdist * (float)1.02;
#endif /* NO_PROTO */
    niss (&srpx, &srpy, &r__1, &spsiz, spath, &c__0, &c__1, &c__0, idum, idum,
	     idum, idum, &c__0, idum, idum, idum, idum, &c__30, &errind, &
	    fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && iareql_(&i__1, fpath, &exlen, expath)) {
	pass_();
    } else {
	fail_();
#ifndef NO_PROTO
	inmsg_("ISS did not find expected path, even though search distance "
		"was sufficient.", 75L);
#else /* NO_PROTO */
	inmsg_("ISS did not find expected path, even though search distance \
was sufficient.", 75L);
#endif /* NO_PROTO */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issgeo_ */

