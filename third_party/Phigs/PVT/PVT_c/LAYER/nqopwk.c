#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE SET OF OPEN WORKSTATIONS -  obtain  current  set  of
     open workstations

  FORTRAN Syntax
     SUBROUTINE pqopwk ( N, ERRIND, OL, WKID )
     INTEGER     N                 set member requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of open workstations
     INTEGER     WKID              OUT Nth member of set of open workstations
**************************************************************************/
#ifdef NO_PROTO
nqopwk (n, errind, ol, wkid)
   integer      *n,
            *errind,
            *ol,
            *wkid;
#else
nqopwk (integer *n, integer *errind, integer *ol, integer *wkid)
#endif
{
   Pint      start, cerror, length, total_length;
   Pint_list idlist;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   idlist.ints = (Pint *) calloc (1, sizeof (Pint));


/**************************************************************************
  C Syntax
     void
     pinq_open_wss ( length, start, errind, idlist, total_length )
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *idlist;          OUT list of ws ids
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_open_wss (length, start, &cerror, &idlist, &total_length);
   *errind = cerror;

   *ol = total_length;
   *wkid = *idlist.ints;

   free (idlist.ints);
}
