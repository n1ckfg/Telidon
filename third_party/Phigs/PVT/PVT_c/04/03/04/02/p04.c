/* fort/04/03/04/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

struct {
    integer black, green, yellow, white, blue;
} colors_;

#define colors_1 colors_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__23 = 23;
static integer c__1025 = 1025;
static integer c__150 = 150;
#ifndef NO_PROTO
static real c_b58 = 0.f;
#else /* NO_PROTO */
static real c_b58 = (float)0.;
#endif /* NO_PROTO */
static integer c__8 = 8;
#ifndef NO_PROTO
static real c_b63 = .15f;
#else /* NO_PROTO */
static real c_b63 = (float).15;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b74 = 1.f;
#else /* NO_PROTO */
static real c_b74 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.02/04                        * */
/*  *    TEST TITLE : Appearance of invisible primitives    * */
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
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[10], ya[10], za[10];
    static integer ix;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npl3 (
	    integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npl3 ();
#endif /* NO_PROTO */
    static integer icol;
#ifndef NO_PROTO
    extern /* Subroutine */ int nads (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nads ();
#endif /* NO_PROTO */
    static real yloc;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nres (integer *, integer *), nsln (integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nres (), nsln ();
#endif /* NO_PROTO */
    static real ytop;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern doublereal ypos8_(integer *);
#else /* NO_PROTO */
    extern doublereal ypos8_();
#endif /* NO_PROTO */
    static integer names[8];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqphf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqphf ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nqplf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nqplf (), nemst ();
#endif /* NO_PROTO */
    static real nomlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), setvs_(char *, integer *, 
	    integer *, ftnlen), nopst (integer *), npost (integer *, integer *
	    , real *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), setvs_(), nopst (), npost (), 
	    nsvwi ();
#endif /* NO_PROTO */
    static integer nanams;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *), setdlg_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, invobs, invset[8], numinv;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer incset[1025], excset[1025], incsiz, excsiz, nstruc;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nmscol_(integer *), nmsprm_(
	    logical *), setmsg_(char *, char *, ftnlen, ftnlen), rnbset_(
	    integer *, integer *, integer *, integer *), tstivf_(integer *, 
	    integer *, integer *, integer *, integer *), nstxci (integer *), 
	    nslwsc (real *), nsplci (integer *), rnperm_(integer *, integer *)
	    , nsivft (integer *, integer *, integer *, integer *, integer *), 
	    dlstpf_(char *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nmscol_(), 
	    nmsprm_(), setmsg_(), rnbset_(), tstivf_(), nstxci (), nslwsc (), 
	    nsplci (), rnperm_(), nsivft (), dlstpf_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, msg, 0, "(A,I9,A,I9,A)", 300, 1 };


/* aspect source */
/*                bundled     individual */
/* linetype */
    initgl_("04.03.04.02/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nexst (&c__102);
    nclst ();
    nmscol_(&globnu_1.wkid);
    nopst (&c__102);
#ifndef NO_PROTO
    nmsprm_((logical*)&c__0);
#else /* NO_PROTO */
    nmsprm_(&c__0);
#endif /* NO_PROTO */
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("5 8 10 11", "Invisibility of primitives should be correctly con"
	    "trolled by the invisibility filter when its inclusion set is the"
	    " largest guaranteed by the standard.", 9L, 150L);
#else /* NO_PROTO */
    setmsg_("5 8 10 11", "Invisibility of primitives should be correctly con\
trolled by the invisibility filter when its inclusion set is the largest gua\
ranteed by the standard.", 9L, 150L);
#endif /* NO_PROTO */
/*  incl = {0-63} */
/*  excl = random set of 6 elements chosen from 0-23 */
    incsiz = 64;
    i__1 = incsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	incset[ix - 1] = ix - 1;
/* L100: */
    }
    excsiz = 6;
    rnbset_(&excsiz, &c__0, &c__23, excset);
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("5 8", "Invisibility of primitives should be correctly controlle"
	    "d by the invisibility filter when its inclusion set is null.", 3L,
	     116L);
#else /* NO_PROTO */
    setmsg_("5 8", "Invisibility of primitives should be correctly controlle\
d by the invisibility filter when its inclusion set is null.", 3L, 116L);
#endif /* NO_PROTO */
/*  incl = null, excl = {2,4,6,8} */
    incsiz = 0;
    setvs_("2,4,6,8", excset, &excsiz, 7L);
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  <inquire PHIGS facilities> to determine: */
/*  nanams = number of available names for namesets */
    nqphf (&c__1, &errind, &idum1, &idum2, &nanams, &idum4, &idum5, &idum6, &
	    idum7);
    chkinq_("pqphf", &errind, 5L);
    if (nanams > 1025) {
	s_wsfi(&io___17);
#ifndef NO_PROTO
	do_fio(&c__1, "Number of available names exceeds current program lim"
		"it.  The value of the PARAMETER SETSIZ must be changed to ", 
		111L);
#else /* NO_PROTO */
	do_fio(&c__1, "Number of available names exceeds current program lim\
it.  The value of the PARAMETER SETSIZ must be changed to ", 111L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&nanams, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".  The current value is ", 24L);
	do_fio(&c__1, (char *)&c__1025, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 300L);
	goto L120;
    }
#ifndef NO_PROTO
    setmsg_("5 8 12", "Invisibility of primitives should be correctly contro"
	    "lled by the invisibility filter when its inclusion set is the la"
	    "rgest supported by the implementation.", 6L, 155L);
#else /* NO_PROTO */
    setmsg_("5 8 12", "Invisibility of primitives should be correctly contro\
lled by the invisibility filter when its inclusion set is the largest suppor\
ted by the implementation.", 6L, 155L);
#endif /* NO_PROTO */
/*  incl = {0-nanams} */
/*  excl = random set of 6 elements chosen from 0-23 */
    i__1 = nanams;
    for (ix = 1; ix <= i__1; ++ix) {
	incset[ix - 1] = nanams - ix;
/* L110: */
    }
    incsiz = nanams;
    excsiz = 6;
    rnbset_(&excsiz, &c__0, &c__23, excset);
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("5 8 12", "Invisibility of primitives should be correctly contro"
	    "lled by the invisibility filter when its exclusion set is the la"
	    "rgest supported by the implementation.", 6L, 155L);
#else /* NO_PROTO */
    setmsg_("5 8 12", "Invisibility of primitives should be correctly contro\
lled by the invisibility filter when its exclusion set is the largest suppor\
ted by the implementation.", 6L, 155L);
#endif /* NO_PROTO */
/*  incl = random set of 6 elements chosen from 0-23 */
/*  excl = {0-63} */
    incsiz = 6;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    excsiz = nanams;
    i__1 = excsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	excset[ix - 1] = nanams - ix;
/* L130: */
    }
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
L120:
#ifndef NO_PROTO
    setmsg_("5 8 12 13", "Invisibility of primitives should be correctly con"
	    "trolled by the invisibility filter by ignoring invalid names in "
	    "its exclusion set.", 9L, 132L);
#else /* NO_PROTO */
    setmsg_("5 8 12 13", "Invisibility of primitives should be correctly con\
trolled by the invisibility filter by ignoring invalid names in its exclusio\
n set.", 9L, 132L);
#endif /* NO_PROTO */
/*  incl = {0,63} */
/*  excl = random set of 6 elements chosen from 0-23 plus -11, nanams+11 
*/
    incsiz = 64;
    for (ix = 1; ix <= 64; ++ix) {
	incset[ix - 1] = 64 - ix;
/* L140: */
    }
    excsiz = 8;
    rnbset_(&excsiz, &c__0, &c__23, excset);
    excset[0] = nanams + 11;
    excset[7] = -11;
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("5 8", "Invisibility of primitives should be correctly controlle"
	    "d by the invisibility filter when its exclusion set is null.", 3L,
	     116L);
#else /* NO_PROTO */
    setmsg_("5 8", "Invisibility of primitives should be correctly controlle\
d by the invisibility filter when its exclusion set is null.", 3L, 116L);
#endif /* NO_PROTO */
/*  incl = random set of 6 elements chosen from 0-23 */
/*  excl = null */
    incsiz = 6;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    excsiz = 0;
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("5 8", "Invisibility of primitives should be correctly controlle"
	    "d by the invisibility filter when its inclusion and exclusion se"
	    "t are neither null nor full.", 3L, 148L);
#else /* NO_PROTO */
    setmsg_("5 8", "Invisibility of primitives should be correctly controlle\
d by the invisibility filter when its inclusion and exclusion set are neithe\
r null nor full.", 3L, 148L);
#endif /* NO_PROTO */
/*  incl = random set of 7 elements chosen from 0-23 */
/*  excl = random set of 5 elements chosen from 0-23 */
    incsiz = 7;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    excsiz = 5;
    rnbset_(&excsiz, &c__0, &c__23, excset);
    tstivf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
    nemst (&c__102);
    nclst ();
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("5 8 9", "Invisible primitives should not obscure visible primit"
	    "ives.", 5L, 59L);
    yincr = .1111111111111111f;
#else /* NO_PROTO */
    setmsg_("5 8 9", "Invisible primitives should not obscure visible primit\
ives.", 5L, 59L);
    yincr = (float).1111111111111111;
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .8f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).8;
#endif /* NO_PROTO */
/*  Set up new structure with 8 numbered 2D (drawn in z=0 plane) */
/*    dotted lines.  Some of these should be invisible, some */
/*    visible but possibly obscured, and some directly visible: */
/*  Set display priority of picture to 0 */
    npost (&globnu_1.wkid, &c__150, &c_b58);
    nopst (&c__150);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nstxci (&colors_1.yellow);
    numlab_(&c__8, &c_b63, &ytop, &yincr);
    nsln (&c__3);
    nslwsc (&c_b58);
    for (ix = 1; ix <= 8; ++ix) {
	names[0] = ix;
	nads (&c__1, names);
	if (colors_1.blue == 1) {
	    icol = 1;
	} else {
	    if (ix > 4) {
		icol = ix - 4;
	    } else {
		icol = ix;
	    }
	}
	nsplci (&icol);
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	nres (&c__1, names);
	yloc -= yincr;
/* L200: */
    }
    nclst ();
/*  invobs = number invisible or obscured = random from 4 to 6 */
/*  invset = 1-8, in random order */
/*  numinv = number invisible = invobs/2 */
    invobs = rndint_(&c__4, &c__6);
    rnperm_(&c__8, invset);
    numinv = invobs / 2;
/*  invset(1       :numinv) should be invisible */
/*  invset(numinv+1:invobs) should be visible, even though obscured */
/*  invset(invobs+1:8)      should be visible */
/*  set invisibility filter using incl = invset(1:numinv), excl = null */
    nsivft (&globnu_1.wkid, &numinv, invset, &c__0, excset);
/*  set up new root structure = nstruc, for obscuring primitives */
/*  post nstruc to workstation with priority = 1.0 */
    nstruc = 155;
    npost (&globnu_1.wkid, &nstruc, &c_b74);
    nopst (&nstruc);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set linewidth scale factor = wide */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomlw, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
#ifndef NO_PROTO
    r__1 = yincr * .3f / (nomlw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = yincr * (float).3 / (nomlw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nslwsc (&r__1);
/*  add names to set: invset(1) to make all obscuring primitives invisible
 */
    nads (&c__1, invset);
    nsln (&c__1);
#ifndef NO_PROTO
    za[0] = .5f;
    za[1] = .8f;
#else /* NO_PROTO */
    za[0] = (float).5;
    za[1] = (float).8;
#endif /* NO_PROTO */
    i__1 = invobs;
    for (ix = numinv + 1; ix <= i__1; ++ix) {
/*  alternate COLOR between 0 and 1 */
	i__2 = ix % 2;
	nsplci (&i__2);
	yloc = ypos8_(&invset[ix - 1]);
	ya[0] = yloc;
	ya[1] = yloc;
	npl3 (&c__2, xa, ya, za);
/* L220: */
    }
    i__1 = 8 - numinv;
#ifndef NO_PROTO
    dlstpf_("OBSCURING BY INVISIBLE PRIMITIVES: Which primitives appear as v"
	    "isible dotted lines (n if none)?", &i__1, &invset[numinv], "S", 
	    95L, 1L);
#else /* NO_PROTO */
    dlstpf_("OBSCURING BY INVISIBLE PRIMITIVES: Which primitives appear as v\
isible dotted lines (n if none)?", &i__1, &invset[numinv], "S", 95L, 1L);
#endif /* NO_PROTO */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

