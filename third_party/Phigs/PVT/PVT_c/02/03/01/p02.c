/* fort/02/03/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b2 = .24f;
static real c_b3 = .35f;
#else /* NO_PROTO */
static real c_b2 = (float).24;
static real c_b3 = (float).35;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b6 = .05f;
#else /* NO_PROTO */
static real c_b6 = (float).05;
#endif /* NO_PROTO */
static integer c__50 = 50;
static integer c__5 = 5;
static integer c__0 = 0;
static integer c__77 = 77;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.01/02                           * */
/*  *    TEST TITLE : Inquire element type and size, and    * */
/*  *                 content when a structure is open      * */
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
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real txx, txy;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static integer rlsz;
    static real chval;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *), nqeco (integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, real *, integer *, integer *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh (), nqeco ();
#endif /* NO_PROTO */
    static integer intar[50], strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static char strar[30*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqets (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqets ();
#endif /* NO_PROTO */
    static integer lnstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer intsz, strsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco ();
#endif /* NO_PROTO */
    static integer errind, eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nschup (real *, real 
	    *), nschsp (real *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nstxal (integer *, integer *), nqcets (integer *, integer *, 
	    integer *, integer *, integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nschup (), nschsp (), setmsg_(), 
	    nstxal (), nqcets (), xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* text alignment horizontal */
/* text alignment vertical */
/* element type */
    initgl_("02.03.01/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    strid = 100;
    nopst (&strid);
    nschup (&c_b2, &c_b3);
    nstxal (&c__1, &c__3);
#ifndef NO_PROTO
    chval = .4f;
#else /* NO_PROTO */
    chval = (float).4;
#endif /* NO_PROTO */
    nschh (&chval);
    nschsp (&c_b6);
#ifndef NO_PROTO
    txx = .16f;
    txy = .2f;
#else /* NO_PROTO */
    txx = (float).16;
    txy = (float).2;
#endif /* NO_PROTO */
    ntx (&txx, &txy, "PHIGS Validation Tests", 22L);

/*  *** *** *** ***   specified element = text   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("1", "<Inquire current element type and size> should return text"
	    " as the element type and an integer array entry size of 0, real "
	    "array entry size of 2, and a string array entry size of 1 when t"
	    "he element pointer is positioned at the last element.", 1L, 239L);

#else /* NO_PROTO */
    setmsg_("1", "<Inquire current element type and size> should return text\
 as the element type and an integer array entry size of 0, real array entry \
size of 2, and a string array entry size of 1 when the element pointer is po\
sitioned at the last element.", 1L, 239L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 7 && intsz == 0 && rlsz == 2 && strsz == 
	    1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Inquire current element content> should return the approp"
	    "riate information contained in the data record associated with t"
	    "ext when the element pointer is positioned at the last element.", 
	    1L, 185L);
#else /* NO_PROTO */
    setmsg_("3", "<Inquire current element content> should return the approp\
riate information contained in the data record associated with text when the\
 element pointer is positioned at the last element.", 1L, 185L);
#endif /* NO_PROTO */
/* ensure garbage in strar prior to inquire */
    s_copy(strar, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 30L, 30L);
    nqceco (&c__50, &c__50, &c__50, &errind, &intsz, intar, &rlsz, rlar, &
	    strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 2 && rlar[0] == txx && rlar[1]
#ifndef NO_PROTO
	     == txy && strsz == 1 && lnstr[0] == 22 && s_cmp(strar, "PHIGS V"
	    "alidation Tests", 30L, 22L) == 0;
#else /* NO_PROTO */
	     == txy && strsz == 1 && lnstr[0] == 22 && s_cmp(strar, "PHIGS V\
alidation Tests", 30L, 22L) == 0;
#endif /* NO_PROTO */
    ifpf_(&L__1);
/*  Make sure <inquire element type and size> is independent of */
/*  element pointer: */
    nsep (&c__3);
#ifndef NO_PROTO
    setmsg_("4", "<Inquire element type and size> should return text as the "
	    "element type and an integer array entry size of 0, real array en"
	    "try size of 2, and a string array entry size of 1 with text as t"
	    "he specified element of the open structure.", 1L, 229L);
#else /* NO_PROTO */
    setmsg_("4", "<Inquire element type and size> should return text as the \
element type and an integer array entry size of 0, real array entry size of \
2, and a string array entry size of 1 with text as the specified element of \
the open structure.", 1L, 229L);
#endif /* NO_PROTO */
    nqets (&strid, &c__5, &errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 7 && intsz == 0 && rlsz == 2 && strsz == 
	    1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "<Inquire element content> should return the appropriate in"
	    "formation contained in the data record associated with text as t"
	    "he specified element of the open structure.", 1L, 165L);
#else /* NO_PROTO */
    setmsg_("6", "<Inquire element content> should return the appropriate in\
formation contained in the data record associated with text as the specified\
 element of the open structure.", 1L, 165L);
#endif /* NO_PROTO */
/* ensure garbage in strar prior to inquire */
    s_copy(strar, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 30L, 30L);
    nqeco (&strid, &c__5, &c__50, &c__50, &c__50, &errind, &intsz, intar, &
	    rlsz, rlar, &strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 2 && rlar[0] == txx && rlar[1]
#ifndef NO_PROTO
	     == txy && strsz == 1 && lnstr[0] == 22 && s_cmp(strar, "PHIGS V"
	    "alidation Tests", 30L, 22L) == 0;
#else /* NO_PROTO */
	     == txy && strsz == 1 && lnstr[0] == 22 && s_cmp(strar, "PHIGS V\
alidation Tests", 30L, 22L) == 0;
#endif /* NO_PROTO */
    ifpf_(&L__1);
/*  *** *** *** *** specified element = character height *** *** *** *** 
*/
#ifndef NO_PROTO
    setmsg_("1", "<Inquire current element type and size> should return char"
	    "acter height as the element type and an integer array entry size"
	    " of 0, real array entry size of 1, and a string array entry size"
	    " of 0 when the element pointer indicates a character height elem"
	    "ent.", 1L, 254L);
#else /* NO_PROTO */
    setmsg_("1", "<Inquire current element type and size> should return char\
acter height as the element type and an integer array entry size of 0, real \
array entry size of 1, and a string array entry size of 0 when the element p\
ointer indicates a character height element.", 1L, 254L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 34 && intsz == 0 && rlsz == 1 && strsz == 
	    0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Inquire current element content> should return the approp"
	    "riate information contained in the data record associated with c"
	    "haracter height when indicated by the element pointer.", 1L, 176L)
	    ;
#else /* NO_PROTO */
    setmsg_("3", "<Inquire current element content> should return the approp\
riate information contained in the data record associated with character hei\
ght when indicated by the element pointer.", 1L, 176L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intsz, intar, &rlsz, rlar, &
	    strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 1 && rlar[0] == chval && 
	    strsz == 0;
    ifpf_(&L__1);
/*  Make sure <inquire element type and size> is independent of */
/*  element pointer: */
    nsep (&c__0);
#ifndef NO_PROTO
    setmsg_("4", "<Inquire element type and size> should return character he"
	    "ight as the element type and an integer array entry size of 0, r"
	    "eal array entry size of 1, and a string array entry size of 0 wi"
	    "th character height as the specified element of the open structu"
	    "re.", 1L, 253L);
#else /* NO_PROTO */
    setmsg_("4", "<Inquire element type and size> should return character he\
ight as the element type and an integer array entry size of 0, real array en\
try size of 1, and a string array entry size of 0 with character height as t\
he specified element of the open structure.", 1L, 253L);
#endif /* NO_PROTO */
    nqets (&strid, &c__3, &errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 34 && intsz == 0 && rlsz == 1 && strsz == 
	    0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "<Inquire element content> should return the appropriate in"
	    "formation contained in the data record associated with character"
	    " height as the specified element of the open structure.", 1L, 
	    177L);
#else /* NO_PROTO */
    setmsg_("6", "<Inquire element content> should return the appropriate in\
formation contained in the data record associated with character height as t\
he specified element of the open structure.", 1L, 177L);
#endif /* NO_PROTO */
    nqeco (&strid, &c__3, &c__50, &c__50, &c__50, &errind, &intsz, intar, &
	    rlsz, rlar, &strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 1 && rlar[0] == chval && 
	    strsz == 0;
    ifpf_(&L__1);

/*  *** *** *** ***   specified element = NIL   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("2", "<Inquire current element type and size> should return NIL "
	    "as the element type and 0 as the length of all array entry sizes"
	    " when the element pointer is 0.", 1L, 153L);
#else /* NO_PROTO */
    setmsg_("2", "<Inquire current element type and size> should return NIL \
as the element type and 0 as the length of all array entry sizes when the el\
ement pointer is 0.", 1L, 153L);
#endif /* NO_PROTO */
    intsz = -6;
    rlsz = -6;
    strsz = -6;
    nqcets (&errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 1 && intsz == 0 && rlsz == 0 && strsz == 
	    0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Inquire current element content> should return 0 as the l"
	    "ength of all array entry sizes associated with the data record w"
	    "hen the element pointer is 0.", 1L, 151L);
#else /* NO_PROTO */
    setmsg_("3", "<Inquire current element content> should return 0 as the l\
ength of all array entry sizes associated with the data record when the elem\
ent pointer is 0.", 1L, 151L);
#endif /* NO_PROTO */
    intsz = -6;
    rlsz = -6;
    strsz = -6;
    nqceco (&c__50, &c__50, &c__50, &errind, &intsz, intar, &rlsz, rlar, &
	    strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 0 && strsz == 0;
    ifpf_(&L__1);
/*  Make sure <inquire element type and size> is independent of */
/*  element pointer: */
    nsep (&c__77);
#ifndef NO_PROTO
    setmsg_("5", "<Inquire element type and size> should return NIL as the e"
	    "lement type and 0 as the length of all array entry sizes when th"
	    "e specified element position of the open structure is 0.", 1L, 
	    178L);
#else /* NO_PROTO */
    setmsg_("5", "<Inquire element type and size> should return NIL as the e\
lement type and 0 as the length of all array entry sizes when the specified \
element position of the open structure is 0.", 1L, 178L);
#endif /* NO_PROTO */
    intsz = -6;
    rlsz = -6;
    strsz = -6;
    nqets (&strid, &c__0, &errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 1 && intsz == 0 && rlsz == 0 && strsz == 
	    0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "<Inquire element content> should return 0 as the length of"
	    " all arrays associated with the data record when the specified e"
	    "lement position of the open structure is 0.", 1L, 165L);
#else /* NO_PROTO */
    setmsg_("6", "<Inquire element content> should return 0 as the length of\
 all arrays associated with the data record when the specified element posit\
ion of the open structure is 0.", 1L, 165L);
#endif /* NO_PROTO */
    intsz = -6;
    rlsz = -6;
    strsz = -6;
    nqeco (&strid, &c__0, &c__50, &c__50, &c__50, &errind, &intsz, intar, &
	    rlsz, rlar, &strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 0 && strsz == 0;
    ifpf_(&L__1);
    nclst ();
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

