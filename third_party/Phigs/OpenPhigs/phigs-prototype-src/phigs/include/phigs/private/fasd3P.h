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

#ifndef _fasd3P_h
#define _fasd3P_h

#include <phigs/phigs.h>

/*******************************************************************************
 * fasd3_head
 *
 * DESCR:       Get facet head information
 * RETURNS:     N/A
 */

void fasd3_head(
   Pfasd3 *fasd3,
   void *pdata
   );

/*******************************************************************************
 * fasd3_next_edata
 *
 * DESCR:       Get facet edge data
 * NOTE:        Remember to set up Pfasd3->edata to point to a valid
 *              Pedge_data_list structure
 * RETURNS:     N/A
 */

void fasd3_next_edata(
   Pfasd3 *fasd3
   );

/*******************************************************************************
 * fasd3_next_vdata3
 *
 * DESCR:       Get facet vertex data
 * NOTE:        Remember to set up Pfasd3->vdata to point to a valid
 *              Pfacet_vdata_list3 structure
 * RETURNS:     N/A
 */

void fasd3_next_vdata3(
   Pfasd3 *fasd3
   );

/*******************************************************************************
 * fasd3_normal3
 *
 * DESCR:       Get normal
 * RETURNS:     N/A
 */

void fasd3_normal3(
   Pvec3 *norm,
   Pfasd3 *fasd3
   );

#endif /* _fasd3P_h */

