/* picenv.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__101 = 101;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b12 = .1f;
static real c_b13 = .15f;
static real c_b14 = .5f;
#else /* NO_PROTO */
static real c_b12 = (float).1;
static real c_b13 = (float).15;
static real c_b14 = (float).5;
#endif /* NO_PROTO */
static integer c__201 = 201;
static integer c__400 = 400;
static integer c__401 = 401;
static integer c__402 = 402;

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
    nschh (&c_b12);
    ntx (&c_b13, &c_b14, "?", 1L);
/* potential invisibility: filter = [2] */
    nres (&c__1, namset);
    namset[0] = 2;
    nads (&c__1, namset);
    nfas (&c__2, endpts, fasx, fasy);
    nres (&c__1, namset);
    nclst ();
    npost (wkid, &c__101, &c_b14);
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
    npost (wkid, &c__201, &c_b14);
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
	npost (wkid, &i__2, &c_b14);
/* L300: */
    }
/*  set up 400,401,402 as a small posted network, with 400 */
/*  executing either 401 or 402.  401 has a 60-deg line, 402 a */
/*  150-deg line. */
    nopst (&c__400);
    nexst (&c__401);
    nclst ();
    npost (wkid, &c__400, &c_b14);
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

