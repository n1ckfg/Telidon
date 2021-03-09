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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <phigs/phg.h>
#include <phigs/util/nset.h>

/*******************************************************************************
 * phg_nset_create
 *
 * DESCR:       Create nameset
 * RETURNS:     Nameset handle or NULL
 */

Nameset phg_nset_create(
   unsigned num_names
   )
{
   unsigned num_chunks;
   Nameset nset;

   if (num_names % 32) {
      num_chunks = (num_names >> 5) + 1;
   }
   else {
      num_chunks = num_names >> 5;
   }

   nset = (Nameset) malloc(sizeof(Nset) + num_chunks * sizeof(uint32_t));
   if (nset != NULL) {
      phg_nset_init(nset, num_chunks, (uint32_t *) &nset[1]);
   }

   return nset;
}

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
   )
{
   nset->max_names  = num_chunks << 5;
   nset->num_chunks = num_chunks;
   nset->nameset    = buf;
   memset(nset->nameset, 0, num_chunks * sizeof(uint32_t));
}

/*******************************************************************************
 * phg_nset_destroy
 *
 * DESCR:       Destroy nameset
 * RETURNS:     N/A
 */

void phg_nset_destroy(
   Nameset nset
   )
{
   free(nset);
}

/*******************************************************************************
 * phg_nset_name_set
 *
 * DESCR:       Set name in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_name_set(
   Nameset nset,
   Pint name
   )
{
   int status;
   uint32_t bit;

   if (name > nset->max_names) {
      status = FALSE;
   }
   else {
      bit = 0x1 << (name & 31);
      nset->nameset[name >> 5] |= bit;
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_nset_name_clear
 *
 * DESCR:       Clear name in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_name_clear(
   Nameset nset,
   Pint name
   )
{
   int status;
   uint32_t bit;

   if (name > nset->max_names) {
      status = FALSE;
   }
   else {
      bit = 0x1 << (name & 31);
      nset->nameset[name >> 5] &= ~bit;
      status = TRUE;
   }

   return status;
}

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
   )
{
   int status;
   unsigned i;

   if (num_names > nset->max_names) {
      status = FALSE;
   }
   else {
      for (i = 0; i < num_names; i++) {
         phg_nset_name_set(nset, name_list[i]);
      }
      status = TRUE;
   }

   return status;
}

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
   )
{
   int status;
   unsigned i;

   if (num_names > nset->max_names) {
      status = FALSE;
   }
   else {
      for (i = 0; i < num_names; i++) {
         phg_nset_name_clear(nset, name_list[i]);
      }
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_nset_names_set_all
 *
 * DESCR:       Set all names in nameset
 * RETURNS:     N/A
 */

void phg_nset_names_set_all(
   Nameset nset
   )
{
   memset(nset->nameset, 0xffffffff, nset->num_chunks * sizeof(uint32_t));
}

/*******************************************************************************
 * phg_nset_names_clear_all
 *
 * DESCR:       Clear all names in nameset
 * RETURNS:     N/A
 */

void phg_nset_names_clear_all(
   Nameset nset
   )
{
   memset(nset->nameset, 0x00000000, nset->num_chunks * sizeof(uint32_t));
}

/*******************************************************************************
 * phg_nset_names_copy_all
 *
 * DESCR:       Copy all names in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_names_copy_all(
   Nameset dest,
   Nameset src
   )
{
   int status;

   if (dest->num_chunks != src->num_chunks) {
      status = FALSE;
   }
   else {
      memcpy(dest->nameset,
             src->nameset,
             src->num_chunks * sizeof(uint32_t));
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_nset_names_intersect
 *
 * DESCR:       Evaluate if there is an intersection between the two name sets
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_names_intersect(
   Nameset nset1,
   Nameset nset2
   )
{
   int status;
   unsigned i;
   uint32_t *nameset1 = nset1->nameset;
   uint32_t *nameset2 = nset2->nameset;
   unsigned num_chunks = PHG_MIN(nset1->num_chunks, nset2->num_chunks);

   status = FALSE;
   for (i = 0; i < num_chunks; i++) {
      if (nameset1[i] & nameset2[i]) {
         status = TRUE;
         break;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_nset_name_is_set
 *
 * DESCR:       Check if name is set in nameset
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_name_is_set(
   Nameset nset,
   Pint name
   )
{
   int status;
   uint32_t bit;

   if (name > nset->max_names) {
      status = FALSE;
   }
   else {
      bit = 0x1 << (name & 31);
      if (nset->nameset[name >> 5] & bit) {
         status = TRUE;
      }
      else {
         status = FALSE;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_nset_names_is_empty_all
 *
 * DESCR:       Check if all names in nameset is empty
 * RETURNS:     TRUE or FALSE
 */

int phg_nset_names_is_empty_all(
   Nameset nset
   )
{
   unsigned i;
   int status = TRUE;

   for (i = 0; i < nset->num_chunks; i++) {
      if (nset->nameset[i] != 0x0) {
         status = FALSE;
         break;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_nset_print
 *
 * DESCR:       Print nameset
 * RETURNS:     N/A
 */

void phg_nset_print(
   Nameset nset
   )
{
   unsigned i;

   for (i = 0; i < nset->num_chunks; i++) {
      printf("%x ", nset->nameset[i]);
   }
   printf("\n");
}

