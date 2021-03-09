/* unrep.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b8 = 1.f;
static real c_b9 = .2f;
#else /* NO_PROTO */
static real c_b8 = (float)1.;
static real c_b9 = (float).2;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b13 = .15f;
static real c_b18 = .04f;
static real c_b19 = 0.f;
#else /* NO_PROTO */
static real c_b13 = (float).15;
static real c_b18 = (float).04;
static real c_b19 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b28 = .05f;
static real c_b29 = .5f;
#else /* NO_PROTO */
static real c_b28 = (float).05;
static real c_b29 = (float).5;
#endif /* NO_PROTO */
static integer c__102 = 102;

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

#ifndef NO_PROTO

#endif /* not NO_PROTO */
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
	    nstxr (&globnu_1.wkid, &c__2, fntid, &prec, &c_b8, &c_b9, &c__1);
	} else if (*prim == 'T' || *prim == 'A') {
	    nstxfn (fntid);
	    nstxpr (&prec);
	    nschsp (&c_b13);
	} else {
/* Writing concatenation */
	    i__1[0] = 25, a__1[0] = "UNREP called with PRIM = ";
	    i__1[1] = 1, a__1[1] = prim;
	    s_cat(ch__1, a__1, i__1, &c__2, 26L);
	    unmsg_(ch__1, 26L);
	}
	if (*prim == 'T' || *prim == 'U') {
	    nschh (&c_b18);
	} else {
	    wcnpc_(&c_b19, &c_b19, &npcx, &npcy, &npcpwc);
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
	    ntx (&c_b28, &c_b29, ch__2, 16L);
	} else {
/* Writing concatenation */
	    i__1[0] = 6, a__1[0] = "1-10: ";
	    i__1[1] = 10, a__1[1] = str;
	    s_cat(ch__2, a__1, i__1, &c__2, 16L);
	    natr (&c_b28, &c_b29, &c_b19, &c_b19, ch__2, 16L);
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

