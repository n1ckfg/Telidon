#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET MODELLING CLIPPING INDICATOR - create structure  element
     to set current modelling clipping indicator attribute

  FORTRAN Syntax
     SUBROUTINE psmcli ( MCLIPI )
     INTEGER     MCLIPI            modelling clipping indicator (PNCLIP, PCLIP)
**************************************************************************/
#ifdef NO_PROTO
nsmcli (mclipi)
   integer      *mclipi;
#else
nsmcli (integer *mclipi)
#endif
{
   Pclip_ind clip;

   clip = *mclipi;
   switch (*mclipi)
   {
   case 0:			/*** PNCLIP=0 ***/
      clip = PIND_NO_CLIP;
      break;
   case 1:			/*** PCLIP=1 ***/
      clip = PIND_CLIP;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_model_clip_ind ( ind )
     Pclip_ind   ind;              clipping indicator
**************************************************************************/

   pset_model_clip_ind (clip);
}
