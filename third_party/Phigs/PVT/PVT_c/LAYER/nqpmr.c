#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE  POLYMARKER  REPRESENTATION  -   obtain   polymarker
     representation on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqpmr ( WKID, PMI, TYPE, ERRIND, MTYPE, MSZSF, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     PMI               polymarker index
     INTEGER     TYPE              type of returned values (PSET, PREALI)
     INTEGER     ERRIND            OUT error indicator
     INTEGER     MTYPE             OUT marker type
     REAL        MSZSF             OUT marker size scale factor
     INTEGER     COLI              OUT polymarker colour index
**************************************************************************/
#ifdef NO_PROTO
nqpmr (wkid, pmi, type, errind, mtype, mszsf, coli)
   integer      *wkid,
            *pmi,
            *type,
            *errind,
            *mtype,
            *coli;
   real    *mszsf;
#else
nqpmr (integer *wkid, integer *pmi, integer *type, integer *errind, integer *mtype, real *mszsf,
       integer *coli)
#endif
{
   Pinq_type inq_type;
   Pmarker_bundle rep;
   Pint  cerror;

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
     pinq_marker_rep ( ws, index, type, errind, rep )
     Pint        ws;               workstation identifier
     Pint        index;            polymarker index
     Pinq_type   type;             type of returned value
     Pint        *errind;          OUT error indicator
     Pmarker_bundle                *rep;OUT polymarker representation
**************************************************************************/

   pinq_marker_rep ((Pint) *wkid, (Pint) *pmi, inq_type, &cerror, &rep);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   *mtype = rep.type;
   *mszsf = rep.size;
   *coli = rep.colr_ind;
}
