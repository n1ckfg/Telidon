/* fort/02/01/03/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b19 = 1.f;
#else /* NO_PROTO */
static real c_b19 = (float)1.;
#endif /* NO_PROTO */
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.03.01/02                        * */
/*  *    TEST TITLE : Changing a structure identifier when  * */
/*  *                 the original and resulting identifier * */
/*  *                 are the same                          * */
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

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer idum1;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical csseq_();
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int npost (integer *, integer *, real *), nopst (
	    integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npost (), nopst (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncstid (integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), stdcss_(void)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncstid (), setmsg_(), stdcss_();
#endif /* NO_PROTO */
    static integer comstr;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern logical strcon_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer opnstr, pstnum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpost (integer *, integer *, integer *, 
	    integer *, integer *, real *), nqstst (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpost (), nqstst ();
#endif /* NO_PROTO */
    static integer pststr;

/* structure status indicator */
/* open structure status */
/* element types */
/* string indicating the state of the CSS */
/* contents of structures 120 and 108 */
    initgl_("02.01.03.01/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  *** *** *** ***   Common structure = NON-EXISTENT   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("2", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure does not e"
	    "xist should create an empty structure.", 1L, 160L);
#else /* NO_PROTO */
    setmsg_("2", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure does not exist should \
create an empty structure.", 1L, 160L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 300;
    ncstid (&comstr, &comstr);
/* use <inquire structure status> to determine */
/*    strsti = structure status indicator */
    nqstst (&comstr, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure does not e"
	    "xist should create an empty structure thus changing the contents"
	    " of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           300,0/", 906L);
#else /* NO_PROTO */
    setmsg_("2", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure does not exist should \
create an empty structure thus changing the contents of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       300,0/", 906L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* *** *** *** Common structure = closed, not referenced, not posted *** 
*** ****/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " not referenced and not posted should result in the structure be"
	    "ing closed, contents unchanged and not posted.", 1L, 232L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, not referen\
ced and not posted should result in the structure being closed, contents unc\
hanged and not posted.", 1L, 232L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 120;
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &idum1);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
#ifndef NO_PROTO
    L__1 = stype == 0 && pstnum == 0 && strcon_(&comstr, "67,907, 66,106    "
	    "  ", 20L);
#else /* NO_PROTO */
    L__1 = stype == 0 && pstnum == 0 && strcon_(&comstr, "67,907, 66,106    \
  ", 20L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " not referenced and not posted should have no effect on the cont"
	    "ents of the CSS.", 1L, 202L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, not referen\
ced and not posted should have no effect on the contents of the CSS.", 1L, 
	    202L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* *** *** *** Common structure = closed, not referenced, posted *** *** 
****/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " not referenced and posted should result in the structure being "
	    "closed, contents unchanged and posted.", 1L, 224L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, not referen\
ced and posted should result in the structure being closed, contents unchang\
ed and posted.", 1L, 224L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 120;
    npost (&globnu_1.wkid, &comstr, &c_b19);
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &idum1);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pststr = posted structure */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__1, &errind, &pstnum, &pststr, &rdum1);
    L__1 = errind == 0 && stype == 0 && pstnum == 1 && pststr == comstr && 
	    strcon_(&comstr, "67,907, 66,106      ", 20L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " not referenced and posted should have no effect on the contents"
	    " of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, not referen\
ced and posted should have no effect on the contents of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* *** *** *** Common structure = closed, referenced, not posted *** *** 
****/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " referenced and not posted should result in the structure being "
	    "closed, contents unchanged and not posted.", 1L, 228L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, referenced \
and not posted should result in the structure being closed, contents unchang\
ed and not posted.", 1L, 228L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 108;
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &idum1);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
#ifndef NO_PROTO
    L__1 = stype == 0 && pstnum == 0 && strcon_(&comstr, "67,961, 66,111    "
	    "  ", 20L);
#else /* NO_PROTO */
    L__1 = stype == 0 && pstnum == 0 && strcon_(&comstr, "67,961, 66,111    \
  ", 20L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " referenced and not posted should have no effect on the contents"
	    " of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, referenced \
and not posted should have no effect on the contents of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/*  *** *** *** Common structure = closed, referenced, posted *** *** *** 
*/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " referenced and posted should result in the structure being clos"
	    "ed, contents unchanged and posted.", 1L, 220L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, referenced \
and posted should result in the structure being closed, contents unchanged a\
nd posted.", 1L, 220L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 108;
    npost (&globnu_1.wkid, &comstr, &c_b19);
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &idum1);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pststr = posted structure */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__1, &errind, &pstnum, &pststr, &rdum1);
    L__1 = errind == 0 && stype == 0 && pstnum == 1 && pststr == comstr && 
	    strcon_(&comstr, "67,961, 66,111      ", 20L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is closed,"
	    " referenced and posted should have no effect on the contents of "
	    "the CSS.", 1L, 194L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is closed, referenced \
and posted should have no effect on the contents of the CSS.", 1L, 194L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* *** *** *** Common structure = opened, not referenced, not posted *** 
*** ****/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " not referenced and not posted should result in the structure be"
	    "ing opened, contents unchanged and not posted.", 1L, 232L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, not referen\
ced and not posted should result in the structure being opened, contents unc\
hanged and not posted.", 1L, 232L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 120;
    nopst (&comstr);
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     opnstr = open structure */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &opnstr);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
    L__1 = stype == 1 && opnstr == comstr && pstnum == 0 && strcon_(&comstr, 
	    "67,907, 66,106      ", 20L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " not referenced and not posted should have no effect on the cont"
	    "ents of the CSS.", 1L, 202L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, not referen\
ced and not posted should have no effect on the contents of the CSS.", 1L, 
	    202L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* *** *** *** Common structure = opened, not referenced, posted *** *** 
****/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " not referenced and posted should result in the structure being "
	    "opened, contents unchanged and posted.", 1L, 224L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, not referen\
ced and posted should result in the structure being opened, contents unchang\
ed and posted.", 1L, 224L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 120;
    nopst (&comstr);
    npost (&globnu_1.wkid, &comstr, &c_b19);
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     opnstr = open structure */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &opnstr);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pststr = posted structure */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__1, &errind, &pstnum, &pststr, &rdum1);
    L__1 = errind == 0 && stype == 1 && opnstr == comstr && pstnum == 1 && 
	    pststr == comstr && strcon_(&comstr, "67,907, 66,106      ", 20L);

    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " not referenced and posted should have no effect on the contents"
	    " of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, not referen\
ced and posted should have no effect on the contents of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* *** *** *** Common structure = opened, referenced, not posted *** *** 
****/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " referenced and not posted should result in the structure being "
	    "opened, contents unchanged and not posted.", 1L, 228L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, referenced \
and not posted should result in the structure being opened, contents unchang\
ed and not posted.", 1L, 228L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 108;
    nopst (&comstr);
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     opnstr = open structure */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &opnstr);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
    L__1 = stype == 1 && opnstr == comstr && pstnum == 0 && strcon_(&comstr, 
	    "67,961, 66,111      ", 20L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " referenced and not posted should have no effect on the contents"
	    " of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, referenced \
and not posted should have no effect on the contents of the CSS.", 1L, 198L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/*  *** *** *** Common structure = opened, referenced, posted *** *** *** 
*/
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " referenced and posted should result in the structure being open"
	    "ed, contents unchanged and posted.", 1L, 220L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, referenced \
and posted should result in the structure being opened, contents unchanged a\
nd posted.", 1L, 220L);
#endif /* NO_PROTO */
/* subroutine to set up the CSS */
    stdcss_();
    comstr = 108;
    nopst (&comstr);
    npost (&globnu_1.wkid, &comstr, &rdum1);
    ncstid (&comstr, &comstr);
/*  use <inquire open structure> to determine */
/*     opnstr = open structure */
/*     stype  = open structure status */
    nqopst (&errind, &stype, &opnstr);
    chkinq_("pqopst", &errind, 6L);
/*  use <inquire posted structures> to determine */
/*     pststr = posted structure */
/*     pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__1, &errind, &pstnum, &pststr, &rdum1);
    L__1 = errind == 0 && stype == 1 && opnstr == comstr && pstnum == 1 && 
	    pststr == comstr && strcon_(&comstr, "67,961, 66,111      ", 20L);

    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure identifier> where the original and resul"
	    "ting identifier are the same and the common structure is opened,"
	    " referenced and posted should have no effect on the contents of "
	    "the CSS.", 1L, 194L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 10"
	    "5,2, 108,2, 111,3, 115,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "           ", 900L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure identifier> where the original and resul\
ting identifier are the same and the common structure is opened, referenced \
and posted should have no effect on the contents of the CSS.", 1L, 194L);
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                                                            \
                                                                            \
                                                                            \
       ", 900L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

