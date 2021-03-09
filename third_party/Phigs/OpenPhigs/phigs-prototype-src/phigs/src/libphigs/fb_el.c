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

#include <stdlib.h>
#include <string.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>
#include <phigs/util/ftn.h>

/*******************************************************************************
 * ppl
 *
 * DESCR:	Creates a new element - Polyline
 * RETURNS:	N/A
 */

FTN_SUBROUTINE(ppl)(
   FTN_INTEGER(n),
   FTN_REAL_ARRAY(pxa),
   FTN_REAL_ARRAY(pya)
   )
{
   Phg_args_add_el args;
   Pint *data;
   Pint i, num_points;
   Ppoint *points;

   if (phg_entry_check(ERR5, Pfn_polyline)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         num_points = FTN_INTEGER_GET(n);
         args.el_type = PELEM_POLYLINE;
         args.el_size = sizeof(Pint) + sizeof(Ppoint) * num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = num_points;
            points = (Ppoint *) &data[1];
            for (i = 0; i < num_points; i++) {
               points[i].x = FTN_REAL_ARRAY_GET(pxa, i);
               points[i].y = FTN_REAL_ARRAY_GET(pya, i);
            }
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pspcli
 *
 * DESCR:       Creates a new element - Line Color Attribute
 * RETURNS:     N/A
 */

FTN_SUBROUTINE(psplci)(
   FTN_INTEGER(coli)
   )
{
   Phg_args_add_el args;
   Pint colr_ind;

   if (phg_entry_check(ERR5, Pfn_set_line_colr_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (colr_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR113);
      }
      else {
         args.el_type = PELEM_LINE_COLR_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            colr_ind = FTN_INTEGER_GET(coli);
            memcpy(args.el_data, &colr_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * psln
 *
 * DESCR:       Creates a new element - Line Type Attribute
 * RETURNS:     N/A
 */

FTN_SUBROUTINE(psln)(
   FTN_INTEGER(ltype)
   )
{
   Phg_args_add_el args;
   Pint linetype;

   if (phg_entry_check(ERR5, Pfn_set_linetype)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LINETYPE;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            linetype = FTN_INTEGER_GET(ltype);
            memcpy(args.el_data, &linetype, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pslwsc
 *
 * DESCR:       Creates a new element - Line Width Attribute
 * RETURNS:     N/A
 */

FTN_SUBROUTINE(pslwsc)(
   FTN_REAL(lwidth)
   )
{
   Phg_args_add_el args;
   Pfloat linewidth;

   if (phg_entry_check(ERR5, Pfn_set_linewidth)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LINEWIDTH;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            linewidth = FTN_REAL_GET(lwidth);
            memcpy(args.el_data, &linewidth, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * ptx
 *
 * DESCR:       Creates a new element - Text
 * RETURNS:     N/A
 */

FTN_SUBROUTINE(ptx)(
   FTN_REAL(px),
   FTN_REAL(py),
   FTN_CHARACTER(chars)
   )
{
   Phg_args_add_el args;
   Pint len;
   Ppoint text_pos;
   Ppoint *data;
   char *char_string;

   if (phg_entry_check(ERR5, Pfn_text)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         len = FTN_CHARACTER_LEN(chars);
         args.el_type = PELEM_TEXT;
         args.el_size = sizeof(Ppoint) + len + 1;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Ppoint *) args.el_data;
            text_pos.x = FTN_REAL_GET(px);
            text_pos.y = FTN_REAL_GET(py);
            memcpy(data, &text_pos, sizeof(Ppoint));
            char_string = (char *) &data[1];
            strncpy(char_string, FTN_CHARACTER_GET(chars), len); 
            char_string[len] = '\0';
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pschh
 *
 * DESCR:       Creates a new element - Character height Attribute
 * RETURNS:     N/A
 */

FTN_SUBROUTINE(pschh)(
   FTN_REAL(chh)
   )
{
   Phg_args_add_el args;
   Pfloat char_ht;

   if (phg_entry_check(ERR5, Pfn_set_char_ht)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_CHAR_HT;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            char_ht = FTN_REAL_GET(chh);
            memcpy(args.el_data, &char_ht, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

