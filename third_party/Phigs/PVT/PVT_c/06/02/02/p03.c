/* fort/06/02/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

/* Table of constant values */

static integer c__0 = 0;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b36 = 0.f;
#else /* NO_PROTO */
static real c_b36 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/03                           * */
/*  *    TEST TITLE : Initialization of WSL view table      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3, i__4;
    logical L__1;
    char ch__1[114], ch__2[113], ch__3[151], ch__4[177], ch__5[126];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, col;
    static char msg[300];
    static integer ivw, row;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer ndvi;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer e0cid[3], npvw, idum1, idum2, idum3, idum4, idum5, idum6, 
	    idum7;
    static real e0vom[16]	/* was [4][4] */, e0vmm[16]	/* was [4][4] 
	    */;
    static integer dfcid[3], pdcid[3];
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real dfvmm[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical rareq_();
#endif /* NO_PROTO */
    static real dfvom[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static real pdvmm[16]	/* was [4][4] */, pdvom[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static integer ivwdx, maxvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwf (integer *, integer *, integer *), 
	    nqvwr (integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwf (), nqvwr ();
#endif /* NO_PROTO */
    static real e0vclm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr3 (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr3 ();
#endif /* NO_PROTO */
    static real dfvclm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
    static real pdvclm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static char msgsuf[25];
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqevwi (integer *, integer *, integer *, 
	    integer *, integer *), xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nsvtip (integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqevwi (), xpopph_(), nqwksl (), nsvtip ();
#endif /* NO_PROTO */
    static integer vwtupd;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpvwr (integer *, integer *, integer *, real 
	    *, real *, real *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpvwr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___22 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___28 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___29 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___34 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___35 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___36 = { 0, msg, 0, "(A,I5)", 300, 1 };


/* control functions that return both Current and Requested values. */
/* clipping indicator */
/*                noclip      clip */
/* relative input priority */
/* update state */
    initgl_("06.02.02/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  message suffix */
    s_copy(msgsuf, "opening workstation.", 25L, 20L);
/*  top of check_table loop */
L100:
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <Inquire list of view indices> to determine */
/*     ndvi = number of defined indices in the view table */
    nqevwi (&globnu_1.wkid, &c__0, &errind, &ndvi, &idum1);
    chkinq_("pqevwi", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 89, a__1[0] = "List of view indices should be in consecutive a"
	    "scending order, starting with zero, after ";
#else /* NO_PROTO */
    i__1[0] = 89, a__1[0] = "List of view indices should be in consecutive a\
scending order, starting with zero, after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 114L);
    setmsg_("8 18 19", ch__1, 7L, 114L);
    i__2 = ndvi;
    for (ivw = 1; ivw <= i__2; ++ivw) {
	nqevwi (&globnu_1.wkid, &ivw, &errind, &idum1, &ivwdx);
	chkinq_("pqevwi", &errind, 6L);
	if (ivwdx != ivw - 1) {
	    fail_();
	    goto L210;
	}
/* L200: */
    }
    pass_();
L210:
/*  <Inquire view facilities> to determine */
/*     npvw = number of predefined views */
    npvw = 666;
    nqvwf (&specwt, &errind, &npvw);
    chkinq_("pqvwf", &errind, 5L);
/*  <inquire workstation state table lengths> to determine */
/*     maxvw = maximum size of the view table */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &idum7, &maxvw);
    chkinq_("pqwksl", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 88, a__1[0] = "There should be at least as many defined view i"
	    "ndices as predefined view entries, after ";
#else /* NO_PROTO */
    i__1[0] = 88, a__1[0] = "There should be at least as many defined view i\
ndices as predefined view entries, after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 113L);
    setmsg_("4 9", ch__2, 3L, 113L);
    L__1 = ndvi >= npvw;
    ifpf_(&L__1);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 89, a__1[0] = "The number of defined view indices should be th"
	    "e same as the maximum table length, after ";
#else /* NO_PROTO */
    i__1[0] = 89, a__1[0] = "The number of defined view indices should be th\
e same as the maximum table length, after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 114L);
    setmsg_("10 12", ch__1, 5L, 114L);
    L__1 = ndvi == maxvw;
    ifpf_(&L__1);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 126, a__1[0] = "For each WDT predefined view, the correspondin"
	    "g WSL requested and current view table entry should have the sam"
	    "e values, after ";
#else /* NO_PROTO */
    i__1[0] = 126, a__1[0] = "For each WDT predefined view, the correspondin\
g WSL requested and current view table entry should have the same values, af\
ter ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__3, a__1, i__1, &c__2, 151L);
    setmsg_("6 9 17", ch__3, 6L, 151L);
    i__2 = npvw - 1;
    for (ivwdx = 0; ivwdx <= i__2; ++ivwdx) {
/*        <Inquire predefined view representation> to determine */
/*        set of values from WDT for index=ivwdx */
	nqpvwr (&specwt, &ivwdx, &errind, pdvom, pdvmm, pdvclm, pdcid, &pdcid[
		1], &pdcid[2]);
	if (errind != 0) {
	    fail_();
	    s_wsfi(&io___22);
#ifndef NO_PROTO
	    do_fio(&c__1, "<Inquire predefined view representation> failed w"
		    "ith error = ", 61L);
#else /* NO_PROTO */
	    do_fio(&c__1, "<Inquire predefined view representation> failed w\
ith error = ", 61L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L310;
	}
/*        <Inquire view representation> to determine */
/*        set of values from WSL for index=ivwdx */
/* ----- requested values */
	nqvwr (&globnu_1.wkid, &ivwdx, &c__1, &errind, &vwtupd, dfvom, dfvmm, 
		dfvclm, dfcid, &dfcid[1], &dfcid[2]);
	if (errind != 0) {
	    fail_();
	    s_wsfi(&io___28);
#ifndef NO_PROTO
	    do_fio(&c__1, "<Inquire view representation> for requested value"
		    "s failed with error = ", 71L);
#else /* NO_PROTO */
	    do_fio(&c__1, "<Inquire view representation> for requested value\
s failed with error = ", 71L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L310;
	}
/* check matrices and clip limits */
	if (! (rareq_(&c__16, dfvom, pdvom, &c_b36, &c_b36) && rareq_(&c__16, 
		dfvmm, pdvmm, &c_b36, &c_b36) && rareq_(&c__6, dfvclm, pdvclm,
		 &c_b36, &c_b36) && iareq_(&c__3, dfcid, pdcid))) {
	    fail_();
	    goto L310;
	}
/* ----- current values */
	nqvwr (&globnu_1.wkid, &ivwdx, &c__0, &errind, &vwtupd, dfvom, dfvmm, 
		dfvclm, dfcid, &dfcid[1], &dfcid[2]);
	if (errind != 0) {
	    fail_();
	    s_wsfi(&io___29);
#ifndef NO_PROTO
	    do_fio(&c__1, "<Inquire view representation> for current values "
		    "failed with error = ", 69L);
#else /* NO_PROTO */
	    do_fio(&c__1, "<Inquire view representation> for current values \
failed with error = ", 69L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L310;
	}
/* check matrices and clip limits */
	if (! (rareq_(&c__16, dfvom, pdvom, &c_b36, &c_b36) && rareq_(&c__16, 
		dfvmm, pdvmm, &c_b36, &c_b36) && rareq_(&c__6, dfvclm, pdvclm,
		 &c_b36, &c_b36) && iareq_(&c__3, dfcid, pdcid))) {
	    fail_();
	    goto L310;
	}
/* L300: */
    }
    pass_();
L310:
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 152, a__1[0] = "Each WSL requested and current view table entr"
	    "y for which there is no corresponding WDT predefined entry shoul"
	    "d have the same values as entry #0, after ";
#else /* NO_PROTO */
    i__1[0] = 152, a__1[0] = "Each WSL requested and current view table entr\
y for which there is no corresponding WDT predefined entry should have the s\
ame values as entry #0, after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__4, a__1, i__1, &c__2, 177L);
    setmsg_("10 17", ch__4, 5L, 177L);
/*  <Inquire view representation> to determine */
/*     ent0 = set of values from WSL for index=0 */
    nqvwr (&globnu_1.wkid, &c__0, &c__1, &errind, &vwtupd, e0vom, e0vmm, 
	    e0vclm, e0cid, &e0cid[1], &e0cid[2]);
    chkinq_("pqvwr", &errind, 5L);
    i__2 = ndvi - 1;
    for (ivwdx = npvw; ivwdx <= i__2; ++ivwdx) {
/* ----- requested values */
	nqvwr (&globnu_1.wkid, &ivwdx, &c__1, &errind, &vwtupd, dfvom, dfvmm, 
		dfvclm, dfcid, &dfcid[1], &dfcid[2]);
	if (errind != 0) {
	    fail_();
	    s_wsfi(&io___34);
#ifndef NO_PROTO
	    do_fio(&c__1, "<Inquire view representation> for requested value"
		    "s failed with error = ", 71L);
#else /* NO_PROTO */
	    do_fio(&c__1, "<Inquire view representation> for requested value\
s failed with error = ", 71L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L410;
	}
/* check matrices and clip limits */
	if (! (rareq_(&c__16, dfvom, e0vom, &c_b36, &c_b36) && rareq_(&c__16, 
		dfvmm, e0vmm, &c_b36, &c_b36) && rareq_(&c__6, dfvclm, e0vclm,
		 &c_b36, &c_b36) && iareq_(&c__3, dfcid, e0cid))) {
	    fail_();
	    goto L410;
	}
/* ----- current values */
	nqvwr (&globnu_1.wkid, &ivwdx, &c__0, &errind, &vwtupd, dfvom, dfvmm, 
		dfvclm, dfcid, &dfcid[1], &dfcid[2]);
	if (errind != 0) {
	    fail_();
	    s_wsfi(&io___35);
#ifndef NO_PROTO
	    do_fio(&c__1, "<Inquire view representation> for current values "
		    "failed with error = ", 69L);
#else /* NO_PROTO */
	    do_fio(&c__1, "<Inquire view representation> for current values \
failed with error = ", 69L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L410;
	}
/* check matrices and clip limits */
	if (! (rareq_(&c__16, dfvom, e0vom, &c_b36, &c_b36) && rareq_(&c__16, 
		dfvmm, e0vmm, &c_b36, &c_b36) && rareq_(&c__6, dfvclm, e0vclm,
		 &c_b36, &c_b36) && iareq_(&c__3, dfcid, e0cid))) {
	    fail_();
	    goto L410;
	}
/* L400: */
    }
    pass_();
L410:
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 101, a__1[0] = "The view transformation update state for each "
	    "entry in the WSL view table should be NOTPENDING after ";
#else /* NO_PROTO */
    i__1[0] = 101, a__1[0] = "The view transformation update state for each \
entry in the WSL view table should be NOTPENDING after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__5, a__1, i__1, &c__2, 126L);
    setmsg_("11 24", ch__5, 5L, 126L);
    i__2 = ndvi - 1;
    for (ivwdx = 0; ivwdx <= i__2; ++ivwdx) {
	nqvwr (&globnu_1.wkid, &ivwdx, &c__1, &errind, &vwtupd, dfvom, dfvmm, 
		dfvclm, dfcid, &dfcid[1], &dfcid[2]);
	if (errind != 0) {
	    fail_();
	    s_wsfi(&io___36);
	    do_fio(&c__1, "<Inquire view representation> failed with error = "
		    , 50L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L510;
	}
	if (vwtupd != 0) {
	    fail_();
	    goto L510;
	}
/* L500: */
    }
    pass_();
L510:
/*  alter view table: */
/*    for view #1: */
/*       add 1.0 to orientation matrix, mapping matrix */
/*       new clip limits = old_limits / 2 + 0.1 */
/*       new clip indicator = reverse of old */
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &vwtupd, dfvom, dfvmm, 
	    dfvclm, dfcid, &dfcid[1], &dfcid[2]);
    chkinq_("pqvwr", &errind, 5L);
    for (row = 1; row <= 4; ++row) {
	for (col = 1; col <= 4; ++col) {
#ifndef NO_PROTO
	    dfvom[row + (col << 2) - 5] += 1.f;
	    dfvmm[row + (col << 2) - 5] += 1.f;
#else /* NO_PROTO */
	    dfvom[row + (col << 2) - 5] += (float)1.;
	    dfvmm[row + (col << 2) - 5] += (float)1.;
#endif /* NO_PROTO */
/* L610: */
	}
/* L600: */
    }
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	dfvclm[ix - 1] = dfvclm[ix - 1] / 2 + .1f;
#else /* NO_PROTO */
	dfvclm[ix - 1] = dfvclm[ix - 1] / 2 + (float).1;
#endif /* NO_PROTO */
/* L620: */
    }
    i__2 = 1 - dfcid[0];
    i__3 = 1 - dfcid[1];
    i__4 = 1 - dfcid[2];
    nsvwr3 (&globnu_1.wkid, &c__1, dfvom, dfvmm, dfvclm, &i__2, &i__3, &i__4);

/*  change order of entries in view table */
/*     make view #2 higher priority than view #0 */
    nsvtip (&globnu_1.wkid, &c__2, &c__0, &c__0);
/*  <close workstation> */
    nclwk (&globnu_1.wkid);
/* check whether to repeat */
    if (s_cmp(msgsuf, "opening workstation.", 25L, 20L) == 0) {
	s_copy(msgsuf, "re-opening workstation.", 25L, 23L);
	goto L100;
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

