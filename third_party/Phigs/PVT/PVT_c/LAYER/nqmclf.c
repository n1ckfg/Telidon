#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE MODELLING CLIPPING FACILITIES -  inquire  number  of
     modelling clipping planes and operators available

  FORTRAN Syntax
     SUBROUTINE pqmclf ( N, ERRIND, NDPMCV, OL, MCLPOP )
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NDPMCV            OUT number of available
                                   modelling clipping half-spaces
     INTEGER     OL                OUT number of modelling clipping operators
     INTEGER     MCLPOP            OUT Nth element of list
                                   of modelling clipping operators
**************************************************************************/
#ifdef NO_PROTO
nqmclf (n, errind, ndpmcv, ol, mclpop)
   integer      *n,
            *errind,
            *ndpmcv,
            *ol,
            *mclpop;
#else
nqmclf (integer *n, integer *errind, integer *ndpmcv, integer *ol, 
        integer *mclpop)
#endif
{
   Pint      length, cerror, start, total_length,
             num;
   Pint_list ops;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   ops.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_model_clip_facs ( length, start, errind, num, ops, total_length )
     Pint        length;      length of application list
     Pint        start;       starting position
     Pint        *errind;          OUT error indicator
     Pint        *num;        OUT number of distinct planes in modelling clipping volume
     Pint_list   *ops;        OUT list of operators
     Pint        *total_length;OUT length of list in PHIGS
**************************************************************************/

   pinq_model_clip_facs (length, start, &cerror, &num, &ops, &total_length);
   *errind = cerror;

   *ol = total_length;
   *ndpmcv = num;
   *mclpop = *ops.ints;

   free (ops.ints);
}
