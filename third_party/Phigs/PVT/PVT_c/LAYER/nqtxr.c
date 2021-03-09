#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE TEXT REPRESENTATION - obtain text representation  on
     workstation

  FORTRAN Syntax
     SUBROUTINE pqtxr ( WKID, TXI, TYPE, ERRIND, FONT, PREC, CHXP, CHSP, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     TXI               text index
     INTEGER     TYPE              type of returned values (PSET, PREALI)
     INTEGER     ERRIND            OUT error indicator
     INTEGER     FONT              OUT text font
     INTEGER     PREC              OUT text precision (PSTRP, PCHARP, PSTRKP)
     REAL        CHXP              OUT character expansion factor
     REAL        CHSP              OUT character spacing
     INTEGER     COLI              OUT text colour index
**************************************************************************/
#ifdef NO_PROTO
nqtxr (wkid, txi, type, errind, font, prec, chxp, chsp, coli)
   integer      *wkid,
            *txi,
            *type,
            *errind,
            *font,
            *prec,
            *coli;
   real    *chxp,
            *chsp;
#else
nqtxr (integer *wkid, integer *txi, integer *type, integer *errind, 
       integer *font, integer *prec,
       real *chxp, real *chsp, integer *coli)
#endif
{
   Pinq_type inq_type;
   Ptext_bundle rep;
   Pint   cerror;

   inq_type = *type;
   switch (*type)
   {
   case 0:
      inq_type = PINQ_SET;
      break;
   case 1:
      inq_type = PINQ_REALIZED;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pinq_text_rep ( ws, index, type, errind, rep )
     Pint        ws;               workstation identifier
     Pint        index;            text index
     Pinq_type   type;             type of returned value
     Pint        *errind;          OUT error indicator
     Ptext_bundle                  *rep;OUT text representation
**************************************************************************/

   pinq_text_rep ((Pint) *wkid, (Pint) *txi, inq_type, &cerror, &rep);
   *errind = cerror;

   *font = rep.font;
   *chxp = rep.char_expan;
   *chsp = rep.char_space;
   *coli = rep.colr_ind;

   *prec = rep.prec;
   if (rep.prec == PPREC_STRING) *prec = 0;
   if (rep.prec == PPREC_CHAR)   *prec = 1;
   if (rep.prec == PPREC_STROKE) *prec = 2;
}
