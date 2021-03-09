#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE HLHSR MODE - obtain workstation's  hidden  line  and
     hidden surface removal (HLHSR) mode

  FORTRAN Syntax
     SUBROUTINE pqhrm ( WKID, ERRIND, HUPD, CHRM, RHRM )
     INTEGER    WKID            workstation identifier
     INTEGER    ERRIND          OUT error indicator
     INTEGER    HUPD            OUT HLHSR mode update state (PNPEND, PPEND)
     INTEGER    CHRM            OUT current HLHSR mode
     INTEGER    RHRM            OUT requested HLHSR mode
**************************************************************************/
#ifdef NO_PROTO
nqhrm (wkid, errind, hupd, chrm, rhrm)
   integer  *wkid,
            *errind,
            *hupd,
            *chrm,
            *rhrm;
#else
nqhrm (integer *wkid, integer *errind, integer *hupd, 
       integer *chrm, integer *rhrm)
#endif
{
   Pint      cur_mode, req_mode, cerror;          
   Pupd_st   state;
/**************************************************************************
  C Syntax
     void
     pinq_hlhsr_mode ( ws, errind, state, cur_mode, req_mode )
     Pint       ws;             workstation identifier
     Pint        *errind;          OUT error indicator
     Pupd_st    *state;         OUT HLHSR update state
     Pint       *cur_mode;      OUT current HLHSR mode
     Pint       *req_mode;      OUT requested HLHSR mode
**************************************************************************/

   pinq_hlhsr_mode ((Pint) *wkid, &cerror, &state, &cur_mode, &req_mode);
   *chrm = cur_mode;
   *rhrm = req_mode;
   *errind = cerror;

   *hupd = state;
   if (state == PUPD_NOT_PEND)
      *hupd = 0;
   else if (state == PUPD_PEND)
      *hupd = 1;
}
