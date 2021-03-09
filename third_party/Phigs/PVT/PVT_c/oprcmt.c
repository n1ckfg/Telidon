/* fort//oprcmt.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__9 = 9;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 00/oprcmt                             * */
/*  *    TEST TITLE : Operator comments                     * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/*  FILE: OPRCMT.FOR */
/*  This program allows the operator to enter comments into the */
/*  relevant message files while not within a numbered test. It */
/*  should be used to record the result of an aborted test, or a test */
/*  that cannot start execution (e.g. cannot compile or link). */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_rsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_rsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsle(), do_lio(), e_wsle(), s_rsfe(), do_fio(), e_rsfe();
    /* Subroutine */ int s_copy();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static char resp[2000], rline[300];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int brdmsg_(char *, ftnlen), initgl_(char *, 
	    ftnlen), windup_(void);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int brdmsg_(), initgl_(), windup_();
#endif /* NO_PROTO */
    static integer nxtpos;

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, 0, 0 };
    static cilist io___2 = { 0, 6, 0, 0, 0 };
    static cilist io___3 = { 0, 5, 0, fmt_800, 0 };
    static cilist io___4 = { 0, 6, 0, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___6 = { 0, 6, 0, 0, 0 };
    static cilist io___8 = { 0, 5, 0, fmt_800, 0 };


    s_wsle(&io___1);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "Enter the identifier for the module and program (e"
	    ".g. \"06.01.02/02\")", 68L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "Enter the identifier for the module and program (e\
.g. \"06.01.02/02\")", 68L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___2);
    do_lio(&c__9, &c__1, "about which operator comment(s) are to be made.", 
	    47L);
    e_wsle();
/* L800: */
    s_rsfe(&io___3);
    do_fio(&c__1, globch_1.pident, 40L);
    e_rsfe();
    initgl_(globch_1.pident, 40L);
L100:
    s_wsle(&io___4);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "Enter next multi-line comment.  A line with a sing"
	    "le period", 59L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "Enter next multi-line comment.  A line with a sing\
le period", 59L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___5);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "terminates the comment.  A line with a single \""
	    "q\" terminates the", 64L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "terminates the comment.  A line with a single \"\
q\" terminates the", 64L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___6);
    do_lio(&c__9, &c__1, "comment and this program.", 25L);
    e_wsle();
    s_copy(resp, "OP:", 2000L, 3L);
L200:
    s_rsfe(&io___8);
    do_fio(&c__1, rline, 300L);
    e_rsfe();
    if (s_cmp(rline, ".", 300L, 1L) == 0 || s_cmp(rline, "q", 300L, 1L) == 0) 
	    {
/*        do nothing */
    } else {
	nxtpos = itrim_(resp, 2000L) + 2;
	s_copy(resp + (nxtpos - 1), rline, 2000 - (nxtpos - 1), 300L);
	goto L200;
    }
    if (s_cmp(resp, "OP:", 2000L, 3L) != 0) {
	brdmsg_(resp, 2000L);
    }
    if (s_cmp(rline, ".", 300L, 1L) == 0) {
	goto L100;
    }
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

#ifndef NO_PROTO
/* Main program alias */ int oprcmt_ () { MAIN__ (); return 0; }
#else /* NO_PROTO */
/* Main program alias */ int oprcmt_ () { MAIN__ (); }
#endif /* NO_PROTO */
