#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE EDGE FACILITIES - obtain list  of  workstation  edge
     facilities

  FORTRAN Syntax
     SUBROUTINE pqedf ( WTYPE, N, ERRIND, NEDT, EDT, NEDW, NOMEDW, REDWMN,
                                             REDWMX,
         NPEDI )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NEDT              OUT number of available edgetypes
     INTEGER     EDT               OUT Nth element of list of available edgetypes
     INTEGER     NEDW              OUT number of available edgewidths
     REAL        NOMEDW            OUT nominal edgewidth
     REAL        REDWMN, REDWMX    OUT range of edgewidths
     INTEGER     NPEDI             OUT number of predefined edge indices
**************************************************************************/
#ifdef NO_PROTO
nqedf (wtype, n, errind, nedt, edt, nedw, nomedw, redwmn, redwmx, npedi)
   integer      *wtype,
            *n,
            *errind,
            *nedt,
            *edt,
            *nedw,
            *npedi;
   real    *nomedw,
            *redwmn,
            *redwmx;
#else
nqedf (integer *wtype, integer *n, integer *errind, integer *nedt, integer *edt, integer *nedw,
       real *nomedw, real *redwmn, real *redwmx, integer *npedi)
#endif
{
   Pint      length, start, cerror, total_length;
   Pedge_facs facilities;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   
   facilities.types.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_edge_facs ( type, length, start, errind, facilities, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pedge_facs  *facilities;      OUT edge facilities
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_edge_facs ((Pint) *wtype, length, start,
       &cerror, &facilities, &total_length);
   *errind = cerror;

   *nedt = total_length;
   *edt = *facilities.types.ints;
   *nedw = facilities.num_widths;
   *nomedw = facilities.nom_width;
   *redwmn = facilities.min_width;
   *redwmx = facilities.max_width;
   *npedi = facilities.num_pred_inds;

   free (facilities.types.ints);
}
