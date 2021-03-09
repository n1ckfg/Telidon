/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2011 - 2012 Surplus Users Ham Society
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

#ifndef _hdlP_h
#define _hdlP_h

#include <stdio.h>
#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/private/cssP.h>

/*******************************************************************************
 * phg_handle_int_list
 *
 * DESCR:       Handle list of integers
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_int_list(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_asf_info
 *
 * DESCR:       Handle asf info
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_asf_info(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_vec
 *
 * DESCR:       Handle vector
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_vec(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_local_tran
 *
 * DESCR:       Handle local transformation
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_local_tran(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_local_tran3
 *
 * DESCR:       Handle local transformation 3D
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_local_tran3(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_matrix
 *
 * DESCR:       Handle matrix
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_matrix(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_matrix3
 *
 * DESCR:       Handle matrix 3D
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_matrix3(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_point_list
 *
 * DESCR:       Handle point list
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_point_list(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_point_list3
 *
 * DESCR:       Handle point list 3D
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_point_list3(
   Css_handle cssh,        
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_point_list_list
 *
 * DESCR:       Handle list of point lists
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_point_list_list(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_point_list_list3
 *
 * DESCR:       Handle list of point lists 3D
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_point_list_list3(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_fasd3
 *
 * DESCR:       Handle facet list 3D
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_fasd3(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_text_align
 *
 * DESCR:       Handle text alignment
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_text_align(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_text
 *
 * DESCR:       Handle text
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_text(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_int
 *
 * DESCR:       Handle integer data
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_int(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_float
 *
 * DESCR:       Handle float data
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_float(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_gcolr
 *
 * DESCR:       Handle colour
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_gcolr(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_lss
 *
 * DESCR:       Handle light source state
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_lss(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

/*******************************************************************************
 * phg_handle_refl_props
 *
 * DESCR:       Handler surface reflectance properties
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int phg_handle_refl_props(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

#endif /* _hdlP_h */

