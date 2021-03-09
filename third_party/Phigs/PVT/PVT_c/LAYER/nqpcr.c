#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED COLOUR REPRESENTATION - obtain predefined
     colour representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqpcr ( WTYPE, PCI, CCSBSZ, ERRIND, OL, CSPEC )
     INTEGER     WTYPE             workstation type
     INTEGER     PCI               predefined colour index
     INTEGER     CCSBSZ            colour component specification buffer size
     INTEGER     ERRIND            OUT error indicator
     REAL        CSPEC             OUT colour component array
     INTEGER     OL                OUT number of components in colour specification
**************************************************************************/
#ifdef NO_PROTO
nqpcr (wtype, coli, ccsbsz, errind, ol, spec)
   integer      *wtype,
            *coli,
            *ccsbsz,
            *errind,
            *ol;
   real     spec[];
#else
nqpcr (integer *wtype, integer *coli, integer *ccsbsz, integer *errind, 
       integer *ol, real spec[])
#endif
{
   Pcolr_rep col_rep;
   Pint      cerror;
/**************************************************************************
  C Syntax
     void
     pinq_pred_colr_rep ( type, index, errind, bundle )
     Pint        type;             workstation type
     Pint        index;            predefined index
     Pint        *errind;          OUT error indicator
     Pcolr_rep   *bundle;          OUT predefined colour rep
**************************************************************************/

   pinq_pred_colr_rep ((Pint) *wtype, (Pint) *coli, &cerror, &col_rep);
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
