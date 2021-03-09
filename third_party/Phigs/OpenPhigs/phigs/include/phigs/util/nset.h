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

#ifndef _nset_h
#define _nset_h

#include <stdint.h>

typedef struct {
   unsigned max_names;
   unsigned num_chunks;
   uint32_t *nameset;
} Nset;

typedef Nset *Nameset;

/*******************************************************************************
 * phg_nset_create
 *
 * DESCR:       Create nameset
 * RETURNS:     Nameset handle or NULL
 */

Nameset phg_nset_create(
   unsigned num_names
   );

/*******************************************************************************
 * phg_nset_init
 *
 * DESCR:       Initialize nameset
 * RETURNS:     N/A
 */

void phg_nset_init(
   Nameset nset,
   unsigned num_chunks,
   uint32_t *buf
   );

/*******************************************************************************
 * phg_nset_destroy
 *
 * DESCR:       Destroy nameset
 * RETURNS:     N/A
 */

void phg_nset_destroy(
   Nameset nset
   );

/*******************************************************************************
 * phg_nset_name_set
 *
 * DESCR:       Set name in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_name_set(
   Nameset nset,
   Pint name
   );

/*******************************************************************************
 * phg_nset_name_clear
 *
 * DESCR:       Clear name in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_name_clear(
   Nameset nset,
   Pint name
   );

/*******************************************************************************
 * phg_nset_names_set
 *
 * DESCR:       Set names in nameset from integer list
 * RETURNS:     TRUE of FALSE
 */

int phg_nset_names_set(
   Nameset nset,
   Pint num_names,
   Pint *name_list
   );

/*******************************************************************************
 * phg_nset_names_clear
 *
 * DESCR:       Clear names in nameset from integer list
 * RETURNS:     TRUE of FALSE
 */

int phg_nset_names_clear(
   Nameset nset,
   Pint num_names,
   Pint *name_list
   );

/*******************************************************************************
 * phg_nset_names_set_all
 *
 * DESCR:       Set all names in nameset
 * RETURNS:     N/A
 */

void phg_nset_names_set_all(
   Nameset nset
   );

/*******************************************************************************
 * phg_nset_names_clear_all
 *
 * DESCR:       Clear all names in nameset
 * RETURNS:     N/A
 */

void phg_nset_names_clear_all(
   Nameset nset
   );

/*******************************************************************************
 * phg_nset_names_copy_all
 *
 * DESCR:       Copy all names in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_names_copy_all(
   Nameset dest,
   Nameset src
   );

/*******************************************************************************
 * phg_nset_names_intersect
 *
 * DESCR:       Evaluate if there is an intersection between the two name sets
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_names_intersect(
   Nameset nset1,
   Nameset nset2
   );

/*******************************************************************************
 * phg_nset_name_is_set
 *
 * DESCR:       Check if name is set in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_name_is_set(
   Nameset nset,
   Pint name
   );

/*******************************************************************************
 * phg_nset_names_is_empty_all
 *
 * DESCR:       Check if all names in nameset is empty
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_names_is_empty_all(
   Nameset nset
   );

/*******************************************************************************
 * phg_nset_print
 *
 * DESCR:       Print nameset
 * RETURNS:     N/A
 */

void phg_nset_print(
   Nameset nset
   );

#endif /* _nset_h */

