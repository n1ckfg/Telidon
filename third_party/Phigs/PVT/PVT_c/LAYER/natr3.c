#include <phigs.h>
#include "f2c.h"

/*********************************************************************
NAME
     ANNOTATION TEXT RELATIVE 3 - create structure element speci-
     fying 3D annotation text primitive

  FORTRAN Syntax
     SUBROUTINE patr3 ( RPX, RPY, RPZ, APX, APY, APZ, CHARS )
     REAL        RPX, RPY, RPZ     reference point (MC)
     REAL        APX, APY, APZ     annotation offset (NPC)
     CHARACTER*(*)                 CHARSstring of characters

**********************************************************************/
#ifdef NO_PROTO
natr3 (rpx, rpy, rpz, apx, apy, apz, chars, clen)
   real    *rpx,
            *rpy,
            *rpz,
            *apx,
            *apy,
            *apz;
   char     *chars;
   integer       clen;
#else
natr3 (real *rpx, real *rpy, real *rpz, real *apx, real *apy, real *apz,
       char *chars, integer clen)
#endif
{
   Ppoint3   ref_pt;
   Pvec3     anno_offset;
   char     *string;
   char *strncpy();

   string = (char *) calloc (clen + 1, sizeof (char));
   strncpy (string, chars, clen);
   string[clen] = '\0';

   ref_pt.x = *rpx;
   ref_pt.y = *rpy;
   ref_pt.z = *rpz;

   anno_offset.delta_x = *apx;
   anno_offset.delta_y = *apy;
   anno_offset.delta_z = *apz;

/**********************************************************************
  C Syntax
     void
     panno_text_rel3 ( ref_pt, anno_offset, text )
     Ppoint3     *ref_pt;          reference point
     Pvec3       *anno_offset;     annotation offset
     char        *text;            annotation text string
**********************************************************************/

   panno_text_rel3 (&ref_pt, &anno_offset, string);

   free (string);
}
