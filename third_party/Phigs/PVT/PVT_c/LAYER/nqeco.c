#include <phigs.h>
#include "f2c.h"
#include <stddef.h>   /* Get Size_t */
#include "struct.h"

/**************************************************************************
NAME
     INQUIRE ELEMENT CONTENT - inquire the contents of the speci-
     fied element

  FORTRAN Syntax
     SUBROUTINE pqeco ( STRID, ELENUM, IIL, IRL, ISL,
                        ERRIND, IL, IA, RL, RA, SL, LSTR, STR )
     INTEGER     STRID             structure identifier
     INTEGER     ELENUM            element number
     INTEGER     IIL               dimension of integer array
     INTEGER     IRL               dimension of real array
     INTEGER     ISL               dimension of character array
     INTEGER     ERRIND            OUT error indicator
     INTEGER     IL                OUT number of integer entries
     INTEGER     IA(IIL)           OUT array containing integer entries
     INTEGER     RL                OUT number of real entries
     REAL        RA(IRL)           OUT array containing real entries
     INTEGER     SL                OUT number of character string entries
     INTEGER     LSTR(ISL)         OUT length of each character string entry
     CHARACTER*(*)                 STR(ISL)OUT character string entries

**************************************************************************/
#ifdef NO_PROTO
nqeco (structid, elid, iil, irl, isl,
       errind, il, ia, rl, ra, sl, lstr, str, lenstr)
   integer      *structid,
            *elid,
            *iil,
            *irl,
            *isl,
            *errind,
            *il,
             ia[],
            *rl,
            *sl,
             lstr[],
             lenstr;
   real     ra[];
   char     *str;
#else
nqeco (integer *structid, integer *elid, integer *iil, integer *irl, 
       integer *isl, integer *errind, integer *il, integer ia[], 
       integer *rl, real ra[], integer *sl,
       integer lstr[], char *str, integer lenstr)
#endif
{
   int       i,
             j,
             k;
   Pint      cerror, struct_id, element;
   Pstore    store;
   Pelem_data *data;
   Pelem_type element_type;
   size_t    size;
   char *strncpy();

   struct_id = *structid;
   element = *elid;

   pinq_elem_type_size (struct_id, element, &cerror, &element_type, &size);
   *errind = cerror;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
/* Create the memory buffer if not already created. */

   pcreate_store (&cerror, &store);
   *errind = cerror;

   if (*errind)
   {
   /* Cannot create memory buffer */
      return;
   }
/**************************************************************************
  C Syntax
     void
     pinq_elem_content ( struct_id, element, store, errind, data )
     Pint        struct_id;        structure identifier
     Pint        element;          element number
     Pstore      store;            handle to Store object
     Pint        *errind;          OUT error indicator
     Pelem_data  **data;           OUT data record
**************************************************************************/

   pinq_elem_content (struct_id, element, store, &cerror, &data);
   *errind = cerror;

   *il = 0;
   *rl = 0;
   *sl = 0;

   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }
   switch (element_type)
   {
   case PELEM_ALL:
      break;
   case PELEM_NIL:
      break;
   case PELEM_POLYLINE3:
      *il = 1;
      ia[0] = data->point_list3.num_points;
      *rl = 3 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->point_list3.points[i].x;
	 ra[ia[0] + i] = data->point_list3.points[i].y;
	 ra[2 * ia[0] + i] = data->point_list3.points[i].z;
      }
      break;
   case PELEM_POLYLINE:
      *il = 1;
      ia[0] = data->point_list.num_points;
      *rl = 2 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->point_list.points[i].x;
	 ra[ia[0] + i] = data->point_list.points[i].y;
      }
      break;
   case PELEM_POLYMARKER3:
      *il = 1;
      ia[0] = data->point_list3.num_points;
      *rl = 3 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->point_list3.points[i].x;
	 ra[ia[0] + i] = data->point_list3.points[i].y;
	 ra[2 * ia[0] + i] = data->point_list3.points[i].z;
      }
      break;
   case PELEM_POLYMARKER:
      *il = 1;
      ia[0] = data->point_list.num_points;
      *rl = 2 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->point_list.points[i].x;
	 ra[ia[0] + i] = data->point_list.points[i].y;
      }
      break;
   case PELEM_TEXT3:
      *rl = 9;
      ra[0] = data->text3.pos.x;
      ra[1] = data->text3.pos.y;
      ra[2] = data->text3.pos.z;
      ra[3] = data->text3.dir[0].delta_x;
      ra[4] = data->text3.dir[0].delta_y;
      ra[5] = data->text3.dir[0].delta_z;
      ra[6] = data->text3.dir[1].delta_x;
      ra[7] = data->text3.dir[1].delta_y;
      ra[8] = data->text3.dir[1].delta_z;
      *sl = 1;
      lstr[0] = lenstr > strlen (data->text3.char_string) ? strlen (data->text3.char_string) : -1;
      strncpy (str, data->text3.char_string, lstr[0]);
   /****  Blank fill rest of string, FORTRAN requirement ****/
      for (j = lstr[0]; j < lenstr; j++)
	 str[j] = ' ';
      break;
   case PELEM_TEXT:
      *rl = 2;
      ra[0] = data->text.pos.x;
      ra[1] = data->text.pos.y;
      *sl = 1;
      lstr[0] = lenstr > strlen (data->text.char_string) ? strlen (data->text.char_string) : -1;
      strncpy (str, data->text.char_string, lstr[0]);
   /****  Blank fill rest of string, FORTRAN requirement ****/
      for (j = lstr[0]; j < lenstr; j++)
	 str[j] = ' ';
      break;
   case PELEM_ANNO_TEXT_REL3:
      *rl = 6;
      ra[0] = data->anno_text_rel3.ref_point.x;
      ra[1] = data->anno_text_rel3.ref_point.y;
      ra[2] = data->anno_text_rel3.ref_point.z;
      ra[3] = data->anno_text_rel3.offset.delta_x;
      ra[4] = data->anno_text_rel3.offset.delta_y;
      ra[5] = data->anno_text_rel3.offset.delta_z;
      *sl = 1;
      lstr[0] = lenstr > strlen (data->anno_text_rel3.char_string)
	 ? strlen (data->anno_text_rel3.char_string) : -1;
      strncpy (str, data->anno_text_rel3.char_string, lstr[0]);
   /****  Blank fill rest of string, FORTRAN requirement ****/
      for (j = lstr[0]; j < lenstr; j++)
	 str[j] = ' ';
      break;
   case PELEM_ANNO_TEXT_REL:
      *rl = 4;
      ra[0] = data->anno_text_rel.ref_point.x;
      ra[1] = data->anno_text_rel.ref_point.y;
      ra[2] = data->anno_text_rel.offset.delta_x;
      ra[3] = data->anno_text_rel.offset.delta_y;
      *sl = 1;
      lstr[0] = lenstr > strlen (data->anno_text_rel.char_string)
	 ? strlen (data->anno_text_rel.char_string) : -1;
      strncpy (str, data->anno_text_rel.char_string, lstr[0]);
   /****  Blank fill rest of string, FORTRAN requirement ****/
      for (j = lstr[0]; j < lenstr; j++)
	 str[j] = ' ';
      break;
   case PELEM_FILL_AREA3:
      *il = 1;
      ia[0] = data->point_list3.num_points;
      *rl = 3 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->point_list3.points[i].x;
	 ra[ia[0] + i] = data->point_list3.points[i].y;
	 ra[2 * ia[0] + i] = data->point_list3.points[i].z;
      }
      break;
   case PELEM_FILL_AREA:
      *il = 1;
      ia[0] = data->point_list.num_points;
      *rl = 2 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->point_list.points[i].x;
	 ra[ia[0] + i] = data->point_list.points[i].y;
      }
      break;
   case PELEM_FILL_AREA_SET3:
      *il = data->point_list_list3.num_point_lists;
      for (i = 0; i < *il; i++)
      {
	 ia[i] = *rl + data->point_list_list3.point_lists[i].num_points;
	 *rl += data->point_list_list3.point_lists[i].num_points;
      }
      *rl = *rl * 3;
      k = 0;
      for (i = 0; i < *il; i++)
      {
	 for (j = 0; j < data->point_list_list3.point_lists[i].num_points; j++)
	 {
	    ra[k] = data->point_list_list3.point_lists[i].points[j].x;
	    ra[ia[*il - 1] + k] = data->point_list_list3.point_lists[i].points[j].y;
	    ra[2 * ia[*il - 1] + k++] = data->point_list_list3.point_lists[i].points[j].z;
	 }
      }
      break;
   case PELEM_FILL_AREA_SET:
      *il = data->point_list_list.num_point_lists;
      for (i = 0; i < *il; i++)
      {
	 ia[i] = *rl + data->point_list_list.point_lists[i].num_points;
	 *rl += data->point_list_list.point_lists[i].num_points;
      }
      *rl = *rl * 2;
      k = 0;
      for (i = 0; i < *il; i++)
      {
	 for (j = 0; j < data->point_list_list.point_lists[i].num_points; j++)
	 {
	    ra[k] = data->point_list_list.point_lists[i].points[j].x;
	    ra[ia[*il - 1] + k++] = data->point_list_list.point_lists[i].points[j].y;
	 }
      }
      break;
   case PELEM_CELL_ARRAY3:
      *il = 2 + data->cell_array3.colr_array.dims.size_x
	 * data->cell_array3.colr_array.dims.size_y;
      ia[0] = data->cell_array3.colr_array.dims.size_x;
      ia[1] = data->cell_array3.colr_array.dims.size_y;
      for (i = 2; i < *il; i++)
      {
	 ia[i] = data->cell_array3.colr_array.colr_array[i - 2];
      }
      *rl = 9;
      ra[0] = data->cell_array3.paral.p.x;
      ra[1] = data->cell_array3.paral.p.y;
      ra[2] = data->cell_array3.paral.p.z;
      ra[3] = data->cell_array3.paral.q.x;
      ra[4] = data->cell_array3.paral.q.y;
      ra[5] = data->cell_array3.paral.q.z;
      ra[6] = data->cell_array3.paral.r.x;
      ra[7] = data->cell_array3.paral.r.y;
      ra[8] = data->cell_array3.paral.r.z;
      break;
   case PELEM_CELL_ARRAY:
      *il = 2 + data->cell_array.colr_array.dims.size_x
	 * data->cell_array.colr_array.dims.size_y;
      ia[0] = data->cell_array.colr_array.dims.size_x;
      ia[1] = data->cell_array.colr_array.dims.size_y;
      for (i = 2; i < *il; i++)
      {
	 ia[i] = data->cell_array.colr_array.colr_array[i - 2];
      }
      *rl = 4;
      ra[0] = data->cell_array.rect.p.x;
      ra[1] = data->cell_array.rect.p.y;
      ra[2] = data->cell_array.rect.q.x;
      ra[3] = data->cell_array.rect.q.y;
      break;
   case PELEM_GDP3:
      *il = 2;
      ia[0] = data->gdp3.point_list.num_points;
      ia[1] = data->gdp3.id;
      *rl = 3 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->gdp3.point_list.points[i].x;
	 ra[ia[0] + i] = data->gdp3.point_list.points[i].y;
	 ra[2 * ia[0] + i] = data->gdp3.point_list.points[i].z;
      }

/* USERMOD: Users may insert computation of actual sl and str, since
   Pgdp3_data is implementation-defined.  */

      *sl = 1;
      lstr[0] = 80;
      memcpy ( str, data->gdp3.data.unsupp.data, sizeof (cdatrec));
      break;
   case PELEM_GDP:
      *il = 2;
      ia[0] = data->gdp.point_list.num_points;
      ia[1] = data->gdp.id;
      *rl = 2 * ia[0];
      for (i = 0; i < ia[0]; i++)
      {
	 ra[i] = data->gdp.point_list.points[i].x;
	 ra[ia[0] + i] = data->gdp.point_list.points[i].y;
      }

/* USERMOD: Users may insert computation of actual sl and str, since
   Pgdp_data is implementation-defined.  */

      *sl = 1;
      lstr[0] = 80;
      memcpy ( str, data->gdp.data.unsupp.data, sizeof (cdatrec));
      break;
   case PELEM_LINE_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_MARKER_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_TEXT_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_INT_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_EDGE_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_LINETYPE:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_LINEWIDTH:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_LINE_COLR_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_MARKER_TYPE:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_MARKER_SIZE:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_MARKER_COLR_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_TEXT_FONT:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_TEXT_PREC:
      *il = 1;
      switch (data->text_prec)
      {
      case PPREC_STRING:
	 ia[0] = 0;
	 break;
      case PPREC_CHAR:
	 ia[0] = 1;
	 break;
      case PPREC_STROKE:
	 ia[0] = 2;
	 break;
      }
      break;
   case PELEM_CHAR_EXPAN:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_CHAR_SPACE:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_TEXT_COLR_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_CHAR_HT:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_CHAR_UP_VEC:
      *rl = 2;
      ra[0] = data->char_up_vec.delta_x;
      ra[1] = data->char_up_vec.delta_y;
      break;
   case PELEM_TEXT_PATH:
      *il = 1;
      switch (data->text_path)
      {
      case PPATH_RIGHT:
	 ia[0] = 0;
	 break;
      case PPATH_LEFT:
	 ia[0] = 1;
	 break;
      case PPATH_UP:
	 ia[0] = 2;
	 break;
      case PPATH_DOWN:
	 ia[0] = 3;
	 break;
      }
      break;
   case PELEM_TEXT_ALIGN:
      *il = 2;
      switch (data->text_align.hor)
      {
      case PHOR_NORM:
	 ia[0] = 0;
	 break;
      case PHOR_LEFT:
	 ia[0] = 1;
	 break;
      case PHOR_CTR:
	 ia[0] = 2;
	 break;
      case PHOR_RIGHT:
	 ia[0] = 3;
	 break;
      }
      switch (data->text_align.vert)
      {
      case PVERT_NORM:
	 ia[1] = 0;
	 break;
      case PVERT_TOP:
	 ia[1] = 1;
	 break;
      case PVERT_CAP:
	 ia[1] = 2;
	 break;
      case PVERT_HALF:
	 ia[1] = 3;
	 break;
      case PVERT_BASE:
	 ia[1] = 4;
	 break;
      case PVERT_BOTTOM:
	 ia[1] = 5;
	 break;
      }
      break;
   case PELEM_ANNO_CHAR_HT:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_ANNO_CHAR_UP_VEC:
      *rl = 2;
      ra[0] = data->char_up_vec.delta_x;
      ra[1] = data->char_up_vec.delta_y;
      break;
   case PELEM_ANNO_PATH:
      *il = 1;
      switch (data->text_path)
      {
      case PPATH_RIGHT:
	 ia[0] = 0;
	 break;
      case PPATH_LEFT:
	 ia[0] = 1;
	 break;
      case PPATH_UP:
	 ia[0] = 2;
	 break;
      case PPATH_DOWN:
	 ia[0] = 3;
	 break;
      }
      break;
   case PELEM_ANNO_ALIGN:
      *il = 2;
      switch (data->text_align.hor)
      {
      case PHOR_NORM:
	 ia[0] = 0;
	 break;
      case PHOR_LEFT:
	 ia[0] = 1;
	 break;
      case PHOR_CTR:
	 ia[0] = 2;
	 break;
      case PHOR_RIGHT:
	 ia[0] = 3;
	 break;
      }
      switch (data->text_align.vert)
      {
      case PVERT_NORM:
	 ia[1] = 0;
	 break;
      case PVERT_TOP:
	 ia[1] = 1;
	 break;
      case PVERT_CAP:
	 ia[1] = 2;
	 break;
      case PVERT_HALF:
	 ia[1] = 3;
	 break;
      case PVERT_BASE:
	 ia[1] = 4;
	 break;
      case PVERT_BOTTOM:
	 ia[1] = 5;
	 break;
      }
      break;
   case PELEM_ANNO_STYLE:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_INT_STYLE:
      *il = 1;
      switch (data->int_style)
      {
      case PSTYLE_HOLLOW:
	 ia[0] = 0;
	 break;
      case PSTYLE_SOLID:
	 ia[0] = 1;
	 break;
      case PSTYLE_PAT:
	 ia[0] = 2;
	 break;
      case PSTYLE_HATCH:
	 ia[0] = 3;
	 break;
      case PSTYLE_EMPTY:
	 ia[0] = 4;
	 break;
      }
      break;
   case PELEM_INT_STYLE_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_INT_COLR_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_EDGE_FLAG:
      *il = 1;
      switch (data->edge_flag)
      {
      case PEDGE_OFF:
	 ia[0] = 0;
	 break;
      case PEDGE_ON:
	 ia[0] = 1;
	 break;
      }
      break;
   case PELEM_EDGETYPE:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_EDGEWIDTH:
      *rl = 1;
      ra[0] = data->float_data;
      break;
   case PELEM_EDGE_COLR_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_PAT_SIZE:
      *rl = 2;
      ra[0] = data->pat_size.size_x;
      ra[1] = data->pat_size.size_y;
      break;
   case PELEM_PAT_REF_POINT_VECS:
      *rl = 9;
      ra[0] = data->pat_ref_point_vecs.ref_point.x;
      ra[1] = data->pat_ref_point_vecs.ref_point.y;
      ra[2] = data->pat_ref_point_vecs.ref_point.z;
      ra[3] = data->pat_ref_point_vecs.ref_vec[0].delta_x;
      ra[4] = data->pat_ref_point_vecs.ref_vec[0].delta_y;
      ra[5] = data->pat_ref_point_vecs.ref_vec[0].delta_z;
      ra[6] = data->pat_ref_point_vecs.ref_vec[1].delta_x;
      ra[7] = data->pat_ref_point_vecs.ref_vec[1].delta_y;
      ra[8] = data->pat_ref_point_vecs.ref_vec[1].delta_z;
      break;
   case PELEM_PAT_REF_POINT:
      *rl = 2;
      ra[0] = data->pat_ref_point.x;
      ra[1] = data->pat_ref_point.y;
      break;
   case PELEM_ADD_NAMES_SET:
      for (i = 0; i < data->names.num_ints; i++)
	 ia[i] = data->names.ints[i];
      *il = data->names.num_ints;
      break;
   case PELEM_REMOVE_NAMES_SET:
      *il = data->names.num_ints;
      for (i = 0; i < *il; i++)
      {
	 ia[i] = data->names.ints[i];
      }
      break;
   case PELEM_INDIV_ASF:
      *il = 2;
      switch (data->asf.id)
      {
      case PASPECT_LINETYPE:
	 ia[0] = 0;
	 break;
      case PASPECT_LINEWIDTH:
	 ia[0] = 1;
	 break;
      case PASPECT_LINE_COLR_IND:
	 ia[0] = 2;
	 break;
      case PASPECT_MARKER_TYPE:
	 ia[0] = 3;
	 break;
      case PASPECT_MARKER_SIZE:
	 ia[0] = 4;
	 break;
      case PASPECT_MARKER_COLR_IND:
	 ia[0] = 5;
	 break;
      case PASPECT_TEXT_FONT:
	 ia[0] = 6;
	 break;
      case PASPECT_TEXT_PREC:
	 ia[0] = 7;
	 break;
      case PASPECT_CHAR_EXPAN:
	 ia[0] = 8;
	 break;
      case PASPECT_CHAR_SPACE:
	 ia[0] = 9;
	 break;
      case PASPECT_TEXT_COLR_IND:
	 ia[0] = 10;
	 break;
      case PASPECT_INT_STYLE:
	 ia[0] = 11;
	 break;
      case PASPECT_INT_STYLE_IND:
	 ia[0] = 12;
	 break;
      case PASPECT_INT_COLR_IND:
	 ia[0] = 13;
	 break;
      case PASPECT_EDGE_FLAG:
	 ia[0] = 14;
	 break;
      case PASPECT_EDGETYPE:
	 ia[0] = 15;
	 break;
      case PASPECT_EDGEWIDTH:
	 ia[0] = 16;
	 break;
      case PASPECT_EDGE_COLR_IND:
	 ia[0] = 17;
	 break;
      }
      switch (data->asf.source)
      {
      case PASF_BUNDLED:
	 ia[1] = 0;
	 break;
      case PASF_INDIV:
	 ia[1] = 1;
	 break;
      }
      break;
   case PELEM_HLHSR_ID:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_LOCAL_MODEL_TRAN3:
      *il = 1;
      switch (data->local_tran.compose_type)
      {
      case PTYPE_PRECONCAT:
	 ia[0] = 0;
	 break;
      case PTYPE_POSTCONCAT:
	 ia[0] = 1;
	 break;
      case PTYPE_REPLACE:
	 ia[0] = 2;
	 break;
      }
      *rl = 16;
      k = 0;
      for (i = 0; i < 4; i++)
      {
	 for (j = 0; j < 4; j++)
	 {
	    ra[k] = data->local_tran3.matrix[j][i];
	    k++;
	 }
      }
      break;
   case PELEM_LOCAL_MODEL_TRAN:
      *il = 1;
      switch (data->local_tran.compose_type)
      {
      case PTYPE_PRECONCAT:
	 ia[0] = 0;
	 break;
      case PTYPE_POSTCONCAT:
	 ia[0] = 1;
	 break;
      case PTYPE_REPLACE:
	 ia[0] = 2;
	 break;
      }
      *rl = 9;
      k = 0;
      for (i = 0; i < 3; i++)
      {
	 for (j = 0; j < 3; j++)
	 {
	    ra[k] = data->local_tran.matrix[j][i];
	    k++;
	 }
      }
      break;
   case PELEM_GLOBAL_MODEL_TRAN3:
      *rl = 16;
      k = 0;
      for (i = 0; i < 4; i++)
      {
	 for (j = 0; j < 4; j++)
	 {
	    ra[k] = data->global_tran3[j][i];
	    k++;
	 }
      }
      break;
   case PELEM_GLOBAL_MODEL_TRAN:
      *rl = 9;
      k = 0;
      for (i = 0; i < 3; i++)
      {
	 for (j = 0; j < 3; j++)
	 {
	    ra[k] = data->global_tran[j][i];
	    k++;
	 }
      }
      break;
   case PELEM_MODEL_CLIP_VOL3:
      *il = 2;
      ia[0] = data->model_clip3.op;
      ia[1] = data->model_clip3.half_spaces.num_half_spaces;
      *rl = 6 * ia[1];
      for (i = 0; i < ia[1]; i++)
      {
	 ra[(6 * i)] = data->model_clip3.half_spaces.half_spaces[i].point.x;
	 ra[(6 * i) + 1] = data->model_clip3.half_spaces.half_spaces[i].point.y;
	 ra[(6 * i) + 2] = data->model_clip3.half_spaces.half_spaces[i].point.z;
	 ra[(6 * i) + 3] = data->model_clip3.half_spaces.half_spaces[i].norm.delta_x;
	 ra[(6 * i) + 4] = data->model_clip3.half_spaces.half_spaces[i].norm.delta_y;
	 ra[(6 * i) + 5] = data->model_clip3.half_spaces.half_spaces[i].norm.delta_z;
      }
      break;
   case PELEM_MODEL_CLIP_VOL:
      *il = 2;
      ia[0] = data->model_clip.op;
      ia[1] = data->model_clip.half_spaces.num_half_spaces;
      *rl = 4 * ia[1];
      for (i = 0; i < ia[1]; i++)
      {
	 ra[(4 * i)] = data->model_clip.half_spaces.half_spaces[i].point.x;
	 ra[(4 * i) + 1] = data->model_clip.half_spaces.half_spaces[i].point.y;
	 ra[(4 * i) + 2] = data->model_clip.half_spaces.half_spaces[i].norm.delta_x;
	 ra[(4 * i) + 3] = data->model_clip.half_spaces.half_spaces[i].norm.delta_y;
      }
      break;
   case PELEM_MODEL_CLIP_IND:
      *il = 1;
      switch (data->clip_ind)
      {
      case PIND_NO_CLIP:
	 ia[0] = 0;
	 break;
      case PIND_CLIP:
	 ia[0] = 1;
	 break;
      }
      break;
   case PELEM_RESTORE_MODEL_CLIP_VOL:
      break;
   case PELEM_VIEW_IND:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_EXEC_STRUCT:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_LABEL:
      *il = 1;
      ia[0] = data->int_data;
      break;
   case PELEM_APPL_DATA:
      *sl = 1;
      lstr[0] = 80;
      memcpy (str, data->appl_data.data, sizeof (cdatrec));
      break;
   case PELEM_GSE:
      *il = 1;
      ia[0] = data->gse.id;
      *sl = 1;
      lstr[0] = 80;
      memcpy ( str, data->gse.data.unsupp.data, data->gse.data.unsupp.size);
      break;
   case PELEM_PICK_ID:
      *il = 1;
      ia[0] = data->int_data;
      break;
   }

   pdel_store (&cerror, &store);
   *errind = cerror;

}
