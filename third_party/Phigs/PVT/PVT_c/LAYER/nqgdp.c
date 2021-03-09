#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE GENERALIZED DRAWING PRIMITIVE -  obtain  generalized
     drawing primitive (GDP) attributes

  FORTRAN Syntax
     SUBROUTINE pqgdp ( WTYPE, GDP, ERRIND, NBND, BNDL )
     INTEGER     WTYPE             workstation type
     INTEGER     GDP               GDP identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NBND              OUT number of sets of attributes used
     INTEGER     BNDL(5)           OUT list of sets of attributes used
**************************************************************************/
#ifdef NO_PROTO
nqgdp (wtype, gdp, errind, nbnd, bndl)
   integer      *wtype,
            *gdp,
            *errind,
            *nbnd,
             bndl[];
#else
nqgdp (integer *wtype, integer *gdp, integer *errind, integer *nbnd, 
       integer bndl[])
#endif
{
   Pint      cnum, cerror, i;
   Pattrs    attrs[5];
/**************************************************************************
  C Syntax
     void
     pinq_gdp ( ws_type, gdp, errind, num_attrs, attrs )
     Pint        ws_type;          workstation type
     Pint        gdp;              GDP function number
     Pint        *errind;          OUT error indicator
     Pint        *num_attrs;       OUT number of attributes
     Pattrs      attrs[5];         OUT list of attributes
**************************************************************************/

   pinq_gdp ((Pint) *wtype, (Pint) *gdp, &cerror, &cnum, attrs);
   *errind = cerror;
   if (*errind) return;
   *nbnd = cnum;

   for (i = 0; i < 5; i++)
   {
      if (attrs[i] == PATTR_LINE)
	 bndl[i] = 0;
      if (attrs[i] == PATTR_MARKER)
	 bndl[i] = 1;
      if (attrs[i] == PATTR_TEXT)
	 bndl[i] = 2;
      if (attrs[i] == PATTR_INT)
	 bndl[i] = 3;
      if (attrs[i] == PATTR_EDGE)
	 bndl[i] = 4;
   }
}
