#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     RETRIEVE STRUCTURE NETWORKS - retrieve  specified  structure
     networks from specified archive file

  FORTRAN Syntax
     SUBROUTINE presn ( AFID, N, LSTRID )
     INTEGER     AFID              archive file identifier
     INTEGER     N                 number of structure identifiers in the list
     INTEGER     LSTRID(N)         list of structure identifiers
**************************************************************************/
#ifdef NO_PROTO
nresn (afid, n, lstrid)
   integer      *afid,
            *n,
             lstrid[];
#else
nresn (integer *afid, integer *n, integer lstrid[])
#endif
{
   Pint      i;
   Pint_list struct_ids;
   struct_ids.ints = (Pint *) calloc (*n, sizeof (Pint));

   struct_ids.num_ints = *n;
   for (i = 0; i < *n; i++)
   {
      struct_ids.ints[i] = lstrid[i];
   }

/**************************************************************************
  C Syntax
     void
     pret_struct_nets ( archive_id, struct_ids )
     Pint        archive_id;       archive identifier
     Pint_list   *struct_ids;      list of structure identifiers
**************************************************************************/

   pret_struct_nets ((Pint) *afid, &struct_ids);

   free (struct_ids.ints);
}
