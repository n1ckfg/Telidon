#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE INPUT QUEUE OVERFLOW - obtain input  queue  overflow
     state of PHIGS error state list

  FORTRAN Syntax
     SUBROUTINE pqiqov ( ERRIND, WKID, ICL, IDN )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     WKID              OUT workstation identifier
     INTEGER     ICL               OUT input class
     INTEGER     IDN               OUT input device number
**************************************************************************/
#ifdef NO_PROTO
nqiqov (errind, wkid, icl, idn)
   integer      *errind,
            *wkid,
            *icl,
            *idn;
#else
nqiqov (integer *errind, integer *wkid, integer *icl, integer *idn)
#endif
{
   Pint      cwkid, cidn, cerror;
   Pin_class class;
/**************************************************************************
  C Syntax
     void
     pinq_in_overf ( errind, ws, class, dev )
     Pint        *errind;          OUT error indicator
     Pint        *ws;              OUT workstation identifier
     Pin_class   *class;           OUT input class
     Pint        *dev;             OUT input device number
**************************************************************************/

   pinq_in_overf (&cerror, &cwkid, &class, &cidn);
   *errind = cerror;
   *wkid = cwkid;
   *idn = cidn;

   *icl = class;
   switch (class)
   {
   case PIN_NONE:
      *icl = 0;
      break;
   case PIN_LOC:
      *icl = 1;
      break;
   case PIN_STROKE:
      *icl = 2;
      break;
   case PIN_VAL:
      *icl = 3;
      break;
   case PIN_CHOICE:
      *icl = 4;
      break;
   case PIN_PICK:
      *icl = 5;
      break;
   case PIN_STRING:
      *icl = 6;
      break;
   }
}
