/* numlab.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__950 = 950;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b13 = 1.f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
#endif /* NO_PROTO */
static integer c__5 = 5;

#ifndef NO_PROTO
/* Subroutine */ int numlab_(integer *hinum, real *rtmarg, real *ytop, 
                 real *yincr)
#else /* NO_PROTO */
/* Subroutine */ int numlab_(hinum, rtmarg, ytop, yincr)
integer *hinum;
real *rtmarg, *ytop, *yincr;
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
    static real u, z;
    static char d2[3];
    static integer ix;
    static real ccx, ccy, txh;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real txv, txx[2], txy[2], chht;
    static integer opid;
    static real chsp, chxp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqep (integer *, integer *), nsep (integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqep (), nsep ();
#endif /* NO_PROTO */
    static real ypos;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), nqedm (integer *, integer *), 
	    nsedm (integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), nqedm (), nsedm (), nclst ();
#endif /* NO_PROTO */
    static integer elptr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), unmsg_();
#endif /* NO_PROTO */
    static integer txfnt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nstxp (
	    integer *), nqtxx (integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *, char *, integer *, real *, real *
	    , real *, real *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nstxp (), nqtxx (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer editmo, errind, labstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nschsp (real *), nschup (
	    real *, real *), nschxp (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nschsp (), nschup (), nschxp ();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxal (integer *, integer *), newstr_(
	    integer *, integer *), nqopst (integer *, integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxal (), newstr_(), nqopst (), nstxfn (), 
	    nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___22 = { 0, d2, 0, "(I2,A)", 3, 1 };


/*  NUMLAB draws a sequence of numeric labels down a vertical column. */
/*  Labels are drawn in stroke precision.  A non-existent structure */
/*  is used as a substructure if there is a currently open structure, */
/*  otherwise it is used as the main structure.  If used as a */
/*  substructure, an <execute structure> element is inserted in the */
/*  main structure.  Most text attributes are set explicitly, but */
/*  text colour index is inherited. */
/*  Input parameters: */
/*    HINUM  : highest number; labels 1-HINUM are drawn. */
/*    RTMARG : right-hand margin for labels */
/*    YTOP   : vertically centered location of top label (#1) */
/*    YINCR  : vertical increment for labels */
/* open-structure status */
/* edit mode */
/* aspect source */
/*                bundled     individual */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    if (*hinum < 1 || *hinum > 99) {
	unmsg_("Invalid value for HINUM in NUMLAB.", 34L);
    }
/*  save edit state, open-structure state */
    nqedm (&errind, &editmo);
    chkinq_("pqedm", &errind, 5L);
    nqopst (&errind, &opstat, &opid);
    chkinq_("pqopst", &errind, 6L);
/*  If a structure is open, save element-pointer and close structure */
    if (opstat == 1) {
	nqep (&errind, &elptr);
	chkinq_("pqep", &errind, 4L);
	nclst ();
    }
/*  get a new structure identifier */
    newstr_(&c__950, &labstr);
    nsedm (&c__0);
    nopst (&labstr);
    nemst (&labstr);
/*  set all aspects to individual */
    setasf_(&c__1);
/* USERMOD  text attributes for labels */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    txfnt = 1;
#ifndef NO_PROTO
    chsp = 0.f;
    chxp = .8f;
#else /* NO_PROTO */
    chsp = (float)0.;
    chxp = (float).8;
#endif /* NO_PROTO */
    nstxfn (&txfnt);
    nstxpr (&c__2);
    nschxp (&chxp);
    nschsp (&chsp);
    nschup (&z, &u);
    nstxp (&c__0);
    nstxal (&c__3, &c__3);
/*  adjust character height according to text-extent */
    nqtxx (&dialog_1.specwt, &txfnt, &chxp, &chsp, &c_b13, &c__0, &c__1, &
	    c__5, "88:", &errind, txx, txy, &ccx, &ccy, 3L);
    chkinq_("pqtxx", &errind, 5L);
    txh = (r__1 = txx[0] - txx[1], dabs(r__1));
    txv = (r__1 = txy[0] - txy[1], dabs(r__1));
/*  scale down vertically or horizontally, to lower size */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = *rtmarg * .9f / txh, r__2 = *yincr * .65f / txv;
#else /* NO_PROTO */
    r__1 = *rtmarg * (float).9 / txh, r__2 = *yincr * (float).65 / txv;
#endif /* NO_PROTO */
    chht = dmin(r__1,r__2);
    nschh (&chht);
    ypos = *ytop;
    i__1 = *hinum;
    for (ix = 1; ix <= i__1; ++ix) {
	s_wsfi(&io___22);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (rtmarg, &ypos, d2, 3L);
	ypos -= *yincr;
/* L100: */
    }
    nclst ();
/*  restore edit state, open-structure state */
    nsedm (&editmo);
    if (opstat == 1) {
	nopst (&opid);
	nsep (&elptr);
	nexst (&labstr);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* numlab_ */

