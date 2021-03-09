/* sigmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__5 = 5;

#ifndef NO_PROTO
/* Subroutine */ int sigmsg_(integer *perrsg, char *funcnm, char *msg, ftnlen 
	funcnm_len, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int sigmsg_(perrsg, funcnm, msg, funcnm_len, msg_len)
integer *perrsg;
char *funcnm, *msg;
ftnlen funcnm_len;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[5];
    integer i__1[3], i__2[5];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static char errch[6];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___2 = { 0, errch, 0, "(I6)", 6, 1 };


/*  SIGMSG formulates a message indicating that the function named by */
/*  funcnm signalled the error code perrsg. */
/*  Input parameters: */
/*    PERRSG : Error code to be incorporated in MSG */
/*    FUNCNM : Name of erroneous function to be incorporated in MSG */
/*  Output parameters: */
/*    MSG    : Resulting descriptive message */
    s_wsfi(&io___2);
    do_fio(&c__1, (char *)&(*perrsg), (ftnlen)sizeof(integer));
    e_wsfi();
    if (s_cmp(funcnm, " ", funcnm_len, 1L) == 0) {
/* Writing concatenation */
	i__1[0] = 41, a__1[0] = "No error signalled; current error code = ";
	i__1[1] = 6, a__1[1] = errch;
	i__1[2] = 1, a__1[2] = ".";
	s_cat(msg, a__1, i__1, &c__3, msg_len);
    } else {
/* Writing concatenation */
	i__2[0] = 9, a__2[0] = "Function ";
	i__2[1] = itrim_(funcnm, funcnm_len), a__2[1] = funcnm;
	i__2[2] = 22, a__2[2] = " signalled error code ";
	i__2[3] = 6, a__2[3] = errch;
	i__2[4] = 1, a__2[4] = ".";
	s_cat(msg, a__2, i__2, &c__5, msg_len);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sigmsg_ */

