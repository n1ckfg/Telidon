#include <phigs.h>
#include "f2c.h"
#include "f2c.h"
#include "fio.h"

/**************************************************************************
NAME
     ERROR LOGGING - log errors on error file

  FORTRAN Syntax
     SUBROUTINE perlog ( ERRNR, FCTID, ERRFIL )
     INTEGER     ERRNR             error number
     INTEGER     FCTID             function identification
     INTEGER     ERRFIL            error file
**************************************************************************/
#ifdef NO_PROTO
nerlog (errnr, fctid, errfil)
   integer      *errnr,
            *fctid,
            *errfil;
#else
nerlog (integer *errnr, integer *fctid, integer *errfil)
#endif
{
   char      err_file[80];
   char     *strcpy();

/*** Translate the integer FORTRAN unit # to
     the corresponding open "C" file using the
     table f__units  f2c keeps, use MXUNIT defined in fio.h
     to know how many units are available                     ***/

   if ((*errfil > MXUNIT) || (f__units[*errfil].ufd == NULL))
   {				/** It's Not Open **/
      name_file (errfil, 0, "err", err_file);
   } else
   {				/** It's Open **/
      strcpy (err_file, f__units[*errfil].ufnm);
   }


/**************************************************************************
  C Syntax
     void
     perr_log ( errnum, funcnum, fname )
     Pint        errnum;           error number
     Pint        funcnum;          number of function that detected the error
     char        *fname;           name of error file
**************************************************************************/

   perr_log ((Pint) *errnr, (Pint) *fctid, err_file);
}
