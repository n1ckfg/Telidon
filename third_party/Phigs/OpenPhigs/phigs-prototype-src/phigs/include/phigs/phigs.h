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

#ifndef _phigs_h
#define _phigs_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

/* Max name length */
#define PHIGS_MAX_NAME_LEN      255

/* Line types */
#define PLINE_SOLID               1
#define PLINE_DASH                2
#define PLINE_DOT                 3
#define PLINE_DASH_DOT            4

/* Marker types */
#define PMARKER_DOT               1
#define PMARKER_PLUS              2
#define PMARKER_ASTERISK          3
#define PMARKER_CIRLCE            4
#define PMARKER_CROSS             5

/* Color model */
#define PINDIRECT                 0
#define PMODEL_RGB                1

/* HLHSR constants */
#define PHIGS_HLHSR_MODE_NONE     0
#define PHIGS_HLHSR_MODE_ZBUFF    1

#define PHIGS_HLHSR_ID_OFF        0
#define PHIGS_HLHSR_ID_ON         1

/* Facet data flags */
#define PFACET_NONE               0
#define PFACET_COLOUR             1
#define PFACET_NORMAL             2
#define PFACET_COLOUR_NORMAL      3

/* Edge data flags */
#define PEDGE_NONE                0
#define PEDGE_VISIBILITY          1

/* Vertex data flags */
#define PVERT_COORD               0
#define PVERT_COORD_COLOUR        1
#define PVERT_COORD_NORMAL        2
#define PVERT_COORD_COLOUR_NORMAL 3

/* Shading methods */
#define PSD_NONE                  1
#define PSD_COLOUR                2

/* Surface reflection */
#define PREFL_NONE                1
#define PREFL_AMBIENT             2
#define PREFL_AMB_DIFF            3
#define PREFL_AMB_DIFF_SPEC       4

/* Light source types */
#define PLIGHT_AMBIENT            1
#define PLIGHT_DIRECTIONAL        2
#define PLIGHT_POSITIONAL         3
#define PLIGHT_SPOT               4

/* PHIGS states */
typedef enum {
   PSYS_ST_PHCL,
   PSYS_ST_PHOP
} Psys_st;

typedef enum {
   PWS_ST_WSCL,
   PWS_ST_WSOP
} Pws_st;

typedef enum {
   PSTRUCT_ST_STCL,
   PSTRUCT_ST_STOP
} Pstruct_st;

/* Archive releated */
typedef enum {
   PST_ARCL,
   PST_AROP
} Par_st;

typedef enum {
   PNET_CSS,
   PNET_AR
} Pstruct_net_source;

/* Workstation related */
typedef enum {
   PCLASS_VEC,
   PCLASS_RASTER,
   PCLASS_OTHER
} Pws_class;

typedef enum {
   PCAT_OUT,
   PCAT_IN,
   PCAT_OUTIN,
   PCAT_MO,
   PCAT_MI
} Pws_cat;

typedef enum {
   PELEM_ALL,
   PELEM_NIL,
   PELEM_ADD_NAMES_SET,
   PELEM_REMOVE_NAMES_SET,
   PELEM_FILL_AREA,
   PELEM_FILL_AREA3,
   PELEM_FILL_AREA_SET,
   PELEM_FILL_AREA_SET3,
   PELEM_FILL_AREA_SET3_DATA,
   PELEM_SET_OF_FILL_AREA_SET3_DATA,
   PELEM_POLYLINE,
   PELEM_POLYLINE3,
   PELEM_POLYMARKER,
   PELEM_POLYMARKER3,
   PELEM_TEXT,
   PELEM_INT_IND,
   PELEM_INT_COLR_IND,
   PELEM_INT_STYLE,
   PELEM_BACK_INT_STYLE,
   PELEM_INT_STYLE_IND,
   PELEM_BACK_INT_STYLE_IND,
   PELEM_LINE_COLR_IND,
   PELEM_LINEWIDTH,
   PELEM_LINETYPE,
   PELEM_LINE_IND,
   PELEM_MARKER_IND,
   PELEM_MARKER_COLR_IND,
   PELEM_MARKER_SIZE,
   PELEM_MARKER_TYPE,
   PELEM_EDGE_IND,
   PELEM_EDGE_COLR_IND,
   PELEM_EDGEWIDTH,
   PELEM_EDGETYPE,
   PELEM_EDGE_FLAG,
   PELEM_TEXT_IND,
   PELEM_TEXT_FONT,
   PELEM_TEXT_PREC,
   PELEM_TEXT_PATH,
   PELEM_TEXT_ALIGN,
   PELEM_CHAR_HT,
   PELEM_CHAR_EXPAN,
   PELEM_CHAR_SPACE,
   PELEM_CHAR_UP_VEC,
   PELEM_TEXT_COLR_IND,
   PELEM_INDIV_ASF,
   PELEM_LOCAL_MODEL_TRAN3,
   PELEM_GLOBAL_MODEL_TRAN3,
   PELEM_VIEW_IND,
   PELEM_EXEC_STRUCT,
   PELEM_LABEL,
   PELEM_PICK_ID,
   PELEM_HLHSR_ID,
   PELEM_INT_COLR,
   PELEM_BACK_INT_COLR,
   PELEM_LINE_COLR,
   PELEM_MARKER_COLR,
   PELEM_EDGE_COLR,
   PELEM_TEXT_COLR,
   PELEM_LIGHT_SRC_STATE,
   PELEM_INT_SHAD_METH,
   PELEM_BACK_INT_SHAD_METH,
   PELEM_INT_REFL_EQN,
   PELEM_BACK_INT_REFL_EQN,
   PELEM_REFL_PROPS,
   PELEM_BACK_REFL_PROPS,
   PELEM_FACE_DISTING_MODE,
   PELEM_FACE_CULL_MODE,
   PELEM_NUM_EL_TYPES
} Pelem_type;

typedef enum {
   PDIR_BACKWARD,
   PDIR_FORWARD
} Psearch_dir;

typedef enum {
   PSEARCH_STATUS_FAILURE,
   PSEARCH_STATUS_SUCCESS
} Psearch_status;

typedef enum {
   PEDIT_INSERT,
   PEDIT_REPLACE
} Pedit_mode;

typedef enum {
   PFLAG_DEL,
   PFLAG_KEEP
} Pref_flag;

typedef enum {
   PERR_OFF,
   PERR_ON
} Perr_mode;

typedef enum {
   PSTRUCT_NONE,
   PSTRUCT_OPEN
} Popen_struct_status;

typedef enum {
   PSTRUCT_STATUS_NON_EXISTENT,
   PSTRUCT_STATUS_EMPTY,
   PSTRUCT_STATUS_NOT_EMPTY
} Pstruct_status;

typedef enum {
   PORDER_TOP_FIRST,
   PORDER_BOTTOM_FIRST
} Ppath_order;

typedef enum {
   PEDGE_OFF,
   PEDGE_ON
} Pedge_flag;

typedef enum {
   PSTYLE_EMPTY,
   PSTYLE_HOLLOW,
   PSTYLE_SOLID,
   PSTYLE_HATCH
} Pint_style;

typedef enum {
   PTYPE_PRECONCAT,
   PTYPE_POSTCONCAT,
   PTYPE_REPLACE
} Pcompose_type;

typedef enum {
   PDISTING_NO,
   PDISTING_YES
} Pdisting_mode;

typedef enum {
   PCULL_NONE,
   PCULL_BACKFACE,
   PCULL_FRONTFACE
} Pcull_mode;

typedef enum {
   PFLAG_COND,
   PFLAG_ALWAYS
} Pctrl_flag;

typedef enum {
   PFLAG_POSTPONE,
   PFLAG_PERFORM
} Pregen_flag;

typedef enum {
   PIND_NO_CLIP,
   PIND_CLIP
} Pclip_ind;

typedef enum {
   PPRI_HIGHER,
   PPRI_LOWER
} Prel_pri;

typedef enum {
   PRES_MAINTAIN,
   PRES_ABANDON,
   PRES_UPD
} Pconf_res;

typedef enum {
   PVISUAL_ST_CORRECT,
   PVISUAL_ST_DEFER,
   PVISUAL_ST_SIMULATED
} Pvisual_st;

typedef enum {
   PSURF_NOT_EMPTY,
   PSURF_EMPTY
} Pdisp_surf_empty;

typedef enum {
   PDEFER_ASAP,
   PDEFER_BNIG,
   PDEFER_BNIL,
   PDEFER_ASTI,
   PDEFER_WAIT
} Pdefer_mode;

typedef enum {
   PMODE_NIVE,
   PMODE_UWOR,
   PMODE_UQUM
} Pmod_mode;

typedef enum {
   PUPD_NOT_PEND,
   PUPD_PEND
} Pupd_st;

typedef enum {
   PINQ_SET,
   PINQ_REALIZED
} Pinq_type;

typedef enum {
   PTYPE_PARAL,
   PTYPE_PERSPECT
} Pproj_type;

typedef enum {
   PASF_BUNDLED,
   PASF_INDIV
} Pasf;

typedef enum {
   PASPECT_LINETYPE,
   PASPECT_LINEWIDTH,
   PASPECT_LINE_COLR_IND,
   PASPECT_MARKER_TYPE,
   PASPECT_MARKER_SIZE,
   PASPECT_MARKER_COLR_IND,
   PASPECT_TEXT_FONT,
   PASPECT_TEXT_PREC,
   PASPECT_CHAR_EXPAN,
   PASPECT_CHAR_SPACE,
   PASPECT_TEXT_COLR_IND,
   PASPECT_INT_STYLE,
   PASPECT_INT_STYLE_IND,
   PASPECT_INT_COLR_IND,
   PASPECT_EDGE_FLAG,
   PASPECT_EDGETYPE,
   PASPECT_EDGEWIDTH,
   PASPECT_EDGE_COLR_IND,
   PASPECT_INT_SHAD_METH,
   PASPECT_REFL_PROPS,
   PASPECT_INT_REFL_EQN,
   PASPECT_BACK_INT_STYLE,
   PASPECT_BACK_INT_STYLE_IND,
   PASPECT_BACK_INT_COLR,
   PASPECT_BACK_INT_SHAD_METH,
   PASPECT_BACK_REFL_PROPS,
   PASPECT_BACK_INT_REFL_EQN
} Paspect;

typedef enum {
   PFLAG_LINE,
   PFLAG_FILL,
   PFLAG_FILL_SET
} Pline_fill_ctrl_flag;

typedef enum {
   PREC_STRING,
   PREC_CHAR,
   PREC_STROKE
} Ptext_prec;

typedef enum {
   PPATH_RIGHT,
   PPATH_LEFT,
   PPATH_UP,
   PPATH_DOWN
} Ptext_path;

typedef enum {
   PHOR_NORM,
   PHOR_LEFT,
   PHOR_CTR,
   PHOR_RIGHT
} Phor_text_align;

typedef enum {
   PVERT_NORM,
   PVERT_TOP,
   PVERT_CAP,
   PVERT_HALF,
   PVERT_BASE,
   PVERT_BOTTOM
} Pvert_text_align;

typedef enum {
   PPR_OFF,
   PPR_ON
} Ppr_switch;

typedef enum {
   PDC_METRES,
   PDC_OTHER
} Pdc_units;

typedef enum {
   PIN_STATUS_NONE,
   PIN_STATUS_OK,
   PIN_STATUS_NO_IN
} Pin_status;

typedef enum {
   PIN_NONE,
   PIN_LOC,
   PIN_STROKE,
   PIN_VAL,
   PIN_CHOICE,
   PIN_PICK,
   PIN_STRING
} Pin_class;

typedef enum {
   POP_REQ,
   POP_SAMPLE,
   POP_EVENT
} Pop_mode;

typedef enum {
   PSWITCH_NO_ECHO,
   PSWITCH_ECHO
} Pecho_switch;

typedef void *Pstore;

typedef int Pint;
typedef long Plong;
typedef float Pfloat;

typedef Pfloat Pmatrix3[4][4];
typedef Pfloat Pmatrix[3][3];

typedef struct {
   Pint       num_elem_types;
   Pelem_type *elem_types;
} Pelem_type_list;

typedef struct {
   Pint struct_id;
   Pint elem_pos;
} Pelem_ref;

typedef struct {
   Pint      num_elem_refs;
   Pelem_ref *elem_refs;
} Pelem_ref_list;

typedef struct {
   Pint         type;
   union {
      Pint      ind;
      struct {
         Pfloat x;
         Pfloat y;
         Pfloat z;
      }         general;
   }            val;
} Pgcolr;

typedef struct {
   Pint num_ints;
   Pint *ints;
} Pint_list;

typedef struct {
   Pint      num_lists;
   Pint_list *lists;
} Pint_list_list;

typedef struct {
   Pfloat x;
   Pfloat y;
} Ppoint;

typedef struct {
   Pfloat x;
   Pfloat y;
   Pfloat z;
} Ppoint3;

typedef struct {
   Pfloat x;
   Pfloat y;
   Pfloat z;
   Pfloat w;
} Ppoint4;

typedef struct {
   Pfloat delta_x;
   Pfloat delta_y;
} Pvec;

typedef struct {
   Pfloat delta_x;
   Pfloat delta_y;
   Pfloat delta_z;
} Pvec3;

typedef struct {
   Ppoint p;
   Ppoint q;
} Prect;

typedef struct {
   Pfloat x_min, x_max;
   Pfloat y_min, y_max;
} Plimit;

typedef struct {
   Pfloat x_min, x_max;
   Pfloat y_min, y_max;
   Pfloat z_min, z_max;
} Plimit3;

typedef struct {
   Pint num_points;
   Ppoint *points;
} Ppoint_list;

typedef struct {
   Pint num_points;
   Ppoint3 *points;
} Ppoint_list3;

typedef struct {
   Pint        num_point_lists;
   Ppoint_list *point_lists;
} Ppoint_list_list;

typedef struct {
   Pint         num_point_lists;
   Ppoint_list3 *point_lists;
} Ppoint_list_list3;

typedef struct {
   Pint   type;
   Pfloat width;
   Pint   colr_ind;
} Pline_bundle;

typedef struct {
   Pint   type;
   Pfloat width;
   Pgcolr colr;
} Pline_bundle_plus;

typedef struct {
   Pint   type;
   Pfloat size;
   Pint   colr_ind;
} Pmarker_bundle;

typedef struct {
   Pint   type;
   Pfloat size;
   Pgcolr colr;
} Pmarker_bundle_plus;

typedef struct {
   Pedge_flag flag;
   Pint       type;
   Pfloat     width;
   Pint       colr_ind;
} Pedge_bundle;

typedef struct {
   Pedge_flag flag;
   Pint       type;
   Pfloat     width;
   Pgcolr     colr;
} Pedge_bundle_plus;

typedef struct {
   Pint_style style;
   Pint       style_ind;
   Pint       colr_ind;
} Pint_bundle;

typedef struct {
   Pfloat     ambient_coef;
   Pfloat     diffuse_coef;
   Pfloat     specular_coef;
   Pgcolr     specular_colr;
   Pfloat     specualr_exp;
} Prefl_props;

typedef struct {
   Pint_style  style;
   Pint        style_ind;
   Pgcolr      colr;
   Pint        refl_eqn;
   Pint        shad_meth;
   Prefl_props refl_props;
   Pint_style  back_style;
   Pint        back_style_ind;
   Pgcolr      back_colr;
   Pint        back_refl_eqn;
   Pint        back_shad_meth;
   Prefl_props back_refl_props;
} Pint_bundle_plus;

typedef struct {
   Pint       font;
   Ptext_prec prec;
   Pfloat     char_expan;
   Pfloat     char_space;
   Pint       colr_ind;
} Ptext_bundle;

typedef struct {
   Pint       font;
   Ptext_prec prec;
   Pfloat     char_expan;
   Pfloat     char_space;
   Pgcolr     colr;
} Ptext_bundle_plus;

typedef struct {
   Paspect id;
   Pasf    source;
} Pasf_info;

typedef struct {
   Phor_text_align  hor;
   Pvert_text_align vert;
} Ptext_align;

typedef struct {
   Ppoint pos;
   char   *char_string;
} Ptext;

typedef struct {
   Pcompose_type compose_type;
   Pmatrix       matrix;
} Plocal_tran;

typedef struct {
   Pcompose_type compose_type;
   Pmatrix3      matrix;
} Plocal_tran3;

typedef struct {
   Pmatrix3  ori_matrix;
   Pmatrix3  map_matrix;
   Plimit3   clip_limit;
   Pclip_ind xy_clip;
   Pclip_ind back_clip;
   Pclip_ind front_clip;
} Pview_rep3;

typedef struct {
   Pfloat red;
   Pfloat green;
   Pfloat blue;
} Prgb;

typedef struct {
   Pfloat hue;
   Pfloat satur;
   Pfloat value;
} Phsv;

typedef union {
   Prgb rgb;
   Phsv hsv;
} Pcolr_rep;

typedef union {
   Pint      ind;
   Pcolr_rep direct;
} Pcoval;

typedef struct {
   Pcoval colr;
   Pvec3  norm;
} Pconorm3;

typedef union {
   Pcoval   colr;
   Pvec3    norm;
   Pconorm3 conorm;
} Pfacet_data3;

typedef union {
   Pcoval   *colrs;
   Pvec3    *norms;
   Pconorm3 *conorms;
} Pfacet_data_arr3;

typedef union {
   Pedge_flag *edges;
} Pedge_data_arr;

typedef struct {
   Pint           num_edges;
   Pedge_data_arr edgedata;
} Pedge_data_list;

typedef struct {
   Pint            num_lists;
   Pedge_data_list *edgelist;
} Pedge_data_list_list;

typedef struct {
   Ppoint3 point;
   Pcoval  colr;
} Pptco3;

typedef struct {
   Ppoint3 point;
   Pvec3   norm;
} Pptnorm3;

typedef struct {
   Ppoint3 point;
   Pcoval  colr;
   Pvec3   norm;
} Pptconorm3;

typedef union {
   Ppoint3    *points;
   Pptco3     *ptcolrs;
   Pptnorm3   *ptnorms;
   Pptconorm3 *ptconorms;
} Pfacet_vdata_arr3;

typedef struct {
   Pint              num_vertices;
   Pfacet_vdata_arr3 vertex_data;
} Pfacet_vdata_list3;

typedef struct {
   Pgcolr colr;
} Pamb_light_src_rec;

typedef struct {
   Pgcolr colr;
   Pvec3  dir;
} Pdir_light_src_rec;

typedef struct {
   Pgcolr  colr;
   Ppoint3 pos;
   Pfloat  coef[2];
} Ppos_light_src_rec;

typedef struct {
   Pgcolr  colr;
   Ppoint3 pos;
   Pvec3   dir;
   Pfloat  exp;
   Pfloat  coef[2];
   Pfloat  angle;
} Pspot_light_src_rec;

typedef union {
   Pamb_light_src_rec  ambient;
   Pdir_light_src_rec  directional;
   Ppos_light_src_rec  positional;
   Pspot_light_src_rec spot;
} Plight_src_rec;

typedef struct {
   Pint           type;
   Plight_src_rec rec;
} Plight_src_bundle;

typedef struct {
   Pint size_x;
   Pint size_y;
} Pint_size;

typedef struct {
   Pint size_x;
   Pint size_y;
   Pint size_z;
} Pint_size3;

typedef struct {
   Pfloat size_x;
   Pfloat size_y;
} Pfloat_size;

typedef struct {
   Pfloat size_x;
   Pfloat size_y;
   Pfloat size_z;
} Pfloat_size3;

typedef struct {
   Pdc_units   dc_units;
   Pfloat_size size_dc;
   Pint_size   size_raster;
} Pdisp_space_size;

typedef struct {
   Pdc_units    dc_units;
   Pfloat_size3 size_dc;
   Pint_size3   size_raster;
} Pdisp_space_size3;

typedef struct {
   Pint   id;
   Pfloat disp_pri;
} Pposted_struct;

typedef struct {
   Pint           num_postings;
   Pposted_struct *postings;
} Pposted_struct_list;

typedef struct {
   Pint               fflag;
   Pint               eflag;
   Pint               vflag;
   Pint               colr_type;
   Pfacet_data3       fdata;
   Pint               nfa;
   Pedge_data_list    *edata;
   Pfacet_vdata_list3 *vdata;
} Pfasd3;

typedef struct {
   Pint                 fflag;
   Pint                 eflag;
   Pint                 vflag;
   Pint                 colr_type;
   Pint                 num_sets;
   Pfacet_data_arr3     fdata;
   Pedge_data_list_list *edata;
   Pint_list_list       *vlist;
   Pfacet_vdata_list3   vdata;
} Psofas3;

typedef struct {
   Pint_list activation;
   Pint_list deactivation;
} Plss;

typedef union {
   Pint              int_data;
   Pfloat            float_data;
   Ppoint_list       point_list;
   Ppoint_list3      point_list3;
   Ppoint_list_list  point_list_list;
   Ppoint_list_list3 point_list_list3;
   Pfasd3            fasd3;
   Psofas3           sofas3;
   Ptext_prec        text_prec;
   Ptext_path        text_path;
   Ptext_align       text_align;
   Ptext             text;
   Pasf_info         asf_info;
   Pvec              vec;
   Plocal_tran       local_tran;
   Plocal_tran3      local_tran3;
   Pmatrix           global_tran;
   Pmatrix3          global_tran3;
   Pint_list         int_list;
   Pedge_flag        edge_flag;
   Pint_style        int_style;
   Pgcolr            colr;
   Plss              lss;
   Prefl_props       props;
   Pdisting_mode     disting_mode;
   Pcull_mode        cull_mode;
} Pelem_data;

typedef struct {
   Plimit win;
   Plimit proj_vp;
} Pview_map;

typedef struct {
   Plimit3    win;
   Plimit3    proj_vp;
   Pproj_type proj_type;
   Ppoint3    proj_ref_point;
   Pfloat     view_plane;
   Pfloat     back_plane;
   Pfloat     front_plane;
} Pview_map3;

typedef struct {
   Pasf         type_asf;
   Pasf         width_asf;
   Pasf         colr_ind_asf;
   Pint         ind;
   Pline_bundle bundle;
} Pline_attrs;

typedef struct {
   Pasf           type_asf;
   Pasf           size_asf;
   Pasf           colr_ind_asf;
   Pint           ind;
   Pmarker_bundle bundle;
} Pmarker_attrs;

typedef struct {
   Pasf        style_asf;
   Pasf        style_ind_asf;
   Pasf        colr_ind_asf;
   Pint        ind;
   Pint_bundle bundle;
} Pint_attrs;

typedef struct {
   Pasf         flag_asf;
   Pasf         type_asf;
   Pasf         widthasf;
   Pasf         colr_ind_asf;
   Pint         ind;
   Pedge_bundle bundle;
} Pedge_attrs;

typedef struct {
   Pint_list incl_set;
   Pint_list excl_set;
} Pfilter;

typedef struct {
   Pint struct_id;
   Pint pick_id;
   Pint elem_pos;
} Ppick_path_elem;

typedef struct {
   Pint            depth;
   Ppick_path_elem *path_list;
} Ppick_path;

typedef struct {
   Pint loc;
   Pint stroke;
   Pint val;
   Pint choice;
   Pint pick;
   Pint string;
} Pnum_in;

typedef struct {
   union {

      struct {
         Pint unused;
      } pet_r1;

      struct {
         Pint unused;
      } pet_r2;

      struct {
         Pint unused;
      } pet_r3;

      struct {
         Pline_attrs line_attrs;
      } pet_r4;

      struct {
         Pline_fill_ctrl_flag line_fill_ctrl_flag;
         union {
            Pline_attrs line_attrs;
            Pint_attrs  int_attrs;
            struct {
               Pint_attrs  int_attrs;
               Pedge_attrs edge_attrs;
            } fill_set;
         } attrs;
      } pet_r5;

   } pets;
} Ploc_data;

typedef Ploc_data Ploc_data3;

typedef struct {
   union {
      struct {
         Pint unused;
      } pet_r1;
   } pets;
} Ppick_data;

typedef Ppick_data Ppick_data3;

typedef struct {
   Pint   buffer_size;
   Pint   init_pos;
   Pfloat x_interval;
   Pfloat y_interval;
   Pfloat time_interval;

   union {
      struct {
         Pint unused;
      } pet_r1;

      struct {
         Pint unused;
      } pet_r2;

      struct {
         Pmarker_attrs marker_attrs;
      } pet_r3;

      struct {
         Pline_attrs line_attrs;
      } pet_r4;
   } pets;

} Pstroke_data;

typedef struct {
   Pint   buffer_size;
   Pint   init_pos;
   Pfloat x_interval;
   Pfloat y_interval;
   Pfloat z_interval;
   Pfloat time_interval;

   union {
      struct {
         Pint unused;
      } pet_r1;

      struct {
         Pint unused;
      } pet_r2;

      struct {
         Pmarker_attrs marker_attrs;
      } pet_r3;

      struct {
         Pline_attrs line_attrs;
      } pet_r4;
   } pets;

} Pstroke_data3;

typedef struct {
   Pfloat low;
   Pfloat high;

   union {

      struct {
         Pint unused;
      } pet_r1;

      struct {
         char *label;
         char *format;
         char *low_label;
         char *high_label;
      } pet_u1;

   } pets;
} Pval_data;

typedef Pval_data Pval_data3;

typedef struct {

   union {
      struct {
         Pint unused;
      } pet_r1;

      struct {
         Pint       num_prompts;
         Ppr_switch *prompts;
      } pet_r2;

      struct {
         Pint       num_strings;
         char       **strings;
      } pet_r3;

      struct {
         Pint       num_strings;
         char       **strings;
      } pet_r4;

      struct {
         Pint       struct_id;
         Pint       num_pick_ids;
         Pint       *pick_ids;
      } pet_r5;
   } pets;

} Pchoice_data;

typedef Pchoice_data Pchoice_data3;

typedef struct {
   Pint buffer_size;
   Pint init_pos;

   union {
      struct {
         Pint unused;
      } pet_r1;
   } pets;
} Pstring_data;

typedef Pstring_data Pstring_data3;

/*******************************************************************************
 * popen_phigs
 *
 * DESCR:       Open phigs
 * RETURNS:     N/A
 */

void popen_phigs(
   char *error_file,
   size_t memory
   );

/*******************************************************************************
 * pclose_phigs
 *
 * DESCR:       Close phigs
 * RETURNS:     N/A
 */

void pclose_phigs(
   void
   );

/* See phgsargs.h for more info */
struct _Phg_args_conn_info;

/*******************************************************************************
 * popen_ws
 *
 * DESCR:       Open workstation
 * RETURNS:     N/A
 */

void popen_ws(
   Pint ws_id,
   struct _Phg_args_conn_info *conn_id,
   Pint ws_type
   );

/*******************************************************************************
 * pclose_ws
 *
 * DESCR:       Close workstation
 * RETURNS:     N/A
 */

void pclose_ws(
   Pint ws_id
   );

/*******************************************************************************
 * pset_ws_vp
 *
 * DESCR:       Set workstation viewport
 * RETURNS:     N/A
 */

void pset_ws_vp(
   Pint ws_id,
   Plimit *viewport
   );

/*******************************************************************************
 * pset_ws_vp3
 *
 * DESCR:       Set workstation viewport
 * RETURNS:     N/A
 */

void pset_ws_vp3(
   Pint ws_id,
   Plimit3 *viewport
   );

/*******************************************************************************
 * pset_ws_win
 *
 * DESCR:       Set workstation window
 * RETURNS:     N/A
 */

void pset_ws_win(
   Pint ws_id,
   Plimit *window
   );

/*******************************************************************************
 * pset_ws_win3
 *
 * DESCR:       Set workstation window
 * RETURNS:     N/A
 */

void pset_ws_win3(
   Pint ws_id,
   Plimit3 *window
   );

/*******************************************************************************
 * pset_invis_filter
 *
 * DESCR:       Set workstation invisibility filter
 * RETURNS:     N/A
 */

void pset_invis_filter(
   Pint ws_id,
   Pfilter *filter
   );

/*******************************************************************************
 * pset_hlhsr_mode
 *
 * DESCR:       Set workstation hlhsr mode
 * RETURNS:     N/A
 */

void pset_hlhsr_mode(
   Pint ws_id,
   Pint hlhsr_mode
   );

/*******************************************************************************
 * pset_line_rep
 *
 * DESCR:       Set workstation line represenation
 * RETURNS:     N/A
 */

void pset_line_rep(
   Pint ws_id,
   Pint line_ind,
   Pline_bundle *line_bundle
   );

/*******************************************************************************
 * pset_marker_rep
 *
 * DESCR:       Set workstation marker represenation
 * RETURNS:     N/A
 */

void pset_marker_rep(
   Pint ws_id,
   Pint marker_ind,
   Pmarker_bundle *marker_bundle
   );

/*******************************************************************************
 * pset_text_rep
 *
 * DESCR:       Set workstation text represenation
 * RETURNS:     N/A
 */

void pset_text_rep(
   Pint ws_id,
   Pint text_ind,
   Ptext_bundle *text_bundle
   );

/*******************************************************************************
 * pset_edge_rep
 *
 * DESCR:       Set workstation edge represenation
 * RETURNS:     N/A
 */

void pset_edge_rep(
   Pint ws_id,
   Pint edge_ind,
   Pedge_bundle *edge_bundle
   );

/*******************************************************************************
 * pset_int_rep
 *
 * DESCR:       Set workstation interior represenation
 * RETURNS:     N/A
 */

void pset_int_rep(
   Pint ws_id,
   Pint int_ind,
   Pint_bundle *int_bundle
   );

/*******************************************************************************
 * ppost_struct
 *
 * DESCR:       Post structure to workstation
 * RETURNS:     N/A
 */

void ppost_struct(
   Pint ws_id,
   Pint struct_id,
   Pfloat priority
   );

/*******************************************************************************
 * punpost_struct
 *
 * DESCR:       Remove posted structure from workstation
 * RETURNS:     N/A
 */

void punpost_struct(
   Pint ws_id,
   Pint struct_id
   );

/*******************************************************************************
 * punpost_all_structs
 *
 * DESCR:       Remove all posted structures from workstation
 * RETURNS:     N/A
 */

void punpost_all_structs(
   Pint ws_id
   );

/*******************************************************************************
 * predraw_all_structs
 *
 * DESCR:       Redraw all structures on workstation
 * RETURNS:     N/A
 */

void predraw_all_structs(
   Pint ws_id,
   Pctrl_flag ctrl_flag
   );

/*******************************************************************************
 * pupd_ws
 *
 * DESCR:       Set workstation update state
 * RETURNS:     N/A
 */

void pupd_ws(
   Pint ws_id,
   Pregen_flag regen_flag
   );

/*******************************************************************************
 * pset_disp_upd_st
 *
 * DESCR:       Set workstation update state
 * RETURNS:     N/A
 */

void pset_disp_upd_st(
   Pint ws_id,
   Pdefer_mode def_mode,
   Pmod_mode mod_mode
   );

/*******************************************************************************
 * pset_view_tran_in_pri
 *
 * DESCR:       Set view input priority
 * RETURNS:     N/A
 */

void pset_view_tran_in_pri(
   Pint ws_id,
   Pint view_ind,
   Pint ref_view_ind,
   Prel_pri rel_pri
   );

/*******************************************************************************
 * pset_light_src_rep
 *
 * DESCR:       Set light source for workstation
 * RETURNS:     N/A
 */

void pset_light_src_rep(
   Pint ws_id,
   Pint light_src_ind,
   Plight_src_bundle *light_src_rep
   );

/*******************************************************************************
 * pset_colr_rep
 *
 * DESCR:       Set workstation colour representation
 * RETURNS:     N/A
 */

void pset_colr_rep(
   Pint ws_id,
   Pint ind,
   Pcolr_rep *rep
   );

/*******************************************************************************
 * pinq_ws_st
 *
 * DESCR:       Get workstation state
 * RETURNS:     N/A
 */

void pinq_ws_st(
   Pws_st *ws_state
   );

/*******************************************************************************
 * pinq_ws_conn_type
 *
 * DESCR:       Get workstation connection type
 * RETURNS:     N/A
 */

void pinq_ws_conn_type(
   Pint ws_id,
   Pstore store,
   Pint *err_ind,
   void **conn_id,
   Pint *ws_type
   );

/*******************************************************************************
 * pinq_open_wss
 *
 * DESCR:       Get list of open workstations
 * RETURNS:     N/A
 */

void pinq_open_wss(
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *open_ws_ids,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_view_inds
 *
 * DESCR:       Get workstation list of view indices
 * RETURNS:     N/A
 */

void pinq_list_view_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *view_inds,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_line_inds
 *
 * DESCR:       Get workstation list of line indices
 * RETURNS:     N/A
 */

void pinq_list_line_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *def_line_ind,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_marker_inds
 *
 * DESCR:       Get workstation list of marker indices
 * RETURNS:     N/A
 */

void pinq_list_marker_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *def_marker_ind,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_text_inds
 *
 * DESCR:       Get workstation list of text indices
 * RETURNS:     N/A
 */

void pinq_list_text_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *def_text_ind,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_int_inds
 *
 * DESCR:       Get workstation list of interior indices
 * RETURNS:     N/A
 */

void pinq_list_int_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *def_int_ind,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_edge_inds
 *
 * DESCR:       Get workstation list of edge indices
 * RETURNS:     N/A
 */

void pinq_list_edge_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *def_edge_ind,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_list_colr_inds
 *
 * DESCR:       Get workstation list of colour indices
 * RETURNS:     N/A
 */

void pinq_list_colr_inds(
   Pint ws_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint *err_ind,
   Pint_list *colr_ind,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pinq_line_rep
 *
 * DESCR:       Get workstation line representation
 * RETURNS:     N/A
 */

void pinq_line_rep(
   Pint ws_id,
   Pint index,
   Pinq_type type,
   Pint *err_ind,
   Pline_bundle *line_rep
   );

/*******************************************************************************
 * pinq_marker_rep
 *
 * DESCR:       Get workstation marker representation
 * RETURNS:     N/A
 */

void pinq_marker_rep(
   Pint ws_id,
   Pint index,
   Pinq_type type,
   Pint *err_ind,
   Pmarker_bundle *marker_rep
   );

/*******************************************************************************
 * pinq_text_rep
 *
 * DESCR:       Get workstation text representation
 * RETURNS:     N/A
 */

void pinq_text_rep(
   Pint ws_id,
   Pint index,
   Pinq_type type,
   Pint *err_ind,
   Ptext_bundle *text_rep
   );

/*******************************************************************************
 * pinq_int_rep
 *
 * DESCR:       Get workstation interior representation
 * RETURNS:     N/A
 */

void pinq_int_rep(
   Pint ws_id,
   Pint index,
   Pinq_type type,
   Pint *err_ind,
   Pint_bundle *int_rep
   );

/*******************************************************************************
 * pinq_edge_rep
 *
 * DESCR:       Get workstation edge representation
 * RETURNS:     N/A
 */

void pinq_edge_rep(
   Pint ws_id,
   Pint index,
   Pinq_type type,
   Pint *err_ind,
   Pedge_bundle *edge_rep
   );

/*******************************************************************************
 * pinq_colr_rep
 *
 * DESCR:       Get workstation colour representation
 * RETURNS:     N/A
 */

void pinq_colr_rep(
   Pint ws_id,
   Pint colr_ind,
   Pinq_type type,
   Pint *err_ind,
   Pcolr_rep *colr_rep
   );

/*******************************************************************************
 * pinq_ws_cat
 *
 * DESCR:       Get workstation category
 * RETURNS:     N/A
 */

void pinq_ws_cat(
   Pint ws_type,
   Pint *err_ind,
   Pws_cat *cat
   );

/*******************************************************************************
 * pinq_disp_space_size3
 *
 * DESCR:       Get workstation type display size 3D
 * RETURNS:     N/A
 */

void pinq_disp_space_size3(
   Pint ws_type,
   Pint *err_ind,
   Pdisp_space_size3 *size
   );

/*******************************************************************************
 * popen_struct
 *
 * DESCR:       Opens a structure for appending or editing.
 * RETURNS:     N/A
 */

void popen_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pclose_struct
 *
 * DESCR:       Closes a previously opened structure.
 * RETURNS:     N/A
 */

void pclose_struct(
   void
   );

/*******************************************************************************
 * pset_edit_mode
 *
 * DESCR:       Set structure edit mode
 * RETURNS:     N/A
 */

void pset_edit_mode(
   Pedit_mode mode
   );

/*******************************************************************************
 * pset_elem_ptr
 *
 * DESCR:       Make the requested index the "currently active element".
 *              NOTE: 0 means set element to even before the very first
 *              element; 1 means set elptr to very first element.
 * RETURNS:     N/A
 */

void pset_elem_ptr(
   Pint elem_ptr_value
   );

/*******************************************************************************
 * poffset_elem_ptr
 *
 * DESCR:       Offsets the element pointer forward by the given number of
 *              elements.
 *              Internal call to pset_elem_ptr does the verification work
 *              on the index.
 * RETURNS:     N/A
 */

void poffset_elem_ptr(
   Pint elem_ptr_offset
   );

/*******************************************************************************
 * pset_elem_ptr_label
 *
 * DESCR:       Searches forward in the structure list for the specified
 *              label, and makes that the current element.  Search begins
 *              with the element after (to the right) of the current one.
 *              Question: should I include the current element in the search?
 *              Or does the search begin with the first element after the
 *              current one?
 *              This version gives fatal error if label not found.
 * RETURNS:     N/A
 */

void pset_elem_ptr_label(
   Pint label_id
   );

/*******************************************************************************
 * pdel_elem
 *
 * DESCR:       Deletes the current element.  The element pointer is left
 *              pointing to the element just before (to the left) the one to
 *              be killed, if any.
 * RETURNS:     N/A
 */

void pdel_elem(
   void
   );

/*******************************************************************************
 * pdel_elem_range
 *
 * DESCR:       Deletes all elements within and on the bounds of the given
 *              range.  The element pointer is left pointing to the element
 *              just prior to the first element deleted.
 * RETURNS:     N/A
 */

void pdel_elem_range(
   Pint elem_ptr1_value,
   Pint elem_ptr2_value
   );

/*******************************************************************************
 * pdel_elems_labels
 *
 * DESCR:       Deletes all elements in the structure that lie between the
 *              given labels, but not the labels themselves.  The element
 *              pointer is left pointing to the first label.
 * RETURNS:     N/A
 */

void pdel_elems_labels(
   Pint label1_id,
   Pint label2_id
   );

/*******************************************************************************
 * pempty_struct
 *
 * DESCR:       Clear structure
 * RETURNS:     N/A
 */

void pempty_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pcopy_all_elems_struct
 *
 * DESCR:       Copies the elements of another structure into the open
 *              structure after the current element, which is updated to
 *              point to the last element inserted.  A structure can be
 *              copied into itself.
 * RETURNS:     N/A
 */

void pcopy_all_elems_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pinq_elem_ptr
 *
 * DESCR:       Returns the index of the current element.
 * RETURNS:     N/A
 */

void pinq_elem_ptr(
   Pint *err_ind,
   Pint *elem_ptr_value
   );

/*******************************************************************************
 * pinq_open_struct
 *
 * DESCR:       Check if a structure is open for appending or editing.
 * RETURNS:     N/A
 */

void pinq_open_struct(
   Pint *err_ind,
   Popen_struct_status *status,
   Pint *struct_id
   );

/*******************************************************************************
 * padd_names_set
 *
 * DESCR:       Creates a new element - name set Inclusion
 * RETURNS:     N/A
 */

void padd_names_set(
   Pint_list *names
   );

/*******************************************************************************
 * premove_names_set
 *
 * DESCR:       Creates a new element - name set Remover
 * RETURNS:     N/A
 */

void premove_names_set(
   Pint_list *names
   );

/*******************************************************************************
 * pset_indiv_asf
 *
 * DESCR:       Creates a new element - Set attribute source flag
 * RETURNS:     N/A
 */

void pset_indiv_asf(
   Paspect asf_id,
   Pasf asf_source
   );

/*******************************************************************************
 * pset_local_tran3
 *
 * DESCR:       Creates a new element - Set local model space transformation 3D
 * RETURNS:     N/A
 */

void pset_local_tran3(
   Pmatrix3 local_tran,
   Pcompose_type compose_type
   );

/*******************************************************************************
 * pset_global_tran3
 *
 * DESCR:       Creates a new element - Set global model space transformation 3D
 * RETURNS:     N/A
 */

void pset_global_tran3(
   Pmatrix3 global_tran
   );

/*******************************************************************************
 * pset_view_ind
 *
 * DESCR:       Creates a new element - Set view index
 * RETURNS:     N/A
 */

void pset_view_ind(
   Pint view_ind
   );

/*******************************************************************************
 * ptext
 *
 * DESCR:       Creates a new element - Text
 * RETURNS:     N/A
 */

void ptext(
   Ppoint *text_pos,
   char *char_string
   );

/*******************************************************************************
 * ppolyline
 *
 * DESCR:       Creates a new element - Polyline
 * RETURNS:     N/A
 */

void ppolyline(
   Ppoint_list *point_list
   );

/*******************************************************************************
 * ppolyline3
 *
 * DESCR:       Creates a new element - Polyline 3D
 * RETURNS:     N/A
 */

void ppolyline3(
   Ppoint_list3 *point_list
   );

/*******************************************************************************
 * ppolymarker
 *
 * DESCR:       Creates a new element - Polymarker
 * RETURNS:     N/A
 */

void ppolymarker(
   Ppoint_list *point_list
   );

/*******************************************************************************
 * ppolymarker3
 *
 * DESCR:       Creates a new element - Polymarker 3D
 * RETURNS:     N/A
 */

void ppolymarker3(
   Ppoint_list3 *point_list
   );

/*******************************************************************************
 * pfill_area
 *
 * DESCR:       Creates a new element - Fill area
 * RETURNS:     N/A
 */

void pfill_area(
   Ppoint_list *point_list
   );

/*******************************************************************************
 * pfill_area3
 *
 * DESCR:       Creates a new element - Fill area 3D
 * RETURNS:     N/A
 */

void pfill_area3(
   Ppoint_list3 *point_list
   );

/*******************************************************************************
 * pfill_area_set
 *
 * DESCR:       Creates a new element - Fill area set
 * RETURNS:     N/A
 */

void pfill_area_set(
   Ppoint_list_list *point_list_list
   );

/*******************************************************************************
 * pfill_area_set3
 *
 * DESCR:       Creates a new element - Fill area set 3D
 * RETURNS:     N/A
 */

void pfill_area_set3(
   Ppoint_list_list3 *point_list_list
   );

/*******************************************************************************
 * pfill_area_set3_data
 *
 * DESCR:       Creates a new element - Fill area set with data 3D
 * RETURNS:     N/A
 */

void pfill_area_set3_data(
   Pint fflag,
   Pint eflag,
   Pint vflag,
   Pint colr_type,
   Pfacet_data3 *fdata,
   Pint nfa,
   Pedge_data_list *edata,
   Pfacet_vdata_list3 *vdata
   );

/*******************************************************************************
 * pset_of_fill_area_set3_data
 *
 * DESCR:       Creates a new element - Set of fill area set with data 3D
 * RETURNS:     N/A
 */

void pset_of_fill_area_set3_data(
   Pint fflag,
   Pint eflag,
   Pint vflag,
   Pint colr_type,
   Pint num_sets,
   Pfacet_data_arr3 *fdata,
   Pedge_data_list_list *edata,
   Pint_list_list *vlist,
   Pfacet_vdata_list3 *vdata
   );

/*******************************************************************************
 * plabel
 *
 * DESCR:       Creates a new element - Label
 * RETURNS:     N/A
 */

void plabel(
   Pint label_id
   );

/*******************************************************************************
 * pset_pick_id
 *
 * DESCR:       Creates a new element - Pick ID
 * RETURNS:     N/A
 */

void pset_pick_id(
   Pint pick_id
   );

/*******************************************************************************
 * pset_hlhsr_id
 *
 * DESCR:       Create hidden lines, surface removal flag element
 * RETURNS:     N/A
 */

void pset_hlhsr_id(
   Pint hlhsr_id
   );

/*******************************************************************************
 * pset_int_ind
 *
 * DESCR:       Creates a new element - Facet Interiour Attribute Index
 * RETURNS:     N/A
 */

void pset_int_ind(
   Pint int_ind
   );

/*******************************************************************************
 * pset_int_colr_ind
 *
 * DESCR:       Creates a new element - Facet Color Attribute
 * RETURNS:     N/A
 */

void pset_int_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_int_style
 *
 * DESCR:       Creates a new element - Face Interiour Style
 * RETURNS:     N/A
 */

void pset_int_style(
   Pint_style int_style
   );

/*******************************************************************************
 * pset_int_style_ind
 *
 * DESCR:       Creates a new element - Face Interiour Pattern Index
 * RETURNS:     N/A
 */

void pset_int_style_ind(
   Pint int_style_ind
   );

/*******************************************************************************
 * pset_back_int_style
 *
 * DESCR:       Creates a new element - Backface Interiour Style
 * RETURNS:     N/A
 */

void pset_back_int_style(
   Pint_style int_style
   );

/*******************************************************************************
 * pset_back_int_style_ind
 *
 * DESCR:       Creates a new element - Backface Interiour Pattern Index
 * RETURNS:     N/A
 */

void pset_back_int_style_ind(
   Pint int_style_ind
   );

/*******************************************************************************
 * pset_line_ind
 *
 * DESCR:       Creates a new element - Line Attribute Index
 * RETURNS:     N/A
 */

void pset_line_ind(
   Pint line_ind
   );

/*******************************************************************************
 * pset_line_colr_ind
 *
 * DESCR:       Creates a new element - Line Color Attribute
 * RETURNS:     N/A
 */

void pset_line_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_linewidth
 *
 * DESCR:       Creates a new element - Line Width Attribute
 * RETURNS:     N/A
 */

void pset_linewidth(
   Pfloat linewidth
   );

/*******************************************************************************
 * pset_linetype
 *
 * DESCR:       Creates a new element - Line Type Attribute
 * RETURNS:     N/A
 */

void pset_linetype(
   Pint linetype
   );

/*******************************************************************************
 * pset_marker_ind
 *
 * DESCR:       Creates a new element - Marker Attribute Index
 * RETURNS:     N/A
 */

void pset_marker_ind(
   Pint marker_ind
   );

/*******************************************************************************
 * pset_marker_colr_ind
 *
 * DESCR:       Creates a new element - Marker Color Attribute
 * RETURNS:     N/A
 */

void pset_marker_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_marker_size
 *
 * DESCR:       Creates a new element - Marker Size Attribute
 * RETURNS:     N/A
 */

void pset_marker_size(
   Pfloat marker_size
   );

/*******************************************************************************
 * pset_marker_type
 *
 * DESCR:       Creates a new element - Marker Type Attribute
 * RETURNS:     N/A
 */

void pset_marker_type(
   Pint marker_type
   );

/*******************************************************************************
 * pset_edge_ind
 *
 * DESCR:       Creates a new element - Edge Attribute Index
 * RETURNS:     N/A
 */

void pset_edge_ind(
   Pint edge_ind
   );

/*******************************************************************************
 * pset_edge_colr_ind
 *
 * DESCR:       Creates a new element - Edge Color Attribute
 * RETURNS:     N/A
 */

void pset_edge_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_edgetype
 *
 * DESCR:       Creates a new element - Edge Type Attribute
 * RETURNS:     N/A
 */

void pset_edgetype(
   Pint edgetype
   );

/*******************************************************************************
 * pset_edge_flag
 *
 * DESCR:       Creates a new element - Edge Flag Attribute
 * RETURNS:     N/A
 */

void pset_edge_flag(
   Pedge_flag edge_flag
   );

/*******************************************************************************
 * pset_edgewidth
 *
 * DESCR:       Creates a new element - Edge Width Attribute
 * RETURNS:     N/A
 */

void pset_edgewidth(
   Pfloat edgewidth
   );

/*******************************************************************************
 * pset_text_font
 *
 * DESCR:       Creates a new element - Text Font Attribute
 * RETURNS:     N/A
 */

void pset_text_font(
   Pint font
   );

/*******************************************************************************
 * pset_text_prec
 *
 * DESCR:       Creates a new element - Text Precision Attribute
 * RETURNS:     N/A
 */

void pset_text_prec(
   Ptext_prec prec
   );

/*******************************************************************************
 * pset_text_path
 *
 * DESCR:       Creates a new element - Text Path Attribute
 * RETURNS:     N/A
 */

void pset_text_path(
   Ptext_path text_path
   );

/*******************************************************************************
 * pset_text_align
 *
 * DESCR:       Creates a new element - Text Alignment Attribute
 * RETURNS:     N/A
 */

void pset_text_align(
   Ptext_align *text_align
   );

/*******************************************************************************
 * pset_char_ht
 *
 * DESCR:       Creates a new element - Character height Attribute
 * RETURNS:     N/A
 */

void pset_char_ht(
   Pfloat char_ht
   );

/*******************************************************************************
 * pset_char_expan
 *
 * DESCR:       Creates a new element - Character expansion factor Attribute
 * RETURNS:     N/A
 */

void pset_char_expan(
   Pfloat char_expan
   );

/*******************************************************************************
 * pset_char_space
 *
 * DESCR:       Creates a new element - Character spaceing Attribute
 * RETURNS:     N/A
 */

void pset_char_space(
   Pfloat char_space
   );

/*******************************************************************************
 * pset_char_up_vec
 *
 * DESCR:       Creates a new element - Character up vector Attribute
 * RETURNS:     N/A
 */

void pset_char_up_vec(
   Pvec *char_up_vec
   );

/*******************************************************************************
 * pset_text_ind
 *
 * DESCR:       Creates a new element - Text Attribute Index
 * RETURNS:     N/A
 */

void pset_text_ind(
   Pint text_ind
   );

/*******************************************************************************
 * pset_text_colr_ind
 *
 * DESCR:       Creates a new element - Text Color Attribute
 * RETURNS:     N/A
 */

void pset_text_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pexec_struct
 *
 * DESCR:       Creates a new element - Nested Structure
 * RETURNS:     N/A
 */

void pexec_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pset_int_colr
 *
 * DESCR:       Creates a new element - Facet Color Attribute
 * RETURNS:     N/A
 */

void pset_int_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_back_int_colr
 *
 * DESCR:       Creates a new element - Backface Color Attribute
 * RETURNS:     N/A
 */

void pset_back_int_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_line_colr
 *
 * DESCR:       Creates a new element - Line Color Attribute
 * RETURNS:     N/A
 */

void pset_line_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_marker_colr
 *
 * DESCR:       Creates a new element - Marker Color Attribute
 * RETURNS:     N/A
 */

void pset_marker_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_edge_colr
 *
 * DESCR:       Creates a new element - Edge Color Attribute
 * RETURNS:     N/A
 */

void pset_edge_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_text_colr
 *
 * DESCR:       Creates a new element - Text Color Attribute
 * RETURNS:     N/A
 */

void pset_text_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_light_src_state
 *
 * DESCR:       Creates a new element - Set light source state
 * RETURNS:     N/A
 */

void pset_light_src_state(
   Pint_list *activation,
   Pint_list *deactivation
   );

/*******************************************************************************
 * pset_int_shad_meth
 *
 * DESCR:       Creates a new element - Set interiour shading method
 * RETURNS:     N/A
 */

void pset_int_shad_meth(
   Pint shad_meth
   );

/*******************************************************************************
 * pset_back_int_shad_meth
 *
 * DESCR:       Creates a new element - Set backface interiour shading method
 * RETURNS:     N/A
 */

void pset_back_int_shad_meth(
   Pint shad_meth
   );

/*******************************************************************************
 * pset_refl_eqn
 *
 * DESCR:       Creates a new element - Set surface reflectance equation
 * RETURNS:     N/A
 */

void pset_refl_eqn(
   Pint refl_equ
   );

/*******************************************************************************
 * pset_back_refl_eqn
 *
 * DESCR:       Creates a new element - Set backsurface reflectance equation
 * RETURNS:     N/A
 */

void pset_back_refl_eqn(
   Pint refl_equ
   );

/*******************************************************************************
 * pset_refl_props
 *
 * DESCR:       Creates a new element - Set surface reflectance properties
 * RETURNS:     N/A
 */

void pset_refl_props(
   Prefl_props *refl_props
   );

/*******************************************************************************
 * pset_back_refl_props
 *
 * DESCR:       Creates a new element - Set backsurface reflectance properties
 * RETURNS:     N/A
 */

void pset_back_refl_props(
   Prefl_props *refl_props
   );

/*******************************************************************************
 * pset_face_disting_mode
 *
 * DESCR:       Creates a new element - Set facet distinguish mode
 * RETURNS:     N/A
 */

void pset_face_disting_mode(
   Pdisting_mode disting_mode
   );

/*******************************************************************************
 * pset_face_cull_mode
 *
 * DESCR:       Creates a new element - Set face culling mode
 * RETURNS:     N/A
 */

void pset_face_cull_mode(
   Pcull_mode cull_mode
   );

/*******************************************************************************
 * ptranslate3
 *
 * DESCR:       Generate 3D translation matrix
 * RETURNS:     N/A
 */

void ptranslate3(
    Pvec3 *trans_vector,       /* translation vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * ptranslate
 *
 * DESCR:       Generate translation matrix
 * RETURNS:     N/A
 */

void ptranslate(
    Pvec *trans_vector,        /* translation vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    );

/*******************************************************************************
 * pscale3
 *  
 * DESCR:       Generate 3D scaling matrix
 * RETURNS:     N/A
 */
    
void pscale3(
    Pvec3 *scale_vector,       /* scale factor vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * pscale
 *
 * DESCR:       Generate scaling matrix
 * RETURNS:     N/A
 */

void pscale(
    Pvec *scale_vector,        /* scale factor vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate_x 
 *
 * DESCR:       Generate matrix for rotation around x-axis
 * RETURNS:     N/A
 */

void protate_x(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate_y
 *
 * DESCR:       Generate matrix for rotation around y-axis
 * RETURNS:     N/A
 */

void protate_y(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate_z
 *
 * DESCR:       Generate matrix for rotation around z-axis
 * RETURNS:     N/A
 */

void protate_z(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate
 *  
 * DESCR:       Generate rotation matrix
 * RETURNS:     N/A
 */

void protate(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    );

/*******************************************************************************
 * pcompose_matrix3
 *
 * DESCR:       Generate combined 3D transformation matrix
 * RETURNS:     N/A
 */

void pcompose_matrix3(
    Pmatrix3 a,                /* matrix a */
    Pmatrix3 b,                /* matrix b */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT result matrix */
    );

/*******************************************************************************
 * pcompose_matrix
 *
 * DESCR:       Generate combined transformation matrix
 * RETURNS:     N/A
 */

void pcompose_matrix(
    Pmatrix a,                 /* matrix a */
    Pmatrix b,                 /* matrix b */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT result matrix */
    );

/*******************************************************************************
 * ptran_point3
 *
 * DESCR:       Translate 3D point using transformation matrix
 * RETURNS:     N/A
 */

void ptran_point3(
    Ppoint3 *p,                /* point */
    Pmatrix3 m,                /* transformation matrix */
    Pint *error_ind,           /* OUT error indicator */
    Ppoint3 *r                 /* OUT transformed point */
    );

/*******************************************************************************
 * ptran_point
 *
 * DESCR:       Translate point using transformation matrix
 * RETURNS:     N/A
 */

void ptran_point(
    Ppoint *p,                 /* point */
    Pmatrix m,                 /* transformation matrix */
    Pint *error_ind,           /* OUT error indicator */
    Ppoint *r                  /* OUT transformed point */
    );

/*******************************************************************************
 * pbuild_tran_matrix3
 *
 * DESCR:       Generate 3D transformation matrix
 * RETURNS:     N/A
 */

void pbuild_tran_matrix3(
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat x_angle,            /* rotation angle X */
    Pfloat y_angle,            /* rotation angle Y */
    Pfloat z_angle,            /* rotation angle Z */
    Pvec3 *scale,              /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 matrix            /* OUT transformation matrix */
    );

/*******************************************************************************
 * void build_tran_matrix
 *
 * DESCR:       Generate transformation matrix
 * RETURNS:     N/A
 */

void pbuild_tran_matrix(
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat angle,              /* rotation angle */
    Pvec *scale,               /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix matrix             /* OUT transformation matrix */
    );

/*******************************************************************************
 * pcompose_tran_matrix3
 *
 * DESCR:       Combine 3D transformation with other transformation matrix
 * RETURNS:     N/A
 */

void pcompose_tran_matrix3(
    Pmatrix3 m,                /* transformation matrix */
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat x_ang,              /* rotation angle X */
    Pfloat y_ang,              /* rotation angle Y */
    Pfloat z_ang,              /* rotation angle Z */
    Pvec3 *scale,              /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 result            /* OUT transformation matrix */
    );

/*******************************************************************************
 * pcompose_tran_matrix
 *  
 * DESCR:       Combine transformation with other transformation matrix
 * RETURNS:     N/A            
 */ 

void pcompose_tran_matrix(
    Pmatrix m,                 /* transformation matrix */
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat angle,              /* rotation angle */
    Pvec *scale,               /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix result             /* OUT transformation matrix */
    );

/*******************************************************************************
 * peval_view_ori_matrix3
 *
 * DESCR:       Generate 3D view orientation matrix
 * RETURNS:     N/A
 */

void peval_view_ori_matrix3(
    Ppoint3 *vrp,              /* view reference point */
    Pvec3 *vpn,                /* view plane normal */
    Pvec3 *vup,                /* view up vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT view orientation matrix */
    );

/*******************************************************************************
 * peval_view_ori_matrix
 *
 * DESCR:       Generate view orientation matrix
 * RETURNS:     N/A
 */

void peval_view_ori_matrix(
    Ppoint *vrp,               /* view reference point */
    Pvec *vup,                 /* view up vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT view orientation matrix */
    );

/*******************************************************************************
 * peval_view_map_matrix3
 *
 * DESCR:       Generate 3D view mapping matrix
 * RETURNS:     N/A
 */

void peval_view_map_matrix3(
    Pview_map3 *map,           /* view mapping */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT view mapping matrix */
    );

/*******************************************************************************
 * peval_view_map_matrix
 *
 * DESCR:       Generate view mapping matrix
 * RETURNS:     N/A
 */

void peval_view_map_matrix(
    Pview_map *map,            /* view mapping */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT view mapping matrix */
    );

/*******************************************************************************
 * pinit_loc3
 *
 * DESCR:       Initialize locator device 3D
 * RETURNS:     N/A
 */

void pinit_loc3(
   Pint ws_id,
   Pint loc_num,
   Pint init_view_ind,
   Ppoint3 *init_loc_pos,
   Pint pet,
   Plimit3 *echo_vol,
   Ploc_data3 *loc_data
   );

/*******************************************************************************
 * pinit_stroke3
 *
 * DESCR:       Initialize stroke device 3D
 * RETURNS:     N/A
 */

void pinit_stroke3(
   Pint ws_id,
   Pint stroke_num,
   Pint init_view_ind,
   Ppoint_list3 *init_stroke,
   Pint pet,
   Plimit3 *echo_vol,
   Pstroke_data3 *stroke_data
   );

/*******************************************************************************
 * pinit_pick3
 *
 * DESCR:       Initialize pick device 3D
 * RETURNS:     N/A
 */

void pinit_pick3(
   Pint ws_id,
   Pint pick_num,
   Pin_status init_status,
   Ppick_path *init_pick,
   Pint pet,
   Plimit3 *echo_vol,
   Ppick_data3 *pick_data,
   Ppath_order order
   );

/*******************************************************************************
 * pset_pick_filter
 *
 * DESCR:       Set pick device filter
 * RETURNS:     N/A
 */

void pset_pick_filter(
   Pint ws_id,
   Pint pick_num,
   Pfilter *filter
   );

/*******************************************************************************
 * pset_loc_mode
 *
 * DESCR:       Set locator input device mode
 * RETURNS:     N/A
 */

void pset_loc_mode(
   Pint ws_id,
   Pint loc_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   );

/*******************************************************************************
 * pset_stroke_mode
 *
 * DESCR:       Set stroke input device mode
 * RETURNS:     N/A
 */

void pset_stroke_mode(
   Pint ws_id,
   Pint stroke_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   );

/*******************************************************************************
 * pset_pick_mode
 *
 * DESCR:       Set pick input device mode
 * RETURNS:     N/A
 */

void pset_pick_mode(
   Pint ws_id,
   Pint pick_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   );

/*******************************************************************************
 * psample_loc
 *
 * DESCR:       Sample locator device
 * RETURNS:     N/A
 */

void psample_loc(
   Pint ws_id,
   Pint loc_num,
   Pint *view_ind,
   Ppoint *loc_pos
   );

/*******************************************************************************
 * psample_loc3
 *
 * DESCR:       Sample locator device 3D
 * RETURNS:     N/A
 */

void psample_loc3(
   Pint ws_id,
   Pint loc_num,
   Pint *view_ind,
   Ppoint3 *loc_pos
   );

/*******************************************************************************
 * psample_stroke
 *
 * DESCR:       Sample stroke device
 * RETURNS:     N/A
 */

void psample_stroke(
   Pint ws_id,
   Pint stroke_num,
   Pint *view_ind,
   Ppoint_list *stroke
   );

/*******************************************************************************
 * psample_stroke3
 *
 * DESCR:       Sample stroke device 3D
 * RETURNS:     N/A
 */

void psample_stroke3(
   Pint ws_id,
   Pint stroke_num,
   Pint *view_ind,
   Ppoint_list3 *stroke
   );

/*******************************************************************************
 * psample_pick
 *
 * DESCR:       Sample pick device
 * RETURNS:     N/A
 */

void psample_pick(
   Pint ws_id,
   Pint pick_num,
   Pint depth,
   Pin_status *pick_in_status,
   Ppick_path *pick
   );

/*******************************************************************************
 * pawait_event
 *
 * DESCR:       Wait for event to occur
 * RETURNS:     N/A
 */

void pawait_event(
   Pfloat timeout,
   Pint *ws_id,
   Pin_class *dev_class,
   Pint *in_num
   );

/*******************************************************************************
 * pget_loc
 *
 * DESCR:       Get locator event from event queue
 * RETURNS:     N/A
 */

void pget_loc(
   Pint *view_ind,
   Ppoint *loc_pos
   );

/*******************************************************************************
 * pget_loc3
 *
 * DESCR:       Get locator event from event queue 3D
 * RETURNS:     N/A
 */

void pget_loc3(
   Pint *view_ind,
   Ppoint3 *loc_pos
   );

/*******************************************************************************
 * pget_stroke
 *
 * DESCR:       Get stroke event from event queue
 * RETURNS:     N/A
 */

void pget_stroke(
   Pint *view_ind,
   Ppoint_list *stroke
   );

/*******************************************************************************
 * pget_stroke3
 *
 * DESCR:       Get stroke event from event queue 3D
 * RETURNS:     N/A
 */

void pget_stroke3(
   Pint *view_ind,
   Ppoint_list3 *stroke
   );

/*******************************************************************************
 * pget_pick
 *
 * DESCR:       Get pick event from event queue
 * RETURNS:     N/A
 */

void pget_pick(
   Pint depth,
   Pin_status *in_status,
   Ppick_path *pick
   );

/*******************************************************************************
 * preq_loc3
 *
 * DESCR:       Request input from locator device 3D
 * RETURNS:     N/A
 */

void preq_loc3(
   Pint ws_id,
   Pint loc_num,
   Pin_status *in_status,
   Pint *view_ind,
   Ppoint3 *loc_pos
   );

/*******************************************************************************
 * preq_stroke3
 *
 * DESCR:       Request input from stroke device 3D
 * RETURNS:     N/A
 */

void preq_stroke3(
   Pint ws_id,
   Pint stroke_num,
   Pin_status *in_status,
   Pint *view_ind,
   Ppoint_list3 *stroke
   );

/*******************************************************************************
 * popen_ar_file
 *
 * DESCR:       Open archive file
 * RETURNS:     N/A
 */

void popen_ar_file(
   Pint archive_id,
   char *archive_file
   );

/*******************************************************************************
 * pclose_ar_file
 * 
 * DESCR:       Close archive file
 * RETURNS:     N/A
 */

void pclose_ar_file(
   Pint archive_id
   );

/*******************************************************************************
 * pset_conf_res
 *
 * DESCR:       Set structure conflict resolution for archive
 * RETURNS:     N/A
 */

void pset_conf_res(
   Pconf_res archive_res,
   Pconf_res retrieval_res
   );

/*******************************************************************************
 * par_structs
 *
 * DESCR:       Store structures in archive
 * RETURNS:     N/A
 */

void par_structs(
   Pint archive_id,
   Pint_list *struct_ids
   );

/*******************************************************************************
 * par_struct_nets
 *
 * DESCR:       Store structure networks in archive
 * RETURNS:     N/A
 */

void par_struct_nets(
   Pint archive_id,
   Pint_list *struct_ids
   );

/*******************************************************************************
 * par_all_structs
 *
 * DESCR:       Store all structures in archive
 * RETURNS:     N/A
 */

void par_all_structs(
   Pint archive_id
   );

/*******************************************************************************
 * pret_struct_ids
 *
 * DESCR:       Retreive all structures identifiers for archive
 * RETURNS:     N/A
 */

void pret_struct_ids(
   Pint archive_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint_list *ids,
   Pint *num_elems_impl_list
   );

/*******************************************************************************
 * pret_structs
 *
 * DESCR:       Retreive structures from archive
 * RETURNS:     N/A
 */

void pret_structs(
   Pint archive_id,
   Pint_list *struct_ids
   );

/*******************************************************************************
 * pret_struct_nets
 *
 * DESCR:       Retreive structure networks from archive
 * RETURNS:     N/A
 */

void pret_struct_nets(
   Pint archive_id,
   Pint_list *struct_ids
   );

/*******************************************************************************
 * pret_all_structs
 *
 * DESCR:       Retreive all structures from archive
 * RETURNS:     N/A
 */

void pret_all_structs(
   Pint archive_id
   );

/*******************************************************************************
 * pdel_structs_ar
 *
 * DESCR:       Delete structures from archive
 * RETURNS:     N/A
 */

void pdel_structs_ar(
   Pint archive_id,
   Pint_list *struct_ids
   );

/*******************************************************************************
 * pdel_struct_nets_ar
 *
 * DESCR:       Delete structure networks from archive
 * RETURNS:     N/A
 */

void pdel_struct_nets_ar(
   Pint archive_id,
   Pint_list *struct_ids
   );

/*******************************************************************************
 * pdel_all_structs_ar
 *
 * DESCR:       Delete all structures from archive
 * RETURNS:     N/A
 */

void pdel_all_structs_ar(
   Pint archive_id
   );

/*******************************************************************************
 * pinq_ar_st
 *
 * DESCR:       Get archive state
 * RETURNS:     N/A
 */

void pinq_ar_st(
   Par_st *ar_st
   );

/*******************************************************************************
 * pinq_conf_res
 *
 * DESCR:       Get archive conflict resolution
 * RETURNS:     N/A
 */

void pinq_conf_res(
   Pint *err_ind,
   Pconf_res *archive_res,
   Pconf_res *retrieval_res
   );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _phigs_h */

