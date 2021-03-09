#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET TEXT COLOUR INDEX -  create  structure  element  to  set
     current text colour index attribute

  FORTRAN Syntax
     SUBROUTINE pstxci ( COLI )
     INTEGER     COLI              text colour index
**************************************************************************/
#ifdef NO_PROTO
nstxci (coli)
   integer      *coli;
#else
nstxci (integer *coli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_text_colr_ind ( colour )
     Pint        colour;           text colour index
**************************************************************************/

   pset_text_colr_ind ((Pint) *coli);
}
