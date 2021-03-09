/* issflt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__10 = 10;

#ifndef NO_PROTO
/* Subroutine */ int issflt_(char *stpath, char *nfilt, char *ifilt, char *
	expath, ftnlen stpath_len, ftnlen nfilt_len, ftnlen ifilt_len, ftnlen 
	expath_len)
#else /* NO_PROTO */
/* Subroutine */ int issflt_(stpath, nfilt, ifilt, expath, stpath_len, 
	nfilt_len, ifilt_len, expath_len)
char *stpath, *nfilt, *ifilt, *expath;
ftnlen stpath_len;
ftnlen nfilt_len;
ftnlen ifilt_len;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real srpx = 1.f;
    static real srpy = 2.f;
    static real srpz = 3.f;
    static real sdist = .1f;
#else /* NO_PROTO */
    static real srpx = (float)1.;
    static real srpy = (float)2.;
    static real srpz = (float)3.;
    static real sdist = (float).1;
#endif /* NO_PROTO */
    static integer sceil = 1;
    static integer mclipi = 0;

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer ifln, nfln;
#ifndef NO_PROTO
    extern /* Subroutine */ int niss3 (real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int niss3 ();
#endif /* NO_PROTO */
    static integer ifles[200], fpath[20]	/* was [2][10] */, iflis[200],
	     nfles[200], nflis[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int setfil_(char *, integer *, integer *, integer 
	    *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setfil_();
#endif /* NO_PROTO */
    static integer iflesx[60], iflisx[60], nflesx[60], istlen, iexpth[20], 
	    nflisx[60], istpth[20]	/* was [2][10] */, fpthsz;

/*  ISSFLT tests the effect of various filter lists on the behavior */
/*  of ISS.  It issues pass or fail depending on whether or not the */
/*  actual result of ISS matches the expected result.  All the */
/*  parameters are encoded in character form, and thus must be */
/*  translated before invoking ISS. */
/*  Input parameters: */
/*    STPATH : starting path for ISS */
/*    NFILT  : normal filter list */
/*    IFILT  : inverted filter list */
/*    EXPATH : expected path */
/* clipping indicator */
/*                noclip      clip */
/*  Throughout, keep fixed for ISS: */
/*    SRP = 1,2,3 */
/*    search distance = 0.1 */
/*    search ceiling = 1 */
/*    clipping flag = OFF */
/*  Set up starting path */
    setvs_(stpath, istpth, &istlen, stpath_len);
    setfil_(nfilt, &nfln, nflisx, nflis, nflesx, nfles, nfilt_len);
    setfil_(ifilt, &ifln, iflisx, iflis, iflesx, ifles, ifilt_len);
    i__1 = istlen / 2;
    niss3 (&srpx, &srpy, &srpz, &sdist, &i__1, istpth, &mclipi, &sceil, &nfln,
	     nflisx, nflis, nflesx, nfles, &ifln, iflisx, iflis, iflesx, 
	    ifles, &c__10, &errind, &fpthsz, fpath);
/*  Set up expected path */
    setvs_(expath, iexpth, &iexlen, expath_len);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issflt_ */

