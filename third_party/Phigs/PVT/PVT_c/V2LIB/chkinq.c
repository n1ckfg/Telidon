/* chkinq.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__7 = 7;

#ifndef NO_PROTO
/* Subroutine */ int chkinq_(char *routnm, integer *ierrcd, ftnlen routnm_len)

#else /* NO_PROTO */
/* Subroutine */ int chkinq_(routnm, ierrcd, routnm_len)
char *routnm;
integer *ierrcd;
ftnlen routnm_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[7];
    integer i__1[7];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char buf[200], aerr[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int ncmsg_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ncmsg_();
    extern integer itrim_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___2 = { 0, aerr, 0, "(I9)", 9, 1 };


/*  Chkinq is used to check that inquire-functions have returned a value 
*/
/*  of zero as the error code.  It is normally called after invoking an */

/*  inquire which is being used incidentally, i.e., one which is NOT the 
*/
/*  object of interest of the test, but rather one whose returned values 
*/
/*  are needed to test OTHER functions.  Nonetheless, the failure of such 
*/
/*  an inquire is a failure of the implementation, since these inquires */

/*  are called only in circumstances when they should work. */
    if (*ierrcd == 0) {
	return 0;
    }
    s_wsfi(&io___2);
    do_fio(&c__1, (char *)&(*ierrcd), (ftnlen)sizeof(integer));
    e_wsfi();
/* Writing concatenation */
    i__1[0] = 20, a__1[0] = "Unexpected error in ";
    i__1[1] = itrim_(globch_1.pident, 40L), a__1[1] = globch_1.pident;
    i__1[2] = 14, a__1[2] = ", Function = \"";
    i__1[3] = routnm_len, a__1[3] = routnm;
    i__1[4] = 16, a__1[4] = "\", Error code = ";
    i__1[5] = 9, a__1[5] = aerr;
    i__1[6] = 1, a__1[6] = ".";
    s_cat(buf, a__1, i__1, &c__7, 200L);
    ncmsg_(buf, 200L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkinq_ */

