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

#ifndef _htabP_h
#define _htabP_h

struct _Htab;
typedef struct _Htab *Hash_table;

/*******************************************************************************
 * phg_htab_create
 *
 * DESCR:       Create hash table
 * RETURNS:     Hash table or NULL
 */

Hash_table phg_htab_create(
    int hash_size
    );

/*******************************************************************************
 * phg_htab_destroy
 *
 * DESCR:       Destroy hash table
 * RETURNS:     N/A
 */

void phg_htab_destroy(
    Hash_table htab,
    void (*destroy_entry)()
    );

/*******************************************************************************
 * phg_htab_delete_entry
 *
 * DESCR:       Delete hash table entry
 * RETURNS:     Pointer to client data or NULL
 */

caddr_t phg_htab_delete_entry(
    Hash_table htab,
    int key
    );

/*******************************************************************************
 * phg_htab_add_entry
 *
 * DESCR:       Add hash table entry
 * RETURNS:     TRUE or FALSE
 */

int phg_htab_add_entry(
    Hash_table htab,
    int key,
    caddr_t cdata
    );

/*******************************************************************************
 * phg_htab_get_entry
 *
 * DESCR:       Get hash table entry
 * RETURNS:     TRUE or FALSE
 */

int phg_htab_get_entry(
    Hash_table htab,
    int key,
    caddr_t *cdata_p
    );

/*******************************************************************************
 * phg_htab_change_data
 *
 * DESCR:       Replace hash table entry
 * RETURNS:     TRUE or FALSE
 */

void phg_htab_change_data(
    Hash_table htab,
    int key,
    caddr_t cdata
    );

/*******************************************************************************
 * phg_htab_num_entries
 *
 * DESCR:       Get number hash table entries
 * RETURNS:     Number of entrues
 */

int phg_htab_num_entries(
    Hash_table htab
    );

/*******************************************************************************
 * phg_htab_first_entry
 *
 * DESCR:       Get first hash table entry
 * RETURNS:     TRUE or FALSE
 */

int phg_htab_first_entry(
    Hash_table htab,
    int *key,
    caddr_t *cdata
    );

/*******************************************************************************
 * phg_htab_next_entry
 *
 * DESCR:       Get next hash table entry
 * RETURNS:     TRUE or FALSE
 */

int phg_htab_next_entry(
    Hash_table htab,
    int *key,
    caddr_t *cdata
    );

#endif /* _htabP_h */

