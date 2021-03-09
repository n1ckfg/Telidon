#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED PATTERN REPRESENTATION  -  obtain  prede-
     fined pattern representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqppar ( WTYPE, PPAI, DIMX, DIMY, ERRIND, DX, DY, COLIA )
     INTEGER     WTYPE             workstation type
     INTEGER     PPAI              predefined pattern index
     INTEGER     DIMX, DIMY        maximum pattern array dimensions
     INTEGER     ERRIND            OUT error indicator
     INTEGER     DX, DY            OUT pattern array dimensions
     INTEGER     COLIA(DIMX, DIMY) OUT pattern array
**************************************************************************/
#ifdef NO_PROTO
nqppar (wtype, pindex, dimx, dimy, errind, dx, dy, colia)
   integer      *wtype,
            *pindex,
            *dimx,
            *dimy,
            *errind,
            *dx,
            *dy,
            *colia;
#else
nqppar (integer *wtype, integer *pindex, integer *dimx, integer *dimy, 
        integer *errind,
	integer *dx, integer *dy, integer *colia)
#endif
{
   Pint      cerror, i;
   Pstore    store;
   Ppat_rep *rep;
/* Create the memory buffer if not already created. */

   pcreate_store (errind, &store);

   if (*errind)
   {
   /* Cannot create memory buffer */
      return;
   }
/**************************************************************************
  C Syntax
     void
     pinq_pred_pat_rep ( type, index, store, errind, rep )
     Pint        type;             workstation type
     Pint        index;            predefined index
     Pstore      store;            handle to Store object
     Pint        *errind;          OUT error indicator
     Ppat_rep    **rep;            OUT predefined pattern rep
**************************************************************************/

   pinq_pred_pat_rep ((Pint) *wtype, (Pint) *pindex, store, &cerror, &rep);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *dx = rep->dims.size_x;
   *dy = rep->dims.size_y;

   /* Check to see if Buffer is big enough */
   if ((*dimx < *dx ) || (*dimy < *dy)) {
      *errind = 2001;
       return;         /* The FORTRAN error, C has no equivalent */
   }


   for (i = 0; i < *dx * *dy; i++)
   {
      colia[i] = rep->colr_array[i];
   }

   pdel_store (&cerror, &store);
   *errind = 0;

}
