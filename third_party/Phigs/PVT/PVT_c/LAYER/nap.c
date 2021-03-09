#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/******************************************************************
NAME
     APPLICATION DATA - create  a  structure  element  containing
     application data

  FORTRAN Syntax
     SUBROUTINE pap ( LDR, DATREC )
     INTEGER     LDR               dimension of data record array
     CHARACTER*80                  DATREC(LDR) data record
******************************************************************/
#ifdef NO_PROTO
nap (ldr, datrec, lendat)
   integer      *ldr;
   cdatrec  *datrec;
   integer       lendat;
#else
nap (integer *ldr, char *datrec, integer lendat)
#endif
{
   Pdata     data;
/*** Put points into structure  ***/

   data.size = sizeof (cdatrec);
   data.data = (void *) datrec;

/*****************************************************************
  C Syntax
     void
     pappl_data ( data )
     Pdata       *data;            - application data
*****************************************************************/

   pappl_data (&data);
}
