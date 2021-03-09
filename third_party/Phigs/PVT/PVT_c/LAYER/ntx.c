#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     TEXT - create structure element specifying 2D text primitive

  FORTRAN Syntax
     SUBROUTINE ptx ( PX, PY, CHARS )
     REAL        PX, PY            text point (MC)
     CHARACTER*(*)                 CHARSstring of characters

**************************************************************************/
#ifdef NO_PROTO
ntx (px, py, chars, clen)
   real    *px,
            *py;
   char     *chars;
   integer       clen;
#else
ntx (real *px, real *py, char *chars, integer clen)
#endif
{
   Ppoint    text_pt;
   char     *string;
   char     *strncpy();
   char     *calloc();

   string = (char *) calloc (clen + 1, sizeof (char));

   strncpy (string, chars, clen);
   string[clen] = '\0';

   text_pt.x = *px;
   text_pt.y = *py;

/**************************************************************************
  C Syntax
     void
     ptext ( text_pt, text )
     Ppoint      *text_pt;         text point
     char        *text;            text string
**************************************************************************/

   ptext (&text_pt, string);

   free (string);
}
