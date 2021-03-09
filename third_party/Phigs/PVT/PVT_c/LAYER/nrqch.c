#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REQUEST CHOICE - request operator interaction with specified
     choice device

  FORTRAN Syntax
     SUBROUTINE prqch ( WKID, CHDNR, STAT, CHNR )
     INTEGER     WKID              workstation identifier
     INTEGER     CHDNR             choice device number
     INTEGER     STAT              OUT status (PNONE, POK, PNCHOI)
     INTEGER     CHNR              OUT choice number
**************************************************************************/
#ifdef NO_PROTO
nrqch (wkid, chdnr, stat, chnr)
   integer      *wkid,
            *chdnr,
            *stat,
            *chnr;
#else
nrqch (integer *wkid, integer *chdnr, integer *stat, integer *chnr)
#endif
{
   Pint  cchnum;
   Pin_status in_status;
/**************************************************************************
  C Syntax
     void
     preq_choice ( ws, dev, in_status, choice )
     Pint        ws;               workstation identifier
     Pint        dev;              choice device number
     Pin_status  *in_status;       OUT input status
     Pint        *choice;          OUT choice
**************************************************************************/

   preq_choice ((Pint) *wkid, (Pint) *chdnr, &in_status, &cchnum);
   *chnr = cchnum;

   *stat = in_status;
   if (in_status == PIN_STATUS_NONE)
      *stat = 0;
   if (in_status == PIN_STATUS_OK)
      *stat = 1;
   if (in_status == PIN_STATUS_NO_IN)
      *stat = 2;
}
