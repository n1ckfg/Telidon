#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF AVAILABLE GENERALIZED DRAWING PRIMITIVES 3 -
     obtain  list of workstation-available 3D generalized drawing
     primitives

  FORTRAN Syntax
     SUBROUTINE pqegd3 ( WTYPE, N, ERRIND, NGDP, GDPL )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NGDP              OUT number of available 3D generalized
                                   drawing primitives
     INTEGER     GDPL              OUT Nth element of list of 3D GDP identifiers
**************************************************************************/
#ifdef NO_PROTO
nqegd3 (wtype, n, errind, ngdp, gdpl)
   integer      *wtype,
            *n,
            *errind,
            *ngdp,
            *gdpl;
#else
nqegd3 (integer *wtype, integer *n, integer *errind, integer *ngdp, integer *gdpl)
#endif
{
   Pint_list gdps;
   Pint      length, cerror, start;
   Pint      total_length;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/
   start = *n - (*n > 0);
   length = (*n != 0);

   gdps.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_avail_gdp3 ( type, length, start, errind, gdps, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *gdps;            OUT list of 3D GDP identifiers
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_avail_gdp3 ((Pint) *wtype, length, start, &cerror, &gdps, 
                          &total_length);
   *errind = cerror;

   *ngdp = total_length;
   if (gdps.num_ints == 1)
      *gdpl = gdps.ints[0];

   free (gdps.ints);
}
