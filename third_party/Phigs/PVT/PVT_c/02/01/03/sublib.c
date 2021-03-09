/* fort/02/01/03/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__15 = 15;
#ifndef NO_PROTO
static real c_b39 = 1.f;
#else /* NO_PROTO */
static real c_b39 = (float)1.;
#endif /* NO_PROTO */
static integer c__8 = 8;
static integer c_n1 = -1;
static integer c__50 = 50;
static integer c__1 = 1;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01.03/tstcid                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstcid_(integer *orgid, integer *resid, integer *orgstb, 
	integer *orgrfb, integer *orgptb, integer *rsstb, integer *rsrfb, 
	integer *rsptb, integer *orgste, integer *orgche, integer *orgpte, 
	integer *rsste, integer *rsche, integer *rspte, char *srstr, char *
	tcnum, char *excss, ftnlen srstr_len, ftnlen tcnum_len, ftnlen 
	excss_len)
#else /* NO_PROTO */
/* Subroutine */ int tstcid_(orgid, resid, orgstb, orgrfb, orgptb, rsstb, 
	rsrfb, rsptb, orgste, orgche, orgpte, rsste, rsche, rspte, srstr, 
	tcnum, excss, srstr_len, tcnum_len, excss_len)
integer *orgid, *resid, *orgstb, *orgrfb, *orgptb, *rsstb, *rsrfb, *rsptb, *
	orgste, *orgche, *orgpte, *rsste, *rsche, *rspte;
char *srstr, *tcnum, *excss;
ftnlen srstr_len;
ftnlen tcnum_len;
ftnlen excss_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[15], a__3[8];
    integer i__1[2], i__2[15], i__3[8];
    logical L__1;
    char ch__1[35], ch__2[34];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_();
#endif /* NO_PROTO */
    static char strg[300];
    static integer tcsz, srpt;
    static real rdum1;
    static integer intp1, intp2, intp3, intp4;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int actst_(integer *, char *, integer *, integer *
	    , logical *, integer *, real *, ftnlen), unmsg_(char *, ftnlen), 
	    elstr_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
    extern integer itrim_();
    extern logical csseq_();
    extern /* Subroutine */ int actst_(), unmsg_(), elstr_();
#endif /* NO_PROTO */
    static integer msgsz, csssz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), npost (integer *, integer *
	    , real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), npost ();
#endif /* NO_PROTO */
    static char strst1[200], strst2[200], strst3[200], strst4[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int tcscid_(integer *, integer *, integer *, char 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int tcscid_();
#endif /* NO_PROTO */
    static char msgbuf[900];
    static logical contok;
    static char invmsg[29];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    stdcss_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), stdcss_();
#endif /* NO_PROTO */
    static integer opstra;
#ifndef NO_PROTO
    extern /* Subroutine */ int ncstid (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ncstid ();
#endif /* NO_PROTO */
    static integer pststa;

/* Input Parameters: */
/* INTEGER orgid           original structure identifier */
/* INTEGER resid           resulting structure identifier */
/*   The following 6 input parameters identify various structure */
/*   states before the change function is executed. */
/* INTEGER orgstb          original structure open state (NOPEN, NCLOS) */

/*INTEGER orgrfb          original structure referenced state (NREF, NNRF)
*/
/* INTEGER orgptb          original structure posted state (NPST, NNPT) */

/* INTEGER rsstb           resulting structure open state (NOPEN, NCLOS) 
*/
/*INTEGER rsrfb           resulting structure referenced state (NREF, NNRF
)*/
/* INTEGER rsptb           resulting structure posted state (NPST, NNPT) 
*/
/*   The following 6 input parameters identify various expected structure 
*/
/*   states after the change function is executed. */
/* INTEGER orgste          original structure open state (NOPEN, NCLOS) */

/* INTEGER orgche          original structure contents (NEMP, NORG) */
/* INTEGER orgpte          original structure posted state (NPST, NNPT) */

/* INTEGER rsste           resulting structure open state (NOPEN, NCLOS) 
*/
/* INTEGER rsche           resulting structure contents (NEMP, NORG) */
/* INTEGER rspte           resulting structure posted state (NPST, NNPT) 
*/
/* CHARACTER srstr         identification of SR numbers */
/* CHARACTER tcnum         identification of test case number */
/* CHARACTER excss         representation of expected CSS state */
/* TSTCID is used to generate the test messages associated with */
/* <change structure identifer>.  The conditions */
/* stated are tested and pass/fail is returned. */
/* Enumeration values for subroutine parameters: */
/*   structure state: non-existent   opened       closed */
/*   structure posted state: */
/*                    structure posted     structure not posted */
/*   structure reference status: */
/*                    referenced  not referenced */
/*   structure contents: */
/*                    empty     original */
/* check the input parameters to ensure they are in bounds */
    s_copy(invmsg, " has invalid value in TSTCID.", 29L, 29L);
    if (*orgstb != -1 && *orgstb != 0 && *orgstb != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgstb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgrfb != -1 && *orgrfb != 2 && *orgrfb != 3) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgrfb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgptb != -1 && *orgptb != 0 && *orgptb != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgptb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*rsstb != -1 && *rsstb != 0 && *rsstb != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsstb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rsrfb != -1 && *rsrfb != 2 && *rsrfb != 3) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsrfb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rsptb != -1 && *rsptb != 0 && *rsptb != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsptb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*orgste != -1 && *orgste != 0 && *orgste != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgste";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgche != -1 && *orgche != 0) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgche";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgpte != -1 && *orgpte != 0 && *orgpte != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgpte";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*rsste != 0 && *rsste != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsste";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rsche != 0 && *rsche != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsche";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rspte != 0 && *rspte != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rspte";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    tcscid_(orgstb, orgrfb, orgptb, strst1, &intp1, 200L);
    tcscid_(rsstb, rsrfb, rsptb, strst2, &intp2, 200L);
    tcscid_(orgste, orgche, orgpte, strst3, &intp3, 200L);
    tcscid_(rsste, rsche, rspte, strst4, &intp4, 200L);
/* Test condition number */
    tcsz = itrim_(tcnum, tcnum_len);
/* generating the string test condition used in setmsg */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 80, a__2[0] = "<Change structure identifier> with the precondi"
	    "tion being (original structure = ";
#else /* NO_PROTO */
    i__2[0] = 80, a__2[0] = "<Change structure identifier> with the precondi\
tion being (original structure = ";
#endif /* NO_PROTO */
    i__2[1] = intp1, a__2[1] = strst1;
    i__2[2] = 31, a__2[2] = " and the resulting structure = ";
    i__2[3] = intp2, a__2[3] = strst2;
#ifndef NO_PROTO
    i__2[4] = 49, a__2[4] = ") should yield the expected results of (origina"
	    "l ";
#else /* NO_PROTO */
    i__2[4] = 49, a__2[4] = ") should yield the expected results of (origina\
l ";
#endif /* NO_PROTO */
    i__2[5] = 12, a__2[5] = "structure = ";
    i__2[6] = intp3, a__2[6] = strst3;
    i__2[7] = 15, a__2[7] = " and resulting ";
    i__2[8] = 12, a__2[8] = "structure = ";
    i__2[9] = intp4, a__2[9] = strst4;
#ifndef NO_PROTO
    i__2[10] = 47, a__2[10] = ") after execution of the function as stated b"
	    "y ";
#else /* NO_PROTO */
    i__2[10] = 47, a__2[10] = ") after execution of the function as stated b\
y ";
#endif /* NO_PROTO */
    i__2[11] = 15, a__2[11] = "test condition ";
    i__2[12] = tcsz, a__2[12] = tcnum;
    i__2[13] = 8, a__2[13] = " of the ";
    i__2[14] = 12, a__2[14] = "truth table.";
    s_cat(msgbuf, a__2, i__2, &c__15, 900L);
    srpt = itrim_(srstr, srstr_len);
    msgsz = itrim_(msgbuf, 900L);
    setmsg_(srstr, msgbuf, srpt, msgsz);
/* subroutine to set the initial state of the CSS */
    stdcss_();
/* when necessary, initialize the open, close status of the specific */
/* structure */
    if (*orgstb == 0) {
	if (*rsstb == 0) {
	    unmsg_("Bad pre-condition: both original and resulting OPEN.", 
		    52L);
	} else {
	    nopst (orgid);
	}
    } else {
	if (*rsstb == 0) {
	    nopst (resid);
	}
    }
/* when necessary intialize the posting status of the specific structure 
*/
    if (*orgptb == 0) {
	npost (&globnu_1.wkid, orgid, &c_b39);
    }
    if (*rsptb == 0) {
	npost (&globnu_1.wkid, resid, &c_b39);
    }
/* Formulate a string indicating the element types and contents for */
/* the original structure, before execution of function */
    elstr_(orgid, strg, 300L);
    ncstid (orgid, resid);
/* comparison of the original expected state to the actual state */
    actst_(orgid, strg, orgche, &opstra, &contok, &pststa, &rdum1, 300L);
    if (opstra == *orgste && contok && pststa == *orgpte) {
/* OK so far - do nothing */
    } else {
	fail_();
	inmsg_("The actual original structure status is incorrect.", 50L);
	goto L750;
    }
/* comparison of the resulting expected state to the actual state */
    actst_(resid, strg, rsche, &opstra, &contok, &pststa, &rdum1, 300L);
    if (opstra == *rsste && contok && pststa == *rspte) {
	pass_();
    } else {
	fail_();
	inmsg_("The actual resulting structure status is incorrect.", 51L);
    }
/* generate a test condition string dealing with the state of the */
/* CSS. */
L750:
/* Writing concatenation */
#ifndef NO_PROTO
    i__3[0] = 80, a__3[0] = "<Change structure identifier> with the precondi"
	    "tion being (original structure = ";
#else /* NO_PROTO */
    i__3[0] = 80, a__3[0] = "<Change structure identifier> with the precondi\
tion being (original structure = ";
#endif /* NO_PROTO */
    i__3[1] = intp1, a__3[1] = strst1;
    i__3[2] = 27, a__3[2] = " and resulting structure = ";
    i__3[3] = intp2, a__3[3] = strst2;
    i__3[4] = 43, a__3[4] = ") should change the contents of the CSS in ";
    i__3[5] = 40, a__3[5] = "accordance with the substitution of the ";
    i__3[6] = 38, a__3[6] = "resulting identifier for the original ";
    i__3[7] = 11, a__3[7] = "identifier.";
    s_cat(msgbuf, a__3, i__3, &c__8, 900L);
    csssz = itrim_(msgbuf, 900L);
    setmsg_(srstr, msgbuf, srpt, csssz);
    L__1 = csseq_(excss, excss_len);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstcid_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01.03/tcscid                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tcscid_(integer *opstra, integer *strsta, integer *
	pststa, char *strst, integer *intp, ftnlen strst_len)
#else /* NO_PROTO */
/* Subroutine */ int tcscid_(opstra, strsta, pststa, strst, intp, strst_len)
integer *opstra, *strsta, *pststa;
char *strst;
integer *intp;
ftnlen strst_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char opstab[30*2] = "OPEN,                         " "CLOSED,    "
	    "                   ";
    static char strtab[30*4] = "EMPTY,                        " "ORIGINAL,  "
	    "                   " "REFERENCED,                   " "NOT-REFER"
	    "ENCED,               ";
    static char psttab[30*2] = "and POSTED                    " "and NOT-POS"
	    "TED                ";
#else /* NO_PROTO */
    static char opstab[30*2+1] = "OPEN,                         CLOSED,     \
                  ";
    static char strtab[30*4+1] = "EMPTY,                        ORIGINAL,   \
                  REFERENCED,                   NOT-REFERENCED,             \
  ";
    static char psttab[30*2+1] = "and POSTED                    and NOT-POST\
ED                ";
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
/*     INTEGER strsta     structure status indicator (NOEXE, NREF, NNRF, 
*/
/*                                                    NEMP,  NORG ) */
/*     INTEGER pststa     posted structure indicator (NOEXE, NPST, NNPT) 
*/
/*     Output Parameters: */
/*     CHARACTER strst    string indicating a structure's state as */
/*                        determined by the input parameters */
/*     INTEGER intp       the actual length of the string */
/* Tcscid returns a string and its length indicating the state of a */
/* structure.  The structure can be: open or closed, referenced or not */
/* referenced, empty or with original contents, and posted or not posted. 
*/
/* Enumeration values for subroutine parameters: */
/*   structure state: non-existent   opened       closed */
/*   structure posted state: */
/*                    structure posted     structure not posted */
/*   structure reference status: */
/*                    referenced  not referenced */
/*   structure contents: */
/*                    empty     original */
    if (*opstra == -1) {
	if (*pststa == -1 && *strsta == -1) {
	    s_copy(strst, "NON-EXISTENT", strst_len, 12L);
	    goto L250;
	} else {
#ifndef NO_PROTO
	    unmsg_("Problem with the structure state being non-existent in s"
		    "ubroutine TCSCID.", 73L);
#else /* NO_PROTO */
	    unmsg_("Problem with the structure state being non-existent in s\
ubroutine TCSCID.", 73L);
#endif /* NO_PROTO */
	}
    }
    s_copy(strst, opstab + *opstra * 30, strst_len, 30L);
    *intp = itrim_(strst, strst_len) + 2;
    s_copy(strst + (*intp - 1), strtab + *strsta * 30, strst_len - (*intp - 1)
	    , 30L);
    *intp = itrim_(strst, strst_len) + 2;
    s_copy(strst + (*intp - 1), psttab + *pststa * 30, strst_len - (*intp - 1)
	    , 30L);
L250:
    *intp = itrim_(strst, strst_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tcscid_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01.03/tstcir                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstcir_(char *tcnum, integer *orgid, integer *resid, 
	char *excss, integer *orgstb, integer *orgptb, integer *rsstb, 
	integer *rsptb, integer *orgste, integer *orgche, integer *orgpte, 
	integer *rsste, integer *rsche, integer *rspte, ftnlen tcnum_len, 
	ftnlen excss_len)
#else /* NO_PROTO */
/* Subroutine */ int tstcir_(tcnum, orgid, resid, excss, orgstb, orgptb, 
	rsstb, rsptb, orgste, orgche, orgpte, rsste, rsche, rspte, tcnum_len, 
	excss_len)
char *tcnum;
integer *orgid, *resid;
char *excss;
integer *orgstb, *orgptb, *rsstb, *rsptb, *orgste, *orgche, *orgpte, *rsste, *
	rsche, *rspte;
ftnlen tcnum_len;
ftnlen excss_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[15], a__3[8];
    integer i__1[2], i__2[15], i__3[8];
    logical L__1;
    char ch__1[35], ch__2[34];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static char strg[300];
    static integer tcsz, intp1, intp2, intp3, intp4;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
    extern logical csseq_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int actst_(integer *, char *, integer *, integer *
	    , logical *, integer *, real *, ftnlen), unmsg_(char *, ftnlen), 
	    elstr_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
    extern logical csseq_();
    extern integer itrim_();
    extern /* Subroutine */ int actst_(), unmsg_(), elstr_();
#endif /* NO_PROTO */
    static integer msgsz, csssz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), npost (integer *, integer *
	    , real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), npost ();
#endif /* NO_PROTO */
    static char strst1[200], strst2[200], strst3[200], strst4[200], msgbuf[
	    900];
    static logical contok;
#ifndef NO_PROTO
    extern /* Subroutine */ int tcscir_(integer *, integer *, integer *, char 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int tcscir_();
#endif /* NO_PROTO */
    static char invmsg[29];
    static real orgpri, respri;
    static integer opstra;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    stdcss_(void), ncstir (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), stdcss_(), ncstir ();
#endif /* NO_PROTO */
    static integer pststa;
    static real pstpri;

/* Input Parameters: */
/* CHARACTER tcnum         identification of test case number */
/* INTEGER   orgid         original structure identifier */
/* INTEGER   resid         resulting structure identifier */
/* CHARACTER excss         representation of expected CSS state */
/*   The following 4 input parameters identify various structure */
/*   states before the change function is executed. */
/* INTEGER orgstb          original structure open state (NOPEN, NCLOS) */

/* INTEGER orgptb          original structure posted state (NPSTO, NNPT) 
*/
/* INTEGER rsstb           resulting structure open state (NOPEN, NCLOS) 
*/
/* INTEGER rsptb           resulting structure posted state (NPSTR, NNPT) 
*/
/*   The following 6 input parameters identify various expected structure 
*/
/*   states after the change function is executed. */
/* INTEGER orgste          original structure open state (NOPEN, NCLOS) */

/* INTEGER orgche          original structure contents (NEMP, NORG) */
/*INTEGER orgpte          original structure posted state (NPSTR, NPSTO, N
NPT)*/
/* INTEGER rsste           resulting structure open state (NOPEN, NCLOS) 
*/
/* INTEGER rsche           resulting structure contents (NEMP, NORG) */
/*INTEGER rspte           resulting structure posted state (NPSTR, NPSTO, 
NNPT)*/
/* TSTCIR is used to generate the test messages associated with */
/* <change structure identifier and references>.  The conditions */
/* stated are tested and pass/fail is returned. */
/* Enumeration values for subroutine parameters: */
/*   structure state: non-existent   opened       closed */
/*   structure posted state: */
/*                                           posted        posted */
/*                    not posted   posted    priority=R,   priority=O */
/*   structure contents: */
/*                    empty     original */
/* set priorities */
#ifndef NO_PROTO
    orgpri = .1f;
    respri = .2f;
#else /* NO_PROTO */
    orgpri = (float).1;
    respri = (float).2;
#endif /* NO_PROTO */
/* check the input parameters to ensure they are in bounds */
    s_copy(invmsg, " has invalid value in TSTCIR.", 29L, 29L);
    if (*orgstb != -1 && *orgstb != 0 && *orgstb != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgstb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgptb != -1 && *orgptb != 5 && *orgptb != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgptb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*rsstb != -1 && *rsstb != 0 && *rsstb != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsstb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rsptb != -1 && *rsptb != 4 && *rsptb != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsptb";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*orgste != -1 && *orgste != 0) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgste";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgche != -1 && *orgche != 0) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgche";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*orgpte != -1 && *orgpte != 1) {
/* Writing concatenation */
	i__1[0] = 6, a__1[0] = "Orgpte";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
    if (*rsste != 0 && *rsste != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsste";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rsche != 0 && *rsche != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rsche";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    if (*rspte != 4 && *rspte != 5 && *rspte != 1) {
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = "Rspte";
	i__1[1] = 29, a__1[1] = invmsg;
	s_cat(ch__2, a__1, i__1, &c__2, 34L);
	unmsg_(ch__2, 34L);
    }
    tcscir_(orgstb, &c_n1, orgptb, strst1, &intp1, 200L);
    tcscir_(rsstb, &c_n1, rsptb, strst2, &intp2, 200L);
    tcscir_(orgste, orgche, orgpte, strst3, &intp3, 200L);
    tcscir_(rsste, rsche, rspte, strst4, &intp4, 200L);
/* Test condition number */
    tcsz = itrim_(tcnum, tcnum_len);
/* generating the string test condition used in setmsg */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 95, a__2[0] = "<Change structure identifier and references> wi"
	    "th the precondition being (original structure = ";
#else /* NO_PROTO */
    i__2[0] = 95, a__2[0] = "<Change structure identifier and references> wi\
th the precondition being (original structure = ";
#endif /* NO_PROTO */
    i__2[1] = intp1, a__2[1] = strst1;
    i__2[2] = 31, a__2[2] = " and the resulting structure = ";
    i__2[3] = intp2, a__2[3] = strst2;
#ifndef NO_PROTO
    i__2[4] = 49, a__2[4] = ") should yield the expected results of (origina"
	    "l ";
#else /* NO_PROTO */
    i__2[4] = 49, a__2[4] = ") should yield the expected results of (origina\
l ";
#endif /* NO_PROTO */
    i__2[5] = 12, a__2[5] = "structure = ";
    i__2[6] = intp3, a__2[6] = strst3;
    i__2[7] = 15, a__2[7] = " and resulting ";
    i__2[8] = 12, a__2[8] = "structure = ";
    i__2[9] = intp4, a__2[9] = strst4;
#ifndef NO_PROTO
    i__2[10] = 47, a__2[10] = ") after execution of the function as stated b"
	    "y ";
#else /* NO_PROTO */
    i__2[10] = 47, a__2[10] = ") after execution of the function as stated b\
y ";
#endif /* NO_PROTO */
    i__2[11] = 15, a__2[11] = "test condition ";
    i__2[12] = tcsz, a__2[12] = tcnum;
    i__2[13] = 8, a__2[13] = " of the ";
    i__2[14] = 12, a__2[14] = "truth table.";
    s_cat(msgbuf, a__2, i__2, &c__15, 900L);
    msgsz = itrim_(msgbuf, 900L);
    setmsg_("1", msgbuf, 1L, msgsz);
/* subroutine to set the initial state of the CSS */
    stdcss_();
/* when necessary, initialize the open, close status of the specific */
/* structure */
    if (*orgstb == 0) {
	if (*rsstb == 0) {
	    unmsg_("Bad pre-condition: both original and resulting OPEN.", 
		    52L);
	} else {
	    nopst (orgid);
	}
    } else {
	if (*rsstb == 0) {
	    nopst (resid);
	}
    }
/* when necessary intialize the posting status of the specific structure 
*/
    if (*orgptb == 5) {
	npost (&globnu_1.wkid, orgid, &orgpri);
    }
    if (*rsptb == 4) {
	npost (&globnu_1.wkid, resid, &respri);
    }
/* Formulate a string indicating the element types and contents for */
/* the original structure, before execution of function. */
    elstr_(orgid, strg, 300L);
    ncstir (orgid, resid);
/* get actual original status */
    actst_(orgid, strg, orgche, &opstra, &contok, &pststa, &pstpri, 300L);
/* comparison of the original expected state to the actual state */
    if (opstra == *orgste && contok && pststa == *orgpte) {
/* OK so far - do nothing */
    } else {
/* no need to check priority, since original should always be unposted
 */
/* or non-existent */
	fail_();
	inmsg_("The original structure status is incorrect.", 43L);
	goto L750;
    }
/* get actual resulting status */
    actst_(resid, strg, rsche, &opstra, &contok, &pststa, &pstpri, 300L);
/* comparison of the resulting expected state to the actual state */
    if (opstra == *rsste && contok) {
/* OK so far - do nothing */
    } else {
	fail_();
	inmsg_("The resulting structure open status or contents is incorrect."
		, 61L);
	goto L750;
    }
    if (*rspte == 4) {
	L__1 = pststa == 0 && pstpri == respri;
	ifpf_(&L__1);
    } else if (*rspte == 5) {
	L__1 = pststa == 0 && pstpri == orgpri;
	ifpf_(&L__1);
    } else if (*rspte == 1) {
	L__1 = pststa == 1;
	ifpf_(&L__1);
    }
/* generate a test condition string dealing with the state of the CSS. */
L750:
/* Writing concatenation */
#ifndef NO_PROTO
    i__3[0] = 95, a__3[0] = "<Change structure identifier and references> wi"
	    "th the precondition being (original structure = ";
#else /* NO_PROTO */
    i__3[0] = 95, a__3[0] = "<Change structure identifier and references> wi\
th the precondition being (original structure = ";
#endif /* NO_PROTO */
    i__3[1] = intp1, a__3[1] = strst1;
    i__3[2] = 27, a__3[2] = " and resulting structure = ";
    i__3[3] = intp2, a__3[3] = strst2;
    i__3[4] = 43, a__3[4] = ") should change the contents of the CSS in ";
    i__3[5] = 40, a__3[5] = "accordance with the substitution of the ";
    i__3[6] = 38, a__3[6] = "resulting identifier for the original ";
    i__3[7] = 11, a__3[7] = "identifier.";
    s_cat(msgbuf, a__3, i__3, &c__8, 900L);
    csssz = itrim_(msgbuf, 900L);
    setmsg_("1 7 8", msgbuf, 5L, csssz);
    L__1 = csseq_(excss, excss_len);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstcir_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01.03/tcscir                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01.03/elstr                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int elstr_(integer *strid, char *strg, ftnlen strg_len)
#else /* NO_PROTO */
/* Subroutine */ int elstr_(strid, strg, strg_len)
integer *strid;
char *strg;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    icilist ici__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer rl, str;
    static real rlar[50];
    static integer intg, strl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *, integer *, char *, ftnlen), ncmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeco (), ncmsg_();
#endif /* NO_PROTO */
    static integer rllen, intar[50], elpos, stlen;
    static char strar[80*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqets (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqets (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, intlen, nxchar, eltype, iexist;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/*     Input Parameter: */
/*     INTEGER strid              structure identifier */
/*     Output Parameter: */
/*     CHARACTER strg             string identifying element types */
/*                                and contents for strid */
/*  Elstr returns the character string STRG which contains integer-like */

/*  substrings separated by commas. The substrings of STRG represent an */

/*  ordered listing of label identifiers and execute structure identifiers
 */
/*  used to indicate the structure element positions of a particular */
/*  structure in the network. */
/*  e.g. The structure 110 creates STRG = "66, 111, 66, 120, 67, 901" */
/*             <open structure> 110 */
/*             <execute structure> 111 */
/*             <execute structure> 120 */
/*             <label> 901 */
/*             <close structure> */
/* PHIGS enumeration parameter for PEEXST and PELB */
/* structure status indicator   non-existent, empty,      non-empty */
/* array length parameter values */
/* initialize values */
    s_copy(strg, " ", strg_len, 1L);
    nxchar = 1;
    elpos = 1;
/* check the status of the structure */
    nqstst (strid, &errind, &iexist);
    chkinq_("pqstst", &errind, 6L);
    if (iexist == 0 || iexist == 1) {
	return 0;
    }
/* create the string STRG for the network structure STRID */
L900:
    nqets (strid, &elpos, &errind, &eltype, &intlen, &rllen, &stlen);
    if (errind != 0) {
	goto L950;
    }
    nqeco (strid, &elpos, &c__50, &c__50, &c__50, &errind, &intg, intar, &rl, 
	    rlar, &str, strl, strar, 80L);
    chkinq_("pqeco", &errind, 5L);
    if (eltype == 66 || eltype == 67) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 3;
	ici__1.iciunit = strg + (nxchar - 1);
	ici__1.icifmt = "(I2, A)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&eltype, (ftnlen)sizeof(integer));
	do_fio(&c__1, ",", 1L);
	e_wsfi();
	nxchar += 3;
    } else {
	ncmsg_("Problem with the element type in subroutine elstr.", 50L);
    }
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 4;
    ici__1.iciunit = strg + (nxchar - 1);
    ici__1.icifmt = "(I3, A)";
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&intar[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, ",", 1L);
    e_wsfi();
    nxchar += 4;
    ++elpos;
    goto L900;
L950:
    i__1 = nxchar - 2;
    s_copy(strg + i__1, " ", strg_len - i__1, 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* elstr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.01.03/actst                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int actst_(integer *acstid, char *strg, integer *expcon, 
	integer *opstra, logical *contok, integer *pststa, real *pstpri, 
	ftnlen strg_len)
#else /* NO_PROTO */
/* Subroutine */ int actst_(acstid, strg, expcon, opstra, contok, pststa, 
	pstpri, strg_len)
integer *acstid;
char *strg;
integer *expcon, *opstra;
logical *contok;
integer *pststa;
real *pstpri;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer idum2;
    static real rdum1;
    static integer idstr, strid, stype, pstlt;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, iexist;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern logical strcon_();
#endif /* NO_PROTO */
    static integer postnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *), 
	    nqpost (integer *, integer *, integer *, integer *, integer *, 
	    real *), nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst (), nqpost (), nqstst ();
#endif /* NO_PROTO */

/*     Input Parameters : */
/*     INTEGER   acstid   structure identifier */
/*     CHARACTER strg     string identifying expected element type */
/*                        and content for structure acstid */
/*     INTEGER   expcon   expected contents: (NOEXE, NORG, NEMP) */
/*     Output Parameters: */
/*    INTEGER opstra     open structure indicator     (NOEXE, NOPEN, NCLOS
)*/
/*     LOGICAL contok     structure contents as expected */
/*     INTEGER pststa     posted structure indicator   (NOEXE, NPST, NNPT)
 */
/*     INTEGER pstpri     posted structure priority */
/* ACTST returns values indicating if a structure is non-existent */
/* open, closed, empty, original, and posted, not posted. */
/* open-structure status: */
/*                none-open   open-structure */
/* structure status indicator: */
/*                non-existent,  empty,      non-empty */
/* Enumeration values for subroutine parameters: */
/*   structure state: non-existent   opened       closed */
/*   structure posted state: */
/*                    structure posted     structure not posted */
/*   structure reference status: */
/*                    referenced  not referenced */
/*   structure contents: */
/*                    empty     original  bad-contents */
/* determine if a structure is empty, non-existent, has the original */
/* contents, or none of these. */
    nqstst (acstid, &errind, &iexist);
    chkinq_("pqstst", &errind, 6L);
    if (iexist == 0) {
/* non-existent */
	*opstra = -1;
	*contok = *expcon == -1;
	*pststa = -1;
#ifndef NO_PROTO
	*pstpri = 0.f;
#else /* NO_PROTO */
	*pstpri = (float)0.;
#endif /* NO_PROTO */
	return 0;
    }
/* set CONTOK = contents OK */
    *contok = *expcon == 0 && iexist == 1 || *expcon == 1 && strcon_(acstid, 
	    strg, strg_len);
/* determine if a structure is opened or closed */
    nqopst (&errind, &stype, &idstr);
    chkinq_("pqopst", &errind, 6L);
    if (stype == 1 && idstr == *acstid) {
	*opstra = 0;
    } else {
	*opstra = 1;
    }
/* determine if a structure is posted or not */
    *pststa = 1;
    nqpost (&globnu_1.wkid, &c__0, &errind, &postnm, &idum2, &rdum1);
    chkinq_("pqpost", &errind, 6L);
    i__1 = postnm;
    for (pstlt = 1; pstlt <= i__1; ++pstlt) {
	nqpost (&globnu_1.wkid, &pstlt, &errind, &idum2, &strid, pstpri);
	chkinq_("pqpost", &errind, 6L);
	if (strid == *acstid) {
	    *pststa = 0;
	    goto L210;
	}
/* L200: */
    }
L210:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* actst_ */

