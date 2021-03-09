#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE POSTED STRUCTURES - obtain list of structures posted
     to workstation

  FORTRAN Syntax
     SUBROUTINE pqpost ( WKID, N, ERRIND, NUMBER, STRID, PRIORT )
     INTEGER     WKID              workstation identifier
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NUMBER            OUT number of structures posted to that
                                   workstation
     INTEGER     STRID             OUT identifier of the Nth structure posted
                                   to that workstation
     REAL        PRIORT            OUT display priority of the Nth structure posted
**************************************************************************/
#ifdef NO_PROTO
nqpost (wkid, n, errind, number, strid, priort)
   integer      *wkid,
            *n,
            *errind,
            *number,
            *strid;
   real    *priort;
#else
nqpost (integer *wkid, integer *n, integer *errind, 
        integer *number, integer *strid, real *priort)
#endif
{
   Pint      start, cerror, length, total_length;
   Pposted_struct_list list;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   list.postings = (Pposted_struct *) calloc (1, sizeof (Pposted_struct));

/**************************************************************************
  C Syntax
     void
     pinq_posted_structs ( ws, length, start, errind, list, total_length )
     Pint        ws;               workstation identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pposted_struct_list           *list;OUT list of posted structures
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_posted_structs ((Pint) *wkid, length, start, &cerror, &list, 
                        &total_length);
   *errind = cerror;

   *number = total_length;
   *strid = list.postings->id;
   *priort = list.postings->disp_pri;
}
