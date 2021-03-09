/* streq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
logical streq_(char *req, ftnlen req_len)
#else /* NO_PROTO */
logical streq_(req, req_len)
char *req;
ftnlen req_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nar, ast, nwk, pst, sst, wst, idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *), nqars (integer *), unmsg_(char *, ftnlen), 
	    nqsys (integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf (), nqars (), unmsg_(), nqsys (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *), nqopst (integer *, integer *, integer *), nqwkst (
	    integer *), nqstrs (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk (), nqopst (), nqwkst (), nqstrs ();
#endif /* NO_PROTO */

/*  STREQ determines whether a required state is actually in force, */
/*  as reported by all the relevant inquire functions. */

/*  Input parameter: */
/*    REQ : 4-character code for required state, position 1-4 standing */
/*          for PHIGS, Workstation, Structure, and Archive, respectively. 
*/
/*          Each position must be 'O', 'C', or '*', standing for open, */
/*          closed, and don't care. */
/* system state value */
/* workstation state */
/* structure state value */
/* archive state */
/* open-structure status */
    ret_val = FALSE_;
    nqsys (&pst);
    nqwkst (&wst);
    nqstrs (&sst);
    nqars (&ast);
    if (*req == 'O') {
/*  PHIGS should be open */
	if (pst != 1) {
	    return ret_val;
	}
	if (req[1] == '*') {
/*           don't care about workstation status */
	} else {
	    nqopwk (&c__0, &errind, &nwk, &idum1);
	    chkinq_("pqopwk", &errind, 6L);
	    if (req[1] == 'O') {
		if (wst != 1) {
		    return ret_val;
		}
		if (nwk < 1) {
		    return ret_val;
		}
	    } else if (req[1] == 'C') {
		if (wst != 0) {
		    return ret_val;
		}
		if (nwk != 0) {
		    return ret_val;
		}
	    } else {
#ifndef NO_PROTO
		unmsg_("Second character of parameter to STREQ must be O or "
			"C or *.", 59L);
#else /* NO_PROTO */
		unmsg_("Second character of parameter to STREQ must be O or \
C or *.", 59L);
#endif /* NO_PROTO */
	    }
	}
	if (req[2] == '*') {
/*           don't care about structure status */
	} else {
	    nqopst (&errind, &opstat, &idum1);
	    chkinq_("pqopst", &errind, 6L);
	    if (req[2] == 'O') {
		if (sst != 1) {
		    return ret_val;
		}
		if (opstat != 1) {
		    return ret_val;
		}
	    } else if (req[2] == 'C') {
		if (sst != 0) {
		    return ret_val;
		}
		if (opstat != 0) {
		    return ret_val;
		}
	    } else {
#ifndef NO_PROTO
		unmsg_("Third character of parameter to STREQ must be O or C"
			" or *.", 58L);
#else /* NO_PROTO */
		unmsg_("Third character of parameter to STREQ must be O or C\
 or *.", 58L);
#endif /* NO_PROTO */
	    }
	}
	if (req[3] == '*') {
/*           don't care about archive status */
	} else {
	    nqarf (&c__0, &errind, &nar, &idum1, &idum2);
	    chkinq_("pqarf", &errind, 5L);
	    if (req[3] == 'O') {
		if (ast != 1) {
		    return ret_val;
		}
		if (nar < 1) {
		    return ret_val;
		}
	    } else if (req[3] == 'C') {
		if (ast != 0) {
		    return ret_val;
		}
		if (nar != 0) {
		    return ret_val;
		}
	    } else {
#ifndef NO_PROTO
		unmsg_("Fourth character of parameter to STREQ must be O or "
			"C or *.", 59L);
#else /* NO_PROTO */
		unmsg_("Fourth character of parameter to STREQ must be O or \
C or *.", 59L);
#endif /* NO_PROTO */
	    }
	}
    } else if (*req == 'C') {
/*  PHIGS should be closed */
	if (s_cmp(req, "CCCC", 4L, 4L) != 0) {
	    unmsg_("STREQ parameter should be CCCC.", 31L);
	}
	if (pst != 0) {
	    return ret_val;
	}
	if (wst != 0) {
	    return ret_val;
	}
	if (sst != 0) {
	    return ret_val;
	}
	if (ast != 0) {
	    return ret_val;
	}
    } else {
	unmsg_("First character of parameter to STREQ must be O or C.", 53L);
    }
    ret_val = TRUE_;
    return ret_val;
} /* streq_ */

