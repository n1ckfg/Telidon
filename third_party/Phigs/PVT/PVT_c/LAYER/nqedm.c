#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE EDIT MODE - obtain current edit mode for structure

  FORTRAN Syntax
     SUBROUTINE pqedm ( ERRIND, EDITMO )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     EDITMO            OUT edit mode (PINSRT, PREPLC)
**************************************************************************/
#ifdef NO_PROTO
nqedm (errind, editmo)
   integer      *errind,
            *editmo;
#else
nqedm (integer *errind, integer *editmo)
#endif

{
   Pedit_mode edit_mode;
   Pint cerror;

/**************************************************************************
   Pedit_mode edit_mode;
  C Syntax
     void
     pinq_edit_mode ( errind, edit_mode )
     Pint        *errind;          OUT error indicator
     Pedit_mode  *edit_mode;       OUT edit mode
**************************************************************************/

   pinq_edit_mode (&cerror, &edit_mode);
   *errind = cerror;

   *editmo = edit_mode;
   switch (edit_mode)
   {
   case PEDIT_INSERT:
      *editmo = 0;
      break;
   case PEDIT_REPLACE:
      *editmo = 1;
      break;
   }
}
