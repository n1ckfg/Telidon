#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE COLOUR REPRESENTATION - obtain colour representation
     on workstation

  FORTRAN Syntax
     SUBROUTINE pqcr ( WKID, COLI, CCSBSZ, TYPE, ERRIND, OL, SPEC )
     INTEGER     WKID         workstation identifier
     INTEGER     COLI         colour index
     INTEGER     CCSBSZ       colour component specification buffer size
     INTEGER     TYPE         type of returned values (PSET, PREALI)
     INTEGER     ERRIND       OUT error indicator
     INTEGER     OL           number of colour components in the colour specification
     REAL        SPEC(CCSBSZ) colour specification
**************************************************************************/
#ifdef NO_PROTO
nqcr (wkid, coli, ccsbsz, type, errind, ol, spec)
   integer      *wkid,
            *coli,
            *ccsbsz,
            *type,
            *errind,
            *ol;
   real     spec[];
#else
nqcr (integer *wkid, integer *coli, integer *ccsbsz, integer *type, integer *errind, integer *ol,
      real spec[])
#endif
{
   Pint cerror;
   Pinq_type inq_type;
   Pcolr_rep col_rep;

   inq_type = *type;
   switch (*type)
   {
   case 0:
      inq_type = PINQ_SET;
      break;
   case 1:
      inq_type = PINQ_REALIZED;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pinq_colr_rep ( ws, index, type, errind, rep )
     Pint        ws;          workstation identifier
     Pint        index;       colour index
     Pinq_type   type;        type of returned value
     Pint        *errind;          OUT error indicator
     Pcolr_rep   *rep;        OUT colour representation
**************************************************************************/

   pinq_colr_rep ((Pint) *wkid, (Pint) *coli, inq_type, &cerror, &col_rep);
   *errind = cerror;

   /* Make sure buffer can hold 3 items */
   if (*ccsbsz < 3) {
       *errind = 2001; /* This is a FORTRAN error, we must use */
       return;         /* is since C has no equivalent         */
   }

   spec[0] = col_rep.rgb.red;
   spec[1] = col_rep.rgb.green;
   spec[2] = col_rep.rgb.blue;
   *ol = 3;
}
