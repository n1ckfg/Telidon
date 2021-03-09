#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE DYNAMICS OF WORKSTATION ATTRIBUTES - obtain dynamics
     of workstation attributes for specified workstation type

  FORTRAN Syntax
     SUBROUTINE pqdswa ( WTYPE, ERRIND, PLBUN, PMBUN, TXBUN, INBUN, EDBUN, PAREP,
         COLREP, VWREP, WKTR, HIFLTR, INFLTR, HLHSR )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            error indicator
     INTEGER     PLBUN             OUT polyline representation changeable
     INTEGER     PMBUN             OUT polymarker representation changeable
     INTEGER     TXBUN             OUT text representation changeable
     INTEGER     INBUN             OUT interior representation changeable
     INTEGER     EDBUN             OUT edge representation changeable
     INTEGER     PAREP             OUT pattern representation changeable
     INTEGER     COLREP            OUT colour representation changeable
     INTEGER     VWREP             OUT view representation changeable
     INTEGER     WKTR              OUT workstation transformation changeable
     INTEGER     HIFLTR            OUT highlighting filter changeable
     INTEGER     INFLTR            OUT invisibility filter changeable
     INTEGER     HLHSR             OUT HLHSR mode changeable
**************************************************************************/
#ifdef NO_PROTO
nqdswa (wtype, errind, plbun, pmbun, txbun, inbun, edbun, parep, colrep, vwrep, wktr, hifltr, infltr, hlhsr)
   integer      *wtype,
            *errind,
            *plbun,
            *pmbun,
            *txbun,
            *inbun,
            *edbun,
            *parep,
            *colrep,
            *vwrep,
            *wktr,
            *hifltr,
            *infltr,
            *hlhsr;
#else
nqdswa (integer *wtype, integer *errind, integer *plbun, integer *pmbun, integer *txbun,
        integer *inbun, integer *edbun, integer *parep, integer *colrep, integer *vwrep,
        integer *wktr, integer *hifltr, integer *infltr, integer *hlhsr)
#endif
{
   Pdyns_ws_attrs attr;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_dyns_ws_attrs ( type, errind, attr )
     Pint        ws_type;          workstation type
     Pint        *errind;          OUT error indicator
     Pdyns_ws_attrs  *attr         OUT attributes dynamics
**************************************************************************/

   pinq_dyns_ws_attrs ((Pint) *wtype, &cerror, &attr);
   *errind = cerror;

   *plbun = attr.line_bundle;
   if (attr.line_bundle == PDYN_IRG) *plbun = 0;
   if (attr.line_bundle == PDYN_IMM) *plbun = 1;
   if (attr.line_bundle == PDYN_CBS) *plbun = 2;

   *pmbun = attr.marker_bundle;
   if (attr.marker_bundle == PDYN_IRG) *pmbun = 0;
   if (attr.marker_bundle == PDYN_IMM) *pmbun = 1;
   if (attr.marker_bundle == PDYN_CBS) *pmbun = 2;

   *txbun = attr.text_bundle;
   if (attr.text_bundle == PDYN_IRG) *txbun = 0;
   if (attr.text_bundle == PDYN_IMM) *txbun = 1;
   if (attr.text_bundle == PDYN_CBS) *txbun = 2;

   *inbun = attr.int_bundle;
   if (attr.int_bundle == PDYN_IRG) *inbun = 0;
   if (attr.int_bundle == PDYN_IMM) *inbun = 1;
   if (attr.int_bundle == PDYN_CBS) *inbun = 2;

   *edbun = attr.edge_bundle;
   if (attr.edge_bundle == PDYN_IRG) *edbun = 0;
   if (attr.edge_bundle == PDYN_IMM) *edbun = 1;
   if (attr.edge_bundle == PDYN_CBS) *edbun = 2;

   *parep = attr.pat_rep;
   if (attr.pat_rep == PDYN_IRG) *parep = 0;
   if (attr.pat_rep == PDYN_IMM) *parep = 1;
   if (attr.pat_rep == PDYN_CBS) *parep = 2;

   *colrep = attr.colr_rep;
   if (attr.colr_rep == PDYN_IRG) *colrep = 0;
   if (attr.colr_rep == PDYN_IMM) *colrep = 1;
   if (attr.colr_rep == PDYN_CBS) *colrep = 2;

   *vwrep = attr.view_rep;
   if (attr.view_rep == PDYN_IRG) *vwrep = 0;
   if (attr.view_rep == PDYN_IMM) *vwrep = 1;
   if (attr.view_rep == PDYN_CBS) *vwrep = 2;

   *wktr = attr.ws_tran;
   if (attr.ws_tran == PDYN_IRG) *wktr = 0;
   if (attr.ws_tran == PDYN_IMM) *wktr = 1;
   if (attr.ws_tran == PDYN_CBS) *wktr = 2;

   *hifltr = attr.highl_filter;
   if (attr.highl_filter == PDYN_IRG) *hifltr = 0;
   if (attr.highl_filter == PDYN_IMM) *hifltr = 1;
   if (attr.highl_filter == PDYN_CBS) *hifltr = 2;

   *infltr = attr.invis_filter;
   if (attr.invis_filter == PDYN_IRG) *infltr = 0;
   if (attr.invis_filter == PDYN_IMM) *infltr = 1;
   if (attr.invis_filter == PDYN_CBS) *infltr = 2;

   *hlhsr = attr.hlhsr_mode;
   if (attr.hlhsr_mode == PDYN_IRG) *hlhsr = 0;
   if (attr.hlhsr_mode == PDYN_IMM) *hlhsr = 1;
   if (attr.hlhsr_mode == PDYN_CBS) *hlhsr = 2;
}
