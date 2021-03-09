#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION TRANSFORMATION-  obtain  2D  workstation
     transformation

  FORTRAN Syntax
     SUBROUTINE pqwkt ( WKID, ERRIND, TUS, RWINDO, CWINDO, RVIEWP, CVIEWP )
     INTEGER     WKID              workstation identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     TUS               OUT workstation transformation update state
     REAL        RWINDO(4)         OUT requested workstation window in NPC
     REAL        CWINDO(4)         OUT current workstation window in NPC
     REAL        RVIEWP(4)         OUT requested workstation viewport in DC
     REAL        CVIEWP(4)         OUT current workstation viewport in DC
**************************************************************************/
#ifdef NO_PROTO
nqwkt (wkid, errind, tus, rwindo, cwindo, rviewp, cviewp)
   integer      *wkid,
            *errind,
            *tus;
   real     rwindo[],
             cwindo[],
             rviewp[],
             cviewp[];
#else
nqwkt (integer *wkid, integer *errind, integer *tus, real rwindo[], real cwindo[],
       real rviewp[], real cviewp[])
#endif
{
   Pint  cerror;
   Pupd_st   upd_st;
   Plimit    req_win_lim;
   Plimit    cur_win_lim;
   Plimit    req_vp_lim;
   Plimit    cur_vp_lim;
/**************************************************************************
  C Syntax
     void
     pinq_ws_tran ( ws, errind, upd_st, req_win_lim, cur_win_lim, req_vp_lim, cur_vp_lim )
     Pint        ws;               workstation identifier
     Pint        *errind;          OUT error indicator
     Pupd_st     *upd_st;          OUT update state
     Plimit      *req_win_lim;     OUT requested workstation window
     Plimit      *cur_win_lim;     OUT current workstation window
     Plimit      *req_vp_lim;      OUT requested workstation viewport
     Plimit      *cur_vp_lim;      OUT current workstation viewport
**************************************************************************/

   pinq_ws_tran ((Pint) *wkid, &cerror, &upd_st,
                 &req_win_lim, &cur_win_lim, &req_vp_lim, &cur_vp_lim);
   *errind = cerror;

   *tus = upd_st;
   if (upd_st == PUPD_NOT_PEND) *tus = 0;
   if (upd_st == PUPD_PEND)     *tus = 1;

   rwindo[0] = req_win_lim.x_min;
   rwindo[1] = req_win_lim.x_max;
   rwindo[2] = req_win_lim.y_min;
   rwindo[3] = req_win_lim.y_max;

   cwindo[0] = cur_win_lim.x_min;
   cwindo[1] = cur_win_lim.x_max;
   cwindo[2] = cur_win_lim.y_min;
   cwindo[3] = cur_win_lim.y_max;

   rviewp[0] = req_vp_lim.x_min;
   rviewp[1] = req_vp_lim.x_max;
   rviewp[2] = req_vp_lim.y_min;
   rviewp[3] = req_vp_lim.y_max;

   cviewp[0] = cur_vp_lim.x_min;
   cviewp[1] = cur_vp_lim.x_max;
   cviewp[2] = cur_vp_lim.y_min;
   cviewp[3] = cur_vp_lim.y_max;
}
