#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE EDGE REPRESENTATION - obtain edge representation  on
     specified workstation

  FORTRAN Syntax
     SUBROUTINE pqedr ( WKID, EDI, TYPE, ERRIND, EDFLAG, EDTYPE, EWIDTH, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     EDI               edge index
     INTEGER     TYPE              type of returned values (PSET, PREALI)
     INTEGER     ERRIND            OUT error indicator
     INTEGER     EDFLAG            OUT edge flag (POFF, PON)
     INTEGER     EDTYPE            OUT edge type
     REAL        EWIDTH            OUT edgewidth scale factor
     INTEGER     COLI              OUT edge colour index
**************************************************************************/
#ifdef NO_PROTO
nqedr (wkid, edi, type, errind, edflag, edtype, ewidth, coli)
   integer      *wkid,
            *edi,
            *type,
            *errind,
            *edflag,
            *edtype,
            *coli;
   real    *ewidth;
#else
nqedr (integer *wkid, integer *edi, integer *type, integer *errind, integer *edflag, integer *edtype,
       real *ewidth, integer *coli)
#endif
{
   Pint cerror;
   Pinq_type inq_type;
   Pedge_bundle rep;

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
     pinq_edge_rep ( ws, index, type, errind, rep )
     Pint        ws;               workstation identifier
     Pint        index;            edge index
     Pinq_type   type;             type of returned value
     Pint        *errind;          OUT error indicator
     Pedge_bundle                  *rep;OUT edge representation
**************************************************************************/

   pinq_edge_rep ((Pint) *wkid, (Pint) *edi, inq_type, &cerror, &rep);
   *errind = cerror;
   *edtype = rep.type;
   *ewidth = rep.width;
   *coli = rep.colr_ind;

   *edflag = rep.flag;
   if (rep.flag == PEDGE_OFF) *edflag = 0;
   if (rep.flag == PEDGE_ON)  *edflag = 1;
}
