#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     RETRIEVE ALL  STRUCTURES  -  retrieve  all  structures  from
     specified archive file

  FORTRAN Syntax
     SUBROUTINE prast ( AFID )
     INTEGER     AFID              archive file identifier
**************************************************************************/
#ifdef NO_PROTO
nrast (afid)
   integer      *afid;
#else
nrast (integer *afid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pret_all_structs ( archive_id )
     Pint        archive_id;       archive identifier
**************************************************************************/

   pret_all_structs ((Pint) *afid);
}
