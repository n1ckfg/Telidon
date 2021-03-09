#include <phigs.h>
#include "f2c.h"
#include "f2c.h"
#include "fio.h"

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw,
       errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_


/**************************************************************************
NAME
     ERROR HANDLING

  FORTRAN Syntax

     SUBROUTINE perhnd ( ERRNR, FCTID, ERRFIL )
     INTEGER     ERRNR             error number
     INTEGER     FCTID             function identification
     INTEGER     ERRFIL            error file

**************************************************************************/

#ifdef NO_PROTO
nerhnd (errnr, fctid, errfil)
   integer       *errnr,
             *fctid,
             *errfil;
#else
nerhnd (integer *errnr, integer *fctid, integer *errfil)
#endif

{
   char       fname[80];
   int        i;

   static void dummy_handler (),
              (*current_handler_1)(), (*current_handler_2)();

    /** By default, name the error file **/
      name_file (errnr, 0, "err", fname);

/*** Now, Search through the list f2c keeps on open
     Fortran units searching for the LUN  (errfil),
     then get the file name associated with it for C.    ***/

   if (*errfil != -666)  /* Bogus file == 666  */
   {
      for (i = 1; i < MXUNIT; i++)
      {
	 if ((f__units[i].uinode != 0) && (f__units[i].ufnm != 0))
	 {
	        strcpy (fname,f__units[i].ufnm);
	        break;
	 }
      }
   }
   else
      strcpy (fname,"-666");

/**************************************************************************

NAME
     ERROR HANDLING - default PHIGS error handling routine

SYNOPSIS
  C Syntax
     void
     perr_hand ( errnum, funcnum, fname )
     Pint        errnum;           error number
     Pint        funcnum;          number of function that detected the error
     char        *fname;           name of error file

**************************************************************************/

/*  Use set_error_handler to get the current error handler; simulate
    action of normal error handling system.  In PVT code, this should
    usually wind up pointing to pvt_perr_hand (user-defined), not
    the system handler, except for tests of error handling.  */

   pset_err_hand (dummy_handler,     &current_handler_1);
   pset_err_hand (current_handler_1, &current_handler_2);

   (*current_handler_1) ((Pint) *errnr, (Pint) *fctid, fname );

}

static void dummy_handler ()
{
   printf ("Dummy handler here - major problem in nerhnd if you see this.\n");
}
