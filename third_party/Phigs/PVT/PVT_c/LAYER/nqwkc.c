#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE WORKSTATION CONNECTION AND TYPE-  obtain  connection
     identifier and type of specified workstation

  FORTRAN Syntax
     SUBROUTINE pqwkc ( WKID, ERRIND, CONID, WTYPE )
     INTEGER     WKID              workstation identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     CONID             OUT connection identifier
     INTEGER     WTYPE             OUT workstation type
**************************************************************************/
#ifdef NO_PROTO
nqwkc (wkid, errind, conid, wtype)
   integer      *wkid,
            *errind,
            *conid,
            *wtype;
#else
nqwkc (integer *wkid, integer *errind, integer *conid, integer *wtype)
#endif
{
   Pint  cwtype, cerror;
   Pstore    store;
/* Create the memory buffer if not already created. */

   pcreate_store (&cerror, &store);
   if (cerror)
   {
   /* Cannot create memory buffer */
      return;
   }
/**************************************************************************
  C Syntax
     void
     pinq_ws_conn_type( ws, store, errind, conn_id, ws_type )
         Pint    ws;               workstation identifier
         Pstore  store;            handle to Store object
         Pint    *errind;          OUT error indicator
         void    **conn_id;        OUT connection identifier
         Pint    *ws_type;         OUT workstation type
**************************************************************************/

   pinq_ws_conn_type ((Pint) *wkid, store, &cerror, (void **)&conid, &cwtype);
   *errind = cerror;
   *wtype = cwtype;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }

   pdel_store (&cerror, &store);
}
