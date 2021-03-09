#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     UNPACK DATA RECORD - unpack values from a data  record  into
     FORTRAN arrays

  FORTRAN Syntax
     SUBROUTINE purec ( LDR, DATREC, IIL, IRL, ISL, ERRIND, IL, IA, RL, RA, SL, LSTR,
          STR )
     INTEGER        LDR               number of array elements used in DATREC
     CHARACTER*80   DATREC(LDR)       data record
     INTEGER        IIL               dimension of integer array
     INTEGER        IRL               dimension of real array
     INTEGER        ISL               dimension of character array
     INTEGER        ERRIND            OUT error indicator (zero if no error)
     INTEGER        IL                OUT number of integer entries
     INTEGER        IA(IIL)           OUT array containing integer entries
     INTEGER        RL                OUT number of real entries
     REAL           RA(IRL)           OUT array containing real entries
     INTEGER        SL                OUT number of character string entries
     INTEGER        LSTR(ISL)         OUT length of each character string entry
     CHARACTER*(*)  STR(ISL)          OUT character string entries

**************************************************************************/
#ifdef NO_PROTO
nurec (ldr, datrec, iil, irl, isl, errind, il, ia, rl, ra, sl, lstr, str, ldrec, ldstr)
   integer      *il,
             ia[],
            *iil,
            *irl,
            *isl,
            *rl,
            *sl,
             lstr[],
            *errind,
            *ldr,
             ldrec,
             ldstr;
   real     ra[];
   char     *str;
   cdatrec  *datrec;
#else
nurec (integer *ldr, cdatrec * datrec, integer *iil, integer *irl, 
       integer *isl, integer *errind, integer *il, integer ia[], 
       integer *rl, real ra[], integer *sl, integer lstr[], char *str,
       integer ldrec, integer ldstr)
#endif
{
   int       i, j;

/***  Re-Store Integers     **/
   *il = datrec->il;
   /* Make sure it is big enough to hold them */
   if ( *iil  < *il ) {
      *errind = 2001;  /* FORTRAN error because C has no */
      return;          /* equivalent                     */
   }

   for (i = 0; i < *il; i++)
   {
      ia[i] = datrec->ia[i];
   }

/***  Re-Store Reals     **/
   *rl = datrec->rl;
   /* Make sure it is big enough to hold them */
   if ( *irl  < *rl ) {
      *errind = 2001;  /* FORTRAN error because C has no */
      return;          /* equivalent                     */
   }
   for (i = 0; i < *rl; i++)
   {
      ra[i] = datrec->ra[i];
   }

/***  Re-Store Strings     **/
   *sl = datrec->sl;
   /* Make sure it is big enough to hold them */
   if ( *isl  < *sl ) {
      *errind = 2001;  /* FORTRAN error because C has no */
      return;          /* equivalent                     */
   }
   for (i = 0; i < *sl; i++)
   {
      lstr[i] = datrec->lstr[i];
      strncpy (&str[i * ldstr], datrec->str[i], lstr[i]);
   /****  Blank fill rest of string, FORTRAN requirement ****/
      for (j = i * ldstr + lstr[i]; j < (i + 1) * ldstr; j++)
	 str[j] = ' ';
   }
   *errind = 0;
}
