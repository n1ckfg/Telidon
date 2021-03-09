#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION TRANSFORMATION 3 - obtain 3D workstation
     transformation

  FORTRAN Syntax
     SUBROUTINE pqwkt3 ( WKID, ERRIND, TUS, RWINDO, CWINDO, RVIEWP, CVIEWP )
     INTEGER     WKID              workstation identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     TUS               OUT workstation transformation update state
     REAL        RWINDO(6)         OUT requested workstation window in NPC
     REAL        CWINDO(6)         OUT current workstation window in NPC
     REAL        RVIEWP(6)         OUT requested workstation viewport in DC
     REAL        CVIEWP(6)         OUT current workstation viewport in DC
***************************************************************************/
#ifdef NO_PROTO
nqwkt3 (wkid, errind, tus, rwindo, cwindo, rviewp, cviewp)
   integer      *wkid,
            *errind,
            *tus;
   real     rwindo[],
             cwindo[],
             rviewp[],
             cviewp[];
#else
nqwkt3 (integer *wkid, integer *errind, integer *tus, real rwindo[], real cwindo[],
	real rviewp[], real cviewp[])
#endif
{
   Pint  cerror;
   Pupd_st   upd_st;
   Plimit3   req_win_lim;
   Plimit3   cur_win_lim;
   Plimit3   req_vp_lim;
   Plimit3   cur_vp_lim;
/**************************************************************************
  C Syntax
     void
     pinq_ws_tran3 ( ws, errind, upd_st, req_win_lim, cur_win_lim, req_vp_lim,
     cur_vp_lim)
     Pint        ws;               workstation identifier
     Pint        *errind;          OUT error indicator
     Pupd_st     *upd_st;          OUT update state
     Plimit3     *req_win_lim;     OUT requested workstation window
     Plimit3     *cur_win_lim;     OUT current workstation window
     Plimit3     *req_vp_lim;      OUT requested workstation viewport
     Plimit3     *cur_vp_lim;      OUT current workstation viewport
**************************************************************************/

   pinq_ws_tran3 ((Pint) *wkid, &cerror, &upd_st,
                  &req_win_lim, &cur_win_lim, &req_vp_lim, &cur_vp_lim);
   *errind = cerror;

   *tus = upd_st;
   if (upd_st == PUPD_NOT_PEND) *tus = 0;
   if (upd_st == PUPD_PEND)     *tus = 1;

   rwindo[0] = req_win_lim.x_min;
   rwindo[1] = req_win_lim.x_max;
   rwindo[2] = req_win_lim.y_min;
   rwindo[3] = req_win_lim.y_max;
   rwindo[4] = req_win_lim.z_min;
   rwindo[5] = req_win_lim.z_max;

   cwindo[0] = cur_win_lim.x_min;
   cwindo[1] = cur_win_lim.x_max;
   cwindo[2] = cur_win_lim.y_min;
   cwindo[3] = cur_win_lim.y_max;
   cwindo[4] = cur_win_lim.z_min;
   cwindo[5] = cur_win_lim.z_max;

   rviewp[0] = req_vp_lim.x_min;
   rviewp[1] = req_vp_lim.x_max;
   rviewp[2] = req_vp_lim.y_min;
   rviewp[3] = req_vp_lim.y_max;
   rviewp[4] = req_vp_lim.z_min;
   rviewp[5] = req_vp_lim.z_max;

   cviewp[0] = cur_vp_lim.x_min;
   cviewp[1] = cur_vp_lim.x_max;
   cviewp[2] = cur_vp_lim.y_min;
   cviewp[3] = cur_vp_lim.y_max;
   cviewp[4] = cur_vp_lim.z_min;
   cviewp[5] = cur_vp_lim.z_max;
}
