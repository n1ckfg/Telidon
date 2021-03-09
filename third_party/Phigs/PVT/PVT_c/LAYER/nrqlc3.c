#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REQUEST LOCATOR 3 - request operator interaction with speci-
     fied locator device

  FORTRAN Syntax
     SUBROUTINE prqlc3 ( WKID, LCDNR, STAT, VIEWI, PX, PY, PZ )
     INTEGER     WKID              workstation identifier
     INTEGER     LCDNR             locator device number
     INTEGER     STAT              OUT status (PNONE, POK)
     INTEGER     VIEWI             OUT view index
     REAL        PX, PY, PZ        OUT locator position
**************************************************************************/
#ifdef NO_PROTO
nrqlc3 (wkid, lcdnr, stat, view_ind, px, py, pz)
   integer      *wkid,
            *lcdnr,
            *stat,
            *view_ind;
   real    *px,
            *py,
            *pz;
#else
nrqlc3 (integer *wkid, integer *lcdnr, integer *stat, 
        integer *view_ind, real *px,
	real *py, real *pz)
#endif
{
   Pint cview;
   Pin_status in_status;
   Ppoint3   loc_pos;
/**************************************************************************
  C Syntax
     void
     preq_loc3 ( ws, dev, in_status, view_ind, loc_pos )
     Pint        ws;               workstation identifier
     Pint        dev;              locator device number
     Pin_status  *in_status;       OUT input status
     Pint        *view_ind;        OUT view index
     Ppoint3     *loc_pos;         OUT locator position
**************************************************************************/

   preq_loc3 ((Pint) *wkid, (Pint) *lcdnr, &in_status, &cview, &loc_pos);
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
   *pz = loc_pos.z;
}
