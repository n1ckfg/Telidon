#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE COLOUR MODEL - obtain workstation's  current  colour
     model

  FORTRAN Syntax
     SUBROUTINE pqcmd ( WKID, ERRIND, CMODEL )
     INTEGER     WKID              workstation identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     CMODEL            OUT current colour model
**************************************************************************/
#ifdef NO_PROTO
nqcmd (wkid, errind, cmodel)
   integer      *wkid,
            *errind,
            *cmodel;
#else
nqcmd (integer *wkid, integer *errind, integer *cmodel)
#endif
{
   Pint cmod, cerror;

/**************************************************************************
  C Syntax
     void
     pinq_colr_model ( ws, errind, model )
     Pint        ws;               workstation identifier
     Pint        *errind;          OUT error indicator
     Pint        *model;           OUT current colour model
**************************************************************************/

   pinq_colr_model ((Pint) *wkid, &cerror, &cmod);
   *errind = cerror;
   *cmodel = cmod;
}
