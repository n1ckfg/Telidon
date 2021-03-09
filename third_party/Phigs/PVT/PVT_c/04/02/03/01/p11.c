/* fort/04/02/03/01/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/11                        * */
/*  *    TEST TITLE : Geometric interaction of text         * */
/*  *                 attributes                            * */
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
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static integer idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nclst (void), nexst (integer *),
	     nopst (integer *), nsvwi (integer *), dchpfv_(char *, integer *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nclst (), nexst (), nopst (), 
	    nsvwi (), dchpfv_();
#endif /* NO_PROTO */
    static integer ngline;
#ifndef NO_PROTO
    extern /* Subroutine */ int discol_(integer *, integer *, integer *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int discol_(), setdlg_();
#endif /* NO_PROTO */
    static integer picstr, numlin;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setasf_(integer *), 
	    nstxci (integer *), xpopph_(integer *, integer *), nsplci (
	    integer *), nstxfn (integer *), inoutl_(void), setmsg_(char *, 
	    char *, ftnlen, ftnlen), geotxt_(logical *, integer *, integer *),
	     nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setasf_(), nstxci (), xpopph_(), 
	    nsplci (), nstxfn (), inoutl_(), setmsg_(), geotxt_(), nstxpr ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* text precision */
/* linetype */
    initgl_("04.02.03.01/11", 14L);
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
/*  Throughout, use font#1 (monospaced), STROKE precision. */
    nstxfn (&c__1);
    nstxpr (&c__2);
/*  use color #1 for text, color #2 and dashed lines for outline */
    discol_(&c__2, &globnu_1.wkid, &idum1);
    nstxci (&c__1);
    nsplci (&c__2);
    nsln (&c__2);
    nexst (&c__102);
    nclst ();
    numlin = 5;
/*  call routine to set up nominal expected outlines */
    inoutl_();
/*  leave #102 open */
    nopst (&c__102);
    setmsg_("1 2 11 27 28 31 35 36 41 42 58 59 60 66 67 68 69 74 75 80 81", 
#ifndef NO_PROTO
	    "The transformation effects of text path, text alignment, and ch"
	    "aracter up vector and of various positive values for character e"
	    "xpansion factor, character spacing, and character height should "
	    "work correctly in conjunction with the text direction vectors fo"
	    "r a 3D test primitive.", 60L, 277L);
#else /* NO_PROTO */
	    "The transformation effects of text path, text alignment, and ch\
aracter up vector and of various positive values for character expansion fac\
tor, character spacing, and character height should work correctly in conjun\
ction with the text direction vectors for a 3D test primitive.", 60L, 277L);
#endif /* NO_PROTO */
/*  GEOTXT generates display in structure #102 */
#ifndef NO_PROTO
    geotxt_((logical*)&c__0, &numlin, &ngline);
    dchpfv_("GEOMETRY OF TEXT ATTRIBUTES: Which text primitive is NOT simila"
	    "r in size, position, and orientation to the dashed outline?", &
	    numlin, &ngline, 122L);
#else /* NO_PROTO */
    geotxt_(&c__0, &numlin, &ngline);
    dchpfv_("GEOMETRY OF TEXT ATTRIBUTES: Which text primitive is NOT simila\
r in size, position, and orientation to the dashed outline?", &numlin, &
	    ngline, 122L);
#endif /* NO_PROTO */
    setmsg_("1 2 11 27 28 31 35 36 41 42 58 59 60 66 67 68 69 74 75 80 81", 
#ifndef NO_PROTO
	    "The transformation effects of text path, text alignment, and ch"
	    "aracter up vector and of various negative values for character e"
	    "xpansion factor, character spacing, and character height should "
	    "work correctly in conjunction with the text direction vectors fo"
	    "r a 3D test primitive.", 60L, 277L);
#else /* NO_PROTO */
	    "The transformation effects of text path, text alignment, and ch\
aracter up vector and of various negative values for character expansion fac\
tor, character spacing, and character height should work correctly in conjun\
ction with the text direction vectors for a 3D test primitive.", 60L, 277L);
#endif /* NO_PROTO */
/*  GEOTXT generates display in structure #102 */
#ifndef NO_PROTO
    geotxt_((logical*)&c__1, &numlin, &ngline);
    dchpfv_("GEOMETRY OF NEGATIVE TEXT ATTRIBUTES: Which text primitive is N"
	    "OT similar in size, position, and orientation to the dashed outl"
	    "ine?", &numlin, &ngline, 131L);
#else /* NO_PROTO */
    geotxt_(&c__1, &numlin, &ngline);
    dchpfv_("GEOMETRY OF NEGATIVE TEXT ATTRIBUTES: Which text primitive is N\
OT similar in size, position, and orientation to the dashed outline?", &
	    numlin, &ngline, 131L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

