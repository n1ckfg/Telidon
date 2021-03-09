#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET MODELLING CLIPPING VOLUME 3 - create  structure  element
     to set current 3D modelling clipping volume

  FORTRAN Syntax
     SUBROUTINE psmcv3 ( OP, NHALFS, HALFSP )
     INTEGER     OP                modelling clipping operator
     INTEGER     NHALFS            number of modelling clipping
                                   half spaces in list
     REAL        HALFSP(6, NHALFS) list of modelling clipping half spaces
**************************************************************************/
#ifdef NO_PROTO
nsmcv3 (mclpop, nmclhs, mclphs)
   integer      *mclpop,
            *nmclhs;
   real     mclphs[][6];
#else
nsmcv3 (integer *mclpop, integer *nmclhs, real mclphs[][6])
#endif
{
   Pint      i;
   Phalf_space_list3 half_spaces;
   half_spaces.num_half_spaces = *nmclhs;
   half_spaces.half_spaces = (Phalf_space3 *) calloc (*nmclhs, sizeof (Phalf_space3));

   for (i = 0; i < *nmclhs; i++)
   {
      half_spaces.half_spaces[i].point.x = mclphs[i][0];
      half_spaces.half_spaces[i].point.y = mclphs[i][1];
      half_spaces.half_spaces[i].point.z = mclphs[i][2];
      half_spaces.half_spaces[i].norm.delta_x = mclphs[i][3];
      half_spaces.half_spaces[i].norm.delta_y = mclphs[i][4];
      half_spaces.half_spaces[i].norm.delta_z = mclphs[i][5];
   }

/**************************************************************************
  C Syntax
     void
     pset_model_clip_vol3 ( mclpop, half_spaces )
     Pint        *mclpop;               operator
     Phalf_space_list3             *half_spaces;list of half-spaces
**************************************************************************/

   pset_model_clip_vol3 ((Pint) *mclpop, &half_spaces);

   free (half_spaces.half_spaces);
}
