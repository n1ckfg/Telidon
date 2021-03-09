/* fort//02/01/03/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__11 = 11;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.03.03/03                        * */
/*  *    TEST TITLE : Effects of <change structure          * */
/*  *                 identifier and references> on the     * */
/*  *                 element pointer                       * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), endit_();
#endif /* NO_PROTO */
    static integer orgid, resid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedm (integer *), nclst (void), nopst (
	    integer *), chkelp_(integer *), initgl_(char *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen), stdcss_(void), ncstir (integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedm (), nclst (), nopst (), chkelp_(), 
	    initgl_(), setmsg_(), stdcss_(), ncstir ();
#endif /* NO_PROTO */
    static integer comstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* edit mode */
/*  Declare program-specific variables */
    initgl_("02.01.03.03/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("4", "If the original and resulting identifier are the same and "
	    "the common structure is open and empty after execution of <chang"
	    "e structure identifier and references> then the element pointer "
	    "should be at zero.", 1L, 204L);
#else /* NO_PROTO */
    setmsg_("4", "If the original and resulting identifier are the same and \
the common structure is open and empty after execution of <change structure \
identifier and references> then the element pointer should be at zero.", 1L, 
	    204L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 142;
    nopst (&comstr);
    ncstir (&comstr, &comstr);
    chkelp_(&c__0);
    nclst ();
#ifndef NO_PROTO
    setmsg_("4", "If the original and resulting identifier are the same and "
	    "the common structure is open and not empty after execution of <c"
	    "hange structure identifier and references> then the element poin"
	    "ter should remain at its current position.", 1L, 228L);
#else /* NO_PROTO */
    setmsg_("4", "If the original and resulting identifier are the same and \
the common structure is open and not empty after execution of <change struct\
ure identifier and references> then the element pointer should remain at its\
 current position.", 1L, 228L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    nsedm (&c__1);
    comstr = 111;
    nopst (&comstr);
/* set element pointer to 4 */
    nsep (&c__4);
    ncstir (&comstr, &comstr);
    chkelp_(&c__4);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5", "If the original and resulting identifiers differ and the o"
	    "riginal structure is open after execution of <change structure i"
	    "dentifier and references> then the open structure should be empt"
	    "y and the element pointer set to zero.", 1L, 224L);
#else /* NO_PROTO */
    setmsg_("5", "If the original and resulting identifiers differ and the o\
riginal structure is open after execution of <change structure identifier an\
d references> then the open structure should be empty and the element pointe\
r set to zero.", 1L, 224L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    nsedm (&c__0);
    stdcss_();
    orgid = 111;
    resid = 130;
    nopst (&orgid);
/*  set element pointer to 3 */
    nsep (&c__3);
    ncstir (&orgid, &resid);
    chkelp_(&c__0);
    nclst ();
#ifndef NO_PROTO
    setmsg_("6", "If the original and resulting identifiers differ, the orig"
	    "inal structure does not exist and the resulting structure is ope"
	    "n after execution of <change structure identifier and references"
	    "> then the element pointer of the open structure should be set t"
	    "o zero.", 1L, 257L);
#else /* NO_PROTO */
    setmsg_("6", "If the original and resulting identifiers differ, the orig\
inal structure does not exist and the resulting structure is open after exec\
ution of <change structure identifier and references> then the element point\
er of the open structure should be set to zero.", 1L, 257L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    orgid = 300;
    resid = 111;
    nopst (&resid);
    ncstir (&orgid, &resid);
    chkelp_(&c__0);
    nclst ();
#ifndef NO_PROTO
    setmsg_("6", "If the original and resulting identifiers differ, the orig"
	    "inal structure does exist and is empty, and the resulting struct"
	    "ure is open after execution of <change structure identifier and "
	    "references> then the element pointer of the open structure shoul"
	    "d be set to zero.", 1L, 267L);
#else /* NO_PROTO */
    setmsg_("6", "If the original and resulting identifiers differ, the orig\
inal structure does exist and is empty, and the resulting structure is open \
after execution of <change structure identifier and references> then the ele\
ment pointer of the open structure should be set to zero.", 1L, 267L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    orgid = 142;
    resid = 111;
    nopst (&resid);
/*  set element pointer to 2 */
    nsep (&c__2);
    ncstir (&orgid, &resid);
    chkelp_(&c__0);
    nclst ();
#ifndef NO_PROTO
    setmsg_("6", "If the original and resulting identifiers differ, the orig"
	    "inal structure does exist and is not empty, and the resulting st"
	    "ructure is open after execution of <change structure identifier "
	    "and references> then the element pointer of the open structure s"
	    "hould be set to the last element.", 1L, 283L);
#else /* NO_PROTO */
    setmsg_("6", "If the original and resulting identifiers differ, the orig\
inal structure does exist and is not empty, and the resulting structure is o\
pen after execution of <change structure identifier and references> then the\
 element pointer of the open structure should be set to the last element.", 
	    1L, 283L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    orgid = 111;
    resid = 104;
    nopst (&resid);
/*  set element pointer to 3 */
    nsep (&c__3);
    ncstir (&orgid, &resid);
    chkelp_(&c__11);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

