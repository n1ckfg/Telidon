/* fort/02/03/03/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__123 = 123;
static integer c__0 = 0;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__103 = 103;
static integer c__1 = 1;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b17 = 33.3f;
#else /* NO_PROTO */
static real c_b17 = (float)33.3;
#endif /* NO_PROTO */
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/05                           * */
/*  *    TEST TITLE : Inheritance of geometric attributes   * */
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
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char str[17];
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real chht;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), endit_(void), nschh (real *)
	    , inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), endit_(), nschh (), inmsg_();
#endif /* NO_PROTO */
    static integer txalh;
    static real exxhi[11], exyhi[11], chupx, chupy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nclst ();
#endif /* NO_PROTO */
    static integer txalv;
    static real exxlo[11], exylo[11];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nexst (), nopst ();
#endif /* NO_PROTO */
    static real tposx, tposy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxp (integer *), tx2dex_(integer *, real *, 
	    real *, real *, integer *, integer *, integer *, real *, real *, 
	    char *, integer *, real *, real *, real *, real *, ftnlen), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxp (), tx2dex_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), nschup (real *, real 
	    *);
#else /* NO_PROTO */
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), nschup ();
#endif /* NO_PROTO */
    static integer specwt, txpath;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    issgeo_(char *, integer *, real *, real *, real *, real *, char *,
	     ftnlen, ftnlen), nstxal (integer *, integer *), xpopph_(integer *
	    , integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), issgeo_(), nstxal (), xpopph_(), 
	    nstxpr ();
#endif /* NO_PROTO */

/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* parameters for <inquire workstation connection and type> */
    initgl_("02.03.03/05", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    if (! sphdis_(&c__123)) {
#ifndef NO_PROTO
	inmsg_("Skipping test because implementation apparently uses non-Euc"
		"lidean metric for search distance.", 94L);
#else /* NO_PROTO */
	inmsg_("Skipping test because implementation apparently uses non-Euc\
lidean metric for search distance.", 94L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  The only geometric attributes which affect the size or position */
/*  of primitives are the text attributes: */
/*    chht   : character height */
/*    chup   : character up vector */
/*    txpath : text path */
/*    txal   : text alignment */

/*  All ISS done with search ceiling of 1, no modelling clipping, and */
/*  null filter lists. */

/*  Set up CSS: */

/*              101 */
/*              / | */
/*            5/  | */
/*            /   | */
/*           /    |6 */
/*        102     | */
/*           \    | */
/*           5\   | */
/*             \  | */
/*              \ | */
/*              103 */

/*  Numbers 101-103 are structure identifiers.  Numbers on edges are */
/*  element positions of 'execute structure' elements. */
/*  tpos = text position = 3.1, 4.2 */
/*  str  = character string = "PHIGS or bust ..." */
#ifndef NO_PROTO
    tposx = 3.1f;
    tposy = 4.2f;
#else /* NO_PROTO */
    tposx = (float)3.1;
    tposy = (float)4.2;
#endif /* NO_PROTO */
    s_copy(str, "PHIGS or bust ...", 17L, 17L);
/* open workstation - get specific workstation type */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  Set up values as in PDT: */
#ifndef NO_PROTO
    chupx = 0.f;
    chupy = 1.f;
    chht = .01f;
#else /* NO_PROTO */
    chupx = (float)0.;
    chupy = (float)1.;
    chht = (float).01;
#endif /* NO_PROTO */
    txpath = 0;
    txalh = 0;
    txalv = 0;
/*  Calculate expected values for PDT in slot #0: */
    tx2dex_(&specwt, &chupx, &chupy, &chht, &txpath, &txalh, &txalv, &tposx, &
	    tposy, str, &c__0, exxlo, exylo, exxhi, exyhi, 17L);
/*  Set up values for structure 101: */
#ifndef NO_PROTO
    chupx = 1.f;
    chupy = 1.3f;
    chht = 2.2f;
#else /* NO_PROTO */
    chupx = (float)1.;
    chupy = (float)1.3;
    chht = (float)2.2;
#endif /* NO_PROTO */
    txpath = 3;
    txalh = 3;
    txalv = 1;
/*  Structure 101 */
    nopst (&c__101);
    nschup (&chupx, &chupy);
    nschh (&chht);
    nstxp (&txpath);
    nstxal (&txalh, &txalv);
    nexst (&c__102);
    nexst (&c__103);
    r__1 = chht / 3;
    nschh (&r__1);
    nclst ();
/*  Calculate expected values for 101: */
    tx2dex_(&specwt, &chupx, &chupy, &chht, &txpath, &txalh, &txalv, &tposx, &
	    tposy, str, &c__1, exxlo, exylo, exxhi, exyhi, 17L);
/*  Set up values for structure 102: */
#ifndef NO_PROTO
    chupx = -1.f;
    chupy = 1.6f;
    chht = .023f;
#else /* NO_PROTO */
    chupx = (float)-1.;
    chupy = (float)1.6;
    chht = (float).023;
#endif /* NO_PROTO */
    txpath = 2;
    txalh = 1;
    txalv = 3;
/*  Structure 102 */
    nopst (&c__102);
    nschup (&chupx, &chupy);
    nschh (&chht);
    nstxp (&txpath);
    nstxal (&txalh, &txalv);
    nexst (&c__103);
    r__1 = chht / 3;
    nschh (&r__1);
    nclst ();
/*  Calculate expected values for 102: */
    tx2dex_(&specwt, &chupx, &chupy, &chht, &txpath, &txalh, &txalv, &tposx, &
	    tposy, str, &c__2, exxlo, exylo, exxhi, exyhi, 17L);
/*  Structure 103 */
    nopst (&c__103);
    nstxpr (&c__0);
    ntx (&tposx, &tposy, str, 17L);
    nschh (&c_b17);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be those se"
	    "t by the most recent ancestor, even if a more distant ancestor a"
	    "lso set them.", 13L, 123L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be those se\
t by the most recent ancestor, even if a more distant ancestor also set them."
	    , 13L, 123L);
#endif /* NO_PROTO */
/*  Test ISS for corners of text rectangle with: */
/*    starting path:         101,0 */
/*    expected corner index: 2 */
/*    expected found path:   101,5 102,5, 103,2 */
    issgeo_("101,0", &c__2, exxlo, exylo, exxhi, exyhi, "101,5, 102,5, 103,2",
	     5L, 19L);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be re-store"
	    "d after being changed by a descendant structure that precedes th"
	    "e starting path.", 13L, 126L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be re-store\
d after being changed by a descendant structure that precedes the starting p\
ath.", 13L, 126L);
#endif /* NO_PROTO */
/*  Test ISS for corners of text rectangle with: */
/*    starting path:         101,6, 103,0 */
/*    expected corner index: 1 */
/*    expected found path:   101,6, 103,2 */
    issgeo_("101,6, 103,0", &c__1, exxlo, exylo, exxhi, exyhi, "101,6, 103,2",
	     12L, 12L);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 6 7", "When not explicitly set by an ancestor or by i"
	    "tself, the geometric attributes for a structure should be as inh"
	    "erited from the PHIGS description table.", 13L, 150L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 6 7", "When not explicitly set by an ancestor or by i\
tself, the geometric attributes for a structure should be as inherited from \
the PHIGS description table.", 13L, 150L);
#endif /* NO_PROTO */
/*  Test ISS for corners of text rectangle with: */
/*    starting path:         103,0 */
/*    expected corner index: 0 */
/*    expected found path:   103,2 */
    issgeo_("103,0", &c__0, exxlo, exylo, exxhi, exyhi, "103,2", 5L, 5L);
/*  Set up values for structure 103: */
#ifndef NO_PROTO
    chupx = -1.f;
    chupy = -1.9f;
    chht = 12.3f;
#else /* NO_PROTO */
    chupx = (float)-1.;
    chupy = (float)-1.9;
    chht = (float)12.3;
#endif /* NO_PROTO */
    txpath = 1;
    txalh = 2;
    txalv = 5;
/*  Insert in beginning of structure 103: */
    nopst (&c__103);
    nsep (&c__0);
    nschup (&chupx, &chupy);
    nschh (&chht);
    nstxp (&txpath);
    nstxal (&txalh, &txalv);
    nclst ();
/*  old elements of 103: */
/*    5. set text precision to STRING */
/*    6. 2D text: str at tpos */
/*    7. set character height to 33.3 */
/*  Calculate expected values for 103: */
    tx2dex_(&specwt, &chupx, &chupy, &chht, &txpath, &txalh, &txalv, &tposx, &
	    tposy, str, &c__3, exxlo, exylo, exxhi, exyhi, 17L);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be as set i"
	    "n prior elements of the current structure, overriding the inheri"
	    "ted attributes.", 13L, 125L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be as set i\
n prior elements of the current structure, overriding the inherited attribut\
es.", 13L, 125L);
#endif /* NO_PROTO */
/*  Test ISS for corners of text rectangle with: */
/*    starting path:         101,0 */
/*    expected corner index: 3 */
/*    expected found path:   101,5, 102,5, 103,6 */
    issgeo_("101,0", &c__3, exxlo, exylo, exxhi, exyhi, "101,5, 102,5, 103,6",
	     5L, 19L);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be as set i"
	    "n prior elements of the current structure when there are no inhe"
	    "rited attributes.", 13L, 127L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 6 7", "Actual geometric attributes should be as set i\
n prior elements of the current structure when there are no inherited attrib\
utes.", 13L, 127L);
#endif /* NO_PROTO */
/*  Test ISS for corners of text rectangle with: */
/*    starting path:         103,0 */
/*    expected corner index: 3 */
/*    expected found path:   103,6 */
    issgeo_("103,0", &c__3, exxlo, exylo, exxhi, exyhi, "103,6", 5L, 5L);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 6", "Actual geometric attributes should be as set in "
	    "prior elements of structure even when these precede the starting"
	    " path.", 11L, 118L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 6", "Actual geometric attributes should be as set in \
prior elements of structure even when these precede the starting path.", 11L, 
	    118L);
#endif /* NO_PROTO */
/*  Test ISS for corners of text rectangle with: */
/*    starting path:         103,5 */
/*    expected corner index: 3 */
/*    expected found path:   103,6 */
    issgeo_("103,5", &c__3, exxlo, exylo, exxhi, exyhi, "103,6", 5L, 5L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

