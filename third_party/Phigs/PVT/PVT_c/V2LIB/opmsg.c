/* opmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int opmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int opmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);
#else /* NO_PROTO */
    integer s_cmp(), s_wsle(), do_lio(), e_wsle();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, iy, nxt, mlen, lastb;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, 0, 0 };
    static cilist io___4 = { 0, 6, 0, 0, 0 };
    static cilist io___8 = { 0, 6, 0, 0, 0 };


/*  OPMSG writes out a message to the operator.  No assumptions are */
/*  made that a workstation is open. */
    if (s_cmp(msg, " ", msg_len, 1L) == 0) {
	s_wsle(&io___1);
	do_lio(&c__9, &c__1, " ", 1L);
	e_wsle();
	return 0;
    }
/*  set IX,LASTB to start, end of substring to be printed */
    ix = 1;
    mlen = itrim_(msg, msg_len);
L100:
    if (mlen - ix < globnu_1.maxlin) {
	s_wsle(&io___4);
	do_lio(&c__9, &c__1, msg + (ix - 1), mlen - (ix - 1));
	e_wsle();
	return 0;
    }
    i__1 = ix;
    for (iy = ix + globnu_1.maxlin; iy >= i__1; --iy) {
	if (msg[iy - 1] == ' ') {
	    lastb = iy;
	    nxt = lastb + 1;
	    goto L210;
	}
/* L200: */
    }
    lastb = ix + globnu_1.maxlin;
    nxt = lastb;
L210:
    s_wsle(&io___8);
    do_lio(&c__9, &c__1, msg + (ix - 1), lastb - 1 - (ix - 1));
    e_wsle();
    ix = nxt;
    goto L100;
} /* opmsg_ */

