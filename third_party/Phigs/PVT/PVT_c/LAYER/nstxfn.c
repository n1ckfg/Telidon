#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET TEXT FONT - create structure element to set current text
     font attribute

  FORTRAN Syntax
     SUBROUTINE pstxfn ( FONT )
     INTEGER     FONT              text font
**************************************************************************/
#ifdef NO_PROTO
nstxfn (font)
   integer      *font;
#else
nstxfn (integer *font)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_text_font ( font )
     Pint        font;             text font
**************************************************************************/

   pset_text_font ((Pint) *font);
}
