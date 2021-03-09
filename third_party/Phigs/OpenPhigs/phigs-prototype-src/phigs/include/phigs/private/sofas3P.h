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

#ifndef _sofas3P_h
#define _sofas3P_h

#include <phigs/phigs.h>

/*******************************************************************************
 * sofas3_head
 *
 * DESCR:       Get set of fill area set header information 3D
 * RETURNS:     N/A
 */

void sofas3_head(
   Psofas3 *sofas3,
   void *pdata
   );

/*******************************************************************************
 * sofas3_num_vlists
 *
 * DESCR:       Get set of fill area set number of vertex lists
 * RETURNS:     Total number of vertext lists
 */

int sofas3_num_vlists(
   Psofas3 *sofas3
   );

/*******************************************************************************
 * sofas3_get_vlist
 *
 * DESCR:       Get set of fill area set vertex list
 * RETURNS:     N/A
 */

void sofas3_get_vlist(
   Pint_list *vlist,
   Psofas3 *sofas3
   );

/*******************************************************************************
 * sofas3_next_vlist
 *
 * DESCR:       Get set of fill area set next vertex list
 * RETURNS:     N/A
 */

void sofas3_next_vlist(
   Pint_list *vlist,
   Psofas3 *sofas3
   );

/*******************************************************************************
 * sofas3_num_elists
 *
 * DESCR:       Get set of fill area set number of edge lists
 * RETURNS:     Total number of edge lists
 */

int sofas3_num_elists(
   Psofas3 *sofas3
   );

/*******************************************************************************
 * sofas3_next_elist
 *
 * DESCR:       Get set of fill area set next edge list
 * RETURNS:     N/A
 */

void sofas3_next_elist(
   Pedge_data_list *elist,
   Psofas3 *sofas3
   );

/*******************************************************************************
 * sofas3_normal3
 *
 * DESCR:       Get normal
 * RETURNS:     N/A
 */

void sofas3_normal3(
   Pvec3 *norm,
   Psofas3 *sofas3,
   Pint_list *vlist
   );

/*******************************************************************************
 * sofas3_print
 *
 * DESCR:       Print set of fill area set 3D
 * RETURNS:     N/A
 */

void sofas3_print(
   Psofas3 *sofas3
   );

/*******************************************************************************
 * sofas3_list
 *
 * DESCR:       List set of fill area set 3D
 * RETURNS:     N/A
 */

void sofas3_list(
   void *pdata
   );

#endif /* _sofas3P_h */

