#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ANNOTATION STYLE  -  create  structure  element  to  set
     current annotation style attribute

  FORTRAN Syntax
     SUBROUTINE psans ( ASTYLE )
     INTEGER     ASTYLE            annotation style
**************************************************************************/
#ifdef NO_PROTO
nsans (astyle)
   integer      *astyle;
#else
nsans (integer *astyle)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_anno_style ( style )
     Pint        style;            annotation style
**************************************************************************/

   pset_anno_style ((Pint) *astyle);
}
