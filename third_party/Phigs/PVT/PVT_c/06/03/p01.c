/* fort/06/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__6 = 6;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.03/01                              * */
/*  *    TEST TITLE : Setting and inquiring the workstation * */
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
    /* System generated locals */
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer dcun;
    static real zero;
    static integer dcun2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real cuwin[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nqdsp (integer *, integer *, integer *, real *, real *
	    , integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nqdsp ();
#endif /* NO_PROTO */
    static real wkwin[6], rqwin[6];
    static integer wtupd;
    static real cuvwp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nqwkt (integer *, integer *, integer *, real *, real *, real *, 
	    real *), nswkv (integer *, real *, real *, real *, real *), 
	    nswkw (integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nqwkt (), nswkv (), nswkw ();
#endif /* NO_PROTO */
    static real wkvwp[6], rqvwp[6];
    static integer admx2x, admx2y;
    static real dcmx2x, dcmx2y;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdsp3 (integer *, integer *, integer *, real 
	    *, real *, real *, integer *, integer *, integer *), nqwkt3 (
	    integer *, integer *, integer *, real *, real *, real *, real *), 
	    nswkv3 (integer *, real *), nswkw3 (integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdsp3 (), nqwkt3 (), nswkv3 (), nswkw3 ();
#endif /* NO_PROTO */
    static logical dcinfo;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer admaxx, errind, admaxy, admaxz;
    static real dcmaxx, dcmaxy, dcmaxz;
    static integer specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* device coordinate units */
    initgl_("06.03/01", 8L);
#ifndef NO_PROTO
    zero = 0.f;
#else /* NO_PROTO */
    zero = (float)0.;
#endif /* NO_PROTO */
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire display space size 3> should report the maximum"
	    " display volume size as positive numbers in both DC and addressa"
	    "ble units.", 3L, 130L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire display space size 3> should report the maximum\
 display volume size as positive numbers in both DC and addressable units.", 
	    3L, 130L);
#endif /* NO_PROTO */
/*  <inquire display space size 3> to determine */
/*     dcun   = device coordinate units */
/*     dcmax  = maximum size in DC units */
/*     admax  = maximum size in addressable units */
    dcun = -6;
    nqdsp3 (&specwt, &errind, &dcun, &dcmaxx, &dcmaxy, &dcmaxz, &admaxx, &
	    admaxy, &admaxz);
#ifndef NO_PROTO
    dcinfo = errind == 0 && dcmaxx > 0.f && dcmaxy > 0.f && dcmaxz > 0.f && 
	    admaxx > 0 && admaxy > 0 && admaxz > 0;
#else /* NO_PROTO */
    dcinfo = errind == 0 && dcmaxx > (float)0. && dcmaxy > (float)0. && 
	    dcmaxz > (float)0. && admaxx > 0 && admaxy > 0 && admaxz > 0;
#endif /* NO_PROTO */
    ifpf_(&dcinfo);
    setmsg_("2 4", "The reported DC units should be either METRES or OTHER.", 
	    3L, 55L);
    L__1 = dcun == 0 || dcun == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 3", "<Inquire display space size> should report the same va"
	    "lues as <inquire display space size 3> for DC units and for the "
	    "first two dimensions of the display space.", 5L, 160L);
#else /* NO_PROTO */
    setmsg_("1 2 3", "<Inquire display space size> should report the same va\
lues as <inquire display space size 3> for DC units and for the first two di\
mensions of the display space.", 5L, 160L);
#endif /* NO_PROTO */
/*  <inquire display space size> to determine */
/*     dcun2  = device coordinate units */
/*     dcmx2 = maximum size in DC units */
/*     admx2 = maximum size in addressable units */
    dcun2 = -6;
    nqdsp (&specwt, &errind, &dcun2, &dcmx2x, &dcmx2y, &admx2x, &admx2y);
    chkinq_("pqdsp", &errind, 5L);
    L__1 = dcun2 == dcun && dcmx2x == dcmaxx && dcmx2y == dcmaxy && admx2x == 
	    admaxx && admx2y == admaxy;
    ifpf_(&L__1);
#ifndef NO_PROTO
    wkwin[0] = 0.f;
    wkwin[1] = 1.f;
    wkwin[2] = .2f;
    wkwin[3] = .8f;
    wkwin[4] = .1f;
    wkwin[5] = 1.f;
#else /* NO_PROTO */
    wkwin[0] = (float)0.;
    wkwin[1] = (float)1.;
    wkwin[2] = (float).2;
    wkwin[3] = (float).8;
    wkwin[4] = (float).1;
    wkwin[5] = (float)1.;
#endif /* NO_PROTO */
/*  <set workstation window 3> */
    nswkw3 (&globnu_1.wkid, wkwin);
#ifndef NO_PROTO
    setmsg_("1 6 8 12 14", "Requested workstation window should be reported "
	    "by <inquire workstation transformation 3> as most recently set b"
	    "y <set workstation window 3>.", 11L, 141L);
#else /* NO_PROTO */
    setmsg_("1 6 8 12 14", "Requested workstation window should be reported \
by <inquire workstation transformation 3> as most recently set by <set works\
tation window 3>.", 11L, 141L);
#endif /* NO_PROTO */
/* <inquire workstation transformation 3> to determine requested 3D window
:*/
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = rareq_(&c__6, rqwin, wkwin, &zero, &zero);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 6 8 13 14", "Requested workstation window should be reported "
	    "by <inquire workstation transformation> as most recently set by "
	    "<set workstation window 3>.", 11L, 139L);
#else /* NO_PROTO */
    setmsg_("1 6 8 13 14", "Requested workstation window should be reported \
by <inquire workstation transformation> as most recently set by <set worksta\
tion window 3>.", 11L, 139L);
#endif /* NO_PROTO */
/*  <inquire workstation transformation> to determine requested 2D window:
 */
    nqwkt (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = rareq_(&c__4, rqwin, wkwin, &zero, &zero);
    ifpf_(&L__1);
    if (! dcinfo) {
#ifndef NO_PROTO
	inmsg_("Skipping viewport 3 tests because DC information is unavaila"
		"ble.", 64L);
#else /* NO_PROTO */
	inmsg_("Skipping viewport 3 tests because DC information is unavaila\
ble.", 64L);
#endif /* NO_PROTO */
	goto L110;
    }
#ifndef NO_PROTO
    wkvwp[0] = dcmaxx * 0.f;
    wkvwp[1] = dcmaxx * .4f;
    wkvwp[2] = dcmaxy * .8f;
    wkvwp[3] = dcmaxy * 1.f;
    wkvwp[4] = dcmaxz * 0.f;
    wkvwp[5] = dcmaxz * .1f;
#else /* NO_PROTO */
    wkvwp[0] = dcmaxx * (float)0.;
    wkvwp[1] = dcmaxx * (float).4;
    wkvwp[2] = dcmaxy * (float).8;
    wkvwp[3] = dcmaxy * (float)1.;
    wkvwp[4] = dcmaxz * (float)0.;
    wkvwp[5] = dcmaxz * (float).1;
#endif /* NO_PROTO */
/*  <set workstation viewport 3> */
    nswkv3 (&globnu_1.wkid, wkvwp);
#ifndef NO_PROTO
    setmsg_("1 9 11 12 14", "Requested workstation viewport should be report"
	    "ed by <inquire workstation transformation 3> as most recently se"
	    "t by <set workstation viewport 3>.", 12L, 145L);
#else /* NO_PROTO */
    setmsg_("1 9 11 12 14", "Requested workstation viewport should be report\
ed by <inquire workstation transformation 3> as most recently set by <set wo\
rkstation viewport 3>.", 12L, 145L);
#endif /* NO_PROTO */
/*  <inquire workstation transformation 3> to determine requested */
/*     3D viewport: */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = rareq_(&c__6, rqvwp, wkvwp, &zero, &zero);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 9 11 13 14", "Requested workstation viewport should be report"
	    "ed by <inquire workstation transformation> as most recently set "
	    "by <set workstation viewport 3>.", 12L, 143L);
#else /* NO_PROTO */
    setmsg_("1 9 11 13 14", "Requested workstation viewport should be report\
ed by <inquire workstation transformation> as most recently set by <set work\
station viewport 3>.", 12L, 143L);
#endif /* NO_PROTO */
/*  <inquire workstation transformation> to determine requested */
/*     2D viewport: */
    nqwkt (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt", &errind, 5L);
    L__1 = rareq_(&c__4, rqvwp, wkvwp, &zero, &zero);
    ifpf_(&L__1);
/*  end_viewport_3: */
L110:
#ifndef NO_PROTO
    wkwin[0] = 0.f;
    wkwin[1] = .4f;
    wkwin[2] = .6f;
    wkwin[3] = 1.f;
#else /* NO_PROTO */
    wkwin[0] = (float)0.;
    wkwin[1] = (float).4;
    wkwin[2] = (float).6;
    wkwin[3] = (float)1.;
#endif /* NO_PROTO */
/*  <set workstation window> */
    nswkw (&globnu_1.wkid, wkwin, &wkwin[1], &wkwin[2], &wkwin[3]);
#ifndef NO_PROTO
    setmsg_("1 7 8 12 14", "Requested workstation window should be reported "
	    "by <inquire workstation transformation 3> as most recently set b"
	    "y <set workstation window>, with z-values unchanged.", 11L, 164L);

#else /* NO_PROTO */
    setmsg_("1 7 8 12 14", "Requested workstation window should be reported \
by <inquire workstation transformation 3> as most recently set by <set works\
tation window>, with z-values unchanged.", 11L, 164L);
#endif /* NO_PROTO */
/* <inquire workstation transformation 3> to determine requested 3D window
:*/
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = rareq_(&c__6, rqwin, wkwin, &zero, &zero);
    ifpf_(&L__1);
    if (! dcinfo) {
#ifndef NO_PROTO
	inmsg_("Skipping viewport tests because DC information is unavailabl"
		"e.", 62L);
#else /* NO_PROTO */
	inmsg_("Skipping viewport tests because DC information is unavailabl\
e.", 62L);
#endif /* NO_PROTO */
	goto L120;
    }
#ifndef NO_PROTO
    wkvwp[0] = dcmaxx * .8f;
    wkvwp[1] = dcmaxx * .9f;
    wkvwp[2] = dcmaxy * .1f;
    wkvwp[3] = dcmaxy * .2f;
#else /* NO_PROTO */
    wkvwp[0] = dcmaxx * (float).8;
    wkvwp[1] = dcmaxx * (float).9;
    wkvwp[2] = dcmaxy * (float).1;
    wkvwp[3] = dcmaxy * (float).2;
#endif /* NO_PROTO */
/*  <set workstation viewport> */
    nswkv (&globnu_1.wkid, wkvwp, &wkvwp[1], &wkvwp[2], &wkvwp[3]);
#ifndef NO_PROTO
    setmsg_("1 10 11 12 14", "Requested workstation viewport should be repor"
	    "ted by <inquire workstation transformation 3> as most recently s"
	    "et by <set workstation viewport>, with z-values unchanged.", 13L, 
	    168L);
#else /* NO_PROTO */
    setmsg_("1 10 11 12 14", "Requested workstation viewport should be repor\
ted by <inquire workstation transformation 3> as most recently set by <set w\
orkstation viewport>, with z-values unchanged.", 13L, 168L);
#endif /* NO_PROTO */
/*  <inquire workstation transformation 3> to determine requested */
/*     3D viewport: */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = rareq_(&c__6, rqvwp, wkvwp, &zero, &zero);
    ifpf_(&L__1);
/*  end_viewport: */
L120:
    if (! dcinfo) {
#ifndef NO_PROTO
	inmsg_("Skipping flat viewport tests because DC information is unava"
		"ilable.", 67L);
#else /* NO_PROTO */
	inmsg_("Skipping flat viewport tests because DC information is unava\
ilable.", 67L);
#endif /* NO_PROTO */
	goto L130;
    }
/*  Set up viewport with zero thickness in z-dimension */
#ifndef NO_PROTO
    wkvwp[0] = dcmaxx * 0.f;
    wkvwp[1] = dcmaxx * .4f;
    wkvwp[2] = dcmaxy * .8f;
    wkvwp[3] = dcmaxy * 1.f;
    wkvwp[4] = dcmaxz * .3f;
#else /* NO_PROTO */
    wkvwp[0] = dcmaxx * (float)0.;
    wkvwp[1] = dcmaxx * (float).4;
    wkvwp[2] = dcmaxy * (float).8;
    wkvwp[3] = dcmaxy * (float)1.;
    wkvwp[4] = dcmaxz * (float).3;
#endif /* NO_PROTO */
    wkvwp[5] = wkvwp[4];
/*  <set workstation viewport 3> */
    nswkv3 (&globnu_1.wkid, wkvwp);
#ifndef NO_PROTO
    setmsg_("1 9 11 12 14", "Requested flat workstation viewport should be r"
	    "eported by <inquire workstation transformation 3> as most recent"
	    "ly set by <set workstation viewport 3>, with unchanged window.", 
	    12L, 173L);
#else /* NO_PROTO */
    setmsg_("1 9 11 12 14", "Requested flat workstation viewport should be r\
eported by <inquire workstation transformation 3> as most recently set by <s\
et workstation viewport 3>, with unchanged window.", 12L, 173L);
#endif /* NO_PROTO */
/*  <inquire workstation transformation 3> to determine requested */
/*     3D window and viewport: */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = rareq_(&c__6, rqwin, wkwin, &zero, &zero) && rareq_(&c__6, rqvwp, 
	    wkvwp, &zero, &zero);
    ifpf_(&L__1);
/*  end_flat_viewport: */
L130:
/*  Set up window with zero thickness in z-dimension */
#ifndef NO_PROTO
    wkwin[0] = .1f;
    wkwin[1] = 1.f;
    wkwin[2] = 0.f;
    wkwin[3] = .9f;
    wkwin[4] = 0.f;
#else /* NO_PROTO */
    wkwin[0] = (float).1;
    wkwin[1] = (float)1.;
    wkwin[2] = (float)0.;
    wkwin[3] = (float).9;
    wkwin[4] = (float)0.;
#endif /* NO_PROTO */
    wkwin[5] = wkwin[4];
/*  <set workstation window 3> */
    nswkw3 (&globnu_1.wkid, wkwin);
#ifndef NO_PROTO
    setmsg_("1 6 8 12 14", "Requested flat workstation window should be repo"
	    "rted by <inquire workstation transformation 3> as most recently "
	    "set by <set workstation window 3>, with unchanged viewport.", 11L,
	     171L);
#else /* NO_PROTO */
    setmsg_("1 6 8 12 14", "Requested flat workstation window should be repo\
rted by <inquire workstation transformation 3> as most recently set by <set \
workstation window 3>, with unchanged viewport.", 11L, 171L);
#endif /* NO_PROTO */
/*  <inquire workstation transformation 3> to determine requested */
/*     3D window and viewport: */
    nqwkt3 (&globnu_1.wkid, &errind, &wtupd, rqwin, cuwin, rqvwp, cuvwp);
    chkinq_("pqwkt3", &errind, 6L);
    L__1 = rareq_(&c__6, rqwin, wkwin, &zero, &zero) && rareq_(&c__6, rqvwp, 
	    wkvwp, &zero, &zero);
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

