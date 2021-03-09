/* e01007.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
#ifndef NO_PROTO
static real c_b6 = .5f;
#else /* NO_PROTO */
static real c_b6 = (float).5;
#endif /* NO_PROTO */
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b11 = .3f;
static real c_b12 = .7f;
#else /* NO_PROTO */
static real c_b11 = (float).3;
static real c_b12 = (float).7;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__10 = 10;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e01007_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e01007_(useprm)
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
    static integer n, ol;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static integer arid, stid, paths[20]	/* was [2][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrsid_(integer *, integer *, integer *, 
	    integer *), nclst (void), rarst_(integer *, integer *, integer *),
	     rrast_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int rrest_(integer *, integer *, integer *), 
	    nexst (integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), rclarf_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrsid_(), nclst (), rarst_(), rrast_();
    extern logical streq_();
    extern /* Subroutine */ int rrest_(), nexst (), setvs_(), nopst (), 
	    rclarf_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void), rrepan_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rdstar_(integer *, integer *, integer *), esetup_(
	    integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_(), rrepan_(), rdstar_(), esetup_(), 
	    tstign_();
#endif /* NO_PROTO */
    static integer apthsz, stlist[2];

/*  E01007 tests the handling of error number 7: function requires */
/*  state (PHOP,*,*,AROP), when PHIGS is open. */
/*  path order */
    s_copy(errchr_1.curcon, "PHIGS is open but no archive file is open", 200L,
	     41L);
    setvs_("7,404", errinf_1.experr, &errinf_1.expsiz, 5L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    nopst (&c__100);
    ntx (&c_b6, &c_b6, "TEXT", 4L);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    ntx (&c_b11, &c_b12, "TEXT", 4L);
    nclst ();
    arid = 11;
    stid = 101;
    stlist[0] = 100;
    stlist[1] = 101;
    pathod = 0;
    pathdp = 0;
    rclarf_(&arid);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rarst_(&arid, &c__2, stlist);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rrsid_(&arid, &c__2, &n, stlist);
    rrest_(&arid, &c__2, stlist);
    rrast_(&arid);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rrepan_(&arid, &stid, &pathod, &pathdp, &c__10, &c__0, &ol, &apthsz, 
	    paths);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    rdstar_(&arid, &c__2, stlist);
    L__1 = streq_("O**C", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e01007_ */

