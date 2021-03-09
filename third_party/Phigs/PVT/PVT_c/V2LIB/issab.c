/* issab.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__100 = 100;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int issab_(real *srpx, real *srpy, real *srpz, real *sdist, 
	char *stpath, integer *mclipi, integer *sceil, char *expath, ftnlen 
	stpath_len, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int issab_(srpx, srpy, srpz, sdist, stpath, mclipi, sceil, 
	expath, stpath_len, expath_len)
real *srpx, *srpy, *srpz, *sdist;
char *stpath;
integer *mclipi, *sceil;
char *expath;
ftnlen stpath_len;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), niss3 (real *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen, istlen, iexpth[200]	/* was [2][100] */, 
	    istpth[200]	/* was [2][100] */, fpthsz;

    /* Fortran I/O blocks */
    static icilist io___10 = { 0, msg, 0, "(A,I5,A)", 200, 1 };
    static icilist io___11 = { 0, msg, 0, "(A,I5,A)", 200, 1 };


/*  This subroutine invokes the 3D spatial search routine with the */
/*  search distance set just below and above the theoretically */
/*  correct distance.  Thus, the search should first be unsuccessful, */
/*  and then successful.  ISSAB issues pass or fail as a result */
/*  of these two searches. */
/*  Input parameters: */
/*    SRPX,Y,Z   : search reference point */
/*    SDIST      : correct search distance */
/*    STPATH     : starting path */
/*    MCLIPI     : modelling clipping indicator */
/*    SCEIL      : search ceiling */
/*    EXPATH     : expected found path */
    setvs_(stpath, istpth, &istlen, stpath_len);
    setvs_(expath, iexpth, &iexlen, expath_len);
#ifndef NO_PROTO
    r__1 = *sdist * .98f;
#else /* NO_PROTO */
    r__1 = *sdist * (float).98;
#endif /* NO_PROTO */
    i__1 = istlen / 2;
    niss3 (srpx, srpy, srpz, &r__1, &i__1, istpth, mclipi, sceil, &c__0, idum,
	     idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
	    errind, &fpthsz, fpath);
    if (errind == 0 && fpthsz == 0) {
/* OK so far */
    } else {
	fail_();
	s_wsfi(&io___10);
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
	inmsg_(msg, 200L);
	return 0;
    }
#ifndef NO_PROTO
    r__1 = *sdist * 1.02f;
#else /* NO_PROTO */
    r__1 = *sdist * (float)1.02;
#endif /* NO_PROTO */
    i__1 = istlen / 2;
    niss3 (srpx, srpy, srpz, &r__1, &i__1, istpth, mclipi, sceil, &c__0, idum,
	     idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth)) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___11);
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
	inmsg_(msg, 200L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issab_ */

