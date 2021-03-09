/* isspf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__100 = 100;

#ifndef NO_PROTO
/* Subroutine */ int isspf_(integer *dimens, real *srpx, real *srpy, real *
	srpz, real *sdist, char *expath, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int isspf_(dimens, srpx, srpy, srpz, sdist, expath, 
	expath_len)
integer *dimens;
real *srpx, *srpy, *srpz, *sdist;
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
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int niss (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), niss3 (
	    real *, real *, real *, real *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int niss (), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen, iexpth[200]	/* was [2][100] */, fpthsz;

/*  This subroutine invokes the specified spatial search routine and */
/*  issues pass or fail, depending on its agreement with the expected */
/*  result.  Always: structure #101 is searched, search ceiling is 1, */
/*  modelling clip off, filter lists empty. */
/*  Input parameters: */
/*    DIMENS         : dimension of search: 2 or 3 */
/*    SRPX,SRPY,SRPZ : search reference point (SRPZ ignored if DIMENS=2) 
*/
/*    SDIST          : search distance */
/*    EXPATH         : expected found path */
/* clipping indicator */
/*                noclip      clip */
    if (*dimens == 2) {
	niss (srpx, srpy, sdist, &c__1, spath, &c__0, &c__1, &c__0, idum, 
		idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
		errind, &fpthsz, fpath);
    } else if (*dimens == 3) {
	niss3 (srpx, srpy, srpz, sdist, &c__1, spath, &c__0, &c__1, &c__0, 
		idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &
		c__100, &errind, &fpthsz, fpath);
    } else {
	unmsg_("Illegal dimension passed to ISSPF.", 34L);
    }
    setvs_(expath, iexpth, &iexlen, expath_len);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* isspf_ */

