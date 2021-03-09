#include <phigs.h>
#include "f2c.h"

/*******************************************************************************
NAME
     CELL ARRAY 3 - create structure element specifying  3D  cell
     array

  FORTRAN Syntax
     SUBROUTINE pca3 ( CPXA, CPYA, CPZA, DIMX, DIMY, ISC, ISR, DX, DY, COLIA )
     REAL        CPXA(3), CPYA(3), CPZA(3)cell parallelogram (P, Q, R) (MC)
     INTEGER     DIMX, DIMY          the dimensions of COLIA which contains
                                     the cell array
     INTEGER     ISC, ISR            indices of start column, start row
     INTEGER     DX, DY              number of columns, number of rows
     INTEGER     COLIA(DIMX, DIMY)   colour index array
*******************************************************************************/
#ifdef NO_PROTO
nca3 (cpxa, cpya, cpza, dimx, dimy, isc, isr, dx, dy, colia)
   real      cpxa[],
             cpya[],
             cpza[];
   integer  *dimx,
            *dimy,
            *isc,
            *isr,
            *dx,
            *dy;
   integer  *colia;
#else
nca3 (real cpxa[], real cpya[], real cpza[], 
      integer *dimx, integer *dimy, integer *isc,
      integer *isr, integer *dx, integer *dy, integer *colia)
#endif
{

#ifndef NO_PROTO
    extern int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern int unmsg_();
#endif /* NO_PROTO */

   int       dim_index, dim_limit, alloc_elems, i, j;
   Pparal    parallelogram;
   Ppat_rep  cell_color;
   Pint      *k, *tmp_array;

/* check for Fortran-y error #2004 - no equivalent in C  */
   if (*dimx <= 0 || *dimy <= 0)
   {  /*  should never get here - condition arises only when
          testing Fortran-unique error code #2004.  No such
          error in C-binding.  */                       
      unmsg_("LAYER/nca3 called with non-positive dimx or dimy.", 49L);
   }

/***  allocate a new array just the size of the sub-array of colia **/
   dim_limit   = *dimx * *dimy;
   alloc_elems = *dx   * *dy;
   if (alloc_elems < 1)
       alloc_elems = 1;
   tmp_array = (Pint *) calloc (alloc_elems, sizeof (Pint));

   cell_color.dims.size_x = *dx;
   cell_color.dims.size_y = *dy;

/***  Now, pull the sub-array to be used out of colia into the
      new array to be sent ( won't need to transpose it)**/

   k = tmp_array;
   for (j = *isr-1; j < *isr + *dy - 1; j++)
   {
      for (i = *isc-1; i < *isc + *dx - 1; i++)
      {
         /* prevent access outside of Fortran array  */
	 dim_index = i + (*dimx * j);
         if (dim_index < dim_limit && dim_index >= 0)
         {
            *k = colia [dim_index];
         }
         else
         {
            /* should never get here, except when testing error
               conditions, #117 in particular.  */
            ;
         }
	 k++;
      }
   }

   cell_color.colr_array = tmp_array;

   parallelogram.p.x = cpxa[0];
   parallelogram.p.y = cpya[0];
   parallelogram.p.z = cpza[0];
   parallelogram.q.x = cpxa[1];
   parallelogram.q.y = cpya[1];
   parallelogram.q.z = cpza[1];
   parallelogram.r.x = cpxa[2];
   parallelogram.r.y = cpya[2];
   parallelogram.r.z = cpza[2];

/****************************************************************************
  C Syntax
     void
     pcell_array3 ( parallelogram, colr_array )
     Pparal      *parallelogram;     cell parallelogram: [0]=P; [1]=Q; [2]=R
     Ppat_rep    *colr_array;        colour array
****************************************************************************/

   pcell_array3 (&parallelogram, &cell_color);
   free (tmp_array);
}
