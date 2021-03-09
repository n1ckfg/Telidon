#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE  STRUCTURE  IDENTIFIERS-  obtain  current  structure
     identifiers

  FORTRAN Syntax
     SUBROUTINE pqsid ( N, ERRIND, NUMBER, STRID )
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NUMBER            OUT number of structure identifiers
     INTEGER     STRID             OUT Nth structure identifier
**************************************************************************/
#ifdef NO_PROTO
nqsid (n, errind, number, strid)
   integer      *n,
            *errind,
            *number,
            *strid;
#else
nqsid (integer *n, integer *errind, integer *number, integer *strid)
#endif
{
   Pint      start, cerror, length, total_length;
   Pint_list struct_ids;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   struct_ids.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_struct_ids ( length, start, errind, struct_ids, length_list )
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *struct_ids;      OUT list of structure ids
     Pint        *length_list;     OUT length of list in PHIGS
**************************************************************************/

   pinq_struct_ids (length, start, &cerror, &struct_ids, &total_length);
   *errind = cerror;

   *number = total_length;
   if (struct_ids.num_ints == 1)
      *strid = struct_ids.ints[0];

   free (struct_ids.ints);
}
