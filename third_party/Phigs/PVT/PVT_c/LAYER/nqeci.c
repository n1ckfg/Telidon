#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF COLOUR  INDICES  -  obtain  list  of  colour
     indices defined on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqeci ( WKID, N, ERRIND, OL, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of colour table entries
     INTEGER     COLI              OUT Nth element of list of colour indices
**************************************************************************/
#ifdef NO_PROTO
nqeci (wkid, n, errind, ol, coli)
   integer      *wkid,
            *n,
            *errind,
            *ol,
            *coli;
#else
nqeci (integer *wkid, integer *n, integer *errind, integer *ol, integer *coli)
#endif
{
   Pint_list indi;
   Pint      length,
             start;
   Pint      total_length;
   Pint cerror;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   indi.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_colr_inds ( ws, length, start, errind, indices, total_length )
     Pint        ws;               workstation identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *indices;         OUT list of colour indices
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_colr_inds ((Pint) *wkid, length, start, &cerror,
       &indi, &total_length);
   *errind = cerror;

   *ol = total_length;
   if (indi.num_ints == 1)
      *coli = indi.ints[0];

   free (indi.ints);
}
