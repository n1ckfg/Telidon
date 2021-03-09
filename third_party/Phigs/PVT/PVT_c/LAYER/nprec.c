#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     PACK DATA RECORD - pack values from FORTRAN arrays into data
     record

  FORTRAN Syntax
     SUBROUTINE pprec ( IL, IA, RL, RA, SL, LSTR, STR, MLDR, ERRIND, LDR, DATREC )
     INTEGER     IL                number of integer entries (>= 0)
     INTEGER     IA(*)             array containing integer entries
     INTEGER     RL                number of real entries (>= 0)
     REAL        RA(*)             array containing real entries
     INTEGER     SL                number of character string entries (>= 0)
     INTEGER     LSTR(*)           lengths of each character string entry (>= 0)
     CHARACTER*(*)                 STR(*)character string entries
     INTEGER     MLDR              dimension of data record array
     INTEGER     ERRIND            OUT error indicator (zero if no error)
     INTEGER     LDR               OUT number of array elements used in DATREC
     CHARACTER*80                  DATREC(MLDR)OUT data record

**************************************************************************/
#ifdef NO_PROTO
nprec (il, ia, rl, ra, sl, lstr, str, mldr, errind, ldr, datrec, ldstr, ldrec)
   integer      *il,
             ia[],
            *rl,
            *sl,
             lstr[],
            *mldr,
            *errind,
            *ldr,
             ldstr,
             ldrec;
   real     ra[];
   char     *str;
   cdatrec  *datrec;
#else
nprec (integer *il, integer ia[], integer *rl, real ra[], integer *sl, integer lstr[], char *str,
   integer *mldr, integer *errind, integer *ldr, cdatrec * datrec, integer ldstr, integer ldrec)
#endif
{
   int       i;
   char *strncpy();

   /* Check that datrec is > 8 big, this is the
      minimum needed by cdatrec   */

   if (*mldr < 8)   /* Too Small */
   {
      *errind = 2001; /* Return the FORTRAN error */
      return;
   }

/***  Store Integers     **/

   if (*il > 19)   /* Too large */
   {
      *errind = 2004;
      return;
   }
   datrec->il = *il;
   for (i = 0; i < *il; i++)
   {
      datrec->ia[i] = ia[i];
   }

/***  Store Reals     **/

   if (*rl > 19)   /* Too large */
   {
      *errind = 2004;
      return;
   }
   datrec->rl = *rl;
   for (i = 0; i < *rl; i++)
   {
      datrec->ra[i] = ra[i];
   }

/***  Store Strings     **/

   if (*sl > 5)   /* Too large */
   {
      *errind = 2004;
      return;
   }
   datrec->sl = *sl;
   for (i = 0; i < *sl; i++)
   {
      datrec->lstr[i] = lstr[i];
      strncpy (datrec->str[i], &str[i * ldstr], lstr[i]);
   }

/* Fake out the software, assume we used just one */

   *ldr = 1;

   *errind = 0;
}
