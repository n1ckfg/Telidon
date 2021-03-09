/* ngtxat.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b4 = 0.f;
#else /* NO_PROTO */
static real c_b4 = (float)0.;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b9 = .15f;
#else /* NO_PROTO */
static real c_b9 = (float).15;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int ngtxat_(char *prim, ftnlen prim_len)
#else /* NO_PROTO */
/* Subroutine */ int ngtxat_(prim, prim_len)
char *prim;
ftnlen prim_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    real r__1;
    char ch__1[38];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real yup, chht, chxp;
    static integer perm[5];
    static real xloc, yloc;
    static integer this__;
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static real ytop, chmag;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_();
#endif /* NO_PROTO */
    static real cxmag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), wcnpc_(real *, real *, real *,
	     real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), wcnpc_();
#endif /* NO_PROTO */
    static real yincr;
    static integer strid;
    static char chstr[7];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), unmsg_();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *), nsatch (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), numlab_(), nsatch ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatal ();
#endif /* NO_PROTO */
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatcu (real *, real *), nschup (real *, real 
	    *), rnperm_(integer *, integer *), nschxp (real *), nstxal (
	    integer *, integer *), nstxfn (integer *), nqopst (integer *, 
	    integer *, integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatcu (), nschup (), rnperm_(), nschxp (), 
	    nstxal (), nstxfn (), nqopst (), nstxpr ();
#endif /* NO_PROTO */

/*  NGTXAT tests the effect of negative values for the character */
/*  height and expansion factor attributes. */
/*  Input parameters: */
/*    PRIM : indicates primitive and mode to be tested: */
/*           T - text/individual */
/*           A - annotation text/individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* open-structure status */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
    nqopst (&errind, &stype, &strid);
    chkinq_("pqopst", &errind, 6L);
    if (stype == 1) {
/*        press on */
    } else {
	unmsg_("NGTXAT aborting, called with no structure open.", 47L);
    }
    wcnpc_(&c_b4, &c_b4, &npcx, &npcy, &npcpwc);
/*  permute 1 thru 5 */
    rnperm_(&c__5, perm);
#ifndef NO_PROTO
    yincr = .15f;
#else /* NO_PROTO */
    yincr = (float).15;
#endif /* NO_PROTO */
    ytop = 1 - yincr;
/*  magnitude of character height */
#ifndef NO_PROTO
    chmag = yincr * .45f;
#else /* NO_PROTO */
    chmag = yincr * (float).45;
#endif /* NO_PROTO */
/*  magnitude of character expansion factor */
#ifndef NO_PROTO
    cxmag = .8f;
#else /* NO_PROTO */
    cxmag = (float).8;
#endif /* NO_PROTO */
/*  some non-symmetric characters */
    s_copy(chstr, "2P4Q5R7", 7L, 7L);
/*  label text lines */
    numlab_(&c__5, &c_b9, &ytop, &yincr);
#ifndef NO_PROTO
    xloc = .57499999999999996f;
#else /* NO_PROTO */
    xloc = (float).57499999999999996;
#endif /* NO_PROTO */
    yloc = ytop;
/*  default attributes */
    nstxfn (&c__2);
    nstxpr (&c__2);
    nstxal (&c__2, &c__3);
    nsatal (&c__2, &c__3);
    for (ix = 1; ix <= 5; ++ix) {
	this__ = perm[ix - 1];
	if (this__ < 3) {
	    chht = -(doublereal)chmag;
	} else {
	    chht = chmag;
	}
	if (this__ % 2 == 0) {
	    chxp = -(doublereal)cxmag;
	} else {
	    chxp = cxmag;
	}
	if (this__ == 5) {
/*  reverse up and down */
#ifndef NO_PROTO
	    yup = -1.f;
#else /* NO_PROTO */
	    yup = (float)-1.;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    yup = 1.f;
#else /* NO_PROTO */
	    yup = (float)1.;
#endif /* NO_PROTO */
	}
	nschxp (&chxp);
	if (*prim == 'T') {
	    nschup (&c_b4, &yup);
	    nschh (&chht);
	    ntx (&xloc, &yloc, chstr, 7L);
	} else if (*prim == 'A') {
	    nsatcu (&c_b4, &yup);
	    r__1 = npcpwc * chht;
	    nsatch (&r__1);
	    natr (&xloc, &yloc, &c_b4, &c_b4, chstr, 7L);
	} else {
/* Writing concatenation */
	    i__1[0] = 36, a__1[0] = "NGTXAT aborting, called with PRIM = ";
	    i__1[1] = 1, a__1[1] = prim;
	    i__1[2] = 1, a__1[2] = ".";
	    s_cat(ch__1, a__1, i__1, &c__3, 38L);
	    unmsg_(ch__1, 38L);
	}
	yloc -= yincr;
/*  next ix */
/* L100: */
    }
#ifndef NO_PROTO
    dchpf_("NEGATIVE CHARACTER HEIGHT AND EXPANSION FACTOR: Which line does "
	    "NOT have normally oriented characters?", &c__5, &c__5, perm, 102L)
	    ;
#else /* NO_PROTO */
    dchpf_("NEGATIVE CHARACTER HEIGHT AND EXPANSION FACTOR: Which line does \
NOT have normally oriented characters?", &c__5, &c__5, perm, 102L);
#endif /* NO_PROTO */
    nemst (&strid);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ngtxat_ */

