#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     EVALUATE VIEW  MAPPING  MATRIX   -  generate  transformation
     matrix to map 2D VRC window to 2D NPC viewport

  FORTRAN Syntax
     SUBROUTINE pevmm ( VWWNLM, PJVPLM, ERRIND, VWMPMT )
     REAL        VWWNLM(4)         window limits (VRC)
     REAL        PJVPLM(4)         projection viewport limits (NPC)
     INTEGER     ERRIND            OUT error indicator
     REAL        VWMPMT(3, 3)      OUT view mapping matrix
**************************************************************************/
#ifdef NO_PROTO
nevmm (vwwnlm, pjvplm, errind, vwmpmt)
   real     vwwnlm[4],
             pjvplm[4],
             vwmpmt[3][3];
   integer      *errind;
#else
nevmm (real vwwnlm[4], real pjvplm[4], integer *errind, real vwmpmt[3][3])
#endif
{
   Pview_map mapping;
   Pint      cerror, i, j;
   Pmatrix   matrix;
   mapping.win.x_min = vwwnlm[0];
   mapping.win.x_max = vwwnlm[1];
   mapping.win.y_min = vwwnlm[2];
   mapping.win.y_max = vwwnlm[3];

   mapping.proj_vp.x_min = pjvplm[0];
   mapping.proj_vp.x_max = pjvplm[1];
   mapping.proj_vp.y_min = pjvplm[2];
   mapping.proj_vp.y_max = pjvplm[3];

/**************************************************************************
  C Syntax
     void
     peval_view_map_matrix ( map, errind, m )
     Pview_map   *map;             view mapping
     Pint        *errind;          OUT error indicator
     Pmatrix     m;                OUT view mapping matrix
**************************************************************************/

   peval_view_map_matrix (&mapping, &cerror, matrix);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 vwmpmt[i][j] = matrix[j][i];
}
