#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET TEXT INDEX - create structure  element  containing  text
     representation index attribute

  FORTRAN Syntax
     SUBROUTINE pstxi ( TXI )
     INTEGER     TXI               text index
**************************************************************************/
#ifdef NO_PROTO
nstxi (txi)
   integer      *txi;
#else
nstxi (integer *txi)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_text_ind ( index )
     Pint        index;            text index
**************************************************************************/

   pset_text_ind ((Pint) *txi);
}
