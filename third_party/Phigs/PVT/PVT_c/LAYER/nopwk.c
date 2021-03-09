#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     OPEN WORKSTATION - open workstation of specified workstation
     type

  FORTRAN Syntax
     SUBROUTINE popwk ( WKID, CONID, WTYPE )
     INTEGER     WKID              workstation identifier
     INTEGER     CONID             connection identifier
     INTEGER     WTYPE             workstation type
**************************************************************************/
#ifdef NO_PROTO
nopwk (wkid, conid, wtype)
   integer      *wkid;
   integer      *conid;
   integer      *wtype;
#else
nopwk (integer *wkid, integer *conid, integer *wtype)
#endif
{

/**************************************************************************
  C Syntax
     void
     popen_ws ( wkid, conid, wtype )
     Pint        wkid;            workstation identifier
     void        *conid;         connection identifier
     Pint        wtype;          workstation type
**************************************************************************/
   popen_ws ((Pint) *wkid, (void *) conid, (Pint) *wtype);
}
