#include <phigs.h>
#include "f2c.h"
#include "f2c.h"
#include "fio.h"

/**************************************************************************
NAME
     OPEN PHIGS - open and initialize PHIGS environment

  FORTRAN Syntax
     SUBROUTINE popph ( ERRFIL, BUFA )
     INTEGER     ERRFIL            error message file
     INTEGER     BUFA              amount of memory units
**************************************************************************/
#ifdef NO_PROTO
nopph (errfil, mem_size)
   integer      *errfil,
            *mem_size;
#else
nopph (integer *errfil, integer *mem_size)
#endif
{
   char      err_file[80];
   char *strcpy ();

/*** Translate the integer FORTRAN unit # to
     the corresponding open "C" file using the
     table f__units  f2c keeps, use MXUNIT defined in fio.h
     to know how many units are available                     ***/

   if ((*errfil == 5) || (*errfil == 6))
      err_file[0] = (char) NULL;
   else if ((*errfil > MXUNIT) || (f__units[*errfil].ufd == NULL))
   {				/** It's Not Open **/
      name_file (errfil, 0, "err", err_file);
   } else
   {				/** It's Open **/
      strcpy (err_file, f__units[*errfil].ufnm);
   }


/**************************************************************************
  C Syntax
     void
     popen_phigs ( error_file, memory )
     char        *error_file;      name of error file
     size_t      memory;           NOT USED
**************************************************************************/

   popen_phigs (err_file, (size_t) *mem_size);
}
