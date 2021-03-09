/* brdmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int brdmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int brdmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfe(), do_fio(), e_wsfe(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ib;
    static char buf[999];
    static integer isp;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int opmsg_();
#endif /* NO_PROTO */
    static char msglin[300];
    static integer lstlin;

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_800, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_800, 0 };


/* Brdmsg broadcasts a message to various destinations.  It uses */
/* variables in common to control how it issues the message passed to it. 
*/
/* leading space is as Fortran carriage control character. */
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = msg_len, a__1[1] = msg;
    s_cat(buf, a__1, i__1, &c__2, 999L);
/*  This loop breaks up msg into chunks of size .le. maxlin.  It also */
/* puts 5 spaces to the start of each non-first line, so that message-type
*/
/*  will stand out. */
L100:
    for (ib = globnu_1.maxlin + 1; ib >= 1; --ib) {
	if (buf[ib - 1] == ' ') {
	    isp = ib;
	    goto L210;
	}
/* L200: */
    }
    isp = globnu_1.maxlin;
L210:
/* isp now points to a line-breaking space. */
    s_copy(msglin, buf, 300L, isp - 1);
    lstlin = itrim_(msglin, 300L);
/* ensure *at least* 5 spaces in start of buf. */
    i__2 = isp;
/* Writing concatenation */
    i__1[0] = 5, a__1[0] = "     ";
    i__1[1] = 999 - i__2, a__1[1] = buf + i__2;
    s_cat(buf, a__1, i__1, &c__2, 999L);
/* Message to operator */
    if (globnu_1.errsw == 1) {
	opmsg_(msglin, lstlin);
    }
/* L800: */
/* Message to files */
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
/* append to global file */
	io___6.ciunit = globnu_1.glblun;
	s_wsfe(&io___6);
	do_fio(&c__1, msglin, lstlin);
	e_wsfe();
    }
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
/* add to individual file */
	io___7.ciunit = globnu_1.indlun;
	s_wsfe(&io___7);
	do_fio(&c__1, msglin, lstlin);
	e_wsfe();
    }
/* any more non-blanks to send out?  If not, quit. */
    if (s_cmp(buf, " ", 999L, 1L) == 0) {
	goto L666;
    }
/* ensure *exactly* 5 leading blanks */
L300:
    if (buf[5] != ' ') {
	goto L100;
    }
    s_copy(buf, buf + 1, 999L, 998L);
    goto L300;
L666:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* brdmsg_ */

