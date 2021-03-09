/* fort/04/02/03/01/p09.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b6 = 1.f;
#else /* NO_PROTO */
static real c_b6 = (float)1.;
#endif /* NO_PROTO */
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/09                        * */
/*  *    TEST TITLE : Character up vector                   * */
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
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *), nclst (void), 
	    nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh (), nclst (), nemst ();
#endif /* NO_PROTO */
    static integer ngstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *), dchpfv_(char *, integer *, integer *, ftnlen), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi (), dchpfv_(), 
	    setdlg_();
#endif /* NO_PROTO */
    static integer picstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setasf_(integer *), 
	    tschup_(integer *, integer *, char *, integer *, integer *, 
	    ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(integer 
	    *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setasf_(), tschup_(), setmsg_(), 
	    xpopph_();
#endif /* NO_PROTO */
    static integer numstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxpr ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* text path */
/* text precision */
    initgl_("04.02.03.01/09", 14L);
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
    nstxpr (&c__2);
    nschh (&c_b6);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*  use font #1 for horizontal path */
    tschup_(&c__1, &c__0, "Going up?", &numstr, &ngstr, 9L);
#ifndef NO_PROTO
    setmsg_("16 27 31 66 67 69 74 75 80 81", "A text primitive with STROKE p"
	    "recision and a horizontal text path should be rotated according "
	    "to the character up vector.", 29L, 121L);
    dchpfv_("CHARACTER UP FOR HORIZONTAL TEXT PATH: Which text primitive is "
	    "NOT aligned within the dotted text extent rectangle on the dashe"
	    "d baseline?", &numstr, &ngstr, 138L);
#else /* NO_PROTO */
    setmsg_("16 27 31 66 67 69 74 75 80 81", "A text primitive with STROKE p\
recision and a horizontal text path should be rotated according to the chara\
cter up vector.", 29L, 121L);
    dchpfv_("CHARACTER UP FOR HORIZONTAL TEXT PATH: Which text primitive is \
NOT aligned within the dotted text extent rectangle on the dashed baseline?", 
	    &numstr, &ngstr, 138L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  use font #2 for vertical path */
    tschup_(&c__2, &c__3, "Up&@M", &numstr, &ngstr, 5L);
#ifndef NO_PROTO
    setmsg_("16 27 31 66 67 68 74 75 80 81", "A text primitive with STROKE p"
	    "recision and a vertical text path should be rotated according to"
	    " the character up vector.", 29L, 119L);
    dchpfv_("CHARACTER UP FOR VERTICAL TEXT PATH: Which text primitive is NO"
	    "T aligned within the dotted text extent rectangle on the dashed "
	    "centerline?", &numstr, &ngstr, 138L);
#else /* NO_PROTO */
    setmsg_("16 27 31 66 67 68 74 75 80 81", "A text primitive with STROKE p\
recision and a vertical text path should be rotated according to the charact\
er up vector.", 29L, 119L);
    dchpfv_("CHARACTER UP FOR VERTICAL TEXT PATH: Which text primitive is NO\
T aligned within the dotted text extent rectangle on the dashed centerline?", 
	    &numstr, &ngstr, 138L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

