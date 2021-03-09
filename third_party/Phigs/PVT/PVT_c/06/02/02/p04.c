/* fort/06/02/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b20 = 0.f;
#else /* NO_PROTO */
static real c_b20 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__0 = 0;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/04                           * */
/*  *    TEST TITLE : Setting and inquiring on the WSL view * */
/*  *                 table                                 * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real exvom[16]	/* was [4][4] */ = { -5.378f,-.4014f,
	    -104.806f,-.07375f,-2.251f,.6207f,0.f,-21.465f,-7.886f,.091292f,
	    2.804f,-128.958f,30.706f,-5.423f,.08502f,-.2066f };
    static real exvmm[16]	/* was [4][4] */ = { 28.482f,-150.45f,35.318f,
	    2.4107f,106.135f,0.f,-.5466f,-5.7922f,-131.3f,0.f,84.676f,
	    -101.682f,16.022f,13.851f,.7512f,1.1572f };
    static real exvclm[6] = { .2f,.3f,.4f,.5f,.6f,.7f };
#else /* NO_PROTO */
    static real exvom[16]	/* was [4][4] */ = { (float)-5.378,(float)
	    -.4014,(float)-104.806,(float)-.07375,(float)-2.251,(float).6207,(
	    float)0.,(float)-21.465,(float)-7.886,(float).091292,(float)2.804,
	    (float)-128.958,(float)30.706,(float)-5.423,(float).08502,(float)
	    -.2066 };
    static real exvmm[16]	/* was [4][4] */ = { (float)28.482,(float)
	    -150.45,(float)35.318,(float)2.4107,(float)106.135,(float)0.,(
	    float)-.5466,(float)-5.7922,(float)-131.3,(float)0.,(float)84.676,
	    (float)-101.682,(float)16.022,(float)13.851,(float).7512,(float)
	    1.1572 };
    static real exvclm[6] = { (float).2,(float).3,(float).4,(float).5,(float)
	    .6,(float).7 };
#endif /* NO_PROTO */
    static integer exvcid[3] = { 0,1,0 };
#ifndef NO_PROTO
    static real e2vom[9]	/* was [3][3] */ = { -5.378f,-.4014f,-.07375f,
	    -2.251f,.6207f,-21.465f,30.706f,-5.423f,-.2066f };
    static real e2vmm[9]	/* was [3][3] */ = { 28.482f,-150.45f,2.4107f,
	    106.135f,0.f,-5.7922f,16.022f,13.851f,1.1572f };
    static real e2vclm[4] = { .1f,.2f,.3f,.4f };
#else /* NO_PROTO */
    static real e2vom[9]	/* was [3][3] */ = { (float)-5.378,(float)
	    -.4014,(float)-.07375,(float)-2.251,(float).6207,(float)-21.465,(
	    float)30.706,(float)-5.423,(float)-.2066 };
    static real e2vmm[9]	/* was [3][3] */ = { (float)28.482,(float)
	    -150.45,(float)2.4107,(float)106.135,(float)0.,(float)-5.7922,(
	    float)16.022,(float)13.851,(float)1.1572 };
    static real e2vclm[4] = { (float).1,(float).2,(float).3,(float).4 };
#endif /* NO_PROTO */
    static integer e2vcid = 0;

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer col;
    static char msg[300];
    static integer row;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer scol;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer srow, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int inmsg_(), nqwkc ();
#endif /* NO_PROTO */
    static real invmm[16]	/* was [4][4] */, invom[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer ivwdx, maxvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *), nsvwr (integer *, integer *, real *, real *, real *,
	     integer *), nsvwr3 (integer *, integer *, real *, real *, real *,
	     integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwr (), nsvwr (), nsvwr3 ();
#endif /* NO_PROTO */
    static integer invcid[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
    static real invclm[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), errctl_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */
    static integer vwtupd;

    /* Fortran I/O blocks */
    static icilist io___22 = { 0, msg, 0, "(A,I5,A,I5)", 300, 1 };
    static icilist io___28 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___33 = { 0, msg, 0, "(A,I5)", 300, 1 };


/* control functions that return both Current and Requested values. */
/* clipping indicator */
/*                noclip      clip */
/*  expected values for entry are: */
/*  exvom(4,4) = orientation matrix   = */
/*     | -5.378     -2.251  -7.886     30.706    | */
/*     | -0.4014    0.6207  9.1292E-02 -5.423    | */
/*     | -104.806   0.0     2.804      8.502E-02 | */
/*     | -7.375E-02 -21.465 -128.958   -0.2066   | */
/*  exvmm(4,4) = mapping matrix       = */
/*     | 28.482  106.135 -131.300 16.022 | */
/*     | -150.45 0.0     0.0      13.851 | */
/*     | 35.318  -0.5466 84.676   0.7512 | */
/*     | 2.4107  -5.7922 -101.682 1.1572 | */
/*  exvclm(6)  = view clipping limits = .2 .3 .4 .5 .6 .7 */
/*  exvcid(3)  = clipping indicators  = NOCLIP, CLIP, NOCLIP */
/*  Set/expected values for entry are: */
/*  e2vom(3,3) = orientation matrix   = */
/*     | -5.378     -2.251  30.706    | */
/*     | -0.4014    0.6207  -5.423    | */
/*     | -7.375E-02 -21.465 -0.2066   | */
/*  e2vmm(3,3) = mapping matrix       = */
/*     | 28.482  106.135 16.022 | */
/*     | -150.45 0.0     13.851 | */
/*     | 2.4107  -5.7922 1.1572 | */
/*  e2vclm(4)  = view clipping limits = .1 .2 .3 .4 */
/*  e2vcid     = x-y clipping indicator = NOCLIP */
    initgl_("06.02.02/04", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire workstation state table lengths> to determine */
/*     maxvw = maximum size of the view table */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &idum7, &maxvw);
    chkinq_("pqwksl", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("12 13", "Reported maximum size of the view table should be at l"
	    "east 6.", 5L, 61L);
#else /* NO_PROTO */
    setmsg_("12 13", "Reported maximum size of the view table should be at l\
east 6.", 5L, 61L);
#endif /* NO_PROTO */
    L__1 = maxvw > 5;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("12 14 17 23", "<Set view representation 3> should be able to se"
	    "t all requested entries, up to the maximum table size.", 11L, 
	    102L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("12 14 17 23", "<Set view representation 3> should be able to se\
t all requested entries, up to the maximum table size.", 11L, 102L);
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = maxvw - 1;
    for (ivwdx = 1; ivwdx <= i__1; ++ivwdx) {
/*        <Set view representation 3> for index #ivwdx, with entry val
ue = */
/*           exvom, exvmm, exvclm, exvcid */
	nsvwr3 (&globnu_1.wkid, &ivwdx, exvom, exvmm, exvclm, exvcid, &exvcid[
		1], &exvcid[2]);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___22);
	    do_fio(&c__1, "<Set view rep 3> for view #", 27L);
	    do_fio(&c__1, (char *)&ivwdx, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " signalled error #", 18L);
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L110;
	}
	nqvwr (&globnu_1.wkid, &ivwdx, &c__1, &errind, &vwtupd, invom, invmm, 
		invclm, invcid, &invcid[1], &invcid[2]);
	if (errind == 0 && rareq_(&c__16, invom, exvom, &c_b20, &c_b20) && 
		rareq_(&c__16, invmm, exvmm, &c_b20, &c_b20) && rareq_(&c__6, 
		invclm, exvclm, &c_b20, &c_b20) && invcid[0] == exvcid[0] && 
		invcid[1] == exvcid[1] && invcid[2] == exvcid[2]) {
/*           OK so far */
	} else {
	    fail_();
	    s_wsfi(&io___28);
	    do_fio(&c__1, "Inquire view rep for view #", 27L);
	    do_fio(&c__1, (char *)&ivwdx, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " failed to match expected values.", 33L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  exvom(4,4) = properly expanded version of e2vom */
/*  exvmm(4,4) = properly expanded version of e2vmm */
    for (row = 1; row <= 4; ++row) {
	srow = min(3,row);
	for (col = 1; col <= 4; ++col) {
	    scol = min(3,col);
	    if (row == 3 || col == 3) {
#ifndef NO_PROTO
		exvom[row + (col << 2) - 5] = 0.f;
		exvmm[row + (col << 2) - 5] = 0.f;
#else /* NO_PROTO */
		exvom[row + (col << 2) - 5] = (float)0.;
		exvmm[row + (col << 2) - 5] = (float)0.;
#endif /* NO_PROTO */
	    } else {
		exvom[row + (col << 2) - 5] = e2vom[srow + scol * 3 - 4];
		exvmm[row + (col << 2) - 5] = e2vmm[srow + scol * 3 - 4];
	    }
/* L210: */
	}
/* L200: */
    }
#ifndef NO_PROTO
    exvom[10] = 1.f;
    exvmm[10] = 1.f;
    setmsg_("15 16 17 23", "<Set view representation> should be able to re-s"
	    "et a user-defined requested entry, with correct defaults supplie"
	    "d by the implementation.", 11L, 136L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    exvom[10] = (float)1.;
    exvmm[10] = (float)1.;
    setmsg_("15 16 17 23", "<Set view representation> should be able to re-s\
et a user-defined requested entry, with correct defaults supplied by the imp\
lementation.", 11L, 136L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/*  <Set view representation> for index #1, with entry value = */
/*     e2vom, e2vmm, e2vclm, e2vcid */
    nsvwr (&globnu_1.wkid, &c__1, e2vom, e2vmm, e2vclm, &e2vcid);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    if (globnu_1.errsig != 0) {
	fail_();
	s_wsfi(&io___33);
	do_fio(&c__1, "<Set view rep> signalled error #", 32L);
	do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
	goto L666;
    }
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &vwtupd, invom, invmm, 
	    invclm, invcid, &invcid[1], &invcid[2]);
    L__1 = errind == 0 && rareq_(&c__16, invom, exvom, &c_b20, &c_b20) && 
	    rareq_(&c__16, invmm, exvmm, &c_b20, &c_b20) && rareq_(&c__4, 
#ifndef NO_PROTO
	    invclm, e2vclm, &c_b20, &c_b20) && invclm[4] == 0.f && invclm[5] 
	    == 1.f && invcid[0] == e2vcid && invcid[1] == 1 && invcid[2] == 1;

#else /* NO_PROTO */
	    invclm, e2vclm, &c_b20, &c_b20) && invclm[4] == (float)0. && 
	    invclm[5] == (float)1. && invcid[0] == e2vcid && invcid[1] == 1 &&
	     invcid[2] == 1;
#endif /* NO_PROTO */
    ifpf_(&L__1);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

