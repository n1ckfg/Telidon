#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     UPDATE WORKSTATION - execute  deferred  workstation  actions
     and optionally correct the display

  FORTRAN Syntax
     SUBROUTINE puwk ( WKID, REGFL )
     INTEGER     WKID              workstation identifier
     INTEGER     REGFL             regeneration flag (PPOSTP, PPERFO)
**************************************************************************/
#ifdef NO_PROTO
nuwk (wkid, regfl)
   integer      *wkid,
            *regfl;
#else
nuwk (integer *wkid, integer *regfl)
#endif
{
   Pregen_flag regen_flag;

   regen_flag = *regfl;

   if (*regfl == 0)
      regen_flag = PFLAG_POSTPONE;
   if (*regfl == 1)
      regen_flag = PFLAG_PERFORM;

/**************************************************************************
  C Syntax
     void
     pupd_ws ( ws, regen_flag )
     Pint        ws;               workstation identifier
     Pregen_flag regen_flag;       when to do the regeneration
**************************************************************************/

   pupd_ws ((Pint) *wkid, regen_flag);
}
