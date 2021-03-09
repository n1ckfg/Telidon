#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF AVAILABLE WORKSTATION TYPES- obtain  current
     list of workstation types defined in PHIGS description table

  FORTRAN Syntax
     SUBROUTINE pqewk ( N, ERRIND, NUMBER, WKTYP )
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NUMBER            OUT number of workstation types
     INTEGER     WKTYP             OUT Nth element of list of available
                                   workstation types
**************************************************************************/
#ifdef NO_PROTO
nqewk (n, errind, number, wktyp)
   integer      *n,
            *errind,
            *number,
            *wktyp;
#else
nqewk (integer *n, integer *errind, integer *number, integer *wktyp)
#endif
{
   Pint      start, cerror, length, total_length;
   Pint_list types;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   types.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_avail_ws_types ( length, start, errind, types, length_list)
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *types;           OUT list of ws types
     Pint        *length_list;     OUT length of list in PHIGS
**************************************************************************/

   pinq_list_avail_ws_types (length, start, &cerror, &types, &total_length);
   *errind = cerror;

   *number = total_length;
   *wktyp = *types.ints;

   free (types.ints);
}
