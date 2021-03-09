#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION STATE VALUE - obtain  workstation  state
     value

  FORTRAN Syntax
     SUBROUTINE pqwkst ( WKSTA )
     INTEGER     WKSTA             OUT workstation state value (PWSCL, PWSOP)
**************************************************************************/
#ifdef NO_PROTO
nqwkst (wksta)
   integer      *wksta;
#else
nqwkst (integer *wksta)
#endif
{
   Pws_st    ws_state;
/**************************************************************************
  C Syntax
     void
     pinq_ws_st ( ws_state )
     Pws_st      *ws_state;        OUT workstation state
**************************************************************************/

   pinq_ws_st (&ws_state);

   *wksta = ws_state;
   if (ws_state == PWS_ST_WSCL)
      *wksta = 0;
   else if (ws_state == PWS_ST_WSOP)
      *wksta = 1;
}
