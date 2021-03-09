/* fort/04/03/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b5 = .15f;
#else /* NO_PROTO */
static real c_b5 = (float).15;
#endif /* NO_PROTO */
static integer c__14 = 14;
static integer c__0 = 0;
static integer c__11 = 11;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__4 = 4;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__3 = 3;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b48 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b48 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.01/asfset                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int asfset_(integer *asfix, integer *asftab, integer *start, 
	integer *end)
#else /* NO_PROTO */
/* Subroutine */ int asfset_(asfix, asftab, start, end)
integer *asfix, *asftab, *start, *end;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf ();
#endif /* NO_PROTO */

/*  ASFSET is used to set a sequence of ASFs to values specified in */
/*  an indicated row of the ASF table. */
/*  Input parameters: */
/*    ASFIX     : the row (1-5) of the table from which values are taken 
*/
/*    ASFTAB    : table containing ASF values */
/*    START,END : first,last column in the table (corresponding to aspect 
*/
/*                identifier) from which values are taken. */
/* aspect identifier */
    /* Parameter adjustments */
    --asftab;

    /* Function Body */
    i__1 = *end;
    for (ix = *start; ix <= i__1; ++ix) {
	nsiasf (&ix, &asftab[*asfix + ix * 5]);
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* asfset_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.01/asfint                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int asfint_(integer *vis, integer *visi, integer *vici, 
	integer *numlin, integer *ngprim)
#else /* NO_PROTO */
/* Subroutine */ int asfint_(vis, visi, vici, numlin, ngprim)
integer *vis, *visi, *vici, *numlin, *ngprim;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer p1[10], p2[10], p3[10];
    static real xa[10], ya[10], za[10];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), nfa3 (
	    integer *, real *, real *, real *), nfas (integer *, integer *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), nfa3 (), nfas ();
#endif /* NO_PROTO */
    static integer ibsw;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *), nsir (integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii (), nsir ();
#endif /* NO_PROTO */
    static integer next;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static integer npts[1];
    static real ytop;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *), nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 (), nsici ();
#endif /* NO_PROTO */
    static integer iprim;
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsisi (integer *), nsedfg (integer *), 
	    numlab_(integer *, real *, real *, real *);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsisi (), nsedfg (), numlab_();
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer iixsrc, colsrc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *), rnperm_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf (), rnperm_();
#endif /* NO_PROTO */
    static integer stysrc;

/*  ASFINT draws a set of fill areas and fill area sets to illustrate */
/*  the effect of various interior aspect source flags. */
/*  Input parameters: */
/*    VIS    : interior style to be displayed/suppressed */
/*    VISI   : interior style index to be displayed/suppressed */
/*    VICI   : interior color index to be displayed/suppressed */
/*    NUMLIN : number of primitives to display */
/*  Output parameters: */
/*    NGPRIM : which primitive is drawn differently */
/* aspect identifier */
/* aspect source */
/*                bundled     individual */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* aspect visibility */
/*  use IBSW to switch individual/bundled */
    ibsw = 1;
/*  primitive to be drawn incorrectly */
    *ngprim = rndint_(&c__1, numlin);
#ifndef NO_PROTO
    yincr = 1.f / (*numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (*numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(numlin, &c_b5, &ytop, &yincr);
    iprim = 1;
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .2f;
    xa[2] = .8f;
    xa[3] = .8f;
    za[0] = .5f;
    za[1] = .5f;
    za[2] = .5f;
    za[3] = .5f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).2;
    xa[2] = (float).8;
    xa[3] = (float).8;
    za[0] = (float).5;
    za[1] = (float).5;
    za[2] = (float).5;
    za[3] = (float).5;
#endif /* NO_PROTO */
/*  set edge flag = OFF */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
    npts[0] = 4;
/*  ensure both individual and bundle are picked for each aspect */
    rnperm_(numlin, p1);
    rnperm_(numlin, p2);
    rnperm_(numlin, p3);
/*  loop to draw primitives */
    i__1 = *numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  randomly pick source for aspects: */
	stysrc = p1[ix - 1] % 2;
	iixsrc = p2[ix - 1] % 2;
	colsrc = p3[ix - 1] % 2;
/*  set bundle #ix to displayed aspects, for BUNDLED source */
/*               and suppressed aspects, for INDIVIDUAL source */
	nsir (&globnu_1.wkid, &ix, &vis[stysrc], &visi[iixsrc], &vici[colsrc])
		;
	nsii (&ix);
/*  set individual attributes */
/*                    to displayed aspects, for INDIVIDUAL source */
/*                  and suppressed aspects, for BUNDLED source */
	nsis (&vis[ibsw - stysrc]);
	nsisi (&visi[ibsw - iixsrc]);
	nsici (&vici[ibsw - colsrc]);
/*  set ASF flags in accordance with: stysrc, iixsrc, colsrc */
	nsiasf (&c__11, &stysrc);
	nsiasf (&c__12, &iixsrc);
	nsiasf (&c__13, &colsrc);
	if (ix == *ngprim) {
/*  set ASF flag NOT in accordance with typsrc */
	    i__2 = ibsw - stysrc;
	    nsiasf (&c__11, &i__2);
	    i__2 = ibsw - iixsrc;
	    nsiasf (&c__12, &i__2);
	    i__2 = ibsw - colsrc;
	    nsiasf (&c__13, &i__2);
	    next = iprim;
	} else {
	    next = iprim + 1;
	}
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .3f;
	ya[1] = yloc - yincr * .3f;
	ya[2] = yloc - yincr * .3f;
	ya[3] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).3;
	ya[1] = yloc - yincr * (float).3;
	ya[2] = yloc - yincr * (float).3;
	ya[3] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	if (iprim == 1) {
	    nfa (&c__4, xa, ya);
	} else if (iprim == 2) {
	    nfa3 (&c__4, xa, ya, za);
	} else if (iprim == 3) {
	    nfas (&c__1, npts, xa, ya);
	} else if (iprim == 4) {
	    nfas3 (&c__1, npts, xa, ya, za);
	} else {
	    nfa (&c__4, xa, ya);
	}
	yloc -= yincr;
	iprim = next;
/*  next ix */
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* asfint_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.01/intinh                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int intinh_(integer *asftab, integer *start, integer *end, 
	integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int intinh_(asftab, start, end, perm)
integer *asftab, *start, *end, *perm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static integer ix, siz;
    static real xact[4], xexp[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), xfinh_(integer *), 
	    nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), xfinh_(), nclst ();
#endif /* NO_PROTO */
    static integer expdx[14];
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *), rn1shf_(integer *, integer *), nsedfg (integer 
	    *), numlab_(integer *, real *, real *, real *), nsiasf (integer *,
	     integer *);
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int locint_(integer *, real *), asfset_(integer *,
	     integer *, integer *, integer *), setval_(char *, integer *, 
	    ftnlen), setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst (), rn1shf_(), 
	    nsedfg (), numlab_(), nsiasf ();
    extern doublereal ylocel_();
    extern /* Subroutine */ int locint_(), asfset_(), setval_(), setrvs_();
#endif /* NO_PROTO */

/*  INTINH creates the structure network for testing interior ASFs. */
/*  Input parameters: */
/*    ASFTAB    : table containing ASF values */
/*    START,END : first,last column in the table (corresponding to aspect 
*/
/*                identifier) from which values are taken. */
/*  Output parameters: */
/*    PERM      : permutation of locations used for structure network */
/* aspect identifier */
/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* off/on switch for edge flag and error handling mode */
/*  x-location of actual/expected interiors */
    /* Parameter adjustments */
    --perm;
    --asftab;

    /* Function Body */
    setrvs_("0.2,0.2,0.5,0.5", xact, &siz, 15L);
    setrvs_("0.6,0.6,0.9,0.9", xexp, &siz, 15L);
/*  randomize order of interiors */
    rn1shf_(&c__14, &perm[1]);
/*  set edge flag = OFF */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
/*  set up CSS as described above */
    locint_(&perm[1], xact);
    nexst (&c__102);
    locint_(&perm[9], xact);
    asfset_(&c__2, &asftab[1], start, end);
    locint_(&perm[10], xact);
    xfinh_(&perm[1]);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locint_(&perm[13], xact);
    locint_(&perm[14], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locint_(&perm[2], xact);
    asfset_(&c__3, &asftab[1], start, end);
    nexst (&c__103);
    locint_(&perm[8], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locint_(&perm[3], xact);
    asfset_(&c__4, &asftab[1], start, end);
    locint_(&perm[4], xact);
    nexst (&c__104);
    locint_(&perm[7], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker 5 / 11 */
    locint_(&perm[5], xact);
    asfset_(&c__5, &asftab[1], start, end);
/*  polymarker 6 / 12 */
    locint_(&perm[6], xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected ASFs: */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	asfset_(&expdx[ix - 1], &asftab[1], start, end);
	locint_(&perm[ix], xexp);
/* L400: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b5, &r__1, &c_b48);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* intinh_ */

