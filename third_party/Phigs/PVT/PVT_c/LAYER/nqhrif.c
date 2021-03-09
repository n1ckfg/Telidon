#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE HLHSR IDENTIFIER FACILITIES - inquire for  available
     hidden line and hidden surface removal identifiers of speci-
     fied workstation type

  FORTRAN Syntax
     SUBROUTINE pqhrif ( WTYPE, NI, ERRIND, NHRID, HRID, NHRMD, HRMD )
     INTEGER     WTYPE             workstation type
     INTEGER     NI                sequence number of HLHSR identifier list
                                   element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NHRID             OUT number of available HLHSR identifiers
     INTEGER     HRID              OUT NIth element of list of available
                                   HLHSR identifiers
**************************************************************************/
#ifdef NO_PROTO
nqhrif (wtype, n, errind, nhrid, hrid)
   integer   *wtype,
            *n,
            *errind,
            *nhrid,
            *hrid;
#else
nqhrif (integer *wtype, integer *n, integer *errind, integer *nhrid, 
        integer *hrid)
#endif
{
   Pint      length, cerror, start, total_length;
   Pint_list list;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   list.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_hlhsr_id_facs ( type, length, start, errind, ids, length_list )
     Pint        type;             workstation type
     Pint        length;           length of id list
     Pint        start;            starting position of id list
     Pint        *errind;          OUT error indicator
     Pint_list   *ids;             OUT list of HLHSR identifiers
     Pint        *length_list;     OUT length of id list in PHIGS
**************************************************************************/

   pinq_hlhsr_id_facs ((Pint) *wtype, length, start, &cerror, &list, 
                       &total_length);
   *errind = cerror;

   *nhrid = total_length;
   *hrid = list.ints[0];

   free (list.ints);
}
