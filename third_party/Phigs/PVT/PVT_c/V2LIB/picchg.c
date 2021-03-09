/* picchg.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__50 = 50;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b67 = 1.f;
#else /* NO_PROTO */
static real c_b67 = (float)1.;
#endif /* NO_PROTO */
static integer c__201 = 201;
#ifndef NO_PROTO
static real c_b87 = .5f;
#else /* NO_PROTO */
static real c_b87 = (float).5;
#endif /* NO_PROTO */
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int picchg_(integer *wkid, char *sevlst, char *pcclst, 
	integer *actsev, integer *actpcc, ftnlen sevlst_len, ftnlen 
	pcclst_len)
#else /* NO_PROTO */
/* Subroutine */ int picchg_(wkid, sevlst, pcclst, actsev, actpcc, sevlst_len,
	 pcclst_len)
integer *wkid;
char *sevlst, *pcclst;
integer *actsev, *actpcc;
ftnlen sevlst_len;
ftnlen pcclst_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer postct = 1;
    static integer killct = 1;
    static integer oldstr = 401;
    static integer pccsev[17] = { 666,666,666,666,666,666,666,666,666,666,666,
	    666,666,666,666,666,666 };

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double r_mod(real *, real *);
    integer pow_ii(integer *, integer *);
#else /* NO_PROTO */
    double r_mod();
    integer pow_ii();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ii, ix;
    static real px[10], py[10];
    static integer pdx, pdy;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ndel (void), 
	    nqif (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqcr (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *), 
	    nscr (integer *, integer *, integer *, real *), ndst (integer *), 
	    nqir (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ndel (), nqif (), nqcr (), nscr (), 
	    ndst (), nqir (), nsir ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum4[16]	/* was [4][4] */, rdum5[16]	/* 
	    was [4][4] */, rdum6[6];
    static integer colia[2500]	/* was [50][50] */, fclip;
    static real cspec[3];
    static integer pccdx;
    static real chexp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedr (), nsedr ();
#endif /* NO_PROTO */
    static integer inset[50];
    static logical nopat;
    static integer sevdx, exset[50], insiz, ltype, mtype;
    static real curvp[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer exsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nqplr (integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *), nsplr (integer *, integer *, integer *, real *
	    , integer *), nqpmr (integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), nspmr (integer *, integer *, 
	    integer *, real *, integer *), nqpar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nqhrm (
	    integer *, integer *, integer *, integer *, integer *), nqtxr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), nqvwr (integer *, integer *, integer *
	    , integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *), nstxr (integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), nshrm (integer *, integer *
	    ), nopst (integer *), nclst (void), npost (integer *, integer *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_(), nqplr (), nsplr (), nqpmr (), 
	    nspmr (), nqpar (), nspar (), nqhrm (), nqtxr (), nqvwr (), 
	    nstxr (), nshrm (), nopst (), nclst (), npost ();
#endif /* NO_PROTO */
    static real radum1[6], radum2[6], radum3[6];
    static integer edflag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkt3 (integer *, integer *, integer *, real 
	    *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkt3 ();
#endif /* NO_PROTO */
    static integer pcccod[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nswkv3 (integer *, real *), nsvwr3 (integer *,
	     integer *, real *, real *, real *, integer *, integer *, integer 
	    *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nswkv3 (), nsvwr3 (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, specwt, sevcod[10], pccsiz, naints, thisis,
	     istyle, numret, curmod, sevsiz, numode, newmod, newstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdswa (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nqdstr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nqhlft (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nshlft (integer *, 
	    integer *, integer *, integer *, integer *), nqivft (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nsivft (integer *, integer *, integer *, integer *, 
	    integer *), nqhrmf (integer *, integer *, integer *, integer *, 
	    integer *), nupost (integer *, integer *), ncstrf (integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdswa (), nqdstr (), nqhlft (), nshlft (), 
	    nqivft (), nsivft (), nqhrmf (), nupost (), ncstrf ();
#endif /* NO_PROTO */

/*  PICCHG: attempts to perform a visual change according to the */
/*  preferred order of the requested severity-list and of the */
/*  specified categories (a subset of the 17 kinds of picture */
/*  change).  It then returns the actual severity and actual picture */
/*  change category performed, or indicates that nothing in the */
/*  severity-list / pcc-list combination could be done. */
/*  --- Input Parameters: */
/*  wkid    : Identifier of workstation for picture change */
/*  sevlst  : List of severity codes in preferred order, */
/*            string format.  E.g. '0,2' means first try IRG, */
/*            then CBS. */
/*  pcclst  : List of picture change categories in preferred */
/*            order (within a given severity code), string format. */
/*            E.g. '2,3' means first try polymarker bundle change, */
/*            then text bundle change. */

/*  --- Output Parameters: */
/*  actsev  : Severity code of actual change; 0 if nothing done. */
/*  actpcc  : Picture change category code of actual change; 0 if */
/*            nothing done. */
/* attribute identifier */
/* aspect source */
/*                bundled     individual */
/* clipping indicator */
/*                noclip      clip */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* type of returned value */
/* linetype */
/* marker type */
/* polyline/fill area control flag */
/* dynamic modification */
/* Current and Requested values. */
/* size of pattern-aray */
/*  postct keeps track of new structure to be posted */
/*  killct keeps track of old structures to be deleted or unposted */
/*  which structure is currently referenced? */
/*  Category codes: */

/*  01 : polyline bundle representation */
/*  02 : polymarker bundle representation */
/*  03 : text bundle representation */
/*  04 : interior bundle representation */
/*  05 : edge bundle representation */
/*  06 : pattern representation */
/*  07 : colour representation */
/*  08 : view representation */
/*  09 : workstation transformation */
/*  10 : highlighting filter */
/*  11 : invisibility filter */
/*  12 : HLHSR mode */
/*  13 : structure content */
/*  14 : post structure */
/*  15 : unpost structure */
/*  16 : delete structure */
/*  17 : reference modification */
/*  convert lists to numeric */
    setvs_(sevlst, sevcod, &sevsiz, sevlst_len);
    setvs_(pcclst, pcccod, &pccsiz, pcclst_len);
/*  specific workstation type from wkid */
    nqwkc (wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  get actual severity codes */
    nqdswa (&specwt, &errind, pccsev, &pccsev[1], &pccsev[2], &pccsev[3], &
	    pccsev[4], &pccsev[5], &pccsev[6], &pccsev[7], &pccsev[8], &
	    pccsev[9], &pccsev[10], &pccsev[11]);
    chkinq_("pqdswa", &errind, 6L);
    nqdstr (&specwt, &errind, &pccsev[12], &pccsev[13], &pccsev[14], &pccsev[
	    15], &pccsev[16]);
    chkinq_("pqdstr", &errind, 6L);
/*  determine pattern availability */
/*     nopat = no pattern interior style available */
    nopat = FALSE_;
    nqif (&specwt, &c__0, &c__0, &errind, &naints, &idum1, &idum2, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
/* loop thru list of available interior styles till find PPATTR */
    i__1 = naints;
    for (ii = 1; ii <= i__1; ++ii) {
	nqif (&specwt, &ii, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis == 2) {
	    goto L25;
	}
/* L20: */
    }
    nopat = TRUE_;
L25:
/*  run through all eligible severities and change-categories */
    i__1 = sevsiz;
    for (sevdx = 1; sevdx <= i__1; ++sevdx) {
	*actsev = sevcod[sevdx - 1];
	i__2 = pccsiz;
	for (pccdx = 1; pccdx <= i__2; ++pccdx) {
	    *actpcc = pcccod[pccdx - 1];
	    if (pccsev[*actpcc - 1] == *actsev) {
		if (*actpcc == 6 && nopat) {
/*                 do nothing - pattern requested but unav
ailable */
		} else {
		    goto L1000;
		}
	    }
/* L110: */
	}
/* L100: */
    }
/*  failed to find available combination */
    *actsev = 0;
    *actpcc = 0;
    return 0;
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  got performable picture change category = actpcc */
L1000:
#ifndef NO_PROTO
    switch (*actpcc) {
#else /* NO_PROTO */
    switch ((int)*actpcc) {
#endif /* NO_PROTO */
	case 1:  goto L2010;
	case 2:  goto L2020;
	case 3:  goto L2030;
	case 4:  goto L2040;
	case 5:  goto L2050;
	case 6:  goto L2060;
	case 7:  goto L2070;
	case 8:  goto L2080;
	case 9:  goto L2090;
	case 10:  goto L2100;
	case 11:  goto L2110;
	case 12:  goto L2120;
	case 13:  goto L2130;
	case 14:  goto L2140;
	case 15:  goto L2150;
	case 16:  goto L2160;
	case 17:  goto L2170;
    }
/*  01:polyline bundle representation */
L2010:
    nqplr (wkid, &c__1, &c__0, &errind, &ltype, &rdum1, &idum1);
    chkinq_("pqplr", &errind, 5L);
    ltype = ltype % 4 + 1;
    nsplr (wkid, &c__1, &ltype, &rdum1, &idum1);
    goto L3000;
/*  02:polymarker bundle representation */
L2020:
    nqpmr (wkid, &c__1, &c__0, &errind, &mtype, &rdum1, &idum1);
    chkinq_("pqpmr", &errind, 5L);
    mtype = mtype % 5 + 1;
    nspmr (wkid, &c__1, &mtype, &rdum1, &idum1);
    goto L3000;
/*  03:text bundle representation */
L2030:
    nqtxr (wkid, &c__1, &c__0, &errind, &idum1, &idum2, &chexp, &rdum1, &
	    idum3);
    chkinq_("pqtxr", &errind, 5L);
#ifndef NO_PROTO
    chexp *= 1.05f;
#else /* NO_PROTO */
    chexp *= (float)1.05;
#endif /* NO_PROTO */
    nstxr (wkid, &c__1, &idum1, &idum2, &chexp, &rdum1, &idum3);
    goto L3000;
/*  04:interior bundle representation */
L2040:
    nqir (wkid, &c__1, &c__0, &errind, &istyle, &idum1, &idum2);
    chkinq_("pqir", &errind, 4L);
/* these two styles are mandatory */
    if (istyle == 0) {
	istyle = 4;
    } else {
	istyle = 0;
    }
    nsir (wkid, &c__1, &istyle, &idum1, &idum2);
    goto L3000;
/*  05:edge bundle representation */
L2050:
    nqedr (wkid, &c__1, &c__0, &errind, &edflag, &idum1, &rdum1, &idum2);
    chkinq_("pqedr", &errind, 5L);
    edflag = 1 - edflag;
    nsedr (wkid, &c__1, &edflag, &idum1, &rdum1, &idum2);
    goto L3000;
/*  06:pattern representation */
L2060:
    nqpar (wkid, &c__1, &c__0, &c__50, &c__50, &errind, &pdx, &pdy, colia);
    chkinq_("pqpar", &errind, 5L);
    if (colia[0] == 0) {
	colia[0] = 1;
    } else {
	colia[0] = 0;
    }
    nspar (wkid, &c__1, &c__50, &c__50, &c__1, &c__1, &pdx, &pdy, colia);
    goto L3000;
/*  07:colour representation */
L2070:
    nqcr (wkid, &c__1, &c__3, &c__0, &errind, &numret, cspec);
    chkinq_("pqcr", &errind, 4L);
#ifndef NO_PROTO
    r__1 = cspec[numret - 1] + .5f;
#else /* NO_PROTO */
    r__1 = cspec[numret - 1] + (float).5;
#endif /* NO_PROTO */
    cspec[numret - 1] = r_mod(&r__1, &c_b67);
    nscr (wkid, &c__1, &numret, cspec);
    goto L3000;
/*  08:view representation */
L2080:
    nqvwr (wkid, &c__1, &c__0, &errind, &idum1, rdum4, rdum5, rdum6, &idum2, &
	    idum3, &fclip);
    chkinq_("pqvwr", &errind, 5L);
    fclip = 1 - fclip;
    nsvwr3 (wkid, &c__1, rdum4, rdum5, rdum6, &idum2, &idum3, &fclip);
    goto L3000;
/*  09:workstation transformation */
L2090:
    nqwkt3 (wkid, &errind, &idum1, radum1, radum2, radum3, curvp);
    chkinq_("pqwkt3", &errind, 6L);
/* shrink y-dim of viewport slightly */
#ifndef NO_PROTO
    curvp[3] = (curvp[3] - curvp[2]) * .99f + curvp[2];
#else /* NO_PROTO */
    curvp[3] = (curvp[3] - curvp[2]) * (float).99 + curvp[2];
#endif /* NO_PROTO */
    nswkv3 (wkid, curvp);
    goto L3000;
/*  10:highlighting filter */
L2100:
    nqhlft (wkid, &c__50, &c__50, &errind, &insiz, inset, &exsiz, exset);
    chkinq_("pqhlft", &errind, 6L);
    exsiz = 0;
    if (insiz == 0) {
	insiz = 1;
	inset[0] = 1;
    } else {
	insiz = 0;
    }
    nshlft (wkid, &insiz, inset, &exsiz, exset);
    goto L3000;
/*  11:invisibility filter */
L2110:
    nqivft (wkid, &c__50, &c__50, &errind, &insiz, inset, &exsiz, exset);
    chkinq_("pqivft", &errind, 6L);
    exsiz = 0;
    if (insiz == 0) {
	insiz = 1;
	inset[0] = 2;
    } else {
	insiz = 0;
    }
    nsivft (wkid, &insiz, inset, &exsiz, exset);
    goto L3000;
/*  12:HLHSR mode */
L2120:
    nqhrm (wkid, &errind, &idum1, &curmod, &idum2);
    chkinq_("pqhrm", &errind, 5L);
    nqhrmf (&specwt, &c__0, &errind, &numode, &idum3);
    chkinq_("pqhrmf", &errind, 6L);
/* look for different, valid mode */
    i__1 = numode;
    for (ix = 1; ix <= i__1; ++ix) {
	nqhrmf (&specwt, &ix, &errind, &idum3, &newmod);
	chkinq_("pqhrmf", &errind, 6L);
	if (newmod != curmod) {
	    goto L2127;
	}
/* L2125: */
    }
    newmod = curmod;
L2127:
    nshrm (wkid, &newmod);
    goto L3000;
/*  13:structure content */
L2130:
/* delete last element of 201 */
    nopst (&c__201);
    ndel ();
    nclst ();
    goto L3000;
/*  14:post structure */
L2140:
/*  PCC 14 posts a new structure 5xx, with vertical lines. */
    i__1 = postct + 500;
    npost (wkid, &i__1, &c_b87);
#ifndef NO_PROTO
    py[0] = .4f;
    py[1] = .6f;
    px[0] = 1.f / pow_ii(&c__2, &postct);
#else /* NO_PROTO */
    py[0] = (float).4;
    py[1] = (float).6;
    px[0] = (float)1. / pow_ii(&c__2, &postct);
#endif /* NO_PROTO */
    px[1] = px[0];
    i__1 = postct + 500;
    nopst (&i__1);
    npl (&c__2, px, py);
    nclst ();
    ++postct;
    goto L3000;
/*  15:unpost structure */
L2150:
    i__1 = killct + 300;
    nupost (wkid, &i__1);
    ++killct;
    goto L3000;
/*  16:delete structure */
L2160:
    i__1 = killct + 300;
    ndst (&i__1);
    ++killct;
    goto L3000;
/*  17:reference modification */
L2170:
/* alternate between 401 and 402 */
    newstr = 803 - oldstr;
    ncstrf (&oldstr, &newstr);
    oldstr = newstr;
    goto L3000;
L3000:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* picchg_ */

