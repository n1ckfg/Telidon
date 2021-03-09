#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE POLYMARKER FACILITIES - obtain list  of  workstation
     polymarker facilities

  FORTRAN Syntax
     SUBROUTINE pqpmf ( WTYPE, N, ERRIND, NMT, MT, NMS, NOMMS, RMSMIN, RMSMAX,
                                           NPPMI )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NMT               OUT number of available marker types
     INTEGER     MT                OUT Nth element of list of available marker types
     INTEGER     NMS               OUT number of available marker sizes
     REAL        NOMMS             OUT nominal marker size (DC)
     REAL        RMSMIN, RMSMAX    OUT range of marker sizes (DC)
     INTEGER     NPPMI             OUT number of predefined polymarker indices
**************************************************************************/
#ifdef NO_PROTO
nqpmf (wtype, n, errind, nmt, mt, nms, nomms, rmsmin, rmsmax, nppmi)
   integer      *wtype,
            *n,
            *errind,
            *nmt,
            *mt,
            *nms,
            *nppmi;
   real    *nomms,
            *rmsmin,
            *rmsmax;
#else
nqpmf (integer *wtype, integer *n, integer *errind, integer *nmt, 
       integer *mt, integer *nms,
       real *nomms, real *rmsmin, real *rmsmax, integer *nppmi)
#endif
{
   Pmarker_facs facilities;
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
     pinq_marker_facs ( type, length, start, errind, facilities, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pmarker_facs                  *facilities;OUT polymarker facilities
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_marker_facs ((Pint) *wtype, length, start, &cerror, &facilities, 
                     &total_length);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *nmt = total_length;
   *mt = *facilities.types.ints;
   *nms = facilities.num_sizes;
   *nomms = facilities.nom_size;
   *rmsmin = facilities.min_size;
   *rmsmax = facilities.max_size;
   *nppmi = facilities.num_pred_inds;

   free (facilities.types.ints);
}
