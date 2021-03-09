/* p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"
#include "phigs.h"

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
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[600];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */
static integer c__1 = 1;
static real c_b3 = (float).5;
Pint  cur_error = 0, cur_function = 555;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01.11.01/01                        * */
/*  *    TEST TITLE : Function of <set error handler>       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/* Main program */ MAIN__()
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy();

    /* Local variables */
    extern /* Subroutine */ int ntx (), ifpf_();
    extern /* Subroutine */ int endit_(), enderr_(), initgl_(), 
	    setmsg_(), esetup_();
    static void my_err_handler();
    static void (*new_err_handler)();
    static void (*old_err_handler)();

    initgl_("09.01.11.01/01", 14L);
    esetup_(&c__1);

    ntx (&c_b3, &c_b3, "TEXT1", 5L);

    pset_err_hand (my_err_handler, &old_err_handler);
    ntx (&c_b3, &c_b3, "TEXT1", 5L);
    setmsg_("1", "<set error handler> sets PHIGS error handler to applicatio\
n defined error handler specified with parameter new error handling function."
, 1L, 135L);
    L__1 = cur_error == errinf_1.errsav[0] && cur_function == errinf_1.funsav[0];
    ifpf_(&L__1); 

    pset_err_hand (old_err_handler, &new_err_handler);
    ntx (&c_b3, &c_b3, "TEXT1", 5L);
    setmsg_("2", "<set error handler> returns previous error handling subroutine.", 1L, 63L);
    L__1 = errinf_1.errsav[0] == errinf_1.errsav[1] &&
           errinf_1.funsav[0] == errinf_1.funsav[1];
    ifpf_(&L__1);

/*  wrap it up. */
    endit_();
} /* MAIN__ */

/*    my_error_handler is new error handler just for test purpose  */
void my_err_handler (error, function, err_file)
    Pint error;
    Pint function;
    char *err_file;
{
    cur_error = error;
    cur_function = function;
}
