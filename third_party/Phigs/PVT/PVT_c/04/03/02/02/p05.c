/* fort/04/03/02/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b52 = 0.f;
static real c_b53 = 1.f;
#else /* NO_PROTO */
static real c_b52 = (float)0.;
static real c_b53 = (float)1.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b61 = .02f;
static real c_b69 = .1f;
#else /* NO_PROTO */
static real c_b61 = (float).02;
static real c_b69 = (float).1;
#endif /* NO_PROTO */
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/05                        * */
/*  *    TEST TITLE : Colour model facilities               * */
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
    static char colabl[8*9] = "red     " "yellow  " "green   " "cyan    " 
	    "blue    " "magenta " "white   " "gray    " "black   ";
    static real rgb[27]	/* was [3][9] */ = { 1.f,0.f,0.f,1.f,1.f,0.f,0.f,1.f,
	    0.f,0.f,1.f,1.f,0.f,0.f,1.f,1.f,0.f,1.f,1.f,1.f,1.f,.5f,.5f,.5f,
	    0.f,0.f,0.f };
    static real cie[27]	/* was [3][9] */ = { .6f,.48f,1.f,.247f,.555f,1.f,
	    .007f,.542f,1.f,-2.f,-2.f,-2.f,.117f,.203f,1.f,-2.f,-2.f,-2.f,
	    .194f,.464f,1.f,.194f,.464f,.5f,-1.f,-1.f,0.f };
    static real hsv[27]	/* was [3][9] */ = { 0.f,1.f,1.f,.1667f,1.f,1.f,
	    .3333f,1.f,1.f,.5f,1.f,1.f,.6667f,1.f,1.f,.8333f,1.f,1.f,-1.f,0.f,
	    1.f,-1.f,0.f,.5f,-1.f,-1.f,0.f };
    static real hls[27]	/* was [3][9] */ = { 0.f,.5f,1.f,.1667f,.5f,1.f,
	    .3333f,.5f,1.f,.5f,.5f,1.f,.6667f,.5f,1.f,.8333f,.5f,1.f,-1.f,1.f,
	    -1.f,-1.f,.5f,0.f,-1.f,0.f,-1.f };
#else /* NO_PROTO */
    static char colabl[8*9+1] = "red     yellow  green   cyan    blue    mag\
enta white   gray    black   ";
    static real rgb[27]	/* was [3][9] */ = { (float)1.,(float)0.,(float)0.,(
	    float)1.,(float)1.,(float)0.,(float)0.,(float)1.,(float)0.,(float)
	    0.,(float)1.,(float)1.,(float)0.,(float)0.,(float)1.,(float)1.,(
	    float)0.,(float)1.,(float)1.,(float)1.,(float)1.,(float).5,(float)
	    .5,(float).5,(float)0.,(float)0.,(float)0. };
    static real cie[27]	/* was [3][9] */ = { (float).6,(float).48,(float)1.,(
	    float).247,(float).555,(float)1.,(float).007,(float).542,(float)
	    1.,(float)-2.,(float)-2.,(float)-2.,(float).117,(float).203,(
	    float)1.,(float)-2.,(float)-2.,(float)-2.,(float).194,(float).464,
	    (float)1.,(float).194,(float).464,(float).5,(float)-1.,(float)-1.,
	    (float)0. };
    static real hsv[27]	/* was [3][9] */ = { (float)0.,(float)1.,(float)1.,(
	    float).1667,(float)1.,(float)1.,(float).3333,(float)1.,(float)1.,(
	    float).5,(float)1.,(float)1.,(float).6667,(float)1.,(float)1.,(
	    float).8333,(float)1.,(float)1.,(float)-1.,(float)0.,(float)1.,(
	    float)-1.,(float)0.,(float).5,(float)-1.,(float)-1.,(float)0. };
    static real hls[27]	/* was [3][9] */ = { (float)0.,(float).5,(float)1.,(
	    float).1667,(float).5,(float)1.,(float).3333,(float).5,(float)1.,(
	    float).5,(float).5,(float)1.,(float).6667,(float).5,(float)1.,(
	    float).8333,(float).5,(float)1.,(float)-1.,(float)1.,(float)-1.,(
	    float)-1.,(float).5,(float)0.,(float)-1.,(float)0.,(float)-1. };
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    logical L__1;
    char ch__1[66];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);

#endif /* not NO_PROTO */
    /* Local variables */
    static integer i, ix, iy;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer nacm;
    static char cnam[8];
    static integer cdex;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *), pass_(void), 
	    nscr (integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqcr (), pass_(), nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2;
    static real cspec[3];
    static logical regmd[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqcmd (integer *, integer *, 
	    integer *), nscmd (integer *, integer *), inmsg_(char *, ftnlen), 
	    nclwk (integer *);
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqcmd (), nscmd (), inmsg_(), 
	    nclwk ();
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static integer defmod, incode;
    static real actcol[3];
    static logical gotdef;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *), colnam_(real *, real *, integer 
	    *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf (), colnam_();
#endif /* NO_PROTO */
    static logical errcod;
#ifndef NO_PROTO
    extern logical coleql_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical coleql_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, passct, curmod, thiscm;
    static real expcol[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    errctl_(logical *), coltrn_(integer *, char *, real *, integer *, 
	    real *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), errctl_(), coltrn_();
#endif /* NO_PROTO */
    static integer numret;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___20 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___21 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___22 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___30 = { 0, msg, 0, "(A)", 300, 1 };
    static icilist io___34 = { 0, msg, 0, "(A)", 300, 1 };


/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.03.02.02/05", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <Inquire colour model facilities> to determine */
/*  lacm = list of available colour models */
/*  in fortran: nacm   = number of available colour models */
/*              thiscm = nth available colour model */
/*  defmod = default colour model */
    nqcmdf (&specwt, &c__0, &errind, &nacm, &idum1, &defmod);
    chkinq_("pqcmdf", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("16 20", "Immediately after <open workstation>, the current colo"
	    "ur model should be the same as the default colour model.", 5L, 
	    110L);
#else /* NO_PROTO */
    setmsg_("16 20", "Immediately after <open workstation>, the current colo\
ur model should be the same as the default colour model.", 5L, 110L);
#endif /* NO_PROTO */
/* curmod = current colour model */
    nqcmd (&globnu_1.wkid, &errind, &curmod);
    chkinq_("pqcmd", &errind, 5L);
    L__1 = curmod == defmod;
    ifpf_(&L__1);
    errcod = FALSE_;
    gotdef = FALSE_;
    for (i = 1; i <= 4; ++i) {
	regmd[i - 1] = FALSE_;
/* L50: */
    }
    i__1 = nacm;
    for (i = 1; i <= i__1; ++i) {
	nqcmdf (&specwt, &i, &errind, &idum1, &thiscm, &idum2);
	if (errind != 0) {
	    errcod = TRUE_;
	    s_wsfi(&io___20);
	    do_fio(&c__1, "Got error indicator ", 20L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " while accessing colour model element #", 39L);
	    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L100;
	}
	if (thiscm >= 1 && thiscm <= 4) {
	    regmd[thiscm - 1] = TRUE_;
	}
/* check that defmod in list of colour models */
	if (thiscm == defmod) {
	    gotdef = TRUE_;
	}
L100:
	;
    }
#ifndef NO_PROTO
    setmsg_("16", "All entries in the list of available colour models should"
	    " be accessible.", 2L, 72L);
#else /* NO_PROTO */
    setmsg_("16", "All entries in the list of available colour models should\
 be accessible.", 2L, 72L);
#endif /* NO_PROTO */
    L__1 = ! errcod;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("16 18", "The default colour model should be in the list of avai"
	    "lable colour models.", 5L, 74L);
#else /* NO_PROTO */
    setmsg_("16 18", "The default colour model should be in the list of avai\
lable colour models.", 5L, 74L);
#endif /* NO_PROTO */
    ifpf_(&gotdef);
#ifndef NO_PROTO
    setmsg_("16 19", "The list of available colour models should contain the"
	    " RGB and CIELUV colour models.", 5L, 84L);
#else /* NO_PROTO */
    setmsg_("16 19", "The list of available colour models should contain the\
 RGB and CIELUV colour models.", 5L, 84L);
#endif /* NO_PROTO */
    L__1 = regmd[0] && regmd[1];
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("16 17", "All entries within the reported list of available colo"
	    "ur models should be realizable and valid.", 5L, 95L);
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    setmsg_("16 17", "All entries within the reported list of available colo\
ur models should be realizable and valid.", 5L, 95L);
    errctl_(&c__1);
#endif /* NO_PROTO */
/*  go thru list of available colour models */
    i__1 = nacm;
    for (i = 1; i <= i__1; ++i) {
	nqcmdf (&specwt, &i, &errind, &idum1, &thiscm, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
	nscmd (&globnu_1.wkid, &thiscm);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Colour model ", 13L);
	    do_fio(&c__1, (char *)&thiscm, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " rejected as invalid.", 21L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L250;
	}
/* inquire colour model to determine curmod */
	nqcmd (&globnu_1.wkid, &errind, &curmod);
	chkinq_("pqcmd", &errind, 5L);
	if (curmod != thiscm) {
	    fail_();
	    s_wsfi(&io___22);
	    do_fio(&c__1, "Colour model set as ", 20L);
	    do_fio(&c__1, (char *)&thiscm, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " but realized as ", 17L);
	    do_fio(&c__1, (char *)&curmod, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L250;
	}
/* L200: */
    }
    pass_();
L250:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  table of colour equivalents (-1 for indeterminate): */

/* entry     colour     RGB        CIE                  HSV            HLS
*/
/* -----     ------     ---        ---                  ---            --
-*/
/*   1       red        1, 0, 0    0.600,0.480,1        0, 1,1         0,.
5,1*/
/*   2       yellow     1, 1, 0    0.247,0.555,1    .1667, 1,1     .1667,.
5,1*/
/*   3       green      0, 1, 0    0.007,0.542,1    .3333, 1,1     .3333,.
5,1*/
/*   4       cyan       0, 1, 1                        .5, 1,1        .5,.
5,1*/
/*   5       blue       0, 0, 1    0.117,0.203,1    .6667, 1,1     .6667,.
5,1*/
/*   6       magenta    1, 0, 1                     .8333, 1,1     .8333,.
5,1*/
/*   7       white      1, 1, 1    0.194,0.464,1       -1, 0,1        -1,1
,-1*/
/*   8       gray      .5,.5,.5    0.194,0.464,0.5     -1, 0,.5       -1,.
5,0*/
/*   9       black      0, 0, 0   -1,   -1,    0       -1,-1,0        -1,0
,-1*/
/* *** *** *** *** ***    check CIE -> RGB  *** *** *** *** *** *** */
/* if got CIE, then do test */
    if (! regmd[1]) {
	goto L399;
    }
    passct = 0;
    for (ix = 1; ix <= 9; ++ix) {
	if (ix == 4 || ix == 6) {
	    goto L300;
	}
/*  <set colour model> CIE */
	nscmd (&globnu_1.wkid, &c__2);
/*  <set colour representation> index #1, CIE entry (ix) but changing 
-1 */
/*     to random value between 0 and 1 */
	for (iy = 1; iy <= 3; ++iy) {
#ifndef NO_PROTO
	    if (cie[iy + ix * 3 - 4] == -1.f) {
#else /* NO_PROTO */
	    if (cie[iy + ix * 3 - 4] == (float)-1.) {
#endif /* NO_PROTO */
		cspec[iy - 1] = rndrl_(&c_b52, &c_b53);
	    } else {
		cspec[iy - 1] = cie[iy + ix * 3 - 4];
	    }
	    expcol[iy - 1] = rgb[iy + ix * 3 - 4];
/* L310: */
	}
	nscr (&globnu_1.wkid, &c__1, &c__3, cspec);
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
/*  attempt to convert only realizable colors */
	if (! coleql_(&c__3, actcol, cspec, &c_b61, &c_b52)) {
	    goto L300;
	}
/*  <set colour model> RGB */
	nscmd (&globnu_1.wkid, &c__1);
/*  <inquire colour representation> #1 as SET, to determine cspec */
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__0, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
	if (numret == 3 && coleql_(&c__3, actcol, expcol, &c_b69, &c_b52)) {
	    ++passct;
	} else {
	    passct = -666;
	    s_wsfi(&io___30);
/* Writing concatenation */
#ifndef NO_PROTO
	    i__2[0] = 57, a__1[0] = "Fail to change colour model from CIE to"
		    " RGB for colour = ";
#else /* NO_PROTO */
	    i__2[0] = 57, a__1[0] = "Fail to change colour model from CIE to\
 RGB for colour = ";
#endif /* NO_PROTO */
	    i__2[1] = 8, a__1[1] = colabl + (ix - 1 << 3);
	    i__2[2] = 1, a__1[2] = ".";
	    s_cat(ch__1, a__1, i__2, &c__3, 66L);
	    do_fio(&c__1, ch__1, 66L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	}
L300:
	;
    }
    if (passct == 0) {
	inmsg_("No realizable CIE colors for CIE to RGB conversion test.", 
		56L);
    } else {
#ifndef NO_PROTO
	setmsg_("21 22 23", "Changing the colour model from CIE to RGB shoul"
		"d not affect the colours in the colour table.", 8L, 92L);
#else /* NO_PROTO */
	setmsg_("21 22 23", "Changing the colour model from CIE to RGB shoul\
d not affect the colours in the colour table.", 8L, 92L);
#endif /* NO_PROTO */
	L__1 = passct > 0;
	ifpf_(&L__1);
    }
/*  end_from_cie: */
/* L350: */
/* *** *** *** *** ***    check RGB -> CIE   *** *** *** *** *** *** */
    passct = 0;
    for (ix = 1; ix <= 9; ++ix) {
	if (ix == 4 || ix == 6) {
	    goto L360;
	}
/*  <set colour model> RGB */
	nscmd (&globnu_1.wkid, &c__1);
	for (iy = 1; iy <= 3; ++iy) {
	    cspec[iy - 1] = rgb[iy + ix * 3 - 4];
/* L370: */
	}
/*  <set colour representation> index #1, RGB entry (ix) */
	nscr (&globnu_1.wkid, &c__1, &c__3, cspec);
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
/*  attempt to convert only realizable colors */
	if (! coleql_(&c__3, actcol, cspec, &c_b61, &c_b52)) {
	    goto L360;
	}
/*  <set colour model> CIE */
	nscmd (&globnu_1.wkid, &c__2);
/*  <inquire colour representation> as SET, to determine cspec */
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__0, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
	colnam_(actcol, &actcol[1], &incode, &cdex, cnam, 8L);
	if (ix <= 7) {
	    if (s_cmp(cnam, colabl + (ix - 1 << 3), 8L, 8L) == 0 && actcol[2] 
#ifndef NO_PROTO
		    > .7f) {
#else /* NO_PROTO */
		    > (float).7) {
#endif /* NO_PROTO */
		goto L355;
	    } else {
		goto L380;
	    }
	} else if (ix == 8) {
#ifndef NO_PROTO
	    if (s_cmp(cnam, "white", 8L, 5L) == 0 && actcol[2] > .2f && 
		    actcol[2] < .8f) {
#else /* NO_PROTO */
	    if (s_cmp(cnam, "white", 8L, 5L) == 0 && actcol[2] > (float).2 && 
		    actcol[2] < (float).8) {
#endif /* NO_PROTO */
		goto L355;
	    } else {
		goto L380;
	    }
	} else if (ix == 9) {
#ifndef NO_PROTO
	    if (actcol[2] < .1f) {
#else /* NO_PROTO */
	    if (actcol[2] < (float).1) {
#endif /* NO_PROTO */
		goto L355;
	    } else {
		goto L380;
	    }
	}
L355:
	++passct;
	goto L360;
L380:
	passct = -666;
	s_wsfi(&io___34);
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 57, a__1[0] = "Fail to change colour model from RGB to CIE"
		" for colour = ";
#else /* NO_PROTO */
	i__2[0] = 57, a__1[0] = "Fail to change colour model from RGB to CIE\
 for colour = ";
#endif /* NO_PROTO */
	i__2[1] = 8, a__1[1] = colabl + (ix - 1 << 3);
	i__2[2] = 1, a__1[2] = ".";
	s_cat(ch__1, a__1, i__2, &c__3, 66L);
	do_fio(&c__1, ch__1, 66L);
	e_wsfi();
	inmsg_(msg, 300L);
L360:
	;
    }
    if (passct == 0) {
	inmsg_("No realizable RGB colors for RGB to CIE conversion test.", 
		56L);
    } else {
#ifndef NO_PROTO
	setmsg_("21 22 23", "Changing the colour model from RGB to CIE shoul"
		"d not affect the colours in the colour table.", 8L, 92L);
#else /* NO_PROTO */
	setmsg_("21 22 23", "Changing the colour model from RGB to CIE shoul\
d not affect the colours in the colour table.", 8L, 92L);
#endif /* NO_PROTO */
	L__1 = passct > 0;
	ifpf_(&L__1);
    }
/*  end_cie: */
L399:
/* *** *** *** *** ***    check HSV <-> RGB  *** *** *** *** *** *** */
/*  if got HSV, then do test, otherwise skip */
    if (! regmd[2]) {
	goto L499;
    }
    coltrn_(&globnu_1.wkid, colabl, hsv, &c__3, rgb, &c__1, "21 22 24", 8L, 
	    8L);
    coltrn_(&globnu_1.wkid, colabl, rgb, &c__1, hsv, &c__3, "21 22 24", 8L, 
	    8L);
/*  end_hsv: */
L499:
/* *** *** *** *** ***    check HLS <-> RGB  *** *** *** *** *** *** */
/* if got HLS, then do test, otherwise skip */
    if (! regmd[3]) {
	goto L599;
    }
    coltrn_(&globnu_1.wkid, colabl, hls, &c__4, rgb, &c__1, "21 22 25", 8L, 
	    8L);
    coltrn_(&globnu_1.wkid, colabl, rgb, &c__1, hls, &c__4, "21 22 25", 8L, 
	    8L);
/*  end_hls: */
L599:
    nclwk (&globnu_1.wkid);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("16 20", "Immediately after re-opening the workstation, the curr"
	    "ent colour model should be the same as the default colour model.",
	     5L, 118L);
#else /* NO_PROTO */
    setmsg_("16 20", "Immediately after re-opening the workstation, the curr\
ent colour model should be the same as the default colour model.", 5L, 118L);
#endif /* NO_PROTO */
/* curmod = current colour model */
    nqcmd (&globnu_1.wkid, &errind, &curmod);
    chkinq_("pqcmd", &errind, 5L);
    L__1 = curmod == defmod;
    ifpf_(&L__1);
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

