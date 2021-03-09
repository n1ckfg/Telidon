/* fort/02/01/02/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__103 = 103;
static integer c__104 = 104;
static integer c__102 = 102;
static integer c__106 = 106;
static integer c__109 = 109;
static integer c__105 = 105;
static integer c__107 = 107;
static integer c__108 = 108;
static integer c__110 = 110;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.01/04                        * */
/*  *    TEST TITLE : Deletion of multiple structures       * */
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
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void), ndst (integer *), 
	    endit_(void), inmsg_(char *, ftnlen);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *), initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_(), ndst (), endit_(), inmsg_();

    extern logical csseq_();
    extern /* Subroutine */ int nclst (), nexst (), nopst (), initgl_();
#endif /* NO_PROTO */
    static integer delstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___3 = { 0, msg, 0, "(A, I3)", 300, 1 };


/* PHIGS parameter types */
    initgl_("02.01.02.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* creation of structures */
    nopst (&c__100);
    nexst (&c__103);
    nexst (&c__104);
    nclst ();
    nopst (&c__102);
    nexst (&c__106);
    nexst (&c__109);
    nclst ();
    nopst (&c__103);
    nexst (&c__105);
    nexst (&c__105);
    nclst ();
    nopst (&c__104);
    nexst (&c__106);
    nclst ();
    nopst (&c__106);
    nexst (&c__107);
    nexst (&c__108);
    nclst ();
    nopst (&c__109);
    nexst (&c__108);
    nexst (&c__110);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 2", "Changes to the CSS should be reflected when deleting mor"
	    "e than one structure.", 3L, 77L);
#else /* NO_PROTO */
    setmsg_("1 2", "Changes to the CSS should be reflected when deleting mor\
e than one structure.", 3L, 77L);
#endif /* NO_PROTO */
    delstr = 103;
    ndst (&delstr);
#ifndef NO_PROTO
    if (! csseq_("100,1, 104,1, 106,1, 107,0/ 100,1, 104,1, 106,2, 108,0/ 10"
	    "2,1, 106,1, 107,0/ 102,1, 106,2, 108,0/ 102,2, 109,1, 108,0/ 102"
	    ",2, 109,2, 110,0/ 105,0/ ", 147L)) {
#else /* NO_PROTO */
    if (! csseq_("100,1, 104,1, 106,1, 107,0/ 100,1, 104,1, 106,2, 108,0/ 10\
2,1, 106,1, 107,0/ 102,1, 106,2, 108,0/ 102,2, 109,1, 108,0/ 102,2, 109,2, 1\
10,0/ 105,0/ ", 147L)) {
#endif /* NO_PROTO */
	goto L555;
    }
    delstr = 106;
    ndst (&delstr);
#ifndef NO_PROTO
    if (! csseq_("102,1, 109,1, 108,0/ 102,1, 109,2, 110,0/ 100,1, 104,0/ 10"
	    "7,0/ 105,0/ ", 70L)) {
#else /* NO_PROTO */
    if (! csseq_("102,1, 109,1, 108,0/ 102,1, 109,2, 110,0/ 100,1, 104,0/ 10\
7,0/ 105,0/ ", 70L)) {
#endif /* NO_PROTO */
	goto L555;
    }
    delstr = 102;
    ndst (&delstr);
    if (! csseq_("109,1, 108,0/ 109,2, 110,0/ 100,1, 104,0/ 107,0/ 105,0/ ", 
	    56L)) {
	goto L555;
    }
    delstr = 110;
    ndst (&delstr);
    if (! csseq_("109,1, 108,0/ 100,1, 104,0/ 107,0/ 105,0/ ", 42L)) {
	goto L555;
    } else {
	pass_();
	goto L666;
    }
/* fail test */
L555:
    fail_();
    s_wsfi(&io___3);
    do_fio(&c__1, "Failure occurred when deleting structure ", 41L);
    do_fio(&c__1, (char *)&delstr, (ftnlen)sizeof(integer));
    e_wsfi();
    inmsg_(msg, 300L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

