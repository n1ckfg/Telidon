#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     ADD NAMES TO SET - create  a  structure  element  containing
     additions to the current name set

  FORTRAN Syntax
     SUBROUTINE pads ( N, NAMSET )
     INTEGER     N                 number of names in the set
     INTEGER     NAMSET(N)         name set
**************************************************************************/
#ifdef NO_PROTO
nads (n, namset)
   integer      *n,
             namset[];
#else
nads (integer *n, integer namset[])
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
     padd_names_set ( set )
     Pint_list   *set;             set of names to be added
**************************************************************************/

   padd_names_set (&set);

   free (set.ints);
}
