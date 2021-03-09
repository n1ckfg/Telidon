#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PATTERN REPRESENTATION - define  pattern  representation
     on specified workstation

  FORTRAN Syntax
     SUBROUTINE pspar ( WKID, PAI, DIMX, DIMY, ISC, ISR, DX, DY, COLIA )
     INTEGER     WKID              workstation identifier
     INTEGER     PAI               pattern index
     INTEGER     DIMX, DIMY        the dimensions of COLIA which contains
                                   the pattern colour index array
     INTEGER     ISC, ISR          indices to start column, start row
     INTEGER     DX, DY            number of columns, number of rows used
     INTEGER     COLIA(DIMX, DIMY) pattern colour index array
**************************************************************************/
#ifdef NO_PROTO
nspar (wkid, pai, dimx, dimy, isc, isr, dx, dy, colia)
   integer      *wkid,
            *pai,
            *dimx,
            *dimy,
            *isc,
            *isr,
            *dx,
            *dy;
   integer      *colia;
#else
nspar (integer *wkid, integer *pai, integer *dimx, integer *dimy, 
       integer *isc, integer *isr,
       integer *dx, integer *dy, integer *colia)
#endif
{
#ifndef NO_PROTO
    extern int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern int unmsg_();
#endif /* NO_PROTO */

   int       dim_index, dim_limit, alloc_elems, i, j;
   Pint      *k, *tmp_array;
   Ppat_rep  rep;

/* check for Fortran-y error #2004 - no equivalent in C  */
   if (*dimx <= 0 || *dimy <= 0)
   {  /*  should never get here - condition arises only when
          testing Fortran-unique error code #2004.  No such
          error in C-binding.  */                       
      unmsg_("LAYER/nspar called with non-positive dimx or dimy.", 50L);
   }

/***  allocate a new array just the size of the sub-array of colia **/
   dim_limit   = *dimx * *dimy;
   alloc_elems = *dx   * *dy;
   if (alloc_elems < 1)
       alloc_elems = 1;
   tmp_array = (Pint *) calloc (alloc_elems, sizeof (Pint));

   rep.dims.size_x = *dx;
   rep.dims.size_y = *dy;
   rep.colr_array = tmp_array;

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

/**************************************************************************
  C Syntax
     void
     pset_pat_rep ( ws, index, rep )
     Pint        ws;               workstation identifier
     Pint        index;            pattern bundle index
     Ppat_rep    *rep;             pattern representation pointer
**************************************************************************/

   pset_pat_rep ((Pint) *wkid, (Pint) *pai, &rep);
   free (tmp_array);
}


