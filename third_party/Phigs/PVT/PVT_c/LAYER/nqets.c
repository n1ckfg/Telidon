#include <phigs.h>
#include "f2c.h"
#include <stddef.h>   /* Get Size_t */

/**************************************************************************
NAME
     INQUIRE ELEMENT TYPE AND SIZE -  obtain  type  and  size  of
     specified element

  FORTRAN Syntax
     SUBROUTINE pqets ( STRID, ELENUM, ERRIND, ELTYPE, IL, RL, SL )
     INTEGER     STRID          structure identifier
     INTEGER     ELENUM         element number
     INTEGER     ERRIND         OUT error indicator
     INTEGER     ELTYPE         OUT element type
     INTEGER     IL             OUT dimension of integer array
                                (this may be passed to PQCECO as ILL)
     INTEGER     RL             OUT dimension of real array
                                (this may be passed to PQCECO as IRL)
     INTEGER     SL             OUT dimension of character array
                                (this may be passed to PQCECO as ISL)
**************************************************************************/
#ifdef NO_PROTO
nqets (structid, elid, errind, elementtype, il, rl, sl)
   integer      *structid,
            *elid,
            *errind,
            *il,
            *rl,
            *sl,
            *elementtype;
#else
nqets (integer *structid, integer *elid, integer *errind, integer *elementtype,
       integer *il, integer *rl, integer *sl)
#endif
{
   int       i;
   Pint      struct_id, cerror, element;
   Pstore    store;
   Pelem_data *data;
   Pelem_type   element_type;
   size_t    size;

   struct_id = *structid;
   element = *elid;

/**************************************************************************
  C Syntax
     void
     pinq_elem_type_size ( struct_id, element, errind, type, size )
     Pint        struct_id;     structure identifier
     Pint        element;       element number
     Pint        *errind;       OUT error indicator
     Pelem_type  *type;         OUT element type
     size_t      *size;         OUT element size
**************************************************************************/

   pinq_elem_type_size (struct_id, element, &cerror, &element_type, &size);
   *errind = cerror;

/* Create the memory buffer if not already created. */
   pcreate_store (errind, &store);
   if (*errind)
   {
   /* Cannot create memory buffer */
      return;
   }
   pinq_elem_content (struct_id, element, store, errind, &data);
   *il = 0;
   *rl = 0;
   *sl = 0;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }

   *elementtype = element_type;

   switch (element_type)
   {
   case PELEM_ALL:
      break;
   case PELEM_NIL:
      break;
   case PELEM_POLYLINE3:
      *il = 1;
      *rl = 3 * data->point_list3.num_points;
      break;
   case PELEM_POLYLINE:
      *il = 1;
      *rl = 2 * data->point_list.num_points;
      break;
   case PELEM_POLYMARKER3:
      *il = 1;
      *rl = 3 * data->point_list3.num_points;
      break;
   case PELEM_POLYMARKER:
      *il = 1;
      *rl = 2 * data->point_list.num_points;
      break;
   case PELEM_TEXT3:
      *rl = 9;
      *sl = 1;
      break;
   case PELEM_TEXT:
      *rl = 2;
      *sl = 1;
      break;
   case PELEM_ANNO_TEXT_REL3:
      *rl = 6;
      *sl = 1;
      break;
   case PELEM_ANNO_TEXT_REL:
      *rl = 4;
      *sl = 1;
      break;
   case PELEM_FILL_AREA3:
      *il = 1;
      *rl = 3 * data->point_list3.num_points;
      break;
   case PELEM_FILL_AREA:
      *il = 1;
      *rl = 2 * data->point_list.num_points;
      break;
   case PELEM_FILL_AREA_SET3:
      *il = data->point_list_list3.num_point_lists;
      for (i = 0; i < *il; i++)
      {
	 *rl += data->point_list_list3.point_lists[i].num_points;
      }
      *rl = *rl * 3;
      break;
   case PELEM_FILL_AREA_SET:
      *il = data->point_list_list.num_point_lists;
      for (i = 0; i < *il; i++)
      {
	 *rl += data->point_list_list.point_lists[i].num_points;
      }
      *rl = *rl * 2;
      break;
   case PELEM_CELL_ARRAY3:
      *il = 2 + data->cell_array3.colr_array.dims.size_x
	 * data->cell_array3.colr_array.dims.size_y;
      *rl = 9;
      break;
   case PELEM_CELL_ARRAY:
      *il = 2 + data->cell_array.colr_array.dims.size_x
	 * data->cell_array.colr_array.dims.size_y;
      *rl = 4;
      break;
   case PELEM_GDP3:
      *il = 2;
      *rl = 3 * data->gdp3.point_list.num_points;

/* USERMOD: Users may insert computation of actual sl, since
   Pgdp3_data is implementation-defined.  */

      *sl = 1;
      break;
   case PELEM_GDP:
      *il = 2;
      *rl = 2 * data->gdp.point_list.num_points;
/* USERMOD: Users may insert computation of actual sl, since
   Pgdp_data is implementation-defined.  */
      *sl = 1;
      break;
   case PELEM_LINE_IND:
      *il = 1;
      break;
   case PELEM_MARKER_IND:
      *il = 1;
      break;
   case PELEM_TEXT_IND:
      *il = 1;
      break;
   case PELEM_INT_IND:
      *il = 1;
      break;
   case PELEM_EDGE_IND:
      *il = 1;
      break;
   case PELEM_LINETYPE:
      *il = 1;
      break;
   case PELEM_LINEWIDTH:
      *rl = 1;
      break;
   case PELEM_LINE_COLR_IND:
      *il = 1;
      break;
   case PELEM_MARKER_TYPE:
      *il = 1;
      break;
   case PELEM_MARKER_SIZE:
      *rl = 1;
      break;
   case PELEM_MARKER_COLR_IND:
      *il = 1;
      break;
   case PELEM_TEXT_FONT:
      *il = 1;
      break;
   case PELEM_TEXT_PREC:
      *il = 1;
      break;
   case PELEM_CHAR_EXPAN:
      *rl = 1;
      break;
   case PELEM_CHAR_SPACE:
      *rl = 1;
      break;
   case PELEM_TEXT_COLR_IND:
      *il = 1;
      break;
   case PELEM_CHAR_HT:
      *rl = 1;
      break;
   case PELEM_CHAR_UP_VEC:
      *rl = 2;
      break;
   case PELEM_TEXT_PATH:
      *il = 1;
      break;
   case PELEM_TEXT_ALIGN:
      *il = 2;
      break;
   case PELEM_ANNO_CHAR_HT:
      *rl = 1;
      break;
   case PELEM_ANNO_CHAR_UP_VEC:
      *rl = 2;
      break;
   case PELEM_ANNO_PATH:
      *il = 1;
      break;
   case PELEM_ANNO_ALIGN:
      *il = 2;
      break;
   case PELEM_ANNO_STYLE:
      *il = 1;
      break;
   case PELEM_INT_STYLE:
      *il = 1;
      break;
   case PELEM_INT_STYLE_IND:
      *il = 1;
      break;
   case PELEM_INT_COLR_IND:
      *il = 1;
      break;
   case PELEM_EDGE_FLAG:
      *il = 1;
      break;
   case PELEM_EDGETYPE:
      *il = 1;
      break;
   case PELEM_EDGEWIDTH:
      *rl = 1;
      break;
   case PELEM_EDGE_COLR_IND:
      *il = 1;
      break;
   case PELEM_PAT_SIZE:
      *rl = 2;
      break;
   case PELEM_PAT_REF_POINT_VECS:
      *rl = 9;
      break;
   case PELEM_PAT_REF_POINT:
      *rl = 2;
      break;
   case PELEM_ADD_NAMES_SET:
      *il = data->names.num_ints;
      break;
   case PELEM_REMOVE_NAMES_SET:
      *il = data->names.num_ints;
      break;
   case PELEM_INDIV_ASF:
      *il = 2;
      break;
   case PELEM_HLHSR_ID:
      *il = 1;
      break;
   case PELEM_LOCAL_MODEL_TRAN3:
      *il = 1;
      *rl = 16;
      break;
   case PELEM_LOCAL_MODEL_TRAN:
      *il = 1;
      *rl = 9;
      break;
   case PELEM_GLOBAL_MODEL_TRAN3:
      *rl = 16;
      break;
   case PELEM_GLOBAL_MODEL_TRAN:
      *rl = 9;
      break;
   case PELEM_MODEL_CLIP_VOL3:
      *il = 2;
      *rl = 6 * data->model_clip3.half_spaces.num_half_spaces;
      break;
   case PELEM_MODEL_CLIP_VOL:
      *il = 2;
      *rl = 4 * data->model_clip.half_spaces.num_half_spaces;
      break;
   case PELEM_MODEL_CLIP_IND:
      *il = 1;
      break;
   case PELEM_RESTORE_MODEL_CLIP_VOL:
      break;
   case PELEM_VIEW_IND:
      *il = 1;
      break;
   case PELEM_EXEC_STRUCT:
      *il = 1;
      break;
   case PELEM_LABEL:
      *il = 1;
      break;
   case PELEM_APPL_DATA:
   /*******   Check this out
      do we need to save data in a structure?  ****/
      break;
   case PELEM_GSE:
      *il = 1;
      break;
   case PELEM_PICK_ID:
      *il = 1;
      break;
   }

   pdel_store (&cerror, &store);
   *errind = cerror;

}
