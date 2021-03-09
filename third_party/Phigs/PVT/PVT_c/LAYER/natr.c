#include <phigs.h>
#include "f2c.h"

/*******************************************************************
NAME
     ANNOTATION TEXT RELATIVE - create structure element specify-
     ing 2D annotation text primitive

  FORTRAN Syntax
     SUBROUTINE patr ( RPX, RPY, APX, APY, CHARS )
     REAL        RPX, RPY          reference point (MC)
     REAL        APX, APY          annotation offset (NPC)
     CHARACTER*(*)                 CHARSstring of characters

********************************************************************/
#ifdef NO_PROTO
natr (rpx, rpy, apx, apy, chars, clen)
   real    *rpx,
            *rpy,
            *apx,
            *apy;
   char     *chars;
   integer       clen;
#else
natr (real *rpx, real *rpy, real *apx, real *apy, char *chars, integer clen)
#endif
{
   Ppoint    ref_pt;
   Pvec      anno_offset;
   char     *string;
   char     *strncpy();

   string = (char *) calloc (clen + 1, sizeof (char));
   strncpy (string, chars, clen);
   string[clen] = '\0';


   ref_pt.x = *rpx;
   ref_pt.y = *rpy;

   anno_offset.delta_x = *apx;
   anno_offset.delta_y = *apy;

/********************************************************************
  C Syntax
     void
     panno_text_rel ( ref_pt, anno_offset, text )
     Ppoint      *ref_pt;          reference point
     Pvec        *anno_offset;     annotation offset
     char        *text;            annotation text string
********************************************************************/

   panno_text_rel (&ref_pt, &anno_offset, string);

   free (string);
}
