/* fort/04/02/04/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b4 = 0.f;
#else /* NO_PROTO */
static real c_b4 = (float)0.;
#endif /* NO_PROTO */
static integer c__7 = 7;
#ifndef NO_PROTO
static real c_b10 = .5f;
#else /* NO_PROTO */
static real c_b10 = (float).5;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b47 = .05f;
static real c_b48 = .35f;
#else /* NO_PROTO */
static real c_b47 = (float).05;
static real c_b48 = (float).35;
#endif /* NO_PROTO */
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.04.01/locat2                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locat2_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locat2_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    static real xa[1], ya[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int locatx_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
    extern doublereal ylocel_();
    extern /* Subroutine */ int locatx_();
#endif /* NO_PROTO */

/*  LOCAT2 draws an annotation text string at the real y-location */
/*  corresponding to the integer index given in YLOC, and puts a */
/*  polymarker at the text position. */
    xa[0] = *xval;
    ya[0] = ylocel_(yloc);
    npm (&c__1, xa, ya);
    locatx_(yloc, xval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locat2_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.04.01/locans                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locans_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locans_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real xoff = -.15f;
    static real yoff = .05f;
#else /* NO_PROTO */
    static real xoff = (float)-.15;
    static real yoff = (float).05;
#endif /* NO_PROTO */

    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    ;
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int wcnpc_();
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real npcpwc;

/*  LOCANS draws an annotation text primitive with a distinct */
/*  annotation point and reference point, at the real y-location */
/*  corresponding to the integer index given in YLOC. */
    wcnpc_(&c_b4, &c_b4, &npcx, &npcy, &npcpwc);
    r__1 = *xval - xoff;
    r__2 = ylocel_(yloc) - yoff;
    r__3 = xoff * npcpwc;
    r__4 = yoff * npcpwc;
    natr (&r__1, &r__2, &r__3, &r__4, "Hiho", 4L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locans_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.04.01/tsanup                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tsanup_(integer *txfont, integer *txpath, char *txstr, 
	integer *numout, integer *ngstr, ftnlen txstr_len)
#else /* NO_PROTO */
/* Subroutine */ int tsanup_(txfont, txpath, txstr, numout, ngstr, txstr_len)
integer *txfont, *txpath;
char *txstr;
integer *numout, *ngstr;
ftnlen txstr_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    double cos(), sin();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real z, xa[9], ya[9], xb[2], yb[2], xf[9]	/* was [3][3] */;
    static integer ix;
    static real scf;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static real xup, xrt, yrt, yup;
    static char dig2[2];
    static real htab[3], irad, orad, vtab[5], xvec, yvec;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static real cost, npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real sint;
    static logical vert;
    static integer algnh[7], algnv[7];
#ifndef NO_PROTO
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    , nbltm (real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int wcnpc_(), nbltm ();
#endif /* NO_PROTO */
    static real txang;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatp (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatp ();
#endif /* NO_PROTO */
    static real intsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static real ntxwd, ntxht;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxp (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxp ();
#endif /* NO_PROTO */
    static real labrad, reclng;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), nsatch (
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), nsatch ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatal ();
#endif /* NO_PROTO */
    static real recsht, npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsplci (integer *);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int setval_(char *, integer *, ftnlen), nsatcu (
	    real *, real *), txexal_(integer *, integer *, char *, real *, 
	    real *, real *, real *, ftnlen), nstxci (integer *), nstxal (
	    integer *, integer *), nstxfn (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsplci ();
    extern integer rndint_();
    extern /* Subroutine */ int setval_(), nsatcu (), txexal_(), nstxci (), 
	    nstxal (), nstxfn ();
#endif /* NO_PROTO */
    static real txposx, txposy;

    /* Fortran I/O blocks */
    static icilist io___39 = { 0, dig2, 0, "(A,I1)", 2, 1 };


/*  TSANUP draws an annotation text string with various values for */
/*  character up and for annotation text alignment.  The annotation */
/*  text strings are displayed along radii of a circle and are */
/*  enclosed by a text extent rectangle (except for one which is */
/*  deliberately drawn incorrectly).  TSANUP assumes that default */
/*  character height has been set to 1.0. */
/*  Input parameters: */
/*    TXFONT : Text font to be used */
/*    TXPATH : Annotation text path to be used */
/*    TXSTR  : Annotation text string to be used */
/*  Output parameters: */
/*    NUMOUT : Number of annotation text primitives drawn */
/*    NGSTR  : Identifier of incorrect annotation text primitive */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* linetype */
/*  numstr = number of strings to display */
    *numout = 7;
    vert = *txpath == 2 || *txpath == 3;
    nstxfn (txfont);
/*  use <inquire text extent> on txstr to determine: */
/*    ntxwd  = nominal width of text extent rectangle */
/*    ntxht  = nominal height of text extent rectangle */
/*    vtab,htab = normalized heights and widths */
    txexal_(txfont, txpath, txstr, &ntxwd, &ntxht, htab, vtab, txstr_len);
    if (vert) {
	reclng = ntxht;
	recsht = ntxwd;
    } else {
	reclng = ntxwd;
	recsht = ntxht;
    }
/*  ngstr = incorrect string identifier */
    *ngstr = rndint_(&c__1, &c__7);
/*  irad = inner radius of circle for display of annotation text strings 
*/
#ifndef NO_PROTO
    irad = recsht * 7 * 1.1f / 6.2831853000000004f;
#else /* NO_PROTO */
    irad = recsht * 7 * (float)1.1 / (float)6.2831853000000004;
#endif /* NO_PROTO */
/*  orad = outer radius of circle for display of annotation text strings 
*/
    orad = irad + reclng;
/*  set up transform to fit annotation text circle on screen, from MC */
/*  centered at origin, with radius orad to WC radius=0.4, centered */
/*  at 0.5,0.5 */
#ifndef NO_PROTO
    z = 0.f;
#else /* NO_PROTO */
    z = (float)0.;
#endif /* NO_PROTO */
/*  label radius factor */
#ifndef NO_PROTO
    labrad = 1.2f;
    scf = .45f / (labrad * orad);
#else /* NO_PROTO */
    labrad = (float)1.2;
    scf = (float).45 / (labrad * orad);
#endif /* NO_PROTO */
    nbltm (&z, &z, &c_b10, &c_b10, &z, &scf, &scf, &errind, xf);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xf, &c__0);
/*  set height for annotation text, apply scale factor directly, */
/*  since annotation text unaffected by transformation. */
    wcnpc_(&c_b4, &c_b4, &npcx, &npcy, &npcpwc);
    r__1 = npcpwc * scf;
    nsatch (&r__1);
/*  annotation text alignments to be used: */
/*     algnh    algnv */
/*     ------   ------ */
/*  1: center   base */
/*  2: left     cap */
/*  3: right    top */
/*  4: left     bottom */
/*  5: center   half */
/*  6: right    half */
/*  7: left     cap */
    setval_("2,1,3,1,2,3,1", algnh, 13L);
    setval_("4,2,1,5,3,3,2", algnv, 13L);
/* first draw labels and expected rectangles */
    nsplci (&c__2);
    nstxci (&c__1);
    nstxal (&c__2, &c__3);
    nstxp (&c__0);
    for (ix = 1; ix <= 7; ++ix) {
/*  txang = angle for annotation text string */
#ifndef NO_PROTO
	txang = (ix << 1) * 3.14159265f / 7;
#else /* NO_PROTO */
	txang = (ix << 1) * (float)3.14159265 / 7;
#endif /* NO_PROTO */
	cost = cos(txang);
	sint = sin(txang);
/*  draw rectangle for expected position of annotation text string, */

/*     based on txang, ntxwd,ntxht */
/*  first draw bottom line along radius */
	xa[0] = irad * cost;
	xa[4] = xa[0];
	xa[3] = (irad + reclng) * cost;
	ya[0] = irad * sint;
	ya[4] = ya[0];
	ya[3] = (irad + reclng) * sint;
/*  unit up vector for rectangle  - this keeps left-bottom corner */
/*  on the radius for either horizontal or vertical path */
	if (vert) {
	    xvec = sint;
	    yvec = -(doublereal)cost;
#ifndef NO_PROTO
	    intsp = .5f;
#else /* NO_PROTO */
	    intsp = (float).5;
#endif /* NO_PROTO */
	} else {
	    xvec = -(doublereal)sint;
	    yvec = cost;
	    intsp = vtab[3] / vtab[0];
	}
	xa[1] = xa[0] + recsht * xvec;
	xa[2] = xa[3] + recsht * xvec;
	ya[1] = ya[0] + recsht * yvec;
	ya[2] = ya[3] + recsht * yvec;
	nsln (&c__3);
	npl (&c__5, xa, ya);
/*  do baseline or centerline */
	xb[0] = xa[0] + intsp * recsht * xvec;
	xb[1] = xa[3] + intsp * recsht * xvec;
	yb[0] = ya[0] + intsp * recsht * yvec;
	yb[1] = ya[3] + intsp * recsht * yvec;
	nsln (&c__2);
	npl (&c__2, xb, yb);
/*  label each spoke */
	s_wsfi(&io___39);
	do_fio(&c__1, "#", 1L);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	e_wsfi();
	r__1 = labrad * xa[3];
	r__2 = labrad * ya[3];
	ntx (&r__1, &r__2, dig2, 2L);
/* L100: */
    }
    nsatp (txpath);
    for (ix = 1; ix <= 7; ++ix) {
/*  txang = angle for annotation text string */
#ifndef NO_PROTO
	txang = (ix << 1) * 3.14159265f / 7;
#else /* NO_PROTO */
	txang = (ix << 1) * (float)3.14159265 / 7;
#endif /* NO_PROTO */
	cost = cos(txang);
	sint = sin(txang);
/*  txpos = requested annotation text position, based on txang,irad, 
*/
/*    and annotation text alignment to be requested. */
/*  first get unit up,right direction */
	if (vert) {
	    xup = cost;
	    yup = sint;
	    xrt = sint;
	    yrt = -(doublereal)cost;
	} else {
	    xup = -(doublereal)sint;
	    yup = cost;
	    xrt = cost;
	    yrt = sint;
	}
	txposx = irad * cost + htab[algnh[ix - 1] - 1] * xrt + vtab[algnv[ix 
		- 1] - 1] * xup;
	txposy = irad * sint + htab[algnh[ix - 1] - 1] * yrt + vtab[algnv[ix 
		- 1] - 1] * yup;
	nsatal (&algnh[ix - 1], &algnv[ix - 1]);
	if (ix == *ngstr) {
#ifndef NO_PROTO
	    txang += (rndint_(&c__0, &c__1) - .5f) * .5f * 3.14159265f / 7;
#else /* NO_PROTO */
	    txang += (rndint_(&c__0, &c__1) - (float).5) * (float).5 * (float)
		    3.14159265 / 7;
#endif /* NO_PROTO */
	    cost = cos(txang);
	    sint = sin(txang);
	    if (vert) {
		xup = cost;
		yup = sint;
	    } else {
		xup = -(doublereal)sint;
		yup = cost;
	    }
	}
	nsatcu (&xup, &yup);
	natr (&txposx, &txposy, &z, &z, txstr, txstr_len);
/*  next ix */
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tsanup_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.04.01/dsanst                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dsanst_(integer *lsiz, integer *lanst)
#else /* NO_PROTO */
/* Subroutine */ int dsanst_(lsiz, lanst)
integer *lsiz, *lanst;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[10], ya[10];
    static integer ix;
    static real xo[10], yo[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer ldis[10], perm[10];
    static real yloc, npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), nsmk (integer *), wcnpc_(real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), nsmk (), wcnpc_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsans (integer *), rnset_(integer *, integer *
	    , integer *), vislab_(char *, char *, real *, real *, real *, 
	    real *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsans (), rnset_(), vislab_();
#endif /* NO_PROTO */
    static real anoffx, anoffy;
    static char anstid[11];
    static real npcpwc;
    static integer numdis;
#ifndef NO_PROTO
    extern /* Subroutine */ int srtiar_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int srtiar_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___62 = { 0, anstid, 0, "(A,I5,A)", 11, 1 };


/*  DSANST accepts a list of annotation styles and displays at most 8 */
/*  of them. */
/* marker type */
    /* Parameter adjustments */
    --lanst;

    /* Function Body */
    wcnpc_(&c_b4, &c_b4, &npcx, &npcy, &npcpwc);
    numdis = min(8,*lsiz);
    rnset_(&numdis, lsiz, perm);
/*  build list of annotation styles to be displayed */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	ldis[ix - 1] = lanst[perm[ix - 1]];
/* L100: */
    }
/*  and sort it */
    srtiar_(&numdis, ldis);
/*  display in order and label all annotation styles in ldis */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .25f, r__2 = 1.f / (*lsiz + 1);
#else /* NO_PROTO */
    r__1 = (float).25, r__2 = (float)1. / (*lsiz + 1);
#endif /* NO_PROTO */
    yincr = dmin(r__1,r__2);
    yloc = 1 - yincr;
/*  annotation offsets in WC */
#ifndef NO_PROTO
    anoffx = .2f;
    anoffy = yincr * .3f;
#else /* NO_PROTO */
    anoffx = (float).2;
    anoffy = yincr * (float).3;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
/*  mark reference and annotation point */
#ifndef NO_PROTO
	xo[ix - 1] = .6f;
#else /* NO_PROTO */
	xo[ix - 1] = (float).6;
#endif /* NO_PROTO */
	yo[ix - 1] = yloc;
	xa[ix - 1] = xo[ix - 1] - anoffx;
	ya[ix - 1] = yo[ix - 1] - anoffy;
	s_wsfi(&io___62);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&ldis[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc - yincr * .3f;
	r__2 = yloc + yincr * .3f;
#else /* NO_PROTO */
	r__1 = yloc - yincr * (float).3;
	r__2 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	vislab_(anstid, "R", &c_b47, &c_b48, &r__1, &r__2, 11L, 1L);
	nsans (&ldis[ix - 1]);
	r__1 = anoffx * npcpwc;
	r__2 = anoffy * npcpwc;
	natr (&xa[ix - 1], &ya[ix - 1], &r__1, &r__2, "abc", 3L);
	yloc -= yincr;
/* L220: */
    }
    nsmk (&c__3);
    npm (&numdis, xa, ya);
    nsmk (&c__4);
    npm (&numdis, xo, yo);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dsanst_ */

