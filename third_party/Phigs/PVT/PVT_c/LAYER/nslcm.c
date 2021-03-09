#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET LOCATOR MODE - set locator  device  operating  mode  and
     echoing state

  FORTRAN Syntax
     SUBROUTINE pslcm ( WKID, LCDNR, MODE, ESW )
     INTEGER     WKID              workstation identifier
     INTEGER     LCDNR             locator device number
     INTEGER     MODE              operating mode (PREQU, PSAMPL, PEVENT)
     INTEGER     ESW               echo switch (PNECHO, PECHO)
**************************************************************************/
#ifdef NO_PROTO
nslcm (wkid, lcdnr, mode, esw)
   integer      *wkid,
            *lcdnr,
            *mode,
            *esw;
#else
nslcm (integer *wkid, integer *lcdnr, integer *mode, integer *esw)
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
     pset_loc_mode ( ws, dev, mode, echo )
     Pint        ws;               workstation identifier
     Pint        dev;              locator device number
     Pop_mode    mode;             operating mode
     Pecho_switch                  echo;echo switch
**************************************************************************/

   pset_loc_mode ((Pint) *wkid, (Pint) *lcdnr, op_mode, echo);
}
