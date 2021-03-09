#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET TEXT PRECISION - create structure element to set current
     text precision attribute

  FORTRAN Syntax
     SUBROUTINE pstxpr ( PREC )
     INTEGER     PREC              text precision ( PSTRP, PCHARP, PSTRKP )
**************************************************************************/
#ifdef NO_PROTO
nstxpr (prec)
   integer      *prec;
#else
nstxpr (integer *prec)
#endif
{
   Ptext_prec precision;

   precision = *prec;
   switch (*prec)
   {
   case 0:
      precision = PPREC_STRING;
      break;
   case 1:
      precision = PPREC_CHAR;
      break;
   case 2:
      precision = PPREC_STROKE;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_text_prec ( precision )
     Ptext_prec  precision;        text precision
**************************************************************************/

   pset_text_prec (precision);
}
