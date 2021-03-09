/* undcmd.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__1 = 1;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__100 = 100;
static integer c__3 = 3;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b20 = .15f;
static real c_b37 = .2f;
static real c_b38 = .5f;
static real c_b50 = .55f;
static real c_b51 = .95f;

logical undcmd_(integer *nummod, integer *modlis, integer *hicol, char *
	prompt, ftnlen prompt_len)
#else /* NO_PROTO */
static real c_b20 = (float).15;
static real c_b37 = (float).2;
static real c_b38 = (float).5;
static real c_b50 = (float).55;
static real c_b51 = (float).95;

logical undcmd_(nummod, modlis, hicol, prompt, prompt_len)
integer *nummod, *modlis, *hicol;
char *prompt;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1, i__2[3], i__3, i__4[2], i__5;
    real r__1;
    logical ret_val;
    char ch__1[80], ch__2[78], ch__3[34];
    icilist ici__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer cm;
    static real hi[8];
    static integer ii;
    static real lo[8];
    static integer ix, icm;
    static char msg[200];
    static real yhi;
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
#else /* NO_PROTO */
    extern logical dyn_();
#endif /* NO_PROTO */
    static real ylo;
    static integer pos1;
    static char cval[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr ();
#endif /* NO_PROTO */
    static real ytop;
    static integer cmdim;
    static logical lomag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), inmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), inmsg_();
#endif /* NO_PROTO */
    static integer numcm, colix, numcl;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char rvals[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), rnset_(integer *, integer *
	    , integer *), dchoic_(char *, integer *, integer *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), rnset_(), dchoic_();
#endif /* NO_PROTO */
    static real actcol[8];
#ifndef NO_PROTO
    extern /* Subroutine */ int colpch_(logical *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int colpch_();
#endif /* NO_PROTO */
    static logical filmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *), 
	    chkinq_(char *, integer *, ftnlen), vislab_(char *, char *, real *
	    , real *, real *, real *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_(), chkinq_(), vislab_();
#endif /* NO_PROTO */
    static integer errind, ranlis[8];
    static real colary[8];
#ifndef NO_PROTO
    extern /* Subroutine */ int drlval_(char *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int drlval_();
#endif /* NO_PROTO */
    static integer numtst;
#ifndef NO_PROTO
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical intsty_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___7 = { 0, cval, 0, "(I5)", 5, 1 };
    static icilist io___11 = { 0, cval, 0, "(I5)", 5, 1 };
    static icilist io___25 = { 0, msg, 0, "(A,I5,A,I5,A,I5,A)", 200, 1 };
    static icilist io___29 = { 0, msg, 0, "(A,I5,A,A,A)", 200, 1 };
    static icilist io___30 = { 0, cval, 0, "(I5)", 5, 1 };


/*  UNDCMD tests the list of color models passed in by requesting */
/*  dimensions and drawing color patches using those dimensions. */
/*  The operator is asked if the displayed color matches the */
/*  randomly chosen color coordinates. */
/*  Input parameters: */
/*    NUMMOD :  Size of list of color models */
/*    MODLIS :  Entire list of color models which may be tested */
/*    HICOL  :  Highest color index to be used */
/*    PROMPT :  String for prompt, indicating documentation to */
/*              be used for reference */
/*  interior style */
/*     type of returned values set, realized */
/*  Determine how to fill in rectangles, use solid style */
/*  if it is available, otherwise use dense polyline cross-hatch */
    /* Parameter adjustments */
    --modlis;

    /* Function Body */
    filmod = intsty_(&dialog_1.specwt, &c__1);
/*  number of models to test */
    numtst = min(8,*nummod);
/*  Test a random subset of the models if > 8 */
    rnset_(&numtst, nummod, ranlis);
    i__1 = numtst;
    for (icm = 1; icm <= i__1; ++icm) {
	nemst (&c__102);
/*  Set Color Model */
	cm = modlis[ranlis[icm - 1]];
	nscmd (&globnu_1.wkid, &cm);
	s_wsfi(&io___7);
	do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
	e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 74, a__1[0] = "DIMENSION OF COLOUR MODEL: How many dimensi"
		"ons are there for colour model ";
#else /* NO_PROTO */
	i__2[0] = 74, a__1[0] = "DIMENSION OF COLOUR MODEL: How many dimensi\
ons are there for colour model ";
#endif /* NO_PROTO */
	i__2[1] = 5, a__1[1] = cval;
	i__2[2] = 1, a__1[2] = "?";
	s_cat(ch__1, a__1, i__2, &c__3, 80L);
	dchoic_(ch__1, &c__0, &c__100, &cmdim, 80L);
	if (cmdim == 0) {
	    inmsg_("Operator reported zero dimensions for a color model.", 
		    52L);
	    ret_val = FALSE_;
	    return ret_val;
	}
/*  determine format for displaying color coordinates */
	lomag = TRUE_;
	i__3 = cmdim;
	for (ix = 1; ix <= i__3; ++ix) {
	    s_wsfi(&io___11);
	    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the LOWER limit"
		    " for valid values for dimension # ";
#else /* NO_PROTO */
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the LOWER limit\
 for valid values for dimension # ";
#endif /* NO_PROTO */
	    i__4[1] = 5, a__2[1] = cval;
	    s_cat(ch__2, a__2, i__4, &c__2, 78L);
	    drlval_(ch__2, &lo[ix - 1], 78L);
/* Writing concatenation */
#ifndef NO_PROTO
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the UPPER limit"
		    " for valid values for dimension # ";
#else /* NO_PROTO */
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the UPPER limit\
 for valid values for dimension # ";
#endif /* NO_PROTO */
	    i__4[1] = 5, a__2[1] = cval;
	    s_cat(ch__2, a__2, i__4, &c__2, 78L);
	    drlval_(ch__2, &hi[ix - 1], 78L);
#ifndef NO_PROTO
	    if ((r__1 = lo[ix - 1], dabs(r__1)) >= 10.f) {
#else /* NO_PROTO */
	    if ((r__1 = lo[ix - 1], dabs(r__1)) >= (float)10.) {
#endif /* NO_PROTO */
		lomag = FALSE_;
	    }
#ifndef NO_PROTO
	    if ((r__1 = hi[ix - 1], dabs(r__1)) >= 10.f) {
#else /* NO_PROTO */
	    if ((r__1 = hi[ix - 1], dabs(r__1)) >= (float)10.) {
#endif /* NO_PROTO */
		lomag = FALSE_;
	    }
/* L100: */
	}
/*  Draw color patches down left side of screen: */
	numcm = *hicol - 1;
#ifndef NO_PROTO
	yincr = 1.f / (numcm + 1.f);
#else /* NO_PROTO */
	yincr = (float)1. / (numcm + (float)1.);
#endif /* NO_PROTO */
	ytop = 1 - yincr;
#ifndef NO_PROTO
	ylo = ytop - yincr * .25f;
	yhi = ytop + yincr * .25f;
#else /* NO_PROTO */
	ylo = ytop - yincr * (float).25;
	yhi = ytop + yincr * (float).25;
#endif /* NO_PROTO */
	numlab_(&numcm, &c_b20, &ytop, &yincr);
	i__3 = *hicol;
	for (colix = 2; colix <= i__3; ++colix) {
	    i__5 = cmdim;
	    for (ix = 1; ix <= i__5; ++ix) {
		colary[ix - 1] = rndrl_(&lo[ix - 1], &hi[ix - 1]);
/* L110: */
	    }
	    nscr (&globnu_1.wkid, &colix, &cmdim, colary);
/*  determine actual colval */
	    nqcr (&globnu_1.wkid, &colix, &cmdim, &c__1, &errind, &numcl, 
		    actcol);
	    chkinq_("pqcr", &errind, 4L);
	    if (numcl != cmdim) {
		s_wsfi(&io___25);
		do_fio(&c__1, "Reported dimensionality for color model #", 
			41L);
		do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is ", 4L);
		do_fio(&c__1, (char *)&numcl, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
		do_fio(&c__1, "; does not match value specified by operator "
			"= ", 47L);
#else /* NO_PROTO */
		do_fio(&c__1, "; does not match value specified by operator \
= ", 47L);
#endif /* NO_PROTO */
		do_fio(&c__1, (char *)&cmdim, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 200L);
		ret_val = FALSE_;
		return ret_val;
	    }
	    colpch_(&filmod, &colix, &c_b37, &ylo, &c_b38, &yhi);
/*  format color coordinates for printing */
	    s_copy(rvals, " ", 80L, 1L);
	    i__5 = numcl;
	    for (ii = 1; ii <= i__5; ++ii) {
		if (lomag) {
		    pos1 = ii * 6 - 5;
		    ici__1.icierr = 0;
		    ici__1.icirnum = 1;
		    ici__1.icirlen = 6;
		    ici__1.iciunit = rvals + (pos1 - 1);
		    ici__1.icifmt = "(A,F5.2)";
		    s_wsfi(&ici__1);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, (char *)&actcol[ii - 1], (ftnlen)sizeof(
			    real));
		    e_wsfi();
		} else {
		    pos1 = ii * 10 - 9;
		    ici__1.icierr = 0;
		    ici__1.icirnum = 1;
		    ici__1.icirlen = 10;
		    ici__1.iciunit = rvals + (pos1 - 1);
		    ici__1.icifmt = "(A,E9.2)";
		    s_wsfi(&ici__1);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, (char *)&actcol[ii - 1], (ftnlen)sizeof(
			    real));
		    e_wsfi();
		}
/* L120: */
	    }
	    vislab_(rvals + 1, "L", &c_b50, &c_b51, &ylo, &yhi, itrim_(rvals, 
		    80L) - 1, 1L);
	    ylo -= yincr;
	    yhi -= yincr;
/*  next random color within color model */
/* L130: */
	}
	s_wsfi(&io___29);
#ifndef NO_PROTO
	do_fio(&c__1, "ACCURACY OF COLOUR MODEL: Are the colours of the rect"
		"angles compatible with the corresponding colour coordinate v"
		"alues within colour model #", 140L);
#else /* NO_PROTO */
	do_fio(&c__1, "ACCURACY OF COLOUR MODEL: Are the colours of the rect\
angles compatible with the corresponding colour coordinate values within col\
our model #", 140L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
	do_fio(&c__1, ", according to the ", 19L);
	do_fio(&c__1, prompt, prompt_len);
	do_fio(&c__1, "?", 1L);
	e_wsfi();
	if (dyn_(msg, 200L)) {
/*           OK so far */
	} else {
	    s_wsfi(&io___30);
	    do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
	    e_wsfi();
/* Writing concatenation */
	    i__2[0] = 13, a__1[0] = "Color Model #";
	    i__2[1] = 5, a__1[1] = cval;
	    i__2[2] = 16, a__1[2] = " caused failure.";
	    s_cat(ch__3, a__1, i__2, &c__3, 34L);
	    inmsg_(ch__3, 34L);
	    ret_val = FALSE_;
	    return ret_val;
	}
/*  next color model */
/* L140: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* undcmd_ */

