#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET HLHSR MODE - enable or disable hidden  line  and  hidden
     surface removal (HLHSR) on workstation

  FORTRAN Syntax
     SUBROUTINE pshrm ( WKID, HRM )
     INTEGER     WKID              workstation identifier
     INTEGER     HRM               HLHSR mode
**************************************************************************/
#ifdef NO_PROTO
nshrm (wkid, hrm)
   integer      *wkid,
            *hrm;
#else
nshrm (integer *wkid, integer *hrm)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_hlhsr_mode ( ws, mode )
     Pint        ws;               workstation identifier
     Pint        mode;             HLHSR mode
**************************************************************************/

   pset_hlhsr_mode ((Pint) *wkid, (Pint) *hrm);
}
