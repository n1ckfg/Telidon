#include <phigs.h>
#include "f2c.h"
#include "f2c.h"
#include "fio.h"

/**************************************************************************
NAME
     OPEN ARCHIVE FILE - open specified archive file

  FORTRAN Syntax
     SUBROUTINE poparf ( AFID, ARCFIL )
     INTEGER     AFID              archive file identifier
     INTEGER     ARCFIL            archive file name
**************************************************************************/
#ifdef NO_PROTO
noparf (afid, arcfil)
   integer      *afid,
            *arcfil;
#else
noparf (integer *afid, integer *arcfil)
#endif
{
   char      archive_file[80];
   char *strcpy ();
/*** Translate the integer FORTRAN unit # to
     the corresponding open "C" file using the
     table f__units  f2c keeps, use MXUNIT defined in fio.h
     to know how many units are available                     ***/


   if ((*arcfil > MXUNIT) || (f__units[*arcfil].ufd == NULL))
   {				/** It's Not Open **/
      name_file (arcfil, afid, "arc", archive_file);
   } else
   {				/** It's Open **/
      strcpy (archive_file, f__units[*arcfil].ufnm);
   }

/**************************************************************************
  C Syntax
     void
     popen_ar_file ( archive_id, archive_file )
     Pint        archive_id;       archive identifier
     char        *archive_file;    archive file name
**************************************************************************/

   popen_ar_file ((Pint) *afid, archive_file);
}
