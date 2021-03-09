#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE CONFLICT RESOLUTION - obtain current values of  con-
     flict resolution flags

  FORTRAN Syntax
     SUBROUTINE pqcnrs ( ERRIND, ARCCR, RETCR )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     ARCCR             OUT archival conflict resolution
     INTEGER     RETCR             OUT retrieval conflict resolution
**************************************************************************/
#ifdef NO_PROTO
nqcnrs (errind, arccr, retcr)
   integer      *errind,
            *arccr,
            *retcr;
#else
nqcnrs (integer *errind, integer *arccr, integer *retcr)
#endif
{
   Pconf_res archive;
   Pconf_res retrieval;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_conf_res ( errind, archive, retrieval )
     Pint        *errind;          OUT error indicator
     Pconf_res   *archive;         OUT archival resolution
     Pconf_res   *retrieval;       OUT retrieval resolution
**************************************************************************/

   pinq_conf_res (&cerror, &archive, &retrieval);
   *errind = cerror;

   *arccr = archive;
   switch (archive)
   {
   case PRES_MAINTAIN:
      *arccr = 0;
      break;
   case PRES_ABANDON:
      *arccr = 1;
      break;
   case PRES_UPD:
      *arccr = 2;
      break;
   }

   *retcr = retrieval;
   switch (retrieval)
   {
   case PRES_MAINTAIN:
      *retcr = 0;
      break;
   case PRES_ABANDON:
      *retcr = 1;
      break;
   case PRES_UPD:
      *retcr = 2;
      break;
   }
}
