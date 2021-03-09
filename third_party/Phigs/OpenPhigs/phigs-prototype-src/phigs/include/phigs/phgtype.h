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

#ifndef _phgtype_h
#define _phgtype_h

#include <stdint.h>
#include <sys/types.h>

#ifndef TRUE
#define TRUE     1
#endif

#ifndef FALSE
#define FALSE    0
#endif

#define PHG_ZERO_TOLERANCE      1.0e-30
#define PHG_MAX_NAMELEN         255

typedef void (*Phg_conv_long)  (uint32_t *);
typedef void (*Phg_conv_short) (uint16_t *);
typedef void (*Phg_conv_float) (float *);

typedef struct {
   Phg_conv_long  conv_long;
   Phg_conv_short conv_short;
   Phg_conv_float conv_float;
} Phg_swap;

typedef struct {
   uint16_t elementType;
   uint16_t length;
} Phg_elmt_info;

typedef struct {
   Pint        num_paths;
   Ppoint_list *paths;
   Pfloat      center;
   Pfloat      right;
} Phg_char;

typedef struct {
   char     *name;
   Pint     num_chars;
   Phg_char *chars;
   Pfloat   top;
   Pfloat   bottom;
} Phg_font;

typedef struct {
   Pint   view_ind;
   Ppoint position;
} Ploc;

typedef struct {
   Pint    view_ind;
   Ppoint3 position;
} Ploc3;

typedef struct {
   Pin_status status;
   Ppick_path pick_path;
} Ppick;

typedef struct {
   Pint   view_ind;
   Pint   num_points;
   Ppoint *points;
} Pstroke;

typedef struct {
   Pint    view_ind;
   Pint    num_points;
   Ppoint3 *points;
} Pstroke3;

typedef struct {
   Pin_status status;
   Pint       choice;
} Pchoice;

typedef struct {
   Pint  length;
   char *string;
} Phg_string;

typedef union {
   Ploc3      loc;
   Ppick      pik;
   Pstroke3   stk;
   Pfloat     val;
   Pchoice    chc;
   Phg_string str;
} Phg_inp_event_data;

typedef struct {
   Pop_mode     mode;
   Pecho_switch esw;
   Ploc3        loc;
   Pint         pet;
   Plimit3      e_volume;
   Ploc_data3   record;
} Plocst3;

typedef struct {
   Pop_mode      mode;
   Pecho_switch  esw;
   Pint_list     inclusion_filter;
   Pint_list     exclusion_filter;
   Ppick         pick;
   Pint          pet;
   Plimit3       e_volume;
   Ppick_data3   record;
   Ppath_order   order;
} Ppickst3;

typedef struct {
   Pop_mode      mode;
   Pecho_switch  esw;
   Pstroke3      stroke;
   Pint          pet;
   Plimit3       e_volume;
   Pstroke_data3 record;
} Pstrokest3;

typedef struct {
   Pop_mode     mode;
   Pecho_switch esw;
   Pfloat       val;
   Pint         pet;
   Plimit3      e_volume;
   Pint         counts[4];
   Pval_data3   record;
} Pvalst3;

typedef struct {
   Pop_mode      mode;
   Pecho_switch  esw;
   Pchoice       choice;
   Pint          pet;
   Plimit3       e_volume;
   Pchoice_data3 record;
} Pchoicest3;

typedef struct {
   Pop_mode      mode;
   Pecho_switch  esw;
   char          *string;
   Pint          pet;
   Plimit3       e_volume;
   Pstring_data3 record;
} Pstringst3;

typedef struct {
   Pint      ws;
   Pin_class in_class;
   Pint      dev;
} Pevent;

struct _Sin_event_queue;
typedef struct _Sin_event_queue *Input_q_handle;

typedef struct {
   caddr_t  buf;
   unsigned size;
} Phg_scratch;

typedef struct _Css_structel *El_handle;
typedef struct _Css_ssl      *Struct_handle;
typedef struct _Css_struct   *Css_handle;
typedef struct _Ws           *Ws_handle;

#define PHG_MIN(a, b) \
   (((a) < (b)) ? (a) : (b))

#define PHG_MAX(a, b) \
   (((a) > (b)) ? (a) : (b))

#define PHG_ABS(a) \
   (((a) < 0.0) ? -(a) : (a))

#define PHG_NEAR_ZERO(s) \
   (PHG_ABS(s) < PHG_ZERO_TOLERANCE)

#define PHG_ZERO_MAG(s) \
   ((s) < PHG_ZERO_TOLERANCE)

#define PHG_MAG_V2(v)                  \
   (sqrt((v)->delta_x * (v)->delta_x + \
         (v)->delta_y * (v)->delta_y))

#define PHG_MAG_V3(v)                  \
   (sqrt((v)->delta_x * (v)->delta_x + \
         (v)->delta_y * (v)->delta_y + \
         (v)->delta_z * (v)->delta_z))

#define PHG_DOT_PROD(v1, v2) \
   ((v1)->x * (v2)->x + (v1)->y * (v2)->y + (v1)->z * (v2)->z)

#define PHG_UNIT_VEC(v)                                               \
   { double len;                                                      \
     len = sqrt((v)->x * (v)->x + (v)->y * (v)->y + (v)->z * (v)->z); \
     (v)->x /= len, (v)->y /= len, (v)->z /= len;                     \
   }

#define PHG_IN_RANGE(low, high, val) \
   ((val) >= (low) && (val) <= (high))

#define PHG_SCRATCH_SPACE(_sc, _size) \
    ((_sc)->size >= (_size) ? (_sc)->buf \
        : phg_grow_scratch( (_sc), (unsigned)(_size) ))

#endif

