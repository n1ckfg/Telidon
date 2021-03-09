#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PREDEFINED TEXT REPRESENTATION -  obtain  predefined
     text representation for workstation type

  FORTRAN Syntax
     SUBROUTINE pqptxr ( WTYPE, PTXI, ERRIND, FONT, PREC, CHXP, CHSP, COLI )
     INTEGER     WTYPE             workstation type
     INTEGER     PTXI              predefined text index
     INTEGER     ERRIND            OUT error indicator
     INTEGER     FONT              OUT text font
     INTEGER     PREC              OUT text precision (PSTRP, PCHARP, PSTRKP)
     REAL        CHXP              OUT character expansion factor
     REAL        CHSP              OUT character spacing
     INTEGER     COLI              OUT text colour index
**************************************************************************/
#ifdef NO_PROTO
nqptxr (wtype, ptxi, errind, font, prec, chxp, chsp, coli)
   integer      *wtype,
            *ptxi,
            *errind,
            *font,
            *prec,
            *coli;
   real    *chxp,
            *chsp;
#else
nqptxr (integer *wtype, integer *ptxi, integer *errind, integer *font, integer *prec,
	real *chxp, real *chsp, integer *coli)
#endif
{
   Ptext_bundle bundle;
   Pint         cerror;
/**************************************************************************
  C Syntax
     void
     pinq_pred_text_rep ( type, index, errind, bundle )
     Pint        type;             workstation type
     Pint        index;            predefined index
     Pint        *errind;          OUT error indicator
     Ptext_bundle                  *bundle;OUT predefined text rep
**************************************************************************/

   pinq_pred_text_rep ((Pint) *wtype, (Pint) *ptxi, &cerror, &bundle);
   *errind = cerror;

   *font = bundle.font;
   *chxp = bundle.char_expan;
   *chsp = bundle.char_space;
   *coli = bundle.colr_ind;

   *prec = bundle.prec;
   if (bundle.prec == PPREC_STRING) *prec = 0;
   if (bundle.prec == PPREC_CHAR)   *prec = 1;
   if (bundle.prec == PPREC_STROKE) *prec = 2;
}
