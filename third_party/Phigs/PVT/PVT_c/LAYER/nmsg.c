#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     MESSAGE - display message on workstation

  FORTRAN Syntax
     SUBROUTINE pmsg ( WKID, MESS )
     INTEGER     WKID              workstation identifier
     CHARACTER*(*)                 MESSmessage

**************************************************************************/
#ifdef NO_PROTO
nmsg (wkid, mess, clen)
   integer      *wkid;
   char     *mess;
   integer       clen;
#else
nmsg (integer *wkid, char *mess, integer clen)
#endif
{
   char *strncpy();
   char     *string;
   string = (char *) calloc (clen + 1, sizeof (char));
   strncpy (string, mess, clen);
   string[clen] = '\0';

/**************************************************************************
  C Syntax
     void
     pmessage ( ws, msg )
     Pint        ws;               workstation identifier
     char        *msg;             message string
**************************************************************************/

   pmessage ((Pint) *wkid, string);

   free (string);
}
