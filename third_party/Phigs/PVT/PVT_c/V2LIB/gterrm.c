/* gterrm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int gterrm_(integer *elun, char *emsg, ftnlen emsg_len)
#else /* NO_PROTO */
/* Subroutine */ int gterrm_(elun, emsg, emsg_len)
integer *elun;
char *emsg;
ftnlen emsg_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char erec[200] = "                                               "
	    "                                                                "
	    "                                                                "
	    "                         ";
#else /* NO_PROTO */
    static char erec[200+1] = "                                             \
                                                                            \
                                                                            \
   ";
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_copy();
    integer s_rsfe(), do_fio(), e_rsfe();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static char ans[1];
    static integer nmrk;
#ifndef NO_PROTO
    extern /* Subroutine */ int opyn_(char *, char *, ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opyn_();
    extern integer itrim_();
    extern /* Subroutine */ int opmsg_();
#endif /* NO_PROTO */
    static logical first;
#ifndef NO_PROTO
    extern logical ermsgh_(char *, char *, integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern logical ermsgh_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 1, "(A)", 0 };
    static cilist io___5 = { 0, 0, 1, "(A)", 0 };


/*  GTERRM retrieves one error message from a specified error file */
/*  and returns it. */
/*  Input parameter: */
/*    ELUN : logical unit number from which to read */
/*  Output parameter: */
/*    EMSG : complete text of error message, even if spread over */
/*           several records; also used as input to tell whether */
/*           this is the first read or not. */
/*  special strings to control processing of error file */
    nmrk = itrim_(errchr_1.errmrk, 20L);
    if (s_cmp(errchr_1.errmrk, " ", 20L, 1L) != 0) {
/*  use special string to identify start of error message */
	first = s_cmp(emsg, "first call", emsg_len, 10L) == 0;
/*  start to fill EMSG from EREC */
L210:
	if (first) {
	    s_copy(emsg, " ", emsg_len, 1L);
	} else {
/*  EREC has first record of error message or EOF indicator */
	    s_copy(emsg, erec, emsg_len, 200L);
	}
	if (s_cmp(emsg, "end of error file", emsg_len, 17L) == 0) {
	    return 0;
	}
L250:
	io___4.ciunit = *elun;
	i__1 = s_rsfe(&io___4);
	if (i__1 != 0) {
	    goto L290;
	}
	i__1 = do_fio(&c__1, erec, 200L);
	if (i__1 != 0) {
	    goto L290;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L290;
	}
/*  EREC now has next record */
	if (ermsgh_(erec, errchr_1.errmrk, &nmrk, 200L, 20L)) {
/*  message header */
	    goto L295;
	} else {
/*  non-header */
	    i__1 = itrim_(emsg, emsg_len) + 1;
	    s_copy(emsg + i__1, erec, emsg_len - i__1, 200L);
	    goto L250;
	}
L290:
	s_copy(erec, "end of error file", 200L, 17L);
L295:
/*  EREC contains either EOFMRK or message header */
	if (first) {
	    first = FALSE_;
	    goto L210;
	}
    } else {
/*  operator must identify completion of error message */
	s_copy(emsg, " ", emsg_len, 1L);
L300:
	io___5.ciunit = *elun;
	i__1 = s_rsfe(&io___5);
	if (i__1 != 0) {
	    goto L310;
	}
	i__1 = do_fio(&c__1, erec, 200L);
	if (i__1 != 0) {
	    goto L310;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L310;
	}
	if (s_cmp(emsg, " ", emsg_len, 1L) == 0) {
	    s_copy(emsg, erec, emsg_len, 200L);
	} else {
	    i__1 = itrim_(emsg, emsg_len) + 1;
	    s_copy(emsg + i__1, erec, emsg_len - i__1, 200L);
	}
	if (s_cmp(emsg, " ", emsg_len, 1L) == 0) {
	    goto L300;
	}
	opmsg_("------- Begin message from error file: -------", 46L);
	opmsg_(emsg, emsg_len);
	opmsg_("------- End message from error file: -------", 44L);
	opyn_("Is the error message completely displayed? ", ans, 43L, 1L);
	if (*ans == 'n') {
	    goto L300;
	}
	goto L320;
L310:
	opmsg_("Hit EOF while trying to read error file.", 40L);
L320:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* gterrm_ */

