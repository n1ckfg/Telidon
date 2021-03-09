#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ANNOTATION TEXT CHARACTER HEIGHT - create structure ele-
     ment  to set current annotation text character height attri-
     bute

  FORTRAN Syntax
     SUBROUTINE psatch ( ATCHH )
     REAL        ATCHH             annotation text character height (TLC)
**************************************************************************/
#ifdef NO_PROTO
nsatch (atchh)
   real    *atchh;
#else
nsatch (real *atchh)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_anno_char_ht ( height )
     Pfloat      height;           character height
**************************************************************************/

   pset_anno_char_ht ((Pfloat) *atchh);
}
