#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDIT MODE - set edit  mode  to  controladdition  of  new
     structure elements to open structure

  FORTRAN Syntax
     SUBROUTINE psedm ( EDITMO )
     INTEGER     EDITMO            edit mode (PINSRT, PREPLC)
**************************************************************************/
#ifdef NO_PROTO
nsedm (editmo)
   integer      *editmo;
#else
nsedm (integer *editmo)
#endif
{
   Pedit_mode mode;

   mode = *editmo;
   if (*editmo == 0)
      mode = PEDIT_INSERT;
   else if (*editmo == 1)
      mode = PEDIT_REPLACE;

/**************************************************************************
  C Syntax
     void
     pset_edit_mode ( mode )
     Pedit_mode  mode;             edit mode
**************************************************************************/

   pset_edit_mode (mode);
}
