/* fort/06/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b13 = 0.f;
#else /* NO_PROTO */
static real c_b13 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.03/02                              * */
/*  *    TEST TITLE : Initialization of the workstation     * */
/*  *                 transformation                        * */
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
    static real npc[6] = { 0.f,1.f,0.f,1.f,0.f,1.f };
    static real dcmax[6] = { 0.f,0.f,0.f,0.f,0.f,0.f };
#else /* NO_PROTO */
    static real npc[6] = { (float)0.,(float)1.,(float)0.,(float)1.,(float)0.,(
	    float)1. };
    static real dcmax[6] = { (float)0.,(float)0.,(float)0.,(float)0.,(float)
	    0.,(float)0. };
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    logical L__1;
    char ch__1[111], ch__2[131], ch__3[138];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer dcun, admax[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int nclwk ();
#endif /* NO_PROTO */
    static real cuwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static real rqwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer wtupd;
    static real cuvwp[6], rqvwp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdsp3 (integer *, integer *, integer *, real 
	    *, real *, real *, integer *, integer *, integer *), nqwkt3 (
	    integer *, integer *, integer *, real *, real *, real *, real *), 
	    nswkv3 (integer *, real *), nswkw3 (integer *, real *), chkinq_(
	    char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdsp3 (), nqwkt3 (), nswkv3 (), nswkw3 (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static char msgsuf[25];
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* update state */
    initgl_("06.03/02", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(msgsuf, "opening workstation.", 25L, 20L);
/*  check_transform loop: */
L100:
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire workstation transformation 3> to determine */
/*     update state:          wtupd */
/*     requested 3D window:   rqwin */
/*     current   3D window:   cuwin */
/*     requested 3D viewport: rqvwp */
/*     current   3D viewport: cuvwp */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 86, a__1[0] = "The workstation transformation update state sho"
	    "uld be initialized to NOTPENDING after ";
#else /* NO_PROTO */
    i__1[0] = 86, a__1[0] = "The workstation transformation update state sho\
uld be initialized to NOTPENDING after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 111L);
    setmsg_("5 12", ch__1, 4L, 111L);
    L__1 = wtupd == 0;
    ifpf_(&L__1);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 106, a__1[0] = "The current and requested workstation window s"
	    "hould be initialized to [0,1] in all three dimensions after ";
#else /* NO_PROTO */
    i__1[0] = 106, a__1[0] = "The current and requested workstation window s\
hould be initialized to [0,1] in all three dimensions after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 131L);
    setmsg_("5 12", ch__2, 4L, 131L);
    L__1 = rareq_(&c__6, rqwin, npc, &c_b13, &c_b13) && rareq_(&c__6, cuwin, 
	    npc, &c_b13, &c_b13);
    ifpf_(&L__1);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 113, a__1[0] = "The current and requested workstation viewport"
	    " should be initialized to the 3D maximum display volume size aft"
	    "er ";
#else /* NO_PROTO */
    i__1[0] = 113, a__1[0] = "The current and requested workstation viewport\
 should be initialized to the 3D maximum display volume size after ";
#endif /* NO_PROTO */
    i__1[1] = 25, a__1[1] = msgsuf;
    s_cat(ch__3, a__1, i__1, &c__2, 138L);
    setmsg_("2 5 12", ch__3, 6L, 138L);
/*  <inquire display space size 3> to determine */
/*     dcmax  = maximum size in DC units */
    nqdsp3 (&specwt, &errind, &dcun, &dcmax[1], &dcmax[3], &dcmax[5], admax, &
	    admax[1], &admax[2]);
    chkinq_("pqdsp3", &errind, 6L);
    L__1 = rareq_(&c__6, rqvwp, dcmax, &c_b13, &c_b13) && rareq_(&c__6, cuvwp,
	     dcmax, &c_b13, &c_b13);
    ifpf_(&L__1);
/*  alter workstation transformation: */
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	rqwin[ix - 1] /= 2.f;
	rqvwp[ix - 1] /= 2.f;
#else /* NO_PROTO */
	rqwin[ix - 1] /= (float)2.;
	rqvwp[ix - 1] /= (float)2.;
#endif /* NO_PROTO */
/* L300: */
    }
/*  <set workstation window 3> */
    nswkw3 (&globnu_1.wkid, rqwin);
/*  <set workstation viewport 3> */
    nswkv3 (&globnu_1.wkid, rqvwp);
/*  <close workstation> */
    nclwk (&globnu_1.wkid);
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

