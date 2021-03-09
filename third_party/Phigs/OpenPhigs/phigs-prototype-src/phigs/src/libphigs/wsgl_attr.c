/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2014 Surplus Users Ham Society
*
*   Open PHIGS is free software: you can redistribute it and/or modify
*   it under the terms of the GNU Lesser General Public License as published by
*   the Free Software Foundation, either version 2.1 of the License, or
*   (at your option) any later version.
*
*   Open PHIGS is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public License
*   along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/gl.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/private/wsglP.h>

/*******************************************************************************
 * wsgl_set_matrix
 *
 * DESCR:	Setup matrix
 * RETURNS:	N/A
 */

static void wsgl_set_matrix(
    Pmatrix3 mat,
    int mult
    )
{
   int i, j;
   GLfloat m[16];
   GLfloat *mp = &m[0];

   for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
         *mp = mat[j][i];
         mp++;
      }
   }

   if (mult) {
      glMultMatrixf(m);
   }
   else {
      glLoadMatrixf(m);
   }
}

/*******************************************************************************
 * wsgl_update_projection
 *
 * DESCR:	Update projection matrix
 * RETURNS:	N/A
 */

void wsgl_update_projection(
   Ws *ws
   )
{
   Wsgl_handle wsgl = ws->render_context;

#ifdef DEBUG
   printf("Update projection\n");
#endif

   glMatrixMode(GL_PROJECTION);
   if (wsgl->render_mode == WS_RENDER_MODE_SELECT) {
      phg_mat_mul(wsgl->model_tran,
                  wsgl->pick_tran,
                  wsgl->cur_struct.view_rep.map_matrix);
      wsgl_set_matrix(wsgl->model_tran, FALSE);
   }
   else {
      wsgl_set_matrix(wsgl->cur_struct.view_rep.map_matrix, FALSE);
   }
}

/*******************************************************************************
 * wsgl_update_modelview
 *
 * DESCR:	Update modelview matrix
 * RETURNS:	N/A
 */

void wsgl_update_modelview(
   Ws *ws
   )
{
   Wsgl_handle wsgl = ws->render_context;

#ifdef DEBUG
   printf("Update modelview\n");
#endif

   glMatrixMode(GL_MODELVIEW);
   phg_mat_mul(wsgl->composite_tran,
               wsgl->cur_struct.global_tran,
               wsgl->cur_struct.local_tran);
   phg_mat_mul(wsgl->model_tran,
               wsgl->cur_struct.view_rep.ori_matrix,
               wsgl->composite_tran);
   wsgl_set_matrix(wsgl->model_tran, FALSE);
}

/*******************************************************************************
 * wsgl_set_view_ind
 *
 * DESCR:	Setup view
 * RETURNS:	N/A
 */

void wsgl_set_view_ind(
   Ws *ws,
   Pint ind
   )
{
   Phg_ret ret;
   Wsgl_handle wsgl = ws->render_context;

   (*ws->inq_representation)(ws,
                             ind,
                             PINQ_REALIZED,
                             PHG_ARGS_VIEWREP,
                             &ret);
   if (ret.err == 0) {
      memcpy(&wsgl->cur_struct.view_rep,
             &ret.data.rep.viewrep,
             sizeof(Pview_rep3));
      wsgl_update_projection(ws);
      wsgl_update_modelview(ws);
   }
}

/*******************************************************************************
 * wsgl_update_hlhsr_id
 *
 * DESCR:	Update depth buffer checking flag
 * RETURNS:	N/A
 */

void wsgl_update_hlhsr_id(
   Ws *ws
   )
{
   Wsgl_handle wsgl = ws->render_context;

   switch(wsgl->cur_struct.hlhsr_id) {
      case PHIGS_HLHSR_ID_OFF:
         glDepthFunc(GL_ALWAYS);
         break;

      case PHIGS_HLHSR_ID_ON:
         glDepthFunc(GL_LESS);
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * wsgl_set_asf
 *
 * DESCR:	Setup asf
 * RETURNS:	N/A
 */

void wsgl_set_asf(
   Ws_attr_st *ast,
   void *asf_info
   )
{
   Pasf_info *data = (Pasf_info *) asf_info;

   if (data->source == PASF_INDIV) {
      phg_nset_name_set(&ast->asf_nameset, data->id);
   }
   else {
      phg_nset_name_clear(&ast->asf_nameset, data->id);
   }
}

/*******************************************************************************
 * wsgl_set_colr
 *
 * DESCR:	Set colour value
 * RETURNS:	N/A
 */

void wsgl_set_colr(
   Pint colr_type,
   Pcoval *colr
   )
{
   switch(colr_type) {
      case PINDIRECT:
         glIndexi(colr->ind);
         break;

      case PMODEL_RGB:
         glColor3f(colr->direct.rgb.red,
                   colr->direct.rgb.green,
                   colr->direct.rgb.blue);
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * wsgl_set_gcolr
 *
 * DESCR:	Set colour
 * RETURNS:	N/A
 */

void wsgl_set_gcolr(
   Pgcolr *gcolr
   )
{
   switch(gcolr->type) {
      case PINDIRECT:
         glIndexi(gcolr->val.ind);
         break;

      case PMODEL_RGB:
         glColor3f(gcolr->val.general.x,
                   gcolr->val.general.y,
                   gcolr->val.general.z);
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * wsgl_colr_from_gcolr
 *
 * DESCR:	Get colour value from Pgcolr
 * RETURNS:	N/A
 */

void wsgl_colr_from_gcolr(
   Pcoval *colr,
   Pgcolr *gcolr
   )
{
   switch(gcolr->type) {
      case PINDIRECT:
         colr->ind = gcolr->val.ind;
         break;

      case PMODEL_RGB:
         colr->direct.rgb.red = gcolr->val.general.x;
         colr->direct.rgb.green = gcolr->val.general.y;
         colr->direct.rgb.blue = gcolr->val.general.z;
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * wsgl_set_line_ind
 *
 * DESCR:	Setup line index
 * RETURNS:	N/A
 */

void wsgl_set_line_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   )
{
   Phg_ret ret;

   (*ws->inq_representation)(ws,
                             ind,
                             PINQ_REALIZED,
                             PHG_ARGS_EXTLNREP,
                             &ret);
   if (ret.err == 0) {
      phg_attr_group_set_line_bundle(ws,
                                     attr_group,
                                     &ret.data.rep.extlnrep);
   }
}

/*******************************************************************************
 * wsgl_setup_line_attr
 *
 * DESCR:	Setup line attributes
 * RETURNS:	N/A
 */

void wsgl_setup_line_attr(
   Ws_attr_st *ast
   )
{
   Pint type;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_LINE_COLR_IND)) {
      wsgl_set_gcolr(&ast->indiv_group.line_bundle.colr);
   }
   else {
      wsgl_set_gcolr(&ast->bundl_group.line_bundle.colr);
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_LINETYPE)) {
      type = ast->indiv_group.line_bundle.type;
   }
   else {
      type = ast->bundl_group.line_bundle.type;
   }

   switch (type) {
      case PLINE_DASH:
         glLineStipple(1, 0x00ff);
         glEnable(GL_LINE_STIPPLE);
      break;

      case PLINE_DOT:
         glLineStipple(1, 0x0101);
         glEnable(GL_LINE_STIPPLE);
      break;

      case PLINE_DASH_DOT:
         glLineStipple(1, 0x1c47);
         glEnable(GL_LINE_STIPPLE);
      break;

      default:
         glDisable(GL_LINE_STIPPLE);
      break;
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_LINEWIDTH)) {
      glLineWidth(ast->indiv_group.line_bundle.width);
   }
   else {
      glLineWidth(ast->bundl_group.line_bundle.width);
   }

   glDisable(GL_LIGHTING);
}

/*******************************************************************************
 * wsgl_set_int_ind
 *
 * DESCR:	Setup interior index
 * RETURNS:	N/A
 */

void wsgl_set_int_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   )
{
   Phg_ret ret;

   (*ws->inq_representation)(ws,
                             ind,
                             PINQ_REALIZED,
                             PHG_ARGS_EXTINTERREP,
                             &ret);
   if (ret.err == 0) {
      phg_attr_group_set_int_bundle(ws,
                                    attr_group,
                                    &ret.data.rep.extinterrep);
   }
}

/*******************************************************************************
 * wsgl_get_int_colr
 *
 * DESCR:	Get interior colur
 * RETURNS:	Pointer to interiour colour
 */

Pgcolr* wsgl_get_int_colr(
   Ws_attr_st *ast
   )
{
   Pgcolr *gcolr;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_INT_COLR_IND)) {
      gcolr = &ast->indiv_group.int_bundle.colr;
   }
   else {
      gcolr = &ast->bundl_group.int_bundle.colr;
   }

   return gcolr;
}

/*******************************************************************************
 * wsgl_get_int_style
 *
 * DESCR:	Get interior style
 * RETURNS:	Interiour style
 */

Pint_style wsgl_get_int_style(
   Ws_attr_st *ast
   )
{
   Pint_style style;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_INT_STYLE)) {
      style = ast->indiv_group.int_bundle.style;
   }
   else {
      style = ast->bundl_group.int_bundle.style;
   }

   return style;
}

/*******************************************************************************
 * wsgl_setup_int_style
 *
 * DESCR:	Setup interior style
 * RETURNS:	N/A
 */

void wsgl_setup_int_style(
   Pint_style style
   )
{
   switch (style) {
      case PSTYLE_HOLLOW:
         glDisable(GL_POLYGON_STIPPLE);
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         break;

      case PSTYLE_SOLID:
         glDisable(GL_POLYGON_STIPPLE);
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         break;

      case PSTYLE_HATCH:
         glEnable(GL_POLYGON_STIPPLE);
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         break;

      default:
         glDisable(GL_POLYGON_STIPPLE);
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         break;
   }
}

/*******************************************************************************
 * wsgl_setup_int_attr_nocol
 *
 * DESCR:	Setup interior attributes without color
 * RETURNS:	N/A
 */

void wsgl_setup_int_attr_nocol(
   Ws *ws,
   Ws_attr_st *ast
   )
{
   Pint_style style;
   Pint style_ind;
   Pint shad_meth;

   Wsgl_handle wsgl = ws->render_context;

   style = wsgl_get_int_style(ast);
   if (style != wsgl->dev_st.int_style) {
      wsgl_setup_int_style(style);
      wsgl->dev_st.int_style = style;
   }

   if (phg_nset_name_is_set(&ast->asf_nameset,
                            (Pint) PASPECT_INT_STYLE_IND)) {
      style_ind = ast->indiv_group.int_bundle.style_ind;
   }
   else {
      style_ind = ast->bundl_group.int_bundle.style_ind;
   }

   if (style_ind != wsgl->dev_st.int_style_ind) {
      glPolygonStipple(wsgl_hatch_tbl[style_ind - 1]);
      wsgl->dev_st.int_style_ind = style_ind;
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_INT_SHAD_METH)) {
      shad_meth = ast->indiv_group.int_bundle.shad_meth;
   }
   else {
      shad_meth = ast->bundl_group.int_bundle.shad_meth;
   }

   if (shad_meth != wsgl->dev_st.int_shad_meth) {
      if (shad_meth == PSD_NONE) {
         glShadeModel(GL_FLAT);
      }
      else {
         glShadeModel(GL_SMOOTH);
      }
      wsgl->dev_st.int_shad_meth = shad_meth;
   }

   if (wsgl->cur_struct.lighting) {
      glEnable(GL_LIGHTING);
   }
   else {
      glDisable(GL_LIGHTING);
   }

   glCullFace(GL_BACK);
}

/*******************************************************************************
 * wsgl_setup_int_attr
 *
 * DESCR:	Setup interior attributes
 * RETURNS:	N/A
 */

void wsgl_setup_int_attr(
   Ws *ws,
   Ws_attr_st *ast
   )
{
   wsgl_set_gcolr(wsgl_get_int_colr(ast));
   wsgl_setup_int_attr_nocol(ws, ast);
}

/*******************************************************************************
 * wsgl_set_edge_ind
 *
 * DESCR:	Setup edge index
 * RETURNS:	N/A
 */

void wsgl_set_edge_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   )
{
   Phg_ret ret;

   (*ws->inq_representation)(ws,
                             ind,
                             PINQ_REALIZED,
                             PHG_ARGS_EXTEDGEREP,
                             &ret);
   if (ret.err == 0) {
      phg_attr_group_set_edge_bundle(ws,
                                     attr_group,
                                     &ret.data.rep.extedgerep);
   }
}

/*******************************************************************************
 * wsgl_get_edge_flag
 *
 * DESCR:	Get edge flag
 * RETURNS:	Edge flag
 */

Pedge_flag wsgl_get_edge_flag(
   Ws_attr_st *ast
   )
{
   Pedge_flag flag;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_EDGE_FLAG)) {
      flag = ast->indiv_group.edge_bundle.flag;
   }
   else {
      flag = ast->bundl_group.edge_bundle.flag;
   }

   return flag;
}

/*******************************************************************************
 * wsgl_get_edge_width
 *
 * DESCR:	Get edge width
 * RETURNS:	Edge width
 */

Pfloat wsgl_get_edge_width(
   Ws_attr_st *ast
   )
{
   Pfloat width;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_EDGEWIDTH)) {
      width = ast->indiv_group.edge_bundle.width;
   }
   else {
      width = ast->bundl_group.edge_bundle.width;
   }

   return width;
}

/*******************************************************************************
 * wsgl_setup_edge_attr
 *
 * DESCR:	Setup edge attributes
 * RETURNS:	N/A
 */

void wsgl_setup_edge_attr(
   Ws_attr_st *ast
   )
{
   Pint type;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_EDGE_COLR_IND)) {
      wsgl_set_gcolr(&ast->indiv_group.edge_bundle.colr);
   }
   else {
      wsgl_set_gcolr(&ast->bundl_group.edge_bundle.colr);
   }

   glLineWidth(wsgl_get_edge_width(ast));

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_EDGETYPE)) {
      type = ast->indiv_group.edge_bundle.type;
   }
   else {
      type = ast->bundl_group.edge_bundle.type;
   }

   /* Line style */
   switch (type) {
      case PLINE_DASH:
         glLineStipple(1, 0x00ff);
         glEnable(GL_LINE_STIPPLE);
      break;

      case PLINE_DOT:
         glLineStipple(1, 0x0101);
         glEnable(GL_LINE_STIPPLE);
      break;

      case PLINE_DASH_DOT:
         glLineStipple(1, 0x1c47);
         glEnable(GL_LINE_STIPPLE);
      break;

      default:
         glDisable(GL_LINE_STIPPLE);
      break;
   }

   glDisable(GL_LIGHTING);
}


/*******************************************************************************
 * wsgl_set_marker_ind
 *
 * DESCR:	Setup marker index
 * RETURNS:	N/A
 */

void wsgl_set_marker_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   )
{
   Phg_ret ret;

   (*ws->inq_representation)(ws,
                             ind,
                             PINQ_REALIZED,
                             PHG_ARGS_EXTMKREP,
                             &ret);
   if (ret.err == 0) {
      phg_attr_group_set_marker_bundle(ws,
                                       attr_group,
                                       &ret.data.rep.extmkrep);
   }
}

/*******************************************************************************
 * wsgl_setup_marker_attr
 *
 * DESCR:	Setup marker attributes
 * RETURNS:	N/A
 */

void wsgl_setup_marker_attr(
   Ws_attr_st *ast,
   Pint *type,
   Pfloat *size
   )
{
   if (phg_nset_name_is_set(&ast->asf_nameset,
                            (Pint) PASPECT_MARKER_COLR_IND)) {
      wsgl_set_gcolr(&ast->indiv_group.marker_bundle.colr);
   }
   else {
      wsgl_set_gcolr(&ast->bundl_group.marker_bundle.colr);
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_MARKER_TYPE)) {
      *type = ast->indiv_group.marker_bundle.type;
   }
   else {
      *type = ast->bundl_group.marker_bundle.type;
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_MARKER_SIZE)) {
      *size = ast->indiv_group.marker_bundle.size;
   }
   else {
      *size = ast->bundl_group.marker_bundle.size;
   }

   glDisable(GL_LIGHTING);
}

/*******************************************************************************
 * wsgl_setup_background
 *
 * DESCR:	Setup background colour
 * RETURNS:	N/A
 */

void wsgl_setup_background(
   Ws *ws
   )
{
   Wsgl_handle wsgl = ws->render_context;

   glDisable(GL_POLYGON_STIPPLE);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glColor3f(wsgl->background.val.general.x,
             wsgl->background.val.general.y,
             wsgl->background.val.general.z);

   /* Need to restore polygon mode */
   wsgl->dev_st.int_style = -1;
}

/*******************************************************************************
 * wsgl_set_text_ind
 *
 * DESCR:	Setup text index
 * RETURNS:	N/A
 */

void wsgl_set_text_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   )
{
   Phg_ret ret;

   (*ws->inq_representation)(ws,
                             ind,
                             PINQ_REALIZED,
                             PHG_ARGS_EXTTXREP,
                             &ret);
    if (ret.err == 0) {
      phg_attr_group_set_text_bundle(ws,
                                     attr_group,
                                     &ret.data.rep.exttxrep);
   }
}

/*******************************************************************************
 * wsgl_get_text_prec
 *
 * DESCR:	Get text precision
 * RETURNS:	Text precision
 */

Ptext_prec wsgl_get_text_prec(
   Ws_attr_st *ast
   )
{
   Ptext_prec prec;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_TEXT_PREC)) {
      prec = ast->indiv_group.text_bundle.prec;
   }
   else {
      prec = ast->bundl_group.text_bundle.prec;
   }

   return prec;
}

/*******************************************************************************
 * wsgl_setup_text_attr
 *
 * DESCR:	Setup text attributes
 * RETURNS:	N/A
 */

void wsgl_setup_text_attr(
   Ws_attr_st *ast,
   Phg_font **fnt,
   Pfloat *char_expan
   )
{
   Pint font;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_TEXT_COLR_IND)) {
      wsgl_set_gcolr(&ast->indiv_group.text_bundle.colr);
   }
   else {
      wsgl_set_gcolr(&ast->bundl_group.text_bundle.colr);
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_TEXT_FONT)) {
      font = ast->indiv_group.text_bundle.font;
   }
   else {
      font = ast->bundl_group.text_bundle.font;
   }

   if (font < 1) {
      *fnt = fnt_fonts[1];
   }
   else {
      *fnt = fnt_fonts[font - 1];
   }

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_CHAR_EXPAN)) {
      *char_expan = ast->indiv_group.text_bundle.char_expan;
   }
   else {
      *char_expan = ast->bundl_group.text_bundle.char_expan;
   }

   glDisable(GL_LIGHTING);
   glLineWidth(2.0);

}

/*******************************************************************************
 * wsgl_get_char_space
 *
 * DESCR:	Get char spacing
 * RETURNS:	Character spacing
 */

Pfloat wsgl_get_char_space(
   Ws_attr_st *ast
   )
{
   Pfloat char_space;

   if (phg_nset_name_is_set(&ast->asf_nameset, (Pint) PASPECT_CHAR_SPACE)) {
      char_space = ast->indiv_group.text_bundle.char_space;
   }
   else {
      char_space = ast->bundl_group.text_bundle.char_space;
   }

   return char_space;
}

/*******************************************************************************
 * wsgl_add_names_set
 *
 * DESCR:	Add names to nameset
 * RETURNS:	N/A
 */

void wsgl_add_names_set(
   Ws *ws,
   void *names
   )
{
   Pint num_ints;
   Pint *data = (Pint *) names;
   Wsgl_handle wsgl = ws->render_context;

   num_ints = *data;
   data++;

   phg_nset_names_set(&wsgl->cur_struct.cur_nameset,
                      num_ints,
                      data);
}

/*******************************************************************************
 * wsgl_remove_names_set
 *
 * DESCR:	Remove names from nameset
 * RETURNS:	N/A
 */

void wsgl_remove_names_set(
   Ws *ws,
   void *names
   )
{
   Pint num_ints;
   Pint *data = (Pint *) names;
   Wsgl_handle wsgl = ws->render_context;

   num_ints = *data;
   data++;

   phg_nset_names_clear(&wsgl->cur_struct.cur_nameset,
                        num_ints,
                        data);
}

