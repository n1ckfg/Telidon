#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE TEXT FACILITIES - obtain list  of  workstation  text
     facilities

  FORTRAN Syntax
     SUBROUTINE pqtxf ( WTYPE, N, ERRIND, NFPP, FONT, PREC, NCHH, MINCHH,
                                     MAXCHH, NCHX, MINCHX, MAXCHX, NPTXI )
     INTEGER     WTYPE             workstation type
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NFPP              OUT number of text font and precision pairs
     INTEGER     FONT              OUT Nth element of list of text fonts
     INTEGER     PREC              OUT Nth element of list of text precisions
     INTEGER     NCHH              OUT number of available character heights
     REAL        MINCHH            OUT minimum character height (DC)
     REAL        MAXCHH            OUT maximum character height (DC)
     INTEGER     NCHX              OUT number of available character expansion factors
     REAL        MINCHX            OUT minimum character expansion factor
     REAL        MAXCHX            OUT maximum character expansion factor
     INTEGER     NPTXI             OUT number of predefined text indices
**************************************************************************/
#ifdef NO_PROTO
nqtxf (wtype, n, errind, nfpp, font, prec, nchh, minchh, maxchh, nchx, minchx, maxchx, nptxi)
   integer      *wtype,
            *n,
            *errind,
            *nfpp,
            *font,
            *prec,
            *nchh,
            *nchx,
            *nptxi;
   real    *minchh,
            *maxchh,
            *minchx,
            *maxchx;
#else
nqtxf (integer *wtype, integer *n, integer *errind, integer *nfpp, 
       integer *font, integer *prec, integer *nchh,
       real *minchh, real *maxchh, integer *nchx, real *minchx, real *maxchx, 
       integer *nptxi)
#endif
{
   Pint      length, cerror, start, total_length;
   Ptext_facs facilities;
/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);
/***  Allocate space to hold the list ***/

   facilities.font_precs = 
      (Ptext_font_prec *) calloc (1, sizeof (Ptext_font_prec));

/**************************************************************************
  C Syntax
     void
     pinq_text_facs ( type, length, start, errind, facilities, total_length )
     Pint        type;             workstation type
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Ptext_facs  *facilities;      OUT text facilities
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_text_facs ((Pint) *wtype, length, start, &cerror, &facilities, 
                   &total_length);
   *errind = cerror;

   *nfpp = total_length;
   *nchh = facilities.num_char_hts;
   *minchh = facilities.min_char_ht;
   *maxchh = facilities.max_char_ht;
   *nchx = facilities.num_char_expans;
   *minchx = facilities.min_char_expan;
   *maxchx = facilities.max_char_expan;
   *nptxi = facilities.num_pred_inds;

   if (facilities.num_font_precs > 0)
   {
      *font = facilities.font_precs[0].font;
      *prec = facilities.font_precs[0].prec;

      switch (facilities.font_precs[0].prec)
      {
      case PPREC_STRING:
	 *prec = 0;
	 break;
      case PPREC_CHAR:
	 *prec = 1;
	 break;
      case PPREC_STROKE:
	 *prec = 2;
	 break;
      }
   }
   free (facilities.font_precs);
}
