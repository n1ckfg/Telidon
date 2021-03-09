#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SAMPLE LOCATOR - sample current measure of specified locator
     device

  FORTRAN Syntax
     SUBROUTINE psmlc ( WKID, LCDNR, VIEWI, LPX, LPY )
     INTEGER     WKID              workstation identifier
     INTEGER     LCDNR             locator device number
     INTEGER     VIEWI             OUT view index
     REAL        LPX, LPY          OUT locator position in WC
**************************************************************************/
#ifdef NO_PROTO
nsmlc (wkid, lcdnr, view_ind, lpx, lpy)
   integer      *wkid,
            *lcdnr,
            *view_ind;
   real    *lpx,
            *lpy;
#else
nsmlc (integer *wkid, integer *lcdnr, integer *view_ind, real *lpx, real *lpy)
#endif
{
   Pint  cview;
   Ppoint    loc_pos;
/**************************************************************************
  C Syntax
     void
     psample_loc ( ws, dev, view_ind, loc_pos )
     Pint        ws;               workstation identifier
     Pint        dev;              locator device number
     Pint        *view_ind;        OUT view index
     Ppoint      *loc_pos;         OUT locator data
**************************************************************************/

   psample_loc ((Pint) *wkid, (Pint) *lcdnr, &cview, &loc_pos);
   *view_ind = cview;

   *lpx = loc_pos.x;
   *lpy = loc_pos.y;
}
