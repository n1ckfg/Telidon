#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     ELEMENT SEARCH - search for next matching element in  speci-
     fied structure

  FORTRAN Syntax
     SUBROUTINE pels  (  STRID, STRTEP, SRCDIR, EISN, EIS, EESN, EES, ERRIND, STATUS,
         FNDEP  )
     INTEGER     STRID             structure identifier
     INTEGER     STRTEP            start element pointer
     INTEGER     SRCDIR            search direction (PBWD, PFWD)
     INTEGER     EISN              number of elements in element inclusion set
     INTEGER     EIS(EISN)         element inclusion set
     INTEGER     EESN              number of elements in element exclusion set
     INTEGER     EES(EESN)         element exclusion set
     INTEGER     ERRIND            OUT error indicator
     INTEGER     STATUS            OUT status indicator (PFAIL, PSUCC)
     INTEGER     FNDEP             OUT found element pointer
**************************************************************************/
#ifdef NO_PROTO
nels (strid, strtep, srcdir, eisn, eis, eesn, ees, errind, status, fndep)
   integer      *strid,
            *strtep,
            *srcdir,
            *eisn,
             eis[],
            *eesn,
             ees[],
            *errind,
            *status,
            *fndep;
#else
nels (integer *strid, integer *strtep, integer *srcdir, integer *eisn, integer eis[], integer *eesn,
      integer ees[], integer *errind, integer *status, integer *fndep)
#endif
{
   Pint      struct_id, cerror, i;
   Pint      start_el;
   Psearch_dir dir;
   Pelem_type_list incl;
   Pelem_type_list excl;
   Pelem_type convert ();
   Psearch_status s_status;
   Pint      found_el;

   struct_id = *strid;
   start_el = *strtep;

   dir = *srcdir;
   switch (*srcdir)
   {
   case 0:			/***  PBWD=0  ***/
      dir = PDIR_BACKWARD;
      break;
   case 1:			/***  PFWD=1  ***/
      dir = PDIR_FORWARD;
      break;
   }

   incl.num_elem_types = *eisn;
   incl.elem_types = (Pelem_type *) calloc (*eisn, sizeof (Pelem_type));

   excl.num_elem_types = *eesn;
   excl.elem_types = (Pelem_type *) calloc (*eesn, sizeof (Pelem_type));

   for (i = 0; i < *eisn; i++)
   {
      incl.elem_types[i] = convert (eis[i]);
   }
   for (i = 0; i < *eesn; i++)
   {
      excl.elem_types[i] = convert (ees[i]);
   }

/**************************************************************************
  C Syntax
     void
     pelem_search  (  struct_id, start_el, dir, incl, excl, errind, status, found_el  )
     Pint        struct_id;        structure identifier
     Pint        start_el;         starting element pointer
     Psearch_dir dir;              search direction
     Pelem_type_list               *incl;element incl. list
     Pelem_type_list               *excl;element excl. list
     Pint        *errind;          OUT error indicator
     Psearch_status                *status;OUT search status
     Pint        *found_el;        OUT found element pointer
**************************************************************************/

   pelem_search (struct_id, start_el, dir, &incl, &excl,
      &cerror, &s_status, &found_el);
   *errind = cerror;

   free (incl.elem_types);
   free (excl.elem_types);

   *status = s_status;
   switch (s_status)
   {
   case 0:			/*** PFAIL ***/
      *status = PSEARCH_STATUS_FAILURE;
      break;
   case 1:			/*** PSUCC ***/
      *status = PSEARCH_STATUS_SUCCESS;
      *fndep = found_el;
   }
}

Pelem_type convert (f_type)
   int       f_type;
{
   switch (f_type)
   {
   case 0:
      return (PELEM_ALL);
      break;
   case 1:
      return (PELEM_NIL);
      break;
   case 2:
      return (PELEM_POLYLINE3);
      break;
   case 3:
      return (PELEM_POLYLINE);
      break;
   case 4:
      return (PELEM_POLYMARKER3);
      break;
   case 5:
      return (PELEM_POLYMARKER);
      break;
   case 6:
      return (PELEM_TEXT3);
      break;
   case 7:
      return (PELEM_TEXT);
      break;
   case 8:
      return (PELEM_ANNO_TEXT_REL3);
      break;
   case 9:
      return (PELEM_ANNO_TEXT_REL);
      break;
   case 10:
      return (PELEM_FILL_AREA3);
      break;
   case 11:
      return (PELEM_FILL_AREA);
      break;
   case 12:
      return (PELEM_FILL_AREA_SET3);
      break;
   case 13:
      return (PELEM_FILL_AREA_SET);
      break;
   case 14:
      return (PELEM_CELL_ARRAY3);
      break;
   case 15:
      return (PELEM_CELL_ARRAY);
      break;
   case 16:
      return (PELEM_GDP3);
      break;
   case 17:
      return (PELEM_GDP);
      break;
   case 18:
      return (PELEM_LINE_IND);
      break;
   case 19:
      return (PELEM_MARKER_IND);
      break;
   case 20:
      return (PELEM_TEXT_IND);
      break;
   case 21:
      return (PELEM_INT_IND);
      break;
   case 22:
      return (PELEM_EDGE_IND);
      break;
   case 23:
      return (PELEM_LINETYPE);
      break;
   case 24:
      return (PELEM_LINEWIDTH);
      break;
   case 25:
      return (PELEM_LINE_COLR_IND);
      break;
   case 26:
      return (PELEM_MARKER_TYPE);
      break;
   case 27:
      return (PELEM_MARKER_SIZE);
      break;
   case 28:
      return (PELEM_MARKER_COLR_IND);
      break;
   case 29:
      return (PELEM_TEXT_FONT);
      break;
   case 30:
      return (PELEM_TEXT_PREC);
      break;
   case 31:
      return (PELEM_CHAR_EXPAN);
      break;
   case 32:
      return (PELEM_CHAR_SPACE);
      break;
   case 34:
      return (PELEM_CHAR_HT);
      break;
   case 33:
      return (PELEM_TEXT_COLR_IND);
      break;
   case 35:
      return (PELEM_CHAR_UP_VEC);
      break;
   case 36:
      return (PELEM_TEXT_PATH);
      break;
   case 37:
      return (PELEM_TEXT_ALIGN);
      break;
   case 38:
      return (PELEM_ANNO_CHAR_HT);
      break;
   case 39:
      return (PELEM_ANNO_CHAR_UP_VEC);
      break;
   case 40:
      return (PELEM_ANNO_PATH);
      break;
   case 41:
      return (PELEM_ANNO_ALIGN);
      break;
   case 42:
      return (PELEM_ANNO_STYLE);
      break;
   case 43:
      return (PELEM_INT_STYLE);
      break;
   case 44:
      return (PELEM_INT_STYLE_IND);
      break;
   case 45:
      return (PELEM_INT_COLR_IND);
      break;
   case 46:
      return (PELEM_EDGE_FLAG);
      break;
   case 47:
      return (PELEM_EDGETYPE);
      break;
   case 48:
      return (PELEM_EDGEWIDTH);
      break;
   case 49:
      return (PELEM_EDGE_COLR_IND);
      break;
   case 50:
      return (PELEM_PAT_SIZE);
      break;
   case 51:
      return (PELEM_PAT_REF_POINT_VECS);
      break;
   case 52:
      return (PELEM_PAT_REF_POINT);
      break;
   case 53:
      return (PELEM_ADD_NAMES_SET);
      break;
   case 54:
      return (PELEM_REMOVE_NAMES_SET);
      break;
   case 55:
      return (PELEM_INDIV_ASF);
      break;
   case 56:
      return (PELEM_HLHSR_ID);
      break;
   case 57:
      return (PELEM_LOCAL_MODEL_TRAN3);
      break;
   case 58:
      return (PELEM_LOCAL_MODEL_TRAN);
      break;
   case 59:
      return (PELEM_GLOBAL_MODEL_TRAN3);
      break;
   case 60:
      return (PELEM_GLOBAL_MODEL_TRAN);
      break;
   case 61:
      return (PELEM_MODEL_CLIP_VOL3);
      break;
   case 62:
      return (PELEM_MODEL_CLIP_VOL);
      break;
   case 63:
      return (PELEM_MODEL_CLIP_IND);
      break;
   case 64:
      return (PELEM_RESTORE_MODEL_CLIP_VOL);
      break;
   case 65:
      return (PELEM_VIEW_IND);
      break;
   case 66:
      return (PELEM_EXEC_STRUCT);
      break;
   case 67:
      return (PELEM_LABEL);
      break;
   case 68:
      return (PELEM_APPL_DATA);
      break;
   case 69:
      return (PELEM_GSE);
      break;
   case 70:
      return (PELEM_PICK_ID);
      break;
   default:
      return (f_type);
      break;
   }
}
