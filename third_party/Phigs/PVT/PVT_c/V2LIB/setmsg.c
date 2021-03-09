/* setmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int setmsg_(char *srlist, char *msg, ftnlen srlist_len, 
	ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int setmsg_(srlist, msg, srlist_len, msg_len)
char *srlist, *msg;
ftnlen srlist_len;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[4];
    integer i__1[2], i__2, i__3, i__4[4];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_cat();
    integer i_indx();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

#endif /* not NO_PROTO */
    /* Local variables */
    static char ch[1];
    static integer it, loc, lim, idig;
    static char term[1];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char fixsr[80];

/*  Setmsg parses the srlist (a list of semantic requirements), accepts an
 */
/*  associated message describing the condition about to be tested, and */

/*  sets the COMMON variable tstmsg to a resulting value, to be issued by 
*/
/*  either pass or fail, whichever is next executed. */
/*  Both pass and fail blank out tstmsg as a sign that they have processed
 */
/*  it, and so setmsg requires that it be blank upon entry. */
    if (s_cmp(globch_1.tstmsg, " ", 900L, 1L) != 0) {
	unmsg_("Non-blank tstmsg detected by setmsg.  Program logic error.", 
		58L);
    }
/* srlist must be a list of 1 or 2-digit numbers separated by spaces. */
/* This routine edits out extra spaces and leading zeros. */
/* term is an "unusual" character, used to terminate string */
    *term = '\17';
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = srlist_len, a__1[1] = srlist;
    s_cat(fixsr, a__1, i__1, &c__2, 80L);
    it = itrim_(fixsr, 80L) + 1;
    fixsr[it - 1] = *term;
/* edit out extra spaces - we assume fixsr is longer than srlist and has 
*/
/* some trailing spaces. */
L100:
    loc = i_indx(fixsr, "  ", 80L, 2L);
    lim = i_indx(fixsr, term, 80L, 1L);
    if (loc > 0 && loc < lim) {
	i__2 = loc;
	s_copy(fixsr + (loc - 1), fixsr + i__2, 80 - (loc - 1), 80 - i__2);
	goto L100;
    }
/* edit out leading zeros */
L200:
    loc = i_indx(fixsr, " 0", 80L, 2L);
    if (loc > 0) {
	i__2 = loc;
	i__3 = loc + 1;
	s_copy(fixsr + i__2, fixsr + i__3, 80 - i__2, 80 - i__3);
	goto L200;
    }
/* should be only digits and spaces */
    loc = 0;
    idig = 0;
L300:
    ++loc;
    *ch = fixsr[loc - 1];
    if (*ch == *term) {
	goto L400;
    }
    if (*ch == ' ') {
	goto L300;
    }
    if (*ch >= '0' && *ch <= '9') {
	idig = 1;
	goto L300;
    }
/* Illegal character in parameter - bomb this test */
    unmsg_("Illegal character in setmsg srlist-parameter.", 45L);
L400:
    if (idig == 0) {
	unmsg_("No digits found in setmsg srlist-parameter.", 43L);
    }
/* OK, fixsr looks valid... */
    lim = i_indx(fixsr, term, 80L, 1L) - 1;
/* set up pass/fail message */
/* Writing concatenation */
    i__4[0] = 3, a__2[0] = "#SR";
    i__4[1] = lim, a__2[1] = fixsr;
    i__4[2] = 2, a__2[2] = ", ";
    i__4[3] = msg_len, a__2[3] = msg;
    s_cat(globch_1.tstmsg, a__2, i__4, &c__4, 900L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setmsg_ */

