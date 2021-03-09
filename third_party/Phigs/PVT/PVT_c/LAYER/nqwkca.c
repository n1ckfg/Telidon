#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION CATEGORY - obtain category of  specified
     workstation type

  FORTRAN Syntax
     SUBROUTINE pqwkca ( WTYPE, ERRIND, WKCAT )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     WKCAT             OUT workstation category
**************************************************************************/
#ifdef NO_PROTO
nqwkca (wtype, errind, wkcat)
   integer      *wtype,
            *errind,
            *wkcat;
#else
nqwkca (integer *wtype, integer *errind, integer *wkcat)
#endif
{
   Pws_cat   category;
   Pint      cerror;
/**************************************************************************
  C Syntax
     void
     pinq_ws_cat ( type, errind, category )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pws_cat     *category;        OUT workstation category
**************************************************************************/

   pinq_ws_cat ((Pint) *wtype, &cerror, &category);
   *errind = cerror;

   *wkcat = category;
   switch (category)
   {
   case PCAT_OUT:
      *wkcat = 0;
      break;
   case PCAT_IN:
      *wkcat = 1;
      break;
   case PCAT_OUTIN:
      *wkcat = 2;
      break;
   case PCAT_MO:
      *wkcat = 3;
      break;
   case PCAT_MI:
      *wkcat = 4;
      break;
   }
}
