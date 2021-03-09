#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET STRING MODE - set string device operating mode and echo-
     ing state

  FORTRAN Syntax
     SUBROUTINE psstm ( WKID, STDNR, MODE, ESW )
     INTEGER     WKID              workstation identifier
     INTEGER     STDNR             string device number
     INTEGER     MODE              operating mode (PREQU, PSAMPL, PEVENT)
     INTEGER     ESW               echo switch (PNECHO, PECHO)
**************************************************************************/
#ifdef NO_PROTO
nsstm (wkid, stdnr, mode, esw)
   integer      *wkid,
            *stdnr,
            *mode,
            *esw;
#else
nsstm (integer *wkid, integer *stdnr, integer *mode, integer *esw)
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
     pset_string_mode ( ws, dev, mode, echo )
     Pint        ws;               workstation identifier
     Pint        dev;              string device number
     Pop_mode    mode;             operating mode
     Pecho_switch                  echo;echo switch
**************************************************************************/

   pset_string_mode ((Pint) *wkid, (Pint) *stdnr, op_mode, echo);
}
