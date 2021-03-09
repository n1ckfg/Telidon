#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF AVAILABLE GENERALIZED DRAWING  PRIMITIVES  -
     obtain  list of workstation-available 2D generalized drawing
     primitives

  FORTRAN Syntax
     SUBROUTINE pqegdp ( WTYPE, N, ERRIND, NGDP, GDPL )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NGDP              OUT number of available generalized
                                   drawing primitives
     INTEGER     GDPL              OUT Nth element of list of GDP identifiers
**************************************************************************/
#ifdef NO_PROTO
nqegdp (wtype, n, errind, ngdp, gdpl)
   integer      *wtype,
            *n,
            *errind,
            *ngdp,
            *gdpl;
#else
nqegdp (integer *wtype, integer *n, integer *errind, integer *ngdp, 
        integer *gdpl)
#endif
{
   Pint_list gdps;
   Pint      length, cerror, start;
   Pint      total_length;

   start = *n - (*n > 0);
   length = (*n != 0);

   gdps.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_avail_gdp ( type, length, start, errind, gdps, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *gdps;            OUT list of GDP identifiers
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_avail_gdp ((Pint) *wtype, length, start, &cerror, &gdps, 
                        &total_length);
   *errind = cerror;

   *ngdp = total_length;
   if (gdps.num_ints == 1)
      *gdpl = gdps.ints[0];

   free (gdps.ints);
}
