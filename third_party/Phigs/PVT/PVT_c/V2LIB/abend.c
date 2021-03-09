/* abend.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int abend_(char *svrty, char *msg, ftnlen svrty_len, ftnlen 
	msg_len)
#else /* NO_PROTO */
/* Subroutine */ int abend_(svrty, msg, svrty_len, msg_len)
char *svrty, *msg;
ftnlen svrty_len;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1[3], i__2[2];
    char ch__1[46];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_cmp();
    /* Subroutine */ int s_copy(), s_stop();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);

#endif /* not NO_PROTO */
    /* Local variables */
    static char buf[900];
#ifndef NO_PROTO
    extern /* Subroutine */ int neclph (void), brdmsg_(char *, ftnlen), 
	    windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int neclph (), brdmsg_(), windup_();
#endif /* NO_PROTO */

/* Abend handles program-aborting messages. */
    ++globnu_1.unerr;
/* Writing concatenation */
    i__1[0] = 2, a__1[0] = svrty;
    i__1[1] = 18, a__1[1] = ": Program ABORT.  ";
    i__1[2] = msg_len, a__1[2] = msg;
    s_cat(buf, a__1, i__1, &c__3, 900L);
    brdmsg_(buf, 900L);
    if (s_cmp(svrty, "UN", 2L, 2L) != 0 && s_cmp(svrty, "NC", 2L, 2L) != 0) {
	++globnu_1.unerr;
/* Writing concatenation */
	i__2[0] = 44, a__2[0] = "UN: unknown severity code passed to abend = "
		;
	i__2[1] = 2, a__2[1] = svrty;
	s_cat(ch__1, a__2, i__2, &c__2, 46L);
	brdmsg_(ch__1, 46L);
    }
/* wrap it up - emergency close */
    neclph ();
/* blank out tstmsg to prevent spurious informational message from windup 
*/
    s_copy(globch_1.tstmsg, " ", 900L, 1L);
/* kill program */
    windup_();
    s_stop("", 0L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* abend_ */

