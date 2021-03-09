/* fort//02/03/03/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__100 = 100;
#ifndef NO_PROTO
static real c_b16 = 0.f;
#else /* NO_PROTO */
static real c_b16 = (float)0.;
#endif /* NO_PROTO */
static integer c__30 = 30;
#ifndef NO_PROTO
static real c_b31 = 1.f;
#else /* NO_PROTO */
static real c_b31 = (float)1.;
#endif /* NO_PROTO */
static integer c__10 = 10;
static integer c__20 = 20;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.03/isspf                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int isspf_(integer *dimens, real *srpx, real *srpy, real *
	srpz, real *sdist, char *expath, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int isspf_(dimens, srpx, srpy, srpz, sdist, expath, 
	expath_len)
integer *dimens;
real *srpx, *srpy, *srpz, *sdist;
char *expath;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer spath[2]	/* was [2][1] */ = { 101,0 };

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int niss (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), niss3 (
	    real *, real *, real *, real *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int niss (), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen, iexpth[200]	/* was [2][100] */, fpthsz;

/*  This subroutine invokes the specified spatial search routine and */
/*  issues pass or fail, depending on its agreement with the expected */
/*  result.  Always: structure #101 is searched, search ceiling is 1, */
/*  modelling clip off, filter lists empty. */
/*  Input parameters: */
/*    DIMENS         : dimension of search: 2 or 3 */
/*    SRPX,SRPY,SRPZ : search reference point (SRPZ ignored if DIMENS=2) 
*/
/*    SDIST          : search distance */
/*    EXPATH         : expected found path */
/* clipping indicator */
/*                noclip      clip */
    if (*dimens == 2) {
	niss (srpx, srpy, sdist, &c__1, spath, &c__0, &c__1, &c__0, idum, 
		idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
		errind, &fpthsz, fpath);
    } else if (*dimens == 3) {
	niss3 (srpx, srpy, srpz, sdist, &c__1, spath, &c__0, &c__1, &c__0, 
		idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &
		c__100, &errind, &fpthsz, fpath);
    } else {
	unmsg_("Illegal dimension passed to ISSPF.", 34L);
    }
    setvs_(expath, iexpth, &iexlen, expath_len);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* isspf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.03/issgeo                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int issgeo_(char *stpth, integer *exix, real *exxlo, real *
	exylo, real *exxhi, real *exyhi, char *expth, ftnlen stpth_len, 
	ftnlen expth_len)
#else /* NO_PROTO */
/* Subroutine */ int issgeo_(stpth, exix, exxlo, exylo, exxhi, exyhi, expth, 
	stpth_len, expth_len)
char *stpth;
integer *exix;
real *exxlo, *exylo, *exxhi, *exyhi;
char *expth;
ftnlen stpth_len;
ftnlen expth_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), niss (real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), niss ();
#endif /* NO_PROTO */
    static real srpx, srpy;
    static integer fpath[60]	/* was [2][30] */, exlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer spath[60]	/* was [2][30] */;
    static real sdist;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer spsiz;
#ifndef NO_PROTO
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, expath[30];
    static real sratio, incrvx, incrvy;
    static integer fpthsz;

/*  This subroutine tests whether ISS successfully detects the */
/*  corners of a text extent rectangle. */
/*  Input parameters: */
/*    STPTH    : starting path for ISS */
/*    EXIX, EXXLO,EXYLO,EXXHI,EXYHI */
/*             : expected corner values for rectangle */
/*    EXPTH    : expected found path for ISS */
/* clipping indicator */
/*                noclip      clip */
/*  sratio = search ratio = 0.1 */
#ifndef NO_PROTO
    sratio = .1f;
#else /* NO_PROTO */
    sratio = (float).1;
#endif /* NO_PROTO */
/*  diagv = diagonal vector = vector from lower-left expected corner */
/*    to upper-right */
/*  incrv = incremental vector = sratio*diagv */
    incrvx = (exxhi[*exix] - exxlo[*exix]) * sratio;
    incrvy = (exyhi[*exix] - exylo[*exix]) * sratio;
/*  sdist = search distance  = length of incrv */
    sdist = vecl_(&incrvx, &incrvy, &c_b16);
/*  srp = upper-right corner + incrv */
    srpx = exxhi[*exix] + incrvx;
    srpy = exyhi[*exix] + incrvy;
/*  starting path */
    setvs_(stpth, spath, &spsiz, stpth_len);
    spsiz /= 2;
/*  expected path */
    setvs_(expth, expath, &exlen, expth_len);
/*  ISS: with stpath, srp, try search distance first just below and */
/*     then just above sdist. */
/*  pass/fail depending on (text first not found with expected path, */
/*     then found with expected path) */
#ifndef NO_PROTO
    r__1 = sdist * .98f;
#else /* NO_PROTO */
    r__1 = sdist * (float).98;
#endif /* NO_PROTO */
    niss (&srpx, &srpy, &r__1, &spsiz, spath, &c__0, &c__1, &c__0, idum, idum,
	     idum, idum, &c__0, idum, idum, idum, idum, &c__30, &errind, &
	    fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && ! iareql_(&i__1, fpath, &exlen, expath)) {
/* OK so far */
    } else {
	fail_();
#ifndef NO_PROTO
	inmsg_("ISS erroneously found expected path, even though search dist"
		"ance was insufficient.", 82L);
#else /* NO_PROTO */
	inmsg_("ISS erroneously found expected path, even though search dist\
ance was insufficient.", 82L);
#endif /* NO_PROTO */
	return 0;
    }
#ifndef NO_PROTO
    r__1 = sdist * 1.02f;
#else /* NO_PROTO */
    r__1 = sdist * (float)1.02;
#endif /* NO_PROTO */
    niss (&srpx, &srpy, &r__1, &spsiz, spath, &c__0, &c__1, &c__0, idum, idum,
	     idum, idum, &c__0, idum, idum, idum, idum, &c__30, &errind, &
	    fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && iareql_(&i__1, fpath, &exlen, expath)) {
	pass_();
    } else {
	fail_();
#ifndef NO_PROTO
	inmsg_("ISS did not find expected path, even though search distance "
		"was sufficient.", 75L);
#else /* NO_PROTO */
	inmsg_("ISS did not find expected path, even though search distance \
was sufficient.", 75L);
#endif /* NO_PROTO */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issgeo_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.03/tx2dex                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tx2dex_(integer *specwt, real *chupx, real *chupy, real *
	chht, integer *txpath, integer *txalh, integer *txalv, real *tposx, 
	real *tposy, char *str, integer *exix, real *exxlo, real *exylo, real 
	*exxhi, real *exyhi, ftnlen str_len)
#else /* NO_PROTO */
/* Subroutine */ int tx2dex_(specwt, chupx, chupy, chht, txpath, txalh, txalv,
	 tposx, tposy, str, exix, exxlo, exylo, exxhi, exyhi, str_len)
integer *specwt;
real *chupx, *chupy, *chht;
integer *txpath, *txalh, *txalv;
real *tposx, *tposy;
char *str;
integer *exix;
real *exxlo, *exylo, *exxhi, *exyhi;
ftnlen str_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int etp_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp_();
#endif /* NO_PROTO */
    static real recx[2], recy[2], xfrm[9]	/* was [3][3] */, rdum1, 
	    rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), nqtxx (integer *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, char *, integer *
	    , real *, real *, real *, real *, ftnlen);
    extern doublereal satan2_(real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), nqtxx ();
    extern doublereal satan2_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real rotang;

/*  This subroutine computes the expected lower-left and upper-right */
/*  corner of a text extent rectangle, including the effect of text */
/*  position and character-up vector, which are not taken into */
/*  account by <inquire text extent>. */
/*  <inquire text extent> with */
/*    workstation type           = primary workstation type */
/*      (ignored because font #1 is workstation-independent) */
/*    text font                  = 1 */
/*    character expansion factor = 1.0 */
/*    character spacing          = 0.0 */
/*      (three above set as assumed by spatial search, see SR15) */
/*    character height           = chht */
/*    text path                  = txpath */
/*    text alignment             = txal */
/*    character string           = str */
/*      to determine: */
/*    recxlo,recxhi,recylo,recyhi = text extent rectangle */
/*      in TLC, with assumed text position = 0,0 character up vector */
/*      = (0,1), and text precision = STROKE */
    nqtxx (specwt, &c__1, &c_b31, &c_b16, chht, txpath, txalh, txalv, str, &
	    errind, recx, recy, &rdum1, &rdum2, str_len);
    chkinq_("pqtxx", &errind, 5L);
/*  rotang = rotation angle for character up vector */
#ifndef NO_PROTO
    rotang = satan2_(chupy, chupx) - 1.5707963250000001f;
#else /* NO_PROTO */
    rotang = satan2_(chupy, chupx) - (float)1.5707963250000001;
#endif /* NO_PROTO */
/*  xfrm = 2D transform for rotation by rotang and shift by tpos */
    ebltm_(&c_b16, &c_b16, tposx, tposy, &rotang, &c_b31, &c_b31, xfrm);
/*  Get lower-left and upper-right corner: */
/*  transform recxlo,recylo, using xfrm to exxlo,exylo */
    etp_(recx, recy, xfrm, &exxlo[*exix], &exylo[*exix]);
/*  transform recxhi,recyhi, using xfrm to exxhi,exyhi */
    etp_(&recx[1], &recy[1], xfrm, &exxhi[*exix], &exyhi[*exix]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tx2dex_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.03/fltran                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int fltran_(real *a, real *b, real *c, real *mat)
#else /* NO_PROTO */
/* Subroutine */ int fltran_(a, b, c, mat)
real *a, *b, *c, *mat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Builtin functions */
#ifndef NO_PROTO
    double asin(doublereal);
#else /* NO_PROTO */
    double asin();
#endif /* NO_PROTO */

    /* Local variables */
    static real uu, zz;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);

    extern doublereal satan2_(real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
    extern /* Subroutine */ int ebltm3_();
    extern doublereal satan2_();
#endif /* NO_PROTO */

/*  Given a set of attitude numbers for a plane, FLTRAN returns a */
/*  4 X 4 transformation matrix which rotates the plane so as to be */
/*  parallel to the z=0 plane.  This is useful for visualizing a */
/*  planar 3D primitive. */
    /* Parameter adjustments */
    mat -= 5;

    /* Function Body */
#ifndef NO_PROTO
    zz = 0.f;
    uu = 1.f;
#else /* NO_PROTO */
    zz = (float)0.;
    uu = (float)1.;
#endif /* NO_PROTO */
    r__2 = -(doublereal)(*b);
    r__1 = -(doublereal)satan2_(&r__2, c);
    r__3 = -(doublereal)asin(*a / vecl_(a, b, c));
    ebltm3_(&zz, &zz, &zz, &zz, &zz, &zz, &r__1, &r__3, &zz, &uu, &uu, &uu, &
	    mat[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* fltran_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.03/issflt                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int issflt_(char *stpath, char *nfilt, char *ifilt, char *
	expath, ftnlen stpath_len, ftnlen nfilt_len, ftnlen ifilt_len, ftnlen 
	expath_len)
#else /* NO_PROTO */
/* Subroutine */ int issflt_(stpath, nfilt, ifilt, expath, stpath_len, 
	nfilt_len, ifilt_len, expath_len)
char *stpath, *nfilt, *ifilt, *expath;
ftnlen stpath_len;
ftnlen nfilt_len;
ftnlen ifilt_len;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real srpx = 1.f;
    static real srpy = 2.f;
    static real srpz = 3.f;
    static real sdist = .1f;
#else /* NO_PROTO */
    static real srpx = (float)1.;
    static real srpy = (float)2.;
    static real srpz = (float)3.;
    static real sdist = (float).1;
#endif /* NO_PROTO */
    static integer sceil = 1;
    static integer mclipi = 0;

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer ifln, nfln;
#ifndef NO_PROTO
    extern /* Subroutine */ int niss3 (real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int niss3 ();
#endif /* NO_PROTO */
    static integer ifles[200], fpath[20]	/* was [2][10] */, iflis[200],
	     nfles[200], nflis[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int setfil_(char *, integer *, integer *, integer 
	    *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setfil_();
#endif /* NO_PROTO */
    static integer iflesx[60], iflisx[60], nflesx[60], istlen, iexpth[20], 
	    nflisx[60], istpth[20]	/* was [2][10] */, fpthsz;

/*  ISSFLT tests the effect of various filter lists on the behavior */
/*  of ISS.  It issues pass or fail depending on whether or not the */
/*  actual result of ISS matches the expected result.  All the */
/*  parameters are encoded in character form, and thus must be */
/*  translated before invoking ISS. */
/*  Input parameters: */
/*    STPATH : starting path for ISS */
/*    NFILT  : normal filter list */
/*    IFILT  : inverted filter list */
/*    EXPATH : expected path */
/* clipping indicator */
/*                noclip      clip */
/*  Throughout, keep fixed for ISS: */
/*    SRP = 1,2,3 */
/*    search distance = 0.1 */
/*    search ceiling = 1 */
/*    clipping flag = OFF */
/*  Set up starting path */
    setvs_(stpath, istpth, &istlen, stpath_len);
    setfil_(nfilt, &nfln, nflisx, nflis, nflesx, nfles, nfilt_len);
    setfil_(ifilt, &ifln, iflisx, iflis, iflesx, ifles, ifilt_len);
    i__1 = istlen / 2;
    niss3 (&srpx, &srpy, &srpz, &sdist, &i__1, istpth, &mclipi, &sceil, &nfln,
	     nflisx, nflis, nflesx, nfles, &ifln, iflisx, iflis, iflesx, 
	    ifles, &c__10, &errind, &fpthsz, fpath);
/*  Set up expected path */
    setvs_(expath, iexpth, &iexlen, expath_len);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issflt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.03/setfil                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setfil_(char *filt, integer *fln, integer *flisx, 
	integer *flis, integer *flesx, integer *fles, ftnlen filt_len)
#else /* NO_PROTO */
/* Subroutine */ int setfil_(filt, fln, flisx, flis, flesx, fles, filt_len)
char *filt;
integer *fln, *flisx, *flis, *flesx, *fles;
ftnlen filt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ecol, icol, eldx, etot, itot, work[2200]	/* was [20][
	    110] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
#endif /* NO_PROTO */
    static integer fltdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer collen[110], numcol;

/*  SETFIL translates the character version of a filter list into the */
/*  appropriate integer arrays. */
/*  Declaration of COLLEN and WORK allows for a filter list with 55 */
/*  filters, each with an inclusion set and exclusion set of up to 20 */
/*  members.  Generated test case from P07 uses at most 50 filters. */
    /* Parameter adjustments */
    --fles;
    --flesx;
    --flis;
    --flisx;

    /* Function Body */
    set2d_(filt, &c__20, &numcol, collen, work, filt_len);
    *fln = numcol / 2;
    if (*fln << 1 != numcol) {
	unmsg_("Illegal filter list passed to SETFIL.", 37L);
    }
    itot = 0;
    etot = 0;
    i__1 = *fln;
    for (fltdx = 1; fltdx <= i__1; ++fltdx) {
	icol = (fltdx << 1) - 1;
	ecol = fltdx << 1;
/*  inclusion set */
	i__2 = collen[icol - 1];
	for (eldx = 1; eldx <= i__2; ++eldx) {
	    ++itot;
	    flis[itot] = work[eldx + icol * 20 - 21];
/* L200: */
	}
	flisx[fltdx] = itot;
/*  exclusion set */
	i__2 = collen[ecol - 1];
	for (eldx = 1; eldx <= i__2; ++eldx) {
	    ++etot;
	    fles[etot] = work[eldx + ecol * 20 - 21];
/* L300: */
	}
	flesx[fltdx] = etot;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setfil_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION 02.03.03/zval                        * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal zval_(real *x, real *y)
#else /* NO_PROTO */
doublereal zval_(x, y)
real *x, *y;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  ZVAL is just a simple linear function of x and y so as to */
/*  generate 3D points on the plane: 3x + 4y - z - 7 = 0, so */
/*    z = f(x,y) = 3x + 4y - 7 */
    ret_val = *x * 3 + *y * 4 - 7;
    return ret_val;
} /* zval_ */

