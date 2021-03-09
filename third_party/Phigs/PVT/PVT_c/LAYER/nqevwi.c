#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF VIEW INDICES- obtain list  of  view  indices
     defined on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqevwi ( WKID, N, ERRIND, NVWIX, VIEWI )
     INTEGER     WKID              workstation identifier
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NVWIX             OUT number of view bundle table entries
     INTEGER     VIEWI             OUT Nth element of list of defined view indices
**************************************************************************/
#ifdef NO_PROTO
nqevwi (wkid, n, errind, nvwix, viewi)
   integer      *wkid,
            *n,
            *errind,
            *nvwix,
            *viewi;
#else
nqevwi (integer *wkid, integer *n, integer *errind, integer *nvwix, integer *viewi)
#endif
{
   Pint      start, cerror, length, total_length;
   Pint_list indices;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   indices.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_view_inds ( ws, length, start, errind, indices, total_length )
     Pint        ws;               workstation identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *indices;         OUT list of view indices
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_view_inds ((Pint) *wkid, length, start, &cerror, &indices, 
                        &total_length);
   *errind = cerror;

   *nvwix = total_length;
   *viewi = *indices.ints;

   free (indices.ints);
}
