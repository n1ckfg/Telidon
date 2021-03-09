#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF PATTERN INDICES -  obtain  list  of  pattern
     indices defined on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqepai ( WKID, N, ERRIND, OL, PAI )
     INTEGER     WKID              workstation identifier
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of pattern table entries
     INTEGER     PAI               OUT Nth element of list of pattern indices
**************************************************************************/
#ifdef NO_PROTO
nqepai (wkid, n, errind, ol, pai)
   integer  *wkid,
            *n,
            *errind,
            *ol,
            *pai;
#else
nqepai (integer *wkid, integer *n, integer *errind, integer *ol, integer *pai)
#endif
{
   Pint_list indi;
   Pint      length, cerror, start;
   Pint      total_length;

   start = *n - (*n > 0);
   length = (*n != 0);

   indi.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_pat_inds ( ws, length, start, errind, indices, total_length )
     Pint        ws;               workstation identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *indices;         OUT list of pattern indices
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_pat_inds ((Pint) *wkid, length, start, &cerror, &indi, 
                       &total_length);
   *errind = cerror;

   *ol = total_length;

   if (indi.num_ints == 1)
      *pai = indi.ints[0];

   free (indi.ints);
}
