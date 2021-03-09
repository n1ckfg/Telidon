#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE INTERIOR REPRESENTATION - obtain interior  represen-
     tation on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqir ( WKID, II, TYPE, ERRIND, INTS, ISTYLI, COLI )
     INTEGER     WKID              workstation identifier
     INTEGER     II                interior index
     INTEGER     TYPE              type of returned values (PSET, PREALI)
     INTEGER     ERRIND            OUT error indicator
     INTEGER     INTS              OUT interior style
     INTEGER     ISTYLI            OUT interior style index
     INTEGER     COLI              OUT interior colour index
**************************************************************************/
#ifdef NO_PROTO
nqir (wkid, ii, type, errind, ints, istyli, coli)
   integer  *wkid,
            *ii,
            *type,
            *errind,
            *ints,
            *istyli,
            *coli;
#else
nqir (integer *wkid, integer *ii, integer *type, integer *errind, 
      integer *ints, integer *istyli, integer *coli)
#endif
{
   Pinq_type    inq_type;
   Pint_bundle  rep;
   Pint         cerror;

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
     pinq_int_rep ( ws, index, type, errind, rep )
     Pint        ws;               workstation identifier
     Pint        index;            interior index
     Pinq_type   type;             type of returned value
     Pint        *errind;          OUT error indicator
     Pint_bundle *rep;             OUT interior representation
**************************************************************************/

   pinq_int_rep ((Pint) *wkid, (Pint) *ii, inq_type, &cerror, &rep);
   *errind = cerror;

   *istyli = rep.style_ind;
   *coli = rep.colr_ind;

   *ints = rep.style;
   if (rep.style == PSTYLE_HOLLOW) *ints = 0;
   if (rep.style == PSTYLE_SOLID)  *ints = 1;
   if (rep.style == PSTYLE_PAT)    *ints = 2;
   if (rep.style == PSTYLE_HATCH)  *ints = 3;
   if (rep.style == PSTYLE_EMPTY)  *ints = 4;
}
