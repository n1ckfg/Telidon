#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET COLOUR MODEL  -  select  colour  model  for  workstation
     colour table

  FORTRAN Syntax
     SUBROUTINE pscmd ( WKID, CMODEL )
     INTEGER     WKID              workstation identifier
     INTEGER     CMODEL            colour model
**************************************************************************/
#ifdef NO_PROTO
nscmd (wkid, cmodel)
   integer      *wkid,
            *cmodel;
#else
nscmd (integer *wkid, integer *cmodel)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_colr_model ( ws, model )
     Pint        ws;               workstation identifier
     Pint        model;            colour model
**************************************************************************/

   pset_colr_model ((Pint) *wkid, (Pint) *cmodel);
}
