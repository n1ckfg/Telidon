/* echkz.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__2 = 2;
static integer c__180 = 180;
static integer c_n666 = -666;

#ifndef NO_PROTO
/* Subroutine */ int echkz_(integer *funcid)
#else /* NO_PROTO */
/* Subroutine */ int echkz_(funcid)
integer *funcid;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), nerhnd (integer *, 
	    integer *, integer *), nerlog (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_(), nerhnd (), nerlog ();
#endif /* NO_PROTO */

/*  ECHKZ does post-processing after an error-signalling function has */
/*  been called. */
/*  Input parameter: */
/*    FUNCID: numeric identifier of function that signalled error */
    if (errinf_1.usrerr == 1 || errinf_1.usrerr == 3) {
/*  user-defined error handling */
/*  make bogus entry in error table to mark end of function effect */
	nerhnd (&c__2, &c__180, &c_n666);
    } else {
/*  system-defined error handling */
/*  make bogus entry in error file to mark end of function effect */
	nerlog (&c__2, &c__180, &globnu_1.errfil);
    }
/*  fill table of expected error-signalling function identifiers */
    ++errinf_1.efcnt;
    errinf_1.efid[errinf_1.efcnt - 1] = *funcid;
    if (itrim_(errchr_1.curcon, 200L) > 150) {
	unmsg_("ECHKZ detected CURCON of excessive length.", 42L);
    }
    if (errinf_1.efcnt > 40) {
	unmsg_("ECHKZ detected CONTAB table overflow.", 37L);
    }
/*  fill table of condition descriptions */
    s_copy(errchr_1.contab + (errinf_1.efcnt - 1) * 150, errchr_1.curcon, 
	    150L, 200L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* echkz_ */

