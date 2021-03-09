#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET STROKE MODE - set stroke device operating mode and echo-
     ing state

  FORTRAN Syntax
     SUBROUTINE psskm ( WKID, SKDNR, MODE, ESW )
     INTEGER     WKID              workstation identifier
     INTEGER     SKDNR             stroke device number
     INTEGER     MODE              operating mode (PREQU, PSAMPL, PEVENT)
     INTEGER     ESW               echo switch (PNECHO, PECHO)
**************************************************************************/
#ifdef NO_PROTO
nsskm (wkid, skdnr, mode, esw)
   integer      *wkid,
            *skdnr,
            *mode,
            *esw;
#else
nsskm (integer *wkid, integer *skdnr, integer *mode, integer *esw)
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
     pset_stroke_mode ( ws, dev, mode, echo )
     Pint        ws;               workstation identifier
     Pint        dev;              stroke device number
     Pop_mode    mode;             operating mode
     Pecho_switch                  echo;echo switch
**************************************************************************/

   pset_stroke_mode ((Pint) *wkid, (Pint) *skdnr, op_mode, echo);
}
