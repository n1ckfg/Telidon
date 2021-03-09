#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     TEXT 3 - create structure element specifying 3D text  primi-
     tive

  FORTRAN Syntax
     SUBROUTINE ptx3 ( PX, PY, PZ, TDX, TDY, TDZ, CHARS )
     REAL        PX, PY, PZ        text point (MC)
     REAL        TDX(2), TDY(2), TDZ(2)text direction vectors (MC)
     CHARACTER*(*)                 CHARSstring of characters

**************************************************************************/
#ifdef NO_PROTO
ntx3 (px, py, pz, tdx, tdy, tdz, chars, clen)
   real    *px,
            *py,
            *pz;
   real     tdx[2],
             tdy[2],
             tdz[2];
   char      chars[];
   integer       clen;
#else
ntx3 (real *px, real *py, real *pz, real tdx[2], real tdy[2],
      real tdz[2], char chars[], integer clen)
#endif
{
   Pvec3     dir[2];
   Ppoint3   text_pt;
   char     *string;
   char     *strncpy();
   char     *calloc();

   string = calloc (clen + 1, sizeof (char));
   strncpy (string, chars, clen);
   string[clen] = '\0';

   text_pt.x = *px;
   text_pt.y = *py;
   text_pt.z = *pz;

   dir[0].delta_x = tdx[0];
   dir[0].delta_y = tdy[0];
   dir[0].delta_z = tdz[0];
   dir[1].delta_x = tdx[1];
   dir[1].delta_y = tdy[1];
   dir[1].delta_z = tdz[1];

/**************************************************************************
  C Syntax
     void
     ptext3 ( text_pt, dir, text )
     Ppoint3     *text_pt;         text point
     Pvec3       dir[2];           direction vectors
     char        *text;            text string
**************************************************************************/

   ptext3 (&text_pt, dir, string);

   free (string);
}
