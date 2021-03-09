#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION STATE TABLE LENGTHS - obtain lengths  of
     workstation state tables for specified workstation type

  FORTRAN Syntax
     SUBROUTINE pqwksl ( WTYPE, ERRIND, MPLBTE, MPMBTE, MTXBTE, MINBTE,
                                          MEDBTE, MPAI, MCOLI, VWTBI )
     INTEGER     WTYPE   workstation type
     INTEGER     ERRIND  OUT error indicator
     INTEGER     MPLBTE  OUT maximum number of polyline bundle table entries
     INTEGER     MPMBTE  OUT maximum number of polymarker bundle table entries
     INTEGER     MTXBTE  OUT maximum number of text bundle table entries
     INTEGER     MINBTE  OUT maximum number of interior bundle table entries
     INTEGER     MEDBTE  OUT maximum number of edge bundle table entries
     INTEGER     MPAI    OUT maximum number of pattern indices
     INTEGER     MCOLI   OUT maximum number of colour indices
     INTEGER     VWTBI   OUT maximum number of view table indices
**************************************************************************/
#ifdef NO_PROTO
nqwksl (wtype, errind, mplbte, mpmbte, mtxbte, minbte, medbte, mpai, mcoli, vwtbi)
   integer      *wtype,
            *errind,
            *mplbte,
            *mpmbte,
            *mtxbte,
            *minbte,
            *medbte,
            *mpai,
            *mcoli,
            *vwtbi;
#else
nqwksl (integer *wtype, integer *errind, integer *mplbte, integer *mpmbte, integer *mtxbte, integer *minbte,
	integer *medbte, integer *mpai, integer *mcoli, integer *vwtbi)
#endif
{
   Pws_st_tables lengths;
   Pint          cerror;
/**************************************************************************
  C Syntax
     void
     pinq_ws_st_table ( type, errind, lengths )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pws_st_tables                 *lengths;OUT lengths of workstation tables
**************************************************************************/

   pinq_ws_st_table ((Pint) *wtype, &cerror, &lengths);
   *errind = cerror;

   *mplbte = lengths.line_bundles;
   *mpmbte = lengths.mark_bundles;
   *mtxbte = lengths.text_bundles;
   *minbte = lengths.int_bundles;
   *medbte = lengths.edge_bundles;
   *mpai  = lengths.pat_reps;
   *mcoli = lengths.colr_reps;
   *vwtbi = lengths.view_reps;
}
