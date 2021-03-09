#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET TEXT REPRESENTATION - define text  attribute  bundle  on
     workstation

  FORTRAN Syntax
     SUBROUTINE pstxr ( WKID, TXI, FONT, PREC, CHXP, CHSP, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     TXI               text index
     INTEGER     FONT              text font
     INTEGER     PREC              text precision (PSTRP, PCHARP, PSTRKP)
     REAL        CHXP              character expansion factor
     REAL        CHSP              character spacing
     INTEGER     COLI              text colour index
**************************************************************************/
#ifdef NO_PROTO
nstxr (wkid, txi, font, prec, chxp, chsp, coli)
   integer      *wkid,
            *txi,
            *font,
            *prec,
            *coli;
   real    *chxp,
            *chsp;
#else
nstxr (integer *wkid, integer *txi, integer *font, integer *prec, real *chxp,
       real *chsp, integer *coli)
#endif
{
   Ptext_bundle rep;
   rep.font = *font;
   rep.char_expan = *chxp;
   rep.char_space = *chsp;
   rep.colr_ind = *coli;
   rep.prec = *prec;
   switch (*prec)
   {
   case 0:
      rep.prec = PPREC_STRING;
      break;
   case 1:
      rep.prec = PPREC_CHAR;
      break;
   case 2:
      rep.prec = PPREC_STROKE;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_text_rep ( ws, index, rep )
     Pint           ws;            workstation identifier
     Pint           index;         text bundle index
     Ptext_bundle   *rep;          text representation pointer
**************************************************************************/

   pset_text_rep ((Pint) *wkid, (Pint) *txi, &rep);
}
