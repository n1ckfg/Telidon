/* fort/02/03/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b5 = .2f;
static real c_b6 = .3f;
static real c_b7 = .434f;
static real c_b8 = 2.2f;
static real c_b9 = 3.1f;
static real c_b10 = 4.9f;
static real c_b11 = 1.3f;
static real c_b12 = 2.4f;
static real c_b13 = 3.55f;
static real c_b14 = 1.f;
#else /* NO_PROTO */
static real c_b5 = (float).2;
static real c_b6 = (float).3;
static real c_b7 = (float).434;
static real c_b8 = (float)2.2;
static real c_b9 = (float)3.1;
static real c_b10 = (float)4.9;
static real c_b11 = (float)1.3;
static real c_b12 = (float)2.4;
static real c_b13 = (float)3.55;
static real c_b14 = (float)1.;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__101 = 101;
static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b34 = 0.f;
#else /* NO_PROTO */
static real c_b34 = (float)0.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b88 = 5.f;
#else /* NO_PROTO */
static real c_b88 = (float)5.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/03                           * */
/*  *    TEST TITLE : Geometrical borderline cases for      * */
/*  *                 graphical primitives                  * */
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
    static real zs[20] = { 0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,
	    0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f };
#else /* NO_PROTO */
    static real zs[20] = { (float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)
	    0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(
	    float)0.,(float)0. };
#endif /* NO_PROTO */
    static integer colia[6]	/* was [3][2] */ = { 0,1,1,0,1,0 };

    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double atan2(doublereal, doublereal);
#else /* NO_PROTO */
    double sqrt();
    /* Subroutine */ int s_copy();
    double atan2();
#endif /* NO_PROTO */

    /* Local variables */
    static integer cx;
    static real xc[20], yc[20], zc[20], xs[20], ys[20], xmc[4], ymc[4], zmc[4]
	    ;
    static char str[32];
    static integer nsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca3 (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nfa3 (integer *, real *, real *, real *), vec1_(real *, real *, 
	    real *, real *, real *, real *), etp3_(real *, real *, real *, 
	    real *, real *, real *, real *), npl3 (integer *, real *, real *, 
	    real *), ntx3 (real *, real *, real *, real *, real *, real *, 
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nca3 (), nfa3 (), vec1_(), etp3_(), npl3 (), 
	    ntx3 ();
#endif /* NO_PROTO */
    static real chht;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static real midx, midy, midz, recx[2], recy[2], xtlc[4], ytlc[4], ztlc[4],
	     npex, npey, npez;
#ifndef NO_PROTO
    extern /* Subroutine */ int eroz_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int eroz_();
#endif /* NO_PROTO */
    static integer npts;
    static real tdvx[2], tdvy[2], tdvz[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nschh (real *), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nschh (), inmsg_();
#endif /* NO_PROTO */
    static real cor12x, cor12y;
    static integer txalh;
    static real cor12z, chupu, sdist, chupv;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), nqwkc (), nclwk ();
#endif /* NO_PROTO */
    static real zdist;
    static integer txalv;
    static real tlcux, tlcuy, tlcuz, tlcvx, tlcvy, tlcvz, tlcwx, tlcwy, tlcwz,
	     tempx, tempy, tposx, tposy, tposz, tempz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nopwk (integer *, integer *
	    , integer *), nstxp (integer *), nqtxx (integer *, integer *, 
	    real *, real *, real *, integer *, integer *, integer *, char *, 
	    integer *, real *, real *, real *, real *, ftnlen), setvs_(char *,
	     integer *, integer *, ftnlen), ebltm3_(real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *), arrtp3_(integer *, real *, real *, real *, real *
	    , real *, real *, real *), ndelra (integer *, integer *), chkinq_(
	    char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nopwk (), nstxp (), nqtxx (), 
	    setvs_(), ebltm3_(), arrtp3_(), ndelra (), chkinq_();
#endif /* NO_PROTO */
    static real idtran[16]	/* was [4][4] */;
    static integer errind, specon, endpts[5];
    static real ndtran[16]	/* was [4][4] */;
    static integer specwt, txpath;
    static real rotmat[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), xpopph_(integer *, integer *), issdis_(real *,
	     real *, real *, real *, real *, integer *, char *, ftnlen), 
	    pervec_(real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *), crossp_(real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *), nschup (real *, real *), setrvs_(
	    char *, real *, integer *, ftnlen), nstxal (integer *, integer *);

#else /* NO_PROTO */
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), setmsg_(), xpopph_(), issdis_(), 
	    pervec_(), crossp_(), nschup (), setrvs_(), nstxal ();
#endif /* NO_PROTO */
    static real sisrpx, sisrpy, sisrpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxpr ();
#endif /* NO_PROTO */

/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* clipping indicator */
/*                noclip      clip */
/* parameters for <inquire workstation connection and type> */
    initgl_("02.03.03/03", 11L);
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
/*  ndtran = non-distorting transformation: arbitrary shift and */
/*    rotate (but not scale).  Apply this to easily visualized */
/*    2D cases to generate more complex 3D cases. */
    ebltm3_(&c_b5, &c_b6, &c_b7, &c_b8, &c_b9, &c_b10, &c_b11, &c_b12, &c_b13,
	     &c_b14, &c_b14, &c_b14, ndtran);
/*  identity matrix */
    idmat_(&c__4, idtran);
    nopst (&c__101);
/*  *** *** *** *** ***   polyline   *** *** *** *** *** *** */

/*  simpl = simple polyline = (1,1),(2,2),(2,1) */
    setrvs_("1,2,2", xs, &nsz, 5L);
    setrvs_("1,2,1", ys, &nsz, 5L);
/*  compl = complex polyline = ndtran X simpl */
    arrtp3_(&nsz, xs, ys, zs, ndtran, xc, yc, zc);
/*  Build structure 101: */
    nemst (&c__101);
    npl3 (&nsz, xc, yc, zc);
/*  sisrp = simple search reference point = (2.1, 1.5, 0.1) */
#ifndef NO_PROTO
    sisrpx = 2.1f;
    sisrpy = 1.5f;
    sisrpz = .1f;
#else /* NO_PROTO */
    sisrpx = (float)2.1;
    sisrpy = (float)1.5;
    sisrpz = (float).1;
#endif /* NO_PROTO */
/*  sdist = distance from primitive */
#ifndef NO_PROTO
    sdist = sqrt(2.f) * .1f;
    setmsg_("2 4 5 6 7 9 10 12", "The middle of a line segment in a 3D polyl"
	    "ine should be found if and only if its true distance from the se"
	    "arch reference point is not greater than the search distance.", 
	    17L, 167L);
#else /* NO_PROTO */
    sdist = sqrt((float)2.) * (float).1;
    setmsg_("2 4 5 6 7 9 10 12", "The middle of a line segment in a 3D polyl\
ine should be found if and only if its true distance from the search referen\
ce point is not greater than the search distance.", 17L, 167L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  sisrp = simple search reference point = (2.1, 2.1, 0.1) */
#ifndef NO_PROTO
    sisrpx = 2.1f;
    sisrpy = 2.1f;
    sisrpz = .1f;
#else /* NO_PROTO */
    sisrpx = (float)2.1;
    sisrpy = (float)2.1;
    sisrpz = (float).1;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = 0.1 * sqrt(3) */
#ifndef NO_PROTO
    sdist = sqrt(3.f) * .1f;
    setmsg_("2 4 5 6 7 9 10 12", "The vertex of a 3D polyline should be foun"
	    "d if and only if its true distance from the search reference poi"
	    "nt is not greater than the search distance.", 17L, 149L);
#else /* NO_PROTO */
    sdist = sqrt((float)3.) * (float).1;
    setmsg_("2 4 5 6 7 9 10 12", "The vertex of a 3D polyline should be foun\
d if and only if its true distance from the search reference point is not gr\
eater than the search distance.", 17L, 149L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  *** *** *** *** ***   text   *** *** *** *** *** *** */

/*  tdv1 =  first text direction vector = 1.2, 5.1, 0.2 */
#ifndef NO_PROTO
    tdvx[0] = 1.2f;
    tdvy[0] = 5.1f;
    tdvz[0] = .2f;
#else /* NO_PROTO */
    tdvx[0] = (float)1.2;
    tdvy[0] = (float)5.1;
    tdvz[0] = (float).2;
#endif /* NO_PROTO */
/*  tdv2 = second text direction vector = 2.1, 1.4, 3.2 */
#ifndef NO_PROTO
    tdvx[1] = 2.1f;
    tdvy[1] = 1.4f;
    tdvz[1] = 3.2f;
#else /* NO_PROTO */
    tdvx[1] = (float)2.1;
    tdvy[1] = (float)1.4;
    tdvz[1] = (float)3.2;
#endif /* NO_PROTO */
/*  tlcu = text local co-ordinate U vector = normalized tdv1 */
    vec1_(tdvx, tdvy, tdvz, &tlcux, &tlcuy, &tlcuz);
/*  tlcv = text local co-ordinate V vector = unit vector in tdv-plane, */
/*         perpendicular to tlcu, and such that tlcv . tdv2 > 0 */
    pervec_(&tlcux, &tlcuy, &tlcuz, &tdvx[1], &tdvy[1], &tdvz[1], &tempx, &
	    tempy, &tempz);
    vec1_(&tempx, &tempy, &tempz, &tlcvx, &tlcvy, &tlcvz);
/*  tlcw = text local co-ordinate W vector, perpendicular to text */
/*         plane = tlcu X tlcv */
    crossp_(&tlcux, &tlcuy, &tlcuz, &tlcvx, &tlcvy, &tlcvz, &tlcwx, &tlcwy, &
	    tlcwz);
/*  tpos = text position = 3.1, 4.2, 0.1 */
#ifndef NO_PROTO
    tposx = 3.1f;
    tposy = 4.2f;
    tposz = .1f;
#else /* NO_PROTO */
    tposx = (float)3.1;
    tposy = (float)4.2;
    tposz = (float).1;
#endif /* NO_PROTO */
/*  Set up geometric attributes: character height, character up */
/*  vector, text path, text alignment */
#ifndef NO_PROTO
    chht = 3.3f;
    chupu = 1.2f;
    chupv = -3.1f;
#else /* NO_PROTO */
    chht = (float)3.3;
    chupu = (float)1.2;
    chupv = (float)-3.1;
#endif /* NO_PROTO */
    txpath = 2;
    txalh = 2;
    txalv = 2;
/*  str = character string = "Quod licet Jovi, non licet bovi." */
    s_copy(str, "Quod licet Jovi, non licet bovi.", 32L, 32L);
/*  Get specific workstation type */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire text extent> with */
/*    workstation type           = primary workstation type */
/*      (ignored because font #1 is workstation-independent) */
/*    text font                  = 1 */
/*    character expansion factor = 1.0 */
/*    character spacing          = 0.0 */
/*      (three above set as assumed by spatial search, see SR15) */
/*    character height           = chht */
/*    text path                  = txpath */
/*    text alignment             = txalh,txalv */
/*    character string           = str */
/*      to determine: */
/*    recxlo,recxhi,recylo,recyhi = text extent rectangle in TLC, */
/*      with assumed text position = 0,0 character up vector = (0,1), */
/*      and text precision = STROKE. */
    nqtxx (&specwt, &c__1, &c_b14, &c_b34, &chht, &txpath, &txalh, &txalv, 
	    str, &errind, recx, recy, &rdum1, &rdum2, 32L);
    chkinq_("pqtxx", &errind, 5L);
/* close workstation */
    nclwk (&globnu_1.wkid);
/*  Rotate expected rectangle in TLC around 0,0 according to */
/*    character-up vector. */
/*  build and apply transformation */
#ifndef NO_PROTO
    r__1 = atan2(chupv, chupu) - 1.5707963250000001f;
#else /* NO_PROTO */
    r__1 = atan2(chupv, chupu) - (float)1.5707963250000001;
#endif /* NO_PROTO */
    eroz_(&r__1, rotmat);
    etp3_(recx, recy, &c_b34, rotmat, xtlc, ytlc, ztlc);
    etp3_(&recx[1], recy, &c_b34, rotmat, &xtlc[1], &ytlc[1], &ztlc[1]);
    etp3_(&recx[1], &recy[1], &c_b34, rotmat, &xtlc[2], &ytlc[2], &ztlc[2]);
    etp3_(recx, &recy[1], &c_b34, rotmat, &xtlc[3], &ytlc[3], &ztlc[3]);
/*  Transform 4 TLC corners to expected values in MC; use tlc-vectors */
/*  for rotation and tpos for shift.  Also, get midpoint: */
#ifndef NO_PROTO
    midx = 0.f;
    midy = 0.f;
    midz = 0.f;
#else /* NO_PROTO */
    midx = (float)0.;
    midy = (float)0.;
    midz = (float)0.;
#endif /* NO_PROTO */
    for (cx = 1; cx <= 4; ++cx) {
	xmc[cx - 1] = tposx + tlcux * xtlc[cx - 1] + tlcvx * ytlc[cx - 1] + 
		tlcwx * ztlc[cx - 1];
	ymc[cx - 1] = tposy + tlcuy * xtlc[cx - 1] + tlcvy * ytlc[cx - 1] + 
		tlcwy * ztlc[cx - 1];
	zmc[cx - 1] = tposz + tlcuz * xtlc[cx - 1] + tlcvz * ytlc[cx - 1] + 
		tlcwz * ztlc[cx - 1];
	midx += xmc[cx - 1] / 4;
	midy += ymc[cx - 1] / 4;
	midz += zmc[cx - 1] / 4;
/* L110: */
    }
/*  Expected MC rectangle is complete; now generate actual text extent. */

/*  Build structure 101: */
/*    1.  set text precision      = STRING */
/*    2.  set character height    = chht */
/*    3.  set character up vector = chup */
/*    4.  set text path           = txpath */
/*    5.  set text alignment      = txalh,txalv */
/*    6.  text 3: str at tpos with tdv1,tdv2 */
    nemst (&c__101);
    nstxpr (&c__0);
    nschh (&chht);
    nschup (&chupu, &chupv);
    nstxp (&txpath);
    nstxal (&txalh, &txalv);
    ntx3 (&tposx, &tposy, &tposz, tdvx, tdvy, tdvz, str, 32L);
/*  Project SRP out past corner #4: */
/*  SRP    = corner(4) + (corner(4) - mid-point) */
    sisrpx = xmc[3] + (xmc[3] - midx);
    sisrpy = ymc[3] + (ymc[3] - midy);
    sisrpz = zmc[3] + (zmc[3] - midz);
/*  sdist  = distance from corner(4) to mid-point */
    r__1 = xmc[3] - midx;
    r__2 = ymc[3] - midy;
    r__3 = zmc[3] - midz;
    sdist = vecl_(&r__1, &r__2, &r__3);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 15", "The size of a 3D text extent rectangle, as"
	    " treated by ISS, should be based on STROKE precision, even if th"
	    "e current precision is not STROKE.", 17L, 140L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 15", "The size of a 3D text extent rectangle, as\
 treated by ISS, should be based on STROKE precision, even if the current pr\
ecision is not STROKE.", 17L, 140L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, idtran, &c__0, "101,6", 5L);
/*  replace element number #1 with: */
/*     1.  set text precision      = STROKE */
    ndelra (&c__1, &c__1);
    nstxpr (&c__2);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 15", "The corner of a 3D text extent rectangle s"
	    "hould be found if and only if its true distance from the search "
	    "reference point is not greater than the search distance.", 17L, 
	    162L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 15", "The corner of a 3D text extent rectangle s\
hould be found if and only if its true distance from the search reference po\
int is not greater than the search distance.", 17L, 162L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, idtran, &c__0, "101,6", 5L);
/*  Project SRP above text plane: */
/*  SRP    = mid-point + tlcw */
    sisrpx = midx + tlcwx;
    sisrpy = midy + tlcwy;
    sisrpz = midz + tlcwz;
/*  sdist  = 1.0 (because tlcw is a unit vector). */
#ifndef NO_PROTO
    sdist = 1.f;
    setmsg_("2 4 5 6 7 9 10 15", "The middle of a 3D text extent rectangle s"
	    "hould be found if and only if its true distance from the search "
	    "reference point is not greater than the search distance.", 17L, 
	    162L);
#else /* NO_PROTO */
    sdist = (float)1.;
    setmsg_("2 4 5 6 7 9 10 15", "The middle of a 3D text extent rectangle s\
hould be found if and only if its true distance from the search reference po\
int is not greater than the search distance.", 17L, 162L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, idtran, &c__0, "101,6", 5L);
/*  Project SRP above and outside of edge of text plane: */
#ifndef NO_PROTO
    zdist = 2.2f;
#else /* NO_PROTO */
    zdist = (float)2.2;
#endif /* NO_PROTO */
/*  cor12  = vector from corner 2 to corner 1 = corner(1) - corner(2) */
    cor12x = xmc[0] - xmc[1];
    cor12y = ymc[0] - ymc[1];
    cor12z = zmc[0] - zmc[1];
/*  SRP    = mid-point + zdist*tlcw + cor12 */
    sisrpx = midx + zdist * tlcwx + cor12x;
    sisrpy = midy + zdist * tlcwy + cor12y;
    sisrpz = midz + zdist * tlcwz + cor12z;
/*  sdist  = sqrt (zdist ** 2 + (cor12 / 2) ** 2 ) */
/* Computing 2nd power */
    r__1 = zdist;
    r__2 = cor12x / 2;
    r__3 = cor12y / 2;
    r__4 = cor12z / 2;
    sdist = sqrt(r__1 * r__1 + vecl_(&r__2, &r__3, &r__4));
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 15", "The edge of a 3D text extent rectangle sho"
	    "uld be found if and only if its true distance from the search re"
	    "ference point is not greater than the search distance.", 17L, 
	    160L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 15", "The edge of a 3D text extent rectangle sho\
uld be found if and only if its true distance from the search reference poin\
t is not greater than the search distance.", 17L, 160L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, idtran, &c__0, "101,6", 5L);
/*  *** *** *** *** ***   cell array   *** *** *** *** *** *** */

/*  simpl = simple cell array = p:(1,1), q:(4,2), r:(2,3) */
    setrvs_("1,4,2", xs, &nsz, 5L);
    setrvs_("1,2,3", ys, &nsz, 5L);
/*  compl = complex cell array = ndtran X simpl */
    arrtp3_(&nsz, xs, ys, zs, ndtran, xc, yc, zc);
/*  Build structure 101: */
    nemst (&c__101);
    nca3 (xc, yc, zc, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, colia);
/*  sisrp = simple search reference point = (2, 2, 0.1) */
#ifndef NO_PROTO
    sisrpx = 2.f;
    sisrpy = 2.f;
    sisrpz = .1f;
#else /* NO_PROTO */
    sisrpx = (float)2.;
    sisrpy = (float)2.;
    sisrpz = (float).1;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = 0.1 */
#ifndef NO_PROTO
    sdist = .1f;
    setmsg_("2 4 5 6 7 9 10 17", "The interior region of a 3D cell array sho"
	    "uld be found if and only if its true distance from the search re"
	    "ference point is not greater than the search distance.", 17L, 
	    160L);
#else /* NO_PROTO */
    sdist = (float).1;
    setmsg_("2 4 5 6 7 9 10 17", "The interior region of a 3D cell array sho\
uld be found if and only if its true distance from the search reference poin\
t is not greater than the search distance.", 17L, 160L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  sisrp = simple search reference point = (1, 2.25, 0.1) */
#ifndef NO_PROTO
    sisrpx = 1.f;
    sisrpy = 2.25f;
    sisrpz = .1f;
#else /* NO_PROTO */
    sisrpx = (float)1.;
    sisrpy = (float)2.25;
    sisrpz = (float).1;
#endif /* NO_PROTO */
/*  npe   = nearest point on edge = (1.5, 2, 0) */
#ifndef NO_PROTO
    npex = 1.5f;
    npey = 2.f;
    npez = 0.f;
#else /* NO_PROTO */
    npex = (float)1.5;
    npey = (float)2.;
    npez = (float)0.;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = */
    r__1 = sisrpx - npex;
    r__2 = sisrpy - npey;
    r__3 = sisrpz - npez;
    sdist = vecl_(&r__1, &r__2, &r__3);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 17", "The edge of a 3D cell array should be foun"
	    "d if and only if its true distance from the search reference poi"
	    "nt is not greater than the search distance.", 17L, 149L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 17", "The edge of a 3D cell array should be foun\
d if and only if its true distance from the search reference point is not gr\
eater than the search distance.", 17L, 149L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  *** *** *** *** ***   fill area   *** *** *** *** *** *** */

/*  simple fill area looks like: */

/*          ------- 2,3.5 */
/*          |     | */
/*       ---+---  | */
/*       |  |  |  | */
/*       |  ----  | */
/*       |        | */
/*       |  ----  | */
/*       |  |  |  | */
/*       ----  |  | */
/*             |  | */
/*       -------  | */
/*       |        | */
/*   0,0 ---------- 2,0 */
    setrvs_("0,2,2,   .5, .5,1.5,1.5,0,0, .5,.5,1.5,1.5,0  ", xs, &nsz, 46L);
    setrvs_("0,0,3.5,3.5,2,  2,  3,  3,1,1, 1.5,1.5, .5, .5", ys, &nsz, 46L);
/*  compl = complex fill area = ndtran X simpl */
    arrtp3_(&nsz, xs, ys, zs, ndtran, xc, yc, zc);
/*  Build structure 101: */
    nemst (&c__101);
    nfa3 (&nsz, xc, yc, zc);
/*  sisrp = simple search reference point = (1, 1.7, 0.1) */
#ifndef NO_PROTO
    sisrpx = 1.f;
    sisrpy = 1.7f;
    sisrpz = .1f;
#else /* NO_PROTO */
    sisrpx = (float)1.;
    sisrpy = (float)1.7;
    sisrpz = (float).1;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = 0.1 */
#ifndef NO_PROTO
    sdist = .1f;
    setmsg_("2 4 5 6 7 9 10 13", "The interior region of a 3D fill area shou"
	    "ld be found if and only if its true distance from the search ref"
	    "erence point is not greater than the search distance.", 17L, 159L)
	    ;
#else /* NO_PROTO */
    sdist = (float).1;
    setmsg_("2 4 5 6 7 9 10 13", "The interior region of a 3D fill area shou\
ld be found if and only if its true distance from the search reference point\
 is not greater than the search distance.", 17L, 159L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  sisrp = simple search reference point = (2.2, 1, 5) */
#ifndef NO_PROTO
    sisrpx = 2.2f;
    sisrpy = 1.f;
    sisrpz = 5.f;
#else /* NO_PROTO */
    sisrpx = (float)2.2;
    sisrpy = (float)1.;
    sisrpz = (float)5.;
#endif /* NO_PROTO */
/*  sdist = distance from primitive */
    sdist = vecl_(&c_b5, &c_b34, &c_b88);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 13", "The edge of a 3D fill area should be found"
	    " if and only if its true distance from the search reference poin"
	    "t is not greater than the search distance.", 17L, 148L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 13", "The edge of a 3D fill area should be found\
 if and only if its true distance from the search reference point is not gre\
ater than the search distance.", 17L, 148L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  sisrp = simple search reference point = (1.1, 1.2, 0) */
#ifndef NO_PROTO
    sisrpx = 1.1f;
    sisrpy = 1.2f;
    sisrpz = 0.f;
#else /* NO_PROTO */
    sisrpx = (float)1.1;
    sisrpy = (float)1.2;
    sisrpz = (float)0.;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = 0.3 */
#ifndef NO_PROTO
    sdist = .3f;
    setmsg_("2 4 5 6 7 9 10 13", "A concave region of a 3D fill area should "
	    "be found if and only if its true distance from the search refere"
	    "nce point is not greater than the search distance.", 17L, 156L);
#else /* NO_PROTO */
    sdist = (float).3;
    setmsg_("2 4 5 6 7 9 10 13", "A concave region of a 3D fill area should \
be found if and only if its true distance from the search reference point is\
 not greater than the search distance.", 17L, 156L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  sisrp = simple search reference point = (1.1, 2.7, 0) */
#ifndef NO_PROTO
    sisrpx = 1.1f;
    sisrpy = 2.7f;
    sisrpz = 0.f;
#else /* NO_PROTO */
    sisrpx = (float)1.1;
    sisrpy = (float)2.7;
    sisrpz = (float)0.;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = 0.3 */
#ifndef NO_PROTO
    sdist = .3f;
    setmsg_("2 4 5 6 7 9 10 13", "An interior region of a 3D fill area surro"
	    "unding a hole formed by a self-intersecting border should be fou"
	    "nd if and only if its true distance from the search reference po"
	    "int is not greater than the search distance.", 17L, 214L);
#else /* NO_PROTO */
    sdist = (float).3;
    setmsg_("2 4 5 6 7 9 10 13", "An interior region of a 3D fill area surro\
unding a hole formed by a self-intersecting border should be found if and on\
ly if its true distance from the search reference point is not greater than \
the search distance.", 17L, 214L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
/*  *** *** *** *** ***   fill area set   *** *** *** *** *** *** */

/*  simpl = simple fill area set = (1,0), (0,0), (0,1), (1,1) / */
/*                                 (2,1), (3,1), (3,0), (2,0) */
    setrvs_("1,0,0,1,2,3,3,2", xs, &nsz, 15L);
    setrvs_("0,0,1,1,1,1,0,0", ys, &nsz, 15L);
/*  compl = complex fill area set = ndtran X simpl */
    arrtp3_(&nsz, xs, ys, zs, ndtran, xc, yc, zc);
    setvs_("4,8", endpts, &npts, 3L);
/*  Build structure 101: */
    nemst (&c__101);
    nfas3 (&npts, endpts, xc, yc, zc);
/*  sisrp = simple search reference point = (1.8, 0.2, 0) */
#ifndef NO_PROTO
    sisrpx = 1.8f;
    sisrpy = .2f;
    sisrpz = 0.f;
#else /* NO_PROTO */
    sisrpx = (float)1.8;
    sisrpy = (float).2;
    sisrpz = (float)0.;
#endif /* NO_PROTO */
/*  sdist = distance from primitive = 0.2 */
#ifndef NO_PROTO
    sdist = .2f;
    setmsg_("2 4 5 6 7 9 10 14", "The edge of a 3D fill area set should be f"
	    "ound if and only if its true distance from the search reference "
	    "point is not greater than the search distance.", 17L, 152L);
#else /* NO_PROTO */
    sdist = (float).2;
    setmsg_("2 4 5 6 7 9 10 14", "The edge of a 3D fill area set should be f\
ound if and only if its true distance from the search reference point is not\
 greater than the search distance.", 17L, 152L);
#endif /* NO_PROTO */
    issdis_(&sisrpx, &sisrpy, &sisrpz, &sdist, ndtran, &c__0, "101,1", 5L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

