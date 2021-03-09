#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     DELETE ALL STRUCTURES FROM ARCHIVE - delete  all  structures
     from an archive file

  FORTRAN Syntax
     SUBROUTINE pdasar ( AFID )
     INTEGER     AFID              archive file identifier
**************************************************************************/
#ifdef NO_PROTO
ndasar (afid)
   integer      *afid;
#else
ndasar (integer *afid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pdel_all_structs_ar ( archive_id )
     Pint        archive_id;       archive identifier
**************************************************************************/

   pdel_all_structs_ar ((Pint) *afid);
}
