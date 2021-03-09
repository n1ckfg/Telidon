#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE SYSTEM STATE VALUE - obtain PHIGS state value

  FORTRAN Syntax
     SUBROUTINE pqsys ( SYSSTA )
     INTEGER     SYSSTA            OUT system state value (PPHCL, PPHOP)
**************************************************************************/
#ifdef NO_PROTO
nqsys (syssta)
   integer      *syssta;
#else
nqsys (integer *syssta)
#endif
{
   Psys_st   sys_state;
/**************************************************************************
  C Syntax
     void
     pinq_sys_st ( sys_state )
     Psys_st     *sys_state;       OUT the system state
**************************************************************************/

   pinq_sys_st (&sys_state);

   *syssta = sys_state;
   if (sys_state == PSYS_ST_PHCL)
      *syssta = 0;
   else if (sys_state == PSYS_ST_PHOP)
      *syssta = 1;
}
