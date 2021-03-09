#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET LINETYPE - create structure element to set current line-
     type attribute

  FORTRAN Syntax
     SUBROUTINE psln ( LTYPE )
     INTEGER     LTYPE             linetype
**************************************************************************/
#ifdef NO_PROTO
nsln (ltype)
   integer      *ltype;
#else
nsln (integer *ltype)
#endif
{


/**************************************************************************
  C Syntax
     void
     pset_linetype ( linetype )
     Pint        linetype;         linetype
**************************************************************************/

   pset_linetype ((Pint) *ltype);
}
