/* coltrn.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b4 = 0.f;
static real c_b5 = 1.f;
#else /* NO_PROTO */
static real c_b4 = (float)0.;
static real c_b5 = (float)1.;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b13 = .02f;
#else /* NO_PROTO */
static real c_b13 = (float).02;
#endif /* NO_PROTO */
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b20 = .1f;
#else /* NO_PROTO */
static real c_b20 = (float).1;
#endif /* NO_PROTO */
static integer c__7 = 7;
static integer c__6 = 6;

#ifndef NO_PROTO
/* Subroutine */ int coltrn_(integer *wkid, char *colabl, real *fromcc, 
	integer *frommd, real *tocc, integer *tomd, char *srs, ftnlen 
	colabl_len, ftnlen srs_len)
#else /* NO_PROTO */
/* Subroutine */ int coltrn_(wkid, colabl, fromcc, frommd, tocc, tomd, srs, 
	colabl_len, srs_len)
integer *wkid;
char *colabl;
real *fromcc;
integer *frommd;
real *tocc;
integer *tomd;
char *srs;
ftnlen colabl_len;
ftnlen srs_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char modnam[3*4] = "RGB" "CIE" "HSV" "HLS";
#else /* NO_PROTO */
    static char modnam[3*4+1] = "RGBCIEHSVHLS";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[7], a__2[6];
    integer i__1[7], i__2[6];
    logical L__1;
    char ch__1[66], ch__2[56], ch__3[92];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi();
    /* Subroutine */ int s_cat();
    integer do_fio(), e_wsfi();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer do_fio(integer *, char *, ftnlen), e_wsfi(void);

#endif /* not NO_PROTO */
    /* Local variables */
    static integer ix, iy;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *), nscr (
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqcr (), nscr ();
#endif /* NO_PROTO */
    static real cspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), inmsg_(char *, 
	    ftnlen);
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), inmsg_();
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static real actcol[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
    extern logical coleql_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
    extern logical coleql_();
#endif /* NO_PROTO */
    static integer errind;
    static real expcol[3];
    static integer passct;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer numret;

    /* Fortran I/O blocks */
    static icilist io___11 = { 0, msg, 0, "(A)", 300, 1 };


/*  COLTRN tests the ability to translate color from one model to */
/*  another and issues pass or fail as a result. */
/*  Input parameters: */
/*    WKID   : workstation identifier */
/*    COLABL : labels (names) of colors to be tested */
/*    FROMCC : color coordinates to translate from */
/*    FROMMD : color model to translate from */
/*    TOCC   : color coordinates to translate to (expected result) */
/*    TOMD   : color model to translate to */
/*    SRS    : SR identifiers for test case */
/* colour model */
/* type of returned value */
    /* Parameter adjustments */
    tocc -= 4;
    fromcc -= 4;
    colabl -= 8;

    /* Function Body */
    passct = 0;
    for (ix = 1; ix <= 9; ++ix) {
/* <set colour model> */
	nscmd (wkid, frommd);
/*  <set colour representation> index #1, entry #ix, change -1 to */
/*     random value between 0 and 1 */
	for (iy = 1; iy <= 3; ++iy) {
#ifndef NO_PROTO
	    if (fromcc[iy + ix * 3] == -1.f) {
#else /* NO_PROTO */
	    if (fromcc[iy + ix * 3] == (float)-1.) {
#endif /* NO_PROTO */
		cspec[iy - 1] = rndrl_(&c_b4, &c_b5);
	    } else {
		cspec[iy - 1] = fromcc[iy + ix * 3];
	    }
	    expcol[iy - 1] = tocc[iy + ix * 3];
/* L110: */
	}
	nscr (wkid, &c__1, &c__3, cspec);
	nqcr (wkid, &c__1, &c__3, &c__1, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
/*  attempt to convert only realizable colors */
	if (! coleql_(&c__3, actcol, cspec, &c_b13, &c_b4)) {
	    goto L100;
	}
/*  <re-set colour model> */
	nscmd (wkid, tomd);
/*  <inquire colour representation> as SET, to determine cspec */
	nqcr (wkid, &c__1, &c__3, &c__0, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
	if (numret == 3 && coleql_(&c__3, actcol, expcol, &c_b20, &c_b4)) {
/*  OK so far */
	    ++passct;
	} else {
	    passct = -666;
	    s_wsfi(&io___11);
/* Writing concatenation */
	    i__1[0] = 33, a__1[0] = "Fail to change colour model from ";
	    i__1[1] = 3, a__1[1] = modnam + (*frommd - 1) * 3;
	    i__1[2] = 4, a__1[2] = " to ";
	    i__1[3] = 3, a__1[3] = modnam + (*tomd - 1) * 3;
	    i__1[4] = 14, a__1[4] = " for colour = ";
	    i__1[5] = 8, a__1[5] = colabl + (ix << 3);
	    i__1[6] = 1, a__1[6] = ".";
	    s_cat(ch__1, a__1, i__1, &c__7, 66L);
	    do_fio(&c__1, ch__1, 66L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	}
L100:
	;
    }
    if (passct == 0) {
/* Writing concatenation */
	i__1[0] = 14, a__1[0] = "No realizable ";
	i__1[1] = 3, a__1[1] = modnam + (*frommd - 1) * 3;
	i__1[2] = 12, a__1[2] = " colors for ";
	i__1[3] = 3, a__1[3] = modnam + (*frommd - 1) * 3;
	i__1[4] = 4, a__1[4] = " to ";
	i__1[5] = 3, a__1[5] = modnam + (*tomd - 1) * 3;
	i__1[6] = 17, a__1[6] = " conversion test.";
	s_cat(ch__2, a__1, i__1, &c__7, 56L);
	inmsg_(ch__2, 56L);
    } else {
/* Writing concatenation */
	i__2[0] = 31, a__2[0] = "Changing the colour model from ";
	i__2[1] = 3, a__2[1] = modnam + (*frommd - 1) * 3;
	i__2[2] = 4, a__2[2] = " to ";
	i__2[3] = 3, a__2[3] = modnam + (*tomd - 1) * 3;
	i__2[4] = 38, a__2[4] = " should not affect the colours in the ";
	i__2[5] = 13, a__2[5] = "colour table.";
	s_cat(ch__3, a__2, i__2, &c__6, 92L);
	setmsg_(srs, ch__3, srs_len, 92L);
	L__1 = passct > 0;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* coltrn_ */

