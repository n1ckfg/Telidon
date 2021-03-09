#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     UNPOST ALL STRUCTURES - unpost all structures posted to  the
     specified workstation

  FORTRAN Syntax
     SUBROUTINE pupast ( WKID )
     INTEGER     WKID              workstation identifier
**************************************************************************/
#ifdef NO_PROTO
nupast (wkid)
   integer      *wkid;
#else
nupast (integer *wkid)
#endif
{

/**************************************************************************
  C Syntax
     void
     punpost_all_structs ( ws_id )
     Pint        ws_id;            workstation identifier
**************************************************************************/

   punpost_all_structs ((Pint) *wkid);
}
