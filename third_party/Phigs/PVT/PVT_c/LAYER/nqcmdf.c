#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE COLOUR MODEL FACILITIES - obtain list of workstation
     colour model facilities

  FORTRAN Syntax
     SUBROUTINE pqcmdf ( WTYPE, N, ERRIND, OL, CMOD, DFCMOD )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 element of list of available colour models
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of available colour models
     INTEGER     CMOD              OUT Nth available colour model
     INTEGER     DFCMOD            OUT default colour model
**************************************************************************/
#ifdef NO_PROTO
nqcmdf (wtype, n, errind, ol, cmod, dfcmod)
   integer      *wtype,
            *n,
            *errind,
            *ol,
            *cmod,
            *dfcmod;
#else
nqcmdf (integer *wtype, integer *n, integer *errind, integer *ol, integer *cmod, integer *dfcmod)
#endif
{
   Pint dfc, cerror;
   Pint      length,
             start,
             total_length;
   Pint_list models;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   models.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_colr_model_facs ( type, length, start, errind, models, total_length, def )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *models;          OUT list of colour models
     Pint        *total_length;    OUT length of list in PHIGS
     Pint        *def;             OUT default colour model
**************************************************************************/

   pinq_colr_model_facs ((Pint) *wtype, length, start,
       &cerror, &models, &total_length, &dfc);

   *errind = cerror;
   *dfcmod = dfc;

   *ol = total_length;

   if (models.num_ints == 1)
      *cmod = models.ints[0];

   free (models.ints);
}
