/* tcscir.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
/* Subroutine */ int tcscir_(integer *opstra, integer *strsta, integer *
	pststa, char *strst, integer *intp, ftnlen strst_len)
#else /* NO_PROTO */
/* Subroutine */ int tcscir_(opstra, strsta, pststa, strst, intp, strst_len)
integer *opstra, *strsta, *pststa;
char *strst;
integer *intp;
ftnlen strst_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char opstab[30*2] = "OPEN                          " "CLOSED     "
	    "                   ";
    static char strtab[30*3] = "                              " ", EMPTY,   "
	    "                   " ", ORIGINAL,                   ";
    static char psttab[50*5] = "and NOT-POSTED                              "
	    "      " "                                                  " 
	    "                                                  " "and POSTED"
	    " with old resulting priority            " "and POSTED with old o"
	    "riginal priority             ";
#else /* NO_PROTO */
    static char opstab[30*2+1] = "OPEN                          CLOSED      \
                  ";
    static char strtab[30*3+1] = "                              , EMPTY,    \
                  , ORIGINAL,                   ";
    static char psttab[50*5+1] = "and NOT-POSTED                            \
                                                                            \
                                and POSTED with old resulting priority      \
      and POSTED with old original priority             ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*     Input Parameters: */
/*     INTEGER opstra     open structure indicator (NOEXE, NOPEN, NCLOS) 
*/
/*     INTEGER strsta     structure status indicator (NOEXE, NEMP,  NORG )
 */
/*    INTEGER pststa     posted structure indicator (NOEXE, NNPT, NPSTR, N
PSTO)*/
/*     Output Parameters: */
/*     CHARACTER strst    string indicating a structure's state as */
/*                        determined by the input parameters */
/*     INTEGER intp       the actual length of the string */
/* Tcscir returns a string and its length indicating the state of a */
/* structure.  The structure can be: open or closed, referenced or not */
/* referenced, empty or with original contents, and posted or not posted. 
*/
/* Enumeration values for subroutine parameters: */
/*   structure state: non-existent   opened       closed */
/*   structure posted state: */
/*                    not posted   posted:priority=R,   posted:priority=O 
*/
/*   structure contents: */
/*                    empty     original */
    if (*opstra == -1) {
	if (*pststa == -1 && *strsta == -1) {
	    s_copy(strst, "NON-EXISTENT", strst_len, 12L);
	    goto L250;
	} else {
#ifndef NO_PROTO
	    unmsg_("Problem with the structure state being non-existent in s"
		    "ubroutine TCSCIR.", 73L);
#else /* NO_PROTO */
	    unmsg_("Problem with the structure state being non-existent in s\
ubroutine TCSCIR.", 73L);
#endif /* NO_PROTO */
	}
    }
    s_copy(strst, opstab + *opstra * 30, strst_len, 30L);
    *intp = itrim_(strst, strst_len) + 1;
    s_copy(strst + (*intp - 1), strtab + (*strsta + 1) * 30, strst_len - (*
	    intp - 1), 30L);
    *intp = itrim_(strst, strst_len) + 2;
    s_copy(strst + (*intp - 1), psttab + (*pststa - 1) * 50, strst_len - (*
	    intp - 1), 50L);
L250:
    *intp = itrim_(strst, strst_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tcscir_ */

