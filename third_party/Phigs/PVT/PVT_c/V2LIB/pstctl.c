/* pstctl.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

#ifndef NO_PROTO
static real c_b6 = 0.f;
static real c_b8 = 1.f;
#else /* NO_PROTO */
static real c_b6 = (float)0.;
static real c_b8 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int pstctl_(integer *ctl)
#else /* NO_PROTO */
/* Subroutine */ int pstctl_(ctl)
integer *ctl;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer postat = 0;
#ifndef NO_PROTO
    static char act[4*4*5] = "n   " "Up  " "Ud  " "UpUd" "Pp  " "n   " "UdPp" 
	    "Ud  " "Pd  " "UpPd" "n   " "Up  " "PpPd" "Pd  " "Pp  " "n   " 
	    "Pd  " "UpPd" "UdPp" "Up  ";
#else /* NO_PROTO */
    static char act[4*4*5+1] = "n   Up  Ud  UpUdPp  n   UdPpUd  Pd  UpPdn   \
Up  PpPdPd  Pp  n   Pd  UpPdUdPpUp  ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static char doact[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int npost (integer *, integer *, real *), nupost (
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npost (), nupost ();
#endif /* NO_PROTO */

/*  PSTCTL controls the posting of structures. */
/*  CTL function */
/*  --- -------- */
/*   0  unpost both picture and dialogue structure */
/*   1  post picture only */
/*   2  post dialogue only */
/*   3  post both */
/*   4  switch picture/dialogue posting; dialogue if neither or both */
/*  POSTAT keeps track of current posting status: */
/*  POSTAT  status */
/*  ------  ------ */
/*     0    neither posted */
/*     1    picture posted */
/*     2    dialogue posted */
/*     3    both posted */
/*  action table: what to do based on POSTAT and CTL */
/*                POSTAT: 0         1        2        3 */
    s_copy(doact, act + (postat + (*ctl << 2) << 2), 4L, 4L);
    if (s_cmp(doact, "n", 4L, 1L) == 0) {
	return 0;
    }
    if (i_indx(doact, "Up", 4L, 2L) > 0) {
	nupost (&globnu_1.wkid, &dialog_1.pstrid);
    }
    if (i_indx(doact, "Ud", 4L, 2L) > 0) {
	nupost (&globnu_1.wkid, &dialog_1.dstrid);
    }
    if (i_indx(doact, "Pp", 4L, 2L) > 0) {
	npost (&globnu_1.wkid, &dialog_1.pstrid, &c_b6);
    }
    if (i_indx(doact, "Pd", 4L, 2L) > 0) {
	npost (&globnu_1.wkid, &dialog_1.dstrid, &c_b8);
    }
    if (*ctl == 4) {
	if (postat == 2) {
	    postat = 1;
	} else {
	    postat = 2;
	}
    } else {
	postat = *ctl;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pstctl_ */

