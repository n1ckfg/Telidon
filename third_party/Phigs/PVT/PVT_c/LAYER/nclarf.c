#include <phigs.h>
#include "f2c.h"

/************************************************************
NAME
     CLOSE ARCHIVE FILE - close named archive file

  FORTRAN Syntax
     SUBROUTINE pclarf ( AFID )
     INTEGER     AFID              archive file identifier
************************************************************/
#ifdef NO_PROTO
nclarf (afid)
   integer      *afid;
#else
nclarf (integer *afid)
#endif
{

/************************************************************
  C Syntax
     void
     pclose_ar_file ( archive_id )
     Pint        archive_id;       archive identifier
************************************************************/

   pclose_ar_file ((Pint) *afid);
}
