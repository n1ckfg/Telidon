#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REQUEST STRING - request operator interaction with specified
     string device

  FORTRAN Syntax
     SUBROUTINE prqst ( WKID, STDNR, STAT, LOSTR, STR )
     INTEGER     WKID              workstation identifier
     INTEGER     STDNR             string device number
     INTEGER     STAT              OUT status (PNONE, POK)
     INTEGER     LOSTR             OUT number of characters returned
     CHARACTER*(*)                 STROUT character string

**************************************************************************/
#ifdef NO_PROTO
nrqst (wkid, stdnr, stat, lostr, str, clen)
   integer      *wkid,
            *stdnr,
            *stat,
            *lostr;
   char     *str;
   integer       clen;
#else
nrqst (integer *wkid, integer *stdnr, integer *stat, 
       integer *lostr, char *str, integer clen)
#endif
{
   Pin_status in_status;
   char      string[300];	/***  Must pre-allocate   ***/
   char     *strcpy();
   char     *strncpy();
/**************************************************************************
  C Syntax
     void
     preq_string ( ws, dev, in_status, string )
     Pint        ws;               workstation identifier
     Pint        dev;              string device number
     Pin_status  *in_status;       OUT input string
     char        *string;          OUT string
**************************************************************************/

   preq_string ((Pint) *wkid, (Pint) *stdnr, &in_status, string);

   *stat = in_status;
   switch (in_status)
   {
   case PIN_STATUS_NONE:
      *stat = 0;
      break;
   case PIN_STATUS_OK:
      *stat = 1;
      break;
   case PIN_STATUS_NO_IN:
      *stat = 2;
      break;
   }

   *lostr = strlen (string);

   if ( *lostr > clen )  /* String too big for Buffer */
   {
       strncpy (str, string, clen); /* Copy in what will fit */
       string[clen] = '\0';
   }
   else
      strcpy (str, string); /* Copy in everything */
}
