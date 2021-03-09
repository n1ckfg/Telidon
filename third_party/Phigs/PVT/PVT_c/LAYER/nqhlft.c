#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE HIGHLIGHTING FILTER - inquire inclusion  and  exclu-
     sion name sets for a workstation's highlighting filter

  FORTRAN Syntax
     SUBROUTINE pqhlft ( WKID, ISBSZ, ESBSZ, ERRIND, ISN, IS, ESN, ES )
     INTEGER     WKID              workstation identifier
     INTEGER     ISBSZ             inclusion set buffer size
     INTEGER     ESBSZ             exclusion set buffer size
     INTEGER     ERRIND            OUT error indicator
     INTEGER     ISN               OUT number of names in the inclusion set
     INTEGER     IS(ISBSZ)         OUT inclusion set
     INTEGER     ESN               OUT number of names in the exclusion set
     INTEGER     ES(ESBSZ)         OUT exclusion set
**************************************************************************/
#ifdef NO_PROTO
nqhlft (wkid, isbsz, esbsz, errind, isn, is, esn, es)
   integer      *wkid,
            *isbsz,
            *esbsz,
            *errind,
            *isn,
             is[],
            *esn,
             es[];
#else
nqhlft (integer *wkid, integer *isbsz, integer *esbsz, integer *errind, integer *isn,
	integer is[], integer *esn, integer es[])
#endif
{
   int       i;
   Pint      cerror;
   Pstore    store;
   Pfilter  *highl_filter;
/* Create the memory buffer if not already created. */
   pcreate_store (errind, &store);

   if (*errind)
   {
   /* Cannot create memory buffer */
      return;
   }
/**************************************************************************
  C Syntax
     void
     pinq_highl_filter ( ws, store, errind, highl_filter )
     Pint        ws;               workstation identifier
     Pstore      store;            handle to Store object
     Pint        *errind;          OUT error indicator
     Pfilter     **highl_filter;   OUT highlighting filter
**************************************************************************/

   pinq_highl_filter ((Pint) *wkid, store, &cerror, &highl_filter);
   *errind = cerror;

   if (cerror)  /* check for errors first, before touching the data */
   {  
      int temp_errind;
      pdel_store (&temp_errind, &store);
      return;
   }

   *isn = highl_filter->incl_set.num_ints;

   if (*isbsz < *isn)
   {

      pdel_store (&cerror, &store);
      *errind = 2001;
      return;
   }
   for (i = 0; i < *isn; i++)
   {
      is[i] = highl_filter->incl_set.ints[i];
   }

   *esn = highl_filter->excl_set.num_ints;
   if (*esbsz < *esn)
   {
      pdel_store (&cerror, &store);
      *errind = 2001;
      return;
   }
   for (i = 0; i < *esn; i++)
   {
      es[i] = highl_filter->excl_set.ints[i];
   }

   pdel_store (&cerror, &store);
   *errind = 0;
}
