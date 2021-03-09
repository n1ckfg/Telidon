#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE ELEMENT POINTER -  obtain  current  element  pointer
     value

  FORTRAN Syntax
     SUBROUTINE pqep ( ERRIND, EP )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     EP                OUT element pointer value
**************************************************************************/
#ifdef NO_PROTO
nqep (errind, ep)
   integer  *errind,
            *ep;
#else
nqep (integer *errind, integer *ep)
#endif
{
   Pint cerror, cep;
/**************************************************************************
  C Syntax
     void
     pinq_elem_ptr ( errind, ep_value )
     Pint        *errind;          OUT error indicator
     Pint        *ep_value;        OUT element pointer value
**************************************************************************/

   pinq_elem_ptr (&cerror, &cep);
   *errind = cerror;
   *ep = cep;
}
