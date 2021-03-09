#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PICK FILTER - set PICK input device's pick filter, which
     determines the pickable primitives

  FORTRAN Syntax
     SUBROUTINE pspkft ( WKID, PKDNR, ISN, IS, ESN, ES )
     INTEGER     WKID              workstation identifier
     INTEGER     PKDNR             pick device number
     INTEGER     ISN               number of names in the inclusion set
     INTEGER     IS(ISN)           inclusion set
     INTEGER     ESN               number of names in the exclusion set
     INTEGER     ES(ESN)           exclusion set
**************************************************************************/
#ifdef NO_PROTO
nspkft (wkid, pkdnr, isn, is, esn, es)
   integer      *wkid,
            *pkdnr,
            *isn,
             is[],
            *esn,
             es[];
#else
nspkft (integer *wkid, integer *pkdnr, integer *isn, integer is[], 
        integer *esn, integer es[])
#endif
{
   Pint      i;
   Pfilter   filter;
   filter.incl_set.ints = (Pint *) calloc (*isn, sizeof (Pint));
   filter.excl_set.ints = (Pint *) calloc (*esn, sizeof (Pint));

   filter.incl_set.num_ints = *isn;
   for (i = 0; i < *isn; i++)
   {
      filter.incl_set.ints[i] = is[i];
   }

   filter.excl_set.num_ints = *esn;
   for (i = 0; i < *isn; i++)
   {
      filter.excl_set.ints[i] = es[i];
   }

/**************************************************************************
  C Syntax
     void
     pset_pick_filter ( ws, dev_num, filter )
     Pint        ws;               workstation identifier
     Pint        dev_num;          pick device number
     Pfilter     *filter;          pick filter
**************************************************************************/

   pset_pick_filter ((Pint) *wkid, (Pint) *pkdnr, &filter);

   free (filter.incl_set.ints);
   free (filter.excl_set.ints);
}
