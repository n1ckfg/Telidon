#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PHIGS FACILITIES- inquire the current list of  PHIGS
     facilities defined in the PHIGS description table

  FORTRAN Syntax
     SUBROUTINE pqphf ( NCS, ERRIND, SIMOPW, SIMOPA, NAMESN, OLCS, CS,
                                            NFLN, IFLN )
     INTEGER     NCS               character set requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     SIMOPW            OUT maximum number of simultaneously
                                   open workstations
     INTEGER     SIMOPA            OUT maximum number of simultaneously
                                   open archive files
     INTEGER     NAMESN            OUT maximum number of available names
                                   for name sets
     INTEGER     OLCS              OUT number of available character sets
     INTEGER     CS                OUT NCSth available character set
     INTEGER     NFLN              OUT maximum length of normal filter
                                   list for ISS
     INTEGER     IFLN              OUT maximum length of inverted filter
                                   list for ISS
**************************************************************************/
#ifdef NO_PROTO
nqphf (n, errind, simopw, simopa, namesn, olcs, cs, nfln, ifln)
   integer      *n,
            *errind,
            *simopw,
            *simopa,
            *namesn,
            *olcs,
            *cs,
            *nfln,
            *ifln;
#else
nqphf (integer *n, integer *errind, integer *simopw, integer *simopa, 
       integer *namesn, integer *olcs,
       integer *cs, integer *nfln, integer *ifln)
#endif
{
   Pint      start, cerror, length, total_length;
   Pint      opws, opar, nnames, maxnorm, maxinv;
   Pint_list char_sets;

   start = *n - (*n > 0);
   length = (*n != 0);

   char_sets.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_phigs_facs ( length, start, errind, open_ws, open_ar, 
            num_names, char_sets, length_list, norm_filt, inv_filt )

     Pint        length;        length of application list
     Pint        start;         starting position
     Pint        *errind;       OUT error indicator
     Pint        *open_ws;      OUT max. num. simultaneously open ws
     Pint        *open_ar;      OUT max. num. simultaneously open archive files
     Pint        *num_names;    OUT number of available names for name sets
     Pint_list   *char_sets;    OUT list of character sets
     Pint        *length_list;  OUT length of list in PHIGS
     Pint        *norm_filt;    OUT max length of normal filter list for ISS
     Pint        *inv_filt;     OUT max length of inverted filter list for ISS
**************************************************************************/

   pinq_phigs_facs (length, start, &cerror, &opws, &opar, &nnames,
                    &char_sets, &total_length, &maxnorm, &maxinv);
   *errind = cerror;
   *simopw = opws;
   *simopa = opar;
   *namesn = nnames;
   *olcs = total_length;
   *cs = *char_sets.ints;
   *nfln = maxnorm;
   *ifln = maxinv;

   free (char_sets.ints);
}
