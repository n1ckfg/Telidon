#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REQUEST LOCATOR - request operator interaction  with  speci-
     fied locator device

  FORTRAN Syntax
     SUBROUTINE prqlc ( WKID, LCDNR, STAT, VIEWI, PX, PY )
     INTEGER     WKID              workstation identifier
     INTEGER     LCDNR             locator device number
     INTEGER     STAT              OUT status (PNONE, POK)
     INTEGER     VIEWI             OUT view index
     REAL        PX, PY            OUT locator position
**************************************************************************/
#ifdef NO_PROTO
nrqlc (wkid, lcdnr, stat, view_ind, px, py)
   integer      *wkid,
            *lcdnr,
            *stat,
            *view_ind;
   real    *px,
            *py;
#else
nrqlc (integer *wkid, integer *lcdnr, integer *stat, 
       integer *view_ind, real *px, real *py)
#endif
{
   Pint  cview;
   Pin_status in_status;
   Ppoint    loc_pos;
/**************************************************************************
  C Syntax
     void
     preq_loc ( ws, dev, in_status, view_ind, loc_pos )
     Pint        ws;               workstation identifier
     Pint        dev;              locator device number
     Pin_status  *in_status;       OUT input status
     Pint        *view_ind;        OUT view index
     Ppoint      *loc_pos;         OUT locator position
**************************************************************************/

   preq_loc ((Pint) *wkid, (Pint) *lcdnr, &in_status, &cview, &loc_pos);
   *view_ind = cview;

   *stat = in_status;
   switch (in_status)
   {
   case PIN_STATUS_NONE:
      *stat = 0;
      break;
   case PIN_STATUS_OK:
      *stat = 1;
      break;
   case PIN_STATUS_NO_IN:
      *stat = 2;
      break;
   }

   *px = loc_pos.x;
   *py = loc_pos.y;
}
