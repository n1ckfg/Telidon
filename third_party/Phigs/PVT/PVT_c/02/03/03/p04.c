/* fort/02/03/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__102 = 102;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__108 = 108;
static integer c__104 = 104;
static integer c__41 = 41;
static integer c__106 = 106;
static integer c__61 = 61;
static integer c__62 = 62;
static integer c__64 = 64;
static integer c__107 = 107;
static integer c__71 = 71;
static integer c__72 = 72;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/04                           * */
/*  *    TEST TITLE : Starting path and search ceiling      * */
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
    static real xa[5], ya[5], za[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer nsz;
    static real srx, sry, srz;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *), 
	    endit_(void), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 (), endit_(), nclst ();
#endif /* NO_PROTO */
    static real sdist;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), initgl_(
	    char *, ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), ispths_(
	    real *, real *, real *, real *, integer *, integer *, char *, 
	    char *, ftnlen, ftnlen), xpopph_(integer *, integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), initgl_(), setmsg_(), 
	    ispths_(), xpopph_(), setrvs_();
#endif /* NO_PROTO */

/* clipping indicator */
/*                noclip      clip */
    initgl_("02.03.03/04", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Set up CSS: */

/*                101 */
/*               /   \ */
/*             1/     \2 */
/*             /       \ */
/*          102         105:1,3 */
/*           |           | */
/*          1|           |2 */
/*           |           | */
/*            \         106 */
/*             \       /   \ */
/*              \    3/     \5 */
/*               \   /       \ */
/*                103         107:3,4 */
/*               /   \ */
/*             1/     \2 */
/*             /       \ */
/*          108         104:2 */


/*  Numbers 101-108 are structure identifiers.  Numbers on edges are */
/*  element positions of 'execute structure' elements.  Numbers */
/*  following colons are element positions of primitives to be found */
/*  by spatial search.  E.g. starting from 101, the first found path */
/*  should be: (101,1), (102,1), (103,2), (104,2). */

/*  All ISS done with same search reference point, search distance */
/*  (set so as to find all the primitives listed above), no modelling */
/*  clipping, and null filter lists. */
    setrvs_("27.63, -6.263,  6.23", xa, &nsz, 20L);
    setrvs_("12.01, 92.0191,-2.12", ya, &nsz, 20L);
    setrvs_("-8.298,39.283, 28.293", za, &nsz, 21L);
    srx = xa[1];
    sry = ya[1];
    srz = za[1];
#ifndef NO_PROTO
    sdist = 1.f;
#else /* NO_PROTO */
    sdist = (float)1.;
#endif /* NO_PROTO */
    nopst (&c__101);
    nexst (&c__102);
    nexst (&c__105);
    nclst ();
    nopst (&c__102);
    nexst (&c__103);
    nclst ();
    nopst (&c__103);
    nexst (&c__108);
    nexst (&c__104);
    nclst ();
    nopst (&c__104);
    nlb (&c__41);
    npm3 (&nsz, xa, ya, za);
    nclst ();
    nopst (&c__105);
    npm3 (&nsz, xa, ya, za);
    nexst (&c__106);
    npm3 (&nsz, xa, ya, za);
    nclst ();
    nopst (&c__106);
    nlb (&c__61);
    nlb (&c__62);
    nexst (&c__103);
    nlb (&c__64);
    nexst (&c__107);
    nclst ();
    nopst (&c__107);
    nlb (&c__71);
    nlb (&c__72);
    npm3 (&nsz, xa, ya, za);
    npm3 (&nsz, xa, ya, za);
    nclst ();
#ifndef NO_PROTO
    setmsg_("2 4 5 6 9", "ISS should ignore a primitive at the starting path"
	    " location, and commence the search at the element immediately fo"
	    "llowing.", 9L, 122L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 9", "ISS should ignore a primitive at the starting path\
 location, and commence the search at the element immediately following.", 9L,
	     122L);
#endif /* NO_PROTO */
/*  <incremental spatial search> with */
/*     starting path  = (101,2), (105,2), (106,5), (107,3) */
/*     search ceiling = 1 */
/*     expected path  = (101,2), (105,2), (106,5), (107,4) */
#ifndef NO_PROTO
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "101,2, 105,2, 106,5, 10"
	    "7,3", "101,2, 105,2, 106,5, 107,4/", 26L, 27L);
    setmsg_("2 4 5 6 9", "ISS should ignore an execute-structure element at "
	    "the starting path location, and commence the search at the eleme"
	    "nt immediately following.", 9L, 139L);
#else /* NO_PROTO */
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "101,2, 105,2, 106,5, 10\
7,3", "101,2, 105,2, 106,5, 107,4/", 26L, 27L);
    setmsg_("2 4 5 6 9", "ISS should ignore an execute-structure element at \
the starting path location, and commence the search at the element immediate\
ly following.", 9L, 139L);
#endif /* NO_PROTO */
/*  <incremental spatial search> with */
/*     starting path  = (101,1) */
/*     search ceiling = 1 */
/*     expected path  = (101,2), (105,1) */
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "101,1", "101,2, 105,1/", 
	    5L, 13L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 8 9", "Repeated incremental spatial search, starting "
	    "with element zero of the root structure, using the found path as"
	    " the next starting path, and a search ceiling of 1, should find "
	    "all qualifying primitives within a network.", 13L, 217L);
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "101,0", "101,1, 102,1, "
	    "103,2, 104,2 /101,2, 105,1 /101,2, 105,2, 106,3, 103,2, 104,2 /1"
	    "01,2, 105,2, 106,5, 107,3 /101,2, 105,2, 106,5, 107,4 /101,2, 10"
	    "5,3 / /", 5L, 149L);
    setmsg_("2 4 5 6 9", "ISS should be able to search a sub-network within "
	    "a larger CSS network.", 9L, 71L);
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "106,1", "106,3, 103,2, "
	    "104,2 /106,5, 107,3 /106,5, 107,4 / /", 5L, 51L);
    setmsg_("2 4 5 6 8 9", "A search ceiling greater than 1 should limit the"
	    " search to the network of the indicated structure.", 11L, 98L);
    ispths_(&srx, &sry, &srz, &sdist, &c__4, &c__0, "101,2, 105,2, 106,3, 10"
	    "3,1, 108,0", "101,2, 105,2, 106,3, 103,2, 104,2 / /", 33L, 37L);
    setmsg_("2 4 5 6 8 9", "Any search ceiling up to the end of the starting"
	    " path should be valid.", 11L, 70L);
    ispths_(&srx, &sry, &srz, &sdist, &c__4, &c__0, "101,1, 102,1, 103,2, 10"
	    "4,1", "101,1, 102,1, 103,2, 104,2 / /", 26L, 30L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 8 9", "Repeated incremental spatial search, starting \
with element zero of the root structure, using the found path as the next st\
arting path, and a search ceiling of 1, should find all qualifying primitive\
s within a network.", 13L, 217L);
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "101,0", "101,1, 102,1, \
103,2, 104,2 /101,2, 105,1 /101,2, 105,2, 106,3, 103,2, 104,2 /101,2, 105,2,\
 106,5, 107,3 /101,2, 105,2, 106,5, 107,4 /101,2, 105,3 / /", 5L, 149L);
    setmsg_("2 4 5 6 9", "ISS should be able to search a sub-network within \
a larger CSS network.", 9L, 71L);
    ispths_(&srx, &sry, &srz, &sdist, &c__1, &c__0, "106,1", "106,3, 103,2, \
104,2 /106,5, 107,3 /106,5, 107,4 / /", 5L, 51L);
    setmsg_("2 4 5 6 8 9", "A search ceiling greater than 1 should limit the\
 search to the network of the indicated structure.", 11L, 98L);
    ispths_(&srx, &sry, &srz, &sdist, &c__4, &c__0, "101,2, 105,2, 106,3, 10\
3,1, 108,0", "101,2, 105,2, 106,3, 103,2, 104,2 / /", 33L, 37L);
    setmsg_("2 4 5 6 8 9", "Any search ceiling up to the end of the starting\
 path should be valid.", 11L, 70L);
    ispths_(&srx, &sry, &srz, &sdist, &c__4, &c__0, "101,1, 102,1, 103,2, 10\
4,1", "101,1, 102,1, 103,2, 104,2 / /", 26L, 30L);
#endif /* NO_PROTO */
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

