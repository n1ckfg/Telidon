#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ANNOTATION TEXT ALIGNMENT - create structure element  to
     set current text alignment attribute

  FORTRAN Syntax
     SUBROUTINE psatal ( ATALH, ATALV )
     INTEGER     ATALH             annotation text alignment horizontal
     INTEGER     ATALV             annotation text alignment vertical
**************************************************************************/
#ifdef NO_PROTO
nsatal (atalh, atalv)
   integer      *atalh,
            *atalv;
#else
nsatal (integer *atalh, integer *atalv)
#endif
{
   Ptext_align text_align;

   text_align.hor = *atalh;
   switch (*atalh)
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

   text_align.vert = *atalv;
   switch (*atalv)
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
     pset_anno_align ( text_align )
     Ptext_align *text_align;      text alignment
**************************************************************************/

   pset_anno_align (&text_align);
}
