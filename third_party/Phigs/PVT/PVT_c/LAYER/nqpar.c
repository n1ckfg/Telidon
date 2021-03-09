#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE  PATTERN  REPRESENTATION  -  inquire   for   pattern
     representation on workstation

  FORTRAN Syntax
     SUBROUTINE pqpar ( WKID, PAI, TYPE, DIMX, DIMY, ERRIND, DX, DY, COLIA )
     INTEGER     WKID              workstation identifier
     INTEGER     PAI               pattern index
     INTEGER     TYPE              type of returned values (PSET, PREALI)
     INTEGER     DIMX, DIMY        maximum pattern array dimensions
     INTEGER     ERRIND            OUT error indicator
     INTEGER     DX, DY            OUT pattern array dimensions
     INTEGER     COLIA(DIMX, DIMY) OUT pattern array
**************************************************************************/
#ifdef NO_PROTO
nqpar (wkid, pai, type, dimx, dimy, errind, dx, dy, colia)
   integer      *wkid,
            *pai,
            *type,
            *dimx,
            *dimy,
            *errind,
            *dx,
            *dy,
            *colia;
#else
nqpar (integer *wkid, integer *pai, integer *type, 
       integer *dimx, integer *dimy, integer *errind,
       integer *dx, integer *dy, integer *colia)
#endif
{
   Pinq_type inq_type;
   Pint      cerror, i;
   Pstore    store;
   Ppat_rep *rep;

/* Create the memory buffer if not already created. */
   pcreate_store (&cerror, &store);
   if (cerror)
   {
   /* Cannot create memory buffer */
      return;
   }

   inq_type = *type;
   switch (*type)
   {
   case 0:
      inq_type = PINQ_SET;
      break;
   case 1:
      inq_type = PINQ_REALIZED;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pinq_pat_rep ( ws, index, type, store, errind, rep, )
     Pint        ws;               workstation identifier
     Pint        index;            pattern index
     Pinq_type   type;             type of returned value
     Pstore      store;            handle to Store object
     Pint        *errind;          OUT error indicator
     Ppat_rep    **rep;            OUT pattern representation
**************************************************************************/

   pinq_pat_rep ((Pint) *wkid, (Pint) *pai, inq_type, store, &cerror, &rep);
   *errind = cerror;

   if (*errind)
   {
   /* Got an Error from the function */
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
