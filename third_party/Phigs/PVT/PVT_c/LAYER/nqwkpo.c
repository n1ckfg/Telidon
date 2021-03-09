#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE SET OF WORKSTATIONS TO WHICH POSTED - obtain list of
     workstations to which structure is posted

  FORTRAN Syntax
     SUBROUTINE pqwkpo ( STRID, N, ERRIND, OL, WKID )
     INTEGER     STRID             structure identifier
     INTEGER     N                 set member requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of workstations to which the
                                   structure is posted
     INTEGER     WKID              OUT Nth member of set of workstations
                                   to which the structure is posted
**************************************************************************/
#ifdef NO_PROTO
nqwkpo (strid, n, errind, ol, wkid)
   integer  *strid,
            *n,
            *errind,
            *ol,
            *wkid;
#else
nqwkpo (integer *strid, integer *n, 
        integer *errind, integer *ol, integer *wkid)
#endif
{
   Pint      start, cerror, len_appl_list, len_impl_list;
   Pint_list ws;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   len_appl_list = (*n != 0);

   ws.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_wss_posted ( struct_id, len_appl_list, start, errind, ws, 
                       len_impl_list )
     Pint        struct_id;        structure identifier
     Pint        len_appl_list;    length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *ws;              OUT list of workstations
     Pint        *len_impl_list;   OUT length of implementation list 
**************************************************************************/

   pinq_wss_posted ((Pint) *strid, len_appl_list, start, 
                     &cerror, &ws, &len_impl_list);
   *errind = cerror;
   *ol = len_impl_list;
   if (len_appl_list > 0)
      *wkid = ws.ints[0];

   free (ws.ints);
}
