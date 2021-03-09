#include <phigs.h>
#include "f2c.h"

/*******************************************************************
NAME
     ARCHIVE ALL STRUCTURES -  archive  all  structures  into  an
     archive file

  FORTRAN Syntax
     SUBROUTINE parast ( AFID )
     INTEGER     AFID              archive file identifier
*******************************************************************/
#ifdef NO_PROTO
narast (afid)
   integer      *afid;
#else
narast (integer *afid)
#endif
{

/*******************************************************************
  C Syntax
     void
     par_all_structs ( archive_id )
     Pint        archive_id;       archive identifier
*******************************************************************/

   par_all_structs ((Pint) *afid);

}
