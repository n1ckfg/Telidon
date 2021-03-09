#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     GET ITEM TYPE FROM METAFILE - get type and length of current
     item from metafile

  FORTRAN Syntax
     SUBROUTINE pgtitm ( WKID, TYPE, IDRL )
     INTEGER     WKID               workstation identifier
     INTEGER     TYPE               OUT item type
     INTEGER     IDRL               OUT item data record length
                                   (to be received from PRDITM)
**************************************************************************/
#ifdef NO_PROTO
ngtitm (wkid, type, idrl)
   integer      *wkid,
            *type,
            *idrl;
#else
ngtitm (integer *wkid, integer *type, integer *idrl)
#endif
{
   Pint ctype, cidrl;

/**************************************************************************
  C Syntax
     void
     pget_item_type ( ws, type, length )
     Pint        ws;               workstation identifier
     Pint        *type;            OUT item type
     Pint        *length;          OUT item data record length
**************************************************************************/

   pget_item_type ((Pint) *wkid, &ctype, &cidrl);

   *type = ctype;
   *idrl = cidrl;

}
