#include <phigs.h>
#include "f2c.h"

/*************************************************************************
NAME
     DELETE STRUCTURES FROM ARCHIVE - delete specified structures
     from an archive file

  FORTRAN Syntax
     SUBROUTINE pdstar ( AFID, N, LSTRID )
     INTEGER     AFID              archive file identifier
     INTEGER     N                 number of structure identifiers in the list
     INTEGER     LSTRID(N)         list of structure identifiers
*************************************************************************/
#ifdef NO_PROTO
ndstar (afid, n, lstrid)
   integer      *afid,
            *n,
             lstrid[];
#else
ndstar (integer *afid, integer *n, integer lstrid[])
#endif
{
   Pint_list struct_ids;
   Pint      i;
   struct_ids.ints = (Pint *) calloc (*n, sizeof (Pint));

   struct_ids.num_ints = *n;
   for (i = 0; i < *n; i++)
      struct_ids.ints[i] = lstrid[i];

/*************************************************************************
  C Syntax
     void
     pdel_structs_ar ( archive_id, struct_ids )
     Pint        archive_id;       archive identifier
     Pint_list   *struct_ids;      list of structure identifiers
*************************************************************************/

   pdel_structs_ar ((Pint) *afid, &struct_ids);

   free (struct_ids.ints);
}
