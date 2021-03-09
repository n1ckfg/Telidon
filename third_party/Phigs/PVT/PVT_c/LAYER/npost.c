#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     POST STRUCTURE - assign structure network to workstation for
     display

  FORTRAN Syntax
     SUBROUTINE ppost ( WKID, STRID, PRIORT )
     INTEGER     WKID              workstation identifier
     INTEGER     STRID             structure identifier
     REAL        PRIORT            display priority
**************************************************************************/
#ifdef NO_PROTO
npost (wkid, strid, priort)
   integer      *wkid,
            *strid;
   real    *priort;
#else
npost (integer *wkid, integer *strid, real *priort)
#endif
{

/**************************************************************************
  C Syntax
     void
     ppost_struct ( ws_id, struct_id, priority )
     Pint        ws_id;            workstation identifier
     Pint        struct_id;        structure identifier
     Pfloat      priority;         priority
**************************************************************************/

   ppost_struct ((Pint) *wkid, (Pint) *strid, (Pfloat) *priort);
}
