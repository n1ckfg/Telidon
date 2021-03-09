#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED VIEW REPRESENTATION -  obtain  predefined
     view representation for workstation type

     SUBROUTINE pqpvwr ( WTYPE, PVWI, ERRIND, VWORMT, VWMPMT, VWCPLM,
          XYCLPI, BCLIPI, FCLIPI )
     INTEGER     WTYPE             workstation type
     INTEGER     PVWI              predefined view index
     INTEGER     ERRIND            OUT error indicator
     REAL        VWORMT(4,4)       OUT view orientation matrix
     REAL        VWMPMT(4,4)       OUT view mapping matrix
     REAL        VWCPLM(6)         OUT view clipping limits (NPC)
     INTEGER     XYCLPI            OUT x-y clipping indicator (PNCLIP, PCLIP)
     INTEGER     BCLIPI            OUT back clipping indicator (PNCLIP, PCLIP)
     INTEGER     FCLIPI            OUT front clipping indicator (PNCLIP, PCLIP)
**************************************************************************/
#ifdef NO_PROTO
nqpvwr (wtype, pvwi, errind, vwormt, vwmpmt, vwcplm, xyclpi, bclipi, fclipi)
   integer      *wtype,
            *pvwi,
            *errind,
            *xyclpi,
            *bclipi,
            *fclipi;
   real     vwormt[4][4],
             vwmpmt[4][4],
             vwcplm[6];
#else
nqpvwr (integer *wtype, integer *pvwi, integer *errind, real vwormt[4][4],
	real vwmpmt[4][4], real vwcplm[6], integer *xyclpi, integer *bclipi,
	integer *fclipi)
#endif
{
   Pint      cerror, i, j;
   Pview_rep3 rep;
/**************************************************************************
  C Syntax
     void
     pinq_pred_view_rep ( type, index, errind, rep )
     Pint        type;             workstation type
     Pint        index;            predefined view index
     Pint        *errind;          OUT error indicator
     Pview_rep3  *rep;             OUT view representation
**************************************************************************/

   pinq_pred_view_rep ((Pint) *wtype, (Pint) *pvwi, &cerror, &rep);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 4; j++)
      {
	 vwormt[i][j] = rep.ori_matrix[j][i];
	 vwmpmt[i][j] = rep.map_matrix[j][i];
      }
   }

   vwcplm[0] = rep.clip_limit.x_min;
   vwcplm[1] = rep.clip_limit.x_max;
   vwcplm[2] = rep.clip_limit.y_min;
   vwcplm[3] = rep.clip_limit.y_max;
   vwcplm[4] = rep.clip_limit.z_min;
   vwcplm[5] = rep.clip_limit.z_max;

   *xyclpi = rep.xy_clip;
   *bclipi = rep.back_clip;
   *fclipi = rep.front_clip;
}
