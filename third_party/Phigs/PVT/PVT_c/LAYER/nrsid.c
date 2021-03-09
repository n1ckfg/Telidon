#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     RETRIEVE STRUCTURE IDENTIFIERS - retrieve list of  structure
     identifiers from specified archive file

  FORTRAN Syntax
     SUBROUTINE prsid ( AFID, ILSIZE, N, LSTRID )
     INTEGER     AFID              archive file identifier
     INTEGER     ILSIZE            size of the list (LSTRID)
     INTEGER     N                 OUT number of structure identifiers in the list
     INTEGER     LSTRID(*)         OUT list of structure identifiers
**************************************************************************/
#ifdef NO_PROTO
nrsid (afid, ilsize, n, lstrid)
   integer  *afid,
            *ilsize,
            *n,
             lstrid[];
#else
nrsid (integer *afid, integer *ilsize, integer *n, integer lstrid[])
#endif
{
   Pint      start, actual_ids, i;
   Pint_list ids;

   start = 0;

   ids.ints = (Pint *) calloc (*ilsize, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pret_struct_ids ( archive_id, max_ids, start, ids, actual_ids )
     Pint        archive_id;       archive identifier
     Pint        max_ids;          size of appl. archive id list
     Pint        start;            start position of ids
     Pint_list   *ids;             OUT list of structure ids
     Pint        *actual_ids;      OUT actual number of ids in PHIGS
**************************************************************************/

   pret_struct_ids ((Pint) *afid, (Pint) *ilsize, start, &ids, &actual_ids);

   *n = actual_ids;
   for (i = 0; i < *n; i++)
   {
      lstrid[i] = ids.ints[i];
   }

   free (ids.ints);
}
