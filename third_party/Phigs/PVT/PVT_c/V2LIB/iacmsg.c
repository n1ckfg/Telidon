/* iacmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    char ophead[300];
} opcomm_;

#define opcomm_1 opcomm_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__5 = 5;
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b23 = 1.f;
static real c_b25 = 0.f;
#else /* NO_PROTO */
static real c_b23 = (float)1.;
static real c_b25 = (float)0.;
#endif /* NO_PROTO */
static integer c__9 = 9;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b46 = .03f;
#else /* NO_PROTO */
static real c_b46 = (float).03;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int iacmsg_(char *msgtxt, ftnlen msgtxt_len)
#else /* NO_PROTO */
/* Subroutine */ int iacmsg_(msgtxt, msgtxt_len)
char *msgtxt;
ftnlen msgtxt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
#else /* NO_PROTO */
    integer i_indx(), i_len();
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), s_wsle(), do_lio(), e_wsle();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ma, mb;
    static real xa[10], ya[10];
    static integer ix;
    static real tm3[9]	/* was [3][3] */, scf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static char msg[300];
    static integer err;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static integer opid;
    static real chsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqep (integer *, integer *),  nmsg (integer *, 
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqep (),  nmsg ();
#endif /* NO_PROTO */
    static real rdum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real copx, copy, xmax;
    static integer outl;
    static real extx[2], exty[2], ypos;
    static integer iline;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), nqedm (integer *, integer *), 
	    nsedm (integer *), nbltm (real *, real *, real *, real *, real *, 
	    real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), nqedm (), nsedm (), nbltm ();
#endif /* NO_PROTO */
    static real loghw;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer elptr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), unmsg_(char *, ftnlen), nemst (
	    integer *), nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), unmsg_(), nemst (), nslmt ();
#endif /* NO_PROTO */
    static integer txfnt;
    static real xsize, ysize;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), nstxp (
	    integer *), nqtxx (integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *, char *, integer *, real *, real *
	    , real *, real *, ftnlen), scapar_(integer *, real *, real *, 
	    integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), nstxp (), nqtxx (), 
	    scapar_();
#endif /* NO_PROTO */
    static integer colloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer editmo;
#ifndef NO_PROTO
    extern /* Subroutine */ int linbrk_(char *, integer *, integer *, integer 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int linbrk_();
#endif /* NO_PROTO */
    static integer errind, opstat, numlin, linpos[90];
    static real chwrat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *), 
	    setasf_(integer *), nsplci (integer *), setrvs_(char *, real *, 
	    integer *, ftnlen), nstxfn (integer *), nstxpr (integer *), 
	    nschxp (real *), nschsp (real *), nstxci (integer *), nschup (
	    real *, real *), nstxal (integer *, integer *), fitpar_(char *, 
	    real *, real *, integer *, ftnlen), pstctl_(integer *), nseplb (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst (), setasf_(), nsplci (), setrvs_(), 
	    nstxfn (), nstxpr (), nschxp (), nschsp (), nstxci (), nschup (), 
	    nstxal (), fitpar_(), pstctl_(), nseplb ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___4 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };


/*  IACMSG sends a character string (MSGTXT) to the operator in */
/*  accordance with DOUTYP.  For DOUTYP 3 IACMSG formats MSGTXT */
/*  into structure #DSTRID. For DOUTYP 1 OR 2 IACMSG simply breaks up */
/*  MSGTXT into the specified line-length and sends out each line */
/*  via PRINT or MESSAGE, respectively. */
/*  If the MSGTXT looks like a topical heading for a test case (caps */
/*  followed by ":"), then the heading is saved in a common area */
/*  shared with OPCO, so the operator's comments are tagged. */
/* aspect source */
/*                bundled     individual */
/* open-structure status */
/* edit mode */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  put MSGTXT in OPHEAD if it's a topical header for a test case. */
/*  look for colon location */
    colloc = i_indx(msgtxt, ":", msgtxt_len, 1L);
    if (colloc <= 0) {
	goto L100;
    }
/* Computing MIN */
    i__2 = 10, i__3 = i_len(msgtxt, msgtxt_len);
    i__1 = min(i__2,i__3);
    for (ix = 1; ix <= i__1; ++ix) {
/*  treat as non-header if first 10 chars not all caps or digits or sp
aces */
	if (i_indx("ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789", msgtxt + (ix - 1),
		 37L, 1L) <= 0) {
	    goto L100;
	}
/* L50: */
    }
    s_copy(opcomm_1.ophead, msgtxt, 300L, colloc);
L100:
    if (dialog_1.doutyp == 1 || dialog_1.doutyp == 2) {
/*  if direct output, skip initialization of structure (DSTRID) */
/*  for dialogue. */
	goto L110;
    } else if (dialog_1.doutyp == 3) {
/*        OK - do nothing */
    } else {
	s_wsfi(&io___4);
	do_fio(&c__1, "Invalid output type in IACMSG: ", 31L);
	do_fio(&c__1, (char *)&dialog_1.dintyp, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  save edit state, open-structure state */
    nqedm (&errind, &editmo);
    chkinq_("pqedm", &errind, 5L);
    nqopst (&errind, &opstat, &opid);
    chkinq_("pqopst", &errind, 6L);
/*  If a structure is open, save element-pointer and close structure */
    if (opstat == 1) {
	if (opid == dialog_1.dstrid) {
	    unmsg_("IACMSG found dialogue structure open.", 37L);
	}
	nqep (&errind, &elptr);
	chkinq_("pqep", &errind, 4L);
	nclst ();
    }
    nsedm (&c__0);
    nopst (&dialog_1.dstrid);
    nemst (&dialog_1.dstrid);
    nsvwi (&c__2);
/*  set all aspects to individual */
    setasf_(&c__1);
/*  outline dialogue area */
    nsplci (&dialog_1.dtxci);
    setrvs_("0,0,1,1,0", xa, &outl, 9L);
    setrvs_("0,0,0,0,0", ya, &outl, 9L);
    ya[1] = dialog_1.dyxrat;
    ya[2] = dialog_1.dyxrat;
    npl (&c__5, xa, ya);
/*  mark start of text elements in structure */
    nlb (&c__101);
/* USERMOD  text attributes for dialogue */
    txfnt = 1;
#ifndef NO_PROTO
    chsp = .1f;
#else /* NO_PROTO */
    chsp = (float).1;
#endif /* NO_PROTO */
    nstxfn (&txfnt);
    nstxpr (&c__2);
    nschxp (&c_b23);
    nschsp (&chsp);
    nstxci (&dialog_1.dtxci);
    nschh (&c_b23);
    nschup (&c_b25, &c_b23);
    nstxp (&c__0);
    nstxal (&c__1, &c__1);
/* USERMOD  Control character height/width ratio for dialogue here: if */
/* USERMOD  characters too skinny, decrease, if too fat, increase. */
#ifndef NO_PROTO
    chwrat = 2.5f;
#else /* NO_PROTO */
    chwrat = (float)2.5;
#endif /* NO_PROTO */
/*  calculate line-size, for a paragraph based on desired */
/*  character body height/width ratio */
    fitpar_(msgtxt, &chwrat, &dialog_1.dyxrat, &dialog_1.dtclim, msgtxt_len);
#ifndef NO_PROTO
    ypos = 0.f;
    xmax = 0.f;
#else /* NO_PROTO */
    ypos = (float)0.;
    xmax = (float)0.;
#endif /* NO_PROTO */
L110:
/*  break up MSGTXT into DTCLIM-size chunks - get array of */
/*  line starting positions */
    linbrk_(msgtxt, &dialog_1.dtclim, &err, &numlin, linpos, msgtxt_len);
    if (numlin >= 90) {
	unmsg_("Too many lines computed by IACMSG.", 34L);
    }
/*  send each line to screen or print or message, as specified */
    i__1 = numlin;
    for (iline = 1; iline <= i__1; ++iline) {
/*  MA and MB point to substring within MSGTXT to be output */
	ma = linpos[iline - 1];
	mb = itrim_(msgtxt, linpos[iline] - 1);
	if (dialog_1.doutyp == 1) {
	    s_wsle(&io___24);
	    do_lio(&c__9, &c__1, msgtxt + (ma - 1), mb - (ma - 1));
	    e_wsle();
	} else if (dialog_1.doutyp == 2) {
	     nmsg (&globnu_1.wkid, msgtxt + (ma - 1), mb - (ma - 1));
	} else {
/*  write MSGTXT into prompt area - WC = x:0-1, y:0-DYXRAT */
	    ntx (&c_b25, &ypos, msgtxt + (ma - 1), mb - (ma - 1));
/*  keep track of widest line and vertical position */
	    nqtxx (&dialog_1.specwt, &txfnt, &c_b23, &chsp, &c_b23, &c__0, &
		    c__1, &c__1, msgtxt + (ma - 1), &errind, extx, exty, &
		    copx, &copy, mb - (ma - 1));
	    chkinq_("pqtxx", &errind, 5L);
	    xsize = (r__1 = extx[0] - extx[1], dabs(r__1));
	    ysize = (r__1 = exty[0] - exty[1], dabs(r__1));
	    xmax = dmax(xmax,xsize);
/* USERMOD  Control separation of dialogue lines here - if too crowded, */
/* USERMOD  increase coefficient of YSIZE, if too sparse, decrease. */

#ifndef NO_PROTO
	    ypos -= ysize * 1.02f;
#else /* NO_PROTO */
	    ypos -= ysize * (float)1.02;
#endif /* NO_PROTO */
	}
/* L200: */
    }
    if (dialog_1.scrmod == 3) {
/*  make sure dialogue is posted */
	pstctl_(&c__2);
    } else if (dialog_1.scrmod == 0) {
/*  post picture only */
	pstctl_(&c__1);
    } else {
/*  split screen - post dialogue and picture */
	pstctl_(&c__3);
    }
/*  if direct output, we're done */
    if (dialog_1.doutyp != 3) {
	return 0;
    }
/*  Text written into rectangle with x-bounds = 0:xmax, */
/*  y-bounds = ypos:0. Must transform to fit into 0:1, 0:dyxrat */
/*  rectangle, with scaling adjusted for CHWRAT = character */
/*  height/width ratio. */
    scapar_(&dialog_1.dtclim, &chwrat, &dialog_1.dyxrat, &numlin, linpos, &
	    rdum, &loghw);
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = 1.f, r__2 = dialog_1.dyxrat / loghw;
    scf = dmin(r__1,r__2) * .94f;
#else /* NO_PROTO */
    r__1 = (float)1., r__2 = dialog_1.dyxrat / loghw;
    scf = dmin(r__1,r__2) * (float).94;
#endif /* NO_PROTO */
    r__1 = scf / xmax;
    r__2 = -(doublereal)scf * loghw / ypos;
    nbltm (&c_b25, &c_b25, &c_b46, &dialog_1.dyxrat, &c_b25, &r__1, &r__2, &
	    errind, tm3);
    chkinq_("pbltm", &errind, 5L);
/*  insert transformation just before text elements */
    nsep (&c__1);
    nseplb (&c__101);
    nslmt (tm3, &c__2);
    nclst ();
/*  restore edit state, open-structure state */
    nsedm (&editmo);
    if (opstat == 1) {
	nopst (&opid);
	nsep (&elptr);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* iacmsg_ */

