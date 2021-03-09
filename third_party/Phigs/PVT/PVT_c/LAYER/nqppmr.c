#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED POLYMARKER REPRESENTATION - obtain prede-
     fined polymarker representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqppmr ( WTYPE, PMI, ERRIND, MTYPE, MSZSF, COLI )
     INTEGER     WTYPE             workstation type
     INTEGER     PMI               predefined polymarker index
     INTEGER     ERRIND            OUT error indicator
     INTEGER     MTYPE             OUT marker type
     REAL        MSZSF             OUT marker size scale factor
     INTEGER     COLI              OUT polymarker colour index
**************************************************************************/
#ifdef NO_PROTO
nqppmr (wtype, pmi, errind, mtype, mszsf, coli)
   integer      *wtype,
            *pmi,
            *errind,
            *mtype,
            *coli;
   real    *mszsf;
#else
nqppmr (integer *wtype, integer *pmi, integer *errind, integer *mtype, 
        real *mszsf, integer *coli)
#endif
{
   Pmarker_bundle bundle;
   Pint           cerror;
/**************************************************************************
  C Syntax
     void
     pinq_pred_marker_rep ( type, index, errind, bundle )
     Pint        type;             workstation type
     Pint        index;            predefined index
     Pint        *errind;          OUT error indicator
     Pmarker_bundle                *bundle;OUT predefined polymarker rep
**************************************************************************/

   pinq_pred_marker_rep ((Pint) *wtype, (Pint) *pmi, &cerror, &bundle);
   *errind = cerror;

   *mtype = bundle.type;
   *mszsf = bundle.size;
   *coli = bundle.colr_ind;
}
