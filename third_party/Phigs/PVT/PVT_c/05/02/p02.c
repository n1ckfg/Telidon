/* fort//05/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__3 = 3;
static integer c__102 = 102;
static integer c__5 = 5;
static integer c__103 = 103;
static integer c__7 = 7;
static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b14 = .5f;
#else /* NO_PROTO */
static real c_b14 = (float).5;
#endif /* NO_PROTO */
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/02                              * */
/*  *    TEST TITLE : Display surface flag                  * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real plx[5] = { .1f,.9f,.9f,.1f,.1f };
    static real ply[5] = { .1f,.1f,.9f,.9f,.1f };
    static real pfx[7] = { 1.1f,1.2f,1.2f,.8f,.8f,1.1f,1.1f };
    static real pfy[7] = { .6f,.6f,1.4f,1.4f,1.2f,1.2f,.6f };
    static real pmx[3] = { .5f,.6f,.7f };
    static real pmy[3] = { .5f,.4f,.3f };
#else /* NO_PROTO */
    static real plx[5] = { (float).1,(float).9,(float).9,(float).1,(float).1 }
	    ;
    static real ply[5] = { (float).1,(float).1,(float).9,(float).9,(float).1 }
	    ;
    static real pfx[7] = { (float)1.1,(float)1.2,(float)1.2,(float).8,(float)
	    .8,(float)1.1,(float)1.1 };
    static real pfy[7] = { (float).6,(float).6,(float)1.4,(float)1.4,(float)
	    1.2,(float)1.2,(float).6 };
    static real pmx[3] = { (float).5,(float).6,(float).7 };
    static real pmy[3] = { (float).5,(float).4,(float).3 };
#endif /* NO_PROTO */

    /* System generated locals */
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), npl (integer 
	    *, real *, real *), npm (integer *, real *, real *), ifpf_(
	    logical *), nuwk (integer *, integer *), nrst (integer *, integer 
	    *), endit_(void), nclst (void), nsdus (integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), nopst (
	    integer *), npost (integer *, integer *, real *), initgl_(char *, 
	    ftnlen), setmsg_(char *, char *, ftnlen, ftnlen);
    extern logical surfok_(integer *, integer *);
    extern /* Subroutine */ int nupast (integer *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), npl (), npm (), ifpf_(), nuwk (), 
	    nrst (), endit_(), nclst (), nsdus (), nopwk (), nopst (), npost (
	    ), initgl_(), setmsg_();
    extern logical surfok_();
    extern /* Subroutine */ int nupast (), xpopph_();
#endif /* NO_PROTO */

/* clear control flag */
/* deferral mode */
/* display surface empty */
/* dynamic modification */
/* modification mode */
/* regeneration flag */
/* state of visual representation */
/*  Declare program-specific variables */
/* parameters used in posting a structure */
    initgl_("05.02/02", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  DESIGN: */
/* create structure 101 with */
/*  polymarker in default workstation window */
    nopst (&c__101);
    npm (&c__3, pmx, pmy);
    nclst ();
/* create structure 102 with */
/*  polyline in default workstation window */
    nopst (&c__102);
    npl (&c__5, plx, ply);
    nclst ();
/* create structure 103 with */
/*  fill area outside default workstation window */
    nopst (&c__103);
    nfa (&c__7, pfx, pfy);
    nclst ();
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  <set display update state> ASAP, NIVE */
    nsdus (&globnu_1.wkid, &c__0, &c__0);
#ifndef NO_PROTO
    setmsg_("4 9 10 12", "After <open workstation>, until something is drawn"
	    " inside the workstation window, the display surface should be re"
	    "ported as EMPTY.", 9L, 130L);
#else /* NO_PROTO */
    setmsg_("4 9 10 12", "After <open workstation>, until something is drawn\
 inside the workstation window, the display surface should be reported as EM\
PTY.", 9L, 130L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__1);
    ifpf_(&L__1);
/*  <post structure> 101 */
    npost (&globnu_1.wkid, &c__101, &c_b14);
#ifndef NO_PROTO
    setmsg_("4 10 11", "After a visible primitive is first posted to a works"
	    "tation with deferral mode ASAP, the display surface should be re"
	    "ported as NOTEMPTY.", 7L, 135L);
#else /* NO_PROTO */
    setmsg_("4 10 11", "After a visible primitive is first posted to a works\
tation with deferral mode ASAP, the display surface should be reported as NO\
TEMPTY.", 7L, 135L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__0);
    ifpf_(&L__1);
/*  <post structure> 102 */
    npost (&globnu_1.wkid, &c__102, &c_b14);
#ifndef NO_PROTO
    setmsg_("4 10 11", "After posting of additional visible primitives to a "
	    "workstation with deferral mode ASAP, the display surface should "
	    "be continue to be reported as NOTEMPTY.", 7L, 155L);
#else /* NO_PROTO */
    setmsg_("4 10 11", "After posting of additional visible primitives to a \
workstation with deferral mode ASAP, the display surface should be continue \
to be reported as NOTEMPTY.", 7L, 155L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__0);
    ifpf_(&L__1);
/*  <unpost all structures> from workstation */
    nupast (&globnu_1.wkid);
#ifndef NO_PROTO
    setmsg_("4 10 12", "After all structures have been unposted from a works"
	    "tation with deferral mode ASAP, the display surface should be re"
	    "ported as EMPTY.", 7L, 132L);
#else /* NO_PROTO */
    setmsg_("4 10 12", "After all structures have been unposted from a works\
tation with deferral mode ASAP, the display surface should be reported as EM\
PTY.", 7L, 132L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__1);
    ifpf_(&L__1);
/*  <post structure> 103 (off-screen) */
    npost (&globnu_1.wkid, &c__103, &c_b14);
#ifndef NO_PROTO
    setmsg_("4 10 12", "If a structure is posted to a workstation with defer"
	    "ral mode ASAP, but none of its primitives lie within the worksta"
	    "tion window, the display surface should still be reported as NOT"
	    "EMPTY.", 7L, 186L);
#else /* NO_PROTO */
    setmsg_("4 10 12", "If a structure is posted to a workstation with defer\
ral mode ASAP, but none of its primitives lie within the workstation window,\
 the display surface should still be reported as NOTEMPTY.", 7L, 186L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__0);
    ifpf_(&L__1);
/*  <set display update state> WAIT, NIVE */
    nsdus (&globnu_1.wkid, &c__4, &c__0);
/*  <unpost all structures> from workstation */
    nupast (&globnu_1.wkid);
/*  <post structure> 101 */
    npost (&globnu_1.wkid, &c__101, &c_b14);
/*  <redraw all structures> */
    nrst (&globnu_1.wkid, &c__1);
#ifndef NO_PROTO
    setmsg_("4 10 11", "After a visible primitive is first posted and the wo"
	    "rkstation is then explicitly updated, the display surface should"
	    " be reported as NOTEMPTY.", 7L, 141L);
#else /* NO_PROTO */
    setmsg_("4 10 11", "After a visible primitive is first posted and the wo\
rkstation is then explicitly updated, the display surface should be reported\
 as NOTEMPTY.", 7L, 141L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__0);
    ifpf_(&L__1);
/*  <unpost all structures> from workstation */
    nupast (&globnu_1.wkid);
/*  <update workstation> with PERFORM */
    nuwk (&globnu_1.wkid, &c__1);
#ifndef NO_PROTO
    setmsg_("4 10 12", "After all structures have been unposted and the work"
	    "station is then explicitly updated, the display surface should b"
	    "e reported as EMPTY.", 7L, 136L);
#else /* NO_PROTO */
    setmsg_("4 10 12", "After all structures have been unposted and the work\
station is then explicitly updated, the display surface should be reported a\
s EMPTY.", 7L, 136L);
#endif /* NO_PROTO */
    L__1 = surfok_(&globnu_1.wkid, &c__1);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

