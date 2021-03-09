#include <phigs.h>
#include "f2c.h"

/***************************************************************************
NAME
     ARCHIVE STRUCTURE NETWORKS  -  archive  specified  structure
     networks into an archive file

  FORTRAN Syntax
     SUBROUTINE parsn ( AFID, N, LSTRID )
     INTEGER     AFID              archive file identifier
     INTEGER     N                 number of structure identifiers in the list
     INTEGER     LSTRID(N)         list of structure identifiers
****************************************************************************/
#ifdef NO_PROTO
narsn (afid, n, lstrid)
   integer      *afid,
            *n,
             lstrid[];
#else
narsn (integer *afid, integer *n, integer lstrid[])
#endif
{
   Pint_list struct_ids;
   Pint      i;
   struct_ids.ints = (Pint *) calloc (*n, sizeof (Pint));

   struct_ids.num_ints = *n;
   for (i = 0; i < *n; i++)
      struct_ids.ints[i] = lstrid[i];

/****************************************************************************
  C Syntax
     void
     par_struct_nets ( archive_id, struct_ids )
     Pint        archive_id;       archive identifier
     Pint_list   *struct_ids;      list of structure identifiers
****************************************************************************/

   par_struct_nets ((Pint) *afid, &struct_ids);

   free (struct_ids.ints);
}
