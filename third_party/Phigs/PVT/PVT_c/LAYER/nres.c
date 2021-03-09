#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REMOVE NAMES FROM SET - create structure element  to  remove
     names from current name set

  FORTRAN Syntax
     SUBROUTINE pres ( N, NAMSET )
     INTEGER     N                 number of names in the set
     INTEGER     NAMSET(N)         name set
**************************************************************************/
#ifdef NO_PROTO
nres (n, namset)
   integer      *n,
             namset[];
#else
nres (integer *n, integer namset[])
#endif
{
   Pint_list set;
   Pint      i;
   set.ints = (Pint *) calloc (*n, sizeof (Pint));

   set.num_ints = *n;
   for (i = 0; i < *n; i++)
      set.ints[i] = namset[i];

/**************************************************************************
  C Syntax
     void
     premove_names_set ( set )
     Pint_list   *set;             set of names to be removed
**************************************************************************/

   premove_names_set (&set);

   free (set.ints);
}
