#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE ARCHIVE STATE VALUE - obtain state value of  archive
     file

  FORTRAN Syntax
     SUBROUTINE pqars ( ARSTA )
     INTEGER     ARSTA             OUT archive state value (PARCL, PAROP)
**************************************************************************/
#ifdef NO_PROTO
nqars (arsta)
   integer      *arsta;
#else
nqars (integer *arsta)
#endif
{
   Par_st    archive_state;
/**************************************************************************
  C Syntax
     void
     pinq_ar_st ( archive_state )
     Par_st      *archive_state;   OUT archive state
**************************************************************************/

   pinq_ar_st (&archive_state);

   *arsta = archive_state;
   if (archive_state == PST_ARCL)
      *arsta = 0;
   else if (archive_state == PST_AROP)
      *arsta = 1;
}
