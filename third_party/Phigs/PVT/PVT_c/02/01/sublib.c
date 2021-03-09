/* fort/02/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__50 = 50;
static integer c__2 = 2;
static integer c__25 = 25;
static integer c__0 = 0;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01/pthseq                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pthseq_(char *adsw, integer *strid, integer *pthord, 
	integer *pthdep, integer *retcod, char *expctd, ftnlen adsw_len, 
	ftnlen expctd_len)
#else /* NO_PROTO */
/* Subroutine */ int pthseq_(adsw, strid, pthord, pthdep, retcod, expctd, 
	adsw_len, expctd_len)
char *adsw;
integer *strid, *pthord, *pthdep, *retcod;
char *expctd;
ftnlen adsw_len;
ftnlen expctd_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3, i__4;
    char ch__1[24];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

#endif /* not NO_PROTO */
    /* Local variables */
    static char msg[300];
    static integer idum, iexp;
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
    extern logical iareq_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
    extern logical iareq_();
#endif /* NO_PROTO */
    static integer ipath;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpde (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     inmsg_(char *, ftnlen), nqpan (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpde (), inmsg_(), nqpan (), unmsg_();
#endif /* NO_PROTO */
    static logical ancest;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, replen, explen[20], reppth[50], repnum, exppth[
	    1000]	/* was [50][20] */, expnum;

    /* Fortran I/O blocks */
    static icilist io___10 = { 0, msg, 0, "(A,I4,A,I4,A,A,A, 3I5)", 300, 1 };
    static icilist io___14 = { 0, msg, 0, "(A,A,A, 3I5)", 300, 1 };


/*  Pthseq obtains a set of ancestor or descendant paths */
/*  and compares the reported set to an expected value to test */
/*  for set-equality, where each element of the set is a path. */
/*  The result is returned in retcod, which is zero if the sets */
/*  are equal.  If the sets are not equal, pthseq writes out an */
/*  informative message explaining the conditions of failure. */
/*  --- Input Parameters: */
/*  adsw    : A/D switch to indicate ancestor or descendant paths */
/*  strid   : structure identifier for start of path */
/*  pthord  : path order */
/*  pthdep  : path depth */
/*  expctd  : expected value, encoded as string; ER paths are terminated 
*/
/*            by slashes, elements separated by commas.  The sequence of 
*/
/*            integers is interpreted as: structure-id, execute-position, 
*/
/*            ... */
/*  --- Output Parameters: */
/*  retcod  : return code, indicating result of test */
/* maximum path size, number of paths, and array length */
/* these are variables to represent expected paths */
/* these are variables to hold paths as reported by inquire */
/* First, parse expctd to set up 2D ragged array of expected paths. */
    set2d_(expctd, &c__50, &expnum, explen, exppth, expctd_len);
/* check adsw validity */
    if (*adsw == 'a' || *adsw == 'A') {
	ancest = TRUE_;
    } else if (*adsw == 'd' || *adsw == 'D') {
	ancest = FALSE_;
    } else {
/* invalid adsw */
/* Writing concatenation */
	i__1[0] = 23, a__1[0] = "Invalid adsw in pthseq:";
	i__1[1] = 1, a__1[1] = adsw;
	s_cat(ch__1, a__1, i__1, &c__2, 24L);
	unmsg_(ch__1, 24L);
    }
/* now get actual paths and compare them to expected; */
/* first get number of paths = repnum */
    if (ancest) {
	nqpan (strid, pthord, pthdep, &c__25, &c__0, &errind, &repnum, &
		replen, reppth);
	chkinq_("pqpan", &errind, 5L);
    } else {
	nqpde (strid, pthord, pthdep, &c__25, &c__0, &errind, &repnum, &
		replen, reppth);
	chkinq_("pqpde", &errind, 5L);
    }
/* if number of paths unequal, whole set is unequal */
    if (repnum != expnum) {
	*retcod = 2;
	s_wsfi(&io___10);
	do_fio(&c__1, "Number of reported paths (", 26L);
	do_fio(&c__1, (char *)&repnum, (ftnlen)sizeof(integer));
	do_fio(&c__1, ") not equal to expected number (", 32L);
	do_fio(&c__1, (char *)&expnum, (ftnlen)sizeof(integer));
	do_fio(&c__1, "), ", 3L);
	do_fio(&c__1, "resulting from inquire with structure-id, path ", 47L);

	do_fio(&c__1, "order, path depth = ", 20L);
	do_fio(&c__1, (char *)&(*strid), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*pthord), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*pthdep), (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
	return 0;
    }
/* go thru set of actual paths, one at a time and compare. */
    i__2 = repnum;
    for (ipath = 1; ipath <= i__2; ++ipath) {
/* get next path */
	if (ancest) {
	    nqpan (strid, pthord, pthdep, &c__25, &ipath, &errind, &idum, &
		    replen, reppth);
	    chkinq_("pqpan", &errind, 5L);
	} else {
	    nqpde (strid, pthord, pthdep, &c__25, &ipath, &errind, &idum, &
		    replen, reppth);
	    chkinq_("pqpde", &errind, 5L);
	}
/* look for a match among expected */
	i__3 = expnum;
	for (iexp = 1; iexp <= i__3; ++iexp) {
/* seek matching length; */
/* multiply by 2, because paths have 2 integers per element - */
/* structure id and element ref */
	    if (replen << 1 != explen[iexp - 1]) {
		goto L200;
	    }
/* check contents */
	    i__4 = replen << 1;
	    if (iareq_(&i__4, reppth, &exppth[iexp * 50 - 50])) {
/* got a match - mark out length to prevent re-matching same c
olumn */
		explen[iexp - 1] = -1;
		goto L100;
	    }
L200:
	    ;
	}
/* no match found - fail */
	*retcod = 3;
	s_wsfi(&io___14);
	do_fio(&c__1, "Reported path unmatched within set of expected paths ",
		 53L);
	do_fio(&c__1, "resulting from inquire with structure-id, path ", 47L);

	do_fio(&c__1, "order, path depth = ", 20L);
	do_fio(&c__1, (char *)&(*strid), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*pthord), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*pthdep), (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
	return 0;
L100:
	;
    }
/* every reported path found a match - success */
    *retcod = 0;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pthseq_ */

