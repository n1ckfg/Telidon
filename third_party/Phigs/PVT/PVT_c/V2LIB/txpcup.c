/* txpcup.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b7 = 0.f;
#else /* NO_PROTO */
static real c_b7 = (float)0.;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b12 = .1f;
#else /* NO_PROTO */
static real c_b12 = (float).1;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b15 = .5f;
#else /* NO_PROTO */
static real c_b15 = (float).5;
#endif /* NO_PROTO */
static integer c__0 = 0;

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
    wcnpc_(&c_b7, &c_b7, &npcx, &npcy, &npcpwc);
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
	    nschh (&c_b12);
	    nstxp (&txp);
	    nstxal (&c__2, &c__3);
	    nschup (&xup, &yup);
	    ntx (&c_b15, &c_b15, chstr, 4L);
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
	    natr (&c_b15, &c_b15, &c_b7, &c_b7, chstr, 4L);
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

