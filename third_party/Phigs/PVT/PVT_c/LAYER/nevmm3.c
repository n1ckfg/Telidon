#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     EVALUATE VIEW MAPPING MATRIX  3  -  generate  transformation
     matrix to map 3D VRC window to 3D NPC viewport

  FORTRAN Syntax
     SUBROUTINE pevmm3 ( VWWNLM, PJVPLM, PJTYPE, PJRX, PJRY, PJRZ, VPLD,
          BPLD, FPLD, ERRIND, VWMPMT )
     REAL        VWWNLM(4)         window limits (VRC)
     REAL        PJVPLM(6)         projection viewport limits (NPC)
     INTEGER     PJTYPE            projection type (PPARL, PPERS)
     REAL        PJRX, PJRY, PJRZ  projection reference point (VRC)
     REAL        VPLD              view plane distance (VRC)
     REAL        BPLD              back plane distance (VRC)
     REAL        FPLD              front plane distance (VRC)
     INTEGER     ERRIND            OUT error indicator
     REAL        VWMPMT(4, 4)      OUT view mapping matrix
**************************************************************************/
#ifdef NO_PROTO
nevmm3 (vwwnlm, pjvplm, pjtype, pjrx, pjry, pjrz, vpld, bpld, fpld, errind, vwmpmt)
   real     vwwnlm[4],
             pjvplm[6],
            *pjrx,
            *pjry,
            *pjrz,
            *vpld,
            *bpld,
            *fpld,
             vwmpmt[4][4];
   integer      *errind,
            *pjtype;
#else
nevmm3 (real vwwnlm[4], real pjvplm[6], integer *pjtype, real *pjrx, real *pjry,
	real *pjrz, real *vpld, real *bpld, real *fpld, integer *errind, real vwmpmt[4][4])
#endif
{
   Pview_map3 mapping;
   Pint      cerror, i, j;
   Pmatrix3  matrix;
   mapping.win.x_min = vwwnlm[0];
   mapping.win.x_max = vwwnlm[1];
   mapping.win.y_min = vwwnlm[2];
   mapping.win.y_max = vwwnlm[3];

   mapping.proj_vp.x_min = pjvplm[0];
   mapping.proj_vp.x_max = pjvplm[1];
   mapping.proj_vp.y_min = pjvplm[2];
   mapping.proj_vp.y_max = pjvplm[3];
   mapping.proj_vp.z_min = pjvplm[4];
   mapping.proj_vp.z_max = pjvplm[5];

   mapping.proj_type = *pjtype;

   switch (*pjtype)
   {
   case 0:			/***  PPARL  ***/
      mapping.proj_type = PTYPE_PARAL;
      break;
   case 1:			/***  PPERS  ***/
      mapping.proj_type = PTYPE_PERSPECT;
      break;
   }

   mapping.proj_ref_point.x = *pjrx;
   mapping.proj_ref_point.y = *pjry;
   mapping.proj_ref_point.z = *pjrz;

   mapping.view_plane = *vpld;
   mapping.back_plane = *bpld;
   mapping.front_plane = *fpld;

/**************************************************************************
  C Syntax
     void
     peval_view_map_matrix3 ( map, errind, m )
     Pview_map3  *map;             view mapping
     Pint        *errind;          OUT error indicator
     Pmatrix3    m;                OUT view mapping matrix
**************************************************************************/

   peval_view_map_matrix3 (&mapping, &cerror, matrix);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 vwmpmt[i][j] = matrix[j][i];
}
