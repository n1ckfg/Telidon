#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     GENERALIZED STRUCTURE ELEMENT - create generalized structure
     element

  FORTRAN Syntax
     SUBROUTINE pgse ( GSEID, LDR, DATREC )
     INTEGER     GSEID             GSE identifier
     INTEGER     LDR               dimension of data record array
     CHARACTER*80                  DATREC(LDR)data record
**************************************************************************/


#ifdef NO_PROTO
ngse (gseid, ldr, datrec, clen)
   integer      *gseid,
            *ldr,
             clen;
   cdatrec  *datrec;
#else
ngse (integer *gseid, integer *ldr, cdatrec * datrec, integer clen)
#endif
{
   Pgse_data gse;
   switch (*gseid)
   {

   /**********    There are no registered gse's at this time, add the
                  structure conversions here as they are defined        *********/
   default:
   /*** Uknown, send in Pdata stucture  ****/
      gse.unsupp.size = sizeof (cdatrec);
      gse.unsupp.data = (void *) datrec;
   }

/**************************************************************************
  C Syntax
     void
     pgse ( id, gse )
     Pint        id;               gse identifier
     Pgse_data   *gse;             gse data record
**************************************************************************/

   pgse ((Pint) *gseid, &gse);
}
