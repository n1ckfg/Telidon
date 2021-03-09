/* tstcid.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

