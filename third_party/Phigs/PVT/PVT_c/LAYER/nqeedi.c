#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF EDGE INDICES- obtain list  of  edge  indices
     defined on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqeedi ( WKID, N, ERRIND, OL, EDI )
     INTEGER     WKID              workstation identifier
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of edge bundle table entries
     INTEGER     EDI               OUT Nth element of list of defined edge
                                   indices
**************************************************************************/
#ifdef NO_PROTO
nqeedi (wkid, n, errind, ol, edi)
   integer      *wkid,
            *n,
            *errind,
            *ol,
            *edi;
#else
nqeedi (integer *wkid, integer *n, integer *errind, integer *ol, integer *edi)
#endif
{
   Pint cerror;
   Pint_list indi;
   Pint      length,
             start;
   Pint      total_length;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   
   indi.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_edge_inds ( ws, length, start, errind, indices, total_length )
     Pint        ws;               workstation identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *indices;         OUT list of edge indices
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_edge_inds ((Pint) *wkid, length, start,
                         &cerror, &indi, &total_length);
   *errind = cerror;

   *ol = total_length;
   if (indi.num_ints == 1)
      *edi = indi.ints[0];

   free (indi.ints);
}
