/* vislab.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__950 = 950;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__5 = 5;

#ifndef NO_PROTO
/* Subroutine */ int vislab_(char *txt, char *align, real *xlo, real *xhi, 
	real *ylo, real *yhi, ftnlen txt_len, ftnlen align_len)
#else /* NO_PROTO */
/* Subroutine */ int vislab_(txt, align, xlo, xhi, ylo, yhi, txt_len, 
	align_len)
char *txt, *align;
real *xlo, *xhi, *ylo, *yhi;
ftnlen txt_len;
ftnlen align_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer alh[5] = { 1,3,2,2,2 };
    static integer alv[5] = { 3,3,1,5,3 };

    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    real r__1, r__2;
    char ch__1[35];

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real u, z, ccx, ccy, txh;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real txv, txx[2], txy[2], chht;
    static integer opid;
    static real chsp, chxp, xloc, yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqep (integer *, integer *), nsep (integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqep (), nsep ();
#endif /* NO_PROTO */
    static integer aldex;
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

/*  VISLAB draws a text label within a specified box.  Labels are */
/*  drawn in stroke precision.  The text label is scaled uniformly */
/*  (aspect ratio preserved) so that it just fits in the box, and */
/*  then aligned as requested.  Thus, there may be empty space left */
/*  within the box. A new structure is used as a substructure if */
/*  there is a currently open structure, otherwise it is used as the */
/*  main structure.  If used as a substructure, an <execute */
/*  structure> element is inserted in the main structure. Most text */
/*  attributes are set explicitly, but text colour index is */
/*  inherited. */
/*  Input parameters: */
/*    TXT     : Contents of text label to be written */
/*    ALIGN   : alignment code: L,R,T,B,C for left,right,top,bottom,center
 */
/*    XLO,XHI : horizontal location for label */
/*    YLO,YHI : vertical location for label */
/* open-structure status */
/* edit mode */
/* aspect source */
/*                bundled     individual */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    aldex = i_indx("LRTBC", align, 5L, 1L);
    if (aldex <= 0) {
/* Writing concatenation */
	i__1[0] = 34, a__1[0] = "Invalid alignment code in VISLAB: ";
	i__1[1] = 1, a__1[1] = align;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
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
/*  set up new structure for labels */
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
    chht = 1.f;
    chsp = .1f;
    chxp = .8f;
#else /* NO_PROTO */
    chht = (float)1.;
    chsp = (float).1;
    chxp = (float).8;
#endif /* NO_PROTO */
    nstxfn (&txfnt);
    nstxpr (&c__2);
    nschxp (&chxp);
    nschsp (&chsp);
    nschup (&z, &u);
    nstxp (&c__0);
    nstxal (&alh[aldex - 1], &alv[aldex - 1]);
/*  adjust character height according to text-extent */
    nqtxx (&dialog_1.specwt, &txfnt, &chxp, &chsp, &chht, &c__0, &c__1, &c__5,
	     txt, &errind, txx, txy, &ccx, &ccy, txt_len);
    chkinq_("pqtxx", &errind, 5L);
    txh = (r__1 = txx[0] - txx[1], dabs(r__1));
    txv = (r__1 = txy[0] - txy[1], dabs(r__1));
/*  scale vertically and horizontally by same amount to fit within box. */

/* Computing MIN */
    r__1 = (*xhi - *xlo) / txh, r__2 = (*yhi - *ylo) / txv;
    chht = dmin(r__1,r__2);
    nschh (&chht);
/*  get correct alignment point - assume centered and then move */
    xloc = (*xlo + *xhi) / 2;
    yloc = (*ylo + *yhi) / 2;
    if (aldex == 1) {
	xloc = *xlo;
    }
    if (aldex == 2) {
	xloc = *xhi;
    }
    if (aldex == 3) {
	yloc = *yhi;
    }
    if (aldex == 4) {
	yloc = *ylo;
    }
    ntx (&xloc, &yloc, txt, txt_len);
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
} /* vislab_ */

