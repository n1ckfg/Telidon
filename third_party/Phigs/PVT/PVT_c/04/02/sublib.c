/* fort/04/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b13 = 0.f;
#else /* NO_PROTO */
static real c_b13 = (float)0.;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b26 = 1.f;
#else /* NO_PROTO */
static real c_b26 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__11 = 11;
static integer c__12 = 12;
static integer c_n1 = -1;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b57 = .2f;
static real c_b70 = .05f;
static real c_b71 = .35f;
static real c_b74 = .4f;
static real c_b119 = .02f;
static real c_b131 = .9f;
static real c_b143 = .3f;
static real c_b184 = .15f;
static real c_b189 = .04f;
#else /* NO_PROTO */
static real c_b57 = (float).2;
static real c_b70 = (float).05;
static real c_b71 = (float).35;
static real c_b74 = (float).4;
static real c_b119 = (float).02;
static real c_b131 = (float).9;
static real c_b143 = (float).3;
static real c_b184 = (float).15;
static real c_b189 = (float).04;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b200 = .5f;
#else /* NO_PROTO */
static real c_b200 = (float).5;
#endif /* NO_PROTO */
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b252 = .1f;
#else /* NO_PROTO */
static real c_b252 = (float).1;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/altsiz                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int altsiz_(real *expdc, real *minsiz, real *maxsiz, integer 
	*maxalt, integer *numalt, real *alt)
#else /* NO_PROTO */
/* Subroutine */ int altsiz_(expdc, minsiz, maxsiz, maxalt, numalt, alt)
real *expdc, *minsiz, *maxsiz;
integer *maxalt, *numalt;
real *alt;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
    static real nxl1, nxl2, nxs1, nxs2;

/*  ALTSIZ finds nearby alternate sizes, to the expected size, and */
/*  returns them to the caller.  The alternates fulfill all these */
/*  conditions: 1) each differs from all the others by at least 25% */
/*  (relative) and by MINSIZ (absolute), and 2) each is no less than */
/*  MINSIZ, and no greater than MAXSIZ. */
/*  Input parameters: */
/*    EXPDC  : Expected size; always the first entry in ALT */
/*   MINSIZ : Minimum size for an entry and for difference between entries
*/
/*    MAXSIZ : Maximum size for an entry */
/*   MAXALT : Maximum number of alternatives to be returned (including EXP
DC)*/
/*  Output parameters: */
/*    NUMALT : Actual number of alternatives returned */
/*    ALT    : List of alternative sizes */
    /* Parameter adjustments */
    --alt;

    /* Function Body */
    *numalt = 1;
    alt[*numalt] = *expdc;
    nxl1 = *expdc;
    nxs1 = *expdc;
/*  generate alternative sizes - must differ by at least 25% *and* MINSIZ 
*/
    i__1 = *maxalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  generate larger choices */
#ifndef NO_PROTO
	nxl2 = nxl1 * 1.25f;
#else /* NO_PROTO */
	nxl2 = nxl1 * (float)1.25;
#endif /* NO_PROTO */
	if (nxl2 - nxl1 < *minsiz) {
	    nxl2 = nxl1 + *minsiz;
	}
	if (nxl2 <= *maxsiz) {
	    ++(*numalt);
	    alt[*numalt] = nxl2;
	    if (*numalt >= *maxalt) {
		return 0;
	    }
	    nxl1 = nxl2;
	}
/*  generate smaller choices */
#ifndef NO_PROTO
	nxs2 = nxs1 / 1.25f;
#else /* NO_PROTO */
	nxs2 = nxs1 / (float)1.25;
#endif /* NO_PROTO */
	if (nxs1 - nxs2 < *minsiz) {
	    nxs2 = nxs1 - *minsiz;
	}
	if (nxs2 >= *minsiz) {
	    ++(*numalt);
	    alt[*numalt] = nxs2;
	    if (*numalt >= *maxalt) {
		return 0;
	    }
	    nxs1 = nxs2;
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* altsiz_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/hlfbox                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int hlfbox_(real *x1st, real *y1st, real *xinc, real *yinc, 
	char *xy, ftnlen xy_len)
#else /* NO_PROTO */
/* Subroutine */ int hlfbox_(x1st, y1st, xinc, yinc, xy, xy_len)
real *x1st, *y1st, *xinc, *yinc;
char *xy;
ftnlen xy_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    char ch__1[33];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[5], ya[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer ixy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  HLFBOX draws a half-box. */
/*  Input parameters: */
/*    X1ST,Y1ST : starting point */
/*    XINC,YINC : x,y increments */
/*    XY        : switch to determine which increment is to be applied */
/*                first.  X creates a box open at the side, Y creates */
/*                a box open at the top or bottom. */
    if (*xy == 'X') {
	ixy = 2;
    } else if (*xy == 'Y') {
	ixy = 4;
    } else {
/* Writing concatenation */
	i__1[0] = 31, a__1[0] = "HLFBOX called with invalid XY: ";
	i__1[1] = 1, a__1[1] = xy;
	i__1[2] = 1, a__1[2] = ".";
	s_cat(ch__1, a__1, i__1, &c__3, 33L);
	unmsg_(ch__1, 33L);
    }
    xa[0] = *x1st;
    ya[0] = *y1st;
    xa[2] = *x1st + *xinc;
    ya[2] = *y1st + *yinc;
    xa[ixy - 1] = xa[2];
    ya[ixy - 1] = ya[0];
    xa[6 - ixy - 1] = xa[0];
    ya[6 - ixy - 1] = ya[2];
    npl (&c__4, xa, ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* hlfbox_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/simark                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int simark_(integer *mkst, integer *coli, real *mkrad, real *
	cx, real *cy)
#else /* NO_PROTO */
/* Subroutine */ int simark_(mkst, coli, mkrad, cx, cy)
integer *mkst, *coli;
real *mkrad, *cx, *cy;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

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
    static real xa[60], ya[60], ang;
    static char msg[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer siz;
    static real ang2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static integer noseg;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setasf_(integer *), 
	    nsplci (integer *), nslwsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), setasf_(), nsplci (), nslwsc ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___16 = { 0, msg, 0, "(A,I5,A)", 100, 1 };


/*  SIMARK uses polyline to simulate markers of various styles. */

/*  Input parameters: */
/*    MKST   : Marker style (either plus, asterick, or circle) */
/*    COLI   : Color to be used in simulation = index #1 */
/*    MKRAD  : Marker radius in WC */
/*    CX,CY  : Marker center in WC */
/* aspect source */
/*                bundled     individual */
/* linetype */
/* marker type */
/*  use ASFs individual */
    setasf_(&c__1);
/*  use polyline to simulate polymarker */
    nsln (&c__1);
    nsplci (coli);
    nslwsc (&c_b13);
    if (*mkst == 2) {
/*  simulate plus */
	xa[0] = *cx - *mkrad;
	xa[1] = *cx + *mkrad;
	ya[0] = *cy;
	ya[1] = *cy;
	npl (&c__2, xa, ya);
	xa[0] = *cx;
	xa[1] = *cx;
	ya[0] = *cy + *mkrad;
	ya[1] = *cy - *mkrad;
	npl (&c__2, xa, ya);
    } else if (*mkst == 3) {
/* simulate asterisk */
	for (siz = 0; siz <= 2; ++siz) {
#ifndef NO_PROTO
	    ang = siz * 3.14159265f / 3;
#else /* NO_PROTO */
	    ang = siz * (float)3.14159265 / 3;
#endif /* NO_PROTO */
	    xa[0] = *cx + *mkrad * cos(ang);
	    ya[0] = *cy + *mkrad * sin(ang);
#ifndef NO_PROTO
	    ang2 = ang + 3.14159265f;
#else /* NO_PROTO */
	    ang2 = ang + (float)3.14159265;
#endif /* NO_PROTO */
	    xa[1] = *cx + *mkrad * cos(ang2);
	    ya[1] = *cy + *mkrad * sin(ang2);
	    npl (&c__2, xa, ya);
/* L100: */
	}
    } else if (*mkst == 4) {
/* mkst = 4, simulate circle */
	noseg = 40;
	i__1 = noseg + 1;
	for (siz = 1; siz <= i__1; ++siz) {
#ifndef NO_PROTO
	    ang = (siz << 1) * 3.14159265f / noseg;
#else /* NO_PROTO */
	    ang = (siz << 1) * (float)3.14159265 / noseg;
#endif /* NO_PROTO */
	    xa[siz - 1] = *cx + *mkrad * cos(ang);
	    ya[siz - 1] = *cy + *mkrad * sin(ang);
/* L200: */
	}
	i__1 = noseg + 1;
	npl (&i__1, xa, ya);
    } else {
/*  invalid marker type */
	s_wsfi(&io___16);
	do_fio(&c__1, "Invalid marker style passed to SIMARK: ", 39L);
	do_fio(&c__1, (char *)&(*mkst), (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 100L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* simark_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION 04.02/basbot                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal basbot_(integer *wktype, integer *font)
#else /* NO_PROTO */
doublereal basbot_(wktype, font)
integer *wktype, *font;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char str[7] = "ISO Wg2";
#else /* NO_PROTO */
    static char str[7+1] = "ISO Wg2";
#endif /* NO_PROTO */

    /* System generated locals */
    real ret_val;

    /* Local variables */
    static real xb[2], yb[2], ccx, ccy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  BASBOT returns the nominal distance (i.e. for character height = */
/*  1.0) between the baseline and bottom of characters for a given */
/*  workstation type and font. */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    nqtxx (wktype, font, &c_b26, &c_b13, &c_b26, &c__0, &c__1, &c__4, str, &
	    errind, xb, yb, &ccx, &ccy, 7L);
    chkinq_("pqtxx", &errind, 5L);
    ret_val = -(doublereal)yb[0];
    return ret_val;
} /* basbot_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/tstasc                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstasc_(char *prompt, char *tstchs, char *prim, ftnlen 
	prompt_len, ftnlen tstchs_len, ftnlen prim_len)
#else /* NO_PROTO */
/* Subroutine */ int tstasc_(prompt, tstchs, prim, prompt_len, tstchs_len, 
	prim_len)
char *prompt, *tstchs, *prim;
ftnlen prompt_len;
ftnlen tstchs_len;
ftnlen prim_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3;
    real r__1, r__2;
    char ch__1[34];

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer i_len();
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer icx;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static integer prec, perm[100], font;
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), nsep (integer *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), nsep (), pass_();
#endif /* NO_PROTO */
    static real ypos;
#ifndef NO_PROTO
    extern logical dchfl_(char *, integer *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical dchfl_();
#endif /* NO_PROTO */
    static integer chlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
    extern logical fpavl_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
    extern logical fpavl_();
    extern /* Subroutine */ int wcnpc_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nosep (integer *), unmsg_(char *, ftnlen), 
	    nstxi (integer *), nstxr (integer *, integer *, integer *, 
	    integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nosep (), unmsg_(), nstxi (), nstxr ();
#endif /* NO_PROTO */
    static char nlabel[6];
    static logical charng;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb ();
#endif /* NO_PROTO */
    static integer lastch;
    static char ranchs[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int vislab_(char *, char *, real *, real *, real *
	    , real *, ftnlen, ftnlen), nsatch (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int vislab_(), nsatch ();
#endif /* NO_PROTO */
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatal (integer *, integer *), rnperm_(
	    integer *, integer *), nstxal (integer *, integer *), nstxfn (
	    integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatal (), rnperm_(), nstxal (), nstxfn (), 
	    nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___36 = { 0, nlabel, 0, "(I2,A,I2,A)", 6, 1 };


/*  TSTASC accepts a prompt and a test string whose leading character */
/*  is NOT a member of the set being tested.  The rest of the string */
/*  has characters in the expected set.  The characters are displayed */
/*  in random order and the operator must identify the one which */
/*  doesn't belong to the set.  PRIM indicates whether text or */
/*  annotation text is to be tested, and whether individually or bundled. 
*/
/*  Input parameters: */
/*    PROMPT : String with which to prompt the operator */
/*   TSTCHS : String containing a set of similar characters, except the fi
rst*/
/*    PRIM   : Indicates which primitive and mode of test */
/*             T - text/individual */
/*             U - text/bundled */
/*             A - annotation text/individual */
/*             B - annotation text/bundled */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
    chlen = i_len(tstchs, tstchs_len);
#ifndef NO_PROTO
    yincr = .1f;
#else /* NO_PROTO */
    yincr = (float).1;
#endif /* NO_PROTO */
    if (*prim == 'T' || *prim == 'U') {
	r__1 = yincr / 2;
	nschh (&r__1);
	nstxal (&c__1, &c__3);
    } else if (*prim == 'A' || *prim == 'B') {
/*  in Y-direction, NPC/WC ratio */
	wcnpc_(&c_b13, &c_b13, &npcx, &npcy, &npcpwc);
	r__1 = npcpwc * yincr / 2;
	nsatch (&r__1);
	nsatal (&c__1, &c__3);
    } else {
/* Writing concatenation */
	i__1[0] = 33, a__1[0] = "TSTASC called with invalid PRIM: ";
	i__1[1] = 1, a__1[1] = prim;
	s_cat(ch__1, a__1, i__1, &c__2, 34L);
	unmsg_(ch__1, 34L);
    }
/*  mark off start, end of structure to be changed */
    nlb (&c__11);
    nlb (&c__12);
    nosep (&c_n1);
/*  loop thru fonts and precisions */
    for (font = 1; font <= 2; ++font) {
	for (prec = 0; prec <= 2; ++prec) {
/*        skip unavailable font-precision pairs */
	    if (! fpavl_(&globnu_1.wkid, &c__5, &font, &prec)) {
		goto L190;
	    }
	    if (*prim == 'T' || *prim == 'A') {
		nstxfn (&font);
		nstxpr (&prec);
	    } else {
		nstxr (&globnu_1.wkid, &c__2, &font, &prec, &c_b26, &c_b57, &
			c__1);
		nstxi (&c__2);
	    }
/*  scramble TSTCHS into RANCHS: */
	    rnperm_(&chlen, perm);
	    i__2 = chlen;
	    for (icx = 1; icx <= i__2; ++icx) {
		i__3 = perm[icx - 1] - 1;
		s_copy(ranchs + (icx - 1), tstchs + i__3, 1L, perm[icx - 1] - 
			i__3);
/* L110: */
	    }
/*  display all characters in TSTCHS in random order, MAXCH at a t
ime */
	    ypos = 1 - yincr;
	    i__2 = chlen;
	    for (icx = 1; icx <= i__2; icx += 8) {
/* Computing MIN */
		i__3 = icx + 7;
		lastch = min(i__3,chlen);
		s_wsfi(&io___36);
		do_fio(&c__1, (char *)&icx, (ftnlen)sizeof(integer));
		do_fio(&c__1, "-", 1L);
		do_fio(&c__1, (char *)&lastch, (ftnlen)sizeof(integer));
		do_fio(&c__1, ":", 1L);
		e_wsfi();
#ifndef NO_PROTO
		r__1 = ypos - yincr * .3f;
		r__2 = ypos + yincr * .3f;
#else /* NO_PROTO */
		r__1 = ypos - yincr * (float).3;
		r__2 = ypos + yincr * (float).3;
#endif /* NO_PROTO */
		vislab_(nlabel, "R", &c_b70, &c_b71, &r__1, &r__2, 6L, 1L);
		if (*prim == 'T' || *prim == 'U') {
		    ntx (&c_b74, &ypos, ranchs + (icx - 1), lastch - (icx - 1)
			    );
		} else {
		    natr (&c_b74, &ypos, &c_b13, &c_b13, ranchs + (icx - 1), 
			    lastch - (icx - 1));
		}
		ypos -= yincr;
/* L220: */
	    }
	    charng = dchfl_(prompt, &chlen, &c__1, perm, prompt_len);
/*  clear display */
	    nsep (&c__1);
	    ndellb (&c__11, &c__12);
	    if (charng) {
		goto L290;
	    }
L190:
/* L210: */
	    ;
	}
/* L200: */
    }
    pass_();
L290:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* tstasc_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.02/fpavl                       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical fpavl_(integer *wkid, integer *txi, integer *font, integer *prec)
#else /* NO_PROTO */
logical fpavl_(wkid, txi, font, prec)
integer *wkid, *txi, *font, *prec;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix, nfpp, idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
    static integer conid, qprec;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer qfont;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxf ();
#endif /* NO_PROTO */
    static integer wtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxr (), nstxr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  Tests whether a given font and precision will be realized exactly */
/*  as such on the workstation type.  If a requested font is realized */
/*  in a higher precision, it is not considered to be directly */
/*  available. */
/*  Input parameters: */
/*    WKID : Workstation identifier */
/*    TXI  : Identifier for a text bundle which may be altered */
/*    FONT : font whose availability is at issue */
/*    PREC : precision whose availability is at issue */
/* type of returned value */
    nqwkc (wkid, &errind, &conid, &wtype);
    chkinq_("pqwkc", &errind, 5L);
/*  check if font,prec claimed in available list */
    nqtxf (&wtype, &c__0, &errind, &nfpp, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    i__1 = nfpp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&wtype, &ix, &errind, &idum1, &qfont, &qprec, &idum3, &rdum1, &
		rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
	if (qfont == *font && qprec >= *prec) {
	    goto L110;
	}
/* L100: */
    }
/*  font not claimed in list - give up */
    ret_val = FALSE_;
    return ret_val;
/*  check if realized exactly as requested */
L110:
    nstxr (wkid, txi, font, prec, &c_b26, &c_b13, &c__1);
    nqtxr (wkid, txi, &c__1, &errind, &qfont, &qprec, &rdum1, &rdum2, &idum1);

    chkinq_("pqtxr", &errind, 5L);
    ret_val = qfont == *font && qprec == *prec;
    return ret_val;
} /* fpavl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/prpfnt                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int prpfnt_(integer *specwt, integer *bestfn)
#else /* NO_PROTO */
/* Subroutine */ int prpfnt_(specwt, bestfn)
integer *specwt, *bestfn;
#endif /* NO_PROTO */
{
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int subfnt_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int subfnt_();
#endif /* NO_PROTO */

/*  PRPFNT looks for a stroke text font other than 1, preferably not */
/*  #2 and not monospaced. */
/*  Input parameters: */
/*    SPECWT : workstation type */
/*  Output parameters: */
/*    BESTFN : selected font */
    subfnt_(specwt, bestfn, &rdum1, &rdum2, &rdum3, &rdum4);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prpfnt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/varfnt                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int varfnt_(integer *bestfn, real *ncbhtw, real *ncbwdw, 
	real *ncbhti, real *ncbwdi)
#else /* NO_PROTO */
/* Subroutine */ int varfnt_(bestfn, ncbhtw, ncbwdw, ncbhti, ncbwdi)
integer *bestfn;
real *ncbhtw, *ncbwdw, *ncbhti, *ncbwdi;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int subfnt_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int subfnt_();
#endif /* NO_PROTO */

/*  VARFNT looks for a stroke text font other than 1, preferably not */
/*  #2 and not monospaced, and returns nominal size for "W" and "i". */
/*  Output parameters: */
/*    BESTFN        : selected font */
/*    NCBHTW,NCBWDW : nominal height, width of "W" in selected font */
/*    NCBHTI,NCBWDI : nominal height, width of "i" in selected font */
    subfnt_(&dialog_1.specwt, bestfn, ncbhtw, ncbwdw, ncbhti, ncbwdi);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* varfnt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/subfnt                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int subfnt_(integer *specwt, integer *bestfn, real *ncbhtw, 
	real *ncbwdw, real *ncbhti, real *ncbwdi)
#else /* NO_PROTO */
/* Subroutine */ int subfnt_(specwt, bestfn, ncbhtw, ncbwdw, ncbhti, ncbwdi)
integer *specwt, *bestfn;
real *ncbhtw, *ncbwdw, *ncbhti, *ncbwdi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static integer ix, nfpp, perm[400];
    static real txrx[2], txry[2];
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *), nqtxx (integer *, integer *
	    , real *, real *, real *, integer *, integer *, integer *, char *,
	     integer *, real *, real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nqtxf (), nqtxx ();
#endif /* NO_PROTO */
    static real tcbwdi, tcbhti;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer bestsc, errind, fnscor, thisfn;
    static real tcbhtw, tcbwdw;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */
    static integer thispr;

/*  SUBFNT looks for a stroke text font other than 1, preferably not */
/*  #2 and not monospaced, and returns nominal size for "W" and "i". */
/*  Input parameters: */
/*    SPECWT : workstation type */
/*  Output parameters: */
/*    BESTFN        : selected font */
/*    NCBHTW,NCBWDW : nominal height, width of "W" in selected font */
/*    NCBHTI,NCBWDI : nominal height, width of "i" in selected font */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    nqtxf (specwt, &c__0, &errind, &nfpp, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    bestsc = -1;
    *bestfn = 1;
/*  go thru the fonts, in random order, looking for a good one */
    rnperm_(&nfpp, perm);
    i__1 = nfpp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (specwt, &perm[ix - 1], &errind, &idum1, &thisfn, &thispr, &
		idum3, &rdum1, &rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
/*  must be non-1 stroke font */
	if (thisfn == 1 || thispr != 2) {
	    goto L300;
	}
/*  determine */
/*    tcbhtw = nominal character body height for W */
/*    tcbwdw = nominal character body width for W */
	nqtxx (specwt, &thisfn, &c_b26, &c_b13, &c_b26, &c__0, &c__1, &c__5, 
		"WWW", &errind, txrx, txry, &rdum1, &rdum2, 3L);
	chkinq_("pqtxx", &errind, 5L);
	tcbhtw = (r__1 = txry[1] - txry[0], dabs(r__1));
	tcbwdw = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / 3;
/*  determine */
/*    tcbhti = nominal character body height for i */
/*    tcbwdi = nominal character body width for i */
	nqtxx (specwt, &thisfn, &c_b26, &c_b13, &c_b26, &c__0, &c__1, &c__5, 
		"iii", &errind, txrx, txry, &rdum1, &rdum2, 3L);
	chkinq_("pqtxx", &errind, 5L);
	tcbhti = (r__1 = txry[1] - txry[0], dabs(r__1));
	tcbwdi = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / 3;
/*  "goodness" score for this font */
	if (thisfn == 2) {
	    fnscor = 0;
	} else {
	    fnscor = 1;
	}
/*  add 2 to score if not monospaced */
	if (! appeq_(&tcbwdw, &tcbwdi, &c_b13, &c_b119)) {
	    fnscor += 2;
	}
	if (fnscor > bestsc) {
/*  best font so far */
	    bestsc = fnscor;
	    *bestfn = thisfn;
	    *ncbhtw = tcbhtw;
	    *ncbwdw = tcbwdw;
	    *ncbhti = tcbhti;
	    *ncbwdi = tcbwdi;
/*  got a non-2, non-monospaced font */
	    if (fnscor >= 3) {
		goto L310;
	    }
	}
L300:
	;
    }
/*  got_font: */
L310:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* subfnt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/chkfnt                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int chkfnt_(integer *lx, integer *lfn, integer *lpr, integer 
	*maxent, char *chstr, logical *subpre, char *prim, ftnlen chstr_len, 
	ftnlen prim_len)
#else /* NO_PROTO */
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
    static icilist io___93 = { 0, fntlab, 0, "(I5)", 5, 1 };


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
    vislab_("Text below composed from character codes:", "L", &c_b70, &c_b131,
	     &r__1, &ypos, 41L, 1L);
    ypos -= yincr;
#ifndef NO_PROTO
    r__1 = ypos - yincr * .6f;
#else /* NO_PROTO */
    r__1 = ypos - yincr * (float).6;
#endif /* NO_PROTO */
    vislab_(chcods, "L", &c_b70, &c_b131, &r__1, &ypos, itrim_(chcods, 100L), 
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
	s_wsfi(&io___93);
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
	vislab_(ch__1, "R", &c_b70, &c_b143, &r__1, &ypos, 11L, 1L);
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
	wcnpc_(&c_b13, &c_b13, &npcx, &npcy, &npcpwc);
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
	    nschsp (&c_b57);
	} else {
	    nstxr (&globnu_1.wkid, &ix, &lfn[ldisp[ix - 1]], &actpre, &c_b26, 
		    &c_b57, &c__1);
	    nstxi (&ix);
	}
	if (*prim == 'T' || *prim == 'U') {
	    ntx (&c_b71, &ypos, chstr, chstr_len);
	} else {
	    natr (&c_b71, &ypos, &c_b13, &c_b13, chstr, chstr_len);
	}
	ypos -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkfnt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/unrep                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int unrep_(integer *fntid, integer *unrpsz, integer *unrpls, 
	char *prim, char *result, ftnlen prim_len, ftnlen result_len)
#else /* NO_PROTO */
/* Subroutine */ int unrep_(fntid, unrpsz, unrpls, prim, result, prim_len, 
	result_len)
integer *fntid, *unrpsz, *unrpls;
char *prim, *result;
ftnlen prim_len;
ftnlen result_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char repch[1*10] = "*" "@" "&" "#" "^" "%" "$" "!" "?" "}";
#else /* NO_PROTO */
    static char repch[1*10+1] = "*@&#^%$!?}";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3;
    real r__1;
    char ch__1[26], ch__2[16];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, rls[10], uls[10];
    static char str[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static integer prec, perm[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static real npcx, npcy;
    static integer rptr, uptr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), wcnpc_(real *, real *, real *,
	     real *, real *), nemst (integer *), unmsg_(char *, ftnlen), 
	    rnset_(integer *, integer *, integer *), nstxi (integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *);
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int nsatch (real *), opcofl_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), wcnpc_(), nemst (), unmsg_(), 
	    rnset_(), nstxi (), nstxr ();
    extern logical iareql_();
    extern /* Subroutine */ int nsatch (), opcofl_();
#endif /* NO_PROTO */
    static integer anslis[20];
    static real npcpwc;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int dilist_(char *, integer *, integer *, ftnlen),
	     nschsp (real *), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int dilist_(), nschsp (), rnperm_();
#endif /* NO_PROTO */
    static integer nunrep, anssiz, truans[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxfn (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxfn (), nstxpr ();
#endif /* NO_PROTO */

/*  UNREP displays some unrepresentable character codes in the */
/*  requested font and then reports whether these were correctly */
/*  identified by the operator. */
/*  Input parameters: */
/*    FNTID  : Font identifier to be used in displayed text */
/*    UNRPSZ : Size of list of unrepresentable character codes */
/*    UNRPLS : List of unrepresentable character codes */
/*    PRIM   : indicates primitive and mode to be tested: */
/*             T - text/individual */
/*             A - annotation text/individual */
/*             U - text/bundled */
/*             B - annotation text/bundled */
/*  Output parameters: */
/*    RESULT : pass/fail result: P or F */
/* text precision */
    /* Parameter adjustments */
    --unrpls;

    /* Function Body */
    if (*fntid < 1 || *fntid > 2) {
	unmsg_("UNREP called with illegal font identifier.", 42L);
    }
    nstxi (&c__2);
    for (prec = 0; prec <= 2; ++prec) {
	if (*prim == 'U' || *prim == 'B') {
	    nstxr (&globnu_1.wkid, &c__2, fntid, &prec, &c_b26, &c_b57, &c__1)
		    ;
	} else if (*prim == 'T' || *prim == 'A') {
	    nstxfn (fntid);
	    nstxpr (&prec);
	    nschsp (&c_b184);
	} else {
/* Writing concatenation */
	    i__1[0] = 25, a__1[0] = "UNREP called with PRIM = ";
	    i__1[1] = 1, a__1[1] = prim;
	    s_cat(ch__1, a__1, i__1, &c__2, 26L);
	    unmsg_(ch__1, 26L);
	}
	if (*prim == 'T' || *prim == 'U') {
	    nschh (&c_b189);
	} else {
	    wcnpc_(&c_b13, &c_b13, &npcx, &npcy, &npcpwc);
#ifndef NO_PROTO
	    r__1 = npcpwc * .04f;
#else /* NO_PROTO */
	    r__1 = npcpwc * (float).04;
#endif /* NO_PROTO */
	    nsatch (&r__1);
	}
/*  number unrepresented */
/* Computing MIN */
	i__2 = *unrpsz, i__3 = rndint_(&c__2, &c__6);
	nunrep = min(i__2,i__3);
/*  str = random mix of ASCII and unrepresented character codes */
	i__2 = 10 - nunrep;
	rnset_(&i__2, &c__10, rls);
	rnset_(&nunrep, unrpsz, uls);
	rnperm_(&c__10, perm);
	uptr = 0;
	rptr = 0;
	for (ix = 1; ix <= 10; ++ix) {
	    if (perm[ix - 1] <= nunrep) {
		++uptr;
		str[ix - 1] = unrpls[uls[uptr - 1]];
		truans[uptr - 1] = ix;
	    } else {
		++rptr;
		str[ix - 1] = repch[rls[rptr - 1] - 1];
	    }
/* L110: */
	}
	if (*prim == 'T' || *prim == 'U') {
/* Writing concatenation */
	    i__1[0] = 6, a__1[0] = "1-10: ";
	    i__1[1] = 10, a__1[1] = str;
	    s_cat(ch__2, a__1, i__1, &c__2, 16L);
	    ntx (&c_b70, &c_b200, ch__2, 16L);
	} else {
/* Writing concatenation */
	    i__1[0] = 6, a__1[0] = "1-10: ";
	    i__1[1] = 10, a__1[1] = str;
	    s_cat(ch__2, a__1, i__1, &c__2, 16L);
	    natr (&c_b70, &c_b200, &c_b13, &c_b13, ch__2, 16L);
	}
#ifndef NO_PROTO
	dilist_("APPEARANCE OF UNREPRESENTED CHARACTER CODES: The implementa"
		"tion should have a special symbol to indicate the presence o"
		"f a non-representable character code within a character stri"
		"ng.  List, in order, all the character positions containing "
		"this special symbol.", &anssiz, anslis, 259L);
#else /* NO_PROTO */
	dilist_("APPEARANCE OF UNREPRESENTED CHARACTER CODES: The implementa\
tion should have a special symbol to indicate the presence of a non-represen\
table character code within a character string.  List, in order, all the cha\
racter positions containing this special symbol.", &anssiz, anslis, 259L);
#endif /* NO_PROTO */
	nemst (&c__102);
	if (iareql_(&anssiz, anslis, &nunrep, truans)) {
/*           OK so far */
	} else {
	    if (anssiz == 1 && anslis[0] == 0) {
		opcofl_();
	    }
	    *result = 'F';
	    return 0;
	}
/* L100: */
    }
    *result = 'P';
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* unrep_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/ngtxat                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    wcnpc_(&c_b13, &c_b13, &npcx, &npcy, &npcpwc);
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
    numlab_(&c__5, &c_b184, &ytop, &yincr);
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
	    nschup (&c_b13, &yup);
	    nschh (&chht);
	    ntx (&xloc, &yloc, chstr, 7L);
	} else if (*prim == 'A') {
	    nsatcu (&c_b13, &yup);
	    r__1 = npcpwc * chht;
	    nsatch (&r__1);
	    natr (&xloc, &yloc, &c_b13, &c_b13, chstr, 7L);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/txpcup                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int txpcup_(char *prim, ftnlen prim_len)
#else /* NO_PROTO */
/* Subroutine */ int txpcup_(prim, prim_len)
char *prim;
ftnlen prim_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[4];
    integer i__1[3], i__2[4];
    real r__1;
    char ch__1[38], ch__2[110], ch__3[121], ch__4[94];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, chg, dir, rot, txp;
    static real xup, yup;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen), fail_(
	    void), natr (real *, real *, real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx (), fail_(), natr ();
#endif /* NO_PROTO */
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer hdlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    nschh (real *), wcnpc_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), nschh (), wcnpc_();
#endif /* NO_PROTO */
    static integer chpos, opans;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer strid;
    static char chstr[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatp (integer *), nemst (integer *), unmsg_(
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatp (), nemst (), unmsg_();
#endif /* NO_PROTO */
    static integer stype;
    static char opstr[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxp (integer *), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void), chkinq_(char *, 
	    integer *, ftnlen), nsatch (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxp (), dchoic_(), opfail_(), chkinq_(), 
	    nsatch ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatal ();
#endif /* NO_PROTO */
    static real npcpwc;
    static char prmthd[40];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatcu (real *, real *), nschup (real *, real 
	    *), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatcu (), nschup (), rnperm_();
#endif /* NO_PROTO */
    static char suffix[19];
    static integer rotper[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxal ();
#endif /* NO_PROTO */
    static integer txpper[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxfn (integer *), nqopst (integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxfn (), nqopst ();
#endif /* NO_PROTO */

/*  TXPCUP tests the interaction of various text path and character */
/*  up combinations for text and annotation text.  A structure must */
/*  be open and available for emptying. */
/*  Input parameters: */
/*    PRIM : indicates primitive and mode to be tested: */
/*           T - text/individual */
/*           A - annotation text/individual */
/* text alignment horizontal */
/* text alignment vertical */
/* open-structure status */
    nqopst (&errind, &stype, &strid);
    chkinq_("pqopst", &errind, 6L);
    if (stype == 1) {
/*        press on */
    } else {
	unmsg_("TXPCUP aborting, called with no structure open.", 47L);
    }
/*  mostly non-symmetrical characters */
    s_copy(chstr, "SPQR", 4L, 4L);
    rnperm_(&c__4, rotper);
    rnperm_(&c__4, txpper);
    wcnpc_(&c_b13, &c_b13, &npcx, &npcy, &npcpwc);
    for (ix = 1; ix <= 4; ++ix) {
	txp = txpper[ix - 1] - 1;
/*  rotation amount = random 0,90,180,270 degrees */
	rot = rotper[ix - 1] - 1;
/*  0 for horizontal, 1 for vertical */
	dir = (txp / 2 + rot) % 2;
#ifndef NO_PROTO
	xup = 0.f;
	yup = 0.f;
#else /* NO_PROTO */
	xup = (float)0.;
	yup = (float)0.;
#endif /* NO_PROTO */
	if (rot % 2 == 0) {
#ifndef NO_PROTO
	    yup = 1.f - rot;
#else /* NO_PROTO */
	    yup = (float)1. - rot;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    xup = rot - 2.f;
#else /* NO_PROTO */
	    xup = rot - (float)2.;
#endif /* NO_PROTO */
	}
	nstxfn (&c__2);
	if (*prim == 'T') {
	    nschh (&c_b252);
	    nstxp (&txp);
	    nstxal (&c__2, &c__3);
	    nschup (&xup, &yup);
	    ntx (&c_b200, &c_b200, chstr, 4L);
	    s_copy(prmthd, "TEXT PATH AND CHARACTER UP:", 40L, 27L);
	} else if (*prim == 'A') {
#ifndef NO_PROTO
	    r__1 = npcpwc * .1f;
#else /* NO_PROTO */
	    r__1 = npcpwc * (float).1;
#endif /* NO_PROTO */
	    nsatch (&r__1);
	    nsatp (&txp);
	    nsatal (&c__2, &c__3);
	    nsatcu (&xup, &yup);
	    natr (&c_b200, &c_b200, &c_b13, &c_b13, chstr, 4L);
	    s_copy(prmthd, "ANNOTATION TEXT PATH AND CHARACTER UP:", 40L, 38L)
		    ;
	} else {
/* Writing concatenation */
	    i__1[0] = 36, a__1[0] = "TXPCUP aborting, called with PRIM = ";
	    i__1[1] = 1, a__1[1] = prim;
	    i__1[2] = 1, a__1[2] = ".";
	    s_cat(ch__1, a__1, i__1, &c__3, 38L);
	    unmsg_(ch__1, 38L);
	}
	hdlen = itrim_(prmthd, 40L) + 1;
/* Writing concatenation */
	i__1[0] = hdlen, a__1[0] = prmthd;
	i__1[1] = 26, a__1[1] = "Is text string as a whole ";
	i__1[2] = 44, a__1[2] = "oriented horizontally (1) or vertically (2)?"
		;
	s_cat(ch__2, a__1, i__1, &c__3, 110L);
	dchoic_(ch__2, &c__0, &c__2, &opans, hdlen + 70);
	if (opans == 0) {
	    opfail_();
	    goto L60;
	} else if (dir + 1 != opans) {
	    fail_();
	    goto L60;
	}
/* Writing concatenation */
	i__2[0] = hdlen, a__2[0] = prmthd;
	i__2[1] = 20, a__2[1] = "Is the character up ";
	i__2[2] = 42, a__2[2] = "direction to the left (1), top (2), right ";
	i__2[3] = 19, a__2[3] = "(3), or bottom (4)?";
	s_cat(ch__3, a__2, i__2, &c__4, 121L);
	dchoic_(ch__3, &c__0, &c__4, &opans, hdlen + 81);
	if (opans == 0) {
	    opfail_();
	    goto L60;
	} else if ((rot + opans) % 4 != 2) {
	    fail_();
	    goto L60;
	}
	if (dir == 0) {
	    s_copy(suffix, "left of the screen.", 19L, 19L);
	} else {
	    s_copy(suffix, "top of the screen.", 19L, 18L);
	}
/* Writing concatenation */
	i__2[0] = hdlen, a__2[0] = prmthd;
	i__2[1] = 23, a__2[1] = "Identify the character ";
	i__2[2] = 12, a__2[2] = "nearest the ";
	i__2[3] = 19, a__2[3] = suffix;
	s_cat(ch__4, a__2, i__2, &c__4, 94L);
	dline_(ch__4, opstr, hdlen + 54, 80L);
	if (s_cmp(opstr, "0", 80L, 1L) == 0) {
	    opfail_();
	    goto L60;
	} else {
/*  CHG = odd  if rotation changes "first" character of text path 
*/
/*        even if rotation does not change it */
	    chg = (rot + 1 - txp / 2) / 2;
/*  0 for 1st character, 1 for last */
	    chpos = (chg + (txp + 1) / 2) % 2;
	    chpos = chpos * 3 + 1;
	    if (s_cmp(opstr, chstr + (chpos - 1), 80L, 1L) != 0) {
		fail_();
		goto L60;
	    }
	}
	nemst (&strid);
/*  next txp */
/* L50: */
    }
    pass_();
/*  end_text_path: */
L60:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* txpcup_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02/distxb                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int distxb_(integer *samp, integer *start, integer *univ, 
	integer *subset)
#else /* NO_PROTO */
/* Subroutine */ int distxb_(samp, start, univ, subset)
integer *samp, *start, *univ, *subset;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i, j, k, jj, ot, jcoli, kcoli, jprec, kprec;
    static real jchsp, kchsp, jchxp, kchxp;
    static integer jfont, kfont;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, maxloc, atrcnt, maxatr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static logical atrnew[5];
    static integer optatr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqptxr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqptxr ();
#endif /* NO_PROTO */

/*  DISTXB selects SAMP predefined bundles at random from the */
/*  text bundle table which are distinct in all their attributes. */
/*  If there are not SAMP completely distinct bundles, DISTXB tries */
/*  to maximize the number of different attributes. */

/*  Input parameters: */
/*    SAMP        : number of predefined bundles to be picked */
/*    START       : starting index */
/*    UNIV        : last element in universe to pick from */
/*  Output parameters: */
/*    SUBSET      : array containing the selected distinct bundles */
/*  total number of attributes */
    /* Parameter adjustments */
    --subset;

    /* Function Body */
    if (*univ + 1 - *start < *samp) {
#ifndef NO_PROTO
	unmsg_("Abort in DISTXB because size of universe is less than reques"
		"ted sample.", 71L);
#else /* NO_PROTO */
	unmsg_("Abort in DISTXB because size of universe is less than reques\
ted sample.", 71L);
#endif /* NO_PROTO */
    }
/*  OPTATR is the best possible number of attributes that can be distinct 
*/
    optatr = 5;
/*  this loop picks out samp elements */
    i__1 = *samp;
    for (i = 1; i <= i__1; ++i) {
/*  number of new attribute values so far */
	maxatr = -1;
/*  look at entire universe each time, starting at random location */
	j = rndint_(start, univ);
	i__2 = *univ;
	for (jj = *start; jj <= i__2; ++jj) {
	    if (j >= *univ) {
/*  cycle around to beginning */
		j = *start;
	    } else {
		++j;
	    }
	    for (ot = 1; ot <= 5; ++ot) {
		atrnew[ot - 1] = TRUE_;
/* L50: */
	    }
/*  get attributes of next candidate */
	    nqptxr (&dialog_1.specwt, &j, &errind, &jfont, &jprec, &jchxp, &
		    jchsp, &jcoli);
	    chkinq_("pqptxr", &errind, 6L);
/*  check against all those picked so far; */
	    i__3 = i - 1;
	    for (k = 1; k <= i__3; ++k) {
/*  if already picked, get another j */
		if (j == subset[k]) {
		    goto L400;
		}
		nqptxr (&dialog_1.specwt, &subset[k], &errind, &kfont, &kprec,
			 &kchxp, &kchsp, &kcoli);
		chkinq_("pqptxr", &errind, 6L);
/*  check all attributes */
		if (jfont == kfont) {
		    atrnew[0] = FALSE_;
		}
		if (jprec == kprec) {
		    atrnew[1] = FALSE_;
		}
		if (jchxp == kchxp) {
		    atrnew[2] = FALSE_;
		}
		if (jchsp == kchsp) {
		    atrnew[3] = FALSE_;
		}
		if (jcoli == kcoli) {
		    atrnew[4] = FALSE_;
		}
/* L300: */
	    }
/*  count # of trues */
	    atrcnt = 0;
	    for (ot = 1; ot <= 5; ++ot) {
		if (atrnew[ot - 1]) {
		    ++atrcnt;
		}
/* L75: */
	    }
/*  take the best so far */
	    if (atrcnt > maxatr) {
		maxatr = atrcnt;
		maxloc = j;
	    }
/*  cannot get better than OPTATR */
	    if (maxatr >= optatr) {
		goto L410;
	    }
L400:
	    ;
	}
/*  put best one on the list */
L410:
	subset[i] = maxloc;
/*  remember greatest number of distinct attributes */
	optatr = maxatr;
/* L500: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* distxb_ */

