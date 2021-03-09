#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE STRUCTURE STATE VALUE  -  obtain  current  structure
     state value

  FORTRAN Syntax
     SUBROUTINE pqstrs ( STRSTA )
     INTEGER     STRSTA            OUT structure state value (PSTCL, PSTOP)
**************************************************************************/
#ifdef NO_PROTO
nqstrs (strsta)
   integer      *strsta;
#else
nqstrs (integer *strsta)
#endif
{
   Pstruct_st struct_state;
/**************************************************************************
  C Syntax
     void
     pinq_struct_st ( struct_state )
     Pstruct_st  *struct_state;    OUT structure state
**************************************************************************/

   pinq_struct_st (&struct_state);

   *strsta = struct_state;
   if (struct_state == PSTRUCT_ST_STCL)
      *strsta = 0;
   else if (struct_state == PSTRUCT_ST_STOP)
      *strsta = 1;
}
