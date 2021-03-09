#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDGE FLAG - create structure element to set current edge
     flag attribute

  FORTRAN Syntax
     SUBROUTINE psedfg ( EDFLAG )
     INTEGER     EDFLAG            edge flag (POFF, PON)
**************************************************************************/
#ifdef NO_PROTO
nsedfg (edflag)
   integer      *edflag;
#else
nsedfg (integer *edflag)
#endif
{
   Pedge_flag edge_flag;

   edge_flag = *edflag;
   switch (*edflag)
   {
   case 0:
      edge_flag = PEDGE_OFF;
      break;
   case 1:
      edge_flag = PEDGE_ON;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_edge_flag ( edge_flag )
     Pedge_flag  edge_flag;        edge flag
**************************************************************************/

   pset_edge_flag (edge_flag);
}
