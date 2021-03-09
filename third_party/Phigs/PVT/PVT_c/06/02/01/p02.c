/* fort/06/02/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.01/02                           * */
/*  *    TEST TITLE : Behavior of 3D mapping                * */
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
    static real bpd, fpd, vpd, prp[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), initgl_(char *, ftnlen), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), initgl_(), setmsg_();
#endif /* NO_PROTO */
    static real vwcent[3], pjvplm[6];
    static integer pjtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), tstcor_(real *,
	     real *, integer *, real *, real *, real *, real *, real *, real *
	    ), tstprj_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), tstcor_(), tstprj_();
#endif /* NO_PROTO */
    static real vwwnlm[4], vwmpmt[16]	/* was [4][4] */;

/*  Declare program-specific variables */
/* viewtype */
    initgl_("06.02.01/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Set 3D mapping parameters for PARALLEL projection: */
#ifndef NO_PROTO
    vwwnlm[0] = -462.27f;
    vwwnlm[1] = -80.95f;
    vwwnlm[2] = -4891.85f;
    vwwnlm[3] = -94.78f;
    pjvplm[0] = .264f;
    pjvplm[1] = .4082f;
    pjvplm[2] = .01339f;
    pjvplm[3] = .7457f;
    pjvplm[4] = .1395f;
    pjvplm[5] = .30036f;
#else /* NO_PROTO */
    vwwnlm[0] = (float)-462.27;
    vwwnlm[1] = (float)-80.95;
    vwwnlm[2] = (float)-4891.85;
    vwwnlm[3] = (float)-94.78;
    pjvplm[0] = (float).264;
    pjvplm[1] = (float).4082;
    pjvplm[2] = (float).01339;
    pjvplm[3] = (float).7457;
    pjvplm[4] = (float).1395;
    pjvplm[5] = (float).30036;
#endif /* NO_PROTO */
    pjtype = 0;
#ifndef NO_PROTO
    prp[0] = -15.044f;
    prp[1] = 1.318f;
    prp[2] = 34.873f;
    vpd = -1.213f;
    bpd = -3.311f;
    fpd = 15.332f;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co"
	    "rners of the view volume to the corresponding corners of the pro"
	    "jection viewport for a PARALLEL projection.", 9L, 157L);
#else /* NO_PROTO */
    prp[0] = (float)-15.044;
    prp[1] = (float)1.318;
    prp[2] = (float)34.873;
    vpd = (float)-1.213;
    bpd = (float)-3.311;
    fpd = (float)15.332;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co\
rners of the view volume to the corresponding corners of the projection view\
port for a PARALLEL projection.", 9L, 157L);
#endif /* NO_PROTO */
/* subroutine TSTCOR performs pass/fail test */
    tstcor_(vwwnlm, pjvplm, &pjtype, prp, &vpd, &bpd, &fpd, vwmpmt, vwcent);
#ifndef NO_PROTO
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p"
	    "oints on a given projector to the same x and y values in NPC spa"
	    "ce for a PARALLEL projection.", 6L, 146L);
#else /* NO_PROTO */
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p\
oints on a given projector to the same x and y values in NPC space for a PAR\
ALLEL projection.", 6L, 146L);
#endif /* NO_PROTO */
/* subroutine TSTPRJ performs pass/fail test */
    tstprj_(prp, vwmpmt, vwcent);
/*  Set 3D mapping parameters for PERSPECTIVE projection: */
#ifndef NO_PROTO
    vwwnlm[0] = -62.2236f;
    vwwnlm[1] = -11.39577f;
    vwwnlm[2] = -60.53f;
    vwwnlm[3] = 24.255f;
    pjvplm[0] = .10639f;
    pjvplm[1] = .22243f;
    pjvplm[2] = .10012f;
    pjvplm[3] = .15392f;
    pjvplm[4] = .24695f;
    pjvplm[5] = .88262f;
#else /* NO_PROTO */
    vwwnlm[0] = (float)-62.2236;
    vwwnlm[1] = (float)-11.39577;
    vwwnlm[2] = (float)-60.53;
    vwwnlm[3] = (float)24.255;
    pjvplm[0] = (float).10639;
    pjvplm[1] = (float).22243;
    pjvplm[2] = (float).10012;
    pjvplm[3] = (float).15392;
    pjvplm[4] = (float).24695;
    pjvplm[5] = (float).88262;
#endif /* NO_PROTO */
    pjtype = 1;
#ifndef NO_PROTO
    prp[0] = -.036054f;
    prp[1] = .0021181f;
    prp[2] = 3.0569f;
    vpd = .16487f;
    bpd = -.0052858f;
    fpd = 3.0531f;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co"
	    "rners of the view volume to the corresponding corners of the pro"
	    "jection viewport for a PERSPECTIVE projection.", 9L, 160L);
#else /* NO_PROTO */
    prp[0] = (float)-.036054;
    prp[1] = (float).0021181;
    prp[2] = (float)3.0569;
    vpd = (float).16487;
    bpd = (float)-.0052858;
    fpd = (float)3.0531;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co\
rners of the view volume to the corresponding corners of the projection view\
port for a PERSPECTIVE projection.", 9L, 160L);
#endif /* NO_PROTO */
/* subroutine TSTCOR performs pass/fail test */
    tstcor_(vwwnlm, pjvplm, &pjtype, prp, &vpd, &bpd, &fpd, vwmpmt, vwcent);
#ifndef NO_PROTO
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p"
	    "oints on a given projector to the same x and y values in NPC spa"
	    "ce for a PERSPECTIVE projection.", 6L, 149L);
#else /* NO_PROTO */
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p\
oints on a given projector to the same x and y values in NPC space for a PER\
SPECTIVE projection.", 6L, 149L);
#endif /* NO_PROTO */
/* subroutine TSTPRJ performs pass/fail test */
    tstprj_(prp, vwmpmt, vwcent);
/*  Set 3D mapping parameters for PARALLEL projection, with flat */
/*  viewport (ZMIN = ZMAX): */
#ifndef NO_PROTO
    vwwnlm[0] = -2.6073f;
    vwwnlm[1] = 231.673f;
    vwwnlm[2] = 830.654f;
    vwwnlm[3] = 47407.5f;
    pjvplm[0] = .30322f;
    pjvplm[1] = .54641f;
    pjvplm[2] = .28099f;
    pjvplm[3] = .68383f;
    pjvplm[4] = .0060076f;
    pjvplm[5] = .0060076f;
#else /* NO_PROTO */
    vwwnlm[0] = (float)-2.6073;
    vwwnlm[1] = (float)231.673;
    vwwnlm[2] = (float)830.654;
    vwwnlm[3] = (float)47407.5;
    pjvplm[0] = (float).30322;
    pjvplm[1] = (float).54641;
    pjvplm[2] = (float).28099;
    pjvplm[3] = (float).68383;
    pjvplm[4] = (float).0060076;
    pjvplm[5] = (float).0060076;
#endif /* NO_PROTO */
    pjtype = 0;
#ifndef NO_PROTO
    prp[0] = 3.8497f;
    prp[1] = 72.49f;
    prp[2] = -111.363f;
    vpd = -.38069f;
    bpd = -.46296f;
    fpd = -.0425281f;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co"
	    "rners of the view volume to the corresponding corners of a flat "
	    "projection viewport for a PARALLEL projection.", 9L, 160L);
#else /* NO_PROTO */
    prp[0] = (float)3.8497;
    prp[1] = (float)72.49;
    prp[2] = (float)-111.363;
    vpd = (float)-.38069;
    bpd = (float)-.46296;
    fpd = (float)-.0425281;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co\
rners of the view volume to the corresponding corners of a flat projection v\
iewport for a PARALLEL projection.", 9L, 160L);
#endif /* NO_PROTO */
/* subroutine TSTCOR performs pass/fail test */
    tstcor_(vwwnlm, pjvplm, &pjtype, prp, &vpd, &bpd, &fpd, vwmpmt, vwcent);
#ifndef NO_PROTO
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p"
	    "oints on a given projector to the same x and y values in NPC spa"
	    "ce for a flat projection viewport and a PARALLEL projection.", 6L,
	     177L);
#else /* NO_PROTO */
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p\
oints on a given projector to the same x and y values in NPC space for a fla\
t projection viewport and a PARALLEL projection.", 6L, 177L);
#endif /* NO_PROTO */
/* subroutine TSTPRJ performs pass/fail test */
    tstprj_(prp, vwmpmt, vwcent);
/*  Set 3D mapping parameters for PERSPECTIVE projection, with a flat */
/*  viewport (ZMIN = ZMAX) and view volume (BPD = FPD): */
#ifndef NO_PROTO
    vwwnlm[0] = -13.7f;
    vwwnlm[1] = 71.55f;
    vwwnlm[2] = -51.5509f;
    vwwnlm[3] = 79.861f;
    pjvplm[0] = .1558f;
    pjvplm[1] = .537f;
    pjvplm[2] = .0017186f;
    pjvplm[3] = .3148f;
    pjvplm[4] = .7394f;
    pjvplm[5] = .7394f;
#else /* NO_PROTO */
    vwwnlm[0] = (float)-13.7;
    vwwnlm[1] = (float)71.55;
    vwwnlm[2] = (float)-51.5509;
    vwwnlm[3] = (float)79.861;
    pjvplm[0] = (float).1558;
    pjvplm[1] = (float).537;
    pjvplm[2] = (float).0017186;
    pjvplm[3] = (float).3148;
    pjvplm[4] = (float).7394;
    pjvplm[5] = (float).7394;
#endif /* NO_PROTO */
    pjtype = 1;
#ifndef NO_PROTO
    prp[0] = -1.8005f;
    prp[1] = -.0419006f;
    prp[2] = 6.3462f;
    vpd = .831f;
    bpd = -2.1753f;
    fpd = -2.1753f;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co"
	    "rners of a flat view volume to the corresponding corners of a fl"
	    "at projection viewport for a PERSPECTIVE projection.", 9L, 166L);
#else /* NO_PROTO */
    prp[0] = (float)-1.8005;
    prp[1] = (float)-.0419006;
    prp[2] = (float)6.3462;
    vpd = (float).831;
    bpd = (float)-2.1753;
    fpd = (float)-2.1753;
    setmsg_("1 2 7 8 9", "<Evaluate view mapping matrix 3> should map the co\
rners of a flat view volume to the corresponding corners of a flat projectio\
n viewport for a PERSPECTIVE projection.", 9L, 166L);
#endif /* NO_PROTO */
/* subroutine TSTCOR performs pass/fail test */
    tstcor_(vwwnlm, pjvplm, &pjtype, prp, &vpd, &bpd, &fpd, vwmpmt, vwcent);
#ifndef NO_PROTO
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p"
	    "oints on a given projector to the same x and y values in NPC spa"
	    "ce for a flat view volume, a flat projection viewport, and a PER"
	    "SPECTIVE projection.", 6L, 201L);
#else /* NO_PROTO */
    setmsg_("1 2 10", "<Evaluate view mapping matrix 3> should map any two p\
oints on a given projector to the same x and y values in NPC space for a fla\
t view volume, a flat projection viewport, and a PERSPECTIVE projection.", 6L,
	     201L);
#endif /* NO_PROTO */
/* subroutine TSTPRJ performs pass/fail test */
    tstprj_(prp, vwmpmt, vwcent);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

