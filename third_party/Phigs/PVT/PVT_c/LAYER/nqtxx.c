#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE TEXT EXTENT  -  obtain  extent  rectangle  for  text
     string

  FORTRAN Syntax
     SUBROUTINE pqtxx ( WKTYPE, FONT, CHXP, CHSP, CHH, TXP, TXALH, TXALV,
          STR, ERRIND, TXEXRX, TXEXRY, COPX, COPY )
     INTEGER     WKTYPE            workstation type
     INTEGER     FONT              text font
     REAL        CHXP              character expansion factor
     REAL        CHSP              character spacing
     REAL        CHH               character height
     INTEGER     TXP               text path
     INTEGER     TXALH             text alignment horizontal
     INTEGER     TXALV             text alignment vertical
     CHARACTER*(*)                 STRcharacter string
     INTEGER     ERRIND            OUT error indicator
     REAL        TXEXRX(2), TXEXRY(2)OUT text extent rectangle
     REAL        COPX, COPY        OUT concatenation offset

**************************************************************************/
#ifdef NO_PROTO
nqtxx (wktype, font, chxp, chsp, chh, txp, txalh, txalv, str,
       errind, txexrx, txexry, copx, copy, clen)
   integer      *wktype,
            *font,
            *txp,
            *txalh,
            *txalv,
            *errind;
   real    *chxp,
            *chsp,
            *chh,
             txexrx[],
             txexry[],
            *copx,
            *copy;
   char     *str;
   long      clen;
#else
nqtxx (integer *wktype, integer *font, real *chxp, real *chsp, real *chh, 
       integer *txp,
       integer *txalh, integer *txalv, char *str,
       integer *errind, real txexrx[], real txexry[],
       real *copx, real *copy, long clen)
#endif
{
   Ptext_path path;
   Phor_text_align hor;
   Pvert_text_align ver;
   Prect     rect;
   Ppoint    offset;
   char     *string;
   char *strncpy();
   Pint  cerror;


   string = (char *) calloc (clen + 1, sizeof (char));
   strncpy (string, str, clen);
   string[clen] = '\0';

   path = *txp;
   switch (*txp)
   {
   case 0:			/*** PRIGHT ***/
      path = PPATH_RIGHT;
      break;
   case 1:			/*** PLEFT ***/
      path = PPATH_LEFT;
      break;
   case 2:			/*** PUP ***/
      path = PPATH_UP;
      break;
   case 3:			/*** PDOWN ***/
      path = PPATH_DOWN;
      break;
   }


   hor = *txalh;
   switch (*txalh)
   {
   case 0:			/*** PAHNOR ***/
      hor = PHOR_NORM;
      break;
   case 1:			/*** PALEFT ***/
      hor = PHOR_LEFT;
      break;
   case 2:			/*** PACENT ***/
      hor = PHOR_CTR;
      break;
   case 3:			/*** PARITE ***/
      hor = PHOR_RIGHT;
      break;
   }

   ver = *txalv;
   switch (*txalv)
   {
   case 0:			/*** PAVNOR ***/
      ver = PVERT_NORM;
      break;
   case 1:			/*** PATOP ***/
      ver = PVERT_TOP;
      break;
   case 2:			/*** PACAP ***/
      ver = PVERT_CAP;
      break;
   case 3:			/*** PAHALF ***/
      ver = PVERT_HALF;
      break;
   case 4:			/*** PABASE ***/
      ver = PVERT_BASE;
      break;
   case 5:			/*** PABOTT ***/
      ver = PVERT_BOTTOM;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pinq_text_extent ( wst, font, exp, sp, ht, path, hor, ver, 
                        str, errind, rect, offset )
     Pint        wst;              workstation type
     Pint        font;             text font
     Pfloat      exp;              char expansion factor
     Pfloat      sp;               char spacing
     Pfloat      ht;               char height
     Ptext_path  path;             text path
     Phor_text_align               hor;horizontal alignment
     Pvert_text_align              ver;vertical alignment
     char        *str;             text string
     Pint        *errind;          OUT error indicator
     Prect       *rect;            OUT extent rectangle
     Ppoint      *offset;          OUT concatenation offset
**************************************************************************/

   pinq_text_extent ((Pint) *wktype, (Pint) *font,
      (Pfloat) *chxp, (Pfloat) *chsp, (Pfloat) *chh, path, hor, ver,
      string, &cerror, &rect, &offset);
   *errind = cerror;

   *copx = offset.x;
   *copy = offset.y;
   txexrx[0] = rect.p.x;
   txexrx[1] = rect.q.x;
   txexry[0] = rect.p.y;
   txexry[1] = rect.q.y;

   free (string);
}
