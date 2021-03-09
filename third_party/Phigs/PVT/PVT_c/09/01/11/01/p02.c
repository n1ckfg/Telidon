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

static integer c__2 = 2;
static real c_b3 = (float).5;
Pint  cur_error = 0, cur_function = 555;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01.11.01/02                        * */
/*  *    TEST TITLE : Set error handler                     * */
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
    static char emsg[300], emsg1[300], emsg2[300];
    extern /* Subroutine */ int endit_(), enderr_(), initgl_(), 
	    gterrm_(), setmsg_(), esetup_();
    static void my_err_handler();
    static void (*default_err_handler)();
    static void (*old_err_handler)();

    initgl_("09.01.11.01/02", 14L);
    esetup_(&c__2);

    ntx (&c_b3, &c_b3, "TEXT1", 5L);

    pset_err_hand (my_err_handler, &default_err_handler);
    ntx (&c_b3, &c_b3, "TEXT1", 5L);

    pset_err_hand (default_err_handler, &old_err_handler);
    ntx (&c_b3, &c_b3, "TEXT1", 5L);
    enderr_();  

    setmsg_("3", "<set error handler> returns default system error handler when \
called first time.", 1L, 80L);
    s_copy(emsg, "first call", 300L, 10L);
    gterrm_(&globnu_1.errfil, emsg, 300L);
    s_copy(emsg1, emsg, 300L, 300L);
    gterrm_(&globnu_1.errfil, emsg, 300L);
    s_copy(emsg2, emsg, 300L, 300L);
    L__1 = s_cmp(emsg1, emsg2, 300L, 300L) == 0;   
    ifpf_(&L__1);   

/*  wrap it up. */
    endit_();
} /* MAIN__ */


/*   my_err_handler is new error handler just for test purpose    */ 
void my_err_handler (error, function, err_file)
    Pint error;
    Pint function;
    char *err_file;
{
    cur_error = error;
    cur_function = function;
}
