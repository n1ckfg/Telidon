#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE MORE SIMULTANEOUS EVENTS - see  if  there  are  more
     simultaneous events on the input queue

  FORTRAN Syntax
     SUBROUTINE pqsim ( ERRIND, FLAG )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     FLAG              OUT more simultaneous events (PNMORE, PMORE)
**************************************************************************/
#ifdef NO_PROTO
nqsim (errind, flag)
   integer      *errind,
            *flag;
#else
nqsim (integer *errind, integer *flag)
#endif
{
   Pint  cerror;
   Pmore_simult_events events;
/**************************************************************************
  C Syntax
     void
     pinq_more_simult_events ( errind, events )
     Pint        *errind;          OUT error indicator
     Pmore_simult_events           *events;OUT simultaneous events
**************************************************************************/

   pinq_more_simult_events (&cerror, &events);
   *errind = cerror;

   *flag = events;
   switch (events)
   {
   case PSIMULT_NO_MORE:
      *flag = 0;
      break;
   case PSIMULT_MORE:
      *flag = 1;
      break;
   }
}
