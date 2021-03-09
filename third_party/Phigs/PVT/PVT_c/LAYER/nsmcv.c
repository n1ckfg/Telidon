#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET MODELLING CLIPPING VOLUME - create structure element  to
     set current 2D modelling clipping volume

  FORTRAN Syntax
     SUBROUTINE psmcv ( OP, NHALFS, HALFSP )
     INTEGER     OP                modelling clipping operator
     INTEGER     NHALFS            number of modelling clipping
                                   half spaces in list
     REAL        HALFSP(4, NHALFS) list of modelling clipping
                                   half spaces
**************************************************************************/
#ifdef NO_PROTO
nsmcv (op, nmclhs, mclphs)
   integer      *op,
            *nmclhs;
   real     mclphs[][4];
#else
nsmcv (integer *op, integer *nmclhs, real mclphs[][4])
#endif
{
   Pint      i;
   Phalf_space_list half_spaces;
   half_spaces.num_half_spaces = *nmclhs;
   half_spaces.half_spaces = (Phalf_space *) calloc (*nmclhs, sizeof (Phalf_space));

   for (i = 0; i < *nmclhs; i++)
   {
      half_spaces.half_spaces[i].point.x = mclphs[i][0];
      half_spaces.half_spaces[i].point.y = mclphs[i][1];
      half_spaces.half_spaces[i].norm.delta_x = mclphs[i][2];
      half_spaces.half_spaces[i].norm.delta_y = mclphs[i][3];
   }

/**************************************************************************
  C Syntax
     void
     pset_model_clip_vol ( op, half_spaces )
     Pint        op;               operator
     Phalf_space_list              *half_spaces;list of half-spaces
**************************************************************************/

   pset_model_clip_vol ((Pint) *op, &half_spaces);

   free (half_spaces.half_spaces);
}
