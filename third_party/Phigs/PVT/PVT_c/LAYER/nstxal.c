#include <phigs.h>
#include "f2c.h"


/**************************************************************************
NAME
     SET TEXT ALIGNMENT - create structure element to set current
     text alignment attribute

  FORTRAN Syntax
     SUBROUTINE pstxal ( TXALH, TXALV )
     INTEGER     TXALH             text alignment horizontal
     INTEGER     TXALV             text alignment vertical
**************************************************************************/
#ifdef NO_PROTO
nstxal (txalh, txalv)
   integer      *txalh,
            *txalv;
#else
nstxal (integer *txalh, integer *txalv)
#endif
{
   Ptext_align text_align;

   text_align.hor = *txalh;
   switch (*txalh)
   {
   case 0:
      text_align.hor = PHOR_NORM;
      break;
   case 1:
      text_align.hor = PHOR_LEFT;
      break;
   case 2:
      text_align.hor = PHOR_CTR;
      break;
   case 3:
      text_align.hor = PHOR_RIGHT;
      break;
   }

   text_align.vert = *txalv;
   switch (*txalv)
   {
   case 0:
      text_align.vert = PVERT_NORM;
      break;
   case 1:
      text_align.vert = PVERT_TOP;
      break;
   case 2:
      text_align.vert = PVERT_CAP;
      break;
   case 3:
      text_align.vert = PVERT_HALF;
      break;
   case 4:
      text_align.vert = PVERT_BASE;
      break;
   case 5:
      text_align.vert = PVERT_BOTTOM;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_text_align ( text_align )
     Ptext_align    *text_align;   text alignment
**************************************************************************/

   pset_text_align (&text_align);
}
