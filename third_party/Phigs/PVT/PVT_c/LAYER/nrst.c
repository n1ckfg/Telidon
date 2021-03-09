#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REDRAW ALL STRUCTURES - redisplay all structures  posted  to
     workstation

  FORTRAN Syntax
     SUBROUTINE prst ( WKID, COFL )
     INTEGER     WKID              workstation identifier
     INTEGER     COFL              control flag (PCONDI, PALWAY)
**************************************************************************/
#ifdef NO_PROTO
nrst (wkid, cofl)
   integer      *wkid,
            *cofl;
#else
nrst (integer *wkid, integer *cofl)
#endif
{
   Pctrl_flag control_flag;

   control_flag = *cofl;
   switch (*cofl)
   {
   case 0:
      control_flag = PFLAG_COND;
      break;
   case 1:
      control_flag = PFLAG_ALWAYS;
      break;
   }

/**************************************************************************
  C Syntax
     void
     predraw_all_structs ( ws, control_flag )
     Pint        ws;               workstation identifier
     Pctrl_flag  control_flag;     controls the redraw of the structures
**************************************************************************/

   predraw_all_structs ((Pint) *wkid, control_flag);
}
