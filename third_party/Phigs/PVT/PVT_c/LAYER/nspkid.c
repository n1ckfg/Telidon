#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PICK  IDENTIFIER  -  create  structure  element  to  set
     current pick identifier attribute

  FORTRAN Syntax
     SUBROUTINE pspkid ( PKID )
     INTEGER     PKID              pick identifier
**************************************************************************/
#ifdef NO_PROTO
nspkid (pkid)
   integer      *pkid;
#else
nspkid (integer *pkid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_pick_id ( pick_id )
     Pint        pick_id;          pick identifier
**************************************************************************/

   pset_pick_id ((Pint) *pkid);
}
