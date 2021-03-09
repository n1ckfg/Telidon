#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ANNOTATION TEXT PATH - create structure element  to  set
     current text path attribute

  FORTRAN Syntax
     SUBROUTINE psatp ( ATP )
     INTEGER     ATP               annotation text path (PRIGHT, PLEFT,
                                   PUP, PDOWN)
**************************************************************************/
#ifdef NO_PROTO
nsatp (atp)
   integer      *atp;
#else
nsatp (integer *atp)
#endif
{
   Ptext_path path;

   path = *atp;
   switch (*atp)
   {
   case 0:
      path = PPATH_RIGHT;
      break;
   case 1:
      path = PPATH_LEFT;
      break;
   case 2:
      path = PPATH_UP;
      break;
   case 3:
      path = PPATH_DOWN;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_anno_path ( path )
     Ptext_path  path;             text path
**************************************************************************/

   pset_anno_path (path);
}
