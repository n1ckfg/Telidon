#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INTERIOR REPRESENTATION - define interior attribute bun-
     dle on workstation

  FORTRAN Syntax
     SUBROUTINE psir ( WKID, II, INTS, STYLI, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     II                interior index
     INTEGER     INTS              interior style
                                   (PHOLLO, PSOLID, PPATTR, PHATCH, PISEMP)
     INTEGER     STYLI             style index
     INTEGER     COLI              colour index
**************************************************************************/
#ifdef NO_PROTO
nsir (wkid, ii, ints, styli, coli)
   integer      *wkid,
            *ii,
            *ints,
            *styli,
            *coli;
#else
nsir (integer *wkid, integer *ii, integer *ints, integer *styli, integer *coli)
#endif
{
   Pint_bundle rep;
   rep.style_ind = *styli;
   rep.colr_ind = *coli;
   rep.style = *ints;
   switch (*ints)
   {
   case 0:
      rep.style = PSTYLE_HOLLOW;
      break;
   case 1:
      rep.style = PSTYLE_SOLID;
      break;
   case 2:
      rep.style = PSTYLE_PAT;
      break;
   case 3:
      rep.style = PSTYLE_HATCH;
      break;
   case 4:
      rep.style = PSTYLE_EMPTY;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_int_rep ( ws, index, rep )
     Pint        ws;               workstation identifier
     Pint        index;            interior bundle index
     Pint_bundle *rep;             interior representation pointer
**************************************************************************/

   pset_int_rep ((Pint) *wkid, (Pint) *ii, &rep);
}
