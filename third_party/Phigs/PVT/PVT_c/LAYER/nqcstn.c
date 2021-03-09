#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE CONFLICTING STRUCTURES IN NETWORK - obtain conflict-
     ing network structures in Central Structure Store and speci-
     fied archive file

  FORTRAN Syntax
     SUBROUTINE pqcstn ( AFID, STRID, SNSRC, N, ERRIND, OL, OSTRID )
     INTEGER     AFID              archive file identifier
     INTEGER     STRID             structure identifier
     INTEGER     SNSRC             structure network source (PCSS, PARCHV)
     INTEGER     N                 element of the structure identifier list
                                   to return
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of structure identifiers in list
     INTEGER     OSTRID            OUT Nth structure identifier in list
**************************************************************************/
#ifdef NO_PROTO
nqcstn (afid, strid, snsrc, n, errind, ol, ostrid)
   integer      *afid,
            *strid,
            *snsrc,
            *n,
            *errind,
            *ol,
            *ostrid;
#else
nqcstn (integer *afid, integer *strid, integer *snsrc, integer *n, integer *errind, integer *ol, integer *ostrid)
#endif
{
   Pint      start,
             length,
             total_length;
   Pstruct_net_source src;
   Pint cerror;
   Pint_list ids;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   ids.ints = (Pint *) calloc (1, sizeof (Pint));

   src = *snsrc;
   switch (*snsrc)
   {
   case 0:
      src = PNET_CSS;
      break;
   case 1:
      src = PNET_AR;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pinq_conf_structs_net ( ar_id, struct_id, src, length, start, errind, ids, total_length )
     Pint        ar_id;            archive identifier
     Pint        struct_id;        structure identifier
     Pstruct_net_source            src;structure network source
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *ids;             OUT conflicting struct id list
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_conf_structs_net ((Pint) *afid, (Pint) *strid, src, length, start,
       &cerror, &ids, &total_length);
   *errind = cerror;

   *ol = total_length;
   if (ids.num_ints == 1)
      *ostrid = ids.ints[0];

   free (ids.ints);
}
