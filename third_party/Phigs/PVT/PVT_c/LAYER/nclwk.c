#include <phigs.h>
#include "f2c.h"

/***********************************************************
NAME
     CLOSE WORKSTATION -  close specified workstation

  FORTRAN Syntax
     SUBROUTINE pclwk ( WKID )
     INTEGER     WKID              workstation identifier
***********************************************************/
#ifdef NO_PROTO
nclwk (wkid)
   integer      *wkid;
#else
nclwk (integer *wkid)
#endif
{

/***********************************************************
  C Syntax
     void
     pclose_ws ( ws_id )
     Pint        ws_id;            workstation identifier
***********************************************************/

   pclose_ws ((Pint) *wkid);
}
