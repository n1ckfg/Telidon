#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDGE REPRESENTATION - define edge  attribute  bundle  on
     workstation

  FORTRAN Syntax
     SUBROUTINE psedr ( WKID, EDI, EDFLAG, EDTYPE, EWIDTH, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     EDI               edge index
     INTEGER     EDFLAG            edge flag (POFF, PON)
     INTEGER     EDTYPE            edgetype
     REAL        EWIDTH            edgewidth scale factor
     INTEGER     COLI              edge colour index
**************************************************************************/
#ifdef NO_PROTO
nsedr (wkid, edi, edflag, edtype, ewidth, coli)
   integer      *wkid,
            *edi,
            *edflag,
            *edtype,
            *coli;
   real    *ewidth;
#else
nsedr (integer *wkid, integer *edi, integer *edflag, integer *edtype, real *ewidth, integer *coli)
#endif
{
   Pedge_bundle rep;
   rep.type = *edtype;
   rep.width = *ewidth;
   rep.colr_ind = *coli;
   rep.flag = *edflag;
   switch (*edflag)
   {
   case 0:
      rep.flag = PEDGE_OFF;
      break;
   case 1:
      rep.flag = PEDGE_ON;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_edge_rep ( ws, index, rep )
     Pint        ws;               workstation identifier
     Pint        index;            edge bundle index
     Pedge_bundle                  *rep;edge representation pointer
**************************************************************************/

   pset_edge_rep ((Pint) *wkid, (Pint) *edi, &rep);
}
