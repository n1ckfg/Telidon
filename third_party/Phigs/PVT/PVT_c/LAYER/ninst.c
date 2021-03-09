#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     INITIALIZE STRING - initialize a STRING input  device  using
     2D data

  FORTRAN Syntax
     SUBROUTINE pinst ( WKID, STDNR, LSTR, ISTR, PET, XMIN, XMAX, YMIN, YMAX,
         LDR, DATREC )
     INTEGER     WKID                workstation identifier
     INTEGER     STDNR               string device number
     INTEGER     LSTR                length of the initial string (>= 0)
     CHARACTER*(*)                   ISTRinitial string
     INTEGER     PET                 prompt/echo type
     REAL        XMIN, XMAX, YMIN, YMAXecho area in device coordinates
     INTEGER     LDR                 dimension of data record array
     CHARACTER*80                    DATREC(LDR)data record

**************************************************************************/
#ifdef NO_PROTO
ninst (wkid, stdnr, lstr, istr, pet, xmin, xmax, ymin, ymax, ldr, datrec, istrlen, clen)
   integer      *wkid,
            *stdnr,
            *lstr,
            *pet,
            *ldr,
             istrlen,
             clen;
   real    *xmin,
            *xmax,
            *ymin,
            *ymax;
   char     *istr;
   cdatrec  *datrec;
#else
ninst (integer *wkid, integer *stdnr, integer *lstr, char *istr, integer *pet, real *xmin, real *xmax,
real *ymin, real *ymax, integer *ldr, cdatrec * datrec, integer istrlen, integer clen)
#endif

{
   Plimit    echo_area;
   Pstring_data record;
   char     *string;
   char  *strncpy();

   if (datrec->il != 2)
   {
      return;
   }

   record.in_buf_size = datrec->ia[0];

/* USERMOD: Users may insert additional needed initialization
   of record, since Pstring_data is implementation-defined.  */

   echo_area.x_min = *xmin;
   echo_area.x_max = *xmax;
   echo_area.y_min = *ymin;
   echo_area.y_max = *ymax;

   string = (char *) calloc (istrlen + 1, sizeof (char));
   strncpy (string, istr, istrlen);
   string[istrlen] = '\0';

/**************************************************************************
  C Syntax
     void
     pinit_string ( ws, dev, init, pet, echo_area, record )
     Pint           ws;              workstation identifier
     Pint           dev;             string device number
     char           *init;           initial string
     Pint           pet;             prompt and echo type
     Plimit         *echo_area;      echo area pointer
     Pstring_data   *record;         data record pointer
**************************************************************************/

   pinit_string ((Pint) *wkid, (Pint) *stdnr, string, (Pint) *pet,
                 &echo_area, &record);

   free (string);
}
