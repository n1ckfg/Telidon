/* fort//trans-sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;
static integer c__3 = 3;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b40 = 0.f;
static real c_b60 = 1e-7f;
static real c_b61 = 1e-4f;
#else /* NO_PROTO */
static real c_b40 = (float)0.;
static real c_b60 = (float)1e-7;
static real c_b61 = (float)1e-4;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__100 = 100;
static integer c__30 = 30;

/*  FILE: TRANS_SUBLIB.FOR */
/*  Overview of transformation subroutine library: */
/*  SUBROUTINE etr3 (dx,dy,dz, xfrmt)  : 3D translate */
/*  SUBROUTINE etr (dx,dy, xfrmt)      : 2D translate */
/*  SUBROUTINE esc3 (fx,fy,fz, xfrmt)  : 3D scale */
/*  SUBROUTINE esc (fx,fy, xfrmt)      : 2D scale */
/*  SUBROUTINE erox (rotang, xfrmt)    : 3D rotate X axis */
/*  SUBROUTINE eroy (rotang, xfrmt)    : 3D rotate Y axis */
/*  SUBROUTINE eroz (rotang, xfrmt)    : 3D rotate Z axis */
/*  SUBROUTINE ero (rotang, xfrmt)     : 2D rotate Z axis */
/*  SUBROUTINE ecom3 (xfrmta, xfrmtb, xfrmto)   : 3D composition */
/*  SUBROUTINE ecom (xfrmta, xfrmtb, xfrmto)    : 2D composition */
/*  SUBROUTINE etp3 (xi,yi,zi, xfrmt, xo,yo,zo) : 3D transform point */
/*  SUBROUTINE etp (xi,yi, xfrmt, xo,yo)        : 2D transform point */
/* SUBROUTINE ebltm3 (x0,y0,z0, dx,dy,dz, phix,phiy,phiz, fx,fy,fz, xfrmt)*/
/*                : 3D build transform */
/*  SUBROUTINE ebltm (x0,y0, dx,dy, phi, fx,fy, xfrmt) */
/*                : 2D build transform */
/* SUBROUTINE ecotm3 (xfrmti, x0,y0,z0, dx,dy,dz, phix,phiy,phiz, fx,fy,fz, xf
rmto)*/
/*                : 3D compose transform */
/*  SUBROUTINE ecotm (xfrmti, x0,y0, dx,dy, phi, fx,fy, xfrmto) */
/*                : 2D compose transform */
/* SUBROUTINE eevom3 (vwrx,vwry,vwrz, vpnx,vpny,vpnz, vupx,vupy,vupz, vwormt)
*/
/*                : 3D view orientation */
/*  SUBROUTINE eevom (vwrx,vwry, vupx,vupy, vwormt) */
/*                : 2D view orientation */
/*  SUBROUTINE eevmm (umin, umax, vmin, vmax, xmin, xmax, ymin, ymax) */
/*                : 2D view mapping */
/**** *** *** *** ***   End of PHIGS-mimicking routines;  *** *** *** *** ***
*/
/**** *** *** *** ***   General-purpose PVT math routines   *** *** *** *** *
***/
/*  SUBROUTINE matmul (m,n,p, a,b, c)           : matrix multiply */
/*  SUBROUTINE idmat (sz, mat)                  : generate identity matrix */
/*  SUBROUTINE arrtp3 (nsz, xi,yi,zi, xfrmt, xo,yo,zo) */
/*                                             : transforms a list of 3D point
s*/
/*  SUBROUTINE red43 (m4, m3)                   : reduce 4x4 matrix to 3x3 */
/*  SUBROUTINE exp34 (m3, m4)                   : expand 3x3 matrix to 4x4 */
/* LOGICAL FUNCTION trnseq (sz, actmat,expmat) : test transformations equal*/
/*  REAL FUNCTION satan2 (y,x)                  : safe arctan */
/*  REAL FUNCTION vecl2 (vx,vy,vz)              : squared length of vector */
/*  REAL FUNCTION vecl (vx,vy,vz)               : length of vector */
/* SUBROUTINE vec1 (vx,vy,vz, vx1,vy1,vz1)     : scale vector to unit length*/

/*  REAL FUNCTION dotprd (vx1,vy1,vz1, vx2,vy2,vz2) */
/*                                              : dot product of vectors */
/*  REAL FUNCTION vecang (vx1,vy1,vz1, vx2,vy2,vz2) */
/*                                              : angle between vectors */
/*  SUBROUTINE crossp (vx1,vy1,vz1, vx2,vy2,vz2, vx3,vy3,vz3) */
/*                                              : cross product of vectors */
/* SUBROUTINE prpv1 (vx1,vy1,vz1, vx2,vy2,vz2) : get perpendicular 3D vector*/

/*  SUBROUTINE pervec (vx1,vy1,vz1, vx2,vy2,vz2, vx3,vy3,vz3) */
/*                                              : perpendicular projection */
/*  SUBROUTINE ptplds (px,py,pz, a,b,c,d, xn,yn,zn, dist) */
/*                                             : point-plane projection,distan
ce*/
/*  SUBROUTINE lnplpt (lx,ly,lz, al,bl,cl, ap,bp,cp,dp, xi,yi,zi) */
/*                                              : point of intersection of */
/*                                              : line and plane */
/* SUBROUTINE pt3pl (xarr,yarr,zarr, a,b,c,d)  : plane containing 3 points*/
/* SUBROUTINE ptspl (ilim, x,y,z, a,b,c,d)     : plane containing n points*/
/*  SUBROUTINE pl2pl (ar,br,cr,dr, ax,bx,cx,dx, ap,bp,cp,dp) */
/*                                              : plane perpendicular */
/*                                              : to reference plane */
/*  SUBROUTINE pl2ln (a1,b1,c1,d1, a2,b2,c2,d2, a,b,c, px,py,pz) */
/*                                              : line as intersection of */
/*                                              : two planes */
/*  INTEGER function abest3 (aa,ba,ca)          : greatest magnitude */
/*  SUBROUTINE ptlnds (px,py,pz, a,b,c,lx,ly,lz, xn,yn,zn, dist) */
/*                                             : distance from point to line*/

/*  SUBROUTINE lintpt (a,b,c, d,e,f, x,y)       : intersection of 2 lines */
/* SUBROUTINE pt2cof (x1,y1, x2,y2, a,b,c)     : calculate 2D line coefficient
s*/
/*  SUBROUTINE parcof (x0,y0, xcoeff,ycoeff, a,b,c) */
/*                                              : line coefficients */
/*  REAL FUNCTION ptregd (px,py,pz, nsz, xa,ya,za) */
/*                                              : minimum distance from 3D */
/*                                             : point to planar 3D region.*/
/*  INTEGER FUNCTION ceilng (x)                 : integer ceiling for x */
/*  INTEGER FUNCTION mod1 (x,m)                 : x between 1 and m */
/*  SUBROUTINE invol (px,py,pz, ilim, arx,ary,arz, side, pldist) */
/*                                              : is point inside volume */
/*  INTEGER FUNCTION inarea (px,py, ilim, x, y) : is point inside area */
/*  SUBROUTINE issdis (sisrpx,sisrpy,sisrpz, sdist, xfrmt, mclipi, expath) */
/*             : ISS for structure 101, varying search distance */
/* SUBROUTINE issab (srpx,srpy,srpz, sdist, stpath, mclipi, sceil, expath)*/
/*             : ISS with varying search distance */
/* SUBROUTINE ispths (srpx,srpy,srpz, sdist, sceil, mclipi, stpth, expths)*/
/*             : ISS for multiple expected found paths */
/*  This set of subroutines is a simple implementation of some of */
/*  the matrix utility functions of PHIGS.  They are not meant */
/*  to be terribly robust or numerically stable in all cases, just */
/*  adequate to generate expected values which may then be compared */
/*  with the actual values returned by the implementation under test. */
/*  They have the same names as the corresponding PHIGS function */
/*  except that the leading "P" is replaced by "E" (for Expected). */
/*  Also, there is no parameter for error indicator. */
/*  Note that the Fortran binding to PHIGS specifies that the */
/*  first index addresses the row and the second index the column */
/*  of a transformation matrix. */
/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/etr3                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int etr3_(real *dx, real *dy, real *dz, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int etr3_(dx, dy, dz, xfrmt)
real *dx, *dy, *dz, *xfrmt;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    idmat_(&c__4, &xfrmt[5]);
    xfrmt[17] = *dx;
    xfrmt[18] = *dy;
    xfrmt[19] = *dz;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etr3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/etr                                  * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int etr_(real *dx, real *dy, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int etr_(dx, dy, xfrmt)
real *dx, *dy, *xfrmt;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    idmat_(&c__3, &xfrmt[4]);
    xfrmt[10] = *dx;
    xfrmt[11] = *dy;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/esc3                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int esc3_(real *fx, real *fy, real *fz, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int esc3_(fx, fy, fz, xfrmt)
real *fx, *fy, *fz, *xfrmt;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    idmat_(&c__4, &xfrmt[5]);
    xfrmt[5] = *fx;
    xfrmt[10] = *fy;
    xfrmt[15] = *fz;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* esc3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/esc                                  * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int esc_(real *fx, real *fy, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int esc_(fx, fy, xfrmt)
real *fx, *fy, *xfrmt;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    idmat_(&c__3, &xfrmt[4]);
    xfrmt[4] = *fx;
    xfrmt[8] = *fy;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* esc_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/erox                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int erox_(real *rotang, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int erox_(rotang, xfrmt)
real *rotang, *xfrmt;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real cs, sn;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    idmat_(&c__4, &xfrmt[5]);
    sn = sin(*rotang);
    cs = cos(*rotang);
    xfrmt[10] = cs;
    xfrmt[15] = cs;
    xfrmt[14] = -(doublereal)sn;
    xfrmt[11] = sn;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* erox_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/eroy                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int eroy_(real *rotang, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int eroy_(rotang, xfrmt)
real *rotang, *xfrmt;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real cs, sn;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    idmat_(&c__4, &xfrmt[5]);
    sn = sin(*rotang);
    cs = cos(*rotang);
    xfrmt[5] = cs;
    xfrmt[15] = cs;
    xfrmt[13] = sn;
    xfrmt[7] = -(doublereal)sn;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eroy_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/eroz                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int eroz_(real *rotang, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int eroz_(rotang, xfrmt)
real *rotang, *xfrmt;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real cs, sn;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    idmat_(&c__4, &xfrmt[5]);
    sn = sin(*rotang);
    cs = cos(*rotang);
    xfrmt[5] = cs;
    xfrmt[10] = cs;
    xfrmt[9] = -(doublereal)sn;
    xfrmt[6] = sn;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eroz_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ero                                  * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ero_(real *rotang, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int ero_(rotang, xfrmt)
real *rotang, *xfrmt;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real cs, sn;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    idmat_(&c__3, &xfrmt[4]);
    sn = sin(*rotang);
    cs = cos(*rotang);
    xfrmt[4] = cs;
    xfrmt[8] = cs;
    xfrmt[7] = -(doublereal)sn;
    xfrmt[5] = sn;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ero_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ecom3                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ecom3_(real *xfrmta, real *xfrmtb, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecom3_(xfrmta, xfrmtb, xfrmto)
real *xfrmta, *xfrmtb, *xfrmto;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 5;
    xfrmtb -= 5;
    xfrmta -= 5;

    /* Function Body */
    matmul_(&c__4, &c__4, &c__4, &xfrmta[5], &xfrmtb[5], &xfrmto[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecom3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ecom                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ecom_(real *xfrmta, real *xfrmtb, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecom_(xfrmta, xfrmtb, xfrmto)
real *xfrmta, *xfrmtb, *xfrmto;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 4;
    xfrmtb -= 4;
    xfrmta -= 4;

    /* Function Body */
    matmul_(&c__3, &c__3, &c__3, &xfrmta[4], &xfrmtb[4], &xfrmto[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecom_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/etp3                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int etp3_(real *xi, real *yi, real *zi, real *xfrmt, real *
	xo, real *yo, real *zo)
#else /* NO_PROTO */
/* Subroutine */ int etp3_(xi, yi, zi, xfrmt, xo, yo, zo)
real *xi, *yi, *zi, *xfrmt, *xo, *yo, *zo;
#endif /* NO_PROTO */
{
    static real w, pti[4]	/* was [4][1] */, pto[4]	/* was [4][1] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    pti[0] = *xi;
    pti[1] = *yi;
    pti[2] = *zi;
#ifndef NO_PROTO
    pti[3] = 1.f;
#else /* NO_PROTO */
    pti[3] = (float)1.;
#endif /* NO_PROTO */
    matmul_(&c__4, &c__4, &c__1, &xfrmt[5], pti, pto);
    w = pto[3];
    *xo = pto[0] / w;
    *yo = pto[1] / w;
    *zo = pto[2] / w;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etp3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/etp                                  * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int etp_(real *xi, real *yi, real *xfrmt, real *xo, real *yo)

#else /* NO_PROTO */
/* Subroutine */ int etp_(xi, yi, xfrmt, xo, yo)
real *xi, *yi, *xfrmt, *xo, *yo;
#endif /* NO_PROTO */
{
    static real w, pti[3]	/* was [3][1] */, pto[3]	/* was [3][1] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int matmul_(integer *, integer *, integer *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int matmul_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    pti[0] = *xi;
    pti[1] = *yi;
#ifndef NO_PROTO
    pti[2] = 1.f;
#else /* NO_PROTO */
    pti[2] = (float)1.;
#endif /* NO_PROTO */
    matmul_(&c__3, &c__3, &c__1, &xfrmt[4], pti, pto);
    w = pto[2];
    *xo = pto[0] / w;
    *yo = pto[1] / w;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* etp_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ebltm3                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ebltm3_(real *x0, real *y0, real *z0, real *dx, real *dy,
	 real *dz, real *phix, real *phiy, real *phiz, real *fx, real *fy, 
	real *fz, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int ebltm3_(x0, y0, z0, dx, dy, dz, phix, phiy, phiz, fx, fy,
	 fz, xfrmt)
real *x0, *y0, *z0, *dx, *dy, *dz, *phix, *phiy, *phiz, *fx, *fy, *fz, *xfrmt;

#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real wka[16]	/* was [4][4] */, wkb[16]	/* was [4][4] */, wkc[
	    16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc3_(real *, real *, real *, real *), etr3_(
	    real *, real *, real *, real *), erox_(real *, real *), eroy_(
	    real *, real *), eroz_(real *, real *), ecom3_(real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc3_(), etr3_(), erox_(), eroy_(), eroz_(), 
	    ecom3_();
#endif /* NO_PROTO */

/* shift so that fixed point is at origin */
    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    r__1 = -(doublereal)(*x0);
    r__2 = -(doublereal)(*y0);
    r__3 = -(doublereal)(*z0);
    etr3_(&r__1, &r__2, &r__3, wka);
/* scale */
    esc3_(fx, fy, fz, wkb);
    ecom3_(wkb, wka, wkc);
/* rotations */
    erox_(phix, wka);
    ecom3_(wka, wkc, wkb);
    eroy_(phiy, wka);
    ecom3_(wka, wkb, wkc);
    eroz_(phiz, wka);
    ecom3_(wka, wkc, wkb);
/* do specified shift and undo fixed-point shift */
    r__1 = *x0 + *dx;
    r__2 = *y0 + *dy;
    r__3 = *z0 + *dz;
    etr3_(&r__1, &r__2, &r__3, wka);
    ecom3_(wka, wkb, &xfrmt[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ebltm3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ebltm                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ebltm_(real *x0, real *y0, real *dx, real *dy, real *phi,
	 real *fx, real *fy, real *xfrmt)
#else /* NO_PROTO */
/* Subroutine */ int ebltm_(x0, y0, dx, dy, phi, fx, fy, xfrmt)
real *x0, *y0, *dx, *dy, *phi, *fx, *fy, *xfrmt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int esc_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc_();
#endif /* NO_PROTO */
    static real wka[9]	/* was [3][3] */, wkb[9]	/* was [3][3] */, wkc[
	    9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ero_(real *, real *), etr_(real *, real *, 
	    real *), ecom_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ero_(), etr_(), ecom_();
#endif /* NO_PROTO */

/* shift so that fixed point is at origin */
    /* Parameter adjustments */
    xfrmt -= 4;

    /* Function Body */
    r__1 = -(doublereal)(*x0);
    r__2 = -(doublereal)(*y0);
    etr_(&r__1, &r__2, wka);
/* scale */
    esc_(fx, fy, wkb);
    ecom_(wkb, wka, wkc);
/* rotation */
    ero_(phi, wka);
    ecom_(wka, wkc, wkb);
/* do specified shift and undo fixed-point shift */
    r__1 = *x0 + *dx;
    r__2 = *y0 + *dy;
    etr_(&r__1, &r__2, wka);
    ecom_(wka, wkb, &xfrmt[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ebltm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ecotm3                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ecotm3_(real *xfrmti, real *x0, real *y0, real *z0, real 
	*dx, real *dy, real *dz, real *phix, real *phiy, real *phiz, real *fx,
	 real *fy, real *fz, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecotm3_(xfrmti, x0, y0, z0, dx, dy, dz, phix, phiy, phiz,
	 fx, fy, fz, xfrmto)
real *xfrmti, *x0, *y0, *z0, *dx, *dy, *dz, *phix, *phiy, *phiz, *fx, *fy, *
	fz, *xfrmto;
#endif /* NO_PROTO */
{
    static real wka[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *), ebltm3_(real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_(), ebltm3_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 5;
    xfrmti -= 5;

    /* Function Body */
    ebltm3_(x0, y0, z0, dx, dy, dz, phix, phiy, phiz, fx, fy, fz, wka);
    ecom3_(&xfrmti[5], wka, &xfrmto[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecotm3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ecotm                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ecotm_(real *xfrmti, real *x0, real *y0, real *dx, real *
	dy, real *phi, real *fx, real *fy, real *xfrmto)
#else /* NO_PROTO */
/* Subroutine */ int ecotm_(xfrmti, x0, y0, dx, dy, phi, fx, fy, xfrmto)
real *xfrmti, *x0, *y0, *dx, *dy, *phi, *fx, *fy, *xfrmto;
#endif /* NO_PROTO */
{
    static real wka[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom_(real *, real *, real *), ebltm_(real *, 
	    real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom_(), ebltm_();
#endif /* NO_PROTO */

    /* Parameter adjustments */
    xfrmto -= 4;
    xfrmti -= 4;

    /* Function Body */
    ebltm_(x0, y0, dx, dy, phi, fx, fy, wka);
    ecom_(&xfrmti[4], wka, &xfrmto[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ecotm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/eevom3                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int eevom3_(real *vwrx, real *vwry, real *vwrz, real *vpnx, 
	real *vpny, real *vpnz, real *vupx, real *vupy, real *vupz, real *
	vwormt)
#else /* NO_PROTO */
/* Subroutine */ int eevom3_(vwrx, vwry, vwrz, vpnx, vpny, vpnz, vupx, vupy, 
	vupz, vwormt)
real *vwrx, *vwry, *vwrz, *vpnx, *vpny, *vpnz, *vupx, *vupy, *vupz, *vwormt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real wk[16]	/* was [4][4] */, tvx, tvy, tvz;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), etr3_(real *, real *, real *, real *), erox_(
	    real *, real *), eroy_(real *, real *), eroz_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), etr3_(), erox_(), eroy_(), eroz_();
#endif /* NO_PROTO */
    static real trmt[16]	/* was [4][4] */, xrot[16]	/* was [4][4] 
	    */, yrot[16]	/* was [4][4] */, zrot[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static real xyrot[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern doublereal satan2_(real *, real *);
#else /* NO_PROTO */
    extern doublereal satan2_();
#endif /* NO_PROTO */

/* calculate Y-rotation (longitude shift), ie swing VPN around */
/* into the VN plane of the UVN system. */
    /* Parameter adjustments */
    vwormt -= 5;

    /* Function Body */
    r__1 = -(doublereal)satan2_(vpnx, vpnz);
    eroy_(&r__1, yrot);
/* transformed VPN: */
    etp3_(vpnx, vpny, vpnz, yrot, &tvx, &tvy, &tvz);
/* calculate X-rotation (latitude shift), ie swing VPN down */
/* to coincide with N axis */
    r__2 = -(doublereal)tvy;
    r__1 = -(doublereal)satan2_(&r__2, &tvz);
    erox_(&r__1, xrot);
/* calculate composite 1st Y, then X rotation: */
    ecom3_(xrot, yrot, xyrot);
/* calculate transformed view-up vector */
    etp3_(vupx, vupy, vupz, xyrot, &tvx, &tvy, &tvz);
/* calculate Z-rotation so as to swing view-up vector into */
/* vn plane, pointing up. */
    r__2 = -(doublereal)tvx;
    r__1 = -(doublereal)satan2_(&r__2, &tvy);
    eroz_(&r__1, zrot);
/* calculate shift for view ref pt */
    r__1 = -(doublereal)(*vwrx);
    r__2 = -(doublereal)(*vwry);
    r__3 = -(doublereal)(*vwrz);
    etr3_(&r__1, &r__2, &r__3, trmt);
/* compose into one matrix */
    ecom3_(xyrot, trmt, wk);
    ecom3_(zrot, wk, &vwormt[5]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eevom3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/eevom                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int eevom_(real *vwrx, real *vwry, real *vupx, real *vupy, 
	real *vwormt)
#else /* NO_PROTO */
/* Subroutine */ int eevom_(vwrx, vwry, vupx, vupy, vwormt)
real *vwrx, *vwry, *vupx, *vupy, *vwormt;
#endif /* NO_PROTO */
{
    static real u, wk[16]	/* was [4][4] */, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int red43_(real *, real *), eevom3_(real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int red43_(), eevom3_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Parameter adjustments */
    vwormt -= 4;

    /* Function Body */
#ifndef NO_PROTO
    zz = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    zz = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    eevom3_(vwrx, vwry, &zz, &zz, &zz, &u, vupx, vupy, &zz, wk);
    red43_(wk, &vwormt[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eevom_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/eevmm                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int eevmm_(real *vwwnlm, real *pjvplm, real *vwmpmt)
#else /* NO_PROTO */
/* Subroutine */ int eevmm_(vwwnlm, pjvplm, vwmpmt)
real *vwwnlm, *pjvplm, *vwmpmt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_();
#endif /* NO_PROTO */

/* note: no 3D version (eevmm3) because standard does not specify */
/* a unique transformation. */
    /* Parameter adjustments */
    vwmpmt -= 4;
    --pjvplm;
    --vwwnlm;

    /* Function Body */
    r__1 = pjvplm[1] - vwwnlm[1];
    r__2 = pjvplm[3] - vwwnlm[3];
    r__3 = (pjvplm[2] - pjvplm[1]) / (vwwnlm[2] - vwwnlm[1]);
    r__4 = (pjvplm[4] - pjvplm[3]) / (vwwnlm[4] - vwwnlm[3]);
    ebltm_(&vwwnlm[1], &vwwnlm[3], &r__1, &r__2, &c_b40, &r__3, &r__4, &
	    vwmpmt[4]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* eevmm_ */

/**** *** *** *** ***   End of PHIGS-mimicking routines;  *** *** *** *** ***
*/
/**** *** *** *** ***   General-purpose PVT math routines   *** *** *** *** *
***/
/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/matmul                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int matmul_(integer *m, integer *n, integer *p, real *a, 
	real *b, real *c)
#else /* NO_PROTO */
/* Subroutine */ int matmul_(m, n, p, a, b, c)
integer *m, *n, *p;
real *a, *b, *c;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Local variables */
    static integer i, j, k;
    static real tot;

/* general purpose matrix multiply - multiplies an MxN array (A) */
/* by a NxP array (B) to yield an MxP array (C). */
    /* Parameter adjustments */
    c_dim1 = *m;
    c_offset = c_dim1 + 1;
    c -= c_offset;
    b_dim1 = *n;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    a_dim1 = *m;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *m;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *p;
	for (j = 1; j <= i__2; ++j) {
#ifndef NO_PROTO
	    tot = 0.f;
#else /* NO_PROTO */
	    tot = (float)0.;
#endif /* NO_PROTO */
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
		tot += a[i + k * a_dim1] * b[k + j * b_dim1];
/* L300: */
	    }
	    c[i + j * c_dim1] = tot;
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* matmul_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/idmat                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int idmat_(integer *sz, real *mat)
#else /* NO_PROTO */
/* Subroutine */ int idmat_(sz, mat)
integer *sz;
real *mat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer mat_dim1, mat_offset, i__1, i__2;

    /* Local variables */
    static integer i, j;

/* General purpose routine to initialize a square matrix to */
/* the identity matrix. */
    /* Parameter adjustments */
    mat_dim1 = *sz;
    mat_offset = mat_dim1 + 1;
    mat -= mat_offset;

    /* Function Body */
    i__1 = *sz;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *sz;
	for (j = 1; j <= i__2; ++j) {
	    if (i == j) {
#ifndef NO_PROTO
		mat[i + j * mat_dim1] = 1.f;
#else /* NO_PROTO */
		mat[i + j * mat_dim1] = (float)1.;
#endif /* NO_PROTO */
	    } else {
#ifndef NO_PROTO
		mat[i + j * mat_dim1] = 0.f;
#else /* NO_PROTO */
		mat[i + j * mat_dim1] = (float)0.;
#endif /* NO_PROTO */
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* idmat_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/arrtp3                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int arrtp3_(integer *nsz, real *xi, real *yi, real *zi, real 
	*xfrmt, real *xo, real *yo, real *zo)
#else /* NO_PROTO */
/* Subroutine */ int arrtp3_(nsz, xi, yi, zi, xfrmt, xo, yo, zo)
integer *nsz;
real *xi, *yi, *zi, *xfrmt, *xo, *yo, *zo;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_();
#endif /* NO_PROTO */

/*  This subroutine transforms a list of 3D points according to the */
/*  given matrix. */
/*  Input parameters: */
/*    NSZ      : number of points */
/*    XI,YI,ZI : points to be transformed */
/*    XFRMT    : matrix containing transformation */
/*  Output parameters: */
/*    XO,YO,ZO : points after being transformed */
    /* Parameter adjustments */
    --zo;
    --yo;
    --xo;
    xfrmt -= 5;
    --zi;
    --yi;
    --xi;

    /* Function Body */
    i__1 = *nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	etp3_(&xi[ix], &yi[ix], &zi[ix], &xfrmt[5], &xo[ix], &yo[ix], &zo[ix])
		;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* arrtp3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/red43                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int red43_(real *m4, real *m3)
#else /* NO_PROTO */
/* Subroutine */ int red43_(m4, m3)
real *m4, *m3;
#endif /* NO_PROTO */
{
    static integer i, j, ir, jr;

/* General purpose routine to reduce a 4x4 matrix to 3x3, by */
/* suppressing 3rd row and column */
    /* Parameter adjustments */
    m3 -= 4;
    m4 -= 5;

    /* Function Body */
    for (i = 1; i <= 4; ++i) {
	ir = min(i,3);
	for (j = 1; j <= 4; ++j) {
	    jr = min(j,3);
	    m3[ir + jr * 3] = m4[i + (j << 2)];
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* red43_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/exp34                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int exp34_(real *mat3, real *mat4)
#else /* NO_PROTO */
/* Subroutine */ int exp34_(mat3, mat4)
real *mat3, *mat4;
#endif /* NO_PROTO */
{
    static integer i, j;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static integer irecv, jrecv;

/*  Expand a 3x3 matrix into a 4x4 matrix. */
    /* Parameter adjustments */
    mat4 -= 5;
    mat3 -= 4;

    /* Function Body */
    idmat_(&c__4, &mat4[5]);
    for (i = 1; i <= 3; ++i) {
	if (i == 3) {
	    irecv = 4;
	} else {
	    irecv = i;
	}
	for (j = 1; j <= 3; ++j) {
	    if (j == 3) {
		jrecv = 4;
	    } else {
		jrecv = j;
	    }
	    mat4[irecv + (jrecv << 2)] = mat3[i + j * 3];
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* exp34_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION TR/trnseq                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical trnseq_(integer *sz, real *actmat, real *expmat)
#else /* NO_PROTO */
logical trnseq_(sz, actmat, expmat)
integer *sz;
real *actmat, *expmat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer actmat_dim1, actmat_offset, expmat_dim1, expmat_offset, i__1, 
	    i__2;
    real r__1, r__2;
    logical ret_val;

    /* Local variables */
    static integer i, j;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real ascale, bscale;

/*  Test two square matrices to see if they represent the same homogeneous
 */
/*  transformation.  Each transformation has an infinite number of */
/*  representations, because the matrix is scaled by element (sz,sz). */
    /* Parameter adjustments */
    expmat_dim1 = *sz;
    expmat_offset = expmat_dim1 + 1;
    expmat -= expmat_offset;
    actmat_dim1 = *sz;
    actmat_offset = actmat_dim1 + 1;
    actmat -= actmat_offset;

    /* Function Body */
    ascale = actmat[*sz + *sz * actmat_dim1];
    bscale = expmat[*sz + *sz * expmat_dim1];
#ifndef NO_PROTO
    if (ascale * bscale == 0.f) {
#else /* NO_PROTO */
    if (ascale * bscale == (float)0.) {
#endif /* NO_PROTO */
/* at least one is zero */
	if (ascale == bscale) {
/* both are zero - set to 1.0 - both matrices represent transforma
tion to */
/* points at infinity */
#ifndef NO_PROTO
	    ascale = 1.f;
	    bscale = 1.f;
#else /* NO_PROTO */
	    ascale = (float)1.;
	    bscale = (float)1.;
#endif /* NO_PROTO */
	} else {
/* one zero and one not - */
	    ret_val = FALSE_;
	    return ret_val;
	}
    }
    i__1 = *sz;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *sz;
	for (j = 1; j <= i__2; ++j) {
	    r__1 = actmat[i + j * actmat_dim1] / ascale;
	    r__2 = expmat[i + j * expmat_dim1] / bscale;
	    if (! appeq_(&r__1, &r__2, &c_b60, &c_b61)) {
		ret_val = FALSE_;
		return ret_val;
	    }
/* L200: */
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* trnseq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION TR/satan2                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal satan2_(real *y, real *x)
#else /* NO_PROTO */
doublereal satan2_(y, x)
real *y, *x;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    double atan2(doublereal, doublereal);
#else /* NO_PROTO */
    double atan2();
#endif /* NO_PROTO */

/*  Safe version of arctan-2 function; returns zero when both x and y */
/*  are zero. */
#ifndef NO_PROTO
    if (*x == 0.f && *y == 0.f) {
	ret_val = 0.f;
#else /* NO_PROTO */
    if (*x == (float)0. && *y == (float)0.) {
	ret_val = (float)0.;
#endif /* NO_PROTO */
    } else {
	ret_val = atan2(*y, *x);
    }
    return ret_val;
} /* satan2_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION TR/vecl2                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal vecl2_(real *vx, real *vy, real *vz)
#else /* NO_PROTO */
doublereal vecl2_(vx, vy, vz)
real *vx, *vy, *vz;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  This function returns the squared length of a 3D vector. */
    ret_val = *vx * *vx + *vy * *vy + *vz * *vz;
    return ret_val;
} /* vecl2_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION TR/vecl                              * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal vecl_(real *vx, real *vy, real *vz)
#else /* NO_PROTO */
doublereal vecl_(vx, vy, vz)
real *vx, *vy, *vz;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_();
#endif /* NO_PROTO */

/*  This function returns the length of a 3D vector. */
    ret_val = sqrt(vecl2_(vx, vy, vz));
    return ret_val;
} /* vecl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/vec1                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int vec1_(real *vx, real *vy, real *vz, real *vx1, real *vy1,
	 real *vz1)
#else /* NO_PROTO */
/* Subroutine */ int vec1_(vx, vy, vz, vx1, vy1, vz1)
real *vx, *vy, *vz, *vx1, *vy1, *vz1;
#endif /* NO_PROTO */
{
    static real d;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */

/*  This subroutine accepts an arbitrary 3D vector and returns a */
/*  parallel vector normalized to unit size. */
    d = vecl_(vx, vy, vz);
    *vx1 = *vx / d;
    *vy1 = *vy / d;
    *vz1 = *vz / d;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* vec1_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION TR/dotprd                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal dotprd_(real *vx1, real *vy1, real *vz1, real *vx2, real *vy2, 
	real *vz2)
#else /* NO_PROTO */
doublereal dotprd_(vx1, vy1, vz1, vx2, vy2, vz2)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  This function accepts two 3D vectors and returns their dot product. */

    ret_val = *vx1 * *vx2 + *vy1 * *vy2 + *vz1 * *vz2;
    return ret_val;
} /* dotprd_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION TR/vecang                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal vecang_(real *vx1, real *vy1, real *vz1, real *vx2, real *vy2, 
	real *vz2)
#else /* NO_PROTO */
doublereal vecang_(vx1, vy1, vz1, vx2, vy2, vz2)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    double acos(doublereal);
#else /* NO_PROTO */
    double acos();
#endif /* NO_PROTO */

    /* Local variables */
    static real vl;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern doublereal vecl_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static real cosval;
#ifndef NO_PROTO
    extern doublereal dotprd_(real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern doublereal dotprd_();
#endif /* NO_PROTO */

/*  This function accepts two 3D vectors and returns the */
/*  angle between them. */
    vl = vecl_(vx1, vy1, vz1) * vecl_(vx2, vy2, vz2);
#ifndef NO_PROTO
    if (vl == 0.f) {
	ret_val = 0.f;
#else /* NO_PROTO */
    if (vl == (float)0.) {
	ret_val = (float)0.;
#endif /* NO_PROTO */
    } else {
	cosval = dotprd_(vx1, vy1, vz1, vx2, vy2, vz2) / vl;
#ifndef NO_PROTO
	if (dabs(cosval) > 1.f) {
#else /* NO_PROTO */
	if (dabs(cosval) > (float)1.) {
#endif /* NO_PROTO */
	    unmsg_("Unstable parameters passed to VECANG.", 37L);
	}
	ret_val = acos(cosval);
    }
    return ret_val;
} /* vecang_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/crossp                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int crossp_(real *vx1, real *vy1, real *vz1, real *vx2, real 
	*vy2, real *vz2, real *vx3, real *vy3, real *vz3)
#else /* NO_PROTO */
/* Subroutine */ int crossp_(vx1, vy1, vz1, vx2, vy2, vz2, vx3, vy3, vz3)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2, *vx3, *vy3, *vz3;
#endif /* NO_PROTO */
{
/*  This subroutine accepts two 3D vectors and returns their */
/*  cross product. */
    *vx3 = *vy1 * *vz2 - *vz1 * *vy2;
    *vy3 = *vz1 * *vx2 - *vx1 * *vz2;
    *vz3 = *vx1 * *vy2 - *vy1 * *vx2;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* crossp_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/prpv1                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int prpv1_(real *vx1, real *vy1, real *vz1, real *vx2, real *
	vy2, real *vz2)
#else /* NO_PROTO */
/* Subroutine */ int prpv1_(vx1, vy1, vz1, vx2, vy2, vz2)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2;
#endif /* NO_PROTO */
{
    static real z;

/*  PRPV1 accepts a 3D vector and returns another 3D vector */
/*  perpendicular to it. */
#ifndef NO_PROTO
    z = 0.f;
#else /* NO_PROTO */
    z = (float)0.;
#endif /* NO_PROTO */
    *vx2 = z;
    *vy2 = z;
    *vz2 = z;
    if (*vx1 == z) {
#ifndef NO_PROTO
	*vx2 = 1.f;
#else /* NO_PROTO */
	*vx2 = (float)1.;
#endif /* NO_PROTO */
    } else if (*vy1 == z) {
#ifndef NO_PROTO
	*vy2 = 1.f;
#else /* NO_PROTO */
	*vy2 = (float)1.;
#endif /* NO_PROTO */
    } else if (*vz1 == z) {
#ifndef NO_PROTO
	*vz2 = 1.f;
#else /* NO_PROTO */
	*vz2 = (float)1.;
#endif /* NO_PROTO */
    } else {
	*vx2 = *vy1;
	*vy2 = -(doublereal)(*vx1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prpv1_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/pervec                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pervec_(real *vx1, real *vy1, real *vz1, real *vx2, real 
	*vy2, real *vz2, real *vx3, real *vy3, real *vz3)
#else /* NO_PROTO */
/* Subroutine */ int pervec_(vx1, vy1, vz1, vx2, vy2, vz2, vx3, vy3, vz3)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2, *vx3, *vy3, *vz3;
#endif /* NO_PROTO */
{
    static real k;
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *), dotprd_(real *, real *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_(), dotprd_();
#endif /* NO_PROTO */

/*  This subroutine accepts two 3D vectors and returns a vector */
/*  orthogonal to the first, in the plane of the first two vectors, */
/*  whose dot product with the second vector is positive, hence */
/*  the angle between them is < 90 degrees.  I.e. the 2nd vector */
/*  minus the 3rd results in a vector with the same direction (but */
/*  not length) as the 1st.  K is the factor by which V1 is */
/*  multiplied and then subtracted from V2 - i.e. */

/*       V3 = V2 - K*V1 */
/*                     _ */
/*                     /|A */
/*                   /   | */
/*                 /     | */
/*            V2 /       | V3 */
/*             /         | */
/*           /           | */
/*         /             | */
/*       /               | */
/*      ----------->.....| */
/*          V1 */
/*      \________________/ */
/*           V2 - V3 */
/*  Or, V1 can be thought of as the attitude numbers for a plane, and */
/*  then V3 is the result of the normal projection of V2 into the plane. 
*/

/*  Closely related to PTPLDS, which is a slightly more general case. */
    k = dotprd_(vx1, vy1, vz1, vx2, vy2, vz2) / vecl2_(vx1, vy1, vz1);
    *vx3 = *vx2 - k * *vx1;
    *vy3 = *vy2 - k * *vy1;
    *vz3 = *vz2 - k * *vz1;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pervec_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ptplds                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ptplds_(real *px, real *py, real *pz, real *a, real *b, 
	real *c, real *d, real *xn, real *yn, real *zn, real *dist)
#else /* NO_PROTO */
/* Subroutine */ int ptplds_(px, py, pz, a, b, c, d, xn, yn, zn, dist)
real *px, *py, *pz, *a, *b, *c, *d, *xn, *yn, *zn, *dist;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, sq, sol;
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_();
#endif /* NO_PROTO */

/* Given a point and plane-coefficients, find nearest */
/* point on plane and distance from plane to point. */
    sq = vecl2_(a, b, c);
    sol = *a * *px + *b * *py + *c * *pz + *d;
    *dist = dabs(sol) / sqrt(sq);
    u = -(doublereal)sol / sq;
    *xn = *px + *a * u;
    *yn = *py + *b * u;
    *zn = *pz + *c * u;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ptplds_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/lnplpt                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int lnplpt_(real *lx, real *ly, real *lz, real *al, real *bl,
	 real *cl, real *ap, real *bp, real *cp, real *dp, real *xi, real *yi,
	 real *zi)
#else /* NO_PROTO */
/* Subroutine */ int lnplpt_(lx, ly, lz, al, bl, cl, ap, bp, cp, dp, xi, yi, 
	zi)
real *lx, *ly, *lz, *al, *bl, *cl, *ap, *bp, *cp, *dp, *xi, *yi, *zi;
#endif /* NO_PROTO */
{
    static real u;
#ifndef NO_PROTO
    extern doublereal dotprd_(real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal dotprd_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  Given a line and a plane, find point of intersection. */
/*  Input parameters */
/*    LX,LY,LZ    : point on the line */
/*    AL,BL,CL    : direction of line */
/*    AP,BP,CP,DP : co-efficients of plane */
/*  Output parameters */
/*    XI,YI,ZI    : point of intersection */
    u = -(doublereal)(dotprd_(ap, bp, cp, lx, ly, lz) + *dp) / dotprd_(ap, bp,
	     cp, al, bl, cl);
    *xi = *lx + *al * u;
    *yi = *ly + *bl * u;
    *zi = *lz + *cl * u;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* lnplpt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/pt3pl                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pt3pl_(real *x, real *y, real *z, real *a, real *b, real 
	*c, real *d)
#else /* NO_PROTO */
/* Subroutine */ int pt3pl_(x, y, z, a, b, c, d)
real *x, *y, *z, *a, *b, *c, *d;
#endif /* NO_PROTO */
{
/* Given 3 points, find containing plane */
    /* Parameter adjustments */
    --z;
    --y;
    --x;

    /* Function Body */
    *a = y[2] * z[3] + y[3] * z[1] + y[1] * z[2] - y[1] * z[3] - y[2] * z[1] 
	    - y[3] * z[2];
    *b = z[2] * x[3] + z[3] * x[1] + z[1] * x[2] - z[1] * x[3] - z[2] * x[1] 
	    - z[3] * x[2];
    *c = x[2] * y[3] + x[3] * y[1] + x[1] * y[2] - x[1] * y[3] - x[2] * y[1] 
	    - x[3] * y[2];
    *d = -(doublereal)(*a * x[1] + *b * y[1] + *c * z[1] + *a * x[2] + *b * y[
	    2] + *c * z[2] + *a * x[3] + *b * y[3] + *c * z[3]) / 3;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pt3pl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ptspl                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ptspl_(integer *ilim, real *x, real *y, real *z, real *a,
	 real *b, real *c, real *d)
#else /* NO_PROTO */
/* Subroutine */ int ptspl_(ilim, x, y, z, a, b, c, d)
integer *ilim;
real *x, *y, *z, *a, *b, *c, *d;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ia;
    static real al, bl, cl, xl, yl, zl, xn, yn, zn, xt[3], yt[3], zt[3];
    static integer ihi, ilo;
    static real sep, dist, xsep, ysep, zsep;
#ifndef NO_PROTO
    extern /* Subroutine */ int pt3pl_(real *, real *, real *, real *, real *,
	     real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pt3pl_();
#endif /* NO_PROTO */
    static integer ibest, ixmin, iymin, ixmax, iymax, izmax, izmin;
#ifndef NO_PROTO
    extern /* Subroutine */ int ptlnds_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ptlnds_();
#endif /* NO_PROTO */
    static real distmx;

/*  Given a set of supposedly co-planar points, find containing */
/*  plane.  Idea here is to find 2 points at greatest separation */
/*  along a principal axis (x, y, or z) and then select 3rd point */
/*  as the one with greatest distance from the line connecting */
/*  these 2 points.  This is an attempt to find 3 "good" (widely */
/*  separated, highly non-colinear) points for computing the plane. */
/*  If there are 3 non-colinear points, this will find them. */
    /* Parameter adjustments */
    --z;
    --y;
    --x;

    /* Function Body */
    ixmax = 1;
    ixmin = 1;
    iymax = 1;
    iymin = 1;
    izmax = 1;
    izmin = 1;
/*  find min,max points for x,y,z */
    i__1 = *ilim;
    for (ia = 2; ia <= i__1; ++ia) {
	if (x[ia] > x[ixmax]) {
	    ixmax = ia;
	}
	if (x[ia] < x[ixmin]) {
	    ixmin = ia;
	}
	if (y[ia] > y[iymax]) {
	    iymax = ia;
	}
	if (y[ia] < y[iymin]) {
	    iymin = ia;
	}
	if (z[ia] > z[izmax]) {
	    izmax = ia;
	}
	if (z[ia] < z[izmin]) {
	    izmin = ia;
	}
/* L100: */
    }
    xsep = x[ixmax] - x[ixmin];
    ysep = y[iymax] - y[iymin];
    zsep = z[izmax] - z[izmin];
/*  take largest of the three separations: */
    if (xsep > ysep) {
	ihi = ixmax;
	ilo = ixmin;
	sep = xsep;
    } else {
	ihi = iymax;
	ilo = iymin;
	sep = ysep;
    }
    if (zsep > sep) {
	ihi = izmax;
	ilo = izmin;
    }
/*  use two widely separated points as axis for plane */
    xt[0] = x[ilo];
    yt[0] = y[ilo];
    zt[0] = z[ilo];
    xt[1] = x[ihi];
    yt[1] = y[ihi];
    zt[1] = z[ihi];
/*  Parameters for axis */
    al = xt[1] - xt[0];
    bl = yt[1] - yt[0];
    cl = zt[1] - zt[0];
    xl = xt[0];
    yl = yt[0];
    zl = zt[0];
/*  as 3rd point, use one with greatest distance from line */
#ifndef NO_PROTO
    distmx = -1.1f;
#else /* NO_PROTO */
    distmx = (float)-1.1;
#endif /* NO_PROTO */
    i__1 = *ilim;
    for (ia = 1; ia <= i__1; ++ia) {
	ptlnds_(&x[ia], &y[ia], &z[ia], &al, &bl, &cl, &xl, &yl, &zl, &xn, &
		yn, &zn, &dist);
	if (dist > distmx) {
	    distmx = dist;
	    ibest = ia;
	}
/* L200: */
    }
    xt[2] = x[ibest];
    yt[2] = y[ibest];
    zt[2] = z[ibest];
    pt3pl_(xt, yt, zt, a, b, c, d);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ptspl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/pl2pl                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pl2pl_(real *ar, real *br, real *cr, real *dr, real *ax, 
	real *bx, real *cx, real *dx, real *ap, real *bp, real *cp, real *dp)
#else /* NO_PROTO */
/* Subroutine */ int pl2pl_(ar, br, cr, dr, ax, bx, cx, dx, ap, bp, cp, dp)
real *ar, *br, *cr, *dr, *ax, *bx, *cx, *dx, *ap, *bp, *cp, *dp;
#endif /* NO_PROTO */
{
    static real al, bl, cl, px, py, pz;
#ifndef NO_PROTO
    extern /* Subroutine */ int pl2ln_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), crossp_(real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pl2ln_(), crossp_();
#endif /* NO_PROTO */

/*  Given a reference plane (R) and an intersecting crossing plane */
/*  (X), find the perpendicular plane (P), which contains the line of */
/*  intersection of R and X, and is perpendicular to R. */
/*  get line of intersection of R and X */
    pl2ln_(ar, br, cr, dr, ax, bx, cx, dx, &al, &bl, &cl, &px, &py, &pz);
/*  cross-prod of line and ref plane is attitude of P-plane */
    crossp_(ar, br, cr, &al, &bl, &cl, ap, bp, cp);
/*  solve for dp, given point on line: */
    *dp = -(doublereal)(*ap * px + *bp * py + *cp * pz);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pl2pl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/pl2ln                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pl2ln_(real *a1, real *b1, real *c1, real *d1, real *a2, 
	real *b2, real *c2, real *d2, real *a, real *b, real *c, real *px, 
	real *py, real *pz)
#else /* NO_PROTO */
/* Subroutine */ int pl2ln_(a1, b1, c1, d1, a2, b2, c2, d2, a, b, c, px, py, 
	pz)
real *a1, *b1, *c1, *d1, *a2, *b2, *c2, *d2, *a, *b, *c, *px, *py, *pz;
#endif /* NO_PROTO */
{
    static integer ixyz;
#ifndef NO_PROTO
    extern integer abest3_(real *, real *, real *);
    extern /* Subroutine */ int crossp_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *), lintpt_(real *, real *, real *,
	     real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern integer abest3_();
    extern /* Subroutine */ int crossp_(), lintpt_();
#endif /* NO_PROTO */

/*  Given two planes, return line-intersection */
/*  Direction of line is cross-product of normal vectors */
    crossp_(a1, b1, c1, a2, b2, c2, a, b, c);
/*  use most stable variable as basis - effectively, use x=0, y=0, */
/*  or z=0 as 3rd plane. */
    ixyz = abest3_(a, b, c);
    if (ixyz == 1) {
#ifndef NO_PROTO
	*px = 0.f;
#else /* NO_PROTO */
	*px = (float)0.;
#endif /* NO_PROTO */
	lintpt_(b1, c1, d1, b2, c2, d2, py, pz);
    } else if (ixyz == 2) {
#ifndef NO_PROTO
	*py = 0.f;
#else /* NO_PROTO */
	*py = (float)0.;
#endif /* NO_PROTO */
	lintpt_(a1, c1, d1, a2, c2, d2, px, pz);
    } else {
#ifndef NO_PROTO
	*pz = 0.f;
#else /* NO_PROTO */
	*pz = (float)0.;
#endif /* NO_PROTO */
	lintpt_(a1, b1, d1, a2, b2, d2, px, py);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pl2ln_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION TR/abest3                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer abest3_(real *aa, real *ba, real *ca)
#else /* NO_PROTO */
integer abest3_(aa, ba, ca)
real *aa, *ba, *ca;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static real a, b, c, best;

/*  function to pick greatest magnitude of 3 numbers */
    a = dabs(*aa);
    b = dabs(*ba);
    c = dabs(*ca);
    if (a > b) {
	ret_val = 1;
	best = a;
    } else {
	ret_val = 2;
	best = b;
    }
    if (c > best) {
	ret_val = 3;
    }
    return ret_val;
} /* abest3_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ptlnds                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ptlnds_(real *px, real *py, real *pz, real *a, real *b, 
	real *c, real *lx, real *ly, real *lz, real *xn, real *yn, real *zn, 
	real *dist)
#else /* NO_PROTO */
/* Subroutine */ int ptlnds_(px, py, pz, a, b, c, lx, ly, lz, xn, yn, zn, 
	dist)
real *px, *py, *pz, *a, *b, *c, *lx, *ly, *lz, *xn, *yn, *zn, *dist;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real u, dp, dx, dy, dz;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static real d2abc;
#ifndef NO_PROTO
    extern doublereal vecl2_(real *, real *, real *), dotprd_(real *, real *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl2_(), dotprd_();
#endif /* NO_PROTO */

/*  Given a point and a line, find nearest point on line and */
/*  distance from line to point. */
    dx = *px - *lx;
    dy = *py - *ly;
    dz = *pz - *lz;
    d2abc = vecl2_(a, b, c);
    dp = dotprd_(a, b, c, &dx, &dy, &dz);
    u = dp / d2abc;
    *xn = *lx + *a * u;
    *yn = *ly + *b * u;
    *zn = *lz + *c * u;
    r__1 = *px - *xn;
    r__2 = *py - *yn;
    r__3 = *pz - *zn;
    *dist = vecl_(&r__1, &r__2, &r__3);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ptlnds_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/lintpt                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int lintpt_(real *a, real *b, real *c, real *d, real *e, 
	real *f, real *x, real *y)
#else /* NO_PROTO */
/* Subroutine */ int lintpt_(a, b, c, d, e, f, x, y)
real *a, *b, *c, *d, *e, *f, *x, *y;
#endif /* NO_PROTO */
{
    static real den;

/* Given two sets of line-coefficients, find intersection point */
    den = *d * *b - *a * *e;
    *x = (*c * *e - *f * *b) / den;
    *y = (*f * *a - *c * *d) / den;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* lintpt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/pt2cof                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pt2cof_(real *x1, real *y1, real *x2, real *y2, real *a, 
	real *b, real *c)
#else /* NO_PROTO */
/* Subroutine */ int pt2cof_(x1, y1, x2, y2, a, b, c)
real *x1, *y1, *x2, *y2, *a, *b, *c;
#endif /* NO_PROTO */
{
/* Given two points, calculate line coefficients. */
    *a = *y1 - *y2;
    *b = *x2 - *x1;
    *c = *x1 * *y2 - *y1 * *x2;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pt2cof_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/parcof                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int parcof_(real *x0, real *y0, real *xcoeff, real *ycoeff, 
	real *a, real *b, real *c)
#else /* NO_PROTO */
/* Subroutine */ int parcof_(x0, y0, xcoeff, ycoeff, a, b, c)
real *x0, *y0, *xcoeff, *ycoeff, *a, *b, *c;
#endif /* NO_PROTO */
{
/*  given parametric form, find line coefficients */
    *a = *ycoeff;
    *b = -(doublereal)(*xcoeff);
    *c = *xcoeff * *y0 - *ycoeff * *x0;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* parcof_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION TR/ptregd                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal ptregd_(real *px, real *py, real *pz, integer *nsz, real *xa, real 
	*ya, real *za)
#else /* NO_PROTO */
doublereal ptregd_(px, py, pz, nsz, xa, ya, za)
real *px, *py, *pz;
integer *nsz;
real *xa, *ya, *za;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real ret_val, r__1, r__2, r__3;

    /* Local variables */
    static real d1, d2;
    static integer ia, ib;
    static real xn, yn, zn, abcp, sega, segb, segc;
    static integer side;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static real dtmp, ptmin;
#ifndef NO_PROTO
    extern /* Subroutine */ int invol_(real *, real *, real *, integer *, 
	    real *, real *, real *, integer *, real *), unmsg_(char *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int invol_(), unmsg_();
#endif /* NO_PROTO */
    static real edgmin, pldist;
#ifndef NO_PROTO
    extern /* Subroutine */ int ptlnds_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ptlnds_();
#endif /* NO_PROTO */

/*  PTREGD computes the minimum distance from a 3D point to a planar */
/*  3D region. */
/* Input parameters: */
/*   PX,PY,PZ : point for which distance is found. */
/*   NSZ      : number of points in region. */
/*   XA,YA,ZA : coordinates of planar region. */
    /* Parameter adjustments */
    --za;
    --ya;
    --xa;

    /* Function Body */
    if (*nsz < 3) {
	unmsg_("Degenerate region passed to PTREGD.", 35L);
    }
    invol_(px, py, pz, nsz, &xa[1], &ya[1], &za[1], &side, &pldist);
    if (side <= 2) {
/*  Distance is simply distance of point from containing plane */
	ret_val = pldist;
	return ret_val;
    }
/*  Distance is minimum of distances from points and from individual edges
 */
/*  Get point minimum: */
#ifndef NO_PROTO
    ptmin = 1e38f;
#else /* NO_PROTO */
    ptmin = (float)1e38;
#endif /* NO_PROTO */
    i__1 = *nsz;
    for (ia = 1; ia <= i__1; ++ia) {
	r__1 = *px - xa[ia];
	r__2 = *py - ya[ia];
	r__3 = *pz - za[ia];
	dtmp = vecl_(&r__1, &r__2, &r__3);
	if (dtmp < ptmin) {
	    ptmin = dtmp;
	}
/* L100: */
    }
/*  Get edge minimum: */
#ifndef NO_PROTO
    edgmin = 1e38f;
#else /* NO_PROTO */
    edgmin = (float)1e38;
#endif /* NO_PROTO */
    i__1 = *nsz;
    for (ia = 1; ia <= i__1; ++ia) {
	ib = ia % *nsz + 1;
/*  Determine if point is between the two planes that contain the */
/*  endpoints of the segment, and are normal to it.  If not, ignore - 
*/
/*  handled by point minimum.  If so, distance is that from point to 
*/
/*  containing line. */
/*  attitude of planes: */
	sega = xa[ia] - xa[ib];
	segb = ya[ia] - ya[ib];
	segc = za[ia] - za[ib];
/*  d-coefficient of each plane: */
	d1 = -(doublereal)(sega * xa[ia] + segb * ya[ia] + segc * za[ia]);
	d2 = -(doublereal)(sega * xa[ib] + segb * ya[ib] + segc * za[ib]);
/*  ABC terms for px,py,pz: */
	abcp = sega * *px + segb * *py + segc * *pz;
#ifndef NO_PROTO
	if ((abcp + d1) * (abcp + d2) < 0.f) {
#else /* NO_PROTO */
	if ((abcp + d1) * (abcp + d2) < (float)0.) {
#endif /* NO_PROTO */
/*  Opposite signs imply point is between planes - get distance fr
om */
/*  point to line. */
	    ptlnds_(px, py, pz, &sega, &segb, &segc, &xa[ia], &ya[ia], &za[ia]
		    , &xn, &yn, &zn, &dtmp);
	    if (dtmp < edgmin) {
		edgmin = dtmp;
	    }
	}
/* L200: */
    }
    ret_val = dmin(ptmin,edgmin);
    return ret_val;
} /* ptregd_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION TR/ceilng                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer ceilng_(real *x)
#else /* NO_PROTO */
integer ceilng_(x)
real *x;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer ix;

/*  CEILNG returns the integer ceiling for x, i.e. the lowest */
/*  integer .ge. x */
    ix = (integer) (*x);
#ifndef NO_PROTO
    if ((real) ix == *x || *x <= 0.f) {
#else /* NO_PROTO */
    if ((real) ix == *x || *x <= (float)0.) {
#endif /* NO_PROTO */
	ret_val = ix;
    } else {
	ret_val = ix + 1;
    }
    return ret_val;
} /* ceilng_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION TR/mod1                           * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer mod1_(integer *x, integer *m)
#else /* NO_PROTO */
integer mod1_(x, m)
integer *x, *m;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer xw;

/*  MOD1 returns X mod M, but coerced between 1 and M, not between */
/*  0 and M-1. */
    if (*x < 0) {
	xw = *x - (*x / *m - 2) * *m;
    } else {
	xw = *x;
    }
    ret_val = xw % *m;
    if (ret_val <= 0) {
	ret_val = *m;
    }
    return ret_val;
} /* mod1_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/invol                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int invol_(real *px, real *py, real *pz, integer *ilim, real 
	*arx, real *ary, real *arz, integer *side, real *pldist)
#else /* NO_PROTO */
/* Subroutine */ int invol_(px, py, pz, ilim, arx, ary, arz, side, pldist)
real *px, *py, *pz;
integer *ilim;
real *arx, *ary, *arz;
integer *side;
real *pldist;
#endif /* NO_PROTO */
{
    static real a, b, c, d, xn, yn, zn;
    static integer idim;
    static real best;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), ptspl_(integer *, 
	    real *, real *, real *, real *, real *, real *, real *);
    extern integer inarea_(real *, real *, integer *, real *, real *);
    extern /* Subroutine */ int ptplds_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), ptspl_();
    extern integer inarea_();
    extern /* Subroutine */ int ptplds_();
#endif /* NO_PROTO */

/*  Given a 3D point and planar fill area, determine whether point */
/*  is within normal projection of the area, and distance of point */
/*  from the plane. */
/*  Input parameters: */
/*    PX,PY,PZ     : 3D point */
/*    ILIM         : Number of vertices of fill area */
/*    ARX,ARY,ARZ  : vertices of fill area */
/*  Output parameters: */
/*    SIDE         : location of point within volume - */
/*                 : 1 if inside, 2 if on an edge, 3 if outside */
/*    PLDIST       : distance of point from the plane. */
    /* Parameter adjustments */
    --arz;
    --ary;
    --arx;

    /* Function Body */
    if (*ilim < 3) {
	unmsg_("Degenerate fill area passed to INVOL.", 37L);
    }
/* get plane from set of points */
    ptspl_(ilim, &arx[1], &ary[1], &arz[1], &a, &b, &c, &d);
/* Given a point and plane-coefficients, find nearest */
/* point on plane and distance from plane to point. */
    ptplds_(px, py, pz, &a, &b, &c, &d, &xn, &yn, &zn, pldist);
/*  Now project the planar points (fill area, plus the normal */
/*  projected point xn,yn,zn) to the "best" plane: x=0, y=0, or z=0, */
/*  depending on largest attitude number. */
    if (dabs(a) > dabs(b)) {
	idim = 1;
	best = dabs(a);
    } else {
	idim = 2;
	best = dabs(b);
    }
    if (dabs(c) > best) {
	idim = 3;
    }
    if (idim == 1) {
/* project to x=0 */
	*side = inarea_(&yn, &zn, ilim, &ary[1], &arz[1]);
    } else if (idim == 2) {
/* project to y=0 */
	*side = inarea_(&xn, &zn, ilim, &arx[1], &arz[1]);
    } else {
/* project to z=0 */
	*side = inarea_(&xn, &yn, ilim, &arx[1], &ary[1]);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* invol_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION TR/inarea                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer inarea_(real *px, real *py, integer *ilim, real *x, real *y)
#else /* NO_PROTO */
integer inarea_(px, py, ilim, x, y)
real *px, *py;
integer *ilim;
real *x, *y;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static real a, b, c;
    static integer ia, ib;
    static real xa, ya, xb, yb;
    static integer ix, ict, icur;
    static real xcur, ycur, yint;
    static integer iprev;
    static real xprev, yprev;
#ifndef NO_PROTO
    extern /* Subroutine */ int pt2cof_(real *, real *, real *, real *, real *
	    , real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pt2cof_();
#endif /* NO_PROTO */
    static integer cursgn, icross;

/*    Given a 2D point and fill area, determine whether point */
/*    is within the area, on edge, or outside. */
/*  Input parameters: */
/*    PX,PY  : 2D point */
/*    ILIM   : Number of vertices of fill area */
/*    X,Y    : vertices of fill area */
/*   Function returns: */
/*       1 : inside */
/*       2 : on an edge */
/*       3 : outside */
/*  Idea here is to generate a ray straight up from px,py (positive */
/*  y-direction), and see how many times it crosses the border. */
/*  First see if px,py is on any edge: */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    i__1 = *ilim;
    for (ia = 1; ia <= i__1; ++ia) {
	ib = ia % *ilim + 1;
	xa = x[ia];
	ya = y[ia];
	xb = x[ib];
	yb = y[ib];
/* Given two points, calculate line coefficients */
	pt2cof_(&xa, &ya, &xb, &yb, &a, &b, &c);
/* if not co-linear, skip */
#ifndef NO_PROTO
	if (a * *px + b * *py + c != 0.f) {
#else /* NO_PROTO */
	if (a * *px + b * *py + c != (float)0.) {
#endif /* NO_PROTO */
	    goto L100;
	}
/* if px,py between points, it's on edge: */
#ifndef NO_PROTO
	if ((xa - *px) * (xb - *px) <= 0.f && (ya - *py) * (yb - *py) <= 0.f) 
		{
#else /* NO_PROTO */
	if ((xa - *px) * (xb - *px) <= (float)0. && (ya - *py) * (yb - *py) <=
		 (float)0.) {
#endif /* NO_PROTO */
	    ret_val = 2;
	    return ret_val;
	}
L100:
	;
    }
/* OK, assume from here on that point is not on an edge; */
/* get point off y-axis */
    i__1 = *ilim;
    for (ix = 1; ix <= i__1; ++ix) {
	if (x[ix] == *px) {
	    goto L200;
	}
	if (x[ix] < *px) {
	    cursgn = -1;
	} else {
	    cursgn = 1;
	}
	iprev = ix;
	goto L210;
L200:
	;
    }
    ret_val = 3;
    return ret_val;
L210:
    icross = 0;
    xprev = x[iprev];
    yprev = y[iprev];
/* start of loop for checking edge segments */
    i__1 = *ilim - 1;
    for (ict = 0; ict <= i__1; ++ict) {
	icur = (iprev + ict) % *ilim + 1;
	xcur = x[icur];
	ycur = y[icur];
/* if not a definite crossing of y-axis (equal doesn't count), */
/* save last point and keep going ... */
#ifndef NO_PROTO
	if ((xcur - *px) * cursgn >= 0.f) {
#else /* NO_PROTO */
	if ((xcur - *px) * cursgn >= (float)0.) {
#endif /* NO_PROTO */
	    goto L290;
	}
/* crossed y-axis */
	cursgn = -cursgn;
/* last two points (cur and prev) determine whether crossing above */
/* or below px,py: */
	pt2cof_(&xcur, &ycur, &xprev, &yprev, &a, &b, &c);
/* formula for y-intercept of line:a,b,c and line:x=px */
	yint = -(doublereal)(a * *px + c) / b;
	if (yint > *py) {
	    ++icross;
	} else if (yint == *py) {
/* aha - on edge after all .. */
	    ret_val = 2;
	    return ret_val;
	}
L290:
	xprev = xcur;
	yprev = ycur;
/* L300: */
    }
    ret_val = 3 - (icross % 2 << 1);
    return ret_val;
} /* inarea_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/issdis                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int issdis_(real *sisrpx, real *sisrpy, real *sisrpz, real *
	sdist, real *xfrmt, integer *mclipi, char *expath, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int issdis_(sisrpx, sisrpy, sisrpz, sdist, xfrmt, mclipi, 
	expath, expath_len)
real *sisrpx, *sisrpy, *sisrpz, *sdist, *xfrmt;
integer *mclipi;
char *expath;
ftnlen expath_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), issab_(real *, real *, real *, real *, char *, 
	    integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), issab_();
#endif /* NO_PROTO */
    static real cosrpx, cosrpy, cosrpz;

/*  This subroutine invokes the 3D spatial search routine with the */
/*  search distance set just below and above the theoretically */
/*  correct distance.  The search always begins at the start of */
/*  structure #101.  Thus, the search should first be unsuccessful, */
/*  and then successful.  ISSDIS issues pass or fail as a result */
/*  of these two searches. */
/*  Input parameters: */
/*    SISRPX,Y,Z : untransformed search reference point */
/*    SDIST      : correct search distance */
/*    XFRMT      : matrix used to transform search reference point */
/*    MCLIPI     : clipping indicator to be used */
/*    EXPATH     : expected found path */
/*  transform search reference point */
    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    etp3_(sisrpx, sisrpy, sisrpz, &xfrmt[5], &cosrpx, &cosrpy, &cosrpz);
    issab_(&cosrpx, &cosrpy, &cosrpz, sdist, "101,0", mclipi, &c__1, expath, 
	    5L, expath_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issdis_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/issab                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int issab_(real *srpx, real *srpy, real *srpz, real *sdist, 
	char *stpath, integer *mclipi, integer *sceil, char *expath, ftnlen 
	stpath_len, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int issab_(srpx, srpy, srpz, sdist, stpath, mclipi, sceil, 
	expath, stpath_len, expath_len)
real *srpx, *srpy, *srpz, *sdist;
char *stpath;
integer *mclipi, *sceil;
char *expath;
ftnlen stpath_len;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), niss3 (real *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen, istlen, iexpth[200]	/* was [2][100] */, 
	    istpth[200]	/* was [2][100] */, fpthsz;

    /* Fortran I/O blocks */
    static icilist io___168 = { 0, msg, 0, "(A,I5,A)", 200, 1 };
    static icilist io___169 = { 0, msg, 0, "(A,I5,A)", 200, 1 };


/*  This subroutine invokes the 3D spatial search routine with the */
/*  search distance set just below and above the theoretically */
/*  correct distance.  Thus, the search should first be unsuccessful, */
/*  and then successful.  ISSAB issues pass or fail as a result */
/*  of these two searches. */
/*  Input parameters: */
/*    SRPX,Y,Z   : search reference point */
/*    SDIST      : correct search distance */
/*    STPATH     : starting path */
/*    MCLIPI     : modelling clipping indicator */
/*    SCEIL      : search ceiling */
/*    EXPATH     : expected found path */
    setvs_(stpath, istpth, &istlen, stpath_len);
    setvs_(expath, iexpth, &iexlen, expath_len);
#ifndef NO_PROTO
    r__1 = *sdist * .98f;
#else /* NO_PROTO */
    r__1 = *sdist * (float).98;
#endif /* NO_PROTO */
    i__1 = istlen / 2;
    niss3 (srpx, srpy, srpz, &r__1, &i__1, istpth, mclipi, sceil, &c__0, idum,
	     idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
	    errind, &fpthsz, fpath);
    if (errind == 0 && fpthsz == 0) {
/* OK so far */
    } else {
	fail_();
	s_wsfi(&io___168);
#ifndef NO_PROTO
	do_fio(&c__1, "ISS did not return null path as expected; error indic"
		"ator = ", 60L);
#else /* NO_PROTO */
	do_fio(&c__1, "ISS did not return null path as expected; error indic\
ator = ", 60L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 200L);
	return 0;
    }
#ifndef NO_PROTO
    r__1 = *sdist * 1.02f;
#else /* NO_PROTO */
    r__1 = *sdist * (float)1.02;
#endif /* NO_PROTO */
    i__1 = istlen / 2;
    niss3 (srpx, srpy, srpz, &r__1, &i__1, istpth, mclipi, sceil, &c__0, idum,
	     idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    if (errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth)) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___169);
#ifndef NO_PROTO
	do_fio(&c__1, "ISS did not return correct found path; error indicato"
		"r = ", 57L);
#else /* NO_PROTO */
	do_fio(&c__1, "ISS did not return correct found path; error indicato\
r = ", 57L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 200L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issab_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE TR/ispths                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ispths_(real *srpx, real *srpy, real *srpz, real *sdist, 
	integer *sceil, integer *mclipi, char *stpth, char *expths, ftnlen 
	stpth_len, ftnlen expths_len)
#else /* NO_PROTO */
/* Subroutine */ int ispths_(srpx, srpy, srpz, sdist, sceil, mclipi, stpth, 
	expths, stpth_len, expths_len)
real *srpx, *srpy, *srpz, *sdist;
integer *sceil, *mclipi;
char *stpth, *expths;
ftnlen stpth_len;
ftnlen expths_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), set2d_(char *, integer *, 
	    integer *, integer *, integer *, ftnlen), niss3 (real *, real *, 
	    real *, real *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), set2d_(), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[60]	/* was [2][30] */, ipath, exlen[30], spath[60]
	    	/* was [2][30] */, exnum;
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
    static integer errind, expath[900]	/* was [30][30] */, fpthsz;

/*  This subroutine repeatedly invokes spatial search, using the */
/*  found path of one search as the starting path for the next, and */
/*  issues pass or fail, depending on whether the actual paths match */
/*  those expected. */
/*  Input parameters: */
/*    SRPX,Y,Z : search reference point to be used in ISS's */
/*    SDIST    : search distance to be used in ISS's */
/*    SCEIL    : search ceiling to be used in ISS's */
/*    MCLIPI   : modelling clipping indicator */
/*    STPTH    : starting path for first ISS */
/*    EXPTHS   : sequence of expected found paths for ISS's */
    setvs_(stpth, spath, &spsiz, stpth_len);
    spsiz /= 2;
    set2d_(expths, &c__30, &exnum, exlen, expath, expths_len);
    i__1 = exnum;
    for (ipath = 1; ipath <= i__1; ++ipath) {
	niss3 (srpx, srpy, srpz, sdist, &spsiz, spath, mclipi, sceil, &c__0, 
		idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__30,
		 &errind, &fpthsz, fpath);
	i__2 = fpthsz << 1;
	if (errind == 0 && iareql_(&i__2, fpath, &exlen[ipath - 1], &expath[
		ipath * 30 - 30])) {
/* OK so far - copy found path to next starting path */
	    spsiz = fpthsz;
	    i__2 = spsiz;
	    for (ix = 1; ix <= i__2; ++ix) {
		spath[(ix << 1) - 2] = fpath[(ix << 1) - 2];
		spath[(ix << 1) - 1] = fpath[(ix << 1) - 1];
/* L110: */
	    }
	} else {
	    fail_();
	    return 0;
	}
/* L100: */
    }
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ispths_ */

