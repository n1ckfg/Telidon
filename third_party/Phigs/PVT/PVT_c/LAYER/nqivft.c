#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE INVISIBILITY FILTER - obtain inclusion and exclusion
     name sets for specified workstation's invisibility filter

  FORTRAN Syntax
     SUBROUTINE pqivft ( WKID, ISBSZ, ESBSZ, ERRIND, ISN, IS, ESN, ES )
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
nqivft (wkid, isbsz, esbsz, errind, isn, is, esn, es)
   integer      *wkid,
            *isbsz,
            *esbsz,
            *errind,
            *isn,
             is[],
            *esn,
             es[];
#else
nqivft (integer *wkid, integer *isbsz, integer *esbsz, integer *errind, 
        integer *isn, integer is[], integer *esn, integer es[])
#endif
{  Pint      cerror;
   int       i;
   Pstore    store;
   Pfilter  *invis_filter;

/* Create the memory buffer if not already created. */

   pcreate_store (&cerror, &store);
   if (cerror)
   {
   /* Cannot create memory buffer */
      return;
   }

/**************************************************************************
  C Syntax
     void
     pinq_invis_filter ( ws, store, errind, invis_filter)
     Pint        ws;               workstation identifier
     Pstore      store;            handle to Store object
     Pint        *errind;          OUT error indicator
     Pfilter     **invis_filter    OUT invisibility filter
**************************************************************************/

   pinq_invis_filter ((Pint) *wkid, store, &cerror, &invis_filter);
   *errind = cerror;

   if (cerror)  /* check for errors first, before touching the data */
   {  
      int temp_errind;
      pdel_store (&temp_errind, &store);
      return;
   }

   *isn = invis_filter->incl_set.num_ints;

   if (*isbsz < *isn)
   {
      pdel_store (&cerror, &store);
      *errind = 2001;
      return;
   }
   for (i = 0; i < *isn; i++)
   {
      is[i] = invis_filter->incl_set.ints[i];
   }

   *esn = invis_filter->excl_set.num_ints;
   if (*esbsz < *esn)
   {

      pdel_store (&cerror, &store);
      *errind = 2001;
      return;
   }
   for (i = 0; i < *esn; i++)
   {
      es[i] = invis_filter->excl_set.ints[i];
   }

   pdel_store (&cerror, &store);
   *errind = 0;
}
