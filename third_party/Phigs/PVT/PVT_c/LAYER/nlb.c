#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     LABEL - create a structure element containing a label  iden-
     tifier

  FORTRAN Syntax
     SUBROUTINE plb ( LABEL )
     INTEGER     LABEL             label identifier
**************************************************************************/
#ifdef NO_PROTO
nlb (label)
   integer      *label;
#else
nlb (integer *label)
#endif
{

/**************************************************************************
  C Syntax
     void
     plabel ( label_id )
     Pint        label_id;         label identifier
**************************************************************************/

   plabel ((Pint) *label);
}
