/* intinh.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__14 = 14;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__3 = 3;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__4 = 4;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b26 = .15f;
static real c_b28 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b26 = (float).15;
static real c_b28 = (float).066666666666666666;
#endif /* NO_PROTO */

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
    numlab_(&c__14, &c_b26, &r__1, &c_b28);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* intinh_ */

