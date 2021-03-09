#include <phigs.h>
#include "f2c.h"

/***************************************************************************
NAME
     CHANGE STRUCTURE REFERENCES - change  all  references  to  a
     specified  structure  to  instead refer to another specified
     structure

  FORTRAN Syntax
     SUBROUTINE pcstrf ( OLDSID, NEWSID )
     INTEGER     OLDSID            original structure identifier
     INTEGER     NEWSID            resulting structure identifier
***************************************************************************/
#ifdef NO_PROTO
ncstrf (oldsid, newsid)
   integer      *oldsid,
            *newsid;
#else
ncstrf (integer *oldsid, integer *newsid)
#endif
{

/***************************************************************************
  C Syntax
     void
     pchange_struct_refs ( orig_struct_id, result_struct_id )
     Pint        orig_struct_id;   original structure id
     Pint        result_struct_id; result structure id
***************************************************************************/

   pchange_struct_refs ((Pint) *oldsid, (Pint) *newsid);
}
