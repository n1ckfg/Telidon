/* exsvrs.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int exsvrs_(integer *sevrty, integer *defmod, integer *modmd,
	 integer *oldsvr, char *svrlst, char *explbl, ftnlen svrlst_len, 
	ftnlen explbl_len)
#else /* NO_PROTO */
/* Subroutine */ int exsvrs_(sevrty, defmod, modmd, oldsvr, svrlst, explbl, 
	svrlst_len, explbl_len)
integer *sevrty, *defmod, *modmd, *oldsvr;
char *svrlst, *explbl;
ftnlen svrlst_len;
ftnlen explbl_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char svrlab[10*3] = "CORRECT   " "DEFERRED  " "SIMULATED ";
#else /* NO_PROTO */
    static char svrlab[10*3+1] = "CORRECT   DEFERRED  SIMULATED ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static logical nonf;
    static integer svrx;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static logical svrst[3];
    static integer nxtpos;

/* EXSVRS returns a string that represents the expected state(s) of visual
*/
/* representation.  It contains c, d, and/or s to indicate that the allowe
d*/
/*  state(s) are correct, deferred, or simulated, respectively.  It also 
*/
/*  returns a English label to describe the states.  This function applies
 */
/*  only to defer mode WAIT, PBNIL, PBNIG, and ASTI. */
/*  Input parameters: */
/*   SEVRTY : severity code for the category of picture change (IRG,IMM,CB
S)*/
/*    DEFMOD : deferral mode (WAIT,ASTI,BNIL,BNIG) */
/*    MODMD  : modification mode (UWOR,UQUM) */
/*    OLDSVR : original state of visual representation (CORRECT, DEFERRED,
 */
/*             SIMULATED) */
/*  Output parameters: */
/*    SVRLST : 3-character code, containing some combination of c,d,s for 
*/
/*             CORRECT, DEFERRED, SIMULATED */
/*    EXPLBL : English label corresponding to SVRLST */
/* deferral mode */
/* modification mode */
/* dynamic modification */
/* state of visual representation */
/*                correct    deferred    simulated */
    if (*defmod < 1 || *defmod > 4) {
	unmsg_("Illegal deferral mode passed to EXSVRS.", 39L);
    }
    if (*modmd == 1 || *modmd == 2) {
/*        OK */
    } else {
	unmsg_("Illegal modification mode passed to EXSVRS.", 43L);
    }
    if (*oldsvr == 0 || *oldsvr == 1 || *oldsvr == 2) {
/*        OK */
    } else {
	unmsg_("Illegal SVR passed to EXSVRS.", 29L);
    }
/*  so much for validity checking - now compute expected state(s) */
    svrst[0] = FALSE_;
    svrst[1] = FALSE_;
    svrst[2] = FALSE_;
    svrst[*oldsvr] = TRUE_;
    if (*sevrty == 1) {
/*        OK as is */
    } else if (*sevrty == 0) {
	svrst[1] = TRUE_;
	if (*modmd == 2 && *oldsvr == 0) {
	    svrst[2] = TRUE_;
	}
    } else if (*sevrty == 2) {
	if (*modmd == 2) {
	    if (*oldsvr == 0) {
		svrst[2] = TRUE_;
	    }
	} else {
/*           MODMD.EQ.PUWOR */
	    svrst[1] = TRUE_;
	}
    } else {
	unmsg_("Illegal severity code passed to EXSVRS.", 39L);
    }
    if (*defmod == 3 || *defmod == 1 || *defmod == 2) {
	svrst[0] = TRUE_;
    }
    s_copy(svrlst, "   ", 3L, 3L);
    if (svrst[0]) {
	*svrlst = 'c';
    }
    if (svrst[1]) {
	svrlst[1] = 'd';
    }
    if (svrst[2]) {
	svrlst[2] = 's';
    }
    nonf = FALSE_;
    nxtpos = 1;
    for (svrx = 0; svrx <= 2; ++svrx) {
	if (svrst[svrx]) {
	    if (nonf) {
		s_copy(explbl + (nxtpos - 1), " or ", explbl_len - (nxtpos - 
			1), 4L);
		nxtpos += 4;
	    } else {
		nonf = TRUE_;
	    }
	    s_copy(explbl + (nxtpos - 1), svrlab + svrx * 10, explbl_len - (
		    nxtpos - 1), 10L);
	    nxtpos = itrim_(explbl, explbl_len) + 1;
	}
/* L98: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* exsvrs_ */

