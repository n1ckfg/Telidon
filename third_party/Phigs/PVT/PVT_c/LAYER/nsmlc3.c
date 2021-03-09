#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SAMPLE LOCATOR 3 - sample current measure of specified loca-
     tor device


  FORTRAN Syntax
     SUBROUTINE psmlc3 ( WKID, LCDNR, VIEWI, LPX, LPY, LPZ )
     INTEGER     WKID              workstation identifier
     INTEGER     LCDNR             locator device number
     INTEGER     VIEWI             OUT view index
     REAL        LPX, LPY, LPZ     OUT locator position in WC
**************************************************************************/
#ifdef NO_PROTO
nsmlc3 (wkid, lcdnr, view_ind, lpx, lpy, lpz)
   integer      *wkid,
            *lcdnr,
            *view_ind;
   real    *lpx,
            *lpy,
            *lpz;
#else
nsmlc3 (integer *wkid, integer *lcdnr, integer *view_ind, real *lpx, real *lpy,
	real *lpz)
#endif
{
   Pint cview;
   Ppoint3   loc_pos;
/**************************************************************************
  C Syntax
     void
     psample_loc3 ( ws, dev, view_ind, loc_pos )
     Pint        ws;               workstation identifier
     Pint        dev;              locator device number
     Pint        *view_ind;        OUT view index
     Ppoint3     *loc_pos;         OUT locator position
**************************************************************************/

   psample_loc3 ((Pint) *wkid, (Pint) *lcdnr, &cview, &loc_pos);
   *view_ind = cview;

   *lpx = loc_pos.x;
   *lpy = loc_pos.y;
   *lpz = loc_pos.z;
}
