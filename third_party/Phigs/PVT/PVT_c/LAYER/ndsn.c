#include <phigs.h>
#include "f2c.h"

/*************************************************************************
NAME
     DELETE STRUCTURE NETWORK - delete network of structures from
     central structure store

  FORTRAN Syntax
     SUBROUTINE pdsn ( STRID, REFHNF )
     INTEGER     STRID             structure identifier
     INTEGER     REFHNF            reference handling mode (PDELE, PKEEP)
*************************************************************************/
#ifdef NO_PROTO
ndsn (strid, refhnf)
   integer      *strid,
            *refhnf;
#else
ndsn (integer *strid, integer *refhnf)
#endif
{
   Pref_flag ref_flag;

   ref_flag = *refhnf;
   if (*refhnf == 0)
      ref_flag = PFLAG_DEL;
   if (*refhnf == 1)
      ref_flag = PFLAG_KEEP;

/*************************************************************************
  C Syntax
     void
     pdel_struct_net ( struct_id, ref_flag )
     Pint        struct_id;        structure identifier
     Pref_flag   ref_flag;         reference handling flag
*************************************************************************/

   pdel_struct_net ((Pint) *strid, ref_flag);
}
