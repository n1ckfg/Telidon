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

#ifndef _hdlP_h
#define _hdlP_h

#include <stdio.h>
#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/private/cssP.h>

/*******************************************************************************
 * hdl_create
 *
 * DESCR:       Create new element handle
 * RETURNS:     Pointer to element head or NULL
 */

Phg_elmt_info* hdl_create(
   void **data,
   caddr_t argdata
   );

/*******************************************************************************
 * hdl_resize
 *
 * DESCR:       Change size element handle
 * RETURNS:     Pointer to element head or NULL
 */

Phg_elmt_info* hdl_resize(
   void *buf,
   void **data,
   caddr_t argdata
   );

/*******************************************************************************
 * hdl_dup
 *
 * DESCR:       Duplicate element handle
 * RETURNS:     Pointer to element head or NULL
 */

Phg_elmt_info* hdl_dup(
   caddr_t argdata
   );

/*******************************************************************************
 * hdl_generic_elmt
 *
 * DESCR:       Handle generic element
 * RETURNS:     TRUE on success, otherwise FALSE
 */

int hdl_generic_elmt(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   );

#endif /* _hdlP_h */

