#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET DISPLAY UPDATE STATE  -  set  workstation  deferral  and
     modification modes

  FORTRAN Syntax
     SUBROUTINE psdus ( WKID, DEFMOD, MODMOD )
     INTEGER     WKID              workstationidentifier
     INTEGER     DEFMOD            deferralmode
     INTEGER     MODMOD            modificationmode
**************************************************************************/
#ifdef NO_PROTO
nsdus (wkid, defmod, modmod)
   integer      *wkid,
            *defmod,
            *modmod;
#else
nsdus (integer *wkid, integer *defmod, integer *modmod)
#endif
{
   Pdefer_mode def_mode;
   Pmod_mode mod_mode;

   def_mode = *defmod;
   switch (*defmod)
   {
   case 0:
      def_mode = PDEFER_ASAP;
      break;
   case 1:
      def_mode = PDEFER_BNIG;
      break;
   case 2:
      def_mode = PDEFER_BNIL;
      break;
   case 3:
      def_mode = PDEFER_ASTI;
      break;
   case 4:
      def_mode = PDEFER_WAIT;
      break;
   }

   mod_mode = *modmod;
   switch (*modmod)
   {
   case 0:
      mod_mode = PMODE_NIVE;
      break;
   case 1:
      mod_mode = PMODE_UWOR;
      break;
   case 2:
      mod_mode = PMODE_UQUM;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_disp_upd_st ( ws, def_mode, mod_mode )
     Pint        ws;               workstation identifier
     Pdefer_mode def_mode;         deferral mode
     Pmod_mode   mod_mode;         modification mode
**************************************************************************/

   pset_disp_upd_st ((Pint) *wkid, def_mode, mod_mode);
}
