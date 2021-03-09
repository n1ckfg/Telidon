#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET VIEW REPRESENTATION  -  define  2D  view  representation
     entry on workstation

  FORTRAN Syntax
     SUBROUTINE psvwr ( WKID, VIEWI, VWORMT, VWMPMT, VWCPLM, XYCLPI )
     INTEGER     WKID              workstation identifier
     INTEGER     VIEWI             view index
     REAL        VWORMT(3, 3)      view orientation matrix
     REAL        VWMPMT(3, 3)      view mapping matrix
     REAL        VWCPLM(4)         view clipping limits (NPC)
                                   (XMIN, XMAX, YMIN, YMAX)
     INTEGER     XYCLPI            x-y clipping indicator (PNCLIP, PCLIP)
**************************************************************************/
#ifdef NO_PROTO
nsvwr (wkid, viewi, vwormt, vwmpmt, vwcplm, xyclpi)
   integer      *wkid,
            *viewi,
            *xyclpi;
   real     vwormt[3][3],
             vwmpmt[3][3],
             vwcplm[4];
#else
nsvwr (integer *wkid, integer *viewi, real vwormt[3][3], real vwmpmt[3][3], 
       real vwcplm[4], integer *xyclpi)
#endif
{
   Pint      i, j;
   Pview_rep rep;
/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
   {
      for (j = 0; j < 3; j++)
      {
	 rep.ori_matrix[i][j] = vwormt[j][i];
	 rep.map_matrix[i][j] = vwmpmt[j][i];
      }
   }

   rep.clip_limit.x_min = vwcplm[0];
   rep.clip_limit.x_max = vwcplm[1];
   rep.clip_limit.y_min = vwcplm[2];
   rep.clip_limit.y_max = vwcplm[3];

   rep.xy_clip = *xyclpi;

/**************************************************************************
  C Syntax
     void
     pset_view_rep ( ws, index, rep )
     Pint           ws;            workstation identifier
     Pint           index;         view index
     Pview_rep      *rep;          view representation
**************************************************************************/

   pset_view_rep ((Pint) *wkid, (Pint) *viewi, &rep);
}
