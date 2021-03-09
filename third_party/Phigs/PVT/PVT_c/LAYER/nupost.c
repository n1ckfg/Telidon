#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     UNPOST STRUCTURE - unpost a  structure  from  the  specified
     workstation

  FORTRAN Syntax
     SUBROUTINE pupost ( WKID, STRID )
     INTEGER     WKID              workstation identifier
     INTEGER     STRID             structure identifier
**************************************************************************/
#ifdef NO_PROTO
nupost (wkid, strid)
   integer      *wkid,
            *strid;
#else
nupost (integer *wkid, integer *strid)
#endif
{

/**************************************************************************
  C Syntax
     void
     punpost_struct ( ws_id, struct_id )
     Pint        ws_id;            workstation identifier
     Pint        struct_id;        structure identifier
**************************************************************************/

   punpost_struct ((Pint) *wkid, (Pint) *strid);
}
