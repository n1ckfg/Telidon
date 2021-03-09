/* fort/05/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__101 = 101;
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b42 = .1f;
static real c_b43 = .15f;
static real c_b44 = .5f;
#else /* NO_PROTO */
static real c_b42 = (float).1;
static real c_b43 = (float).15;
static real c_b44 = (float).5;
#endif /* NO_PROTO */
static integer c__201 = 201;
static integer c__400 = 400;
static integer c__401 = 401;
static integer c__402 = 402;
static integer c__50 = 50;
#ifndef NO_PROTO
static real c_b134 = 1.f;
#else /* NO_PROTO */
static real c_b134 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 05.02/setpcl                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setpcl_(char *pcctab, ftnlen pcctab_len)
#else /* NO_PROTO */
/* Subroutine */ int setpcl_(pcctab, pcctab_len)
char *pcctab;
ftnlen pcctab_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

/*  SETPCL: loads the pcctab table with the names of the picture */
/*  change categories. */
    /* Parameter adjustments */
    pcctab -= 34;

    /* Function Body */
    s_copy(pcctab + 34, "polyline bundle representation", 34L, 30L);
    s_copy(pcctab + 68, "polymarker bundle representation", 34L, 32L);
    s_copy(pcctab + 102, "text bundle representation", 34L, 26L);
    s_copy(pcctab + 136, "interior bundle representation", 34L, 30L);
    s_copy(pcctab + 170, "edge bundle representation", 34L, 26L);
    s_copy(pcctab + 204, "pattern representation", 34L, 22L);
    s_copy(pcctab + 238, "colour representation", 34L, 21L);
    s_copy(pcctab + 272, "view representation", 34L, 19L);
    s_copy(pcctab + 306, "workstation transformation", 34L, 26L);
    s_copy(pcctab + 340, "highlighting filter", 34L, 19L);
    s_copy(pcctab + 374, "invisibility filter", 34L, 19L);
    s_copy(pcctab + 408, "HLHSR mode", 34L, 10L);
    s_copy(pcctab + 442, "structure content", 34L, 17L);
    s_copy(pcctab + 476, "post structure", 34L, 14L);
    s_copy(pcctab + 510, "unpost structure", 34L, 16L);
    s_copy(pcctab + 544, "delete structure", 34L, 16L);
    s_copy(pcctab + 578, "reference modification", 34L, 22L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setpcl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 05.02/setsvr                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setsvr_(integer *wkid, integer *reqsvr)
#else /* NO_PROTO */
/* Subroutine */ int setsvr_(wkid, reqsvr)
integer *wkid, *reqsvr;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nrst (integer *, integer *), nsdus (integer *,
	     integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nrst (), nsdus ();
#endif /* NO_PROTO */
    static integer actpcc;
#ifndef NO_PROTO
    extern /* Subroutine */ int picchg_(integer *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int picchg_();
#endif /* NO_PROTO */
    static integer actsev;

/*  SETSVR: attempts to set the SVR of the specified workstation */
/*  to requested state.  There is no error report; the caller must */
/*  determine success. */
/* deferral mode */
/* modification mode */
/* dynamic modification */
/* clear control flag */
/*                conditionally  always */
/* state of visual representation */
/*                correct    deferred    simulated */
    nsdus (wkid, &c__4, &c__2);
/* make SVR correct */
    nrst (wkid, &c__0);
    if (*reqsvr == 1) {
/*  attempt IRG-type picture change */
	picchg_(wkid, "0", "13,14,15,16,17,9,8,1,2,3,4,5,6,7,10,11,12", &
		actsev, &actpcc, 1L, 41L);
    } else if (*reqsvr == 2) {
/*  attempt CBS-type picture change */
	picchg_(wkid, "2", "13,14,15,16,17,9,8,1,2,3,4,5,6,7,10,11,12", &
		actsev, &actpcc, 1L, 41L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setsvr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 05.02/surfok                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical surfok_(integer *wkid, integer *expsur)
#else /* NO_PROTO */
logical surfok_(wkid, expsur)
integer *wkid, *expsur;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdus (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, actsur;

/*  SURFOK: true iff display surface flag equals expected value. */
    nqdus (wkid, &errind, &idum1, &idum2, &actsur, &idum3);
    chkinq_("pqdus", &errind, 5L);
    ret_val = actsur == *expsur;
    return ret_val;
} /* surfok_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 05.02/svrok                       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical svrok_(integer *wkid, char *expvls, ftnlen expvls_len)
#else /* NO_PROTO */
logical svrok_(wkid, expvls, expvls_len)
integer *wkid;
char *expvls;
ftnlen expvls_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char svrcod[1*3] = "c" "d" "s";
#else /* NO_PROTO */
    static char svrcod[1*3+1] = "cds";
#endif /* NO_PROTO */

    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdus (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, actsvr;

/*  SVROK: true iff current SVR is one of the expected values, */
/*  encoded by character: c-correct, s-simulated, d-deferred. */
/*  E.g. expvls = 'cd' means SVR must be either CORRECT or */
/*  DEFERRED. */
/* state of visual representation */
/*                correct    deferred    simulated */
    nqdus (wkid, &errind, &idum1, &idum2, &idum3, &actsvr);
    chkinq_("pqdus", &errind, 5L);
    ret_val = i_indx(expvls, svrcod + actsvr, expvls_len, 1L) > 0;
    return ret_val;
} /* svrok_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 05.02/picenv                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int picenv_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int picenv_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real vclip[4] = { 0.f,1.f,0.f,1.f };
    static real plx[2] = { .3f,.7f };
    static real pmx[1] = { .08f };
    static real ply[2] = { .7f,.3f };
    static real pmy[1] = { .08f };
    static real fasx[6] = { .1f,.2f,.3f,.7f,.8f,.9f };
    static real fasy[6] = { .1f,.3f,.1f,.9f,.7f,.9f };
#else /* NO_PROTO */
    static real vclip[4] = { (float)0.,(float)1.,(float)0.,(float)1. };
    static real plx[2] = { (float).3,(float).7 };
    static real pmx[1] = { (float).08 };
    static real ply[2] = { (float).7,(float).3 };
    static real pmy[1] = { (float).08 };
    static real fasx[6] = { (float).1,(float).2,(float).3,(float).7,(float).8,
	    (float).9 };
    static real fasy[6] = { (float).1,(float).3,(float).1,(float).9,(float).7,
	    (float).9 };
#endif /* NO_PROTO */
    static integer endpts[2] = { 3,6 };

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal), sqrt(doublereal);
#else /* NO_PROTO */
    double cos(), sin(), sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static real ang;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *), ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm (), ntx ();
#endif /* NO_PROTO */
    static integer lim2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void), nads (integer *, integer *), 
	    nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas (), nads (), nfas ();
#endif /* NO_PROTO */
    static real imat[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nres (integer *, integer *), idmat_(integer *,
	     real *), nschh (real *), nclst (void), nexst (integer *), nopst (
	    integer *), npost (integer *, integer *, real *), nsvwi (integer *
	    ), nsvwr (integer *, integer *, real *, real *, real *, integer *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nres (), idmat_(), nschh (), nclst (), nexst (
	    ), nopst (), npost (), nsvwi (), nsvwr ();
#endif /* NO_PROTO */
    static integer namset[5], attrib;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf ();
#endif /* NO_PROTO */

/*  PICENV: sets up an environment of posted structures to the */
/*  specified workstation, so that PICCHG can be perform requested */
/*  changes. */
/*  Structure Conventions: */

/*  #101 is posted and contains a polyline, polymarker, text, */
/*       fill-area-set to exercise primitive representation changes */
/*       (PCC 1-7). */

/*  #201 is posted with lines fanning out from the bottom, */
/*       available for element deletion (PCC 13). */

/*  #301-350 are posted each with line fanning out from the top, */
/*       available for unposting or structure deletion (PCC 15-16) */

/*  #400,401,402 is a small network, with 400 executing either 401 or */
/*       402, available for <change structure references> (PCC 17). */
/*       401 has a 60-deg line, 402 a 150-deg line. */

/*  PCC 8-12, 14 require no additional environment.  PCC 14 will post */
/*  a new structure 5xx, with vertical lines. */
/* aspect source */
/*                bundled     individual */
/* clipping indicator */
/*                noclip      clip */
/* first, clear the decks */
    ndas ();
/* set up 101 with bundled primitives */
    nopst (&c__101);
    for (attrib = 0; attrib <= 17; ++attrib) {
	nsiasf (&attrib, &c__0);
/* L100: */
    }
/* use entry #1 in all bundles. This is the default, except for view, */
/* which must be set explicitly. */
    nsvwi (&c__1);
    idmat_(&c__3, imat);
/* set up view #1 like default */
    nsvwr (wkid, &c__1, imat, imat, vclip, &c__1);
    npl (&c__2, plx, ply);
    npm (&c__1, pmx, pmy);
/* potential highlight: filter = [1] */
    namset[0] = 1;
    nads (&c__1, namset);
    nschh (&c_b42);
    ntx (&c_b43, &c_b44, "?", 1L);
/* potential invisibility: filter = [2] */
    nres (&c__1, namset);
    namset[0] = 2;
    nads (&c__1, namset);
    nfas (&c__2, endpts, fasx, fasy);
    nres (&c__1, namset);
    nclst ();
    npost (wkid, &c__101, &c_b44);
/* set up 201, posted, with lines fanning out from the bottom */
    nopst (&c__201);
#ifndef NO_PROTO
    plx[0] = .5f;
    ply[0] = 0.f;
#else /* NO_PROTO */
    plx[0] = (float).5;
    ply[0] = (float)0.;
#endif /* NO_PROTO */
    lim2 = 50;
    i__1 = lim2 - 1;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ang = ix * 3.14159265f / lim2;
	plx[1] = plx[0] + cos(ang) * .3f;
	ply[1] = ply[0] + sin(ang) * .3f;
#else /* NO_PROTO */
	ang = ix * (float)3.14159265 / lim2;
	plx[1] = plx[0] + cos(ang) * (float).3;
	ply[1] = ply[0] + sin(ang) * (float).3;
#endif /* NO_PROTO */
	npl (&c__2, plx, ply);
/* L200: */
    }
    nclst ();
    npost (wkid, &c__201, &c_b44);
/*  set up 301-350, posted, each with line fanning out from the top */
#ifndef NO_PROTO
    plx[0] = .5f;
    ply[0] = 1.f;
#else /* NO_PROTO */
    plx[0] = (float).5;
    ply[0] = (float)1.;
#endif /* NO_PROTO */
    lim2 = 50;
    i__1 = lim2;
    for (ix = 1; ix <= i__1; ++ix) {
	i__2 = ix + 300;
	nopst (&i__2);
#ifndef NO_PROTO
	ang = ix * 3.14159265f / lim2;
	plx[1] = plx[0] + cos(ang) * .3f;
	ply[1] = ply[0] - sin(ang) * .3f;
#else /* NO_PROTO */
	ang = ix * (float)3.14159265 / lim2;
	plx[1] = plx[0] + cos(ang) * (float).3;
	ply[1] = ply[0] - sin(ang) * (float).3;
#endif /* NO_PROTO */
	npl (&c__2, plx, ply);
	nclst ();
	i__2 = ix + 300;
	npost (wkid, &i__2, &c_b44);
/* L300: */
    }
/*  set up 400,401,402 as a small posted network, with 400 */
/*  executing either 401 or 402.  401 has a 60-deg line, 402 a */
/*  150-deg line. */
    nopst (&c__400);
    nexst (&c__401);
    nclst ();
    npost (wkid, &c__400, &c_b44);
#ifndef NO_PROTO
    plx[0] = .5f;
    ply[0] = sqrt(.75f);
    ply[1] = 0.f;
#else /* NO_PROTO */
    plx[0] = (float).5;
    ply[0] = sqrt((float).75);
    ply[1] = (float)0.;
#endif /* NO_PROTO */
    nopst (&c__401);
#ifndef NO_PROTO
    plx[1] = 0.f;
#else /* NO_PROTO */
    plx[1] = (float)0.;
#endif /* NO_PROTO */
    npl (&c__2, plx, ply);
    nclst ();
    nopst (&c__402);
#ifndef NO_PROTO
    plx[1] = 1.f;
#else /* NO_PROTO */
    plx[1] = (float)1.;
#endif /* NO_PROTO */
    npl (&c__2, plx, ply);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* picenv_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 05.02/picchg                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int picchg_(integer *wkid, char *sevlst, char *pcclst, 
	integer *actsev, integer *actpcc, ftnlen sevlst_len, ftnlen 
	pcclst_len)
#else /* NO_PROTO */
/* Subroutine */ int picchg_(wkid, sevlst, pcclst, actsev, actpcc, sevlst_len,
	 pcclst_len)
integer *wkid;
char *sevlst, *pcclst;
integer *actsev, *actpcc;
ftnlen sevlst_len;
ftnlen pcclst_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer postct = 1;
    static integer killct = 1;
    static integer oldstr = 401;
    static integer pccsev[17] = { 666,666,666,666,666,666,666,666,666,666,666,
	    666,666,666,666,666,666 };

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double r_mod(real *, real *);
    integer pow_ii(integer *, integer *);
#else /* NO_PROTO */
    double r_mod();
    integer pow_ii();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ii, ix;
    static real px[10], py[10];
    static integer pdx, pdy;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ndel (void), 
	    nqif (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqcr (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *), 
	    nscr (integer *, integer *, integer *, real *), ndst (integer *), 
	    nqir (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ndel (), nqif (), nqcr (), nscr (), 
	    ndst (), nqir (), nsir ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum4[16]	/* was [4][4] */, rdum5[16]	/* 
	    was [4][4] */, rdum6[6];
    static integer colia[2500]	/* was [50][50] */, fclip;
    static real cspec[3];
    static integer pccdx;
    static real chexp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedr (), nsedr ();
#endif /* NO_PROTO */
    static integer inset[50];
    static logical nopat;
    static integer sevdx, exset[50], insiz, ltype, mtype;
    static real curvp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer exsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nqplr (integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *), nsplr (integer *, integer *, integer *, real *
	    , integer *), nqpmr (integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), nspmr (integer *, integer *, 
	    integer *, real *, integer *), nqpar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nqhrm (
	    integer *, integer *, integer *, integer *, integer *), nqtxr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), nqvwr (integer *, integer *, integer *
	    , integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *), nstxr (integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), nshrm (integer *, integer *
	    ), nopst (integer *), nclst (void), npost (integer *, integer *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_(), nqplr (), nsplr (), nqpmr (), 
	    nspmr (), nqpar (), nspar (), nqhrm (), nqtxr (), nqvwr (), 
	    nstxr (), nshrm (), nopst (), nclst (), npost ();
#endif /* NO_PROTO */
    static real radum1[6], radum2[6], radum3[6];
    static integer edflag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkt3 (integer *, integer *, integer *, real 
	    *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkt3 ();
#endif /* NO_PROTO */
    static integer pcccod[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nswkv3 (integer *, real *), nsvwr3 (integer *,
	     integer *, real *, real *, real *, integer *, integer *, integer 
	    *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nswkv3 (), nsvwr3 (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, specwt, sevcod[10], pccsiz, naints, thisis,
	     istyle, numret, curmod, sevsiz, numode, newmod, newstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdswa (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nqdstr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nqhlft (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nshlft (integer *, 
	    integer *, integer *, integer *, integer *), nqivft (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nsivft (integer *, integer *, integer *, integer *, 
	    integer *), nqhrmf (integer *, integer *, integer *, integer *, 
	    integer *), nupost (integer *, integer *), ncstrf (integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdswa (), nqdstr (), nqhlft (), nshlft (), 
	    nqivft (), nsivft (), nqhrmf (), nupost (), ncstrf ();
#endif /* NO_PROTO */

/*  PICCHG: attempts to perform a visual change according to the */
/*  preferred order of the requested severity-list and of the */
/*  specified categories (a subset of the 17 kinds of picture */
/*  change).  It then returns the actual severity and actual picture */
/*  change category performed, or indicates that nothing in the */
/*  severity-list / pcc-list combination could be done. */
/*  --- Input Parameters: */
/*  wkid    : Identifier of workstation for picture change */
/*  sevlst  : List of severity codes in preferred order, */
/*            string format.  E.g. '0,2' means first try IRG, */
/*            then CBS. */
/*  pcclst  : List of picture change categories in preferred */
/*            order (within a given severity code), string format. */
/*            E.g. '2,3' means first try polymarker bundle change, */
/*            then text bundle change. */

/*  --- Output Parameters: */
/*  actsev  : Severity code of actual change; 0 if nothing done. */
/*  actpcc  : Picture change category code of actual change; 0 if */
/*            nothing done. */
/* attribute identifier */
/* aspect source */
/*                bundled     individual */
/* clipping indicator */
/*                noclip      clip */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* type of returned value */
/* linetype */
/* marker type */
/* polyline/fill area control flag */
/* dynamic modification */
/* Current and Requested values. */
/* size of pattern-aray */
/*  postct keeps track of new structure to be posted */
/*  killct keeps track of old structures to be deleted or unposted */
/*  which structure is currently referenced? */
/*  Category codes: */

/*  01 : polyline bundle representation */
/*  02 : polymarker bundle representation */
/*  03 : text bundle representation */
/*  04 : interior bundle representation */
/*  05 : edge bundle representation */
/*  06 : pattern representation */
/*  07 : colour representation */
/*  08 : view representation */
/*  09 : workstation transformation */
/*  10 : highlighting filter */
/*  11 : invisibility filter */
/*  12 : HLHSR mode */
/*  13 : structure content */
/*  14 : post structure */
/*  15 : unpost structure */
/*  16 : delete structure */
/*  17 : reference modification */
/*  convert lists to numeric */
    setvs_(sevlst, sevcod, &sevsiz, sevlst_len);
    setvs_(pcclst, pcccod, &pccsiz, pcclst_len);
/*  specific workstation type from wkid */
    nqwkc (wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  get actual severity codes */
    nqdswa (&specwt, &errind, pccsev, &pccsev[1], &pccsev[2], &pccsev[3], &
	    pccsev[4], &pccsev[5], &pccsev[6], &pccsev[7], &pccsev[8], &
	    pccsev[9], &pccsev[10], &pccsev[11]);
    chkinq_("pqdswa", &errind, 6L);
    nqdstr (&specwt, &errind, &pccsev[12], &pccsev[13], &pccsev[14], &pccsev[
	    15], &pccsev[16]);
    chkinq_("pqdstr", &errind, 6L);
/*  determine pattern availability */
/*     nopat = no pattern interior style available */
    nopat = FALSE_;
    nqif (&specwt, &c__0, &c__0, &errind, &naints, &idum1, &idum2, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
/* loop thru list of available interior styles till find PPATTR */
    i__1 = naints;
    for (ii = 1; ii <= i__1; ++ii) {
	nqif (&specwt, &ii, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis == 2) {
	    goto L25;
	}
/* L20: */
    }
    nopat = TRUE_;
L25:
/*  run through all eligible severities and change-categories */
    i__1 = sevsiz;
    for (sevdx = 1; sevdx <= i__1; ++sevdx) {
	*actsev = sevcod[sevdx - 1];
	i__2 = pccsiz;
	for (pccdx = 1; pccdx <= i__2; ++pccdx) {
	    *actpcc = pcccod[pccdx - 1];
	    if (pccsev[*actpcc - 1] == *actsev) {
		if (*actpcc == 6 && nopat) {
/*                 do nothing - pattern requested but unav
ailable */
		} else {
		    goto L1000;
		}
	    }
/* L110: */
	}
/* L100: */
    }
/*  failed to find available combination */
    *actsev = 0;
    *actpcc = 0;
    return 0;
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  got performable picture change category = actpcc */
L1000:
#ifndef NO_PROTO
    switch (*actpcc) {
#else /* NO_PROTO */
    switch ((int)*actpcc) {
#endif /* NO_PROTO */
	case 1:  goto L2010;
	case 2:  goto L2020;
	case 3:  goto L2030;
	case 4:  goto L2040;
	case 5:  goto L2050;
	case 6:  goto L2060;
	case 7:  goto L2070;
	case 8:  goto L2080;
	case 9:  goto L2090;
	case 10:  goto L2100;
	case 11:  goto L2110;
	case 12:  goto L2120;
	case 13:  goto L2130;
	case 14:  goto L2140;
	case 15:  goto L2150;
	case 16:  goto L2160;
	case 17:  goto L2170;
    }
/*  01:polyline bundle representation */
L2010:
    nqplr (wkid, &c__1, &c__0, &errind, &ltype, &rdum1, &idum1);
    chkinq_("pqplr", &errind, 5L);
    ltype = ltype % 4 + 1;
    nsplr (wkid, &c__1, &ltype, &rdum1, &idum1);
    goto L3000;
/*  02:polymarker bundle representation */
L2020:
    nqpmr (wkid, &c__1, &c__0, &errind, &mtype, &rdum1, &idum1);
    chkinq_("pqpmr", &errind, 5L);
    mtype = mtype % 5 + 1;
    nspmr (wkid, &c__1, &mtype, &rdum1, &idum1);
    goto L3000;
/*  03:text bundle representation */
L2030:
    nqtxr (wkid, &c__1, &c__0, &errind, &idum1, &idum2, &chexp, &rdum1, &
	    idum3);
    chkinq_("pqtxr", &errind, 5L);
#ifndef NO_PROTO
    chexp *= 1.05f;
#else /* NO_PROTO */
    chexp *= (float)1.05;
#endif /* NO_PROTO */
    nstxr (wkid, &c__1, &idum1, &idum2, &chexp, &rdum1, &idum3);
    goto L3000;
/*  04:interior bundle representation */
L2040:
    nqir (wkid, &c__1, &c__0, &errind, &istyle, &idum1, &idum2);
    chkinq_("pqir", &errind, 4L);
/* these two styles are mandatory */
    if (istyle == 0) {
	istyle = 4;
    } else {
	istyle = 0;
    }
    nsir (wkid, &c__1, &istyle, &idum1, &idum2);
    goto L3000;
/*  05:edge bundle representation */
L2050:
    nqedr (wkid, &c__1, &c__0, &errind, &edflag, &idum1, &rdum1, &idum2);
    chkinq_("pqedr", &errind, 5L);
    edflag = 1 - edflag;
    nsedr (wkid, &c__1, &edflag, &idum1, &rdum1, &idum2);
    goto L3000;
/*  06:pattern representation */
L2060:
    nqpar (wkid, &c__1, &c__0, &c__50, &c__50, &errind, &pdx, &pdy, colia);
    chkinq_("pqpar", &errind, 5L);
    if (colia[0] == 0) {
	colia[0] = 1;
    } else {
	colia[0] = 0;
    }
    nspar (wkid, &c__1, &c__50, &c__50, &c__1, &c__1, &pdx, &pdy, colia);
    goto L3000;
/*  07:colour representation */
L2070:
    nqcr (wkid, &c__1, &c__3, &c__0, &errind, &numret, cspec);
    chkinq_("pqcr", &errind, 4L);
#ifndef NO_PROTO
    r__1 = cspec[numret - 1] + .5f;
#else /* NO_PROTO */
    r__1 = cspec[numret - 1] + (float).5;
#endif /* NO_PROTO */
    cspec[numret - 1] = r_mod(&r__1, &c_b134);
    nscr (wkid, &c__1, &numret, cspec);
    goto L3000;
/*  08:view representation */
L2080:
    nqvwr (wkid, &c__1, &c__0, &errind, &idum1, rdum4, rdum5, rdum6, &idum2, &
	    idum3, &fclip);
    chkinq_("pqvwr", &errind, 5L);
    fclip = 1 - fclip;
    nsvwr3 (wkid, &c__1, rdum4, rdum5, rdum6, &idum2, &idum3, &fclip);
    goto L3000;
/*  09:workstation transformation */
L2090:
    nqwkt3 (wkid, &errind, &idum1, radum1, radum2, radum3, curvp);
    chkinq_("pqwkt3", &errind, 6L);
/* shrink y-dim of viewport slightly */
#ifndef NO_PROTO
    curvp[3] = (curvp[3] - curvp[2]) * .99f + curvp[2];
#else /* NO_PROTO */
    curvp[3] = (curvp[3] - curvp[2]) * (float).99 + curvp[2];
#endif /* NO_PROTO */
    nswkv3 (wkid, curvp);
    goto L3000;
/*  10:highlighting filter */
L2100:
    nqhlft (wkid, &c__50, &c__50, &errind, &insiz, inset, &exsiz, exset);
    chkinq_("pqhlft", &errind, 6L);
    exsiz = 0;
    if (insiz == 0) {
	insiz = 1;
	inset[0] = 1;
    } else {
	insiz = 0;
    }
    nshlft (wkid, &insiz, inset, &exsiz, exset);
    goto L3000;
/*  11:invisibility filter */
L2110:
    nqivft (wkid, &c__50, &c__50, &errind, &insiz, inset, &exsiz, exset);
    chkinq_("pqivft", &errind, 6L);
    exsiz = 0;
    if (insiz == 0) {
	insiz = 1;
	inset[0] = 2;
    } else {
	insiz = 0;
    }
    nsivft (wkid, &insiz, inset, &exsiz, exset);
    goto L3000;
/*  12:HLHSR mode */
L2120:
    nqhrm (wkid, &errind, &idum1, &curmod, &idum2);
    chkinq_("pqhrm", &errind, 5L);
    nqhrmf (&specwt, &c__0, &errind, &numode, &idum3);
    chkinq_("pqhrmf", &errind, 6L);
/* look for different, valid mode */
    i__1 = numode;
    for (ix = 1; ix <= i__1; ++ix) {
	nqhrmf (&specwt, &ix, &errind, &idum3, &newmod);
	chkinq_("pqhrmf", &errind, 6L);
	if (newmod != curmod) {
	    goto L2127;
	}
/* L2125: */
    }
    newmod = curmod;
L2127:
    nshrm (wkid, &newmod);
    goto L3000;
/*  13:structure content */
L2130:
/* delete last element of 201 */
    nopst (&c__201);
    ndel ();
    nclst ();
    goto L3000;
/*  14:post structure */
L2140:
/*  PCC 14 posts a new structure 5xx, with vertical lines. */
    i__1 = postct + 500;
    npost (wkid, &i__1, &c_b44);
#ifndef NO_PROTO
    py[0] = .4f;
    py[1] = .6f;
    px[0] = 1.f / pow_ii(&c__2, &postct);
#else /* NO_PROTO */
    py[0] = (float).4;
    py[1] = (float).6;
    px[0] = (float)1. / pow_ii(&c__2, &postct);
#endif /* NO_PROTO */
    px[1] = px[0];
    i__1 = postct + 500;
    nopst (&i__1);
    npl (&c__2, px, py);
    nclst ();
    ++postct;
    goto L3000;
/*  15:unpost structure */
L2150:
    i__1 = killct + 300;
    nupost (wkid, &i__1);
    ++killct;
    goto L3000;
/*  16:delete structure */
L2160:
    i__1 = killct + 300;
    ndst (&i__1);
    ++killct;
    goto L3000;
/*  17:reference modification */
L2170:
/* alternate between 401 and 402 */
    newstr = 803 - oldstr;
    ncstrf (&oldstr, &newstr);
    oldstr = newstr;
    goto L3000;
L3000:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* picchg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 05.02/exsvrs                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int exsvrs_(integer *sevrty, integer *defmod, integer *modmd,
	 integer *oldsvr, char *svrlst, char *explbl, ftnlen svrlst_len, 
	ftnlen explbl_len)
#else /* NO_PROTO */
/* Subroutine */ int exsvrs_(sevrty, defmod, modmd, oldsvr, svrlst, explbl, 
	svrlst_len, explbl_len)
integer *sevrty, *defmod, *modmd, *oldsvr;
char *svrlst, *explbl;
ftnlen svrlst_len;
ftnlen explbl_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char svrlab[10*3] = "CORRECT   " "DEFERRED  " "SIMULATED ";
#else /* NO_PROTO */
    static char svrlab[10*3+1] = "CORRECT   DEFERRED  SIMULATED ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static logical nonf;
    static integer svrx;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static logical svrst[3];
    static integer nxtpos;

/* EXSVRS returns a string that represents the expected state(s) of visual
*/
/* representation.  It contains c, d, and/or s to indicate that the allowe
d*/
/*  state(s) are correct, deferred, or simulated, respectively.  It also 
*/
/*  returns a English label to describe the states.  This function applies
 */
/*  only to defer mode WAIT, PBNIL, PBNIG, and ASTI. */
/*  Input parameters: */
/*   SEVRTY : severity code for the category of picture change (IRG,IMM,CB
S)*/
/*    DEFMOD : deferral mode (WAIT,ASTI,BNIL,BNIG) */
/*    MODMD  : modification mode (UWOR,UQUM) */
/*    OLDSVR : original state of visual representation (CORRECT, DEFERRED,
 */
/*             SIMULATED) */
/*  Output parameters: */
/*    SVRLST : 3-character code, containing some combination of c,d,s for 
*/
/*             CORRECT, DEFERRED, SIMULATED */
/*    EXPLBL : English label corresponding to SVRLST */
/* deferral mode */
/* modification mode */
/* dynamic modification */
/* state of visual representation */
/*                correct    deferred    simulated */
    if (*defmod < 1 || *defmod > 4) {
	unmsg_("Illegal deferral mode passed to EXSVRS.", 39L);
    }
    if (*modmd == 1 || *modmd == 2) {
/*        OK */
    } else {
	unmsg_("Illegal modification mode passed to EXSVRS.", 43L);
    }
    if (*oldsvr == 0 || *oldsvr == 1 || *oldsvr == 2) {
/*        OK */
    } else {
	unmsg_("Illegal SVR passed to EXSVRS.", 29L);
    }
/*  so much for validity checking - now compute expected state(s) */
    svrst[0] = FALSE_;
    svrst[1] = FALSE_;
    svrst[2] = FALSE_;
    svrst[*oldsvr] = TRUE_;
    if (*sevrty == 1) {
/*        OK as is */
    } else if (*sevrty == 0) {
	svrst[1] = TRUE_;
	if (*modmd == 2 && *oldsvr == 0) {
	    svrst[2] = TRUE_;
	}
    } else if (*sevrty == 2) {
	if (*modmd == 2) {
	    if (*oldsvr == 0) {
		svrst[2] = TRUE_;
	    }
	} else {
/*           MODMD.EQ.PUWOR */
	    svrst[1] = TRUE_;
	}
    } else {
	unmsg_("Illegal severity code passed to EXSVRS.", 39L);
    }
    if (*defmod == 3 || *defmod == 1 || *defmod == 2) {
	svrst[0] = TRUE_;
    }
    s_copy(svrlst, "   ", 3L, 3L);
    if (svrst[0]) {
	*svrlst = 'c';
    }
    if (svrst[1]) {
	svrlst[1] = 'd';
    }
    if (svrst[2]) {
	svrlst[2] = 's';
    }
    nonf = FALSE_;
    nxtpos = 1;
    for (svrx = 0; svrx <= 2; ++svrx) {
	if (svrst[svrx]) {
	    if (nonf) {
		s_copy(explbl + (nxtpos - 1), " or ", explbl_len - (nxtpos - 
			1), 4L);
		nxtpos += 4;
	    } else {
		nonf = TRUE_;
	    }
	    s_copy(explbl + (nxtpos - 1), svrlab + svrx * 10, explbl_len - (
		    nxtpos - 1), 10L);
	    nxtpos = itrim_(explbl, explbl_len) + 1;
	}
/* L98: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* exsvrs_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 05.02/doimod                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int doimod_(integer *wkid, integer *inclas, integer *inmode)
#else /* NO_PROTO */
/* Subroutine */ int doimod_(wkid, inclas, inmode)
integer *wkid, *inclas, *inmode;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nschm (integer *, integer *, integer *, 
	    integer *), nslcm (integer *, integer *, integer *, integer *), 
	    unmsg_(char *, ftnlen), nspkm (integer *, integer *, integer *, 
	    integer *), nsskm (integer *, integer *, integer *, integer *), 
	    nsvlm (integer *, integer *, integer *, integer *), nsstm (
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschm (), nslcm (), unmsg_(), nspkm (), 
	    nsskm (), nsvlm (), nsstm ();
#endif /* NO_PROTO */

/*  DOIMOD: on the workstation (wkid), sets device #1 of the */
/*  specified input class (inclas) to the requested mode (inmode). */
/* operating mode */
/*                request  sample    event */
/* echo switch */
#ifndef NO_PROTO
    switch (*inclas) {
#else /* NO_PROTO */
    switch ((int)*inclas) {
#endif /* NO_PROTO */
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
    }
    unmsg_("Invalid input class passed to DOIMOD.", 37L);
L10:
/*     set locator mode */
    nslcm (wkid, &c__1, inmode, &c__0);
    goto L100;
L20:
/*     set stroke mode */
    nsskm (wkid, &c__1, inmode, &c__0);
    goto L100;
L30:
/*     set valuator mode */
    nsvlm (wkid, &c__1, inmode, &c__0);
    goto L100;
L40:
/*     set choice mode */
    nschm (wkid, &c__1, inmode, &c__0);
    goto L100;
L50:
/*     set pick mode */
    nspkm (wkid, &c__1, inmode, &c__0);
    goto L100;
L60:
/*     set string mode */
    nsstm (wkid, &c__1, inmode, &c__0);
    goto L100;
L100:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* doimod_ */

