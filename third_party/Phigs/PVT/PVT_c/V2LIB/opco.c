/* opco.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char ophead[300];
} opcomm_;

#define opcomm_1 opcomm_

/* Table of constant values */

static integer c__2 = 2;
static integer c__4 = 4;
static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int opco_(char *topic, ftnlen topic_len)
#else /* NO_PROTO */
/* Subroutine */ int opco_(topic, topic_len)
char *topic;
ftnlen topic_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[4], a__3[3];
    integer i__1[2], i__2[4], i__3[3];
    char ch__1[1204];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static char resp[900];
    static integer oplen;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int brdmsg_(char *, ftnlen), dstrng_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int brdmsg_(), dstrng_();
#endif /* NO_PROTO */
    static char prompt[300];

/*  OPCO allows the operator to enter a character string as a */
/*  comment, which is then generated as an OP-type message. */
/*  If there is a current topical heading, it is prefixed to */
/*  the string. */
    oplen = itrim_(opcomm_1.ophead, 300L) + 1;
    if (s_cmp(topic, " ", topic_len, 1L) == 0) {
/* Writing concatenation */
	i__1[0] = oplen, a__1[0] = opcomm_1.ophead;
	i__1[1] = 17, a__1[1] = "Operator comment?";
	s_cat(prompt, a__1, i__1, &c__2, 300L);
    } else {
/* Writing concatenation */
	i__2[0] = oplen, a__2[0] = opcomm_1.ophead;
	i__2[1] = 17, a__2[1] = "Operator comment ";
	i__2[2] = topic_len, a__2[2] = topic;
	i__2[3] = 1, a__2[3] = "?";
	s_cat(prompt, a__2, i__2, &c__4, 300L);
    }
    dstrng_(prompt, resp, 300L, 900L);
    if (s_cmp(resp, " ", 900L, 1L) != 0) {
/* Writing concatenation */
	i__3[0] = 4, a__3[0] = "OP: ";
	i__3[1] = oplen, a__3[1] = opcomm_1.ophead;
	i__3[2] = 900, a__3[2] = resp;
	s_cat(ch__1, a__3, i__3, &c__3, 1204L);
	brdmsg_(ch__1, oplen + 904);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opco_ */

