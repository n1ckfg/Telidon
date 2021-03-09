#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET VIEW REPRESENTATION 3 - define  3D  view  representation
     entry on workstation

  FORTRAN Syntax
     SUBROUTINE psvwr3 ( WKID, VIEWI, VWORMT, VWMPMT, VWCPLM, XYCLPI,
           BCLIPI, FCLIPI )
     INTEGER     WKID              workstation identifier
     INTEGER     VIEWI             view index
     REAL        VWORMT(4, 4)      view orientation matrix
     REAL        VWMPMT(4, 4)      view mapping matrix
     REAL        VWCPLM(6)         view clipping limits (NPC)
                                   (XMIN, XMAX, YMIN, YMAX, ZMIN, ZMAX)
     INTEGER     XYCLPI            x-y clipping indicator (PNCLIP, PCLIP)
     INTEGER     BCLIPI            back clipping indicator (PNCLIP, PCLIP)
     INTEGER     FCLIPI            front clipping indicator (PNCLIP, PCLIP)
**************************************************************************/
#ifdef NO_PROTO
nsvwr3 (wkid, viewi, vwormt, vwmpmt, vwcplm, xyclpi, bclipi, fclipi)
   integer      *wkid,
            *viewi,
            *xyclpi,
            *bclipi,
            *fclipi;
   real     vwormt[4][4],
             vwmpmt[4][4],
             vwcplm[6];
#else
nsvwr3 (integer *wkid, integer *viewi, real vwormt[4][4], real vwmpmt[4][4],
	real vwcplm[6], integer *xyclpi, integer *bclipi, integer *fclipi)
#endif
{
   Pint      i,
             j;
   Pview_rep3 rep;
/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 4; j++)
      {
	 rep.ori_matrix[i][j] = vwormt[j][i];
	 rep.map_matrix[i][j] = vwmpmt[j][i];
      }
   }

   rep.clip_limit.x_min = vwcplm[0];
   rep.clip_limit.x_max = vwcplm[1];
   rep.clip_limit.y_min = vwcplm[2];
   rep.clip_limit.y_max = vwcplm[3];
   rep.clip_limit.z_min = vwcplm[4];
   rep.clip_limit.z_max = vwcplm[5];

/* not the neatest - in theory, should use C enum constants.  */
   rep.xy_clip = *xyclpi;
   rep.back_clip = *bclipi;
   rep.front_clip = *fclipi;

/**************************************************************************
  C Syntax
     void
     pset_view_rep3 ( ws, index, rep )
     Pint           ws;            workstation identifier
     Pint           index;         view index
     Pview_rep3     *rep;          view representation
**************************************************************************/

   pset_view_rep3 ((Pint) *wkid, (Pint) *viewi, &rep);
}
