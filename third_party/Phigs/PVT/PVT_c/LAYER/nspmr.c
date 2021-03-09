#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET POLYMARKER REPRESENTATION - define polymarker  attribute
     bundle on workstation

  FORTRAN Syntax
     SUBROUTINE pspmr ( WKID, PMI, MTYPE, MSZSF, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     PMI               polymarker index
     INTEGER     MTYPE             marker type
     REAL        MSZSF             marker size scale factor
     INTEGER     COLI              polymarker colour index
**************************************************************************/
#ifdef NO_PROTO
nspmr (wkid, pmi, mtype, mszsf, coli)
   integer      *wkid,
            *pmi,
            *mtype,
            *coli;
   real    *mszsf;
#else
nspmr (integer *wkid, integer *pmi, integer *mtype, real *mszsf, integer *coli)
#endif
{
   Pmarker_bundle rep;
   rep.type = *mtype;
   rep.size = *mszsf;
   rep.colr_ind = *coli;

/**************************************************************************
  C Syntax
     void
     pset_marker_rep ( ws, index, rep )
     Pint           ws;            workstation identifier
     Pint           index;         polymarker bundle index
     Pmarker_bundle *rep;          polymarker representation pointer
**************************************************************************/

   pset_marker_rep ((Pint) *wkid, (Pint) *pmi, &rep);
}
