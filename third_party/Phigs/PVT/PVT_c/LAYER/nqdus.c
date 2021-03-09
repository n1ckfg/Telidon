#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE DISPLAY UPDATE STATE - obtain current display update
     state

  FORTRAN Syntax
     SUBROUTINE pqdus ( WKID, ERRIND, DEFMOD, MODMOD, DEMPTY, STOFVR )
     INTEGER     WKID              workstation identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     DEFMOD            OUT deferral mode
     INTEGER     MODMOD            OUT modification mode
     INTEGER     DEMPTY            OUT display surface empty
     INTEGER     STOFVR            OUT state of visual representation
**************************************************************************/
#ifdef NO_PROTO
nqdus (wkid, errind, defmod, modmod, dempty, stofvr)
   integer      *wkid,
            *errind,
            *defmod,
            *modmod,
            *dempty,
            *stofvr;
#else
nqdus (integer *wkid, integer *errind, integer *defmod, integer *modmod, integer *dempty, integer *stofvr)
#endif
{
   Pdefer_mode def_mode;
   Pmod_mode mod_mode;
   Pdisp_surf_empty disp_empty;
   Pvisual_st state;
   Pint cerror;

/**************************************************************************
  C Syntax
     void
     pinq_disp_upd_st ( ws, errind, def_mode, mod_mode, display_empty, state )
     Pint              ws;          workstation identifier
     Pint             *errind;      OUT error indicator
     Pdefer_mode      *def_mode;    OUT deferral mode
     Pmod_mode        *mod_mode;    OUT modification mode
     Pdisp_surf_empty *disp_empty   OUT display surface empty
     Pvisual_st       *state;       OUT state of visual representation
**************************************************************************/

   pinq_disp_upd_st ((Pint) *wkid,
      &cerror, &def_mode, &mod_mode, &disp_empty, &state);
   *errind = cerror;

   *defmod = def_mode;
   if (def_mode == PDEFER_ASAP) *defmod = 0;
   if (def_mode == PDEFER_BNIG) *defmod = 1;
   if (def_mode == PDEFER_BNIL) *defmod = 2;
   if (def_mode == PDEFER_ASTI) *defmod = 3;
   if (def_mode == PDEFER_WAIT) *defmod = 4;

   *modmod = mod_mode;
   if (mod_mode == PMODE_NIVE) *modmod = 0;
   if (mod_mode == PMODE_UWOR) *modmod = 1;
   if (mod_mode == PMODE_UQUM) *modmod = 2;

   *dempty = disp_empty;
   if (disp_empty == PSURF_EMPTY)     *dempty = 1;
   if (disp_empty == PSURF_NOT_EMPTY) *dempty = 0;

   *stofvr = state;
   if (state == PVISUAL_ST_CORRECT)   *stofvr = 0;
   if (state == PVISUAL_ST_DEFER)     *stofvr = 1;
   if (state == PVISUAL_ST_SIMULATED) *stofvr = 2;
}
