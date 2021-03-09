#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE POLYLINE FACILITIES - obtain list of polyline facil-
     ities from workstation description table

  FORTRAN Syntax
     SUBROUTINE pqplf ( WTYPE, N, ERRIND, NLT, LT, NLW, NOMLW, RLWMIN, RLWMAX,
                                         NPPLI )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NLT               OUT number of available linetypes
     INTEGER     LT                OUT Nth element of list of available linetypes
     INTEGER     NLW               OUT number of available linewidths
     REAL        NOMLW             OUT nominal linewidth (DC)
     REAL        RLWMIN, RLWMAX    OUT range of linewidths (DC)
     INTEGER     NPPLI             OUT number of predefined polyline indices
**************************************************************************/
#ifdef NO_PROTO
nqplf (wtype, n, errind, nlt, lt, nlw, nomlw, rlwmin, rlwmax, nppli)
   integer      *wtype,
            *n,
            *errind,
            *nlt,
            *lt,
            *nlw,
            *nppli;
   real    *nomlw,
            *rlwmin,
            *rlwmax;
#else
nqplf (integer *wtype, integer *n, integer *errind, integer *nlt, 
       integer *lt, integer *nlw, real *nomlw, real *rlwmin, 
       real *rlwmax, integer *nppli)
#endif
{
   Pline_facs facilities;
   Pint      length, cerror, start;
   Pint      total_length;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   facilities.types.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_line_facs ( type, length, start, errind, facilities, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pline_facs  *facilities;      OUT polyline facilities
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_line_facs ((Pint) *wtype, length, start, &cerror, &facilities, 
                   &total_length);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *nlt = total_length;
   *lt = *facilities.types.ints;
   *nlw = facilities.num_widths;
   *nomlw = facilities.nom_width;
   *rlwmin = facilities.min_width;
   *rlwmax = facilities.max_width;
   *nppli = facilities.num_pred_inds;

   free (facilities.types.ints);
}
