#include <phigs.h>
#include "f2c.h"

/**************************************************************************

NAME
     INQUIRE POLYLINE REPRESENTATION - obtain polyline  represen-
     tation on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqplr ( WKID, PLI, TYPE, ERRIND, LTYPE, LWIDTH, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     PLI               polyline index
     INTEGER     TYPE              type of returned values (PSET,PREALI)
     INTEGER     ERRIND            OUT error indicator
     INTEGER     LTYPE             OUT linetype
     REAL        LWIDTH            OUT linewidth scale factor
     INTEGER     COLI              OUT polyline colour index
**************************************************************************/
#ifdef NO_PROTO
nqplr (wkid, pli, type, errind, ltype, lwidth, coli)
   integer      *wkid,
            *pli,
            *type,
            *errind,
            *ltype,
            *coli;
   real    *lwidth;
#else
nqplr (integer *wkid, integer *pli, integer *type, integer *errind, 
       integer *ltype,
       real *lwidth, integer *coli)
#endif
{
   Pinq_type inq_type;
   Pline_bundle rep;
   Pint     cerror;

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
     pinq_line_rep ( ws, index, type, errind, rep )
     Pint        ws;               workstation identifier
     Pint        index;            polyline index
     Pinq_type   type;             type of returned value
     Pint        *errind;          OUT error indicator
     Pline_bundle                  *rep;OUT polyline representation
**************************************************************************/

   pinq_line_rep ((Pint) *wkid, (Pint) *pli, inq_type, &cerror, &rep);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *ltype = rep.type;
   *lwidth = rep.width;
   *coli = rep.colr_ind;
}
