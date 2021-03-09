#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET CHOICE MODE - set choice device operating mode and echo-
     ing state

  FORTRAN Syntax
     SUBROUTINE pschm ( WKID, CHDNR, MODE, ESW )
     INTEGER     WKID              workstation identifier
     INTEGER     CHDNR             choice device number
     INTEGER     MODE              operating mode (PREQU, PSAMPL, PEVENT)
     INTEGER     ESW               echo switch (PNECHO, PECHO)
**************************************************************************/
#ifdef NO_PROTO
nschm (wkid, chdnr, mode, esw)
   integer      *wkid,
            *chdnr,
            *mode,
            *esw;
#else
nschm (integer *wkid, integer *chdnr, integer *mode, integer *esw)
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
     pset_choice_mode ( ws, dev, mode, echo )
     Pint        ws;               workstation identifier
     Pint        dev;              choice device number
     Pop_mode    mode;             operating mode
     Pecho_switch                  echo;echo switch
**************************************************************************/

   pset_choice_mode ((Pint) *wkid, (Pint) *chdnr, op_mode, echo);
}
