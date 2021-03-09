/* chkfnt.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b10 = .05f;
static real c_b11 = .9f;
#else /* NO_PROTO */
static real c_b10 = (float).05;
static real c_b11 = (float).9;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b23 = .3f;
#else /* NO_PROTO */
static real c_b23 = (float).3;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b31 = 0.f;
static real c_b42 = .2f;
static real c_b43 = 1.f;
static real c_b48 = .35f;

/* Subroutine */ int chkfnt_(integer *lx, integer *lfn, integer *lpr, integer 
	*maxent, char *chstr, logical *subpre, char *prim, ftnlen chstr_len, 
	ftnlen prim_len)
#else /* NO_PROTO */
static real c_b31 = (float)0.;
static real c_b42 = (float).2;
static real c_b43 = (float)1.;
static real c_b48 = (float).35;

/* Subroutine */ int chkfnt_(lx, lfn, lpr, maxent, chstr, subpre, prim, 
	chstr_len, prim_len)
integer *lx, *lfn, *lpr, *maxent;
char *chstr;
logical *subpre;
char *prim;
ftnlen chstr_len;
ftnlen prim_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1, i__2, i__3[3], i__4[2];
    real r__1, r__2;
    char ch__1[11], ch__2[27];
    icilist ici__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen), s_wsfi(icilist *), do_fio(integer *, char *
	    , ftnlen), e_wsfi(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer i_len(), s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[5], ya[5];
    static integer ix, lcc[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), natr (real *, real *, real *, real *, 
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx (), natr ();
#endif /* NO_PROTO */
    static real npcx, npcy, ypos, ytop;
    static integer lench;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), wcnpc_(real *, real *, real *,
	     real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), wcnpc_();
#endif /* NO_PROTO */
    static integer ldisp[20];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), rnset_(integer *, 
	    integer *, integer *), nstxi (integer *), nstxr (integer *, 
	    integer *, integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), rnset_(), nstxi (), nstxr ();
#endif /* NO_PROTO */
    static char chcods[100], fntlab[5];
    static integer actpre;
#ifndef NO_PROTO
    extern /* Subroutine */ int vislab_(char *, char *, real *, real *, real *
	    , real *, ftnlen, ftnlen), nsatch (real *);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int vislab_(), nsatch ();
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer numlin;
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *), srtiar_(
	    integer *, integer *), nsatal (integer *, integer *), nschsp (
	    real *), nstxal (integer *, integer *), nstxfn (integer *), 
	    nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_(), srtiar_(), nsatal (), nschsp (), 
	    nstxal (), nstxfn (), nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___13 = { 0, fntlab, 0, "(I5)", 5, 1 };


/*  CHKFNT accepts a list of fonts and precisions, and randomly picks */
/*  some of them to be illustrated using the specified character */
/*  string. */

/*  Input parameters: */
/*    LX     : size of font and precision lists */
/*    LFN    : list of text fonts to be shown */
/*    LPR    : list of precisions to be used with corresponding font */
/*    MAXENT : maximum number of entries to be illustrated */
/*    CHSTR  : character string to be used when displaying fonts */
/*    SUBPRE : logical switch to control whether sub-available */
/*             precisions are requested. */
/*    PRIM   : indicates primitive and mode to be tested: */
/*             T - text/individual */
/*             A - annotation text/individual */
/*             U - text/bundled */
/*             B - annotation text/bundled */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
    /* Parameter adjustments */
    --lpr;
    --lfn;

    /* Function Body */
    lench = i_len(chstr, chstr_len);
/*  lcc = list of character codes = codes for chstr */
    i__1 = lench;
    for (ix = 1; ix <= i__1; ++ix) {
	lcc[ix - 1] = chstr[ix - 1];
	i__2 = (ix << 2) - 4;
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = (ix << 2) - i__2;
	ici__1.iciunit = chcods + i__2;
	ici__1.icifmt = "(I3,A)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&lcc[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ",", 1L);
	e_wsfi();
/* L110: */
    }
    i__1 = (lench << 2) - 1;
    s_copy(chcods + i__1, " ", 100 - i__1, 1L);
/*  ldisp = list of fonts to be displayed - pointers into LPOSFN */
    if (*lx > *maxent) {
/*  pick a random subset to show */
	rnset_(maxent, lx, ldisp);
	numlin = *maxent;
    } else {
/*  show all of them */
	rnperm_(lx, ldisp);
	numlin = *lx;
    }
    srtiar_(&numlin, ldisp);
/*  display lcc - list of character codes */
#ifndef NO_PROTO
    ypos = .97f;
    yincr = .08f;
    r__1 = ypos - yincr * .6f;
#else /* NO_PROTO */
    ypos = (float).97;
    yincr = (float).08;
    r__1 = ypos - yincr * (float).6;
#endif /* NO_PROTO */
    vislab_("Text below composed from character codes:", "L", &c_b10, &c_b11, 
	    &r__1, &ypos, 41L, 1L);
    ypos -= yincr;
#ifndef NO_PROTO
    r__1 = ypos - yincr * .6f;
#else /* NO_PROTO */
    r__1 = ypos - yincr * (float).6;
#endif /* NO_PROTO */
    vislab_(chcods, "L", &c_b10, &c_b11, &r__1, &ypos, itrim_(chcods, 100L), 
	    1L);
    ypos -= yincr;
    ya[0] = ypos;
    ya[1] = ypos;
#ifndef NO_PROTO
    xa[0] = .05f;
    xa[1] = .95f;
#else /* NO_PROTO */
    xa[0] = (float).05;
    xa[1] = (float).95;
#endif /* NO_PROTO */
    npl (&c__2, xa, ya);
/*  display and label chstr for each font in ldisp, using that */
/*  font's associated precision - labels first */
    ytop = ypos - yincr;
    ypos = ytop;
/* Computing MIN */
    r__1 = ypos / 7, r__2 = ypos / (*maxent + 1);
    yincr = dmin(r__1,r__2);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	s_wsfi(&io___13);
	do_fio(&c__1, (char *)&lfn[ldisp[ix - 1]], (ftnlen)sizeof(integer));
	e_wsfi();
/* Writing concatenation */
	i__3[0] = 5, a__1[0] = "Font ";
	i__3[1] = 5, a__1[1] = fntlab;
	i__3[2] = 1, a__1[2] = ":";
	s_cat(ch__1, a__1, i__3, &c__3, 11L);
#ifndef NO_PROTO
	r__1 = ypos - yincr * .6f;
#else /* NO_PROTO */
	r__1 = ypos - yincr * (float).6;
#endif /* NO_PROTO */
	vislab_(ch__1, "R", &c_b10, &c_b23, &r__1, &ypos, 11L, 1L);
	ypos -= yincr;
/* L100: */
    }
    ypos = ytop;
    if (*prim == 'T' || *prim == 'U') {
#ifndef NO_PROTO
	r__1 = yincr * .5f;
#else /* NO_PROTO */
	r__1 = yincr * (float).5;
#endif /* NO_PROTO */
	nschh (&r__1);
	nstxal (&c__1, &c__1);
    } else if (*prim == 'A' || *prim == 'B') {
	wcnpc_(&c_b31, &c_b31, &npcx, &npcy, &npcpwc);
#ifndef NO_PROTO
	r__1 = yincr * .5f * npcpwc;
#else /* NO_PROTO */
	r__1 = yincr * (float).5 * npcpwc;
#endif /* NO_PROTO */
	nsatch (&r__1);
	nsatal (&c__1, &c__1);
    } else {
/* Writing concatenation */
	i__4[0] = 26, a__2[0] = "CHKFNT called with PRIM = ";
	i__4[1] = 1, a__2[1] = prim;
	s_cat(ch__2, a__2, i__4, &c__2, 27L);
	unmsg_(ch__2, 27L);
    }
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	actpre = lpr[ldisp[ix - 1]];
	if (*subpre) {
	    actpre -= rndint_(&c__1, &c__2);
	    actpre = max(actpre,0);
	}
	if (*prim == 'T' || *prim == 'A') {
	    nstxfn (&lfn[ldisp[ix - 1]]);
	    nstxpr (&actpre);
	    nschsp (&c_b42);
	} else {
	    nstxr (&globnu_1.wkid, &ix, &lfn[ldisp[ix - 1]], &actpre, &c_b43, 
		    &c_b42, &c__1);
	    nstxi (&ix);
	}
	if (*prim == 'T' || *prim == 'U') {
	    ntx (&c_b48, &ypos, chstr, chstr_len);
	} else {
	    natr (&c_b48, &ypos, &c_b31, &c_b31, chstr, chstr_len);
	}
	ypos -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkfnt_ */

