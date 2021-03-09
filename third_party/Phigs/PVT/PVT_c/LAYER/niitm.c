#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     INTERPRET ITEM  -  interpret  supplied  metafile  item  data
     record

  FORTRAN Syntax
     SUBROUTINE piitm ( TYPE, NCHS, LDR, DATREC )
     INTEGER     TYPE              item type
     INTEGER     NCHS              number of significant characters in data record
     INTEGER     LDR               dimension of data record array
     CHARACTER*80                  DATREC(LDR)data record
**************************************************************************/
#ifdef NO_PROTO
niitm (type, nchs, ldr, datrec, lendat, clen)
   integer      *type,
            *nchs,
            *ldr,
             lendat,
             clen;
   cdatrec  *datrec;
#else
niitm (integer *type, integer *nchs, integer *ldr, cdatrec * datrec, integer lendat, integer clen)
#endif
{
   Pint      length;
   Pitem_data record;

   length = sizeof (cdatrec);
   record.unsupp.size = sizeof (cdatrec);
   record.unsupp.data = (void *) datrec;

/**************************************************************************
  C Syntax
     void
     pinterpret_item ( type, item_data_length, item_data )
     Pint        type;             item type
     Pint        item_data_length; item data record length
     Pitem_data  *item_data;       item data record
**************************************************************************/

   pinterpret_item ((Pint) *type, length, &record);

}
