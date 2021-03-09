#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE  ANNOTATION  FACILITIES  -  obtain  annotation  text
     facilities on workstation type

  FORTRAN Syntax
     SUBROUTINE pqanf ( WTYPE, N, ERRIND, NAS, AS, NCHH, MINCHH, MAXCHH )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element of annotation styles requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NAS               OUT number of available annotation styles
     INTEGER     AS                OUT Nth element of list of available
                                         annotation styles
     INTEGER     NCHH              OUT number of character heights
     REAL        MINCHH            OUT minimum character height
     REAL        MAXCHH            OUT maximum character height
**************************************************************************/
#ifdef NO_PROTO
nqanf (wtype, n, errind, nas, as, nchh, minchh, maxchh)
   integer      *wtype,
            *n,
            *errind,
            *nas,
            *as,
            *nchh;
   real    *minchh,
            *maxchh;
#else
nqanf (integer *wtype, integer *n, integer *errind, integer *nas, 
       integer *as, integer *nchh, real *minchh, real *maxchh)
#endif
{
   Pint      cnumch, cerror, i, j;
   Pfloat    cmin,cmax;
   Pint      length,
             start,
             total_length;
   Pint_list styles;

   start = *n - (*n > 0);
   length = (*n != 0);

   styles.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_anno_facs ( type, length, start, errind, styles, 
           total_length, num_char_hts,
           min_char_ht, max_char_ht )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *styles;          OUT list annotation styles
     Pint        *total_length;    OUT length of list in PHIGS
     Pint        *num_char_hts;    OUT number of character heights
     Pfloat      *min_char_ht;     OUT minimum character height
     Pfloat      *max_char_ht;     OUT maximum character height
**************************************************************************/

   pinq_anno_facs ((Pint) *wtype, length, start,
          &cerror, &styles, &total_length, &cnumch, &cmin,&cmax);
   *errind = cerror;
   *nchh   = cnumch;
   *minchh = cmin;
   *maxchh = cmax;

   *nas = total_length;
   if (styles.num_ints == 1)
      *as = styles.ints[0];

   free (styles.ints);
}
