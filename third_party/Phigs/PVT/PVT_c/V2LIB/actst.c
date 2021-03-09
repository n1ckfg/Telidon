/* actst.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;

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

