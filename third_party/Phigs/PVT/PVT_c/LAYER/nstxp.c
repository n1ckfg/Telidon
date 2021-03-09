#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET TEXT PATH - create structure element to set current text
     path attribute

  FORTRAN Syntax
     SUBROUTINE pstxp ( TXP )
     INTEGER     TXP               text path (PRIGHT, PLEFT, PUP, PDOWN)
**************************************************************************/
#ifdef NO_PROTO
nstxp (txp)
   integer      *txp;
#else
nstxp (integer *txp)
#endif
{
   Ptext_path path;

   path = *txp;
   switch (*txp)
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
     pset_text_path ( path )
     Ptext_path  path;             text path
**************************************************************************/

   pset_text_path (path);
}
