#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE GENERALIZED DRAWING PRIMITIVE 3 - obtain generalized
     drawing primitive 3 (GDP3) attributes

  FORTRAN Syntax
     SUBROUTINE pqgdp3 ( WTYPE, GDP, ERRIND, NBND, BNDL )
     INTEGER     WTYPE             workstation type
     INTEGER     GDP               3D GDP identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NBND              OUT number of sets of attributes used
     INTEGER     BNDL(5)           OUT list of sets of attributes used
**************************************************************************/
#ifdef NO_PROTO
nqgdp3 (wtype, gdp, errind, nbnd, bndl)
   integer      *wtype,
            *gdp,
            *errind,
            *nbnd,
             bndl[];
#else
nqgdp3 (integer *wtype, integer *gdp, integer *errind, integer *nbnd, 
        integer bndl[])
#endif
{
   Pint      cnum, cerror, i;
   Pattrs    attrs[5];
/**************************************************************************
  C Syntax
     void
     pinq_gdp3 ( ws_type, gdp, errind, num_attrs, attrs )
     Pint        ws_type;          workstation type
     Pint        gdp;              3D GDP function number
     Pint        *errind;          OUT error indicator
     Pint        *num_attrs;       OUT number of attributes
     Pattrs      attrs[5];         OUT list of attributes
**************************************************************************/

   pinq_gdp3 ((Pint) *wtype, (Pint) *gdp, &cerror, &cnum, attrs);
   *errind = cerror;
   if (*errind) return;
   *nbnd = cnum;

   for (i = 0; i < *nbnd; i++)
      switch (attrs[i])
      {
      case PATTR_LINE:
	 bndl[i] = 0;
	 break;
      case PATTR_MARKER:
	 bndl[i] = 1;
	 break;
      case PATTR_TEXT:
	 bndl[i] = 2;
	 break;
      case PATTR_INT:
	 bndl[i] = 3;
	 break;
      case PATTR_EDGE:
	 bndl[i] = 4;
	 break;
      }
}
