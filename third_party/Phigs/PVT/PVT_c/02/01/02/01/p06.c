/* fort/02/01/02/01/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__102 = 102;
static integer c__101 = 101;
static integer c__103 = 103;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__107 = 107;
static integer c__108 = 108;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.01/06                        * */
/*  *    TEST TITLE : Effect of <delete structure> on       * */
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
    extern /* Subroutine */ int nsep (integer *), ndst (integer *), endit_(
	    void), nsedm (integer *), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), ndst (), endit_(), nsedm (), inmsg_()
	    ;
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), chkelp_(
	    integer *), initgl_(char *, ftnlen), setmsg_(char *, char *, 
	    ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), chkelp_(), initgl_(), 
	    setmsg_(), xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* edit mode */
    initgl_("02.01.02.01/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Set up CSS as: */

/*                                  100 */
/*                                   | */
/*                                   | */
/*   --------------------------------------------------------------------
--*/
/*   | |       | |       | |       | |       | |       | |       | |      
|*/
/*   | |       | |       | |       | |       | |       | |       | |      
|*/
/* 2 | | 3   1 | | 6   4 | | 5   7 | | 11  8 | | 12  9 | | 13 10 | | 14   
| 15*/
/*   | |       | |       | |       | |       | |       | |       | |      
|*/
/*   101       102       103       104       105       106       107     1
08*/
    strid = 100;
    nopst (&strid);
    nexst (&c__102);
    nexst (&c__101);
    nexst (&c__101);
    nexst (&c__103);
    nexst (&c__103);
    nexst (&c__102);
    nexst (&c__104);
    nexst (&c__105);
    nexst (&c__106);
    nexst (&c__107);
    nexst (&c__104);
    nexst (&c__105);
    nexst (&c__106);
    nexst (&c__107);
    nexst (&c__108);
/*  Throughout, expected state is shown as the sequence of */
/*  references within structure #100, with the current element */
/*  marked by an asterisk.  Thus the first state is: */
/*  (102, 101, 101, 103, 103, 102, 104, 105, 106, 107, */
/*   104, 105, 106, 107, 108*) */
/*  set edit mode to INSERT */
    nsedm (&c__0);
    inmsg_("Following test cases run in INSERT mode.", 40L);
/*  set element pointer to 5 and delete structure #107 */
    nsep (&c__5);
    ndst (&c__107);
#ifndef NO_PROTO
    setmsg_("6", "When <delete structure> causes deletion of references foll"
	    "owing the current element, the element pointer should be unchang"
	    "ed.", 1L, 125L);
#else /* NO_PROTO */
    setmsg_("6", "When <delete structure> causes deletion of references foll\
owing the current element, the element pointer should be unchanged.", 1L, 
	    125L);
#endif /* NO_PROTO */
    chkelp_(&c__5);
/*  (102, 101, 101, 103, 103*, 102, 104, 105, 106, 104, 105, 106, 108) */
/*  delete structure #101 */
    ndst (&c__101);
#ifndef NO_PROTO
    setmsg_("6", "When <delete structure> causes deletion of references prec"
	    "eding the current element, the element pointer should be changed"
	    " so as to point to the same element.", 1L, 158L);
#else /* NO_PROTO */
    setmsg_("6", "When <delete structure> causes deletion of references prec\
eding the current element, the element pointer should be changed so as to po\
int to the same element.", 1L, 158L);
#endif /* NO_PROTO */
    chkelp_(&c__3);
/*  (102, 103, 103*, 102, 104, 105, 106, 104, 105, 106, 108) */
/*  delete structure #103 */
    ndst (&c__103);
#ifndef NO_PROTO
    setmsg_("7", "When <delete structure> causes deletion of references at t"
	    "he current element, the element pointer should be changed so as "
	    "to point to the preceding element.", 1L, 156L);
#else /* NO_PROTO */
    setmsg_("7", "When <delete structure> causes deletion of references at t\
he current element, the element pointer should be changed so as to point to \
the preceding element.", 1L, 156L);
#endif /* NO_PROTO */
    chkelp_(&c__1);
/*  (102*, 102, 104, 105, 106, 104, 105, 106, 108) */
/*  delete structure #102 */
    ndst (&c__102);
#ifndef NO_PROTO
    setmsg_("7", "When <delete structure> causes deletion of references at t"
	    "he current element, and no preceding element exists, the element"
	    " pointer should be changed to point to zero.", 1L, 166L);
#else /* NO_PROTO */
    setmsg_("7", "When <delete structure> causes deletion of references at t\
he current element, and no preceding element exists, the element pointer sho\
uld be changed to point to zero.", 1L, 166L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/*  (* 104, 105, 106, 104, 105, 106, 108) */
/*  set edit mode to REPLACE */
    nsedm (&c__1);
    inmsg_("Following test cases run in REPLACE mode.", 41L);
/*  delete structure #108 */
    ndst (&c__108);
#ifndef NO_PROTO
    setmsg_("6", "When <delete structure> causes deletion of references and "
	    "the element pointer is zero, it should remain at zero.", 1L, 112L)
	    ;
#else /* NO_PROTO */
    setmsg_("6", "When <delete structure> causes deletion of references and \
the element pointer is zero, it should remain at zero.", 1L, 112L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/*  (* 104, 105, 106, 104, 105, 106) */
/*  set element pointer to 4 and delete structure #105 */
    nsep (&c__4);
    ndst (&c__105);
#ifndef NO_PROTO
    setmsg_("6", "When <delete structure> causes deletion of references surr"
	    "ounding the current element, the element pointer should be chang"
	    "ed so as to point to the same element.", 1L, 160L);
#else /* NO_PROTO */
    setmsg_("6", "When <delete structure> causes deletion of references surr\
ounding the current element, the element pointer should be changed so as to \
point to the same element.", 1L, 160L);
#endif /* NO_PROTO */
    chkelp_(&c__3);
/*  (104, 106, 104*, 106) */
/*  set element pointer to 4 and delete structure #106 */
    nsep (&c__4);
    ndst (&c__106);
#ifndef NO_PROTO
    setmsg_("7", "When <delete structure> causes deletion of references at t"
	    "he current element, which is the last element, the element point"
	    "er should be changed so as to point to the preceding element.", 
	    1L, 183L);
#else /* NO_PROTO */
    setmsg_("7", "When <delete structure> causes deletion of references at t\
he current element, which is the last element, the element pointer should be\
 changed so as to point to the preceding element.", 1L, 183L);
#endif /* NO_PROTO */
    chkelp_(&c__2);
/*  (104, 104*) */
/*  delete structure #104 */
    ndst (&c__104);
#ifndef NO_PROTO
    setmsg_("7", "When <delete structure> causes deletion of references at t"
	    "he current element thereby emptying the structure, the element p"
	    "ointer should be changed to point to zero.", 1L, 164L);
#else /* NO_PROTO */
    setmsg_("7", "When <delete structure> causes deletion of references at t\
he current element thereby emptying the structure, the element pointer shoul\
d be changed to point to zero.", 1L, 164L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

