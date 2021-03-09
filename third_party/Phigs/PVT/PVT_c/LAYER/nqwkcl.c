#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION CLASSIFICATION -  obtain  classification
     of specified workstation type

  FORTRAN Syntax
     SUBROUTINE pqwkcl ( WTYPE, ERRIND, VRTYPE )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     VRTYPE            OUT vector/raster/other type
**************************************************************************/
#ifdef NO_PROTO
nqwkcl (wtype, errind, vrtype)
   integer      *wtype,
            *errind,
            *vrtype;
#else
nqwkcl (integer *wtype, integer *errind, integer *vrtype)
#endif
{
   Pws_class class;
   Pint      cerror;
/**************************************************************************
  C Syntax
     void
     pinq_ws_class ( type, errind, class )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pws_class   *class;           OUT workstation class
**************************************************************************/

   pinq_ws_class ((Pint) *wtype, &cerror, &class);
   *errind = cerror;

   *vrtype = class;
   switch (class)
   {
   case PCLASS_VEC:
      *vrtype = 0;
      break;
   case PCLASS_RASTER:
      *vrtype = 1;
      break;
   case PCLASS_OTHER:
      *vrtype = 2;
      break;
   }
}
