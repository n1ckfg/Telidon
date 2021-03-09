#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE DEFAULT DISPLAY UPDATE STATE - inquire  the  default
     display update state for a specified workstation type

  FORTRAN Syntax
     SUBROUTINE pqddus ( WTYPE, ERRIND, DEFMOD, MODMOD )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     DEFMOD            OUT default value for deferral mode
     INTEGER     MODMOD            OUT default value for modification mode
**************************************************************************/
#ifdef NO_PROTO
nqddus (wtype, errind, defmod, modmod)
   integer      *wtype,
            *errind,
            *defmod,
            *modmod;
#else
nqddus (integer *wtype, integer *errind, integer *defmod, integer *modmod)
#endif
{
   Pdefer_mode def_mode;
   Pmod_mode mod_mode;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_def_disp_upd_st ( type, errind, def_mode, mod_mode )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pdefer_mode *def_mode;        OUT deferral mode
     Pmod_mode   *mod_mode;        OUT modification mode
**************************************************************************/

   pinq_def_disp_upd_st ((Pint) *wtype, &cerror, &def_mode, &mod_mode);
   *errind = cerror;

   *defmod = def_mode;
   switch (def_mode)
   {
   case PDEFER_ASAP:
      *defmod = 0;
      break;
   case PDEFER_BNIG:
      *defmod = 1;
      break;
   case PDEFER_BNIL:
      *defmod = 2;
      break;
   case PDEFER_ASTI:
      *defmod = 3;
      break;
   case PDEFER_WAIT:
      *defmod = 4;
      break;
   }

   *modmod = mod_mode;
   switch (mod_mode)
   {
   case PMODE_NIVE:
      *modmod = 0;
      break;
   case PMODE_UWOR:
      *modmod = 1;
      break;
   case PMODE_UQUM:
      *modmod = 2;
      break;
   }
}
