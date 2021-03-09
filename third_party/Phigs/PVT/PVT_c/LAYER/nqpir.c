#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED INTERIOR REPRESENTATION -  obtain  prede-
     fined interior representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqpir ( WTYPE, PII, ERRIND, STYLE, STYLID, COLI )
     INTEGER     WTYPE             workstation type
     INTEGER     PII               predefined interior index
     INTEGER     ERRIND            OUT error indicator
     INTEGER     STYLE             OUT interior style
     INTEGER     STYLID            OUT interior style index
     INTEGER     COLI              OUT interior colour index
**************************************************************************/
#ifdef NO_PROTO
nqpir (wtype, pii, errind, style, stylid, coli)
   integer      *wtype,
            *pii,
            *errind,
            *style,
            *stylid,
            *coli;
#else
nqpir (integer *wtype, integer *pii, integer *errind, 
       integer *style, integer *stylid, integer *coli)
#endif
{
   Pint_bundle bundle;
   Pint        cerror;
/**************************************************************************
  C Syntax
     void
     pinq_pred_int_rep ( type, index, errind, bundle )
     Pint        type;             workstation type
     Pint        index;            predefined index
     Pint        *errind;          OUT error indicator
     Pint_bundle *bundle;          OUT predefined interior rep
**************************************************************************/

   pinq_pred_int_rep ((Pint) *wtype, (Pint) *pii, &cerror, &bundle);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *stylid = bundle.style_ind;
   *coli = bundle.colr_ind;

   *style = bundle.style;
   if (bundle.style == PSTYLE_HOLLOW) *style = 0;
   if (bundle.style == PSTYLE_SOLID)  *style = 1;
   if (bundle.style == PSTYLE_PAT)    *style = 2;
   if (bundle.style == PSTYLE_HATCH)  *style = 3;
   if (bundle.style == PSTYLE_EMPTY)  *style = 4;
}
