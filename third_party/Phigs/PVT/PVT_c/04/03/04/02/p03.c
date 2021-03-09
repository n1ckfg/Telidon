/* fort/04/03/04/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__23 = 23;
static integer c__1025 = 1025;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.02/03                        * */
/*  *    TEST TITLE : Appearance of highlighted primitives  * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[300];
    static integer txci, idum1, idum2, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqphf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), nclst (void), nexst (integer *),
	     setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqphf (), nclst (), 
	    nexst (), setvs_(), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static integer nanams;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), setdlg_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, ranord[8], picstr, hllist[4], ivlist[4], primid, 
	    incset[1025], excset[1025], incsiz, excsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nmscol_(integer *), nmsprm_(
	    logical *), setmsg_(char *, char *, ftnlen, ftnlen), rnbset_(
	    integer *, integer *, integer *, integer *), tsthlf_(integer *, 
	    integer *, integer *, integer *, integer *), rnperm_(integer *, 
	    integer *), nshlft (integer *, integer *, integer *, integer *, 
	    integer *), nsivft (integer *, integer *, integer *, integer *, 
	    integer *), dlstpf_(char *, integer *, integer *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nmscol_(), 
	    nmsprm_(), setmsg_(), rnbset_(), tsthlf_(), rnperm_(), nshlft (), 
	    nsivft (), dlstpf_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, msg, 0, "(A,I9,A,I9,A)", 300, 1 };


/* aspect source */
/*                bundled     individual */
    initgl_("04.03.04.02/03", 14L);
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
    nmsprm_((logical*)&c__1);
#else /* NO_PROTO */
    nmsprm_(&c__1);
#endif /* NO_PROTO */
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 10 11", "Highlighting of primitives should be correctly con"
	    "trolled by the highlighting filter when its inclusion set is the"
	    " largest guaranteed by the standard.", 9L, 150L);
#else /* NO_PROTO */
    setmsg_("1 4 10 11", "Highlighting of primitives should be correctly con\
trolled by the highlighting filter when its inclusion set is the largest gua\
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
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4", "Highlighting of primitives should be correctly controlle"
	    "d by the highlighting filter when its inclusion set is null.", 3L,
	     116L);
#else /* NO_PROTO */
    setmsg_("1 4", "Highlighting of primitives should be correctly controlle\
d by the highlighting filter when its inclusion set is null.", 3L, 116L);
#endif /* NO_PROTO */
/*  incl = null, excl = {2,4,6,8} */
    incsiz = 0;
    setvs_("2,4,6,8", excset, &excsiz, 7L);
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
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
    setmsg_("1 4 12", "Highlighting of primitives should be correctly contro"
	    "lled by the highlighting filter when its inclusion set is the la"
	    "rgest supported by the implementation.", 6L, 155L);
#else /* NO_PROTO */
    setmsg_("1 4 12", "Highlighting of primitives should be correctly contro\
lled by the highlighting filter when its inclusion set is the largest suppor\
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
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
L120:
#ifndef NO_PROTO
    setmsg_("1 4 12 13", "Highlighting of primitives should be correctly con"
	    "trolled by the highlighting filter by ignoring invalid names in "
	    "its inclusion set.", 9L, 132L);
#else /* NO_PROTO */
    setmsg_("1 4 12 13", "Highlighting of primitives should be correctly con\
trolled by the highlighting filter by ignoring invalid names in its inclusio\
n set.", 9L, 132L);
#endif /* NO_PROTO */
/*  incl = random set of 6 elements chosen from 0-23 plus -1, nanams */
/*  excl = null */
    incsiz = 8;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    incset[0] = -1;
    incset[7] = nanams;
    excsiz = 0;
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
#ifndef NO_PROTO
    setmsg_("1 4 10 11", "Highlighting of primitives should be correctly con"
	    "trolled by the highlighting filter when its exclusion set is the"
	    " largest guaranteed by the standard.", 9L, 150L);
#else /* NO_PROTO */
    setmsg_("1 4 10 11", "Highlighting of primitives should be correctly con\
trolled by the highlighting filter when its exclusion set is the largest gua\
ranteed by the standard.", 9L, 150L);
#endif /* NO_PROTO */
/*  incl = random set of 6 elements chosen from 0-23 */
/*  excl = {0-63} */
    incsiz = 6;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    excsiz = 64;
    i__1 = excsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	excset[ix - 1] = ix - 1;
/* L130: */
    }
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4", "Highlighting of primitives should be correctly controlle"
	    "d by the highlighting filter when its exclusion set is null.", 3L,
	     116L);
#else /* NO_PROTO */
    setmsg_("1 4", "Highlighting of primitives should be correctly controlle\
d by the highlighting filter when its exclusion set is null.", 3L, 116L);
#endif /* NO_PROTO */
/*  incl = random set of 6 elements chosen from 0-23 */
/*  excl = null */
    incsiz = 6;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    excsiz = 0;
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4", "Highlighting of primitives should be correctly controlle"
	    "d by the highlighting filter when its inclusion and exclusion se"
	    "t are neither null nor full.", 3L, 148L);
#else /* NO_PROTO */
    setmsg_("1 4", "Highlighting of primitives should be correctly controlle\
d by the highlighting filter when its inclusion and exclusion set are neithe\
r null nor full.", 3L, 148L);
#endif /* NO_PROTO */
/*  incl = random set of 7 elements chosen from 0-23 */
/*  excl = random set of 5 elements chosen from 0-23 */
    incsiz = 7;
    rnbset_(&incsiz, &c__0, &c__23, incset);
    excsiz = 5;
    rnbset_(&excsiz, &c__0, &c__23, excset);
    tsthlf_(&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  ranord = random order for 1-8 */
    rnperm_(&c__8, ranord);
    for (ix = 1; ix <= 4; ++ix) {
	primid = ranord[ix - 1];
/*  make primitive #primid eligible for highlighting */
	incset[ix - 1] = primid * 3 - 2;
	hllist[ix - 1] = primid;
/* L200: */
    }
    nshlft (&globnu_1.wkid, &c__4, incset, &c__0, excset);
    for (ix = 3; ix <= 6; ++ix) {
	primid = ranord[ix - 1];
/*  make primitive #primid eligible for invisibility */
	incset[ix - 3] = primid * 3 - 2;
	ivlist[ix - 3] = primid;
/* L300: */
    }
    nsivft (&globnu_1.wkid, &c__4, incset, &c__0, excset);
#ifndef NO_PROTO
    setmsg_("1 4 5 8", "Primitives eligible only for highlighting should be "
	    "highlighted even when displayed along with invisible primitives.",
	     7L, 116L);
    dlstpf_("PRECEDENCE OF INVISIBILITY OVER HIGHLIGHTING: For which pairs o"
	    "f primitives is the left member highlighted (n if none)?", &c__2, 
	    hllist, "S", 119L, 1L);
    setmsg_("1 4 5 8", "Primitives eligible for both highlighting and invisi"
	    "bility should be invisible.", 7L, 79L);
    dlstpf_("PRECEDENCE OF INVISIBILITY OVER HIGHLIGHTING: For which pairs o"
	    "f primitives is the left member invisible (n if none)?", &c__4, 
	    ivlist, "S", 117L, 1L);
#else /* NO_PROTO */
    setmsg_("1 4 5 8", "Primitives eligible only for highlighting should be \
highlighted even when displayed along with invisible primitives.", 7L, 116L);
    dlstpf_("PRECEDENCE OF INVISIBILITY OVER HIGHLIGHTING: For which pairs o\
f primitives is the left member highlighted (n if none)?", &c__2, hllist, 
	    "S", 119L, 1L);
    setmsg_("1 4 5 8", "Primitives eligible for both highlighting and invisi\
bility should be invisible.", 7L, 79L);
    dlstpf_("PRECEDENCE OF INVISIBILITY OVER HIGHLIGHTING: For which pairs o\
f primitives is the left member invisible (n if none)?", &c__4, ivlist, "S", 
	    117L, 1L);
#endif /* NO_PROTO */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

