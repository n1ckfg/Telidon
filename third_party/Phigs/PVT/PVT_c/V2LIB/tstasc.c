/* tstasc.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b8 = 0.f;
#else /* NO_PROTO */
static real c_b8 = (float)0.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__11 = 11;
static integer c__12 = 12;
static integer c_n1 = -1;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b24 = 1.f;
static real c_b25 = .2f;
static real c_b38 = .05f;
static real c_b39 = .35f;
static real c_b42 = .4f;

/* Subroutine */ int tstasc_(char *prompt, char *tstchs, char *prim, ftnlen 
	prompt_len, ftnlen tstchs_len, ftnlen prim_len)
#else /* NO_PROTO */
static real c_b24 = (float)1.;
static real c_b25 = (float).2;
static real c_b38 = (float).05;
static real c_b39 = (float).35;
static real c_b42 = (float).4;

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
    static icilist io___14 = { 0, nlabel, 0, "(I2,A,I2,A)", 6, 1 };


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
	wcnpc_(&c_b8, &c_b8, &npcx, &npcy, &npcpwc);
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
		nstxr (&globnu_1.wkid, &c__2, &font, &prec, &c_b24, &c_b25, &
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
		s_wsfi(&io___14);
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
		vislab_(nlabel, "R", &c_b38, &c_b39, &r__1, &r__2, 6L, 1L);
		if (*prim == 'T' || *prim == 'U') {
		    ntx (&c_b42, &ypos, ranchs + (icx - 1), lastch - (icx - 1)
			    );
		} else {
		    natr (&c_b42, &ypos, &c_b8, &c_b8, ranchs + (icx - 1), 
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

