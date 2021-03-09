#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE ALL CONFLICTING STRUCTURES - obtain all  conflicting
     structures  in  both  Central  Structure Store and specified
     archive file

  FORTRAN Syntax
     SUBROUTINE pqcst ( AFID, N, ERRIND, OL, OSTRID )
     INTEGER     AFID              archive file identifier
     INTEGER     N                 element of the structure identifier list
                                   to return
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of structure identifiers in list
     INTEGER     OSTRID            OUT Nth structure identifier in list
**************************************************************************/
#ifdef NO_PROTO
nqcst (afid, n, errind, ol, ostrid)
   integer      *afid,
            *n,
            *errind,
            *ol,
            *ostrid;
#else
nqcst (integer *afid, integer *n, integer *errind, integer *ol, integer *ostrid)
#endif
{
   Pint      start,
             length,
             total_length;
   Pint cerror;
   Pint_list ids;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   ids.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_all_conf_structs ( ar_id, length, start, errind, ids, total_length )
     Pint        ar_id;            archive identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *ids;             OUT list of conflicting structure ids
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_all_conf_structs ((Pint) *afid, length, start,
         &cerror, &ids, &total_length);
   *errind = cerror;

   *ol = total_length;
   if (ids.num_ints == 1)
      *ostrid = ids.ints[0];


   free (ids.ints);
}
