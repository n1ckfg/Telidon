/* c01007.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

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

static integer c__2 = 2;
static integer c__10 = 10;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int c01007_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01007_(useprm)
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
    static integer n, ol, arid, stid, paths[20]	/* was [2][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrsid_(integer *, integer *, integer *, 
	    integer *), rarst_(integer *, integer *, integer *), rrast_(
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), ifphcl_(integer *), 
	    rclarf_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrsid_(), rarst_(), rrast_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), setvs_(), ifphcl_(), rclarf_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void), rrepan_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rdstar_(integer *, integer *, integer *), tstign_(
	    logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_(), rrepan_(), rdstar_(), tstign_();
#endif /* NO_PROTO */
    static integer apthsz, stlist[2];

/*  C01007 tests the handling of error number 7: function requires */
/*  state (PHOP,*,*,AROP), when PHIGS is closed. */
/*  path order */
    ifphcl_(useprm);
    setvs_("7,404", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    arid = 11;
    stid = 100;
    stlist[0] = 100;
    stlist[1] = 101;
    pathod = 0;
    pathdp = 0;
    rclarf_(&arid);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rarst_(&arid, &c__2, stlist);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rrsid_(&arid, &c__2, &n, stlist);
    rrest_(&arid, &c__2, stlist);
    rrast_(&arid);
    rrepan_(&arid, &stid, &pathod, &pathdp, &c__10, &c__0, &ol, &apthsz, 
	    paths);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    rdstar_(&arid, &c__2, stlist);
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01007_ */

