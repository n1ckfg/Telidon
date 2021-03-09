#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INDIVIDUAL ASF - create structure element to set current
     Aspect Source Flag (ASF) for attribute

  FORTRAN Syntax
     SUBROUTINE psiasf ( ASPCID, ASFVAL )
     INTEGER     ASPCID            aspect identifier
     INTEGER     ASFVAL            aspect source flag value (PBUNDL, PINDIV)
**************************************************************************/
#ifdef NO_PROTO
nsiasf (aspcid, asfval)
   integer      *aspcid,
            *asfval;
#else
nsiasf (integer *aspcid, integer *asfval)
#endif
{
   Paspect   att_id;
   Pasf      att_source;

   att_id = *aspcid;
   switch (*aspcid)
   {
   case 0:
      att_id = PASPECT_LINETYPE;
      break;
   case 1:
      att_id = PASPECT_LINEWIDTH;
      break;
   case 2:
      att_id = PASPECT_LINE_COLR_IND;
      break;
   case 3:
      att_id = PASPECT_MARKER_TYPE;
      break;
   case 4:
      att_id = PASPECT_MARKER_SIZE;
      break;
   case 5:
      att_id = PASPECT_MARKER_COLR_IND;
      break;
   case 6:
      att_id = PASPECT_TEXT_FONT;
      break;
   case 7:
      att_id = PASPECT_TEXT_PREC;
      break;
   case 8:
      att_id = PASPECT_CHAR_EXPAN;
      break;
   case 9:
      att_id = PASPECT_CHAR_SPACE;
      break;
   case 10:
      att_id = PASPECT_TEXT_COLR_IND;
      break;
   case 11:
      att_id = PASPECT_INT_STYLE;
      break;
   case 12:
      att_id = PASPECT_INT_STYLE_IND;
      break;
   case 13:
      att_id = PASPECT_INT_COLR_IND;
      break;
   case 14:
      att_id = PASPECT_EDGE_FLAG;
      break;
   case 15:
      att_id = PASPECT_EDGETYPE;
      break;
   case 16:
      att_id = PASPECT_EDGEWIDTH;
      break;
   case 17:
      att_id = PASPECT_EDGE_COLR_IND;
      break;
   }

   att_source = *asfval;
   switch (*asfval)
   {
   case 0:
      att_source = PASF_BUNDLED;
      break;
   case 1:
      att_source = PASF_INDIV;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_indiv_asf ( att_id, att_source )
     Paspect     att_id;           attribute identifier
     Pasf        att_source;       attribute source
**************************************************************************/

   pset_indiv_asf (att_id, att_source);
}
