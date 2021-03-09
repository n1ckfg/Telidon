#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET HLHSR IDENTIFIER  -  create  structure  element  to  set
     current  hidden line and hidden surface removal  HLHSR iden-
     tifier attribute

  FORTRAN Syntax
     SUBROUTINE pshrid ( HRID )
     INTEGER     HRID              HLHSR identifier
**************************************************************************/
#ifdef NO_PROTO
nshrid (hrid)
   integer      *hrid;
#else
nshrid (integer *hrid)
#endif
{


/**************************************************************************
  C Syntax
     void
     pset_hlhsr_id ( id )
     Pint        id;               HLHSR identifier
**************************************************************************/

   pset_hlhsr_id ((Pint) *hrid);
}
