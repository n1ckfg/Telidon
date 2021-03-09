#include <phigs.h>
#include "f2c.h"

/*************************************************************************
NAME
     CELL ARRAY - create structure  element  specifying  2D  cell
     array

  FORTRAN Syntax
     SUBROUTINE pca ( PX, PY, QX, QY, DIMX, DIMY, ISC, ISR, DX, DY, COLIA )
     REAL        PX, PY, QX, QY    two points (P, Q) (MC)
     INTEGER     DIMX, DIMY        the dimensions of COLIA which contains
                                   the cell array
     INTEGER     ISC, ISR          indices of start column, start row
     INTEGER     DX, DY            number of columns, number of rows
     INTEGER     COLIA(DIMX, DIMY) colour index array
*************************************************************************/
#ifdef NO_PROTO
nca (px, py, qx, qy, dimx, dimy, isc, isr, dx, dy, colia)
   real     *px,
            *py,
            *qx,
            *qy;
   integer  *dimx,
            *dimy,
            *isc,
            *isr,
            *dx,
            *dy;
   integer  *colia;
#else
nca (real *px, real *py, real *qx, real *qy, integer *dimx, integer *dimy,
     integer *isc, integer *isr, integer *dx, integer *dy, integer *colia)
#endif
{

#ifndef NO_PROTO
    extern int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern int unmsg_();
#endif /* NO_PROTO */

   int       dim_index, dim_limit, alloc_elems, i, j;
   Prect     rectangle;
   Ppat_rep  cell_color;
   Pint      *k, *tmp_array;

/* check for Fortran-y error #2004 - no equivalent in C  */
   if (*dimx <= 0 || *dimy <= 0)
   {  /*  should never get here - condition arises only when
          testing Fortran-unique error code #2004.  No such
          error in C-binding.  */                       
      unmsg_("LAYER/nca called with non-positive dimx or dimy.", 48L);
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
      new array to be sent ( won't need to transpose it) **/

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

   rectangle.p.x = *px;
   rectangle.p.y = *py;
   rectangle.q.x = *qx;
   rectangle.q.y = *qy;

/*************************************************************************
  C Syntax
     void
     pcell_array ( rectangle, colr_array )
     Prect       *rectangle;       cell rectangle
     Ppat_rep    *colr_array;      colour array
*************************************************************************/

   pcell_array (&rectangle, &cell_color);
   free (tmp_array);
}
