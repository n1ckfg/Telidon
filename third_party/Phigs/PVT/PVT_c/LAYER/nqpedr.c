#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED EDGE REPRESENTATION -  obtain  predefined
     edge representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqpedr ( WTYPE, PEDI, ERRIND, EDFLAG, EDTYPE, EWIDTH, COLI )
     INTEGER     WTYPE             workstation type
     INTEGER     PEDI              predefined edge index
     INTEGER     ERRIND            OUT error indicator
     INTEGER     EDFLAG            OUT edge flag (POFF, PON)
     INTEGER     EDTYPE            OUT edgetype
     REAL        EWIDTH            OUT edgewidth scale factor
     INTEGER     COLI              OUT edge colour index
**************************************************************************/
#ifdef NO_PROTO
nqpedr (wtype, pedi, errind, edflag, edtype, ewidth, coli)
   integer      *wtype,
            *pedi,
            *errind,
            *edflag,
            *edtype,
            *coli;
   real    *ewidth;
#else
nqpedr (integer *wtype, integer *pedi, integer *errind, 
        integer *edflag, integer *edtype,
        real *ewidth, integer *coli)
#endif
{
   Pedge_bundle bundle;
   Pint         cerror;
/**************************************************************************
  C Syntax
     void
     pinq_pred_edge_rep ( type, index, errind, bundle )
     Pint           type;             workstation type
     Pint           index;            predefined index
     Pint           *errind;          OUT error indicator
     Pedge_bundle   *bundle           OUT predefined edge rep
**************************************************************************/

   pinq_pred_edge_rep ((Pint) *wtype, (Pint) *pedi, &cerror, &bundle);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *edtype = bundle.type;
   *ewidth = bundle.width;
   *coli = bundle.colr_ind;

   *edflag = bundle.flag;
   if (bundle.flag == PEDGE_OFF) *edflag = 0;
   if (bundle.flag == PEDGE_ON)  *edflag = 1;
}
