/* fort//04/03/04/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b7 = 1.f;
static real c_b10 = .1f;
#else /* NO_PROTO */
static real c_b7 = (float)1.;
static real c_b10 = (float).1;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__100 = 100;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.04.01/curnms                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int curnms_(integer *mxnofl, integer *mxn, char *stpath, 
	char *expath, char *exnmst, ftnlen stpath_len, ftnlen expath_len, 
	ftnlen exnmst_len)
#else /* NO_PROTO */
/* Subroutine */ int curnms_(mxnofl, mxn, stpath, expath, exnmst, stpath_len, 
	expath_len, exnmst_len)
integer *mxnofl, *mxn;
char *stpath, *expath, *exnmst;
ftnlen stpath_len;
ftnlen expath_len;
ftnlen exnmst_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer norexx[10] = { 0,0,0,0,0,0,0,0,0,0 };
    static integer invexx[1] = { 0 };
    static integer norinx[10] = { 1,2,3,4,5,6,7,8,9,10 };
    static integer invsiz = 1;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer ival, perm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), niss3 (real *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */, ilast;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), unmsg_(char *, ftnlen)
	    , setvs_(char *, integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), unmsg_(), setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, noract, invinc[100], norinc[10], invexc[1], norexc[
	    1], iexpth[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */
    static integer istpth[10], iexsiz, fpthsz, invinx[1], norsiz, istsiz;

    /* Fortran I/O blocks */
    static icilist io___24 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___25 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/*  CURNMS performs an incremental spatial search, with filters set */
/*  so as to accept only the expected nameset.  It issues "pass" */
/*  if the search halts at the expected location, and does not */
/*  find any primitive thereafter;  otherwise it issues "fail". */
/*  Always: search reference point is 1,1,1, search distance is 0.1, */
/*  search ceiling is 1, and modelling clip is off. */
/*  Input parameters: */
/*    MXNOFL : Maximum number of entries in normal filter list */
/*    MXN    : Maximum number of names - gives size of universe */
/*    STPATH : starting path */
/*    EXPATH : expected found path */
/*    EXNMST : expected current name set */
/* clipping indicator */
/*                noclip      clip */
/*  Exclusion sets are always empty */
/*  Normal inclusion sets are all singletons */
/*  Only one inverted inclusion and exclusion set */
    if (*mxn > 100) {
	unmsg_("Nameset universe too large for CURNMS.", 38L);
    }
/*  encode starting path */
    setvs_(stpath, istpth, &istsiz, stpath_len);
/*  encode expected found path */
    setvs_(expath, iexpth, &iexsiz, expath_len);
/*  normal filter has one inclusion set per name - this ensures that */
/*  nameset has at least all the expected names. */
    setvs_(exnmst, norinc, &norsiz, exnmst_len);
    if (norsiz <= 1) {
	goto L70;
    }
/*  mix up NORINC */
    rnperm_(&norsiz, perm);
    ival = norinc[perm[0] - 1];
    i__1 = norsiz - 1;
    for (ix = 1; ix <= i__1; ++ix) {
	norinc[perm[ix - 1] - 1] = norinc[perm[ix] - 1];
/* L80: */
    }
    norinc[perm[norsiz - 1] - 1] = ival;
L70:
/*  inverted filter has all names in its one inclusion set *except* */
/*  those expected - this ensures that no extra names are in name */
/*  set. */
    invinx[0] = *mxn - norsiz;
/*  put universe in INVINC */
    i__1 = *mxn;
    for (ival = 1; ival <= i__1; ++ival) {
	invinc[ival - 1] = ival - 1;
/* L100: */
    }
/*  take out those in expected name set. */
/*  This loop works only if maximum nameset value < MXN - NORINC ... */
/*  i.e. assumes that there are enough inverted values at the end of */
/*  INVINC to overwrite normal values. */
    ilast = *mxn;
    i__1 = norsiz;
    for (ival = 1; ival <= i__1; ++ival) {
	invinc[norinc[ival - 1]] = invinc[ilast - 1];
	--ilast;
/* L200: */
    }
/*  if filter list is too long cut back to max */
    noract = min(norsiz,*mxnofl);
    i__1 = istsiz / 2;
    niss3 (&c_b7, &c_b7, &c_b7, &c_b10, &i__1, istpth, &c__0, &c__1, &noract, 
	    norinx, norinc, norexx, norexc, &invsiz, invinx, invinc, invexx, 
	    invexc, &c__100, &errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && iareql_(&i__1, fpath, &iexsiz, iexpth)) {
/*        OK so far */
    } else {
	fail_();
	s_wsfi(&io___24);
#ifndef NO_PROTO
	do_fio(&c__1, "ISS did not return correct found path; error indicato"
		"r = ", 57L);
#else /* NO_PROTO */
	do_fio(&c__1, "ISS did not return correct found path; error indicato\
r = ", 57L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 300L);
	return 0;
    }
/* The 2nd call to ISS is valid only if the maximum length of the normal 
*/
/* filter list is >= size of nameset being tested.  Otherwise, if filter 
*/
/* list has been truncated, a primitive with a "too-small" nameset might 
*/
/* be found and cause the test to fail. */
    if (noract < norsiz) {
	pass_();
#ifndef NO_PROTO
	inmsg_("Inverse test skipped because of limitation on size of normal"
		" filter list.", 73L);
#else /* NO_PROTO */
	inmsg_("Inverse test skipped because of limitation on size of normal\
 filter list.", 73L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = iexsiz / 2;
    niss3 (&c_b7, &c_b7, &c_b7, &c_b10, &i__1, iexpth, &c__0, &c__1, &noract, 
	    norinx, norinc, norexx, norexc, &invsiz, invinx, invinc, invexx, 
	    invexc, &c__100, &errind, &fpthsz, fpath);
    if (errind == 0 && fpthsz == 0) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___25);
#ifndef NO_PROTO
	do_fio(&c__1, "ISS did not return null path as expected; error indic"
		"ator = ", 60L);
#else /* NO_PROTO */
	do_fio(&c__1, "ISS did not return null path as expected; error indic\
ator = ", 60L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* curnms_ */

