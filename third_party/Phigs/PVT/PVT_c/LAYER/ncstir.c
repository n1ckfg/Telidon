#include <phigs.h>
#include "f2c.h"

/***************************************************************************
NAME
     CHANGE STRUCTURE IDENTIFIER  AND  REFERENCES  -  change  the
     identifier assigned to a structure and all references to it

  FORTRAN Syntax
     SUBROUTINE pcstir ( OLDSID, NEWSID )
     INTEGER     OLDSID            original structure identifier
     INTEGER     NEWSID            resulting structure identifier
***************************************************************************/
#ifdef NO_PROTO
ncstir (oldsid, newsid)
   integer      *oldsid,
            *newsid;
#else
ncstir (integer *oldsid, integer *newsid)
#endif
{

/***************************************************************************
  C Syntax
     void
     pchange_struct_id_refs ( orig_struct_id, result_struct_id )
     Pint        orig_struct_id;   original structure id
     Pint        result_struct_id; result structure id
***************************************************************************/

   pchange_struct_id_refs ((Pint) *oldsid, (Pint) *newsid);
}
