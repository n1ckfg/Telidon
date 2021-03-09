#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET CONFLICT RESOLUTION - set conflict resolution flags

  FORTRAN Syntax
     SUBROUTINE pscnrs ( ARCCR, RETCR )
     INTEGER     ARCCR             archival conflict resolution
     INTEGER     RETCR             retrieval conflict resolution
**************************************************************************/
#ifdef NO_PROTO
nscnrs (arccr, retcr)
   integer      *arccr,
            *retcr;
#else
nscnrs (integer *arccr, integer *retcr)
#endif
{
   Pconf_res archival_resolution;
   Pconf_res retrieval_resolution;

   archival_resolution = *arccr;
   switch (*arccr)
   {
   case 0:
      archival_resolution = PRES_MAINTAIN;
      break;
   case 1:
      archival_resolution = PRES_ABANDON;
      break;
   case 2:
      archival_resolution = PRES_UPD;
      break;
   }

   retrieval_resolution = *retcr;
   switch (*retcr)
   {
   case 0:
      retrieval_resolution = PRES_MAINTAIN;
      break;
   case 1:
      retrieval_resolution = PRES_ABANDON;
      break;
   case 2:
      retrieval_resolution = PRES_UPD;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_conf_res ( archival_resolution, retrieval_resolution )
     Pconf_res   archival_resolution;archival conflict resolution
     Pconf_res   retrieval_resolution;retrieval conflict resolution
**************************************************************************/

   pset_conf_res (archival_resolution, retrieval_resolution);
}
