#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET POLYLINE REPRESENTATION - define polyline attribute bun-
     dle on workstation

  FORTRAN Syntax
     SUBROUTINE psplr ( WKID, PLI, LTYPE, LWIDTH, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     PLI               polyline index
     INTEGER     LTYPE             linetype
     REAL        LWIDTH            linewidth scale factor
     INTEGER     COLI              colour index
**************************************************************************/
#ifdef NO_PROTO
nsplr (wkid, pli, ltype, lwidth, coli)
   integer      *wkid,
            *pli,
            *ltype,
            *coli;
   real    *lwidth;
#else
nsplr (integer *wkid, integer *pli, integer *ltype, real *lwidth, integer *coli)
#endif
{
   Pline_bundle rep;
   rep.type = *ltype;
   rep.width = *lwidth;
   rep.colr_ind = *coli;

/**************************************************************************
  C Syntax
     void
     pset_line_rep ( ws, index, rep )
     Pint           ws;            workstation identifier
     Pint           index;         polyline bundle index
     Pline_bundle   *rep;          polyline representation pointer
**************************************************************************/

   pset_line_rep ((Pint) *wkid, (Pint) *pli, &rep);
}
