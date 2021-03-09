#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE GENERALIZED STRUCTURE ELEMENT  FACILITIES  -  obtain
     list of generalized structure element (GSE) facilities

  FORTRAN Syntax
     SUBROUTINE pqgsef ( N, ERRIND, OL, GSEID, WSDIND )
     INTEGER     N                 element of the list of available GSEs
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of available GSEs
     INTEGER     GSEID             OUT GSE identifier of Nth element
                                   of the list of available GSEs
     INTEGER     WSDIND            OUT workstation dependency
                                   indicator of Nth element of the list
                                   of available GSEs (PWKI, PWKD)
**************************************************************************/
#ifdef NO_PROTO
nqgsef (n, errind, ol, gseid, wsdind)
   integer      *n,
            *errind,
            *ol,
            *gseid,
            *wsdind;
#else
nqgsef (integer *n, integer *errind, integer *ol, integer *gseid, 
        integer *wsdind)
#endif
{
   Pint      start, cerror, length, total_length;
   Pgse_id_dep_list gse;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
   gse.id_facs = (Pgse_id_dep *) calloc (1, sizeof (Pgse_id_dep));

/**************************************************************************
  C Syntax
     void
     pinq_gse_facs ( length, start, errind, gse, total_length )
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pgse_id_dep_list              *gse;OUT list of GSE ids and their dependencies
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_gse_facs (length, start, &cerror, &gse, &total_length);
   *errind = cerror;

   *ol = total_length;
   *gseid = gse.id_facs->id;

   if (gse.id_facs->ind == PWS_INDEP)
      *wsdind = 0;
   else if (gse.id_facs->ind == PWS_DEP)
      *wsdind = 1;

   free (gse.id_facs);
}
