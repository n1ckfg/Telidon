#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF AVAILABLE GENERALIZED STRUCTURE  ELEMENTS  -
     obtain  list  of workstation-dependent generalized structure
     elements

  FORTRAN Syntax
     SUBROUTINE pqegse ( WTYPE, N, ERRIND, NGSE, GSEL )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NGSE              OUT number of available generalized
                                   structure elements
     INTEGER     GSEL              OUT Nth element of list of GSE identifiers
**************************************************************************/
#ifdef NO_PROTO
nqegse (wtype, n, errind, ngse, gsel)
   integer      *wtype,
            *n,
            *errind,
            *ngse,
            *gsel;
#else
nqegse (integer *wtype, integer *n, integer *errind, integer *ngse, 
        integer *gsel)
#endif
{
   Pint_list gses;
   Pint      length, cerror, start;
   Pint      total_length;

   start = *n - (*n > 0);
   length = (*n != 0);
   gses.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_avail_gse ( type, length, start, errind, gses, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *gses;            OUT list of GSEs
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_avail_gdp ((Pint) *wtype, length, start, &cerror, &gses, 
                        &total_length);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *ngse = total_length;
   if (gses.num_ints == 1)
      *gsel = gses.ints[0];

   free (gses.ints);
}
