/* fort/06/02/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.02.02/tstvip                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstvip_(integer *spcpos, integer *refpos, integer *
	relpri, integer *ndvi)
#else /* NO_PROTO */
/* Subroutine */ int tstvip_(spcpos, refpos, relpri, ndvi)
integer *spcpos, *refpos, *relpri, *ndvi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
    static integer ivw;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer idum1;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareq_();
#endif /* NO_PROTO */
    static integer isend, irecv, refvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer spcvw, nspos, actord[500];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, curord[500], expord[500];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqevwi (integer *, integer *, integer *, 
	    integer *, integer *), nsvtip (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqevwi (), nsvtip ();
#endif /* NO_PROTO */

/*  TSTVIP tests the PSVTIP function by computing the correct */
/*  effect of the function call on the current list of view */
/*  indices, and comparing it with the actual result. */
/*  Pass or fail is issued as a result. */
/*  ------- INPUT PARAMETERS */
/*  spcpos     : position in current list of specified index */
/*  refpos     : position in current list of reference index */
/*  relpri     : relative priority of specified index */
/*  ndvi       : number of defined view indices */
/* relative input priority */
/* check array size is sufficient */
    if (500 < *ndvi) {
	unmsg_("Allocated array size in TSTVIP is too small.", 44L);
    }
/*  Use <inquire list of view indices> to determine */
/*        curord = current order */
    i__1 = *ndvi;
    for (ivw = 1; ivw <= i__1; ++ivw) {
	nqevwi (&globnu_1.wkid, &ivw, &errind, &idum1, &curord[ivw - 1]);
	chkinq_("pqevwi", &errind, 6L);
/* L100: */
    }
/* from parameters, calculate expord = expected order */
/*     nspos is new position of specified view index */
    nspos = *refpos;
    if (*spcpos < *refpos && *relpri == 0) {
	--nspos;
    } else if (*spcpos > *refpos && *relpri == 1) {
	++nspos;
    }
/* irecv and isend are receiving and sending positions in curord */
/* and expord, respectively. */
    irecv = 0;
    isend = 0;
L150:
    ++isend;
    ++irecv;
/* skip sending of old position of specified view */
    if (isend == *spcpos) {
	++isend;
    }
/* skip reception of new position of specified view */
    if (irecv == nspos) {
	++irecv;
    }
/* check if done with loop */
    if (isend > *ndvi || irecv > *ndvi) {
	goto L200;
    }
    expord[irecv - 1] = curord[isend - 1];
    goto L150;
L200:
/* fill in last slot */
    expord[nspos - 1] = curord[*spcpos - 1];
/*  establish identity (not just position) of specified and reference view
 */
    spcvw = curord[*spcpos - 1];
    refvw = curord[*refpos - 1];
/*  invoke <set view transformation input priority> using */
/*        spcvw, refvw, relpri */
    nsvtip (&globnu_1.wkid, &spcvw, &refvw, relpri);
/*  Use <inquire list of view indices> to determine */
/*        actord = actual order */
    i__1 = *ndvi;
    for (ivw = 1; ivw <= i__1; ++ivw) {
	nqevwi (&globnu_1.wkid, &ivw, &errind, &idum1, &actord[ivw - 1]);
	chkinq_("pqevwi", &errind, 6L);
/* L300: */
    }
/*  pass/fail depending on (actord = expord) */
    L__1 = iareq_(ndvi, actord, expord);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstvip_ */

