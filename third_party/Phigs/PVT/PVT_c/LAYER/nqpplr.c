#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED POLYLINE REPRESENTATION -  obtain  prede-
     fined polyline representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqpplr ( WTYPE, PLI, ERRIND, LTYPE, LWIDTH, COLI )
     INTEGER     WTYPE             workstation type
     INTEGER     PLI               predefined polyline index
     INTEGER     ERRIND            OUT error indicator
     INTEGER     LTYPE             OUT linetype
     REAL        LWIDTH            OUT linewidth scale factor
     INTEGER     COLI              OUT polyline colour index
**************************************************************************/
#ifdef NO_PROTO
nqpplr (wtype, pli, errind, ltype, lwidth, coli)
   integer      *wtype,
            *pli,
            *errind,
            *ltype,
            *coli;
   real    *lwidth;
#else
nqpplr (integer *wtype, integer *pli, integer *errind, integer *ltype, 
        real *lwidth, integer *coli)
#endif
{
   Pline_bundle bundle;
   Pint         cerror;
/**************************************************************************
  C Syntax
     void
     pinq_pred_line_rep ( type, index, errind, bundle )
     Pint        type;             workstation type
     Pint        index;            predefined index
     Pint        *errind;          OUT error indicator
     Pline_bundle                  *bundle;OUT predefined polyline rep
**************************************************************************/

   pinq_pred_line_rep ((Pint) *wtype, (Pint) *pli, &cerror, &bundle);
   *errind = cerror;

   *ltype = bundle.type;
   *lwidth = bundle.width;
   *coli = bundle.colr_ind;
}
