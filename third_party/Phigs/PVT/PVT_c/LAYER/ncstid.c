#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     CHANGE  STRUCTURE  IDENTIFIER  -   change   the   identifier
     assigned to a structure

  FORTRAN Syntax
     SUBROUTINE pcstid ( OLDSID, NEWSID )
     INTEGER     OLDSID            original structure identifier
     INTEGER     NEWSID            resulting structure identifier
**************************************************************************/
#ifdef NO_PROTO
ncstid (oldsid, newsid)
   integer      *oldsid,
            *newsid;
#else
ncstid (integer *oldsid, integer *newsid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pchange_struct_id ( orig_struct_id, result_struct_id )
     Pint        orig_struct_id;   original structure id
     Pint        result_struct_id; result structure id
**************************************************************************/

   pchange_struct_id ((Pint) *oldsid, (Pint) *newsid);
}
