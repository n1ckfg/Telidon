/* comtok.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 3.f;
static real c_b3 = 4.f;
static real c_b4 = 5.f;
static real c_b5 = .03f;
#else /* NO_PROTO */
static real c_b2 = (float)3.;
static real c_b3 = (float)4.;
static real c_b4 = (float)5.;
static real c_b5 = (float).03;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__100 = 100;

#ifndef NO_PROTO
/* Subroutine */ int comtok_(real *expcom, char *expath, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int comtok_(expcom, expath, expath_len)
real *expcom;
char *expath;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer spath[2]	/* was [2][1] */ = { 101,0 };

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), ifpf_();
#endif /* NO_PROTO */
    static integer idum[2];
    static real srpx, srpy, srpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int niss3 (real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen, iexpth[200]	/* was [2][100] */, fpthsz;

/*  COMTOK accepts an expected composite transformation and found */
/*  path.  It performs an incremental spatial search of structure */
/*  #101, using the transformed value of (3,4,5) as the SRP, and */
/*  issues pass or fail depending on whether the actual found path */
/*  matches that expected. */
/*  Input parameters: */
/*    EXPCOM : expected composite transformation */
/*    EXPATH : expected found path */
/* clipping indicator */
/*                noclip      clip */
    /* Parameter adjustments */
    expcom -= 5;

    /* Function Body */
/*  get expected point in WC */
    etp3_(&c_b2, &c_b3, &c_b4, &expcom[5], &srpx, &srpy, &srpz);
/*  decode expected found path */
    setvs_(expath, iexpth, &iexlen, expath_len);
    niss3 (&srpx, &srpy, &srpz, &c_b5, &c__1, spath, &c__0, &c__1, &c__0, 
	    idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* comtok_ */

