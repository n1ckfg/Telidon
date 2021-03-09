/* fort/04/03/02/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__6 = 6;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b60 = .01f;
static real c_b61 = 0.f;
#else /* NO_PROTO */
static real c_b60 = (float).01;
static real c_b61 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/04                        * */
/*  *    TEST TITLE : Colour specification facilities       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ci;
    static real val;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer cola, nacm;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer imod;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer ncol;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr ();
#endif /* NO_PROTO */
    static real rdum[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    , pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr (), pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2;
    static real cspec[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nscmd (integer *, integer *);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nscmd ();
    extern logical rareq_();
    extern /* Subroutine */ int inmsg_(), nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static real actcol[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf ();
#endif /* NO_PROTO */
    static integer colmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer setcod, errind, specon;
    static real expcol[3], newcol[3];
    static logical inqerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static logical seterr;
    static integer specwt;
    static real inqprm[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int errctl_(logical *), setmsg_(char *, char *, 
	    ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int errctl_(), setmsg_();
#endif /* NO_PROTO */
    static integer numret;
    static real setprm[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___18 = { 0, msg, 0, "(A,I5,A,I2,A,3F9.3)", 300, 1 };
    static icilist io___19 = { 0, msg, 0, "(A,I2,A,3F9.3)", 300, 1 };


/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.03.02.02/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqcmdf (&specwt, &c__0, &errind, &nacm, &idum1, &idum2);
    chkinq_("pqcmdf", &errind, 6L);
/* no set or inquire error yet */
    seterr = FALSE_;
    inqerr = FALSE_;
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
/* go thru registered color models */
    i__1 = nacm;
    for (imod = 1; imod <= i__1; ++imod) {
	nqcmdf (&specwt, &imod, &errind, &idum1, &colmod, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
	if (colmod < 1 || colmod > 4) {
	    goto L100;
	}
	nscmd (&globnu_1.wkid, &colmod);
#ifndef NO_PROTO
	for (val = 0.f; val <= 1.f; val += .19999f) {
#else /* NO_PROTO */
	for (val = (float)0.; val <= (float)1.; val += (float).19999) {
#endif /* NO_PROTO */
	    cspec[0] = val;
/* Computing 2nd power */
	    r__1 = val;
	    cspec[1] = r__1 * r__1;
/* Computing 3rd power */
	    r__1 = val, r__2 = r__1;
	    cspec[2] = r__2 * (r__1 * r__1);
	    nscr (&globnu_1.wkid, &c__1, &c__3, cspec);
	    if (globnu_1.errsig != 0) {
		seterr = TRUE_;
		setprm[0] = cspec[0];
		setprm[1] = cspec[1];
		setprm[2] = cspec[2];
		setcod = globnu_1.errsig;
		globnu_1.errsig = 0;
	    }
	    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &numret, 
		    cspec);
	    chkinq_("pqcr", &errind, 4L);
#ifndef NO_PROTO
	    if (numret != 3 || cspec[0] < 0.f || cspec[0] > 1.f || cspec[1] < 
		    0.f || cspec[1] > 1.f || cspec[2] < 0.f || cspec[2] > 1.f)
		     {
#else /* NO_PROTO */
	    if (numret != 3 || cspec[0] < (float)0. || cspec[0] > (float)1. ||
		     cspec[1] < (float)0. || cspec[1] > (float)1. || cspec[2] 
		    < (float)0. || cspec[2] > (float)1.) {
#endif /* NO_PROTO */
		inqerr = TRUE_;
		inqprm[0] = cspec[0];
		inqprm[1] = cspec[1];
		inqprm[2] = cspec[2];
	    }
/* L110: */
	}
L100:
	;
    }
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("21 26 27", "All colour specification parameters within range of"
	    " the current colour model should be accepted as valid.", 8L, 105L)
	    ;
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("21 26 27", "All colour specification parameters within range of\
 the current colour model should be accepted as valid.", 8L, 105L);
#endif /* NO_PROTO */
    if (seterr) {
	fail_();
	s_wsfi(&io___18);
	do_fio(&c__1, "Error code ", 11L);
	do_fio(&c__1, (char *)&setcod, (ftnlen)sizeof(integer));
	do_fio(&c__1, " signalled for color model ", 27L);
	do_fio(&c__1, (char *)&colmod, (ftnlen)sizeof(integer));
	do_fio(&c__1, ", color-spec = ", 15L);
	do_fio(&c__3, (char *)&setprm[0], (ftnlen)sizeof(real));
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("21 26 32 33", "The components of a realized colour specificatio"
	    "n should be reported within the range of the current colour mode"
	    "l.", 11L, 114L);
#else /* NO_PROTO */
    setmsg_("21 26 32 33", "The components of a realized colour specificatio\
n should be reported within the range of the current colour model.", 11L, 
	    114L);
#endif /* NO_PROTO */
    if (inqerr) {
	fail_();
	s_wsfi(&io___19);
	do_fio(&c__1, "For color model ", 16L);
	do_fio(&c__1, (char *)&colmod, (ftnlen)sizeof(integer));
	do_fio(&c__1, ", reported color-spec = ", 24L);
	do_fio(&c__3, (char *)&inqprm[0], (ftnlen)sizeof(real));
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
#ifndef NO_PROTO
    setmsg_("21 26 32 33", "The components of a realized colour specificatio"
	    "n should be reported within the range of the current colour mode"
	    "l, even when converted from another colour model.", 11L, 161L);
#else /* NO_PROTO */
    setmsg_("21 26 32 33", "The components of a realized colour specificatio\
n should be reported within the range of the current colour model, even when\
 converted from another colour model.", 11L, 161L);
#endif /* NO_PROTO */
    nscmd (&globnu_1.wkid, &c__2);
#ifndef NO_PROTO
    cspec[0] = .6f;
    cspec[1] = .48f;
    cspec[2] = 1.f;
#else /* NO_PROTO */
    cspec[0] = (float).6;
    cspec[1] = (float).48;
    cspec[2] = (float)1.;
#endif /* NO_PROTO */
    nscr (&globnu_1.wkid, &c__0, &c__3, cspec);
#ifndef NO_PROTO
    cspec[0] = .1f;
    cspec[1] = .53f;
    cspec[2] = .1f;
#else /* NO_PROTO */
    cspec[0] = (float).1;
    cspec[1] = (float).53;
    cspec[2] = (float).1;
#endif /* NO_PROTO */
    nscr (&globnu_1.wkid, &c__1, &c__3, cspec);
    nscmd (&globnu_1.wkid, &c__1);
    for (ci = 0; ci <= 1; ++ci) {
	nqcr (&globnu_1.wkid, &ci, &c__6, &c__1, &errind, &numret, cspec);
	chkinq_("pqcr", &errind, 4L);
#ifndef NO_PROTO
	if (numret != 3 || cspec[0] < 0.f || cspec[0] > 1.f || cspec[1] < 0.f 
		|| cspec[1] > 1.f || cspec[2] < 0.f || cspec[2] > 1.f) {
#else /* NO_PROTO */
	if (numret != 3 || cspec[0] < (float)0. || cspec[0] > (float)1. || 
		cspec[1] < (float)0. || cspec[1] > (float)1. || cspec[2] < (
		float)0. || cspec[2] > (float)1.) {
#endif /* NO_PROTO */
	    fail_();
	    goto L310;
	}
/* L300: */
    }
    pass_();
L310:
/* <inquire colour facilities> to determine */
/* cola = colour available and */
/* ncol = number of colours */
    nqcf (&specwt, &errind, &ncol, &cola, &idum1, rdum);
    chkinq_("pqcf", &errind, 4L);
    if (cola == 1 && ncol == 0) {
#ifndef NO_PROTO
	setmsg_("3 5 32 33", "For colour workstations with a continuous rang"
		"e of colours, the colour specification parameters should be "
		"realized as themselves.", 9L, 129L);
#else /* NO_PROTO */
	setmsg_("3 5 32 33", "For colour workstations with a continuous rang\
e of colours, the colour specification parameters should be realized as them\
selves.", 9L, 129L);
#endif /* NO_PROTO */
/* <set colour representation> index #1, red=.78, green=.36, blue=.23 
*/
#ifndef NO_PROTO
	expcol[0] = .78f;
	expcol[1] = .36f;
	expcol[2] = .23f;
#else /* NO_PROTO */
	expcol[0] = (float).78;
	expcol[1] = (float).36;
	expcol[2] = (float).23;
#endif /* NO_PROTO */
	nscr (&globnu_1.wkid, &c__1, &c__3, expcol);
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
	L__1 = numret == 3 && rareq_(&c__3, actcol, expcol, &c_b60, &c_b61);
	ifpf_(&L__1);
    } else {
#ifndef NO_PROTO
	setmsg_("3 6 32 33", "For workstations with a noncontinuous range of"
		" colours or monochrome workstations, the colour specificatio"
		"n parameters should be realized as closely as possible.", 9L, 
		161L);
#else /* NO_PROTO */
	setmsg_("3 6 32 33", "For workstations with a noncontinuous range of\
 colours or monochrome workstations, the colour specification parameters sho\
uld be realized as closely as possible.", 9L, 161L);
#endif /* NO_PROTO */
/* <set colour representation> index #1, red=.17, green=.92, blue=.87 
*/
#ifndef NO_PROTO
	actcol[0] = .17f;
	actcol[1] = .92f;
	actcol[2] = .87f;
#else /* NO_PROTO */
	actcol[0] = (float).17;
	actcol[1] = (float).92;
	actcol[2] = (float).87;
#endif /* NO_PROTO */
	nscr (&globnu_1.wkid, &c__1, &c__3, actcol);
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, expcol);
	chkinq_("pqcr", &errind, 4L);
	nscr (&globnu_1.wkid, &c__1, &c__3, expcol);
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, newcol);
	chkinq_("pqcr", &errind, 4L);
	L__1 = numret == 3 && rareq_(&c__3, newcol, expcol, &c_b60, &c_b61);
	ifpf_(&L__1);
    }
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

