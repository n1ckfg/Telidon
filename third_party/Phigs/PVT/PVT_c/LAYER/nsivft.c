#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INVISIBILITY FILTER - set workstation's name set  filter
     to determine invisible primitives

  FORTRAN Syntax
     SUBROUTINE psivft ( WKID, ISN, IS, ESN, ES )
     INTEGER     WKID              workstation identifier
     INTEGER     ISN               number of names in the inclusion set
     INTEGER     IS(ISN)           inclusion set
     INTEGER     ESN               number of names in the exclusion set
     INTEGER     ES(ESN)           exclusion set
**************************************************************************/
#ifdef NO_PROTO
nsivft (wkid, isn, is, esn, es)
   integer      *wkid,
            *isn,
             is[],
            *esn,
             es[];
#else
nsivft (integer *wkid, integer *isn, integer is[], integer *esn, integer es[])
#endif
{
   Pfilter   filter;
   Pint      i;
   filter.incl_set.ints = (Pint *) calloc (*isn, sizeof (Pint));
   filter.excl_set.ints = (Pint *) calloc (*esn, sizeof (Pint));

   filter.incl_set.num_ints = *isn;
   for (i = 0; i < *isn; i++)
   {
      filter.incl_set.ints[i] = is[i];
   }

   filter.excl_set.num_ints = *esn;
   for (i = 0; i < *esn; i++)
   {
      filter.excl_set.ints[i] = es[i];
   }

/**************************************************************************
  C Syntax
     void
     pset_invis_filter ( ws, filter )
     Pint        ws;               workstation identifier
     Pfilter     *filter;          highlighting filter
**************************************************************************/

   pset_invis_filter ((Pint) *wkid, &filter);

   free (filter.incl_set.ints);
   free (filter.excl_set.ints);
}
