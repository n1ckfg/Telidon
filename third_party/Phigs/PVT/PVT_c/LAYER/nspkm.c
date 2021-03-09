#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PICK MODE - set pick device operating mode  and  echoing
     state

  FORTRAN Syntax
     SUBROUTINE pspkm ( WKID, PKDNR, MODE, ESW )
     INTEGER     WKID              workstation identifier
     INTEGER     PKDNR             pick device number
     INTEGER     MODE              operating mode (PREQU, PSAMPL, PEVENT)
     INTEGER     ESW               echo switch (PNECHO, PECHO)
**************************************************************************/
#ifdef NO_PROTO
nspkm (wkid, pkdnr, mode, esw)
   integer      *wkid,
            *pkdnr,
            *mode,
            *esw;
#else
nspkm (integer *wkid, integer *pkdnr, integer *mode, integer *esw)
#endif
{
   Pop_mode  op_mode;
   Pecho_switch echo;

   op_mode = *mode;
   switch (*mode)
   {
   case 0:
      op_mode = POP_REQ;
      break;
   case 1:
      op_mode = POP_SAMPLE;
      break;
   case 2:
      op_mode = POP_EVENT;
      break;
   }

   echo = *esw;
   switch (*esw)
   {
   case 0:
      echo = PSWITCH_NO_ECHO;
      break;
   case 1:
      echo = PSWITCH_ECHO;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_pick_mode ( ws, dev, mode, echo )
     Pint        ws;               workstation identifier
     Pint        dev;              pick device number
     Pop_mode    mode;             operating mode
     Pecho_switch                  echo;echo switch
**************************************************************************/

   pset_pick_mode ((Pint) *wkid, (Pint) *pkdnr, op_mode, echo);
}
