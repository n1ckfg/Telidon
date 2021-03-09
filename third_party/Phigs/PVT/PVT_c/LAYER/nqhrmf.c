#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE HLHSR MODE FACILITIES - inquire for hidden line  and
     hidden surface removal modes of specified workstation type

  FORTRAN Syntax
     SUBROUTINE pqhrmf ( WTYPE, NM, ERRIND, NHRMD, HRMD )
     INTEGER     WTYPE             workstation type
     INTEGER     NM                sequence number of HLHSR mode list element
                                   requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NHRMD             OUT number of available HLHSR modes
     INTEGER     HRMD              OUT NMth element of list of available
                                   HLHSR modes
**************************************************************************/
#ifdef NO_PROTO
nqhrmf (wtype, n, errind, nhrid, hrid)
   integer      *wtype,
            *n,
            *errind,
            *nhrid,
            *hrid;
#else
nqhrmf (integer *wtype, integer *n, integer *errind, integer *nhrid, 
        integer *hrid)
#endif
{
   Pint      start, cerror, length, total_length;
   Pint_list ids;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   ids.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_hlhsr_mode_facs ( type, length, start, errind, modes, length_list )
     Pint        type;             workstation type
     Pint        length;           length of mode list
     Pint        start;            starting position of mode list
     Pint        *errind;          OUT error indicator
     Pint_list   *modes;           OUT list of HLHSR modes
     Pint        *length_list;     OUT length of mode list in PHIGS
**************************************************************************/

   pinq_hlhsr_mode_facs ((Pint) *wtype, length, start, &cerror, &ids, 
                          &total_length);
   *errind = cerror;

   *nhrid = total_length;
   *hrid = *ids.ints;
   free (ids.ints);
}
